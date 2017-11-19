#include <iostream>
#include <fstream>
#define NM 100005
using namespace std;
ifstream in("arbint.in");
ofstream out("arbint.out");
int ait[4*NM],n,v[NM],m,cc,aa,bb;
void upd(int poz,int a,int val,int st,int dr)
{
    int mij=(st+dr)/2;
    if(st==dr && st==a)
    {
        ait[poz]=val;
        return;
    }
    if(a>dr || a<st)return;
    upd(poz*2,a,val,st,mij);
    upd(poz*2+1,a,val,mij+1,dr);
    ait[poz]=max(ait[poz*2],ait[poz*2+1]);
}
void build(int poz,int st,int dr)
{
    int mij=(st+dr)/2;
    if(st==dr)
    {
        ait[poz]=v[st];
        return;
    }
    build(poz*2,st,mij);
    build(poz*2+1,mij+1,dr);
    ait[poz]=max(ait[poz*2],ait[poz*2+1]);
}
int query(int poz,int a,int b,int st,int dr)
{
    int mij=(st+dr)/2;
    if(a<=st && dr<=b)return ait[poz];
    if(a>dr || b<st)return -1;
    return max(query(poz*2,a,b,st,mij),query(poz*2+1,a,b,mij+1,dr));
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)in>>v[i];
    build(1,1,n);
    for(int i=1;i<=m;++i)
    {
        in>>cc>>aa>>bb;
        if(cc==1)upd(1,aa,bb,1,n);
        else out<<query(1,aa,bb,1,n)<<'\n';
    }
    return 0;
}
///a st dr b
