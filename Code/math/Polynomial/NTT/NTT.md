# <center> 快速数论变换 </center>

——将单位根换成原根的快速傅里叶变换

## <center> 原根 </center>

### 阶

> **前置：欧拉公式**
> 
> 对于 $a\in Z,m\in N^*$，若 $\gcd(a,m)=1$，则有
>
> $$a^{\varphi(m) }\equiv 1\pmod{m}$$
> 
> 这其实是对 **费马小定理** 的推广。费马小定理指出了 $m\in \mathcal{P}$ 时的特殊情况，即 $a^{m-1}\equiv1\pmod m$。

由欧拉公式，我们知道对于 $\gcd(a,m)=1$，一定存在 $x$ 使得 $a^x\equiv 1\pmod m$。那么，我们称最小的这个 $x$ 为 $a$ 模 $m$ 的阶，记为 $\delta_m(a)$ 或 $ord_a(m)$。

这阶具有以下几条重要性质：

#### 性质 $1$

$a^1,a^2,a^3,\dots,a^{\delta_m(a)}$ 在 $\bmod m$ 的意义下两两不相等。

> **证明**
> 
> 考虑反证法。若存在 $p,q\le \delta_m(a)$ 使得 $a^p=a^q$，则有：
> 
> $$a^{|p-q|}\equiv 1\pmod m$$
>
> 而这里显然 $|p-q|<\delta_m(a)$，那么 $a$ 在摸 $m$ 下的阶就不是 $\delta_m(a)$ 而是 $|p-q|$ 了。与假设矛盾。

#### 性质 $2$

若 $a^n\equiv 1\pmod m$，则 $\delta_m(a)\mid n$。

> **证明**
> 
> 不妨设 $n=q\times \delta_m(a)+r$，其中 $0\le r<\delta_m(a)$。
> 
> $r>0$ 时，有：
> 
> $$a^r=a^r(a^{\delta_m(a)})^q=a^n\equiv 1\pmod m$$
> 
> 这也与阶的最小性矛盾。

同时，通过证明的过程，我们还发现，若 $a^p\equiv a^q\pmod m$，则必然有 $p\equiv q\pmod {\delta_m(a)}$。

#### 性质 $3$

若 $a,b$ 在模 $m$ 的意义下分别有阶 $\delta_m(a)$ 和 $\delta_m(b)$，则

$$\delta_m(ab)=\delta_m(a)\delta_m(b)$$

的充分必要条件是

$$\gcd(\delta_m(a),\delta_m(b))=1$$

> **证明**
> 
> - 先证明必要性：
> 
> 因为 $\delta_m(a),\delta_m(b)$ 是 $a,b$ 在模 $m$ 意义下的阶，因此
> 
> $$a^{\delta_m(a)}\equiv 1\pmod m$$
>
> 所以：
> 
> $$a^{\operatorname{lcm}(\delta_m(a),\delta_m(b))}\equiv 1\pmod m$$
> 
> 相同地，有
> 
> $$(ab)^{\operatorname{lcm}(\delta_m(a),\delta_m(b))}\equiv 1\pmod m$$
> 
> 根据性质 $2$，不难得到 $\delta_m(ab)\mid \operatorname{lcm}(\delta_m(a),\delta_m(b))$，结合 $\delta_m(ab)=\delta_m(a)\delta_m(b)$ 得到
> 
> $$\delta_m(a)\delta_m(b)\mid \operatorname{lcm}(\delta_m(a),\delta_m(b))$$
> 
> 因此，$\gcd(\delta_m(a),\delta_m(b))=1$。
> 
> - 再证充分性
> 
> 显然，有 $(ab)^{\delta_m(ab)\delta_m(b)}\equiv 1\pmod m$
>
> 又因为：
>
> $$b^{\delta_m(b)}\equiv 1\pmod m$$
> 
> 原式就变成
>
> $$a^{\delta_m(ab)\delta_m(b)}\equiv 1\pmod m$$
>
> 根据性质 $2$，有：
> 
> $$\delta_m(a)\mid \delta_m(ab)\delta_m(b)$$
> 
> 结合 $\gcd(\delta_m(a),\delta_m(b))=1$ 可以得到：
> 
> $$\delta_m(a)\mid \delta_m(ab)$$
> 
> 类似地，我们可以得到 $\delta_m(b)\mid \delta(ab)$，也即：
> 
> $$\delta_m(a)\delta_m(b)\mid\delta(ab)$$
> 
> 但同时，我们有：
> 
> $$(ab)^{\delta_m(ab)}\equiv (a^{\delta_m(a)})^{\delta_m(b)}\times (b^{\delta_m(b)})^{\delta_m(a)}\equiv 1\pmod m$$
> 
> 因此 $\delta_{ab}\mid \delta_m(a)\delta_m(b)$，即：
> 
> $$\delta_m(ab)=\delta_m(a)\delta_m(b)$$

#### 性质 $4$

若 $a$ 在模 $m$ 下有阶 $\delta_m(a)$，则

$$\delta_m(a^k)=\frac{\delta_m(a)}{\gcd(\delta_m(a),k)}$$

这里证明从略。（才不是因为 $\text{oi-wiki}$ 上 $\mathcal{LaTeX}$ 炸了看不清楚呢）

### 原根

说了这么一大堆晦涩难懂的阶的性质（虽然其实也挺好理解），终于可以使用感性理解大法了。（怎么可能是因为我也不理解）

但出于尊重，定义还是要摆上来的：

#### 定义

对于 $m\in Z^*,g\in Z$，若 $\delta_m(g)=\varphi(m)$，则称 $g$ 为 $m$ 的一个原根。

其实通过刚刚对于阶的学习，我们不难发现，一个数模 $m$ 意义下的阶永远小于等于 $\varphi(m)$，这是因为 $a^{\varphi(m)}\equiv 1\pmod m$，而如果有更小的 $n$ 满足 $a^n\equiv 1\pmod m$，那么 $n$ 一定是 $\varphi(m)$ 的因子。而原根，就是所有 $\varphi(m)$ 的因子都不能满足 $a^n\equiv 1\pmod m$ 的特殊情况。因此，直觉告诉我们，原根并不一定存在。

事实也确实如此，这里我们给出判定定理：

#### 判定

若 $\forall p\in \mathcal{P}$ 使得 $p\mid \varphi(m)$ 都有 $a^{\frac{\varphi(m)}{p}}\not = 1\pmod m$，则 $m$ 有原根。

这定理我们不证，大家参考 $\text{oi-wiki}$ 罢（溜。

#### 原根个数

若 $m$ 有原根，那么它有 $\varphi(\varphi(m))$ 个原根。

这里还是很好理解的。若 $a$ 是 $m$ 的一个原根，根据阶的性质 $4$，我们知道若 $\gcd(k,m)=1$，则 $\delta_m(a^k)=\frac{\delta_m(a)}{\gcd(\delta_m(a),k)}=\delta_m(a)=\varphi(m)$，故 $a^k$ 也是 $m$ 的一个原根。而与 $\varphi(m)$ 互质的数一共有 $\varphi(\varphi(m))$ 个，因此不难得到 $m$ 的原根一共有 $\varphi(\varphi(m))$ 个。

## <center> 快速数论变换 </center>

### 原根与单位根

回想为什么我们可以使用单位根加速傅里叶变换，得到了单位根的四条性质：

1. $w_{pn}^{pk}=w_n^k$。
2. $w_n^k$ 对于 $\forall k\in [0,k-1]$ 都互不相同。
3. $w_n^{k+\frac{n}{2}}=-w_{n}^k$。
4. $\sum\limits_{i=0}^{n-1}w_n^i=0$。

因此，我们只需要验证原根也具有类似的性质即可。

例如互异性，我们甚至在阶的性质中就已经证明完毕了。而可除公约数性也是因为原根需要被写成 $g^{\frac{p-1}{n}}$ 的形式。至于剩下的东西，~~我也不会证~~。

总之，我们只需要在快速傅里叶变换的基础之上，把单位根改成原根，就可以大大减少原来的高精度的 `double` 运算，只需要数论中加减乘除取模运算即可。

```cpp
void NTT(int *f,int rev){
	for(int i=0;i<limit;++i)
		if(i<r[i])	swap(f[i], f[r[i]]);
	for(int mid=1;mid<limit;mid<<=1){
		int step=ksm(rev?G:Gi,(MOD-1)/(mid<<1));
		for(int R=mid<<1, j=0;j<limit;j+=R){
			int w=1;
			for(int k=0;k<mid;++k, w=w*step%MOD){
				int x=f[j+k], y=w*f[j+k+mid]%MOD;
				f[j+k]=(x+y)%MOD, f[j+k+mid]=(x-y+MOD)%MOD;
			}
		}
	}
}
```

代码还是很简洁的。
