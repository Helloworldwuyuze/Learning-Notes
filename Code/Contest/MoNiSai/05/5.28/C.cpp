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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n, a[N], b[N], m;

struct node{
	int t[N<<2], tag[N<<2];
	void push_down(int p){
		if(tag[p]==INF)	return ;
		tag[p<<1]=tag[p<<1|1]=tag[p];
		t[p<<1]=t[p<<1|1]=tag[p];
		tag[p]=INF;
	}
	void update(int p,int l,int r,int left,int right,int k){
		if(left<=l&&r<=right){ tag[p]=k; t[p]=k; return ;}
		int mid=l+r>>1;
		push_down(p);
		if(left<=mid)	update(p<<1,l,mid,left,right,k);
		if(right>mid)	update(p<<1|1,mid+1,r,left,right,k);
	}
	int query(int p,int l,int r,int x){
		if(l==r)	return t[p];
		int mid=l+r>>1;
		push_down(p);
		if(x<=mid)	return query(p<<1,l,mid,x);
		else	return query(p<<1|1,mid+1,r,x);
	}
}seg1, seg2;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>a[i];
	for(int i=1;i<=n;++i)	cin>>b[i];
	while(m--){
		int op,x,y,k;
		cin>>op;
		if(op==1){
			cin>>x>>y>>k;
			seg1.update(1,1,n,y,y+k-1,x-y);
			seg2.update(1,1,n,y,y+k-1,1);
		}else{
			cin>>x;
			if(seg2.query(1,1,n,x))	cout<<a[x+seg1.query(1,1,n,x)]<<endl;
			else	cout<<b[x]<<endl;
		}
	}
	return 0;
}