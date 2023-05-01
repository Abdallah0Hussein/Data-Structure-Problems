#include <bits/stdc++.h>
#include "Containers.cpp"

using namespace std;

template <typename T>


void sortQueue(Queue<int> &q);
void sortQueue(Queue<char>& q);

int main()
{
    Queue<char> q;
    q.enqueue('z');
    q.enqueue('b');
    q.enqueue('c');
    q.enqueue('m');
    sortQueue(q);
    q.print();
}


void sortQueue(Queue<int>& q)
{
    // A temporary queue to store the sorted elements
    Queue<int> sortedQueue(q.queueSize());

    // Minimum element to locate minimum elements in order to store
    int min;

    int size = q.queueSize();
    // Looping over all elements to store it
    for (int i = 0; i < size;i++)
    {    
        // Reset the "min" to be the Biggest value of current data type
        min = INT_MAX;

        // Dequeuing the minimum element each time and store it in the "sortedqueue"
        for (int j = 0; j < size - i; j++)
        {
            int element = q.dequeue();
            // If the "element" is less than the "min", let the "min" be this "element"
            if (min > element)
            {
            /*
                IF we found an "element" less than "min" (and the min was holding an element from the queue) 
                So restore(enqueuing it again to the queue) the "min" to the queue to put it in its right order in another iteration.
                But Do not put the intial value of min into the queue as it was NOT part of it
            */ 
                if (min != INT_MAX)
                {
                    q.enqueue(min);
                }
                min = element;
                // Continue Looping without restoring the "element" again to the queue
                continue;
            }
            // Restoring the element again to the queue as it's not the minimum element yet
            q.enqueue(element);
        } 
        // enqueue the minimum element of the current iteration
        sortedQueue.enqueue(min);
    }
    // Move the sortedqueue to the q to save space
    q = move(sortedQueue);
}

void sortQueue(Queue<char>& q)
{
    Queue<char> sortedQueue(q.queueSize());
    char min;
    int size = q.queueSize();
    for (int i = 0; i < size;i++)
    {    
        min = CHAR_MAX;
        for (int j = 0; j < size - i; j++)
        {
            int element = q.dequeue();
            if (min > element)
            {
                if (min != CHAR_MAX)
                {
                    q.enqueue(min);
                }
                min = element;
                continue;
            }
            q.enqueue(element);
        } 
        sortedQueue.enqueue(min);
    }
    q = move(sortedQueue);
}

