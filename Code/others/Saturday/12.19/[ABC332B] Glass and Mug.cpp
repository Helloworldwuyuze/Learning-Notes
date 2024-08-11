#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int g,m,k,a,b;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>k>>g>>m;
	for(int i=1;i<=k;++i){
		if(a==g)	a=0;
		else if(b==0)	b=m;
		else{
			if(g-a>b)	a+=b, b=0;
			else	b-=g-a,a=g;
		}
	}
	cout<<a<<" "<<b<<endl;
	return 0;
}

