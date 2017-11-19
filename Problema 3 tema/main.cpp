#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int x[105],y[105],k,i,j;
int main()
{
    in>>k;
    while(in>>x[++i]);
    --i;
    for(int ii=1;ii<=i;++ii)
    {
        int jj=ii;
        while(jj>1 && x[jj]<x[jj-1])
        {
            swap(x[jj],x[jj-1]);
            --jj;
        }
    }
    for(int ii=1;(ii<=k || x[ii]<0) && ii<=i;++ii,++j)y[ii]=x[ii];
    for(int ii=1;ii<=j;++ii)cout<<y[ii]<<" ";
    return 0;
}
