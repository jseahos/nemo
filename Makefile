CPP=clang++
CPPFLAGS=-std=c++17 -Werror -Wall -Wextra -Wpedantic

SRC_DIR=src
BIN_DIR=bin

SRC=$(wildcard $(SRC_DIR)/*.cpp)
OBJ=$(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%.o, $(SRC))
EXE=$(BIN_DIR)/nemo

.PHONY: all
all: $(EXE)

$(EXE): $(OBJ)
	$(CPP) -o $@ $^

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CPP) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(BIN_DIR)
