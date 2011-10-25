//////////////////////////////////////////////////////////////////////
/// @file test_library.cpp
/// @author James Anderson  Section A
/// @brief Implementation  file for test_library class for assignment 9
////////////////////////////////////////////////////////////////////// 
#include "test_library.h"

CPPUNIT_TEST_SUITE_REGISTRATION (Test_library);

 void test_bubble ();
    void test_selection ();
    void test_insertion ();
    void test_search ();
	void test_binary_search ();

void Test_library::test_bubble ()
{
	Vector<int> test;
	int data[15] = {10,3,6,12,14,11,9,4,5,7,8,15,1,13,2} ;
	int sorted[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15} ;

	// populating the vector 
	for (int i = 0 ; i <= 14 ; i++ )
	{
		test.push_back (data[i]);
		CPPUNIT_ASSERT (test[i] == data[i]);

	}

	//preform sort
	bubble_sort(test);
	
	//testing to see if the array was sorted
	for (int i = 0 ; i <= 14 ; i++ )
	{
		CPPUNIT_ASSERT (test[i] == sorted[i]);
	}
}

void Test_library::test_selection ()
{
	Vector<int> test;
	int data[15] = {10,3,6,12,14,11,9,4,5,7,8,15,1,13,2} ;
	int sorted[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15} ;

	// populating the vector 
	for (int i = 0 ; i <= 14 ; i++ )
	{
		test.push_back (data[i]);
		CPPUNIT_ASSERT (test[i] == data[i]);

	}

	//preform sort
	selection_sort(test);
	
	//testing to see if the array was sorted
	for (int i = 0 ; i <= 14 ; i++ )
	{
		CPPUNIT_ASSERT (test[i] == sorted[i]);
	}
}

void Test_library::test_insertion ()
{
	Vector<int> test;
	int data[15] = {10,3,6,12,14,11,9,4,5,7,8,15,1,13,2} ;
	int sorted[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15} ;

	// populating the vector 
	for (int i = 0 ; i <= 14 ; i++ )
	{
		test.push_back (data[i]);
		CPPUNIT_ASSERT (test[i] == data[i]);

	}

	//preform sort
	insertion_sort(test);
	
	//testing to see if the array was sorted
	for (int i = 0 ; i <= 14 ; i++ )
	{
		
		CPPUNIT_ASSERT (test[i] == sorted[i]);
	}
}

void Test_library::test_search ()
{
	Vector<int> test;
	int data[15] = {1,3,6,12,14,11,9,4,5,7,8,2,10,13,15} ;
	int sorted[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15} ;

	// populating the vector 
	for (int i = 0 ; i <= 14 ; i++ )
	{
		test.push_back (data[i]);
		CPPUNIT_ASSERT (test[i] == data[i]);
	}

	//preform sort
	bubble_sort(test);
	
	//testing to see if search works
	for (int i = 1 ; i <= 15 ; i++ )
	{
		CPPUNIT_ASSERT ( search(test,i)== i-1);
	}
	
	try 
	{
		search(test,42);
		CPPUNIT_ASSERT (false);
	}
	catch (Exception& e)
	{
		CPPUNIT_ASSERT (NOT_FOUND == e.error_code ());
	}
}

void Test_library::test_binary_search ()
{
	Vector<int> test;
	int data[15] = {1,3,6,12,14,11,9,4,5,7,8,2,10,13,15} ;
	int sorted[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15} ;

	// populating the vector 
	for (int i = 0 ; i <= 14 ; i++ )
	{
		test.push_back (data[i]);
		CPPUNIT_ASSERT (test[i] == data[i]);
		
	}

	//preform sort
	
	bubble_sort(test);
	
	//testing to see if binary search works

	for (int i = 1 ; i <= 15 ; i++ )
	{
		CPPUNIT_ASSERT ( binary_search(test,i)== i-1);
	}

	try 
	{
		binary_search(test,42);
		CPPUNIT_ASSERT (false);
	}
	catch (Exception& e)
	{
		CPPUNIT_ASSERT (NOT_FOUND == e.error_code ());
	}
}
