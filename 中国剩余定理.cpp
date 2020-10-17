#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;
ll k;
ll a[15], b[15];
ll ksc(ll a, ll b, ll mod) {
  ll ans = 0;
  while (b > 0) {
    if (b & 1) ans = (ans + a) % mod;
    a = (a + a) % mod;
    b >>= 1;
  }
  return ans;
}
void exgcd(ll a, ll b, ll& x, ll& y)
{
  if (b == 0) { x = 1; y = 0; return; }
  exgcd(b, a % b, x, y);
  ll tp = x;
  x = y; y = tp - a / b * y;
}

ll china()
{
  ll ans = 0, lcm = 1, x, y;
  for (ll i = 1; i <= k; ++i) lcm *= b[i];
  for (ll i = 1; i <= k; ++i)
  {
    ll tp = lcm / b[i];
    exgcd(tp, b[i], x, y);
    x = (x % b[i] + b[i]) % b[i];//x要为最小非负整数解
    ans = (ans + ksc(ksc(tp, x, lcm), a[i], lcm)) % lcm;
  }
  return (ans + lcm) % lcm;
}
int main()
{
  cin >> k;
  for (ll i = 1; i <= k; i++)
    cin >> a[i];
  for (ll i = 1; i <= k; i++)
    cin >> b[i];
for(int i=1;i<=k;i++) a[i]=(a[i]%b[i]+b[i])%b[i];
  cout << china();
}