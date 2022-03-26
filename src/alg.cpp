// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        ++k;
    }
  }
  return k;
}
int countPairs2(int *arr, int len, int value) {
   int n = 0;
  while ((value - arr[0] >= arr[k]) && (k < len))
    ++n;
  int v = 0;
  int a = 0;
  int b = n - 1;
  while (a != b) {
    if (arr[a] + arr[b] > value) {
      --b;
    } else {
        if (arr[a] + arr[b] < value) {
          ++a;
      } else {
          for (int i = n - 1; i > a; i--) {
            if (arr[i] + arr[a] < value)
              break;
            if (arr[i] + arr[a] == value)
              ++v;
          }
          ++a;
        }
      }
  }
  return v;
}
int countPairs3(int *arr, int len, int value) {
  int m = 0;
  int h = 0;
  while ((value - arr[0] >= arr[h]) && (h < len))
    ++h;
  for (int i = 0; i < h - 1; i++) {
    int y = value - arr[i];
    int a = i + 1;
    int b = h - 1;
    bool f = false;
    while ((a <= b) && (!f)) {
      int cen = (a + b) / 2;
      if (arr[cen] == y) {
        for (int j = a; j <= b; j++)
          if (arr[j] == y)
            ++m;
        f = true;
      }
      if (arr[cen] > y)
        b = cen - 1;
      else
        a = cen + 1;
    }
  }
  return m;
}
