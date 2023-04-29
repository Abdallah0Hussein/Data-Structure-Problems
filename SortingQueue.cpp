#include <bits/stdc++.h>
#include "Containers.cpp"

using namespace std;

template <typename T>
void sortQueue(Queue<T> &q)
{
    vector<T> vec;
    // coping elements from queue to the vector and deleting queue elements
    while (!q.isEmpty())
    {
        vec.push_back(q.dequeue());
    }
    sort(vec.begin(),vec.end());
    // copying elements back from queue to the vector but sorted
    for(T i: vec){
        q.enqueue(i);
    }
}
int main()
{
    Queue<int> q;
    q.enqueue(9);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(1);
    sortQueue(q);
    q.print();
}