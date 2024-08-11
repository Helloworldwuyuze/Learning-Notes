#include<bits/stdc++.h>
#define pr printf("\n")
#define pp printf(" ")
#define INF 0x3f3f3f3f
using namespace std;//10 2 OJIJOIOIIJ
typedef long long ll;
const ll N=2e5+5;
int n,k;
int fj[N],fo[N],fk[N];
int nxtj[N],nxto[N];
int ansk[N],ansj[N],anso[N],net[N];
string s;
int main(){
	freopen("joi.in","r",stdin);
	freopen("joi.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s;
	s=" "+s;
	ll lastj=0,lasto=0,lastk=0,lo=0,lk=0,mxo=0,mxk=0,mxj=0,mij=INF;
	ll op=0;
	for(ll i=1;i<=n;i++)
	{
		if(s[i]=='J'){
			if(!op) op=i;
			else net[op]=i,op=i;
		}
	}
	for(ll i=n;i>=1;i--){
		if(s[i]=='J')
		{
			if(!lastj) lastj=i,mxj=i;
			else fj[lastj]=i,lastj=i;
			mij=min(mij,lastj);
			if(lo) nxtj[i]=lo;
		}
		if(s[i]=='O')
		{
			if(!lasto) lasto=i,mxo=i;
			else fo[lasto]=i,lasto=i;
			lo=i;
			if(lk) nxto[i]=lk;
		}
		if(s[i]=='I')
		{
			if(!lastk) lastk=i,mxk=i;
			else fk[lastk]=i,lastk=i;
			lk=i;
		}
	}
	ll last=mxk;
	ll i=mxk,sum=1;
	while(i!=0){
		if(sum<k){
			sum++;
			i=fk[i];
			continue;
		}
		ansk[i]=last;
		last=fk[last];
		i=fk[i];
	}
	i=mxo,sum=1;
	last=mxo;
	while(i!=0){
		if(sum<k){
			sum++;
			i=fo[i];
			continue;
		}
		anso[i]=last;
		last=fo[last];
		
		i=fo[i];
	}
	i=mxj,sum=1;
	last=mxj;
	while(i!=0){
		
		if(sum<k){
			i=fj[i];
			sum++;
			continue;
		}
		ansj[i]=last;
		last=fj[last];
//		printf("%d %d %d %d\n",i,ansj[i],fj[i],sum);
		i=fj[i];
	}	
	ll j=mij,minn=INF;
	i=j;
	while(j!=0){
		i=j;
		i=ansj[i];
//		printf("%d %d\n" ,j,i);
		i=nxtj[i];
//		printf("%d %d\n" ,j,i);
		i=anso[i];
//		printf("%d %d\n" ,j,i);
		i=nxto[i];
//		printf("%d %d\n" ,j,i);
		i=ansk[i];
		if(i&&j) minn=min(minn,i-j+1-3*k);
//		printf("%d %d %d\n",minn,i,j);
		j=net[j];
	}
	if(minn==INF) printf("-1");
	else printf("%d",minn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
JJOIOJOIOIJIO
12222333334
00112011220
00010001010

20 3
JJJOOJJJJJJOIIOIOIII
*/
