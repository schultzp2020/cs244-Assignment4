#pragma once
#include "DoublyLinkedListNode.h"

// Mutable reverse iterator for a linked list.
// Implemented by using the mutable forward iterator and switching the direction of increment / decrement.
template <class T>
class MutableReverseDoublyLinkedListIterator
{
public:
    // Construct from a starting node
    MutableReverseDoublyLinkedListIterator(DoublyLinkedListNode<T>* start);

    // Pre-increment operator (++i):
    // Advances iterator to the next node.
    MutableReverseDoublyLinkedListIterator<T>& operator ++ ();

    // Post-increment operator (i++):
    // Advances iterator to the next node.
    void operator ++ (int);

    // Pre-decrement operator (--i):
    // Regresses iterator to the previous node.
    MutableReverseDoublyLinkedListIterator<T>& operator -- ();

    // Post-decrement operator (i--):
    // Regresses iterator to the previous node.
    void operator -- (int);

    // Equality operator; checks if iterators are at the same node.
    bool operator == (const MutableReverseDoublyLinkedListIterator<T>& other) const;

    // Inequality operator; checks if iterators are not at the same node.
    bool operator != (const MutableReverseDoublyLinkedListIterator<T>& other) const;

    // Dereference to access value at the current node.
    T& operator * ();

    // Dereference to access value at the current node.
    T* operator -> ();

private:
    // The node the iterator is currently visiting.
    MutableDoublyLinkedListIterator<T> base;
};

template<class T>
MutableReverseDoublyLinkedListIterator<T>::MutableReverseDoublyLinkedListIterator(DoublyLinkedListNode<T>* start)
    : base{ start }
{
}

template<class T>
MutableReverseDoublyLinkedListIterator<T>& MutableReverseDoublyLinkedListIterator<T>::operator++()
{
    // Decrement the base iterator to progress backwards.
    --base;

    // Pre-increment operator (++i) can be easily chained.
    return *this;
}

template<class T>
void MutableReverseDoublyLinkedListIterator<T>::operator++(int)
{
    // Decrement the base iterator to progress backwards.
    base--;

    // Chain assignment disabled for pre-increment.
}

template<class T>
MutableReverseDoublyLinkedListIterator<T>& MutableReverseDoublyLinkedListIterator<T>::operator--()
{
    // Increment the base iterator to regress from the perspective of the reverse iterator.
    ++base;

    // Pre-decrement operator (--i) can be easily chained.
    return *this;
}

template<class T>
void MutableReverseDoublyLinkedListIterator<T>::operator--(int)
{
    // Increment the base iterator to regress from the perspective of the reverse iterator.
    base++;

    // Chain assignment disabled for pre-decrement.
}

template<class T>
bool MutableReverseDoublyLinkedListIterator<T>::operator==(const MutableReverseDoublyLinkedListIterator<T>& other) const
{
    return base == other.base;
}

template<class T>
bool MutableReverseDoublyLinkedListIterator<T>::operator!=(const MutableReverseDoublyLinkedListIterator<T>& other) const
{
    return base != other.base;
}

template<class T>
T& MutableReverseDoublyLinkedListIterator<T>::operator*()
{
    return *base;
}

template<class T>
T* MutableReverseDoublyLinkedListIterator<T>::operator->()
{
    return &(*base);
}
