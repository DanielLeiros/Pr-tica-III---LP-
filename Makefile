RM = rm -rf
# Compilador
CC=g++
# Variaveis para os subdiretorios
LIB_DIR=./lib
INC_DIR=./include
OBJ_DIR=./build
BIN_DIR=./bin
SRC_DIR=./src
DOC_DIR=./doc
TEST_DIR=./test



CFLAGS = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)
.PHONY: all clean distclean doxy



debug: CFLAGS += -g -O0

Sapo: $(OBJ_DIR)/main.o $(OBJ_DIR)/circuito.o $(OBJ_DIR)/sapo.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel em $(BIN_DIR)] +++"
	@echo "============="

dir: 
	mkdir build	
	mkdir bin
	
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/circuito.o: $(SRC_DIR)/circuito.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/sapo.o: $(SRC_DIR)/sapo.cpp
	$(CC) -c $(CFLAGS) -o $@ $<


doxy:
	$(RM) $(DOC_DIR)/*


clear:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
	rmdir build
	rmdir bin
# FIM do Makefile
