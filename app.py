import serial
nome_arquivo = "pedidos_ajuda.txt"
pedidosAjuda = 0
with open(nome_arquivo, "w") as arquivo:
    arquivo.write(str(pedidosAjuda))

porta = "COM9" 
velocidade = 9600

conexao = serial.Serial(porta, velocidade)

try:
    while True:
        if conexao.in_waiting > 0:
            dado = conexao.read().decode("utf-8")
            if dado == "c":
                pedidosAjuda += 1
                with open(nome_arquivo, "w") as arquivo:
                    arquivo.write(str(pedidosAjuda))
                if pedidosAjuda == 1:
                    print(f"O aluno pediu ajuda {pedidosAjuda} vez!")
                else:print(f"O aluno pediu ajuda {pedidosAjuda} vezes!")



except KeyboardInterrupt:
    print("\nPrograma encerrado pelo usuário.")
finally:
    conexao.close()
