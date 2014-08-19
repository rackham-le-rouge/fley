CC=gcc
CFLAGS=-Wall
LDFLAGS=-lncurses
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

