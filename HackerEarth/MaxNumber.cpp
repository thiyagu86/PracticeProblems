#include <iostream>
using namespace std;
 
int main()
{
    int nOfElems = 0;
    int nArray[100000];
    
    cin >> nOfElems;
    
    long long llSubsetCount = 0;
    long long llSum = 0;
    
    int nNegativeMax;
    bool bFirst = true;
    
    int nTemp; 
    for (int nVal = 0;nVal < nOfElems;nVal++)
    {
        //int nTemp;
        cin >> nTemp;
        //nArray[nVal] = nTemp;
        if(bFirst)
        {
            nNegativeMax = nTemp;
            bFirst = false;
        }
        else if(nTemp > nNegativeMax)
        {
            nNegativeMax = nTemp;
        }
            
        
        if(nTemp >= 0)
        {
            cout << "The nTemp is: " << nTemp << endl;
            llSubsetCount++;
            llSum += nTemp;
        }
    }
    if(llSubsetCount == 0)
    {
        llSum = nNegativeMax;
        llSubsetCount = 1;
    }
    cout << llSum << " " << llSubsetCount;
    return 0;
}
