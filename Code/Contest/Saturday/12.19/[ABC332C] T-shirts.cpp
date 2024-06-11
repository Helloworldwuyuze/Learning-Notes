#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

char s[N];
int n,m,s1[N],s2[N],ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1;i<=n;++i){
		if(s[i]=='0')	continue;
		s1[i]=s1[i-1]+(s[i]=='1'), s2[i]=s2[i-1]+(s[i]=='2');
	}
	for(int i=1;i<=n;++i){
		ans=max(ans,max(0,s1[i]-m)+s2[i]);
	}
	cout<<ans<<endl;
	return 0;
}

