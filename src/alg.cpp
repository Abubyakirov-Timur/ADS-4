// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
        if (i != j)
            if (arr[i] + arr[j] == value)
                count++;
    return count / 2;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++)
        for (int j = len - 1; j > i; j--)
             if (arr[i] + arr[j] == value)
                 count++;
    return count;
}
int binar(int *arr, int l, int r, int x) {
    int lt = l, rt = r, m = 0; bool f = 0;
    while (lt <= rt)  {
        m = (lt + rt) / 2;
        if (arr[m] == x) {
            return binar(arr, l, m - 1, x) + binar(arr, m + 1, r, x) + 1;
        }
        if (x < arr[m])
            rt = m - 1;
        else
            lt = m + 1;
    }
    return 0;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
      count += binar(&arr[i + 1], 0 , len - i, value - arr[i]);
    }
    return count;
}
