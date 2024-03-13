#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;
#define int long long
#define endl '\n'
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,a[M],s[M];
int l=1,r;

bool check(int m){
//	cout<<endl<<"###"<<m<<"###"<<endl;
	int x=1,y=1,z=1;
	for(int i=1;i<n;++i){
		x=i;
		while(s[y-1]-s[x-1]<m&&y<=i+n-1)	++y;
		while(s[z-1]-s[y-1]<m&&z<=i+n-1)	++z;
//		cout<<i<<" "<<x<<" "<<y<<" "<<z<<endl;
		if(s[i+n-1]-s[z-1]>=m)	return true;
	}
	return false;
}

signed main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>a[i],r+=a[i],a[i+n]=a[i];
	for(int i=1;i<=n<<1;++i)	s[i]=s[i-1]+a[i];
//	cout<<endl;
	while(l<r){
//		cout<<endl<<"###"<<l<<" "<<r<<"###"<<endl;
		int mid=l+r+1>>1;
		if(check(mid))	l=mid;
		else	r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}
