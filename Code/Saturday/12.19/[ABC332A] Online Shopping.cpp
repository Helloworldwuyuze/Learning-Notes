#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int n,s,k,a[N],b[N],sum;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>s>>k;
	for(int i=1;i<=n;++i)	cin>>a[i]>>b[i], sum+=a[i]*b[i];
	cout<<(sum<s?sum+k:sum)<<endl; 
	return 0;
}

