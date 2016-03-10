CXX := clang++

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

$(TARGET): $(OBJECTS) $(TESTDIR)/eulertests.o
	$(CXX) $^ -o $(TARGET) $(LIB)

$(TESTDIR)/eulertests.o: $(TESTDIR)/eulertests.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(INC) $(SYS) -c $< -o $@
$(OBJECTS): $(SOURCES) 
	@mkdir -p $(BUILDDIR)
	$(CXX) $(INC) $(SYS) -c $< -o $@ 

.PHONY: clean
clean:
	rm -r $(BUILDDIR)
