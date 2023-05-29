#include <iostream>
#include "itreator.h"



template<typename T>
class List {
public:
    typedef ListIterator<T> iterator;

    List() { init(); }
    List(const List& x) {
        init();
        for (auto it = x.begin(); it != x.end(); ++it)
            push_back(*it);
    }
    ~List() {
        clear();
        delete head;
        delete tail;
    }

    bool empty() const { return head->next == tail; }
    size_t size() const {
        size_t count = 0;
        for (auto it = begin(); it != end(); ++it)
            ++count;
        return count;
    }

    iterator begin() const { return iterator(head->next); }
    iterator end() const { return iterator(tail); }

    void push_back(const T& x) { insert(end(), x); }
    void push_front(const T& x) { insert(begin(), x); }
    void pop_back() { erase(--end()); }
    void pop_front() { erase(begin()); }

    iterator insert(iterator position, const T& x) {
        Node<T>* p = position.p;
        Node<T>* node = new Node<T>(x, p->prev, p);
        p->prev->next = node;
        p->prev = node;
        return iterator(node);
    }
    iterator erase(iterator position) {
        Node<T>* p = position.p;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        iterator next(p->next);
        delete p;
        return next;
    }

private:
    void init() {
        head = new Node<T>;
        tail = new Node<T>;
        head->next = tail;
        tail->prev = head;
    }

    void clear() {
        while (!empty())
            pop_front();
    }

private:
    Node<T>* head;
    Node<T>* tail;
};