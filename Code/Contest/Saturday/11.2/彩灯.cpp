#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int n,l[N],r[N],blk[N],siz[N],idx;
bool a[N],f[N];

int main(){
	freopen("lamp.in","r",stdin);
	freopen("lamp.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>a[i];
	for(int i=1;i<=n;){
		++idx; l[idx]=i;
		do{
			blk[i]=idx;
			++siz[idx];
			++i;
		}while(a[i]!=a[i-1]&&i<=n);
		r[idx]=i-1;
	}
	int maxx=0;
	for(int i=1;i<=idx;++i){
//		cout<<i<<" "<<siz[i]<<" "<<l[i]<<" "<<r[i]<<endl;
		maxx=max(maxx,siz[i]+siz[i-1]+siz[i+1]);
//		if(maxx==9)	cout<<i<<endl;
	}
	cout<<maxx<<endl;
	return 0;
}
