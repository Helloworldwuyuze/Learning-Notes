#include<bits/stdc++.h>

using namespace std;

const int N = 5 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int n,m,a[N][N],b[N][N],ans=INF,x[N],y[N];
bool xx[N],yy[N];

bool check(){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[x[i]][y[j]]!=b[i][j])	return false;
	return true;
}

int solve(){
	int sum=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)	sum+=x[j]<x[i];
	for(int i=1;i<=m;++i)
		for(int j=i+1;j<=m;++j)	sum+=y[j]<y[i];
	return sum;
}

void dfsy(int loca){
	if(loca==m+1){
		if(check())	ans=min(ans,solve());
		return ;
	}
	for(int i=1;i<=m;++i){
		if(yy[i])	continue;
		yy[i]=true; y[loca]=i;
		dfsy(loca+1);
		yy[i]=false; y[loca]=0;
	}
}

void dfsx(int loca){
	if(loca==n+1){
		dfsy(1);
		return ;
	}
	for(int i=1;i<=n;++i){
		if(xx[i])	continue;
		xx[i]=true; x[loca]=i;
		dfsx(loca+1);
		xx[i]=false; x[loca]=0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)	cin>>a[i][j];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)	cin>>b[i][j];
	dfsx(1);
	cout<<(ans==INF?-1:ans)<<endl;
	return 0;
}

