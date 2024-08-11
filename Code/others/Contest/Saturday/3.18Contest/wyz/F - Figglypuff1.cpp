#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;
#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 3000 + 10;
typedef pair<int,int> PII;
int n,m;
char a[N][N];
int f[N][N],cnt[N*2][26];

signed main(){
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}
	f[1][1]=1;
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(i==1&&j==1)	continue;
			if(a[i-1][j]==a[i][j-1])	f[i][j]=f[i-1][j]+f[i][j-1];
			else	f[i][j]=max(f[i-1][j],f[i][j-1]);
		}
	}
	
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=m;++j){
//			cout<<f[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cnt[i+j-1][a[i][j]-'a']=max(cnt[i+j-1][a[i][j]-'a'],f[i][j]);
			if(cnt[i+j-1][a[i][j]-'a']>INF){
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
//	for(int i=0;i<26;++i){
//		cout<<char(i+'a')<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=n+m-1;++i){
//		for(int j=0;j<26;++j){
//			cout<<cnt[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<cnt[n+m-1][a[n][m]-'a']<<endl;
	cout<<(cnt[n+m-1][a[n][m]-'a']>=3?"YES":"NO");
	return 0;
}
