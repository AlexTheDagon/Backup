#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
using namespace std;
ifstream in("mesaj.in");
ofstream out("mesaj.out");
int n,m,icuv,isec;
string s,mesaj;
vector <string> v;
int dmin[2000];
int main()
{
    in>>n>>m;
    in>>mesaj;
    for(int i=0;i<n;++i)
    {
        in>>s;
        v.pb(s);
    }
    dmin[0]=0;
    for(int i=1;i<=m;++i)
    {
        dmin[i]=dmin[i-1]+1;
        for(int cuv=0;cuv<n;++cuv)
        {
            if(i>=v[cuv].size() && mesaj[i-1]==v[cuv][v[cuv].size()-1])
            {
                icuv=v[cuv].size()-1;
                isec=i-1;
                while(isec>=0 && icuv>=0)///verif
                {
                    if(mesaj[isec]==v[cuv][icuv])
                    {
                        --icuv;
                    }
                    --isec;
                }
                if(icuv==-1)
                {
                    if(dmin[isec+1]+i-isec-1-v[cuv].size()<dmin[i])dmin[i]=dmin[isec+1]+i-isec-1-v[cuv].size();
                }
            }
        }
    }
    out<<dmin[m];
    return 0;
}
/**
dmin[i]=nr min de caractere extra pana la poz i
for(int i=1;oi<=n;++i)
{
    for(cuv)
        incep de la finalul cuvantului si vad unde se termina cu secventa
    dmin[i]=dmin[poz_inceput_a_secventei-1]+lungima secventa-lungima cuvant
}



for(int i=0;i<m;++i)

**/

///Sa fac calcularea cuvintelor inainte de a face dp;
