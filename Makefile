CC = clang++
CFLAGS = -g -Wall
SOURCES = $(wildcard src/*.cpp)
TARGETS = $(notdir $(SOURCES:%.cpp=%))
TEST=$(firstword $(shell find . -perm +111 -type f -exec ls -1t {} +))

.PHONY: all clean test

all: $(TARGETS)

% : src/%.cpp
	$(CC) $(CFLAGS) $< -o $@

test: $(TEST)
	./$(TEST)

clean:
	$(RM) $(TARGETS)
