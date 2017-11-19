#include <iostream>

using namespace std;
int a[101],k,n,p,sem,maxx,m;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]<a[i-1])sem=1;
    }
    if(sem==1)
    {
        m=n;
        for(int i=1;i<=n;++i)
        {
            maxx=0;
            for(int j=1;j<=m;++j)
            {
                if(maxx<=a[j])
                {
                    maxx=a[j];
                    p=j;
                }
            }
            for(int l=p;l<m;++l)cout<<l<<" "<<l+1<<'\n';
            swap(a[p],a[m]);\
            m--;
        }
    }
    return 0;
}
