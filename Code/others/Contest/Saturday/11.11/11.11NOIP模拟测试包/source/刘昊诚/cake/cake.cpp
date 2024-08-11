 #include<iostream>
 #include<cstdio>
 using namespace std;
 const int N=2005;
 int n,a[N],pre[N],nxt[N];
 long long ans;
 bool chosen[N];
 void dfs(int u,int step,long long sum){
 	if(step>n){
 		ans=max(ans,sum);
 		return;
 	}
 	int chs=0,ioi;
 	for(int i=1;i<=n;i++){
 		if(chosen[i])continue;
 		int lj=pre[i],rj=nxt[i];
 		if(!chosen[lj]&&!chosen[rj])continue;
 		chs=max(chs,a[i]);
 		if(chs==a[i])ioi=i;
 	}
 	chosen[ioi]=true;
 	for(int i=1;i<=n;i++){
 		if(chosen[i])continue;
 		int lj=pre[i],rj=nxt[i];
 		if(!chosen[lj]&&!chosen[rj])continue;
 		chosen[i]=true;
 		dfs(i,step+2,sum+(long long)a[i]);
 		chosen[i]=false;
 	}
 	ans=max(ans,sum);
 	return;
 }
 int main(){
 	freopen("cake.in","r",stdin);
 	freopen("cake.out","w",stdout);
 	scanf("%d",&n);
 	for(int i=1;i<=n;i++){
 		scanf("%d",a+i);
 		pre[i]=(i-1?i-1:n);
 		nxt[i]=(i+1<=n?i+1:1);
 	}
 	for(int i=1;i<=n;i++){
 		chosen[i]=true;
 		dfs(i,1,(long long)a[i]);
 		chosen[i]=false;
 	}
 //	for(int at=2;at<=n;at++){
 //		if(!(at&2)){
 //			for(int j=1;j<=n;j++){
 //				if(!dp[at-1][j])continue;
 //				int lj=pre[j],rj=nxt[j];
 //				
 //			}
 //			continue;
 //		}
 //	}
 	printf("%lld\n",ans);
 	return 0;
 }
