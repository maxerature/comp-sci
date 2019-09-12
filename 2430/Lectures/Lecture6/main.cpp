#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;



int bubbleSort(int a[], int n) {
    int temp;
    for(int pass=1;pass<n;pass++) {
        for(int i=0; i<n;i++) {
            if(a[i] > a[i+1]) {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }
}

int selectionSort(int a[], int n) {
    int temp;
    int min;
    int first;
    for(int i=0; i<n;i++){
        first = i;
        min = i+1;
        for(int j=i+2; j<n;j++){
            if(a[j]<a[min]) min=j;
        }
        if(a[min] < a[first]) {
            temp = a[first];
            a[first] = a[min];
            a[min] = temp;
        }
    }
}

int InsertSort(int array[], int n) {
    int temp;
    for(int i=1; i<n;i++) {
        temp = array[i];
        while(temp < array[i-1] && i>0) {
            array[i] = array[i-1];
            i--;
        }
        array[i] = temp;
    }
}


void print(int a[], int n) {
    for (int i=0; i< n;i++) {
        cout << a[i] << endl;
    }
}


int main()
{

//    int array[10] = {5,6,4,7,3,8,2,9,1,10};
////    InsertSort(ten, 10);
//    int temp;
//    for(int i=1; i<10;i++) {
//        temp = array[i];
//        while(temp < array[i-1] && i>0) {
//            array[i] = array[i-1];
//            i--;
//        }
//        array[i] = temp;
//    }
//    print(array, 10);



    int hundred[100];
    for (int i=0; i<101; i++) {
        hundred[i] = rand()%100;
    }

    int thousand[1000];
    for(int i=0; i<1001; i++) {
        thousand[i] = rand()%1000;
    }

    int twentyK[20000];
    for(int i=0; i<20001; i++) {
        twentyK[i] = rand()%20000;
    }

    clock_t time_start;
    double runTime;

    time_start = clock();
    bubbleSort(hundred, 100);
    runTime = ((clock() - time_start) / (double) CLOCKS_PER_SEC)*1000000;
    cout << "Bubblesort 100:" << runTime << " nanoseconds" << endl;

    time_start = clock();
    selectionSort(hundred, 100);
    runTime = ((clock() - time_start) / (double) CLOCKS_PER_SEC)*1000000;
    cout << "SelectSort 100:" << runTime << " nanoseconds" << endl;

    time_start = clock();
    InsertSort(hundred, 100);
    runTime = ((clock() - time_start) / (double) CLOCKS_PER_SEC)*1000000;
    cout << "InsertSort 100:" << runTime<< " nanoseconds" << endl;

    cout << endl;

    time_start = clock();
    bubbleSort(thousand, 1000);
    runTime = ((clock() - time_start) / (double) CLOCKS_PER_SEC)*1000000;
    cout << "Bubblesort 1000:" << runTime << " nanoseconds" << endl;

    time_start = clock();
    selectionSort(thousand, 1000);
    runTime = ((clock() - time_start) / (double) CLOCKS_PER_SEC)*1000000;
    cout << "SelectSort 1000:" << runTime << " nanoseconds" << endl;

    time_start = clock();
    InsertSort(thousand, 1000);
    runTime = ((clock() - time_start) / (double) CLOCKS_PER_SEC)*1000000;
    cout << "InsertSort 1000:" << runTime<< " nanoseconds" << endl;

    cout << endl;

    time_start = clock();
    bubbleSort(twentyK, 20000);
    runTime = ((clock() - time_start) / (double) CLOCKS_PER_SEC);
    cout << "Bubblesort 20000:" << runTime << " seconds" << endl;

    time_start = clock();
    selectionSort(twentyK, 20000);
    runTime = ((clock() - time_start) / (double) CLOCKS_PER_SEC);
    cout << "SelectSort 20000:" << runTime << " seconds" << endl;

    time_start = clock();
    InsertSort(twentyK, 20000);
    runTime = ((clock() - time_start) / (double) CLOCKS_PER_SEC)*1000000;
    cout << "InsertSort 20000:" << runTime<< " nanoseconds" << endl;
}
