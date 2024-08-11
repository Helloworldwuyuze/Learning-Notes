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
typedef unsigned int ui;
const int N = 5e4 + 10;
const int M = 1e6 + 10;

int n, a[N], col[N], nn, m, ans1[N], ans2[N], sum, s1, s2, x[N], y[N];
struct node{
	int l, r, id;
	bool operator <(const node &other) const {
		if(l/nn == other.l/nn)	return (l/nn%2)?r>other.r:r<other.r;
		else	return l/nn < other.l/nn;
	}
}range[N];

int gcd(int x,int y){ return y==0?x:gcd(y, x%y);}

void addr(int x){ s1 += col[a[x]], col[a[x]] ++, s2 += sum, sum ++;}
void addl(int x){ s1 += col[a[x]], col[a[x]] ++, s2 += sum, sum ++;}
void delr(int x){ s1 -= --col[a[x]], s2 -= --sum;}
void dell(int x){ s1 -= --col[a[x]], s2 -= --sum;}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m; nn = sqrt(n);
	for(int i=1;i<=n;++i)	cin>>a[i];
	for(int i=1;i<=m;++i)	cin>>x[i]>>y[i], range[i] = node{x[i], y[i], i};
	sort(range+1, range+1+m);
	int l = 1, r = 0;
	for(int i=1;i<=m;++i){
		while(r<range[i].r)	addr(++r);
		while(l>range[i].l)	addl(--l);
		while(r>range[i].r)	delr(r--);
		while(l<range[i].l)	dell(l++);
		// cerr<<range[i].l<<" "<<range[i].r<<" "<<l<<" "<<r<<" "<<s1<<" "<<s2<<endl;
		ans1[range[i].id] = s1, ans2[range[i].id] = s2;
	}
	for(int i=1;i<=m;++i){
		if(x[i] == y[i])	cout<<"0/1"<<endl;
		else{
			int g = gcd(ans1[i], ans2[i]);
			cout<<ans1[i]/g<<"/"<<ans2[i]/g<<endl;
		}
	}
	return 0;
}