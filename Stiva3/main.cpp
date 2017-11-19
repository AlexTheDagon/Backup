#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#define pb push_back
using namespace std;
ifstream in("stiva3.in");
ofstream out("stiva3.out");
int a[50005],fol[50005];
vector <int> v;
int minn,maxx;
stack <int> s;
int ind;
int n;
int main()
{
    in>>n;
    for(int nrt=1;nrt<6;++nrt)
    {
        minn=2000000005;
        maxx=0;
        for(int i=1;i<=n;++i)
        {
            in>>a[i];
            minn=min(minn,a[i]);
        }
        for(int i=1;i<=n;++i)
        {
            a[i]=a[i]-minn+1;
            fol[a[i]]=1;
        }
        for(int i=1;a[i]!=1;++i)maxx=max(maxx,a[i]);
        if(maxx!=0)
        {
            for(int i=1;i<=maxx;++i)
            {
                if(!fol[i])
                {
                    v.pb(i);
                    fol[i]=1;
                }
            }
        }
        for(int i=1;i<=n;++i)v.pb(a[i]);
        maxx=0;
        for(int i=1;i<=n;++i)maxx=max(a[i],maxx);
        for(int i=maxx;i>0;--i)if(!fol[i])v.pb(i);
        ///bine
        ind=0;
        for(int i=1;i<=maxx;++i)
        {
            s.push(i);
            while(!s.empty() && s.top()==v[ind])
            {
                ++ind;
                s.pop();
            }
        }
        if(s.empty())out<<"1";
        else out<<"0";
        out<<'\n';
        while(!s.empty())s.pop();
        v.clear();
        for(int i=1;i<=maxx;++i)fol[i]=0;
    }
    return 0;
}
///Inserez la inceput toate nr mai mari decat si si mai mici  decat maximul pana acolo care lipsesc si dupa 1 nr care lipsesc
///dupa care verific daca se paote realiza stivuirea(cand introduc nr la inceput le introduc crescator)
