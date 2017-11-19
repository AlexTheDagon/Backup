#include <fstream>
using namespace std;

int n,a,b,sol;
int v[100100];

ifstream in("unuzero.in");
ofstream out("unuzero.out");
	
inline void verif()
{
	int ok=0;
	for(int i=1;i<=n;)
	{
		if(v[i]==1)
		{
			ok=1;
			int sv=i,nr=0;
			while(v[i]==v[sv] && i<=n) ++i,++nr;
			if(!(nr>=a && nr<=b)) return ;
		}
		else ++i;
	}
	
	if(!ok) return;
	
	sol++;
	/*for(int i=1;i<=n;++i)
	{
		out<<v[i];
	}
	out<<'\n';*/
}

void back(int k)
{
	if(k>n) verif();
	else
	for(int i=0;i<=1;++i)
	{
		v[k]=i;
		back(k+1);
	}
}

int main()
{
	in>>n>>a>>b;
	back(1);
	out<<sol%666013<<'\n';
	out.close();
	return 0;
}
