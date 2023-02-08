int main(void)
{
    int i;
    float f;
    float *p;
    float **q;

    1 + 3;   // int
    1.0 + 3; // float

    // type of expression is the type of the lefthand side of the assignment
    i = 1 + 3; // int

    f = 1 + 3; // type coerced into a float

    f;  // float
    &f; // address-of gives a pointer to a float

    &p; // pointer to a pointer to a float, float**

    q = &p; // float**

    *q; // dereferences q, float pointer, inverse of the & operator
    // float * (take away one of the addresses)

    // & address-of
    // * dereference

    **q; // float
    // ***q; is an error (can't dereference more levels than we have indirection)

    // q = &f;
    // this assignment throws an error (incompatable pointer types) because:
    // left: float***
    // right: float *

    return 0;
}
