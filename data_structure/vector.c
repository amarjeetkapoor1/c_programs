#include"vector.h"

//This function inserts an element at the back of the vector
void push_back(struct vector *a, struct string i){
	if(a->N-a->n>0){
		a->p[a->n]=i;
	}
	else{
		a->p=(struct string*)realloc(a->p,2*a->N*sizeof(struct string));
		a->p[a->n]=i;
		a->N=2*a->N;
	}
	a->n++;
}


//This function prints every element in the vector structure
void print_vector(struct vector p){
	int i;
	for(i=0;i<p.n;i++){
		print(p.p[i]);
		printf("\n");
	}
}

//This function initializes the vector struct
void init_vector(struct vector *x){
	x->N=1,x->n=0;
	x->p=(struct string*)malloc(sizeof(struct string));
}
