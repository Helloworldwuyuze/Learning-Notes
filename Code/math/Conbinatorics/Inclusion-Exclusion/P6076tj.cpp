#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll n,m,c,f[410],C[410][410];
ll ksm(ll x,int y){
	ll ans=1;
	while(y){
		if(y&1)ans=ans*x%mod;
		x=x*x%mod,y=y>>1;
	}
	return ans;
}
int main(){
	cin>>n>>m>>c;
	for(int i=0;i<=400;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	for(ll i=1;i<=c;i++){
		ll st=0,k=1;
		for(int j=m;j>=1;j--,k=k*(i+1)%mod){
			if(j&1)
				st=(st+ksm(k-1,n)*C[m][j])%mod;
			else
				st=(st-ksm(k-1,n)*C[m][j]%mod+mod)%mod;
		}
		f[i]=(ksm(ksm(i+1,m)-1,n)-st+mod)%mod;
	}
	ll ans=f[c],an1=0;
	for(int i=1;i<=c;i++){
		if(i&1)
			an1=(an1+f[c-i]*C[c][i])%mod;
		else
			an1=(an1-f[c-i]*C[c][i]%mod+mod)%mod;
		cout<<an1<<" ";
	}
	cout<<(ans-an1+mod)%mod;
	return 0;
}
