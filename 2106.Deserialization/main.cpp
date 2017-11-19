#include <iostream>
#include <string>
#include <vector>
#include <map>
#define NM 245
#define LM 1005
using namespace std;
int n,l,ns,poz;

map<int,string> name;
map<string,int> code;
map<int,vector<int> > memebers
vector <int> v;

string encoding;
int toint(char c)
{
    if(isalpha(c))return c-'A'+10;
    return c-'0';
}
long long next_int()
{
    long long rez=0;
    for(int i=poz;i<poz+8;++i)rez=rez+16*toint(encoding[i]);
    poz+=8;
    return rez;
}
string next_string()
{
    string s;
    long long lungime=next_int();
    for(int i=1;i<=lungime)s+=next_char();
    return s;
    ///de verif + implementat next char
}
void pars_struc(long long id)
{
    for(auto mem:members[id])
    {
        if(mem==code["int"])next_int();
        else
        {
            if(mem==code["string"])next_string();
            else pars_struc(mem);
        }
    }
}
int main()
{
    cin>>n>>l;

    return 0;
}


next_char(returneaza charul corespunzator urmatoarei litere);
/// -1        -int
///  0        -string
///  1->m     -struct de alt tip
