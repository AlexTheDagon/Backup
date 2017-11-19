     #include <iostream>
    #include <fstream>
    #include <string>
    #include <queue>
    #include <cctype>
    #define DN 62
    #define DK 12
    #define mp make_pair
    #define x first
    #define y second
    using namespace std;

    typedef pair<int,int> per;
    ifstream in("miting.in");
    ofstream out("miting.out");
    int n,m,k,dmin[DK][DK][DN][DN];
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};

    string c,mt[DN];

    int getPos(char x) {
    	for(int i=0; i<c.size(); ++i) if(c[i]==x) return i;
    }

    int ins(int a,int b) {
    	return a>=0 && b>=0 && a<n && b<m;
    }

    void bfs(int s,int d, int sx, int sy) {
    	queue<per> c;
    	for(c.push(mp(sx,sy)); !c.empty();) {
    		per fr=c.front(); c.pop();
    		for(int _=0; _<4; ++_) {
    			int ii=fr.x+dx[_],jj=fr.y+dy[_];
    			if(ins(ii,jj)&&mt[ii][jj]!='#' && dmin[s][d][ii][jj]>dmin[s][d][fr.x][fr.y]+1) {
    				dmin[s][d][ii][jj]=dmin[s][d][fr.x][fr.y]+1;
    				c.push(mp(ii,jj));
    			}
    		}
    	}
    }

    int main() {
    	int p;
    	in>>p>>n>>m>>c;
    	in.get();
    	for(int i=0; i<n; ++i) {
    		getline(in,mt[i]);
    	}
    	k=c.size();
    	for(int i=0; i<k; ++i) for(int j=0; j<k; ++j)
    		for(int x=0; x<n; ++x) for(int y=0; y<m; ++y)
    			dmin[i][j][x][y]=(1<<30);


    	for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) if(isalpha(mt[i][j])) {
    		int pos=getPos(mt[i][j]);
    		dmin[pos][pos][i][j]=0;
    		bfs(pos,pos,i,j);
    	}



    	for(int l=2; l<=k; ++l) for(int s=0; s+l-1<k; ++s) {
    		int d=s+l-1;
    		for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) {
    			for(int x=s; x<d; ++x) if(dmin[s][x][i][j]!=(1<<30) && dmin[x+1][d][i][j]!=(1<<30))
    				dmin[s][d][i][j]=min(dmin[s][d][i][j],dmin[s][x][i][j]+dmin[x+1][d][i][j]);
    			bfs(s,d,i,j);
    		}
    	}
    	int r=(1<<30);
    	for(int i=0; i<n; ++i) for(int j=0; j<m; ++j)
    		r=min(r,dmin[0][k-1][i][j]);
    	out<<r;
    }
