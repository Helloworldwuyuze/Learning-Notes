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
const int N = 1e6 + 10;
const int M = 1e6 + 10;

int val[N], sum[N][20], n, m, dep[N], pre[N][20];
int x, y, k;

void dfs(int x){
	dep[x] = dep[x/2] + 1;
	if(x >= (1<<n-1) && x <= (1<<n)-1){
		sum[x][0] = pre[x][0] = val[x];
		for(int i=1;i<=n;++i)	pre[x][i] = pre[x][0];
		return ;
	}
	dfs(x<<1), dfs(x<<1|1);
	for(int i=1;i<n-dep[x];++i)
		sum[x][i] = sum[x<<1][i-1] + sum[x<<1|1][i-1];
	sum[x][0] = pre[x][0] = val[x];
	for(int i=1;i<=n;++i)	pre[x][i] = sum[x][i] + pre[x][i-1];
}

int lca(int x,int y){
	if(dep[x] < dep[y])	swap(x, y);
	while(dep[x] > dep[y])	x>>=1;
	while(x != y)	x>>=1, y>>=1;
	return x;
}

int get(int x,int k){
	if(k<0)	return 0;
	int ans = k>=n ? pre[x][n] : pre[x][k];
	// cout<<"ANS! "<<ans<<endl;
	for(int i=1,y=x>>1,z=x;i<=k&&y;++i,z=y,y>>=1){
		if(k-i<=n)	ans += pre[y][k-i] - pre[z][k-i-1];
		else	ans += pre[y][n] - pre[z][n];
		// cout<<"ANS! "<<i<<" "<<ans<<endl;
	}
	// cout<<"Get! "<<x<<" "<<k<<" "<<ans<<endl;
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=(1<<n)-1;++i)	cin>>val[i];
	dep[0] = -1; dfs(1);
	// for(int i=1;i<=(1<<n)-1;++i)	cout<<dep[i]<<" ";
	// cout<<endl;
	// for(int i=1;i<=(1<<n)-1;++i,cout<<endl)
	// 	for(int j=0;j<=n;++j)	cout<<sum[i][j]<<" ";
	// for(int i=1;i<=(1<<n)-1;++i,cout<<endl)
	// 	for(int j=0;j<=n;++j)	cout<<pre[i][j]<<" ";
	// cin>>m;
	while(m--){
		cin>>x>>y>>k;
		int l = lca(x, y);
		if(l == x || l == y){
			if(l == y)	swap(x, y);
			int dis = dep[y] - dep[x];
			if(dis&1){
				// cerr<<"Situation 1"<<endl;
				int mdis = (dis+1)/2;
				int m1 = y, m2 = y;
				while(dep[y] - dep[m1] != dep[m1] - dep[x] - 1)	m1>>=1;
				m2 = m1>>1;
				if(k>=mdis)	cout<<(k-mdis>n ? 0 : sum[m1][k-mdis]) + get(m2, k-mdis)<<endl;
				else	cout<<0<<endl;
			}else{
				// cerr<<"Situation 2"<<endl;
				int mdis = dis>>1;
				int m = y;
				while(dep[y] - dep[m] != dep[m] - dep[x])	m>>=1;
				if(k>=mdis)	cout<<get(m, k-mdis)<<endl;
				else	cout<<0<<endl;
			}
		}else{
			int dis = dep[x] + dep[y] - 2*dep[l];
			if(dis&1){
				// cerr<<"Situation 3"<<endl;
				int mdis = (dis+1)/2;
				if(dep[y] > dep[x])	swap(x, y);
				int m1 = x, m2 = x;
				// cerr<<x<<" "<<y<<endl;
				while(dep[x] - dep[m1] != dep[m1] + dep[y] - 1 - 2*dep[l])	m1>>=1;
				m2 = m1>>1;
				// cerr<<m1<<" "<<m2<<endl;
				if(k>=mdis)	cout<<(k-mdis>n ? 0 : sum[m1][k-mdis]) + get(m2, k-mdis)<<endl;
				else	cout<<0<<endl;
			}else{
				// cerr<<"Situation 4"<<endl;
				int mdis = dis>>1;
				if(dep[y] > dep[x])	swap(x, y);
				int m = x;
				while(dep[x] - dep[m] != dep[m] + dep[y] - 2*dep[l])	m>>=1;
				// cout<<dis<<endl;
				if(k>=mdis)	cout<<get(m, k-mdis)<<endl;
				else	cout<<0<<endl;
			}
		}
	}
	return 0;
}