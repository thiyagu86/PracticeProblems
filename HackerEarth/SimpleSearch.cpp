#include <iostream>

using namespace std;

int nArray[100001] = {0};

int findKey(int nSize,int nKey)
{
	for(int nVal = 0;nVal < nSize;nVal++)
	{
	    if(nKey == nArray[nVal])
	        return nVal;
	}
	else 
		return -1;
}

int main()
{
    int nOfElems = 0;
    cin >> nOfElems;

    for(int nVal = 0; nVal < nOfElems; nVal++)
    {
    	cin >> nArray[nVal];
    }
    
    int nKey = 0
    cin >> nKey;

    int nIndex = findKey(nVal,nKey);

	return 0;
}