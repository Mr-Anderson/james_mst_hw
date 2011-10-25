//////////////////////////////////////////////////////////////////////
/// @file test_bst.cpp
/// @author James Anderson  Section A
/// @brief Implementation  file for test_bst class for assignment 5
////////////////////////////////////////////////////////////////////// 
#include "test_bst.h"

CPPUNIT_TEST_SUITE_REGISTRATION (Test_bst);

void Test_bst::test_constructor ()
{
	Bst<int> test;
	
	// Constructor check
	CPPUNIT_ASSERT (test.size () == 0);
	
}

void Test_bst::test_insert ()
{
	Bst<int> test;
	int fixed[15] = {16,8,24,4,12,20,28,2,6,10,14,18,22,26,30} ;
	
	// Fill the bst
	for (  int i = 0 ; i < 15 ; i++ )
	{
		test.insert(fixed[i]);
		CPPUNIT_ASSERT (test.size () == i+1 );
		CPPUNIT_ASSERT (test.search(fixed[i]) == fixed[i] );
	}

	
}

void Test_bst::test_remove ()
{
	Bst<int> test;
	int temp ;
	
	// Fill the bst
	for ( unsigned int i = 1 ; i <= 1000 ; i++ )
	{
		temp = i;
		test.insert(temp);
		CPPUNIT_ASSERT (test.size () == i);
		CPPUNIT_ASSERT (test.search(temp) == temp );
		
	}
	// Remove items then check for them
	for ( unsigned int i = 1 ; i <= 1000 ; i++ )
	{
		test.remove(i);
		//CPPUNIT_ASSERT (test.search(i) == NULL);
	}
	
}


void Test_bst::test_search ()
{
	Bst<int> test;
	int temp ;
	
	// add items then search for them
	for ( unsigned int i = 1 ; i <= 1000 ; i++ )
	{
		test.insert(i);
		CPPUNIT_ASSERT ( test.search(i) == i);
	}
	
}

void Test_bst::test_clear ()
{
	Bst<int> test;
	int temp ;
	
	// Fill the bst
	for ( unsigned int i = 1 ; i <= 1000 ; i++ )
	{
		temp = i;
		test.insert(temp);
		CPPUNIT_ASSERT (test.size () == i);
		CPPUNIT_ASSERT (test.search(temp) == temp );
		
	}
	
	//clear the bst
	test.clear();
	
	CPPUNIT_ASSERT (test.empty() == true);
}

void Test_bst::test_empty ()
{
	Bst<int> test;
	int temp ;
	
	//test that the bst is empy
	CPPUNIT_ASSERT (test.empty() == true);	
	CPPUNIT_ASSERT (test.size() == 0);	
	
	// Fill the bst
	for ( unsigned int i = 1 ; i <= 1000 ; i++ )
	{
		temp = i;
		test.insert(temp);
		CPPUNIT_ASSERT (test.size () == i);
		CPPUNIT_ASSERT (test.search(temp) == temp );
		
	}
	
	//test that the bst is full
	CPPUNIT_ASSERT (test.empty() == false);	
	CPPUNIT_ASSERT (test.size() != 0);	
	
	//clear the bst
	test.clear();
	
	//test that its empty
	CPPUNIT_ASSERT (test.empty() == true);	
	CPPUNIT_ASSERT (test.size() == 0);	
}

void Test_bst::test_size()
{
	Bst<int> test;
	int temp ;
	
	//test that the bst is empy
	CPPUNIT_ASSERT (test.empty() == true);	
	CPPUNIT_ASSERT (test.size() == 0);	
	
	// Fill the bst
	for ( unsigned int i = 1 ; i <= 1000 ; i++ )
	{
		temp = i;
		test.insert(temp);
		CPPUNIT_ASSERT (test.size () == i);
		CPPUNIT_ASSERT (test.search(temp) == temp );
		
	}
	
	//test that the bst is full
	CPPUNIT_ASSERT (test.empty() == false);	
	CPPUNIT_ASSERT (test.size() != 0);	
	
	//clear the bst
	test.clear();
	
	//test that its empty
	CPPUNIT_ASSERT (test.empty() == true);	
	CPPUNIT_ASSERT (test.size() == 0);	
	
}
