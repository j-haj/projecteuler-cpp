CXX := clang++

BUILDDIR := build
SRCDIR := src
TESTDIR := test
TARGET := bin/tester

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(pathsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
LIB := -L lib
SYS := -isystem include/gtest
INC := -I include/projecteuler

test: $(TARGET)
	./bin/tester

$(TARGET): $(OBJECTS) $(BUILDDIR)/eulertests.o
	$(CXX) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/eulertests.o: test/eulertests.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(INC) $(SYS) -c test/eulertests.cpp -o $(BUILDDIR)/eulertests.o

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CXX) $(INC) $(SYS) -c $< -o $@"; $(CXX) $(INC) $(SYS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILDDIR)
