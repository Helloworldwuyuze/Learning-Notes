#include<bits/stdc++.h>
#define pr printf("\n")
#define pp printf(" ")
#define INF 0x3f3f3f3f
using namespace std;
typedef int ll;
ll n,m,k,sum;
string s,a;
ll qpow(ll a,ll b){
	if(!b) return 1;
	ll ans=1;
	while(b){
		if(b&1) ans=ans*a%k;
		a=a*a%k;
		b>>=1; 
	}
	return ans%k;
}
void gz(ll x){
	if(x>n){
		ll ans=0,i=0;
		while(a.find(s,i)!=EOF) ans++,i=a.find(s,i)+1; 
		if(ans>=1) return;
		sum++;sum%=k;
		return;
			
	}
	ll les=0;
//	if(x==1) les=1;
	for(ll i=les;i<10;i++){
		string b=a;
		a+=char(i+'0');
		gz(x+1);
		a=b;
	}
}
const ll N=5e5+5;
ll lac[N],inv[N]; 
ll C(ll a,ll b){
	if(!b) return 1;
	return lac[n]%k*inv[m]%k*inv[n-m]%k;
}
int main(){
	freopen("gt.in","r",stdin);
	freopen("gt.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	cin>>s;
	lac[0]=1;
	for(ll i=1;i<=n/m;i++) lac[i]=lac[i-1]*i%k;
	inv[n/m]=qpow(lac[n/m],k-2)%k;
	for(ll i=n/m-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%k; 
	if(n<=9){gz(1);printf("%d\n",sum);}
	else{
		sum=0;
		ll p=1;
		for(ll i=0;i<=n/m;i++){
			sum=(sum+qpow(10,n-i*m)%k*C(n/m,i)*p%k)%k;
			p*=-1;
		}
		printf("%d\n",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
