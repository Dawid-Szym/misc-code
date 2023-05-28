#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void drawTree(int height) {
    ofstream file("choinka.txt");
        if (height < 4 || height > 14) {
        cerr << "Nieprawidlowa wysokosc. Wysokosc musi byc z zakresu 4-14." << endl;
        return;
    }

    int spaces = height - 1;
    int stars = 1;

    for (int i = 0; i < height - 1; i++) {
        string line;
        for (int j = 0; j < spaces; j++) {
            cout << ' ';
            line += ' ';
        }

        for (int j = 0; j < stars; j++) {
            cout << '*';
            line += '*';
        }

        cout << endl;
        file << line + '\n';

        spaces--;
        stars += 2;
    }

    int baseWidth = stars;
    int baseSpaces = (baseWidth - 1) / 2;

    string line;
    for (int i = 0; i < baseSpaces; i++) {
        cout << ' ';
        line += ' ';
    }
    cout << '*' << endl;
    file << line + '*' + '\n';

    file.close();
}


void saveStatToFile(int lastNumber, int totalCount, int negativeCount, int positiveCount, int evenCount, int oddCount) {
    ofstream file("statystyki.txt");

    file << "Ostatnia podana liczba: " << lastNumber << endl;
    file << "Liczba podanych liczb: " << totalCount << endl;
    file << "Liczba liczb ujemnych: " << negativeCount << endl;
    file << "Liczba liczb dodatnich: " << positiveCount << endl;
    file << "Liczba liczb parzystych: " << evenCount << endl;
    file << "Liczba liczb nieparzystych: " << oddCount << endl;

    file.close();
}

void stat(){
    int lastNumber = 0;
    int totalCount = 0;
    int negativeCount = 0;
    int positiveCount = 0;
    int evenCount = 0;
    int oddCount = 0;
    int consecutiveSameCount = 0;
    int sum = 0;
    while (sum <= 100 && negativeCount <= 10 && consecutiveSameCount < 2) {
                int number;
                cout << "Podaj liczbe: ";
                cin >> number;

                totalCount++;

                if (number < 0) {
                    negativeCount++;
                } else if (number > 0) {
                    positiveCount++;
                }

                if (number % 2 == 0) {
                    evenCount++;
                } else {
                    oddCount++;
                }
                
                if (number == lastNumber && number != 0) {
                    consecutiveSameCount++;
                } else {
                    consecutiveSameCount = 0;
                }
                
                lastNumber = number;
                sum += number;
            }

            saveStatToFile(lastNumber, totalCount, negativeCount, positiveCount, evenCount, oddCount);
}

double convert(double temperature, string sourceScale, string targetScale) {
    double convertedTemperature;

    if (sourceScale == "C") {
        if (targetScale == "F") {
            convertedTemperature = (temperature * 1.8) + 32;
        } else if (targetScale == "K") {
            convertedTemperature = temperature + 273.15;
        } else {
            cout << "Bledna skala docelowa.\n";
            return 0;
        }
    } else if (sourceScale == "K") {
        if (targetScale == "F") {
            convertedTemperature = (temperature * 1.8) - 459.67;
        } else if (targetScale == "C") {
            if (temperature < 0) {
                cout << "Blad zera bezwzgl. (T=0 K).\n";
                return 0;
            }
            convertedTemperature = temperature - 273.15;
        } else {
            cout << "Bledna skala docelowa.\n";
            return 0;
        }
    } else if (sourceScale == "F") {
        if (targetScale == "C") {
            convertedTemperature = (temperature - 32) / 1.8;
        } else if (targetScale == "K") {
            convertedTemperature = (temperature + 459.67) * 5 / 9;
        } else {
            cout << "Bledna skala docelowa.\n";
            return 0;
        }
    } else {
        cout << "Bledna skala docelowa.\n";
        return 0;
    }

    return convertedTemperature;
}



int main() {
    while(1){
        int zad = 0;
        cout << "podaj zadanie do wyswietlenia (1-3): ";
        cin >> zad;
        switch (zad)
        {
        case 1:{
            int height;
            cout << "zadanie jeden rysowanie choinki + zapis do pliku:\n";
            cout << "Podaj wys. choinki (z zakresu 4-14): ";
            cin >> height;

            drawTree(height);   
            break;
        }

        case 2:{
            cout <<"Program bioracy liczby z klawiatury i konczy sie na podanych warunkach:\n";
            stat();
            cout <<"statystyka zapisana\n";
            break;

        }
        
        case 3:{
            double temperature;
            string sourceScale, targetScale;
            double convertedTemperature;

            cout << "Podaj wartosc temperatury: ";
            cin >> temperature;
            cout << "Podaj skale zrodlowa (C, K, F): ";
            cin >> sourceScale;
            cout << "Podaj skale docelowa (C, K, F): ";
            cin >> targetScale;

            convertedTemperature = convert(temperature, sourceScale, targetScale);
            cout << "Przeliczona temperatura: " << convertedTemperature << " " << targetScale << endl;

            break;
        }


        default:
            cout << "nie ma takiego zadania\n\n\n";
        }
    
    }
    return 0;
}
