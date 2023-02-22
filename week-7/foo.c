#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
s           112
v            v
----------------------------------------
|           Hi!
----------------------------------------
*/

int main(void)
{
    char *s = malloc(1024);

    // place "Hi!" (a string)
    strcpy(s + 112, "Hi!");

    // update to "*i!" (a char)
    // all three of these lines are equivalent:
    strcpy(&s[112], '*');       // [] have an implicit dereference within them
    strcpy(&(*(s + 112)), '*'); // address of/dereference are inverses of eachother
    strcpy(s + 112, '*');

    // another two ways to do this:
    *(s + 112) = '*';
    s[112] = '~';

    printf("%s\n", s + 112);
}
