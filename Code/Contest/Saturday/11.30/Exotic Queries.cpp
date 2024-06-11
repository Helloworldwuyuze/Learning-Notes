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

const int N = 1e6 + 10;
const int M = 8e5 + 10;
#define endl '\n'
#define int long long
const int INF = 0x3f3f3f3f;

int n,m,a[N],s[N]; 
vector<int> v[N];

namespace seg{
	struct TREE{
		int left,right,maxx;
	}t[N<<2];
	
	void build(int p,int left,int right){
		t[p].left=left, t[p].right=right; t[p].maxx=0;
		if(left==right)	return ;
		int mid=left+right>>1;
		build(p<<1,left,mid), build(p<<1|1,mid+1,right);
	}
	
	void push_up(int p){
		t[p].maxx=max(t[p<<1].maxx,t[p<<1|1].maxx);
	}
	
	void update(int p,int x,int k){
		if(t[p].left==t[p].right){ t[p].maxx=k; return ;}
		int mid=t[p].left+t[p].right>>1;
		if(x<=mid)	update(p<<1,x,k);
		else	update(p<<1|1,x,k);
		push_up(p);
		return ;
	}
	
	int query(int p,int left,int right){
		if(left<=t[p].left&&t[p].right<=right)	return t[p].maxx;
		int mid=t[p].left+t[p].right>>1,maxx=0;
		if(left<=mid)	maxx=max(maxx,query(p<<1,left,right));
		if(right>mid)	maxx=max(maxx,query(p<<1|1,left,right));
		return maxx;
	}
} 

namespace bit{
	int b[N];
	#define lowbit(x) (x&-x)
	void update(int x,bool f){
		if(x==0)	return ;
		for(int i=x;i<=n;i+=lowbit(i))	b[i]+=f;
	}
	int query(int x){
		int ans=0;
		for(int i=x;i;i-=lowbit(i))	ans+=b[i];
		return ans;
	}
}

struct node{
	int l,r,id;
}q[N];

bool cmp(node x,node y){
	return x.r<y.r;
}

int ans[N],ans1[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>a[i], v[a[i]].push_back(i), s[a[i]]=1;
	for(int i=1;i<=n;++i)	s[i]+=s[i-1];
	for(int i=1;i<=m;++i)	cin>>q[i].l>>q[i].r, q[i].id=i;
	sort(q+1,q+1+m,cmp);
	int k=1;
	seg::build(1,1,n);
	for(int i=1;i<=n;++i){
//		cout<<endl<<"###"<<i<<"###"<<endl;
		if(v[i].size()){
			seg::update(1,v[i][0],i);
//			cout<<"QAQ"<<endl;
			for(int j=1;j<v[i].size();++j){
//				cout<<v[i][j-1]<<" "<<v[i][j]<<endl;
				bit::update(seg::query(1,v[i][j-1]+1,v[i][j]),1);
				seg::update(1,v[i][j],i);
			}
		}
		while(q[k].r==i&&k<=m)	ans[q[k].id]=s[q[k].r]-s[q[k].l-1],ans1[q[k].id]=bit::query(q[k].r)-bit::query(q[k].l-1),++k;
//		for(int i=1;i<=n;++i)
//			cout<<bit::query(i)-bit::query(i-1)<<" ";
//		cout<<endl;
	}
	for(int i=1;i<=m;++i)	cout<<ans[i]+ans1[i]<<endl;
	return 0;
}
/*
10 8 
1 6 2 3 2 6 3 10 1 2 
1 10 
2 2 
3 3 
2 3 
1 3 
3 6 
4 6 
5 5
*/
