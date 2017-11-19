#include <cstdio>
#include <stack>
#include <utility>

using namespace std;

static const int NMAX = 200001;

int N, rez;
int h[NMAX], st[NMAX], dr[NMAX];
stack< pair< int, int > > S;

int main(int argc, char **argv) {
	freopen("copaci.in", "r", stdin);
	freopen("copaci.out", "w", stdout);

	scanf("%d\n", &N);
	for (int i = 0; i < N; scanf("%d ", h + i), ++i);

	for (int i = 0; i < N; ++i) {
		while (!S.empty() && h[i] > S.top().first) {
			dr[S.top().second] = 1;
			S.pop();
		}
		if (!S.empty() && h[i] == S.top().first)
			S.pop();
		else
			S.push(make_pair(h[i], i));
	}

	while (!S.empty()) S.pop();

	for (int i = N-1; i >=0; --i) {
		while (!S.empty() && h[i] > S.top().first) {
			st[S.top().second] = 1;
			S.pop();
		}
		if (!S.empty() && h[i] == S.top().first)
			S.pop();
		else
			S.push(make_pair(h[i], i));
	}

	for (int i = 0; i < N; ++i)
		rez += st[i] && dr[i] ? 1 : 0;

	printf("%d\n", rez);

	return 0;
}

