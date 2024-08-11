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

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n, m, V, v[N], w[N], bl[N], re[N], idx, q[N], num[N], tail, head, f[N];
vector<int> gp[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>V;
	for(int i=1;i<=n;++i)	cin>>w[i]>>v[i]>>re[i];
	for(int i=1;i<=n;++i){
		int rest = min(re[i], V/w[i]);
		for(int d=0;d<w[i];++d){
			tail = 0, head = 1;
			int lim = (V-d)/w[i];
			for(int j=0;j<=lim;++j){
				while(head<=tail && f[j*w[i]+d] - j*v[i] >= q[tail])	--tail;
				q[++tail] = f[j*w[i]+d] - j*v[i], num[tail] = j;
				while(head<=tail && num[head]+rest < j)	++head;
				f[j*w[i]+d] = max(f[j*w[i]+d], q[head]+j*v[i]);
			}
		}
	}
	++idx;
	for(int i=0;i<=V;++i)
		v[i] = f[i], w[i] = i, bl[i] = idx, gp[idx].pb(i);
	for(int i=1;i<=m;++i){
		int a, b, c;
		++idx; cin>>a>>b>>c;
		for(int j=0;j<=V;++j)
			v[i*(V+1)+j] = a*j*j+b*j+c, w[i*(V+1)+j] = j, bl[i*(V+1)+j] = idx;
	}
	n = (m+1)*(V+1);
	// for(int i=1;i<=n;++i)
	// 	cout<<v[i]<<" "<<w[i]<<" "<<bl[i]<<endl;
	for(int i=1;i<=n;++i)	gp[bl[i]].pb(i);
	memset(f, 0, sizeof(f));
	for(int i=1;i<=m+1;++i)
		for(int j=V;j>=0;--j)
			for(int k:gp[i])
				if(j>=w[k])	f[j] = max(f[j], f[j-w[k]]+v[k]);
	cout<<f[V]<<endl;
	return 0;
}