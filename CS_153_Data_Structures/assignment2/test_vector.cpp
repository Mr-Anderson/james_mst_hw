//////////////////////////////////////////////////////////////////////
/// @file test_vector.cpp
/// @author James Anderson  Section A
/// @brief Implementation  file for test_vector class for assignment 2
////////////////////////////////////////////////////////////////////// 
#include "test_vector.h"

CPPUNIT_TEST_SUITE_REGISTRATION (Test_vector);

void Test_vector::test_constructor ()
{
	Vector<int> test;
	
	// Constructor check
	CPPUNIT_ASSERT (test.size () == 0);
	CPPUNIT_ASSERT (test.max_size () == 1);
	
}
void Test_vector::test_push_back ()
{
	Vector<int> test;
	
	// Push on one item
	test.push_back (42);
	CPPUNIT_ASSERT (test[0] == 42);
	CPPUNIT_ASSERT (test.size () == 1);
	CPPUNIT_ASSERT (test.max_size () == 1);
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
	// checking to see if vector size is adjusting corectly
	for (int i = 1 ; i <= 500 ; i++ )
	{
		test.push_back (i);
		CPPUNIT_ASSERT (test[i] == i);
		CPPUNIT_ASSERT (test.size () == i + 1);
		CPPUNIT_ASSERT (test.max_size () == pow(2,floor(log(i)/log(2) + 1)));
	}
}

void Test_vector::test_pop_back ()
{
	Vector<int> test;
	
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
	// populating the vector 
	for (int i = 0 ; i <= 500 ; i++ )
	{
		test.push_back (i);
		CPPUNIT_ASSERT (test[i] == i);
		CPPUNIT_ASSERT (test.size () == i + 1);
		
	}
	//checking pop_back
	for (int i = 500 ; i >= 0 ; i--)
	{
		test.pop_back ();
		CPPUNIT_ASSERT (test.size () == i );
		//CPPUNIT_ASSERT (test.max_size () == pow(2,floor(log((i-1)*2)/log(2) + 1)));

	}


}

void Test_vector::test_clear ()
{
	Vector<int> test;

	// populating the vector 
	for (int i = 0 ; i <= 500 ; i++ )
	{
		test.push_back (i);
		CPPUNIT_ASSERT (test[i] == i);
		CPPUNIT_ASSERT (test.size () == i + 1);
	}

	//clearing the vector 
	test.clear ();

	//testing to see if the array was cleared
	CPPUNIT_ASSERT (test.size () == 0);
	CPPUNIT_ASSERT (test.max_size () == 1);

}
