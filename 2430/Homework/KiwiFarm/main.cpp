#include <iostream>
#include <fstream>
#include "ArgumentManager.h"

using namespace std;


void debug_printFarm(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        int *p = matrix[i];
        for (int j = 0; j < size; j++) {
            cout << *p << " ";
            *p++;
        }
        cout << endl;
    }
}

int getRipeCount(int *row, int size){
    int *p = row;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (*p > 5) {
            ++count;
        }
        ++p;
    }
    return count;
}

void harvest(int **matrix, int size, int row, int *ripe, int *rotten) {
    int *p = matrix[row];
    for(int i = 0; i < size; i++) {
        if (*p >5 && *p< 9) {
            *ripe = *ripe+1;
        }
        else if (*p > 8) *rotten = *rotten+1;
        *p = 0;
        *p++;
    }
}

void growth(int **matrix, int size, int row) {
    int *p = matrix[row];
    for(int i = 0; i < size; i++) {
        *p = *p+1;
        *p++;
    }
}

void day(int **matrix, int size, int *ripe, int* rotten, int day) {
    int harvested[size];
    for(int i = 0; i < size; i++) harvested[i]=0;
    debug_printFarm(matrix, size);
    cout << endl << endl;
    //Check row harvestability
    for (int i = 0; i < size; i++) {
        int *row = matrix[i];
        int ripeCount = getRipeCount(row, size);
        cout << ripeCount << " ";
        if (ripeCount >= size/2) {
            harvest(matrix, size, i, ripe, rotten);
            harvested[i] = 1;
        }
    }
    cout << endl << "----------" << endl;
    if (day != 7) {
        for (int i=0; i < size; i++) {
            if (harvested[i] == 0) growth(matrix, size, i);
        }
    }
}


int main(int argc, char *argv[])
{
    if (argc != 3 && argc !=2) {
        cout << "Invalid arguments" << endl;
        return 1;
    }
    ArgumentManager am(argc, argv);
    string input = am.get("input");
    string output = am.get("output");

    cout << input << " " << output << endl;

    //This is the code to solve the problem

    ifstream ifs(input);

    int size;
    ifs >> size;

    //This is pointer matrix
    int **mat;
    //define rows
    mat = new int*[size];
    int x;
    for (int i = 0; i < size; i++) {
        //create 1 row at a time
        mat[i] = new int[size];
        int *p = mat[i];
        for(int j = 0; j < size; j++) {
            ifs >> x;
            *p = x;
            ++p;
        }
    }

    int *ripe = new int;
    int *rotten = new int;
    *ripe = 0;
    *rotten = 0;

    for(int i = 0; i < 8; i++) day(mat, size, ripe, rotten, i);

    cout<< endl << "Harvested: " << *ripe << endl << "Rotten: " << *rotten << endl;


    ofstream ofs(output);



    for (int i = 0; i < size; i++) {
        int *p = mat[i];
        for (int j = 0; j < size; j++) {
            ofs << *p << " ";
            *p++;
        }
        ofs << endl;
    }

    ofs << endl <<
           "Harvested kiwis: " << *ripe << endl <<
           "Rotten kiwis: " << *rotten << endl << endl;



    ofs.close();
    return 0;
}
