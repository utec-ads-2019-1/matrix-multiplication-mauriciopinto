//
// Created by Malena on 6/12/2019.
//

#ifndef MATRIX_MULT_MATRIX_H
#define MATRIX_MULT_MATRIX_H
#include<iostream>
#include<stdlib.h>

using namespace std;
class matrix{
public:
    int rows, columns;
    float** elements;
    matrix(int rows, int columns) : rows(rows), columns(columns){
        elements = new float*[rows];
        for(int i = 0; i < rows; i++){
            elements[i] = new float[columns];
        }
    }
    void generateNumbers(){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                elements[i][j] = rand()%10;
            }
        }
    }
    void showElements(){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};
#endif //MATRIX_MULT_MATRIX_H
