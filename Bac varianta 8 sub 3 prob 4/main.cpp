#include <iostream>

using namespace std;
void sub(int n,int m,int a[],int b[])
{
    int i=1,j=1,ind=0,cp[205]={0},ci[205]={0},sem=0,ind2=0;
    while(i<=n && j<=m)
    {
        if(sem==0)///tb numar par
        {
            while(a[i]<cp[ind] && i<=n)++i;
            if(i<=n)cp[++ind]=a[i];
            i++;
        }
        else
        {
            while(b[j]<cp[ind] && j<=n)++j;
            if(j<=n)cp[++ind]=b[j];
            j++;
        }
        sem=1-sem;
    }
    if(sem==0)///tb numar par
        {
            while(a[i]<cp[ind] && i<=n)++i;
            if(i<=n)cp[++ind]=a[i];
            i++;
        }
        else
        {
            while(b[j]<cp[ind] && j<=n)++j;
            if(j<=n)cp[++ind]=b[j];
            j++;
        }
    i=1,j=1,sem=0;
    while(i<=n && j<=m)
    {
        if(sem)///tb numar par
        {
            while(a[i]<ci[ind2] && i<=n)++i;
            if(i<=n)ci[++ind2]=a[i];
            i++;
        }
        else
        {
            while(b[j]<ci[ind2] && j<=n)++j;
            if(j<=n)ci[++ind2]=b[j];
            j++;
        }
        sem=1-sem;
    }
    if(sem)///tb numar par
        {
            while(a[i]<ci[ind2] && i<=n)++i;
            if(i<=n)ci[++ind2]=a[i];
            i++;
        }
        else
        {
            while(b[j]<ci[ind2] && j<=n)++j;
            if(j<=n)ci[++ind2]=b[j];
            j++;
        }
        sem=1-sem
    if(ind>ind2)for(int i=1;i<=ind;++i)cout<<cp[i]<<" ";
    else for(int i=1;i<=ind2;++i)cout<<ci[i]<<" ";
}
int nn,mm,x[105],y[105];
int main()
{
    cin>>nn>>mm;
    for(int i=1;i<=nn;++i)cin>>x[i];
    for(int i=1;i<=mm;++i)cin>>y[i];
    sub(nn,mm,x,y);
    return 0;
}
