#include <stdio.h>
#include <sys/mman.h> // mmap()
#include <string.h>   // memcopy()

struct node
{
    int len;
    struct node *next;
};

int main(void)
{
    // mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);
    void *mem = mmap(
        NULL,
        1024,
        PROT_READ | PROT_WRITE,
        MAP_ANON | MAP_PRIVATE, // not mapped to actual file, child gets own copy after fork (not shared with parent)
        -1,
        0);
    // allocated directly from OS
    printf("%p\n", mem);

    struct node n = {100, NULL}; // make sure they're in order
    // struct node n = {.len=100, .next=NULL}; // alternate syntax

    // copy struct node into memory
    memcpy(mem, &n, sizeof n);
    printf("%d\n", n.len);
    printf("%p\n", n.next);

    // copy structure off the stack into memory (heap)
    struct node *p = mem; // void pointers can be assigned to pointers of any other type
    printf("%d\n", p->len);
    printf("%p\n", p->next);
    // p points to the same place mem is pointing but now it's a struct node pointer
}