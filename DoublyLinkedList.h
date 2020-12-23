#pragma once
#include <stdexcept>
#include <ostream>
#include "DoublyLinkedListNode.h"
#include "DoublyLinkedListIterator.h"
#include "MutableDoublyLinkedListIterator.h"
#include "ReverseDoublyLinkedListIterator.h"
#include "MutableReverseDoublyLinkedListIterator.h"

// A container class for a doubly-linked list
template <typename T>
class DoublyLinkedList
{
public:
    // Use default constructor
    DoublyLinkedList() = default;

    // Copy constructor
    DoublyLinkedList(const DoublyLinkedList<T>& original);

    // Destructor
    ~DoublyLinkedList();

    // Copy assignment operator
    DoublyLinkedList<T>& operator= (const DoublyLinkedList<T>& original);

    // Get number of nodes in the list
    unsigned int getSize() const;

    // Get element at the beginning of the list
    const T& getFirst() const;

    // Get element at the beginning of the list
    T& getFirst();

    // Get element at the end of the list
    const T& getLast() const;

    // Get element at the end of the list
    T& getLast();

    // Add an item to the beginning of the list
    void addFirst(T value);

    // Remove an item from the beginning of the list
    void removeFirst();

    // Add an item to the end of the list
    void addLast(T value);

    // Remove an item from the end of the list
    void removeLast();

    // Remove all items from the list without destroying container
    void clear();

    // Allows sort to access the private variables
    template<typename T, typename C>
    friend void sort(DoublyLinkedList<T>& list, C compare);

    // Stream insertion operator
    template <typename T2>
    friend std::ostream& operator << (
        std::ostream& os,
        const DoublyLinkedList<T2>& list);

    // Start of forward iterator
    DoublyLinkedListIterator<T> begin() const;

    // End of forward iterator
    DoublyLinkedListIterator<T> end() const;

    // Start of mutable forward iterator
    MutableDoublyLinkedListIterator<T> begin();

    // End of mutable forward iterator
    MutableDoublyLinkedListIterator<T> end();

    // Start of reverse iterator
    ReverseDoublyLinkedListIterator<T> rbegin() const;

    // End of reverse iterator
    ReverseDoublyLinkedListIterator<T> rend() const;

    // Start of mutable reverse iterator
    MutableReverseDoublyLinkedListIterator<T> rbegin();

    // End of reverse forward iterator
    MutableReverseDoublyLinkedListIterator<T> rend();


private:
    // Swaps a node from list to the end of this list
    void nodeSwapList(DoublyLinkedList<T>& list, DoublyLinkedListNode<T>* node);
    
    // Number of nodes in the list
    unsigned int size { 0 };

    // Pointer to first node in the list
    DoublyLinkedListNode<T>* first { nullptr };

    // Pointer to last node in the list
    DoublyLinkedListNode<T>* last { nullptr };
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& original)
{
    // TODO: implement copy constructor
    auto iterator(original.begin()); //initialize an iterator with original beginning

    while (iterator != original.end()) //iterate through the entire list
    {
        addLast(*iterator); //copy the value from the iterator to the new list
        iterator++; //increment the iterator
    }
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    clear(); //clear the entire list
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& original)
{
    // TODO: implement copy assignment operator
    clear(); //clear the entire list
    auto iterator(original.begin()); //initialize an iterator with original beginning

    while (iterator != original.end()) //iterate through the entire list
    {
        addLast(*iterator); //copy the value from the iterator to the new list
        iterator++; //increment the iterator
    }

    return *this; //return the list
}

template <typename T>
void DoublyLinkedList<T>::addFirst(T value)
{
    // TODO: implement addFirst
    DoublyLinkedListNode<T>* newNode{ new DoublyLinkedListNode<T>() }; //create a new node

    newNode->value = value; //assign value to newNew->value

    newNode->next = first; //assign first to newNew->next

    newNode->previous = nullptr; //assign nullptr to newNew->previous

    if (first) //execute if first exists
    {
        first->previous = newNode; //assign newNode to first->previous
    }

    first = newNode; //assign first to newNode

    if (!last) //execute if last does not exist
    {
        last = first; //assign first to last
    }

    size++; //increment the size
}

template <typename T>
void DoublyLinkedList<T>::removeFirst()
{
    // TODO: implement removeFirst
    if (first) //execute if first exists
    {
        DoublyLinkedListNode<T>* nodeToDelete{ first }; //initialize nodeToDelete to first

        first = first->next; //assign first to first->next

        delete nodeToDelete; //delete nodeToDelete

        size--; //decrement the size

        if (first) //execute if first exists
        {
            first->previous = nullptr; //assign nullptr to first->previous
        }
        else //execute if first does not exist
        {
            last = nullptr; //assign last to nullptr
        }
    }
    else //if first does not exist throw an exception
    {
        throw std::out_of_range("Empty list"); //throws an exception
    }
}

template<typename T>
void DoublyLinkedList<T>::addLast(T value)
{
    // TODO: implement addLast
    DoublyLinkedListNode<T>* newNode{ new DoublyLinkedListNode<T>() }; //create a new node

    newNode->value = value; //assign value to newNew->value

    newNode->next = nullptr; //assign nullptr to newNode->next

    newNode->previous = last; //assign last to newNode->previous

    if (last) //execute if last exists
    {
        last->next = newNode; //assign newNode to last->next
    }

    last = newNode; //assign newNode to last

    if (!first) //execute if first does not exist
    {
        first = last; //assign last to first
    }

    size++; //increment the size
}

template<typename T>
void DoublyLinkedList<T>::removeLast()
{
    // TODO: implement removeLast
    if (last) //if last exists execute
    {
        DoublyLinkedListNode<T>* nodeToDelete{ last }; //initialize nodeToDelete to last

        last = last->previous; //assign last to last->previous

        delete nodeToDelete; //delete nodeToDelete

        size--; //decrement size

        if (last) //if the new last does exist assign last->next to nullptr
        {
            last->next = nullptr; //assign last->next to nullptr
        }
        else //if the new last does not exist assign first to nullptr
        {
            first = nullptr; //assign first to nullptr
        }
    }
    else //if list does not exist throw an exception
    {
        throw std::out_of_range("Empty list"); //throws an exception
    }
}

template<typename T>
void DoublyLinkedList<T>::clear()
{
    // Keep track of the next node to delete.
    DoublyLinkedListNode<T>* toDelete { first };

    // Loop until toDelete == nullptr
    while (toDelete)
    {
        // Use first as temp storage
        first = toDelete->next;

        delete toDelete;

        // Advance to the next node.
        toDelete = first;
    }
    // first should now be nullptr.

    last = nullptr;
    size = 0;
}

template<typename T>
unsigned int DoublyLinkedList<T>::getSize() const
{
    return size;
}

template <typename T>
T const& DoublyLinkedList<T>::getFirst() const
{
    if (first)
    {
        return first->value;
    }
    else
    {
        throw std::out_of_range("Empty list");
    }
}

template <typename T>
T& DoublyLinkedList<T>::getFirst()
{
    if (first)
    {
        return first->value;
    }
    else
    {
        throw std::out_of_range("Empty list");
    }
}

template<typename T>
const T& DoublyLinkedList<T>::getLast() const
{
    if (last)
    {
        return last->value;
    }
    else
    {
        throw std::out_of_range("Empty list");
    }
}

template<typename T>
T& DoublyLinkedList<T>::getLast()
{
    if (last)
    {
        return last->value;
    }
    else
    {
        throw std::out_of_range("Empty list");
    }
}

template <typename T>
std::ostream& operator << (std::ostream& os, const DoublyLinkedList<T>& list)
{
    if (list.getSize() == 0)
    {
        // Special case: empty list
        os << "[]";
    }
    else
    {
        // Print opening bracket and first element
        os << "[" << list.first->value;

        DoublyLinkedListNode<T>* current{ list.first->next };
        while (current != nullptr)
        {
            // Print a comma, then the next element
            os << ", " << current->value;

            current = current->next;
        }

        // Print closing bracket
        os << "]";
    }

    return os;
}


template <typename T>
DoublyLinkedListIterator<T> DoublyLinkedList<T>::begin() const
{
    return DoublyLinkedListIterator<T>{first};
}

template <typename T>
DoublyLinkedListIterator<T> DoublyLinkedList<T>::end() const
{
    return DoublyLinkedListIterator<T>{nullptr};
}

template <typename T>
MutableDoublyLinkedListIterator<T> DoublyLinkedList<T>::begin()
{
    return MutableDoublyLinkedListIterator<T>{first};
}

template <typename T>
MutableDoublyLinkedListIterator<T> DoublyLinkedList<T>::end()
{
    return MutableDoublyLinkedListIterator<T>{nullptr};
}

template<typename T>
ReverseDoublyLinkedListIterator<T> DoublyLinkedList<T>::rbegin() const
{
    return ReverseDoublyLinkedListIterator<T>{last};
}

template<typename T>
ReverseDoublyLinkedListIterator<T> DoublyLinkedList<T>::rend() const
{
    return ReverseDoublyLinkedListIterator<T>{nullptr};
}

template<typename T>
MutableReverseDoublyLinkedListIterator<T> DoublyLinkedList<T>::rbegin()
{
    return MutableReverseDoublyLinkedListIterator<T>{last};
}

template<typename T>
MutableReverseDoublyLinkedListIterator<T> DoublyLinkedList<T>::rend()
{
    return MutableReverseDoublyLinkedListIterator<T>{nullptr};
}

// Swaps a node from list to the end of this list
// For nodeSwapList to work node must exist inside list
template<typename T>
void DoublyLinkedList<T>::nodeSwapList(DoublyLinkedList<T>& list, DoublyLinkedListNode<T>* node)
{
    bool error{ true }; //initialize error to true
    DoublyLinkedListNode<T>* previousNode{ NULL }; //initialize previousNode to null
    DoublyLinkedListNode<T>* nextNode{ NULL }; //initialize nextNode to null

    MutableDoublyLinkedListIterator<T> iterator(list.begin()); //make sure the given node is in the given list
    while (iterator != list.end()) //iterator through the entire list
    {
        if (iterator.current == node) { error = false; }; //assigns error to false if the given node is in the given list
        iterator++; //increment iterator
    }

    if (error) //if the given node is not in the given list throw an error
    {
        throw std::logic_error("Node does not exist inside of the list given"); //throws a logic error
    }

    if (node->next && node->previous) //assigns the corresponding nodes to each other given both node->next and node->previous do exist
    {
        nextNode = node->next; //assigns node->next to nextNode
        previousNode = node->previous;  //assigns node->previous to previousNode
        previousNode->next = nextNode; //assigns previousNode->next to nextNode
        nextNode->previous = previousNode; //assigns nextNode->previous to previousNode
    }

    else if (!node->next && node->previous) //assigns the corresponding nodes to each other given node->next does not exist and node->previous does exist
    {
        previousNode = node->previous; //assigns node->previous to previousNode
        list.last = previousNode; //assigns list.last to previousNode
        previousNode->next = nullptr; //assigns previousNode->next to nullptr
    }

    else if (node->next && !node->previous) //assigns the corresponding nodes to each other given node->next does exist and node->previous does not exist
    {
        nextNode = node->next; //assigns node->next to nextNode
        list.first = nextNode; //assigns list.first to nextNode
        nextNode->previous = nullptr; //assigns nextNode->previous to nullptr
    }
    
    else //assigns the corresponding nodes to each other given both node->next and node->previous do not exist
    {
        list.first = nullptr; //assigns list.last to nullptr
        list.last = nullptr; //assigns list.first to nullptr
    }
    
    list.size--; //decrement the given list size

    if (!this->first) //insert the node into this list if it is the first element
    {
        this->first = node; //assigns this->first to node
        node->previous = nullptr; //assigns node->previous to nullptr
        node->next = nullptr; //assigns node->next to nullptr
        this->last = node; //assigns node->last to node
        this->size++; //increment this list size
    }
    else //insert the node into this list if it is not the first element
    {
        this->last->next = node; //assigns this->last->next to node
        node->previous = this->last; //assigns node->previous to this->last
        node->next = nullptr; //assigns node->next to nullptr
        this->last = node; //assigns node->last to node
        this->size++; //increment this list size
    }

}

// Sorts a list using a specified compare function.
// When the function returns, compare(a, b) is true only if a precedes b in the list.
template<typename T, typename C>
void sort(DoublyLinkedList<T>& list, C compare)
{
    // TODO: implement sort
    DoublyLinkedList<T> newList; //create a DoublyLinkedList<T> called newList

    while (list.getSize() != 0) //while elements exist in the list loop
    {
        MutableDoublyLinkedListIterator<T> iterator(list.begin()); //initialize iterator to the first element in the list
        DoublyLinkedListNode<T>* node{ iterator.current }; //initialize node to the first element in the list
        iterator++; //increment iterator for efficiency

        while (iterator != list.end()) //find the largest or small element in the list depending on compare
        {
            if (compare(*iterator, node->value)) //executes of compare is true
            {
                node = iterator.current; //assigns the current node in the iterator to node
            }
            iterator++; //increment iterator
        }

        newList.nodeSwapList(list, node); //insert the node from list to newList
    }

    list = newList; //copies values from newList to list
}
