# 一般情况

对于树上 DP，要求求以每一个节点为根的树内的 $dp$ 值，这类问题我们可以用换根 DP 完成。一般地，我们总是用 $f_{fa}$ 来更新 $f_u$，可以写成

$$f_u=f_{fa}+val(u,fa)$$

的形式。

其中，最重要的是找到由父亲转移到儿子会产生那些贡献和算重的贡献，将贡献加上，多余的减掉，一般就可以在 $O(n)$ 内求出所有的贡献。流程一般包括两遍 `dfs`，第一遍统计以 $u$ 为根节点的子树内的答案，第二遍由 $1$ 号节点开始进行换根。

# 典例分析

## P3047 [USACO12FEB] Nearby Cows G

### Description

给定一棵树，没给点有权值 $a_i$，对于每个点 $u$，求：

$$\sum\limits_{\operatorname{dis}(u,v)\le k}a_k$$

### Solution

观察 $n$ 的数据范围是 $10^5$，考虑换根DP。

首先设状态，因为注意到 $k$ 仅有20，我们可以设 $f_{i,j}$ 表示以 $i$ 为根节点的子树内与它距离为 $j$ 的点的权值和。

首先第一遍 `dfs` 求出来再子树内的答案，然后考虑转移。

对于一个数 $v$，若 $fa_v=u$，则它的父亲周围与它距离不超过 $k-1$ 的点它显然能够到达，其中不要忘记这里面还包含它子树内的与它距离小于等于 $k-2$ 的点。然后再加上它的子树内距离它 $k-1$ 和 $k$ 的点即可。

```cpp
vector<int> g[N];
int n,k,c[N],siz[N],f[N][26],fa[N],dep[N],dp[N][26];

void dfs1(int x,int fat){
    fa[x]=fat; dep[x]=dep[fat]+1; siz[x]=1;
    for(int i=0, xx=x;i<=k&&xx;++i, xx=fa[xx])
        f[xx][dep[x]-dep[xx]]+=c[x];
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(y==fat)  continue;
        dfs1(y,x);
        siz[x]+=siz[y];
    }
}
void dfs2(int x){
    dp[x][0]=c[x]; dp[x][1]=f[x][1]+c[fa[x]]+c[x]*(x!=1);
    if(x!=1)    for(int i=2;i<=k;++i)   dp[x][i]=dp[fa[x]][i-1]+f[x][i]+f[x][i-1];
    else    for(int i=2;i<=k;++i)   dp[x][i]=f[x][i];
    if(x==1)    for(int i=1;i<=k;++i)   dp[x][i]+=dp[x][i-1];
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(y==fa[x])    continue;
        dfs2(y);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>k;
    for(int i=1,x,y;i<n;++i)    cin>>x>>y, g[x].pb(y), g[y].pb(x);
    for(int i=1;i<=n;++i)   cin>>c[i];
    dfs1(1,0);
    dfs2(1);
    for(int i=1;i<=n;++i)   cout<<dp[i][k]<<endl;
    return 0;
}
```
