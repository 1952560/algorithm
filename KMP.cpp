void fail(int f[], string p) {
  int lenthP = p.size();
  f[0] = -1;
  for (int j = 1; j < lenthP; j++) {
    int i = f[j - 1];
    while (p[j] != p[i + 1] && i >= 0)
      i = f[i];
    if (p[j] == p[i + 1])
      f[j] = i + 1;
    else
      f[j] = -1;
  }
}

int kmp(string t, string p) {//p为子串
  int f[maxn];
  fail(f, p);
  int posP = 0, posT = 0;
  int lenthP = p.size(), lenthT = t.size();
  while (posP < lenthP && posT < lenthT) {
    if (p[posP] == t[posT]) {
      posP++; posT++;
    }
    else if (posP == 0)
      posT++;
    else 
      posP = f[posP - 1] + 1;
  }
  if (posP < lenthP)
    return -1;
  else
    return posT - lenthP;
}