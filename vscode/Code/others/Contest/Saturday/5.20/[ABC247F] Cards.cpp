#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 2e5 + 10;
const int MOD = 998244353;

int n,x;
int f[N],fa[N],p[N],siz[N];

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main(){
	cin.tie(0), cout.tie(0);
	cin>>n;
	f[1]=1, f[2]=3;
	for(int i=3;i<=n;++i){
		f[i]=(f[i-1]+f[i-2])%MOD;
	}
	for(int i=1;i<=n;++i){
		cin>>x;
		fa[i]=i, p[x]=i;
		siz[i]=1;
	}
	for(int i=1;i<=n;++i){
		cin>>x;
		int fa1=find(p[x]),fa2=find(i);
//		cout<<fa1<<" "<<fa2<<endl;
		if(fa1==fa2)	continue;
		fa[fa2]=fa1, siz[fa1]+=siz[fa2], siz[fa2]=1;
//		for(int i=1;i<=n;++i){
//			cout<<siz[i]<<" ";
//		}
//		cout<<endl;
	}
	long long ans=1;
	for(int i=1;i<=n;++i){
//		cout<<siz[i]<<endl;
		ans=(ans*f[siz[i]])%MOD;
	}
	cout<<ans;
	return 0;
}

