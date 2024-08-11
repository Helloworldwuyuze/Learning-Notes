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
typedef unsigned int ui;
const int N = 1e6 + 10;
const int M = 1e6 + 10;

int n, q, x, y, z;
int a[N], nn, blk[N], l[N], r[N], tag[N], cnt, b[N];
char op;

void init(){
	nn = sqrt(n);
	for(int i=1;i<=n;++i){
		blk[i] = (i-1)/nn+1;
		l[blk[i]] = (blk[i] - 1) * nn + 1;
		r[blk[i]] = min(blk[i] * nn, n);
		b[i] = a[i];
	}
	cnt = blk[n];
	for(int i=1;i<=cnt;++i)
		sort(b+l[i], b+1+r[i]);
}
void cpy(int x){
	for(int i=l[x];i<=r[x];++i)
		b[i] = a[i];
	sort(b+l[x], b+1+r[x]);
}
void update(int left,int right,int x){
	int bl = blk[left], br = blk[right];
	if(bl==br){
		for(int i=left;i<=right;++i)
			a[i] += x;
		cpy(bl);
		return ;
	}
	for(int i=left;i<=r[bl];++i)	a[i] += x;
	for(int i=l[br];i<=right;++i)	a[i] += x;
	cpy(bl), cpy(br);
	for(int i=bl+1;i<br;++i)
		tag[i] += x;
}
int query(int left,int right,int x){
	int bl = blk[left], br = blk[right], sum = 0;
	if(bl == br){
		for(int i=left;i<=right;++i)
			sum += a[i] >= (x-tag[bl]);
		return sum;
	}
	for(int i=left;i<=r[bl];++i)	sum += a[i] >= (x-tag[bl]);
	for(int i=l[br];i<=right;++i)	sum += a[i] >= (x-tag[br]);
	for(int i=bl+1;i<br;++i){
		if(b[r[i]] < x-tag[i])	continue;
		int t = lower_bound(b+l[i], b+r[i]+1, x-tag[i]) - b;
		// cout<<le<<" "<<r[i]<<endl;
		sum += r[i] - t + 1;
	}
	return sum;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)   cin>>a[i];
	init();
	// for(int i=1;i<=n;++i)
	// 	cout<<blk[i]<<" "<<l[i]<<" "<<r[i]<<" "<<b[i]<<endl;
	while(q--){
		cin>>op>>x>>y>>z;
		if(op=='M')	update(x, y, z);
		else	cout<<query(x, y, z)<<endl;
		// cout<<"#####"<<endl;
		// for(int i=1;i<=n;++i)
		// 	cout<<blk[i]<<" "<<l[i]<<" "<<r[i]<<" "<<a[i]<<endl;
	}
	return 0;
}