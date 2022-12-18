INPUT = tests/1.asm.txt

all: mini_js $(INPUT)
	./mini_js < $(INPUT)

mini_js: lex.yy.c y.tab.c
	g++ -o mini_js y.tab.c

lex.yy.c: mini_js.l
	lex mini_js.l

y.tab.c: mini_js.y
	yacc mini_js.y -v