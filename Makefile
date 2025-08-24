all:
	g++ main.cpp comp.cpp inputfuncs.cpp outputfuncs.cpp solvefuncs.cpp testfunc.cpp -o quadr
test:
	g++ main.cpp comp.cpp inputfuncs.cpp outputfuncs.cpp solvefuncs.cpp testfunc.cpp -o quadrTest -DTESTMODE
debug:
	g++ main.cpp comp.cpp inputfuncs.cpp outputfuncs.cpp solvefuncs.cpp testfunc.cpp -o quadrDebug -DDEBUGMODE
testdebug:
	g++ main.cpp comp.cpp inputfuncs.cpp outputfuncs.cpp solvefuncs.cpp testfunc.cpp -o quadrTestDebug -DDEBUGMODE -DTESTMODE

