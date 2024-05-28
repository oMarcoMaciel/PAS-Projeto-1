#include <PulseSensorPlayground.h>

// Pin do PulseSensor
const int pulsePin = A0; // Use a entrada analógica A0

// Criação de um objeto PulseSensor
PulseSensorPlayground pulseSensor;

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial

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
  int myBPM = pulseSensor.getBeatsPerMinute(); // Obtém a frequência cardíaca

  if (pulseSensor.sawStartOfBeat()) { // Se um batimento foi detectado
    Serial.print("Batimentos por minuto: ");
    Serial.println(myBPM);
  }
  
  delay(1000); // Aguarda 1 segundo entre leituras
}
