#ifndef TEST_Avl_H
#define TEST_Avl_H
//////////////////////////////////////////////////////////////////////
/// @file test_avl.h
/// @author James Anderson  Section A
/// @brief Heder file for test_avl class for assignment 7
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class test_avl
/// @brief Used to test the various fetures and limits of the avl class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_avl::test_constructor ()
/// @brief function checks the functionality of the constructor in the 
/// avl class 
/// @post function will check the constructor of the avl class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_avl::test_insert
/// @brief function checks the functionality of the pushfront function in the 
/// avl class
/// @param x is the value to be inserted
/// @post function will check the insert function
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_avl::test_remove 
/// @brief function checks the functionality of the remove function in the 
/// avl class and also checks the container empty  and not found error 
/// @param x is to be removed
/// @post function will check the remove function as well as the container
/// empty and not found error
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/// @fn Test_avl::test_clear ()
/// @brief function checks the functionality of the  clear function in the 
/// avl class 
/// @post function will check the  clear function 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_avl::test_empty ()
/// @brief function checks the functionality of the empty function in the 
/// avl class 
/// @post function will check the empty function 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_avl::test_size ()
/// @brief function checks the functionality of the size  function in the 
/// avl class 
/// @post function will check the size function 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_avl::test_pre ()
/// @brief function checks the functionality of the pre order iterator 
/// @post function will check the values output by the pre order 
/// iterator
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_avl::test_in ()
/// @brief function checks the functionality of the in order iterator 
/// @post function will check the values output by the in order 
/// iterator
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_avl::test_post ()
/// @brief function checks the functionality of the post order iterator 
/// @post function will check the values output by the post order 
/// iterator
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_avl::test_copy ()
/// @brief function checks the functionality of the copy constuctor 
/// @post function will check the values of a copyed avl
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_avl::test_assignment ()
/// @brief function checks the functionality of the assignment operator 
/// @post function will check the values of a copyed avl
////////////////////////////////////////////////////////////////////// 


#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>
#include "avl.h"
#include "exception.h"
#include "math.h"
#include "cstdlib"
#include "iostream"
#include <cstdlib>
#include <ctime>

class Test_avl : public CPPUNIT_NS::TestFixture
{
  private:
    CPPUNIT_TEST_SUITE (Test_avl);
    CPPUNIT_TEST (test_constructor);
    CPPUNIT_TEST (test_insert);
    CPPUNIT_TEST (test_remove);
    CPPUNIT_TEST (test_clear);
    CPPUNIT_TEST (test_empty);
    CPPUNIT_TEST (test_size);
	CPPUNIT_TEST (test_pre);
	CPPUNIT_TEST (test_in);
	CPPUNIT_TEST (test_post);
	CPPUNIT_TEST (test_copy);
	CPPUNIT_TEST (test_assignment);
    CPPUNIT_TEST_SUITE_END ();

  protected:
  
    void test_constructor ();
	void test_insert ();
	void test_remove ();
	void test_clear ();
    void test_empty ();	
    void test_size ();
	void test_pre () ;
	void test_in () ;
	void test_post () ;
	void test_copy () ;
	void test_assignment () ;

};

#endif
