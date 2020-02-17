#include <stdio.h>
#include "vector.h"

void CreateTest1(void);
void CreateTest2(void);
void CreateTest3(void);
void CreateTest4(void);

void DestroyTest1(void);
void DestroyTest2(void);

void AddTest1(void);
void AddTest2(void);
void AddTest3(void);
void AddTest4(void);
void AddTest5(void);

void DeleteTest1(void);
void DeleteTest2(void);
void DeleteTest3(void);
void DeleteTest4(void);

void GetTest1(void);
void GetTest2(void);
void GetTest3(void);

void SetTest1(void);
void SetTest2(void);
void SetTest3(void);

void VectorSizeTest1(void);
void VectorSizeTest2(void);

void DataChangeTo1(int *_item);

int main(){

    CreateTest1();
	CreateTest2();
	CreateTest3();
	CreateTest4();

    DestroyTest1();
	DestroyTest2();

    AddTest1();
	AddTest2();
	AddTest3();
	AddTest4();

    DeleteTest1();
	DeleteTest2();
	DeleteTest3();
	DeleteTest4();

    GetTest1();
	GetTest2();
	GetTest3();

    SetTest1();
	SetTest2();
	SetTest3();

    VectorSizeTest1();
	VectorSizeTest2();
    
    return 1;
}

void CreateTest1(void){
	Vector *ptr;

	/* test if vector was created with good parameters*/
	ptr =VectorCreate(5 , 5);
	if (ptr != NULL){
		printf("status of creation is: passed \n");
	}
	else{
		printf("status of creation is: failed \n");
	}
	VectorDestroy(&ptr, NULL);
}

void CreateTest2(void){
	Vector *ptr;
	/* test if input wrong size and block size both '0' */
	ptr =VectorCreate(0 , 0);
	if (ptr == NULL){
		printf("status of wrong size and block size both '0' is: passed \n");
	}
	else{
		printf("status of wrong size and block size both '0' is: failed \n");

	}
	VectorDestroy(&ptr,NULL);
}

void CreateTest3(void){
	Vector *ptr1, *ptr2;
	/* test if input size or blockSize  are '0' */
	ptr1 = VectorCreate(0, 5);
	ptr2 = VectorCreate(5, 0);
	if (ptr1!= NULL && ptr2 != NULL ){
		printf("status test if input size or blockSize both '0' is: passed \n");
	}
	else{
		printf("status test if input size or blockSize both '0' is: failed \n");
	}
	VectorDestroy(&ptr1, NULL);
	VectorDestroy(&ptr2, NULL);

}

void CreateTest4(void){
	Vector *ptr;
	/* test if input size is '-1' */
	ptr = VectorCreate(-1, 5);
	if (ptr == NULL){
		printf("status  test if input size is '-1': passed \n\n");
	}
	else{
		printf("status test if input size is '-1': failed \n\n");

	}
	VectorDestroy(&ptr, NULL);
}

void DestroyTest1(void){
	VectorDestroy(NULL, NULL);
	printf("status of destroy with NULL: passed\n");
}

void DestroyTest2(void){
	Vector *ptr;
	ptr =VectorCreate(5 , 5);
	VectorDestroy(&ptr, NULL);
    if(ptr == NULL){
        printf("status of regular destroy is : passed\n\n");
    }
}


void DataChangeTo1(int *_item){
    *_item = 1;
}




void AddTest1(void){
	Vector *ptr;
	int numOfElements;
    int num1 = 3, num2 = 2;
	/*check if regular insert is working */
	ptr =VectorCreate(3 , 3);
	VectorAppend(ptr, &num1);
	VectorAppend(ptr, &num2);
	numOfElements = VectorSize(ptr);
	if (VECTOR_SUCCESS == VectorAppend(ptr, &num1) && numOfElements == 2){
		printf("status of regular insertion: passed \n");
	}
	else{
		printf("status of regular insertion: not passed \n");
	}
	VectorDestroy(&ptr, NULL);
}

void AddTest2(void){
	Vector *ptr;
	int vecSize;
    int num1 = 3, num2 = 2;
	ptr =VectorCreate(0 , 12);
	VectorAppend(ptr, &num1);
	vecSize = VectorCapacity(ptr);
	if (VECTOR_SUCCESS == VectorAppend(ptr, &num2) && vecSize == 12){
			printf("status realock funk : passed \n");
	}
	else{
		printf("status realock funk : failed\n");
	}
	VectorDestroy(&ptr, NULL);
}

void AddTest3(void){
	Vector *ptr;
    int num1 = 1;
	/*check 'ERR_NOT_INITIALIZED' error */ 
	ptr =VectorCreate(2 , 2);
	if (VectorAppend(NULL, &num1) == VECTOR_UNITIALIZED_ERROR){
			printf("status 'ERR_NOT_INITIALIZED' error: passed \n");
	}
	else{
		printf("status 'ERR_NOT_INITIALIZED' error: failed \n");
	}
	VectorDestroy(&ptr, NULL);
}

void AddTest4(void){
	Vector *ptr;
    int num1 = 3, num2 = 2;
	ptr =VectorCreate(1 , 0);
	VectorAppend(ptr, &num1);
	if (VectorAppend(ptr, &num2) == VECTOR_INDEX_OUT_OF_BOUNDS_ERROR){
			printf("status 'OVER_FLOW' error: passed \n");
	}
	else{
		printf("status 'OVER_FLOW' error: failed \n");
	}
	VectorDestroy(&ptr, NULL);
}


void DeleteTest1(void){
	Vector *ptr;
	int num1 = 2, num2 = 5;
    int *returnPtr;
	/*check regular deleting*/
	ptr =VectorCreate(2 , 1);
	VectorAppend(ptr, (void*)&num1);
	VectorAppend(ptr, (void*)&num2);
	VectorRemove(ptr, (void*)&returnPtr);
	if (VectorRemove(ptr, (void*)&returnPtr) == VECTOR_SUCCESS && *returnPtr == 2){
			printf("status of regular deleting: passed \n");
	}
	else{
		printf("status of regular deleting: fail \n");
	}
	VectorDestroy(&ptr, NULL);
}

void DeleteTest2(void){
	Vector *ptr;
	int data = 2, size, *reData;

	/*check regular deleting*/
	ptr =VectorCreate(1 , 1);	
	VectorAppend(ptr, (void*)&data );	
	VectorAppend(ptr, (void*)&data );	
	VectorAppend(ptr, (void*)&data );
	VectorAppend(ptr, (void*)&data );
	VectorAppend(ptr, (void*)&data );
	VectorRemove(ptr, (void*)&reData);
	VectorRemove(ptr, (void*)&reData);
	VectorRemove(ptr, (void*)&reData);
	VectorRemove(ptr, (void*)&reData);
    size = VectorCapacity(ptr);
	if (VectorRemove(ptr, (void*)&reData) == VECTOR_SUCCESS && size == 2){
			printf("status of deleting with reallocating: passed \n");
	}
	else{
		printf("status of regular deleting reallocating: failed \n");
	}
	VectorDestroy(&ptr, NULL);
}

void DeleteTest3(void){
	Vector *ptr;
	int reData;
	ptr =VectorCreate(2 , 1);
	if (VectorRemove(NULL, (void*)&reData) == VECTOR_UNITIALIZED_ERROR && VectorRemove(ptr, NULL) == VECTOR_UNITIALIZED_ERROR){
			printf("status 'ERR_NOT_INITIALIZED' error: passed \n");
	}
	else{
		printf("status 'ERR_NOT_INITIALIZED' error: failed \n");
	}
	VectorDestroy(&ptr, NULL);
}

void DeleteTest4(void){
	Vector *ptr;
	int *reData;
	/*check ERR_UNDER_FLOW' error */ 
	ptr =VectorCreate(2 , 1);
	if (VectorRemove(ptr, (void*)&reData) == VECTOR_INDEX_OUT_OF_BOUNDS_ERROR){
			printf("status 'ERR_UNDER_FLOW' error: passed \n\n");
	}
	else{
		printf("status 'ERR_UNDER_FLOW' error: failed \n\n");
	}
	VectorDestroy(&ptr, NULL);
}

void GetTest1(void){
	Vector *ptr;
    int data = 565;
	int *reData = NULL;

	/*check regular work*/
	ptr =VectorCreate(2 , 2);
	VectorAppend(ptr, (void*)&data);
	if (VectorGet(ptr, 0 , (void**)&reData) == VECTOR_SUCCESS && *reData == data){
			printf("status of regular work: passed \n");
	}
	else{
		printf("status of regular work: failed \n");
	}
	VectorDestroy(&ptr, NULL);

}

void GetTest2(void){
	Vector *ptr;
	int *reData;
	ptr =VectorCreate(2 , 2);
	if (VectorGet(NULL, 1,(void*)&reData) == VECTOR_UNITIALIZED_ERROR && VectorGet(ptr, 2, NULL) == VECTOR_UNITIALIZED_ERROR){
			printf("status 'ERR_NOT_INITIALIZED' error: passed \n");
	}
	else{
		printf("status 'ERR_NOT_INITIALIZED' error: failed \n");
	}
	VectorDestroy(&ptr, NULL);

}

void GetTest3(void){
    int data = 535;
	Vector *ptr;
	int *reData;
	/*check ERR_WRONG_INDEX work*/
	ptr =VectorCreate(2 , 2);
	VectorAppend(ptr, (void*)&data);

	if (VectorGet(ptr, 5,  (void*)&reData) == VECTOR_INDEX_OUT_OF_BOUNDS_ERROR){
			printf("status of ERR_WRONG_INDEX work: passed \n\n");
	}
	else{
		printf("status of ERR_WRONG_INDEX work: failed \n\n");
	}
	VectorDestroy(&ptr, NULL);
}

void SetTest1(void){
	Vector *ptr;
    int data = 565, data2 = 5;
	int *reData;
	ptr =VectorCreate(2 , 2);
	VectorAppend(ptr, (void*)&data);
	VectorSet(ptr, 0, (void*)&data2);
	if (VectorGet(ptr, 0 , (void*)&reData) == VECTOR_SUCCESS && *reData == 5){
			printf("status of regular work: passed \n");
	}
	else{
		printf("status of regular work: failed \n");
	}
	VectorDestroy(&ptr, NULL);

}

void SetTest2(void){
	Vector *ptr;
	int reData;
	ptr =VectorCreate(2 , 2);
	if (VectorGet(NULL, 0, (void*)&reData) == VECTOR_UNITIALIZED_ERROR && VectorGet(ptr, 5, NULL) == VECTOR_UNITIALIZED_ERROR){
			printf("status 'ERR_NOT_INITIALIZED' error: passed \n");
	}
	else{
		printf("status 'ERR_NOT_INITIALIZED' error: failed \n");
	}
	VectorDestroy(&ptr, NULL);


}

void SetTest3(void){
	Vector *ptr;
    int data = 565;
	/*check ERR_WRONG_INDEX work*/
	ptr =VectorCreate(2 , 2);
	VectorAppend(ptr, (void*)&data);
	if (VectorSet(ptr, 6, (void*)&data) == VECTOR_INDEX_OUT_OF_BOUNDS_ERROR){
			printf("status of ERR_WRONG_INDEX work: passed \n\n");
	}
	else{
		printf("status of ERR_WRONG_INDEX work: failed \n\n");
	}
	VectorDestroy(&ptr, NULL);
}

void VectorSizeTest1(void){
	Vector *ptr;
	/*check ERR_NOT_INITIALIZED' error */ 
	ptr =VectorCreate(2 , 2);
	if (VectorSize(NULL) == 0){
			printf("status 'ERR_NOT_INITIALIZED' error: passed \n");
	}
	else{
		printf("status 'ERR_NOT_INITIALIZED' error: not passed \n");
	}
	VectorDestroy(&ptr, NULL);
}

void VectorSizeTest2(void){
	Vector *ptr;
    int data1 = 344, data2 = 231;
	/*check regular work*/
	ptr =VectorCreate(2 , 2);
	VectorAppend(ptr, (void*)&data1);
	VectorAppend(ptr, (void*)&data2);
	if (VectorSize(ptr) == 2){
			printf("status of regular work: passed \n");
	}
	else{
		printf("status of regular work: not passed \n");
	}
	VectorDestroy(&ptr, NULL);

}