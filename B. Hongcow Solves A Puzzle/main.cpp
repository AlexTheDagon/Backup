#include <iostream>

using namespace std;
int imin=5000,jmin=5000,imax,jmax,n,m,nr;
char c;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>c;
            if(c=='X')
            {
                imin=min(imin,i);
                jmin=min(j,jmin);
                imax=max(i,imax);
                jmax=max(j,jmax);
                ++nr;
            }
        }
    }
    if(nr==(imax-imin+1)*(jmax-jmin+1))cout<<"YES";
    else cout<<"NO";
    return 0;
}
