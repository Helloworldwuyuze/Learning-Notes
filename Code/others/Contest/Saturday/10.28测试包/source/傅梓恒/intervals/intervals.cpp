#include<cstdio>
#include<iostream>
using namespace std;
const int N=2e5+100;
typedef long long ll;
int n,m;
struct node{
	int l,r,a;
}e[N];
ll ans=0;
int main(){
	freopen("intervals.in","r",stdin);
	freopen("intervals.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].l,&e[i].r,&e[i].a);
	}
	for(int i=0;i<(1<<n);i++){
		ll res=0;
		for(int j=1;j<=m;j++){
			for(int k=e[j].l;k<=e[j].r;k++){
				//cout<<i<<" "<<e[j].l<<" "<<e[j].r<<" "<<n-k<<endl; 
				if((i>>(n-k))&1){
					res+=e[j].a;
					break;
				}
			}
		}
		//cout<<i<<" "<<res<<endl; 
		ans=max(ans,res);
	}
	printf("%lld\n",ans); 
	return 0;
}
