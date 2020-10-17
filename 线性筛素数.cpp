#include<cstdio>
#include<iostream>
using namespace std;

int n, q, check[100000001] = { 0 };
int prime[1000001], cnt = 0;
//根据n<=10^8,q<=10^6开对应的数组大小，防止MLE
//初始将check数组全部标记为0，标0的是素数，标1的不是素数

void getPrime() {
	check[1] = 1;//1不是素数
	for (int i = 2; i <= n; i++)
	{
		if (!check[i])prime[cnt++] = i;//若当前数i没有被之前的所有数筛掉，表明i是素数，将i添加进素数表prime
		for (int j = 0; j < cnt && i * prime[j] < 100000001; j++)//注意i*prime[j]不要超过n的上限（10^8）
		{
			check[i * prime[j]] = 1;//将当前素数prime[j]的i倍标记为合数
			if (i % prime[j] == 0)break;//关键步骤：保证每个合数只被筛一次
		}
	}
}


int main()
{
	scanf("%d%d", &n, &q);
	getPrime();
	for (int i = 1; i <= q; i++)
	{
		scanf("%d", &n);
		printf("%d\n", prime[n - 1]);//由于素数表从0开始存，所以输出时下标应减1
	}
	return 0;
}
