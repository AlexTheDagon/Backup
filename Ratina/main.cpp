#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define NM 10005
#define LM 2005
using namespace std;
ifstream in("ratina.in");
ofstream out("ratina.out");
struct trie
{
    trie *fiu[30]={0};
    int fr=0;
};
int cnt,l[NM],n,m,sol,a[NM];
char cuv[LM];
vector<int> v[NM];
int verif(int poz)
{
    for(int i=1;i<=a[0];++i)
        if(v[a[i]][poz]!=v[a[1]][poz])return 0;
    return 1;
}///bine
void adauga(char *p,trie *T,int ind)
{
    if(*p==0)return;
    if(T->fiu[*p-'a']==0)
    {
        ++cnt;
        T->fiu[*p-'a']=new trie;
        T->fiu[*p-'a']->fr=cnt;
    }
    if(T->fiu[*p-'a']->fr==0)
        T->fr=++cnt;
    v[ind].pb(T->fiu[*p-'a']->fr);
    adauga(p+1,T->fiu[*p-'a'],ind);
}///bine
trie *T;
int minn,nr,aaa,hi,low,mid,lm;
vector<int> vv;
int main()
{
    T=new trie;
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        in>>cuv+1;
        v[i].pb(-100);
        adauga(cuv+1,T,i);
        l[i]=strlen(cuv+1);
    }
    for(int i=1;i<=m;++i)
    {
        in>>a[0];
        hi=1000000000,low=1;
        for(int j=1;j<=a[0];++j)
        {
            in>>a[j];
            hi=min(hi,l[a[j]]);
        }
        sol=0;
        while(hi>=low)
        {
            mid=(hi+low)/2;
            if(verif(mid))
            {
                low=mid+1;
                sol=mid;
            }
            else hi=mid-1;
        }
        out<<sol<<'\n';
    }
    return 0;
}
