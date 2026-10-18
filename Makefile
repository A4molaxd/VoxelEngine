CC  := gcc
CXX := g++

BUILD_DIR := build/mingw
TARGET := $(BUILD_DIR)/VoxelEngine.exe

LIB_DIR := Libraries/lib
INC_DIR := Libraries/include

CPP_SOURCES := $(wildcard *.cpp)
C_SOURCES   := gl.c

OBJECTS := $(CPP_SOURCES:.cpp=.o) $(C_SOURCES:.c=.o)

CPPFLAGS := -I"$(INC_DIR)"
CFLAGS   := -Wall -O2 -g
CXXFLAGS := -Wall -O2 -g -std=c++17

GLFW_LIB := $(LIB_DIR)/libglfw3.a

LDLIBS := "$(GLFW_LIB)" -lopengl32 -lgdi32 -luser32 -lkernel32

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

gl.o: gl.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET)
