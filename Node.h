/*
  * @file Node.h
  * @author Cara Fisher
  * @date 2/24/17
  * @brief Header file of templated Node class; creates and initializes a node with a value and pointing at nullptr
  */

 #ifndef NODE_H
 #define NODE_H

 template<typename T>
 class Node
 {
         private:
                 T m_value;
                 Node<T>* m_parent;
                 Node<T>* m_left;
                 Node<T>* m_right;
         public:
 // @pre None
 // @post Initializes m_left and m_right to nullptr
 // @return None
                 Node();
 // @pre None
 // @post None
 // @return Returns m_value
                 T getValue();
 // @pre None
 // @post None
 // @return Returns m_left
                 Node<T>* getLeft();
 // @pre None
 // @post None
 // @return Returns m_right
                 Node<T>* getRight();
 // @pre None
 // @post None
 // @return Returns m_parent
                 Node<T>* getParent();
 // @pre value is valid
 // @post Sets m_value to value
 // @return None
                 void setValue(T value);
 // @pre left is a valid Node pointer
 // @post m_left is set to left
 // @return None
                 void setLeft(Node<T>* left);
 // @pre right is a valid Node pointer
 // @post m_right is set to right
 // @return None
                 void setRight(Node<T>* right);
 // @pre parent is a valid Node pointer
 // @post m_parent is set to parent
 // @return None
                 void setParent(Node<T>* parent);
 };

 #include "Node.hpp"
 #endif
