
#include <iostream>
#include<string.h>
#include<malloc.h>

int length(struct transaction*);

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen);

struct transaction {
	int amount;
	char date[11];
	char description[20];
}A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } },
	B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
struct elems{
	int year;
	int mon;
	int day;
	int pos;
};

void main(){
	
	sortedArraysCommonElements(A,3, B,3);
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	int len1, len2;
	struct transaction *first, *second;
	int i, j, k, len[2];
	char temp[10];



	if (A == NULL || B == NULL)
		return NULL;
	else{

		len[0] = length(A);
		len[1] = length(B);

		for (i = 0; i < ALen; i++){
			for (j = 0; j <= ALen - i; j++){
				if (A[j].date > A[j + 1].date){
					strcpy(temp ,A[j].date);
					strcpy(A[j].date, A[j + 1].date);
					strcpy(A[j + 1].date, temp);
				}
			}
		}
		
	}
}


int length(struct transaction *temp){
	return sizeof(temp) / sizeof(struct transaction);
}