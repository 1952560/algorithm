#include<iostream>
#include<algorithm>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
const ll maxn = 5e5 + 5;

ll n, m;

struct Edge
{
  ll from;
  ll to;
  ll dist;
  bool operator < (const Edge& rhs)const {
    return dist < rhs.dist;
  }
}e[maxn];

ll par[maxn];

ll find(ll x){
  return par[x] == x ? x : par[x] = find(par[x]);
}

int main()
{
  //input;
  sort(e, e + m);
  for (ll i = 0; i < n; i++) {
    par[i] = i;
  }
  ll sum = 0;
  for (ll i = 0; i < m; i++) {
    if (find(e[i].from) == find(e[i].to)) {
      continue;
    }
    par[find(e[i].from)] = find(e[i].to);
    sum += e[i].dist;//将边加入最小生成树，根据题目需要更改
  }
  return 0;
}
