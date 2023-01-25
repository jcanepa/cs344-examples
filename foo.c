#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[] = "exit";

    // pointer comparison doesn't work b/c the strings are at different places in memory
    // printf("%d\n", s == "exit");

    // compare a byte at a time
    printf("%d\n", strcmp(s, "exit"));
    // strcmp returns the difference between these strings (0 difference is a match)

    if (strcmp(s, "exit") == 0)
        printf("strings are the same!\n");
}