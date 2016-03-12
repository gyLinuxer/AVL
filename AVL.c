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

int max(int a,int b)
{
    return a>b?a:b;
}
int abs(int a,int b)
{
    return a>b?a-b:b-a;
}
int get_bf(struct node * node)
{
     if(!node)
	return 0;

     return (!node->left?0:node->left->maxheight)-(!node->right?0:node->right->maxheight);
}
int get_max_height(struct node * node)
{
     if(!node)
	return 0;     

     int h_left = node->left?0:node->left->maxheight;
     int h_right= node->right?0:node->right->maxheight;
     return h_left > h_right ? h_left : h_right; 
} 
void insert_avl(struct node * node)
{
	struct node * next;
	struct node * parent;
	struct node * min_no_bf_node;
	struct node * min_rev_node = NULL;
	int cur_dir = 0;//current_direction 0:left 1:none 2:right
	int stop = 0 ,mstop = 0,max_height = 0 ;

	if (!tree_root){
	    tree_root = node;
	    return;
	}
	
	next = tree_root;
	min_no_bf_node = NULL;
	min_rev_node = NULL;

	if (node->dat < tree_root->dat)
	    cur_dir = 1;
	else
	    cur_dir = 2;

	while(!stop){
	    if (node->dat < next->dat){//insert it to left
		
                if(!min_rev_node && (cur_dir == 2))
			min_rev_node = next;
		}
	    	
		if(!next->left){
		    next->left = node;
		    node->parent = next;
		    node->maxheight = 0;
		    stop = 1;
		    //start modify the maxheight of probable parent nodes.
		    mstop = 0;
		}else
		    next = next->left;	

	    }else{//insert it to right

	       if(!min_rev_node && (cur_dir == 1))
			min_rev_node = next;

		if(!next->right){
		    stop = 1 ;
		    next->right = node;
		    node->parnet = next;		    
		    node->maxheight = 0; 		    
		}else	
		    next = next->right;	

	    }

	    parent = next->parent;
   	    while(parent && !mstop){
		parent = next->parent;
		parent->bf = get_bf(parent->left,parent->right);
		max_height =  get_max_height(parent);

		if(parent->maxheight!=max_height){
	 	   parent->maxheight = max_height;
	            
		    if(parent->bf > 1 || parent->bf<-1)
	      	        min_no_bf_node = parent;

		}else
	          mstop = 1;
	
		
	
			
	if(!min_no_bf_node) 
		return;
	
	if(cur_dir==1){//left tree no bf
	    if(!min_rev_node){//need to r reverse
		if(!min_no_bf_node->parent){//it is root node
		   tree_root = min_no_bf_node->left;
		   tree_root->parent=null;
		   min_no_bf_node->parent = tree_root;
		   min_no_bf_node->left = tree_root->right;
		   tree_root->right = min_no_bf_node;		   
		   tree_root->bf = get_bf(tree_root);
		    
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
