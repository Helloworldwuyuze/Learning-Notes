#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>
#include<unordered_map>

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
#define endl '\n'

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e3 + 10;
const int M = 1e2 + 10;

int ma[N], s, w[N][10], v[N], m[N], b, lim[10], idx, f[10][10][10][10][10];

int Hash(int x){
	if(!ma[x])	ma[x] = ++idx;
	return ma[x];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>s;
	for(int i=1;i<=s;++i){
		cin>>m[i];
		for(int j=1;j<=m[i];++j){
			int id, k; 	cin>>id>>k;
			id = Hash(id);
			w[i][id] = k;
		}
		cin>>v[i];
	}
	cin>>b;
	for(int i=1;i<=b;++i){
		int id, k;
		cin>>id>>k>>v[i+s]; id = Hash(id);
		w[i+s][id] = 1, lim[id] = k;
	}
	memset(f, 0x3f, sizeof(f));
	f[0][0][0][0][0] = 0;
	// for(int i=1;i<=b+s;++i)
	// 	cout<<i<<" "<<w[i][1]<<" "<<w[i][2]<<" "<<w[i][3]<<" "<<w[i][4]<<" "<<w[i][5]<<" "<<v[i]<<endl;
	for(int i=1;i<=b+s;++i)
		for(int j=w[i][1];j<=lim[1];++j)
			for(int k=w[i][2];k<=lim[2];++k)
				for(int l=w[i][3];l<=lim[3];++l)
					for(int m=w[i][4];m<=lim[4];++m)
						for(int n=w[i][5];n<=lim[5];++n)
							f[j][k][l][m][n] = min(f[j][k][l][m][n], f[j-w[i][1]][k-w[i][2]][l-w[i][3]][m-w[i][4]][n-w[i][5]]+v[i]);
	cout<<f[lim[1]][lim[2]][lim[3]][lim[4]][lim[5]]<<endl;
	return 0;
}