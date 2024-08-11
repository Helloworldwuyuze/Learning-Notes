#include<cstdio>
#include<cstring>
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
const int inf=0x3f3f3f3f;
const int N=5e4+5,M=5e4+5;
int n,m;
struct Edge{
    int v,id,next;
}edge[N<<1];
int head[N],cnt=0;
void addedge(int u,int v,int id){
    edge[cnt].v=v;
    edge[cnt].id=id;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
int fa[N],dep[N],g[N][25],fe[N];
void dfs(int u){
    for(int i=1;i<=20;i++)g[u][i]=g[g[u][i-1]][i-1];
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].v,id=edge[i].id;
        if(v==fa[u])continue;
        fe[id]=v;
        g[v][0]=fa[v]=u;
        dep[v]=dep[u]+1;
        dfs(v);
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    for(int i=20;i>=0;i--)if(dep[g[x][i]]>=dep[y])x=g[x][i];
    if(x==y)return x;
    for(int i=20;i>=0;i--)if(g[x][i]!=g[y][i])x=g[x][i],y=g[y][i];
    return fa[x];
}
int ans[N];
int main(){
    freopen("disruption.in","r",stdin);
    freopen("disruption.out","w",stdout);
    memset(head,-1,sizeof(head));
    memset(ans,0x3f,sizeof(ans));
    n=read(),m=read();
    for(int i=1;i<n;i++){
        int u,v;
        u=read(),v=read();
        addedge(u,v,i);
        addedge(v,u,i);
    }
    dep[1]=1;
    dfs(1);
    for(int i=1;i<=m;i++){
        int u,v,w;
        u=read(),v=read(),w=read();
        int x=lca(u,v);
        // fprintf(stderr,"LCA(%d,%d)=%d\n",u,v,x);
        for(int j=u;j!=x;j=fa[j])ans[j]=min(ans[j],w);
        for(int j=v;j!=x;j=fa[j])ans[j]=min(ans[j],w);
    }
    for(int i=1;i<n;i++)printf("%d\n",ans[fe[i]]==inf?-1:ans[fe[i]]);
    return 0;
}