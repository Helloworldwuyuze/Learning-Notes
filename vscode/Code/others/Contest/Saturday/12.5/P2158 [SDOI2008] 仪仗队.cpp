#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<map>

using namespace std;

const int N = 4e4 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int prime[N], phi[N], cnt;
int n;

void init(){
	phi[1]=1;
	for(int i=2;i<=n;++i){
		if(!prime[i])	prime[++cnt]=i, phi[i]=i-1;
		for(int j=1;j<=cnt&&i*prime[j]<=n;++j){
			prime[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}else	phi[i*prime[j]]=phi[i]*phi[prime[j]];
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	init();
	long long s=0;
	for(int i=2;i<n;++i)	s+=phi[i];
	cout<<3+2*s<<endl;
	return 0;
}

