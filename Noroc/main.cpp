#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream in("noroc.in");
ofstream out("noroc.out");
int x,y;
double rez=1;
int main()
{
    in>>x>>y;
    for(int i=1;i<=x;++i)
    {
        rez/=2.0;
    }
    out<<fixed<<setprecision(7)<<rez;
    return 0;
}
