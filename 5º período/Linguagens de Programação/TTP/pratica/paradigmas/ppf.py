#PARADIGMA DE PROGRAMACAO FUNCIONAL
# o paradigma funcional é implementado nas funções anônimas lambda,
# e nos métodos map e reducer
# cálculo lambda é um sistema
# formal em lógica matemática para expressar computação 
# com base na abstração e aplicação de funções usando 
# associação e substituição de variáveis.

# functools: é um módulo para funções de ordem superior e fornece funções que
# atuam ou retornam outras funções

# reduce: é um método que aplica uma função de dois argumentos 
# cumulativamente aos itens em sequência, da esquerda para a direita, 
# para reduzir a sequência a um único valor
import functools

numeros = [1, 2, 3, 4, 5]
potencia = lambda x, y = 2: x ** y
lista = list(map(potencia, numeros))
print(lista)

# Soma de valores
lista = [1, 2, 3, 4, 5]
soma = functools.reduce(lambda x, y: x + y, lista)
print(soma)
