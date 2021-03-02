# 浙大PAT题解
准备考研浙大的小菜鸡^_^

## PAT A1065

`long long`的范围为$[-2^{63},2^{63}),$因此题中所给的两个整数相加可能会溢出(正溢出或者负溢出)。

①当$A+B≥2^{63}$时，显然有$A+B>C$成立，但$A+B$会因为超过`long long`的正向最大值而溢出。题目给定A与B最大值均为$2^{63}-1$,故$A+B$最大为$2^{64}-2$,因此使用`long long`存储正溢出后的值的区间为$[-2^{63},-2](∵(2^{64}-2) \%   2^{64}=-2)$.所以，当$A>0,B>0,A+B<0$时为正溢出，输出`true`.

②当$A+B<-2^{63}$时，显然有$A+B<C$成立，但$A+B$会因为超过`long long`的负向最小值而溢出。题目给定A与B最小值均为$-2^{63}$,故$A+B$最小为$-2^{64}$,因此使用`long long`存储负溢出后的值的区间为$[0,2^{63})(∵(-2^{64})\%2^{64}=0)$.所以，当$A<0,B<0,A+B>0$时为负溢出，输出`false`.