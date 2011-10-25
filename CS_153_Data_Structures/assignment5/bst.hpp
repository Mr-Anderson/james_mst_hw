//////////////////////////////////////////////////////////////////////
/// @file bst.hpp
/// @author James Anderson  CS 153 Section A
/// @brief  Template implemintation file for
/// the bst class for assignment 6
//////////////////////////////////////////////////////////////////////

template <class generic>
Bst<generic>::Bst ()  
{
	m_size = 0 ;
	m_root = NULL;
}

template <class generic>
Bst<generic>::~Bst ()
{
	clear();
}


template <class generic>
void Bst<generic>::insert (generic x)
{
	m_size++ ;
	
	if (m_root == NULL)
	{
		m_root = new Btn<generic>;
		m_root->data = new generic;
		m_root->instance = new int;
		*(m_root->instance) = 1;
		*(m_root->data) = x ;
		m_root->parent = NULL;
		m_root->left = NULL;
		m_root->right = NULL;
	}
	
	else 
	{
		Btn<generic> * temp = m_root;
		
		do
		{
			if(*(temp->data) > x  )
			{
				if (temp->left == NULL )
				{
					temp->left = new Btn<generic>;
					temp->left->data = new generic;
					temp->left->instance = new int;
					*(temp->left->instance) = 1;
					*(temp->left->data) = x ;
					temp->left->parent = temp;
					temp->left->left = NULL;
					temp->left->right = NULL;
					temp = NULL;
				}
				else
				{
					temp = temp->left;
				}
			}
			else if(*(temp->data) < x )
			{
				if (temp->right == NULL )
				{
					temp->right = new Btn<generic>;
					temp->right->data = new generic;
					temp->right->instance = new int;
					*(temp->right->instance) = 1;
					*(temp->right->data) = x ;
					temp->right->parent = temp;
					temp->right->left = NULL;
					temp->right->right = NULL;
					temp = NULL;
				}
				else
				{
					temp = temp->right;
				}	
			}
			else if(*(temp->data) = x )
			{
				*(temp->instance)++;
				temp = NULL;
			}
			
		}while (temp != NULL) ;
		
		
	}
	
}

template <class generic>
void Bst<generic>::remove (generic x)
{
	Btn<generic> * temp ;
	
	//throw exception if empty
	if (empty())
	{
		throw Exception
		(
			CONTAINER_EMPTY,
			"The container is empty. You canot make it smaller."
		);
	}	
	

	//find node with data were looking for
	temp = p_search (x);
	

	//if the item to be deleted exists
	if (temp != NULL)
	{
		
		
		//node to delete has no children
		if (temp->left == NULL && temp->right == NULL )
		{
			delete_leaf (temp);
		}

		//node to delete has two children
		else if (temp->left != NULL && temp->right != NULL )
		{
			
			
			//move temp2 down to left right most 
			Btn<generic> * temp2 ;
			temp2 = temp;
			
			if (temp2->left !=NULL)
			temp2 = temp2->left;
			while ( temp2->right != NULL )
			{	
				temp2 = temp2->right ; 
			}
			

			
			//swap data in node to delete 
			swap(temp , temp2);
			
			
			
			
			//node to delete has no children
			if (temp2->left == NULL && temp2->right == NULL )
			{
				delete_leaf ( temp2 ) ;
			}
			
			//node to delete has one child
			else
			{
				
				//cerr << temp2 << endl;
				delete_link ( temp2 ) ;
			}
			
	 
		}
		
		//node to delete has one child
		else
		{
			delete_link ( temp ) ;		
			
		}
		
	}
	
}

template <class generic>
generic & Bst<generic>::search (generic x)
{
	
	Btn<generic> * temp ;

	temp = p_search (x);
	
	return *(temp->data);
}

template <class generic>
void Bst<generic>::clear ()
{
	
	while( !empty() )
	{
		remove (*(m_root->data)) ;
	}

}

template <class generic>
bool Bst<generic>::empty () const
{
	bool temp = false ;
	if (m_size == 0)
	{
		temp = true;
	}
	return temp;
}

template <class generic>
unsigned int Bst<generic>::size () const
{
	return m_size;
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
void Bst<generic>::delete_leaf (Btn<generic> *temp1)
{

	if (temp1->parent != NULL)
	{
		if (temp1->parent->right == temp1)
		{
		temp1->parent->right = NULL;
		}
		else if (temp1->parent->left == temp1)
		{
			temp1->parent->left = NULL;
		}
	}
			
	else
	{
		m_root = NULL;
	}
	
	m_size = m_size - *(temp1->instance) ;		
	delete temp1->instance;
	delete temp1->data; 
	delete temp1;	

}

template <class generic>
void Bst<generic>::delete_link (Btn<generic> * temp1)
{
	//cerr << "fuck my life" << endl;
	//child to right 
	
	if (temp1->right != NULL)
	{
		
		//point parent to child		
		if ( temp1->parent != NULL)
		{
			if (temp1->parent->right == temp1)
			{
				temp1->parent->right = temp1->right;
			}
			else if (temp1->parent->left == temp1)
			{
				temp1->parent->left = temp1->right;
			}
		}
		
		else
		{
			m_root = temp1->right;
		}
				
		//point child to parent
		temp1->right->parent = temp1->parent;
				
		//delete node
			

	}
			
	//child to left
	else 
	{
			
		//point parent to child
		if ( temp1->parent != NULL)
		{
			if (temp1->parent->right == temp1)
			{
				temp1->parent->right = temp1->left;
			}	
			else if (temp1->parent->left == temp1)
			{
				temp1->parent->left = temp1->left;
			}
		}
		else
		{
			m_root = temp1->left;
		}
				
	
				
		//point child to parent
		temp1->left->parent = temp1->parent;
				
				
		//delete node
		
			
	}
	
	
	m_size = m_size - *(temp1->instance) ;		
	delete temp1->instance;
	delete temp1->data;	
	delete temp1;	
	
}



template <class generic>
Btn<generic> * Bst<generic>::p_insert (generic)
{

}

template <class generic>
Btn<generic> * Bst<generic>::p_remove (generic)
{

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
	
	return temp ;
}
