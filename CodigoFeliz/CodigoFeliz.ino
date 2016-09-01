
int Cable1 = 13;
int Cable2 = 12;
int Cable3 = 11;
int Cable4 = 10;
int Umbral = 100;
int sensorDeLuz = A4;
int Tiempo = 1000;
int estado = 0;
void Paso1() {
  digitalWrite(Cable1, HIGH);
  digitalWrite(Cable2, LOW);
  digitalWrite(Cable3, LOW);
  digitalWrite(Cable4, LOW);
}
void Paso2() {
  digitalWrite(Cable1, LOW);
  digitalWrite(Cable2, HIGH);
  digitalWrite(Cable3, LOW);
  digitalWrite(Cable4, LOW);
}
void Paso3() {
  digitalWrite(Cable1, LOW);
  digitalWrite(Cable2, LOW);
  digitalWrite(Cable3, HIGH);
  digitalWrite(Cable4, LOW);
}
void Paso4() {
  digitalWrite(Cable1, LOW);
  digitalWrite(Cable2, LOW);
  digitalWrite(Cable3, LOW);
  digitalWrite(Cable4, HIGH);
}

void Automatica(){
  if (analogRead(sensorDeLuz) < Umbral) {
  Paso1();
    Paso2();
      Paso3();
        Paso4();
}
if (analogRead(sensorDeLuz) > Umbral) {
   Paso4();
    Paso3();
      Paso2();
        Paso1();
}
}
void Manual(int distancia) {
  if (distancia > 0) {
    for (int i = 0; i < distancia; i++) {
      Paso1();
       delay (100);
      Paso2();
      delay (100);
      Paso3();
      delay (100);
      Paso4();
      delay (100);
    }
    if (distancia < 0) {
      for (int i = 0; i > distancia; i--) {
        Paso4();
        Paso3();
        Paso2();
        Paso1();
      }
    }
  }
}

void setup() {
  Serial.begin (9600);
  pinMode (sensorDeLuz, INPUT);
  pinMode (Cable1, OUTPUT);
  pinMode (Cable2, OUTPUT);
  pinMode (Cable3, OUTPUT);
  pinMode (Cable3, OUTPUT);

}


void loop () {

Manual(1);

  int distancia = 0;
  char c = Serial.read();
  if (c == 'M') {
    estado = 0;
    distancia = Serial.parseInt();
  }

  if (estado == 1) {
    Automatica ();
  } else if (estado == 0) {
    Manual(distancia);
  }


}

