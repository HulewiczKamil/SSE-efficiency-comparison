#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

/* ---Used Data---
https://software.intel.com/content/www/us/en/develop/articles/introduction-to-intel-advanced-vector-extensions.html
https://en.wikipedia.org/wiki/Flynn%27s_taxonomy

*/
#define TAB_SIZE 8192
#define REPETITION 100

clock_t timeOfStart, timeOfEnd;
double timePassed;

// Initialising the struct of 128-bit vector
typedef struct{
    float vecOne;
    float vecTwo;
    float vecThree;
    float vecFour;
}numericVector;

//filling vectors with randomly generated data
void generaetNumber(numericVector *dataSet);

//printing the vector
void printVector(numericVector *dataSet);

//SIMD operations - returning time passed
double additionSIMD(numericVector *setA ,numericVector* setB, int numbers);
double subtractionSIMD(numericVector* setA ,numericVector* setB, int numbers);
double multiplicationSIMD(numericVector* setA ,numericVector* setB, int numbers);
double divisionSIMD(numericVector* setA ,numericVector* setB, int numbers);

//SIMD operations - returning results
numericVector additionSIMDResult(numericVector *setA ,numericVector *setB, int numbers);
numericVector subtractionSIMDResult(numericVector* setA ,numericVector* setB, int numbers);
numericVector multiplicationSIMDResult(numericVector* setA ,numericVector* setB, int numbers);
numericVector divisionSIMDResult(numericVector* setA ,numericVector* setB, int numbers);

//SISD operations - returning time passed
double additionSISD(float *a, float *b, int numbers);
double subtractionSISD(float *a, float *b, int numbers);
double multiplicationSISD(float *a, float *b, int numbers);
double divisionSISD(float *a, float *b, int numbers);

//SISD operations - returning results
float additionSISDResult(float *a, float *b, int numbers);
float subtractionSISDResult(float *a, float *b, int numbers);
float multiplicationSISDResult(float *a, float *b, int numbers);
float divisionSISDResult(float *a, float *b, int numbers);


int main(){
    double summaryAdditionTime;
    double summarySubTime;
    double summaryMultTime;
    double summartDivTime;

    srand(time(NULL));
    numericVector setA[TAB_SIZE];
    numericVector setB[TAB_SIZE];
    generaetNumber(setA);
    generaetNumber(setB);
    printVector(setA);
    printVector(setB);
    double x = additionSIMD(setA, setB, 4096);
    printf("Czas trwania %lf\n",x);
    printf("OiAK - Laboratorium 4\n");
    printf("Prowadzacy: mgr. Tomasz Serafin\n");


    return 0;
}

void generaetNumber(numericVector *dataSet){
    for(int i = 0; i<TAB_SIZE; ++i){
    dataSet[i].vecOne = ((float)(rand()%100000))/((float)(rand()%100000));
    dataSet[i].vecTwo = ((float)(rand()%100000))/((float)(rand()%100000));
    dataSet[i].vecThree = ((float)(rand()%100000))/((float)(rand()%100000));
    dataSet[i].vecFour = ((float)(rand()%100000))/((float)(rand()%100000));
    }
}

 void printVector(numericVector *dataSet){
    for(int i = 0; i<TAB_SIZE; ++i){
        printf("%lf, %lf, %lf, %lf, numer iteracji %d\n",
        dataSet[i].vecOne, 
        dataSet[i].vecTwo, 
        dataSet[i].vecThree, 
        dataSet[i].vecFour, i);
    }
}
//SIMD operations - returning time passed
double additionSIMD(numericVector* setA ,numericVector* setB, int numbers){
    numericVector result;
    timePassed = 0;

    for(int i=0; i<numbers; ++i){
    timeOfStart = clock();

    asm(
        "movq %1, %%rax\n"
        "movups (%%rax), %%xmm0\n"
        "movq %2, %%rax\n"
        "movups (%%rax), %%xmm1\n"
        "addps %%xmm1, %%xmm0\n"
        "movups %%xmm0, %0\n"
        :"=g"(result)
        :"g"(setA), "g"(setB)
        :"rax"
    );

    timeOfEnd = clock();
    timePassed += (double)(timeOfEnd - timeOfStart);
    }
    return timePassed;
}
double subtractionSIMD(numericVector* setA ,numericVector* setB, int numbers){

}
double multiplicationSIMD(numericVector* setA ,numericVector* setB, int numbers){

}
double divisionSIMD(numericVector* setA ,numericVector *setB, int numbers){

}

//SIMD operations - returning results
numericVector additionSIMDResult(numericVector *setA ,numericVector* setB, int numbers){

}
numericVector subtractionSIMDResult(numericVector* setA ,numericVector* setB, int numbers){

}
numericVector multiplicationSIMDResult(numericVector *setA ,numericVector* setB, int numbers){

}
numericVector divisionSIMDResult(numericVector* setA ,numericVector* setB, int numbers){

}

//SISD operations - returning time passed
double additionSISD(float *a, float *b, int numbers){

}
double subtractionSISD(float *a, float *b, int numbers){

}
double multiplicationSISD(float *a, float *b, int numbers){

}
double divisionSISD(float *a, float *b, int numbers){

}

//SISD operations - returning results
float additionSISDResult(float *a, float *b, int numbers){

}
float subtractionSISDResult(float *a, float *b, int numbers){

}
float multiplicationSISDResult(float *a, float *b, int numbers){

}
float divisionSISDResult(float *a, float *b, int numbers){

}