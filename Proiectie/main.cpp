#include <iostream>
#include <fstream>
using namespace std;
ifstream in("proiectie.in");
ofstream out("proiectie.out");
int y1max=-100000000,x1max=-10000000,y2max=-10000000,x2max=-10000000,y1min=10000000,y2min=10000000,x1min=10000000,x2min=10000000,n,x,y;

int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>x>>y;
        if(x>x1max)
        {
            x1max=x;
            y1max=y;
        }
        else
        {
            if(x==x1max && (y1max-y1min)>y1max-y)y1max=y;
            if(x<x1min)
            {
                x1min=x;
                y1min=y;
            }
        }
        if(y>y2max)
        {
            y2max=y;
            x2max=x;
        }
        else
        {
            if(y==y2max && x2max-x2min>x2max-x)x2max=x;
            if(y<y2min)
            {
                y2min=y;
                x2min=x;
            }
        }
    }
    out<<max((x1max-x1min-y1max+y1min),(x2max-x2min+y2min-y2max));
    return 0;
}
