NAME        := account
SRCS        := tests.cpp Account.cpp

OBJS        := $(SRCS:.cpp=.o)
DEPS        := $(OBJS:.o=.d)

CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98 -pedantic -W
CPPFLAGS    := -I. -MMD -MP
LDFLAGS     :=
LDLIBS      :=

RM          := rm -f
MAKEFLAGS   := --no-print-directory --jobs

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS) $(NAME)

re:
	$(MAKE) clean
	$(MAKE) all

asan: CXXFLAGS	+= -O -g -fsanitize=address,undefined -fno-optimize-sibling-calls
asan: LDFLAGS   += -g -fsanitize=address,undefined
asan: all

.PHONY: clean re run
