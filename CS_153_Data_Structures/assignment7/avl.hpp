//////////////////////////////////////////////////////////////////////
/// @file avl.hpp
/// @author James Anderson  CS 153 Section A
/// @brief  Template implemintation file for
/// the avl class for assignment 7
//////////////////////////////////////////////////////////////////////



template <class generic>
void Avl<generic>::insert (generic x)
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
		m_root->balance = 0 ;
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
					temp->balance = 0;
					//insert_balance(temp);
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
					temp->balance = 0;
					//insert_balance(temp);
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
void Avl<generic>::remove (generic x)
{
	Btn<generic> * temp ;
	
	//throw exception if empty
	if (m_root == NULL)
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
void Avl<generic>::delete_leaf (Btn<generic> *temp1)
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
void Avl<generic>::delete_link (Btn<generic> * temp1)
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
void Avl<generic>::insert_balance (Btn<generic> * temp )
{
	while (temp->parent != NULL)
	{
		//left
		if(temp->balance <= -2)
		{
			//left
			if(temp->left->balance < 0)
			{
				left_left ( temp , temp->left);
			}
			//right
			else if (temp->left->balance > 0)
			{
				left_right ( temp->left , temp->left->right);
			}
		}
		//right
		else if(temp->balance >= 2)
		{
			//left
			if(temp->left->balance < 0)
			{
				right_left ( temp->right , temp->right->left);
			}
			//right
			else if (temp->left->balance > 0)
			{
				right_right ( temp , temp->right);
			}
		}
		//from right
		if(temp->parent->right == temp)
		{
			temp->parent->balance++;
		}
		//from left
		else if(temp->parent->left == temp)
		{
			temp->parent->balance--;
		}		
		temp = temp->parent;
	}
	
}

template <class generic>
void Avl<generic>::left_left (Btn<generic> * root , Btn<generic> * pivot)
{

	
}

template <class generic>
void Avl<generic>::right_right (Btn<generic> * root , Btn<generic> * pivot)
{

	
}

template <class generic>
void Avl<generic>::left_right (Btn<generic> * root , Btn<generic> * pivot)
{

	
}

template <class generic>
void Avl<generic>::right_left (Btn<generic> * root , Btn<generic> * pivot)
{

	
}
