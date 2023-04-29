#include <iostream>
#include "Containers.cpp"

template <typename type>
class StackUsingQ
{
private:
  int size;
  Queue<type> queue;
public:
  
  // StackUsingQ(Queue<type> queue) : size(queue.queueSize())
  // {
  //   this->queue = queue;
  // }
  StackUsingQ() : size(0){}

  void print()
  {
    queue.print();
  }

  void push(type value)
  {
    queue.enqueue(value);
    ++size;
  }

  type pop()
  {
    // Exception for poping an empty stack
    if (size == 0)
    {
      throw std::out_of_range("\n\t\t\t*** This stack is empty ***");
    }

    Queue<type> Q(size - 1);
    // Intialize "element"
    type element = queue.first();
    for (int i = 0; i < size; i++)
    {
      // Dequeue the last element form this->queue and storing it at "element"
      if (i == (size - 1))
      {  
        element = queue.dequeue();
      }
      else
      {
        // Copying all elements of the "queue" except the last element into "Q" 
        // By dequeuing elements of the "queue" and enqueuing them into "Q"
        Q.enqueue(queue.dequeue());      
      }
    }

    for (int i = 0; i < size - 1; i++)
    {
      // Restore all elements of the "queue" except the last element FROM "Q"
      queue.enqueue(Q.dequeue());      
    }
    --size;
    return element;
  }
};

int main()
{
  StackUsingQ<int> stack;
  stack.push(1);
  stack.push(5);
  stack.push(3);
  stack.push(9);
  cout << stack.pop() << endl;
  stack.print();
}