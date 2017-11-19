#include <iostream>
#include <fstream>
using namespace std;
int x;
ifstream in("date.in");
ofstream out("date.out");

int main()
{
    in>>x;
    if(x<=4 && x>=1){out<<"few";}
    else{if(x>=5 && x<=9){out<<"several";}
         else{if(x>=10 && x<=19){out<<"pack";}
              else{if(x>=20 && x<=49)out<<"lots";
                    else{if(x>=50 && x<=99)out<<"horde";
                         else{if(x>=100 && x<=249)out<<"throng";
                              else{if(x>=250 && x<=499)out<<"swarn";
                                   else{if(x>=500 && x<=999)out<<"zounds ";
                                        else{out<<"legion";}}}}}}}}
}
