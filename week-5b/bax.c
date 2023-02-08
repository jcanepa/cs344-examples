#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    // void pointer can be assigned to any type of var
    // and the other way around?
    char *s = malloc(10); // malloc returns a void pointer (typeless)

    // array of 10 integers
    int *i = malloc(10 * sizeof(int));
    printf("%d\n", i[2]);

    // when we want an array of things, but we don't know the type of objects
    // you can make an array of void pointers
    void *foo = malloc(10);
    *foo; // dereference a void pointer
    // void indicates the expression has no type
}
