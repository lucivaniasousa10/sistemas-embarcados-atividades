// LEDs
const int vermelho = 6;
const int verde = 5;
const int amarelo = 3;

// Botão
const int botao = 2;

int estado = 0;
int leituraAnterior = LOW;
int estadoBotao = LOW;

unsigned long ultimoTempo = 0;
const unsigned long debounce = 50;

void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);

  pinMode(botao, INPUT);

  digitalWrite(vermelho, LOW);
  digitalWrite(amarelo, LOW);
  digitalWrite(verde, LOW);
}

void loop() {

  int leitura = digitalRead(botao);

  if (leitura != leituraAnterior) {
    ultimoTempo = millis();
  }

  if (millis() - ultimoTempo > debounce) {

    if (leitura != estadoBotao) {
      estadoBotao = leitura;

      if (estadoBotao == HIGH) {
        estado++;

        if (estado > 3) {
          estado = 0;
        }
      }
    }
  }

  leituraAnterior = leitura;

  digitalWrite(vermelho, estado == 1 ? HIGH : LOW);
  digitalWrite(amarelo, estado == 2 ? HIGH : LOW);
  digitalWrite(verde, estado == 3 ? HIGH : LOW);
}
