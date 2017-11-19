#include <iostream>
#include <fstream>
using namespace std;
ifstream  in("piata.in");
ofstream out("piata.out");
long long s;
int sp[40005],it,im,jt,jm,n;
int pozstart,pozfinal;
int main()
{
    in>>n>>it>>jt>>im>>jm;
    for(int i=1;i<=n;++i)
    {
        sp[i]=sp[i-1]+i%100000/10000+i%10000/1000+i%1000/100+i%100/10+i%10;
    }
    pozstart=jt-it;///nu mai tb sa scad 1 la sp
    pozfinal=pozstart+1+jm-jt;
    if(pozfinal<1)pozfinal=pozfinal+n;
    if(pozstart<0)pozstart=pozstart+n;
    for(int i=it;i<=im;++i)
    {
        if(pozfinal>pozstart)s=s+sp[pozfinal]-sp[pozstart];
        else s=s+sp[n]-sp[pozstart]+sp[pozfinal];
        --pozfinal;
        --pozstart;
        if(pozfinal<1)pozfinal=pozfinal+n;
        if(pozstart<0)pozstart=pozstart+n;
    }
    out<<s;
    return 0;
}
