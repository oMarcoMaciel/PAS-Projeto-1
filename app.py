import serial

nome_arquivo = "pedidos_ajuda.txt"
pedidosAjuda = 0
batimentosCardiacos = 0

with open(nome_arquivo, "w") as arquivo:
    arquivo.write(f"{pedidosAjuda},{batimentosCardiacos}")

porta = "COM7"
velocidade = 9600

conexao = serial.Serial(porta, velocidade)

try:
    while True:
        if conexao.in_waiting > 0:
            dado = conexao.read().decode("utf-8")
            if dado == "c":
                pedidosAjuda += 1
                with open(nome_arquivo, "w") as arquivo:
                    arquivo.write(f"{pedidosAjuda},{batimentosCardiacos}")
                if pedidosAjuda == 1:
                    print(f"O aluno pediu ajuda {pedidosAjuda} vez!")
                else:
                    print(f"O aluno pediu ajuda {pedidosAjuda} vezes!")

        # Simule a leitura dos batimentos cardíacos (substitua pela leitura real)
        # Aqui, estou apenas incrementando um valor fictício para demonstração
        batimentosCardiacos += 1
        with open(nome_arquivo, "w") as arquivo:
            arquivo.write(f"{pedidosAjuda},{batimentosCardiacos}")

except KeyboardInterrupt:
    print("\nPrograma encerrado pelo usuário.")
finally:
    conexao.close()
