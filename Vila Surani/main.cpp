#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
queue< pair<int,int> >Q;
ifstream fin("vila.in");
ofstream fout("vila.out");
const int Dx[]={-1,0,1,0};
const int Dy[]={0,1,0,-1};
const int INF=0x3f3f3f3f;
int D[150][150];
int arie[17000];
int nr[17000];
pair<int,int>afis[17000];
int n,m,newx,newy,nr_celule,maxim=0,iv,jv,maxtot=0,cont=0,act=0;
bool inside(int x,int y)
{
    return x>=1 && y>=1 && x<=n && y<=m;
}
void fill(int x,int y)
{
    nr_celule++;
    D[x][y]=act;
    for(int d=0;d<4;d++)
    {
        newx=x+Dx[d];
        newy=y+Dy[d];
        if(inside(newx,newy) && D[newx][newy]==-2)
            fill(newx,newy);
    }
}
void vecini(int i,int j)
{
    int s=1;
    for(int d=0;d<4;d++)
    {
        iv=i+Dx[d];
        jv=j+Dy[d];
        if(D[iv][jv]!=-1 && inside(iv,jv))
        {
            if(nr[D[iv][jv]]==0)
            {
               s+=arie[D[iv][jv]];
               nr[D[iv][jv]]=1;
            }
        }
    }
    if(s>maxtot)
    {
        maxtot=s;
        cont=1;
        afis[cont].first=i;
        afis[cont].second=j;
    }
    else
    {
        if(s==maxtot)
        {
            cont++;
            afis[cont].first=i;
            afis[cont].second=j;
        }
    }
    for(int d=0;d<4;d++)
    {
        iv=i+Dx[d];
        jv=j+Dy[d];
        if(inside(iv,jv) && D[iv][jv]!=-1)
        {
            nr[D[iv][jv]]=0;
        }
    }
}
bool ok(int i,int j)
{
    if(i<1 or j<1 or i>n or j>m or D[i][j]==0) return false;
    return true;
}
int main()
{
    char c;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            fin>>c;
            if(c==45)
                D[i][j]=-2;
            else
                D[i][j]=-1;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(D[i][j]==-2)
            {
                act++;
                nr_celule=0;
                fill(i,j);
                arie[act]=nr_celule;
                if(nr_celule>maxim)
                    maxim=nr_celule;
            }
        }
    fout<<act<<'\n'<<maxim<<'\n';
    maxim=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(D[i][j]==-1)
            {
                vecini(i,j);
            }
    for(int i=1;i<=cont;i++)
        fout<<afis[i].first<<" "<<afis[i].second<<" ";
    if(maxtot>0)
        fout<<maxtot;
    else fout<<0;
    return 0;
}
