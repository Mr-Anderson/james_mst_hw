//////////////////////////////////////////////////////////////////////
/// @file test_priority_queue.cpp
/// @author James Anderson  Section A
/// @brief Implementation  file for test_priority_queue class for assignment 8
////////////////////////////////////////////////////////////////////// 
#include "test_priority_queue.h"

CPPUNIT_TEST_SUITE_REGISTRATION (Test_priority_queue);

void Test_priority_queue::test_constructor ()
{
	Priority_queue<int> test;
	
	// Constructor check
	CPPUNIT_ASSERT (test.size () == 0);
	
}

void Test_priority_queue::test_push ()
{
	Priority_queue<int> test;
	
	int fixed[15] = {17,10,14,8,7,12,3,20,18,6,22,35,19,2,1} ;

	// Fill the priority_queue
	for (  int i = 0 ; i < 15 ; i++ )
	{
		test.push(fixed[i]);
		CPPUNIT_ASSERT (test.size () == i+1 );
	}
	
	
}

void Test_priority_queue::test_pop ()
{
	Priority_queue<int> test;
	
	int fixed[15] = {17,10,14,8,7,12,3,20,18,6,22,35,19,2,1} ;
	int pop[15] = {35,22,3,14,12,7,6,10,8,2,19,18,17,20,1} ;
	
	// Fill the priority_queue
	for (  int i = 0 ; i < 15 ; i++ )
	{
		test.push(fixed[i]);
		CPPUNIT_ASSERT (test.size () == i+1 );
	}
	
	//check the fill an pop function
	for (  int i = 0 ; i < 15 ; i++ )
	{
		CPPUNIT_ASSERT (pop[i] == test.top() );
		test.pop();
	}
	
	//check that exception is thrown
	try 
	{
		test.pop();
		CPPUNIT_ASSERT (false);
	}
	catch (Exception& e)
	{
		CPPUNIT_ASSERT (CONTAINER_EMPTY == e.error_code ());
	}
	
		//check that exception is thrown
	try 
	{
		int temp = test.top();
		CPPUNIT_ASSERT (false);
	}
	catch (Exception& e)
	{
		CPPUNIT_ASSERT (CONTAINER_EMPTY == e.error_code ());
	}
	
}


void Test_priority_queue::test_copy () 
{
	Priority_queue<int> test;
	
	int fixed[15] = {17,10,14,8,7,12,3,20,18,6,22,35,19,2,1} ;
	int pop[15] = {35,22,3,14,12,7,6,10,8,2,19,18,17,20,1} ;
	
	// Fill the priority_queue
	for (  int i = 0 ; i < 15 ; i++ )
	{
		test.push(fixed[i]);
		CPPUNIT_ASSERT (test.size () == i+1 );
	}
	
	//preform copy constructor 
	Priority_queue<int> test2(test);
	
	//check that the two are the same
	for (  int i = 0 ; i < 15 ; i++ )
	{
		CPPUNIT_ASSERT (test2.top() == test.top() );
		test.pop();
		test2.pop ();
	}
	
}

void Test_priority_queue::test_assignment () 
{
	Priority_queue<int> test;
	Priority_queue<int> test2;
	
	int fixed[15] = {17,10,14,8,7,12,3,20,18,6,22,35,19,2,1} ;
	int pop[15] = {35,22,3,14,12,7,6,10,8,2,19,18,17,20,1} ;
	
	// Fill the priority_queues
	for (  int i = 0 ; i < 15 ; i++ )
	{
		test.push(fixed[i]);
		test2.push(pop[i]);
		CPPUNIT_ASSERT (test.size () == i+1 );
	}
	
	//preform copy asignment
	test2 = test ;
	
	//check that the two are the same
	for (  int i = 0 ; i < 15 ; i++ )
	{
		CPPUNIT_ASSERT (test2.top() == test.top() );
		test.pop();
		test2.pop ();
	}
	
}

