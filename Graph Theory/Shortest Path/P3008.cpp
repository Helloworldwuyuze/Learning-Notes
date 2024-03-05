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

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2.5e4 + 10;
const int M = 1e6 + 10;

int n,m,p,s,x,y,z;
vector<PII> g[N];
int dis[N];
bool vis[N];

void spfa(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0; 
	deque<int> q;
	q.push_back(s);
	while(q.size()){
		int x=q.front(); q.pop_front();
		vis[x]=false;
		for(PII y:g[x])
			if(dis[y.fi]>dis[x]+y.se){
				dis[y.fi]=dis[x]+y.se;
				if(!vis[y.fi]){
					if(q.size()&&dis[y.fi]<dis[q.front()])	q.push_front(y.fi);
					else	q.push_back(y.fi);
					vis[y.fi]=true;
				}
			}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>p>>s;
	for(int i=1;i<=m;++i)	cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
	for(int i=1;i<=p;++i)	cin>>x>>y>>z, g[x].pb(mk(y,z));
	spfa(s);
	for(int i=1;i<=n;++i)
		if(dis[i]>INF/2)	cout<<"NO PATH"<<endl;
		else	cout<<dis[i]<<endl;
	return 0;
}