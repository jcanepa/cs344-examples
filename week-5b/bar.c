#include <stdio.h>

struct foo
{
    int baz;
};

void bar(struct foo *o) // accept a pointer
{
    // o.baz = 12; won't work because it needs to be dereferenced first
    // dereference o before using dot operator

    // both these work, second is more idiomatic
    // (*o).baz = 12;
    o->baz = 12;
}

int main(void)
{
    struct foo f;
    bar(&f); // pass in address-of f
    printf("%d\n", f.baz);
}
