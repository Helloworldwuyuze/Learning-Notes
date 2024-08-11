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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 128 + 10;

int n, m, k, a[N], pre[N], x[N], y[N], tot, fa[N];
char c[N];

struct bignum{
	int a[N], len;
	void print(){
		for(int i=len;i;--i)
			cout<<a[i];
		cout<<endl;
	}
};
bignum operator *(bignum a,int x){
	int f=0;
	for(int i=1;i<=a.len;++i){
		a.a[i] = a.a[i]*x+f, f = a.a[i]/10, a.a[i]%=10;
	}
	if(f)	a.a[++a.len] = f;
	return a;
}

int find(int x){ return x==fa[x]?fa[x]:fa[x]=find(fa[x]);}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>k;
	for(int i=1;i<=k;++i)	cin>>a[i], tot += a[i];
	pre[1] = 2;
	for(int i=2;i<=k+1;++i)	pre[i] = pre[i-1] + a[i-1];
	cin>>(c+1); int len = strlen(c+1);
	for(int i=1;i<=len;++i){
		if(c[i]<='z'&&c[i]>='a')
			for(int j = pre[c[i]-'a'+1]+1; j<=pre[c[i]-'a'+2]; ++j)	x[++n] = j;
		else	x[++n] = c[i] - '0' + 1;
	}
	cin>>(c+1); len = strlen(c+1);
	for(int i=1;i<=len;++i){
		if(c[i]<='z'&&c[i]>='a')
			for(int j = pre[c[i]-'a'+1]+1; j<=pre[c[i]-'a'+2]; ++j)	y[++m] = j;
		else	y[++m] = c[i] - '0' + 1;
	}
	if(n!=m)	return cout<<0<<endl, 0;
	for(int i = 1; i<=tot+2; ++i)	fa[i] = i;
	for(int i = 1; i<=n; ++i){
		int fx = find(x[i]), fy = find(y[i]);
		if(fx+fy==3){ cout<<0<<endl; return 0;}
		if(fx==fy)	continue;
		fa[fx] = fy; --tot;
	}
	bignum ans; ans.len = ans.a[1] = 1;
	while(tot--)	ans = ans * 2;
	ans.print();
	return 0;
}