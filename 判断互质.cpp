位运算（超快）
此段代码a、b不能为0
inline int gcd(int a,int b) {
    while(b^=a^=b^=a%=b);
    return a;
}


if+while+位运算（超快）
此段代码a、b可以为0
inline int gcd(int a,int b) {
	if(b) while((a%=b) && (b%=a));
	return a+b;
}


辗转相除法（较快）
此段代码a、b不能为0
inline int gcd(int a,int b) {
	if(a%b==0) return b;
		else return (gcd(b,a%b));
}

