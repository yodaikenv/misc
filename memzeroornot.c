#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define ASIZE 24097
#define COUNT 10000000
void fakeit(int *, int);
int f(int x){
	int A[ASIZE];
#ifdef MEMSET
	memset((char *)A, 0, ASIZE* sizeof(int));
#endif
	fakeit(&A[0],x);
}


int main(){
	int i;
	for(i=0; i < COUNT; i++)f(i);
}

