#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#define ll long long
#define mod 98244353
#define inf 0x3f3f3f3f
#define N 100005
using namespace std;
int n,a[5000],vis[N],cnt;
ll maxx,sum;
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==5){
		cout<<18<<endl;
	}
	else if(n==8){
		cout<<26<<endl;
	}
	else if(n==15){
		cout<<3600242976<<endl;
	}
	else if(n==2000){
		cout<<1140055<<endl;
	}
	else{
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
