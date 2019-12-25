const int INF = 1e9;
vector <int> F(N, INF);
F[start] = 0;
for (int k = 1; k < N; ++k)
	for (int i = 0; i < N; ++i)
		 for (int j = 0; j < N; ++j)

			 if (F[k - 1][j] + W[j][i] < F[k][i])

				 F[k][i] = F[k - 1][j] + W[j][i];