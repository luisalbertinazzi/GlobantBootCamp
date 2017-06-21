# GlobantBootCamp

Tetris

Para este proyecto decidí utilizar la librería SDL2 para los input, sonido y gráficos dado que al haber trabajado con la misma ya tenía el setup en mi computadora, y conozco sus funciones básicas. 
Para empezar voy a tener una clase denominada “Tetrómino”, la misma clase va a:
-	Guardar las 7 figuras de los tetrominos
-	Tener una variable de rotaciónActual enum
-	Una función que devuelva arreglo del Tetrómino girado

Las piezas están definidas en un arreglo bidimensional de 4x4. 

El arreglo bidimensional (para las piezas: cube,  I, L, espejoL, N, espejoN, y T) estaría lleno por: 0 representando espacios vacíos, 1 para pivote y 2 para bloques normales.

Ejemplo para T:

{0,0,0,0}

{0,0,2,0}

{0,0,1,2}

{0,0,2,0}

T rotada:

{0,0,0,0}

{0,0,0,0}

{0,2,1,2}

{0,0,2,0}


La idea me surgió porque para hacer mapas he trabajado con este tipo de arreglos, además al dibujarlo en una hoja tuve la idea de almacenar cada uno de los tetrominos en un arreglo de 4 dimensiones. ¿Esto que quiere decir?  Con un simple arreglo de 7x4x4x4 se solucionó. Se entiende así: si hay 7 piezas, con 4 rotaciones que debemos mostrar y cada pieza se encasilla en un arreglo de 4x4 podemos guardarlas en un arreglo de 7x4x4x4



En cuanto al tablero, vamos a tener otra clase denominada “board”  que va a:
-	Tener un array de 10x20 que comienza con todas las posiciones LIBRES (puede ser de tipo enum y contener 2 valores). A medida que se llena cada cuadro, cambian de estado.
-	Va a definir el alto, ancho, posición y márgenes
-	Contener una función que inicializa el board (llena todo en libre)
-	Contener otra función que GUARDE piezas, es decir, cambia el estado de los cubos a ocupado, dependiendo del Tetrómino (se tiene que llevar un Tetrómino)
-	Una función que libere UNA LINEA del arreglo a medida que se cambian totalmente a OCUPADO y este mismo puede volver a dibujar el tablero bajando las piezas. Puede actuar en conjunto otra función que vea cuantas líneas se deban eliminar y llame a la de liberar UNA LINEA cuando sea necesario (?)
-	Un método que chequee si un bloque esta vacío o no para poder luego detectar colisiones 
-	También vamos a necesitar métodos de get para los bloques, porque tenemos que detectarlos en Pixeles
-	Una función q devuelva un boolean que nos permita ver si el movimiento es posible o no utilizando los métodos anteriores para chequear colisiones

Iba a hacer en principio un tablero que solo DIBUJARA sobre la ventana del game o App, pero me pareció más fácil darle un poco más de utilidad al mismo y hacer que lleve en si un poco más de responsabilidad respecto a las piezas (con el chequeo de colisiones) 
Podríamos crear una clase CreaVent/CreatesWind/ImputOutput (Entrada y salida de datos)  que crea la ventana, la limpia, actualiza la pantalla y toma los input con SDL, en esta podríamos tener un enum con colores y así es más fácil en main (o APP) crear un objeto de la misma. Tiene métodos que:
-	Dibujan un rectángulo
-	Limpian pantalla
-	Un get para las teclas
-	Un actualizar pantalla
-	Uno que inicia gráfico
-	 Y uno que toma altura y ancho de pantalla
Sugiero crear esta clase para a la creación de ventanas y los eventos  AISLARLOS de la lógica del juego. 

Otra de las clases será nombrada GAME y tendrá todos los datos de board y Tetrómino (y de IO), y en ella ambas se relacionaran 
Esta clase tendrá:
-	PosX y posY de DONDE empieza en el tablero el Tetrómino (esto impide que muestre partes del arreglo vacías)
-	Una función que pregunte  al principio si la pieza puede entrar en el tablero, para tirar GameOver 
-	Variables como altura de pantalla, próximas posiciones del Tetrómino, próximo Tetrómino(y la rotación del mismo)
-	Tiene punteros (objetos) de board, Tetrómino y IO
-	Una función que inicia el juego, una que dibuja pieza y otra que dibuja el tablero 
-	Tenemos que agregar una función RAND para generar la pieza al azar, tiene que darle pieza y rotación con la que va a iniciar
-	Debe definir un tiempo de espera para loopear la bajada de la pieza
-	El constructor (como tiene que conocer el resto de los datos) debe llevarse un board, un Tetrómino, un IO y la pantalla donde trabajara
-	La función que inicializa el juego deberá (al menos) tener funciones que:
o	Seleccione la primer y segunda pieza al AZAR
o	Poner la pieza en POSICION
o	Saber rotación y tipo
o	Puede haber otro método que sea CREAR pieza, que llamemos para darle al puntero de siguiente una pieza nueva, entonces crearíamos en primer lugar la primera y segunda en la inicialización y luego usaríamos CREAR pieza para renovar la siguiente pieza
-	La función que dibuja tiene los colores de CrearVent, puede asignar aleatoriamente colores a los bloques con una llamada a rand, de ahí un switch puede asignarlos
-	El método de dibujar el tablero lo único que debería hacer es dibujar las líneas verticales y horizontales del tablero, así como las de la pieza que viene. Aunque si tenemos un fondo como el que se nos fue provisto podríamos cargarlo  y delimitar sin colores
-	Tal vez en vez de llamar a todo en App podríamos tener una función que llame a las que dibujan las piezas actual y siguiente además del tablero (?)
-	Una variable con puntos que se acumulan si una línea es eliminada
-	Una función que cambie el tiempo de espera para bajar la pieza cada 10 líneas eliminadas


La clase App (o sea nuestro main) va a tener que dibujar cada imagen una y otra vez, antes de cada movimiento chequea si es posible o no además del check en la posición INICIAL para ver si el jugador perdió. Estas funciones están en game, por lo que solo incluimos esta clase

La SDL nos permite tomar (de nuestra clase CrearVent) la ventana, y las teclas, entonces con un WHILE podemos decir que: “mientras no se apreté escape, el juego continua” 

App debería también tomar el tiempo actual (en milisegundos), el comando en la librería es SDL_GetTicks();

Un switch con los casos de las teclas presionadas (abajo, derecha e izquierda) debe hacer lo pertinente, acelerar la pieza, moverla.

Para girar deberíamos poner otras teclas, como A y S, o G y H. La SDL nos va a permitir tomar la entrada de manera sencilla, por lo que solo deberíamos imprimir en el lugar la pieza girada en cada caso (todo dentro del switch para los eventos)
