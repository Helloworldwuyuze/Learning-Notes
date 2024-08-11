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
const int N = 2e5 + 10;
const int M = 5e6 + 10;
const int MOVE = 2e6+100;

int n, d, x[M], y[M], ans;
struct pnt{
	int x, y;
	bool operator <(const pnt &other) const { return x == other.x ? y<other.y : x<other.x; }
}p[N];

int b[M];
#define lowbit(x) (x&-x)
void update(int x,int k){ for(int i=x;i<=d+1;i+=lowbit(i))	b[i] += k;}
int query(int x){ int ans=0; for(int i=x;i;i-=lowbit(i))	ans += b[i]; return ans;}
#undef lowbit

bool cmp(pnt x, pnt y){
	return x.y < y.y;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>d;
	for(int i=1;i<=n;++i)	cin>>p[i].x>>p[i].y, p[i].x += MOVE, p[i].y += MOVE;
	sort(p+1, p+1+n);
	for(int i=1;i<=n;++i)	x[1] += abs(p[i].x - 1);
	int j = 0;
	if(x[1] <= d)	update(x[1] + 1, 1);
	for(int i=2;i<=MOVE*2+100;++i){
		x[i] = x[i-1] + j - (n-j);
		while(p[j+1].x == i && j<=n)	++j;
		if(x[i] <= d)	update(x[i]+1, 1);
	}
	j = 0;
	sort(p+1, p+1+n, cmp);
	for(int i=1;i<=n;++i)	y[1] += abs(p[i].y - 1);
	if(y[1] <= d)	ans += query(d - y[1] + 1);
	for(int i=2;i<=MOVE*2+100;++i){
		y[i] = y[i-1] + j - (n-j);
		while(p[j+1].y == i && j<=n)	++j;
		if(y[i] <= d)	ans += query(d - y[i] + 1);
	}
	cout<<ans<<endl;
	return 0;
}