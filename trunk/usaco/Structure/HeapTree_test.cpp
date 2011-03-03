#include <iostream>
#include <cstdlib>
#include "HeapTree.cpp"
using namespace std;

int main()
{
    HeapTree<int, int>* h = new HeapTree<int, int>();
    h -> insert(1, 3);
    h -> insert(3, 1);
    h -> insert(2, 2);

    int x[1];
    h -> getTopID(x);
    cout << *x << endl;
    return 0;
}
