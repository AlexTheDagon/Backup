#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("clepsidru.in");
ofstream out("clepsidru.out");
long sus,jos,n,k,b,a0,an,s,sens,i;
void sens1(int x);
void sens2(int x);
int main()
{
    fin>>n>>b;
    jos=a0=an=0;
    sus=1-b;
    out<<n+b-1<<"\n";
    fin>>k;
    for(i=1;i<=k;i++)
    {
        fin>>s>>sens;
        if(sens==1)sens1(s);
        else sens2(s);
    }
    if(sus<=0)a0=1-sus;
    if(jos>=n)an=jos-n+1;
    out<<a0<<" ";
    for(i=1;i<n;i++)
    {
        if((i>=sus)&&(i<=jos))
        {
            if(sens==1)out<<"0"<<'\n'<<"1 ";
            else out<<"1"<<'\n'<<"0 ";
        }
        else out<<'0'<<'\n'<<"0 ";
    }
    out<<an<<'\n';
    return 0;
}
void sens1(int x)
{
    if(sus<n)
    {
        sus+=x;
        jos+=x;
        if(sus>=n)
        {
            sus=n;
            jos=n+b-1;
        }
    }
}
void sens2(int x)
{
    if(jos>0)
    {
        jos-=x;
        sus-=x;
        if(jos<=0)
        {
            jos=0;
            sus=1-b;
        }
    }
}
