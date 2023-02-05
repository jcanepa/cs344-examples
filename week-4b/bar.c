#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("Hello world! ");
    printf("And then some"); // waits until a new line

    // fflush(stdout);          // print this right away
    sleep(1);
    printf("...finally!\n");
}