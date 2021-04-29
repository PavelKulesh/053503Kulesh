#include "4_2.h"
#include <assert.h>
#include <stdio.h>
int test_fileopen() {
    FILE *myfile1;
	myfile1 = fopen("main.txt", "r");
    FILE *myfile2;
	myfile2 = fopen("empty.txt", "r");
    assert(checkfileopen(myfile1) == 1);
    assert(checkfileopen(myfile2) == 0);
}
int test_empty() {
    char str1[]="Сorrect string!";
    char str2[]="";
    assert(checkempty(str1) == 1);
    assert(checkempty(str2) == 0);
}
#undef main
int main() {
    test_fileopen();
    test_empty();
}