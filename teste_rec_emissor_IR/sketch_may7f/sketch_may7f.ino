#define IR022 8

int led1 = 13;
int ledir = 12;
int botao = 2;
int estadobotao = 0;

unsigned long tempoAnterior = 0;
const unsigned long intervalo = 500; // 0,5 segundos
bool estadoLedir = false;

void setup() {
  pinMode(IR022, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(ledir, OUTPUT);
  pinMode(botao, INPUT);
}

void loop() {
  // Pisca o LED 'ledir' a cada 0,5 segundos
  unsigned long tempoAtual = millis();
  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual;
    estadoLedir = !estadoLedir;
    digitalWrite(ledir, estadoLedir);
  }

  estadobotao = digitalRead(botao);

  if (estadobotao == 1) {
    if (digitalRead(IR022) == 0) {
      for (int x = 0; x < 5; x++) {
        digitalWrite(led1, HIGH);
        delay(500);
        digitalWrite(led1, LOW);
        delay(500);
      }
    }
  }
}
