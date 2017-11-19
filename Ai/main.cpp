#include <iostream>
#include <fstream>
#include <queue>
#define NM 1005
#define x first
#define y second
#define mp make_pair
#include <stdlib.h>
using namespace std;
ifstream in("ai.in");
ofstream out("ai.out");
int n,k;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int a[NM][NM],rob1[NM][NM],rob2[NM][NM];
pair <int,int> fr,t,s1,s2,r1,r2;
int l,lmax,col,lin,ii,jj,ist,ifin,jst,jfin;
queue<pair<int,int> > q,dest1,dest2;
bool viz1[NM][NM],viz2[NM][NM];
double tg1,tg2;
int ok(int i,int j)
{
    return (i>0 && i<=n && j>0 && j<=n);
}
double tg(int a,int b)
{
    if(b==0)return 0;
    return 1,0*a/b;
}
int main()
{
    in>>n;
    in>>t.x>>t.y;
    in>>s1.x>>s1.y>>s2.x>>s2.y;
    in>>r1.x>>r1.y>>r2.x>>r2.y;
    in>>k;
    for(int i=1;i<=k;++i)
    {
        in>>lin>>col;
        a[lin][col]=-1;
    }
    a[t.x][t.y]=-1;///prelurarea matricii initiale
    ///gasirea zidului de lungime max
    for(int i=0;i<=n+1;++i)
    {
        for(int j=0;j<=n+1;++j)
        {
            if(a[i][j]==-1)++l;
            else l=0;
            lmax=max(l,lmax);
        }
    }

    l=0;
    for(int i=0;i<=n+1;++i)
    {
        for(int j=0;j<=n+1;++j)
        {
            if(a[j][i]==-1)++l;
            else l=0;
            lmax=max(l,lmax);
        }
    }
    out<<lmax<<'\n';
    ///gasirea zonelor de blocarea a laserului
    tg1=tg(abs(s1.x-t.x),abs(s1.y-t.y));
    tg2=tg((s2.x-t.x),abs(s2.y-t.y));

    return 0;
}




de verificat tangenta punctelor(sa verific sa nu impart la 0)
de pus fiecare punt in destinatie
de luat minimele din parti opuse

