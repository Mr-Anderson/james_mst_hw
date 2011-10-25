//////////////////////////////////////////////////////////////////////
/// @file list.hpp
/// @author James Anderson  CS 153 Section A
/// @brief  Template implemintation file for
/// the double linked class for assignment 4
////////////////////////////////////////////////////////////////////// 

template <class generic>
List<generic>::List () : m_front(NULL) , m_back(NULL) , m_size(0) 
{
	
}

template <class generic>
List<generic>::List (List & l)
{
	m_front = NULL;
	m_size = 0 ;
	clear();
	Iterator i;
	
	for (i = l.begin(); i != l.end(); i++)
	{
		push_back(*i); 
	}
	

}

template <class generic>
List<generic>::~List () 
{
	clear ();	 
}

 
template <class generic>
List<generic> & List<generic>:: operator= (const List & l)
{
	clear();
	Iterator i;
	
	for (i = l.begin(); i != l.end(); i++)
	{
		push_back(*i); 
	}
	
	return *this;
}

template <class generic>
void List<generic>::push_front (generic x)
{
	if (m_front == NULL)
	{
		m_front = new Node<generic>;
		m_back = m_front ;
		m_front->data = x;
		m_front->forward = NULL;
		m_front->back = NULL;
		
	}
	else 
	{
		
		m_front->back = new Node<generic>;
		m_front->back->forward = m_front;
		m_front = m_front->back;
		m_front->forward->back = m_front;
		m_front->data = x;
		m_front->back = NULL;
		
		
		
	}
	m_size++ ;
}

template <class generic>
void List<generic>::pop_front ()
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
		Node<generic> * temp;
	    temp = m_front;
		delete temp  ;
		m_front = NULL;
		m_back = NULL;
		m_size--;
	}
	
	else 
	{
		Node<generic> * temp;
	    temp = m_front;
		m_front = m_front->forward;
		delete temp  ;
		m_front->back = NULL ;
		m_size--;
		
	}
	
}

template <class generic>
void List<generic>::push_back (generic x)
{
	if (m_front == NULL)
	{
		m_front = new Node<generic>;
		m_back = m_front ;
		m_front->data = x;
		m_front->forward = NULL;
		m_front->back = NULL;
		
	}
	else 
	{
		
		m_back->forward = new Node<generic>;
		m_back->forward->data = x;
		m_back->forward->back = m_front;
		m_back->forward->forward = NULL;
		m_back = m_back->forward;
		
	}
	m_size++ ;
}

template <class generic>
void List<generic>::pop_back ()
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
		Node<generic> * temp;
	    temp = m_front;
		delete temp  ;
		m_front = NULL;
		m_back = NULL;
		m_size--;
	}
	
	else 
	{
		Node<generic> * temp;
	    temp = m_front;
		m_front = m_front->forward;
		delete temp  ;
		m_front->back = NULL ;
		m_size--;
		
	}
}

template <class generic>
void List<generic>::remove (generic x)
{
	Node<generic> * temp;
	temp = m_front;

	while(temp->forward->forward != NULL)
	{
		
		if (temp->forward->data == x)
		{
			if (temp == m_front)
			{
				pop_front();
			}

			else 
			{
				Node<generic> * temp2;
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
generic& List<generic>::front ()
{
	return m_front->data;
}

template <class generic>
generic& List<generic>::back ()
{
	return m_back->data;
}

template <class generic>
void List<generic>::clear ()
{
	while ( m_front != NULL)
	{
		pop_front();
	}
	
}

template <class generic>
unsigned int List<generic>::size () const
{
	return m_size ;
}

template <class generic>
bool List<generic>::empty () const
{
	bool x = 0;
	if (m_front == NULL)
	{
		x = 1;
	}
	return x;
}

template <class generic>
ListIterator<generic> List<generic>::begin () const
{
    return Iterator (m_front);
}

template <class generic>
ListIterator<generic> List<generic>::end () const
{
    return Iterator (m_back);
}



