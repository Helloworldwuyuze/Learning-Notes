#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<bitset>

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
const int N = 5e4 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

int n;
string s[N];

int ch[N*20][26], idx, maxlen;
int ans[N*20], tot;
bitset<N*20> flag;
bitset<N*20> tag;
void insert(string s,bool f){
    int len=s.size(), p=0;
    for(int i=0;i<len;++i){
        if(!ch[p][s[i]-'a'])    ch[p][s[i]-'a']=++idx;
        p=ch[p][s[i]-'a'];
        if(f)   tag[p]=f;
    }
    flag[p]=true;
}
void solve(int x){
    // cout<<"###"<<x<<"###"<<endl;
    if(flag[x]) ans[++tot]=-1;
    for(int i=0;i<26;++i){
        if(!ch[x][i]||tag[ch[x][i]])   continue;
        // cout<<(char)(i+'a')<<" ";
        ans[++tot]=i;
        solve(ch[x][i]);
    }
    // cout<<endl;
    for(int i=0;i<26;++i)
        if(tag[ch[x][i]]&&ch[x][i])   ans[++tot]=i, solve(ch[x][i]);
    ans[++tot]=-2;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>s[i];
        int len=s[i].size();
        maxlen=max(maxlen,len);
    }
    bool flag=false;
    // cout<<maxlen<<endl;
    for(int i=1;i<=n;++i){
        int len=s[i].size();
        if(maxlen==len&&!flag){
            insert(s[i],true);
            flag=true;
        }else   insert(s[i],false);
    }
    solve(0);
    cout<<tot-maxlen-1<<endl;
    for(int i=1;i<=tot-maxlen-1;++i)
        if(ans[i]==-1)  cout<<"P"<<endl;
        else if(ans[i]==-2) cout<<"-"<<endl;
        else    cout<<(char)(ans[i]+'a')<<endl;
    return 0;
}