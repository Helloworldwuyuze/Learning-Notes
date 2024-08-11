#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

const int N = 2e5 + 10;
int n,x;
int a[N<<1],b[N<<4],cnt;
int ans,l=1,maxx;

int main(){
//	freopen("baoli.file","r",stdin);
//	freopen("baoli.outfile","w",stdout);
	cin.tie(0); cout.tie(0);
	cin>>n>>x;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		int idx=0;
		while(a[i]--){
			b[++cnt]=++idx;
		}
	}
	for(int i=1;i<=cnt;++i)
		b[cnt+i]=b[i];
	cnt<<=1;
	for(int i=1;i<=cnt;++i){
		if(i-l+1>x)	ans-=b[l++];
		if(i-l+1<=x)	ans+=b[i];
		maxx=max(maxx,ans);
	}
	cout<<maxx; 
	return 0;
}
