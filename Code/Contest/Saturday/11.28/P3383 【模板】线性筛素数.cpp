#include<bits/stdc++.h>

using namespace std;

const int N = 1e8 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int n,q,p[N],tot;

void init(){
	p[1]=1;
	for(int i=2;i<=n;++i){
		if(!p[i])	p[++tot]=i;
		for(int j=1;j<=tot&&p[j]*i<=n;++j){
			p[p[j]*i]=1;
			if(i%p[j]==0)	break;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	init();
	while(q--){
		int x;
		cin>>x;
		cout<<p[x]<<endl;
	}
	return 0;
}
