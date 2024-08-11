#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<set>
#include<vector>

using namespace std;

const int N = 4e5 + 10;
const int M = 8e5 + 10;
#define endl '\n'
#define int long long
const int INF = 0x3f3f3f3f;

int n,m,Next[M],ver[M],head[N],tot=-1;
void add(int x,int y){
	ver[++tot]=y;
	Next[tot]=head[x];
	head[x]=tot;
}
int c[N],dfn[N],idx,rk[N],siz[N];

struct node{
	int left,right;
	long long sum,tag;
}t[N<<2];

void push_up(int p){
	t[p].sum=t[p<<1].sum|t[p<<1|1].sum;
}

void build(int p,int left,int right){
	t[p].left=left, t[p].right=right; t[p].tag=0;
	if(left==right){
		t[p].sum=1ll<<c[rk[left]];
		return ;
	}
	int mid=left+right>>1;
	build(p<<1,left,mid), build(p<<1|1,mid+1,right);
	push_up(p);
}

void push_down(int p){
	if(!t[p].tag)	return ;
	t[p<<1].tag=t[p<<1|1].tag=t[p].tag;
	t[p<<1].sum=t[p<<1|1].sum=t[p].tag;
	t[p].tag=0;
}

void dfs(int x,int fat){
	dfn[x]=++idx; rk[idx]=x;
	siz[x]=1;
	for(int i=head[x];~i;i=Next[i]){
		int y=ver[i];
		if(y==fat)	continue;
		dfs(y,x);
		siz[x]+=siz[y];
	}
}

void update(int p,int left,int right,int k){
	if(left<=t[p].left&&t[p].right<=right){
		t[p].tag=t[p].sum=1ll<<k;
		return ;
	}
	push_down(p);
	int mid=t[p].left+t[p].right>>1;
	if(left<=mid)	update(p<<1,left,right,k);
	if(right>mid)	update(p<<1|1,left,right,k);
	push_up(p);
}

int query(int p,int left,int right){
	if(left<=t[p].left&&t[p].right<=right)	return t[p].sum;
	push_down(p);
	int mid=t[p].left+t[p].right>>1, res=0;
	if(left<=mid)	res|=query(p<<1,left,right);
	if(right>mid)	res|=query(p<<1|1,left,right);
	return res;
}

int popcnt(int x){
	int sum=0;
	while(x)	sum+=x%2, x/=2;
	return sum;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(head,-1,sizeof(head));
	cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>c[i];
	for(int i=1,x,y;i<n;++i)	cin>>x>>y, add(x,y), add(y,x);
	dfs(1,0);
	build(1,1,n);
	for(int i=1;i<=m;++i){
		int op,x,y;
		cin>>op;
		if(op==1){
			cin>>x>>y;
			update(1,dfn[x],dfn[x]+siz[x]-1,y);
		}else{
			cin>>x;
			cout<<popcnt(query(1,dfn[x],dfn[x]+siz[x]-1))<<endl;
		}
	}
	return 0;
}
/*
23 30 
1 2 2 6 5 3 2 1 1 1 2 4 5 3 4 4 3 3 3 3 3 4 6 
1 2 
1 3 
1 4 
2 5 
2 6 
3 7 
3 8 
4 9 
4 10 
4 11 
6 12 
6 13 
7 14 
7 15 
7 16 
8 17 
8 18 
10 19 
10 20 
10 21 
11 22 
11 23 
2 1 2 5 2 6 2 7 2 8 2 9 2 10 2 11 2 4 1 12 1 1 13 1 1 14 1 1 15 1 1 16 1 1 17 1 1 18 1 1 19 1 1 20 1 1 21 1 1 22 1 1 23 1 2 1 2 5 2 6 2 7 2 8 
2 9 2 10 2 11 2 4
*/
