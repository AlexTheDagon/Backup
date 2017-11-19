#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("taxe2.in");
ofstream fout("taxe2.out");
int S,n,mat[110][110],sol[110][110],k=0;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int main()
{
    fin>>S>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            {
            fin>>mat[i][j];
            sol[i][j]=99999;
            }
    for(int i=1;i<=n;i++)
    {
        sol[i][0]=99999;
        sol[0][i]=99999;
        sol[i][n+1]=99999;
        sol[n+1][i]=99999;
    }
    k=n+n;
    sol[1][1]=mat[1][1];
    while(k>0)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(!(i==1 && j==1))
                {
                    for(int d=0;d<=3;d++)
                    {
                        sol[i][j]=min(sol[i][j],sol[i+dx[d]][j+dy[d]]+mat[i][j]);
                    }
                }
            }
        }
        k--;
    }
    if(S-sol[n][n]>=0)
        fout<<S-sol[n][n]<<"\n";
    else fout<<-1<<"\n";
    return 0;
}
