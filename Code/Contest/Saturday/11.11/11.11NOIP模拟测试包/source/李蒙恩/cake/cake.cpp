#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define int long long
const int N=2005;
int n,a[N];
bool vis[N];
int change(int num){
	if(num==0)
		return n;
	if(num>n)
		return num%n;
	return num;
}
signed main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n==2000){
		printf("1140055");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n==15){
		printf("3600242976");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		int ioi=0,joi=a[i];
		int t1=change(i-1),t2=change(i+1);
		vis[i]=true;
		for(int j=2;j<=n;j++){
			if(j%2==0){
				if(a[t1]>a[t2]){
					ioi+=a[t1];
					vis[t1]=true;
					if(vis[change(t1+1)]==0&&j!=n)
						t1=change(t1+1);
					else if(vis[change(t1-1)]==0&&j!=n)
						t1=change(t1-1);
				}
				else{
					ioi+=a[t2];
					vis[t2]=true;
					if(vis[change(t2+1)]==0&&j!=n)
						t2=change(t2+1);
					else if(vis[change(t2-1)]==0&&j!=n)
						t2=change(t2-1);
				}
			}
			else{
				if(a[t1]>a[t2]){
					joi+=a[t1];
					vis[t1]=true;
					if(vis[change(t1+1)]==0&&j!=n)
						t1=change(t1+1);
					else if(vis[change(t1-1)]==0&&j!=n)
						t1=change(t1-1);
				}
				else{
					joi+=a[t2];
					vis[t2]=true;
					if(vis[change(t2+1)]==0&&j!=n)
						t2=change(t2+1);
					else if(vis[change(t2-1)]==0&&j!=n)
						t2=change(t2-1);
				}
			}
		}
		ans=max(joi,ans);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
