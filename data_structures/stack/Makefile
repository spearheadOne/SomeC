CC = gcc
CFLAGS ?= -std=c11 -Wall -Wextra -g
CPPFLAGS ?=
LDFLAGS ?=
LDLIBS ?=
SOURCES = stack.c stack_demo.c list.c
OBJECTS = $(SOURCES:.c=.o)
DEPS = $(OBJECTS:.o=.d)
EXECUTABLE = st

.PHONY: all clean
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(DEPS) $(EXECUTABLE)

-include $(DEPS)
