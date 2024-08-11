#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
#define file(a) freopen(#a".in","r",stdin),freopen(#a".out","w",stdout);
const int N=2e5+10;
int n,k;
char s[N];
int pre[3][N],nex[3][N],posj,poso,posi;
int cntj,cnto,cnti,tmp1,tmp2;
int firstj,firsto,firsti;
int J[N],O[N],I[N],head[N],locj,loco;
inline int solve(int i){
	if(I[i]==-1||head[I[i]]==0||O[head[I[i]]]==-1||head[O[head[I[i]]]]==0||J[head[O[head[I[i]]]]]==-1) return INF;
	return J[head[O[head[I[i]]]]];
}

int main(){
	file(joi);
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		if(s[i]=='J'){
			cntj++;
			pre[0][i]=posj;
			nex[0][posj]=i;
			posj=i;
			if(cntj==1) firstj=i;
			if(cntj<k){
				J[i]=-1;
				continue;
			}
			if(cntj==k){
				J[i]=firstj;
				continue;
			}
			J[i]=nex[0][J[pre[0][i]]];
		}
		else if(s[i]=='O'){
			cnto++;
			pre[1][i]=poso;
			nex[1][poso]=i;
			poso=i;
			if(cnto==1) firsto=i;
			if(cnto<k){
				O[i]=-1;
				continue;
			}
			if(cnto==k){
				O[i]=firsto;
				continue;
			}
			O[i]=nex[1][O[pre[1][i]]];
		}
		else{
			cnti++;
			pre[2][i]=posi;
			nex[2][posi]=i;
			posi=i;
			if(cnti==1) firsti=i;
			if(cnti<k){
				I[i]=-1;
				continue;
			}
			if(cnti==k){
				I[i]=firsti;
				continue;
			}
			I[i]=nex[2][I[pre[2][i]]];
		}
	}
	for(int i=1;i<=n;++i){
		if(s[i]=='J') locj=i;
		if(s[i]=='O') loco=i,head[i]=locj;
		if(s[i]=='I') head[i]=loco;
	}
	int ans=INF;
	for(int i=1;i<=n;++i){
		if(s[i]=='I'){
			int tmp=solve(i);
			if(tmp==INF) continue;
			ans=min(ans,i-solve(i)+1);
		}
	}
	if(ans==INF) puts("-1");
	else printf("%d\n",ans-3*k);
	return 0;
}
