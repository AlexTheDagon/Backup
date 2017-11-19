#include <iostream>
#include <fstream>
using namespace std;
ifstream in("classictask.in");
ofstream out("classictask.out");
long long a,b,c;
long long inmultire(long long k,long long l)
{
    long long cifx[20]={0},cify[20]={0},cif[40]={0},r,x,y,cx=0,cy=0,nr,i,j;
    x=k;
    y=l;
    for(i=0;y>0;++i)
    {
        cify[i]=y%10;
        y=y/10;
        ++cy;
    }
    for(i=0;x>0;++i)
    {
        cifx[i]=x%10;
        x=x/10;
        ++cx;
    }
    r=0;
    for(i=0;i<cx;++i)
    {
        for(j=0;j<cy;++j)
        {
            cif[i+j]=cif[i+j]+cifx[i]*cify[j]+r;
            r=cif[i+j]/10;
            cif[i+j]%=10;
        }
        if(r)
        {
            cif[i+j]+=r;
        }

    }
    nr=0;
    for(i=18;i>=0;--i)
    {
        nr=nr*10+cif[i];
    }
    return nr;
}
long long logaritmputere(long long a,long long b,long long c)
{
    if(b==0)return 1;
    else if(b%2==0)return logaritmputere(inmultire(a,a)%c,b/2,c);
    return inmultire(logaritmputere(inmultire(a,a)%c,b/2,c),a)%c;
}
int main()
{
    in>>a>>b>>c;
    out<<logaritmputere(a%c,b,c)<<'\n';
    return 0;
}
