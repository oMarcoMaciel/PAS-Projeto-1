# PAS-Projeto-1
# PAS (Pulseira de Assistência Sensorial)

## Introdução
A Pulseira de Assistência Sensorial (PAS) é um dispositivo desenvolvido em Arduino para auxiliar crianças autistas. Ele monitora a frequência cardíaca da criança e possui um botão de alarme para situações de emergência. Este guia fornecerá todas as informações necessárias para montar, programar e utilizar a PAS.

## Conteúdo

- [Componentes Necessários](#componentes-necessários)
- [Montagem do Hardware](#montagem-do-hardware)
- [Instalação do Software](#instalação-do-software)
- [Programação do Arduino](#programação-do-arduino)
- [Como Usar](#como-usar)
- [Manutenção](#manutenção)

## Componentes Necessários

Para montar a PAS, você precisará dos seguintes componentes:

- 1 Arduino Uno
- 1 Sensor de Frequência Cardíaca (ex: Pulse Sensor)
- 1 Botão Push-Button
- Fios Jumpers
- 1 Protoboard

## Montagem do Hardware

1. **Conecte o Sensor de Frequência Cardíaca**:
    - Conecte o fio vermelho do sensor ao pino 5V do Arduino.
    - Conecte o fio preto do sensor ao pino GND do Arduino.
    - Conecte o fio púrpura (sinal) ao pino A0 do Arduino.

2. **Conecte o Botão**:
    - Conecte um terminal do botão ao pino digital 2 do Arduino.
    - Conecte o outro terminal a um dos terminais do resistor.
    - Conecte o outro terminal do resistor ao GND do Arduino.
    - Conecte o terminal que foi conectado ao pino digital 2 ao 5V através de um fio jumper.

## Instalação do Software

1. **Baixe e Instale a IDE do Arduino**:
    - Acesse [Arduino Software](https://www.arduino.cc/en/software) e baixe a versão adequada para seu sistema operacional.
    - Siga as instruções de instalação fornecidas no site.

2. **Instale as Bibliotecas Necessárias**:
    - Abra a IDE do Arduino.
    - Vá em `Sketch` > `Include Library` > `Manage Libraries`.
    - Procure e instale a biblioteca `PulseSensor Playground`.

## Programação do Arduino

1. **Abra a IDE do Arduino**.
2. **Carregue o código**:
    - Copie e cole o seguinte código na IDE do Arduino:

    ```cpp
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
    ```

3. **Carregue o código no Arduino**:
    - Conecte o Arduino ao computador via USB.
    - Selecione a porta correta em `Tools` > `Port`.
    - Clique em `Upload`.

## Como Usar

1. **Coloque a pulseira na criança**: Certifique-se de que o sensor de frequência cardíaca esteja bem posicionado no pulso da criança.
2. **Ligue o dispositivo**: Conecte a bateria ao Arduino.
3. **Monitoramento**: O dispositivo começará a monitorar a frequência cardíaca automaticamente.
4. **Alarme**: Se a criança pressionar o botão, será mostrado no site, para um profissional ir direto ao auxílio.

## Manutenção

- **Verificação de Conexões**: Inspecione as conexões de fios e componentes periodicamente para garantir que estejam firmes e seguras.
- **Atualizações de Software**: Verifique por atualizações de código e bibliotecas periodicamente para garantir o melhor desempenho do dispositivo.

---

**Desenvolvido por: Galileu Calaça, Igor Andrade, Marco Maciel, Rafael Moreira, Raphael Vasconcelos, Fabio Lins, Isadora Salviano, Maria Clara Poggi, Rodrigo Quirino, Gustavo Carneiro**
