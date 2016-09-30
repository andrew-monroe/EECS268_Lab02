/**
*	@file Node.h
*	@author Andy Monroe
*	@date 09-29-2016
*	@brief Header file for templated class Node. Node contains an object and a
        pointer to another Node.
*/

#ifndef Node_h
#define Node_h

template <typename T>
class Node
{
    public:
        /*
            Node constructor used when creating a new node
        */
        Node(T item);

        /*
            return a reference to the next node
        */
        Node<T>* getNextNode() const;

        /*
            set the next node pointer to point at a new node containing a
            specified value
        */
        void setNextNode(Node<T>* value);

        /*
            return the item contained within the node
        */
        T getItem() const;

        /*
            set the item contained in the node to be a new item
        */
        void setItem(T item);

    private:
        T m_item;
        Node* m_nextNode;
};

#include "Node.hpp"

#endif
