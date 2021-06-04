all: main main_test codecov_test valgrind

main:
	g++ main.cpp -o main

main_test:
	g++ -ftest-coverage -fprofile-arcs -O0 -o main_test Test.cpp DataJoke.cpp

codecov_test:
	./main_test
	gcov -abcfu DataJoke.cpp

valgrind: 
	valgrind ./main_test

