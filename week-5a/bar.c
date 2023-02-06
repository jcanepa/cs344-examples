#include <stdio.h>

// this file is an example of bad practice.
// this breaks becasue we try to access the memory address to a "house that was burned down"

int *foo(void)
{
    int x = 12; // automatic variable x that will disappear when foo returns
    return &x;  // returns an address to a varibale that won't exist by the time it's recieved
}

int bar(void)
{
    int y = 42, z = 100;
    return y + z;
}

int main_1(void)
{
    printf("%d\n", *foo());
    // causes error
    // warning: address of stack memory associated with local variable 'x' returned [-Wreturn-stack-address]
}

void main(void)
{
    int *val = *foo();
    printf("%d\n", *val); // 12
    bar();
    printf("%d\n", *val); // 42
}
