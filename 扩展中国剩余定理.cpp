#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#define ll long long
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

int ai[20], bi[20];
int n;

ll exgcd(ll a, ll b, ll& x, ll& y)
{
  if (b == 0) { x = 1; y = 0; return a; }
  ll gcd = exgcd(b, a % b, x, y);
  ll tp = x;
  x = y; y = tp - a / b * y;
  return gcd;
}

ll mul(ll x, ll y, ll p) {//计算x*y
  ll z = (ld)x / p * y;
  ll res = (ull)x * y - (ull)z * p;
  return (res + p) % p;
}

ll excrt()
{
  ll x, y, k;
  ll M = bi[1], ans = ai[1];//第一个方程的解特判
  for (int i = 2; i <= n; i++)
  {
    ll a = M, b = bi[i], c = (ai[i] - ans % b + b) % b;//ax≡c(mod b)
    ll gcd = exgcd(a, b, x, y), bg = b / gcd;
    if (c % gcd != 0) return -1; //判断是否无解

    x = mul(x, c / gcd, bg);
    ans += x * M;//更新前k个方程组的答案
    M *= bg;//M为前k个m的lcm
    ans = (ans % M + M) % M;
  }
  return (ans % M + M) % M;
}

int main()
{
  cin >> n;
  for (ll i = 1; i <= n; i++)
    cin >> ai[i];
  for (ll i = 1; i <= n; i++)
    cin >> bi[i];
  for (int i = 1; i <= n; i++) ai[i] = (ai[i] % bi[i] + bi[i]) % bi[i];
  cout << excrt();
}

