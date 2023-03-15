#
# @author    Clément Vidon
# @date      230312
# @file      Makefile
#
############ PROJECT

NAME        := castor

LIBS		:=
LIBS_PATH	:=

SRC_DIR     := .
SRCS        := \
			   tests.cpp \
			   print.cpp \
			   cast.cpp \
			   detect.cpp \
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
CXXFLAGS	+= -Wconversion -Wsign-conversion -pedantic
DEBUG_FLAGS	:= -Wno-unused -fno-omit-frame-pointer -Og -D DEBUG
CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS     := $(addprefix -L,$(dir $(LIBS_PATH)))
LDLIBS      := $(addprefix -l,$(LIBS))

## MAKE VARIABLES

RM          := rm -f
MAKEFLAGS   := --no-print-directory --jobs -C
UNAME		:= $(shell uname)
DIR_DUP     = mkdir -p $(@D)

ifeq ($(UNAME), Darwin)
	AGE			:= $$(printf "%08d" $$(( $$(date +%s) - $$(stat -f "%m" $(NAME)) )))
endif
ifeq ($(UNAME), Linux)
	AGE			:= $$(date -d@$$(($$(date +%s) - $$(date -r $(NAME) +%s))) -u +%H:%M:%S)
endif

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

sure: CXXFLAGS	:= -Wno-everything -Wno-unused
sure: all

asan: CXXFLAGS	+= -fsanitize=address,undefined,integer,nullability,vptr #
asan: CXXFLAGS	+= -fno-optimize-sibling-calls $(DEBUG_FLAGS)
asan: LDFLAGS	+= -g -fsanitize=address,undefined,integer,nullability,vptr #
asan: all

run:

ifneq ("$(wildcard $(NAME))","")
	clear
	echo  CREATED $(AGE) AGO
	echo "--------------------"
	./$(NAME)
endif

leaks:
leaks: CXXFLAGS	+= $(DEBUG_FLAGS)
leaks: re

ifeq ($(UNAME), Linux)
	clear
	echo  CREATED $(AGE) AGO
	echo "--------------------"
	-valgrind -q ./$(NAME)
endif
ifeq ($(UNAME), Darwin)
	clear
	echo  CREATED $(AGE) AGO
	echo "--------------------"
	-leaks -q -atExit -- ./$(NAME)
endif

## OPTIONS

.PHONY: clean re run
.SILENT:
