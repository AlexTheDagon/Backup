#include <iostream>
#include <fstream>
using namespace std;
ifstream in("apel.in");
ofstream out("apel.out");

map<char,string> funcs;
map<char,int>vars;
int eval_func(char nume,vector<int> args);
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
