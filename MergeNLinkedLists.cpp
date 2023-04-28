#include <iostream>
#include <vector>
#include <stdarg.h>
#include "Containers.cpp"

using namespace std;

template <typename type>
void Merge2Lists(SLL<type>& newList, SLL<type>& list1, SLL<type>& list2);

template <typename type>
void MergeLists(SLL<type>& newList, int nParam, ...);


int main()
{
  SLL<int> nwList;
  SLL<int> list1;
  SLL<int> list2;
  SLL<int> list3;

  list1.insertAtTail(1);
  list1.insertAtTail(4);
  list1.insertAtTail(5);
  list2.insertAtTail(1);
  list2.insertAtTail(3);
  list2.insertAtTail(4);
  list3.insertAtTail(2);
  list3.insertAtTail(6);
  // MergeLists5(nwList, list1, list3);
  MergeLists(nwList, 3 , list1, list2, list3);
  nwList.print();
}
template <typename type>
void Merge2Lists(SLL<type>& newList, SLL<type>& list1, SLL<type>& list2)
{
  vector<int> listVec;
  //[1, 4, 5], [1, 3, 4], [2, 6]
  node<type>* cursor1 = list1.head;
  node<type>* cursor2 = list2.head;

  for (int i = 0; i < 3; i++)
  {
    if (cursor1 != NULL)
    {
      listVec.push_back(cursor1->element);
      cursor1 = cursor1->next;
    }

    if (cursor2 != NULL)
    {
      listVec.push_back(cursor2->element);
      cursor2 = cursor2->next;
    }

    sort(listVec.begin(), listVec.end());

    for(int val : listVec)
    {
      newList.insertAtTail(val);
    }
    listVec.clear();
  }
}
template <typename type>
void MergeLists(SLL<type>& newList, int nParam, ...)
{
  vector<int> listVec;
  SLL<type> currList;

  // Type to hold information about variable arguments
  va_list args;
  // Initializes args to retrieve the additional arguments after parameter "nParam".
  va_start(args, nParam);

  for (int i = 0; i < nParam; i++)
  {
    // Get the next list stored in variable list 'args'  
    // Every time you call this function, it returns the next element in the variable list "args"
    currList = va_arg(args, SLL<type>);
    // Looping over the list to store its elements into "listVec" vector 
    while (currList.head != NULL)
    {
      listVec.push_back(currList.head->element);
      currList.head = currList.head->next;
    }
  }

  sort(listVec.begin(), listVec.end());

  for(int& val : listVec)
  {
    newList.insertAtTail(val);
  }
  listVec.clear();

  // Terminate variable list
  va_end(args);
}
  // Copy "args" list (with current state) into "argsCopy".
  // va_copy(argsCopy, args);
  // for (int i = 0; i < nParam; i++)
  // {
  //   listVec.push_back(va_arg(argsCopy, SLL<type>).linkedListSize());
  // }
  // int maxSize = *max_element(listVec.begin(), listVec.end());
  // listVec.clear();
  // va_end(argsCopy);