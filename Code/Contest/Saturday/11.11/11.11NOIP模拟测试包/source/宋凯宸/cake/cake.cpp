#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=2005;
int n;
long long a[N];
long long c[N];
bool vis[N];
long long maxx=-1;
long long cheak(int x){
	long long ans=0;ans+=a[x];
	vis[(a[x-1]<=a[x+1]?x+1:x-1)]=1;vis[x]=1;
	if(vis[x-1]==1){
		int i=x-1,j=x,tot=0;
		for(int i=x-1;i>=1;i--)c[++tot]=a[i];
		for(int j=n;j>=x;j--)c[++tot]=a[j];
	}
	if(vis[x+1]==1){
		int i=x,j=x+1,tot=0;
		for(int i=x;i>=1;i--)c[++tot]=a[i];
		for(int j=n;j>=x+1;j--)c[++tot]=a[j];
	}
	int i=2,j=n-1;
	long long max1,max2;
	while(i<=j){
		if(i==j){
			ans+=c[i];break; 
		} 
		int k,l;
		if(c[i+1]>c[j]){
			max1=c[i]+max(c[i+2],c[j])-c[i+1];
			k=c[i+1];
		} 
		else {
			max1=c[i]+max(c[i+1],c[j-1])-c[j];
			k=c[j];
		}
		if(c[j-1]>c[i]){
			max2=c[j]+max(c[i],c[j-2])-c[j-1];
			l=c[j-1];
		}
		else {
			max2=c[j]+max(c[i+1],c[j-1])-c[i];
			l=c[i];
		}
		if(max1==max2&&k<l)max1++;
		if(max1==max2&&k>l)max2++;
		if(max1>max2){
			ans+=c[i];i++;
			if(c[i]<c[j])j--;
			else i++;
		}
		else{
			ans+=c[j];j--;
			if(c[i]<c[j])j--;
			else i++;
		}
	} 
	return ans;
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	a[0]=a[n];a[n+1]=a[1];
	for(int i=1;i<=n;i++){
		if(cheak(i)>maxx)maxx=cheak(i);
		memset(vis,0,sizeof(vis));
		memset(c,0,sizeof(c));
	}
	cout<<maxx;
	return 0;
}
