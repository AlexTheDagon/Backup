#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream in("ecuatii2.in");
ofstream out("ecuatii2.out");
int n,sem,semafor,c,nrx,nr;
float rez;
char a[260],semn;
int main()
{
    in>>n;
    for(int j=1;j<=n;++j)
    {
        in>>a;
        semafor=0;
        sem=0;
        c=0;
        nr=0;
        nrx=0;
        rez=0;
        if(a[0]=='-')semn='-';
        else semn='+';
        for(int i=0;a[i]!=(char)0;++i)
        {
            if(a[i]=='-' || a[i]=='+' || a[i]=='=')
            {
                if(a[i]=='=')
                {
                    semafor=1;
                    if(sem==1)nrx=nrx-(semn-44)*c;
                    else nr=nr+(semn-44)*c;
                    sem=0;
                    c=0;
                    semn='+';
                }
                else
                {
                    if(semafor==1)
                    {
                        if(sem==1)nrx=nrx+(semn-44)*c;
                        else nr=nr-(semn-44)*c;
                    }
                    else
                    {
                        if(sem==1)nrx=nrx-(semn-44)*c;
                        else nr=nr+(semn-44)*c;
                    }
                    sem=0;
                    c=0;
                    semn=a[i];
                }
            }
            else
            {
                if(a[i]=='x')
                {
                    sem=1;
                    if(c==0)c=1;
                }
                else
                {
                    c=c*10+(a[i]-'0');
                }
            }
        }
        if(sem==1)nrx=nrx+(semn-44)*c;
        else nr=nr-(semn-44)*c;
        if(nr!=0 && nrx==0)out<<"imposibil"<<'\n';
        else
        {
            if(nr==0 && nrx==0)out<<"infinit"<<'\n';
            else
            {
                rez=(float)nr/nrx;
                out<<fixed<<setprecision(4)<<rez<<'\n';
            }
        }
        for(int i=0;i<260;++i)a[i]=(char)0;

    }
    return 0;
}
