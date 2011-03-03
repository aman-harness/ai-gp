#include <iostream>
#include <cstdlib>
#include "HeapTree.cpp"
using namespace std;

int main()
{
    HeapTree<int, int>* h = new HeapTree<int, int>(1000000);
    for(int i=1;i<1000000;i++)
    {
        h -> insert(i, i*10);
    }
    int x[1];
    h -> getTopID(x);
    cout << *x << endl;
    h -> getTopData(x);
    cout << *x << endl;
    return 0;
}
