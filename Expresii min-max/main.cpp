#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream in("emm.in");
ofstream out("emm.out");
stack <int> val,auxv;
stack <char> s,aux;
char c,oper;
int nr,x,y;
int main()
{
    while(in>>c)
    {
        if(isdigit(c))///formez numarul
        {
            if(nr==-1)nr=(c-'0');
            else nr=nr*10+(c-'0');
        }
        else
        {
            if(nr!=-1)///adaug numarul in stiva val
            {
                val.push(nr);
                nr=-1;
            }
            if(c!=')')s.push(c);///daca nu e final de paranteza adaug in stiva
            else///pana aici e ok
            {
                auxv.push(val.top());///pun ultimul elem in stiva aux(pt ca sunt nr operatori +1 numere in int parantezei
                val.pop();///scot elem din stiva principala
                while(s.top()!='(')///mute elementele din interiorul stivelor in celelalte stive
                {
                    aux.push(s.top());
                    s.pop();
                    auxv.push(val.top());
                    val.pop();
                }
                s.pop();///scot paranteza ( din stiva aux
                while(!aux.empty())
                {
                    x=auxv.top();
                    auxv.pop();
                    y=auxv.top();
                    auxv.pop();
                    if(aux.top()=='m')auxv.push(min(x,y));
                    else auxv.push(max(x,y));
                    aux.pop();
                }
                val.push(auxv.top());
                auxv.pop();
            }

        }
    }
    if(nr!=-1)val.push(nr);
    while(!s.empty())
    {
        aux.push(s.top());
        s.pop();
        auxv.push(val.top());
        val.pop();
    }
    auxv.push(val.top());
    val.pop();
    while(!aux.empty())
    {
        x=auxv.top();
        auxv.pop();
        y=auxv.top();
        auxv.pop();
        if(aux.top()=='m')auxv.push(min(x,y));
        else auxv.push(max(x,y));
        aux.pop();
    }
    val.push(auxv.top());
    auxv.pop();
    out<<val.top();
    return 0;
}
///4 cauzri
/// ( -->citesc pana dau de--> )
/// ) -->ma intorc si operez tot ce e in stack pana la prima --> (
/// m/M --> iau ultimele 2 numere si returnez valoarea corespunzatoare
/// nr --> il bag in stiva de numere
/// cei nu ii numar se pune in stiva de operanzi
