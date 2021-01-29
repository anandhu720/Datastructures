#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> u = {4, 1, 2, 3, 4, 2, 3};

    int key = 12;

    if (u.find(key) != u.end())
        cout << key << " is found" << endl;
    else
        cout << key << " is not found" << endl;

    //to show all elements in unordered set
    unordered_set<int>::iterator itr;
    for (itr = u.begin(); itr != u.end(); itr++)
        cout << (*itr) << endl;
}