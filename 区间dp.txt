一、定义
 

区间DP，顾名思义是在区间上DP，它的主要思想就是先在小区间进行DP得到最优解，然后再利用小区间的最优解合并求大区间的最优解。

 

 
二、实现思路
 

下面给出区间DP最简单形式的伪代码(具体要根据题目修改)

//mst(dp,0) 初始化DP数组
for(int i=1;i<=n;i++)
{
    dp[i][i]=初始值
}
for(int len=2;len<=n;len++)  //区间长度
for(int i=1;i<=n;i++)        //枚举起点
{
    int j=i+len-1;           //区间终点
    if(j>n) break;           //越界结束
    for(int k=i;k<j;k++)     //枚举分割点，构造状态转移方程
    {
        dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+w[i][j]);
    }
}

三、经典例题
 
1. 石子合并问题


题目描述
在一个圆形操场的四周摆放 N 堆石子,现要将石子有次序地合并成一堆.规定每次只能选相邻的2堆合并成新的一堆，并将新的一堆的石子数，记为该次合并的得分。

试设计出一个算法,计算出将 N 堆石子合并成 1 堆的最小得分和最大得分。

输入格式
数据的第 1 行是正整数 N，表示有 N 堆石子。

第 2 行有 N 个整数，第 i 个整数 ai 表示第 i 堆石子的个数。

输出格式
输出共 2 行，第 1 行为最小得分，第 2 行为最大得分。

输入输出样例

输入#1
4
4 5 9 4 
输出#1
43
54


代码：
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
const ll maxn = 210;

int n;
int s[maxn];
int mm[maxn][maxn];//最大
int mi[maxn][maxn];//最小
int sum[maxn];//前缀和

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> s[i];
  memset(mi, 0x3f, sizeof(mi));
  for (int i = 1; i <= n; i++) {
    sum[i] += sum[i - 1] + s[i];
    mi[i][i] = 0;
  }
  for (int i = n + 1; i <= 2 * n; i++) {
    sum[i] += sum[i - 1] + s[i - n];
    mi[i][i] = 0;
  }
  for (int len= 2; len <= n; len++) {//枚举长度
    for (int i = 1; i <=2*n ; i++) {//枚举起点
      int j = i + len - 1;//终点
      if (j > 2*n)
        break;
      for (int k = i; k < j; k++) {
        mm[i][j] = max(mm[i][j], mm[i][k]+ mm[k + 1][j] + sum[j] - sum[i - 1]);
        mi[i][j] = min(mi[i][j], mi[i][k] + mi[k + 1][j] + sum[j] - sum[i - 1]);
      }
    }
  }
  int ansmin = 1e9+7;
  int ansmax = 0;
  for (int i = 1; i <= n+1; i++) {
    ansmin = min(ansmin, mi[i][n + i - 1]);
    ansmax = max(ansmax, mm[i][n + i - 1]);
  }
  cout << ansmin << '\n' << ansmax;
}