#ifndef TEST_Stack_H
#define TEST_Stack_H
//////////////////////////////////////////////////////////////////////
/// @file test_stack.h
/// @author James Anderson  Section A
/// @brief Heder file for test_stack class for assignment 3
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class test_stack
/// @brief Used to test the various fetures and limits of the stack class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_stack::test_constructor ()
/// @brief function checks the functionality of the constructor in the 
/// stack class 
/// @post function will check the constructor of the stack class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_stack::test_copy ()
/// @brief function checks the functionality of the copy constructor in the 
/// stack class 
/// @post function will check the copy constructor of the stack class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_stack::test_assignment ()
/// @brief function checks the functionality of the assigment operator in the 
/// stack class 
/// @post function will check the assignment operator of the stack class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_stack::test_push
/// @brief function checks the functionality of the push function in the 
/// stack class
/// @post function will check the push function
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_stack::test_pop
/// @brief function checks the functionality of the  pop function in the 
/// stack class and also checks the container empty error 
/// @post function will check the  pop function as well as the container
/// empty error
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_stack::test_clear ()
/// @brief function checks the functionality of the clear  function in the 
/// stack class 
/// @post function will check the clear function 
////////////////////////////////////////////////////////////////////// 


#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>
#include "stack.h"
#include "exception.h"
#include "math.h"

class Test_stack : public CPPUNIT_NS::TestFixture
{
  private:
    CPPUNIT_TEST_SUITE (Test_stack);
    CPPUNIT_TEST (test_constructor);
    CPPUNIT_TEST (test_copy);
    CPPUNIT_TEST (test_assignment);
	CPPUNIT_TEST (test_push);
    CPPUNIT_TEST (test_pop);
    CPPUNIT_TEST (test_clear);
    CPPUNIT_TEST_SUITE_END ();

  protected:
  
    void test_constructor ();
    void test_copy ();
	void test_assignment ();
	void test_push();
    void test_pop(); 
	void test_clear ();
	
};

#endif
