#include<cstdio>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<iostream>
#define long long long
using namespace std;
const int N=1e3+10;
int n,m,phi,al,ar,F[N*N+N];
long per[N*N+N];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int qpow(int x,int i){
	int res=1;
	for(;i;i>>=1,x=x*x%n)
		if(i&1)res=res*x%n;
	return res;
}
inline int f(int i){
	if(i>=phi)i=qpow(i%n,i%phi+phi);
	else i=qpow(i%n,i);
	return i?i:n;
}
unordered_map<int,int> mp;
int main(){
	int tt;
	scanf("%d",&tt);
	while(tt--){
		scanf("%d%d",&n,&m);n--;
		bool ok=0;phi=1;
		for(int x=n,i=2;i<=x;i++)
			if(x%i==0){
				phi*=i-1;x/=i;
				while(x%i==0){phi*=i;x/=i;}
			}
		for(int i=1;i<phi;i++){
			per[i]=0;F[i]=f(i);
			for(int j=1;j<=i;j++)per[j]+=F[i];
			for(int j=1;j<=i;j++)
				if(per[j]==m){
					printf("%d %d\n",j,i);
					ok=1;break;
				}
			if(ok)break;
		}
		if(ok)continue;
		// puts("QAQ");
		int k=phi*n/gcd(phi,n),tot=0;
		long S=0,sL=0,sR=0,mL=0,mR=0;
		for(int i=0;i<k;i++)S+=F[phi+i]=f(phi+i);
		for(int i=1;i<=phi;i++)sR+=F[i];
		mR=sR%S;sL=m;mL=sL%S;
		for(int r=phi,l=1;l<phi+k;){
			if(r<phi+k&&sR<=sL){
				per[r]=sR;mp[mR]=r;
				sR+=F[++r];
				if((mR+=F[r])>=S)mR-=S;
			}else{
				if(mp.find(mL)!=mp.end()){
					al=l;ar=mp[mL];
					ar+=(sL-per[ar])/S*k;
					ok=1;break;
				}
				if((mL+=F[l])>=S)mL-=S;
				sL+=F[l++];
			}
		}
		// cout<<per[1145]<<endl;
		if(ok)printf("%d %d\n",al,ar);
		else printf("-1 -1\n");
		mp.clear();
	}
	return 0;
}