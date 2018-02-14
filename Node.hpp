/*
  * @file Node.hpp
  * @author Cara Fisher
  * @date 2/24/17
  * @brief Implementation of Node.h
  */

 #include "Node.h"

 template<typename T>
 Node<T>::Node()
 {
         m_left = nullptr;
         m_right = nullptr;
         m_parent = nullptr;
 }
 template<typename T>
 T Node<T>::getValue()
 {
         return(m_value);
 }
 template<typename T>
 Node<T>* Node<T>::getLeft()
 {
         return(m_left);
 }
 template<typename T>
 Node<T>* Node<T>::getRight()
 {
         return(m_right);
 }
 template<typename T>
 Node<T>* Node<T>::getParent()
 {
         return(m_parent);
 }
 template<typename T>
 void Node<T>::setValue(T value)
 {
         m_value = value;
 }
 template<typename T>
 void Node<T>::setLeft(Node<T>* left)
 {
         m_left = left;
 }
 template<typename T>
 void Node<T>::setRight(Node<T>* right)
 {
         m_right = right;
 }
 template<typename T>
 void Node<T>::setParent(Node<T>* parent)
 {
         m_parent = parent;
 }
