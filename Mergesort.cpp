#include<iostream>



template<class  T>
class MergeSort
{
private :
    T * Data;
    int SizeArray = 0;
public:
    MergeSort(int SizeArray, T * ArrayName)
    {
    Data = ArrayName;
    this->SizeArray=SizeArray;
    MergeDivide(0,SizeArray);
    MergePrint();

    }
    void MergeDivide(int low,int high);
    void MergeCombine(int low, int mid, int high);
    void MergePrint()
    {
    for(int i =0;i<=SizeArray;i++)
    {
        std::cout<<Data[i]<<std::endl;
    }

    }
};

template<class  T>
void MergeSort<T>::MergeDivide(int low, int high)
{
    if((high - low) == 0)
        return;
else{

    int mid = (low + high )/2;
    MergeDivide(low,mid);
    MergeDivide(mid+1,high);
    MergeCombine(low,mid,high);
}

}

template<class  T>
void MergeSort<T>::MergeCombine(int low, int mid, int high)
{
    int IterateStart=low;
    int IterateMid = mid+1;
    T newArray[high - low +1 ];
    int IterateNewArray =  low ;

    while( IterateStart <=mid && IterateMid <= high )                //for a 5 long array high is 4
    {
        if(Data[IterateStart] < Data[IterateMid])
        {
            newArray[IterateNewArray] = Data[IterateStart];
            IterateNewArray ++;
            IterateStart++;
        }
        else
        {
            newArray[IterateNewArray] = Data[IterateMid];
            IterateNewArray ++;
            IterateMid++;
        }

    }

    while(IterateStart <= mid)
    {
            newArray[IterateNewArray] = Data[IterateStart];
            IterateNewArray ++;
            IterateStart++;

    }
    while(IterateMid <= high)
    {
            newArray[IterateNewArray] = Data[IterateMid];
            IterateNewArray ++;
            IterateMid++;


    }
    for(int i =low; i<IterateNewArray; i++)
    {
        Data[i] = newArray[i];

    }

}




int main()
{
int data1[]={2,3,2,34,5,33,2,4};
MergeSort<int> test( 7 ,data1);
return 0;
}
