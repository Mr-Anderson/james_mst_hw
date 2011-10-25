//////////////////////////////////////////////////////////////////////
/// @file bst.hpp
/// @author James Anderson  CS 153 Section A
/// @brief  Template implemintation file for
/// the bst class for assignment 7
//////////////////////////////////////////////////////////////////////


template <class generic>
BTPreorderIterator<generic> Bst<generic>::pre_search (generic x) 
{
	return PreOrder (p_search(x));
}

template <class generic>
BTInorderIterator<generic> Bst<generic>::in_search (generic x) 
{
	return InOrder (p_search(x));
}

template <class generic>
BTPostorderIterator<generic> Bst<generic>::post_search (generic x) 
{
	return PostOrder (p_search(x));
}

template <class generic>
void Bst<generic>::swap (Btn<generic> * temp1, Btn<generic> * temp2)
{
	generic * temp3 = NULL;
			
			
	temp3 = temp1->data;
	temp1->data = temp2->data;
	temp2->data = temp3;
	
	temp3 = NULL;
	
	int * temp4 = NULL;
			
			
	temp4 = temp1->instance;
	temp1->instance = temp2->instance;
	temp2->instance = temp4;
	
	temp4 = NULL;

}


template <class generic>
Btn<generic> * Bst<generic>::p_insert (generic x)
{
	Btn<generic> * temp ;
	temp = m_root;
	
	bool loop = true ;
	//set temp to the x wher looking for 
	
	while ( loop )
	{
	
		//cerr << "searching for" << x << endl;
		if (temp->right == NULL || temp->left == NULL)
		{
			loop = 0 ;
		}
		else if(*(temp->data) > x )
		{	
			temp = temp->left;
		}
		else if(*(temp->data) < x )
		{
			temp = temp->right;
		}
		
		else if (*(temp->data) == x)
		{
			temp = temp->parent;
			loop = 0 ;
		}
	}
	//cerr << "found" << *(temp->data) << endl;
	
	return temp ;
	
}

template <class generic>
Btn<generic> * Bst<generic>::p_remove (generic x)
{
	Btn<generic> * temp ;
	temp = m_root;
	
	bool loop = true ;
	//set temp to the x wher looking for 
	
	while ( loop )
	{
	
		//cerr << "searching for" << x << endl;
		if (temp == NULL)
		{
			loop = 0 ;
		}
		else if(*(temp->data) > x )
		{	
			temp = temp->left;
		}
		else if(*(temp->data) < x )
		{
			temp = temp->right;
		}
		
		else if (*(temp->data) == x)
		{
			loop = 0 ;
		}
	}
	//cerr << "found" << *(temp->data) << endl;
	
	return temp->parent ;
}

template <class generic>
Btn<generic> * Bst<generic>::p_search (generic x)
{

	Btn<generic> * temp ;
	temp = m_root;
	
	bool loop = true ;
	//set temp to the x wher looking for 
	
	while ( loop )
	{
	
		//cerr << "searching for" << x << endl;
		if (temp == NULL)
		{
			loop = 0 ;
		}
		else if(*(temp->data) > x )
		{	
			temp = temp->left;
		}
		else if(*(temp->data) < x )
		{
			temp = temp->right;
		}
		
		else if (*(temp->data) == x)
		{
			loop = 0 ;
		}
	}
	//cerr << "found" << *(temp->data) << endl;
	
	if ( temp == NULL)
	{
		throw Exception
			(
				NOT_FOUND,
				"Im sorry dave, I canot return that value."
			);
	}
	
	
	return temp ;
}
