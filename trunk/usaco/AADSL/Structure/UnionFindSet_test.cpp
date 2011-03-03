#include <iostream>
#include <cstdlib>
#include "UnionFindSet.cpp"
using namespace std;

int main()
{
    UFSet* sets = new UFSet(1000);

    sets->combine(1, 2);
    sets->combine(1, 3);
    if (sets->findSet(1) == sets->findSet(3))
        cout << "ok" << endl;
    return 0;
}
