#PARADIGMA DE PROGRAMACAO PROCEDURAL
# é um subtipo de programação imperativa em que
# as instruções são estruturadas em procedimentos 
# (também conhecidos como sub-rotinas ou funções)
# No trecho de código abaixo pode-se ver um exemplo 
# em que é declarada uma função stringify que recebe 
# como parâmetro uma lista de caracteres e retorna a junção deles
def stringify (caracteres):
    string = ''
    for c in caracteres:
        string = string + c
    return string

caracteres = ['P', 'y', 't', 'h', 'o', 'n']
string_final = stringify(caracteres)
print(string_final)

