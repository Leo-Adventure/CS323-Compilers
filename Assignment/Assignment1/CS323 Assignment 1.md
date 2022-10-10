## CS323 Assignment 1

### Exercise 1

6 tokens will be generated.

### Exercise 2

1. `n+1`
2. `n-1`
3. 1
4. 1
5. If $m = n$, then the number of proper prefix of length m is 0, if  $m\ne n$, the number is 1
6. $\frac{n(n+1)}{2} +1$
7. $2^n $

### Exercise 3

1. 所有由字母 a, b 组成的串，包括空串 $\epsilon$。
2. 倒数第三个字母是 a 的所有由字母 a, b 组成的串
3. 只含有三个字母 b，的所有由字母 a, b 组成的串

### Exercise 4

1. Let's define :

   $posDigit \rightarrow [1-9]$

   $digit -> [0-9]$

   then, we can get the representation of all strings representing valid telephone numbers in Shenzhen:

   $86-755-\ \ posDigit \ \ digit^7 $

2. $a(a|b)^*b$

3. Let's define:

   $remain \rightarrow [bcdfghjklmnpqrstvwxyz]$

   then, we can get the representation as belows:

   $remain^* \ \ a\ \  (a|remain)^*\ \ e \ \ (e|remain)^* \ \ i \ \ (i|remain)^* \ \  o \ \ (o|remain)^* \ \ u \ \ (u|remain)^* $  

### Optional Exercise 5

$L_1$ 和 $L_2$ 两个正则语言等价，证明如下。

不失一般性，我们只考虑如下串的递归定义形式：一个长度为$n$的串为长度为 $n-1 $的串**向右**增加字母生成$(n > 0)$。

考虑使用数学归纳法进行证明，当串的长度为$0$的时候，两种语言都只能构造出空串 $\epsilon$ ，此时两种语言显然等价。

当串的长度为1时，$L_1$ 和 $L_2$ 都可以生成 串 $a$, $b$，此时两种语言依然等价。

考虑当串的长度为 $k$ 的时候，两种语言仍然等价，设都可以生成长度为 $k$ 的串 $w$，当串的长度为 $k+1$ 的时候，根据前面定义的串递归定义方式，两种语言都可以生成 $w, wb, wa$三种串，此时$L_1, L_2$两种语言依然等价。

证毕，$L_1, L_2$两语言等价。

