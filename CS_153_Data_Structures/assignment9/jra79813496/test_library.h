#ifndef TEST_LIVRARY_H
#define TEST_LIBRARY_H
//////////////////////////////////////////////////////////////////////
/// @file test_library.h
/// @author James Anderson  Section A
/// @brief Heder file for test_library class for assignment 9
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class test_library
/// @brief Used to test the various fetures and limits of the library class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_library::test_bubble ()
/// @brief function checks the functionality of the bubble sort
/// @post function will check the bubble sort of the library class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_library::test_insertion ()
/// @brief function checks the functionality of the insertion sort
/// @post function will check the insertion sort of the library class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_library::test_selection ()
/// @brief function checks the functionality of the selection sort
/// @post function will check the selection sort of the library class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_library::test_search ()
/// @brief function checks the functionality of the search function
/// @post function will check the search of the library class
////////////////////////////////////////////////////////////////////// 

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>
#include "vector.h"
#include "exception.h"
#include "math.h"
#include "library.h"
#include "cstdlib"
#include "iostream"
using std::cerr ;
using std::endl ;

class Test_library : public CPPUNIT_NS::TestFixture
{
  private:
    CPPUNIT_TEST_SUITE (Test_library);
    CPPUNIT_TEST (test_bubble);
    CPPUNIT_TEST (test_selection);
    CPPUNIT_TEST (test_insertion);
    CPPUNIT_TEST (test_search);
    CPPUNIT_TEST (test_binary_search);	
	
    CPPUNIT_TEST_SUITE_END ();

  protected:
    void test_bubble ();
    void test_selection ();
    void test_insertion ();
    void test_search ();
	void test_binary_search ();
};

#endif
