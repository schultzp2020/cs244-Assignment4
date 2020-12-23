#include <iostream>
#include <cassert>
#include "DoublyLinkedList.h"

using namespace std;

// Generates a failed assertion if an expected exception is not thrown.
template <typename E, typename F>
void assertException(F test)
{
    try
    {
        test();
        assert(false);
    }
    catch (E e)
    {
    }
}

// Checks if the contents of a linked list match a sequence of expected values (stored in an array).
template <typename T>
void checkList(const DoublyLinkedList<T>& list, T* expected, unsigned int expectedSize)
{
    // Make sure that the size of the linked list is as expected
    assert(list.getSize() == expectedSize);

    unsigned int i = 0;
    for (const T& item : list)
    {
        assert(item == expected[i]);
        i++;
    }
}

// Tests addFirst, addLast, removeFirst, and removeLast.
void basicTests()
{
    DoublyLinkedList<int> list;
    const DoublyLinkedList<int>& clist = list;

    cout << "addFirst() test with empty list:" << endl;

    // Add items to the front of the list
    for (int i = 0; i < 10; i++)
    {
        list.addFirst(i);
    }

    // Print out the list using <<
    cout << clist << endl;

    // check the list using forward iterator
    int expected = 9;
    unsigned int limit = 0;
    for (auto i = clist.begin(); i != clist.end() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == expected);
        expected--;
    }
    cout << endl;

    // check the list using reverse iterator
    expected = 0;
    limit = 0;
    for (auto i = clist.rbegin(); i != clist.rend() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == expected);
        expected++;
    }
    cout << endl;

    // check basic list attributes
    assert(clist.getSize() == 10);
    assert(clist.getFirst() == 9);
    assert(clist.getLast() == 0);
    assert(list.getFirst() == 9);
    assert(list.getLast() == 0);

    cout << "PASS" << endl << endl;

    cout << "addLast() test with non-empty list:" << endl;

    for (int i = 10; i < 20; i++)
    {
        list.addLast(i);
    }

    cout << clist << endl;

    int expectedArr[20] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    unsigned int k = 0;
    limit = 0;
    for (auto i = clist.begin(); i != clist.end() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == expectedArr[k]);
        k++;
    }
    cout << endl;

    k = 19;
    limit = 0;
    for (auto i = clist.rbegin(); i != clist.rend() && limit < 100; i++, limit++)
    {
        assert(*i == expectedArr[k]);
        cout << *i << ' ';
        k--;
    }
    cout << endl;

    assert(clist.getSize() == 20);
    assert(clist.getFirst() == 9);
    assert(clist.getLast() == 19);
    assert(list.getFirst() == 9);
    assert(list.getLast() == 19);

    cout << "PASS" << endl << endl;

    cout << "Non-const getFirst() and getLast():" << endl;

    list.getFirst() = -1;
    list.getLast() = -2;

    expectedArr[0] = -1;
    expectedArr[19] = -2;

    cout << clist << endl;

    k = 0; limit = 0;
    for (auto i = clist.begin(); i != clist.end() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == expectedArr[k]);
        k++;
    }
    cout << endl;

    k = 19;
    limit = 0;
    for (auto i = clist.rbegin(); i != clist.rend() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == expectedArr[k]);
        k--;
    }
    cout << endl;

    assert(clist.getSize() == 20);
    assert(clist.getFirst() == -1);
    assert(clist.getLast() == -2);
    assert(list.getFirst() == -1);
    assert(list.getLast() == -2);

    cout << "PASS" << endl << endl;

    cout << "removeFirst():" << endl;

    for (int i = 0; i < 15; i++)
    {
        list.removeFirst();
    }

    cout << list << endl;

    k = 15; limit = 0;
    for (auto i = clist.begin(); i != clist.end() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == expectedArr[k]);
        k++;
    }
    cout << endl;

    k = 19;
    limit = 0;
    for (auto i = clist.rbegin(); i != clist.rend() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == expectedArr[k]);
        k--;
    }
    cout << endl;

    assert(clist.getSize() == 5);
    assert(clist.getFirst() == 15);
    assert(clist.getLast() == -2);
    assert(list.getFirst() == 15);
    assert(list.getLast() == -2);

    cout << "PASS" << endl << endl;

    cout << "addFirst() on non-empty list:" << endl;

    for (int i = 20; i < 30; i++)
    {
        list.addFirst(i);
    }

    cout << clist << endl;

    int expectedArr2[15] = { 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 15, 16, 17, 18, -2 };
    k = 0;
    limit = 0;
    for (auto i = clist.begin(); i != clist.end() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == expectedArr2[k]);
        k++;
    }
    cout << endl;

    k = 14;
    limit = 0;
    for (auto i = clist.rbegin(); i != clist.rend() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == expectedArr2[k]);
        k--;
    }
    cout << endl;

    assert(clist.getSize() == 15);
    assert(clist.getFirst() == 29);
    assert(clist.getLast() == -2);
    assert(list.getFirst() == 29);
    assert(list.getLast() == -2);

    cout << "PASS" << endl << endl;

    cout << "removeLast():" << endl;
    for (int i = 0; i < 10; i++)
    {
        list.removeLast();
    }

    cout << clist << endl;

    k = 0; limit = 0;
    for (auto i = clist.begin(); i != clist.end() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == expectedArr2[k]);
        k++;
    }
    cout << endl;

    k = 4;
    limit = 0;
    for (auto i = clist.rbegin(); i != clist.rend() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == expectedArr2[k]);
        k--;
    }
    cout << endl;

    assert(clist.getSize() == 5);
    assert(clist.getFirst() == 29);
    assert(clist.getLast() == 25);
    assert(list.getFirst() == 29);
    assert(list.getLast() == 25);

    cout << "PASS" << endl << endl;

    cout << "removeFirst() down to empty list:" << endl;
    for (int i = 0; i < 5; i++)
    {
        list.removeFirst();
    }

    cout << clist << endl;

    assert(list.begin() == list.end());
    assert(list.rbegin() == list.rend());
    assert(clist.begin() == clist.end());
    assert(clist.rbegin() == clist.rend());
    assert(clist.getSize() == 0);

    cout << "PASS" << endl << endl;

    cout << "addFirst() after emptying list:" << endl;

    for (int i = 30; i < 40; i++)
    {
        list.addFirst(i);
    }

    cout << clist << endl;

    expected = 39; limit = 0;
    for (auto i = clist.begin(); i != clist.end() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == expected);
        expected--;
    }
    cout << endl;

    expected = 30;
    limit = 0;
    for (auto i = clist.rbegin(); i != clist.rend() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == expected);
        expected++;
    }
    cout << endl;

    assert(clist.getSize() == 10);
    assert(clist.getFirst() == 39);
    assert(clist.getLast() == 30);
    assert(list.getFirst() == 39);
    assert(list.getLast() == 30);

    cout << "PASS" << endl << endl;

    cout << "removeLast() to empty list:" << endl;

    for (int i = 0; i < 10; i++)
    {
        list.removeLast();
    }

    cout << clist << endl;

    assert(list.begin() == list.end());
    assert(list.rbegin() == list.rend());
    assert(clist.begin() == clist.end());
    assert(clist.rbegin() == clist.rend());
    assert(clist.getSize() == 0);

    cout << "PASS" << endl << endl;

    cout << "addLast() after emptying list:" << endl;

    for (int i = 40; i < 50; i++)
    {
        list.addLast(i);
    }

    cout << clist << endl;

    expected = 40; limit = 0;
    for (auto i = clist.begin(); i != clist.end() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == expected);
        expected++;
    }
    cout << endl;

    expected = 49;
    limit = 0;
    for (auto i = clist.rbegin(); i != clist.rend() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == expected);
        expected--;
    }
    cout << endl;

    assert(clist.getSize() == 10);
    assert(clist.getFirst() == 40);
    assert(clist.getLast() == 49);
    assert(list.getFirst() == 40);
    assert(list.getLast() == 49);

    cout << "PASS" << endl << endl;

    cout << "clear() test:" << endl;

    list.clear();

    cout << clist << endl;

    assert(list.begin() == list.end());
    assert(list.rbegin() == list.rend());
    assert(clist.begin() == clist.end());
    assert(clist.rbegin() == clist.rend());
    assert(clist.getSize() == 0);

    assertException<logic_error>([&list]() { list.removeFirst(); });
    assertException<logic_error>([&list]() { list.removeLast(); });

    assertException<logic_error>([&list]() { cout << list.getFirst() << endl; });
    assertException<logic_error>([&list]() { cout << list.getLast() << endl; });

    assertException<logic_error>([&clist]() { cout << clist.getFirst() << endl; });
    assertException<logic_error>([&clist]() { cout << clist.getLast() << endl; });

    assert(list.begin() == list.end());
    assert(list.rbegin() == list.rend());
    assert(clist.begin() == clist.end());
    assert(clist.rbegin() == clist.rend());
    assert(clist.getSize() == 0);

    cout << "PASS" << endl << endl;

    cout << "addFirst() and addLast() after clear():" << endl;

    for (int i = 50; i < 60; i++)
    {
        list.addFirst(i);
    }

    for (int i = 60; i < 70; i++)
    {
        list.addLast(i);
    }

    int expectedArr3[20] = { 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69 };

    cout << clist << endl;

    k = 0; limit = 0;
    for (auto i = clist.begin(); i != clist.end() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == expectedArr3[k]);
        k++;
    }
    cout << endl;

    k = 19;
    limit = 0;
    for (auto i = clist.rbegin(); i != clist.rend() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == expectedArr3[k]);
        k--;
    }
    cout << endl;

    assert(list.getFirst() == 59);
    assert(list.getLast() == 69);
    assert(clist.getSize() == 20);
    assert(clist.getFirst() == 59);
    assert(clist.getLast() == 69);

    cout << "PASS" << endl << endl;

    cout << "iterating in both directions:" << endl;

    auto myIterator = clist.begin();
    for (int i = 0; i < 10; i++)
    {
        cout << *myIterator << ' ';
        assert(*myIterator == expectedArr3[i]);
        myIterator++;
    }

    for (int i = 10; i >= 0; i--)
    {
        cout << *myIterator << ' ';
        assert(*myIterator == expectedArr3[i]);
        myIterator--;
    }

    cout << endl;

    auto myReverseIterator = clist.rbegin();
    for (int i = 19; i > 9; i--)
    {
        cout << *myReverseIterator << ' ';
        assert(*myReverseIterator == expectedArr3[i]);
        myReverseIterator++;
    }

    for (int i = 9; i < 20; i++)
    {
        cout << *myReverseIterator << ' ';
        assert(*myReverseIterator == expectedArr3[i]);
        myReverseIterator--;
    }

    cout << endl;

    cout << "PASS" << endl << endl;

    cout << "mutable forward iterator:" << endl;
    limit = 0;
    for (auto i = list.begin(); i != list.end() && limit < 100; i++, limit++)
    {
        *i = -(*i);
    }

    cout << clist << endl;

    k = 0; limit = 0;
    for (auto i = clist.begin(); i != clist.end() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == -expectedArr3[k]);
        k++;
    }
    cout << endl;

    k = 19;
    limit = 0;
    for (auto i = clist.rbegin(); i != clist.rend() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == -expectedArr3[k]);
        k--;
    }
    cout << endl;

    assert(list.getFirst() == -59);
    assert(list.getLast() == -69);
    assert(clist.getSize() == 20);
    assert(clist.getFirst() == -59);
    assert(clist.getLast() == -69);

    cout << "PASS" << endl << endl;

    cout << "mutable reverse iterator:" << endl;
    limit = 0;
    for (auto i = list.rbegin(); i != list.rend() && limit < 100; i++, limit++)
    {
        *i = (*i) * (*i);
    }

    cout << clist << endl;

    k = 0; limit = 0;
    for (auto i = clist.begin(); i != clist.end() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == expectedArr3[k] * expectedArr3[k]);
        k++;
    }
    cout << endl;

    k = 19;
    limit = 0;
    for (auto i = clist.rbegin(); i != clist.rend() && limit < 100; i++, limit++)
    {
        cout << *i << ' ';
        assert(*i == expectedArr3[k] * expectedArr3[k]);
        k--;
    }
    cout << endl;

    assert(list.getFirst() == 59 * 59);
    assert(list.getLast() == 69 * 69);
    assert(clist.getSize() == 20);
    assert(clist.getFirst() == 59 * 59);
    assert(clist.getLast() == 69 * 69);

    cout << "PASS" << endl << endl;
}

const unsigned int MEMORY_LEAK_TEST_COUNT { 100000000 };

// Makes sure removeFirst and removeLast don't have memory leaks.
// Also uses addFirst and addLast, although they're less likely to be the source of any problems.
void memoryLeakTests()
{
    DoublyLinkedList<int> list;

    cout << "Checking for memory leak in removeFirst (may take a few seconds): " << endl;
    for (unsigned int i { 0 }; i < MEMORY_LEAK_TEST_COUNT; i++)
    {
        list.addFirst(i);
        list.removeFirst();
    }

    cout << "PASS" << endl << endl;

    cout << "Checking for memory leak in removeLast (may take a few seconds): " << endl;
    for (unsigned int i{ 0 }; i < MEMORY_LEAK_TEST_COUNT; i++)
    {
        list.addLast(i);
        list.removeLast();
    }

    cout << "PASS" << endl << endl;
}

// Tests the copy constructor for DoublyLinkedList.
void testCopyConstructor()
{
    DoublyLinkedList<int> original;
    for (int i = 0; i < 10; i++)
    {
        original.addLast(i);
    }

    int expectedOriginal[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    cout << "Testing copy constructor: " << endl;

    DoublyLinkedList<int> copy1{ original };

    cout << "Original: " << original << endl;
    cout << "Copy: " << copy1 << endl;
    cout << "PASS" << endl << endl;

    assert(copy1.getFirst() == 0);
    assert(copy1.getLast() == 9);

    // Run a subroutine to check the contents of the lists
    checkList(original, expectedOriginal, 10);
    checkList(copy1, expectedOriginal, 10);

    cout << "Modifying the copy: " << endl;
    copy1.getFirst() = 11;
    copy1.getLast() = 12;

    cout << "Original: " << original << endl;
    cout << "Copy: " << copy1 << endl;
    cout << "PASS" << endl << endl;

    assert(original.getFirst() == 0);
    assert(original.getLast() == 9);
    assert(copy1.getFirst() == 11);
    assert(copy1.getLast() == 12);

    cout << "Adding to the copy: " << endl;
    copy1.addFirst(13);
    copy1.addLast(14);

    cout << "Original: " << original << endl;
    cout << "Copy: " << copy1 << endl;
    cout << "PASS" << endl << endl;

    assert(original.getFirst() == 0);
    assert(original.getLast() == 9);
    assert(copy1.getFirst() == 13);
    assert(copy1.getLast() == 14);

    int expectedModified[12] = { 13, 11, 1, 2, 3, 4, 5, 6, 7, 8, 12, 14 };

    // Run a subroutine to check the contents of the lists
    checkList(original, expectedOriginal, 10);
    checkList(copy1, expectedModified, 12);

    cout << "Removing from the copy: " << endl;
    copy1.removeFirst();
    copy1.removeFirst();
    copy1.removeFirst();

    cout << "Original: " << original << endl;
    cout << "Copy: " << copy1 << endl;
    cout << "PASS" << endl << endl;

    assert(original.getFirst() == 0);
    assert(original.getLast() == 9);
    assert(copy1.getFirst() == 2);
    assert(copy1.getLast() == 14);

    // Run a subroutine to check the contents of the lists
    checkList(original, expectedOriginal, 10);
    checkList(copy1, &expectedModified[3], 9);

    cout << "Making another copy: " << endl;

    DoublyLinkedList<int> copy2{ original };

    cout << "Original: " << original << endl;
    cout << "Copy: " << copy2 << endl;
    cout << "PASS" << endl << endl;

    assert(copy2.getFirst() == 0);
    assert(copy2.getLast() == 9);

    // Run a subroutine to check the contents of the lists
    checkList(original, expectedOriginal, 10);
    checkList(copy2, expectedOriginal, 10);

    cout << "Modifying the original: " << endl;
    original.getFirst() = 11;
    original.getLast() = 12;

    cout << "Original: " << original << endl;
    cout << "Copy: " << copy2 << endl;
    cout << "PASS" << endl << endl;

    assert(copy2.getFirst() == 0);
    assert(copy2.getLast() == 9);
    assert(original.getFirst() == 11);
    assert(original.getLast() == 12);

    cout << "Adding to the original: " << endl;
    original.addFirst(13);
    original.addLast(14);

    cout << "Original: " << original << endl;
    cout << "Copy: " << copy2 << endl;
    cout << "PASS" << endl << endl;

    assert(copy2.getFirst() == 0);
    assert(copy2.getLast() == 9);
    assert(original.getFirst() == 13);
    assert(original.getLast() == 14);

    // Run a subroutine to check the contents of the lists
    checkList(original, expectedModified, 12);
    checkList(copy2, expectedOriginal, 10);

    cout << "Removing from the original: " << endl;
    original.removeFirst();
    original.removeFirst();
    original.removeFirst();

    cout << "Original: " << original << endl;
    cout << "Copy: " << copy2 << endl;
    cout << "PASS" << endl << endl;

    assert(copy2.getFirst() == 0);
    assert(copy2.getLast() == 9);
    assert(original.getFirst() == 2);
    assert(original.getLast() == 14);

    // Run a subroutine to check the contents of the lists
    checkList(original, &expectedModified[3], 9);
    checkList(copy2, expectedOriginal, 10);
}

// Tests the copy assignment operator for DoublyLinkedList.
void testCopyAssignment()
{
    DoublyLinkedList<int> original;
    for (int i = 0; i < 10; i++)
    {
        original.addLast(i);
    }

    int expectedOriginal[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    cout << "Testing copy assignment: " << endl;

    DoublyLinkedList<int> copy;
    copy = original;

    cout << "Original: " << original << endl;
    cout << "Copy: " << copy << endl;
    cout << "PASS" << endl << endl;

    assert(copy.getFirst() == 0);
    assert(copy.getLast() == 9);

    // Run a subroutine to check the contents of the lists
    checkList(original, expectedOriginal, 10);
    checkList(copy, expectedOriginal, 10);

    cout << "Modifying the copy: " << endl;
    copy.getFirst() = 11;
    copy.getLast() = 12;

    cout << "Original: " << original << endl;
    cout << "Copy: " << copy << endl;
    cout << "PASS" << endl << endl;

    assert(original.getFirst() == 0);
    assert(original.getLast() == 9);
    assert(copy.getFirst() == 11);
    assert(copy.getLast() == 12);

    cout << "Adding to the copy: " << endl;
    copy.addFirst(13);
    copy.addLast(14);

    cout << "Original: " << original << endl;
    cout << "Copy: " << copy << endl;
    cout << "PASS" << endl << endl;

    assert(original.getFirst() == 0);
    assert(original.getLast() == 9);
    assert(copy.getFirst() == 13);
    assert(copy.getLast() == 14);

    int expectedModified[12] = { 13, 11, 1, 2, 3, 4, 5, 6, 7, 8, 12, 14 };

    // Run a subroutine to check the contents of the lists
    checkList(original, expectedOriginal, 10);
    checkList(copy, expectedModified, 12);

    cout << "Removing from the copy: " << endl;
    copy.removeFirst();
    copy.removeFirst();
    copy.removeFirst();

    cout << "Original: " << original << endl;
    cout << "Copy: " << copy << endl;
    cout << "PASS" << endl << endl;

    assert(original.getFirst() == 0);
    assert(original.getLast() == 9);
    assert(copy.getFirst() == 2);
    assert(copy.getLast() == 14);

    // Run a subroutine to check the contents of the lists
    checkList(original, expectedOriginal, 10);
    checkList(copy, &expectedModified[3], 9);

    cout << "Making another copy: " << endl;

    copy = original;

    cout << "Original: " << original << endl;
    cout << "Copy: " << copy << endl;
    cout << "PASS" << endl << endl;

    assert(copy.getFirst() == 0);
    assert(copy.getLast() == 9);

    // Run a subroutine to check the contents of the lists
    checkList(original, expectedOriginal, 10);
    checkList(copy, expectedOriginal, 10);

    cout << "Modifying the original: " << endl;
    original.getFirst() = 11;
    original.getLast() = 12;

    cout << "Original: " << original << endl;
    cout << "Copy: " << copy << endl;
    cout << "PASS" << endl << endl;

    assert(copy.getFirst() == 0);
    assert(copy.getLast() == 9);
    assert(original.getFirst() == 11);
    assert(original.getLast() == 12);

    cout << "Adding to the original: " << endl;
    original.addFirst(13);
    original.addLast(14);

    cout << "Original: " << original << endl;
    cout << "Copy: " << copy << endl;
    cout << "PASS" << endl << endl;

    assert(copy.getFirst() == 0);
    assert(copy.getLast() == 9);
    assert(original.getFirst() == 13);
    assert(original.getLast() == 14);

    // Run a subroutine to check the contents of the lists
    checkList(original, expectedModified, 12);
    checkList(copy, expectedOriginal, 10);

    cout << "Removing from the original: " << endl;
    original.removeFirst();
    original.removeFirst();
    original.removeFirst();

    cout << "Original: " << original << endl;
    cout << "Copy: " << copy << endl;
    cout << "PASS" << endl << endl;

    assert(copy.getFirst() == 0);
    assert(copy.getLast() == 9);
    assert(original.getFirst() == 2);
    assert(original.getLast() == 14);

    // Run a subroutine to check the contents of the lists
    checkList(original, &expectedModified[3], 9);
    checkList(copy, expectedOriginal, 10);

    cout << "Check for memory leak (may take a few seconds): " << endl;
    for (unsigned int i{ 0 }; i < MEMORY_LEAK_TEST_COUNT / 10; i++)
    {
        copy = original;
        copy.addFirst(1);
    }
    cout << "PASS" << endl << endl;
}

// Runs all the required tests for part 1 of assignment 4.
void part1Tests()
{
    basicTests();
    memoryLeakTests();
    testCopyConstructor();
    testCopyAssignment();

    cout << "PART 1 TESTS PASSED!" << endl << endl;
}

// Implementation of insertion sort to use for testing linked-list sort.
template <typename T, typename C>
void insertionSort(T* a, unsigned int length, C comp)
{
    // Each iteration, one more item is sorted at the front of the list.
    for (unsigned int sortedCount{ 1 }; sortedCount < length; sortedCount++)
    {
        // Next item to insert comes immediately after the end of the sorted sublist.
        T toInsert{ a[sortedCount] };

        // Scan to the left, searching for the place to insert the item.
        // Keep going as long as the next item belongs after the item to be inserted.
        int j;
        for (j = { static_cast<int>(sortedCount - 1) }; j >= 0 && comp(toInsert, a[j]); j--)
        {
            // Shift items to the right to make space for the item being inserted.
            a[j + 1] = a[j];
        }

        // Put the item in its correct position.
        a[j + 1] = toInsert;
    }
}

// Standard, natural-order comparison function template
template <typename T>
bool naturalOrder(T t1, T t2)
{
    return t1 < t2;
}

// Function template for comparison that is like natural-order but reversed.
template <typename T>
bool reverseOrder(T t1, T t2)
{
    return t1 > t2;
}

// Generates a random integer between 0 and 999
int randomInt()
{
    return rand() % 1000;
}

// Generates a random double between 0.0 and 0.999
double randomDouble()
{
    return (rand() % 1000) / 1000.0;
}

// Generates a random sequence of 10 alphabetic characters
string randomString()
{
    char chars[10];
    for (int i = 0; i < 10; i++)
    {
        chars[i] = 'A' + (rand() % 26);
    }

    return chars;
}


// We should really make this a class with private members and public getters,
// but let's just keep things simple here.
struct Movie
{
    string title;
    string director;
    string genre;
    unsigned int year;
    bool operator==(const Movie& other);
    bool operator!=(const Movie& other) { return !(*this == other);  }
};

// Equality operator for movies.
bool Movie::operator==(const Movie& other)
{
    return title == other.title && director == other.director && genre == other.genre && year == other.year;
}

// Function template for ordering movies by director
bool orderByTitle(Movie item1, Movie item2)
{
    return item1.title < item2.title;
}

// Function template for ordering movies by director
bool orderByDirector(Movie item1, Movie item2)
{
    return item1.director < item2.director;
}

// Function template for ordering movies by director
bool orderByGenre(Movie item1, Movie item2)
{
    return item1.genre < item2.genre;
}

// Function template for ordering movies by director
bool orderByYear(Movie item1, Movie item2)
{
    return item1.year < item2.year;
}

// Stream insertion operator for movies
std::ostream& operator << (std::ostream& out, const Movie& movie)
{
    out << movie.title << "; " << movie.director << "; " << movie.genre << "; " << movie.year;
    return out;
}


// Runs a test using a specified comparison function and a random entry generator.
// Typename T must be explicitly specified to indicate what types of entries are to be used.
template <typename T, typename C, typename G>
void sortingTest(C comp, G generator)
{
    // Global constant to determine how many tests to run for each case.
    const unsigned int SORTING_TEST_COUNT{ 100 };

    DoublyLinkedList<T> actual {};
    T expected[SORTING_TEST_COUNT];

    for (int i = 2; i <= SORTING_TEST_COUNT; i++)
    {
        actual.clear();
        for (int j = 0; j < i; j++)
        {
            actual.addLast(generator());
            expected[j] = actual.getLast();
        }

        // Use insertion sort to predict the correct answer.
        insertionSort(expected, i, comp);

        // Test selection sort.
        sort(actual, comp);

        auto iterator{ actual.begin() };
        for (int j = 0; j < i - 1; j++)
        {
            // Make sure the actual sorted list produced by selection sort matches the expected 
            // sorted list (as determined by insertion sort).
            assert(*iterator == expected[j]);
            iterator++;
        }
    }
}

// Runs a sequence of tests for part 2 (sorting a doubly-linked list).
void part2Tests()
{
    Movie movies[5]
    {
        { "Star Wars", "Lucas, George", "Space Fantasy", 1977 },
        { "The Fellowship of the Ring", "Jackson, Peter", "Fantasy", 2001 },
        { "Star Trek", "Abrams, J.J.", "Science Fiction", 2009 },
        { "Monty Python and the Holy Grail", "Gilliam, Terry & Jones, Terry", "Comedy", 1975 },
        { "Raiders of the Lost Ark", "Spielberg, Steven", "Action / Adventure", 1981 }
    };

    DoublyLinkedList<Movie> movieList;

    for (unsigned int i{ 0 }; i < 5; i++)
    {
        movieList.addLast(movies[i]);
    }

    cout << "Unsorted movies:" << endl;
    for (unsigned int i{ 0 }; i < 5; i++)
    {
        cout << movies[i] << endl;
    }
    cout << endl;

    sort(movieList, &orderByTitle);
    insertionSort(movies, 5, &orderByTitle);

    auto it{ movieList.begin() };
    for (unsigned int index{ 0 }; index < 5; index++)
    {
        assert(*it == movies[index]);
        it++;
    }

    cout << "Ordered by title:" << endl;
    for (unsigned int i{ 0 }; i < 5; i++)
    {
        cout << movies[i] << endl;
    }
    cout << endl;

    sort(movieList, &orderByDirector);
    insertionSort(movies, 5, &orderByDirector);

    it = movieList.begin();
    for (unsigned int index{ 0 }; index < 5; index++)
    {
        assert(*it == movies[index]);
        it++;
    }

    cout << "Ordered by director:" << endl;
    for (unsigned int i{ 0 }; i < 5; i++)
    {
        cout << movies[i] << endl;
    }
    cout << endl;

    sort(movieList, &orderByGenre);
    insertionSort(movies, 5, &orderByGenre);

    it = movieList.begin();
    for (unsigned int index{ 0 }; index < 5; index++)
    {
        assert(*it == movies[index]);
        it++;
    }

    cout << "Ordered by genre:" << endl;
    for (unsigned int i{ 0 }; i < 5; i++)
    {
        cout << movies[i] << endl;
    }
    cout << endl;

    sort(movieList, &orderByYear);
    insertionSort(movies, 5, &orderByYear);

    it = movieList.begin();
    for (unsigned int index{ 0 }; index < 5; index++)
    {
        assert(*it == movies[index]);
        it++;
    }

    cout << "Ordered by year:" << endl;
    for (unsigned int i{ 0 }; i < 5; i++)
    {
        cout << movies[i] << endl;
    }
    cout << endl;

    cout << "Running more tests..." << endl;

    cout << "Testing int ascending: " << endl;
    sortingTest<int>(&naturalOrder<int>, &randomInt);
    cout << "Passed!" << endl;

    cout << "Testing int descending: " << endl;
    sortingTest<int>(&reverseOrder<int>, &randomInt);
    cout << "Passed!" << endl;

    cout << "Testing double ascending: " << endl;
    sortingTest<double>(&naturalOrder<double>, &randomDouble);
    cout << "Passed!" << endl;

    cout << "Testing double descending: " << endl;
    sortingTest<double>(&reverseOrder<double>, &randomDouble);
    cout << "Passed!" << endl;

    cout << "Testing string ascending: " << endl;
    sortingTest<string>(&naturalOrder<string>, &randomString);
    cout << "Passed!" << endl;

    cout << "Testing string descending: " << endl;
    sortingTest<string>(&reverseOrder<string>, &randomString);
    cout << "Passed!" << endl;

    cout << "PART 2 TESTS PASSED!" << endl << endl;
}

int main()
{
    part1Tests();
    part2Tests();

    cout << "ALL TESTS PASSED!" << endl;

    return 0;
}
