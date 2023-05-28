import datetime

print('Algorytmy z rozgałęzieniami instrukcje warunkowe')
while True:
    zad = int(input('wyswietl zadanie: '))

    ###
    if(zad == 1):
        print('Zadanie 1.1 sprawdzania czy podana przez użytkownika liczba a jest wieksza od zera.')
        temp = int(input('podaj zmienna: '))
        if(temp)>0:
            print('zmienna A jest > 0')
        else:
            print('zmienna A nie jest > 0')
    ###
    if(zad == 2):
        print('Zadanie 1.2 sprawdzania czy podana przez użytkownika liczba a jest większa od 0, a mniejsza od 11')
        temp = int(input('podaj zmienna: '))
        if(temp>0 and temp <11):
            print('zmienna A jest > 0 i < 11')
        else:
            print('zmienna A nie jest > 0 i < 11')
    ###
    if(zad == 3):
        print('Zadanie 1.3 sprawdzania czy podana przez użytkownika liczba a jest większa od 0, a mniejsza od 11 lub większa od 17 a mniejsza od 21')
        temp = int(input('podaj zmienna: '))
        if(temp>0 and temp <11):
            print('A jest > 0 i < 11')
        elif(temp>17 and temp <21):
            print('A nie jest > 0 i < 11')
        else:
            print('A nie spelnia warunkow')
    ###
    if(zad == 4):
        print('Zadanie 1.4 sprawdzania czy podana przez użytkownika liczba a jest liczba całkowita.')
        temp = float(input('podaj zmienna: '))
        if(temp == int(temp)):
            print('zmienna A jest calkowita')
        else:
            print('zmienna A nie jest calkowita')
    ###
    if(zad == 5):
        print('Zadanie 1.5 sprawdzania czy podana przez użytkownika liczba a jest liczba całkowita i obliczania jej sumy cyfr.')
        temp = float(input('podaj zmienna: '))
        if(temp == int(temp)):
            result = 0
            digit = 0
            for digit in str(temp):
               if digit.isdigit():
                    result += int(digit)
            print('wynik wynosi ' + str(result))
        else:
            print('zmienna A nie jest calkowita')
    ###
    if(zad == 6):
        print('Zadanie 1.6 sprawdzania czy podana przez użytkownika liczba a jest liczba całkowita i sprawdzania, czy jest podzielna przez 2.')
        temp = float(input('podaj zmienna: '))
        if(temp == int(temp)):
            temp = int(temp)
            if(temp%2 == 0 ):
                print('zmienna A jest podzielna przez 2')
            else:
                print('zmienna A nie jest podzielna przez 2')
        else:
            print('zmienna A nie jest calkowita')
    ###
    if(zad == 7):
        print('Zadanie 1.6 sprawdzania czy podana przez użytkownika liczba a jest liczba całkowita i sprawdzania, czy jest podzielna przez 2.')
        temp = float(input('podaj zmienna: '))
        if(temp == int(temp)):
            temp = int(temp)
            if(temp%2 == 0 ):
                print('zmienna A jest podzielna przez 2')
            else:
                print('zmienna A nie jest podzielna przez 2')
        else:
            print('zmienna A nie jest calkowita')
    ###
    if(zad == 8):
        print('Zadanie 1.8 sprawdzania, czy podany przez użytkownika rok jest przestępny')
        temp = float(input('podaj rok: '))
        if(temp%4==0 and temp%100!=0 or temp%400==0):
            print('rok jest przestepny')
        else:
            print('rok nie jest przestepny')
    ###
    if(zad == 9):
        print('Zadanie 1.9 podawania daty w formacie - dzien:XX, miesiac:XX, rok:XXXX,gdzie X oznacza liczbę naturalna.')
        date = datetime.datetime.now().date()
        temp = date.strftime("dzien: %d miesiac: %m rok: %Y")
        print(temp)
    ###
    if(zad == 10):
        print('Zadanie 10 zmiana liczby 1-7 na odpowiedni dzien tygodnia + wykluczenie innych liczb')
        days = ["poniedzialek", "wtorek", "sroda", "czwartek", "piatek", "sobota", "niedziela"]
        temp = int(input('podaj liczbe 1-7 '))
        if(temp <=7 and temp >=1):
            print(days[temp-1])
        else:
            print('zla liczba')
    ###
    if(zad == 11):
        print('Zadanie 11 zmiana liczby 1-12 na odpowiedni miesiac + wykluczenie innych liczb')
        days = ['styczen', 'luty', 'marzec', 'kwiecien', 'maj', 'czerwiec', 'lipiec', 'sierpien', 'wrzesien', 'pazdziernik', 'listopad', 'grudzien']
        temp = int(input('podaj liczbe 1-12 '))
        if(temp <=12 and temp >=1):
            print(days[temp-1])
        else:
            print('zla liczba')
    if(zad == 12):
        print('Zadanie 1.12 sprawdzania przez które ćwiartki układu współrzędnych przechodzi prosta y = ax + b dla wczytanych przez użytkownika a, b')
        a = float(input('podaj a '))
        b = float(input('podaj b'))
        if(a==0):
            if(b==0):
                print('idzie po prostej x')
            elif(b>0):
                print('cwiartki 1 i 2')
            else:
                print('cwiartki 3 i 4')
        elif(a>0):
            if(b==0):
                print('cwiartki 1 i 3')
            elif(b>0):
                print('cwiartki 1, 2 i 3')
            else:
                print('cwiartki 1, 3 i 4')
        else:
            if(b==0):
                print('cwiartki 2 i 4')
            elif(b>0):
                print('cwiartki 1, 2 i 4')
            else:
                print('cwiartki 2, 3 i 4')
    if(zad ==13):
        print('Zadanie 1.13 obliczania wartości x dla danego równania ax + b = 0 (i sprawdzania, czy takie rozwiązanie istnieje- jeśli tak to ile!)')
        a = float(input('podaj a '))
        temp = float(input('podaj b '))
        if(a==0):
            print('rownanie nie ma rozwiazania')
        else:
            print(-temp/a)