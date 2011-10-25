//////////////////////////////////////////////////////////////////////
/// @file slist.hpp
/// @author James Anderson  CS 153 Section A
/// @brief  Template implemintation file for
/// the single linked class for assignment 4
////////////////////////////////////////////////////////////////////// 

template <class generic>
SList<generic>::SList () : m_front(NULL) , m_size(0) 
{
	
}

template <class generic>
SList<generic>::SList (SList & l)
{
	m_front = NULL;
	m_size = 0 ;
	clear();
	SList<generic> temp;
	Iterator i;
	
	for (i = l.begin(); i != l.end(); i++)
	{
		temp.push_front(*i); 
	}
	for (i = temp.begin(); i != temp.end(); i++)
	{
		push_front(*i); 
	}
	temp.clear ();

}

template <class generic>
SList<generic>::~SList () 
{
	clear ();	 
}

 
template <class generic>
SList<generic> & SList<generic>:: operator= (const SList & l)
{
	clear();
	SList<generic> temp;
	Iterator i;
	
	for (i = l.begin(); i != l.end(); i++)
	{
		temp.push_front(*i); 
	}
	for (i = temp.begin(); i != temp.end(); i++)
	{
		push_front(*i); 
	}
	
	temp.clear();
	
	return *this;
}

template <class generic>
void SList<generic>::push_front (generic x)
{
	if (m_front == NULL)
	{
		m_front = new SNode<generic>;
		m_front->data = x;
		m_front->forward = NULL;
	}
	else 
	{
		SNode<generic> * temp;
		temp = m_front;
		m_front = new SNode<generic>;
		m_front->data = x;
		m_front->forward = temp;
		
	}
	m_size++ ;
}

template <class generic>
void SList<generic>::pop_front ()
{

	if (m_front == NULL)
	{
		throw Exception
		(
			CONTAINER_EMPTY,
			"The container is empty. You canot make it smaller."
		);
	}
	else if (m_front->forward == NULL)
	{
		delete m_front;
		m_front = NULL;
		m_size--;
	}
	else 
	{
		SNode<generic> * temp;
		temp = m_front;
		m_front = m_front->forward;
		delete temp;
		m_size--;
		
	}

	
}

template <class generic>
void SList<generic>::remove (generic x)
{
	SNode<generic> * temp;
	temp = m_front;
	
	while(temp->forward != NULL && !empty())
	{
		
		if (temp->forward->data == x)
		{
			if (temp == m_front)
			{
				pop_front();
			}
			else 
			{
				SNode<generic> * temp2;
   				temp2 = temp->forward->forward;
   				delete temp->forward;
   				temp->forward = temp2;
   				m_size--;
   			}
   			
   				
		}
		temp = temp->forward;
   		
	}
   			
	
}

template <class generic>
void SList<generic>::clear ()
{
	while ( m_front != NULL)
	{
		pop_front();
	}
	
}

template <class generic>
generic& SList<generic>::front ()
{
	return m_front->data;
}

template <class generic>
SListIterator<generic> SList<generic>::begin () const
{
    return Iterator (m_front);
}

template <class generic>
SListIterator<generic> SList<generic>::end () const
{
    return Iterator ();
}

template <class generic>
unsigned int SList<generic>::size () const
{
	return m_size ;
}

template <class generic>
bool SList<generic>::empty () const
{
	bool x = 0;
	if (m_front == NULL)
	{
		x = 1;
	}
	return x;
}
