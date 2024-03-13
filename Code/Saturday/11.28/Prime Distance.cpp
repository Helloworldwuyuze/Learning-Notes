#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue> 

using namespace std;

const int N = 1e6 + 10;
const int M = 1e5 + 10;
#define endl '\n'
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll l,r,p[N],tot,a[N];

void init(){
	for(ll i=2;i<=M-10;++i){
		if(!p[i])	p[++tot]=i;
		for(ll j=1;j<=tot&&p[j]*i<=M-10;++j){
			p[p[j]*i]=1;
			if(i%p[j])	break;
		}
	}
}

void solve(){
	for(ll i=1;i<=tot;++i){
		for(ll j=max(2*p[i],(l%p[i]?(l/p[i]*p[i]+p[i]):l));j<=r;j+=p[i])	a[j-l]=1;
	}
}

int main(){
	init();
	while(scanf("%lld%lld",&l,&r)!=EOF){
		if(l==1)	l=2;
		for(int i=0;i<=r-l+1;++i)	a[i]=0;
		solve();
		ll sum=0;
		for(ll i=0;i<=r-l;++i){
			sum+=a[i]==0;
		}
		if(sum<=1){
			printf("There are no adjacent primes.\n");
			continue;
		}
		ll p1,p2,p3,p4,pos=-1,maxx=0,minn=INF;
		for(ll i=0;i<=r-l;++i){
			if(a[i]==0){
				if(pos!=-1){
					if(maxx<i-pos)	maxx=i-pos, p1=pos+l,p2=i+l;
					if(minn>i-pos)	minn=i-pos, p3=pos+l,p4=i+l;
				}
				pos=i;
			}
		}
		printf("%lld,%lld are closest, %lld,%lld are most distant.\n",p3,p4,p1,p2);
	}
	return 0;
}
