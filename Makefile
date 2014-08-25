#
# \file                 Makefile
# \author               Jerome GRARD
# \version              1.0
# \date                 2014
# \brief                Makefile for fley
#
# \details              Cleaning and compilation macro



CC=gcc
CFLAGS=-Wall
LDFLAGS=-lncurses -O2
EXEC=fley

all: $(EXEC)
allc: mrproper $(EXEC)

fley: drawing.o io.o main.o
	@$(CC) -o $@ $^ $(LDFLAGS)
	@echo [LD] $@

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo [CC] $@

clean:
	@echo ---------------
	@echo      clean
	@echo ---------------
	rm -rf *.o

mrproper: clean
	@echo ---------------
	@echo   clean all
	@echo ---------------
	rm -rf $(EXEC)

