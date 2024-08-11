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
// #define endl '\n'

#define pi acos(-1)
#define eps (1e-8)
#define null nullptr

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 3e5 + 10;
const int M = 3e5 + 10;
const int MOD = 19260817;

struct matrix{
	int n, m, a[4][4];
	matrix(){}
	matrix(int n, int m): n(n), m(m) {
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)	a[i][j] = 0;
		if(n==m)	for(int i=1;i<=n;++i)	a[i][i] = 1;
	}
	void print(){
		cout<<n<<" "<<m<<endl;
		for(int i=1;i<=n;++i,cout<<endl)
			for(int j=1;j<=m;++j)
				cout<<a[i][j]<<" ";
	}
};
matrix operator *(matrix x, matrix y){
	matrix ans(x.n, y.m);
	for(int i=1;i<=x.n;++i)
		for(int j=1;j<=y.m;++j)	ans.a[i][j] = 0;
	if(x.m!=y.n)    return ans;
	for(int i=1;i<=ans.n;++i)
		for(int j=1;j<=ans.m;++j){
			for(int k=1;k<=x.m;++k)
				ans.a[i][j] += x.a[i][k] * y.a[k][j];
			ans.a[i][j]%=MOD;
		}
	return ans;
}
matrix operator +(matrix x, matrix y){
	matrix ans(x.n, x.m);
	if(x.n!=y.n||x.m!=y.m)	return ans;
	for(int i=1;i<=x.n;++i)
		for(int j=1;j<=x.m;++j)
			ans.a[i][j] = (x.a[i][j] + y.a[i][j]) % MOD;
	return ans;
}
bool operator ==(matrix x, matrix y){
	if(x.n!=y.n||x.m!=y.m)	return false;
	for(int i=1;i<=x.n;++i)
		for(int j=1;j<=x.m;++j)
			if(x.a[i][j]!=y.a[i][j])	return false;
	return true;
}

matrix t[N<<2], tag[N<<2], E33(3, 3);
matrix k, a[N];
void push_up(int p){ t[p] = t[p<<1] + t[p<<1|1];}
void push_down(int p){
	if(tag[p]==E33)	return ;
	tag[p<<1] = tag[p] * tag[p<<1], tag[p<<1|1] = tag[p] * tag[p<<1|1];
	t[p<<1] = tag[p] * t[p<<1], t[p<<1|1] = tag[p] * t[p<<1|1];
	tag[p] = E33;
}
void build(int p,int l,int r){
	tag[p] = E33;
	if(l==r)	return (void)(t[p] = a[l]);
	int mid = l+r>>1;
	build(p<<1, l, mid), build(p<<1|1, mid+1, r);
	push_up(p);
}
void update(int p,int l,int r,int left,int right,matrix k){
	if(left<=l&&r<=right){ t[p] = k * t[p], tag[p] = k * tag[p]; return ;}
	int mid = l+r>>1;
	push_down(p);
	if(left<=mid)	update(p<<1, l, mid, left, right, k);
	if(right>mid)	update(p<<1|1, mid+1, r, left, right, k);
	push_up(p);
}
int query(int p,int l,int r,int left,int right){
	if(left<=l&&r<=right)	return t[p].a[1][1];
	int mid = l+r>>1, res = 0;
	push_down(p);
	if(left<=mid)	res += query(p<<1, l, mid, left, right);
	if(right>mid)	res += query(p<<1|1, mid+1, r, left, right);
	return res % MOD;
}

int n, m, op, l, r, v, x, lst;

void inita(matrix &x, int v){
	x.n = 3, x.m = 1;
	x.a[1][1] = v, x.a[2][1] = 0, x.a[3][1] = 1;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>x, inita(a[i], x);
	build(1, 1, n);
	while(m--){
		cin>>op>>l>>r; l^=lst, r^=lst;
		if(op==1)	cout<<(lst = query(1, 1, n, l, r))<<endl;
		else if(op==2){
			cin>>v; v^=lst; k.m = k.n = 3;
			for(int i=1;i<=3;++i)
				for(int j=1;j<=3;++j)	k.a[i][j] = 0;
			k.a[1][1] = k.a[2][2] = k.a[3][3] = 1, k.a[1][3] = v;
			update(1, 1, n ,l, r, k);
		}else if(op==3){
			cin>>v; v^=lst; k.m = k.n = 3;
			for(int i=1;i<=3;++i)
				for(int j=1;j<=3;++j)	k.a[i][j] = 0;
			k.a[1][1] = k.a[2][2] = k.a[3][3] = 1, k.a[2][3] = v;
			update(1, 1, n, l, r, k);
		}else if(op==4){
			k.m = k.n = 3;
			for(int i=1;i<=3;++i)
				for(int j=1;j<=3;++j)	k.a[i][j] = 0;
			k.a[1][1] = k.a[2][2] = k.a[3][3] = k.a[1][2] = 1;
			update(1, 1, n, l, r, k);
		}
		// for(int i=1;i<=n<<1;++i)
		// 	cout<<"###"<<i<<"###"<<endl, t[i].print(), tag[i].print();
	}
	return 0;
}