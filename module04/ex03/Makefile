NAME        := materia

LIBS		:=
LIBS_PATH	:=

SRC_DIR     := src
SRCS        := \
	AMateria.cpp \
	Character.cpp \
	Cure.cpp \
	Ice.cpp \
	MateriaSource.cpp \
	main.cpp \

INC_DIR		:= include
BUILD_DIR   := .build

############

SRCS        := $(SRCS:%=$(SRC_DIR)/%)
INCS        := $(INC_DIR) $(dir $(SRCS))
OBJS        := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)

CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98 -pedantic -W
CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS     := $(addprefix -L,$(dir $(LIBS_PATH)))
LDLIBS      := $(addprefix -l,$(LIBS))

RM          := rm -f
MAKEFLAGS   := --no-print-directory --jobs -C
AGE			:= $$(date -d@$$(($$(date +%s) - $$(date -r $(NAME) +%s))) -u +%H:%M:%S)
DIR_DUP     = mkdir -p $(@D)

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

asan: CXXFLAGS	+= -O -g -fsanitize=address,undefined -fno-optimize-sibling-calls
asan: LDFLAGS   += -g -fsanitize=address,undefined
asan: all

run:
ifneq ("$(wildcard $(NAME))","")
	clear
	echo  CREATED $(AGE) AGO
	echo "--------------------"
	./$(NAME)
endif

run-valgrind:
	clear
	echo BINARY CREATED $(AGE) AGO
	echo "---------------------------"
	valgrind -q ./$(NAME)

.PHONY: clean re run
.SILENT:
