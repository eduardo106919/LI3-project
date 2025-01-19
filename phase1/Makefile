#=========================================================================
# Directories
SRC_DIR=src
INC_DIR=include
BLD_DIR=build
BIN_DIR=bin
TST_DIR=test
DOC_DIR=docs
RPT_DIR=coverage-reports
RST_DIR=resultados
#-------------------------------------------------------------------------
# Compilation
CC=gcc
OPTS=-O2
CFLAGS=-Wall -Wextra -pedantic-errors -I$(INC_DIR)
LDFLAGS=-lm
DBG_FLAGS=-g
GPROF_FLAGS=-pg
RPT_FLAGS=-fprofile-arcs -ftest-coverage
#-------------------------------------------------------------------------
# FIles
CFILES=$(wildcard $(SRC_DIR)/**/*.c)
OBJS=$(patsubst $(SRC_DIR)/%.c, $(BLD_DIR)/%.o, $(CFILES))
#-------------------------------------------------------------------------
# Executables
MAIN=$(BIN_DIR)/programa-principal
TEST=$(BIN_DIR)/programa-testes
INTERATIVE=$(BIN_DIR)/programa-interativo
BINS=$(MAIN) $(TEST) $(INTERATIVE)
#=========================================================================

all: setup $(MAIN)

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

$(BLD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: setup
setup:
	@mkdir -p $(BLD_DIR)
	@mkdir -p $(BIN_DIR)

.PHONY: clean
clean:
	rm -r $(BLD_DIR) $(BIN_DIR) $(RST_DIR)/*