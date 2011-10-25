#ifndef TEST_SLIST_H
#define TEST_SLIST_H
//////////////////////////////////////////////////////////////////////
/// @file test_slist.h
/// @author James Anderson  Section A
/// @brief Heder file for test_slist class for assignment 3
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class test_slist
/// @brief Used to test the various fetures and limits of the slist class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_slist::test_constructor ()
/// @brief function checks the functionality of the constructor in the 
/// slist class 
/// @post function will check the constructor of the slist class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_slist::test_copy ()
/// @brief function checks the functionality of the copy constructor in the 
/// slist class 
/// @post function will check the copy constructor of the slist class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_slist::test_assignment ()
/// @brief function checks the functionality of the assigment operator in the 
/// slist class 
/// @post function will check the assignment operator of the slist class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_slist::test_push_front ()
/// @brief function checks the functionality of the pushfront function in the 
/// single list class
/// @post function will check the push front function
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_slist::test_pop_front ()
/// @brief function checks the functionality of the  popfront function in the 
/// slist class and also checks the container empty error 
/// @post function will check the  popfront function as well as the container
/// empty error
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_slist::test_clear ()
/// @brief function checks the functionality of the clear  function in the 
/// slist class 
/// @post function will check the clear function 
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_slist::test_remove ()
/// @brief function checks the functionality of the remove function in the 
/// slist class 
/// @post function will check the remove function 
////////////////////////////////////////////////////////////////////// 

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>
#include "slist.h"
#include "exception.h"
#include "math.h"

class Test_slist : public CPPUNIT_NS::TestFixture
{
  private:
    CPPUNIT_TEST_SUITE (Test_slist);
    CPPUNIT_TEST (test_constructor);
    CPPUNIT_TEST (test_copy);
    CPPUNIT_TEST (test_assignment);
    CPPUNIT_TEST (test_push_front);
    CPPUNIT_TEST (test_pop_front);
    CPPUNIT_TEST (test_clear);
    CPPUNIT_TEST (test_remove);
    CPPUNIT_TEST_SUITE_END ();

  protected:
  
    void test_constructor ();
    void test_push_front ();
    void test_copy ();
    void test_assignment ();
    void test_pop_front (); 
    void test_clear ();
    void test_remove ();
    
};

#endif
