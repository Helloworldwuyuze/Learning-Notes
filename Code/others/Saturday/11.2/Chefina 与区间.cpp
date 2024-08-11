#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int n,ans,T;
int l[N],r[N],b[M],m;
int pre[M],suf[M]; 

int main(){
	freopen("chfran.in","r",stdin);
	freopen("chfran.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)	cin>>l[i]>>r[i], b[i]=l[i], b[i+n]=r[i];
		sort(b+1,b+1+2*n);
		m=unique(b+1,b+1+2*n)-b-1;
		for(int i=1;i<=m+1;++i)	pre[i]=suf[i]=0;
		ans=0;
		for(int i=1;i<=n;++i){
			l[i]=lower_bound(b+1,b+1+m,l[i])-b;
			r[i]=lower_bound(b+1,b+1+m,r[i])-b;
			pre[r[i]]++, suf[l[i]]++;
		}
		for(int i=1;i<=m;++i)	pre[i]+=pre[i-1];
		for(int i=m;i;--i)	suf[i]+=suf[i+1];
		for(int i=1;i<=m;++i){
			if(pre[i]!=0&&suf[i+1]!=0)	ans=max(ans,pre[i]+suf[i+1]);
//			cout<<i<<" "<<pre[i]+suf[i+1]<<" "<<ans<<endl;
		}
		if(ans==0)	cout<<-1<<endl;
		else	cout<<n-ans<<endl;
	}
	return 0;
}

