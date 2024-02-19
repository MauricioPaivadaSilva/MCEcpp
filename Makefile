CC = g++
CFLAGS = -Wall -Wextra -pedantic
SRC_DIR = ./src
OBJ_DIR = ./obj
LIB_DIR = ./lib
INCLUDE_DIR = ./include

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBS_FIlES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))
LIB_NAME = libgraph.a
LIB_TARGET = $(LIB_DIR)/$(LIB_NAME)

all: $(LIB_TARGET)

$(LIB_TARGET): $(OBS_FIlES)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCLUDE_DIR)

.PHONY: clean

clean:
	rm -rf $(OBJ_DIR)/*.o $(LIB_TARGET)
