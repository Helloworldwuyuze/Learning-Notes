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
const int N = 1e5 + 10;
const int M = 1e6 + 10;

string s;
int big, len;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>s; len=s.size();
	for(int i=0;i<len;++i)
		big+=s[i]>='A'&&s[i]<='Z';
	if(big*2>len)
		for(int i=0;i<len;++i)
			if(s[i]<='z'&&s[i]>='a')	cout<<(char)(s[i]-32);
			else	cout<<s[i];
	else
		for(int i=0;i<len;++i)
			if(s[i]<='Z'&&s[i]>='A')	cout<<(char)(s[i]+32);
			else	cout<<s[i];
	cout<<endl;
	return 0;
}