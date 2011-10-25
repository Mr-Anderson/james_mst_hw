//////////////////////////////////////////////////////////////////////
/// @file btpostorderiterator.hpp
/// @author James Anderson  CS 153 Section A
/// @brief  Template implemintation  file for binary
/// tre post order iterator class for assignment 6
////////////////////////////////////////////////////////////////////// 

template <class generic>
BTPostorderIterator<generic>::BTPostorderIterator () : m_current (NULL) 
{
}

template <class generic>
BTPostorderIterator<generic>::BTPostorderIterator (Btn<generic> * x) : m_current (x) 
{
}

template <class generic>
generic BTPostorderIterator<generic>::operator* () const
{
	return *(m_current->data);
}

template <class generic>
BTPostorderIterator<generic> BTPostorderIterator<generic>::operator++ ()
{
	bool loop = 1 , from_left = 0 , from_right = 0 ;
	while(loop)
	{
		
		//left
		if (from_left && from_right && m_current->left != NULL )
		{
			m_current = m_current->left ;
		}
		//right 
		else if (from_left && m_current->right != NULL )
		{
			m_current = m_current->right ;
			from_left = true ;
			from_right = true ;
		}
		//middle
		else if (from_right || (from_left &&  m_current->right == NULL ))
		{
			loop = 0 ;	
		}
		//parent
		else
		{
			
			//to left
			if (m_current->parent->left == m_current)
			{
				from_left = true ;
				from_right = false ;
			}
			//to right
			else if (m_current->parent->right == m_current)
			{
				from_left = false ;
				from_right = true ;
			}
			//woops
			else 
			{
				cerr << "trying to go up to null" << endl ;
			}
			//move up a node
			m_current = m_current->parent; 
		}
	
	}
	return *this;
}

template <class generic>
BTPostorderIterator<generic> BTPostorderIterator<generic>::operator++ (int x)
{
    return ++(*this);
}

template <class generic>
bool BTPostorderIterator<generic>::operator== (const BTPostorderIterator & bt) const
{
    return m_current == bt.m_current;
}

template <class generic>
bool BTPostorderIterator<generic>::operator!= (const BTPostorderIterator & bt) const
{
    return m_current != bt.m_current;
}

template <class generic>
void BTPostorderIterator<generic>::parent( bool from_left , bool from_right )
{
	

}

template <class generic>
Btn<generic> * BTPostorderIterator<generic>::current()
{
	return m_current;
}



