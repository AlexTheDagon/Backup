#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in("reteta2.in");
ofstream out("reteta2.out");
string s,aux;
string v[101];
int timp,x[101],sem,l,nr,sing,scant,stimp,ing;
int main()
{
    getline(in,s);
    for(int i=0;i<s.size();++i)
    {
        if(s[i]==')' || s[i]=='(')s[i]=' ';
    }
    for(int i=0;i<=s.size();++i)
    {
        if(isalpha(s[i]))///daca e litera
        {
            aux.append(s,i,1);
            sing=1;
            nr=0;
        }
        else
        {
            if(isdigit(s[i]))///daca e cifra
            {
                nr=nr*10+(s[i]-'0');
                scant=1;
            }
            else///daca e spatiu
            {
                if(sing==1 && scant==1)
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
                    sing=0;
                    scant=0;
                }
                else
                {
                    if(scant==1)
                    {
                        timp+=nr;
                        scant=0;
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
