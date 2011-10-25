#ifndef TEST_ARRAY_H
#define TEST_ARRAY_H
//////////////////////////////////////////////////////////////////////
/// @file test_array.h
/// @author James Anderson  Section A
/// @brief Heder file for test_array class for assignment 1
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class test_array
/// @brief Used to test the various fetures and limits of the array class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_array::test_push_back ()
/// @brief function checks the functionality of the pushback function in the 
/// array class checks the out of bounds error as well as the container full error
/// @post function will check the push back as well as the container full and out 
/// of bounds errors
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_array::test_pop_back ()
/// @brief function checks the functionality of the popback function in the 
/// array class and also checks the container empty error 
/// @post function will check the popback function as well as the container
/// empty error
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_array::test_clear ()
/// @brief function checks the functionality of the clear function in the 
/// array class 
/// @post function will check the clear function
////////////////////////////////////////////////////////////////////// 
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>

#include "array.h"

class Test_array : public CPPUNIT_NS::TestFixture
{
  private:
    CPPUNIT_TEST_SUITE (Test_array);
    CPPUNIT_TEST (test_push_back);
    CPPUNIT_TEST (test_pop_back);
	CPPUNIT_TEST (test_clear);
    CPPUNIT_TEST_SUITE_END ();

  protected:
    void test_push_back ();
    void test_pop_back ();
	void test_clear ();
};

#endif 
