#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#define NM 55
using namespace std;
ifstream in("monezi2.in");
ofstream out("monezi2.out");
int n,a[NM],q,s,cs,sem;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>a[i];
    in>>q;
    for(int i=1;i<=q;++i)
    {
        in>>s;
        sem=0;
        for(int i=1;i<n && sem==0;++i)
        {
            for(int j=i+1;j<=n && sem==0;++j)
            {
                cs=s-a[j];
                while(s%a[i]!=cs%a[i] && cs%a[i]!=0 && cs>=0)cs-=a[j];
                if(cs/a[i]>=(s-cs)/a[j] && cs%a[i]==0)sem=1;
            }
        }
        if(sem)out<<"DA";
        else out<<"NU";
        out<<'\n';
    }
    return 0;
}
