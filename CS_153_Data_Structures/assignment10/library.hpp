//////////////////////////////////////////////////////////////////////
/// @file library.hpp
/// @author James Anderson  CS 153 Section A
/// @brief  Template implemintation  file for vector class for assignment 10
////////////////////////////////////////////////////////////////////// 

// returns the index of where the generic was found in the vector
template <class generic>
unsigned int search (Vector<generic> & vector, generic data)
{
	unsigned int index = 0 ;
	while (index < vector.size() && vector[index] != data )
	{
		index ++ ;
	}
	if (index == vector.size() )
	{

		throw Exception
		(
			NOT_FOUND,
			"The data you requested could not be found."
		);
	}	
	return index ;
}

template <class generic>
unsigned int binary_search (Vector<generic> & vector, generic data)
{
	unsigned int index_right = (vector.size()  ) , index_left = -1 , probe = ((index_right - index_left)/2);
	while ( vector[probe] != data )
	{
		probe = ((index_right - index_left)/2);
		
		if (probe <= 0 )
		{
			throw Exception
			(
				NOT_FOUND,
				"The data you requested could not be found."
			);
		}	
		
 		probe = index_left + probe;
		
		if(vector[probe] < data)
		{
			index_left = probe;
		}
		else if(vector[probe] > data)
		{
			index_right = probe;
		}
		
	}
	return probe ;
}

// pass in the vector that is to be sorted least to greatest
template <class generic>
void bubble_sort (Vector<generic> & vector)
{
	generic temp;
	unsigned int size = 0 ;
	size = vector.size();
	
	for(; 1 < size ; size-- )
	{
	
		for(int i=0 ; i + 1  < size ; i++ )
		{

			if(vector[i] > vector[i+1])
			{
				temp = vector[i] ;
				vector[i] = vector[i+1] ;
				vector[i+1] = temp ;
			}
			
		}
	}	
}

template <class generic>
void selection_sort (Vector<generic> & vector)
{
	generic temp;
	int selection = 0, start = 0 ;
	
	for(; start <= vector.size()-1 ; start++ )
	{

		selection = start;
		for(int i = start ; i <= vector.size() - 1 ; i++ )
		{
			
			if(vector[i] < vector[selection])
			{
				selection=i;
			}
		}
		if(start != selection)
		{
		
			temp = vector[start] ;
			vector[start] = vector[selection] ;
			vector[selection] = temp ;
		}

	}		

}

template <class generic>
void insertion_sort (Vector<generic> & vector)
{
	generic temp;
	int  start = 0 ;
	
	
	for(; start <= vector.size()-1 ; start++ )
	{
	
		for(int i = start ; i >= 1 ; i-- )
		{
			if(vector[i] < vector[i-1])
			{
				temp = vector[i] ;
				vector[i] = vector[i-1] ;
				vector[i-1] = temp ;
			}
			else
			{
				i = 0 ;
			}
		}

	}		

}

template <class generic>
void quick_sort (Vector<generic> & vector)
{
	generic temp;
	unsigned int sltemp , srtemp;
	int  pivot = 0 ;
	stack<unsigned int> sl,sr;
	
	sl.push(0);
	sr.push(vector.size() - 1);
	
	while(!sl.empty())
	{
	
		if(sl.top()+1 == sr.top())
		{
			if(vector[sl.top()] > vector[sr.top()])
			{
				temp = vector[sl.top()] ;
				vector[sl.top()] = vector[sr.top()] ;
				vector[sr.top()] = temp ;
			}
			sl.pop();
			sr.pop();
		}
		else
		{
			pivot = sl.top();
			for(int i = pivot + 1 ; i <= sr.top() ; i++)
			{
				if( vector[i] > vector[pivot])
				{
					for(int j = i + 1;j <= sr.top(); j++)
					{
						if( vector[j] < vector[pivot])
						{
							temp = vector[i] ;
							vector[i] = vector[j] ;
							vector[j] = temp ;
						}
						if(j > sr.top())
						{
							i = sr.top();
						}
					}
				}
			}
			while(pivot < sr.top() && vector[pivot + 1] < vector[pivot] )
			{
				temp = vector[pivot] ;
				vector[pivot] = vector[pivot + 1] ;
				vector[pivot + 1] = temp ;
				pivot++;
			}
			sltemp = sl.top() ;
			srtemp = sr.top() ;
			sl.pop();
			sr.pop();	
			sl.push(sltemp) ;
			sr.push(pivot-1);
			if(!(sl.top() < sr.top()))
			{
				sl.pop();
				sr.pop();			
			}
			sl.push(pivot+1);
			sr.push(srtemp);
			if(!(sl.top() < sr.top()))
			{
				sl.pop();
				sr.pop();			
			}
		}
		
	}
	//OMG it worked the first time !!!!!!!!!!!!!!!
	
}

template <class generic>
void merge_sort (Vector<generic> & vector)
{
	generic temp;
	unsigned int size = 0 ;
	stack<unsigned int> sl,sr,ml,mr ;
	
	//makes up merge left and merge right stacks
	sl.push(0);
	sr.push(vector.size() - 1);
	while(!sl.empty())
	{
		ml.push(sl.top());
		mr.push(sr.top());
		sl.pop();
		sr.pop();
		sl.push(ml.top());
		sr.push((mr.top() - ml.top())/2) ;
		if(!(sl.top() < sr.top()))
		{
			sl.pop();
			sr.pop();			
		}
		sr.push(ml.top());
		sl.push(((mr.top() - ml.top())/2)+1) ;
		if(!(sl.top() < sr.top()))
		{
			sl.pop();
			sr.pop();			
		}	
	}
	
	//preformes merges
	while(!ml.empty())
	{

		size = ((mr.top()-ml.top())+1);
	
		for(; 1 < size ; size-- )
		{
	
			for(int i = ml.top() ; i + 1  < size ; i++ )
			{

				if(vector[i] > vector[i+1])
				{
					temp = vector[i] ;
					vector[i] = vector[i+1] ;
					vector[i+1] = temp ;
				}
			
			}
		}
		ml.pop();
		mr.pop();
	}

}


