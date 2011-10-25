//////////////////////////////////////////////////////////////////////
/// @file test_list.cpp
/// @author James Anderson  Section A
/// @brief Implementation  file for test_list class for assignment 3
////////////////////////////////////////////////////////////////////// 
#include "test_list.h"

CPPUNIT_TEST_SUITE_REGISTRATION (Test_list);

void Test_list::test_constructor ()
{
	List<int> test;
	
	// Constructor check
	CPPUNIT_ASSERT (test.size () == 0);
	
}

void Test_list::test_copy ()
{
	List<int> test;
	
	// Fill the list
	for ( unsigned int i = 1; i <= 1000 ; i++)
	{
		test.push_front(i);
	}
	
	//Copy the list
	List<int> test2(test);
	
	//Create Iterators for both lists
	List<int>::Iterator a;
	List<int>::Iterator b;
	
	//Check that the list was copyed corectly
	for ( a = test.begin() , b = test2.begin() ; a != test.end() ; a++ , b++ )
	{
		CPPUNIT_ASSERT (*a == *b);
	} 
	
}

void Test_list::test_assignment ()
{
	List<int> test;
	
	// fill the list
	for ( unsigned int i = 1; i <= 1000 ; i++)
	{
		test.push_front(i);
	}
	
	List<int> test2;
	
	//fill the second list with different data
	for ( unsigned int i = 1000; i <= 1 ; i--)
	{
		test2.push_front(i);
	}
	
	// assign list 1 to list 2
	test2 = test;
	
	// create iterators for both lists
	List<int>::Iterator a;
	List<int>::Iterator b;
	
	//check the assignment
	for ( a = test.begin() , b = test2.begin() ; a != test.end() ; a++ , b++ )
	{
		CPPUNIT_ASSERT (*a == *b);
	} 
	
}


void Test_list::test_push_front ()
{
	List<int> test;
	List<int>::Iterator k;
	
	//fill the list with data
	for (  int i = 1  ; i <= 1000 ; i++   )
	{
		
		test.push_front(5);
		CPPUNIT_ASSERT (test.size() == i);
		
	}
	
	//check that the list was filled 
	for ( k = test.begin() ; k != test.end() ; k++ )
	{
		
		CPPUNIT_ASSERT (5 == *k);
		
		
	}
	
	
}

void Test_list::test_pop_front ()
{
	List<int> test;
	
	//fill the list with data
	for ( unsigned int i = 1 ; i <= 1000 ; i++ )
	{
		test.push_front(i);
	}
	
	//pop off data and check that it was poped off
	for ( unsigned int i = 1000 ; i >=1 ; i-- )
	{
		CPPUNIT_ASSERT (test.empty() == 0);
		CPPUNIT_ASSERT (test.size() == i );
		
		test.pop_front();
		
		CPPUNIT_ASSERT (test.size() == i - 1);
		
	}
	
	//check that the list if empty 
	CPPUNIT_ASSERT (test.size() == 0);
	CPPUNIT_ASSERT (test.empty() == 1);
	
	// try poping an empty list and check for error code
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

void Test_list::test_push_back ()
{
	List<int> test;
	List<int>::Iterator k;
	
	//fill the list with data
	for (  int i = 1  ; i <= 1000 ; i++   )
	{
		
		test.push_back(5);
		CPPUNIT_ASSERT (test.size() == i);
		
	}
	
	//check that the list was filled 
	for ( k = test.begin() ; k != test.end() ; k++ )
	{
		
		CPPUNIT_ASSERT (5 == *k);
		
		
	}
	
	
}

void Test_list::test_pop_back ()
{
	List<int> test;
	
	//fill the list with data
	for ( unsigned int i = 1 ; i <= 1000 ; i++ )
	{
		test.push_back(i);
	}
	
	//pop off data and check that it was poped off
	for ( unsigned int i = 1000 ; i >= 1 ; i-- )
	{
		
		CPPUNIT_ASSERT (test.size() == i );
		CPPUNIT_ASSERT (test.empty() == 0);
		
		test.pop_back();
		
		
		CPPUNIT_ASSERT (test.size() == i - 1);
		
	}
	
	//check that the list is empty 
	CPPUNIT_ASSERT (test.size() == 0);
	CPPUNIT_ASSERT (test.empty() == 1);
	
	// try poping an empty list and check for error code
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

void Test_list::test_remove ()
{
	List<int> test;
	List<int>::Iterator k;
	
	//create int to iterate
	int j = 3;
	
	//fill the list with data 1-5 with 3 in the begining and end.
	for (  int i = 1  ; i <= 1003 ; i++   )
	{
		
		test.push_front(j);
		CPPUNIT_ASSERT (test.size() == i);
		
		j++;
		if (j > 5)
		{
			j = 1;
		}
	}
	
	//remove 3 
	test.remove(3);
	
	//check to see that all 3s where removed
	for ( k = test.begin() ; k != test.end() ; k++ )
	{
		
		CPPUNIT_ASSERT (*k != 3);
		
	}
	
}



void Test_list::test_clear ()
{
	List<int> test;
	
	//fill list with data 
	for ( unsigned int i = 1 ; i <= 1000 ; i++ )
	{
		test.push_front(i);
	}
	
	//clear the list
	test.clear();
	
	//check to see if list was cleared and is empty
	CPPUNIT_ASSERT (test.size() == 0);
	CPPUNIT_ASSERT (test.empty() == 1);
	
}
