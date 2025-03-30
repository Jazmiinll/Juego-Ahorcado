Juego del Ahorcado en C++

Descripción:
Este proyecto es una implementación del clásico juego del Ahorcado en C++ utilizando Programación Orientada a Objetos (POO). El juego elige una palabra al azar de una lista predefinida y el jugador debe adivinarla antes de que se agoten los intentos.

Características: 
- Uso de clases para estructurar el código.
- Dibujo del ahorcado en la consola.
- Lista de palabras predefinida.
- Registro y almacenamiento de resultados en un archivo de texto.
- Menú interactivo con opciones para jugar, ver resultados y salir.

Instrucciones de Uso: 
- Al ejecutar el programa, se mostrará un menú con las siguientes opciones:
- Jugar partida: Inicia una nueva partida donde el jugador debe adivinar la palabra secreta.
- Mostrar lista de jugadores: Muestra los resultados almacenados de partidas anteriores.
- Salir: Cierra el programa.

En el juego, el jugador ingresa letras para tratar de adivinar la palabra oculta.
- Si el jugador adivina la palabra antes de agotar los intentos, gana la partida.
- Si el jugador falla 6 veces, pierde la partida y se muestra la palabra secreta.
- Los resultados se guardan en un archivo de texto resultados.txt.

Estructura del Código: 
- El código está organizado en dos clases principales:
- Clase Ahorcado: Maneja la lógica del juego, incluyendo la selección de palabras, verificación de letras, y dibujo del ahorcado.
- Clase Jugador: Se encarga de almacenar y mostrar los resultados de los jugadores en un archivo de texto.
