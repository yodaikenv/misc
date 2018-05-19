/* (c) Victor Yodaiken 
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <limits.h>
double timenow()
{
    struct timespec tp;
    clock_gettime(CLOCK_REALTIME, &tp);
    return ((double) tp.tv_sec * 1000000.0) +
	((double) tp.tv_nsec) / 1000.0;
}

#define COUNT 100000
#define PSIZE 10000
float x[PSIZE];

float * y(int index){ return &x[index]; }
void floop(int n, float P[], float v){
	for(int i=0; i < n; i++) P[i]= v;
}
void ufloop(int n, float P[], float v){
	for(unsigned int i=0; i < (unsigned)n; i++) P[i]= v;
}
void xloop(int n,float v){
	for(int i=0; i < n; i++) *y(i)= v;
}
void mfloop(int n, float P[],float v){
	memset(P,0,sizeof(float)*n);
}

#include <stdlib.h>

int main(int argc, char **argv)
{
    double t;
    int repeat = COUNT, r = COUNT;
    float z;
    int i = 0;

    if (argc > 1)
	r= repeat = (atoi(argv[1]) > 0 ? atoi(argv[1]) : 1);

	t = timenow();
    while (r--) {
	z = random();
	floop(PSIZE,x,z);
    }
	t = timenow() - t;
	printf("floop %ld \n", (long)t);

	t = timenow();
    r = repeat;
    while (r--) {
	z = random();
	ufloop(PSIZE,x,z);
    }
	t = timenow() - t;
	printf("ufloop %ld \n", (long)t);

	t = timenow();
    r = repeat;
    while (r--) {
	z = random();
	xloop(PSIZE,z);
    }
	t = timenow() - t;
	printf("xloop %ld \n", (long)t);

    r = repeat;
    while (r--) {
	z = random();
	memset(x,0,sizeof(float)*PSIZE);
    }
	t = timenow() - t;
	printf("mfloop %ld \n", (long)t);


}

