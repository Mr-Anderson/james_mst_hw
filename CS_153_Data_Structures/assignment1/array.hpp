//////////////////////////////////////////////////////////////////////
/// @file array.hpp
/// @author James Anderson  CS 153 Section A
/// @brief  Template implemintation  file for array class for assignment 1
////////////////////////////////////////////////////////////////////// 
template <class generic>
Array<generic>::Array () : m_size (0), m_max_size (20)
{
	generic m_data[m_max_size];
}

template <class generic>
void Array<generic>::push_back (generic x)
{
	if (m_size >= m_max_size)
	{
		throw Exception
		(
			CONTAINER_FULL,
			"The array is full. You have reached its max size."
		);
	}	
	m_data[m_size] = x;
	m_size++;
}

template <class generic>
void Array<generic>::pop_back ()
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
}

template <class generic>
void Array<generic>::clear ()
{
	m_size = 0;
}

template <class generic>
generic& Array<generic>::operator[] (unsigned int x)
{
	if (x >= m_size or x < 0)
	{
		throw Exception
		(
			OUT_OF_BOUNDS,
			"The position you have asked for is not in the scope of the array."
		);
	}	
	return m_data[x];
}

template <class generic>
generic& Array<generic>::operator[] (unsigned int x) const
{
	if (x >= m_size or x < 0)
	{
		throw Exception
		(
			OUT_OF_BOUNDS,
			"The position you have asked for is not in the scope of the array."
		);
	}	
	return m_data[x];
}

template <class generic>
unsigned int Array<generic>::size () const
{
	return m_size ;
}

template <class generic>
unsigned int Array<generic>::max_size () const
{
	return m_max_size ;
}
