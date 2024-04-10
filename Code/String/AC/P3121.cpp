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
const int N = 1e5 + 10;
const int M = 2e6 + 10;
const int MOD = 1e9 + 7;

string s,c;
int n;

int t[N][26], fail[N], idx, flag[N], sta[N];

void insert(string s){
    int len=s.size(), p=0;
    for(int i=0;i<len;++i)
        p=t[p][s[i]-'a']?(t[p][s[i]-'a']):(t[p][s[i]-'a']=++idx);
    flag[p]=len;
}
queue<int> q;
void build(){
    for(int i=0;i<26;++i)
        if(t[0][i]) q.push(t[0][i]);
    while(q.size()){
        int p=q.front(); q.pop();
        for(int i=0;i<26;++i)
            if(t[p][i]) fail[t[p][i]]=t[fail[p]][i], q.push(t[p][i]);
            else    t[p][i]=t[fail[p]][i];
    }
}
void query(string& s){
    int len=s.size(), p=0;
    sta[0]=0;
    for(int i=1;i<len;++i){
        sta[i]=t[sta[i-1]][s[i]-'a'];
        // cout<<i<<" "<<sta[i]<<" "<<flag<<endl;
        if(flag[sta[i]]){
            s.erase(i-flag[sta[i]]+1,flag[sta[i]]);
            len-=flag[sta[i]]; i-=flag[sta[i]];
        }
    }
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>s>>n; s=" "+s;
    for(int i=1;i<=n;++i)
        cin>>c, insert(c);
    build(); query(s);
    s.erase(0,1);
    cout<<s<<endl;
    return 0;
}