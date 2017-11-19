#include <iostream>
#include <fstream>
using namespace std;
ifstream in("aiacuhexagoane.in");
ofstream out("aiacuhexagoane.out");
long long n,m,q,a,b,ea,eb;
long long gen(long long x);
int main()
{
    in>>n>>m>>q;
    while(q)
    {
        --q;
        in>>a>>b;
        if(n>1)
        {
            ea=gen(--a);
            eb=gen(--b);
            if(ea==eb)out<<"da";
            else out<<"nu";
        }
        else out<<"nu";
        out<<'\n';
    }
    return 0;
}
long long gen(long long x)
{
    int ex=x%(2*m-1)+1;
    if(ex>m)
    {
        ex-=m;
        ex+=2;
    }
    return ex%3;
}
