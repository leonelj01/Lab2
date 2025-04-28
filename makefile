SRC_DIR = ./src
INC_DIR = ./inc

OUT_DIR = ./build
OBJ_DIR = $(OUT_DIR)/obj
BIN_DIR = $(OUT_DIR)/bin

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
DEP_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.d,$(SRC_FILES))

# el menos es para que no se vea el error si no existe el archivo .d
-include $(OBJ_DIR)/%.d 

all: $(OBJ_FILES)
	@echo "Building project..."
	@mkdir -p $(BIN_DIR)
	@gcc $(OBJ_FILES) -o $(BIN_DIR)/app.out

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $< to $@"
	@mkdir -p $(OBJ_DIR)
	@gcc -o $@ -c $< $(foreach DIR, $(INC_DIR), -I $(DIR)) -MMD


clean:
	@rm -rf $(OUT_DIR)

info:
	@echo "Source Directory: $(SRC_DIR)"
	@echo "Include Directory: $(INC_DIR)"
	@echo "Output Directory: $(OUT_DIR)"
	@echo "Object Files: $(OBJ_FILES)"
	@echo "Binary File: $(BIN_DIR)/app.out"
