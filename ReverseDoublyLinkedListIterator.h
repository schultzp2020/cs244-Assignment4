#pragma once
#include "DoublyLinkedListNode.h"

// Reverse iterator for a linked list.
// Implemented by using the forward iterator and switching the direction of increment / decrement.
template <typename T>
class ReverseDoublyLinkedListIterator
{
public:
    // Construct from a starting node
    ReverseDoublyLinkedListIterator(DoublyLinkedListNode<T> const* start);

    // Pre-increment operator (++i):
    // Advances iterator to the next node.
    ReverseDoublyLinkedListIterator<T>& operator ++ ();

    // Post-increment operator (i++):
    // Advances iterator to the next node.
    void operator ++ (int);

    // Pre-decrement operator (--i):
    // Regresses iterator to the previous node.
    ReverseDoublyLinkedListIterator<T>& operator -- ();

    // Post-decrement operator (i--):
    // Regresses iterator to the previous node.
    void operator -- (int);

    // Equality operator; checks if iterators are at the same node.
    bool operator == (const ReverseDoublyLinkedListIterator<T>& other) const;

    // Inequality operator; checks if iterators are not at the same node.
    bool operator != (const ReverseDoublyLinkedListIterator<T>& other) const;

    // Dereference to access value at the current node.
    T const& operator * () const;

    // Dereference to access value at the current node.
    T const* operator -> () const;

private:
    // The node the iterator is currently visiting.
    DoublyLinkedListIterator<T> base;
};

template<typename T>
ReverseDoublyLinkedListIterator<T>::ReverseDoublyLinkedListIterator(DoublyLinkedListNode<T> const* start)
    : base{ start }
{
}

template<typename T>
ReverseDoublyLinkedListIterator<T>& ReverseDoublyLinkedListIterator<T>::operator++()
{
    // Decrement the base iterator to progress backwards.
    --base;

    // Pre-increment operator (++i) can be easily chained.
    return *this;
}

template<typename T>
void ReverseDoublyLinkedListIterator<T>::operator++(int)
{
    // Decrement the base iterator to progress backwards.
    base--;

    // Chain assignment disabled for pre-increment.
}

template<typename T>
ReverseDoublyLinkedListIterator<T>& ReverseDoublyLinkedListIterator<T>::operator--()
{
    // Increment the base iterator to regress from the perspective of the reverse iterator.
    ++base;

    // Pre-decrement operator (--i) can be easily chained.
    return *this;
}

template<typename T>
void ReverseDoublyLinkedListIterator<T>::operator--(int)
{
    // Increment the base iterator to regress from the perspective of the reverse iterator.
    base++;

    // Chain assignment disabled for pre-decrement.
}

template<typename T>
bool ReverseDoublyLinkedListIterator<T>::operator==(const ReverseDoublyLinkedListIterator<T>& other) const
{
    return base == other.base;
}

template<typename T>
bool ReverseDoublyLinkedListIterator<T>::operator!=(const ReverseDoublyLinkedListIterator<T>& other) const
{
    return base != other.base;
}

template<typename T>
T const& ReverseDoublyLinkedListIterator<T>::operator*() const
{
    return *base;
}

template<typename T>
T const* ReverseDoublyLinkedListIterator<T>::operator->() const
{
    return &(*base);
}
