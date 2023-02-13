#include <stdio.h>

int main(void)
{
    char *s = "Hello world!";
    printf("%s\n", s + 1);    // ello world!
                              // each char is 1 byte long
    printf("%c\n", *(s + 1)); // e
    printf("%c\n", s[1]);     // e

    int a[5] = {0, 11, 22, 33, 44};
    printf("%p\n", a);     // pointer to the first element (0)
    printf("%p\n", a + 1); // 11
                           // even though the next int is more than 1 byte (because of the data type)

    print("%d\n", *(a + 1)); // 11
    print("%d\n", a[1]);     // 11
    // int is 2 or 4 bytes (depends)

    // NULL is a pointer
}