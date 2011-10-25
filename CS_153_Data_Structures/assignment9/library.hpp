//////////////////////////////////////////////////////////////////////
/// @file library.hpp
/// @author James Anderson  CS 153 Section A
/// @brief  Template implemintation  file for vector class for assignment 9
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
