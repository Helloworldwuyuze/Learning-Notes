#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
vector<int>G[100005];
int a[300005];
int c[300005];
int main(){
	freopen("meximum.in","r",stdin);
	freopen("meximum.out","w",stdout); 
	int n;
	scanf("%d",&n);
	int id=n;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}long long ans=0;
	for(int l=1; l<=n; l++){
		int mex=0;
		memset(c,0,sizeof c);
		for(int r=l; r<=n; r++){
			c[a[r]]=1;
			while(c[mex])mex++;ans+=mex;
		}
	}cout<<ans;
	return 0;
}/*
4 4
1 2 3 4
1 2
1 3
1 4
1 0
1 1
2 1
4 100

*/
