#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cctype>
#define x first
#define y second
#define mp make_pair
#define NM 62
#define KM 12

using namespace std;
typedef pair<int,int> fr;
ifstream in("miting.in");
ofstream out("miting.out");
int n,m,k,dmin[KM][KM][NM][NM],im=10000000,jm=1000000,iM,jM,v,lng;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
string cuv,mt[NM];


int pozitie(char x)
{
    for(int i=0;i<cuv.size();++i)if(cuv[i]==x)return i;
}///bine
int ins(int i,int j)
{
    if(i<n && i>=0 && j<m && j>=0)return 1;
    return 0;
}///bine
void bfs(int s,int d,int sx,int sy)
{
    queue <fr> q;
    for(q.push(mp(sx,sy)); !q.empty();)
    {
        fr pereche=q.front();
        q.pop();
        for(int h=0;h<4;++h)
        {
            int ii=pereche.x+dx[h];
            int jj=pereche.y+dy[h];
            if(ins(ii,jj)&& mt[ii][jj]!='#' && dmin[s][d][ii][jj]>dmin[s][d][pereche.x][pereche.y]+1)
            {
                dmin[s][d][ii][jj]=dmin[s][d][pereche.x][pereche.y]+1;
                q.push(mp(ii,jj));
            }
        }
    }
}

int main()
{
    in>>v>>n>>m>>cuv;
    in.get();
    for(int i=0;i<n;++i)getline(in,mt[i]);
    ///bine
    lng=cuv.size();
    for(int i=0;i<lng;++i)
    {
        for(int j=0;j<lng;++j)
        {
            for(int w=0;w<n;++w)
            {
                for(int e=0;e<m;++e)
                {
                    dmin[i][j][w][e]=(1<<30);
                }
            }
        }
    }
    ///bine
    if(v==2)
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(isalpha(mt[i][j]))
                {
                    int poz=pozitie(mt[i][j]);
                    dmin[poz][poz][i][j]=0;
                    bfs(poz,poz,i,j);
                }
            }
        }
        ///bine
        for(int l=2;l<=lng;++l)
        {
            for(int s=0;s+l-1<lng;++s)
            {
                int d=s+l-1;
                for(int i=0;i<n;++i)
                {
                    for(int j=0;j<m;++j)
                    {
                        for(int x=s; x<d; ++x) if(dmin[s][x][i][j]!=(1<<30) && dmin[x+1][d][i][j]!=(1<<30))
                            dmin[s][d][i][j]=min(dmin[s][d][i][j],dmin[s][x][i][j]+dmin[x+1][d][i][j]);
                        bfs(s,d,i,j);
                    }
                }
            }
        }
        ///bine
        int minim=(1<<30);
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)minim=min(minim,dmin[0][lng-1][i][j]);
        out<<minim;
    }
    else
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(isalpha(mt[i][j]))
                {
                    im=min(im,i);
                    iM=max(iM,i);
                    jm=min(j,jm);
                    jM=max(jM,j);
                }
            }
        }
        out<<(iM-im+1)*(jM-jm+1);
    }
    return 0;
}
