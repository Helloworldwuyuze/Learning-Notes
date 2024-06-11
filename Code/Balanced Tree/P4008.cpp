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
#include<ext/rope>

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define DBG cerr << __LINE__ << ' ' << __FUNCTION__ << endl

#define DRE default_random_engine
#define UID uniform_int_distribution
#define y0 Y0
#define y1 Y1
// #define endl '\n'

#define pi acos(-1)
#define eps (1e-8)

using namespace std;
using namespace __gnu_cxx;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 50 + 10;
const int M = 1e6 + 10;

rope <char> r;
char ch;
string op;
int pos, n, len, x;

int main(){
	// ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	scanf("%d",&n);
	while(n--){
		cin>>op; scanf("%d", &len);
		// cout<<op<<endl;
		switch(op[0]){
			case 'M':{ pos=len; break; }
			case 'I':{
				int poss = pos;
				while(len){
					ch=getchar();
					if(ch>=32&&ch<=126)	r.insert(poss, ch), ++poss, --len;
				}
				break;
			}case 'D':{ r.erase(pos, len); break; }
			case 'G':{ cout<<r.substr(pos, len)<<endl; break; }
			case 'P':{ --pos; break;}
			case 'N':{ ++pos; break;}
		}
	}
	return 0;
}