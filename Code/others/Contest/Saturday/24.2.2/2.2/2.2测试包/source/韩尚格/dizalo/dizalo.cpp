#include<iostream>
#define lowbit(x) x&(-x)
using namespace std;
const int N=2e5+5;
int n,q,c,a[N],t[N],v[N],p[N],g[N],ti[N];
int query(int x){
	int ans=0;
	while(x<=n){
		ans+=t[x];
		x+=lowbit(x);
	}
	return ans;
}
void update(int x,int val){
	while(x){
		t[x]+=val;
		x-=lowbit(x);
	}
}
int solve(){
	for(int i=0;i<=n;i++) t[i]=0;
	int mx=0;
	for(int i=1;i<=n;i++) p[a[i]]=i;
	for(int i=1;i<=n;i++) ti[i]=p[i],p[i]=0;
	for(int i=1;i<=n;i++){
		if(ti[i]>mx) v[i]=1;
		else v[i]=0;
		mx=max(mx,ti[i]);
	}
	int ans=0,tp=0;
	for(int i=n;i;i--){
		if(!ti[i]) continue;
		tp++;
		if(v[i]) ans+=(tp-1-query(ti[i]));
		update(ti[i],1);
	}
	return ans+tp;
}
int main(){
	freopen("dizalo.in","r",stdin);
	freopen("dizalo.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<solve()<<" ";
	while(q--){
		cin>>c;
		a[c]=0;
		cout<<solve()<<" ";
	}
	return 0;
}
