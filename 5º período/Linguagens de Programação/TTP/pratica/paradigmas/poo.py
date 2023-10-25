#PARADIGMA DE PROGRAMACAO ORIENTADA A OBJETOS
# Não é possível a diferenciação de métodos públicos, 
# privados e protegidos pela própria linguagem, 
# mas a comunidade utiliza como convenção dois underscores 
# antes do nome das propriedades e métodos considerados 
# internos na classe. 
# Após a declaração da classe é possível instanciar objetos daquela classe 
class Cliente:
    def __init__(self, nome, email, plano):
        self.nome = nome
        self.email = email
        lista_planos = ["basico", "premium"]
        if plano in lista_planos:
            self.plano = plano
        else:
            raise Exception("Plano invalido") 

cliente = Cliente ("Carol", "carol@gmail.com", "premium")
print (cliente.nome)


