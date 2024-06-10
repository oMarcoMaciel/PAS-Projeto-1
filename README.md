# PAS-Projeto

## Introdução
A Pulseira de Assistência Sensorial (PAS) é um dispositivo desenvolvido em Arduino para auxiliar crianças autistas. Ele monitora a frequência cardíaca da criança e possui um botão para situações de crise. Este guia fornecerá todas as informações necessárias para montar, programar e utilizar a PAS.

## Conteúdo

- [Componentes Necessários](#componentes-necess%C3%A1rios)
- [Montagem do Hardware](#montagem-do-hardware)
- [Instalação do Software](#instala%C3%A7%C3%A3o-do-software)
- [Programação do Arduino](#programa%C3%A7%C3%A3o-do-arduino)
- [Como Usar](#como-usar)
- [Manutenção](#manuten%C3%A7%C3%A3o)

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

3. **Instale o PySerial**:
    - Abra um terminal ou prompt de comando e execute:
      ```sh
      pip install pyserial
      ```

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
2. **Conecte-se ao site**: Abra o site pelo seu navegador.
3. **Monitoramento**: O dispositivo começará a monitorar a frequência cardíaca automaticamente.
4. **Visualização no Site**: Se a criança pressionar o botão, será mostrado no site, para um profissional ir direto ao auxílio.

## Manutenção

- **Verificação de Conexões**: Inspecione as conexões de fios e componentes periodicamente para garantir que estejam firmes e seguras.
- **Atualizações de Software**: Verifique por atualizações de código e bibliotecas periodicamente para garantir o melhor desempenho do dispositivo.

## Código Python para Receber Dados via Serial

Crie um arquivo Python chamado `receive_data.py` com o seguinte conteúdo para ler os dados do Arduino:

```app.py
import serial
import time

# Configuração da porta serial (ajuste conforme necessário)
arduino_port = 'COM7'  # Substitua 'COM7' pela porta correta
baud_rate = 9600

# Inicializa a comunicação serial
ser = serial.Serial(arduino_port, baud_rate)
time.sleep(2)  # Aguarda a estabilização da conexão

button_press_count = 0
last_button_state = 1  # Assume que o botão começa no estado "solto" (HIGH)

# Temporizador para controle de atualização
last_update_time = time.time()
update_interval = 5  # Intervalo de atualização em segundos

# Função para calcular os batimentos por minuto (BPM)
def calculate_bpm(pulse_value):
    # Esse cálculo é um exemplo e pode ser ajustado conforme o sensor específico usado
    return pulse_value

try:
    while True:
        if ser.in_waiting > 0:
            # Lê uma linha de dados da serial
            line = ser.readline().decode('utf-8').strip()
            
            # Verifica se a linha contém os dados esperados (números)
            if ',' in line:
                try:
                    pulse_value, button_state = map(int, line.split(','))
                except ValueError:
                    # Ignora linhas que não contêm dados válidos
                    continue

                # Verifica se o botão foi pressionado (transição de HIGH para LOW)
                if button_state == 0 and last_button_state == 1:
                    button_press_count += 1

                last_button_state = button_state

                # Atualiza os dados a cada 5 segundos
                current_time = time.time()
                if current_time - last_update_time >= update_interval:
                    # Calcula os BPM (ajuste conforme necessário)
                    bpm = calculate_bpm(pulse_value)

                    # Exibe os valores lidos
                    print(f"Batimento Cardíaco: {bpm}, Botão Pressionado: {button_press_count} vezes")

                    # Salva os valores no arquivo (sobrescrevendo o arquivo)
                    with open('pedidos_ajuda.txt', 'w') as file:
                        file.write("Contador de Pressionamentos,Batimentos por Minuto (BPM)\n")
                        file.write(f"{button_press_count},{bpm}\n")

                    # Atualiza o tempo da última atualização
                    last_update_time = current_time

except KeyboardInterrupt:
    print("Interrompido pelo usuário")

finally:
    ser.close()
```
## Crie Arquivo TXT para Conexão com Site 

```pedidos_ajuda.txt
Contador de Pressionamentos,Batimentos por Minuto (BPM)
3,31
```

## Arquivos HTML e CSS

Crie um arquivo chamado `index.html` com o seguinte conteúdo para a interface web:

```index.html
<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Contador de Pedidos de Ajuda</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            text-align: center;
            padding: 20px;
        }
        h1 {
            color: #333;
        }
        #contador {
            font-size: 24px;
            color: #007bff;
        }
        #batimentos {
            font-size: 18px;
            color: #28a745;
        }
    </style>
</head>
<body>
    <h1>Contador de Pedidos de Ajuda e Batimentos Cardíacos</h1>
    <p>O aluno pediu ajuda:</p>
    <p id="contador">Carregando...</p>
    <p id="batimentos">Batimentos cardíacos: Carregando...</p>

    <script>
        // Função para carregar o valor do arquivo
        async function carregarContador() {
            try {
                const resposta = await fetch('pedidos_ajuda.txt');
                const texto = await resposta.text();
                const linhas = texto.trim().split('\n');
                const ultimaLinha = linhas[linhas.length - 1];
                const [pedidosAjuda, batimentosCardiacos] = ultimaLinha.split(',');
                document.getElementById('contador').textContent = `Pedidos de ajuda: ${pedidosAjuda}`;
                document.getElementById('batimentos').textContent = `Batimentos cardíacos: ${batimentosCardiacos}`;
            } catch (erro) {
                console.error('Erro ao carregar o contador:', erro);
                document.getElementById('contador').textContent = 'Erro ao carregar o contador.';
                document.getElementById('batimentos').textContent = 'Erro ao carregar os batimentos cardíacos.';
            }
        }

        // Chama a função ao carregar a página e a cada 5 segundos
        carregarContador();
        setInterval(carregarContador, 5000);
    </script>
</body>
</html>
```

Crie um arquivo chamado `styles.css` com o seguinte conteúdo para a estilização:

```css
body {
    font-family: Arial, sans-serif;
    margin: 0;
    padding: 0;
    background-color: #f4f4f4;
}

header {
    background-color: #ff914d;
    padding: 10px 20px;
    display: flex;
    justify-content: space-between;
    align-items: center;
}

.header-content {
    display: flex;
    align-items: center;
}

.profile {
    display: flex;
    align-items: center;
}

.profile img {
    border-radius: 50%;
    width: 50px;
    height: 50px;
    margin-right: 10px;
}

.profile-info h1 {
    margin: 0;
    font-size: 18px;
}

.profile-info p {
    margin: 0;
    font-size: 14px;
}

.date-time {
    font-size: 16px;
}

main {
    display: flex;
}

aside {
    width: 200px;
    background-color: #fff;
    padding: 20px;
}

aside h2 {
    font-size: 18px;
    margin-top: 0;
}

aside ul {
    list-style: none;
    padding: 0;
}

aside ul li {
    margin: 10px 0;
}

aside ul li a {
    text-decoration: none;
    color: #333;
}

aside ul li a.active {
    font-weight: bold;
    color: #ff914d;
}

section.students {
    flex-grow: 1;
    background-color: #fff;
    padding: 20px;
}

section.students h2 {
    font-size: 24px;
    margin-top: 0;
}

table {
    width: 100%;
    border-collapse: collapse;
    margin-top: 20px;
}

table th, table td {
    border: 1px solid #ddd;
    padding: 8px;
    text-align: left;
}

table th {
    background-color: #f4f4f4;
}

.regular {
    color: green;
}

.help {
    color: red;
}

.attending {
    color: orange;
}

.bpm.warning {
    font-weight: bold;
}

.total {
    margin-top: 20px;
    text-align: right;
    font-size: 16px;
}

footer {
    padding: 10px 20px;
    background-color: #f4f4f4;
    text-align: right;
}

footer button {
    padding: 10px 20px;
    background-color: #ffa500;
    color: #fff;
    border: none;
    cursor: pointer;
}

footer button:hover {
    background-color: #ff8c00;
}
```

---

**Desenvolvido por: Galileu Calaça, Igor Andrade, Marco Maciel, Rafael Moreira, Raphael Vasconcelos, Fabio Lins, Isadora Salviano, Maria Clara Poggi, Rodrigo Quirino, Gustavo Carneiro**
