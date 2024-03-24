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
const int N = 1e5 + 10;
const int M = 1e6 + 10;

string s1,s2;
int n,l,r=1e14,s[N][128],len1,len2,letter[128];
vector<int> position[128];

bool check(int x){
	int sum=0,need=x;
	for(int i=0;i<len2;++i){
		if(!letter[s2[i]])	return false;
		sum+=need/letter[s2[i]];
		// if(x==2)	cout<<need<<" "<<s2[i]-'a'<<" "<<sum<<endl;
		if(i==len2-1)	break;
		if(x%letter[s2[i]])	++sum, need=x-s[position[s2[i]][x%letter[s2[i]]]+1][s2[i+1]];
		else	need=x-s[position[s2[i]].back()][s2[i+1]];
		// else	need=x;
	}
	return sum<=n;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>s1>>s2;
	len1=s1.size(); len2=s2.size();
	for(int i=0;i<len1;++i)
		s[i][s1[i]]++, letter[s1[i]]++, position[s1[i]].pb(i);
	for(int i=len1-1;i>=0;--i)
		for(int j=0;j<128;++j)
			s[i][j]+=s[i+1][j];
	while(l<r){
		int mid=l+r+1>>1;
		// cout<<mid<<" "<<check(mid)<<endl;
		if(check(mid))	l=mid;
		else	r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}