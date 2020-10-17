#include<iostream>
typedef long long ll;
using namespace std;
ll merge_sort_recursive(ll arr[], ll reg[], ll start, ll end) {
  if (start >= end)
    return 0;
  ll len = end - start, mid = (len >> 1) + start;
  ll start1 = start, end1 = mid;
  ll start2 = mid + 1, end2 = end;
  ll result = 0;
  result += merge_sort_recursive(arr, reg, start1, end1);
  result+=merge_sort_recursive(arr, reg, start2, end2);
  ll k=start;
  while (start1 <= end1 && start2 <= end2) {
    if (arr[start1] <= arr[start2])
      reg[k++] = arr[start1++];
    else {
      reg[k++] = arr[start2++];
      result += end1 - start1 + 1;
    }
  }
  while (start1 <= end1)
    reg[k++] = arr[start1++];
  while (start2 <= end2)
    reg[k++] = arr[start2++];
  for (ll k = start; k <= end; k++)
    arr[k] = reg[k];
  return result;
}
ll get_result(ll arr[], const ll len) {
  ll* reg = new ll[len];
  return merge_sort_recursive(arr, reg, 0, len-1);
}
