#include<iostream>
#include<cstdio>
using namespace std;
int h[200005];
int main(){
	freopen("zatopljenje.in","r",stdin);
	freopen("zatopljenje.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; i++)scanf("%d",&h[i]);
	int p=1;
	for(int i=2; i<=n; i++)
		if(h[i]<h[p])
			p=i;
//	cout<<p<<endl;
	bool ok=1;
	for(int i=2; i<=p; i++)ok&=(h[i-1]>=h[i]);
	for(int i=n-1; i>=p; i--)ok&=(h[i+1]>=h[i]);
//	cout<<ok<<endl;
	int p2=p;
	if(ok)while(h[p2]==h[p]&&p2<=n)p2++;
	if(h[p2]>h[p])p2--;
//	cout<<p<<" "<<p2<<endl;
	while(q--){
		int x,l,r;
		scanf("%d%d%d",&l,&r,&x);
		if(ok){
			if(l<p&&p2<r) {
				if(h[p]<=x){
					int cnt=(h[l]>x)+(h[r]>x);
//					printf("%d %d\n",(h[l]>x),(h[r]>x));
					printf("%d\n",cnt);
				}
				else printf("%d\n",1);
			}
			else printf("%d\n",(h[l]>x||h[r]>x));
		}else {
			int cnt=0;
			for(int i=l; i<=r; i++){
				if(h[i]>x&&h[i-1]<=x)cnt++;
			}printf("%d\n",cnt);
		}
	}
	return 0;
}/*
fc zatopljenje.out zatopljenje03.out
*/
