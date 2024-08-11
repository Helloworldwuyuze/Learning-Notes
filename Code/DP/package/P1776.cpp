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
const int N = 100 + 10;
const int M = 4e4 + 10;

int n, V, v[N], w[N], m[N];
int f[M], q[M], num[M], head, tail, tmp, ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>V;
	for(int i=1;i<=n;++i)	cin>>v[i]>>w[i]>>m[i];
	for(int i=1;i<=n;++i){
		// cout<<i<<endl;
		// for(int j=1;j<=V;++j)
		// 	cout<<f[j]<<" ";
		// cout<<endl;
		if(w[i] == 0){ ans += w[i] * m[i]; continue;}
		int rest = min(m[i], V/w[i]);
		for(int d=0;d<w[i];++d){
			int lim = (V-d)/w[i];
			head = 1, tail = 0;
			for(int j=0;j<=lim;++j){
				while(head<=tail && f[j*w[i]+d] - j*v[i] >= q[tail])	--tail;
				q[++tail] = f[j*w[i]+d]-j*v[i], num[tail] = j;
				// if(i==7 && d == 1)	cout<<head<<" "<<tail<<endl;
				// if(i==7 && d == 1){
				// 	cout<<"###"<<j<<"###"<<endl;
				// 	cout<<j<<" "<<head<<" "<<tail<<endl;
				// 	for(int k=head;k<=tail;++k)	cout<<q[k]<<" "<<num[k]<<endl;
				// 	// for(int j=1;j<=V;++j)	cout<<f[j]<<" ";
				// 	// cout<<endl;
				// }
				while(head<=tail && num[head]+rest < j)	++head;
				f[j*w[i]+d] = max(f[j*w[i]+d], q[head] + j*v[i]);
				// if(i==7 && d == 1){
				// 	cout<<"###"<<j<<"###"<<endl;
				// 	for(int k=head;k<=tail;++k)	cout<<q[k]<<" "<<num[k]<<endl;
				// 	// for(int j=1;j<=V;++j)	cout<<f[j]<<" ";
				// 	// cout<<endl;
				// }
				tmp = max(tmp, f[j*w[i]+d]);
			}
			// if(i == 7){
			// 	cout<<d<<" "<<lim<<endl;
			// 	for(int j=1;j<=V;++j)
			// 		cout<<f[j]<<" ";
			// 	cout<<endl;
			// }
		}
	}
	cout<<tmp+ans<<endl;
	return 0;
}