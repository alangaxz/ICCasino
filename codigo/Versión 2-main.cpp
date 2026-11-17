#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <random>
using namespace std;

double Poker();
double Bacara();
double Ruleta();
double BlackJack();
double Tragamonedas();

int dinero = 0;

void depositarDinero() {
    float deposito = 0;
    while(deposito < 1) {
        cout<<"Dinero a depositar: $";
        cin>>deposito;
        if(deposito < 1) {
            cout<<"Valor invalido. Vuelva a intentarlo.\n";
        }
    }
    dinero += deposito;
}

int sacarCartaBJ(){
    int carta = (rand() % 13) + 1;
    if (carta > 10) {
        return 10;
    }
    return carta;
}

int numeroRuleta() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(-1, 36); // 00 = -1 e imprimir 00  / 0 = 0 / n = n
    int n = dist(gen);
    return n;
}
int n = numeroRuleta();

int colorRuleta() {
    enum colores {
        verde, rojo, negro, error // verde = 00/0 / rojo = impar / negro = par
    };
    if(n == 0 || n == -1) {
        return verde;
    }
    else if(n % 2 == 0) {
        return negro;
    }
    else if(n % 2 != 0) {
        return rojo;
    }
    else {
        return error;
    }
}

int menuRuleta() {
    int tipoA = 0;
    cout<<"------------BIENVENIDO A LA RULETA------------\n";
    cout<<"QUE APUESTA DESEAS HACER? (Introducir numero)\n";
    cout<<"1. Un numero...............(x36)\n";
    cout<<"2. 2 numeros seguidos......(x18)\n";
    cout<<"3. 3 numeros seguidos......(x12)\n";
    cout<<"4. 4 numeros seguidos......(x9)\n";
    cout<<"5. 5 numeros seguidos......(x7)\n";
    cout<<"6. Media docena............(x6)\n";
    cout<<"7. Docena..................(x3)\n";
    cout<<"8. Mitad...................(x2)\n";
    cout<<"9. Verde(00 / 0)...........(x20)\n";
    cout<<"10. Rojo/negro.............(x2)\n";

    while(tipoA < 1 || tipoA > 10) {
        cout<<"APUESTA DESEADA: ";
        cin>>tipoA;
        if(tipoA < 1 || tipoA > 10) {
            cout<<"Dato invalido. Vuelva a intentarlo\n";
        }
    }
    return tipoA;
}

int dineroApuesta() {
    int apuesta = 0, dineroInicial = dinero;
    do {
        cout<<"Cuentas con $"<<dinero<<endl;
        cout<<"Dinero a apostar: $";
        cin>>apuesta;
        if(apuesta>dinero) {
            cout<<"Cantidad insuficiente. Vuelva a intentarlo\n";
        }
        else if(apuesta<1) {
            cout<<"Cantidad invalida. Vuelva a intentarlo\n";
        } else {
            dinero -= apuesta;
        }
    } while(apuesta > dineroInicial || apuesta < 1);
    return apuesta;
}



void menu1() {
        cout<<"=================================================================================="<<endl;
        cout<<"=================================================================================="<<endl;
        cout<<"=======                ========              ===========                =========="<<endl;
        cout<<"============     ============     =====================     ======================"<<endl;
        cout<<"============     ===========    ======================     ======================="<<endl;
        cout<<"============     ===========    ======================     ======================="<<endl;
        cout<<"============     ===========    ======================     ======asino============"<<endl;
        cout<<"============     ===========    ======================     ======================="<<endl;
        cout<<"============     ===========    ======================     ======================="<<endl;
        cout<<"============     ============     =====================     ======================"<<endl;
        cout<<"=======                 ======               ===========                =========="<<endl;
        cout<<"=================================================================================="<<endl;
        cout<<"=================================================================================="<<endl;
        cout<<endl;
        cout<<endl;
    int p;
    do {
        cout<<"1. Jugar" << endl;
        cout<<"2. Reglas" << endl;
        cout<<"3. Salir" << endl;
        cin>> p;

        switch(p){
            case 1:
                {
                int a;
                cout<< "Juegos que tenemos dentro del ICCasino" << endl;
                cout<< "1. Poker"<< endl;
                cout<< "2. Bacara"<< endl;
                cout<< "3. Ruleta"<< endl;
                cout<< "4. BlackJack"<< endl;
                cout<< "5. Tragamonedas"<< endl;
                cout<< "6. Salir"<< endl;
                cout<< "Elige un juego: ";
                cin>> a;

                int resultado = 0;

                switch(a) {
                    case 1:
                        resultado = Poker();
                        break;
                    case 2:
                        resultado= Bacara();
                        break;
                    case 3:
                        resultado = Ruleta();
                        break;
                    case 4:
                        resultado = BlackJack();
                        break;
                    case 5:
                        resultado = Tragamonedas();
                        break;
                    case 6:
                        cout<<"Regresae"<< endl;
                        break;
                    default:
                        cout<<"error"<<endl;
                }
                break;
            }
            case 2:
                {
                int b;
                cout << "Reglas de los juegos" << endl;
                cout << "1. Poker" << endl;
                cout << "2. Bacara" << endl;
                cout << "3. Ruleta" << endl;
                cout << "4. BlackJack" << endl;
                cout << "5. Tragamonedas" << endl;
                cout << "6. Salir" << endl;
                cin >> b;

                //Aqui van a ir las reglas
                switch(b) {
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 6:
                        cout<<"Regresar"<< endl;
                        break;
                    default:
                        cout<<"error"<<endl;
                }
                break;
            }
            case 3:
                cout<< "Lo esperamos pronto" << endl;
                break;
            default:
                cout<<"error" << endl;
        }
    }while (p!= 3);
}

//Aqui van los juegos
    double Poker(){
        return 0.0;
    };

    double Bacara(){
        return 0.0;
    };

    double Tragamonedas(){
        return 0.0;
    };

    double BlackJack(){
        int opcionBJ;
        do {
            cout << "----------BLACKJACK----------\n";
            cout << "1. Empezar\n";
            cout << "2. Regresar\n" << endl;
            cin >> opcionBJ;

    switch (opcionBJ){
        case 1: {
        int otraBJ, sumaJugadorBJ, sumaCrupierBJ, ASBJ;
        bool ASJugadorBJ = false, ASCrupierBJ = false;
            vector<int> carta;
            cout << "-----Partida BlackJack-----\n" << endl;
            for (int i = 0; i < 4; i++){
            carta.push_back(sacarCartaBJ());
            }
            cout << "Tu primera carta: " << carta[0] << "\n";
            cout << "Tu segunda carta: " << carta[1] << "\n" << endl;
            if (carta[0] == 1 || carta[1] == 1){
                do {
                cout << "¿Quieres dejar tu AS con valor de 1 u 11?" << endl;
                cin >> ASBJ;
                if (ASBJ == 11){
                    if (carta[0] == 1){
                        carta[0] = 11;
                        ASJugadorBJ = true;
                    }
                    else if (carta[1] == 1){
                        carta[1] = 11;
                        ASJugadorBJ = true;
                    }
                }
                else if (ASBJ != 1 && ASBJ != 11){
                    cout << "Error, vuelva a ingresar la opcion\n" << endl;
                }
            } while (ASBJ != 1 && ASBJ != 11);
            }
            sumaJugadorBJ = carta[0] + carta[1];
            cout << "Tu suma es: " << sumaJugadorBJ << "\n" << endl;
            cout << "Primera del crupier: " << carta[2] << "\n";
            cout << "Carta secreta: X\n" << endl;
            if (carta[2] == 1){
                carta[2] = 11;
                ASCrupierBJ = true;
            }
            if (carta[3] == 1) {
                if (carta[2] + 11 <= 21) {
                    carta[3] = 11;
                    ASCrupierBJ = true;
                }
            }
            if (sumaJugadorBJ == 21){
                if (carta[2] + carta[3] == 21){
                    cout << "Empataron, la carta secreta del Crupier es: " << carta[3] << ", y suma 21" << endl;
                    break;
                }
                else {
                cout << "\n¡Ganaste! La carta secreta del Crupier era " << carta[3] << " y suma " << carta[2] + carta[3] << endl;
                break;
                }
            }
            do {
                if (sumaJugadorBJ >= 21) break;
                cout << "¿Deseas pedir otra carta? \n";
                cout << "1. Si\n";
                cout << "2. No\n";
                cin >> otraBJ;
                while (otraBJ != 1 and otraBJ != 2){
                    cout << "\nError, vuelva a ingresar la opcion." << endl;
                    cin >> otraBJ;
                }
                if (otraBJ == 1){
                    int nuevaCartaBJ = sacarCartaBJ();
                    cout << "Tu nueva carta: " << nuevaCartaBJ << endl;
                    if (nuevaCartaBJ == 1) {
                        do {
                        cout << "¿Quieres dejar tu AS con valor de 1 u 11?" << endl;
                        cin >> ASBJ;
                        if (ASBJ == 11){
                        nuevaCartaBJ = 11;
                        ASJugadorBJ = true;
                        }
                        else if (ASBJ == 1){
                        nuevaCartaBJ = 1;
                        }
                        else {
                            cout << "Error, vuelva a ingresar la opcion." << endl;
                        }
                        } while (ASBJ != 1 && ASBJ != 11);
                    }
                    carta.push_back(nuevaCartaBJ);
                    sumaJugadorBJ += nuevaCartaBJ;
                    if (sumaJugadorBJ > 21 && ASJugadorBJ == true){
                        sumaJugadorBJ -= 10;
                        ASJugadorBJ = false;
                    }
                    cout << "Suma actual: " << sumaJugadorBJ << "\n" << endl;
                    if (sumaJugadorBJ > 21){
                        cout << "Perdiste." << endl;
                        break;
                    }
                }
            } while (sumaJugadorBJ < 21 && otraBJ == 1);

            if (sumaJugadorBJ <= 21) {
            cout << "\nTurno del Crupier" << endl;
            cout << "Carta oculta: " << carta[3] << endl;
            sumaCrupierBJ = carta[2] + carta[3];
            cout << "Suma actual: " << sumaCrupierBJ << endl;
            while (sumaCrupierBJ < 17){
                int nuevaCartaCrupierBJ = sacarCartaBJ();
                if (nuevaCartaCrupierBJ == 1){
                    if (sumaCrupierBJ + 11 <= 21){
                        nuevaCartaCrupierBJ = 11;
                        ASCrupierBJ = true;
                    }
                }
                sumaCrupierBJ += nuevaCartaCrupierBJ;
                if (sumaCrupierBJ > 21 && ASCrupierBJ == true){
                    sumaCrupierBJ -= 10;
                    ASCrupierBJ = false;
                }
                cout << "Nueva carta Crupier: " << nuevaCartaCrupierBJ << endl;
                cout << "Suma Crupier: " << sumaCrupierBJ << "\n" << endl;
                if (sumaCrupierBJ > 21){
                    cout << "El crupier tiene mas de 21. ¡Ganaste!" << endl;
                    break;
                }
            }

            if (sumaJugadorBJ > sumaCrupierBJ && sumaJugadorBJ <= 21){
                cout << "¡Ganaste!" << endl;
                break;
            }
            else if (sumaJugadorBJ < sumaCrupierBJ && sumaCrupierBJ <= 21){
                cout << "Perdiste" << endl;
                break;
            }
            else if (sumaJugadorBJ == sumaCrupierBJ && sumaCrupierBJ <= 21){
                cout << "Empate, nadie gana nada." << endl;
                break;
            }
            }
        } break;

        case 2:
            cout << "Regresando al menu principal...\n" << endl;
            break;

        default:
            cout << "Opcion invalida. Por favor, elige 1 o 2.\n" << endl;
            break;
    }
    } while (opcionBJ != 2);
        return 0.0;
    };

    double Ruleta(){
        int casilla = 0;

    int tipoA = menuRuleta();

    int apuesta = dineroApuesta();

    switch(tipoA) {
    case 1:
        do {
            cout<<"Numero seleccionado (-1 para 00): ";
            cin>>casilla;
            if(casilla < -1 || casilla > 36) {
                cout<<"Numero invalido. Vuelva a intentarlo en un rango de -1 y 36\n";
            }
        } while(casilla < -1 || casilla > 36);

        if(n==-1) {
            cout<<"GIRA LA RULETA Y CAE EN.............00!!\n";
        }
        else {
            cout<<"GIRA LA RULETA Y CAE EN............."<<n<<"!!\n";
        }

        if(casilla == n) {
            cout<<"GANASTE!!! HAS GANADO $"<<apuesta*36<<endl;
            dinero += (apuesta*36);
        }
        else {
            cout<<"PERDISTE!!\n";
        }
        break;
    case 2:
        do {
            cout<<"Primer numero del par (-1 para 00): ";
            cin>>casilla;
            if(casilla < -1 || casilla > 35) {
                cout<<"Numero invalido. Vuelva a intentarlo en un rango de -1 y 35\n";
            }
        } while(casilla < -1 || casilla > 35);

        if(n==-1) {
            cout<<"GIRA LA RULETA Y CAE EN.............00!!\n";
        }
        else {
            cout<<"GIRA LA RULETA Y CAE EN............."<<n<<"!!\n";
        }

        if(casilla == n || casilla+1 == n) {
            cout<<"GANASTE!!! HAS GANADO $"<<apuesta*18<<endl;
            dinero += (apuesta*18);
        }
        else {
            cout<<"PERDISTE!!\n";
        }
        break;
    case 3:
        do {
            cout<<"Primer numero del grupo (-1 para 00): ";
            cin>>casilla;
            if(casilla < -1 || casilla > 34) {
                cout<<"Numero invalido. Vuelva a intentarlo en un rango de -1 y 34\n";
            }
        } while(casilla < -1 || casilla > 34);

        if(n==-1) {
            cout<<"GIRA LA RULETA Y CAE EN.............00!!\n";
        }
        else {
            cout<<"GIRA LA RULETA Y CAE EN............."<<n<<"!!\n";
        }

        if(casilla == n || casilla+1 == n || casilla+2 == n) {
            cout<<"GANASTE!!! HAS GANADO $"<<apuesta*12<<endl;
            dinero += (apuesta*12);
        }
        else {
            cout<<"PERDISTE!!\n";
        }
        break;
    case 4:
        do {
            cout<<"Primer numero del grupo (-1 para 00): ";
            cin>>casilla;
            if(casilla < -1 || casilla > 33) {
                cout<<"Numero invalido. Vuelva a intentarlo en un rango de -1 y 33\n";
            }
        } while(casilla < -1 || casilla > 33);

        if(n==-1) {
            cout<<"GIRA LA RULETA Y CAE EN.............00!!\n";
        }
        else {
            cout<<"GIRA LA RULETA Y CAE EN............."<<n<<"!!\n";
        }

        if(casilla == n || casilla+1 == n || casilla+2 == n || casilla+3 == n) {
            cout<<"GANASTE!!! HAS GANADO $"<<apuesta*9<<endl;
            dinero += (apuesta*9);
        }
        else {
            cout<<"PERDISTE!!\n";
        }
        break;
    case 5:
        do {
            cout<<"Primer numero del grupo (-1 para 00): ";
            cin>>casilla;
            if(casilla < -1 || casilla > 32) {
                cout<<"Numero invalido. Vuelva a intentarlo en un rango de -1 y 32\n";
            }
        } while(casilla < -1 || casilla > 32);

        if(n==-1) {
            cout<<"GIRA LA RULETA Y CAE EN.............00!!\n";
        }
        else {
            cout<<"GIRA LA RULETA Y CAE EN............."<<n<<"!!\n";
        }

        if(casilla == n || casilla+1 == n || casilla+2 == n || casilla+3 == n || casilla+4 == n) {
            cout<<"GANASTE!!! HAS GANADO $"<<apuesta*7<<endl;
            dinero += (apuesta*7);
        }
        else {
            cout<<"PERDISTE!!\n";
        }
        break;
    case 6:
        do {
            cout<<"Primer numero de la media docena (-1 para 00): ";
            cin>>casilla;
            if(casilla < -1 || casilla > 31) {
                cout<<"Numero invalido. Vuelva a intentarlo en un rango de -1 y 31\n";
            }
        } while(casilla < -1 || casilla > 31);

        if(n==-1) {
            cout<<"GIRA LA RULETA Y CAE EN.............00!!\n";
        }
        else {
            cout<<"GIRA LA RULETA Y CAE EN............."<<n<<"!!\n";
        }

        if(casilla == n || casilla+1 == n || casilla+2 == n || casilla+3 == n || casilla+4 == n || casilla+5 == n) {
            cout<<"GANASTE!!! HAS GANADO $"<<apuesta*6<<endl;
            dinero += (apuesta*6);
        }
        else {
            cout<<"PERDISTE!!\n";
        }
        break;
    case 7:
        while(casilla < 1 || casilla > 3) {
            cout<<"Escoge(Introducir numero):\n1. Primera docena(1-12)\n2. Segunda docena (13-24)\n3. Tercera docena (25-36)\n";
            cin>>casilla;
            if(casilla < 1 || casilla > 3) {
                cout<<"Numero invalido. Vuelva a intentarlo en un rango de 1 y 3\n";
            }
        }

        if(n==-1) {
            cout<<"GIRA LA RULETA Y CAE EN.............00!!\n";
        }
        else {
            cout<<"GIRA LA RULETA Y CAE EN............."<<n<<"!!\n";
        }

        switch(casilla) {
        case 1:
            if(n >= 1 && n<= 12) {
                cout<<"GANASTE!!! HAS GANADO $"<<apuesta*3<<endl;
                dinero += (apuesta*3);
            }
            else {
                cout<<"PERDISTE!!\n";
            }
            break;
        case 2:
            if(n >= 13 && n<= 24) {
                cout<<"GANASTE!!! HAS GANADO $"<<apuesta*3<<endl;
                dinero += (apuesta*3);
            }
            else {
                cout<<"PERDISTE!!\n";
            }
            break;
        case 3:
            if(n >= 25 && n<= 36) {
                cout<<"GANASTE!!! HAS GANADO $"<<apuesta*3<<endl;
                dinero += (apuesta*3);
            }
            else {
                cout<<"PERDISTE!!\n";
            }
            break;
        default:
            cout<<"ERROR!\n";
        }
        break;
    case 8:
        while(casilla < 1 || casilla > 2) {
            cout<<"Escoge primera (1) o segunda (2) mitad (1-18 / 19-36). Introducir numero.\n";
            cin>>casilla;
            if(casilla < 1 || casilla > 2) {
                cout<<"Numero invalido. Vuelva a intentarlo en un rango de 1 y 2\n";
            }
        }

        if(n==-1) {
            cout<<"GIRA LA RULETA Y CAE EN.............00!!\n";
        }
        else {
            cout<<"GIRA LA RULETA Y CAE EN............."<<n<<"!!\n";
        }

        switch(casilla) {
        case 1:
            if(n >= 1 && n<= 18) {
                cout<<"GANASTE!!! HAS GANADO $"<<apuesta*2<<endl;
                dinero += (apuesta*2);
            }
            else {
                cout<<"PERDISTE!!\n";
            }
            break;
        case 2:
            if(n >= 19 && n<= 36) {
                cout<<"GANASTE!!! HAS GANADO $"<<apuesta*2<<endl;
                dinero += (apuesta*2);
            }
            else {
                cout<<"PERDISTE!!\n";
            }
            break;
        default:
            cout<<"ERROR!\n";
        }
        break;
    case 9:
        if(n==-1) {
            cout<<"GIRA LA RULETA Y CAE EN.............00!!\n";
        }
        else {
            cout<<"GIRA LA RULETA Y CAE EN............."<<n<<"!!\n";
        }

        if(n == -1 || n == 0) {
            cout<<"GANASTE!!! HAS GANADO $"<<apuesta*20<<endl;
            dinero += (apuesta*20);
        }
        else {
                cout<<"PERDISTE!!\n";
        }
        break;
    case 10:
        while(casilla < 1 || casilla > 2) {
            cout<<"Rojo(1) o negro(2)? Introducir numero\n";
            cin>>casilla;
            if(casilla < 1 || casilla > 2) {
                cout<<"Numero invalido. Vuelva a intentarlo en un rango de 1 y 2\n";
            }
        }
        if(n==-1) {
            cout<<"GIRA LA RULETA Y CAE EN.............00(verde)!!\n";
        }
        else {
            cout<<"GIRA LA RULETA Y CAE EN............."<<n<<"(";
            switch(colorRuleta()) {
            case 0:
                cout<<"verde";
                break;
            case 1:
                cout<<"rojo";
                break;
            case 2:
                cout<<"negro";
                break;
            default:
                cout<<"ERROR!";
                break;
            }
            cout<<")!!\n";
        }

        if(casilla == colorRuleta()) {
            cout<<"GANASTE!!! HAS GANADO $"<<apuesta*2<<endl;
            dinero += (apuesta*2);
        }
        else {
            cout<<"PERDISTE!!\n";
        }
        break;
    default:
        cout<<"ERROR!\n";
    }

    cout<<"Dinero actual: $"<<dinero<<endl; // borrar esto (era para la prueba)
        return 0.0;
    };



int main() {
    srand(time(0));
    menu1();

    return 0;
}
