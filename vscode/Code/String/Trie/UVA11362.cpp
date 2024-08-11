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
typedef pair<int,bool> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

int t,n;
string s[N];

struct Trie{
    int son[N][10],idx;
    int flag[N];
    void insert(string s){
        int p=0, len=s.size();
        for(int i=0;i<len;++i){
            if(!son[p][s[i]-'0']) son[p][s[i]-'0']=++idx;
            p=son[p][s[i]-'0'];
        }
        flag[p]++;
    }
    bool query(string s){
        int p=0, len=s.size();
        for(int i=0;i<len-1;++i){
            p=son[p][s[i]-'0'];
            if(flag[p]) return true;
        }
        p=son[p][s[len-1]-'0'];
        if(flag[p]>1)   return true;
        else    return false;
    }
}tree;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<=N-10;++i){
            for(int j=0;j<10;++j)   tree.son[i][j]=0;
            tree.flag[i]=0;
        }
        tree.idx=0;
        bool flag=false;
        for(int i=1;i<=n;++i){
            cin>>s[i];
            tree.insert(s[i]);
        }
        for(int i=1;i<=n;++i)
            flag|=tree.query(s[i]);
        if(flag)    cout<<"NO"<<endl;
        else    cout<<"YES"<<endl;
    }
    return 0;
}