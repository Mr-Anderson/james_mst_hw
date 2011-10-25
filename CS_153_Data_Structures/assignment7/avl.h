#ifndef AVL_H
#define AVL_H

//////////////////////////////////////////////////////////////////////
/// @file avl.h
/// @author James Anderson  CS 153 Section A
/// @brief Heder file for binary search tree class for assignment 7
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bst<generic>::insert (generic x)
/// @brief inserts  value into the Bst 
/// @post inserts value into corect place in the Bst and incresses size
/// @param x holds the variable value to be removed
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bst<generic>::remove (generic x)
/// @brief removes all values mathing the specivied value
/// @post removes all values and decreses size of bst
/// @param x holds the variable value to be removed
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn PreOrder<generic>::pre_search (generic x)
/// @brief returns an iterator starting at the value specified
/// @post returns iterator starting at the search 
/// @return returns iterator starting at the search 
/// @param x holds the variable value to be searched for
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn InOrder<generic>::pin_search (generic x)
/// @brief returns an iterator starting at the value specified
/// @post returns iterator starting at the search 
/// @return returns iterator starting at the search 
/// @param x holds the variable value to be searched for
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn PostOrder<generic>::post_search (generic x)
/// @brief returns an iterator starting at the value specified
/// @post returns iterator starting at the search 
/// @return returns iterator starting at the search 
/// @param x holds the variable value to be searched for
////////////////////////////////////////////////////////////////////// 

#include "bst.h"
template <class generic>
class Avl : public Bst<generic>
{
  public:
    void insert( generic x );
    void remove( generic x );
	
  private:
  
	void delete_leaf (Btn<generic> *temp1);
	void delete_link (Btn<generic> *temp1);
	void insert_balance (Btn<generic> * problem );
	void right_right (Btn<generic> * , Btn<generic> * );
	void left_left (Btn<generic> * , Btn<generic> * );
	void left_right (Btn<generic> * , Btn<generic> * );
	void right_left (Btn<generic> * , Btn<generic> * );
	using Bst<generic>:: swap;
	using Bst<generic>:: m_size;
	using Bst<generic>:: m_root;
	
	
    

};

#include "avl.hpp"
#endif
