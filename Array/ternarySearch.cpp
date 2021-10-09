#include <bits/stdc++.h>

using namespace std;

int ternarySearch(int a[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid1 = l + (r - l) / 3;
        int mid2 = mid1 + (r - l) / 3;

        if (a[mid1] == x)
            return mid1;
        else if (a[mid2] == x)
            return mid2;
        else if (a[mid1] > x)
            return ternarySearch(a, l, mid1 - 1, x);
        else if (a[mid2] < x)
            return ternarySearch(a, mid2 + 1, r, x);

        return ternarySearch(a, mid1 + 1, mid2 - 1, x);
    }
    return -1;
}

int main()
{
    int a[] = {2, 4, 6, 8, 12, 13, 16, 46, 56};
    int n = sizeof(a) / sizeof(a[0]);

    cout << ternarySearch(a, 0, n, 2) << "\n";

    return 0;
}