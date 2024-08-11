#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
int num[200010];
int l[200010], r[200010], a[200010];
long long ans = 0;
void dfs(int x)
{
	if (x == n + 1)
	{
		long long sum = 0;
		for (int i = 1; i <= m; i++)
		{
			bool f = false;
			for (int j = l[i]; j <= r[i]; j++)
				if (num[j])
				{
					f = true;
					break;
				}
			if (f) sum += a[i];
		}
		ans = max(ans, sum);
		return;
	}
	num[x] = 0;
	dfs(x + 1);
	num[x] = 1;
	dfs(x + 1);
}
int main()
{
	freopen("intervals.in", "r", stdin);
	freopen("intervals.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> l[i] >> r[i] >> a[i];
	dfs(1);
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
