#include <iostream>
#include<ctime>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<stdio.h>
using namespace std;
/* name of groups rahma samy mohamed 20198035
doha khaled 20198126
mahmoud samy razek 20198075*/
class testsorting{
private:

    int size;
    int data[];
public:
    testsorting(){
    size=0;
    int data[]={0 ,0 , 0};
    }
  void GenerateRandomList(int min, int max, int size){
  srand(time(NULL));
    for (int i=1;i<=size;i++){
        cout<<"the random number is :"<<endl;
        cout<<rand()%(max-min+1)+min<<endl;
    }

 }
   void swap(int* temp1, int* temp2)
    {
    int t = *temp1;
    *temp1 = *temp2;
    *tem2 = t;
    }
    ///////////////////////////////////selection sort////////////////////////////////
    void selectSort(int data[], int size)
{

        int min,temp;

        for (int i=0; i < size-1; i++)
        {
            min = i;

                for (int j=i+1; j < size; j++)
                {

                if (data[j] < data[pos_min])
                   min=j;

                }


            if (min != i)
            {
                 temp = data[i];
                 data[i] = data[min];
                 data[min] = temp;
            }
        }
}
////////////////////////////quick sort///////////////////////////////////////////
   int part (int mydata[], int begain, int size2)
{
    int pivot = mydata[size2];    // pivot
    int i = (begain- 1);

    for (int j = begain; j <=size2 - 1; j++)
    {

        if (mydata[j] <= pivot)
        {
            i++;
            swap(&mydata[i], &mydata[j]);
        }
    }
    swap(&mydata[i + 1], &mydata[size2]);
    return (i + 1);
}
void quickSort(int myarr[], int begain, int size3)
{
    if (begain< size3)
    {
        int al = part(myarr,begain,size3);
        quickSort(myarr, begain, al - 1);
        quickSort(myarr, al + 1,size3);
    }
}
 int RunOnce(int sorter, int data[], int size){
    if (sorter==1){
   time_t start,endtime;
   start=time(NULL);
   selectSort(data,size);
   endtime=time(NULL);
   cout<<"the time differenence is is :"<<endl;
   cout<<difftime(start,endtime)<<endl;

    }
  else if (sorter==2){
    time_t start2,endtime2;
   start2=time(NULL);
   quickSort(data,0,size);
   endtime2=time(NULL);
   cout<<"the time differenence is is :"<<endl;
   cout<<difftime(start2,endtime2)<<endl;


  }
}
void RunAndAverage(int sorter,int  min, int max, int size, int sets_num){
  int sumoftimes=0;
  int *data=new int[size];
   for (int i=0; i<sets_num ; i++)
    {
         GenerateRandomList(min,max,size);
         sumoftimes=sumoftimes+ RunOnce(sorter,data, size);
        delete data;
    }
    int averg=sumoftimes/sets_num;
   cout<<"the average of times of data is="<<averg<<endl;
}
};
int main(){

  int maximum,minimum,sorter,numsets,size=0;
  cout<<"enter the size of the data"<<endl;
  cin>>size;
  cout<<"enter the minimum of random variable maximum first and minimum second:"<<endl;
  cin>>maximum>>minimum;
  if (minimum>maximum)
    cout<<"ERROR!PROGRAM TERMINATE"<<endl;


    ////////////////test function 1///////////////
    testsorting s;
    cout<<"the random list is :"<<endl;
    s.GenerateRandomList(minimum,maximum,size);
    /////////////test function 2/////////////////
    int size2=0;
    cout<<"enter the size of the data :"<<endl;
    cin>>size2;
    int*arr=new int[size2];
    cout<<"enter the elements"<<endl;
    for (int i=0; i<size2 ; i++)
    {
        cin>>arr[i];
    }
   cout<<"choose 1- selection sort or"<<endl;
   cout<<"2- quick sort"<<endl;
   cin>>sorter;
    s.RunOnce(sorter,arr,size2);
  //////////////////test function 3//////////////////////
  int size3=0;
  cout<<"enter the size of the data"<<endl;
  cin>>size3;
  cout<<"enter the minimum of random variable maximum first and minimum second:"<<endl;
  cin>>maximum>>minimum;
  if (minimum>maximum)
    cout<<"ERROR!PROGRAM TERMINATE"<<endl;
  cout<<"enter the number of iterations  of the data"<<endl;
  cin>>numsets;
  s.RunAndAverage( sorter,minimum, maximum, size3,numsets);

return 0;
}
