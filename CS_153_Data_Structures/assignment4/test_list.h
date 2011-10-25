#ifndef TEST_List_H
#define TEST_List_H
//////////////////////////////////////////////////////////////////////
/// @file test_list.h
/// @author James Anderson  Section A
/// @brief Heder file for test_list class for assignment 3
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class test_list
/// @brief Used to test the various fetures and limits of the list class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_constructor ()
/// @brief function checks the functionality of the constructor in the 
/// list class 
/// @post function will check the constructor of the list class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_copy ()
/// @brief function checks the functionality of the copy constructor in the 
/// list class 
/// @post function will check the copy constructor of the list class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_assignment ()
/// @brief function checks the functionality of the assigment operator in the 
/// list class 
/// @post function will check the assignment operator of the list class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_push_front ()
/// @brief function checks the functionality of the pushfront function in the 
/// list class
/// @post function will check the push front function
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_pop_front ()
/// @brief function checks the functionality of the  popfront function in the 
/// list class and also checks the container empty error 
/// @post function will check the  popfront function as well as the container
/// empty error
//////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_push_back ()
/// @brief function checks the functionality of the pushback function in the 
/// single list class
/// @post function will check the push back function
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_pop_back ()
/// @brief function checks the functionality of the  popback function in the 
/// list class and also checks the container empty error 
/// @post function will check the  popback function as well as the container
/// empty error
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_clear ()
/// @brief function checks the functionality of the clear  function in the 
/// list class 
/// @post function will check the clear function 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_list::test_remove ()
/// @brief function checks the functionality of the remove function in the 
/// list class 
/// @post function will check the remove function 
////////////////////////////////////////////////////////////////////// 

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>
#include "list.h"
#include "exception.h"
#include "math.h"

class Test_list : public CPPUNIT_NS::TestFixture
{
  private:
    CPPUNIT_TEST_SUITE (Test_list);
    CPPUNIT_TEST (test_constructor);
    CPPUNIT_TEST (test_copy);
    CPPUNIT_TEST (test_assignment);
    CPPUNIT_TEST (test_push_front);
    CPPUNIT_TEST (test_pop_front);
	CPPUNIT_TEST (test_push_back);
    CPPUNIT_TEST (test_pop_back);
    CPPUNIT_TEST (test_clear);
    CPPUNIT_TEST (test_remove);
    CPPUNIT_TEST_SUITE_END ();

  protected:
  
    void test_constructor ();
    void test_copy ();
	void test_assignment ();
	void test_push_front ();
    void test_pop_front (); 
	void test_push_back ();
    void test_pop_back ();
    void test_remove ();
	void test_clear ();
	
};

#endif
