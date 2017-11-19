#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
int n,k;
string s[105];
int a[105][105],viz[105],pos,sem,ind,sol[105],d[105],ziua,minn;
int v[105][105];
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        for(int j=1;j<=k;++j)
        {
            cin>>a[i][j];
            if(j>2)
            {
                if(a[i][j]>a[i][j-1] && a[i][j-1]>a[i][j-2])
                {
                    v[i][j]=1;
                    ++d[i];
                    ++pos;
                }
            }
        }
    }
    while(pos)
    {
        sem=0;
        ///parcurgere de verif
        for(int i=1;i<=n && sem==0;++i)
        {
            if(d[i]==1)
            {
                ind=i;
                sem=1;
            }
        }
        /// daca am gasit o zi cu o singura posibilitate
        if(sem)
        {
            for(int j=1;j<=k;++j)if(v[ind][j])ziua=j;
            for(int i=1;i<=n;++i)
            {
                if(v[i][ziua])
                {
                    --pos;
                    --d[i];
                    v[i][ziua]=0;
                }
            }
            for(int j=1;j<=k;++j)v[ind][j]=0;
            pos-=d[ind];
            d[ind]=0;
            sol[ziua]=ind;
        }
        else///daca nu am gasit un id cu o singura posibilitate
        {
            minn=100000000;
            for(int i=1;i<=n;++i)
            {
                if(d[i]>0 && d[i]<minn)
                {
                    minn=d[i];
                    ind=i;
                }
            }
            ziua=0;
            for(int j=1;j<=k;++j)if(v[ind][j])ziua=j;
            for(int i=1;i<=n;++i)
            {
                if(v[i][ziua])
                {
                    --pos;
                    --d[i];
                    v[i][ziua]=0;
                }
            }
            for(int j=1;j<=k;++j)v[ind][j]=0;
            pos-=d[ind];
            d[ind]=0;
            sol[ziua]=ind;
        }
    }
    for(int i=1;i<=k;++i)
    {
        if(sol[i])cout<<s[sol[i]]<<'\n';
        else cout<<"none"<<'\n';
    }
    return 0;
}
///v[i][j]---zilele in care poate participa id i
///d[i]---nr de zile
