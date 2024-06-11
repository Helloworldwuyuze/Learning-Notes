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
#define null nullptr

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 3e5 + 10;
const int M = 1e6 + 10;

int n, m, s, l;
struct cows{
	int l, r, id;
	bool operator <(const cows &other) const{ return l==other.l?r>other.r:l<other.l;}
}c[N];
int ans[N];

int b[N];
#define lowbit(x) (x&-x)
void update(int x,int k){ for(int i=x;i<=m;i+=lowbit(i))	b[i]+=k;}
int query(int x){ int ans=0; for(int i=x;i;i-=lowbit(i))	ans+=b[i]; return ans;}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while(cin>>n&&n){
		m=l=0;
		for(int i=1;i<=n;++i)	cin>>c[i].l>>c[i].r, ++c[i].l, ++c[i].r, m=max(c[i].r, m), c[i].id=i;
		sort(c+1, c+1+n);
		for(int i=1;i<=n;++i){
			if(c[i].l!=c[i-1].l||c[i].r!=c[i-1].r)	l=i;
			ans[c[i].id] = query(m) - query(c[i].r-1) - (i-l);
			update(c[i].r, 1);
		}
		for(int i=1;i<=n;++i)	cout<<ans[i]<<" ";
		cout<<endl;
		for(int i=1;i<=n;++i)	update(c[i].r, -1);
	}
	return 0;
}