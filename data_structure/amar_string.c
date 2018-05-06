#include"amar_string.h"

//This function concatenates a single character to a string
void insert(struct string *p ,char i){
	if(p->N-p->n>0){
		p->x[p->n]=i;
		
	}
	else{
		p->x=(char*)realloc(p->x,2*p->N*sizeof(char));
		p->x[p->n]=i;
		p->N=2*p->N;
	}
	p->n++;
}

//This function prints the struct string created above
void print(struct string p){
	int i;
	for(i=0;i<p.n;i++){
		printf("%c",p.x[i]);
	}
}

//This function checks if two string structs are equal
int equality(struct string x, struct string y)
{
	//unequal is 1;
	if(x.n!=y.n)
		return 1;
	int i;
	for(i=0;i<x.n;i++)
	{
		if(x.x[i]!=y.x[i])
			return 1;
	}
	return 0;
}

//This function builds a string one character at a time from the terminal
char* getstring(struct string *x,char *y){

	char c;
	x->x=(char*)malloc(sizeof(char));
	while(1){
		c = y[i];
		i++;
		if(c=='\n' || c=='\r' ){
			break;
		}
		insert(x,c);
	}

}

//This function concatenates string to another string
void insert_string(struct string *x, struct string *y){

	char c;
	int i;
	for(i=0;i< y->n;i++){
		insert(x,y->x[i]);
	}
	//print(*x);
	
}

//This fucntion assigns a string to another string
void equal(struct string *x, struct string *y){

	char c;
	x->x=(char*)malloc(sizeof(char));
	int i;
	for(i=0;i< y->n;i++){
		insert(x,y->x[i]);
	}
	//print(*x);
	
}

//This function initializes the string struct
void initialse(struct string *x){
	x->N=1,x->n=0;
	x->x=(char*)malloc(sizeof(char));
}
