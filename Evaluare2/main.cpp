#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
ifstream in("evaluare2.in");
ofstream out("evaluare2.out");
string expr;
long long get_expr_val(int &ind);
long long get_term(int &ind);
long long get_factor(int &ind);
long long get_number(int &ind);
long long get_pow(int &ind);
long long reversed(long long n)
{
    long long nou=0;
    while(n)
    {
        nou=nou*10+n%10;
        n/=10;
    }
    return nou;
}
int main()
{
    in>>expr;
    int indice=0;
    out<<get_expr_val(indice);
    return 0;
}

long long get_expr_val(int &ind)
{
    long long res=get_term(ind);
    while(expr[ind]=='+')
    {
        ++ind;
        res+=get_term(ind);
    }
    return res;
}

long long get_term(int &ind)
{

    long long res=get_pow(ind);
    while(expr[ind]=='/')
    {
        ++ind;
        res/=get_pow(ind);
    }
    return res;
}
long long get_pow(int &ind)
{
    long long res=get_factor(ind);
    while(expr[ind]=='^')
    {
        ++ind;
        long long put=get_pow(ind);
        res=pow(res,put);
    }
    return res;
}
long long get_factor(int &ind)
{
    long long res=0;
    if(expr[ind]=='(')
    {
        ++ind;
        res=get_expr_val(ind);
        ++ind;
    }
    else
    {
        if(expr[ind]=='!')
        {
            ++ind;
            res=reversed(get_factor(ind));
        }
        else res=get_number(ind);
    }
    return res;
}
















long long get_number(int &ind)
{

    long long nr=0;
    while(isdigit(expr[ind]))
    {
        nr=nr*10+(expr[ind]-'0');
        ++ind;
    }
    return nr;
}
