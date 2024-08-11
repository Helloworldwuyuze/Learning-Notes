#include<bits/stdc++.h>

using namespace std;

const int N = 2e3 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int n,m,ans=-1;
char c[N][N];
bool a[N][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n+1;++j)	cin>>c[i][j], a[i][j]=c[i][j]=='1';
	for(int i=1;i<=n;++i){
		int cur=i;
		while(cur<=m&&!a[cur][i])	++cur;
		if(cur>m){
			cout<<"Cannot Determine"<<endl;
			return 0;
		}
		ans=max(ans,cur);
		if(cur!=i)
			for(int j=1;j<=n+1;++j)	swap(a[i][j],a[cur][j]);
		for(int j=1;j<=m;++j)
			if(j!=i&&a[j][i])
				for(int k=1	;k<=n+1;++k)	a[j][k]^=a[i][k];
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;++i)
		if(a[i][n+1])	cout<<"?y7M#"<<endl;
		else	cout<<"Earth"<<endl;
	return 0;
}

