#include <iostream>
#include <vector>
using namespace std;
int a[1005][1005],n,m,k,c[1005],x,y,fol[1005],l[1005],lmax,nrleg;
vector <int> v[1005];
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=k;++i)
    {
        cin>>x;
        c[x]=1;
    }
    for(int i=1;i<=m;++i)
    {
        cin>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
        fol[x]=1;
        fol[y]=1;
        l[x]++;
        l[y]++;
        lmax=max(l[x],max(l[y],lmax));
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;++i)
    {
        if(l[i]>0)
        {
            for(int j=0;j<l[i];++j)
            {
                if(a[i][v[i][j]]==0 && (c[i]==0 || c[v[i][j]]==0))
                {
                    ++nrleg;
                }
            }
        }
    }
    cout<<nrleg<<endl<<endl;
    for(int i=1;i<=n;++i)
    {
        lmax=0;
        if(fol[i]==0)
        {
            for(int j=1;j<=n;++j)
            {
                if(i!=j && (c[i]==0 || c[j]==0))
                {
                    if(l[i]>lmax || l[j]>lmax)
                    {
                        if(l[i]>l[j])
                        {
                            lmax=l[i];
                            l[i]++;
                        }
                        else
                        {
                            lmax=l[j];
                            l[j]++;
                        }
                        cout<<l[i]<<" "<<i<<endl<<l[j]<<" "<<j<<endl<<lmax<<endl<<endl;
                    }

                }
            }
            nrleg+=lmax;
        }
    }
    cout<<nrleg;
    return 0;
}
