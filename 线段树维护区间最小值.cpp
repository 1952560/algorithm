#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

const int INF = 1e9 + 7;
#define int long long

struct Node
{
  int l, r;
  int minn; //区间最小值
  int dis;
  int addv;
} tree[300005 * 4];

int a[300005];
int b[300005];

void build(int o, int l, int r) {
  tree[o].l = l;
  tree[o].r = r;
  tree[o].addv = 0;
  if (l == r) { //叶子
    tree[o].minn = a[l];
    tree[o].dis = b[l];
    return;
  }
  build(o * 2, l, (l + r) / 2);
  build(o * 2 + 1, (l + r) / 2 + 1, r);
  tree[o].minn = min(tree[o * 2].minn , tree[o * 2 + 1].minn);
  tree[o].dis = min(tree[o * 2].dis, tree[o * 2 + 1].dis);
}

void pushdown(int o)
{
  if (tree[o].l < tree[o].r) {
    tree[o * 2].minn += tree[o].addv;
    tree[o * 2 + 1].minn += tree[o].addv;
    tree[o * 2].dis += tree[o].addv;
    tree[o * 2 + 1].dis += tree[o].addv;
    tree[o * 2].addv += tree[o].addv;
    tree[o * 2 + 1].addv += tree[o].addv;
  }
  tree[o].addv = 0;
}

int query1(int o, int a, int b) {
  if (tree[o].l >= a && tree[o].r <= b) { //被包含
    return tree[o].minn;
  }
  pushdown(o);
  int mid = (tree[o].l + tree[o].r) / 2;
  int result = INF;
  if (a <= mid)
    result =min(result, query1(o * 2, a, b));
  if (b > mid)
    result =min(result, query1(o * 2 + 1, a, b));
  return result;
}

int query2(int o, int a, int b) {
  if (tree[o].l >= a && tree[o].r <= b) { //被包含
    return tree[o].dis;
  }
  pushdown(o);
  int mid = (tree[o].l + tree[o].r) / 2;
  int result = INF;
  if (a <= mid)
    result = min(result, query2(o * 2, a, b));
  if (b > mid)
    result = min(result, query2(o * 2 + 1, a, b));
  return result;
}

void update(int o, int a, int b, int x) {
  if (tree[o].l >= a && tree[o].r <= b) {
    tree[o].addv += x;
    tree[o].minn += x ;
    tree[o].dis += x;
  }
  else {
    int mid = (tree[o].l + tree[o].r) / 2;
    if (a <= mid)
      update(o * 2, a, b, x);
    if (b > mid)
      update(o * 2 + 1, a, b, x);
    tree[o].minn =min( tree[o * 2].minn + tree[o].addv ,tree[o * 2 + 1].minn +tree[o].addv);
    tree[o].dis = min(tree[o * 2].dis + tree[o].addv, tree[o * 2 + 1].dis + tree[o].addv);
  }
}

signed main()
{
  int n, m;
  cin >> n >> m;
  char ch;
  string str;
  for (int i = 1; i <= n; i++) {
    cin >> ch;
    str.push_back(ch);
    if (ch == '(')
      a[i] = a[i - 1] + 1;
    else if (ch == ')')
      a[i] = a[i - 1] - 1;
    b[i] = a[i] - i;
  }
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int k = 0;
    cin >> k;
    if (str[k - 1] == '(') {
      str[k - 1] = ')';
      update(1, k, n, -2);
      int minx = 1, maxx = k;
      while (maxx > minx) {
        int mid = (maxx + minx) / 2;
        if (query2(1, 1, mid) < 0) {
          maxx = mid;
        }
        else
          minx = mid + 1;
      }
          str[minx - 1] = '(';
          update(1, minx, n, 2);
          cout << minx << '\n';
    }
    else {
      str[k - 1] = '(';
      update(1, k, n, 2);
      int minx = 1, maxx = k;
      while (maxx > minx) {
        int mid = (maxx + minx) / 2;
        if (query1(1, mid, n) >= 2) {
          maxx = mid;
        }
        else
          minx = mid + 1;
      }
        str[minx - 1] = ')';
        update(1, minx, n, -2);
        cout << minx << '\n';
      
    }
  }
}