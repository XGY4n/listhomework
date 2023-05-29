#include"mylist.h"
#include <iostream>

int main()
{
    List<int> int_list; // 创建一个int类型的list

    // 在list后面插入元素
    int_list.push_back(1);
    int_list.push_back(2);
    int_list.push_back(3);

    // 遍历list中的元素
    for (auto it = int_list.begin(); it != int_list.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    // 在list前面插入元素
    int_list.push_front(4);
    int_list.push_front(5);
    int_list.push_front(6);

    // 遍历list中的元素
    for (auto it = int_list.begin(); it != int_list.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    // 删除list中的元素
    int_list.pop_back();
    int_list.pop_front();

    // 遍历list中的元素
    for (auto it = int_list.begin(); it != int_list.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    return 0;
}