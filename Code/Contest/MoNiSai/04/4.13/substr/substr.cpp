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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 50 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

int n, a[N], len[N], border[N][N], minn=INF;
char c[N][N];
char ans[N*N], tmp[N*N];

bool check(int x,int y,int z){
//	cout<<"###"<<x<<" "<<y<<" "<<z<<"###"<<endl;
	for(int i=len[x]-z+1, j=1;j<=z;++i, ++j){
//		cout<<c[x][i]<<" "<<c[y][j]<<endl;
		if(c[x][i]!=c[y][j])	return false;
	}
	return true;
}

bool chk(char c[], char s[]){
	int lc=strlen(c+1);
	for(int i=1;i<=lc;++i)
		if(c[i]<s[i])	return true;
		else if(s[i]<c[i])	return false;
	return false;
}

bool belong(int x,int y){
	if(len[x]>len[y])	return false;
	for(int l=1;l+len[x]-1<=len[y];++l){
		bool flag=true;
		for(int i=l;i<=l+len[x]-1;++i)
			if(c[x][i-l+1]!=c[y][i]){
				flag=false;
				break;
			}
		if(flag)	return true;
	}
	return false;
}

signed main(){
	freopen("substr.in","r",stdin);
	freopen("substr.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>(c[i]+1), a[i]=i, len[i]=strlen(c[i]+1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j)	continue;
//			cout<<i<<" "<<j<<" "<<belong(i,j)<<" "<<belong(j,i)<<endl;
			if(belong(i,j)){
				for(int k=i+1;k<=n;++k){
					len[k-1]=len[k];
					for(int l=1;l<=len[k-1];++l)
						c[k-1][l]=c[k][l];
				}
				n--; --i;
				break;
			}
			int l=min(len[i],len[j]);
			for(int k=l;k>=0;--k)
				if(check(i,j,k)){
					border[i][j]=k;
					break;
				}
//			cout<<i<<" "<<j<<" "<<border[i][j]<<endl;
		}
	}
//	cout<<n<<endl;
	do{
//		cout<<"###";
//		for(int i=1;i<=n;++i)
//			cout<<a[i]<<" ";
//		cout<<endl;
		int idx=len[a[1]];
		for(int i=1;i<=len[1];++i)	tmp[i]=c[a[1]][i];
		for(int i=2;i<=n;++i){
//			cout<<border[a[i-1]][a[i]]<<" "<<len[a[i]]<<" ";
			for(int j=border[a[i-1]][a[i]]+1;j<=len[a[i]];++j)
				tmp[++idx]=c[a[i]][j];
		}
//		cout<<endl;
		if(idx<minn){
			minn=idx;
			for(int i=1;i<=idx;++i)	ans[i]=tmp[i];
		}else if(idx==minn&&chk(tmp,ans)){
			minn=idx;
			for(int i=1;i<=idx;++i)	ans[i]=tmp[i];
		}
//		cout<<(ans+1)<<endl;
	}while(next_permutation(a+1,a+1+n));
	for(int i=1;i<=minn;++i)
		cout<<ans[i];
	cout<<endl;
	return 0;
}

