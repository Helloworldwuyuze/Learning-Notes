#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
#define fin(a) freopen(#a".in","r",stdin)
#define fout(a) freopen(#a".out","w",stdout)
const int N=305;
int n,m;
ll f[N][N];
struct node{
	ll w;
	int zuo,you;
	bool operator < (const node&rho) const{
		if(rho.w==w) return rho.you>you;
		return rho.w<w;
	}
};
vector<node> g[N];
int st[N][N];

int main(){
	fin(greedy);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int L,R;
		ll w;
		scanf("%lld%d%d",&w,&L,&R);
		f[L][R]=w;
		for(int j=L;j<=R;++j) g[j].push_back(node{w,L,R});
	}
	for(int i=1;i<=n;++i) sort(g[i].begin(),g[i].end());
	for(int len=1;len<=n;++len){
		int L=0,R=0;
		memset(st,0,sizeof(st));
		for(int i=1;i+len-1<=n;++i){
			int j=i+len-1;
			for(int k=i;k<=j;++k){
				int tot=0,l=g[k].size();
				if(k>i&&k<j){
					while(tot<l&&(g[k][tot].zuo<i||g[k][tot].you>j))
						tot++;
				}
//				cout<<i<<" "<<j<<" "<<k<<" "<<tot<<"\n";
				if(f[i][k-1]+f[k+1][j]+g[k][tot].w>f[i][j]&&st[g[k][tot].zuo][g[k][tot].you]==0){
					st[L][R]=0;
					L=g[k][tot].zuo,R=g[k][tot].you;
					st[L][R]=1;
					f[i][j]=f[i][k-1]+f[k+1][j]+g[k][tot].w;
				}
			}
		}
	}
	printf("%lld\n",f[1][n]);
	return 0;
}
