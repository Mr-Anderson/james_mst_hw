/////////////////////////////////////////////////////////////////////
/// @file listiterator.hpp
/// @author James Anderson  CS 153 Section A
/// @brief  Template implemintation  file for double 
/// linked list iterator class for assignment 4
////////////////////////////////////////////////////////////////////// 

template <class generic>
ListIterator<generic>::ListIterator () : m_current (NULL)
{
}

template <class generic>
ListIterator<generic>::ListIterator (Node<generic> * x) : m_current (x)
{
}

template <class generic>
generic ListIterator<generic>::operator* () const
{
    return m_current->data;
}

template <class generic>
ListIterator<generic> ListIterator<generic>::operator++ ()
{
    m_current = m_current->forward;
    return *this;
}

template <class generic>
ListIterator<generic> ListIterator<generic>::operator++ (int)
{
    return ++(*this);
}

template <class generic>
ListIterator<generic> ListIterator<generic>::operator-- ()
{
    m_current = m_current->back;
    return *this;
}

template <class generic>
ListIterator<generic> ListIterator<generic>::operator-- (int)
{
    return --(*this);
}

template <class generic>
bool ListIterator<generic>::operator== (const ListIterator & rhs) const
{
    return m_current == rhs.m_current;
}

template <class generic>
bool ListIterator<generic>::operator!= (const ListIterator & rhs) const
{
    return m_current != rhs.m_current;
}
