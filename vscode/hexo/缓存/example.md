---
title: 小波的 KaTeX 联系
date: 2024-7-1 21:30:21
tags: Markdown 练习
mathjax: true
---

$$
\textbf{\KaTeX 入门}\kern{22em}\text{Copied By Helloworldwuyuze}
\\
\boxed{
\color{#FFFFFF}\rule{40em}{67em}}\color{black}
\mathllap{\raisebox{65.5em}{\text{先假设你有一个简单的公式。}\kern{26.5em}}}
\mathllap{\raisebox{62em}{$f(x)=\begin{cases}f(x-1)+f(x-2)&x\ge 2\\1&\text{Otherwise}\end{cases}$\kern{21em}}}
\mathllap{\raisebox{60em}{假设现在有人又给了一个公式。}\kern{25.5em}}
\mathllap{\raisebox{57.5em}{$g(x)=\begin{cases}g(x-1)+f(x)&x\ge 2\\1&\text{Otherwise}\end{cases}$\kern{23em}}}
\mathllap{\raisebox{55em}{现在，看一看你所写公式的码量。你会发现你的 $\KaTeX$ 技能提升了。}\kern{9em}}
\mathllap{\raisebox{53em}{也就是说，只要多写写公式你的水平自然会提升。}\kern{17.4em}}
\mathllap{\raisebox{51em}{那么，现在你已经对 $\KaTeX$ 的基本用法有了一定的了解，就让我们来看一看下面这个简单}}
\mathllap{\raisebox{49.5em}{的例子，来吧我们刚刚学到的东西运用到实践当中吧！}\kern{15.35em}}
\mathllap{\raisebox{54.5em}{
    \def\arraystrech{0.2}
    $\begin{array}{cccccccccccccccccccccccccccccc}
    \\\\\\\\\\\\\\\\\\\\
    &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\\
    \hline
    \end{array}$
    \kern{3.5em}
}
}
\mathllap{\raisebox{45.5em}{\boxed{
    \raisebox{}{$\begin{matrix}\textbf{试看看}\\\text{例题1.8}\end{matrix}$}
}}\kern{30em}}
\mathllap{\raisebox{42em}{$\displaystyle\log\Pi(N)=\Big({N+\frac{1}{2}}\Big)\log N-N+A-\int_N^{\infty}\frac{\overline{B}_1(x)\mathrm{d}x}{x},A=1+\int_1^{\infty}\frac{\overline{B}_1(x)\mathrm{d}x}{x}$}\kern{5em}}
\mathllap{\raisebox{38.5em}{$\displaystyle\log \Pi (s)=\Big(s+\frac{1}{2}\Big)\log s-s+A-\int_{0}^{\infty}\frac{\overline{B}_1(t)\mathrm{d}t}{t+s}$}\kern{17.3em}}
\mathllap{\raisebox{18.8em}{$\displaystyle\begin{aligned}\log\Pi(s)=&\large{\lim_{n\to\infty}}\Big[s\log (N+1)+\sum_{n=1}^N\log n-\sum_{n=1}^N\log(s+n)\Big]\\=&\large{\lim_{n\to \infty}}\Big[s\log(N+1)+\int_{1}^N\log x\mathrm{d}x-\frac{1}{2}\log N+\int_{1}^N\frac{\overline{B}_1(x)\mathrm{d}x}{x}\\
&\large{-\int_{1}^N\log(s+x)\mathrm{d}x-\frac{1}{2}[\log(s+1)+\log(s+N)]}\\&\large{-\int_{1}^N\frac{\overline{B}_1(x)\mathrm{d}x}{s+x}}\Big]\\=&\large{\lim_{n\to\infty}}\Big[s\log(N+1)+N\log N-N+1+\frac{1}{2}\log N+\int_{1}^N\frac{\overline{B}_1(x)\mathrm{d}x}{x}\\&\large{-(s+N)+\log(s+N)+(s+N)+(s+1)\log(s+1)}\\&\large{-(s+1)-\frac{1}{2}\log(s+1)-\frac{1}{2}\log(s+N)-\int_1^N\frac{\overline{B}_1(x)\mathrm{d}x}{s+x}}\Big]\\=&\large{(s+\frac{1}{2})\log(s+1)+\int_{1}^{\infty}\frac{\overline{B}_1(x)\mathrm{d}x}{x}-\int_{1}^{\infty}\frac{\overline{B}_1(x)\mathrm{d}x}{s+x}}\\&\large{+\lim_{n\to\infty}}\Big[s\log(N+1)+(N\frac{1}{2})\log N\\&\large{-(S+N+\frac{1}{2})\log(S+N)}\Big]\\=&\large{(s+\frac{1}{2})\log(s+1)+(A-1)-\int_{1}^\infty\frac{\overline{B}_1(x)\mathrm{d}x}{s+x}}\\&\large{+\lim_{n\to\infty}\Big[s\log\frac{N+1}{s}-(N+\frac{1}{2})\log(1+\frac{s}{x})\Big]}\end{aligned}$}\kern{1.5em}}
\mathllap{\raisebox{0em}{$\color{#FFFFFF}\rule{40em}{2em}$}}
\mathllap{\raisebox{0.65em}{\textbf{假如让那些写 $\KaTeX$ 的那些人来出教程}}\kern{11em}}
$$