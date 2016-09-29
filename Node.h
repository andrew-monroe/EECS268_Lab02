/**
*	@file Node.h
*	@author Andy Monroe
*	@date 09-13-2016
*	@brief aasdfasdfasdfasdfasdfasdfasdfasdfasdf
*/

#ifndef Node_h
#define Node_h

template <typename T>
class Node
{
    public:
        Node(T item);
        Node(T item, Node<T> next);
        Node<T>* getNextNode() const;
        void setNextNode(Node<T>* value);
        T getItem() const;
        void setItem(T item);

    private:
        T m_item;
        Node* m_nextNode;
};

#include "Node.hpp"

#endif
