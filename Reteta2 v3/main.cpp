#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in("reteta2.in");
ofstream out("reteta2.out");
string s,aux;
string v[101];
int timp,x[101],sem,l,nr,este_ing,este_cant,ing;
int main()
{
    getline(in,s);
    for(int i=0;i<s.size();++i)
    {
        if(s[i]==')' || s[i]=='(')s[i]=' ';
    }
    for(int i=0;i<=s.size();++i)
    {
        if(isalpha(s[i]))
        {
            aux.append(s,i,1);
            este_ing=1;
            nr=0;
        }
        else
        {
            if(isdigit(s[i]))
            {
                nr=nr*10+(s[i]-'0');
                este_cant=1;
            }
            else
            {
                if(este_ing==1 && este_cant==1)
                {
                    sem=0;
                    for(int i=1;i<=ing;++i)
                    {
                        if(v[i]==aux)
                        {
                            x[i]+=nr;
                            sem=1;
                        }
                    }
                    if(sem==0)
                    {
                        v[++ing]=aux;
                        x[ing]=nr;
                    }
                    aux="";
                    nr=0;
                    este_ing=0;
                    este_cant=0;
                }
                else
                {
                    if(este_cant==1)
                    {
                        timp+=nr;
                        este_cant=0;
                        nr=0;
                    }
                }
            }
        }
    }
    out<<timp<<'\n';
    for(int i=1;i<=ing;++i)
    {
        aux="";
        for(int j=1;j<=ing;++j)
        {
            if((v[j]<aux || aux=="") && v[j]!="")
            {
                aux=v[j];
                l=j;
            }
        }
        v[l]="";
        out<<aux<<" "<<x[l]<<'\n';
    }
    return 0;
}
