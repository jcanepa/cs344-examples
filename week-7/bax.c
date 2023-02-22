#include <stdio.h>
#include <stdlib.h>

// some made-up random number that's unlikely to appear in regular usage
#define MAGIC 0x278a36c5

int main(void)
{
    // demo how to use a "magic number", which is used to prevent double frees
    char *s = mymalloc(10);

    myfree(s);
    myfree(s);

    // when using a struct block, add a magic number
    // in free, back up to the (padded) size of the struct block (since we're assuming we'd be passed the beginning of our data)
    // look into the struct block for the magic number is present before freeing
    // this prevents you from freeing the same memory twice
}

myfree(s)
{
    // if magic number is at s
    // print some error about double free & return
    // mark block free
    // write some magic number at s
}