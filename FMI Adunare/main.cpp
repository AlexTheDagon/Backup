#include <iostream>
#include <fstream>
using namespace std;
ifstream in("readunare.in");
ofstream out("readunare.out");
string a,b,sol,aux;
int nra,nrb,nr,c,f1,f2,f3;
int main()
{
    in>>a>>b;
    for(auto i:a)if(i=='{')++nra;
    for(auto i:b)if(i=='{')++nrb;
    --nra;
    --nrb;
    f3=1;
    for(c=1;f3<nra;++c)f3=2*f3+1;
    nra=c;
    if(a.size()==2)nra=0;
    f3=1;
    for(c=1;f3<nrb;++c)f3=2*f3+1;
    nrb=c;
    if(b.size()==2)nrb=0;
    nr=nra+nrb;
    sol="{}";
    for(int i=2;i<=nr;++i)
    {
        aux=sol;
        sol+=",{";
        sol+=aux;
        sol+='}';
    }
    if(nr!=0)
    {
        out<<'{';
        for(int i=sol.size()-1;i>=0;--i)
        {
            if(sol[i]=='{')out<<'}';
            else
            {
                if(sol[i]=='}')out<<'{';
                else out<<',';
            }
        }
        out<<'}';
    }
    else out<<sol;
    return 0;
}
