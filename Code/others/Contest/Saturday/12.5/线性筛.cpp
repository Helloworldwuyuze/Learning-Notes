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

const int N = 1e5 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int p[N],cnt;

void prime(){
	for(int i=2;i<=N-10;++i){
		if(!p[i])	p[++cnt]=i;
		for(int j=1;p[j]*i<=N-10&&j<=cnt;++j){
			p[i*p[j]]=1;
			if(i%p[j]==0)	break;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	prime();
	for(int i=1;i<=10;++i)	cout<<p[i]<<endl;
	return 0;
}
