#include "IntStr.h"
#include <iostream>

using namespace std;

int main()
{


    Intarr a(5);
    a.printarr();
    Intarr b(5);
    b.printarr();
    Intarr c;
    c=b+3;
    c.printarr();

    return 0;
}
