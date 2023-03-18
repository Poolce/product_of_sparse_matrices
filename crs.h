#include <list>
#include <random>
#include <iostream>

struct dot
{
    int i;
    int j;
    double val;

    dot(int _i, int _j, double _val) : i(_i), j(_j), val(_val) {}

    void out()
    {
        std::cout << i << " " << j << " " << val << "\n";
    }
};

struct Matrix
{
    int size;
    int nonZeroC;
    std::list<dot> nonZeroData;

    Matrix(int _size = 0) : size(_size), nonZeroC(0){}

    void randomize()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int randInt = rand() % 100;
                if (randInt > 75)
                {
                    nonZeroData.push_back(dot(i, j, randInt));
                    nonZeroC++;
                }
            }
        }
    }

    void out()
    {
        for (int _i = 0; _i < size; _i++)
        {
            for (int _j = 0; _j < size; _j++)
            {
                bool isnFind = true;
                for(auto val : nonZeroData){
                    if(val.i == _i&&val.j==_j)
                    {std::cout<<val.val<<" \t";
                    isnFind = false;
                    break;}
                }
                if(isnFind)std::cout<<0<<"\t";
            }
            std::cout<<"\n";
            
        }
    }
};
