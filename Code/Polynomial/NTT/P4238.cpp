#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>

#include<bitset>
#include<set>

#include<deque>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>
#include<random>

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define DBG cerr << __LINE__ << ' ' << __FUNCTION__ << endl

#define DRE default_random_engine
#define UID uniform_int_distribution
#define y0 Y0
#define y1 Y1

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 3e5 + 10;
const int M = 1e6 + 10;
const int MOD = 998244353, G = 3;

int r[N], limit, t;
int ksm(int x,int m){
	int ans=1;
	while(m){
		if(m&1)	ans=ans*x%MOD;
		x=x*x%MOD; m>>=1;
	}
	return ans;
}
const int Gi = ksm(G, MOD-2);

int n,f1[N],f2[N];

void out(int a[],int n){
	for(int i=0;i<=n;++i)	cout<<a[i]<<" ";
	cout<<endl;
}
void NTT(int *f,int rev){
	for(int i=0;i<limit;++i)
		if(i<r[i])	swap(f[i], f[r[i]]);
	for(int mid=1;mid<limit;mid<<=1){
		int step=ksm(rev?G:Gi,(MOD-1)/(mid<<1));
		for(int R=mid<<1, j=0;j<limit;j+=R){
			int w=1;
			for(int k=0;k<mid;++k, w=w*step%MOD){
				int x=f[j+k], y=w*f[j+k+mid]%MOD;
				f[j+k]=(x+y)%MOD, f[j+k+mid]=(x-y+MOD)%MOD;
			}
		}
	}
}
void mul(int *a,int *b,int n,int m,int *c){
	limit = 1, t = 0;
	while(limit<=n+m)	limit<<=1, ++t;
	for(int i=0;i<limit;++i)	r[i]=(r[i>>1]>>1)|((i&1)<<t-1);
	NTT(a,1), NTT(b,1);
	for(int i=0;i<limit;++i)	c[i]=a[i]*b[i]%MOD;
	NTT(c,0); int inv=ksm(limit,MOD-2);
	for(int i=0;i<limit;++i)	c[i]=c[i]*inv%MOD;
}
void reduce(int *a,int *b,int n,int *c){
	for(int i=0;i<=n;++i)	c[i]=(a[i]-b[i]+MOD)%MOD;
}
void NumMul(int *a,int b,int n){
	for(int i=0;i<=n;++i)	a[i]=a[i]*b%MOD;
}

int ans[N], g[20][N], tmp[N], _tmp[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)	cin>>f1[i];
	g[0][0]=ksm(f1[0],MOD-2);
	int j=1;
	for(int i=1; i<n ;i<<=1, ++j){
		for(int k=0;k<=i>>1;++k)	tmp[k]=g[j-1][k], f2[k]=g[j-1][k];
		for(int k=(i>>1)+1;k<=i;++k)	f2[k]=tmp[k]=0;
		cout<<"f2:";out(f2,i>>1);
		cout<<"tmp:";out(tmp,i>>1);
		mul(f2,tmp,i>>1,i>>1,_tmp);
		cout<<"_tmp:";out(_tmp,i);
		for(int k=0;k<=i;++k)	f2[k]=_tmp[k];
		for(int k=0;k<=i;++k)	tmp[k]=f1[k], _tmp[k]=f2[k];
		for(int k=i+1;k<=i<<1;++k)	tmp[k]=_tmp[k]=0;
		cout<<"tmp:";out(tmp,i);
		cout<<"_tmp";out(_tmp,i);
		mul(_tmp,tmp,i,i,f2);
		cout<<"f2:";out(f2,i<<1);
		NumMul(g[j-1],2,i>>1);
		reduce(g[j-1],f2,i<<1,g[j]);
		out(g[j-1],i>>1), out(f2,i), out(g[j],i);
	}
	for(int i=0;i<n;++i)
		cout<<g[j-1][i]<<" ";
	cout<<endl;
	return 0;
}