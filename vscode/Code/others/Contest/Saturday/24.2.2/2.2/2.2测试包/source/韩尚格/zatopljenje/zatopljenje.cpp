#include<iostream>
#include<algorithm>
#define lowbit(x) x&(-x)
#define int long long
using namespace std;
const int N=2e5+5;
struct node{
	int id,l,r;
};
node f[N],g[N];
int n,m,q,u,v,H;
int cmp1(node x,node y){
	return x.l<y.l;	
}
int cmp2(node x,node y){
	return x.r<y.r;
}
int h[N];
int t[N];
int query(int x){
	int ans=0;
	while(x<=m){
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
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>h[i];
		if(h[i]>h[i-1]){
			m++;
			f[m].id=g[m].id=i;
			f[m].l=g[m].l=h[i-1];
			f[m].r=g[m].r=h[i];
		}
	}
	sort(f+1,f+m+1,cmp1);
	sort(g+1,g+m+1,cmp2);
	int l,r,c;
	u=v=1;
	while(q--){
		cin>>l>>r>>c;
		H+=c;
		while(u<m&&f[u].l<=H){
			update(f[u].id-1,-1);
			cout<<f[u].id<<" qwq\n";
			u++;
		}
		while(v<m&&g[v].r<=H){
			update(g[v].id-1,1);
			cout<<g[v].id<<" wqw\n"; 
			v++;
		}
		cout<<l<<" "<<r<<" "<<c<<"\n";
		int ans=query(r)-query(l);
		if(h[l]>H) ans++;
		cout<<ans<<"\n";
	}
	return 0;
} 
