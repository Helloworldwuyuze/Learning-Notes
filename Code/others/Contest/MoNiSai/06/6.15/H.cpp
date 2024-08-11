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
const int M = 1e6;

int n, m, cntq, cntm, ans = 1;
struct ques{
	int x, l, r;
	bool operator <(const ques &other) const { return x<other.x;}
}q[N];
struct modify{
	int x, y, f;
	bool operator <(const modify &other) const { return x<other.x;}
}mo[N<<1];

int b[M+10];
#define lowbit(x) (x&-x)
void update(int x,int k){ for(int i=x;i<=M+1;i+=lowbit(i))	b[i]+=k;}
int query(int x){ int ans=0; for(int i=x;i;i-=lowbit(i))	ans+=b[i]; return ans;}
#undef lowbit

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1,y,l,r;i<=n;++i){
		cin>>y>>l>>r; ++y, ++l, ++r;
		if(l==1 && r==M+1)	++ans;
		mo[++cntm] = {l-1, y, 1}, mo[++cntm] = {r, y, -1};
	}
	for(int i=1,x,l,r;i<=m;++i){
		cin>>x>>l>>r; ++x, ++l, ++r;
		if(l==1 && r==M+1)	++ans;
		q[++cntq] = {x, l, r};
	}
	sort(q+1, q+1+cntq), sort(mo+1, mo+1+cntm);
	// for(int i=1;i<=cntm;++i)	cout<<mo[i].x<<" "<<mo[i].y<<" "<<mo[i].f<<endl;
	// for(int i=1;i<=cntq;++i)	cout<<q[i].x<<" "<<q[i].l<<" "<<q[i].r<<endl;
	int i = 1, j = 1;
	// cout<<ans<<endl;
	while(mo[j].x == 0 && j<=cntm)	update(mo[j].y, mo[j].f), ++j;
	// int lstans = ans;
	for(int x = 1; x <= M+1; ++x){
		while(q[i].x == x && i<=cntq)	ans += query(q[i].r) - query(q[i].l-1), ++i;
		while(mo[j].x == x && j<=cntm)	update(mo[j].y, mo[j].f), ++j;
		// if(ans != lstans)	cout<<x<<" "<<ans<<endl, lstans = ans;
	}
	cout<<ans<<endl;
	return 0;
}