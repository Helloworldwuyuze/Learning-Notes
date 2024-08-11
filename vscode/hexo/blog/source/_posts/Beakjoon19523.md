---
title: Beakjoon19523 Sol
date: 2024-8-11 21:46:21
tags: 题解笔记
mathjax: true
---

# Beakjoon19523

## Des

给定一个 $h\times w$ 的矩阵，初始你处在 $(0,0)$ 的地方，每次你可以进行两个操作：

- $(x,y)\to ((x+1)\bmod h,y)$
- $(x,y)\to (x,(y+1)\bmod w)$

现在需要你求出对于每个点分配一个方向，求出其中有多少种是可以从 $(0,0)$ 经过所有的点恰好一次走回 $(0,0)$。

## Sol

于是，我们现在考虑，如果某个点 $(x,y)$ 确定了一定往下走，那么是不是对于点 $(x+1, y-1)$ 和 $(x-1, y+1)$ 也都确定了是往下走的。这是因为我们知道 $(x,y)\to (x,y+1)$，那么 $(x+1,y)$ 就只能通过 $(x+1,y-1)$ 走到。

继续把这个推广下去，我们会发现，对于任意的 $(x,y)$，只要与它处于一条对角线上，都会和它方向相同。而这里，对角线的概念有所不同，这里我们定义只要满足：

$$
\begin{cases}x+d\equiv x\pmod{h}\\y-d\equiv y\pmod w\end{cases}
$$

这就等价于：

$$
\begin{cases}d\equiv 0\pmod h\\d\equiv 0\pmod w\end{cases}\Leftrightarrow \begin{cases}h\mid d\\w\mid d\end{cases}
$$

也就是说，这里 $d$ 存在最小正整数解，且这个解等于 $\operatorname{lcm}(h,w)$。这就表明，每个对角线的长度都是 $\operatorname{lcm}(h,w)$ 的，而显然，一个点只会属于一条对角线，这是因为对角线的不同等价于点 $(x,y)$ 的坐标和 $x+y$ 在模意义下的不同。因此，就一共有 $\frac{h\times w}{\operatorname{lcm}(h,w)}=\gcd(h,w)$ 的不同。

这样，我们就知道了，对于一个矩阵 $h\times w$，我们可以选择的地方一共有 $2^{\gcd(h,w)}$ 种。现在我们考虑怎么做是合法的。

首先，需要注意的是，我们有操作 $(x,y)\to(x+1, y)$ 和 $(x,y)\to (x,y+1)$ 这两种操作，除了 $g=1$（下面记 $g=\gcd(h,w)$）的情况，$x+y\pmod g$ 一定不等于 $x+y+1\pmod g$。也就是说，我们走一步一定从一条对角线走到另一条对角线。那么，我们假设 $(0,0)$ 处在对角线 $1$，那么它一定是经过对角线 $2,3,\dots, g$ 直到返回 $1$。于是，如果我们设这 $g$ 条对角线有 $k$ 条是往下的，那么往右的有 $g-k$ 条，且如果能从 $(x, y)$ 够走回 $(x,y)$，一定有式子：

$$
\begin{aligned}x+d\times k&\equiv x\pmod h\\y+d\times(g-k)&\equiv y\pmod w\end{aligned}
$$

将 $(0,0)$ 带入或直接化简，有：

$$
\begin{aligned}d\times k&\equiv 0\pmod h\\d\times(g-k)&\equiv0\pmod w\end{aligned}
$$

对于这个同余方程，其实就是：

$$
\begin{aligned}h&\mid d\times k\\w&\mid d\times(g-k)\end{aligned}
$$

显然可以看出有一组解：

$$
d=\operatorname{lcm}(\frac{h}{\gcd(h,k)},\frac{w}{\gcd(w,g-k)})
$$

显然，因为对角线一共有 $g$ 条，我们要经过所有的及诶单，一定有轮数 $d=\operatorname{lcm}(h,w)$。也即我们上面求出的 $d$ 如果与最小公倍数相等就可以加入贡献否则就不能，而贡献也很简单，就是：

$$
\sum_{i=0}^g [d=\operatorname{lcm}(h,w)]\times \binom{g}{k}
$$

于是这场酣畅淋漓的解体盛宴就完成了！！！
