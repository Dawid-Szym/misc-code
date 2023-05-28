#include <iostream>
#include <cmath>

using namespace std;
int main(){
    double Ax, Ay, Bx, By, r, alpha;
    cout << "Program do rysowania strzalki\nWprowadz dane:\nAx: ";
    cin >> Ax;//punk kola x
    cout << "\nAy: ";
    cin >> Ay;//punkt kola y
    cout << "\nBx: ";
    cin >> Bx;
    cout << "\nBy: ";
    cin >> By;
    cout << "\nr: ";
    cin >> r;
    cout << "\nKat alpha w stopniach(10<=alpha<=45): ";
    cin >> alpha;

    if(alpha>=10 &&alpha<=45){
        //funkcja ab
        double funa1 = (By - Ay) / (Bx - Ax);
        double funb1 = Ay - funa1 * Ax;
        //cout << endl<<funa1<<endl<<funb1<<endl<<endl;     testy
        //rownanie kw
        double tempa = 1 + pow(funa1, 2);
        double tempb = -2 * Ax + 2 * funa1 * (funb1 - Ay);
        double tempc = pow(Ax, 2) + pow(funb1 - Ay, 2) - pow(r, 2);
        double tempo = pow(tempb, 2) - 4 * tempa * tempc;
        //punkt D
        double Dx1 = (-tempb + sqrt(tempo)) / (2 * tempa);
        double Dx2 = (-tempb - sqrt(tempo)) / (2 * tempa);
        double Dy1 = funa1 * Dx1 + funb1;
        double Dy2 = funa1 * Dx2 + funb1;
        //cout <<endl<<Dx1<<" "<<Dy1<<endl<<Dx2<<" "<<Dy2<<endl<<endl;     testy
        //ktory jest prawdziwy
        double Dxtrue, Dytrue;
        if(Dx1>Ax &&Dx1<Bx){
            //Dx1
            Dxtrue=Dx1;
            Dytrue=Dy1;
        }else{
            //Dx2
            Dxtrue=Dx2;
            Dytrue=Dy2;
        }
        //cout << Dxtrue<<endl<<Dytrue;     testy
        //h i H
        double alphatrue= alpha * M_PI / 180.0;
        double h=(r/10)*cos(alphatrue);
        //cout <<h;
        double Hx1 = Dxtrue + sqrt(h * h / (1 + funa1 * funa1));
        double Hy1 = funa1 * Hx1 + funb1;
        double Hx2 = Dxtrue - sqrt(h * h / (1 + funa1 * funa1));
        double Hy2 = funa1 * Hx2 + funb1;
        //cout << Hx1 <<endl<<Hy1<<endl<<Hx2<<endl<<Hy2;     testy
        double Hxtrue, Hytrue;
        if(Hx1>Ax &&Hx1<Dxtrue){
            //Hx1
            Hxtrue=Hx1;
            Hytrue=Hy1;
        }else{
            //Hx2
            Hxtrue=Hx2;
            Hytrue=Hy2;
        }
       // cout <<Hxtrue<<endl<<Hytrue;
        double funa2 = -1 / funa1;
        double funb2 = Hytrue - funa2 * Hxtrue;
       // cout <<funa2 << endl << funb2;
        //odleglosc od promienia
        double dista=sin(alphatrue)*r/10;
        cout <<dista;
        tempa = sqrt(pow(dista, 2) / (1 + pow(funa2, 2)));
        tempb = funa2 * tempa;
        double Ex = Hxtrue + tempa;
        double Ey = Hytrue + tempb;
        double Fx = Hxtrue - tempa;
        double Fy = Hytrue - tempb;

        //cout << Ex <<endl<<Ey <<endl<<Fx <<endl<<Fy <<endl;     testy
        cout << "\nSzukane punkty maja takie wspolrzedne:\nPunkt D; x: "<<Dxtrue<< " y: "<< Dytrue<<"\nPunkt E; x: "<<Ex<<" y: "<<Ey<<"\nPunkt F; x: "<<Fx<<" y: "<<Fy;
        return 0;

    }else {
        cout << "Kat alpha jest spoza oczekiwanych wartosci (10<=alpha<=45)";
        return 0;
    }
    return 0;
}