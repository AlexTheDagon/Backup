#include <iostream>
#include <fstream>
#include <cstdlib>
#define l 12500020
using namespace std;
ifstream in("eqs.in");
ofstream out("eqs.out");
int fol[25000000];
int sol,a1,a2,a3,a4,a5;
int main()
{
    in>>a1>>a2>>a3>>a4>>a5;
    for(int i=-50;i<=50;++i)
    {
        for(int j=-50;j<=50;++j)
        {
            if(i*j!=0)
            {
                ++fol[a1*i*i*i+a2*j*j*j+l];
            }
        }
    }
    for(int i=-50;i<=50;++i)
    {
        for(int j=-50;j<=50;++j)
        {
            for(int k=-50;k<=50;++k)
            {
                if(i*j*k!=0 && abs(a3*i*i*i+a4*j*j*j+a5*k*k*k)<12500010)
                {
                    sol+=fol[a3*i*i*i+a4*j*j*j+a5*k*k*k+l];
                }
            }
        }
    }
    out<<sol;
    return 0;
}
