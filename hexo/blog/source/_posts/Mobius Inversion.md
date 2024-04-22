---
title: 莫比乌斯反演
date: 2024-3-25 15:20:42
tags: 算法笔记
mathjax: true
---

# 莫比乌斯反演

## 引入函数

### 莫比乌斯函数

#### 定义1

$$\mu(x)=\left\{\begin{matrix}1,x=1\\(-1)^k,x=\prod\limits_{i=1}^kp_k\\0,\mathrm{otherwise}\end{matrix}\right.$$

#### 性质1.1

它是一个积性函数，即对于 $p,q$，若 $\gcd(p,q)=1$，则 $\mu(p\times q)=\mu(p)\times \mu(q)$。

> **证明**
>
> 对于 $p=1$ 的情况，显然 $\mu(1\cdot x)=\mu(x)\cdot\mu(1)$
>
> 否则，若 $p,q$ 中有一个数有平方因子，那么整个 $p\cdot q$ 必然有平方因子，故 $\mu(p\cdot q)=\mu(p)*\mu(q)=0$。
>
> 对于一般情况，设 $p=\prod\limits_{i=1}^{k_1}p_i,q=\prod\limits_{i=1}^{k_2}p_i$，那么 $\mu(p)=(-1)^{k_1},\mu(q)=(-1)^{k_2}$，而 $\gcd(p,q)=1$，所以 $p\cdot q=\prod\limits_{i=1}^{k_1+k_2}p_i,mu(p\cdot q)=(-1)^{(k_1+k_2)}=(-1)^{k_1}\cdot (-1)^{k_2}=\mu(p)\cdot \mu(q)$。
>
> 证毕

#### 性质1.2

$$\sum\limits_{d\mid n}\mu(d)=\epsilon(n)$$

这定理也可以写成 $\mu*\operatorname{1}=\epsilon$。其中 $*$ 是狄利克雷卷积。

> 证明
>
> 显然，性质 1.2 等价于：
>
> $$\sum_{d\mid x}\mu(d)=\left\{\begin{matrix}1, x=1\\ 0,\text{otherwise}\end{matrix}\right.$$
>
> 容易证明 $x=1$ 时该命题成立。
>
> 对于 $x\not =1$ 的情况，我们设 $x=\prod_{i=1}^k p_i$。容易想到所有能够产生贡献的因子都是这 $k$ 个因子的不重复组合，因为有平方的因子的莫比乌斯函数值为0。其中，有 $i$ 个质因子的因子有 $\binom{k}{i}$ 个。由此不难看出原式 $=\sum_{i=0}^k (-1)^i\binom{k}{i}$。下面分两种情况讨论：
>
> - $k$ 为偶数。
>
>   根据公式 $\binom{n}{m}=\binom{n-1}{m}+\binom{n-1}{m-1}$，那么原式 $=\binom{k}{0}-\binom{k}{1}+\binom{k}{2}-\cdots+\binom{k}{k}=(\binom{k-1}{0})-(\binom{k-1}{0}+\binom{k-1}{1})+(\binom{k-1}{1}+\binom{k-1}{2})-\cdots-(\binom{k-1}{k-2}+\binom{k-1}{k-1})+(\binom{k-1}{k-1})$.容易看出两两抵消，最后结果为0。
>
> - $k$ 为奇数。
>
>   那么 $i$ 与 $k-i$ 奇偶性不同，而 $\binom{i}{k}=\binom{k-i}{i}$，因此两两抵消，最终结果为0。
>
> 证毕。

### 欧拉函数

#### 定义2

$$\varphi(x)=\sum\limits_{i=1}^x[\gcd(i,x)=1]$$

欧拉函数反映了一个数与小于等于它并且与它互质的数的个数。

#### 性质2.1

它也是个积性函数，这里我们不证。另外，我们可以写出它的通项公式：$\varphi(x)=\prod\limits_{i=1}^k(1-\frac{1}{p_i})$。

> **证明**
>
> 设 $x$ 能够质因数分解为 $x=\prod\limits_{i=1}^{m}p_i^{\alpha_i}$，让 $x$ 减去所有 $p_i$ 的倍数得到 $n-\sum\limits_{i=1}^m\left\lfloor\frac{n}{p_i}\right\rfloor$。但是这并不是最终答案，因为还有 $p_i\times p_{i+1}$ 的倍数被算了两边。没错就是容斥原理。然后最终答案就是 $n+\sum\limits_{i=1}^{m}(-1)^{i}\sum\limits_{j=1}^{k-i+1}\prod\limits_{k=j}^{j+i-1}p_k$。最终因式分解就可以得到原式。
>
> 证毕

其实，写出通项公式和之后已经很容易证明它是积性函数了。

### 因子函数

#### 定义3

$\sigma(x)=\sum\limits_{d\mid n}d$。

它表示了一个数的因子和。

#### 性质3

它也是积性函数。
> **证明**
>
> 设 $\sum\limits_{d\mid p}d=\sum\limits_{i=1}^na_i, \sum\limits_{d\mid q}d=\sum\limits_{i=1}^mb_i$。其中，因为 $\gcd(p,q)=1$，所以 $\{a_n\}$ 中的元素与 $\{b_n\}$ 中的互不相同。那么将 $\{a_n\}$ 与 $\{b_n\}$ 两两组合就可以补充不漏地得到 $p\cdot q$ 的所有因子，即 $\sigma(p\cdot q)=(\sum\limits_{i=1}^na_i)(\sum\limits_{i=1}^mb_i)=\sigma(p)\cdot \sigma(q)$。
>
> 证毕

### 恒等函数

#### 定义4

$$\operatorname{1}(x)=1$$

这个我就不想多说了，其中重要的一点事它是完全积性函数，即对于 $\forall a,b\in \N^*$，都满足 $\operatorname{1}(a\cdot b)=\operatorname{1}(a)\cdot \operatorname{1}(b)$。

### 元函数

#### 定义5

$$\epsilon(x)=[x=1]$$

即这个函数返回 $x$ 是否为 $1$。显然，它也是完全积性函数。

#### 性质5

对于任意函数 $f(x)$，它与 $\epsilon$ 的狄利克雷卷积 $f*\epsilon=f$。这个请读着自证。

### 单位函数

#### 定义6

$$\operatorname{Id}(x)=x$$

它返回的是自变量本身。同样，它是完全积性函数。

## 狄利克雷卷积

我们定义：两个函数 $f(x),g(x)$ 间的运算 $\sum\limits_{d|n}f(n)\cdot g(\frac{n}{d})$ 计为 $(f*g)(x)$，称为狄利克雷卷积。它满足交换律、结合律和对加法的分配率。

## 结论及证明

若函数 $F(x)=\sum\limits_{d\mid x}f(d)$，则 $f(x)=\sum\limits_{d\mid x}\mu(d)F(\frac{x}{d})$ 或 $f(x)=\sum\limits_{d\mid x}\mu(\frac{x}{d})F(d)$。这定理又可以写成设 $F=f*\operatorname{1}$，则 $f=F*\mu$。

> **证明**
>
> 由 $\mu*\operatorname{1}=\epsilon$ 和 $F=f*\operatorname{1}$ 进行推导。
>
> 由 $F=f*\operatorname{1}$ 可得 $F*\mu=f*\operatorname{1}*\mu$，再由 $\mu * 1=\epsilon$ 可得 $F*\mu=f*\epsilon=f$。
>
> 即 $F*\mu=f$。
>
> 证毕

由此可以推导出两条重要结论：

1. $\epsilon(n)=\sum\limits_{d\mid n}\mu(d)$，也就是 $\epsilon=\mu*\operatorname{1}$。
2. $n=\sum\limits_{d\mid n}\varphi(d)$，也即 $\operatorname{Id}=\varphi*\operatorname{1}$，或 $\mu*\operatorname{Id}=\varphi$。

第一条我们在补充函数- $\mu$ 函数中已经证明，下面给出第二条的证明。

> **证明**
>
> 由欧拉函数的定义得到 $\varphi(n)=\sum\limits_{i=1}^n[\gcd(i,n)=1]=\sum\limits_{i=1}^n\epsilon(\gcd(i,n))$，由第一条得到原式 $=\sum\limits_{i=1}^n\sum\limits_{d\mid i,d\mid n}\mu(d)$，改变求和顺序，能够得到原式 $=\sum\limits_{d\mid n} \mu(d)\sum\limits_{d\mid i} 1=\sum\limits_{d\mid n}\mu(d)\frac{n}{d}=\sum\limits_{d\mid n}\mu(d)\operatorname{Id}(\frac{n}{d})$，然后反过来就得到 $\operatorname{Id}=\varphi*\operatorname{1}$。
>
> 证毕

## 小技巧：整除分块

### 求：$\sum\limits_{i=1}^n\left\lfloor\frac{n}{i}\right\rfloor$

我们注意到：$\left\lfloor\frac{n}{i}\right\rfloor$ 的取值至多只有 $O(\sqrt n)$ 的数量级，因此我们只需要知道每个取值有多少个 $i$ 能够取到就可以在 $O(\sqrt{n})$ 内求出这个值。如何快速求出有多少个 $i$ 能取到呢？下面给出定理：

定理：$\frac{n}{i}$ 的取值中能够取到最大的 $i$ 是 $\left\lfloor\frac{n}{\left\lfloor\frac{n}{i}\right\rfloor}\right\rfloor$。

下面给出证明：

> - 充分性：设 $j=\left\lfloor\frac{n}{\left\lfloor\frac{n}{i}\right\rfloor}\right\rfloor$，那么显然有 $\left\lfloor\frac{n}{j}\right\rfloor=\left\lfloor\frac{n}{\left\lfloor\frac{n}{\left\lfloor\frac{n}{i}\right\rfloor}\right\rfloor}\right\rfloor=\left\lfloor\frac{n}{i}\right\rfloor$
>
> - 必要性：因为 $\left\lfloor\frac{n}{i}\right\rfloor=\left\lfloor\frac{n}{j}\right\rfloor$，所以 $\left\lfloor\frac{n}{j}\right\rfloor\ge\left\lfloor\frac{n}{i}\right\rfloor$，即 $\frac{n}{j}\ge\left\lfloor\frac{n}{i}\right\rfloor$。
>
>   两边同取倒数，得到 $\frac{j}{n}\le\frac{1}{\left\lfloor\frac{n}{i}\right\rfloor}$,最后同乘以 $n$ 得到 $j\le \left\lfloor\frac{n}{\left\lfloor\frac{n}{i}\right\rfloor}\right\rfloor$。
>
> 证毕。

### 进阶：求 $\sum i\cdot\left\lfloor\frac{n}{i}\right\rfloor$

我们拆分一下，把所有结果一致的 $i$ 提出来，能够得到原式 $=\sum\limits_{k=i}^j k\times \left\lfloor\frac{n}{k}\right\rfloor$，其中 $i,j$ 满足 $\left\lfloor\frac{n}{i}\right\rfloor=\left\lfloor\frac{n}{j}\right\rfloor$，且 $i,j$ 分别是这个取值区间的左右端点。因此 $\Leftrightarrow\left\lfloor\frac{n}{i}\right\rfloor\sum\limits_{k=i}^j k=\left\lfloor\frac{n}{i}\right\rfloor\cdot\frac{(i+j)(j-i+1)}{2}$。

由此不难看出对于求 $\sum\limits_{i=1}^nf(i)\times \left\lfloor\frac{n}{i}\right\rfloor$ 的问题，可以直接将 $\frac{n}{i}$ 相等的 $i$ 取值写成 $\frac{n}{i}\times (s_j-s_{i-1})$，其中 $s_n=\sum\limits_{i=1}^nf(i)$。

## 线性筛法求 $\mu$ 函数

性质2：$\mu(x\cdot p)=-\mu(x)$，其中 $p$ 为素数且 $p\not\ \mid x$。

这个定理读者自证即可。

由此，这性质很适配线性筛。在 ```i%p[j]==0``` 时令 ```mu[i*p[j]]=0``` 即可，因为至少含有一个完全平方因子 $p^2$。再其它时候都有 ```i%p[j]!=0```，应用性质 2 不难得出 ```mu[i*p[j]]=-mu[i]```。

下面看几道例题：

## 例题

### 例1

求 $\sum\limits_{i=1}^n\sum\limits_{j=1}^m[\gcd(i,j)=1]$。

### Solution 1

容易看出 $[\gcd(i,j)=1]\Leftrightarrow \epsilon(\gcd(i,j))$，又根据 $\epsilon=\mu *1$ 不难得到 $\epsilon(\gcd(i,j))\Leftrightarrow \sum\limits_{d\mid \gcd(i,j)}\mu(d)\Leftrightarrow \sum\limits_{d\mid i,d\mid j}\mu(d)$。因此原式可以写成

$$\sum\limits_{i=1}^n\sum\limits_{j=1}^m\sum\limits_{d\mid i,d\mid j}\mu(d)$$

我们改变枚举顺序首先枚举 $d$ 就能够得到

$$\sum\limits_{d=1}^{\min(n,m)}\mu(d)\sum\limits_{d\mid i}^n\sum\limits_{d\mid j}^m1=\sum\limits_{d=1}^{\min(n,m)}\mu(d)\left\lfloor\frac{n}{d}\right\rfloor\left\lfloor\frac{m}{d}\right\rfloor$$

于是 $O(\sqrt n)$ 内即可完成一次询问。

### 例2

求 $\sum\limits_{i=1}^n\sum\limits_{j=1}^m[\gcd(i,j)=k]$

### Solution2

这里先把 $k$ 提出得到

$$\sum\limits_{i=1}^{\left\lfloor\frac{n}{k}\right\rfloor}\sum\limits_{j=1}^{\left\lfloor\frac{m}{k}\right\rfloor}[\gcd(i,j)=1]$$

然后按照例 1 就可以得到答案。

### 例3

设素数集合为 $\mathcal{P}$，求 $\sum\limits_{k\in \mathcal{P}}\sum\limits_{i=1}^n\sum\limits_{j=1}^m[\gcd(i,j)=k]$

### Solution3

首先按照例 2 把二三层求和化简成

$$\sum\limits_{k\in \mathcal{P}}\sum\limits_{d=1}^{\min(\left\lfloor\frac{n}{k}\right\rfloor,\left\lfloor\frac{m}{k}\right\rfloor)}\mu(d)\left\lfloor\frac{n}{k\times d}\right\rfloor\left\lfloor\frac{m}{k\times d}\right\rfloor$$

然后有一个常用的小技巧，我们枚举 $T=k\times d$，得到

$$\sum\limits_{T=1}^{\min(n,m)}\left\lfloor\frac{n}{T}\right\rfloor\left\lfloor\frac{m}{T}\right\rfloor\sum\limits_{k\in \mathcal{P},k\mid T}\mu(\frac{T}{k})$$

注意到最后一个求和是可以预处理的，它只与一个变量 $T$ 有关，我们枚举 $k\in \mathcal{P}$ 然后给它的 $i$ 倍加上 $\mu(i)$ 即可。

### 例4

求 $\sum\limits_{i=1}^n\sum\limits_{j=1}^md(ij)$，其中 $d(x)=\sum\limits_{d\mid x}1$。

### Solution4

首先摆出公式 $d(i,j)=\sum\limits_{x\mid i}\sum\limits_{y\mid j}[\gcd(x,y)=1]$。

于是式子就变成了

$$\sum\limits_{i=1}^n\sum\limits_{j=1}^m\sum\limits_{x\mid i}\sum\limits_{y\mid j}[\gcd(x,y)=1]$$

先枚举 $x,y$ 得到

$$\sum\limits_{x=1}^n\sum\limits_{y=1}^m\left\lfloor\frac{n}{x}\right\rfloor\left\lfloor\frac{m}{y}\right\rfloor\epsilon(\gcd(x,y))$$

按习惯改写 $x,y$ 为 $i,j$，然后把 $\epsilon$ 莫比乌斯反演，得到：

$$\sum\limits_{i=1}^n\sum\limits_{j=1}^m\left\lfloor\frac{n}{i}\right\rfloor\left\lfloor\frac{m}{j}\right\rfloor\sum\limits_{d\mid i,d\mid j}\mu(d)$$

改而枚举 $d$ 得到

$$\sum\limits_{d=1}^{\min(n,m)}\mu(d)\sum\limits_{i=1}^{\left\lfloor\frac{n}{d}\right\rfloor}\sum\limits_{j=1}^{\left\lfloor\frac{m}{d}\right\rfloor}\left\lfloor\frac{n}{i}\right\rfloor\left\lfloor\frac{m}{j}\right\rfloor=\sum\limits_{d=1}^{\min(n,m)}\mu(d)(\sum\limits_{i=1}^{\left\lfloor\frac{n}{d}\right\rfloor}\left\lfloor\frac{n}{i}\right\rfloor)(\sum\limits_{j=1}^{\left\lfloor\frac{m}{d}\right\rfloor}\left\lfloor\frac{m}{j}\right\rfloor)$$

最后套上整除分治就可以在 $O(T\times \sqrt N)$ 内得到答案。

关于 $d(ij)=\sum\limits_{x\mid i}\sum\limits_{y\mid j}[\gcd(i,j)=1]$ 的证明：

> **证明**
>
> 我们考虑对 $ij$ 的每一个因子进行唯一映射，即构建自变量为 $ij$ 的因子的函数。显然，如果一个因子包含 $p^{\alpha_1}$，而 $i$ 中含有 $p^{\alpha_2}$，$j$ 中含有 $p^{\alpha_3}$，那么当 $\alpha_2>\alpha_1$ 时，我们规定用所有的 $i$ 中的 $p$，否则规定用 $\alpha_1-\alpha_2$ 个 $j$ 的 $p$，这样分别计为 $i_{\alpha_2}$ 和 $j_{\alpha_1-\alpha_2}$，因此 $i$ 与 $j$ 不会同时出现一个因子，即枚举到的两个因子互质。
>
> 证毕。
