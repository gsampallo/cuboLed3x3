/*
 * Demo del modelo de cubo led.
 * by Guillermo Sampallo
 */
int pinMatrix[3][3]={ 
  { 9,6,3},
  { 10,7,4},
  { 8,5,2}
};

void setup() {
    for (int i=0;i<11;i++) {
        pinMode(i,OUTPUT);    // PINS0-10 are set as output
    }
    pinMode(A0,OUTPUT);    //PIN A0 set as output
    pinMode(A1,OUTPUT);   // PIN A1 set as output
    pinMode(A2,OUTPUT);   // PIN A2 set as output
    
    digitalWrite(A0,HIGH);    //pull up the A0 pin
    digitalWrite(A1,HIGH);   // pull up the A1 pin
    digitalWrite(A2,HIGH);   // pull up the A2 pin

}

void loop() { 
  
  apagar();
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      for(int k=0;k<3;k++) {
        apagar();
        encender(k,i,j);
        delay(200);
      }
    }
  }
  apagar();
  
  //iluminar las caras

  for(int h=0;h<3;h++) {
    for(int i=0;i<3;i++) {
      apagar();
      for(int j=0;j<3;j++) {
        encender(i,h,j);
      }
      delay(200);      
    }
  }  

  for(int h=0;h<3;h++) {
    for(int i=0;i<3;i++) {
      apagar();
      for(int j=0;j<3;j++) {
        encender(i,j,h);
      }
      delay(200);      
    }
  } 

  for(int h=0;h<3;h++) {
    apagar();
    for(int i=0;i<3;i++) {
      
      
        encender(i,0,h);
        encender(i,1,h);
        encender(i,2,h);
      
      delay(200);      
    }
  } 

  for(int i=0;i<3;i++) {
    apagar();
    iluminarCara(i,true);
    delay(200);
  }

  for(int i=0;i<3;i++) {
    apagar();
    iluminarCara(i,false);
    delay(200);
  }  

  //flecha
  apagar();
  iluminarColumna(8);
  delay(200);
  iluminarColumna(8);
  iluminarColumna(5);
  iluminarColumna(10);
  delay(200);
  iluminarColumna(9);
  iluminarColumna(7);
  iluminarColumna(2);
  delay(200);
  iluminarColumna(6);
  iluminarColumna(4);
  delay(200);
  iluminarColumna(3);  
  delay(200);

  apagar();
  for(int i=0;i<3;i++) { //nivel
    encender(i,0,0);
    delay(200);
    encender(i,0,1);
    encender(i,1,0);
    delay(200);
    encender(i,0,2);
    encender(i,2,0);
    encender(i,1,1);
    delay(200);
    encender(i,1,2);
    encender(i,2,1);
    delay(200);
    encender(i,2,2);
    delay(200);
    apagar();
   
  }

  int circuloColumnas[8] = { 8,5,2,4,3,6,9,10};
  for(int h=0;h<2;h++) {
    for(int i=0;i<8;i++) { //columnas
      apagar();
      iluminarColumna(circuloColumnas[i]);
      delay(200);
    }
  }
  
  for(int i=0;i<3;i++) {
    perseguir(i);
  }
  

}

void recorrido(int nivel) {
  int recorrer[][2] = {
    {0,0},
    {0,1},
    {0,2},
    {1,2},
    {2,2},
    {2,1},
    {2,0},
    {1,0}
  };  
  for(int h=0;h<8;h++) {
   apagar();
   encender(nivel,recorrer[h][1],recorrer[h][0]);
   
   delay(200);
  }   
}

void perseguir(int nivel) {
  int recorrer[][4] = {
    {0,0,2,2},
    {0,1,2,1},
    {0,2,2,0},
    {1,2,1,0},
    {2,2,0,0},
    {2,1,0,1},
    {2,0,0,2},
    {1,0,1,2}
  };  
  for(int h=0;h<8;h++) {
   apagar();
   encender(nivel,recorrer[h][1],recorrer[h][0]);
   encender(nivel,recorrer[h][3],recorrer[h][2]);
   
   delay(200);
  }   
}


void iluminarCara(int cara,boolean frente) {
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      if(frente) {
        encender(i,j,cara);
      } else {
        encender(i,cara,j);
      }
    }
  }
}

void iluminarColumna(int columna) {
  digitalWrite(A0,LOW);
  digitalWrite(A1,LOW);
  digitalWrite(A2,LOW);
  digitalWrite(columna,HIGH);  
}

void encender(int nivel,int fila,int columna) {
  if(nivel == 0) {
    digitalWrite(A2,LOW);
  } else if(nivel == 1) {
    digitalWrite(A1,LOW);
  } else if(nivel == 2) {
    digitalWrite(A0,LOW);
  }

  //int pin = nivel [fila][columna];

  digitalWrite(pinMatrix [fila][columna],HIGH);  
}

void apagar() {
  digitalWrite(A0,HIGH);
  digitalWrite(A1,HIGH);
  digitalWrite(A2,HIGH);

 for (int i=2;i<11;i++) {
    digitalWrite(i,LOW); 
 }    
}
  
