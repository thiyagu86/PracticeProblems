

#include <iostream>

using namespace std;

int nArray[10001] = {0};

int findKey(int nSize,int nKey)
{
    std::vector<int> nVec;
    for(int nVal = 0;nVal < nSize;nVal++)
    {
        if(nArray[nVal] != 0 && nArray[nVal] == nKey)
        {
            nVec.push_back(nArray[nVal]);
        }
    }
    int nMin = 0;
    //Assign first vector value as smallest
    if(!nVec.empty())
        nMin = nVec(0);

    for (int i = 0; i < nVec.size(); i++)
    {
        if(nMin < nVec[i])
            nMin = nVec[i];
    }
    return nMin;
}

int main()
{
    int nOfElems = 0;
    cin >> nOfElems;

    for(int nVal = 0; nVal < nOfElems; nVal++)
    {
        int nValue;
        cin >> nValue;
    	nArray[nValue]++;
    }
    
    int nKey = 0;
    cin >> nKey;

    int nIndex = findKey(nVal,nKey);

	return 0;
}