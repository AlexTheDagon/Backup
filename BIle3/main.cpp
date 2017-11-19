#include <iostream>
#include <fstream>
using namespace std;
ifstream in("bile3.in");
ofstream out("bile3.out");
int n,k,c[30],s;
void gen(int N,int K,int pas,int sens)
{
    int i,j;
    if(N<K)return;
    if(K==1)
    {
        if(sens)
        {
            for(i=N;i>0;--i)
            {
                out<<i<<" ";
                for(j=pas-1;j>=0;--j)out<<c[j]<<" ";
                out<<'\n';
            }
        }
        else
        {
            for(i=1;i<=N;++i)
            {
                out<<i<<" ";
                for(j=pas-1;j>=0;--j)out<<c[j]<<" ";
                out<<'\n';
            }
        }
    }
    else
    {
        if(sens)
        {
            c[pas]=N;
            gen(N-1,K-1,pas+1,0);
            gen(N-1,K,pas,1);
        }
        else
        {
            gen(N-1,K,pas,0);
            c[pas]=N;
            gen(N-1,K-1,pas+1,1);
        }
    }
}
int main()
{
    in>>n>>k;
    gen(n,k,0,0);
    return 0;
}
