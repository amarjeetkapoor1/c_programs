/*!
 *	\file header.h 
 *
 *  \brief It contain defination for dynamic string like that in c++.    
 *
 *      
 *	compiler g++
 *
 *  \author amarjeet singh kapoor
 *      
 */
#ifndef _AMAR_STRING_H_
#define _AMAR_STRING_H_

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//This serves the purpose of very basic string.
struct string{
	char *x;
	int N,n;
};


//This function concatenates a single character to a string
void insert(struct string * ,char );

//This function prints the struct string created above
void print(struct string );

//This function checks if two string structs are equal
int equality(struct string , struct string );

//This function builds a string one character at a time from the terminal
char* getstring(struct string *);

//This function concatenates string to another string
void insert_string(struct string *, struct string *);
//This fucntion assigns a string to another string
void equal(struct string *, struct string *);
//This function initializes the string struct
void initialse(struct string *);


#endif
