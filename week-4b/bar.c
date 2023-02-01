#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("Hello world!");
    fflush(stdout);          // print this right away
    printf("And then some"); // waits until a new line
    sleep(1);
}