#include <stdio.h>
#include <string.h>

int main(void)
{
    // allocates array of 5 elements and adds them into the char array
    char s[] = "exit";

    // pointer comparison doesn't work b/c the strings are at different places in memory
    // printf("%d\n", s == "exit");

    // let's compare these char arrays 1 byte at a time
    printf("%d\n", strcmp(s, "exit"));
    // strcmp returns the difference between these strings
    // (0 difference is a match)

    // this is the way to check whether 2 strings are equal
    if (strcmp(s, "exit") == 0)
        printf("strings are the same!\n");

    // another way to create a pointer by defining the pointer to a constant (I think)
    char *foo = "exit";
    printf("%s\n", foo);
}
