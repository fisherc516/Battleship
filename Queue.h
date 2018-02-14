 /*
  * @file Queue.h
  * @author Cara Fisher
  * @date 2/28/17
  * @brief Header file of templated Queue class
  */

 #ifndef QUEUE_H
 #define QUEUE_H

 #include "Node.h"
 
 template<typename T>
 class Queue
 {
         private:
                int m_size;
                // NOTE: m_right of Node<T> will be the next in line
                Node<T>* m_front;
         public:
  // @pre None
  // @post Creates and initializes a Queue with size 0 and m_front referring to nullptr
  // @return None
                Queue();
  // @pre None
  // @post Removes all node instances from queue before deletion
  // @return None
                ~Queue();
  // @pre None
  // @post None
  // @return Returns true if empty, false otherwise
                bool isEmpty() const;
  // @pre Takes in a valid value of type T
  // @post Entry added to back of queue containing value newEntry
  // @return None
                void push(const T newEntry);
  // @pre Assumes queue is not empty
  // @post Removes the front of the queue
  // @return None
                void pop();
  // @pre Assumes queue is not empty
  // @post None
  // @return Returns the value at the front of the queue
                T peek() const;
  // @pre None
  // @post None
  // @return Returns the size
                int size() const;
  // @pre None
  // @post Prints the contents or prints the empty string if the queue is empty
  // @return None
                void print() const;
 };

 #include "Queue.hpp"
 #endif
