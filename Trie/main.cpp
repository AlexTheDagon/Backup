#include <iostream>
#include <fstream>

using namespace std;
ifstream in("trie.in");
ofstream out("trie.out");

struct TRIE
{
    struct TRIE *fiu[30]={0};
    int terminal=0,fr=0;
};
void adauga(char *p,TRIE *T)
{
    if(*p==0)
    {
        T->terminal++;
        return;
    }
    if(T->fiu[*p-'a']==0)
    {
        T->fiu[*p-'a']=new TRIE;
        T->fr++;
    }
    adauga(p+1,T->fiu[*p-'a']);
}///bine
void sterge(char *p,TRIE *T)
{
    if(*p==0)T->terminal--;
    else
    {
        sterge(p+1,T->fiu[*p-'a']);
        if(T->fiu[*p-'a']->fr==0 && T->fiu[*p-'a']->terminal==0)
        {
            delete T->fiu[*p-'a'];
            T->fiu[*p-'a']=0;
            T->fr--;
        }
    }
}
int aparitii(char *p,TRIE *T)
{
    if(*p==0)return T->terminal;
    if(T->fiu[*p-'a']==0)return 0;
    aparitii(p+1,T->fiu[*p-'a']);
}
int pref(char *p,TRIE *T)
{
    if(*p==0)return 0;
    if(T->fiu[*p-'a']==0)return 0;
    return 1+pref(p+1,T->fiu[*p-'a']);
}
int n,i,caz;
TRIE *T;
char CUV[30];
int main()
{
    T=new TRIE;
    while(in>>caz)
    {
        in>>CUV;
        if(caz==0)adauga(CUV,T);
        if(caz==1)sterge(CUV,T);
        if(caz==2)out<<aparitii(CUV,T)<<'\n';
        if(caz==3)out<<pref(CUV,T)<<'\n';
    }

    return 0;
}


/// problema : http://www.spoj.com/problems/PHONELST/
/// http://acm.timus.ru/problem.aspx?space=1&num=1590
/// http://codeforces.com/contest/271/problem/D
