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
const int MOD = 1e9 + 7;

int n,m,l1,r1,l2,r2,t;
int fa[N][20];

int find(int x,int k){ return x==fa[x][k]?x:fa[x][k]=find(fa[x][k], k);}

void merge(int l,int r,int L,int R){
	int t = log(r-l+1)/log(2);
	int x = find(l, t), y = find(L, t);
	int X = find(r-(1<<t)+1, t), Y = find(R-(1<<t)+1, t);
//	cerr<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<t<<" "<<x<<" "<<y<<" "<<X<<" "<<Y<<endl;
	if(x>y)	swap(x,y);
	if(X>Y)	swap(X,Y);
	fa[x][t] = y;
	fa[X][t] = Y;
}

int ksm(int x,int m){
	int ans=1;
	while(m){ if(m&1) ans=ans*x%MOD; x=x*x%MOD; m>>=1;}
	return ans;
}
bool vis[N];

signed main(){
//	freopen("P3295_4.in","r",stdin); 
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m; t = log(n)/log(2);
	for(int j=0;j<=t;++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			fa[i][j]=i;
	for(int i=1;i<=m;++i){
		cin>>l1>>r1>>l2>>r2;
//		if(l1>l2)	swap(l1, l2), swap(r1, r2);
		merge(l1, r1, l2, r2);
	}
//	cerr<<"QAQ"<<endl;
	for(int j = t; j; --j)
		for(int i = 1; i+(1<<j)-1<=n; ++i)
			if(find(i, j)!=i){
				int x = i, y = find(i, j);
				int xx = find(x, j-1), yy = find(y, j-1);
				fa[xx][j-1] = yy;
				xx = find(x+(1<<j-1), j-1), yy=find(y+(1<<j-1), j-1);
				fa[xx][j-1] = yy;
			}
	// for(int j=0;j<=t;++j,cout<<endl)
	// 	for(int i=1;i+(1<<j)-1<=n;++i){
	// 		cout<<fa[i][j]<<" ";
	// 	}
	int ans=9*ksm(10,MOD-2)%MOD;
	for(int i=1;i<=n;++i){
		int f = find(i, 0);
		if(!vis[f])	vis[f]=true, ans=ans*10%MOD;
	}
	cout<<ans<<endl;
	return 0;
}
