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
const int N = 1e3 + 10;
const int M = 1e6 + 10;

int n, m, w[N], v[N], belong[N], f[N], k, b[N];
vector<int> group[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=n;++i)	cin>>w[i]>>v[i]>>belong[i], b[i] = belong[i];
	sort(b+1, b+1+n), k = unique(b+1, b+1+n) - b - 1;
	for(int i=1;i<=n;++i)	belong[i] = lower_bound(b+1, b+1+k, belong[i]) - b, group[belong[i]].pb(i);
	for(int i=1;i<=k;++i)
		for(int j=m;j>=0;--j)
			for(int k:group[i])
				if(j>=w[k])	f[j] = max(f[j], f[j-w[k]]+v[k]);
	cout<<f[m]<<endl;
	return 0;
}