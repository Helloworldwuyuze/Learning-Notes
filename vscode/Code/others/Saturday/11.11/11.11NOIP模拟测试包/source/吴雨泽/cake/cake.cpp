#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<queue>
#include<stack>
#include<set>
#include<vector>

using namespace std;

const int N = 4e3 + 10;
const int M = 2e5 + 10;
#define endl '\n'
#define int long long
const int INF = 0x3f3f3f3f;

int n,a[N],f[N][N],l[N][N],r[N][N];

void updatel(int i,int j){
	if(a[i+1]>a[j])	l[i][j]=a[i]+f[i+2][j];
	else	l[i][j]=a[i]+f[i+1][j-1];
}
void updater(int i,int j){
	if(a[i]>a[j-1])	r[i][j]=a[j]+f[i+1][j-1];
	else	r[i][j]=a[j]+f[i][j-2];
}

signed main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		a[i+n]=a[i];
	}
	n<<=1;
	for(int i=1;i<=n;++i)	f[i][i]=l[i][i]=r[i][i]=a[i];
	for(int len=2;len<=n;++len){
		for(int i=1;i+len-1<=n;++i){
			int j=i+len-1;
			updatel(i,j), updater(i,j);
			f[i][j]=max(l[i][j],r[i][j]);
		}
	}
	int maxx=0;
	n>>=1;
	for(int i=1;i<=n;++i)
		maxx=max(maxx,max(l[i][i+n-1],r[i][i+n-1]));
	cout<<maxx<<endl;
	return 0;
}

