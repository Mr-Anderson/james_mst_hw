//////////////////////////////////////////////////////////////////////
/// @file stack.hpp
/// @author James Anderson  CS 153 Section A
/// @brief  Template implemintation file for
/// the stack class for assignment 4
//////////////////////////////////////////////////////////////////////

template <class generic>
Stack<generic>::Stack ()
{
}

template <class generic>
Stack<generic>::Stack (Stack & s) : SList<generic> (s)
{
}

template <class generic>
Stack<generic>::~Stack ()
{
}

template <class generic>
Stack<generic> & Stack<generic>:: operator= (const Stack & s)
{
	
	return *this;
}

template <class generic>
void Stack<generic>::push (generic x)
{
    SList<generic>::push_front (x);
}

template <class generic>
void Stack<generic>::pop ()
{
    SList<generic>::pop_front ();
}

template <class generic>
void Stack<generic>::clear ()
{
    SList<generic>::clear ();
}

template <class generic>
generic & Stack<generic>::top ()
{
    return SList<generic>::front ();
}

template <class generic>
unsigned int Stack<generic>::size () const
{
    return SList<generic>::size ();
}

template <class generic>
bool Stack<generic>::empty () const
{
    return SList<generic>::empty ();
}

