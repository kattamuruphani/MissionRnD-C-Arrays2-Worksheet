/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<malloc.h>
#include<stdlib.h>
#include<string.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
struct elems{
	int date_pos[4];
};


int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{
	int len1, len2, inc;
	struct elems *first, *second;
	int i, j, k;
	
	struct transaction *common_elems;
	
	if (Arr == NULL || len==0)
		return NULL;
	else{
		
		
		first = (struct elems*)malloc(sizeof(struct elems)*len);
		
		for (i = 0; i < len; i++){
			k = strlen(Arr[i].date) - 1;
			inc = 1;
			first[i].date_pos[0] = 0;
			for (j = k; j >= k - 3; j--){
				first[i].date_pos[0] += (Arr[i].date[j] - 48)* inc;
				inc *= 10;
			}
			k -= 4;
			first[i].date_pos[1] = 0;
			inc = 1;
			for (j -= 1; j >= k - 2; j--){
				first[i].date_pos[1] += (Arr[i].date[j] - 48)*inc;
				inc *= 10;
			}
			k -= 3;
			first[i].date_pos[2] = 0;
			inc = 1;
			for (j = j - 1; j >= k - 2; j--){
				first[i].date_pos[2] += (Arr[i].date[j] - 48)*inc;
				inc *= 10;
			}
			first[i].date_pos[3] = i;
		}


		
		second = (struct elems*)malloc(sizeof(struct elems));
			k = strlen(date) - 1;
			inc = 1;
			second[0].date_pos[0] = 0;
			for (j = k; j >= k - 3; j--){
				second[0].date_pos[0] += (date[j] - 48)* inc;
				inc *= 10;
			}
			k -= 4;
			second[0].date_pos[1] = 0;
			inc = 1;
			for (j -= 1; j >= k - 2; j--){
				second[0].date_pos[1] += (date[j] - 48)*inc;
				inc *= 10;
			}
			k -= 3;
			second[0].date_pos[2] = 0;
			inc = 1;
			for (j = j - 1; j >= k - 2; j--){
				second[0].date_pos[2] += (date[j] - 48)*inc;
			}
			second[0].date_pos[3] = 0;




			for (i = 0; i <= len - 1; i++){
				if (first[i].date_pos[0] < second[0].date_pos[0]){

				}
				else if (first[i].date_pos[0] > second[0].date_pos[0]){
					return len - i-1;
				}
				else{
					if (first[i].date_pos[1] < second[0].date_pos[1]){

					}
					else if (first[i].date_pos[1] > second[0].date_pos[1]){
						return len - i-1;
					}
					else{
						if (first[i].date_pos[3] < second[0].date_pos[3]){

						}
						else if (first[i].date_pos[2] > second[0].date_pos[2]){
							return len - i-1;
						}
						else{
							
							if (first[i].date_pos[2] != first[i + 1].date_pos[2])
								return len - i - 1;
							else
								return 0;
						}
					}
				}
			}
			return 0;
		

	}
}

