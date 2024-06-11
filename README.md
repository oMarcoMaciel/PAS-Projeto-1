# PAS-Projeto

## Introdução
A Pulseira de Assistência Sensorial (PAS) é um dispositivo desenvolvido em Arduino para auxiliar crianças com TEA. Ele monitora a frequência cardíaca da criança e possui um botão para situações de crise. Este guia fornecerá todas as informações necessárias para montar, programar e utilizar a PAS.

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
- 1 LED

## Montagem do Hardware

1. **Conecte o Sensor de Frequência Cardíaca**:
    - Conecte o fio vermelho do sensor ao pino 5V do Arduino.
    - Conecte o fio preto do sensor ao pino GND do Arduino.
    - Conecte o fio roxo (sinal) ao pino A0 do Arduino.

2. **Conecte o Botão**:
    - Conecte um terminal do botão ao pino digital 2 do Arduino.
    - Conecte o outro terminal ao GND do Arduino.
    - Conecte o terminal que foi conectado ao pino digital 2 ao 5V através de um fio jumper.

3. **Conecte o LED**:
   - Conecte um terminal do LED ao pino digital 3 do Arduino.
   - Conecte o outro terminal do LED ao GND do Arduino.

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
    - Copie e cole o código [PAS-Projeto-1.ino](https://github.com/oMarcoMaciel/PAS-Projeto-1/blob/main/PAS-Projeto-1.ino) na IDE do Arduino:

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

Crie um arquivo Python chamado [app.py](https://github.com/oMarcoMaciel/PAS-Projeto-1/blob/main/app.py) com o seguinte conteúdo para ler os dados do Arduino:

## Crie Arquivo TXT [pedidos_ajuda.txt](https://github.com/oMarcoMaciel/PAS-Projeto-1/blob/main/pedidos_ajuda.txt) para Conexão com Site 

## Arquivos HTML e CSS

Crie um arquivo chamado [index.html](https://github.com/oMarcoMaciel/PAS-Projeto-1/blob/main/index.html) com o seguinte conteúdo para a interface web:

Crie um arquivo chamado [styles.css](https://github.com/oMarcoMaciel/PAS-Projeto-1/blob/main/styles.css) com o seguinte conteúdo para a estilização:

---

**Desenvolvido por: Galileu Calaça, Igor Andrade, Marco Maciel, Rafael Moreira, Raphael Vasconcelos, Fabio Lins, Isadora Salviano, Maria Clara Poggi, Rodrigo Quirino, Gustavo Carneiro**
