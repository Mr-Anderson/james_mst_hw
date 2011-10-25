#ifndef BTPOSTORDERITERATOR_H
#define BTPOSTORDERITERATOR_H

//////////////////////////////////////////////////////////////////////
/// @file BTPostorderIterator.h
/// @author James Anderson  CS 153 Section A
/// @brief Heder file for BTPostorderIterator  class for assignment 7
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class BTPostorderIterator 
/// @brief BTPostorderIterator is a iterator used to move through and extract data
/// from the binary tree class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTPostorderIterator <generic>::BTPostorderIterator ()
/// @brief creates a new BTPostorderIterator  
/// @post creates a new BTPostorderIterator   
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTPostorderIterator <generic>::BTPostorderIterator (Node<generic> * x);
/// @brief creates an iterator stating at a specific pointer
/// @param x holds pointer to the staring node of the iterator
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTPostorderIterator <generic>::generic operator* () const
/// @brief feeds back the value of the data in the curent node 
/// @return gives back the data found in the curent node
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTPostorderIterator <generic>::BTPostorderIterator operator++ ()
/// @brief advances the iterator by one  
/// @post iterator will be advanced by one
/// @returns the this operator 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTPostorderIterator <generic>::BTPostorderIterator operator++ (int)
/// @brief advances the iterator by one  
/// @post iterator will be advanced by one
/// @returns the this operator 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTPostorderIterator <generic>::operator== (const BTPostorderIterator & bt) const
/// @brief tells weather the iterator and another are equal
/// @param bt holds the pointer to the the other iterator
/// @return feeds back a 1 if they are equal and a 0 if not 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn BTPostorderIterator <generic>::operator!= (const BTPostorderIterator & bt) const
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
class BTPostorderIterator
{
  public:
    BTPostorderIterator ();
    BTPostorderIterator (Btn<generic> *);
    generic operator* () const;
    BTPostorderIterator operator++ ();
    BTPostorderIterator operator++ (int);
    bool operator== (const BTPostorderIterator &) const;
    bool operator!= (const BTPostorderIterator &) const;
	Btn<generic> * current();
	
  private:
    Btn<generic> * m_current;
    void parent ( bool , bool );
};

#include "btpostorderiterator.hpp"
#endif
