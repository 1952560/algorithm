Number of 1 Bits

Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Example:

```
Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
```

常规思路：

```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n){
            if(n&1)
            ans++;
            n>>=1;
        }
        return ans;
    }
};
```

小技巧：

我们可以把前面的算法进行优化。我们不再检查数字的每一个位，而是不断把数字最后一个 1 反转，并把答案加一。当数字变成 0 的时候，我们就知道它没有 1 的位了，此时返回答案。

这里关键的想法是对于任意数字 n ，将 n 和 n - 1n−1 做与运算，会把最后一个 1 的位变成 0 。为什么？考虑 n 和 n - 1的二进制表示。

![](https://github.com/1952560/IMG/blob/main/abfd6109e7482d70d20cb8fc1d632f90eacf1b5e89dfecb2e523da1bcb562f66-image.png)