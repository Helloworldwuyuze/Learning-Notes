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

int n, s, t, tt;
struct station{
	int x, c;
	bool operator <(const station &other) const { return x<other.x; }
}a[N];
int st[N], top, du[N], dis[N];
vector<PII> g[N];

void topu(){
	queue<int> q;
	for(int i=1;i<=n;++i)	dis[i] = 3e18;
	// memset(dis, 0x3f, sizeof(dis));
	for(int i=1;i<=n;++i)
		if(!du[i])	q.push(i), dis[i] = a[i].x == s ? 0 : dis[i];
	while(q.size()){
		int x = q.front(); q.pop();
		for(PII y:g[x]){
			dis[y.fi] = min(dis[y.fi], dis[x] + y.se);
			if(--du[y.fi] == 0)	q.push(y.fi);
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>s>>t;
	for(int i=1;i<=n;++i)	cin>>a[i].c>>a[i].x;
	++n, a[n] = station{t, 0};
	sort(a+1, a+1+n);
	for(int i=1;i<=n;++i){
		if(!a[i].c)	tt = i;
		while(top && a[st[top]].c >= a[i].c)	--top;
		if(top)	g[i].pb(mk(st[top], a[i].c*(a[i].x - a[st[top]].x))), ++du[st[top]];
		if(a[i].x != s)	st[++top] = i;
	}
	top = 0;
	for(int i=n;i;--i){
		while(top && a[st[top]].c >= a[i].c)	--top;
		if(top)	g[i].pb(mk(st[top], a[i].c*(a[st[top]].x - a[i].x))), ++du[st[top]];
		if(a[i].x != s)	st[++top] = i;
	}
	topu();
	cout<<dis[tt]<<endl;
	return 0;
}