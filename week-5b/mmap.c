#include <stdio.h>
#include <sys/mman.h>

// getting memory straight from the OS (without malloc)
// using malloc makes C more poratble (can still run on systems that don't have a mmap call)
int main(void)
{
    // args: void *addr, size_t len, int prot, int flags, int fd, off_t offset
    int *a = mmap(
        NULL,
        12 * sizeof(int),
        PROT_READ | PROT_WRITE,
        MAP_ANON | MAP_PRIVATE,
        -1,
        0); // should return a pointer if successful

    if (a == MAP_FAILED)
    {
        perror("mmap");
        return 1;
    }

    printf("%p\n", a);

    a[10] = 99;

    // malloc & free
    // mmap and munmap (can't use free, cannot free things not mmallo'ed)
    munmap(a, 12 * sizeof(int));

    // a[10] = 99; don't use memory after you've freed it!
}
