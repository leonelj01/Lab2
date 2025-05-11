# === Configuración de directorios ===
SRC_DIR = src
INC_DIR = inc

BUILD_DIR = build
OBJ_DIR = ${BUILD_DIR}/obj
BIN_DIR = ${BUILD_DIR}/bin
DOC_DIR = ${BUILD_DIR}/doc

# === Archivos fuente, objeto y dependencias ===
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
DEP_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.d,$(SRC_FILES))

PROGRAM = $(BIN_DIR)/lab2

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 $(foreach DIR, $(INC_DIR), -I$(DIR)) -MMD

# Incluye archivos de dependencia (si existen)
-include $(DEP_FILES)

# === Reglas principales ===
all: $(PROGRAM)

$(PROGRAM): $(OBJ_FILES) | $(BIN_DIR)
	@echo "Linking executable..."
	@$(CC) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Compiling $< to $@"
	@$(CC) $(CFLAGS) -c $< -o $@

# === Creación de directorios necesarios ===
$(BUILD_DIR):
	@mkdir -p $@

$(OBJ_DIR): | $(BUILD_DIR)
	@mkdir -p $@

$(BIN_DIR): | $(BUILD_DIR)
	@mkdir -p $@

$(DOC_DIR): | $(BUILD_DIR)
	@mkdir -p $@

# === Comandos adicionales ===
clean:
	@echo "Cleaning build files..."
	@rm -rf $(BUILD_DIR)

info:
	@echo "Source Directory: $(SRC_DIR)"
	@echo "Include Directory: $(INC_DIR)"
	@echo "Output Directory: $(BUILD_DIR)"
	@echo "Object Files: $(OBJ_FILES)"
	@echo "Binary File: $(PROGRAM)"

exe: all
	@echo "Running program..."
	@$(PROGRAM)

doc: | $(DOC_DIR)
	@echo "Generating documentation..."
	@doxygen Doxyfile
