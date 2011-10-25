//////////////////////////////////////////////////////////////////////
/// @file slist.hpp
/// @author James Anderson  CS 153 Section A
/// @brief  Template implemintation  file for singly 
/// linked list iterator class for assignment 4
////////////////////////////////////////////////////////////////////// 

template <class generic>
SListIterator<generic>::SListIterator () : m_current (NULL)
{
}

template <class generic>
SListIterator<generic>::SListIterator (SNode<generic> * x) : m_current (x)
{
}

template <class generic>
generic SListIterator<generic>::operator* () const
{
    return m_current->data;
}

template <class generic>
SListIterator<generic> SListIterator<generic>::operator++ ()
{
    m_current = m_current->forward;
    return *this;
}

template <class generic>
SListIterator<generic> SListIterator<generic>::operator++ (int)
{
    return ++(*this);
}

template <class generic>
bool SListIterator<generic>::operator== (const SListIterator & rhs) const
{
    return m_current == rhs.m_current;
}

template <class generic>
bool SListIterator<generic>::operator!= (const SListIterator & rhs) const
{
    return m_current != rhs.m_current;
}
