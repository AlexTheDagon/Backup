#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream in("ecuatii2.in");
ofstream out("ecuatii2.out");
int n,nrx,nr,c,sem,semafor;
float rez;
char a[260],semn;
int main()
{
    in>>n;
    for(int j=1;j<=n;++j)
    {
        in>>a;
        semn='+';
        nr=0;
        nrx=0;
        c=0;
        for(int i=0;a[i]!=(char)0;++i)
        {

            if(a[i]=='+' || a[i]=='-')
            {
                if(semafor==0)
                {
                    if(semn=='+')
                    {
                        if(sem==0)nr=nr+c;
                        else nrx=nrx+c;
                    }
                    else
                    {
                        if(sem==0)nr=nr-c;
                        else nrx=nrx-c;
                    }
                }
                else
                {
                    if(semn=='+')
                    {
                        if(sem==0)nr=nr-c;
                        else nrx=nrx-c;
                    }
                    else
                    {
                        if(sem==0)nr=nr+c;
                        else nrx=nrx+c;
                    }
                }
                semn=a[i];
                c=0;
            }
            else
            {
                sem=0;
                if(a[i]!='x' && a[i]!='=')c=c*10+(a[i]-'0');
                else
                {
                    if(a[i]=='=')
                    {
                        if(semn=='+')
                        {
                            if(sem==0)nr=nr+c;
                            else nrx=nrx+c;
                        }
                        else
                        {
                            if(sem==0)nr=nr-c;
                            else nrx=nrx-c;
                        }
                        semafor=1;
                        c=0;
                    }
                    else
                    {
                        sem=1;
                        if(c==0)c++;
                    }
                }
            }
        }
        if(semn=='+')
        {
            if(sem==0)nr=nr-c;
            else nrx=nrx-c;
        }
        else
        {
            if(sem==0)nr=nr+c;
            else nrx=nrx+c;
        }
        if(nrx==0 && nr!=0)out<<"imposibil"<<'\n';
        else
        {
            if(nrx==0 && nr==0)out<<"infinit"<<'\n';
            else
            {
                rez=nr/nrx;
                out<<setprecision(5)<<rez<<'\n';
            }
        }
        for(int i=0;i<=259;++i)a[i]=(char)0;
    }
    return 0;
}
