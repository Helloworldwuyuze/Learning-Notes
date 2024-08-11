# Tarjan 算法

## 强联通分量 （SCC）

**强联通分量（SCC）**，表示有向图中一段能够两两互相到达的极大子图。

### Tarjan 求强联通分量

在使用 $DFS$ 遍历一张有向图时，会产生四种边：

- **树边（Tree Edge）**，表示在进行搜索时走过的边。
- **返祖边（Back Edge）**，表示在搜索到一个点时走到还在栈中的节点的边。
- **横边（Cross Edge）**，表示在一个节点到达另一个不在栈中的节点的边。
- **前向边（Forward Edge）**，表示在祖先到它的二三及更高级儿子的边。

如下图：

![](D:\vscode\graph\Tarjan1.png)

经过 $\text{Tarjan}$ 算法之后，我们能够得到四种不同的边：

![](D:/vscode/graph/Tarjan2.png)

青绿色的边就是树边，橙色的边是横边，黄色的边是返祖边，而紫色的边是前向边。

而在这里，我们根据 $\text{DFS}$ 的顺序，定义两个数组 $dfn$ 和 $low$。

- $dfn$ ：即时间戳，表示遍历到 $x$ 节点的时间。
- $low$ ：它的定义需要着重强调。在无向图求 $\text{SCC}$ 的算法中，它定义为在 $x$ 的子树内，只经过一条非树边所能够到达的最小时间戳，并且要求拥有该时间戳的点在遍历到时是在 $\text{DFS}$ 的栈内的。

例如上图，假设枚举顺序是 $1,2,3,4,6,5$，那么我们模拟处理过程：

1. 进入 $1$ 号节点。
2. 1. 进入 $2$ 号节点。发现无出边，此时 $low_2 = dfn_2 = 2$，此时 $2$ 出栈。
3. 1. 进入 $4$ 号节点，然后进入六号节点，发现有一条返祖边 $6\to 3$，这是一条非树边，并且在此之前并没有经历过任何一条非树边。因此，将 $low_6$ 更新为 $dfn_3$，也就是 $low_6=3$。
   2. 进入 $5$ 号节点，发现没有任何出边，此时 $low_5=dfn_5=6$，$5$ 号节点出栈。
   3. 在 $6$ 号节点回溯的时候，我们发现 $6$ 号节点的 $low$ 比 $3$ 的低，并且 $3\to 6$ 是一条树边，因此我们可以使用 $low_6$ 来更新 $low_3$。
   4. 随后发现一条横向边 $3\to 2$。但是注意，这里 $2$ 号节点已经出栈，因此我们无法更新 $low_3$。于是此时 $low_3 = dfn_3 = 3$，将 $3$ 子树内在栈内的出栈。
4. 随后回溯到 $1$，发现一条前向边 $1\to 6$。不在栈内，因此不更新。此时 $low_1 = dfn_1 = 1$。因此将 $1$ 出栈。

不难发现，我们在 $low_x=dfn_x$ 时将 $x$ 子树内的节点都出栈，这是因为我们无法通过树边到达更前面的节点，也就是 $x$ 的子树是一个相对 **隔离** 的状态。因此还在栈内的 $x$ 子树内的节点就都和 $x$ 属于一个强联通分量，弹出即可。

由此不难得出 $\text{Tarjan}$ 求 $\text{SCC}$ 代码：

``````cpp
int dfn[N], low[N], idx, cnt, belong[N], st[N], top;
vector<int> scc[N];
bool inst[N];

void Tarjan(int x){
    dfn[x] = low[x] = ++idx;
    st[++top] = x, inst[x] = true;
    for(int y:g[x])
        if(!dfn[y])	Tarjan(y), low[x] = min(low[x], low[y]);
    	else if(inst[y])	low[x] = min(low[x], dfn[y]);
    if(low[x] == dfn[x]){
        ++cnt;
        while(st[top+1] != x)	scc[cnt].pb(st[top]), belong[st[top]] = cnt, inst[st[top--]] = false;
    }
}
``````

### 强联通分量的应用

在处理某些有向图的问题的时候，我们通常希望它们没有环，并且这些环单独考虑的话不难处理。这个时候我们就可以使用 $Tarjan$ 把强联通分量都处理出来，并且一个强联通分量设成一个点重新建图，这个时候整张图就变成了一个 **有向无环图（DAG）**，那么对于一张 $\text{DAG}$，我们就有许多手段进行处理，例如拓扑排序或者动态规划等等。

#### [稳定婚姻]([P1407 [国家集训队\] 稳定婚姻 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1407))

这道题给定一个 $2n$ 个点的二分图，其中有关系 $(i,i+n)$，另外有某些额外关系 $(x,y)$。求对于每一条 $(i,i+n)$ 删掉之后是否还能够达成二分图完美匹配。

首先，我们称 $i\le n$ 的点为左边的点，而 $i>n$ 的点为右边的点。

这道题的边是无向的，我们考虑什么时候删掉一条边还可以匹配。显然，如果当 $(i,i+n)$ 失配，$i$ 可以找到另一个右边的点进行匹配，而该点的配偶也可以继续寻找新的右边的点进行配偶，直到有一个左边的点在失去原先的配偶之后找到了 $i+n$ 进行匹配，这个时候就完成了完美匹配。在这个过程中，我们发现了一个环。因此，我们大胆猜测，删去一条边之后能够完成完美匹配当且仅当该边处于一个环中。这很好证明，必要性上述已经证明了，充分性再倒推一遍即可。

但是我们怎么找环呢？因为这是二分图，而且已经明确有关系 $i\to i+n$，于是我们把图改为有向图，令 $i\to i+n$，而对于其他关系，我们令右边的点指向左边的点，这样构成一个环就相当于构成一个强联通分量。故我们直接跑 $\text{Tarjan}$，然后判断 $(i,i+n)$ 是否处于一个强联通分量即可。






