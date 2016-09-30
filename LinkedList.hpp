/**
*	@file LinkedList.hpp
*	@author Andy Monroe
*	@date 09-29-2016
*	@brief Implementation file for templated class LinkedList. LinkedList
        contains a series of Node values. LinkedList knows where the first Node
        is and how many Nodes there are, and uses this information in various
        methods to perform LinkedList various operations.
*/

/** @pre None.
*   @post An empty list is created.
*/
template <typename T>
LinkedList<T>::LinkedList()
{
    m_length = 0;
    m_front = nullptr;
}

/** @pre None.
*   @post Deletes all nodes in the list.
*/
template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* temp = m_front;
    Node<T>* temp2 = nullptr;

    while (temp != nullptr)
    {
        temp2 = temp->getNextNode();

        delete temp;

        temp = temp2;
    }
}

/** @pre None.
*   @post None.
*   @return true if the list is empty, false otherwise.
*/
template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return(m_length == 0);
}

/** @pre None.
*   @post None.
*   @return the number of elements in the list.
*/
template <typename T>
int LinkedList<T>::getLength() const
{
    return(m_length);
}

/** @pre The type T is overloaded with the == operator
*   @post None.
*   @return returns the index of the first node in the list that contains the value. Returns 0 otherwise.
* 		NOTE: The range of indices is from 1 to n, where n is the number of elements in the list
*/
template <typename T>
int LinkedList<T>::positionOf(T value) const
{
    int position = 1;
    Node<T>* temp = m_front;

    while(position <= m_length && !(temp->getItem() == value))
    {
        position++;

        temp = temp->getNextNode();
    }

    if(position > m_length)
    {
        return(0);
    }
    else
    {
        return(position);
    }
}

/** @pre the value is a valid T.
*   @post One new element added to the end of the list.
*   @return none.
*/
template <typename T>
void LinkedList<T>::addBack(T value)
{
    Node<T>* temp = m_front;

    for(int x = 1; x < m_length; x++)
    {
        temp = temp->getNextNode();
    }

    if (m_length != 0)
        temp->setNextNode(new Node<T>(value));
    else
        m_front = new Node<T>(value);

    m_length++;
}

/** @pre the value is a valid T.
*   @post One new element added to the front of the list.
*   @return none.
*/
template <typename T>
void LinkedList<T>::addFront(T value)
{
    Node<T>* temp = new Node<T>(value);

    temp->setNextNode(m_front);

    m_front = temp;

    m_length++;
}

/** @pre None
*   @post One new element is inserted at the given position.
*   @return true if the element was inserted false otherwise.
* 		NOTE: The range of indices is from 1 to n, where n is the number of elements in the list
*/
template <typename T>
bool LinkedList<T>::insert(int position, T value)
{
    if(m_length+1 < position)
        return(false);

    if (position == 1)
    {
        addFront(value);

        return(true);
    }
    else if (position == m_length+1)
    {
        addBack(value);

        return(true);
    }
    else
    {
        Node<T>* toNewNode = m_front;
        Node<T>* fromNewNode = m_front->getNextNode();
        Node<T>* newNode = new Node<T>(value);

        for(int x = 1; x < position; x++)
        {
            toNewNode = fromNewNode;
            fromNewNode = fromNewNode->getNextNode();
        }

        toNewNode->setNextNode(newNode);
        newNode->setNextNode(fromNewNode);

        m_length++;
    }

    return(true);
}

/** @pre None
*   @post One element is removed from the back of the list.
*   @return true if the back element was removed, false if the list is empty.
*/
template <typename T>
bool LinkedList<T>::removeBack()
{
    if(isEmpty())
        return(false);

    Node<T>* temp = m_front;

    for(int x = 1; x < m_length; x++)
    {
        temp = temp->getNextNode();
    }

    delete temp;

    m_length--;

    return(true);
}

/** @pre None
*   @post One element is removed from the front of the list.
*   @return true if the front element was removed, false if the list is empty.
*/
template <typename T>
bool LinkedList<T>::removeFront()
{
    if(isEmpty())
        return(false);

    Node<T>* temp = m_front->getNextNode();

    delete m_front;

    m_front = temp;

    m_length--;

    return(true);
}

/** @pre None
*   @post One element at the provided index is removed
*   @return true if an element was removed, false otherwise.
* 		NOTE: The range of indices is from 1 to n, where n is the number of elements in the list
*/
template <typename T>
bool LinkedList<T>::removeAt(int position)
{
    if(isEmpty())
        return(false);

    Node<T>* nodeRemoved = m_front;
    Node<T>* toNodeRemoved = nullptr;

    if (position == 1)
    {
        removeFront();
    }
    else if (position == m_length)
    {
        removeBack();
    }
    else
    {
        for(int x = 1; x < position; x++)
        {
            toNodeRemoved = nodeRemoved;
            nodeRemoved = nodeRemoved->getNextNode();
        }

        toNodeRemoved->setNextNode(nodeRemoved->getNextNode());

        delete nodeRemoved;

        m_length--;
    }

    return(true);
}

/** @pre None
*   @post The value at the given position is overridden with the provided value.
* 		NOTE: The range of indices is from 1 to n, where n is the number of elements in the list
*/
template <typename T>
void LinkedList<T>::setEntry(int position, T value)
{
    Node<T>* temp = m_front;

    for(int x = 1; x < position; x++)
    {
        temp = temp->getNextNode();
    }

    temp->setItem(value);
}

/** @pre None
*   @post None
*   @return The entry at the given position.
* 		NOTE: The range of indices is from 1 to n, where n is the number of elements in the list
*/
template <typename T>
T LinkedList<T>::getEntry( int position ) const
{
    Node<T>* temp = m_front;

    for(int x = 1; x < position; x++)
    {
        temp = temp->getNextNode();
    }

    return(temp->getItem());
}
