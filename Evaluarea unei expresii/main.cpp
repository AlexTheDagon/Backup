#include <iostream>
#include <fstream>
using namespace std;
ifstream in("evaluare.in");
ofstream out("evaluare.out");
string expr;
int get_expr_val(int &ind);
int get_term(int &ind);
int get_factor(int &ind);
int get_number(int &ind);
int main()
{
    in>>expr;
    int indice=0;
    out<<get_expr_val(indice);
    return 0;
}
int get_expr_val(int &ind)
{
    int res=get_term(ind);
    while(expr[ind]=='+' || expr[ind]=='-')
    {
        ++ind;
        if(expr[ind-1]=='+')res+=get_term(ind);
        else res-=get_term(ind);
    }
    return res;
}
int get_term(int &ind)
{
    int res=get_factor(ind);
    while(expr[ind]=='*' || expr[ind]=='/')
    {
        ++ind;
        if(expr[ind-1]=='*')res*=get_factor(ind);
        else res/=get_factor(ind);
    }
    return res;
}
int get_factor(int &ind)
{
    if(expr[ind]!='(')return get_number(ind);
    else
    {
        ++ind;
        int res=get_expr_val(ind);
        ++ind;
        return res;
    }
}
int get_number(int &ind)
{

    int nr=0;
    while(isdigit(expr[ind]))
    {
        nr=nr*10+(expr[ind]-'0');
        ++ind;
    }
    return nr;
}
