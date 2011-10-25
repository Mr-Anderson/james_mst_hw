#ifndef BT_H
#define BT_H

//////////////////////////////////////////////////////////////////////
/// @file bt.h
/// @author James Anderson  CS 153 Section A
/// @brief Heder file for double linked class for assignment 7
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class Bt
/// @brief Bt is used to create and edit a double linked bt and 
/// includes funtions to add remove and iterate the bt.
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bt<generic>::Bt ()
/// @brief creates a new double linked bt
/// @pre needs the type of variable to be sored in the Bt
/// @post creates a new empty bt  
/// @param generic holds the type of variable the bt will hold
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bt<generic>::Bt (Bt & x)
/// @brief creates a new  bt and copys existing bt into it
/// @pre needs the type of variable to be sored in the bt and and 
/// exsiting bt of the same type
/// @post creates a new bt inhariting the variables of existing bt 
/// @param Bt & x holds the bt to be copied 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bt<generic>:: operator= (const Bt & x)
/// @brief alows you to assign one bt to another
/// @pre the two bt must be of the same type
/// @post copys one bt into the other 
/// @param const Bt & x holds the bt to be copied 
/// @return returns the curent bt 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bt<generic>::clear ()
/// @brief clears all of the values in the Bt 
/// @post decreses the size to 0 and sets the root to null
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bt<generic>::empty () 
/// @brief tells whether or not the bt is empty
/// @return returns a bool with 1 for empty and 0 for not 
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/// @fn Bt<generic>::size () const
/// @brief feeds back the size of the bt
/// @return returns the size of the bt 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn PreOrder<generic>::pre_begin () const
/// @brief returns an Iterator to the first node on the bt 
/// @return returns a pointer to the first node
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn PreOrder<generic>::pre_end () const
/// @brief returns an Iterator to the last node on the bt 
/// @return returns a pointer to the last node
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/// @fn InOrder<generic>::in_begin () const
/// @brief returns an Iterator to the first node on the bt 
/// @return returns a pointer to the first node
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn InOrder<generic>::in_end () const
/// @brief returns an Iterator to the last node on the bt 
/// @return returns a pointer to the last node
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/// @fn PostOrder<generic>::post_begin () const
/// @brief returns an Iterator to the first node on the bt 
/// @return returns a pointer to the first node
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn PostOrder<generic>::post_end () const
/// @brief returns an Iterator to the last node on the bt 
/// @return returns a pointer to the last node
//////////////////////////////////////////////////////////////////////

#include "btn.h"
#include "exception.h"
#include "btpreorderiterator.h"
#include "btinorderiterator.h"
#include "btpostorderiterator.h"

template <class generic>
class BT
{
  public:
    BT();
    ~BT();
    BT(BT &);
    BT & operator= (const BT &);
    void clear ();
    bool empty () const;
    unsigned int size () const;
    typedef BTPreorderIterator<generic> PreOrder;
    typedef BTInorderIterator<generic> InOrder;
    typedef BTPostorderIterator<generic> PostOrder;
    PreOrder pre_begin () const;
    PreOrder pre_end () const;
    InOrder in_begin () const;
    InOrder in_end () const;
    PostOrder post_begin () const;
    PostOrder post_end () const;

  protected:
    Btn<generic> * m_root;
    unsigned int m_size;
    void swap (Btn<generic> *, Btn<generic> *);
	void i_give_up_insert (generic,short) ;
};

#include "bt.hpp"
#endif
