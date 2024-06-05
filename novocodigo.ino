#include <PulseSensorPlayground.h>

// Pin do PulseSensor
const int pulsePin = A0; // Use a entrada analógica A0

// Criação de um objeto PulseSensor
PulseSensorPlayground pulseSensor;

int pedidosAjuda = 0;
const char* nome_arquivo = "pedidos_ajuda.txt";

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
  // Leitura do botão
  if (Serial.available() > 0) {
    char dado = Serial.read();
    if (dado == 'c') {
      pedidosAjuda++;
      Serial.print("O aluno pediu ajuda ");
      Serial.print(pedidosAjuda);
      Serial.println(pedidosAjuda == 1 ? " vez!" : " vezes!");
      // Atualiza o arquivo
      atualizarArquivo();
    }
  }

  // Leitura do batimento cardíaco
  int myBPM = pulseSensor.getBeatsPerMinute();
  if (pulseSensor.sawStartOfBeat()) {
    Serial.print("Batimentos por minuto: ");
    Serial.println(myBPM);
  }
  
  delay(1000); // Aguarda 1 segundo entre leituras
}

void atualizarArquivo() {
  // Atualiza o arquivo com o número de pedidos de ajuda
  File arquivo = SD.open(nome_arquivo, FILE_WRITE);
  if (arquivo) {
    arquivo.println(pedidosAjuda);
    arquivo.close();
  } else {
    Serial.println("Erro ao abrir o arquivo.");
  }
}
