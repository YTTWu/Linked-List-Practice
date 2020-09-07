//
//  main.cpp
//  Linked List Practice
//
//  Created by yuteng Wu on 9/6/20.
//  Copyright © 2020 Yuteng Wu. All rights reserved.
//

#include <iostream>

using namespace std;

template<class T>
class Node
{
private:
   T data;
   Node<T> *next;

public:
   Node();
   void insert(T x);
   void display();
   void insertAt(T data, int position);
   void deleteNode(int position);
};


// global variable
template<class T>
Node<T> *head;


int main() {

   Node<int> node;

   /*
   node.insertAt(1, 1);
   node.insertAt(2, 2);
   node.insertAt(3, 3);

   node.display();

   node.insertAt(4, 1);
   node.insertAt(5, 2);

   node.display();
*/
   node.insert(1);
   node.insert(2);
   node.insert(3);
   node.insert(4);

   node.display();

   node.deleteNode(4);

   node.display();




}


template<class T>
Node<T>::Node(){}



template<class T>
void Node<T>::insertAt(T data, int position)
{
   int x = 2;
   Node<T> *temp = head<T>;
   Node<T> *newNode = new Node();//-----------------Node<T> *newNode;
   newNode->data = data;
   newNode->next = NULL;

   if(position == 1)
   {
      newNode->next = temp;
      head<T> = newNode;
      return;
   }
   else
   {
      while(temp != NULL)
      {
         if(x == position)
         {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
         }
         x++;
         temp = temp->next;
      }
   }
}




template<class T>
void Node<T>::insert(T x)
{
   Node<T> *temp = new Node();
   Node<T> *newNode = new Node();

   if(head<T> == NULL)
   {
      temp->data = x;
      temp->next = NULL;
      head<T> = temp;
      return;
   }

   temp = head<T>;
   while(temp != NULL)
   {

      if(temp->next == NULL)
      {

         newNode->data = x;
         newNode->next = NULL;
         temp->next = newNode;
         return;

      }
      temp = temp->next;

   }

}



template<class T>
void Node<T>::deleteNode(int position)
{
   int x = 1;
   Node<T> *temp = new Node();
   temp = head<T>;


   if(position == 1)
   {
      head<T> = temp->next;
      delete temp;
   }
   else
   {
      while(temp != NULL)
      {

         if(x == position-1)
         {
            temp->next = temp->next->next;
            delete temp;
            return;
         }
         x++;
         temp = temp->next;
      }
   }
}





template<class T>
void Node<T>::display()
{
   Node<T> *temp = head<T>;
   cout << "List is: ";
   while(temp != NULL)
   {
      cout << temp->data << " ";
      temp = temp->next;
   }
   cout << endl;
}
