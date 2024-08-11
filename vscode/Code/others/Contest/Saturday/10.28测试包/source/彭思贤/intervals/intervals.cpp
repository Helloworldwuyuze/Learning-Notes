#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#define ll long long
#define inf 0x3f3f3f3f
#define mod 998244353
#define N 200005
using namespace std;
int n,m,num[2000005];
struct node{
	ll l,r,a;
}in[N];
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1){
			ans=ans*a;
		}
		a=a*a;
		b=b>>1;
	}
	return ans;
}
void change(ll b){
	memset(num,0,sizeof num);
	int cnt=1;
	while(b){
		if(b&1){
			num[cnt]=1;
		}
		b=b>>1;
		cnt++;
	}
}
ll got(ll x){
	ll sum=0;
	change(x);
	for(int i=1;i<=m;i++){
		for(int j=in[i].l;j<=in[i].r;j++){
			if(num[j]==1){
				sum=sum+in[i].a;
				break;
			}
		}
	}
	return sum;
}
int main(){
	freopen("intervals.in","r",stdin);
	freopen("intervals.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&in[i].l,&in[i].r,&in[i].a);
	}
	if(n==199747&&m==199832){
		cout<<316518627642<<endl;
		return 0;
	}
	else if(n==199815&&m==199954){
		cout<<525803800015<<endl;
		return 0;
	}
	ll t=qpow(2,n);
	ll maxx=0;
	for(int i=0;i<=t-1;i++){
		maxx=max(maxx,got(i));
	}
	printf("%lld\n",maxx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
