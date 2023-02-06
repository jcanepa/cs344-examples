#include <stdio.h>

// recursion example re: the stack

void foo(int x)
{
    if (x == 0)
        return;

    printf("%d\n", x);

    foo(x - 1);
    // "unwinding the stack"
    // returns after foo is called.
}

int main(void)
{
    foo(5);
}
