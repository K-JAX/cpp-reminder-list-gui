# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = `pkg-config --cflags Qt5Widgets`

# Linker flags
LDFLAGS = `pkg-config --libs Qt5Widgets`

# Target executable
TARGET = reminder_app

# Source files
SRCS = main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Compile the source files into object files
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
