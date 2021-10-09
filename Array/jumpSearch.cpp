#include <bits/stdc++.h>
using namespace std;

int jumpSearch(int a[], int n, int key)
{
    int step = sqrt(n);
    int index1 = 0;

    while (a[index1] < key)
    {
        index1 += step;
        if (index1 > n)
            return -1;
    }

    for (int i = index1; i >= 0; i--)
    {
        if (a[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int a[7] = {2, 4, 6, 12, 16, 77, 100};
    int n = sizeof(a) / sizeof(a[0]);
    cout << jumpSearch(a, n, 16) << "\n";
}