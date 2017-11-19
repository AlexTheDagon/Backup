#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
ifstream in("ecuatii2.in");
ofstream out("ecuatii2.out");
int nrx,nr,t,val_nr_intregi,semx,semmembru=1,semn=1;
float valx;
string s;
int main()
{
    in>>t;
    for(int nrt=1;nrt<=t;++nrt)
    {
        nrx=0;
        val_nr_intregi=0;
        semmembru=1;
        semx=0;
        semn=1;
        nr=0;
        in>>s;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='+' || s[i]=='-' || s[i]=='=')
            {
                if(semx==1)
                {
                    nrx-=semn*nr*semmembru;
                    nr=0;
                    semx=0;
                }
                else
                {
                    val_nr_intregi+=semn*nr*semmembru;
                    nr=0;
                }
                if(s[i]=='=')
                {
                    semmembru=-1;
                    semn=1;
                }
                else semn=(char)44-s[i];
            }
            else
            {
                if(s[i]=='x')
                {
                    semx=1;
                    if(nr==0)nr=1;
                }
                else
                {
                    nr=nr*10+(s[i]-'0');
                }

            }
        }
        if(semx==1)
        {
            nrx-=semn*nr*semmembru;
            nr=0;
            semx=0;
        }
        else
        {
            val_nr_intregi+=semn*nr*semmembru;
            nr=0;
        }
        if(nrx==0)
        {
            if(val_nr_intregi==0)out<<"infinit"<<'\n';
            else out<<"imposibil"<<'\n';
        }
        else
        {
            valx=(float)val_nr_intregi/nrx;
            out<<fixed<<setprecision(4)<<valx<<'\n';
        }

    }
    return 0;
}
