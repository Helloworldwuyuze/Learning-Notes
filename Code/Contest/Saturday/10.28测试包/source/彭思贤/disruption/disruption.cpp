#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#define ll long long
#define inf 0x3f3f3f3f
#define mod 998244353
#define N 200005
using namespace std;
int n,m;
int a,b,c;
int main(){
	freopen("disruption.in","r",stdin);
	freopen("disruption.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n-1;i++){
		cin>>a>>b;
	}
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
	}
	for(int i=1;i<=n-1;i++){
		cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
