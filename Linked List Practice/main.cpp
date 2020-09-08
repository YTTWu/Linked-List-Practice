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
   Node<T> *head;

public:
   Node();
   void insert(T x);
   void display();
   void insertAt(T data, int position);
   void deleteNode(int position);
   void reverseList();
   void reverseListRecursion(Node<T> *head);
   void print(Node<T> *head);
   void reversePrint(Node<T> *head);

   T getData()const;
   Node<T> getNext();
   Node<T> *getHead();
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
   node.insert(5);

   node.display();

   //node.deleteNode(4);

   //node.display();

   node.reverseList();

   node.display();

   node.print(node.getHead());



   node.reverseListRecursion(node.getHead());


   node.display();




}


template<class T>
Node<T>::Node():head(NULL){}



template<class T>
void Node<T>::insertAt(T data, int position)
{
   int x = 2;
   Node<T> *temp = head;
   Node<T> *newNode = new Node();//-----------------Node<T> *newNode;
   newNode->data = data;
   newNode->next = NULL;

   if(position == 1)
   {
      newNode->next = temp;
      head = newNode;
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

   if(head == NULL)
   {
      temp->data = x;
      temp->next = NULL;
      head = temp;
      return;
   }

   temp = head;
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
   temp = head;


   if(position == 1)
   {
      head = temp->next;
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

   Node<T> *temp = head;
   cout << "List is: ";
   while(temp != NULL)
   {
      cout << temp->data << " ";
      temp = temp->next;
   }
   cout << endl;



}


template<class T>
void Node<T>::reverseList()
{
   Node<T> *current, *pre, *next;
   current = head;
   pre = NULL;
   next = NULL;

   while(current != NULL)
   {
      next = current->next;
      current->next = pre;
      pre = current;
      current = next;
   }

   head = pre;
}


template<class T>
void Node<T>::reverseListRecursion(Node<T> *head_local)
{
   if(head_local->next == NULL)
   {
      this->head = head_local;
      return;
   }

   reverseListRecursion(head_local->next);

   Node<T> *temp = head_local->next;
   temp->next = head_local;
   head_local->next = NULL;
}



template<class T>
void Node<T>::print(Node<T> *head)
{
   if(head == NULL)
   {
      cout << endl;
      return;
   }

   cout << head->data << " ";

   print(head->next);
}


template<class T>
void Node<T>::reversePrint(Node<T> *head)
{
   if(head == NULL)
   {
      return;
   }
   reversePrint(head->next);
   cout << head->data << " ";

}



template<class T>
T Node<T>::getData()const
{
   return data;
}


template<class T>
Node<T> Node<T>::getNext()
{
   return next;
}


template<class T>
Node<T> *Node<T>::getHead()
{
   return head;
}
