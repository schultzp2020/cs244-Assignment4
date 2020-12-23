#pragma once
#include "DoublyLinkedListNode.h"

template<typename T>
class DoublyLinkedList;


// Mutable forward iterator for a linked list
template <class T>
class MutableDoublyLinkedListIterator
{
public:
    // Construct from a starting node
    MutableDoublyLinkedListIterator(DoublyLinkedListNode<T>* start);

    // Pre-increment operator (++i):
    // Advances iterator to the next node.
    MutableDoublyLinkedListIterator<T>& operator ++ ();

    // Post-increment operator (i++):
    // Advances iterator to the next node.
    void operator ++ (int);

    // Pre-decrement operator (--i):
    // Regresses iterator to the previous node.
    MutableDoublyLinkedListIterator<T>& operator -- ();

    // Post-decrement operator (i--):
    // Regresses iterator to the previous node.
    void operator -- (int);

    // Equality operator; checks if iterators are at the same node.
    bool operator == (const MutableDoublyLinkedListIterator<T>& other) const;

    // Inequality operator; checks if iterators are not at the same node.
    bool operator != (const MutableDoublyLinkedListIterator<T>& other) const;

    // Dereference to access value at the current node.
    T& operator * ();

    // Dereference to access value at the current node.
    T* operator -> ();

    // Allows sort to access the private variables
    template<typename T, typename C>
    friend void sort(DoublyLinkedList<T>& list, C compare);

    // Allows DoublyLunkedList to access the private variables
    template<typename T>
    friend class DoublyLinkedList;

private:
    // The node the iterator is currently visiting.
    DoublyLinkedListNode<T>* current;
};

template <typename T>
MutableDoublyLinkedListIterator<T>::MutableDoublyLinkedListIterator(DoublyLinkedListNode<T>* start)
    : current{ start }
{
}

template <typename T>
MutableDoublyLinkedListIterator<T>& MutableDoublyLinkedListIterator<T>::operator ++ () 
{
    // Advance to the next node.
    current = current->next;

    // Pre-increment operator (++i) can be easily chained.
    return *this;
}

template <typename T>
void MutableDoublyLinkedListIterator<T>::operator ++ (int)
{
    // Advance to the next node.
    current = current->next;

    // Chain assignment disabled for pre-increment.
}

template<class T>
MutableDoublyLinkedListIterator<T>& MutableDoublyLinkedListIterator<T>::operator--()
{
    // Regress to the previous node.
    current = current->previous;

    // Pre-decrement operator (--i) can be easily chained.
    return *this;
}

template<class T>
void MutableDoublyLinkedListIterator<T>::operator--(int)
{
    // Regress to the previous node.
    current = current->previous;

    // Chain assignment disabled for pre-decrement.
}

template <typename T>
bool MutableDoublyLinkedListIterator<T>::operator == (const MutableDoublyLinkedListIterator<T>& other) const
{
    return this->current == other.current;
}

template <typename T>
bool MutableDoublyLinkedListIterator<T>::operator != (const MutableDoublyLinkedListIterator<T>& other) const
{
    return !(*this == other);
}


template <typename T>
T& MutableDoublyLinkedListIterator<T>::operator * ()
{
    return current->value;
}

template <typename T>
T* MutableDoublyLinkedListIterator<T>::operator -> ()
{
    return &(current->value);
}