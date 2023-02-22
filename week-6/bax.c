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
    // signature from `man mmap`:
    // mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);
    void *mem = mmap(
        NULL,
        1024,
        PROT_READ | PROT_WRITE,
        MAP_ANON | MAP_PRIVATE, // not mapped to actual file, child gets own copy after fork (not shared with parent)
        -1,
        0);

    // copy structure off the stack into memory (heap)
    struct node *p = mem; // void pointers can be assigned to pointers of any other type
    int *i = mem;         // can do this, nothing yet stored to this addr

    printf("%p\n", mem);
    printf("%p\n", p);
    printf("%p\n", i);

    // we own the memory and we can store stuff there
    p->len = 100;
    p->next = NULL;
    // embed structures in our chunk of memory

    *i = 200; // this points to the same address as the struct node pointer above
              // 2 addresses point at the same
              // aliasing
              // overwrites whatever was there before (100)

    printf("%d\n", p->len);
    printf("%p\n", p->next);
    // p points to the same place mem is pointing but now it's a struct node pointer

    // use pointer arithmatic to navigate within our allocated memory
    // addresses are just numbers in memory that go up sequentially
    // look at memory as a type of structure
}