#include <iostream>
#include <fstream>
#define prim 666013
using namespace std;
ifstream in("kfib.in");
ofstream out("kfib.out");
long long M[3][3],n,SOL[3][3];
void mult(long long A[][3],long long B[][3],long long C[][3])
{
    for(int i=1;i<=2;++i)
        for(int j=1;j<=2;++j)
            for(int k=1;k<=2;++k)
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%prim;
}///bine
long long lgput(long long put)
{
    long long Z[3][3],ZC[3][3],CSOL[3][3];
    Z[1][1]=0;
    Z[1][2]=Z[2][1]=Z[2][2]=1;
    SOL[1][1]=SOL[2][2]=1;
    for(int i=1;i<=2;++i)
        for(int j=1;j<=2;++j)
            ZC[i][j]=Z[i][j];
    for(int i=0;(1<<i)<=put;++i)
    {
        if(put&(1<<i))
        {
            for(int i=1;i<=2;++i)
                for(int j=1;j<=2;++j)CSOL[i][j]=SOL[i][j];
            for(int i=1;i<=2;++i)
                for(int j=1;j<=2;++j)SOL[i][j]=0;
            mult(CSOL,Z,SOL);
        }
        for(int i=1;i<=2;++i)
            for(int j=1;j<=2;++j)ZC[i][j]=Z[i][j];
        for(int i=1;i<=2;++i)
            for(int j=1;j<=2;++j)Z[i][j]=0;
        mult(ZC,ZC,Z);
    }
}
long long AA[3][3],BB[3][3],CC[3][3];
int main()
{
    in>>n;
    lgput(n-1);
    out<<SOL[2][2];
    return 0;
}
