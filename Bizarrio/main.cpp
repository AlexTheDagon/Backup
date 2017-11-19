#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream in("bizar.in");
ofstream out("bizar.out");
int eval(int &ind);
int get_number(int &ind);
string citit,expr;

int main()
{
    getline(in,citit);
    for(int i=0;i<citit.size();++i)
    {
        if(citit[i]!=' ')expr+=citit[i];
    }
    int indice=0;
    out<<eval(indice);
    return 0;
}
int eval(int &ind)
{
    int nr=get_number(ind);
    while(expr[ind]=='(')
    {
        vector<int> arg;
        while(expr[ind]!=')')
        {
            ++ind;
            arg.push_back(eval(ind));
        }
        ++ind;
        nr=arg[(nr+arg.size()-1)%arg.size()];
    }
    return nr;
}
int get_number(int &ind)
{
    int nr=0;
    while(isdigit(expr[ind]))
    {
        nr=nr*10+expr[ind]-'0';
        ++ind;
    }
    return nr;
}
