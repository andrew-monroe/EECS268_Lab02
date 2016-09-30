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
        /** @pre None.
    	*   @post m_item equals item, m_nextNode equals nullptr.
    	*/
        Node(T item);

        /** @pre None.
    	*   @post None.
    	*   @return value of m_nextNode, even if it is nullptr
    	*/
        Node<T>* getNextNode() const;

        /** @pre None.
    	*   @post m_nextNode now points to value.s
    	*/
        void setNextNode(Node<T>* value);

        /** @pre None.
    	*   @post None.
    	*   @return value of m_item
    	*/
        T getItem() const;

        /** @pre None.
    	*   @post m_item equals item.
    	*/
        void setItem(T item);

    private:
        T m_item;
        Node* m_nextNode;
};

#include "Node.hpp"

#endif
