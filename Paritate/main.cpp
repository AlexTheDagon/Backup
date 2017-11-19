#include <iostream>
#include <fstream>
using namespace std;
ifstream in("paritate.in");
ofstream out("paritate.out");
char s;
int poz,p,contor,sem;
int val;
char nr;
int main()
{
    poz=-1;
    while(in>>s)
    {
        ++poz;
        if(poz%8==0)
        {
            val=s-'0';
            contor=0;
        }
        else
        {
            if(s=='1')++contor;
            if(contor%2!=val && poz%8==7)sem=1;
        }
    }
    in.close();
    ifstream in("paritate.in");
    poz=-1;
    if(sem)
    {
        out<<"NU"<<'\n';
        while(in>>s)
        {
            ++poz;
            if(poz%8==0)
            {
                val=s-'0';
                contor=0;
            }
            else
            {
                if(s=='1')++contor;
                if(contor%2!=val && poz%8==7)out<<(poz-7)/8<<" ";
            }
        }
    }
    else
    {
        out<<"DA"<<'\n';
        while(in>>s)
        {
            ++poz;
            if(poz%8==0)
            {
                nr=0;
                p=64;
            }
            else
            {
                if(s=='1')nr+=p;
                p/=2;
                if(poz%8==7)
                {
                    if(nr!=10)out<<nr;
                    else out<<'\n';
                }
            }
        }
    }
    return 0;
}
