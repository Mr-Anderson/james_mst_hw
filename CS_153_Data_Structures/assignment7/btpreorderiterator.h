#ifndef BTPREORDERITERATOR_H
#define BTPREORDERITERATOR_H

//////////////////////////////////////////////////////////////////////
/// @file BTPreorderIterator.h
/// @author James Anderson  CS 153 Section A
/// @brief Heder file for BTPreorderIterator  class for assignment 7
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class BTPreorderIterator 
/// @brief BTPreorderIterator is a iterator used to move through and extract data
/// from the binary tree class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTPreorderIterator <generic>::BTPreorderIterator ()
/// @brief creates a new BTPreorderIterator  
/// @post creates a new BTPreorderIterator   
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTPreorderIterator <generic>::BTPreorderIterator (Node<generic> * x);
/// @brief creates an iterator stating at a specific pointer
/// @param x holds pointer to the staring node of the iterator
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTPreorderIterator <generic>::generic operator* () const
/// @brief feeds back the value of the data in the curent node 
/// @return gives back the data found in the curent node
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTPreorderIterator <generic>::BTPreorderIterator operator++ ()
/// @brief advances the iterator by one  
/// @post iterator will be advanced by one
/// @returns the this operator 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTPreorderIterator <generic>::BTPreorderIterator operator++ (int)
/// @brief advances the iterator by one  
/// @post iterator will be advanced by one
/// @returns the this operator 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTPreorderIterator <generic>::operator== (const BTPreorderIterator & bt) const
/// @brief tells weather the iterator and another are equal
/// @param bt holds the pointer to the the other iterator
/// @return feeds back a 1 if they are equal and a 0 if not 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTPreorderIterator <generic>::operator!= (const BTPreorderIterator & bt) const
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
class BTPreorderIterator
{
  public:
    BTPreorderIterator ();
    BTPreorderIterator (Btn<generic> *);
    generic operator* () const;
    BTPreorderIterator operator++ ();
    BTPreorderIterator operator++ (int);
    bool operator== (const BTPreorderIterator &) const;
    bool operator!= (const BTPreorderIterator &) const;
	Btn<generic> * current();
	
  private:
    Btn<generic> * m_current;
    void parent ( bool , bool );
};

#include "btpreorderiterator.hpp"
#endif
