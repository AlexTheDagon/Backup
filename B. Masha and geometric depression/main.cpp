#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
long long b1,q,l,m,a[100005],fr,sem,sem2,sem3,sem4,put,aux[100005],sem5,sem6;
int main()
{
    cin>>b1>>q>>l>>m;
    if(l<abs(b1))
    {
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=m;++i)
    {
        cin>>a[i];
        if(b1==0 && a[i]==0)sem=1;
        if(q==0)
        {
            if(b1==a[i])sem6=1;
            if(a[i]==0)sem5=1;
        }
        if(q==1 && a[i]==b1)sem2=1;
        if(q==-1)
        {
            if(a[i]==b1)sem3=1;
            if(a[i]==-b1)sem4=1;
        }
    }
    if(q==0)
    {
        if(sem6 && sem5)
        {
            cout<<"0";
            return 0;
        }
        if(sem5)
        {
            cout<<"1";
            return 0;
        }
        if(sem6)
        {
            cout<<"inf";
            return 0;
        }
    }///bine
    if(sem==1)
    {
        cout<<"0";
        return 0;
    }
    else
    {
        if(b1==0)
        {
            cout<<"inf";
            return 0;
        }
    }///bine
    if(sem2==1)
    {
        cout<<"0";
        return 0;
    }
    else
    {
        if(q==1)
        {
            cout<<"inf";
            return 0;
        }
    }///bine
    if(sem3 && sem4)
    {
        cout<<"0";
        return 0;
    }
    else
    {
        if(sem3 || sem4 || q==-1)
        {
            cout<<"inf";
            return 0;
        }
    }///bine
    if(b1>l)
    {
        cout<<"0";
        return 0;
    }
    aux[1]=b1;
    int k=1;
    while(abs(aux[k]*q)<=l)
    {
        aux[k+1]=aux[k]*q;
        ++k;
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=k;++j)
        {
            if(a[i]==aux[j])aux[j]=0;
        }
    }
    int nr=0;
    for(int i=1;i<=k;++i)if(aux[i]!=0)++nr;
    cout<<nr;
    return 0;
}
