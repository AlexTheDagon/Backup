#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("logic.in");
ofstream out("logic.out");
string s,s1,s2;
int fol[300],fol2[300];
int ind[300];
int n;
int poz;
int eval();
int op();
int op2();
int op3();
int op4();
int v1,v2;
int nr,sem;
string l1,l2;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        sem=1;
        in>>s1>>s2;
        for(int j=0;j<s1.size();++j)
        {
            if(isalpha(s1[j]) && fol[s1[j]]==0)
            {
                l1+=s1[j];
                fol[s1[j]]=1;
            }
        }
        for(int j=0;j<s2.size();++j)
        {
            if(isalpha(s2[j]) && fol2[s2[j]]==0)
            {
                l2+=s2[j];
                fol2[s2[j]]=1;
            }
        }
        sort(l1.begin(),l1.end());
        sort(l2.begin(),l2.end());
        if(l1!=l2)sem=0;
        if(sem)
        {
            for(int j=0;j<(1<<l1.size());++j)
            {
                for(int k=0;k<l1.size();++k)
                {
                    if((j&(1<<k))==0)ind[l1[k]]=0;
                    else ind[l1[k]]=1;
                }
                poz=0;
                s=s1;
                v1=op();
                s="";
                poz=0;
                s=s2;
                v2=op();
                s="";
                if(v1!=v2)sem=0;
            }
        }
        if(sem)out<<"egale";
        else out<<"diferite";
        out<<'\n';
        for(int j=0;j<250;++j)fol[j]=fol2[j]=0;
        l1=l2="";
    }
    return 0;
}
int op()
{
    int r=op2();
    while(s[poz]=='|')
    {
        ++poz;
        r=(r|op2());
    }
    return r;
}
int op2()
{
    int r=op3();
    while(s[poz]=='^')
    {
        ++poz;
        r=(r^op3());
    }
    return r;
}
int op3()
{
    int r=op4();
    while(s[poz]=='&')
    {
        ++poz;
        r=(r&op4());
    }
    return r;
}
int op4()
{
    int r=0;
    if(s[poz]=='~')
    {
        ++poz;
        r=1-op4();
    }
    else
    {
        if(s[poz]=='(')
        {
            ++poz;
            r=op();
            ++poz;
        }
        else
        {
            if(isalpha(s[poz]))
            {
                r=ind[s[poz]];
                ++poz;
            }
        }
    }
    return r;
}


