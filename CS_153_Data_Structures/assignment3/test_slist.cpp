//////////////////////////////////////////////////////////////////////
/// @file test_slist.cpp
/// @author James Anderson  Section A
/// @brief Implementation  file for test_slist class for assignment 3
////////////////////////////////////////////////////////////////////// 
#include "test_slist.h"

CPPUNIT_TEST_SUITE_REGISTRATION (Test_slist);

void Test_slist::test_constructor ()
{
	SList<int> test;
	SList<int>::Iterator i;
	i = test.begin();
	
	// Constructor check
	CPPUNIT_ASSERT (test.size () == 0);
	
}

void Test_slist::test_copy ()
{
	SList<int> test;
	
	for ( unsigned int i = 1; i <= 1000 ; i++)
	{
		test.push_front(i);
	}
	
	SList<int> test2(test);
	
	SList<int>::Iterator a;
	SList<int>::Iterator b;
	
	for ( a = test.begin() , b = test2.begin() ; a != test.end() ; a++ , b++ )
	{
		CPPUNIT_ASSERT (*a == *b);
	} 
	
}

void Test_slist::test_assignment ()
{
	SList<int> test;
	
	for ( unsigned int i = 1; i <= 1000 ; i++)
	{
		test.push_front(i);
	}
	
	SList<int> test2;
	
	for ( unsigned int i = 1000; i <= 1 ; i--)
	{
		test2.push_front(i);
	}
	
	test2 = test;
	
	SList<int>::Iterator a;
	SList<int>::Iterator b;
	
	for ( a = test.begin() , b = test2.begin() ; a != test.end() ; a++ , b++ )
	{
		CPPUNIT_ASSERT (*a == *b);
	} 
	
}


void Test_slist::test_push_front ()
{

	SList<int> test;
	SList<int>::Iterator k;
	
	for (  int i = 1  ; i <= 1000 ; i++   )
	{
		
		test.push_front(5);
		CPPUNIT_ASSERT (test.size() == i);
		
	}
	
	
	
	for ( k = test.begin() ; k != test.end() ; k++ )
	{
		
		CPPUNIT_ASSERT (5 == *k);
		
		
	}
}

void Test_slist::test_remove ()
{

	SList<int> test;
	SList<int>::Iterator k;
	
	 int j = 1;
	
	for (  int i = 1  ; i <= 1000 ; i++   )
	{
		
		test.push_front(j);
		CPPUNIT_ASSERT (test.size() == i);
		
		j++;
		if (j > 5)
		{
			j = 1;
		}
	}
	
	test.remove(3);
	
	for ( k = test.begin() ; k != test.end() ; k++ )
	{
		
		CPPUNIT_ASSERT (3 != *k);
		
	}
	
	
	
	
}

void Test_slist::test_pop_front ()
{
	
	SList<int> test;
	
	
	for ( unsigned int i = 1 ; i <= 1000 ; i++ )
	{
		test.push_front(i);
	}
	
	for ( unsigned int i = 1000 ; i >=1 ; i-- )
	{
		CPPUNIT_ASSERT (test.empty() == 0);
		CPPUNIT_ASSERT (test.size() == i );
		
		test.pop_front();
		
		CPPUNIT_ASSERT (test.size() == i - 1);
		
	}
	
	CPPUNIT_ASSERT (test.size() == 0);
	CPPUNIT_ASSERT (test.empty() == 1);
	
	try 
	{
		test.pop_front ();
		CPPUNIT_ASSERT (false);
	}
	catch (Exception& e)
	{
		CPPUNIT_ASSERT (CONTAINER_EMPTY == e.error_code ());
	}
	
	
}

void Test_slist::test_clear ()
{
	SList<int> test;
	
	
	for ( unsigned int i = 1 ; i <= 1000 ; i++ )
	{
		test.push_front(i);
	}
	
	test.clear();
	
	CPPUNIT_ASSERT (test.size() == 0);
	CPPUNIT_ASSERT (test.empty() == 1);
	
}
