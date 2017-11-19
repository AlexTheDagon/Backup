#include <iostream>
#include <algorithm>
using namespace std;
int n,a[100001],b[100001],i,j;
int main()
{
    cin>>n;
    for(int l=1;l<=n;++l)cin>>a[l];
    sort(a+1,a+n+1);
    j=1;
    i=1;
    while(i<=n)
    {
        if(b[j]==0)
        {
            if(a[i]>=j)
            {
                b[j]=1;
                a[i]=j;
            }
            ++i;
        }
        else
        {
            ++j;
        }
    }
    i=1;
    while(b[i]!=0)++i;
    cout<<i;
    return 0;
}
