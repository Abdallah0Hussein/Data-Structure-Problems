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

struct Node
{
    int value;
    Node *next;
    Node(int value) : value(value) {}
};
class Stack_Linked_List
{
private:
    Node *head;

public:
    Stack_Linked_List() : head(nullptr) {}
    void add(int value) // add front
    {
        Node *new_node = new Node(value);
        new_node->next = head;
        head = new_node;
    }
    int pop() // pop front
    {
        if (head == nullptr)
        {
            throw runtime_error("List is empty");
        }
        Node *new_node = head->next;
        int removed_value = head->value;
        delete head;
        head = new_node;
        return removed_value;
    }
    void print()
    {
        Node *tmp = head;
        while (tmp != nullptr)
        {
            cout << tmp->value << " ";
            tmp = tmp->next;
        }
    }
};
template <typename type>
class Stack
{
private:
    int size;
    int maxSize = 10;
    type *arr = new type[size];

public:
    Stack(int n)
    {
        maxSize = n;
    }
    Stack()
    {
        size = 0;
    }
    void push(type ele)
    {
        if (size >= maxSize)
        {
            maxSize *= 2;
        }
        arr[size] = ele;
        size++;
    }
    type pop()
    {
        type e = arr[size - 1];
        if (size == 0)
        {
            cout << "\n\t\t\t*** This stack is empty ***" << endl;
        }
        else
        {
            size--;
        }
        return e;
    }
    type top()
    {
        if (size == 0)
        {
            cout << "\n\t\t\t*** This stack is empty ***" << endl;
        }
        return arr[size - 1];
    }
    bool isEmpty()
    {
        return arr.size() == 0;
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
            cout << "\n\t\t\t*** This stack is empty ***" << endl;
            return;
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

// class Stack
// {
// private:
//     int size;
//     int top;
//     int *array;

// public:
//     Stack() : size(0), top(-1), array(nullptr) {}
//     Stack(int size) : size(size), top(-1)
//     {
//         array = new int[size];
//     }
//     bool isEmpty()
//     {
//         return top == -1;
//     }
//     void push(int item)
//     {
//         if (top == size - 1)
//         {
//             int *new_array = new int[size * 2];
//             for (int i = 0; i < size; i++)
//             {
//                 new_array[i] = array[i];
//             }
//             delete[] array;
//             array = new_array;
//             size *= 2;
//         }
//         array[++top] = item;
//     }
//     int pop()
//     {
//         if (top == -1)
//         {
//             throw runtime_error("Stack is empty");
//         }
//         return array[top--];
//     }
//     int peek()
//     {
//         return array[top];
//     }
// };

// int main()
// {
//     // Stack stck(3);
//     // stck.push(2);
//     // stck.push(4);
//     // stck.push(3);
//     // for (int i = 0; i < 3; ++i)
//     // {
//     //     cout << stck.peek() << endl;
//     //     stck.pop();
//     // }
//     Stack_Linked_List lst;
//     lst.add(2);
//     lst.add(4);
//     lst.add(4);
//     lst.pop();
//     lst.add(3);
//     lst.print();
// }
template <typename type>
class Queue
{
private:
    int size;
    type *arr = new type[size];

public:
    Queue()
    {
        size = 0;
    }
    void enqueue(type ele)
    {

        arr[size] = ele;
        size++;
    }
    type first()
    {

        // cout << "first : " << head->element << endl;
        // cout << "inside : " << endl;
        // print();
        if (size == 0)
        {
            cout << "\n\t\t\t*** This queue is empty ***\n"
                 << endl;
        }
        return arr[0];
    }
    type dequeue()
    {
        type e = arr[0];
        if (size == 0)
        {
            cout << "\n\t\t\t*** This queue is empty ***\n";
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
            cout << "\n\t\t\t*** This queue is empty ***\n"
                 << endl;
            return;
        }
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
};

template <typename type>
struct node
{
    type element;
    node<type> *next;
    node(type element) : element(element) {}
    node() : next(NULL) , element(0) {}
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
    SLL<type>& operator=(const SLL<type> anotherSLL);
   // SLL(const SLL<type> anotherSLL);
    void insertAtHead(type ele);
    void insertAtTail(type ele);
    void insertAt(type ele, int index);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    type retrieveAt(int index);
    void replaceAt(type ele, int index);
    bool isExit(type ele);
    bool isItemAtEqual(type ele, int index);
    bool isEmpty();
    int linkedListSize();
    void clear();
    void print();
};

template <typename type>
SLL<type>& SLL<type>::operator=(const SLL<type> anotherSLL)
{
    if (this != &anotherSLL)
    {
        delete head;
        delete tail;
        head = new node<type>;
        tail = new node<type>;
        head = tail = nullptr;
        node<type>* current = anotherSLL.head;

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
bool SLL<type>::isExit(type ele)
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

class Linked_List
{
private:
    Node *tail;

public:
    Node *head;
    void print();
    void insert_end(int value);
    Linked_List() : head(nullptr), tail(nullptr) {}
    void search(int value);
    ~Linked_List();
    void insert_front(int value);
    void delete_front();
    void delete_end();
    void delete_val(int value);
    void insertion(int value, int index);
};
void Linked_List::delete_val(int value)
{
    Node *current = head;
    Node *previous = nullptr;
    while (current != nullptr)
    {
        if (current->value == value)
        {
            previous->next = current->next;
            delete current;
            current = previous->next;
            break;
        }
        previous = current;
        current = current->next;
    }
}
void Linked_List::insertion(int value, int index)
{
    Node *new_node = new Node(value);
    Node *current = head;
    index--;
    while (current != nullptr && index != 0)
    {
        current = current->next;
        // cout << head->next << '\n';
        index--;
    }
    new_node->next = current->next;
    current->next = new_node;
}
void Linked_List::delete_end()
{
    if (head == nullptr)
    {
        // Empty list
        return;
    }
    else if (head == tail)
    {
        // Only one node in the list
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        Node *current = head;
        while (current->next != tail)
        {
            current = current->next;
        }
        delete tail;
        tail = current;
        current->next = nullptr;
    }
}

void Linked_List::delete_front()
{
    Node *new_node = head->next;
    delete head;
    head = new_node;
}

void Linked_List::insert_front(int value)
{
    Node *new_node = new Node(value);
    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
}
Linked_List::~Linked_List()
{
    while (head != nullptr)
    {
        Node *current = head->next;
        delete head;
        head = current;
    }
    head = tail = nullptr;
}
void Linked_List::print()
{
    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
}

void Linked_List::insert_end(int value)
{
    Node *new_node = new Node(value);
    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
        tail->next = nullptr;
    }

    else
    {
        tail->next = new_node;
        tail = new_node;
        new_node->next = nullptr;
    }
}
void Linked_List::search(int value)
{
    int counter = 0;
    for (Node *node = head; node != nullptr; node = node->next, ++counter)
    {
        if (node->value == value)
        {
            cout << counter << " ";
        }
    }
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
    int doubleLinkedListSize();
    void removeAtHead();
    void removeAtTail();
    bool isEmpty();
    void clear();
    void print();
    // not compelte
    void removeAt(int index);
    type retrieveAt(int index);
    void replaceAt(type ele, int index);
    bool isExit(type ele);
    bool isItemAtEqual(type ele, int index);
    void reverse();
    void forwardTraversal();
    // problem
    void backwardTraversal();
};
template <typename type>
void DLL<type>::print()
{
    D_node<type> *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->element << " ";
        tmp = tmp->next;
    }
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
    if (index >= size)
    {
        cout << "\n\t\t\t*** out of bounds ***\n";
        return;
    }
    else if (index == 0)
    {
        insertAtHead(ele);
    }
    else if (index == size - 1)
    {
        insertAtTail(ele);
    }
    else
    {
        int counter = 0;
        D_node<type> *ptr = head;
        D_node<type> *newNode = new D_node<type>(ele);
        for (int i = 1; i < index; i++)
        {
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        newNode->prev = ptr;
        ptr->next->prev = newNode;
        ptr->next = newNode;
    }
    size++;
}
template <typename type>
void DLL<type>::removeAtHead()
{
    if (head == NULL)
    {
        cout << "\n\t\t\t*** This list is empty ***\n"
             << endl;
        return;
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
        cout << "\n\t\t\t*** This list is empty ***\n"
             << endl;
        return;
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
// not compelte
void DLL<type>::removeAt(int index)
{
    if (index >= size)
    {
        cout << "\n\t\t\t*** out of bounds ***\n";
        return;
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
        int counter = 0;
        D_node<type> *ptr = head->next;
        D_node<type> *ptrN;
        for (int i = 1; i < index; i++)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }
    size--;
}
template <typename type>
type DLL<type>::retrieveAt(int index)
{
    // zero based
    type e;
    if (size <= index)
    {
        // cout << "\n\t\t\t*** out of bounds ***\n" << endl;
        return e;
    }
    D_node<type> *ptr = head;
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
void DLL<type>::replaceAt(type ele, int index)
{
    // zero based
    if (size <= index)
    {
        cout << "\n\t\t\t*** out of bounds ***\n"
             << endl;
        return;
    }
    D_node<type> *ptr = head;
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
bool DLL<type>::isExit(type ele)
{
    // zero based
    D_node<type> *ptr = head;
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
bool DLL<type>::isItemAtEqual(type ele, int index)
{
    D_node<type> *ptr = head;
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
void DLL<type>::reverse()
{
    D_node<type> *start = head;
    int count = 0;
    D_node<type> *end = tail;
    // cout << "size : " << size << endl;
    while (count < size)
    {
        swap(start->element, end->element);
        start = start->next;
        end = end->prev;
        count += 2;
    }
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
struct D_Node
{
    int value;
    D_Node *next;
    D_Node *prev;
    D_Node(int value) : value(value) {}
};
class D_Linked_List
{
private:
    D_Node *head;
    D_Node *tail;

public:
    D_Linked_List() : head(nullptr), tail(nullptr) {}
    ~D_Linked_List();
    void print();
    void insert_end(int value);
    void insert_front(int value);
    void insertion(int value, int index);
    void delete_end();
    void delete_front();
    void delete_val(int value);
    void reverse();
};
void D_Linked_List::reverse()
{
    D_Node *current = head;
    while (current != nullptr)
    {
        swap(current->next, current->prev);
        current = current->prev;
    }
    swap(head, tail);
}

void D_Linked_List::delete_val(int value)
{
    D_Node *current = head;
    while (current != nullptr)
    {
        if (current->value == value)
        {
            D_Node *tmp = current;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            current = current->next;
            delete tmp;
        }
        current = current->next;
    }
}
void D_Linked_List::delete_front()
{
    D_Node *current = head->next;
    delete head;
    head = current;
    head->prev = nullptr;
}
void D_Linked_List::delete_end()
{
    D_Node *current = tail->prev;
    delete tail;
    current->next = nullptr;
    tail = current;
}
void D_Linked_List::insertion(int value, int index)
{
    D_Node *current = head;
    while (current != nullptr && index > 0)
    {
        index--;
        current = current->next;
    }
    D_Node *new_node = new D_Node(value);
    new_node->prev = current->prev;
    new_node->next = current;
    current->prev->next = new_node;
    current->prev = new_node;
}

void D_Linked_List::insert_front(int value)
{
    D_Node *new_node = new D_Node(value);
    if (head == nullptr)
    {
        head = tail = new_node;
        tail->next = nullptr;
        head->prev = nullptr;
    }
    else
    {
        new_node->next = head;
        new_node->prev = nullptr;
        head->prev = new_node;
        head = new_node;
    }
}
D_Linked_List::~D_Linked_List()
{
    while (head != nullptr)
    {
        D_Node *tmp = head->next;
        delete head;
        head = tmp;
    }
    head = tail = nullptr;
}
void D_Linked_List::insert_end(int value)
{
    D_Node *new_node = new D_Node(value);
    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
        tail->next = nullptr;
        head->prev = nullptr;
    }
    else
    {
        new_node->prev = tail;
        new_node->next = nullptr;
        tail->next = new_node;
        tail = new_node;
    }
}
void D_Linked_List::print()
{
    D_Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
}

// int main()
// {
//     D_Linked_List list;
//     // list.insert_end(5);
//     // list.insert_end(4);
//     // list.insert_end(3);
//     list.insert_front(4);
//     list.insert_front(3);
//     list.insert_front(2);
//     // list.insertion(1, 1);
//     // list.insertion(3, 2);
//     // list.delete_end();
//     // list.delete_front();
//     // list.delete_val(3);
//     // list.reverse();
//     list.print();
// }