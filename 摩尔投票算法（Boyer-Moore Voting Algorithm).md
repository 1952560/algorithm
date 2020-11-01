# 摩尔投票算法（Boyer-Moore Voting Algorithm)

#### 一、题目介绍：

给定一个长度为n的数组的时候，**找出其中的主元素**，即该元素在数组中出现的次数大于n/2的取整。题目中已经假定所给的数组一定含有元素，且主元素一定存在。

#### 二：一些常用的方法：

1.哈希表法

2.排序法：排序后，出现次数大于一半的肯定在中间。

#### 二、摩尔投票算法:

摩尔投票算法的时间和空间都很低，时间复杂度为O(n)，空间复杂度为O(1)，这也是选择遮盖算法的原因。

Boyer-Moore算法的详细步骤：

- 我们维护一个候选众数 candidate 和它出现的次数 count。初始时 candidate 可以为任意值，count 为 0；

- 我们遍历数组 nums 中的所有元素，对于每个元素 x，在判断 x 之前，如果 count 的值为 0，我们先将 x 的值赋予 candidate，随后我们判断 x：

  - 如果 x 与 candidate 相等，那么计数器 count 的值增加 1；
  - 如果 x 与 candidate 不等，那么计数器 count 的值减少 1。

- 在遍历完成后，candidate 即为整个数组的众数。

  我们举一个具体的例子，例如下面的这个数组：

  ```
  [7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 7, 7, 7, 7]
  ```

  

在遍历到数组中的第一个元素以及每个在 | 之后的元素时，candidate 都会因为 count 的值变为 0 而发生改变。最后一次 candidate 的值从 5 变为 7，也就是这个数组中的众数。

#### 三、算法证明：

1. 如果候选人不是maj 则 maj,会和其他非候选人一起反对 会反对候选人,所以候选人一定会下台(maj==0时发生换届选举)
2. 如果候选人是maj , 则maj 会支持自己，其他候选人会反对，同样因为maj 票数超过一半，所以maj 一定会成功当选

#### 四、代码：

```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int num : nums) {
            if (num == candidate)
                ++count;
            else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};
```

