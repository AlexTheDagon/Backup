#include <iostream>
#include <map>
using namespace std;
map <char,string> cod;
map<string,int> nr;
int n;
int fr[100004],lg;
string s;
char lit;
string cuv;
int main()
{
    for(int i=1;i<=26;++i)
    {
        cin>>lit>>s;
        cod[lit]=s;
    }
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        cuv="";
        for(auto j:s)cuv+=cod[j];
        if(nr.find(cuv)!=nr.end())
        {
            ++fr[nr[cuv]];
        }
        else
        {
            ++lg;
            nr[cuv]=lg;
            ++fr[lg];
        }
    }
    int maxx=0;
    for(int i=1;i<=lg;++i)maxx=max(maxx,fr[i]);
    if(maxx<2)cout<<"-1";
    else cout<<maxx;
    return 0;
}
