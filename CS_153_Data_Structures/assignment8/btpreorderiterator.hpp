//////////////////////////////////////////////////////////////////////
/// @file btpreorderiterator.hpp
/// @author James Anderson  CS 153 Section A
/// @brief  Template implemintation  file for binary
/// tre pre order iterator class for assignment 8
////////////////////////////////////////////////////////////////////// 

template <class generic>
BTPreorderIterator<generic>::BTPreorderIterator () : m_current (NULL) 
{
}

template <class generic>
BTPreorderIterator<generic>::BTPreorderIterator (Btn<generic> * x) : m_current (x) 
{
}

template <class generic>
generic BTPreorderIterator<generic>::operator* () const
{
	return *(m_current->data);
}

template <class generic>
BTPreorderIterator<generic> BTPreorderIterator<generic>::operator++ ()
{
	bool loop = 1 , from_left = 0 , from_right = 0 ;
	while(loop)
	{
	
		//middle
		if (from_left && from_right)
		{
			loop = 0 ;	
		}
		//left
		else if (!from_left && !from_right && m_current->left != NULL )
		{
			m_current = m_current->left ;
			from_left = true ;
			from_right = true ;
		}
		//right 
		else if (from_left  && m_current->right != NULL )
		{
			m_current = m_current->right ;
			from_left = true ;
			from_right = true ;
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
BTPreorderIterator<generic> BTPreorderIterator<generic>::operator++ (int x)
{
    return ++(*this);
}

template <class generic>
bool BTPreorderIterator<generic>::operator== (const BTPreorderIterator & bt) const
{
    return m_current == bt.m_current;
}

template <class generic>
bool BTPreorderIterator<generic>::operator!= (const BTPreorderIterator & bt) const
{
    return m_current != bt.m_current;
}

template <class generic>
void BTPreorderIterator<generic>::parent( bool from_left , bool from_right )
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

template <class generic>
Btn<generic> * BTPreorderIterator<generic>::current()
{
	return m_current;
}



