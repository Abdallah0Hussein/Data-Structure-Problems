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
    int maxSize;
    type *arr;

public:
    Stack(int maxSize) : maxSize(maxSize), size(0)
    {
        arr = new type[maxSize];
    }
    Stack() : size(0), maxSize(10)
    {
        arr = new type[maxSize];
    }
    void push(type ele)
    {
        if (size == maxSize)
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
        if (size < (maxSize / 4)) // Shrink the array when it's only 25% full
        {
            maxSize /= 2;
            type *new_arr = new type[maxSize];
            for (int i = 0; i < size; i++)
            {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
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
            cout << "\n\t\t\t*** This stack is empty ***";
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
    int maxSize;
    type *arr;

public:
    Queue() : size(0), maxSize(10)
    {
        arr = new type[maxSize];
    }

    Queue(int maxSize) : maxSize(maxSize), size(0)
    {
        arr = new type[maxSize];
    }
    void enqueue(type ele)
    {
        if (size == maxSize)
        {
            maxSize *= 2;
            type *new_arr = new type[maxSize];
            for (int i = 0; i < size; i++)
            {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
        }
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
            for (size_t i = 0; i < size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            size--;
            if (size < (maxSize / 4)) // Shrink the array when it's only 25% full
            {
                maxSize /= 2;
                type *new_arr = new type[maxSize];
                for (int i = 0; i < size; i++)
                {
                    new_arr[i] = arr[i];
                }
                delete[] arr;
                arr = new_arr;
            }
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
            cout << "\n\t\t\t*** This queue is empty ***\n";
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
// **Single Linked List

template <typename type>
class SLL
{
private:
    int size;
    // Swap first node with Idx's node
    void swap(int Idx);
    void adjacentSwap(int firstIdx, int secondIdx);
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
    void swap(int firstIdx, int secondIdx);
};

template <typename type>
void SLL<type>::swap(int firstIdx, int secondIdx)
{
    if (firstIdx < 0 || secondIdx < 0 || firstIdx >= size || secondIdx >= size)
    {
        throw std::out_of_range("\n\t\t\t*** Out Of bounds ***\n");
        return;
    }
    if (firstIdx == secondIdx)
    {
        throw std::invalid_argument("Can't swap the same node with itself");
        return;
    }

    // If the two nodes are adjacent
    if (abs(firstIdx - secondIdx) == 1)
    {
        adjacentSwap(firstIdx, secondIdx);
        return;
    }
    // Swapping secondIdx node with the head node (first node)
    if (firstIdx == 0)
    {
        swap(secondIdx);
        return;
    }
    // Swapping firstIdx node with the head node (first node)
    else if (secondIdx == 0)
    {
        swap(firstIdx);
        return;
    }

    // Pointer to the Back node of firstIdx node
    node<type> *cursorB1 = this->head;
    // Pointer to the firstIdx node
    node<type> *cursor1 = nullptr;
    // Pointer to the next(After) node of firstIdx node
    node<type> *cursorAf1 = nullptr;

    // Pointer to the Back node of secondIdx node
    node<type> *cursorB2 = this->head;
    // Pointer to the secondIdx node
    node<type> *cursor2 = nullptr;
    // Pointer to the next(After) node of secondIdx node
    node<type> *cursorAf2 = nullptr;


    /*
        Making cursorB1 pointing at "firstIdx - 1" node by incrementing it by (firstIdx - 1),
        'cause the cursorB1 poiting at the head in the intial state
    */ 
    for (int i = 0; i < firstIdx - 1; i++)
    {
        cursorB1 = cursorB1->next;
    }
    // Inialize the cursors
    cursor1 = cursorB1->next;
    cursorAf1 = cursor1->next;

    // Same as above
    for (int i = 0; i < secondIdx - 1; i++)
    {
        cursorB2 = cursorB2->next;
    }
    cursor2 = cursorB2->next;
    cursorAf2 = cursor2->next;

    /*
    Swapping nodes by change the Back(previous) and After(next) nodes
    of the firstIdx node with the Back(previous) and After(next) nodes of secondIdx node
    */  
    cursorB1->next = cursor2;
    cursor2->next = cursorAf1;
    cursorB2->next = cursor1;
    cursor1->next = cursorAf2;

    // If the cursor1 or cursor2 was the last node then make the tail pointing at it
    if (cursor1->next == NULL)
    {
        tail = cursor1;
    }
    else if(cursor2->next == NULL)
    {
        tail = cursor2;
    } 
}

template <typename type>
void SLL<type>::adjacentSwap(int firstIdx, int secondIdx)
{
    /*
        If the first Index was higher than the second Index 
        Then swapping the values to make it easy to swap nodes
    */ 
    if (firstIdx > secondIdx)
    {
        swap(firstIdx, secondIdx);
    }

/* 
--  Here we need only cursor to the previous node of the firstIdx node 
--  And a cursor to the next node of secondIdx node, 'cause the two nodes are adjacent
*/
    node<type>* cursorB1 = this->head;
    node<type>* cursor1 = nullptr;
    
    node<type>* cursor2 = this->head;
    node<type>* cursorAf2 = nullptr;

    for (int i = 0; i < secondIdx; i++)
    {
        cursor2 = cursor2->next;
    }
    cursorAf2 = cursor2->next;

    // Checking if the firstIdx node (remember: firstIdxit is the lower index now) is first (head) node or not
    if (firstIdx == 0)
    {
    /*
    -- Swapping the head node with secondIdx node by making the head pointer points at the second node and first node poiting at the third node
    -- and the second node poiting at first node 
    */ 
        cursor1 = this->head;
        this->head = cursor2;
        cursor2->next = cursor1;
        cursor1->next = cursorAf2;
        return;
    }
    //Else Intialize the previous node of secondIdx node
    for (int i = 0; i < firstIdx - 1; i++)
    {
        cursorB1 = cursorB1->next;
    }
    cursor1 = cursorB1->next;

    /*
    -- Swapping the two adjacent nodes
    -- By Making the previous of firstIdx node pointing at the secondIdx node
    -- and the secondIdx node points at the firstIdx node and the firstIdx node points at the nextnode of the secondIdx node
    */
    cursorB1->next = cursor2;
    cursor2->next = cursor1;
    cursor1->next = cursorAf2;

    // Checking if the cursor1 was the last node to make the tail points at it
    if (cursor1->next == NULL)
    {
        tail = cursor1;
    } 
}

template <typename type>
// Swapping the head node with Idx node
void SLL<type>::swap(int Idx)
{
    node<type> *cursor1 = this->head;
    node<type> *cursorAf1 = cursor1->next;

    node<type> *cursorB2 = this->head;
    node<type> *cursor2 = nullptr;
    node<type> *cursorAf2 = nullptr;

    for (int i = 0; i < Idx - 1; i++)
    {
        cursorB2 = cursorB2->next;
    }
    cursor2 = cursorB2->next;
    cursorAf2 = cursor2->next;

    /*
    -- Swapping the head node with secondIdx node by making the head pointer points at the second node and first node poiting at the next node of the Idx node
    -- and the Idx node poiting at first node 
    */ 
    this->head = cursor2;
    cursor2->next = cursorAf1;
    cursorB2->next = cursor1;
    cursor1->next = cursorAf2;

    // Checking if the cursor1 was the last node to make the tail points at it
    if (cursor1->next == NULL)
    {
        tail = cursor1;
    }
}

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
        newNode->next = nullptr;
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
    if (index >= size)
    {
        throw std::out_of_range("\n\t\t\t*** Out Of bounds ***\n");
    }
    if (index == 0)
    {
        removeAtHead();
        return;
    }
    if (index == (size - 1))
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
        throw std::out_of_range("\n\t\t\t*** Out of bound ***\n");
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
    node<type> *ptr = this->head;
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

// Double Linked List
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
    void swap(int firstItemIdx, int secondItemIdx);
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
template <typename type>
void DLL<type>::swap(int firstItemIdx, int secondItemIdx)
{
    if (firstItemIdx < 0 || secondItemIdx < 0 || firstItemIdx >= size || secondItemIdx >= size)
        throw std::out_of_range("\n\t\t\t*** Out Of bounds ***\n");
    if (firstItemIdx == secondItemIdx)
    {
        throw std::invalid_argument("Can't swap the same node with itself");
    }
    D_node<type> *firstNode = head;
    for (int i = 0; i < firstItemIdx; i++)
    {
        firstNode = firstNode->next;
    }

    D_node<type> *secondNode = head;
    for (int i = 0; i < secondItemIdx; i++)
    {
        secondNode = secondNode->next;
    }
    // Swap previous and next pointers
    std::swap(firstNode->next, secondNode->next);
    std::swap(firstNode->prev, secondNode->prev);

    // Update prev pointers of adjacent nodes
    if (firstNode->prev != nullptr)
        firstNode->prev->next = firstNode;

    if (secondNode->prev != nullptr)
        secondNode->prev->next = secondNode;

    // Update prev pointers of adjacent nodes
    if (firstNode->next != nullptr)
        firstNode->next->prev = firstNode;

    if (secondNode->next != nullptr)
        secondNode->next->prev = secondNode;

    // if it's the head pointer
    if (firstNode == head)
        head = secondNode; // now head is the second node

    else if (secondNode == head) // using else if here to prevent the previous condition
                                 // as the previous condition make this condition always true
        head = firstNode;

    // if it's the tail pointer
    if (tail == firstNode)
        tail = secondNode; // now tail is the second node

    else if (tail == secondNode) // using else if here to prevent the previous condition
                                 // as the previous condition make this condition always true
        tail = firstNode;
}

int main()
{
    DLL<int> list;
    list.insertAtTail(10); // 0
    list.insertAtTail(20); // 1
    list.insertAtTail(30); // 2
    list.insertAtTail(40); // 3
    list.insertAtTail(50); // 4

    std::cout << "Before swapping: ";
    list.forwardTraversal();

    list.swap(2, 4);

    std::cout << "After swapping: ";
    list.backwardTraversal();

    return 0;
}

// Circular Linked List
template <typename type>
class circularSLL
{
private:
    int length;
    node<type> *head, *tail;

public:
    circularSLL()
    {
        clear();
    }
    int linkedListSize();
    bool isEmpty();
    void clear();
    void insertAtHead(type ele);
    void insertAtTail(type ele);
    void insertInMiddle(type ele, int index);
    void removeHead();
    void removeTail();
    void removeAt(int index);
    type retrieveAt(int index);
    void replaceAt(type ele, int index);
    bool isExit(type ele);
    bool isItemAtEqual(type ele, int index);
    void print();
};
template <typename type>
int circularSLL<type>::linkedListSize()
{
    return length;
}
template <typename type>
bool circularSLL<type>::isEmpty()
{
    return (length == 0);
}
template <typename type>
void circularSLL<type>::clear()
{
    tail = head = nullptr;
    length = 0;
}
template <typename type>
void circularSLL<type>::insertAtHead(type ele)
{
    node<type> *newNode = new node<type>(ele);
    if (head == nullptr)
    {
        head = tail = newNode;
        // tail = newNode;
        newNode->next = head;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    length++;
}
template <typename type>
void circularSLL<type>::insertAtTail(type ele)
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
        newNode->next = head;
        tail = newNode;
    }
    length++;
}
template <typename type>
void circularSLL<type>::insertInMiddle(type ele, int index)
{
    if (index > length || index < 0)
    {
        throw std::out_of_range("\n\t\t\tOut of bounds\n");
    }
    else
    {
        node<type> *newNode = new node<type>(ele);
        if (index == 0)
        {
            insertAtHead(ele);
        }
        else if (index == length)
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
            length++;
        }
    }
}
template <typename type>
void circularSLL<type>::removeHead()
{
    if (length == 0)
    {
        throw std::out_of_range("\n\t\t\t*** Empty linked list ***\n");
    }
    else if (length == 1)
    {
        delete head;
        head = tail = NULL;
    }
    else
    {
        node<type> *ptr = head;
        head = ptr->next;
        tail->next = head;
        delete ptr;
    }
    length--;
}
template <typename type>
void circularSLL<type>::removeTail()
{
    if (length == 0)
    {
        throw std::out_of_range("\n\t\t\t*** Empty linked list ***\n");
    }
    else if (length == 1)
    {
        delete head;
        head = tail = NULL;
    }
    else
    {
        node<type> *cur = head->next;
        node<type> *pre = head;
        int counter = length;
        while (counter > 1)
        {
            pre = cur;
            cur = cur->next;
            counter--;
        }
        delete cur;
        pre->next = head;
        tail = pre;
        delete pre;
    }
    length--;
}
template <typename type>
void circularSLL<type>::removeAt(int index)
{
    if (length == 0)
    {
        throw std::out_of_range("\n\t\t\t*** Empty linked list ***\n");
    }
    if (index >= length)
    {
        throw std::out_of_range("\n\t\t\t*** Out Of bounds ***\n");
    }
    if (index == 0)
    {
        removeHead();
        return;
    }
    else if (index == length - 1)
    {
        removeTail();
        return;
    }
    else
    {
        node<type> *cur = head->next;
        node<type> *pre = head;
        for (int i = 1; i < index; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        if (cur == tail)
        {
            tail = cur;
            tail->next = head;
        }
        else
            pre->next = cur->next;
        // cout << tail->next->element << " " << head->element << endl;
    }
    length--;
}
template <typename type>
type circularSLL<type>::retrieveAt(int index)
{
    // zero based
    type e;
    if (length <= index)
    {
        throw std::out_of_range("\n\t\t\t*** Out of bound ***\n");
    }
    node<type> *ptr = head;
    int counter = 0;
    int count = length;
    while (count)
    {
        if (counter == index)
        {
            e = ptr->element;
            break;
        }
        counter++;
        count--;
        ptr = ptr->next;
    }
    return e;
}
template <typename type>
void circularSLL<type>::replaceAt(type ele, int index)
{
    // zero based
    if (length <= index)
    {
        throw std::out_of_range("\n\t\t\t*** Out of bound ***\n");
    }
    node<type> *ptr = head;
    int counter = 0;
    int count = length;
    while (count)
    {
        if (counter == index)
        {
            ptr->element = ele;
            break;
        }
        counter++;
        count--;
        ptr = ptr->next;
    }
}
template <typename type>
bool circularSLL<type>::isExit(type ele)
{
    // zero based
    node<type> *ptr = head;
    int counter = length;
    while (counter)
    {
        if (ptr->element == ele)
        {
            return true;
        }
        counter--;
        ptr = ptr->next;
    }
    return false;
}
template <typename type>
bool circularSLL<type>::isItemAtEqual(type ele, int index)
{
    if (index >= length)
    {
        throw std::out_of_range("\n\t\t\t*** Out of bound ***\n");
    }
    node<type> *ptr = head;
    int counter = 0, size = length;
    while (size)
    {
        if (counter == index)
        {
            if (ptr->element == ele)
                return true;
        }
        counter++;
        size--;
        ptr = ptr->next;
    }
    return false;
}
template <typename type>
void circularSLL<type>::print()
{
    node<type> *ptr = head;
    int counter = length;
    while (counter)
    {
        if (counter == 1)
        {
            cout << ptr->element << endl;
            ;
            break;
        }
        cout << ptr->element << "->";
        ptr = ptr->next;
        counter--;
    }
}
