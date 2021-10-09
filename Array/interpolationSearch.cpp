#include <iostream>
#include <math.h>

using namespace std;

int interpolationSearch(int *, int, int);

int main()
{
    int a[] = {2, 4, 6, 12, 14, 19, 26, 30, 73};
    int n = sizeof(a) / sizeof(a[0]);

    cout << interpolationSearch(a, n, 13) << "\n";

    return 0;
}

int interpolationSearch(int a[], int n, int key)
{
    int lo = 0, hi = (n - 1);
    while (lo <= hi && key >= a[lo] && key <= a[hi])
    {
        if (lo == hi)
        {
            if (a[lo] == key)
                return lo;
            return -1;
        }

        int pos = lo + (((double)(hi - lo) / (a[hi] - a[lo])) * (key - a[lo]));

        if (a[pos] == key)
            return pos;
        else if (a[pos] < key)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;
}