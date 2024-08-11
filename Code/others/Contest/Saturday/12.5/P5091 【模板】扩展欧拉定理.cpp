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
#define int long long
const int INF = 0x3f3f3f3f;

int a,m,b,n;
int phi;

int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}

int ksm(int x,int m){
	int ans=1;
	while(m){
		if(m&1)	ans=ans*x%n;
		x=x*x%n; m>>=1;
	}
	return ans;
}

signed main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
	cin>>a>>m;
	phi=n=m;
	for(int i=2;i*i<=m;++i){
		if(m%i==0)	phi=phi/i*(i-1);
		while(m%i==0)	m/=i;
	}
	if(m!=1)	phi=phi/m*(m-1);
//	cout<<phi<<endl;
	bool flag=false;
	char c=getchar();
	while(c<'0'||c>'9')	c=getchar();
	while(c<='9'&&c>='0'){
		b=b*10+(c-'0');
		if(b>=phi)	b%=phi, flag=true;
		c=getchar();
	}
//	cout<<a<<" "<<b<<endl;
	cout<<ksm(a,b+flag*phi)<<endl;
	return 0;
}

