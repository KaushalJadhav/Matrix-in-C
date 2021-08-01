#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<stdbool.h>
#include <stdarg.h>
 
typedef int** mat_int;
typedef float** mat_float;
typedef double** mat_doub;
typedef void** mat_void;
typedef unsigned int** mat_uint;
typedef char** mat_char;
typedef unsigned char** mat_uchar;
typedef short int** mat_sint;
typedef unsigned short int** mat_usint;
typedef long int** mat_lint;
typedef unsigned long int** mat_ulint;
typedef long long int** mat_llint;
typedef unsigned long long int** mat_ullint;
typedef long double** mat_ldoub;
typedef bool** mat_bool;
typedef char*** mat_string;

#define declare_type(type) \
typedef type**

#define initialise(data_type)\
data_type**  

#define initialise_array(data_type)\
data_type*

#define create_space(m,n,data_type) \
(data_type**)malloc(m*sizeof(data_type*))

#define create_mat(m,n,type,mat_ptr)\
do{\
    mat_ptr=create_space(m,n,type);\
    if(mat_ptr==NULL){\
    perror("Malloc failed");\
    exit(EXIT_FAILURE);}\
    for(int i=0;i<n;i++) {\
    mat_ptr[i]=(type*) malloc (n*sizeof(type));\
    if(mat_ptr[i]==NULL){\
    perror("Malloc failed");\
    exit(EXIT_FAILURE);}\
    }\
}\
while(0)

#define create_sq_mat(n,type,mat_ptr) create_mat(n,n,type,mat_ptr)

#define fill_mat(m,n,type,mat_ptr,fill_value) ({\
for(int i=0;i<m;i++){\
for(int j=0;j<n;j++) mat_ptr[i][j]=(type)fill_value;\
}\
})

#define create_null_mat(m,n,type,mat_ptr) ({\
create_mat(m,n,type,mat_ptr);\
fill_mat(m,n,type,mat_ptr,0);\
})

#define print_mat(m,n,format,mat_ptr)({\
for(int i=0;i<m;i++){\
for(int j=0;j<n;j++) printf(format,*(*(mat_ptr+i)+j));\
printf("\n");}\
})

#define scan_mat(m,n,format,mat_ptr)({\
for(int i=0;i<m;i++){\
for(int j=0;j<n;j++) scanf(format,*(mat_ptr+i)+j);}\
})

#define create_Identity_mat(n,type,mat_ptr) ({\
create_null_mat(n,n,type,mat_ptr);\
for(int i=0;i<n;i++) mat_ptr[i][i]=1;\
})

#define destroy(mat_ptr)\
free(mat_ptr)

#define add_mat(mat1,mat2,result,m,n) ({\
for(int i=0;i<m;i++){\
for(int j=0;j<n;j++) result[i][j]=mat1[i][j]+mat2[i][j];\
}\
})

#define sub_mat(mat1,mat2,result,m,n) ({\
for(int i=0;i<m;i++){\
for(int j=0;j<n;j++) result[i][j]=mat1[i][j]-mat2[i][j];\
}\
})

#define create_array(n,type,a)\
do{\
    a=(type*)malloc(n*sizeof(type));\
    if(a==NULL){\
    perror("Malloc failed");\
    exit(EXIT_FAILURE);}\
}\
while(0)
