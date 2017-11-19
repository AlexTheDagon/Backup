#include <iostream>

using namespace std;
char a[101];
int n,d,p[101],s,smax;
int main()
{
    cin>>n;
    cin>>d;
    for(int i=1;i<=d;++i)
    {
        cin>>a;
        for(int j=0;j<n;++j)if(a[j]=='1')p[i]++;
    }
    for(int i=1;i<=d;++i)
    {
        if(p[i]==n)
        {
            if(s>smax)smax=s;
            s=0;
        }
        else ++s;
    }
    if(s>smax)smax=s;
    cout<<smax;
    return 0;
}
