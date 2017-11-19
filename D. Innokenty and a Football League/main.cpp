#include <iostream>

using namespace std;
int n,r[1005],sem,e[1005],fol;
string s,a,b,t[3][1005],nume[1005];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a>>b;
        s+=a[0];
        s+=a[1];
        s+=b[0];
        t[2][i]=s;
        s="";
        s+=a[0];
        s+=a[1];
        s+=a[2];
        t[1][i]=s;
        s="";
    }
    for(int i=1;i<=n;++i)
    {
        fol=0;
        for(int j=1;j<=n;++j)
        {
            if(i!=j)
            {
                if(t[1][i]==t[1][j] || t[1][i]==t[2][j])fol=1;
            }
        }
        if(fol==1)nume[i]=t[2][i];
        else nume[i]=t[1][i];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(i!=j && nume[i]==nume[j])sem=1;
        }
    }
    if(sem)cout<<"NO";
    else
    {
        cout<<"YES"<<'\n';
        for(int i=1;i<=n;++i)cout<<nume[i]<<'\n';
    }
    return 0;
}

