#include "matrix.h"
#include <thread>
#define NUM_THREADS 8

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
    matrix m1(100,100);
    matrix m2(100,100);
    matrix m3(m1.rows, m2.columns);
    m1.generateNumbers();
    m1.showElements();
    m2.generateNumbers();
    m2.showElements();
    thread thread1(multMatrix, m1, m2, ref(m3), 0, m1.rows/NUM_THREADS);
    thread thread2(multMatrix, m1, m2, ref(m3), m1.rows/NUM_THREADS, 2*(m1.rows/NUM_THREADS));
    thread thread3(multMatrix, m1, m2, ref(m3), 2*(m1.rows/NUM_THREADS), 3*(m1.rows/NUM_THREADS));
    thread thread4(multMatrix, m1, m2, ref(m3), 3*(m1.rows/NUM_THREADS), 4*(m1.rows/NUM_THREADS));
    thread thread5(multMatrix, m1, m2, ref(m3), 4*(m1.rows/NUM_THREADS), 5*(m1.rows/NUM_THREADS));
    thread thread6(multMatrix, m1, m2, ref(m3), 5*(m1.rows/NUM_THREADS), 6*(m1.rows/NUM_THREADS));
    thread thread7(multMatrix, m1, m2, ref(m3), 6*(m1.rows/NUM_THREADS), 7*(m1.rows/NUM_THREADS));
    thread thread8(multMatrix, m1, m2, ref(m3), 7*(m1.rows/NUM_THREADS), m1.rows);
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    thread5.join();
    thread6.join();
    thread7.join();
    thread8.join();
    m3.showElements();
}
