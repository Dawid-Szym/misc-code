#include <iostream>
#include <cmath>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;



//funkcje p.1

void fillone(int* arr, int temp){
    int i=0;
    while(i<temp){
        arr[i]=(i%3)+1;
        i++;
    }
}

void filltwo(int* arr, int temp){
    for (int i = 0; i < temp; i++) {
        int liczn = i%6;
        switch (liczn)
        {
            case 0: {arr[i]=1;break;}
            case 1: {arr[i]=2;break;}
            case 2: {arr[i]=4;break;}
            case 3: {arr[i]=8;break;}
            case 4: {arr[i]=16;break;}
            case 5: {arr[i]=32;break;}
        }
    }
}

void fillthree(int* arr, int temp){
    int aroftwo[temp + 1];
    aroftwo[0] = 1;
    for(int i = 1; i <= temp; i++) {
        aroftwo[i] = aroftwo[i - 1] * 2;
    }
    int index = 0;
    for(int i = 0; i < temp; i++) {
        for(int j = 0; j <= index && i < temp; j++, i++) {
            arr[i] = aroftwo[j];
        }
        i--;
        index++;
    }
}



void fillfour(int* arr, int temp){
    for (int i = 0; i < temp; i++) {
        if (i == 0 || i == 1) {
            arr[i] = 1;
        } else {
            arr[i] = pow(2, i - 1);
        }
    }
}

void fillfive(char* arr, int temp){
    char lett[]={'A', 'C', 'E', 'F'};
    int i =0, j=0;
    while(i<temp){
        arr[i] = lett[j];
        i++;
        if(j==3){
            j=0;
        }else{j++;}
    }
}

void fillsix(char* arr, int temp){
    char letter[] = {'A', 'C', 'E', 'F', 'F', 'E', 'C', 'A'};
    int i = 0, j = 0;
    while (i < temp) {
        arr[i] = letter[j];
        i++;
        j++;
        if (j == 8) {
            j = 0;
        }
    }
}

void fillseven(double* arr, int temp, double a, double b){
    double den = a-b;
    for(int i=0; i<temp; i++){
        double sum=0;
        if(i%2==0){
            for(int k=1; k<=i; k++){
                sum = sum+exp(sqrt((a*a) + (b*b) + (i*i)));
                arr[i]=sum;
            }
        }else{
            for(int k=1; k<=i; k++){
                double num;
                num = sqrt(abs(a + b + i));
                double res;
                res = num/den;
                sum = sum+res;
                arr[i]=sum;
            }
        }
    }
}



//funkcje p.2

int** createMatrix(int n, int m) {
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 100 + 1;
        }
    }
    return matrix;
}



void displayMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void addM(int **matrix1, int **matrix2, int **result, int n, int m) {
    for (int i = 0; i < n; i++) {
        result[i] = new int[m];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractM(int **matrix1, int **matrix2, int **result, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyM(int **matrix1, int **matrix2, int **result, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = 0;
            for (int k = 0; k < m; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void transposeM(int **matrix, int **result, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void zeroDiagonal(int **matrix, int **result, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        result[i][i] = 0;
    }
}
long double multiplyOdwrNotZero(int **matrix, int n, int m) {
    long double result=1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                result = result * (1.0 / matrix[i][j]); //
            }
        }
    }
    return result;
}

double arithmeticM(int **matrix, int n, int m) {
    double sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += matrix[i][j];
            count++;
        }
    }
    return sum / count;
}

double geometricM(int **matrix, int n, int m) {
    double product = 1;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            product *= abs(matrix[i][j]);
            count++;
        }
    }
    double geometricM = pow(product, 1.0 / (count));
    return geometricM;
}

void frequency(int **matrix, int n, int m) {
    int freq[101] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            freq[matrix[i][j]]++;
        }
    }

    for (int i = 1; i <= 100; i++) {
        if (freq[i] > 0) {
            cout << "Wartosc: " << i << " wystapila razy: " << freq[i] <<endl;
        }
    }
}


//main

int main(){
    int loop = 1;
    while(loop>0){
        cout << "wpisanie wartosci 1, 2 wyswietli odpowiadajace zadanie: ";
        int zad;
        cin >> zad;
        switch (zad)
        {
        case 1:{
            cout << "zadanie 1: wypelnianie tablicy o rozmiarze N na wskazane sposoby\nPodaj N: ";
            int temp;
            cin >> temp;
            cout << "Podaj A: ";
            double a;
            cin >> a;
            cout << "Podaj B: ";
            double b;
            cin >> b;
            //1
            int arone[temp];
            fillone(arone, temp);
            cout << "1)  ";
            for(int i=0; i<temp; i++){
                cout <<arone[i]<<" ";
            }
            cout << endl;
            //2
            int arni[temp];
            filltwo(arni, temp);
            cout << "2)  ";
            for(int i=0; i<temp; i++){
                cout <<arni[i]<<" ";
            }
            cout << endl;
            //3
            int arsan[temp];
            fillthree(arsan, temp);
            cout << "3)  ";
            for(int i=0; i<temp; i++){
                cout <<arsan[i]<<" ";
            }
            cout << endl;


            //4
            int aryon[temp];
            fillfour(aryon, temp);
            cout << "4)  ";
            for(int i=0; i<temp; i++){
                cout <<aryon[i]<<" ";
            }
            cout << endl;
            //5
            char argo[temp];
            fillfive(argo, temp);
            cout << "5)  ";
            for(int i=0; i<temp; i++){
                cout <<argo[i]<<" ";
            }
            cout << endl;
            //6
            char arroku[temp];
            fillsix(arroku, temp);
            cout << "6)  ";
            for(int i=0; i<temp; i++){
                cout <<arroku[i]<<" ";
            }
            cout << endl;

            //7
            double arnana[temp];
            if(a-b==0){
                cout <<"wartosc a-b nie moze byc 0\n";
                break;
            } 
            fillseven(arnana, temp, a, b);
            cout << "7)  ";
            for(int i=0; i<temp; i++){
                cout <<arnana[i]<<" ";
            }
            cout << endl;
            break;
            
        }

        case 2:{
            cout << "Dzialania na macierzach\n Podaj rozmiar macierzy do wygenerowania\nN: ";
            int n;
            cin >> n;
            cout << "M: ";
            int m;
            cin >> m;
            cout <<endl;
            //create
            int** matrixA = createMatrix(n, m);
            int** matrixB = createMatrix(n, m);
            
            //display
            cout << "Matrix A:" <<endl;
            displayMatrix(matrixA, n, m);
            cout << "Matrix B:" <<endl;
            displayMatrix(matrixB, n, m);
            int **result= createMatrix(n, m);
            //dodawanie
            cout <<"\nDodawanie:\n";
            addM(matrixA, matrixB, result, n, m);
            displayMatrix(result, n, m);
            //odejmowanie
            cout <<"\nOdejmowanie:\n";
            subtractM(matrixA, matrixB, result, n, m);
            displayMatrix(result, n, m);
            //iloczyn
            cout <<"\nIloczyn:\n";
            multiplyM(matrixA, matrixB, result, n, m);
            displayMatrix(result, n, m);

            cout <<"\n\nKolejne podpunkty skupiaja sie na 1 macierzy;\n";
            bool task;
            cout <<"macierz A (1) B (0):";
            cin >>task;
            //transpozycja
            cout <<"\n\nTranspozycja:\n";
            if(task ==true){
                transposeM(matrixA, result, n, m);
                displayMatrix(result, n, m);
            }else{
                transposeM(matrixB, result, n, m);
                displayMatrix(result, n, m);
            }
            cout <<"\nZerowanie po przekatnej:\n";
            //zerowanie po przekatnej
            if(task ==true){
                zeroDiagonal(matrixA, result, n, m);
                displayMatrix(result, n, m);
            }else{
                zeroDiagonal(matrixB, result, n, m);
                displayMatrix(result, n, m);
            }
            //iloczyn odwrotnosci wszystkich niezerowych el.
            cout <<"\n\niloczyn odwrotnosci wszystkich niezerowych el.:\n";
            if(task ==true){
                cout << fixed << setprecision(10) << multiplyOdwrNotZero(matrixA, n, m);
            }else{
                cout << fixed << setprecision(10) << multiplyOdwrNotZero(matrixA, n, m);
            }
            //srednia aryt.
            cout <<"\n\nsrednia aryt.:\n";
            if(task ==true){
                cout << arithmeticM(matrixA, n, m);
            }else{
                cout << arithmeticM(matrixB, n, m);
            }
            //srednia geo wart. bezwzgl.
            cout <<"\n\nsrednia geo. wart. bezwzgl.:\n";
            if(task ==true){
                cout << geometricM(matrixA, n, m);
            }else{
                cout << geometricM(matrixB, n, m);
            }

            //czestosci wystepowania kazdej wartosci
            cout <<"\n\nczestosc wystepowania wart.:\n";
            if(task ==true){
                frequency(matrixA, n, m);
            }else{
                frequency(matrixB, n, m);
            }



            break;
            }
        }


        }
           





        










    return 0;





    }
