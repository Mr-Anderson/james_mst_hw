#ifndef SLIST_H
#define SLIST_H

//////////////////////////////////////////////////////////////////////
/// @file slist.h
/// @author James Anderson  CS 153 Section A
/// @brief Heder file for single linked class for assignment 3
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class SList
/// @brief slist is used to create and edit a single linked list and 
/// includes funtions to add remove and iterate the list.
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn SList<generic>::SList ()
/// @brief creates a new single linked list
/// @pre needs the type of variable to be sored in the SList
/// @post creates a new empty list  
/// @param generic holds the type of variable the list will hold
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn SList<generic>::SList (SList & l);
/// @brief creates a new single linked list and copys existing list into it
/// @pre needs the type of variable to be sored in the list and and 
/// exsiting list of the same type
/// @post creates a new list inhariting the variables of existing list 
/// @param Slist & l holds the list to be copied 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn SList<generic>::~SList;
/// @brief destructor for Slist
/// @post clears the curent list 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn SList<generic>:: operator= (const SList & l)
/// @brief alows you to assign one list to another
/// @pre the two list must be of the same type
/// @post copys one list into the other 
/// @param const SList & l holds the list to be copied 
/// @return returns the curent list 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn SList<generic>::pust_front (generic x)
/// @brief adds a value to the top of the list
/// @post will add x to the top of the list and increse the size 
/// @param x holds the value to be added to the list
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn SList<generic>::pop_front ()
/// @brief delets top value off the SList 
/// @post decreses the list size by one taking off the top variable
/// and will throw CONTAINER_EMPTY if the size is at 0
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn SList<generic>::remove (generic x)
/// @brief removes all values mathing the specivied value
/// @post removes all values and decreses size of list
/// @param x holds the variable value to be removed
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn SList<generic>::clear ()
/// @brief clears all of the values in the SList 
/// @post decreses the size to 0 and sets the head to null
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn SList<generic>::front ()
/// @brief retunst the value of the front pointer
/// @post will reurn the front
/// @return returns the pointer m_front
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn SList<generic>::size () const
/// @brief feeds back the size of the list
/// @return returns the size of the list 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn SList<generic>::empty () 
/// @brief tells whether or not the list is empty
/// @return returns a bool with 1 for empty and 0 for not 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn SList<generic>::Iterator begin () const;
/// @brief returns an Iterator to the first node on the list 
/// @return returns a pointer to the first node
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn SList<generic>::Iterator end () const;
/// @brief returns an Iterator to the last node on the list 
/// @return returns a pointer to the last node
//////////////////////////////////////////////////////////////////////

#include "exception.h"
#include "snode.h"
#include "slistiterator.h"


template <class generic>
class SList
{
  public:
    SList ();
    SList (SList &);
    ~SList ();
    SList & operator= (const SList &);
    void push_front (generic);
    void pop_front ();
    void remove (generic);
    generic & front ();
    void clear ();
    unsigned int size () const;
    bool empty () const;
    typedef SListIterator<generic> Iterator;
    Iterator begin () const;
    Iterator end () const;

  private:
    unsigned int m_size;
    SNode<generic> * m_front;
};

#include "slist.hpp"
#endif
