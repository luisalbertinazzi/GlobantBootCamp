# GlobantBootCamp
Tetris Project

In this project I used the SDL library. I worked a little bit with it some time ago, and i had it already installed in my computer.
For starters, there's going to be a class "Tetromino" which will do the following:
-Save the 7 tetrominos
-There's going to a variable "enum actualRotation" which will tell me the rotation position in which the piece is
-The getter for the position in which the piece is facing will return an array(4x4) depending on  "actualRotation"
-posX and posY will be 2 variables which will tell me where the piece starts ( so i can avoid showing empty spaces when the tetromino spawns)
Example for piece I:
{0,0,2,0,0}   //0 is an empty tile
{0,0,2,0,0}   //2 is a common piece
{0,0,1,0,0}   //1 is the PIVOTE
{0,0,2,0,0}

If there are 7 pieces, and 4 rotations for each one, and we're saving them in 4x4 arrays, we could use a 4-dimensional array 7x4x4x4

On the other hand we've got the board. This class will do the following:
- Have an array of 10x20 with all positiones filled with "free" (we can store an enum variable that has FREE and OCCUPIED )
- this class will define the height and widht of the board and it's edges
- There  will be a function that initializes the board on FREE
- There's also going to be a function that STORE pieces depending on it's shape and changes the "FREE" value to "OCCUPIED" 
- Have a function that asks if there's any piece that went above the board, so it can tell us if the game is over
- Have a function that will DELETE a line in case is full of OCCUPIED and will make all cubes move down, we can make another function that  will run a loop in which it'll see which lines we need to "FREE".
- There'll be a method that will checkif a tile is FREE or OCCUPIED
- Have a function that will return true or false depending on if the movement we tried to do is possible or not (Collisions)



Para este proyecto decidí utilizar la librería SDL2 para los imput, sonido y gráficos dado que al haber trabajado con la misma ya tenía el setup en mi compu, y conozco sus funciones básicas.
Para empezar voy a tener una clase denominada “Tetromino”, la misma clase va a:
-	Guardar las 7 figuras de los tetrominos
-	Tener una variable de rotaciónActual enum
-	Una función que devuelva arreglo del tetromino girado
-	PosX y posY de DONDE empieza en el tablero el tetromino (esto impide que muestre partes del arreglo vacías)
-	

El arreglo bidimensional (para las piezas: cube,  I, L, espejoL, N, espejoN, y T) estaría lleno por: 0 representando espacios vacíos, 1 para pivote y 2 para bloques normales.
Ejemplo para T:
{0,0,0,0,0}
{0,0,2,0,0}
{0,0,1,2,0}
{0,0,2,0,0}

La idea me surgió porque para hacer mapas he trabajado con este tipo de arreglos, además al dibujarlo en una hoja tuve la idea de almacenar cada uno de los tetrominos en un arreglo de 4 dimensiones. ¿Esto que quiere decir?  Con un simple arreglo de 7x4x4x4 se solucionó. Se entiende asi: si hay 7 piezas, con 4 rotaciones que debemos mostrar y cada pieza se encasilla en un arreglo de 4x4 podemos guardarlas en un arreglo de 7x4x4x4.

En cuanto al tablero, vamos a tener otra clase denominada “board”  que va a:
-	Tener un array de 10x20 que comienza con todas las posiciones LIBRES (puede ser de tipo enum y contener 2 valores). A medida que se llena cada cuadro, cambian de estado.
-	Va a definir el alto, ancho, posición y  márgenes
-	Contener una función que inicializa el board (llena todo en libre)
-	Contener otra función que GUARDE piezas, es decir, cambia el estado de los cubos a ocupado, dependiendo del tetromino (se tiene que llevar un tetromino)
-	Una función que pregunte si hay una pieza que salga del tablero, para tirar GameOver (puede que pongamos esta en la clase GAME también)
-	Una función que libere UNA LINEA del arreglo a medida que se cambian totalmente a OCUPADO y este mismo puede volver a dibujar el tablero bajando las piezas. Puede actuar en conjunto otra función que vea cuantas líneas se deban eliminar y llame a la de liberar UNA LINEA cuando sea necesario (?)
-	Un método que chequee si un bloque esta vacío o no para poder luego detectar colisiones 
-	Tambien vamos a necesitar métodos de get para los bloques, porque tenemos que detectarlos en Pixels
-	Una función q devuelva un  que nos permita ver si el movimiento es posible o no utlizando los métodos anteriores para chequear colisiones
Iba a hacer en principio un tablero que solo DIBUJARA sobre la ventana del game o app, pero me pareció más fácil darle un poco más de utilidad al mismo y hacer que lleve en si un poco más de responsabilidad respecto a las piezas (con el chequeo de colisiones) 




