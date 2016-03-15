/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include<stdlib.h>
int findSingleOccurenceNumber(int *arr, int len)
{
	int x, y, count1;
	if ((len - 1) % 3 != 0||arr==NULL)
		return -1;
	for (x = 0; x < len; x++)
	{
		count1 = 0;
		for (y = 0; y < len; y++)
		{
			if (x == y)
				continue;
			if (arr[x] == arr[y]){
				count1++;
				break;
			}

		}
		if (count1 ==0)
			return arr[x];
	}
}