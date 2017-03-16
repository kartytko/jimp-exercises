//
// Created by kartytko on 09.03.17.
//

#include "Array2D.h"
#include <iostream>
int **NewArray2D(int n_rows, int n_columns);
void FillArray2D(int n_rows, int n_columns, int *const *tab);


int **Array2D(int n_rows, int n_columns){
    return NewArray2D(n_rows, n_columns);
}


int **NewArray2D(int n_rows, int n_columns) {
//    int counter = 1;
    if(n_rows<=0){
        int  **tab = nullptr;
        return tab;
    }

    if(n_columns<=0){
        int  **tab = nullptr;
        return tab;
    }

    int** tab = new int*[n_rows];

    for(int i=0; i<n_rows; i++){
        tab[i] = new int[n_columns];
    }

    FillArray2D(n_rows, n_columns, tab);

    //    DeleteArray2D(tab, n_rows, n_columns);

    return tab;
}



void FillArray2D(int n_rows, int n_columns, int *const *tab) {
    int counter=1;

    for(int i=0; i<n_rows; i++){
        for (int j=0; j<n_columns; j++){
            tab[i][j] = counter;
//            std::cout<< tab[i][j]<<" ";
            counter ++;
        }
    }
}



void PrintArray2D(int n_rows, int n_columns, int **array){
    for(int i=0; i<n_rows; i++){
        for(int j=0; j<n_columns; j++){
            std::cout<<array[i][j];
        }
    }
}



void DeleteArray2D(int **array, int n_rows, int n_columns){
    for(int i=0; i<n_rows; i++){
        delete [] array[i];
    }
    delete [] array;
}