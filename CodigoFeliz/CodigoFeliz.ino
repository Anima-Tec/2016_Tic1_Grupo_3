
int Cable1 = 13;
int Cable2 = 12;
int Cable3 = 11;
int Cable4 = 10;
int Umbral = 100;
int sensorDeLuz = A4;
int Tiempo = 1000;
int estado = 0;
void Paso0() {
  digitalWrite(Cable1, LOW);
  digitalWrite(Cable2, LOW);
  digitalWrite(Cable3, LOW);
  digitalWrite(Cable4, LOW);
}
void Paso1() {
  digitalWrite(Cable1, HIGH);
  digitalWrite(Cable2, LOW);
  digitalWrite(Cable3, HIGH);
  digitalWrite(Cable4, LOW);
}
void Paso2() {
  digitalWrite(Cable1, HIGH);
  digitalWrite(Cable2, LOW);
  digitalWrite(Cable3, LOW);
  digitalWrite(Cable4, LOW);
}
void Paso3() {
  digitalWrite(Cable1, HIGH);
  digitalWrite(Cable2, LOW);
  digitalWrite(Cable3, LOW);
  digitalWrite(Cable4, HIGH);
}
void Paso4() {
  digitalWrite(Cable1, LOW);
  digitalWrite(Cable2, LOW);
  digitalWrite(Cable3, LOW);
  digitalWrite(Cable4, HIGH);
}
void Paso5() {
  digitalWrite(Cable1, LOW);
  digitalWrite(Cable2, HIGH);
  digitalWrite(Cable3, LOW);
  digitalWrite(Cable4, HIGH);
}
void Paso6() {
  digitalWrite(Cable1, LOW);
  digitalWrite(Cable2, HIGH);
  digitalWrite(Cable3, LOW);
  digitalWrite(Cable4, LOW);
}
void Paso7() {
  digitalWrite(Cable1, LOW);
  digitalWrite(Cable2, HIGH);
  digitalWrite(Cable3, HIGH);
  digitalWrite(Cable4, LOW);
}
void Paso8() {
  digitalWrite(Cable1, LOW);
  digitalWrite(Cable2, LOW);
  digitalWrite(Cable3, HIGH);
  digitalWrite(Cable4, LOW);
}


void Automatica() {
  if (analogRead(sensorDeLuz) > Umbral) {
    Paso0();
    delay(10);
    /*Paso1();
      delay(10);
      Paso2();
      delay(10);*/
    Paso3();
    delay(10);
    /* Paso4();
      delay(10);
      Paso5();
      delay(10);*/
    Paso6();
    delay(10);
    /* Paso7();
      delay(10);*/
    Paso8();
    delay(10);
  }
  if (analogRead(sensorDeLuz) < Umbral) {
    Paso8();
    delay(10);
    /*Paso7();
      delay(10);*/
    Paso6();
    delay(10);
    /*Paso5();
      delay(10);
      Paso4();
      delay(10);*/
    Paso3();
    delay(10);
    /* Paso2();
      delay(10);
      Paso1();
      delay(10);*/
    Paso0();
    delay(10);



  }


}
void Manual(int distancia) {
  if (distancia > 0) {
    Serial.println("adelante");
    for (int i = 0; i < distancia; i++) {
      Serial.println(i);
      //Paso0 ();
      //delay (10);
      Paso1();
      delayMicroseconds (10000);
      Paso2();
      delayMicroseconds (10000);
      Paso3();
      delayMicroseconds (10000);
      Paso4();
      delayMicroseconds (10000);
      Paso5();
     delayMicroseconds (10000);
      Paso6();
     delayMicroseconds (10000);
      Paso7();
      delayMicroseconds (10000);
      Paso8();
      delayMicroseconds (10000);
    }
  }

  if (distancia < 0) {
    Serial.println("reversa");
    for (int i = 0; i > distancia; i--) {
      Serial.println(i);


      Paso8();
      delay (10);
      Paso7();
      delay (10);
      Paso6();
      delay (10);
      Paso5();
      delay (10);
      Paso4();
      delay (10);
      Paso3();
      delay (10);
      Paso2();
      delay (10);
      Paso1();
      delay (10);
      //Paso0();
    }
  }
}
//Paso0();
//}


void setup() {
  Serial.begin (9600);
  pinMode (sensorDeLuz, INPUT);
  pinMode (Cable1, OUTPUT);
  pinMode (Cable2, OUTPUT);
  pinMode (Cable3, OUTPUT);
  pinMode (Cable4, OUTPUT);


}




void loop () {




  int distancia = 0;
  char c = Serial.read();
  if (c == 'M') {
    estado = 0;
    distancia = Serial.parseInt();
    Serial.println(distancia);
  }
  if (c == 'A') {
    estado = 1;
    Umbral = analogRead (sensorDeLuz);
    Serial.println(Umbral);
  }
  if (c == '1') {
    Paso1();
    estado = 2;
    distancia = 0;
    Serial.println(1);
  }
  if (c == '2') {
    estado = 2;
    distancia = 0;
    Paso2();
  }
  if (c == '3') {
    Paso3();
    estado = 2;
    distancia = 0;
  }
  if (c == '4') {
    Paso4();
    estado = 2;
    distancia = 0;
  }
  if (c == '5') {
    Paso5();
    estado = 2;
    distancia = 0;
  }
  if (c == '6') {
    Paso6();
    estado = 2;
    distancia = 0;
  }
  if (c == '7') {
    Paso7();
    estado = 2;
    distancia = 0;
  }
  if (c == '8') {
    Paso8();
    estado = 2;
    distancia = 0;
  }



  if (estado == 1) {
    Automatica ();
    Serial.println(analogRead (sensorDeLuz));
  } else if (estado == 0) {
    Manual(distancia);
  }
}

