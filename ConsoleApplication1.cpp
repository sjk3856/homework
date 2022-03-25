#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int row;
    int col;
    int value;
} term;

int main()
{
    //배열
    int matrixA[4][5] = { {0,2,0,1,1},{0,2,4,0,0},{1,2,0,0,0},{3,0,0,0,0} };
    int matrixB[4][5] = { {1,0,2,3,0},{0,0,3,0,0},{0,0,0,0,1},{1,5,0,3,0} };

    //배열 크기
    int sizeOfColA = sizeof(matrixA[0]) / sizeof(int);
    int sizeOfRowA = sizeof(matrixA) / sizeof(matrixA[0]);
    int sizeOfColB = sizeof(matrixB[0]) / sizeof(int);
    int sizeOfRowB = sizeof(matrixB) / sizeof(matrixB[0]);

    //배열 출력
    printf("A\n\n");
    for (int i = 0; i < sizeOfRowA; i++){
        for (int j = 0; j < sizeOfColA; j++){
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }

    printf("\n\n------------------------\n\n");
    printf("B\n\n");
    for (int i = 0; i < sizeOfRowB; i++) {
        for (int j = 0; j < sizeOfColB; j++) {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    //A의 0이 아닌 공간의 갯수
    int totalNonZeroNumberA = 0;
    for (int row = 0; row < sizeOfRowA; row++) {
        for (int col = 0; col < sizeOfColA; col++) {
            if (matrixA[row][col] != 0) {
                totalNonZeroNumberA++;
            }
        }
    }
    //B의 0이 아닌 공간의 갯수
    int totalNonZeroNumberB = 0;
    for (int row = 0; row < sizeOfRowB; row++) {
        for (int col = 0; col < sizeOfColB; col++) {
            if (matrixB[row][col] != 0)
                totalNonZeroNumberB++;
        }
    }


    //구조체 선언
    term* a = (term*)malloc(sizeof(term) * (totalNonZeroNumberA+1));
    term* b = (term*)malloc(sizeof(term) * (totalNonZeroNumberB+1));
    

    //A를 행렬에서 순회행렬로 변환
    a[0].row = sizeOfRowA;
    a[0].col = sizeOfColA;
    a[0].value = totalNonZeroNumberA;
    int idx = 1;

    for (int n = 0; n < sizeOfRowA; n++) {
        for (int m = 0; m < sizeOfColA; m++) {
            if (matrixA[n][m] != 0) {
                a[idx].row = n;
                a[idx].col = m;
                a[idx++].value = matrixA[n][m];
            }
        }
    }
    //B를 행렬에서 순회행렬로 변환
    b[0].row = sizeOfRowB;
    b[0].col = sizeOfColB;
    b[0].value = totalNonZeroNumberB;
    int iidx = 1;

    for (int n = 0; n < sizeOfRowB; n++) {
        for (int m = 0; m < sizeOfColB; m++) {
            if (matrixB[n][m] != 0) {
                b[iidx].row = n;
                b[iidx].col = m;
                b[iidx++].value = matrixB[n][m];
            }
        }
    }

    /*
    //A의 회소행렬 출력
    printf("A\n");
    for (int row = 0; row <= 8; row++) {
        printf("%d, %d, %d\n", a[row].row, a[row].col, a[row].value);
    }
    printf("\n----------------------------------\n\n");
    //B의 회소행렬 출력
    printf("B\n");
    for (int row = 0; row <= 8; row++) {
        printf("%d, %d, %d\n", b[row].row, b[row].col, b[row].value);
    }
    */


    /*여기까지가 행렬 A와 B를 회소행렬을 바꾸고 출력까지*/




    term* c = (term*)malloc(sizeof(term) * (totalNonZeroNumberA + 1));
    int iiidx = 1;
    for (int n = 0; n < sizeOfRowA; n++) {
        for (int m = 0; m < sizeOfColA; m++) {
            c[iiidx].row = 0;
            c[iiidx].col = 0;
            c[iiidx++].value = 0;
        }
    }
    
    for (int i = 0; i <= 8; i++) {
        for (int x = 0; x <= 8; x++) {
            if ((a[i].row == b[x].row) && (a[i].col == b[x].col)) {
                c[x].row = a[i].row;
                c[x].col = a[i].col;
                c[x].value = a[i].value + b[x].value;
            }
        }
    }
    c[0].value = a[0].value;
    printf("\n----------------------------------\n\n");
    /*
    printf("A+B\n");
    for (int row = 0; row <= 8; row++) {
        printf("%d, %d, %d\n", c[row].row, c[row].col, c[row].value);
    }
    */
    
    
    /*다시 희소행렬을 행렬로 만들기*/


    int matrixC[4][5] = { 0, };


    for (int i = 1; i <= 8; i++) {
        if (c[i].value != 0) {
            matrixC[c[i].row][c[i].col] = c[i].value;
        }
    }
    

    printf("\n");
    
    printf("A+B\n\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }
}
