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
