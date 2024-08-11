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
const int N = 1e6 + 2e2 + 10;
const int M = 2e6 + 10;
const int MOD = 1e9 + 7;

int n;
string s,c;

namespace AC{
    int t[N][27], idx, flag[N], fail[N], ans[N], de[N], rk[N];
    void insert(string c,int j){
        int len=c.size(), p=0;
        for(int i=0;i<len;++i)
            p=t[p][c[i]-'a']?t[p][c[i]-'a']:(t[p][c[i]-'a']=++idx);
        flag[p]++; rk[j]=p;
    }
    queue<int> q;
    void build(){
        for(int i=0;i<26;++i)
            if(t[0][i]) q.push(t[0][i]);
        while(q.size()){
            int p=q.front(); q.pop();
            for(int i=0;i<26;++i)
                if(t[p][i]) fail[t[p][i]]=t[fail[p]][i], q.push(t[p][i]), de[fail[t[p][i]]]++;
                else    t[p][i]=t[fail[p]][i];
        }
    }
    void query(string s){
        int len=s.size(), p=0;
        for(int i=0;i<len;++i){
            p=t[p][s[i]-'a'];
            // cout<<p<<" "<<flag[p]<<" "<<flag[fail[p]]<<endl;
            ans[p]++;
        }
        for(int i=0;i<=idx;++i)
            if(!de[i])  q.push(i);
        while(q.size()){
            int p=q.front(); q.pop();
            ans[fail[p]]+=ans[p];
            if(--de[fail[p]]==0)    q.push(fail[p]);
        }
    }
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>c, AC::insert(c,i), s=s+c+"{";
    AC::build();
    AC::query(s);
    // for(int i=0;i<=AC::idx;++i)
    //     cout<<AC::fail[i]<<" ";
    // cout<<endl;
    // for(int i=0;i<=AC::idx;++i)
    //     cout<<AC::ans[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;++i)
        cout<<AC::ans[AC::rk[i]]<<endl;
    return 0;
}