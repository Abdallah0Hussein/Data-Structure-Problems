#include <bits/stdc++.h>
using namespace std;

// Array List
template <typename T>
class arrayList
{
private:
    int size;
    int maxSize;
    T *list;

public:
    arrayList(int n)
    {
        size = 0;
        maxSize = n;
        list = new T[maxSize];
    }
    int listSize()
    {
        return size;
    }
    int listMaxSize()
    {
        return maxSize;
    }
    void insert(T ele)
    {
        if (maxSize <= size)
        {
            throw std::out_of_range("\n\t\t\t*** This List is Full ***\n");
        }
        list[size] = ele;
        size++;
    }
    void insertAt(T ele, int index)
    {

        if (maxSize <= size)
        {
            throw std::out_of_range("\n\t\t\t*** This List is Full ***\n");
        }
        if (index >= size || index < 0)
        {
            throw std::out_of_range("\n\t\t\t*** Out Of bounds ***\n");
        }
        else
        {
            size++;
            for (int i = size - 1; i > index; i--)
            {
                list[i] = list[i - 1];
            }
            list[index] = ele;
        }
    }
    T retrieveAt(int index)
    {
        if (index >= size || index < 0)
        {

            throw std::out_of_range("\n\t\t\t*** Out Of bounds ***\n");
        }
        return list[index--];
    }
    void removeAt(int index)
    {

        if (index >= size || index < 0)
        {
            throw std::out_of_range("\n\t\t\t*** Out Of bounds ***\n");
        }
        else
        {
            for (int i = index; i < size; i++)
            {
                list[i] = list[i + 1];
            }
            size--;
        }
    }
    void replaceAt(T newEle, int index)
    {

        if (index >= size || index < 0)
        {
            throw std::out_of_range("\n\t\t\t*** Out Of bounds ***\n");
        }
        else
        {
            list[index] = newEle;
        }
    }
    bool isItemAtEqual(T element, int index)
    {
        if (index >= size || index < 0)
        {
            throw std::out_of_range("\n\t\t\t*** Out Of bounds ***\n");
        }
        return (list[index] == element);
    }
    bool isFull()
    {
        return (size == maxSize);
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    void clear()
    {
        size = 0;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << list[i] << " ";
        }
        cout << endl;
    }
    ~arrayList()
    {
        delete[] list;
    }
};

template <typename type>
class Stack
{
private:
    int size;
    int maxSize = 10;
    type *arr;

public:
    Stack(int maxSize) : maxSize(maxSize), size(0)
    {
        arr = new type[maxSize];
    }
    Stack() : size(0)
    {
        arr = new type[maxSize];
    }
    void push(type ele)
    {
        if (size >= maxSize)
        {
            maxSize *= 2;
            type *new_array = new type[maxSize];
            for (int i = 0; i < size; i++)
            {
                new_array[i] = arr[i];
            }
            delete[] arr;
            arr = new_array;
        }
        arr[size++] = ele;
    }
    type pop()
    {
        if (size == 0)
        {
            throw std::out_of_range("\n\t\t\t*** This stack is empty ***");
        }
        return arr[--size];
    }
    type top()
    {
        if (size == 0)
        {
            throw std::out_of_range("\n\t\t\t*** This stack is empty ***");
        }
        return arr[size - 1];
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void clear()
    {
        size = 0;
    }
    int sizeStack()
    {
        return size;
    }
    void print()
    {
        if (size == 0)
        {
            throw std::out_of_range("\n\t\t\t*** This stack is empty ***");
        }
        for (int i = size - 1; i >= 0; i--)
        {
            if (i == 0)
            {
                cout << arr[i] << endl;
                return;
            }
            cout << arr[i] << "<-";
        }
    }
};

template <typename type>
class Queue
{
private:
    int size;
    type *arr;

public:
    Queue()
    {
        size = 0;
        arr = new type[10];
    }

    Queue(int maxSize)
    {
        size = 0;
        arr = new type[maxSize];
    }
    void enqueue(type ele)
    {
        arr[size] = ele;
        size++;
    }
    type first()
    {
        if (size == 0)
        {
            throw std::out_of_range("\n\t\t\t*** This queue is empty ***\n");
        }
        return arr[0];
    }
    type dequeue()
    {
        type e = arr[0];
        if (size == 0)
        {
            throw std::out_of_range("\n\t\t\t*** This queue is empty ***\n");
        }
        else
        {
            // cout << "done" << endl;
            for (size_t i = 0; i < size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            size--;
        }
        return e;
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    int queueSize()
    {
        return size;
    }
    void clear()
    {
        size = 0;
    }
    void print()
    {
        if (size == 0)
        {
            throw std::out_of_range("\n\t\t\t*** This queue is empty ***\n");
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (i == size - 1)
                {
                    cout << arr[i] << endl;
                }
                else
                {
                    cout << arr[i] << " <- ";
                }
            }
        }
    }
};

template <typename type>
struct node
{
    type element;
    node<type> *next;
    node(type element) : element(element) {}
    node() : next(NULL), element(0) {}
};
// Single Linked List

template <typename type>
class SLL
{
private:
    int size;

public:
    node<type> *head, *tail;
    SLL()
    {
        clear();
    }
    SLL<type> &operator=(const SLL<type> anotherSLL);
    // SLL(const SLL<type> anotherSLL);
    void insertAtHead(type ele);
    void insertAtTail(type ele);
    void insertAt(type ele, int index);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    type retrieveAt(int index);
    void replaceAt(type ele, int index);
    bool isExist(type ele);
    bool isItemAtEqual(type ele, int index);
    bool isEmpty();
    int linkedListSize();
    void clear();
    void print();
};

template <typename type>
SLL<type> &SLL<type>::operator=(const SLL<type> anotherSLL)
{
    if (this != &anotherSLL)
    {
        delete head;
        delete tail;
        head = new node<type>;
        tail = new node<type>;
        head = tail = nullptr;
        node<type> *current = anotherSLL.head;

        while (current != NULL)
        {
            this->insertAtTail(current->element);
            current = current->next;
        }
    }
    return *this;
}

// template <typename type>
// SLL<type>::SLL(const SLL<type> anotherSLL)
// {
//     node<type>* current = anotherSLL.head;
//     head = tail = nullptr;
//     while (current != NULL)
//     {
//         this->insertAtTail(current->element);
//         current = current->next;
//     }
// }

template <typename type>
int SLL<type>::linkedListSize()
{
    return size;
}
template <typename type>
bool SLL<type>::isEmpty()
{
    return (size == 0);
}
template <typename type>
void SLL<type>::clear()
{
    tail = head = nullptr;
    size = 0;
}
template <typename type>
void SLL<type>::insertAtHead(type ele)
{
    node<type> *newNode = new node<type>(ele);
    if (size == 0)
    {
        head = newNode;
        tail = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    size++;
}
template <typename type>
void SLL<type>::insertAtTail(type ele)
{
    node<type> *newNode = new node<type>(ele);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->next = NULL;
        tail = newNode;
    }
    size++;
}
template <typename type>
void SLL<type>::insertAt(type ele, int index)
{
    if (index > size || index < 0)
    {
        throw std::out_of_range("\n\t\t\t*** Out Of bounds ***\n");
    }
    else
    {
        node<type> *newNode = new node<type>(ele);
        if (index == 0)
        {
            insertAtHead(ele);
        }
        else if (index == size)
        {
            insertAtTail(ele);
        }
        else
        {
            node<type> *ptr = head;
            for (int i = 1; i < index; i++)
            {
                ptr = ptr->next;
            }
            newNode->next = ptr->next;
            ptr->next = newNode;
            size++;
        }
    }
}
template <typename type>
void SLL<type>::removeAtHead()
{
    if (size == 0)
    {
        throw std::out_of_range("\n\t\t\t*** Empty linked list ***\n");
    }
    else if (size == 1)
    {
        delete head;
        head = tail = NULL;
    }
    else
    {
        node<type> *ptr = head;
        head = ptr->next;
        delete ptr;
    }
    size--;
}

template <typename type>
void SLL<type>::removeAtTail()
{
    if (size == 0)
    {
        throw std::out_of_range("\n\t\t\t*** Empty linked list ***\n");
    }
    else if (size == 1)
    {
        delete head;
        head = tail = NULL;
    }
    else
    {
        node<type> *cur = head->next;
        node<type> *pre = head;
        while (cur->next != NULL)
        {
            pre = cur;
            cur = cur->next;
        }
        delete cur;
        pre->next = NULL;
        tail = pre;
        delete pre;
    }
    size--;
}
template <typename type>
void SLL<type>::removeAt(int index)
{
    if (size == 0)
    {
        throw std::out_of_range("\n\t\t\t*** Empty linked list ***\n");
    }
    else if (index >= size)
    {
        throw std::out_of_range("\n\t\t\t*** Out Of bounds ***\n");
    }
    if (index == 0)
    {
        removeAtHead();
        return;
    }
    if (index == size - 1)
    {
        removeAtTail();
        return;
    }
    else
    {
        int counter = 0;
        node<type> *cur = head;
        while (counter < index - 1)
        {
            cur = cur->next;
            counter++;
        }
        node<type> *tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
    }
    size--;
}

template <typename type>
type SLL<type>::retrieveAt(int index)
{
    // zero based
    type e;
    if (size <= index)
    {
        // cout << "\n\t\t\t*** out of bounds ***\n" << endl;
        return 0;
    }
    node<type> *ptr = head;
    int counter = 0;
    while (ptr->next != NULL)
    {
        if (counter == index)
        {
            e = ptr->element;
            break;
        }
        counter++;
        ptr = ptr->next;
    }
    return e;
}
template <typename type>
void SLL<type>::replaceAt(type ele, int index)
{
    // zero based
    if (size <= index)
    {
        throw std::out_of_range("\n\t\t\t*** Out Of bounds ***\n");
    }
    node<type> *ptr = head;
    int counter = 0;
    while (ptr->next != NULL)
    {
        if (counter == index)
        {
            ptr->element = ele;
            break;
        }
        counter++;
        ptr = ptr->next;
    }
}
template <typename type>
bool SLL<type>::isExist(type ele)
{
    // zero based
    node<type> *ptr = head;
    int counter = 0;
    while (ptr->next != NULL)
    {
        if (ptr->element == ele)
        {
            return true;
        }
        counter++;
        ptr = ptr->next;
    }
    return false;
}
template <typename type>
bool SLL<type>::isItemAtEqual(type ele, int index)
{
    node<type> *ptr = head;
    int counter = 0;
    while (ptr->next != NULL)
    {
        if (counter == index)
        {
            if (ptr->element == ele)
                return true;
        }
        counter++;
        ptr = ptr->next;
    }
    return false;
}
template <typename type>
void SLL<type>::print()
{
    node<type> *ptr = head;
    while (ptr->next != nullptr)
    {
        cout << ptr->element << "->";
        ptr = ptr->next;
    }
    cout << tail->element << endl;
}

template <typename type>
struct D_node
{
    type element;
    D_node<type> *next;
    D_node<type> *prev;
    D_node(type element) : element(element) {}
};

// Doubly Linked List
template <typename type>
class DLL
{
private:
    int size;
    D_node<type> *head, *tail;

public:
    DLL()
    {
        clear();
    }
    void insertAtHead(type ele);
    void insertAtTail(type ele);
    void insertAt(type ele, int index);
    void insertAfter(D_node<type> *prev_node, int data);
    int doubleLinkedListSize();
    void removeAtHead();
    void removeAtTail();
    bool isEmpty();
    void clear();
    void removeAt(int index);
    type retrieveAt(int index);
    void replaceAt(type ele, int index);
    bool isExist(type ele);
    bool isItemAtEqual(type ele, int index);
    void reverse();
    void forwardTraversal();
    void backwardTraversal();
};
template <typename type>
void DLL<type>::insertAfter(D_node<type> *prev_node, int data)
{
    if (prev_node == nullptr)
    {
        throw std::invalid_argument("Previous node can't be null");
    }
    D_node<type> *new_node = new D_node<type>(data);
    new_node->next = prev_node->next;
    if (prev_node->next != nullptr) // the nullptr doesn't have a previous ptr
        prev_node->next->prev = new_node;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    size++;
}

template <typename type>
int DLL<type>::doubleLinkedListSize()
{
    return size;
}
template <typename type>
bool DLL<type>::isEmpty()
{
    return (size == 0);
}
template <typename type>
void DLL<type>::clear()
{
    tail = head = nullptr;
    size = 0;
}
template <typename type>
void DLL<type>::insertAtHead(type ele)
{
    D_node<type> *newNode = new D_node<type>(ele);
    if (head == nullptr)
    {
        head = tail = newNode;
        head->prev = NULL;
        tail->next = NULL;
    }
    else
    {
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
    }
    // cout << "done" << endl;
    size++;
}
template <typename type>
void DLL<type>::insertAtTail(type ele)
{
    D_node<type> *newNode = new D_node<type>(ele);
    if (head == nullptr)
    {
        newNode->next = newNode->prev = NULL;
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = NULL;
        tail = newNode;
    }

    size++;
}
template <typename type>
void DLL<type>::insertAt(type ele, int index)
{
    if (index > size)
    {
        throw std::out_of_range("\n\t\t\t*** Out Of bounds ***\n");
    }
    else if (index == 0)
    {
        insertAtHead(ele);
        return;
    }
    else if (index == size)
    {
        insertAtTail(ele);
        return;
    }
    else
    {
        D_node<type> *ptr = head;
        for (int i = 1; i < index; i++)
        {
            ptr = ptr->next;
        }
        insertAfter(ptr, ele);
    }
    size++;
}
template <typename type>
void DLL<type>::removeAtHead()
{
    if (head == NULL)
    {
        throw std::out_of_range("\n\t\t\t*** This list is empty ***\n");
    }
    else if (size == 0)
    {
        delete head;
        head = tail = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }
    size--;
}
template <typename type>
void DLL<type>::removeAtTail()
{
    if (head == NULL)
    {
        throw std::out_of_range("\n\t\t\t*** This list is empty ***\n");
    }
    else if (size == 0)
    {
        delete head;
        head = tail = NULL;
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
    }
    size--;
}
template <typename type>
void DLL<type>::removeAt(int index)
{
    if (index >= size)
    {
        throw std::out_of_range("\n\t\t\t*** out of bounds ***\n");
    }
    else if (index == 0)
    {
        removeAtHead();
    }
    else if (index == size - 1)
    {
        removeAtTail();
    }
    else
    {
        D_node<type> *ptr = head;
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete ptr;
    }
    size--;
}
template <typename type>
type DLL<type>::retrieveAt(int index)
{
    // zero based
    if (size <= index)
    {
        throw std::out_of_range("\n\t\t\t*** Out Of bounds ***\n");
    }
    D_node<type> *ptr = head;
    int counter = 0;
    while (ptr->next != nullptr)
    {
        if (counter == index)
        {
            break;
        }
        counter++;
        ptr = ptr->next;
    }
    return ptr->element;
}

template <typename type>
void DLL<type>::replaceAt(type ele, int index)
{
    // zero based
    if (size <= index)
    {
        throw std::out_of_range("\n\t\t\t*** out of bounds ***\n");
    }
    D_node<type> *ptr = head;
    int counter = 0;
    while (ptr->next != NULL)
    {
        if (counter == index)
        {
            break;
        }
        counter++;
        ptr = ptr->next;
    }
    ptr->element = ele;
}
template <typename type>
bool DLL<type>::isExist(type ele)
{
    // zero based
    D_node<type> *ptr = head;
    while (ptr != nullptr)
    {
        if (ptr->element == ele)
        {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}
template <typename type>
bool DLL<type>::isItemAtEqual(type ele, int index)
{
    // zero based
    if (size <= index)
    {
        throw std::out_of_range("\n\t\t\t*** Out Of bounds ***\n");
    }

    D_node<type> *ptr = head;
    int counter = 0;
    while (ptr != nullptr)
    {
        if (counter == index)
        {
            if (ptr->element == ele)
                return true;
        }
        counter++;
        ptr = ptr->next;
    }
    return false;
}

template <typename type>
void DLL<type>::reverse()
{
    D_node<type> *current = head;
    while (current != nullptr)
    {
        swap(current->next, current->prev);
        current = current->prev;
    }
    swap(head, tail);
}
template <typename type>
void DLL<type>::forwardTraversal()
{
    D_node<type> *ptr = head;
    while (ptr->next != NULL)
    {
        cout << ptr->element << "->";
        ptr = ptr->next;
    }
    cout << tail->element << endl;
}
template <typename type>
void DLL<type>::backwardTraversal()
{
    D_node<type> *ptr = tail;
    while (ptr->prev != NULL)
    {
        cout << ptr->element << "->";
        ptr = ptr->prev;
    }
    cout << head->element << endl;
}
