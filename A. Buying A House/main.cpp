#include <iostream>

using namespace std;
int st,dr,k,n,a[105],sem,minn,m;
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    sem=1;
    st=dr=m;
    while(sem)
    {
        if(st>1)--st;
        if(dr<n)++dr;
        if(a[st]<=k && a[st]!=0)
        {
            cout<<(m-st)*10;
            return 0;
        }
        if(a[dr]<=k && a[dr]!=0)
        {
            cout<<(dr-m)*10;
            return 0;
        }
    }
    return 0;
}
