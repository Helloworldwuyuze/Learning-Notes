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
const int N = 1e3 + 10;
const int M = 2e5 + 10;

int n,m,q;
bool tag[N<<3][N<<3], vis[N<<3][N<<3];
struct line{
	int a,b,c,d;
}a[N];
int b[N<<2], cnt, ans;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

void dfs(int x,int y){
	vis[x][y]=true;
	for(int i:{0, 1, 2, 3}){
		int xx = x + dx[i], yy = y + dy[i];
		if(xx>m||yy>n||xx<=0||yy<=0)	continue;
		dfs(xx, yy);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=q;++i){
		cin>>a[i].a>>a[i].b>>a[i].c>>a[i].d;
		b[++cnt] = a[i].a, b[++cnt] = a[i].b, b[++cnt] = a[i].c, b[++cnt] = a[i].d;
	}
	sort(b+1, b+1+cnt);
	cnt = unique(b+1, b+1+cnt) - b - 1;
	for(int i=1;i<=q;++i){
		a[i].a = lower_bound(b+1, b+1+cnt, a[i].a) -b;
		a[i].b = lower_bound(b+1, b+1+cnt, a[i].b) -b;
		a[i].c = lower_bound(b+1, b+1+cnt, a[i].c) -b;
		a[i].d = lower_bound(b+1, b+1+cnt, a[i].d) -b;
		a[i].a = a[i].a*2-1; a[i].b = a[i].b*2-1; a[i].c = a[i].c*2-1; a[i].d = a[i].d*2-1;
	}
	for(int i=1;i<=q;++i){
		if(a[i].a==a[i].c){
			int l = min(a[i].b, a[i].d), r = max(a[i].b, a[i].d);
			for(int i=l;i<=r;++i)	tag[a[i].a+1][i] = true;
		}else{
			int l = min(a[i].a, a[i].c), r = max(a[i].b, a[i].d);
			for(int i=l;i<=r;++i)	tag[i][a[i].b+1] = true;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(!vis[i][j])	dfs(i,j), ++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}