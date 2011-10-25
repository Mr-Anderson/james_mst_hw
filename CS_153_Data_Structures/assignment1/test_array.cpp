//////////////////////////////////////////////////////////////////////
/// @file test_array.cpp
/// @author James Anderson  Section A
/// @brief Implementation  file for test_array class for assignment 1
////////////////////////////////////////////////////////////////////// 
#include "test_array.h"

CPPUNIT_TEST_SUITE_REGISTRATION (Test_array);

void Test_array::test_push_back ()
{
	Array<int> test;
	
	// Constructor check
	CPPUNIT_ASSERT (test.size () == 0);
	CPPUNIT_ASSERT (test.max_size () == 20);
	// Push on one item
	test.push_back (3);
	
	// check that item
	CPPUNIT_ASSERT (test[0] == 3);
	CPPUNIT_ASSERT (test.size () == 1);
	CPPUNIT_ASSERT (test.max_size () == 20);
	
	// checking to see if data out of bounds is handeled
	try 
	{
		test[2] = 50;
		CPPUNIT_ASSERT (false);
	}
	catch (Exception& e)
	{
		CPPUNIT_ASSERT (OUT_OF_BOUNDS == e.error_code ());
	}
	try 
	{
		test[-70] = 50;
		CPPUNIT_ASSERT (false);
	}
	catch (Exception& e)
	{
		CPPUNIT_ASSERT (OUT_OF_BOUNDS == e.error_code ());
	}
	
	// checking to see if container full is handeled
	try 
	{
		for (int i = 1 ; i <= 21 ; i++ )
		{
			test.push_back (i);
			CPPUNIT_ASSERT (test[i] == i);
			CPPUNIT_ASSERT (test.size () == i + 1);
			CPPUNIT_ASSERT (test.max_size () == 20);
		}
		CPPUNIT_ASSERT (false);
	}
	catch (Exception& e)
	{
		CPPUNIT_ASSERT (CONTAINER_FULL == e.error_code ());
	}
	
}

void Test_array::test_pop_back ()
{
	Array<int> test;
	

	// Constructor check
	CPPUNIT_ASSERT (test.size () == 0);
	CPPUNIT_ASSERT (test.max_size () == 20);
	
	// push on 20 items
	for (int i = 0 ; i <= 19 ; i++ )
		{
			test.push_back (i);
			CPPUNIT_ASSERT (test[i] == i);
			CPPUNIT_ASSERT (test.size () == i +1);
			CPPUNIT_ASSERT (test.max_size () == 20);
		}
		
	//pop back 20 items
	for (int i = 20 ; i >= 1 ; i-- )
		{
			test.pop_back ();
			CPPUNIT_ASSERT (test.size () == i - 1 );
			CPPUNIT_ASSERT (test.max_size () == 20);
		}
	
	// checking to see if container empty is handeled
	try 
	{
		test.pop_back ();
		CPPUNIT_ASSERT (false);
	}
	catch (Exception& e)
	{
		CPPUNIT_ASSERT (CONTAINER_EMPTY == e.error_code ());
	}
}

void Test_array::test_clear ()
{
	Array<int> test;
	

	// Constructor check
	CPPUNIT_ASSERT (test.size () == 0);
	CPPUNIT_ASSERT (test.max_size () == 20);
	
	// pusth on 20 items
	for (int i = 0 ; i <= 19 ; i++ )
		{
			test.push_back (i);
			CPPUNIT_ASSERT (test[i] == i);
			CPPUNIT_ASSERT (test.size () == i + 1);
			CPPUNIT_ASSERT (test.max_size () == 20);
		}
	
	// clear the array 
	test.clear ();
	
	//check that the array was cleared 
	CPPUNIT_ASSERT (test.size () == 0);
	CPPUNIT_ASSERT (test.max_size () == 20);
	
	
}
