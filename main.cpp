#include "matrix.h"
#include <thread>
#define NUM_THREADS 2

void multMatrix(matrix m1, matrix m2, matrix &m3, int first, int last){
    for(int m = 0; m < m2.columns; m++){
        for(int i = first; i < last; i++){
            float suma = 0;
            for(int j = 0; j < m1.columns; j++){
                suma += (m1.elements[i][j])*(m2.elements[j][m]);
            }
            m3.elements[i][m] = suma;
        }
    }
}

int main(){
    matrix m1(5,3);
    matrix m2(3,5);
    matrix m3(m1.rows, m2.columns);
    m1.generateNumbers();
    m1.showElements();
    m2.generateNumbers();
    m2.showElements();
    thread thread1(multMatrix, m1, m2, ref(m3), 0, NUM_THREADS/2);
    thread thread2(multMatrix, m1, m2, ref(m3), NUM_THREADS/2, m1.rows);
    thread1.join();
    thread2.join();
    m3.showElements();
}
