CC = g++
CFLAGS = -Wall -Wextra -pedantic -fPIC
SRC_DIR = ./src
OBJ_DIR = ./obj
LIB_DIR = ./lib
INCLUDE_DIR = ./include

SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBS_FIlES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))
LIB_NAME = libgraph.so
LIB_TARGET = $(LIB_DIR)/$(LIB_NAME)

all: $(LIB_TARGET)

$(LIB_TARGET): $(OBS_FIlES)
	$(CC) $(CFLAGS) -shared -o $@ $^ -L/usr/local/lib $(SFML_LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCLUDE_DIR)

.PHONY: clean

clean:
	rm -rf $(OBJ_DIR)/*.o $(LIB_TARGET)
