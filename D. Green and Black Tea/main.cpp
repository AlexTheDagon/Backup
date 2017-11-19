#include <iostream>

using namespace std;
int n,k,a,b,grmax,sem,ramasemax,ramasemin,grmin,kmin;
char c[100005];
int main()
{
    cin>>n>>k>>a>>b;
    grmax=max(a,b)/k;
    ramasemax=max(a,b)%k;
    if(ramasemax>0 && grmax!=0)
    {
        kmin=min(a,b)/grmax;
        ramasemin=min(a,b)%grmax;
        if(kmin==0)sem=1;
    }
    else
    {
        if(grmax>0)
        {
            kmin=min(a,b)/grmax;
            ramasemin=min(a,b)%grmax;
            if(ramasemin==min(a,b) && grmax>1)
            {
                kmin=min(a,b)/(grmax-1);
                ramasemin=min(a,b)%(grmax-1);
            }
            if(ramasemin==min(a,b))sem=1;
        }
        else sem=1;
    }
    if(sem==1)cout<<"NO";
    else
    {
        for(int i=1;i<=k;++i)
        {
            if(a>b)cout<<"G";
            else cout<<"B";
        }
        grmax--;
        for(int i=1;i<=grmax;++i)
        {
            for(int i=1;i<=kmin;++i)
            {
                if(a>b)cout<<"B";
                else cout<<"G";
            }
            for(int i=1;i<=k;++i)
            {
                if(a>b)cout<<"G";
                else cout<<"B";
            }
        }
        for(int i=1;i<=ramasemin;++i)
        {
            if(a>b)cout<<"B";
            else cout<<"G";
        }
        for(int i=1;i<=ramasemax;++i)
        {
            if(a>b)cout<<"G";
            else cout<<"B";
        }
    }
    return 0;
}
