#ifndef ARRAY_H
#define ARRAY_H
//////////////////////////////////////////////////////////////////////
/// @file array.h
/// @author James Anderson  CS 153 Section A
/// @brief Heder file for array class for assignment 1
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class array
/// @brief array is used to create and edit an array with error handleing fetures 
///  giving programers the ability to push back items delete items clear and read
///  back items it has errors of out of bounds container empty and container full
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Array<generic>::Array ()
/// @brief creates a new array 
/// @pre needs the type of variable to be sored in the array
/// @post creates a new array with the max size of 20 
/// @param generic holds the type of variable the array will hold
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Array<generic>::push_back (generic x)
/// @brief adds another variable onto the top of the array
/// @pre the perameter must be of the type specified when calling Array()
/// @post Push back will push one more variable onto the top of the array 
/// incressing the size by one and will throw CONTAINER_FULL if the max size 
/// is reached 
/// @param x holds the variable that is to be pushed onto the array
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Array<generic>::pop_back ()
/// @brief delets top value off the array 
/// @post will decresse the array size by one and throw CONTAINER_EMPTY 
///  if the size is at 0
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Array<generic>::clear ()
/// @brief clears all of the values in the array 
/// @post decreses the size to 0
/// @param generic holds the type of variable the array will hold
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Array<generic>::operator[] (unsigned int x)
/// @brief Gets the value at a specified posision in the array
/// @pre the array must have values in it
/// @post will read the value at the specified posititon and throw a OUT_OF_BOUNDS
/// error if a position is called that dose not exist
/// @param x holds the position the user wants to read
/// @return returns the value at the specified postion in the array 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Array<generic>::operator[] (unsigned int x) const
/// @brief Gets the constant value at a specified posision in the array
/// @pre the array must have values in it
/// @post will read the value at the specified posititon and throw a OUT_OF_BOUNDS
/// error if a position is called that dose not exist
/// @param x holds the position the user wants to read
/// @return returns the value at the specified postion in the array 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Array<generic>::size () const
/// @brief Gets the constant value of the curent size of the array 
/// @post will read the curent size
/// @return returns the size of the array 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Array<generic>::max_size () const
/// @brief Gets the constant value of the max size of the array 
/// @post will read the max size
/// @return returns the max size of the array 
////////////////////////////////////////////////////////////////////// 
#include "exception.h"

template <class generic>
class Array
{
  public:
    Array ();
    void push_back (generic);
    void pop_back ();
    void clear ();
    generic& operator[] (unsigned int);
    generic& operator[] (unsigned int) const;
    unsigned int size () const; ///< holds the current size of the array
    unsigned int max_size () const; ///< holds the max size of the array

  private:
    unsigned int m_size; ///< holds the size of the list
    unsigned int m_max_size; ///< holds the size of the list
    generic m_data[20]; ///< generic array that holds data
};

#include "array.hpp"
#endif
