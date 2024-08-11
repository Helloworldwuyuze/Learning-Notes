#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>
#include<unordered_map>

#include<bitset>
#include<set>

#include<deque>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>
#include<random>

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define DBG cerr << __LINE__ << ' ' << __FUNCTION__ << endl

#define DRE default_random_engine
#define UID uniform_int_distribution
#define y0 Y0
#define y1 Y1

#define pi acos(-1)
#define eps (1e-8)
#define endl '\n'

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e2 + 10;
const int M = 2e6 + 10;

int sum[N][N][N], m, n;
struct qry{
	int x, y, z, f;
}q[M];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)	cin>>sum[i][j][k];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				sum[i][j][k] += sum[i-1][j][k] + sum[i][j-1][k] + sum[i][j][k-1] - sum[i-1][j-1][k] - sum[i-1][j][k-1] - 
				sum[i][j-1][k-1] + sum[i-1][j-1][k-1];
	cin>>m;
	while(m--){
		int xmn, xmx, ymn, ymx, zmn, zmx;
		cin>>xmn>>xmx>>ymn>>ymx>>zmn>>zmx; --xmn, --ymn, --zmn;
		cout<<sum[xmx][ymx][zmx] - sum[xmn][ymx][zmx] - sum[xmx][ymn][zmx] - sum[xmx][ymx][zmn] + 
				sum[xmn][ymn][zmx] + sum[xmn][ymx][zmn] + sum[xmx][ymn][zmn] - sum[xmn][ymn][zmn]<<endl;
	}
	return 0;
}