#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

ifstream fin ("3cifre.in");
ofstream fout ("3cifre.out");

long long c[500000];
int main()
{
    long long n,x,aux,uc,nrmin,nrmax,mn,mx;
    fin>>n>>x;
    nrmin=INT_MAX;
    nrmax=INT_MIN;
    mn=INT_MAX;
    mx=INT_MIN;
    for (int i=1;i<=n;i++)
        fin>>c[i];
    for (int i=1;i<=n;i++)
    {
        aux=c[i];
        while (aux>0)
        {
            uc=aux%10;
            aux/=10;
            if (aux%100!=aux%10&&aux<mn)
            {
                mn=aux%100;
                nrmin=c[i];
            }
            if (aux%100!=aux%10&&aux>mx)
            {
                mx=aux%100;
                nrmax=c[i];
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        aux=c[i];
        while (aux>0)
        {
            uc=aux%10;
            aux/=10;
            if (aux%100!=aux%10&&aux<mn)
            {
                mn=aux%100;
                nrmin=c[i];
            }
            if (aux%100!=aux%10&&aux>mx)
            {
                mx=aux%100;
                nrmax=c[i];
            }
        }
    }
    if (x==1)
        cout<<mn<<" "<<contormin<<" "<<nrmin<<" "<<nrmax;
    return 0;
}
