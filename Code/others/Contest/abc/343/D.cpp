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
const int N = 10 + 10;
const int M = 1e6 + 10;

int h,w,n,x[N],y[N];
int a[N],cnt,top;
PII st[N];
bool flag,vis[N];

bool chk(){
	int nx=0, ny=0;
	for(int i=1;i<=top;++i){
		int u=x[a[st[i].fi]], v=y[a[st[i].fi]];
		if(st[i].se)	swap(u,v);
		if(nx+u>w)	return false;
		for(int i=nx+1;i<=nx+w;++i)
			for(int j=ny+1;j<=ny+h;++i)
				if(ma[i][j]==true)	return false;
				else	ma[i][j]=true;
	}
}

void dfs(int l){
	if(l==cnt+1){
		if(chk())	flag=true;
		return ;
	}
	for(int i=1;i<=cnt;++i){
		if(vis[i])	continue;
		vis[i]=true; st[++top]=mk(i,0);
		dfs(l+1);
		vis[i]=false; --top;
		vis[i]=true; st[++top]=mk(i,1);
		dfs(l+1);
		vis[i]=false; --top;
	}
}

bool check(int s){
	int sum=1;
	while(s){
		if(s&1)	a[++cnt]=sum;
		++sum, s>>=1;
	}
	memset(vis,0,sizeof(vis));
	flag=false; dfs(1);
	return flag;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>h>>w;
	for(int i=1;i<=n;++i)	cin>>x[i]>>y[i];
	for(int i=1;i<=(1<<n)-1;++i){
		if(check(i)){cout<<"Yes"; break;}
	}
	return 0;
}