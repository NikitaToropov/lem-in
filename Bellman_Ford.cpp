const int INF = 1e9;
vector <int> F(N, INF);
F[start] = 0;
for (int k = 1; k < N; ++k)
	for (int i = 0; i < N; ++i)
		 for (int j = 0; j < N; ++j)

			 if (F[k - 1][j] + W[j][i] < F[k][i])

				 F[k][i] = F[k - 1][j] + W[j][i];


struct edge {
	int a, b, cost;
};
 
int n, m, v;
vector<edge> e;
const int INF = 1000000000;
 
void solve() {
	vector<int> d (n, INF);
	d[v] = 0;
	for (int i=0; i<n-1; ++i)
		for (int j=0; j<m; ++j)
			if (d[e[j].a] < INF)
				d[e[j].b] = min (d[e[j].b], d[e[j].a] + e[j].cost);
	// вывод d, например, на экран
}