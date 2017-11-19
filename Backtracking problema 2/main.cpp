#include <iostream>

using namespace std;
int n,v[10],fol[10],k;
int gen(int x,int p)
{
    if(p>k)
    {
        for(int i=1;i<=k;++i)cout<<v[i]<<" ";
        cout<<endl;
    }
    else
    {
        for(int i=x;i<=n;++i)
        {
            if(fol[i]==0)
            {
                v[p]=i;
                fol[i]=1;
                gen(i+1,p+1);
                fol[i]=0;
            }
        }
    }
}

int main()
{
    cin>>n>>k;
    gen(1,1);
    return 0;
}

