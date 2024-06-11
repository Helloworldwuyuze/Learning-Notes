#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int nxt[N],a[N],b[N],n,cnt,lst[N];

int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>a[i], b[i]=a[i];
	sort(b+1,b+1+n);
	cnt=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;++i)
		a[i]=lower_bound(b+1,b+1+cnt,a[i])-b;
	for(int i=n;i;--i)
		if(!lst[a[i]])	lst[a[i]]=i;
	for(int i=1;i<=n;){
		if(lst[a[i]]!=INF){
			int ii=i;
			while(i<=lst[a[ii]])	a[i]=a[ii], ++i;
		}else	++i;
	}
	for(int i=1;i<=n;++i)	cout<<b[a[i]]<<endl;
	return 0;
}
//10 1 1 2 2 1 2 2 1 1 2
