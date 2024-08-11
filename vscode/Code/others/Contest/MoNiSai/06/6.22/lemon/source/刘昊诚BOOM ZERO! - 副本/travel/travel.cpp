#include<iostream>
#include<cstdio>
#define N 300005
#define mod 19260817
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
using namespace std;
int n,m,a[N],b[N],lans;
void bf(){
	while(m--){
		int op,l,r,v;
		cin>>op>>l>>r;
		l^=lans,r^=lans;
		if(op==1){
			int res=0; for(int i=l;i<=r;i++)res=(res+a[i])%mod;
			cout<<res<<"\n"; lans=res;
		}else if(op==2){
			cin>>v;v^=lans;for(int i=l;i<=r;i++)a[i]=(a[i]+v)%mod;
		}else if(op==3){
			cin>>v;v^=lans;for(int i=l;i<=r;i++)b[i]=(b[i]+v)%mod;
		}else {for(int i=l;i<=r;i++)a[i]=(a[i]+b[i])%mod;}
	}
}
int tr[N<<2],tag[N<<2];
void build(int p,int pl,int pr)
{
	if(pl==pr){tr[p]=a[pl];return;}
	int mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	tr[p]=tr[ls(p)]+tr[rs(p)];
}
void upd(int p,int pl,int pr,int v){tr[p]+=(pr-pl+1)*v,tag[p]+=v;}
void pushdown(int p,int pl,int pr)
{
	if(tag[p])return;
	int mid=(pl+pr)>>1;
	upd(ls(p),pl,mid,tag[p]);
	upd(rs(p),mid+1,pr,tag[p]);
	tag[p]=0;
}
void update(int p,int pl,int pr,int L,int R,int val)
{
	if(L<=pl&&pr<=R){upd(p,pl,pr,val);return;}
	int mid=(pl+pr)>>1; pushdown(p,pl,pr);
	if(L<=mid)update(ls(p),pl,mid,L,R,val);
	if(R>mid)update(rs(p),mid+1,pr,L,R,val);
	tr[p]=tr[ls(p)]+tr[rs(p)];
}
int query(int p,int pl,int pr,int L,int R)
{
	if(L<=pl&&pr<=R)return tr[p];
	int mid=(pl+pr)>>1,res=0; pushdown(p,pl,pr);
	if(L<=mid)res+=query(ls(p),pl,mid,L,R);
	if(R>mid)res+=query(rs(p),mid+1,pr,L,R);
	return res;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=3000&&m<=3000){bf();return 0;}
	build(1,1,n);
	while(m--)
	{
		int l,r,v,op;
		cin>>op>>l>>r;
		l^=lans,r^=lans;
		if(op==1)cout<<(lans=query(1,1,n,l,r))<<"\n";
		else if(op==2)
		{
			cin>>v;v^=lans;
			update(1,1,n,l,r,v);
		}
		else if(op==3)
		{
			cin>>v;v^=lans;
			for(int i=l;i<=r;i++)b[i]+=v;
		}
		else
		{
			for(int i=l;i<=r;i++)update(1,1,n,i,i,b[i]);
		}
	}
	return 0;
}
