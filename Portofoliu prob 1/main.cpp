#include <iostream>
#include <fstream>
using namespace std;
ifstream in("Numere.in");
ofstream out("Numere.out");
int cmmdc(int x,int y)
{
    while(x!=y)
    {
        if(x>y)x=x-y;
        else y=y-x;
    }
    return x;
}
int main()
{
    int x,y;
    while(in>>x>>y)
    {
        int d=cmmdc(x,y);
        out<<x/d<<" "<<y/d<<'\n';
    }
    return 0;
}
