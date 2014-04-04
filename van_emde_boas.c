#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct van_emde_boas VEB;

struct van_emde_boas{
	int u;					/*Stores the actual number of elements in the given structure*/
	int *min, *max;			/*Stores the min and max numbers */
	VEB *summary;			/*Another summary section which has exact structure of VEB and stores the summary of the descendant tree*/
	VEB **cluster;			/*Stores the actual data*/
};

int high( int x, int u);
int low( int x, int u);
int index_func(int x, int y, int u);

void VEB_tree_insert( VEB *, int x);
void VEB_empty_tree_insert( VEB *v, int x);
int *VEB_tree_minimum( VEB *v);
int *VEB_tree_maximum( VEB *v);
VEB *create_VEB_tree(VEB *v, int u);

int main( void ){

	int x;
	printf("Enter the size of the tree in the power of 2 \n");
	scanf("%d", &x);

	/*Checks whether number is power of 2 or not*/
	if( !(x && (! ( x& (x-1 ) ))) ){
		printf("Please enter the number in the power of 2\n");
		exit(0);
	}
	

	return 0;
}

VEB *create_VEB_tree(VEB *v, int u){
	if(u == 0 || u< 0)
		return NULL;
	int sqrt_root_of_u = sqrt(u);
	v -> u = u;
	v -> min = NULL;
	v -> max = NULL;

	if(u != 2){
		int i;
		v -> summary = (VEB*)malloc(sizeof (VEB) * sqrt_root_of_u) ;
		v -> cluster = (VEB**)malloc(sizeof (VEB*) * sqrt_root_of_u);
	
		for(i =0; i<  sqrt_root_of_u; ++i)
			create_VEB_tree( v-> cluster[i], u/ sqrt_root_of_u);

		create_VEB_tree( v -> summary, sqrt_root_of_u );
		//create_VEB_tree( v -> cluster, u/2);
	}
	else{
		v -> summary = NULL;
		v -> cluster = NULL;
	}
	return NULL;
}

void VEB_tree_insert(VEB *v, int x){
	if( v -> min == NULL)
		VEB_empty_tree_insert(v, x);

	else if( x < *(v -> min)){
		int temp = x;
		x = temp;
		*(v -> min) = x;

		if( v -> u > 2){
			if( VEB_tree_minimum(v) == NULL){
				VEB_tree_insert( v -> summary, high( x, v -> u));
				VEB_empty_tree_insert( v -> cluster[ high( x, v -> u) ], low(x, v -> u));
			}
			else
				VEB_tree_insert( v -> cluster[high ( x, v ->u)], low( x, v -> u));
		}
		if( x > (*v-> max))
			*(v -> max) = x;
	}
}

void VEB_empty_tree_insert(VEB *v, int x){
	*(v -> min) = x;
	*(v -> max) = x;
}

int *VEB_tree_minimum( VEB *v){
	return v->min;
}


int *VEB_tree_maximum( VEB *v){
	return v->max;
}

int high(int x, int u){
	return  x/sqrt(u );
}

int low(int x, int u){
	return  (x % (int)sqrt(u) );
}

int index_func(int x, int y, int u){
	return ( (x * sqrt(u)) + y);
}

