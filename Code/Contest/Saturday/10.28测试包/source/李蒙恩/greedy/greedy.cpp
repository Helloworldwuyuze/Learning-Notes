#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,m;
ll arr[N],w[N],l[N],r[N];
bool vis[N],flag=false;
signed main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout); 
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%lld %d %d",&w[i],&l[i],&r[i]);
		arr[l[i]]++;
		arr[r[i]+1]--;
	}
	for(int i=1;i<=n;i++){
		arr[i]+=arr[i-1];
	}
	ll ans=0;
	while(1){
		flag=false;
		for(int i=1;i<=m;i++){
			if(vis[i]) continue;
			for(int j=l[i];j<=r[i];j++){
				if(arr[j]==1){
					ans+=w[i];
					vis[i]=true;
					flag=true;
					break;
				}
			}
			for(int j=l[i];j<=r[i];j++){
				arr[j]--;
			}
		}
		if(flag==false){
			break;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
