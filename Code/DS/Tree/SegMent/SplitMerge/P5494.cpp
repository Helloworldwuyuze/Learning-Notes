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
#define null nullptr

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 1e6 + 10;

queue<int> Q;
int n, m, op, x, p, l, r, q, k;

int s[N<<5], ls[N<<5], rs[N<<5], root[N], idx;
void push_up(int p){ s[p] = s[ls[p]] + s[rs[p]];}
void split(int &p, int &q, int l, int r, int left, int right){
	if(!p)	return ;
	if(left<=l&&r<=right)	return (void)(q = p, p = 0);
	if(!q)	q=Q.front(), Q.pop();
	int mid = l+r>>1;
	if(left<=mid)	split(ls[p], ls[q], l, mid, left, right);
	if(right>mid)	split(rs[p], rs[q], mid+1, r, left, right);
	push_up(p), push_up(q);
}
void Del(int &x){
	s[x] = ls[x] = rs[x] = 0;
	Q.push(x), x = 0;
}
void merge(int &p, int &q, int l, int r){
	if(!p||!q)	return (void)(p = p + q);
	if(l == r)	return s[p] += s[q], Del(q);
	int mid = l+r>>1;
	merge(ls[p], ls[q], l, mid), merge(rs[p], rs[q], mid+1, r);
	push_up(p); return Del(q);
}
void update(int &p, int l, int r, int x, int k){
	if(!k)	return ;
	if(!p)	p = Q.front(), Q.pop();
	if(l==r)	return (void)(s[p] += k);
	int mid = l+r>>1;
	if(x<=mid)	update(ls[p], l, mid, x, k);
	else	update(rs[p], mid+1, r, x, k);
	push_up(p);
}
int query(int p, int l, int r, int left, int right){
	// cout<<"QUERY::"<<p<<" "<<l<<" "<<r<<" "<<left<<" "<<right<<" "<<s[p]<<endl;
	if(!p)	return 0;
	if(left<=l&&r<=right)	return s[p];
	int mid = l+r>>1, res = 0;
	if(left<=mid)	res += query(ls[p], l, mid, left, right);
	if(right>mid)	res += query(rs[p], mid+1, r, left, right);
	return res;
}
int kth(int p, int l, int r, int k){
	if(l==r)	return l;
	int mid = l+r>>1;
	if(s[ls[p]]>=k)	return kth(ls[p], l, mid, k);
	else	return kth(rs[p], mid+1, r, k - s[ls[p]]);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n<<5;++i)	Q.push(i);
	for(int i=1;i<=n;++i)	cin>>x, update(root[idx = 1], 1, n, i, x);
	// cout<<"QAQ"<<endl;
	while(m--){
		cin>>op;
		switch(op){
			case 0:{
				cin>>p>>l>>r; split(root[p], root[++idx], 1, n, l, r);
				break;
			}case 1:{
				cin>>p>>q; merge(root[p], root[q], 1, n);
				break;
			}case 2:{
				cin>>p>>x>>q; update(root[p], 1, n, q, x);
				break;
			}case 3:{
				cin>>p>>l>>r; cout<<query(root[p], 1, n, l, r)<<endl;
				break;
			}case 4:{
				cin>>p>>k;
				if(s[root[p]]<k)	cout<<-1<<endl;
				else	cout<<kth(root[p], 1, n, k)<<endl;
				break;
			}
		}
		// for(int i=1; i<Q.front(); ++i)
		// 	cout<<i<<" "<<s[i]<<" "<<ls[i]<<" "<<rs[i]<<endl;
		// cout<<endl;
	}
	return 0;
}