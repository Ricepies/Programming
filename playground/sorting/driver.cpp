#include <iostream>
#include <vector>
typedef int Item;
#define key(A) ((A))

bool less(Item A, Item B)
{
    return key(A) < key(B);
}

void exch(Item A, Item B)
{
    std::swap(A, B);
}

void compexch(Item A, Item B)
{
    if (less(A, B))
        exch(A, B);
}
