#pragma once
#include "DoublyLinkedListNode.h"

// Forward iterator for a linked list
template <typename T>
class DoublyLinkedListIterator
{
public:
    // Construct from a starting node
    DoublyLinkedListIterator(DoublyLinkedListNode<T> const* start);

    // Pre-increment operator (++i):
    // Advances iterator to the next node.
    DoublyLinkedListIterator<T>& operator ++ ();

    // Post-increment operator (i++):
    // Advances iterator to the next node.
    void operator ++ (int);

    // Pre-decrement operator (--i):
    // Regresses iterator to the previous node.
    DoublyLinkedListIterator<T>& operator -- ();

    // Post-decrement operator (i--):
    // Regresses iterator to the previous node.
    void operator -- (int);

    // Equality operator; checks if iterators are at the same node.
    bool operator == (const DoublyLinkedListIterator<T>& other) const;

    // Inequality operator; checks if iterators are not at the same node.
    bool operator != (const DoublyLinkedListIterator<T>& other) const;

    // Dereference to access value at the current node.
    T const& operator * () const;

    // Dereference to access value at the current node.
    T const* operator -> () const;

private:
    // The node the iterator is currently visiting.
    const DoublyLinkedListNode<T>* current;
};

template <typename T>
DoublyLinkedListIterator<T>::DoublyLinkedListIterator(
    const DoublyLinkedListNode<T>* start) : current{ start }
{
}

template <typename T>
DoublyLinkedListIterator<T>& DoublyLinkedListIterator<T>::operator ++ ()
{
    // Advance to the next node.
    current = current->next;

    // Pre-increment operator (++i) can be easily chained.
    return *this;
}

template <typename T>
void DoublyLinkedListIterator<T>::operator ++ (int)
{
    // Advance to the next node.
    current = current->next;

    // Chain assignment disabled for pre-increment.
}

template<typename T>
DoublyLinkedListIterator<T>& DoublyLinkedListIterator<T>::operator--()
{
    // Regress to the previous node.
    current = current->previous;

    // Pre-decrement operator (--i) can be easily chained.
    return *this;
}

template<typename T>
void DoublyLinkedListIterator<T>::operator--(int)
{
    // Regress to the previous node.
    current = current->previous;

    // Chain assignment disabled for pre-decrement.
}

template <typename T>
bool DoublyLinkedListIterator<T>::operator == (const DoublyLinkedListIterator<T>& other) const
{
    return this->current == other.current;
}

template <typename T>
bool DoublyLinkedListIterator<T>::operator != (const DoublyLinkedListIterator<T>& other) const
{
    return !(*this == other);
}

template <typename T>
T const& DoublyLinkedListIterator<T>::operator * () const
{
    return current->value;
}

template <typename T>
T const* DoublyLinkedListIterator<T>::operator -> () const
{
    return &(current->value);
}
