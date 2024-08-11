#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int M = 2e5 + 10;
#define endl '\n'
#define int long long
const int INF = 0x3f3f3f3f;

int n,m,k,u[N],v[N],maxv;

struct tree{
	int left,right;
	int sum;
}t[N<<2];
struct ques{
	int x,id,f,l,r;
}q[N<<1];
int ans[N],pre[N],nxt[N];

bool cmp(ques x,ques y){
	return x.x==y.x?(x.id<y.id):(x.x<y.x);
}

void push_up(int p){
	t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
}
void build(int p,int left,int right){
	t[p].left=left, t[p].right=right, t[p].sum=0;
	if(left==right)	return ;
	int mid=left+right>>1;
	build(p<<1,left,mid), build(p<<1|1,mid+1,right);
}
void update(int p,int x,int k){
	if(t[p].left==t[p].right){
		t[p].sum+=k+v[t[p].left];
		return ;
	}
	int mid=t[p].left+t[p].right>>1;
	if(x<=mid)	update(p<<1,x,k);
	else	update(p<<1|1,x,k);
	push_up(p);
}
int query(int p,int left,int right){
	if(left<=t[p].left&&t[p].right<=right)	return t[p].sum;
	int mid=t[p].left+t[p].right>>1, res=0;
	if(left<=mid)	res+=query(p<<1,left,right);
	if(right>mid)	res+=query(p<<1|1,left,right);
	return res;
}

signed main(){
//	freopen("miracle.in","r",stdin);
//	freopen("miracle.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)
		cin>>u[i];
	for(int i=1;i<=m;++i)
		cin>>v[i], maxv=max(maxv,v[i]);
	for(int i=1,x,y;i<=k;++i)
		cin>>x>>y, q[i]={x-1,i,-1,x,y}, q[i+k]={y,i,1,x,y};
	sort(u+1,u+1+n), sort(v+1,v+1+m), sort(q+1,q+1+2*k,cmp);
	
	int cnt=0,ccnt=0;
	for(int i=0;i<=N-10;++i){
		while(v[cnt+1]<=i&&cnt<m)	++cnt;
		while(v[ccnt]<i)	++ccnt;
		pre[i]=cnt; nxt[i]=ccnt;
	}
	
	build(1,1,m);
	int tt=1;
	while(q[tt].x<u[1])	++tt;
//	cout<<tt<<endl;
	for(int i=1;i<=n;++i){
		int ii=i,jj=1;
		while(u[i+1]==u[i])	++i;
		int len=ii-i+1;
		
		for(int j=u[i];j<=maxv;j+=u[i]){
			while(j>v[jj])	++jj;
			if(j==v[jj])	update(1,jj,u[i]*len);
		}
		
//		cout<<endl<<"###"<<i<<"###"<<endl;
		while(q[tt].x>=u[i]&&q[tt].x<u[i+1]){
//			cout<<tt<<" "<<q[tt].l<<" "<<u[i]<<" "<<pre[q[tt].r]<<endl;
			ans[q[tt].id]+=query(1,nxt[q[tt].l],pre[q[tt].r])*q[tt].f, ++tt;
		}
//		for(int i=1;i<=m<<1;++i){
//			cout<<i<<" "<<t[i].left<<" "<<t[i].right<<" "<<t[i].sum<<endl;
//		}
//		cout<<"---"<<endl;
//		for(int i=1;i<=k;++i)	cout<<ans[i]<<endl;
	}
	for(int i=tt;i<=k<<1;++i){
//		cout<<i<<" "<<pre[q[i].x]<<" "<<pre[q[i].r]<<" "<<q[i].x<<" "<<q[i].r<<endl;
		ans[q[i].id]+=query(1,nxt[q[i].l],pre[q[i].r])*q[i].f;
//		if(q[i].id==1)	cout<<q[i].x<<" "<<q[i].l<<" "<<q[i].r<<" "<<nxt[q[i].l]<<" "<<pre[q[i].r]<<endl;
	}
	for(int i=1;i<=k;++i)	cout<<ans[i]<<endl;
	return 0;
}
/*
3 4 3 
2 3 1 
4 6 7 8 
1 4 
2 8 
3 6
*/

