#ifndef LIBRARY_H
#define LIBRARY_H 

//////////////////////////////////////////////////////////////////////
/// @file library.h
/// @author James Anderson  CS 153 Section A
/// @brief Heder file for vector class for assignment 9
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class vector
/// @brief vector is used to create and edit an array with error handleing fetures 
///  giving programers the ability to push back items delete items clear and read
///  back items it has errors of out of bounds and container empty
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Vector<generic>::Vector ()
/// @brief creates a new vector 
/// @pre needs the type of variable to be sored in the vector
/// @post creates a new vector  
/// @param generic holds the type of variable the vector will hold
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Vector<generic>::push_back (generic x)
/// @brief adds another variable onto the top of the vector
/// @pre the perameter must be of the type specified when calling Array()
/// @post Push back will push one more variable onto the top of the array 
/// incressing the size by one if the max size is reached it will also double
/// the array size. 
/// @param x holds the variable that is to be pushed onto the vector
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Vector<generic>::pop_back ()
/// @brief delets top value off the vector 
/// @post will decresse the array size by one, if the size is one forth
/// of the max size it will decrese the size by half, and throw 
/// CONTAINER_EMPTY if the size is at 0
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Vector<generic>::clear ()
/// @brief clears all of the values in the vector 
/// @post decreses the size to 0 and max size to 1
/// @param generic holds the type of variable the array will hold
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Vector<generic>::operator[] (unsigned int x)
/// @brief Gets the value at a specified posision in the vector
/// @pre the array must have values in it
/// @post will read the value at the specified posititon and throw a OUT_OF_BOUNDS
/// error if a position is called that dose not exist
/// @param x holds the position the user wants to read
/// @return returns the value at the specified postion in the vector 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Vector<generic>::operator[] (unsigned int x) const
/// @brief Gets the constant value at a specified posision in the vector
/// @pre the vector must have values in it
/// @post will read the value at the specified posititon and throw a OUT_OF_BOUNDS
/// error if a position is called that dose not exist
/// @param x holds the position the user wants to read
/// @return returns the value at the specified postion in the vector 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Array<generic>::size () const
/// @brief Gets the constant value of the curent size of the vector 
/// @post will read the curent size
/// @return returns the size of the vector
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Array<generic>::max_size () const
/// @brief Gets the constant value of the max size of the vector 
/// @post will read the curent max size
/// @return returns the max size of the vector 
////////////////////////////////////////////////////////////////////// 


#include "exception.h"
#include "vector.h"
#include "cstdlib"
#include "iostream"
using std::cerr ;
using std::endl ;

// returns the index of where the generic was found in the vector
template <class generic>
unsigned int search (Vector<generic> &, generic);

template <class generic>
unsigned int binary_search (Vector<generic> &, generic);

// pass in the vector that is to be sorted least to greatest
template <class generic>
void bubble_sort (Vector<generic> &);

template <class generic>
void selection_sort (Vector<generic> &);

template <class generic>
void insertion_sort (Vector<generic> &);

#include "library.hpp"
#endif
