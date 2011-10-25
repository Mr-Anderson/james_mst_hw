//////////////////////////////////////////////////////////////////////
/// @file vector.hpp
/// @author James Anderson  CS 153 Section A
/// @brief  Template implemintation  file for vector class for assignment 9
////////////////////////////////////////////////////////////////////// 
template <class generic>
Vector<generic>::Vector () : m_size (0), m_max_size (1)
{
	m_data = new generic[m_max_size];
}

template <class generic>
Vector<generic>::~Vector () 
{
	delete[] m_data; 
}

template <class generic>
void Vector<generic>::push_back (generic x)
{
	// check if the array is full 
	if (m_size >= m_max_size)
	{
		//create temperary pointer to array 
		generic * temp = m_data;
		// create new array with twice the size
		m_max_size *= 2;
		m_data = new generic [m_max_size];
		for(unsigned int i = 0 ; i < m_size ; i++ )
		{
			//fill the new array with old data
			m_data [i] = temp [i] ;		
		
		}
		// delete old array 
		delete[] temp;
	}
	// add new data to array 
	m_data[m_size++] = x;
	
}

template <class generic>
void Vector<generic>::pop_back ()
{

	if (m_size <= 0)
	{
		throw Exception
		(
			CONTAINER_EMPTY,
			"The array is empty. You canot make it smaller."
		);
	}	
	
	m_size--;
	
	// check to see if the array is to lage
	if (m_size <=  m_max_size / 4 )
	{
		//create temperary pointer to array 
		generic * temp = m_data;
		// create new array with half the size
		m_max_size /= 2;
		m_data = new generic [m_max_size];
		for(unsigned int i = 0 ; i < m_size ; i++ )
		{
			//fill the new array with old data
			m_data [i] = temp [i] ;		
		
		}
		// delete old array 
		delete[] temp;
	}
	
	if (m_size == 0)
	{
		m_max_size = 1 ;
	}
	
	
}

template <class generic>
void Vector<generic>::clear ()
{
	// delete array
	delete[] m_data;
	// reset sizes
	m_size = 0;
	m_max_size = 1;
	//create new array
	m_data = new generic[m_max_size];
	
}

template <class generic>
generic& Vector<generic>::operator[] (unsigned int x)
{
	if (x >= m_size or x < 0)
	{
		throw Exception
		(
			OUT_OF_BOUNDS,
			"The position you have asked for is not in the scope of the vector."
		);
	}	
	return m_data[x];
}

template <class generic>
generic& Vector<generic>::operator[] (unsigned int x) const
{
	if (x >= m_size or x < 0)
	{
		throw Exception
		(
			OUT_OF_BOUNDS,
			"The position you have asked for is not in the scope of the vector."
		);
	}	
	return m_data[x];
}

template <class generic>
unsigned int Vector<generic>::size () const
{
	return m_size ;
}

template <class generic>
unsigned int Vector<generic>::max_size () const
{
	return m_max_size ;
}
