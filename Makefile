CXX := clang++
CFLAGS := -std=c++14 -Wall -pedantic

BUILDDIR := build
SRCDIR := src
TESTDIR := test
TARGET := bin/tester

SRCEXT := cpp
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

LIB := lib/libgtest.a
SYS := -isystem include/
INC := -I include/

test: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJECTS) $(BUILDDIR)/eulertests.o
	$(CXX) $(INC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/eulertests.o: $(TESTDIR)/eulertests.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(INC) $(SYS) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp 
	@mkdir -p $(BUILDDIR)
	$(CXX) $(INC) $(SYS) $(CFLAGS) -c $< -o $@ 

.PHONY: clean
clean:
	rm -r $(BUILDDIR)
