#include <iostream>
#include <vector>
#include <stdarg.h>
#include "Containers.cpp"

using namespace std;

void MergeLists5(Linked_List& newList, Linked_List& list1, Linked_List& list2);
void MergeLists(Linked_List& newList, int nParam, ...);
int main()
{
  Linked_List nwList;
  Linked_List list1;
  Linked_List list2;
  Linked_List list3;

  list1.insert_end(1);
  list1.insert_end(4);
  list1.insert_end(5);
  list2.insert_end(1);
  list2.insert_end(3);
  list2.insert_end(4);
  list3.insert_end(2);
  list3.insert_end(6);
  // MergeLists5(nwList, list1, list3);
  MergeLists(nwList, 3 , list1, list2, list3);
  nwList.print();
}

void MergeLists5(Linked_List& newList, Linked_List& list1, Linked_List& list2)
{
  vector<int> listVec;
  //[1, 4, 5], [1, 3, 4], [2, 6]
  Node* cursor1 = list1.head;
  Node* cursor2 = list2.head;

  for (int i = 0; i < 3; i++)
  {
    if (cursor1 != NULL)
    {
      listVec.push_back(cursor1->value);
      cursor1 = cursor1->next;
    }

    if (cursor2 != NULL)
    {
      listVec.push_back(cursor2->value);
      cursor2 = cursor2->next;
    }

    sort(listVec.begin(), listVec.end());

    for(int val : listVec)
    {
      newList.insert_end(val);
    }
    listVec.clear();
  }
}

void MergeLists(Linked_List& newList, int nParam, ...)
{
  vector<int> listVec;
  Linked_List cursor;

  // Type to hold information about variable arguments
  va_list args, argsCopy;
  // Initializes args to retrieve the additional arguments after parameter "nParam".
  va_start(args, nParam);

  // // Copy "args" list (with current state) into "argsCopy".
  // va_copy(argsCopy, args);
  // for (int i = 0; i < nParam; i++)
  // {
  //   listVec.push_back(va_arg(argsCopy, Linked_List).size());
  // }
  // int maxSize = *max_element(listVec.begin(), listVec.end());
  // listVec.clear();
  // va_end(argsCopy);

  for (int i = 0; i < 3; i++) //maxSize
  {
    //[1, 4, 5], [1, 3, 4], [2, 6]
    for (int i = 0; i < nParam; i++)
    {
      Linked_List cursor(va_arg(args, Linked_List));
      if (cursor.head != NULL)
      {
        listVec.push_back((cursor.head)->value);
        cursor.delete_front();
      }
    }

    va_end(args);
    va_start(args, nParam);

    sort(listVec.begin(), listVec.end());

    for(int val : listVec)
    {
      newList.insert_end(val);
    }
    listVec.clear();
  }
  va_end(args);
}