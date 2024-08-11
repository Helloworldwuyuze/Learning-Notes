#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N = 2e6 + 10;
const int M = 2e6;
const int MOD = 1032992941;

int n,mu[N],p[N],cnt;

int s(int n){ return n*(n+1)/2;}
void init(){
	mu[1]=1;
	for(int i=2;i<=M;++i){
		if(!p[i])	p[++cnt]=i, mu[i]=-1;
		for(int j=1;j<=cnt&&p[j]*i<=M;++j){
			p[i*p[j]]=1;
			if(i%p[j]==0)	break;
			mu[i*p[j]]=-mu[i];
		}
	}
	for(int i=1;i<=M;++i)	mu[i]+=mu[i-1];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	init();
	int ans=0;
	for(int i=1;i<=n;++i){
		int j=n/(n/i), res=0, nn=n/i;
		for(int l=1;l<=nn;++l){
			int r=nn/(nn/l);
			res+=(mu[r]-mu[l-1])*(nn/l)*(nn/l);
			l=r;
		}
		ans+=(s(j)-s(i-1))*res;
		i=j;
	}
	cout<<(ans-s(n))/2<<endl;
	return 0;
}
/*
6
1 2
1 3
1 5
1 4
5 6
*/
