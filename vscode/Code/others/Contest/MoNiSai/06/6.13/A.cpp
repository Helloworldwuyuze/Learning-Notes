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

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 2e5 + 10;

int n, m, c, mx, ans;
vector<PII> g[N];
int dis[N], sum[N], b[N];
struct edge{
    int u, v, d;
}e[M];
bool vis[N];
priority_queue<PII, vector<PII>, greater<PII> >q;

void dijkstra(int s){
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0; q.push(mk(0, s));
    while(q.size()){
        int x = q.top().se; q.pop();
        if(vis[x])  continue;
        vis[x] = true;
        for(PII y:g[x])
            if(dis[y.fi]>dis[x] + y.se){
                dis[y.fi] = dis[x] + y.se;
                q.push(mk(dis[y.fi], y.fi));
            }
    }
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n>>m>>c;
    for(int i=1; i<=m; ++i)   cin>>e[i].u>>e[i].v>>e[i].d, g[e[i].u].pb(mk(e[i].v, e[i].d)), g[e[i].v].pb(mk(e[i].u, e[i].d)), ans += e[i].d;
    dijkstra(1);
    memcpy(b, dis, sizeof(dis));
    sort(b+1, b+1+n);
    int cnt = unique(b+1, b+1+n)-b-1;
    for(int i=1;i<=n;++i)
        dis[i] = lower_bound(b+1, b+1+cnt, dis[i]) - b;
    // for(int i=1;i<=n;++i)
        // cout<<dis[i]<<" ";
    // cout<<endl;
    for(int i=1; i<=m; ++i)
        sum[max(dis[e[i].u], dis[e[i].v])] += e[i].d;
    // for(int i=1;i<=n;++i)
    //     cout<<sum[i]<<" ";
    // cout<<endl;
    for(int i = n; i>=0; --i)
        sum[i] += sum[i+1];
    sort(dis+1, dis+1+n);
    for(int i=1;i<=n;++i){
        ans = min(ans, c*b[dis[i]] + sum[dis[i]+1]);
    }
    cout<<ans<<endl;
	return 0;
}