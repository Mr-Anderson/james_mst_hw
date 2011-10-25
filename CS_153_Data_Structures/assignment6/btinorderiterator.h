#ifndef BTINORDERITERATOR_H
#define BTINORDERITERATOR_H

//////////////////////////////////////////////////////////////////////
/// @file BTInorderIterator.h
/// @author James Anderson  CS 153 Section A
/// @brief Heder file for BTInorderIterator  class for assignment 6
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class BTInorderIterator 
/// @brief BTInorderIterator is a iterator used to move through and extract data
/// from the binary tree class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTInorderIterator <generic>::BTInorderIterator ()
/// @brief creates a new BTInorderIterator  
/// @post creates a new BTInorderIterator   
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTInorderIterator <generic>::BTInorderIterator (Node<generic> * x);
/// @brief creates an iterator stating at a specific pointer
/// @param x holds pointer to the staring node of the iterator
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTInorderIterator <generic>::generic operator* () const
/// @brief feeds back the value of the data in the curent node 
/// @return gives back the data found in the curent node
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTInorderIterator <generic>::BTInorderIterator operator++ ()
/// @brief advances the iterator by one  
/// @post iterator will be advanced by one
/// @returns the this operator 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTInorderIterator <generic>::BTInorderIterator operator++ (int)
/// @brief advances the iterator by one  
/// @post iterator will be advanced by one
/// @returns the this operator 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTInorderIterator <generic>::operator== (const BTInorderIterator & bt) const
/// @brief tells weather the iterator and another are equal
/// @param bt holds the pointer to the the other iterator
/// @return feeds back a 1 if they are equal and a 0 if not 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTInorderIterator <generic>::operator!= (const BTInorderIterator & bt) const
/// @brief tells weather the iterator and another are equal
/// @param bt holst the pointer to the the other iterator
/// @return feeds back a 0 if they are equal and a 1 if not 
////////////////////////////////////////////////////////////////////// 


#include "btn.h"
#include "exception.h"
#include "iostream"

using std::cout;
using std::cerr;
using std::endl;
using std::cin;


template <class generic>
class BTInorderIterator
{
  public:
    BTInorderIterator ();
    BTInorderIterator (Btn<generic> *);
    generic operator* () const;
    BTInorderIterator operator++ ();
    BTInorderIterator operator++ (int);
    bool operator== (const BTInorderIterator &) const;
    bool operator!= (const BTInorderIterator &) const;
  private:
    Btn<generic> * m_current;    void parent ( bool , bool );
};

#include "btinorderiterator.hpp"
#endif
