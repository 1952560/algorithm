typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
ll ksc(ll x, ll y, ll p) {//计算x*y
  ll z = (ld)x / p * y;
  ll res = (ull)x * y - (ull)z * p;
  return (res + p) % p;
}