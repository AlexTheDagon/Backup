#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream in("ecuatii2.in");
ofstream out("ecuatii2.out");
char semn='+',a[260];
float rez;
int n,nr,nrx,c,sem,semafor;
int main()
{
    in>>n;
    for(int j=1;j<=n;++j)
    {
        semn='+';
        c=0;
        nrx=0;
        nr=0;
        semafor=0;
        in>>a;
        sem=0;
        for(int i=0;a[i]!=(char)0;++i)
        {

            if(a[i]!='+' && a[i]!='-' && a[i]!='=' && a[i]!='x')
            {
                c=c*10+(a[i]-'0');
            }
            else
            {
                if(a[i]=='=')
                {
                    if(semn=='+')
                    {
                        if(sem==1)nrx=nrx+c;
                        else nr=nr+c;
                    }
                    else
                    {
                        if(sem==1)nrx=nrx-c;
                        else nr=nr-c;
                    }
                    semafor=1;
                    semn='+';
                    c=0;
                }
                else
                {
                    if(a[i]=='x')
                    {
                        sem=1;
                        if(c==0)c++;
                    }
                    else
                    {
                        if(semafor==0)
                        {
                            if(semn=='+')
                            {
                                if(sem==1)nrx=nrx+c;
                                else nr=nr+c;
                            }
                            else
                            {
                                if(sem==1)nrx=nrx-c;
                                else nr=nr-c;
                            }
                        }
                        else
                        {
                            if(semn=='+')
                            {
                                if(sem==1)nrx=nrx-c;
                                else nr=nr-c;
                            }
                            else
                            {
                                if(sem==1)nrx=nrx+c;
                                else nr=nr+c;
                            }
                        }
                        sem=0;
                        semn=a[i];
                        c=0;
                    }
                }
            }

        }
        if(semn=='+')
        {
            if(sem==1)nrx=nrx-c;
            else nr=nr-c;
        }
        else
        {
            if(sem==1)nrx=nrx+c;
            else nr=nr+c;
        }
        for(int i=0;i<260;++i)a[i]=(char)0;
        if(nr!=0 && nrx==0)out<<"imposibil"<<'\n';
        else
        {
            if(nr==0 && nrx==0)out<<"infinit"<<'\n';
            else
            {
                rez=(float)nr/nrx*(-1);
                rez=rez*10000;
                rez=(int)rez;
                out<<(float)rez/10000<<'\n';
            }
        }
    }
    return 0;
}
