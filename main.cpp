#include"mylist.h"
#include <iostream>

int main()
{
    List<int> int_list; // ����һ��int���͵�list

    // ��list�������Ԫ��
    int_list.push_back(1);
    int_list.push_back(2);
    int_list.push_back(3);

    // ����list�е�Ԫ��
    for (auto it = int_list.begin(); it != int_list.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    // ��listǰ�����Ԫ��
    int_list.push_front(4);
    int_list.push_front(5);
    int_list.push_front(6);

    // ����list�е�Ԫ��
    for (auto it = int_list.begin(); it != int_list.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    // ɾ��list�е�Ԫ��
    int_list.pop_back();
    int_list.pop_front();

    // ����list�е�Ԫ��
    for (auto it = int_list.begin(); it != int_list.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    return 0;
}