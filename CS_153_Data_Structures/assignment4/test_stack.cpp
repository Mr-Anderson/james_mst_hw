//////////////////////////////////////////////////////////////////////
/// @file test_stack.cpp
/// @author James Anderson  Section A
/// @brief Implementation  file for test_stack class for assignment 3
////////////////////////////////////////////////////////////////////// 
#include "test_stack.h"

CPPUNIT_TEST_SUITE_REGISTRATION (Test_stack);

void Test_stack::test_constructor ()
{
	Stack<int> test;

	// Constructor check
	CPPUNIT_ASSERT (test.size () == 0);
	
}

void Test_stack::test_copy ()
{
	Stack<int> test;
	
	// Fill the stack
	for ( unsigned int i = 1; i <= 1000 ; i++)
	{
		test.push(i);
	}
	
	//Copy the stack
	Stack<int> test2(test);
	
	//check that the two stacks are the same
	for ( unsigned int i = 1000; i <= 1 ; i++)
	{
		CPPUNIT_ASSERT (test.top () == test2.top () );
		test.pop () ;
		test2.pop () ;
		
	}
	
}

void Test_stack::test_assignment ()
{
	Stack<int> test;
	
	// fill the stack
	for ( unsigned int i = 1; i <= 1000 ; i++)
	{
		test.push(i);
	}
	
	Stack<int> test2;
	
	//fill the second stack with different data
	for ( unsigned int i = 1000; i <= 1 ; i--)
	{
		test2.push(i);
	}
	
	// assign stack 1 to stack 2
	test2 = test;
	
	//check that the two stacks are the same
	for ( unsigned int i = 1000; i <= 1 ; i++)
	{
		CPPUNIT_ASSERT (test.top () == test2.top () );
		test.pop () ;
		test2.pop () ;
		
	}
}


void Test_stack::test_push()
{
	Stack<int> test;
	
	//fill the stack with data and check
	for (  int i = 1  ; i <= 1000 ; i++   )
	{
		test.push(i);
		CPPUNIT_ASSERT (test.size() == i);
		CPPUNIT_ASSERT (test.top() == i);
		CPPUNIT_ASSERT (test.empty() == false);
	}
	
}

void Test_stack::test_pop ()
{
	Stack<int> test;
	
	//fill the stack with data
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
	
	//check that the stack if empty 
	CPPUNIT_ASSERT (test.size() == 0);
	CPPUNIT_ASSERT (test.empty() == 1);
	
	// try poping an empty stack and check for error code
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

void Test_stack::test_clear ()
{
	Stack<int> test;
	
	//fill stack with data 
	for ( unsigned int i = 1 ; i <= 1000 ; i++ )
	{
		test.push(i);
	}
	
	//clear the stack
	test.clear();
	
	//check to see if stack was cleared and is empty
	CPPUNIT_ASSERT (test.size() == 0);
	CPPUNIT_ASSERT (test.empty() == 1);
	
}
