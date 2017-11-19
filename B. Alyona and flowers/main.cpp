#include <iostream>

using namespace std;
int f[105],sp[105],l,r,fr[105],n,m,s;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>f[i];
        sp[i]=sp[i-1]+f[i];
    }
    for(int i=1;i<=m;++i)
    {
        cin>>l>>r;
        if((sp[r]-sp[l-1])>0)s+=sp[r]-sp[l-1];
    }
    cout<<s;
    return 0;
}
