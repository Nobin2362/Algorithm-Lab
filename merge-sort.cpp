#include<iostream>

using namespace std;

void Merge(int*array,int le,int mid,int ri)
{
    int nle, gri,i,j,k;
    nle=mid-le+1;
    gri=ri-mid;
    int learr[nle], riarr[gri];
    for(i = 0;i<nle; i++)
    {
        learr[i]=array[le+i];
    }
    for(j = 0;j<gri;j++)
    {
        riarr[j]=array[mid+1+j];
    }
    i = 0;
    j = 0;
    k = le;
    while(i<nle && j<gri)
    {
        if(learr[i]<=riarr[j])
        {
            array[k]=learr[i];
            i++;
        }
        else
        {
            array[k]=riarr[j];
            j++;
        }
        k++;
    }
    while(i<nle)
    {
        array[k]=learr[i];
        i++;
        k++;
    }
    while(j<gri)
    {
        array[k] = riarr[j];
        j++;
        k++;
    }
}

void display(int *array, int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<< " ";
    }
    cout<<endl;
}

void MergeSort(int *array, int le, int ri)
{
    int middle;
    if(le<ri)
    {
        int mid = le+(ri-le)/2;
        MergeSort(array,le,mid);
        MergeSort(array,mid+1,ri);
        Merge(array,le,mid,ri);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int array[n];
    for(int i=0;i<n;i++)
    {
        cin >> array[i];
    }
    MergeSort(array,0,n-1);
    display(array,n);
}
