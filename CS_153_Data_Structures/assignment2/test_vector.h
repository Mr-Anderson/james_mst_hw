#ifndef TEST_VECTOR_H
#define TEST_VECTOR_H
//////////////////////////////////////////////////////////////////////
/// @file test_vector.h
/// @author James Anderson  Section A
/// @brief Heder file for test_vector class for assignment 1
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class test_vector
/// @brief Used to test the various fetures and limits of the vector class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_vector::test_constructor ()
/// @brief function checks the functionality of the constructor in the 
/// vector class 
/// @post function will check the constructor of the vector class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_vector::test_push_back ()
/// @brief function checks the functionality of the pushback function in the 
/// array class checks the out of bounds error as well as the container full error
/// @post function will check the push back as well as the container full and out 
/// of bounds errors
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_vector::test_pop_back ()
/// @brief function checks the functionality of the  popback function in the 
/// array class and also checks the container empty error 
/// @post function will check the  popback function as well as the container
/// empty error
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Test_vector::test_clear ()
/// @brief function checks the functionality of the clear  function in the 
/// vector class 
/// @post function will check the clear function 
////////////////////////////////////////////////////////////////////// 


#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>
#include "vector.h"
#include "exception.h"
#include "math.h"

class Test_vector : public CPPUNIT_NS::TestFixture
{
  private:
    CPPUNIT_TEST_SUITE (Test_vector);
    CPPUNIT_TEST (test_constructor);
    CPPUNIT_TEST (test_push_back);
    CPPUNIT_TEST (test_pop_back);
    CPPUNIT_TEST (test_clear);
    CPPUNIT_TEST_SUITE_END ();

  protected:
    void test_push_back ();
    void test_pop_back ();
    void test_constructor ();
    void test_clear ();
};

#endif
