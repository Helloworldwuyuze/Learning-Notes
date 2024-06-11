#include<bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int n,p[N],tot;

void init(){
	for(int i=2;i<=2*n;++i){
		if(!p[i])	p[++tot]=i;
		for(int j=1;j<=tot&&p[j]*i<=2*n;++j){
			p[p[j]*i]=1;
			if(i%p[j]==0)	break;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	init();
	for(int i=1;p[i]<=n;++i){
		int sum=0,j=n;
		while(j)	sum+=j/p[i], j/=p[i];
		cout<<p[i]<<" "<<sum<<endl;
	}
	return 0;
}
