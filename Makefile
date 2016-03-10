CXX := clang++

BUILDDIR := build
SRCDIR := src
TESTDIR := test
TARGET := bin/tester

SRCEXT := cpp
SOURCES := $(SRCDIR)/%.cpp
OBJECTS := $(BUILDDIR)/%.o
LIB := lib/libgtest.a
SYS := -isystem include/
INC := -I include/

test: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJECTS) 
	$(CXX) $^ -o $(TARGET) $(LIB)

$(OBJECTS): $(SOURCES) test/eulertests.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(INC) $(SYS) -c $< -o $@ 

.PHONY: clean
clean:
	rm -r $(BUILDDIR)
