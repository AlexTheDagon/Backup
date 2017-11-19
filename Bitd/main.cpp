#include <iostream>

using namespace std;
int n,x,maxx,desc[50],p,minn,nou;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        minn=0;
        maxx=0;
        for(int j=0;j<=30;++j)
        {
            if(x&(1<<j))
            {
                desc[j]=1;
                maxx=j;
            }
        }
        while(minn<maxx && desc[minn]!=1)++minn;
        while(desc[maxx]!=0 && maxx>=0)--maxx;
        if(minn<maxx)
        {
            swap(desc[minn],desc[maxx]);
            p=1;
            nou=0;
            for(int j=0;j<=30;++j)if(desc[j])nou+=(1<<j);
            cout<<nou<<" ";
        }
        else cout<<x<<" ";
        for(int j=0;j<=40;++j)desc[j]=0;
    }
    return 0;
}
