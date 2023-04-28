#include <iostream>
#include "Containers.cpp"

using namespace std;
template <typename type>
void combineNodes(node<type>* head, SLL<type>& newList);

int main()
{
  SLL<int> list;
  SLL<int> newList;
  list.insertAtTail(0);
  list.insertAtTail(3);
  list.insertAtTail(1);
  list.insertAtTail(0);
  list.insertAtTail(4);
  list.insertAtTail(5);
  list.insertAtTail(2);
  list.insertAtTail(0);
  combineNodes(list.head, newList);
  list.print();
  cout << "\n-------------------------\n";
  newList.print();
}

// Take the original linked list head and combine its the nodes between zeros into the newList
template <typename type>
void combineNodes(node<type>* head, SLL<type>& newList)
{
  //SLL<int> newList;
  int element = 0;

  // [0, 3, 1, 0, 4, 5, 2, 0]
  while (head->next != NULL)
  {
    if ((head->next)->element == 0)
    {
      // Combine the current node element with the element of the 'element'
      // Then Insert it into the list then reset the 'element' element
      element += head->element;
      newList.insertAtTail(element);
      element = 0;
      }
      else
      {
        element += head->element;
      }
    head = head->next;
  }
}