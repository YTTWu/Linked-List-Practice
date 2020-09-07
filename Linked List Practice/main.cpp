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
};


// global variable
template<class T>
Node<T> *head;


int main() {

   Node<string> node;
   int userInput;
   string x;



   cout << "How many numbers? ";
   cin >> userInput;

   for(int i = 0; i < userInput; i++)
   {
      cout << "Enter the number: ";
      cin >> x;

      node.insert(x);
      node.display();
   }

   int position;
   cout << "Where do you want to insert your node: ";
   cin >> position;

   cout << "Enter the number: ";
   cin >> x;

   node.insertAt(x, position);
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
   temp->data = x;
   temp->next = head<T>;
   head<T> = temp;
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
