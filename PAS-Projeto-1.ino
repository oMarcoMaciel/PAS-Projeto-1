#include <PulseSensorPlayground.h>

// Definição dos pinos
const int pulsePin = A0;   // Pino do sensor de batimento cardíaco
const int buttonPin = 2;   // Pino do botão

PulseSensorPlayground pulseSensor;


// Variáveis
int pulseValue = 0;        // Valor lido do sensor de batimento cardíaco
int buttonState = 0;       // Estado do botão

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);
  
  // Configura os pinos
  pinMode(buttonPin, INPUT_PULLUP); // Usa o resistor pull-up interno do Arduino
  pulseSensor.analogInput(pulsePin);
  pulseSensor.setThreshold(550);  // Ajuste este valor conforme necessário
  if (pulseSensor.begin()) {
    Serial.println("PulseSensor iniciado com sucesso.");
  } else {
    Serial.println("Falha ao iniciar o PulseSensor.");
  }
}

void loop() {
  // Lê o valor do sensor de batimento cardíaco
  int myBPM = pulseSensor.getBeatsPerMinute();

  // Verifica se há uma batida detectada
  bool pulseDetected = pulseSensor.sawStartOfBeat();
  
  // Lê o estado do botão
  buttonState = digitalRead(buttonPin);

  // Envia os dados via serial no formato: "pulseValue,buttonState"
  Serial.print(myBPM);
  Serial.print(",");
  Serial.println(buttonState);

  // Pequena pausa para estabilidade da leitura
  delay(100);
}
