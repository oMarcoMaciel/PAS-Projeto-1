const int botaoPin = 2; 

int contador = 0; 
int ultimoStatusBotao = HIGH;

void setup() {
  pinMode(botaoPin, INPUT_PULLUP); 
  Serial.begin(9600);
}

void loop() {
  int leitura = digitalRead(botaoPin); 

  if (leitura != ultimoStatusBotao) {
    delay(50); 
    leitura = digitalRead(botaoPin); 
  }

  if (leitura == LOW && ultimoStatusBotao == HIGH) {
    contador++; 
    Serial.print("Quantidade de cliques: ");
    Serial.println(contador);
  }

  ultimoStatusBotao = leitura; 
}


