#ifndef BST_H
#define BST_H

//////////////////////////////////////////////////////////////////////
/// @file bst.h
/// @author James Anderson  CS 153 Section A
/// @brief Heder file for double linked class for assignment 5
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class Bst
/// @brief Bst is used to create and edit a double linked bst and 
/// includes funtions to add remove and iterate the bst.
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bst<generic>::Bst ()
/// @brief creates a new double linked bst
/// @pre needs the type of variable to be sored in the Bst
/// @post creates a new empty bst  
/// @param generic holds the type of variable the bst will hold
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bst<generic>::Bst (Bst & l);
/// @brief creates a new double linked bst and copys existing bst into it
/// @pre needs the type of variable to be sored in the bst and and 
/// exsiting bst of the same type
/// @post creates a new bst inhariting the variables of existing bst 
/// @param Bst & l holds the bst to be copied 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bst<generic>::~Bst;
/// @brief destructor for Bst
/// @post clears the curent bst 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bst<generic>:: operator= (const Bst & l)
/// @brief alows you to assign one bst to another
/// @pre the two bst must be of the same type
/// @post copys one bst into the other 
/// @param const Bst & l holds the bst to be copied 
/// @return returns the curent bst 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bst<generic>::pust_front (generic x)
/// @brief adds a value to the top of the bst
/// @post will add x to the top of the bst and increse the size 
/// @param x holds the value to be added to the bst
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bst<generic>::pop_front ()
/// @brief delets top value off the Bst 
/// @post decreses the bst size by one taking off the top variable
/// and will throw CONTAINER_EMPTY if the size is at 0
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bst<generic>::push_back (generic x)
/// @brief adds a value to the top of the bst
/// @post will add x to the top of the bst and increse the size 
/// @param x holds the value to be added to the bst
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bst<generic>::pop_back ()
/// @brief delets top value off the Bst 
/// @post decreses the bst size by one taking off the back variable
/// and will throw CONTAINER_EMPTY if the size is at 0
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bst<generic>::remove (generic x)
/// @brief removes all values mathing the specivied value
/// @post removes all values and decreses size of bst
/// @param x holds the variable value to be removed
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bst<generic>::clear ()
/// @brief clears all of the values in the Bst 
/// @post decreses the size to 0 and sets the head to null
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bst<generic>::front ()
/// @brief retunst the value of the front pointer
/// @post will reurn the front
/// @return returns the pointer m_root
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bst<generic>::back ()
/// @brief retunst the value of the back pointer
/// @post will reurn the back
/// @return returns the pointer m_root
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bst<generic>::size () const
/// @brief feeds back the size of the bst
/// @return returns the size of the bst 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bst<generic>::empty () 
/// @brief tells whether or not the bst is empty
/// @return returns a bool with 1 for empty and 0 for not 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bst<generic>::Iterator begin () const;
/// @brief returns an Iterator to the first node on the bst 
/// @return returns a pointer to the first node
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Bst<generic>::Iterator end () const;
/// @brief returns an Iterator to the last node on the bst 
/// @return returns a pointer to the last node
//////////////////////////////////////////////////////////////////////

#include "btn.h"
#include "exception.h"
#include "iostream"

using std::cout;
using std::cerr;
using std::endl;
using std::cin;

template <class generic>
class Bst
{
  public:
    Bst ();
    ~Bst ();
    void insert (generic);
    void remove (generic);
    generic & search (generic);
    void clear ();
    bool empty () const;
    unsigned int size () const;
	
  private:
    unsigned int m_size;
    Btn<generic> * m_root;
    void swap ( Btn<generic> *,  Btn<generic> *);
    void delete_leaf ( Btn<generic> * );
    void delete_link ( Btn<generic> * );
    
  protected:
    
    //returns a pointer to the parent of the inserted node
    Btn<generic> * p_insert (generic); 
    //returns a pointer to the parent of the deleted node
    Btn<generic> * p_remove (generic); 
    //returns a pointer to the node containing the found data
    Btn<generic> * p_search (generic); 
	
};

#include "bst.hpp"
#endif
