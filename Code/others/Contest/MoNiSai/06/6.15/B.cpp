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
// #define endl '\n'

#define pi acos(-1)
#define eps (1e-8)
#define null nullptr

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 100 + 10;
const int M = 2e5 + 10;

int t, n, m;
vector<PII> g[N];
bool vis[N], flag;
int ma[N][N];
int dis[N];

void dfs(int x){
	vis[x] = true;
	for(PII y:g[x]){
		if(!vis[y.fi])	dis[y.fi] = dis[x] + y.se, dfs(y.fi);
		else if(dis[x] + y.se != dis[y.fi]){ flag=true; return ;}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n;++j)	ma[i][j] = INF;
		flag=false;
		for(int i=1,x,y,z;i<=m;++i){
			cin>>x>>y>>z; --x;
			ma[x][y] = z, ma[y][x] = -z;
		}
		for(int k=0;k<=n;++k)
			for(int i=0;i<=n;++i)
				for(int j=0;j<=n;++j){
					if(i==j||i==k||k==j)	continue;
					if(ma[i][k]==INF||ma[k][j]==INF)	continue;
					if(ma[i][j] == INF){
						ma[i][j] = ma[i][k] + ma[k][j];
					}else if(ma[i][j] != ma[i][k] + ma[k][j]){ flag=true; break;}
				}
		if(flag)	cout<<"false"<<endl;
		else	cout<<"true"<<endl;
	}
	return 0;
}