#include <stdio.h>
#include <malloc.h>

struct node{
	struct node * left;
	struct node * right;
	struct node * parent;
	int 	      maxheight;
	int 	      dat;
	int 	      bf;
};
struct node * tree_root = NULL; 




void insert_avl(struct node * node)
{
	struct node * next;
	struct node * parent;
	struct node * min_no_bf_node;
	struct node * min_rev_node = NULL;
	int cur_dir = 0;//current_direction 0:left 1:none 2:right
	int stop = 0;
	if (!tree_root){
	    tree_root = node;
	    return;
	}
	
	next = tree_root;
	min_no_bf_node = NULL;
	while(!stop){
	
	    if (node->dat < next->dat){//insert it to left
		
	  	if(!cur_dir){
		   cur_dir = 1;
		}else{
		   if(!min_rev_node && (cur_dir == 2))
			min_rev_node = next;
		}
	    	
		if (++next->bf >1){
			min_no_bf_node = next;
		}
		
		if(!next->left){
		    next->left = node;
		    node->parent = next;

		    stop = 1;
		}else
		    next = next->left;	

	    }else{//insert it to right

		if(!cur_dir){
		   cur_dir = 2;
		}else{
		   if(!min_rev_node && (cur_dir == 1))
			min_rev_node = next;
		}

		if (--next->bf <-1){
			min_no_bf_node = next;
		}

		if(!next->right){
		    stop = 1 ;
		    next->right = node;
		    node->parnet = next;		    
		   		    
		}else	
		    next = next->right;	
	    }
	}
	
			
	if(!min_no_bf_node) 
		return;
	
	if(cur_dir==1){//left tree no bf
	    if(!min_rev_node){//need to R reverse
		if(!min_no_bf_node->parent){//it is root node
		   tree_root = min_no_bf_node->left;
		   tree_root->parent=null;
		   min_no_bf_node->parent = min_no_bf_node->left;
		   mint_no_bf_node->left=NULL; 	    
		   
		}else{
		
		}	
	    }else{//need to LR reverse
	
	    }	
		
	}else//right tree no bf
	{
	   if(!min_rev_node){//need to L reverse
		if(next)	
	   }else{//need to RL reverse
		
	   }
	
	}	
	
}


void main()
{
	char * t = (char*)malloc(10);
	int i=0;
	
	for (i=0;i<10;i++){
	   t[i] = 'A' + i;
	}	

	puts(t);
}
