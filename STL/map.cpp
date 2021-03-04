#include <iostream>
#include <map>
using namespace std;

int main()
{
    //intializing map
    map<int, string> m;

    //inserting to map
    m.insert(pair<int, string>(1, "anandhu"));
    m.insert(pair<int, string>(2, "raghavan"));
    m.insert(pair<int, string>(3, "lekha"));
    m.insert(pair<int, string>(4, "athira"));
    m.insert(pair<int, string>(5, "loomi"));

    //iterating through map
    map<int, string>::iterator itr;
    for (itr = m.begin(); itr != m.end(); itr++)
    {
        cout << itr->first << " " << itr->second << endl;
    }

    //iterating through map
    cout << "value found" << endl;
    map<int, string>::iterator itr1;
    itr1 = m.find(3);
    cout << itr1->first << " " << itr1->second << endl;

    cout << endl;
    return 0;
}