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

#define int __int128
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e3 + 10;
const int M = 1e6 + 10;

inline void read(int &x){
	int f = 1; x = 0;
	char c = getchar();
	for(; c<'0'||c>'9'; c=getchar()) if(c=='-') f = -1;
	for(; c<='9'&&c>='0'; c=getchar())	x = (x<<1)+(x<<3)+(c^'0');
	x *= f;
}
void write(int x){
	if(x<0)	putchar('-'), write(-x);
	if(x>=10)	write(x/10);
	if(x>=0)	putchar(x%10+'0');
}

int T, n, m;
int a[N], b[N];

int gcd(int x,int y){ return y==0?x:gcd(y, x%y); }

struct seg{
	int g[N<<2];
	void update(int p,int l,int r,int x,int k){
		if(l == r)	return (void)(g[p] = k);
		int mid = l+r>>1;
		if(x<=mid)	update(p<<1, l, mid, x, k);
		else	update(p<<1|1, mid+1, r, x, k);
		g[p] = gcd(g[p<<1], g[p<<1|1]);
	}
}s[N], t[N];
bool x[N], y[N];
int cntx, cnty;

bool chk(){
	bool flag = false;
	if(cntx == n || cnty == m)	return false;
	for(int i=1;i<=n;++i)
		if(!x[i] && s[i].g[1] > 1){
			x[i] = true; ++cntx;
			// cout<<"QAQ"<<endl;
			// write(i), putchar(' '), write(a[i]), puts("");
			for(int j=1;j<=m;++j)
				t[j].update(1, 1, n, i, 0);
			flag |= 1;
		}
	for(int j=1;j<=m;++j)
		if(!y[j] && t[j].g[1] > 1){
			y[j] = true, ++cnty;
			// cout<<"QAQ"<<endl;
			// write(j), putchar(' '), write(b[j]), puts("");
			for(int i=1;i<=n;++i)
				s[i].update(1, 1, m, j, 0);
			flag |= 1;
		}
	return flag;
}

signed main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0), cout.tie(0);
	read(T);
	while(T--){
		read(n), read(m);
		cntx = cnty = 0;
		for(int i=1;i<=n;++i)	read(a[i]), x[i] = false;
		for(int i=1;i<=m;++i)	read(b[i]), y[i] = false;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				s[i].update(1, 1, m, j, a[i]/gcd(a[i], b[j]));
			// cout<<"### I:"; write(i); cout<<"###"<<endl;
			// for(int j=1;j<=m<<1;++j)	write(s[i].g[j]), putchar(' ');
			// puts("");
		for(int j=1;j<=m;++j)
			for(int i=1;i<=n;++i)
				t[j].update(1, 1, n, i, b[j]/gcd(b[j], a[i]));
			// cout<<"### J:"; write(j); cout<<"###"<<endl;
			// for(int i=1;i<=n<<1;++i)	write(t[j].g[i]), putchar(' ');
			// puts("");
		while(chk()){
			// for(int i=1;i<=n;++i){
			// 	cout<<"### I:"; write(i); cout<<"###"<<endl;
			// 	for(int j=1;j<=m<<1;++j)	write(s[i].g[j]), putchar(' ');
			// 	puts("");
			// }
			// for(int j=1;j<=m;++j){
			// 	cout<<"### J:"; write(j); cout<<"###"<<endl;
			// 	for(int i=1;i<=n<<1;++i)	write(t[j].g[i]), putchar(' ');
			// 	puts("");
			// }
		}
		if(cntx == n || cnty == m)	puts("NO");
		else{
			puts("YES");
			write(n-cntx), putchar(' '), write(m-cnty), puts("");
			for(int i=1;i<=n;++i)
				if(!x[i])	write(a[i]), putchar(' ');
			puts("");
			for(int i=1;i<=m;++i)
				if(!y[i])	write(b[i]), putchar(' ');
			puts("");
		}
	}
	return 0;
}

