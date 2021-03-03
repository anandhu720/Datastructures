#include <iostream>
#include <set>
int main()
{
    //intializing singly linked list
    std::set<int> s = {2, 4, 6, 8, 10, 10};

    //inserting elements
    s.insert(20);
    s.insert(0);

    //iterations
    std::cout << "Using iteration" << std::endl;
    std::set<int>::iterator itr;
    for (itr = s.begin(); itr != s.end(); itr++)
        std::cout << (*itr) << " ";
    std::cout << std::endl;

    std::cout << "Using forEach Loop" << std::endl;
    for (int x : s)
        std::cout << x << " ";
    std::cout << std::endl;
}