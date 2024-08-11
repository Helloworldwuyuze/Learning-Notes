#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath> 
#include<algorithm>
#include<string>

using namespace std;

const int N = 1e5 + 10;
int n,m,x;
int head[N],ver[N<<1],Next[N<<1],tot=-1;
int son[N],size[N],de[N],fa[N],top[N],rk[N],dfn[N],idx;
struct node{
	int left,right;
	int off,tag;
}t[N<<2];
#define len(i) (t[p].right-t[p].left+1)

void dfs1(int x,int fat){
	fa[x]=fat;
	de[x]=de[fat]+1;
	size[x]=1;
	for(int i=head[x];~i;i=Next[i]){
		int y=ver[i];
		if(y==fa[x])	continue;
		dfs1(y,x);
		size[x]+=size[y];
		if(son[x]==0||size[y]>size[son[x]])	son[x]=y;
	}
}

void dfs2(int x,int tp){
	dfn[x]=++idx;
	rk[idx]=x;
	top[x]=tp;
	if(son[x])	dfs2(son[x],tp);
	for(int i=head[x];~i;i=Next[i]){
		int y=ver[i];
		if(y==fa[x]||y==son[x])	continue;
		dfs2(y,y);
	}
} 

void push_up(int p){
	t[p].off=t[p<<1].off+t[p<<1|1].off;
}

void build(int p,int left,int right){
	t[p].tag=-1;
	t[p].left=left; t[p].right=right;
	if(left==right){
		t[p].off=1;
		return ;
	}
	int mid=left+right>>1;
	build(p<<1,left,mid);
	build(p<<1|1,mid+1,right);
	push_up(p);
}

void push_down(int p){
	if(t[p].tag==-1)	return ;
	t[p<<1].tag=t[p].tag;
	t[p<<1|1].tag=t[p].tag;
	t[p<<1].off=t[p].tag?0:len(p<<1);
	t[p<<1|1].off=t[p].tag?0:len(p<<1|1);
	t[p].tag=-1;
}

int query(int p,int left,int right){
	if(left<=t[p].left&&t[p].right<=right){
		return t[p].off;
	}
	push_down(p);
	int mid=t[p].left+t[p].right>>1;
	int res=0;
	if(left<=mid)	res+=query(p<<1,left,right);
	if(right>mid)	res+=query(p<<1|1,left,right);
	return res;
}

void update(int p,int left,int right,int state){
	if(left<=t[p].left&&t[p].right<=right){
		t[p].tag=state;
		t[p].off=state?0:len(p);
		return ;
	}
	push_down(p);
	int mid=(t[p].left+t[p].right)>>1;
	if(left<=mid)	update(p<<1,left,right,state);
	if(right>mid)	update(p<<1|1,left,right,state);
	push_up(p);
}

void update_line(int x,int y,int state){
	while(top[x]!=top[y]){
		if(de[top[x]]<de[top[y]])	swap(x,y);
		update(1,dfn[top[x]],dfn[x],state);
		x=fa[top[x]];
	}
	if(de[x]>de[y])	swap(x,y);
	update(1,dfn[x],dfn[y],state);
}

int query_line(int x,int y){
	int ans=0;
	while(top[x]!=top[y]){
		if(de[top[x]]<de[top[y]])	swap(x,y);
		ans+=query(1,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if(de[x]>de[y])	swap(x,y);
	return ans+query(1,dfn[x],dfn[y]);
}

void add(int x,int y){
	ver[++tot]=y;
	Next[tot]=head[x];
	head[x]=tot;
}

int main(){
	
	cin.tie(0);
	cout.tie(0);
	memset(head,-1,sizeof(head));
	cin>>n;
	for(int i=1;i<n;++i){
		cin>>x;
		add(i,x),add(x,i);
	}
	dfs1(0,-1);
	dfs2(0,0);
	build(1,1,n);
	for(int i=1;i<n<<1;++i){
		printf("%d %d %d %d\n",t[i].left,t[i].right,t[i].off,t[i].tag); 
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		string s;
		cin>>s;
		if(s[0]=='i'){
			cin>>x;
			int t=query_line(0,x);
			update_line(0,x,1);
			cout<<abs(t-query_line(0,x))<<"\n";
		}else{
			cin>>x;
			int t=query(1,dfn[x],dfn[x]+size[x]-1);
			update(1,dfn[x],dfn[x]+size[x]-1,0);
			cout<<abs(t-query(1,dfn[x],dfn[x]+size[x]-1))<<"\n";
		}
		for(int i=1;i<n<<1;++i){
			printf("%d %d %d %d\n",t[i].left,t[i].right,t[i].off,t[i].tag); 
		}
	}
	
	return 0;
}
