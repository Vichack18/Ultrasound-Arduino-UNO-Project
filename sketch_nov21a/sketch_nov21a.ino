int eco = 4; // se aclara para nosotros en que pin va a estar el eco del ultrasonido //
int trig = 2;
int tiempopulso; // Lo usamos para contar los microsegundos que pasan desde que se emitio la onda hasta que volvio //
int distancia;

void setup() {
  // put your setup code here, to run once:
pinMode ( eco, INPUT);
pinMode ( trig, OUTPUT);
Serial.begin(9600); // Imprime todos los datos que queremos imprimir a traves de la pc //
// se establece una velocidad de 9600 bit por segundo para que no se pisen ( arduino y pc) //
//en la transferencia de datos ( se ponen de acuerdo ) //

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite( trig, HIGH);
delayMicroseconds (10); // El segundo se divide en 10.000 partes en vez de 1.000 //
digitalWrite (trig , LOW);

tiempopulso = pulseIn (eco , HIGH);  // pulseIn funcion que simplifica lineas de codigo, le dice al arduino que //
// tome el tiempo entre una funcion y otra,  que tome el tiempo hasta que haya un cambio de estado en //
// la variable que le pusimos //

distancia = 0.034 / 2 * tiempopulso; // Formula/Funcion de Fisica (de sonido) utilizada para saber la distancia //
// en la que fue y volvio el sonido, con esta funcion le decimos al arduino que en ves de darnos //
// el tiempo, que nos de la distancia //
// 0.034 es la distancia que recorre el sonido en el tiempo que le estamos diciendo (tiempopulso), y //
// dividido por dos ya que va y vuelve //

Serial.println (distancia);

}
