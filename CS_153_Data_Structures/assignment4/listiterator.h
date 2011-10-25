#ifndef LISTITERATOR_H
#define LISTITERATOR_H

//////////////////////////////////////////////////////////////////////
/// @file ListIterator.h
/// @author James Anderson  CS 153 Section A
/// @brief Heder file for ListIterator  class for assignment 4
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class ListIterator 
/// @brief ListIterator is a iterator used to move through and extract data
/// from the list class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn ListIterator <generic>::ListIterator ()
/// @brief creates a new ListIterator  
/// @post creates a new ListIterator   
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn ListIterator <generic>::ListIterator (Node<generic> * x);
/// @brief creates an iterator stating at a specific pointer
/// @param x holds pointer to the staring node of the iterator
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn ListIterator <generic>::generic operator* () const
/// @brief feeds back the value of the data in the curent node 
/// @return gives back the data found in the curnt node
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn ListIterator <generic>::ListIterator operator++ ()
/// @brief advances the iterator by one  
/// @post iterator will be advanced by one
/// @returns the this operator 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn ListIterator <generic>::ListIterator operator++ (int)
/// @brief advances the iterator by one  
/// @post iterator will be advanced by one
/// @returns the this operator 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn ListIterator <generic>::operator== (const ListIterator & rhs) const
/// @brief tells weather the iterator and another are equal
/// @param rhs holst the pointer to the the other iterator
/// @return feeds back a 1 if they are equal and a 0 if not 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn ListIterator <generic>::operator!= (const ListIterator & rhs) const
/// @brief tells weather the iterator and another are equal
/// @param rhs holst the pointer to the the other iterator
/// @return feeds back a 0 if they are equal and a 1 if not 
////////////////////////////////////////////////////////////////////// 

#include "node.h"

template <class generic>
class ListIterator
{
  public:
    ListIterator ();
    ListIterator (Node<generic> *);
    generic operator* () const;
    ListIterator operator++ ();
    ListIterator operator++ (int);
    ListIterator operator-- ();
    ListIterator operator-- (int);
    bool operator== (const ListIterator &) const;
    bool operator!= (const ListIterator &) const;

  private:
    Node<generic> * m_current;
};

#include "listiterator.hpp"
#endif
