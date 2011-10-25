#ifndef LIBRARY_H
#define LIBRARY_H 

//////////////////////////////////////////////////////////////////////
/// @file library.h
/// @author James Anderson  CS 153 Section A
/// @brief Heder file for library class for assignment 9
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class library
/// @brief library contains several sort and search functions
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn search (Vector<generic> &, generic);
/// @brief dose a linar search 
/// @pre needs a sorted vector and the data to be seached for
/// @post outputs location of data or throws exeption 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn binary_search (Vector<generic> &, generic);
/// @brief dose a binary search 
/// @pre needs a sorted vector and the data to be seached for
/// @post outputs location of data or throws exeption 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn bubble_sort (Vector<generic> &);
/// @brief dose a bubble sort
/// @pre needs vector with the data to be sorted
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn selecton_sort (Vector<generic> &);
/// @brief dose a bubble sort
/// @pre needs vector with the data to be sorted
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn insertion_sort (Vector<generic> &);
/// @brief dose a bubble sort
/// @pre needs vector with the data to be sorted
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
