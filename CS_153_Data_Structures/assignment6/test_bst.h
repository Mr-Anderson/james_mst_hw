#ifndef TEST_Bst_H
#define TEST_Bst_H
//////////////////////////////////////////////////////////////////////
/// @file test_bst.h
/// @author James Anderson  Section A
/// @brief Heder file for test_bst class for assignment 6
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class test_bst
/// @brief Used to test the various fetures and limits of the bst class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_bst::test_constructor ()
/// @brief function checks the functionality of the constructor in the 
/// bst class 
/// @post function will check the constructor of the bst class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_bst::test_insert
/// @brief function checks the functionality of the pushfront function in the 
/// bst class
/// @param x is the value to be inserted
/// @post function will check the insert function
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_bst::test_remove 
/// @brief function checks the functionality of the remove function in the 
/// bst class and also checks the container empty  and not found error 
/// @param x is to be removed
/// @post function will check the remove function as well as the container
/// empty and not found error
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/// @fn Test_bst::test_clear ()
/// @brief function checks the functionality of the  clear function in the 
/// bst class 
/// @post function will check the  clear function 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_bst::test_empty ()
/// @brief function checks the functionality of the empty function in the 
/// bst class 
/// @post function will check the empty function 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_bst::test_size ()
/// @brief function checks the functionality of the size  function in the 
/// bst class 
/// @post function will check the size function 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_bst::test_pre ()
/// @brief function checks the functionality of the pre order iterator 
/// @post function will check the values output by the pre order 
/// iterator
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_bst::test_in ()
/// @brief function checks the functionality of the in order iterator 
/// @post function will check the values output by the in order 
/// iterator
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_bst::test_post ()
/// @brief function checks the functionality of the post order iterator 
/// @post function will check the values output by the post order 
/// iterator
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_bst::test_copy ()
/// @brief function checks the functionality of the copy constuctor 
/// @post function will check the values of a copyed bst
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_bst::test_assignment ()
/// @brief function checks the functionality of the assignment operator 
/// @post function will check the values of a copyed bst
////////////////////////////////////////////////////////////////////// 


#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>
#include "bst.h"
#include "exception.h"
#include "math.h"
#include "cstdlib"
#include "iostream"
#include <cstdlib>
#include <ctime>

class Test_bst : public CPPUNIT_NS::TestFixture
{
  private:
    CPPUNIT_TEST_SUITE (Test_bst);
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
