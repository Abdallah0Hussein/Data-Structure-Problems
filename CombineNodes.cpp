#include <iostream>
#include "Containers.cpp"

using namespace std;

void combineNodes(Node* head, Linked_List& newList);

int main()
{
  Linked_List list;
  Linked_List newList;
  list.insert_end(0);
  list.insert_end(3);
  list.insert_end(1);
  list.insert_end(0);
  list.insert_end(4);
  list.insert_end(5);
  list.insert_end(2);
  list.insert_end(0);
  combineNodes(list.head, newList);
  list.print();
  cout << "\n-------------------------\n";
  newList.print();
}

// Take the original linked list head and combine its the nodes between zeros into the newList
void combineNodes(Node* head, Linked_List& newList)
{
  //Linked_List newList;
  int element = 0;

  // [0, 3, 1, 0, 4, 5, 2, 0]
  while (head->next != NULL)
  {
    if ((head->next)->value == 0)
    {
      // Combine the current node value with the value of the 'element'
      // Then Insert it into the list then reset the 'element' value
      element += head->value;
      newList.insert_end(element);
      element = 0;
      }
      else
      {
        element += head->value;
      }
    head = head->next;
  }
}