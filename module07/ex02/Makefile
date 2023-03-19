#
# @author    Clément Vidon
# @date      230319
# @file      Makefile
#
############ PROJECT

NAME        := array

LIBS		:=
LIBS_PATH	:=

SRC_DIR     := src
SRCS        := \
	main.cpp \

INC_DIR		:= include
BUILD_DIR   := .build

############ GENERIC

## COMPILATION VARIABLES

SRCS        := $(SRCS:%=$(SRC_DIR)/%)
INCS        := $(INC_DIR) $(dir $(SRCS))
OBJS        := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)

CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98
EXTRA_FLAGS	:= -Wconversion -Wsign-conversion -pedantic
DEBUG_FLAGS	:= -Wno-unused -fno-omit-frame-pointer -Og -D DEBUG
CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS     := $(addprefix -L,$(dir $(LIBS_PATH)))
LDLIBS      := $(addprefix -l,$(LIBS))

## MAKE VARIABLES

RM          := rm -f
MAKEFLAGS   := --no-print-directory --jobs -C
UNAME		:= $(shell uname)
FILE_AGE	:= $$(date -d@$$(($$(date +%s) - $$(date -r $(NAME) +%s))) -u +%H:%M:%S)
DIR_DUP     = mkdir -p $(@D)

## GENERAL RULES

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_PATH)
	$(CXX) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	$(info CREATED $(NAME))

$(LIBS_PATH):
	$(MAKE) $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(DIR_DUP)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS)

clean:
	for f in $(dir $(LIBS_PATH)); do $(MAKE) $$f clean; done
	$(RM) $(OBJS) $(DEPS) $(NAME)
	$(info REMOVED $(OBJS))
	$(info REMOVED $(DEPS))
	$(info REMOVED $(NAME))

re:
	$(MAKE) clean
	$(MAKE) all

## EXTRA RULES

info:
	$(info  make sure - compile without any warning or errors)
	$(info  make asan - compile with fsanitize)
	$(info  make leak - make and execute via valgrind)
	$(info  make exec - make and execute)
	$(info  make test - make and run tests)

sure: CXXFLAGS	:= -Wno-everything -Wno-unused
sure: all

asan: CXXFLAGS	+= $(EXTRA_FLAGS)
asan: CXXFLAGS	+= -fsanitize=address,undefined,vptr
asan: CXXFLAGS	+= -fno-optimize-sibling-calls $(DEBUG_FLAGS)
asan: LDFLAGS	+= -g -fsanitize=address,undefined,vptr
asan: all

leak:
leak: CXXFLAGS += $(EXTRA_FLAGS)
leak: CXXFLAGS += $(DEBUG_FLAGS)
leak: all

ifneq ("$(wildcard $(NAME))","")
	clear
	echo  CREATED $(FILE_AGE) AGO
	echo "--------------------"
	-valgrind -q ./$(NAME)
else
	$(info $(NAME) not found)
endif

exec:
exec:

ifneq ("$(wildcard $(NAME))","")
	clear
	echo  CREATED $(FILE_AGE) AGO
	echo "--------------------"
	-./$(NAME)
else
	$(info $(NAME) not found)
endif

test: re
	-bash test/tests.sh

## OPTIONS

.PHONY: clean re exec test
.SILENT:
