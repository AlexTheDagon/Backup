#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int x[100][100],n,m;
void oglindirelinie(int x[100][100])
{
    for(int i=1;i<=n/2;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int aux=x[i][j];
            x[i][j]=x[i+n-1][j];
            x[i+n-1][j]=aux;
        }
    }
}
void oglindirecoloana(int x[100][100])
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m/2;j++)
        {
            int aux=x[i][j];
            x[i][j]=x[i][m+1-j];
            x[i][m+1-j]=aux;
        }
    }
}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            fin>>x[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            fout<<x[i][j]<<" ";
        fout<<"\n";
    }
    return 0;
}
