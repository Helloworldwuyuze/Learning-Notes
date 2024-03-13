#include<cstdio>
#include<algorithm>
using namespace std;
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||'9'<c){
        if(c=='-')f=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x*f;
}
const int N=300+5,M=50000+5;
int n,m,ans=0;
int w[M],l[M],r[M];
bool vis[M],ate[N];
void dfs(int res){
    ans=max(ans,res);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            bool rec[N];
            for(int j=l[i];j<=r[i];j++)
                if(!ate[j])rec[j]=ate[j]=true;
                else rec[j]=false;
            dfs(res+w[i]);
            for(int j=l[i];j<=r[i];j++)
                if(rec[j])ate[j]=false;
            vis[i]=false;
        }
    }
}
int main(){
    freopen("greedy.in","r",stdin);
    freopen("greedy.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)w[i]=read(),l[i]=read(),r[i]=read();
    dfs(0);
    printf("%d\n",ans);
    return 0;
}