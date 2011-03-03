#include <iostream>
#include <HeapTree.h>
#include <UnionFindSet.h>
using namespace std;

void HeapTree_test()
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
}

void UnionFindSet_test()
{
    UFSet* sets = new UFSet(1000);

    sets->combine(1, 2);
    sets->combine(1, 3);
    if (sets->findSet(1) == sets->findSet(3))
        cout << "ok" << endl;
}

int main()
{
    cout << "Hello world!" << endl;
    UnionFindSet_test();
    HeapTree_test();
    return 0;
}
