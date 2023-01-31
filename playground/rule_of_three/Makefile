NAME        := a.out

BUILD_DIR   := .build
SRC_DIR     := src
SRCS        := \
	main.cpp \
	Rot.cpp \

LIBS		:=
LIBS_PATH	:=

##############

INCS        := $(dir $(SRCS))
SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)

CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98 -pedantic -W
CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS     := $(addprefix -L,$(dir $(LIBS_PATH)))
LDLIBS      := $(addprefix -l,$(LIBS))

RM          := rm -f
MAKEFLAGS   := --no-print-directory --jobs
DIR_DUP     = mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_PATH)
	$(CXX) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	$(info CREATED $(NAME))

$(LIBS_PATH):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(DIR_DUP)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS)

clean:
	for f in $(dir $(LIBS_PATH)); do $(MAKE) -C $$f clean; done
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

run: all
	./$(NAME)

.PHONY: clean re run
.SILENT:
