#include <iostream>
#include <fstream>
using namespace std;
ifstream in("xp.in");
ofstream out("xp.out");
long long prod[2005],prd[2005],pd[2005],prs,ps,P,v[2005];
int a,b,n,p,q,aa,bb,act,pozz,fa[2005],fb[2005],val;
void gennr(int A,int B);
void gen();
void genn(int A,int B,int ind);
void genrest(int A,int B,int ind);


int main()
{
    in>>n>>a>>b>>p>>q;
    prs=1;
    ps=1;
    for(int i=0;i<=2003;++i)prod[i]=pd[i]=prd[i]=1;
    gen();
    ///bine
    for(int i=1;i<=n/2000;++i)
    {
        genn(fa[i],fb[i],(i-1)*2000+1);
        for(int j=1;j<=2000;++j)
        {
            P=P^((prd[i+1]*((pd[j+1]*ps)%q))%q);
            ps*=v[j];
            ps%=q;
        }
    }
    if(n%2000)
    {
        genrest(fa[n/2000+1],fb[n/2000+1],n/2000*2000+1);
        for(int j=1;j<=n%2000;++j)
        {
            P=P^((pd[j+1]*ps)%q);
            ps*=v[j];
            ps%=q;
        }
    }
    out<<P;
	return 0;
}









void gennr(int A,int B)
{
    a=((A+p-1)^(B+1))%p;
    b=((A+p-1)|(B+1))%p;

}///bine
void gen()
{
    for(int i=1;i<=n;++i)
    {
        ++pozz;
        if(pozz>0)
        {
            pozz-=2000;
            ++act;
            fa[act]=a;
            fb[act]=b;
        }
        prod[act]=(prod[act]*max(1,((i%p)^((a+1)&(b+1)))%p))%q;
        gennr(a,b);
    }
    for(int i=2001;i>0;--i)prd[i]=((prod[i]%q)*prd[i+1])%q;
}
void genn(int A,int B,int ind)
{
    a=A;
    b=B;
    for(int i=1;i<=2000;++i)
    {
        v[i]=max(1,((ind%p)^((a+1)&(b+1)))%p);
        gennr(a,b);
        ++ind;
    }
    pd[2001]=1;
    for(int i=2000;i>=1;--i)pd[i]=(v[i]*pd[i+1])%q;
    ///bine
}
void genrest(int A,int B,int ind)
{
    a=A;
    b=B;
    for(int i=1;i<=n%2000;++i)
    {
        v[i]=max(1,((ind%p)^((a+1)&(b+1)))%p);
        gennr(a,b);
        ++ind;
    }
    pd[n%2000+1]=1;
    for(int i=n%2000;i>=1;--i)pd[i]=(v[i]*pd[i+1])%q;
}
