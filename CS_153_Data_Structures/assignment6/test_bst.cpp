//////////////////////////////////////////////////////////////////////
/// @file test_bst.cpp
/// @author James Anderson  Section A
/// @brief Implementation  file for test_bst class for assignment 6
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
	Bst<int>::InOrder k;
	int fixed[15] = {16,8,24,4,12,20,28,2,6,10,14,18,22,26,30} ;
	int in[15] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30} ;
	// Fill the bst
	for (  int i = 0 ; i < 15 ; i++ )
	{
		test.insert(fixed[i]);
		CPPUNIT_ASSERT (test.size () == i+1 );
	}
	int j = 0 ;
	//check the fill
	for ( k = test.in_begin() ; k != test.in_end() ; k++  )
	{
		CPPUNIT_ASSERT (in[j] == *k);
		j++ ;
	}
	
}

void Test_bst::test_remove ()
{
	Bst<int> test;
	Bst<int>::InOrder k;
	int fixed[15] = {16,8,24,4,12,20,28,2,6,10,14,18,22,26,30} ;
	
	//try removing when empty 
	try 
	{
		test.remove(226) ;
		CPPUNIT_ASSERT (false);
	}
	catch (Exception& e)
	{
		CPPUNIT_ASSERT (CONTAINER_EMPTY == e.error_code ());
	}
	
	
	// Fill the bst
	for (  int i = 0 ; i < 15 ; i++ )
	{
		test.insert(fixed[i]);
		CPPUNIT_ASSERT (test.size () == i+1 );
	}
	
	//test removing a value that dosent exist
	try 
	{
		test.remove(226) ;
		CPPUNIT_ASSERT (false);
	}
	catch (Exception& e)
	{
		CPPUNIT_ASSERT (NOT_FOUND == e.error_code ());
	}
	
	
	//test removing values
	test.remove (16) ;
	for ( k = test.in_begin() ; k != test.in_end() ; k++  )
	{
		CPPUNIT_ASSERT (16 != *k);
	}
	
	
	//linked
	test.remove (24) ;
	for ( k = test.in_begin() ; k != test.in_end() ; k++  )
	{
		CPPUNIT_ASSERT (24 != *k);
	}
	
	
	//leafe
	test.remove (2) ;
	for ( k = test.in_begin() ; k != test.in_end() ; k++  )
	{
		CPPUNIT_ASSERT (2 != *k);
	}
	
}

void Test_bst::test_clear ()
{
	Bst<int> test;
	Bst<int>::InOrder k;
	int fixed[15] = {16,8,24,4,12,20,28,2,6,10,14,18,22,26,30} ;
	// Fill the bst
	for (  int i = 0 ; i < 15 ; i++ )
	{
		test.insert(fixed[i]);
		CPPUNIT_ASSERT (test.size () == i+1 );
	}
	
	//clear and test
	test.clear() ;
	CPPUNIT_ASSERT (test.size () == 0 );
	CPPUNIT_ASSERT (test.empty () == 1 );

}

void Test_bst::test_empty ()
{
	Bst<int> test;
	Bst<int>::InOrder k;
	int fixed[15] = {16,8,24,4,12,20,28,2,6,10,14,18,22,26,30} ;
	// Fill the bst
	for (  int i = 0 ; i < 15 ; i++ )
	{
		test.insert(fixed[i]);
		CPPUNIT_ASSERT (test.size () == i+1 );
	}
	
	//pretest empty
	CPPUNIT_ASSERT (test.empty () == 0 );

	//clear and test
	test.clear() ;
	CPPUNIT_ASSERT (test.size () == 0 );
	CPPUNIT_ASSERT (test.empty () == 1 );
}

void Test_bst::test_size()
{
	Bst<int> test;
	Bst<int>::InOrder k;
	int fixed[15] = {16,8,24,4,12,20,28,2,6,10,14,18,22,26,30} ;
	// Fill the bst
	for (  int i = 0 ; i < 15 ; i++ )
	{
		test.insert(fixed[i]);
		CPPUNIT_ASSERT (test.size () == i+1 );
	}
	
	//pretest size
	CPPUNIT_ASSERT (test.size () == 15 );

	//clear and test
	test.clear() ;
	CPPUNIT_ASSERT (test.size () == 0 );
	CPPUNIT_ASSERT (test.empty () == 1 );
	
}

void Test_bst::test_pre ()
{
	Bst<int> test;
	Bst<int>::PreOrder k;
	int fixed[15] = {16,8,24,4,12,20,28,2,6,10,14,18,22,26,30} ;
	int pre[15] = {16,8,4,2,6,12,10,14,24,20,18,22,28,26,30} ;
	// Fill the bst
	for (  int i = 0 ; i < 15 ; i++ )
	{
		test.insert(fixed[i]);
		CPPUNIT_ASSERT (test.size () == i+1 );
	}
	int j = 0 ;
	//check the fill
	for ( k = test.pre_begin() ; k != test.pre_end() ; k++  )
	{
		CPPUNIT_ASSERT (pre[j] == *k);
		j++ ;
	}	
}
void Test_bst::test_in ()
{
	Bst<int> test;
	Bst<int>::InOrder k;
	int fixed[15] = {16,8,24,4,12,20,28,2,6,10,14,18,22,26,30} ;
	int in[15] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30} ;
	// Fill the bst
	for (  int i = 0 ; i < 15 ; i++ )
	{
		test.insert(fixed[i]);
		CPPUNIT_ASSERT (test.size () == i+1 );
	}
	int j = 0 ;
	//check the fill
	for ( k = test.in_begin() ; k != test.in_end() ; k++  )
	{
		CPPUNIT_ASSERT (in[j] == *k);
		j++ ;
	}
}
void Test_bst::test_post ()
{
	Bst<int> test;
	Bst<int>::PostOrder k;
	int fixed[15] = {16,8,24,4,12,20,28,2,6,10,14,18,22,26,30} ;
	int post[15] = {2,6,4,10,14,12,8,18,22,20,26,30,28,24,16} ;
	// Fill the bst
	for (  int i = 0 ; i < 15 ; i++ )
	{
		test.insert(fixed[i]);
		CPPUNIT_ASSERT (test.size () == i+1 );
	}
	int j = 0 ;
	//check the fill
	for ( k = test.post_begin() ; k != test.post_end() ; k++  )
	{
		CPPUNIT_ASSERT (post[j] == *k);
		j++ ;
	}
}
void Test_bst::test_copy () 
{
	Bst<int> test;
	Bst<int>::InOrder k;
	Bst<int>::InOrder j;
	int fixed[15] = {16,8,24,4,12,20,28,2,6,10,14,18,22,26,30} ;

	// Fill the bst
	for (  int i = 0 ; i < 15 ; i++ )
	{
		test.insert(fixed[i]);
		CPPUNIT_ASSERT (test.size () == i+1 );
	}

	//preform copy constructor 
	Bst<int> test2(test);
	
	//check that the two are the same
	j = test2.in_begin() ;
	for ( k = test.in_begin() ; k != test.in_end() ; k++  )
	{
		CPPUNIT_ASSERT (*j == *k);
		j++ ;
	}
	CPPUNIT_ASSERT (*j == *k);
	
}
void Test_bst::test_assignment () 
{
	Bst<int> test1;
	Bst<int> test2;
	Bst<int>::InOrder k;
	Bst<int>::InOrder j;
	int fixed[15] = {16,8,24,4,12,20,28,2,6,10,14,18,22,26,30} ;
	int junk[15] = {45,25,21,48,16,79,1,3,2,4,7,6,8,18,26} ;
	
	// Fill both the bsts
	for (  int i = 0 ; i < 15 ; i++ )
	{
		test1.insert(fixed[i]);
		test2.insert(junk[i]);
		CPPUNIT_ASSERT (test1.size () == i+1 );
		CPPUNIT_ASSERT (test2.size () == i+1 );

	}
	
	//preform assignment
	test2 = test1 ;
	
	//check that the two are the same
	j = test2.in_begin() ;
	for ( k = test1.in_begin() ; k != test1.in_end() ; k++  )
	{
		CPPUNIT_ASSERT (*j == *k);
		j++ ;
	}
	CPPUNIT_ASSERT (*j == *k);
		

	
}
