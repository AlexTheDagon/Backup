#include <iostream>
#include <fstream>
#include <vector>
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define inf 1e9
using namespace std;
ifstream in("dreptunghiuri2.in");
ofstream out("dreptunghiuri2.out");
int n,m,a[1005][1005],sp[1005][1005],nr,imin,jmin;
bool viz[1005][1005];
vector <pair<int,int> > v;
int omax,nrmax;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            in>>a[i][j];

    for(int i=1;i<=n;++i)///de verif ca nu sunt sigur daca pote sa fie si 1 care nu apartine de dr
    {
        for(int j=1;j<=m;++j)
        {
            if(a[i][j]==1 && viz[i][j]==0)
            {
                v.pb(mp(i,j));
                ++nr;
                imin=i;
                jmin=j;
                while(a[i][jmin]==1)++jmin;
                while(a[imin][j]==1)++imin;
                ++sp[i][j];
                --sp[i][jmin];
                --sp[imin][j];
                ++sp[imin][jmin];
                for(int l=i;l<imin;++l)viz[l][j]=viz[l][jmin-1]=1;
                for(int c=j;c<jmin;++c)viz[i][c]=viz[imin-1][c]=1;
            }
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)sp[i][j]=sp[i][j]+sp[i-1][j]+sp[i][j-1]-sp[i-1][j-1];
    for(auto i:v)
    {
        if(sp[i.x][i.y]>omax)
        {
            omax=sp[i.x][i.y];
            nrmax=1;
        }
        else if(sp[i.x][i.y]==omax)++nrmax;
    }
    out<<nr<<" "<<omax<<" "<<nrmax;
    return 0;
}
