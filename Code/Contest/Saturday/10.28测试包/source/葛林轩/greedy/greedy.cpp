#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int f[310][310];
int main()
{
	freopen("greedy.in", "r", stdin);
	freopen("greedy.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int w, l, r;
		cin >> w >> l >> r;
		f[l][r] = w;
	 } 
	for (int len = 1; len <= n; len++)
		for (int i = 1; i <= n - len + 1; i++)
		{
			int j = i + len - 1;
			int t = 0;
			for (int k = i; k <= j; k++)
			{
				for (int l = i; l <= k + 1; l++) t = max(t, f[i][k] + f[l][j] - (k != j && l != i) * f[l][k] - (k == j && l == i) * f[l][j]);
				for (int l = k + 2; l <= j; l++) 
					t = max(t, f[i][k] + f[l][j] + f[i][j]);
			}
			f[i][j] = t;
		}
	cout << f[1][n] << endl;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
