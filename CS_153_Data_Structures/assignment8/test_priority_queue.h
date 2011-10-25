#ifndef TEST_PRIORITY_QUEUE_H
#define TEST_PRIORITY_QUEUE_H
//////////////////////////////////////////////////////////////////////
/// @file test_priority queue.h
/// @author James Anderson  Section A
/// @brief Heder file for test_priority queue class for assignment 8
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class test_priority queue
/// @brief Used to test the various fetures and limits of the priority queue class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_priority queue::test_constructor ()
/// @brief function checks the functionality of the constructor in the 
/// priority queue class 
/// @post function will check the constructor of the priority queue class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_priority queue::test_push
/// @brief function checks the functionality of the push function in the 
/// priority queue class
/// @param x is the value to be inserted
/// @post function will check the insert function
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_priority queue::test_pop 
/// @brief function checks the functionality of the pop function in the 
/// priority queue class and also checks the container empty  and not found error 
/// @param x is to be removed
/// @post function will check the pop function as well as the container
/// empty and not found error
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/// @fn Test_priority queue::test_copy ()
/// @brief function checks the functionality of the copy constuctor 
/// @post function will check the values of a copyed priority queue
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_priority queue::test_assignment ()
/// @brief function checks the functionality of the assignment operator 
/// @post function will check the values of a copyed priority queue
////////////////////////////////////////////////////////////////////// 


#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>
#include "priority_queue.h"
#include "exception.h"
#include "math.h"
#include "cstdlib"
#include "iostream"
#include <cstdlib>
#include <ctime>

class Test_priority_queue : public CPPUNIT_NS::TestFixture
{
  private:
    CPPUNIT_TEST_SUITE (Test_priority_queue);
    CPPUNIT_TEST (test_constructor);
    CPPUNIT_TEST (test_push);
	CPPUNIT_TEST (test_pop);
	CPPUNIT_TEST (test_copy);
	CPPUNIT_TEST (test_assignment);
    CPPUNIT_TEST_SUITE_END ();
	
  protected:
  
    void test_constructor ();
	void test_push ();
	void test_pop ();
	void test_copy () ;
	void test_assignment () ;

};

#endif
