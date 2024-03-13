#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;
#define endl '\n'
#define int long long
const int INF = 0x3f3f3f3f;

set<int> col[N];
int n,q,x,y,op;
int Next[M],ver[M],head[N],tot=-1;
void add(int x,int y){
	ver[++tot]=y;
	Next[tot]=head[x];
	head[x]=tot;
}
int dfn[N],siz[N],rk[N],idx=0;
void dfs(int x,int fa){
	dfn[x]=++idx, siz[x]=1, rk[idx]=x;
	for(int i=head[x];~i;i=Next[i]){
		int y=ver[i];
		if(y==fa)	continue;
		dfs(y,x); siz[x]+=siz[y];
	}
}

namespace segtree{
	struct node{
		int left,right,sum,tag;
	}t[N<<2];
	#define len(p) (t[p].right-t[p].left+1)
	void build(int p,int left,int right){
		t[p].left=left, t[p].right=right;
		t[p].sum=t[p].tag=0;
		if(left==right)	return ;
		int mid=left+right>>1;
		build(p<<1,left,mid), build(p<<1|1,mid+1,right);
	}
	void push_up(int p){
		t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
	}
	void push_down(int p){
		if(t[p].tag==0)	return;
		t[p<<1].tag+=t[p].tag, t[p<<1|1].tag+=t[p].tag;
		t[p<<1].sum+=t[p].tag*len(p<<1), t[p<<1|1].sum+=t[p].tag*len(p<<1|1);
		t[p].tag=0;
	}
	void update(int p,int left,int right,int k){
		if(left<=t[p].left&&t[p].right<=right){
			t[p].tag+=k, t[p].sum+=k*len(p);
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
		if(left<=mid)	res+=query(p<<1,left,right);
		if(right>mid)	res+=query(p<<1|1,left,right);
		return res;
	}
}
using namespace segtree;

void ERASE(int x,int y){
	set<int>::iterator it=col[y].lower_bound(dfn[x]);
	while(it!=col[y].end()){
		int p=rk[*it];
//		cout<<p<<endl;
		if(!(dfn[x]<=dfn[p]&&dfn[p]<=dfn[x]+siz[x]-1))	break;
		update(1,dfn[p],dfn[p]+siz[p]-1,-1);
		col[y].erase(dfn[p]);
		it=col[y].lower_bound(dfn[x]);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>q;
	memset(head,-1,sizeof(head));
	for(int i=1;i<n;++i)	cin>>x>>y, add(x,y), add(y,x);
	dfs(1,0);
//	cout<<"QAQ"<<endl;
	build(1,1,n);
	while(q--){
//		cout<<"-----------------------------"<<endl;
		cin>>op;
		if(op==1){
			cin>>x>>y;
			set<int>::iterator it=col[y].lower_bound(dfn[x]);
			if(it==col[y].end()){
//				cout<<"END"<<endl;
				if(it!=col[y].begin()){
				}
				--it;
				int p=rk[*it];
				if(dfn[p]<=dfn[x]&&dfn[x]<=dfn[p]+siz[p]-1)	continue;
				col[y].insert(dfn[x]);
				update(1,dfn[x],dfn[x]+siz[x]-1,1);
			}else if(it==col[y].begin()){
//				cout<<"BEGIN"<<" "<<rk[*it]<<endl;
				if(rk[*it]==x)	continue;
				ERASE(x,y);
				col[y].insert(dfn[x]);
				update(1,dfn[x],dfn[x]+siz[x]-1,1);
			}else{
//				cout<<"OTHERWISE"<<endl;
				--it;
				int p=rk[*it];
				if(dfn[p]<=dfn[x]&&dfn[x]<=dfn[p]+siz[p]-1)	continue;
				ERASE(x,y);
				col[y].insert(dfn[x]);
				update(1,dfn[x],dfn[x]+siz[x]-1,1);
			}
		}else{
			cin>>x;
			cout<<query(1,dfn[x],dfn[x]+siz[x]-1)<<endl;
		}
	}
	return 0;
}
/*
5 18 
1 2 
1 3 
3 4 
3 5 
1 4 1 
2 1 
2 2 
2 3 
2 4 
2 5 
1 5 1 
2 1 
2 2 
2 3 
2 4 
2 5 
1 1 1 
2 1 
2 2 
2 3 
2 4 
2 5
*/
