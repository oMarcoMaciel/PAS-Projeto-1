// Definição dos pinos
const int pulsePin = A0;   // Pino do sensor de batimento cardíaco
const int buttonPin = 2;   // Pino do botão

// Variáveis
int pulseValue = 0;        // Valor lido do sensor de batimento cardíaco
int buttonState = 0;       // Estado do botão

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);
  
  // Configura os pinos
  pinMode(pulsePin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Usa o resistor pull-up interno do Arduino
}

void loop() {
  // Lê o valor do sensor de batimento cardíaco
  pulseValue = analogRead(pulsePin);
  
  // Lê o estado do botão
  buttonState = digitalRead(buttonPin);

  // Envia os dados via serial no formato: "pulseValue,buttonState"
  Serial.print(pulseValue);
  Serial.print(",");
  Serial.println(buttonState);

  // Pequena pausa para estabilidade da leitura
  delay(100);
}
