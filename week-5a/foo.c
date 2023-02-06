#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int addr(int x, int y)
{
    int z = x + y; // automatic variable (freed once function returns) `auto`
    return z;
}

// returns a pointer to a character
// not a string unless it is null terminated
char *give_me_ram(int byte_count)
{
    char *ram = malloc(byte_count); // this gets us memory (ask OS for memory we didn't have before).
    // A new page in physical memory is allocated for my process.
    return ram;
}

int main(void)
{
    printf("%d\n", addr(2, 3));

    // char *mem = give_me_ram(2048);
    char *mem = malloc(2048); // returns a pointer back to this addr
    // anytime you malloc ram, there's a memory leak (when not freed)

    strcpy(mem, "Hello, world!"); // copy bytes into this address
    puts(mem);

    free(mem); // deallocates memory (no memory leaks!)
    puts(mem); // undefined behavior, we're not allowed to access memory after we've freed it. Anything can happen!

    return 0;
}