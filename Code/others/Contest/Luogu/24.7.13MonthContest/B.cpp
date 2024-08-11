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
const int N = 5e5 + 10;
const int M = 1e6 + 10;

char s[N], t[N];
int blk[N], dif[N], T, l[N], r[N], tot;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--){
		cin>>(s+1)>>(t+1); tot = 0;
		int n = strlen(s+1), ans = 0;
		for(int i=1;i<=n;++i){
			blk[i] = blk[i-1] + (t[i] != t[i-1]);
			if(s[i] != t[i])	dif[i] = dif[i-1]+1;
			else	dif[i] = 0;
		}
		for(int i=1;i<=n+1;++i){
			if(dif[i] == 1)	l[++tot] = i;
			else if(!dif[i] && dif[i-1])	r[tot] = i-1;
		}
		for(int i=1;i<=tot;++i){
			cout<<"Differ! "<<l[i]<<" "<<r[i]<<" "<<blk[r[i]]<<" "<<blk[l[i]-1]<<endl;
			if(blk[r[i]] - blk[l[i]-1] > 1){
				++ans;
				for(int j=l[i];j<=r[i];++j)	s[j] = (s[j]=='0') + '0';
			}
		}
		// cout<<(s+1)<<endl;
		tot = 0;
		cout<<"ANS in the Middle! "<<ans<<endl;
		for(int i=1;i<=n;++i)
			if(blk[i] != blk[i-1])	r[tot] = i-1, l[++tot] = i;
		r[tot] = n;
		int lst = 1;
		for(int i=1;i<=tot;++i){
			bool flag = false;
			// cout<<l[i]<<" "<<r[i]<<endl;
			for(int j=l[i];j<=r[i];++j)	flag |= s[j] != t[j];
			if(!flag){
				int res1 = 0, res0 = 0;
				cout<<"Whole range! "<<lst<<" "<<i-1<<endl;
				for(int j=lst; j<i; ++j)	res1 += t[l[j]] == '1', res0 += t[l[j]]	== '0';
				if(i-1 >= lst)	ans += min(res1, res0) + 1;
				cout<<"Ans in the Middle! "<<ans<<endl;
				lst = i+1;
			}
		}
		int res1 = 0, res0 = 0;
		for(int i=lst;i<=tot;++i)	res1 += t[l[i]] == '1', res0 += t[r[i]] == '0';
		if(tot >= lst)	ans += min(res1, res0) + 1;
		// cout<<blk[n]<<endl;
		cout<<"ANS! "<<ans<<endl;
		// cout<<ans<<endl;
	}
	return 0;
}