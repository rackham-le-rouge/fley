#
# \file                 Makefile
# \author               Jerome GRARD
# \version              1.0
# \date                 2014
# \brief                Makefile for fley
#
# \details              Cleaning and compilation macro - We are using the compilation option of the libcommon project
			(http://www.thelibcommonproject.org) to improve our code quality.



CC=gcc
LDFLAGS=-lncurses -O2
EXEC=fley
CFLAGS=-fopenmp -W -Waggregate-return -Wall -Warray-bounds -Wbad-function-cast -Wcast-align -Wcast-qual         \
                 -Wchar-subscripts -Wcomment -Wdeclaration-after-statement -Werror -Wextra -Wfloat-equal        \
                 -Wformat -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wignored-qualifiers -Wimplicit    \
                 -Wimplicit-function-declaration -Wimplicit-int -Winit-self -Winline -Winvalid-pch -Wlogical-op \
                 -Wlong-long -Wmain -Wmissing-braces -Wmissing-declarations -Wmissing-field-initializers        \
                 -Wmissing-include-dirs -Wmissing-noreturn -Wmissing-parameter-type -Wmissing-prototypes        \
                 -Wmultichar -Wnested-externs -Wno-multichar -Wnonnull -Wold-style-definition                   \
                 -Woverlength-strings -Wparentheses -Wpointer-arith -Wpointer-sign                              \
                 -Wreturn-type -Wsequence-point -Wshadow -Wsign-compare -Wstack-protector                       \
                 -Wswitch -Wswitch-default -Wswitch-enum -Wsync-nand -Wtrigraphs -Wundef -Wuninitialized        \
                 -Wunknown-pragmas -Wunsafe-loop-optimizations -Wunused -Wunused-function -Wunused-label        \
                 -Wunused-parameter -Wunused-value -Wunused-variable -Wvla -Wvolatile-register-var              \
                 -Wwrite-strings -fno-common -fstack-protector-all -pedantic -std=c99 -Wstrict-aliasing=3




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

