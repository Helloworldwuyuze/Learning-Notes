#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define endl '\n'
int m,n;
int a[N],b[N],cnt,idx,ans[N];
typedef pair<int,int> PII;
#define mk(x,y) make_pair(x,y)
PII q[N];
struct node{
	int left,right,sum;
}t[N<<2];
void build(int p,int left,int right){
	t[p].left=left, t[p].right=right, t[p].sum=0;
	if(left==right)	return ;
	int mid=left+right>>1;
	build(p<<1,left,mid), build(p<<1|1,mid+1,right);
}
void push_up(int p){
	t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
}
void update(int p,int x){
	if(t[p].left==t[p].right){ t[p].sum++; return ;}
	int mid=t[p].left+t[p].right>>1;
	if(x<=mid)	update(p<<1,x);
	else	update(p<<1|1,x);
	push_up(p);
}
int query(int p,int k){
	if(t[p].left==t[p].right)	return b[t[p].left];
	if(t[p<<1].sum>=k)	return query(p<<1,k);
	else	return query(p<<1|1,k-t[p<<1].sum);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=m;++i)	cin>>a[i], b[i]=a[i];
	for(int i=1;i<=n;++i)	cin>>q[i].first, q[i].second=i;
	sort(b+1,b+1+m), sort(q+1,q+1+n);
	cnt=unique(b+1,b+1+m)-b-1;
	for(int i=1;i<=m;++i)	a[i]=lower_bound(b+1,b+1+cnt,a[i])-b;
	build(1,1,cnt);
	for(int i=1,j=1;i<=m;++i){
		update(1,a[i]);
		while(q[j].first==i)	ans[q[j].second]=query(1,++idx), ++j;
	}
	for(int i=1;i<=n;++i)	cout<<ans[i]<<endl;
	return 0;
}
