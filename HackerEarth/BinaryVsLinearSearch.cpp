#include <iostream>
using namespace std;

int nNumElems = 0;

int nGlobalRight = 0;

void insertionSort(int a[],int nSize)
{
  int i,j,key;
  for(i = 1;i< nSize;i++)
  {
    int key = a[i];
    int j = i-1;

    while(j >= 0 && a[j] > key)
    {
       a[j+1] = a[j];
       j=j-1;
       //printElems(i,j,a[i],a[j],a[j+1],key,1);
    }
    a[j+1]=key;
    //printElems(i,j,a[i],a[j],a[j+1],key);
  }
}

void printArray(int a[],int nSize)
{
  for(int nVal = 0; nVal < nSize;nVal ++)
  {
    cout << "Printing array elements: " << a[nVal] <<endl;
  }
  cout << endl;
}
/*int BinarySearch(int nArray,int key,int nNumElems)
{
    int nMiddle = nNumElems/2;

    int nLeftIndex,nRightIndex;

    nLeftIndex = 0;
    nRightIndex = nNumElems-1;

    if(nArray[nMiddle] == key)
    	return nMiddle;
    else if( key < nArray[nMiddle])
    {
    	std::memset(nTemp, 0, sizeof nTemp);
    	std::copy(nArray[nLeftIndex],nArray[nMiddle],nTemp[0]);
        BinarySearch(nTemp,key,nMiddle);
    }
    else if( key > nArray[nMiddle])
    {
    	std::memset(nTemp, 0, sizeof nTemp);
    	std::copy(nArray[nMiddle],nArray[nRightIndex],nTemp[0]);
        BinarySearch(nTemp,key,nMiddle);
    }
}*/
int BinarySearch(int nArray[], int nLeftIndex, int nRightIndex, int nKey) 
{ 
    if (nRightIndex >= nLeftIndex) { 
        int nMiddle = nLeftIndex + (nRightIndex - nLeftIndex) / 2; 
  
        //Base condition
        if (nArray[nMiddle] == nKey) 
            return nMiddle; 
  
        // If element is smaller than mid, then it can only be present in left portion
        if (nArray[nMiddle] > nKey)
        {
            nGlobalRight = nMiddle -1;
            return BinarySearch(nArray, nLeftIndex, nMiddle - 1, nKey);
        }
        else
        {
           // Else the element can only be present in right portion
           nGlobalRight = nRightIndex;
           return BinarySearch(nArray, nMiddle + 1, nRightIndex, nKey);
        }
    } 
    //No element found
    return nGlobalRight; 
}
int retClosest(int nKey, int Val1, int Val2)
{
	cout << "(nKey - Val1): " << nKey -Val1 << "(Val2 - nKey): " << Val2 - nKey << endl; 
	if( (nKey-Val1) > (Val2-nKey))
	{
		return Val2;
	}
	else if ((nKey-Val1) == (Val2-nKey))
	{
		return Val2;
	}
	else
	{
		return Val1;
	}
}

int ClosestMatch(int nArray[], int nLeftIndex, int nRightIndex, int nKey) 
{ 
   //Corner Cases
	if(nKey < nArray[0])
		return 0;
	if(nKey > nArray[nNumElems-1])
		return nNumElems-1;

	int i=0,j = nNumElems,nMiddle = 0;

	while(i<j)
	{
		nMiddle = (i+j)/2;

        //Base condition
		if(nArray[nMiddle] == nKey)
			return nArray[nMiddle];

		if(nKey < nArray[nMiddle])
		{
			if(nMiddle > 0 && nKey > nArray[nMiddle - 1])
				retClosest(nKey,nArray[nMiddle-1],nArray[nMiddle]);

			j = nMiddle;
		}
		else
		{
			if(nMiddle < (nNumElems-1) && nKey < nArray[nMiddle+1])
				retClosest(nKey,nArray[nMiddle],nArray[nMiddle+1]);

			i = nMiddle+1;
		}
	}
	//return arr[mid];
	cout << "returning middle: " << nMiddle << endl;
	return nMiddle;
} 
int GetSmallNum(int nArray[], int nLeftIndex, int nRightIndex, int nKey)
{
	int nIndex = ClosestMatch(nArray,nLeftIndex,nRightIndex,nKey);

	if(nIndex == 0)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << nGlobalRight+1 << endl;
	}

	//cout << nNumElems << " - " << nIndex << endl; 

	//cout << nNumElems - nIndex << endl;
}
int main()
{
    //cout << "Enter the number of elements in array: ";

    cin >> nNumElems;

    int nArray[5000]={0};
    
    for(int i = 0;i<nNumElems;i++)
       cin >> nArray[i];

    //printArray(nArray,nNumElems);
    insertionSort(nArray,nNumElems);
    printArray(nArray,nNumElems);

    int nQuery = 0;

    cin >> nQuery;

    for(int i = 0;i < nQuery; i++)
    {
       int nKey = 0;
       cin >> nKey;
       GetSmallNum(nArray,0,nNumElems-1,nKey);
    }
	return 0;
}