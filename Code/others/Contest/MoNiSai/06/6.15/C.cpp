#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>

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
#define endl '\n'

#define pi acos(-1)
#define eps (1e-8)
#define null nullptr

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e3 + 10;
const int M = 5e2 + 10;

char s1[N], s2[N];
int k, n, m;
int f[N][N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>(s1+1)>>(s2+1)>>k;
	int n = strlen(s1 + 1), m = strlen(s2 + 1);
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			if(i==0&&j==0)  continue;
			else if(i==0)	f[i][j] = j*k;
			else if(j==0)	f[i][j] = i*k;
			else	f[i][j] = min(min(f[i-1][j], f[i][j-1]) + k, f[i-1][j-1] + abs(s1[i] - s2[j]));
			// cout<<f[i][j]<<" ";
		}
	}
	cout<<f[n][m]<<endl;
	return 0;
}