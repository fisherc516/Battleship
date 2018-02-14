 /*
  * @file Queue.hpp
  * @author Cara Fisher
  * @date 2-28-17
  * @brief Implementation of Queue.h (templated Queue class)
  */

 #include <iostream>
 #include "Queue.h"

 template <typename T>
 Queue<T>::Queue()
 {
 	m_size = 0;
        // NOTE: m_right of Node<T> will be the next in line
 	m_front = nullptr;
 } 
 template <typename T>
 Queue<T>::~Queue()
 {
 	while(!isEmpty())
 	{
  		pop();
 	}
 }
 template <typename T>
 bool Queue<T>::isEmpty() const
 {
 	return(m_size == 0);
 }
 template <typename T>
 void Queue<T>::push(const T newEntry)
 {
 	if(m_size == 0)
 	{
  		m_front = new Node<T>();
  		m_front->setValue(newEntry);
 	}
 	else
 	{
  		Node<T>* add = new Node<T>();
  		add->setValue(newEntry);
                Node<T>* temp = m_front;
  		while(temp->getRight() != nullptr)
                {
                        temp = temp->getRight();
                }
                temp->setRight(add);
                temp = nullptr;
 	}
 	m_size++;
 }
 template <typename T>
 void Queue<T>::pop()
 {
        if(m_size == 1)
        {
                delete m_front;
                m_front = nullptr;
        }
        else
        {
                Node<T>* temp = m_front;
                m_front = m_front->getRight();
                delete temp;
                temp = nullptr;
        }
        m_size--;
 }
 template <typename T>
 T Queue<T>::peek() const
 {
        return(m_front->getValue());
 }
 template <typename T>
 int Queue<T>::size() const
 {
 	return(m_size);
 }
 template <typename T>
 void Queue<T>::print() const
 {
 	if(isEmpty())
 	{
  		std::cout << "";
 	}
 	else
 	{
  		Node<T>* temp = m_front;
  		while(temp->getRight() != nullptr)
  		{
   			std::cout << temp->getValue() << " ";
   			temp = temp->getRight();
  		}
  		std::cout << temp->getValue() << std::endl;
 	} 
 }
