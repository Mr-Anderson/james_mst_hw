//////////////////////////////////////////////////////////////////////
/// @file priority_queue.hpp
/// @author James Anderson  CS 153 Section A
/// @brief  Template implemintation file for
/// the priority queue class for assignment 8
//////////////////////////////////////////////////////////////////////

template <class generic>
Priority_queue<generic>::Priority_queue ()  
{
	m_size = 0 ;
	m_root = NULL;
	m_push = NULL;
	m_pop = NULL;
}

template <class generic>
Priority_queue<generic>::~Priority_queue ()
{
	clear();
}

template <class generic>
Priority_queue<generic>::Priority_queue(Priority_queue & original)
{
	m_size = 0 ;
	m_root = NULL;
	m_push = NULL;
	m_pop = NULL;
	
	//create temp
	Priority_queue<generic> temp;
	
	//copy to temp
	while (!original.empty())
	{
		temp.push(original.top()) ;
		original.pop();
	}
	
	//copy temp to new and old
	while (!temp.empty())
	{
		original.push(temp.top()) ;
		push(temp.top()) ;
		temp.pop();
	}
}

template <class generic>
Priority_queue<generic> & Priority_queue<generic>:: operator= ( Priority_queue & original)
{
	clear();
	
	//create temp
	Priority_queue<generic> temp;
	
	//copy to temp
	while (!original.empty())
	{
		temp.push(original.top()) ;
		original.pop();
	}
	
	//copy temp to new and old
	while (!temp.empty())
	{
		original.push(temp.top()) ;
		push(temp.top()) ;
		temp.pop();
	}
	
	return *this ;
}

template <class generic>
void Priority_queue<generic>::push (generic x)
{
	m_size++ ;
	
	if (m_root == NULL)
	{
		m_root = new Btn<generic>;
		m_root->data = new generic;
		*(m_root->data) = x ;
		m_root->parent = NULL;
		m_root->left = NULL;
		m_root->right = NULL;
		m_push = m_root ;
		m_pop = m_root;
	}
	
	else 
	{
		

		if(m_push->left == NULL  )
		{
			m_push->left = new Btn<generic>;
			m_push->left->data = new generic;
			*(m_push->left->data) = x ;
			m_push->left->parent = m_push;
			m_push->left->left = NULL;
			m_push->left->right = NULL;
			m_pop = m_push ;
			heapify( m_push->left);
			
		}
		else 
		{
			m_push->right = new Btn<generic>;
			m_push->right->data = new generic;
			*(m_push->right->data) = x ;
			m_push->right->parent = m_push;
			m_push->right->left = NULL;
			m_push->right->right = NULL;
			heapify( m_push->right);
			
			// move m_push to next destination
			while (m_push->parent != NULL && m_push->parent->right == m_push)
			{
				m_push = m_push->parent;
			}
			if (m_push != m_root)
			{
				m_push = m_push->parent;
				m_push = m_push->right;
			}
			while(m_push->left != NULL)
			{
				m_push = m_push->left ;
			}

		}
		
	}
	
}

template <class generic>
void Priority_queue<generic>::pop ()
{
	
	//throw exception if empty

	if (m_root == NULL)
	{
		throw Exception
		(
			CONTAINER_EMPTY,
			"The container is empty. You canot make it smaller."
			
		);
	}	
	
	m_size-- ;
	if(m_pop == m_root && m_pop->right == NULL && m_pop->left == NULL)
	{
		delete m_pop->data ;
		delete m_pop ;
		m_root = NULL;
		m_push = NULL;
		m_pop = NULL;
	
	}
	else if( m_pop->right != NULL)
	{
		swap ( m_pop->right , m_root) ;
		delete m_pop->right->data ;
		delete m_pop->right ;
		m_pop->right = NULL ;
		m_push = m_pop ;
		heepify( );
		
		
	}
	else 
	{
		swap ( m_pop->left , m_root) ;
		delete m_pop->left->data ;
		delete m_pop->left ;
		m_pop->left = NULL ;
		heepify( );
		
		
		// move m_pop to next destination
		while (m_pop->parent != NULL && m_pop->parent->left == m_pop)
		{
			m_pop = m_pop->parent;
		}
		
		if (m_pop != m_root)
		{
			m_pop = m_pop->parent;
			m_pop = m_pop->left;
		}
		
		while(m_pop->right != NULL && m_pop->right->right != NULL)
		{
			m_pop = m_pop->right ;
		}
		
	}
	
	
}

template <class generic>
generic Priority_queue<generic>::top ()
{
	//throw exception if empty
	if (m_root == NULL)
	{
	
		throw Exception
		(
			CONTAINER_EMPTY,
			"The container is empty. You canot make it smaller."
		);
	}	
	return *(m_root->data);
}

template <class generic>
void Priority_queue<generic>::clear ()
{
	
	while( !empty() )
	{
		pop () ;
	}

}

template <class generic>
bool Priority_queue<generic>::empty () const
{
	bool temp = false ;
	if (m_size == 0)
	{
		temp = true;
	}
	return temp;
}

template <class generic>
unsigned int Priority_queue<generic>::size () const
{
	return m_size;
}


template <class generic>
void Priority_queue<generic>::swap (Btn<generic> * temp1, Btn<generic> * temp2)
{
	generic * temp3 = NULL;
			
			
	temp3 = temp1->data;
	temp1->data = temp2->data;
	temp2->data = temp3;
	
	temp3 = NULL;


}


template <class generic>
void Priority_queue<generic>::heapify( Btn<generic> * temp )
{
	
	while ( temp != m_root && *(temp->parent->data) < *(temp->data)  )
	{
		swap ( temp , temp->parent);
		temp = temp->parent;
	}

}

template <class generic>
void Priority_queue<generic>::heepify( )
{
	Btn<generic> * temp = m_root ;
	

	
	if(temp->right == NULL && temp->left != NULL)
	{
		if(*(temp->data) < *(temp->left->data))
		{
			swap( temp , temp->left ) ;
		}
	}
	else
	{
		while ( temp->left != NULL && temp->right != NULL && *(temp->data) < *(temp->right->data) && *(temp->data) < *(temp->left->data) )
		{
			if (*(temp->data) < *(temp->right->data))
			{
				swap (temp , temp->right);
				temp = temp->right ;
			}
			else
			{
				swap (temp , temp->left);
				temp = temp->left ;
			}
		}
	}
	
	
}
