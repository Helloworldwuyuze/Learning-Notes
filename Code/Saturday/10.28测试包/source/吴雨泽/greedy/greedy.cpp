#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include<stack>

using namespace std;

const int N = 50 + 10;
const int M = 20 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int n,m,ans;
struct cow{
	int l,r,w;
}a[M];
bool cover[N];
bool chs[N];

bool cmp(cow x,cow y){
	return (x.r-x.l+1)==(y.r-y.l+1)?(x.l<y.l):(x.r-x.l+1)<(y.r+y.l+1);
}

int main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=n;++i)	cin>>a[i].w>>a[i].l>>a[i].r;
	sort(a+1,a+1+n,cmp);
	for(int i=0;i<(1<<n);++i){
		int x=i,s=0,res=0;
		memset(chs,0,sizeof(chs));
		memset(cover,0,sizeof(cover));
		while(x)	chs[++s]=x%2, x>>=1;
		bool ok=true;
		for(int k=1;k<=n;++k)
			if(chs[k]){
				bool flag=true;
				for(int j=a[k].l;j<=a[k].r;++j)	flag&=cover[j];
				if(flag){ ok=false; break;}
				res+=a[k].w;
				for(int j=a[k].l;j<=a[k].r;++j)	cover[j]=1;
			}
		if(ok)
			ans=max(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}

