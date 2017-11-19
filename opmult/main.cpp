#include <iostream>
#include <fstream>
using namespace std;
ifstream in("opmult.in");
ofstream out("opmult.out");
int op1();
int op2();
int op3();
int p;
int k;
string s;
int nr();
int t;
int main()
{
    in>>t;
    for(int pop=1;pop<=t;++pop)
    {
        in>>k>>s;
        p=0;
        int val=op1();
        if(val)out<<"DA"<<'\n';
        else out<<"NU"<<'\n';
    }
    return 0;
}
int op1()
{
    int r=op2();
    int nou=0;
    while(s[p]=='-' || s[p]=='u')
    {
        if(s[p]=='-')
        {
            ++p;
            nou=op2();
            if(r==1 && nou==1)r=0;
        }
        else
        {
            ++p;
            nou=op2();
            r=max(nou,r);
        }
    }
    return r;
}

int op2()
{
    int r=op3();
    int nou;
    while(s[p]=='n')
    {
        ++p;
        nou=op3();
        r=(nou&&r);
    }
    return r;
}
int op3()
{
    int sem1=0,sem2=0;
    if(s[p]=='(')sem1=1;
    ++p;
    int nr1=nr();
    ++p;
    int nr2=nr();
    if(s[p]==')')sem2=1;
    ++p;
    nr1+=sem1;
    nr2-=sem2;
    if(nr1<=k && nr2>=k)return 1;
    return 0;
}










int nr()
{
    int x=0;
    while(isdigit(s[p]))
    {
        x=x*10+s[p]-'0';
        ++p;
    }
    return x;
}
