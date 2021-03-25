#include <bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int, int, int);

int exponentialSearch(int a[], int n, int x)
{
    if (a[0] == x)
        return 0;
    int i = 1;
    while (i < n && a[i] <= x)
        i *= 2;

    return binarySearch(a, i / 2, min(i, n - 1), x);
}

int binarySearch(int a[], int l, int h, int x)
{
    if (l < h)
    {
        int mid = l + (h - 1) / 2;
        if (a[mid] == x)
            return mid;
        else if (x > a[mid])
            return binarySearch(a, mid + 1, h, x);
        else if (x < a[mid])
            return binarySearch(a, l, mid - 1, x);
    }

    return -1;
}

int main()
{
    int a[] = {1, 3, 6, 23, 122, 234, 345};
    int n = sizeof(a) / sizeof(a[0]);

    cout << exponentialSearch(a, n, 345) << "\n";
    return 0;
}