#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>

#include<bitset>
#include<set>

#include<deque>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>

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
const int N = 3e5 + 10;
const int M = 1e6 + 10;

struct node{
	int x, y, ans;
	bool west, east;
	bool operator <(const node &other) const { return x == other.x ? y>other.y : x<other.x;}
}pnt[N];
vector<int> g[N];
int n, m, w, h, sum;
bool vis[N];

void dfs(int x){
	vis[x] = true, sum += pnt[x].east;
	for(int i=0;i<g[x].size();++i)
		if(!vis[g[x][i]])	dfs(g[x][i]);
}

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>w>>h;
	for(int i=1;i<=n;++i)
		cin>>pnt[i].x>>pnt[i].y, pnt[i].west = pnt[i].x==0, pnt[i].east = pnt[i].x==w;
	for(int i=1,x,y,k;i<=m;++i){
		cin>>x>>y>>k;
		g[x].pb(y);
		if(k==2)	g[y].pb(x);
	}
	for(int i=1;i<=n;++i)
		if(pnt[i].west){
			for(int i=1;i<=n;++i)	vis[i] = false;
			sum = 0, dfs(i), pnt[i].ans = sum;
		}
	sort(pnt+1, pnt+1+n);
	for(int i=1;i<=n;++i){
		if(!pnt[i].west)	return 0;
		cout<<pnt[i].ans<<endl;
	}
	return 0;
}

