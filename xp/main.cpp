#include <iostream>
#include <fstream>
using namespace std;
ifstream in("xp.in");
ofstream out("xp.out");
long long n,p,q,a,b,ac,bc,B,A,prod[2005],ps[2005],pd[2005],val[2005],prd[2005],prst[2005],P,paux,aux,intregi,rest,nn;
int main()
{
    in>>n>>a>>b>>p>>q;
    intregi=n/2000;
    rest=n%2000;
    if(rest)nn=intregi+1;
    A=a;
    B=b;
    for(int i=1;i<=2002;++i)prod[i]=1;
    for(int i=1;i<=n;++i)
    {
        prod[(i-1)/2000+1]*=max((long long)1,((i%p)^(((a+1)&(b+1))%p))%p);
        prod[(i-1)/2000+1]%=q;
        ac=((a+p-1)^(b+1))%p;
        bc=((a+p-1)|(b+1))%p;
        a=ac;
        b=bc;
    }
    a=A;
    b=B;
    for(int i=1;i<=2001;++i)pr[i]=1;
    for(int i=1;i<=2001;++i)
    {
        for(int j=1;j<=2001;++j)
        {
            if(i!=j)pr[i]=(pr[i]*prod[j])%q;
        }
    }
    for(int i=0;i<=2002;++i)ps[i]=pd[i]=1;
    for(int i=1;i<=n;++i)
    {
        val[(i-1)%2000+1]=max((long long)1,((i%p)^(((a+1)&(b+1))%p))%p);
        ac=((a+p-1)^(b+1))%p;
        bc=((a+p-1)|(b+1))%p;;
        a=ac;
        b=bc;
        ///calcul val
        if(i%2000==0)
        {
            for(int j=1;j<=2000;++j)ps[j]=(ps[j-1]*val[j])%q;
            for(int j=2000;j>0;--j)pd[j]=(pd[j+1]*val[j])%q;
            paux=pr[(i-1)/2000+1];
            for(int j=1;j<=2000;++j)
            {
                aux=1;
                aux*=ps[j-1];
                aux*=pd[j+1];
                aux=((aux%q)*paux)%q;
                P=P^aux;
            }
        }
    }
    for(int i=0;i<=2002;++i)ps[i]=pd[i]=1;
    if(n%2000)
    {
        for(int j=1;j<=n%2000;++j)ps[j]=(ps[j-1]*val[j])%q;
        for(int j=n%2000;j>0;--j)pd[j]=(pd[j+1]*val[j])%q;
        paux=1;
        for(int j=1;j<=intregi;++j)paux=(paux*prod[j])%q;
        for(int j=1;j<=n%2000;++j)
        {
            aux=1;
            aux*=ps[j-1];
            aux*=pd[j+1];
            aux=((aux%q)*paux)%q;
            P=P^aux;
        }
    }
    out<<P;
    return 0;
}
///se imparte in sqrt(n) bucati si se calculeaza prod pe buc
