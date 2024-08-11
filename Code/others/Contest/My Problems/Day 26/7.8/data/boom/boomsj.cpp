#include<bits/stdc++.h>

using namespace std;

const int K = 1e3;
const long long P = 1e15;

int T = 10;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	srand((unsigned)time(NULL));
	freopen("boom31.in","w",stdout);
	cout<<T<<endl;
	while(T--){
		long long k = (rand()-10+K)%K + 10;
		long long p = (((1ll*rand()<<16) + rand() << 16) + rand()) % P;
		cout<<k<<" "<<p<<endl;
	}
	return 0;
}
