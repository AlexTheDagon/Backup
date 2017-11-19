#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("zimeria.in");
ofstream out("zimeria.out");
int p,n,lit[150],aux;
char nr[150];
int dif;
string m[400005];
string s,ord;
int main()
{
    in>>p;
    in>>n;
    in>>ord;
    if(p==1)
    {
        for(int i=1;i<=n;++i)
        {
            in>>m[i];
        }
        sort(m+1,m+n+1);
        for(int i=1;i<=n;++i)if(m[i]!=m[i-1])++dif;
        out<<dif;
    }
    else
    {
        int a[400005];
        for(int i=0;i<12;++i)
        {
            nr[i]=ord[i];
            lit[ord[i]]=i;
        }
        for(int i=1;i<=n;++i)
        {
            in>>s;
            a[i]=0;
            for(auto j:s)a[i]=a[i]*100+lit[j];
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;++i)
        {
            aux=a[i];
            s="";
            while(aux)
            {
                s+=nr[aux%100];
                aux/=100;
            }
            for(int j=4;j>=0;--j)out<<s[j];
            out<<'\n';
        }
    }
    return 0;
}
