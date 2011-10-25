//////////////////////////////////////////////////////////////////////
/// @file bt.hpp
/// @author James Anderson  CS 153 Section A
/// @brief  Template implemintation file for
/// the bt class for assignment 7
//////////////////////////////////////////////////////////////////////

template <class generic>
BT<generic>::BT ()  
{
	m_size = 0 ;
	m_root = NULL;
}

template <class generic>
BT<generic>::~BT ()
{
	clear();
}


template <class generic>
BT<generic>::BT( BT & y)
{
	m_size = 0 ;
	m_root = NULL;
	
	Btn<generic> * temp ;
	
	PreOrder k ;

	for ( k = y.pre_begin() ; k != y.pre_end() ; k++)
	{
		i_give_up_insert (*k,k.current()->balance) ;
	}
	i_give_up_insert (*k,k.current()->balance) ;
	
}

template <class generic>
BT<generic> & BT<generic>:: operator= (const BT & y)
{
	
	clear ();
	
	
	Btn<generic> * temp ;
	
	PreOrder k ;

	for ( k = y.pre_begin() ; k != y.pre_end() ; k++)
	{
		i_give_up_insert (*k,k.current()->balance) ;
	}
	i_give_up_insert (*k,k.current()->balance) ;
	
	
	
	return *this ;
	
}


template <class generic>
void BT<generic>::clear ()
{
	PostOrder k ;
	Btn<generic> * temp ;
	
	if (!empty ())
	{
		
		for ( k = post_begin() ; k != post_end() ; )
		{
			temp = k.current() ;
			k++ ;
			//cerr << *(temp->data) << endl ;
			delete temp->data ;
			delete temp->instance ;
			delete temp;
		}
		
		temp = k.current() ;
		//cerr << *(temp->data) << endl ;
		delete temp->data ;
		delete temp->instance ;
		delete temp;

		
		m_root = NULL;
		m_size = 0 ;
	}
	
}

template <class generic>
bool BT<generic>::empty () const
{
	bool temp = false ;
	if (m_size == 0)
	{
		temp = true;
	}
	return temp;
}

template <class generic>
unsigned int BT<generic>::size () const
{
	return m_size;
}

template <class generic>
BTPreorderIterator<generic> BT<generic>::pre_begin () const
{	
	return PreOrder (m_root);
}

template <class generic>
BTPreorderIterator<generic> BT<generic>::pre_end () const
{
	Btn<generic> * temp ;
	temp = m_root ;
	
	while (temp->right != NULL)
	{
		temp = temp->right;
	}
	
	return PreOrder (temp);
}

template <class generic>
BTInorderIterator<generic> BT<generic>::in_begin () const
{
	Btn<generic> * temp ;
	temp = m_root;
	
	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	
	return InOrder (temp);
}

template <class generic>
BTInorderIterator<generic> BT<generic>::in_end () const
{
	Btn<generic> * temp ;
	temp = m_root;
	
	while (temp->right != NULL)
	{
		temp = temp->right;
	}
	
	return InOrder (temp);
}

template <class generic>
BTPostorderIterator<generic> BT<generic>::post_begin () const
{
	Btn<generic> * temp ;
	temp = m_root;
	bool loop = 1;
	
	while (loop)
	{
		if (temp->left != NULL)
		{
			temp = temp->left;
		}
		else if (temp->right != NULL)
		{
			temp = temp->right;
		}
		else 
		{
			loop = 0;
		}
	}
	
	return PostOrder (temp);
}

template <class generic>
BTPostorderIterator<generic> BT<generic>::post_end () const
{

	return PostOrder (m_root);
}

template <class generic>
void BT<generic>::i_give_up_insert (generic x , short balance)
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
		m_root->balance = balance;
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
					temp->left->balance = balance;
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
					temp->right->balance = balance;
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
