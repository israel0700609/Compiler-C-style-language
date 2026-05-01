CC      = gcc
CFLAGS  = -I..

TARGET  = parser
AST_SRC = ../ast/ast.c

.PHONY: all clean

all: $(TARGET)

# Generate y.tab.c and y.tab.h from parser.y
y.tab.c y.tab.h: parser.y
	yacc -d parser.y

# Generate lex.yy.c from Scanner.l
lex.yy.c: Scanner.l y.tab.h
	lex Scanner.l

# Link everything together
$(TARGET): y.tab.c lex.yy.c $(AST_SRC)
	$(CC) $(CFLAGS) -o $@ y.tab.c lex.yy.c $(AST_SRC) -ll

clean:
	rm -f $(TARGET) y.tab.c y.tab.h lex.yy.c y.output