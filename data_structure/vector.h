/*!
 *	\file header.h 
 *
 *  \brief It contain defination for vector like that in c++.    
 *
 *      
 *	compiler g++
 *
 *  \author amarjeet singh kapoor
 *      
 */
#ifndef _VECTOR_H_
#define _VECTOR_H_
#include"amar_string.h"

//This serves the purpose of very basic vector
struct vector{
		struct string *p;
	unsigned int N,n;
};

//This function inserts an element at the back of the vector
void push_back(struct vector *, struct string);


//This function prints every element in the vector structure
void print_vector(struct vector);

//This function initializes the vector struct
void init_vector(struct vector *);

#endif
