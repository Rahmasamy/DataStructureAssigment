#include <iostream>
#include <cstdlib>
#include <functional>
#include <chrono>
////////another way for problem2
/* name of groups rahma samy mohamed 20198035
doha khaled 20198126
mahmoud samy razek 20198075*/
using namespace std;
void swap(int* b, int* a) {
  int t = *b;
  *b = *a;
  *b = t;
}

void Selection_Sort(int arra[], int n) {
  int  mine,j, i;
     i = 0 ;
  while ( i < n - 1)
        {

       mine= i;

      for (j = i + 1; j < n; j++)

      if (arra[j] < arra[mine])

        mine = j;


    swap(&arra[mine], &arra[i]);
     i++;
  }
}

int partition(int arra[], int l, int h) {
  int P = arra[h];

  int i = (l - 1);

  for (int j = l; j <= h - 1; j++) {

    if (arra[j] < P) {

      i++;

      swap(&arra[i], &arra[j]);
    }
  }
  swap(&arra[i + 1], &arra[h]);

  return (i + 1);
}

void Quick_Sort(int arra[], int l, int h) {
  if (l < h) {

    int B = partition(arra, l, h);

    Quick_Sort(arra, l, B - 1);

    Quick_Sort(arra, B + 1, h);
  }
}

class Sorting {

public:

  int* GenereteRandomList(int min, int max, int size) {

    int* arra = new int[size];

    int value = max - min + 1;

    for (int i = 0; i < size; i++) {

      arra[i] = rand() % value + min;
    }
    return arra;
  }

  int Runonce(string sorter, int D[], int size) {

    std::chrono::_V2::system_clock::time_point start = chrono::high_resolution_clock::now();

    if (sorter == "quick_Sort") {

      Quick_Sort(D, 0, size - 1);
    }
    else if (sorter == "selection_Sort") {

      Selection_Sort(D, size);
    }

    std::chrono::_V2::system_clock::time_point finish = chrono::high_resolution_clock::now();

    std::chrono::microseconds microseconds = chrono::duration_cast<chrono::microseconds>(finish - start);

    return microseconds.count();
  }

  int RunAndAverage(string Sorted_arr, int min, int max, int size, int setsnumbers) {
    int time = 0;
    int i = 0;

    while ( i < setsnumbers) {

      int* arra = GenereteRandomList(min, max, size);

      time += Runonce(Sorted_arr, arra, size);
      i++;
    }
    return (time / setsnumbers);
  }

};

int main()
{
   Sorting S;

  double Quick_Time = S.RunAndAverage("quick_Sort", 0, 10, 10000, 100);

  double Sorting_Time = S.RunAndAverage("selection_Sort", 0, 10, 10000, 100);

  cout << "selection_Sort " << "="<<Sorting_Time << " Ms" << endl;
  cout<<"******************"<<endl;
  cout << "quick_Sort " << "="<<Quick_Time << " Ms" << endl;

    return 0;
}
