#include <iostream>
#include "crs.h"

using std::cout;

Matrix getSeqMult(Matrix a, Matrix b)
{
    Matrix c(a.size);
    for (auto dotA : a.nonZeroData)
    {
        for (auto dotB : b.nonZeroData)
        {
            bool notFind = true;
            for (auto dotC : c.nonZeroData)
            {
                if (dotC.i == dotA.i && dotC.j == dotA.j)
                {
                    dotC.val += dotA.val * dotB.val;
                    notFind = false;
                    break;
                    
                }
            }
            if (notFind)
            {
                c.nonZeroData.push_back(dot(dotA.i, dotB.j, dotA.val * dotB.val));
                c.nonZeroC++;
            }
        }
    }
    return c;
}

int main()
{
    Matrix a(3);
    a.randomize();
    a.out();
    std::cout<<"\n\n";
    Matrix b(3);
    b.randomize();
    b.out();
    std::cout<<"\n\n";

    Matrix c = getSeqMult(a,b);
    c.out();
}