#include <stdio.h>
#include <sys/mman.h>
#include <string.h>

struct node
{
    int len;
    struct node *next;
};

int main(void)
{
    void *mem = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

    char *s = mem;
    char *p = s + 3; // causes misalignment (you can't run this program on every architecture)

    struct node *n = (struct node *)p; // type cast, coersion
                                       // points to same address as p

    n->len = 100;
    n->next = NULL;

    printf("%d\n", n->len);
    printf("%p\n", n->next);
}