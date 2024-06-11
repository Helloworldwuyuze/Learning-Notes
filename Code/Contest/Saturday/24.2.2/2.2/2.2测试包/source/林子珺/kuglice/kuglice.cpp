#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=3e3+10;

bool s1=1,s2=1,s3=1,s4=1;
int n,a[N];

void solve1(){
	if(a[1]!=a[n]){
		cout<<"1:1\n";
		return;
	}
	int c1=0,c2=0;
	while(a[c1+1]==a[1])c1++;
	while(a[n-c2]==a[n])c2++;
	if(c1==n)cout<<"1:0\n";
	else if(abs(c1-c2)%2==0)cout<<"1:1\n";
	else cout<<"2:0\n";
}

int ap=-0x3f3f3f3f,aq=0x3f3f3f3f;

int vis[N];
void dfs(int l,int r,int x,int p,int q){
//	cerr<<l<<' '<<r<<' '<<x<<endl;
	if(l>r){
		if(abs(p-q)<abs(ap-aq)){
			ap=p;
			aq=q;
		}
		return;
	}
	if(x%2==1){
		vis[a[l]]++;
		dfs(l+1,r,x+1,vis[a[l]]==1?p+1:p,q);
		vis[a[l]]--;
		vis[a[r]]++;
		dfs(l,r-1,x+1,vis[a[r]]==1?p+1:p,q);
		vis[a[r]]--;
	}else{
		vis[a[l]]++;
		dfs(l+1,r,x+1,p,vis[a[l]]==1?q+1:q);
		vis[a[l]]--;
		vis[a[r]]++;
		dfs(l,r-1,x+1,p,vis[a[r]]==1?q+1:q);
		vis[a[r]]--;
	}
}

void solve2(){
	dfs(1,n,1,0,0);
	cout<<ap<<':'<<aq<<endl;
}

signed main(){
	freopen("kuglice.in","r",stdin);
	freopen("kuglice.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	if(n>20)s2=0;
	if(n>300)s4=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>2)s1=0;
		if(a[i]>20)s3=0;
	}
	if(s1)solve1();
	else{
		solve2();
	}
	return 0;
}

