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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

string s;
int W,B;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>W>>B;
	s="wbwbwwbwbwbw";
	for(int i=1;i<=50;++i)	s+="wbwbwwbwbwbw";
	int len=s.size();
	for(int l=0;l<len;++l){
		for(int r=l;r<len;++r){
			int w=0,b=0;
			for(int i=l;i<=r;++i)
				if(s[i]=='w')	++w;
				else	++b;
			if(w==W&&b==B){
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}