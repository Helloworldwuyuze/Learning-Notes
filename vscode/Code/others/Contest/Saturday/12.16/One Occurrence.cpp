#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;

int n,m;
int a[N],b[N],lst[N],ans[N];
struct ques{
	int l,r,id;
	bool operator <(const ques& o){ return r<o.r;} 
}q[N];
struct node{
	int left,right,loca,minn;
}t[N<<2];

void push_up(int p){
	if(t[p<<1].minn<=t[p<<1|1].minn)	t[p].minn=t[p<<1].minn, t[p].loca=t[p<<1].loca;
	else	t[p].minn=t[p<<1|1].minn, t[p].loca=t[p<<1|1].loca;
}

void build(int p,int left,int right){
	t[p].left=left, t[p].right=right;
	if(left==right){
		t[p].loca=left, t[p].minn=INF;
		return ;
	}
	int mid=left+right>>1;
	build(p<<1,left,mid), build(p<<1|1,mid+1,right);
	push_up(p);
}

void update(int p,int x,int k){
	if(t[p].left==t[p].right){
		t[p].minn=k;
		return ;
	}
	int mid=t[p].left+t[p].right>>1;
	if(x<=mid)	update(p<<1,x,k);
	else	update(p<<1|1,x,k);
	push_up(p);
}

PII query(int p,int left,int right){
//	cout<<"QUERY::\t"<<p<<" "<<left<<" "<<right<<" "<<t[p].left<<" "<<t[p].right<<endl;
	if(left<=t[p].left&&t[p].right<=right)	return make_pair(t[p].minn,t[p].loca);
	int mid=t[p].left+t[p].right>>1;
	PII res=make_pair(INF,0);
	if(left<=mid)	res=min(res,query(p<<1,left,right));
	if(right>mid)	res=min(res,query(p<<1|1,left,right));
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		lst[i]=b[a[i]]; b[a[i]]=i;
	}
	cin>>m;
	for(int i=1;i<=m;++i)	cin>>q[i].l>>q[i].r, q[i].id=i;
	build(1,1,n);
	sort(q+1,q+1+m);
//	for(int i=1;i<=m;++i)	cout<<q[i].l<<" "<<q[i].r<<" "<<q[i].id<<endl;
	int j=1;
	for(int i=1;i<=n;++i){
//		cout<<"###"<<i<<"###"<<endl;
		update(1,i,lst[i]);
		if(lst[i]!=0)	update(1,lst[i],INF);
		while(q[j].r==i&&j<=m){
			PII res=query(1,q[j].l,q[j].r);
			if(res.first<q[j].l)	ans[q[j].id]=a[res.second];
			else	ans[q[j].id]=0;
			++j;
		}
	}
	for(int i=1;i<=m;++i)	cout<<ans[i]<<endl;
	return 0;
}
/*
6 
1 1 2 3 2 4 
2 
2 6 
1 2
*/
