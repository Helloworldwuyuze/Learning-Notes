#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
const int INF=0x3f3f3f3f3f3f3f3f,mod=19260817;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp_make_pair
int n,m;
struct node{
	int val,lazy;
};
node t[2][N*4];
void pushup(node *t,int p){t[p].val=(t[p*2].val+t[p*2+1].val)%mod;}
void pushdown(node *t,int p,int l,int r){
	int m=(l+r)>>1;
	t[p*2].val=(t[p*2].val+t[p].lazy*(m-l+1)%mod)%mod;
	t[p*2].lazy=(t[p*2].lazy+t[p].lazy)%mod;
	t[p*2+1].val=(t[p*2+1].val+t[p].lazy*(r-m)%mod)%mod;
	t[p*2+1].lazy=(t[p*2+1].lazy+t[p].lazy)%mod;
	t[p].lazy=0;
}
void update(node *t,int p,int l,int r,int L,int R,int val){
	if(L<=l&&r<=R){
		t[p].val=(t[p].val+(r-l+1)*val%mod)%mod;
		t[p].lazy=(t[p].lazy+val)%mod;
		return;
	}
	int m=(l+r)>>1;
	pushdown(t,p,l,r);
	if(L<=m)update(t,p*2,l,m,L,R,val);
	if(R>m)update(t,p*2+1,m+1,r,L,R,val);
	pushup(t,p);
}
int query(node *t,int p,int l,int r,int L,int R){
	if(L<=l&&r<=R)return t[p].val;
	int m=(l+r)>>1,ans=0;
	pushdown(t,p,l,r);
	if(L<=m)ans=(ans+query(t,p*2,l,m,L,R))%mod;
	if(R>m)ans=(ans+query(t,p*2+1,m+1,r,L,R))%mod;
	return ans;
}
void add(node *x,node *y,int p,int l,int r,int L,int R){
	if(l==r){
		x[p].val=(x[p].val+y[p].val)%mod;
		return;
	}
	pushdown(x,p,l,r);
	pushdown(y,p,l,r);
	int m=(l+r)>>1;
	if(L<=m)add(x,y,p*2,l,m,L,R);
	if(R>m)add(x,y,p*2+1,m+1,r,L,R);
	pushup(x,p);
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int lans=0;
	for(int i=1;i<=n;i++){
		int v;cin>>v;
		update(t[0],1,1,n,i,i,v);
	}
	for(int i=1;i<=m;i++){cerr<<i<<endl;
		int op,l,r,v;
		cin>>op>>l>>r;
		if(op==2||op==3)cin>>v;
		l^=lans,r^=lans,v^=lans;
		if(op==1)cout<<(lans=query(t[0],1,1,n,l,r))<<'\n';
		if(op==2)update(t[0],1,1,n,l,r,v);
		if(op==3)update(t[1],1,1,n,l,r,v);
		if(op==4)add(t[0],t[1],1,1,n,l,r);
	}
	return 0;
}

