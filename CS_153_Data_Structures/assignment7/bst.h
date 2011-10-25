#ifndef BST_H
#define BST_H

//////////////////////////////////////////////////////////////////////
/// @file bst.h
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


#include "bt.h"
#include "btn.h"
#include "exception.h"
#include "iostream"

using std::cout;
using std::cerr;
using std::endl;
using std::cin;

template <class generic>
class Bst : public BT<generic>
{
  public:
    typedef BTPreorderIterator<generic> PreOrder;
    typedef BTInorderIterator<generic> InOrder;
    typedef BTPostorderIterator<generic> PostOrder;
    PreOrder pre_search (generic);
    InOrder in_search (generic);
    PostOrder post_search (generic);
	void swap ( Btn<generic> *,  Btn<generic> *);
	
  private:
	using BT<generic>:: m_size;
	using BT<generic>:: m_root;
    
  protected:
    //returns a pointer to the parent of the inserted node
    Btn<generic> * p_insert(generic); 
    //returns a pointer to the parent of the deleted node
    Btn<generic> * p_remove(generic); 
    //returns a pointer to the node containing the found data
    Btn<generic> * p_search (generic); 
	
};

#include "bst.hpp"
#endif
