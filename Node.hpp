/**
*	@file Node.cpp
*	@author Andy Monroe
*	@date 09-29-2016
*	@brief Implementation file for templated class Node. Node contains an
        object and a pointer to another Node.
*/

/*
    Node constructor used when creating a new node
*/
template <typename T>
Node<T>::Node(T item)
{
    m_item = item;
    m_nextNode = nullptr;
}

/*
    return a reference to the next node
*/
template <typename T>
Node<T>* Node<T>::getNextNode() const
{
    return(m_nextNode);
}

/*
    set the next node pointer to point at a new node containing a specified
        value
*/
template <typename T>
void Node<T>::setNextNode(Node<T>* value)
{
    m_nextNode = value;
}

/*
    return the item contained within the node
*/
template <typename T>
T Node<T>::getItem() const
{
    return(m_item);
}

/*
    set the item contained in the node to be a new item
*/
template <typename T>
void Node<T>::setItem(T item)
{
    m_item = item;
}
