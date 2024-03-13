#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int n,sum[N],lsto,lsti,lstj,ans,io,m;
bool f[N];
char c[N];

bool fun(){
	bool flag=true;
	m=lsto;
	for(int j=lsto+1;j<=n;++j)
		if(c[j]=='O'&&f[j]==false){ lsto=j; flag=false; break;}
	if(flag)	return false;
	flag=true;
	for(int j=lsto+1;j<=n;++j)
		if((c[j]=='I')&&f[j]==false){ lsti=j; flag=false; break;}
	if(flag)	return false;
	return true;
}

int main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>(c+1);
	lsto=0;
	for(int i=1;i<=n;++i)	sum[i]=sum[i-1]+(c[i]=='J'||c[i]=='I');
	while(fun())
		if(sum[lsto-1]-ans>0)	++ans, f[lsto]=f[lsti]=1;
	if(sum[n]-ans<ans)	cout<<(sum[n]-ans+(ans-sum[n]+ans)/2)<<endl;
	else	cout<<ans<<endl;
	return 0;
}
/*
JJOIIOOJOJIOIIO
  8  66 5  7
*/
