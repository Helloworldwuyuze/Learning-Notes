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

using namespace std;

const int INF = 0x3f3f3f3f;
#define int long long
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef set<int>::iterator ITER;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n,m,a[N],q[N],ans[N],re[N],rk[N];
int maxx,minn[N],mn;
bool f[N],e[N];
set<int> s;

struct node{
	int left,right,sum;
}t[N<<2];
void build(int p,int l,int r){
	t[p].left=l ,t[p].right=r; t[p].sum=0;
	if(l==r)	return ;
	int mid=l+r>>1;
	build(p<<1,l,mid), build(p<<1|1,mid+1,r);
}
void push_up(int p){ t[p].sum=t[p<<1].sum+t[p<<1|1].sum;}
void update(int p,int x,int k){
	if(t[p].left==t[p].right){ t[p].sum+=k; return ;}
	int mid=t[p].left+t[p].right>>1;
	if(x<=mid)	update(p<<1,x,k);
	else	update(p<<1|1,x,k);
	push_up(p);
}
int query(int p,int l,int r){
	if(l<=t[p].left&&t[p].right<=r)	return t[p].sum;
	int mid=t[p].left+t[p].right>>1, res=0;
	if(l<=mid)	res+=query(p<<1,l,r);
	if(r>mid)	res+=query(p<<1|1,l,r);
	return res;
}

signed main(){
	freopen("dizalo.in","r",stdin);
	freopen("dizalo.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    build(1,1,n);
    for(int i=1;i<=n;++i){
    	cin>>a[i]; rk[a[i]]=i;
    	re[i]=query(1,a[i],n);
    	update(1,a[i],1); s.insert(a[i]);
	}
	
	s.insert(0);
	for(ITER it=s.begin();it!=s.end();++it){
		if(it==s.begin())	continue;
		if(rk[*it]<maxx)	continue;
		maxx=max(maxx,rk[*it]);
		ans[0]+=re[rk[*it]];
	}
	
	mn=INF;
	for(int i=n;i;--i)	f[i]=(a[i]<mn), mn=min(mn,a[i]);
	for(int i=1;i<=m;++i){
		cin>>q[i]; e[q[i]]=true;
		if(f[q[i]]){
			int sum=0;
			for(int j=1;j<q[i];++j)
				if(!e[j])	++sum;
			ans[i]=ans[i-1]-sum;
		}
		else{
			int sum=0;
			for(int j=q[i]+1;j<=n;++j)
				if(!e[j]&&a[j]<a[q[i]]&&f[j]){
					++sum;
				}
			ans[i]=ans[i-1]-sum;
		}
	}
	for(int i=0;i<=m;++i)	cout<<ans[i]+n-i<<" ";
    return 0;
}
/*
5 2 
3 4 1 2 5 
3 2
*/
