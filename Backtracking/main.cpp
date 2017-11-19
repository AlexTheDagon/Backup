#include <iostream>

using namespace std;
int fol[10],v[10],n;
void gen(int p)
{
    if(p>n)
    {
        for(int i=1;i<=n;++i)cout<<v[i]<<" ";
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;++i)
    {
        if(fol[i]==0)
        {
            fol[i]=1;
            v[p]=i;
            gen(p+1);
            fol[i]=0;
        }
    }
}
int main()
{
    cin>>n;
    gen(1);
    return 0;
}
