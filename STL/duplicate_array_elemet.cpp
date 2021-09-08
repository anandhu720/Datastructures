#include "bits/stdc++.h"

using namespace std;

int main()
{
    int a[] = {1, 5, 2, 1, 4, 3, 1, 7, 2, 8, 9, 5};
    unordered_set<int> inset;
    unordered_set<int> duplicate;

    int n = sizeof(a) / sizeof(int);

    // looping through array elements
    for (int i = 0; i < n; i++)
    {
        // if element is not there then insert that
        if (inset.find(a[i]) == inset.end())
            inset.insert(a[i]);

        // if element is already there then insert into
        // duplicate set
        else
        {
            duplicate.insert(a[i]);
        }
    }

    // printing the result
    cout << "the duplicate numbers are :" << endl;
    unordered_set<int>::iterator itr;

    for (itr = duplicate.begin(); itr != duplicate.end(); itr++)
        cout << (*itr) << " ";
    cout << endl;
}