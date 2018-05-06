#include<stdlib.h>
#include<stdio.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* find(int data,struct node*root){
	if(root==NULL){
		return root;
	}
	if(data<root->data){
		root=find(data,root->left);

	}
	else if(data>root->data){
		root=find(data,root->right);
		
	}
	else if(data==root->data){
	    
    }
    return root;
}

struct node* insert(int data, struct node*root){	
	if(root==NULL){
		struct node*temp= (struct node*)malloc(sizeof(struct node));
		temp->data=data;
		temp->right=NULL;
		temp->left=NULL;
		root=temp;

	}
	if(data<root->data){
		root->left=insert(data,root->left);

	}
	else if(data>root->data){
		root->right=insert(data,root->right);
	}
	return root;
	
}

int main(){

}




