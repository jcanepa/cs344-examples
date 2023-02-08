#include <stdio.h>

int main(void)
{
    char s[2048];

    fgets(s, stdin, 2048); // "     ls   -l     -a  "

    char *tok; // char pointer, automatic variable. On the stack!
               // the thing it points to is not necessarily on the stack
               // value is indeturminate because we didn't initialize it
               // this variable will go away once the function returns, but it's value won't

    tok = strtok(s, " \t\r\n"); // scan for chars not in delimiter
                                // returns pointer to the byte we own (have been allocated)
                                // no need to allocate
                                // adds a null character to the end of the first string
                                // string is a pointer to the first character and the assumption there's a null terminator at the end

    while ((tok = strtok(NULL, " \t\r\n")) != NULL)
    {
    }
}