#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
using namespace std;
ifstream in("search.in");
ofstream out("search.out");
string cuv[105];
int n,m,np[105][5010][30],venit[105][5010][30],ind,nr,lcur;
string mesaj;
vector <int> indact[105];
char c;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        in>>cuv[i];
        for(int lit='a';lit<='z';++lit)
        {
            ind=-1;
            for(int j=cuv[i].size()-1;j>=0;--j)
            {
                np[i][j][lit-'a']=ind;
                if(cuv[i][j]==lit)ind=j;
            }
        }
    }
    in>>c;
    for(int j=1;j<=n;++j)
    {
        if(cuv[j][0]==c)indact[j].pb(0);
        else indact[j].pb(np[j][0][c-'a']);
    }
    for(int l=1;l<=n;++l)
        if(indact[l][lcur]>-1)++nr;
    out<<nr<<'\n';
    mesaj+=c;
    for(int icur=2;icur<=m;++icur)
    {
        nr=0;
        in>>c;
        if(c=='-')///bine
        {
            for(int i=1;i<=n;++i)indact[i].pop_back();
            mesaj.pop_back();
            --lcur;
        }
        else
        {
            mesaj+=c;
            for(int j=1;j<=n;++j)
            {
                if(indact[j][lcur]!=-1)indact[j].pb(np[j][indact[j][lcur]][c-'a']);
                else indact[j].pb(-1);
            }
            ++lcur;
        }
        for(int l=1;l<=n;++l)
            if(indact[l][lcur]>-1)++nr;
        out<<nr<<'\n';
    }
    return 0;
}
/**Avem next_poz[cuv][ind][lit]--->unde este prima litera lit pentru cuvantul cuv dupa indicele ind
tin minte pentru fiecarel itera din m indicii fiecarui cuvant(cand se taie revin la indicele precedent)--->Bianca


Eu:
venit[cuv][ind][lit]---de unde am venit in


**/
