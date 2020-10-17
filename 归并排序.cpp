#include<iostream>

using namespace std;

template<typename T>
void merge_sort_recursive(T arr[], T reg[], int start, int end) {
  if (start >= end)
    return;
  int len = end - start, mid = (len >> 1) + start;
  int start1 = start, end1 = mid;
  int start2 = mid + 1, end2 = end;
  merge_sort_recursive(arr, reg, start1, end1);
  merge_sort_recursive(arr, reg, start2, end2);
  int k = start;
  while (start1 <= end1 && start2 <= end2)
    reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
  while (start1 <= end1)
    reg[k++] = arr[start1++];
  while (start2 <= end2)
    reg[k++] = arr[start2++];
  for (k = start; k <= end; k++)
    arr[k] = reg[k];
}

template<typename T>
void merge_sort(T arr[], const int len) {
  T* reg = new T[len];
  merge_sort_recursive(arr, reg, 0, len - 1);
}

int main()
{
  int a[10];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  merge_sort(a, n);
  for (int i = 0; i < n; i++)
    cout << a[i] << ' ';
}
