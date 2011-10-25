#ifndef SLISTITERATOR_H
#define SLISTITERATOR_H

//////////////////////////////////////////////////////////////////////
/// @file slistiteratior.h
/// @author James Anderson  CS 153 Section A
/// @brief Heder file for SListIterator  class for assignment 4
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class SListIterator 
/// @brief SListIterator is a iterator used to move through and extract data
/// from the slist class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn SListIterator <generic>::SListIterator ()
/// @brief creates a new SListIterator  
/// @post creates a new SListIterator   
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn SListIterator <generic>::SListIterator (SNode<generic> * x);
/// @brief creates an iterator stating at a specific pointer
/// @param x holds pointer to the staring node of the iterator
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn SListIterator <generic>::generic operator* () const
/// @brief feeds back the value of the data in the curent node 
/// @return gives back the data found in the curnt node
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn SListIterator <generic>::SListIterator operator++ ()
/// @brief advances the iterator by one  
/// @post iterator will be advanced by one
/// @returns the this operator 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn SListIterator <generic>::SListIterator operator++ (int)
/// @brief advances the iterator by one  
/// @post iterator will be advanced by one
/// @returns the this operator 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn SListIterator <generic>::operator== (const SListIterator & rhs) const
/// @brief tells weather the iterator and another are equal
/// @param rhs holst the pointer to the the other iterator
/// @return feeds back a 1 if they are equal and a 0 if not 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn SListIterator <generic>::operator!= (const SListIterator & rhs) const
/// @brief tells weather the iterator and another are equal
/// @param rhs holst the pointer to the the other iterator
/// @return feeds back a 0 if they are equal and a 1 if not 
////////////////////////////////////////////////////////////////////// 

#include "snode.h"

template <class generic>
class SListIterator
{
  public:
    SListIterator ();
    SListIterator (SNode<generic> *);
    generic operator* () const;
    SListIterator operator++ ();
    SListIterator operator++ (int);
    bool operator== (const SListIterator &) const;
    bool operator!= (const SListIterator &) const;

  private:
    SNode<generic> * m_current;
};

#include "slistiterator.hpp"
#endif
