#include <iostream>
#include <forward_list>
int main()
{
    //intializing singly linked list
    std::forward_list<int> l = {2, 4, 6, 8, 10};

    //inserting elements
    l.push_front(20);
    l.push_front(0);

    //deleting elements
    l.pop_front();
    l.pop_front();

    //iterations
    std::cout << "Using iteration" << std::endl;
    std::forward_list<int>::iterator itr;
    for (itr = l.begin(); itr != l.end(); itr++)
        std::cout << (*itr) << " ";
    std::cout << std::endl;

    std::cout << "Using forEach Loop" << std::endl;
    for (int x : l)
        std::cout << x << " ";
    std::cout << std::endl;
}