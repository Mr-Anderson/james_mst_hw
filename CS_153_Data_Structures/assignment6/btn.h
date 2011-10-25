#ifndef BTN_H
#define BTN_H

//////////////////////////////////////////////////////////////////////
/// @file btn.h
/// @author James Anderson  CS 153 Section A
/// @brief Heder file for node class for assignment 5
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class btn
/// @brief creats a struct containing data and two pointers
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn btn<generic>::btn
/// @brief creates a new node 
/// @post node contains a variable and three pointers 
/// @param generic holds the type of variable the node will hold
////////////////////////////////////////////////////////////////////// 

template <class generic>
struct Btn
{
    Btn * parent;
    Btn * left;
    Btn * right;
    generic * data;
	int * instance;

};

#endif
