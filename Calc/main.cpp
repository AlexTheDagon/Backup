#include <iostream>
#include <fstream>
using namespace std;
ifstream in("calc.in");
ofstream out("calc.out");
string s,pre,urm;
int p,n,a[100005],sem,ii,poz;
int main()
{
    in>>p;
    in>>n>>s;
    if(p==1)
    {
        a[0]=1;
        a[1]=1;
        for(int i=2;i<=n;++i)a[i]=(a[i-1]+a[i-2])%1000000007;
        out<<a[n];
    }
    else
    {
        ///generarea zilei x+1
        for(auto i:s)if(i=='1')++sem;
        if(sem==n)urm="-1";
        else
        {
            if(s[n-1]=='1')
            {
                for(poz=1;s[n-poz]=='1';++poz);
                --poz;
                urm=s;
                if(poz%2)
                {
                    urm[n-poz-2]='1';
                    for(int i=n-poz-1;i<n;++i)urm[i]='0';
                }
                else
                {
                    urm[n-poz-2]='1';
                    for(int i=n-poz-1;i<n;++i)urm[i]='0';
                    urm[n-1]='1';
                }
            }
            else
            {
                for(poz=1;s[n-poz]=='0';++poz);
                --poz;
                urm=s;
                urm[n-1]=urm[n-2]='1';
            }
        }
        ///bine
        ///generarea zile x-1
        sem=0;
        for(int i=0;i<n;++i)if(s[i]=='1')++sem;
        if(sem==0 || (n%2==1 && sem==1 && s[n-1]=='1'))pre="-1";
        else
        {
            pre=s;
            if(s[n-1]=='1')
            {
                for(poz=1;s[n-poz]=='1';++poz);
                --poz;
                pre=s;
                if(poz!=1)pre[n-2]=pre[n-1]='0';
                else
                {
                    ++poz;
                    while(s[n-poz]=='0')++poz;
                    pre[n-poz]=pre[n-poz+1]='0';
                    poz-=2;
                    for(int i=n-poz;i<n;++i)pre[i]='1';
                }
            }
            else
            {
                for(poz=1;s[n-poz]=='0';++poz);
                pre=s;
                pre[n-poz]=pre[n-poz+1]='0';
                for(int i=n-poz+2;i<n;++i)pre[i]='1';
            }
        }
        out<<pre<<'\n'<<urm;
    }
    return 0;
}



