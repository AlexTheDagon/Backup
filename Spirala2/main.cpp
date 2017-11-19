#include <iostream>
#include <fstream>
using namespace std;
ifstream in("spirala2.in");
ofstream out("spirala2.out");
int a[51][51],n,k,x[51][51],c,b[3000],is,ij,js,jd,h,nr;
int main()
{
    in>>n>>k;
    for(int i=1;i<=n;++i)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;++j)
            {
                c++;
                a[i][j]=c;
                x[i][j]=c;
            }
        }
        else
        {
            for(int j=1;j<=n;++j)
            {
                c++;
                a[i][n-j+1]=c;
                x[i][n-j+1]=c;
            }
        }
    }
    while(k!=h)
    {
        h=0;
        ++nr;
        is=1;
        ij=n;
        js=1;
        jd=n;
        c=0;
        while(c<n*n)
        {
            for(int i=js;i<jd;++i)
            {
                ++c;
                b[c]=a[is][i];
            }
            for(int i=is;i<ij;++i)
            {
                ++c;
                b[c]=a[i][jd];
            }
            for(int i=jd;i>js;--i)
            {
                ++c;
                b[c]=a[ij][i];
            }
            for(int i=ij;i>is;--i)
            {
                ++c;
                b[c]=a[i][js];
            }
            ++is;
            ++js;
            --ij;
            --jd;
        }///bine
        c=0;
        for(int i=1;i<=n;++i)
        {
            if(i%2==1)
            {
                for(int j=1;j<=n;++j)
                {
                    c++;
                    a[i][j]=b[c];
                }
            }
            else
            {
                for(int j=1;j<=n;++j)
                {
                    c++;
                    a[i][n-j+1]=b[c];
                }
            }
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(x[i][j]==a[i][j])++h;
            }
        }
        cout<<h<<endl;
    }
    out<<nr;

    return 0;
}
