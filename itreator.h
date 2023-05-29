#pragma once

template<typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;
    Node(const T& data = T(), Node* prev = nullptr, Node* next = nullptr)
        : data(data), prev(prev), next(next) {}
};
template<typename T>
class ListIterator {
public:
    typedef ListIterator<T> self;
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef ptrdiff_t difference_type;

    ListIterator() : p(nullptr) {}
    ListIterator(Node<T>* p) : p(p) {}
    ListIterator(const self& x) : p(x.p) {}

    reference operator*() const { return p->data; }
    pointer operator->() const { return &(operator*()); }

    self& operator++() {
        p = p->next;
        return *this;
    }
    self operator++(int) {
        self tmp = *this;
        ++* this;
        return tmp;
    }
    self& operator--() {
        p = p->prev;
        return *this;
    }
    self operator--(int) {
        self tmp = *this;
        --* this;
        return tmp;
    }

    bool operator==(const self& x) const { return p == x.p; }
    bool operator!=(const self& x) const { return !(*this == x); }

//private:
    Node<T>* p;
};