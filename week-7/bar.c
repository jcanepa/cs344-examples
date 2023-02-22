#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
s           112
v            v
----------------------------------------
|           *i!
----------------------------------------
        ^
       108
*/

struct foo
{
    char c;
    int i;
};

int main(void)
{
    char *s = malloc(1024);
    struct foo f = {'b', 12};
    // struct foo f = {.c='b', .i=12}; // same as above

    // place something 108 bytes above s
    // these are equivalent
    memcpy(s + 108, &f, sizeof(struct foo)); // provide a pointer to f by taking adddress-of
    // memcpy(s + 108, &f, sizeof f);           // can provide an expression where f, () are required for types (like above)

    // get apointer to the struct foo in memory
    struct foo *fp = (struct foo *)(s + 108);

    printf("%s\n", s + 112);
    printf("fp 1: %c %d\n", fp->c, fp->i);

    // // place "Hi!" (a string)
    strcpy(s + 112, "Hi!");

    // // update to "*i!" (a char)
    // strcpy(s + 112, '*');

    // *(s + 112) = '*';

    printf("%s\n", s + 112);
}
