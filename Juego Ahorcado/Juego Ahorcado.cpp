// Juego Ahorcado.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <vector> 
#include <cstdlib> //permite utilizar rand y srand
#include <ctime> //permite manipular el tiempo para iniciar el generador de numeros aleatorios
#include <fstream> //permite leer y escribir archivos.
#include <string>//permite manejar las cadenas de texto

using namespace std;

//Clase que representa el juego del ahorcado
class Ahorcado {
private:
    vector<string> palabras;  // Lista de palabras posibles
    string palabraSecreta;  // La palabra secreta a adivinar
    string palabraAdivinada; // Palabra que el jugador adivina
    int intentosFallidos = 0; // Inicializa los intentos fallidos a 0
    vector<char> letrasIncorrectas; // Letras incorrectas que el jugador ha adivinado

public:
    void iniciarJuego(); // Inicializa el juego
    bool jugar(); // Función principal para jugar
    void mostrarEstado(); // Muestra el estado del juego
};

// Clase que maneja los resultados de los jugadores
class Jugador {
public:
    void guardarResultado(string nombre, bool gano); // Guarda el resultado del jugador en un archivo
    void mostrarResultados(); // Muestra los resultados de todos los jugadores
};

//Funcion para limpiar pantalla
void limpiarPantalla() {
    system("cls");
}

// Función que dibuja el ahorcado según el número de intentos fallidos
void dibujarAhorcado(int intentos) {
    switch (intentos) {
    case 0:
        cout << "  --------" << endl;
        cout << "  |      |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << " ---" << endl;
        break;

    case 1:
        cout << "  --------" << endl;
        cout << "  |      |" << endl;
        cout << "  |      O" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << " ---" << endl;
        break;

    case 2:
        cout << "  --------" << endl;
        cout << "  |      |" << endl;
        cout << "  |      O" << endl;
        cout << "  |      |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << " ---" << endl;
        break;

    case 3:
        cout << "  --------" << endl;
        cout << "  |      |" << endl;
        cout << "  |      O" << endl;
        cout << "  |     /|" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << " ---" << endl;
        break;

    case 4:
        cout << "  --------" << endl;
        cout << "  |      |" << endl;
        cout << "  |      O" << endl;
        cout << "  |     /|\\" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << " ---" << endl;
        break;
    case 5:
        cout << "  --------" << endl;
        cout << "  |      |" << endl;
        cout << "  |      O" << endl;
        cout << "  |     /|\\" << endl;
        cout << "  |     /" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << " ---" << endl;
        break;

    case 6:
        cout << "  --------" << endl;
        cout << "  |      |" << endl;
        cout << "  |      O" << endl;
        cout << "  |     /|\\" << endl;
        cout << "  |     / \\" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << " ---" << endl;
        break;

    default:
        break;
    }
}

// Inicializa los atributos para un nuevo juego
void Ahorcado::iniciarJuego() {
    // Lista de palabras posibles
    palabras = { "gato", "perro", "computadora", "programar", "teclado",
                 "pantalla", "codigo", "variable", "funcion", "clase",
                 "objeto", "estructura", "vector", "puntero", "memoria",
                 "archivo", "ingenieria", "universidad", "desarrollo", "depuracion" };
    srand(time(0)); // Inicializa el generador de números aleatorios con el tiempo actual
    palabraSecreta = palabras[rand() % palabras.size()]; // Selecciona una palabra aleatoria
    palabraAdivinada = string(palabraSecreta.length(), '_'); // Crea una palabra secreta con guiones bajos
    intentosFallidos; // Número de intentos fallidos
}

// Ejecuta el juego
bool Ahorcado::jugar() {
    iniciarJuego();// Inicia un nuevo juego
    char letra; // Letra que el jugador ingresa
    bool acierto; // Indica si el jugador acertó la letra o no

    // Mientras haya intentos disponibles y la palabra no se haya adivinado
    while (intentosFallidos < 6 && palabraAdivinada != palabraSecreta) {
        cout << "\n::: A H O R C A D O :::\n";
        mostrarEstado(); // Muestra el estado actual del juego
        cout << "Ingresa una letra: ";
        cin >> letra;

        acierto = false; // Asume que no hubo acierto inicialmente
        // Recorre cada letra de la palabra secreta
        for (size_t i = 0; i < palabraSecreta.length(); i++) {
            if (palabraSecreta[i] == letra) { // Si la letra coincide con la palabra secreta
                palabraAdivinada[i] = letra; // Reemplaza el guion bajo por la letra correcta
                acierto = true; // Se ha acertado la letra
            }
        }

        if (!acierto) { // Si no se acerto, incrementa los intentos fallidos
            intentosFallidos++;
            letrasIncorrectas.push_back(letra); // Agrega la letra incorrecta a la lista
        }
        limpiarPantalla(); //Limpia la pantalla para el siguiente turno
    }

    // Muestra el estado actual del juego (palabra con letras adivinadas y partes del ahorcado)
    mostrarEstado();

    // Verifica si el jugador ha adivinado toda la palabra
    if (palabraAdivinada == palabraSecreta) {
        cout << "Felicidades, has ganado. La palabra era: " << palabraSecreta << endl;
        return true;  // Retorna 'true' indicando que el jugador ganó
    }
    else {
        cout << "Lo siento, perdiste. La palabra era: " << palabraSecreta << endl;
        return false;  // Retorna 'false' indicando que el jugador perdió
    }
}

// Muestra el estado actual del juego
void Ahorcado::mostrarEstado() {
    dibujarAhorcado(intentosFallidos); // Dibuja el ahorcado según los intentos fallidos
    cout << "\nPalabra: " << palabraAdivinada << endl; // Muestra la palabra parcialmente adivinada
    cout << "Intentos fallidos: " << intentosFallidos << " / 6" << endl; // Muestra los intentos fallidos
    cout << "Letras incorrectas: ";

    // Muestra las letras incorrectas que el jugador ha adivinado
    for (char letra : letrasIncorrectas) cout << letra << " ";
    cout << endl;
}

// Guarda el resultado del jugador en un archivo de texto
void Jugador::guardarResultado(string nombre, bool gano) {
    ofstream archivo("resultados.txt");
    if (archivo.is_open()) {
        if (gano) {  // Si el jugador ganó (gano == true)
            archivo << nombre << " - Gano" << endl;
        }
        else {     // Si el jugador perdió (gano == false)
            archivo << nombre << " - Perdio" << endl;
        }
        archivo.close();
    }
}

// Muestra los resultados de todos los jugadores almacenados en el archivo
void Jugador::mostrarResultados() {
    limpiarPantalla();
    ifstream archivo("resultados.txt"); //Abre el archivo para leer los resultados
    string linea;

    // Lee y muestra cada línea del archivo
    cout << ":: Lista de jugadores ::\n";
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close(); // Cierra el archivo
    }
    else {
        cout << "No hay resultados aun.\n"; // Si no hay resultados, muestra un mensaje
    }
}

// Funcion principal del juego
int main() {
    int opcion;  // Variable para almacenar la opcion elegida por el usuario
    string nombre;  // Variable para almacenar el nombre del jugador

    do {
        limpiarPantalla(); // Limpia la pantalla para una mejor visualizacion

        // Muestra las opciones del menu principal del juego
        cout << "::: MENU DEL JUEGO :::\n";
        cout << "1. Jugar partida\n";
        cout << "2. Mostrar lista de jugadores. " << endl;
        cout << "3. Salir. " << endl;
        cout << " Elige una opcion: ";
        cin >> opcion;  // Captura la opcion del usuario

        limpiarPantalla();  // Limpia la pantalla después de elegir una opción

        switch (opcion) {
        case 1: {  // Opcion para iniciar una nueva partida
            cout << "::: R E G I S T R O ::: \n";
            cout << "Jugador: "; // Solicita el nombre del jugador
            cin >> nombre;

            Ahorcado juego;  // Crea un objeto de la clase Ahorcado
            bool gano = juego.jugar(); // Inicia el juego y obtiene si el jugador ganó

            Jugador jugador;  // Crea un objeto de la clase Jugador
            jugador.guardarResultado(nombre, gano); // Guarda el resultado en el archivo

            cout << "\nPresiona Enter para continuar...";
            cin.ignore(); // Evita que la entrada anterior cause problemas
            cin.get(); // Espera que el usuario presione Enter antes de continuar
            break;
        }
        case 2: {  // Opcion para mostrar la lista de jugadores
            Jugador jugador;
            jugador.mostrarResultados(); // Llama a la funcion para mostrar los resultados 

            cout << "\nPresiona Enter para continuar...";
            cin.ignore(); // Evita que la entrada anterior cause problemas
            cin.get(); // Espera que el usuario presione Enter antes de continuar
            break;
        }
        case 3:
            cout << "Gracias por jugar. Vuelve pronto\n"; // Mensaje de despedida
            return 0;  // Termina el programa
            break;
        default:
            cout << "Opcion no valida. Intenta de nuevo.\n"; // Mensaje si la opción no es válida
            cin.ignore(); // Evita que la entrada anterior cause problemas
            cin.get(); // Espera que el usuario presione Enter antes de continuar
        }
    } while (opcion != 3); // Continúa el ciclo hasta que el jugador elija salir

    return 0;  // Retorno de la funcion principal
}