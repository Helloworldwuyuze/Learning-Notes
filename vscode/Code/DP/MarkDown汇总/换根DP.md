# 一般情况

对于树上 DP，要求求以每一个节点为根的树内的 $dp$ 值，这类问题我们可以用换根 DP 完成。一般地，我们总是用 $f_{fa}$ 来更新 $f_u$，可以写成

$$
f_u=f_{fa}+val(u,fa)
$$

的形式。

其中，最重要的是找到由父亲转移到儿子会产生那些贡献和算重的贡献，将贡献加上，多余的减掉，一般就可以在 $O(n)$ 内求出所有的贡献。流程一般包括两遍 `dfs`，第一遍统计以 $u$ 为根节点的子树内的答案，第二遍由 $1$ 号节点开始进行换根。

# 典例分析

## P3047 [USACO12FEB] Nearby Cows G

### Description

给定一棵树，没给点有权值 $a_i$，对于每个点 $u$，求：

$$
\sum\limits_{\operatorname{dis}(u,v)\le k}a_k
$$

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

## P3647 [APIO2014] 连珠线

### Description

有一种游戏，能支持两种操作

1. `Append(u,v)` 在 $u$ 后面拉一根红线到 $v$
2. `Insert(u,v,w)` 在 $(u,v)$ 之间去掉红线变成蓝线

现在给定最终树的形态，求最大的可能的蓝线权值和。

### Solution

首先树上问题，容易想到树形 DP，我们设 $f_{u,0/1}$ 表示 $u$ 节点 是/不是 一根蓝线的中点所产生的贡献。

对于 $f_{u,0}$，很容易想到它与 $v$ 可以是红线也可以是蓝线，如果是红线贡献就是 $f_{v,0}$，否则 $v$ 就是蓝线中点，贡献就是 $f_{v,1}+\operatorname{dis}(u,v)$，于是不难得到转移方程：

$$f_{u,0}=\sum\limits_{v\in son_u}\max\{f_{v,0},f_{v,1}+\operatorname{dis}(u,v)\}$$

对于 $f_{u,1}$，因为它只能和它的父亲以及 **一个** 儿子形成蓝线，因此枚举这个儿子 $v$，不难得到：

$$f_{u,1}=\sum_{v\in son_u,v\not =V}\max\{f_{v,0},f_{v,1}+\operatorname{dis}(u,v)\}+f_{V,0}+\operatorname{dis}(u,V)$$

我们完全可以将 $f_{u,1}$ 先设成 $f_{u,0}$，然后算的时候减掉：

$$f_{u,1}=f_{u,0}+\sum_{v\in son_u}\max\{f_{v,0}+\operatorname{dis}(u,v)-\max\{f_{v,0},f_{v,1}+\operatorname{dis}(u,v)\}\}$$

（好恶心的柿子）QAQ。

但是我们忽略了一种情况，就是一个父亲节点和它的两个儿子构成蓝线的贡献，于是想到换根。

考虑从一个父亲转移到一个儿子，首先需要减掉自己做儿子的贡献，同时加上父亲作为儿子的贡献。

首先考虑如何减掉自己的贡献。我们计数组 $dp_{u,0/1,v}$ 表示以 $u$ 为根节点的子树，是/不是蓝线中点，而且不考虑儿子 $v$ 的答案。对于 $0$ 的情况，我们直接减掉 $\max\{f_{v,0},f_{v,1}+\operatorname{dis}(u,v)\}$ 即可，但对于 $1$ 的情况，我们就需要额外记录一个次大值来维护这个值。

对于自己父亲的贡献，可以看做多加了一个儿子，即

$$f_{u,0}=dp_{u,0,v}+\max\{f_{fa,0},f_{fa,1}+\operatorname{dis}(fa,u)\}$$

$$f_{u,1}=dp_{u,1,v}+\max\{mx_{u,v},f_{fa,0}+\operatorname{dis}(fa,u)-\max\{f_{fa,0},f_{fa,1}+\operatorname{dis}(fa,u)\}\}$$

其中 $mx_{u,v}$ 表示去掉 $v$ 之后 $u$ 子树的权值和。

```cpp
void dfs1(int x,int fat){
    f[x][0]=0, f[x][1]=-INF;
    int maxx1=-INF,maxx2=-INF;
    for(int i=head[x];~i;i=Next[i]){
        int y=ver[i], z=w[i];
        if(y==fat)   continue;

        son[x].pb(y);
        fa[y]=x, len[y]=z; 
        dfs1(y,x);
        f[x][0]+=max(f[y][0],f[y][1]+z);
        if(tran(y)>maxx1)   maxx2=maxx1, maxx1=tran(y);
        else if(tran(y)>maxx2)  maxx2=tran(y);
    }
    f[x][1]=f[x][0]+maxx1;
    for(int i=head[x];~i;i=Next[i]){
        int y=ver[i], z=w[i];
        if(y==fat)    continue;

        dp[x][0].pb(f[x][0]-max(f[y][0],f[y][1]+z));
        if(tran(y)==maxx1)  dp[x][1].pb(dp[x][0].back()+maxx2), mx[x].pb(maxx2);
        else    dp[x][1].pb(dp[x][0].back()+maxx1), mx[x].pb(maxx1);
    }
}

void dfs2(int x){
    for(int i=0;i<son[x].size();++i){
        int y=son[x][i], z=len[y];
        f[x][0]=dp[x][0][i], f[x][1]=dp[x][1][i];
        if(fa[x]){
           f[x][0]+=max(f[fa[x]][0],f[fa[x]][1]+len[x]);
           f[x][1]=f[x][0]+max(mx[x][i],f[fa[x]][0]+len[x]-max(f[fa[x]][0],f[fa[x]][1]+len[x]));
        }
        ans=max(ans,f[y][0]+max(f[x][0],f[x][1]+z));
        dfs2(y);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    memset(head,-1,sizeof(head));
    cin>>n;
    for(int i=1,x,y,z;i<n;++i)  cin>>x>>y>>z, add(x,y,z), add(y,x,z);
    dfs1(1,0); dfs2(1);
    cout<<ans<<endl;
    return 0;
}
```