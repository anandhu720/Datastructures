//Basic program

#include <iostream>
#include <vector>
using namespace std;
int main()
{

    //initializing vector
    vector<int> v = {2, 4, 6, 8, 10};

    //inserting elements into vector
    v.push_back(20);
    v.push_back(30);

    //deleting elements from vector
    v.pop_back();

    //iterations
    cout << "Using forEach loop" << endl;
    for (int x : v)
        cout << x << " ";
    cout << endl;

    cout << "Using Iterator" << endl;
    vector<int>::iterator itr;
    for (itr = v.begin(); itr != v.end(); itr++)
        cout << (*itr) << " ";
    cout << endl;

    return 0;
}