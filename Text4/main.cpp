#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in("text4.in");
ofstream out("text4.out");
string s,ss,sss;
int cuvinte,l,poz,intregi,ramasi,maxx;
int main()
{
    in>>maxx;
    getline(in,s);
    while(!in.eof())
    {
        poz=0;
        getline(in,s);
        while(poz<s.size())
        {
            ramasi=0;
            intregi=0;
            cuvinte=0;
            ss="";
            while(poz<s.size() && ss.size()<maxx)
            {
                if(s[poz]!=' ')ss+=s[poz];
                else if(ss[ss.size()-1]!=' ')ss+=s[poz];
                if((s[poz+1]==' ' || poz+1==s.size()) && s[poz]!=' ')++cuvinte;
                ++poz;
            }
            --poz;
            ///bine;
            if((s[poz+1]==' ' || poz+1==s.size()) && s[poz]!=' ')out<<ss<<'\n';
            else
            {
                while(!((s[poz+1]==' ' || poz+1==s.size()) && s[poz]!=' '))
                {
                    --poz;
                    ss.erase(ss.begin()+ss.size()-1);
                }
                ramasi=(maxx-ss.size())%cuvinte;
                intregi=(maxx-ss.size())/cuvinte;
                for(int i=0;i<ss.size();++i)
                {
                    if(ss[i]==' ')
                    {
                        out<<' ';
                        for(int k=1;k<=intregi;++k)out<<' ';
                        if(ramasi)
                        {
                            out<<' ';
                            --ramasi;
                        }
                    }
                    else out<<ss[i];
                }
                out<<'\n';
            }
            ++poz;
            while(s[poz]==' ' && poz<s.size())++poz;
        }
    }
    return 0;
}
