#include "4_1.h"
#include <assert.h>
int test_input() {
    char str1[]="Сorrect string!";
    char str2[]="";
    assert(checkinput(str1) == 1);
    assert(checkinput(str2) == 0);
}
int test_brackets() {
    char str1[]="Сorrect(money)string!";
    char str2[]="Incorrect string!";
    assert(checkbrackets(str1) == 1);
    assert(checkbrackets(str2) == 0);
}
#undef main
int main() {
    test_input();
    test_brackets();
}