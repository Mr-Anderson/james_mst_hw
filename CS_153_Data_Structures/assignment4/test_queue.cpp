//////////////////////////////////////////////////////////////////////
/// @file test_queue.cpp
/// @author James Anderson  Section A
/// @brief Implementation  file for test_queue class for assignment 3
////////////////////////////////////////////////////////////////////// 
#include "test_queue.h"

CPPUNIT_TEST_SUITE_REGISTRATION (Test_queue);

void Test_queue::test_constructor ()
{
	Queue<int> test;
	
	// Constructor check
	CPPUNIT_ASSERT (test.size () == 0);
	
}

void Test_queue::test_copy ()
{
	Queue<int> test;
	
	// Fill the queue
	for ( unsigned int i = 1; i <= 1000 ; i++)
	{
		test.push(i);
	}
	
	//Copy the queue
	Queue<int> test2(test);
	
	//check that the two queues are the same
	for ( unsigned int i = 1000; i <= 1 ; i++)
	{
		CPPUNIT_ASSERT (test.back () == test2.back ());
		test.pop ();
		test2.pop ();
		
	}
	
	
}

void Test_queue::test_assignment ()
{
	Queue<int> test;
	
	// fill the queue
	for ( unsigned int i = 1; i <= 1000 ; i++)
	{
		test.push(i);
	}
	
	Queue<int> test2;
	
	//fill the second queue with different data
	for ( unsigned int i = 1000; i <= 1 ; i--)
	{
		test2.push(i);
	}
	
	// assign queue 1 to queue 2
	test2 = test;
	
	//check that the two queues are the same
	for ( unsigned int i = 1000; i <= 1 ; i++)
	{
		CPPUNIT_ASSERT (test.back () == test2.back () );
		test.pop ();
		test2.pop ();
		
	}
	
}


void Test_queue::test_push()
{
	Queue<int> test;
	
	//fill the queue with data and check
	for (  int i = 1  ; i <= 1000 ; i++   )
	{
		test.push(i);
		CPPUNIT_ASSERT (test.size() == i);
		CPPUNIT_ASSERT (test.front() == i);
		CPPUNIT_ASSERT (test.empty() == false);
	}
	
}

void Test_queue::test_pop ()
{
	Queue<int> test;
	
	//fill the queue with data
	for ( unsigned int i = 1 ; i <= 1000 ; i++ )
	{
		test.push(i);
	}
	
	//pop off data and check that it was poped off
	for ( unsigned int i = 1000 ; i >=1 ; i-- )
	{
		CPPUNIT_ASSERT (test.empty() == 0);
		CPPUNIT_ASSERT (test.size() == i );
		
		test.pop();
		
		CPPUNIT_ASSERT (test.size() == i - 1);
		
	}
	
	//check that the queue if empty 
	CPPUNIT_ASSERT (test.size() == 0);
	CPPUNIT_ASSERT (test.empty() == 1);
	
	// try poping an empty queue and check for error code
	try 
	{
		test.pop ();
		CPPUNIT_ASSERT (false);
	}
	catch (Exception& e)
	{
		CPPUNIT_ASSERT (CONTAINER_EMPTY == e.error_code ());
	}
	
	
}

void Test_queue::test_clear ()
{
	Queue<int> test;
	
	//fill queue with data 
	for ( unsigned int i = 1 ; i <= 1000 ; i++ )
	{
		test.push(i);
	}
	
	//clear the queue
	test.clear();
	
	//check to see if queue was cleared and is empty
	CPPUNIT_ASSERT (test.size() == 0);
	CPPUNIT_ASSERT (test.empty() == 1);
	
}
