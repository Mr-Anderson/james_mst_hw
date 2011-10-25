//////////////////////////////////////////////////////////////////////
/// @file queue.hpp
/// @author James Anderson  CS 153 Section A
/// @brief  Template implemintation file for
/// the queue class for assignment 4
////////////////////////////////////////////////////////////////////// 

template <class generic>
Queue<generic>::Queue ()
{
}

template <class generic>
Queue<generic>::Queue (Queue & q) : List<generic> (q)
{
}

template <class generic>
Queue<generic>::~Queue ()
{
}

template <class generic>
Queue<generic> & Queue<generic>:: operator= (const Queue & q)
{
	
	return *this;
}

template <class generic>
bool Queue<generic>::empty () const
{
    return List<generic>::empty ();
}

template <class generic>
unsigned int Queue<generic>::size () const
{
    return List<generic>::size ();
}

template <class generic>
generic & Queue<generic>::front ()
{
    return List<generic>::front ();
}

template <class generic>
generic & Queue<generic>::back ()
{
    return List<generic>::back ();
}

template <class generic>
void Queue<generic>::push (generic x)
{
    List<generic>::push_front (x);
}

template <class generic>
void Queue<generic>::pop ()
{
    List<generic>::pop_back ();
}

template <class generic>
void Queue<generic>::clear ()
{
    List<generic>::clear ();
}





