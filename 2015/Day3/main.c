#include "stdlib.h"
#include <stdio.h>
#include <string.h>
#include "assert.h"
#define capacity 5000
#define SIZE 10007 // Prime number for better distribution

int cantorPairing(int x,int y){
	return (x+y)*(x+y+1)/2+y;
}

typedef struct Node{
	int val[2];
	struct Node* next;
}Node;

typedef struct HashSet{
	int size;
	Node** table;
} hashSet;

//hashSet* createHashSet(int size){
//	hashSet* set = (hashSet*)malloc(sizeof(hashSet));
//	if (!set){
//		printf("Fail to Create the set");
//		exit(EXIT_FAILURE);
//	}
//
//	set->size= size;
//	set->table = (Node**)calloc(sizeof(Node*),size);
//	for (size_t i = 0; i < size; ++i) {
//		set->table[i] = NULL;
//	}
//	printf("size of init array is %zu \n",sizeof(set->table)/sizeof(set->table[0]));
//	return set;
//}

void grow(hashSet* hs,int size){
	Node** Newtable = (Node**)calloc(sizeof(Node*),size*2);
	if (Newtable == NULL){
		printf("Memory allocation failed for the new table.\n");
		exit(EXIT_FAILURE);
	}
	for(int i=0;i<sizeof(hs->table);i++){
		Newtable[i] = hs->table[i];
	}
	free(hs->table);
	hs->table = Newtable;
	hs->size = size;
	printf("the size of new array is %lu \n",sizeof(Newtable));
}

void insert(hashSet* set, Node* node) {
    int index = cantorPairing(node->val[0],node->val[1]);

    if (!set->table[index]) {
        set->table[index] =node;
    } else {
        Node* temp = set->table[index];

        // Check for duplicate elements
        while (temp->next && temp->next->val[0]==node->val[0]|| temp->next->val[1]==node->val[1])
            temp = temp->next;

        temp->next = node;
    }
    set->size++;
}
void destroy(hashSet*hs){
	free(hs->table);
	free(hs);
}

Node* item(int val[2]){
	Node* N = (Node*)malloc(sizeof(Node));
	memcpy( N->val,val, sizeof(int)*2);
	return N;
};

void testHashSet() {
	// Create a hash set
	//
	hashSet* hs= (hashSet*)malloc(sizeof(hashSet));
	hs->table = (Node**)malloc(SIZE * sizeof(Node*));
	hs->size = 0;

	// Create a sample node
	int sampleValue[2] = {42, 99};
	Node* sampleNode = item(sampleValue);

	// Insert the sample node
	insert(hs, sampleNode);

	// Vertablethe node is in the hash set
	int idx = cantorPairing(sampleValue[0], sampleValue[1]);
	assert(hs->table[idx] == sampleNode);
	// Clean up
	// (Don't forget to free memory when done with the hash set)
	destroy(hs);
	printf("Unit test passed!\n");
}

int main(){
	char up = '^';
	char down= 'v';
	char  left= '<';
	char right= '>';
	FILE* fp = fopen("i.txt", "r");
	fseek(fp, 0l, SEEK_END);
	long l = ftell(fp);
	rewind(fp);
	int**cords = malloc(sizeof(int)*l);
	int idx =0;
	char ch;
	while ((ch=fgetc(fp))!=EOF){
			
	}
	return 0;
}
