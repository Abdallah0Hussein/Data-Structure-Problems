#include <bits/stdc++.h>
using namespace std;

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
class Stack
{
private:
    int size;
    int top;
    int *array;

public:
    Stack(int size) : size(size), top(-1)
    {
        array = new int[size];
    }
    bool isEmpty()
    {
        return top == -1;
    }
    void push(int item)
    {
        array[++top] = item;
    }
    int pop()
    {
        if (top == -1)
        {
            throw runtime_error("Stack is empty");
        }
        return array[top--];
    }
    int peek()
    {
        return array[top];
    }
};

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
class Queue // circular
{
private:
    int size;
    int front;
    int rear;
    int added_items;
    int *array;

public:
    Queue(int sz) : front(0), rear(0), added_items(0), size(sz)
    {
        array = new int[sz];
    }

    int next(int position)
    {
        ++position;
        if (position == size)
        {
            position = 0; // reset position for circular queue
        }
        return position;
    }

    void enqueue(int item)
    {
        array[rear] = item;
        rear = next(rear);
        ++added_items;
    }

    int dequeue()
    {
        int value = array[front];
        --added_items;
        front = next(front);
        return value;
    }

    int frontt()
    {
        return array[front];
    }
};
class Q_Linked_List
{
private:
    Node *head;

public:
    Q_Linked_List() : head(nullptr) {}
    void add(int value) // add end
    {
        if (head == nullptr)
        {
            Node *new_node = new Node(value);
            head = new_node;
            new_node->next = nullptr;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            Node *new_node = new Node(value);
            current->next = new_node;
            new_node->next = nullptr;
        }
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

// int main()
// {
//     // Queue q(5);
//     // q.enqueue(2);
//     // q.enqueue(5);
//     // for (int i = 0; i < 2; ++i)
//     // {
//     //     cout << q.frontt() << endl;
//     //     q.dequeue();
//     // }

//     Linked_List lst;
//     lst.add(2);
//     lst.add(5);
//     lst.add(6);
//     lst.pop();
//     lst.print();
// }

class Linked_List
{
private:
    Node *head;
    Node *tail;

public:
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
// int main()
// {
//     Linked_List list;
//     list.insert_end(2);
//     list.insert_end(3);
//     list.insert_end(5);
//     list.insert_end(6);
//     list.insert_end(4);
//     list.delete_val(5);
//     list.delete_val(6);
//     // list.delete_end();
//     //     list.insert_front(1);
//     //     list.insertion(7,2);
//     list.print();
//     //     cout << '\n';
//     //     list.search(4);
//     //     Node *node1 = new Node(2);
//     //     Node *node2 = new Node(4);
//     //     Node *node3 = new Node(6);
//     //     Node *node4 = new Node(8);

//     //     node1->next = node2;
//     //     node2->next = node3;
//     //     node3->next = node4;
//     //     node4->next = nullptr;
// }

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

int main()
{
    D_Linked_List list;
    // list.insert_end(5);
    // list.insert_end(4);
    // list.insert_end(3);
    list.insert_front(4);
    list.insert_front(3);
    list.insert_front(2);
    // list.insertion(1, 1);
    // list.insertion(3, 2);
    // list.delete_end();
    // list.delete_front();
    // list.delete_val(3);
    // list.reverse();
    list.print();
}