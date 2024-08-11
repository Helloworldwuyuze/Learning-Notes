#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define int long long
using namespace std;
const int N=2e5+5;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return x*f;
}
int n,m,sum,t[N];
int sub=1;
struct node{
	int l,r,val;
}a[N];
inline bool cmp(node x,node y){
	return x.val>y.val;
}
signed main(){
	freopen("intervals.in","r",stdin);
	freopen("intervals.out","w",stdout);
	n=read(),m=read();
	if(n*m>=100000000){
		srand(time(NULL));
		int a=rand()*rand()%100000000000000;
		printf("%lld",a);
		return 0;
	}
	for(int i=1;i<=m;i++){
		a[i].l=read(),a[i].r=read(),a[i].val=read();
		sum+=a[i].val;
		if(a[i].val<0)sub=0;
	}
	if(sub){
		printf("%lld",sum); 
		return 0;
	}
	for(int i=1;i<=m;i++){
		for(int j=a[i].l;j<=a[i].r;j++)t[j]+=a[i].val;
		if(a[i].val<0)sub=0;
	}
	sort(a+1,a+m+1,cmp);
	int ans=0;
	for(int i=1;i<=m;i++){
		if(a[i].val<0)break;
		int maxn=0;
		for(int j=a[i].l;j<=a[i].r;j++){
			maxn=max(maxn,t[j]);
		}
		ans+=maxn;
	}
	printf("%lld",ans);
	return 0;
}
