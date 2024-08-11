#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<ctime>
#include<vector>

using namespace std;
const int N = 1e5 + 10;
#define int long long
#define len(p) (t[p].right-t[p].left+1)

int n,m,root,MOD;
int x,y,z,opt; 
int a[N],size[N],son[N],fa[N],dfn[N],rk[N],top[N],de[N],idx;
int Next[N<<1],ver[N<<1],head[N],tot=-1;
struct node{
	int left,right;
	int sum;
	int tag;
}t[N<<2];

void add(int x,int y){
	ver[++tot]=y;
	Next[tot]=head[x];
	head[x]=tot;
}

void dfs1(int x,int fat){
	fa[x]=fat;
	size[x]=1;
	de[x]=de[fat]+1;
	for(int i=head[x];~i;i=Next[i]){
		int y=ver[i];
		if(y==fat)	continue;
		dfs1(y,x);
		size[x]+=size[y];
		if(size[y]>size[son[x]])	son[x]=y;
	}
}

void dfs2(int x,int tp){
	top[x]=tp;
	dfn[x]=++idx, rk[idx]=x;
	if(son[x])	dfs2(son[x],tp);
	for(int i=head[x];~i;i=Next[i]){
		int y=ver[i];
		if(y==fa[x]||y==son[x])	continue;
		dfs2(y,y);
	}
}

void push_up(int p){
	t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
}

void build(int p,int left,int right){
	t[p].left=left, t[p].right=right, t[p].tag=0;
	if(left==right){
		t[p].sum=a[rk[left]];
		return ;
	}
	int mid=left+right>>1;
	build(p<<1,left,mid);
	build(p<<1|1,mid+1,right);
	push_up(p);
}

void push_down(int p){
	if(t[p].tag==0)	return ;
	t[p<<1].tag=(t[p<<1].tag+t[p].tag);
	t[p<<1|1].tag=(t[p<<1|1].tag+t[p].tag);
	t[p<<1].sum=(t[p].tag*len(p<<1)+t[p<<1].sum);
	t[p<<1|1].sum=(t[p].tag*len(p<<1|1)+t[p<<1|1].sum);
	t[p].tag=0;
}

void update(int p,int left,int right,int k){
//	cout<<p<<endl;
	if(left<=t[p].left&&t[p].right<=right){
		t[p].sum=(t[p].sum+k*len(p));
		t[p].tag=(t[p].tag+k);
		return ;
	}
	push_down(p);
	int mid=t[p].left+t[p].right>>1;
	if(left<=mid)	update(p<<1,left,right,k);
	if(right>mid)	update(p<<1|1,left,right,k);
	push_up(p);
}

int query(int p,int left,int right){
	if(left<=t[p].left&&t[p].right<=right){
		return t[p].sum%MOD;
	}
	push_down(p);
	int mid=t[p].left+t[p].right>>1;
	int res=0;
	if(left<=mid)	res=(res+query(p<<1,left,right))%MOD;
	if(right>mid)	res=(res+query(p<<1|1,left,right))%MOD;
	return res;
}

void update_line(int x,int y,int z){
	while(top[x]!=top[y]){
		if(de[top[x]]<de[top[y]])	swap(x,y);
		update(1,dfn[top[x]],dfn[x],z);
		x=fa[top[x]];
	}
	if(de[x]>de[y])	swap(x,y);
	update(1,dfn[x],dfn[y],z);
}

int query_line(int x,int y){
	int ans=0;
	while(top[x]!=top[y]){
		if(de[top[x]]<de[top[y]])	swap(x,y);
		ans=(ans+query(1,dfn[top[x]],dfn[x]))%MOD;
		x=fa[top[x]];
	}
	if(de[x]>de[y])	swap(x,y);
	ans=(ans+query(1,dfn[x],dfn[y]))%MOD;
	return ans;
}

signed main(){
	memset(head,-1,sizeof(head));
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>root>>MOD;
	for(int i=1;i<=n;++i)	cin>>a[i];
	for(int i=1;i<n;++i){
		cin>>x>>y;
		add(x,y),add(y,x);
	}
	dfs1(root,0);
	dfs2(root,root);
	build(1,1,n);
//	for(int i=1;i<=n;++i){
//		printf("%lld %lld %lld %lld %lld %lld %lld\n",son[i],size[i],fa[i],de[i],top[i],dfn[i],rk[i]);
//	}
//	for(int i=1;i<=n<<1;++i){
//		printf("%lld %lld %lld %lld\n",t[i].left,t[i].right,t[i].sum,t[i].tag);
//	}
	
	while(m--){
		cin>>opt;
		if(opt==1){
			cin>>x>>y>>z;
			update_line(x,y,z%MOD);
		}else if(opt==2){
			cin>>x>>y;
			cout<<query_line(x,y)<<"\n";
		}else if(opt==3){
			cin>>x>>z;
			update(1,dfn[x],dfn[x]+size[x]-1,z%MOD);
		}else{
			cin>>x;
			cout<<query(1,dfn[x],dfn[x]+size[x]-1)<<"\n";
		}
//		for(int i=1;i<=n<<1;++i){
//			printf("%lld %lld %lld %lld\n",t[i].left,t[i].right,t[i].sum,t[i].tag);
//		}
	}
	return 0;
}
