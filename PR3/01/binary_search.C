# include <iostream>
using namespace std;

/**
	@file binarysearch.cpp
	@brief Declaration and Implementation on C++ of the funtion "binary_search".
	@author Juan Diego M. Flores
	@date 06/25/2016
*/


/**
	  @brief Function to search object in to a container using Binary Search, this 
	  function has O(lg(n)) time complexity.
	  @param A Container, an Object that is going to be searched and 
	  limits to take part of search.
	  @returns Position in to container of object, if it was not found, funtion 
	  returns a code of error.
*/
template<class T, class Compare> int binary_search(const T* array, const T& object, int l, int r){

	if (l > r)
		return -1;
	else{
		int m = (l + r)/2;

		if (Compare()(object, array[m]))
			return binary_search<T,Compare>(array, object, l, m - 1);
		else if(Compare()(array[m], object))
			return binary_search<T,Compare>(array, object, m + 1, r);
		return(m);
	}
}

/**
	  @brief Function to search object in to a container using Binary Search, this 
	  function has O(lg(n)) time complexity.
	  @param A Container, an Object that is going to be searched and 
	  limits to take part of search.
	  @returns Position in to container of object, if it was not found, funtion 
	  returns a code of error.
*/
template<class T, class Compare> int binary_search(const T* array, const T &object, int l, int r, Compare funtion){
	if (l > r)
		return -1;
	else{
		
		int m =(l + r) / 2;

		if (funtion(object, array[m]))
			return binary_search<T,Compare>(array, object, l, m - 1, funtion);
		else if(funtion(array[m], object))
			return binary_search<T,Compare>(array, object, m + 1, r, funtion);

		return m;
	}

}

/*
	@brief .
*/
template<class T> class Criteria{
	public:
		bool operator() (const T &A, const T &B){
			return(A < B);
		}
};

/**
	@brief Funtion Main.
*/
int main()
{
	int array [] = {1, 3, 5, 21, 24, 32, 41, 44, 46, 50};
	cout << binary_search< int, Criteria<int> >(array, 5, 0, 9) << '\n';

	cout << binary_search(array, 50, 0, 9,[](const int  &A, const int &B){return(A<B);}) << '\n';
return(0);
}