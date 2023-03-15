#include <stdio.h>
#include <string.h>

void print_str(char *s)
{
    char str2[10];
    strcpy(str2, s);

    printf("%p\n", str2);
    // address changes each run, prevents attacks that allow hackers to offset bit location to executable code
}

int main(void)
{
    // overwrites the return address beyond the end of str2
    print_str("Hello! This is a super long string that will cause buffer overruns because it's over the 10 bytes allocated above");
    printf("Execution continued");
}
