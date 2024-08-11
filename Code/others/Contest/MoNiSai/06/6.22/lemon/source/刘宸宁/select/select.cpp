#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,sum,cnt,a[N],b[N];
inline ll check(){
	if(!cnt) return 1;
	ll flag=1;
	for(int i=1;i<=cnt;i++) b[a[i]]++;
	for(int i=1;i<=cnt;i++) if(b[2*a[i]]||b[3*a[i]]) flag=0;
	for(int i=1;i<=cnt;i++) b[a[i]]--;
	return flag;
}
inline void dfs(ll x){
	if(x>n){
		if(check()) sum++;
		return;
	}
	a[++cnt]=x;dfs(x+1);cnt--;
	dfs(x+1);
}
int main(){
	freopen("select.in","r",stdin);
	freopen("select.out","w",stdout);
	scanf("%lld",&n);
	if(!n){printf("1\n");}
	else{
		dfs(1);
		printf("%lld\n",sum);
		fclose(stdin);
		fclose(stdout);
	}
	return 0;
}

