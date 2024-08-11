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
const int N = 2e5 + 10;
const int M = 2e6 + 10;
const int MOD = 1e9 + 7;

int n;
char c[M];

int t[N][26], fail[N], de[N], idx, flag[N], ans[N];
int tag[N];

void insert(char c[],int j){
    int len=strlen(c), p=0;
    for(int i=0;i<len;++i){
        if(!t[p][c[i]-'a']) t[p][c[i]-'a']=++idx;
        p=t[p][c[i]-'a'];
    }
    flag[p]++; tag[j]=p;
}

queue<int> q;
void build(){
    for(int i=0;i<26;++i)
        if(t[0][i]) q.push(t[0][i]), ++de[0];
    while(q.size()){
        int p=q.front(); q.pop();
        for(int i=0;i<26;++i)
            if(t[p][i]) fail[t[p][i]]=t[fail[p]][i], q.push(t[p][i]), de[fail[t[p][i]]]++;
            else    t[p][i]=t[fail[p]][i];
    }
}

void topu(){
    while(q.size()) q.pop();
    for(int i=0;i<=idx;++i)
        if(!de[i])   q.push(i);
    while(q.size()){
        int p=q.front(); q.pop();
        ans[fail[p]]+=ans[p];
        if(--de[fail[p]]==0)    q.push(fail[p]);
    }
}

void query(char c[]){
    int len=strlen(c), p=0;
    for(int i=0;i<len;++i){
        p=t[p][c[i]-'a'];
        ++ans[p];
    }
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>c;
        insert(c,i);
    }
    build();
    // for(int i=0;i<=idx;++i)
    //     cout<<i<<" "<<t[i][0]<<" "<<t[i][1]<<" "<<fail[i]<<endl;
    cin>>c;
    query(c); topu();
    for(int i=1;i<=n;++i)
        cout<<ans[tag[i]]<<endl;
    return 0;
}