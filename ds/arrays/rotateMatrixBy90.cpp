// tutuorial https://www.youtube.com/watch?v=Jtu6dJ0Cb94

#include <bits/stdc++.h>
using namespace std;

void shm() {
#ifndef ONLINE_JUDGE
    freopen("D:\\cpp\\input.txt", "r", stdin);
    freopen("D:\\cpp\\output.txt", "w", stdout);
#endif
}

const int MATRIX_SIZE = 4;
void printMatrix(int m[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0 ; i < MATRIX_SIZE ; i++) {
        for (int j = 0 ; j < MATRIX_SIZE; j++) {
            cout << m[i][j];
            if (m[i][j] < 10) cout << "    ";
            else if (m[i][j] < 100) cout << "   ";
            else cout << "   ";
        }
        cout << endl;
    }
    cout << "----------------------------------" << endl;
}

void swap (int &i, int &j) {
    int temp = i ;
    i = j;
    j = temp ;
}

int main()
{
    shm();
    int m[MATRIX_SIZE][MATRIX_SIZE];
    int numOfRotations = 3; // no of times to rotate the matrix

    //filling the matrix
    int count = 0;
    for (int i = 0 ; i < MATRIX_SIZE ; i++) {
        for (int j = 0 ; j < MATRIX_SIZE; j++) {
            m[i][j] = count++;
        }
    }

    cout << "-------Original matrix---------" << endl;
    printMatrix(m);

    for (int k = 0 ; k < numOfRotations ; k++) {
        int level = 0; // mean number of circles in a matrix
        int totalNoLevels = MATRIX_SIZE / 2 ;
        int last = MATRIX_SIZE - 1 ;
        while (level < totalNoLevels) {
            for (int i = level ; i < last; i++) {
                swap(m[level][i], m[i][last]);
                swap(m[level][i], m[last][last - i + level]);
                swap(m[level][i], m[last - i + level][level]);
            }
            level++; //once the outer level is done we move to inner level
            last--; //when we move to inner level the last will
            //also become the inner level
        }
    }
    cout << "-------Rotated matrix---------" << endl;
    printMatrix(m);
}
