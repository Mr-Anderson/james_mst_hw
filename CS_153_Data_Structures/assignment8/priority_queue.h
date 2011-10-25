#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

//////////////////////////////////////////////////////////////////////
/// @file priority_queue.h
/// @author James Anderson  CS 153 Section A
/// @brief Heder file for double linked class for assignment 8
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class Priority Queue
/// @brief Priority Queue is used to create and edit a Priority Queue and 
/// includes funtions to add remove and iterate the Priority Queue.
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Priority Queue<generic>::Priority Queue ()
/// @brief creates a new Priority Queue
/// @pre needs the type of variable to be sored in the Priority Queue
/// @post creates a new empty Priority Queue  
/// @param generic holds the type of variable the Priority Queue will hold
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Priority Queue<generic>::Priority Queue (Priority Queue & x)
/// @brief creates a new  Priority Queue and copys existing Priority Queue into it
/// @pre needs the type of variable to be sored in the Priority Queue and and 
/// exsiting Priority Queue of the same type
/// @post creates a new Priority Queue inhariting the variables of existing Priority Queue 
/// @param Priority Queue & x holds the Priority Queue to be copied 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Priority Queue<generic>:: operator= (const Priority Queue & x)
/// @brief alows you to assign one Priority Queue to another
/// @pre the two Priority Queue must be of the same type
/// @post copys one Priority Queue into the other 
/// @param const Priority Queue & x holds the Priority Queue to be copied 
/// @return returns the curent Priority Queue 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Priority Queue<generic>::clear ()
/// @brief clears all of the values in the Priority Queue 
/// @post decreses the size to 0 and sets the root to null
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Priority Queue<generic>::empty () 
/// @brief tells whether or not the Priority Queue is empty
/// @return returns a bool with 1 for empty and 0 for not 
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/// @fn Priority Queue<generic>::size () const
/// @brief feeds back the size of the Priority Queue
/// @return returns the size of the Priority Queue 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn PreOrder<generic>::pre_begin () const
/// @brief returns an Iterator to the first node on the Priority Queue 
/// @return returns a pointer to the first node
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn PreOrder<generic>::pre_end () const
/// @brief returns an Iterator to the last node on the Priority Queue 
/// @return returns a pointer to the last node
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/// @fn InOrder<generic>::in_begin () const
/// @brief returns an Iterator to the first node on the Priority Queue 
/// @return returns a pointer to the first node
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn InOrder<generic>::in_end () const
/// @brief returns an Iterator to the last node on the Priority Queue 
/// @return returns a pointer to the last node
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/// @fn PostOrder<generic>::post_begin () const
/// @brief returns an Iterator to the first node on the Priority Queue 
/// @return returns a pointer to the first node
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn PostOrder<generic>::post_end () const
/// @brief returns an Iterator to the last node on the Priority Queue 
/// @return returns a pointer to the last node
//////////////////////////////////////////////////////////////////////

#include "bt.h"
#include "btn.h"
#include "exception.h"
template <class generic>
class Priority_queue : public BT<generic>
{
  public:
    Priority_queue();
	~Priority_queue();
    Priority_queue(Priority_queue &);
    Priority_queue & operator= ( Priority_queue &);
    void push( generic x );
    void pop();
    generic top();
	bool empty() const;
	unsigned int size () const ;
	
  private:
  
    void swap ( Btn<generic> *,  Btn<generic> *);
	void heapify( Btn<generic> * );
	void heepify( );
	void clear ( );
	using BT<generic>:: m_size;
	using BT<generic>:: m_root;	
	Btn<generic> * m_push ;
	Btn<generic> * m_pop ;
	
};

#include "priority_queue.hpp"
#endif
