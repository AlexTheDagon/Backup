#include <iostream>
#include <bits/stdc++.h>
#define NM 305
using namespace std;
ifstream in("sub.in");
ofstream out("sub.out");
struct trie
{
    trie *fiu[27]={0};
    int fr=0,ult=-1;
    bool fol2=1,fol=1;
};
int na,nb,l,sol,cur;
void adauga(char *p,trie *T)
{
    if(*p==0)return;
    char x=*p-'a';
    if(T->fiu[x]==0)
        if(cur==1)T->fiu[x]=new trie;
        else return;
    if(T->fiu[x]->ult!=cur)
    {
        T->fiu[x]->ult=cur;
        ++T->fiu[x]->fr;
        if(T->fiu[x]->fr==na && T->fiu[x]->fol2==1)
        {
            ++sol;
            T->fiu[x]->fol2=0;
        }
    }
    adauga(p+1,T->fiu[x]);
}///bine

void verif(char *p,trie *T)
{
    if(*p==0 || T->fiu[*p-'a']==0 || T->fiu[*p-'a']->fr<na)return;
    if(T->fiu[*p-'a']->fol)
    {
        T->fiu[*p-'a']->fol=0;
        --sol;
    }
    verif(p+1,T->fiu[*p-'a']);
}

char cuv[NM];
trie *TA;
int aux;
int main()
{
    in>>na;
    TA=new trie;
    for(cur=1;cur<=na;++cur)
    {
        in>>cuv+1;
        l=strlen(cuv+1);
        for(int j=1;j<=l;++j)
            adauga(cuv+j,TA);
    }
    in>>nb;
    for(int i=1;i<=nb;++i)
    {
        in>>cuv+1;
        l=strlen(cuv+1);
        for(int j=1;j<=l;++j)
            verif(cuv+j,TA);
    }
    out<<sol;
    return 0;
}
