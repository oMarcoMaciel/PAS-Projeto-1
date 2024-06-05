#include <PulseSensorPlayground.h>

// Pin do PulseSensor
const int pulsePin = A0; // Use a entrada analógica A0

const int botaoPin = 2; 

int contador = 0; 
int ultimoStatusBotao = HIGH;

// Criação de um objeto PulseSensor
PulseSensorPlayground pulseSensor;

void setup() {
  pinMode(botaoPin, INPUT_PULLUP); 
  Serial.begin(9600);

  // Configurações do PulseSensor
  pulseSensor.analogInput(pulsePin);
  pulseSensor.setThreshold(550); // Define o limiar para detectar um batimento
  
  if (pulseSensor.begin()) {
    Serial.println("PulseSensor iniciado com sucesso!");
  } else {
    Serial.println("Erro ao iniciar o PulseSensor.");
  }
}

void loop() {
  int leitura = digitalRead(botaoPin); 
  int myBPM = pulseSensor.getBeatsPerMinute(); // Obtém a frequência cardíaca
  
  if (pulseSensor.sawStartOfBeat()) { // Se um batimento foi detectado
    Serial.print("Batimentos por minuto: ");
    Serial.println(myBPM);
  }

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

  delay(1000); // Aguarda 1 segundo entre leituras
  // PRECISA DAR UM JEITO NESSE DELAY

}


