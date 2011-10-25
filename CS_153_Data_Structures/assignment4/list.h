#ifndef LIST_H
#define LIST_H
//////////////////////////////////////////////////////////////////////
/// @file list.h
/// @author James Anderson  CS 153 Section A
/// @brief Heder file for double linked class for assignment 4
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class List
/// @brief List is used to create and edit a double linked list and 
/// includes funtions to add remove and iterate the list.
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn List<generic>::List ()
/// @brief creates a new double linked list
/// @pre needs the type of variable to be sored in the List
/// @post creates a new empty list  
/// @param generic holds the type of variable the list will hold
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn List<generic>::List (List & l);
/// @brief creates a new double linked list and copys existing list into it
/// @pre needs the type of variable to be sored in the list and and 
/// exsiting list of the same type
/// @post creates a new list inhariting the variables of existing list 
/// @param List & l holds the list to be copied 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn List<generic>::~List;
/// @brief destructor for List
/// @post clears the curent list 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn List<generic>:: operator= (const List & l)
/// @brief alows you to assign one list to another
/// @pre the two list must be of the same type
/// @post copys one list into the other 
/// @param const List & l holds the list to be copied 
/// @return returns the curent list 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn List<generic>::pust_front (generic x)
/// @brief adds a value to the top of the list
/// @post will add x to the top of the list and increse the size 
/// @param x holds the value to be added to the list
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn List<generic>::pop_front ()
/// @brief delets top value off the List 
/// @post decreses the list size by one taking off the top variable
/// and will throw CONTAINER_EMPTY if the size is at 0
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn List<generic>::push_back (generic x)
/// @brief adds a value to the top of the list
/// @post will add x to the top of the list and increse the size 
/// @param x holds the value to be added to the list
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn List<generic>::pop_back ()
/// @brief delets top value off the List 
/// @post decreses the list size by one taking off the back variable
/// and will throw CONTAINER_EMPTY if the size is at 0
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn List<generic>::remove (generic x)
/// @brief removes all values mathing the specivied value
/// @post removes all values and decreses size of list
/// @param x holds the variable value to be removed
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn List<generic>::clear ()
/// @brief clears all of the values in the List 
/// @post decreses the size to 0 and sets the head to null
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn List<generic>::front ()
/// @brief retunst the value of the front pointer
/// @post will reurn the front
/// @return returns the pointer m_front
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn List<generic>::back ()
/// @brief retunst the value of the back pointer
/// @post will reurn the back
/// @return returns the pointer m_front
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn List<generic>::size () const
/// @brief feeds back the size of the list
/// @return returns the size of the list 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn List<generic>::empty () 
/// @brief tells whether or not the list is empty
/// @return returns a bool with 1 for empty and 0 for not 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn List<generic>::Iterator begin () const;
/// @brief returns an Iterator to the first node on the list 
/// @return returns a pointer to the first node
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn List<generic>::Iterator end () const;
/// @brief returns an Iterator to the last node on the list 
/// @return returns a pointer to the last node
//////////////////////////////////////////////////////////////////////

#include "listiterator.h"
#include "exception.h"
#include "node.h"

template <class generic>
class List
{
  public:
    List ();
    List (List &);
    ~List ();
    List & operator= (const List &);
    void push_front (generic);
    void pop_front ();
    void push_back (generic);
    void pop_back ();
    void remove (generic);
    generic & front ();
    generic & back ();
    void clear ();
    unsigned int size () const;
    bool empty () const;
    typedef ListIterator<generic> Iterator;
    Iterator begin () const;
    Iterator end () const;

  private:
    unsigned int m_size;
    Node<generic> * m_front;
    Node<generic> * m_back;
};

#include "list.hpp"
#endif
