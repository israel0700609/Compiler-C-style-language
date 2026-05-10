echo "Deleting Files"
rm -f lex.yy.c
rm -f y.tab.h
rm -f y.tab.c
echo "Generating lex and yacc"
lex ./syntax_analyzer/Scanner.l
bison -d -y ./syntax_analyzer/Parser.y
echo "Compiling..."
gcc lex.yy.c y.tab.c ast/ast.c semantic_analyzer/BluePrintFiles/scope.c -g -o compiler
echo "Running the compiler and saving the output AST to \"output.txt\""
./compiler < input.txt > output.txt
echo "Compiled"