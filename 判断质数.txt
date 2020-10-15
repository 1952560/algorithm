ll ksc(ll x, ll y, ll p) {//计算x*y
  ll z = (ld)x / p * y;
  ll res = (ull)x * y - (ull)z * p;
  return (res + p) % p;
}

inline ll ksm(ll x, ll y, ll p) {//快速幂
  ll res = 1;
  while (y) {
    if (y & 1)res = ksc(res, x, p);
    x = ksc(x, x, p); y >>= 1;
  }return res;
}

inline bool mr(ll x, ll p) {
  if (ksm(x, p - 1, p) != 1)return 0;//费马小定理
  ll y = p - 1, z;
  while (!(y & 1)) {//一定要是能化成平方的形式
    y >>= 1; z = ksm(x, y, p);//计算
    if (z != 1 && z != p - 1)return 0;//不是质数
    if (z == p - 1)return 1;//一定要为1，才能继续二次探测
  }return 1;
}

inline bool prime(ll x) {
  if (x < 2)return 0;
  if (x == 2 || x == 3 || x == 5 || x == 7 || x == 43) return 1;
  return mr(2, x) && mr(3, x) && mr(5, x) && mr(7, x) && mr(43, x);
}
