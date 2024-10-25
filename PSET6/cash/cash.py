
cambio = -1.0
while cambio < 0:
    try:
        cambio = float(input("Cambio a devolver (en dólares): "))
    except ValueError:
        print("Por favor, introduce un número válido.")

cambio = round(cambio * 100)

centavos25 = cambio // 25
cambio = cambio % 25
centavos10 = cambio // 10
cambio = cambio % 10
centavos5 = cambio // 5
cambio = cambio % 5
centavos1 = cambio

total_monedas = centavos25 + centavos10 + centavos5 + centavos1

print(total_monedas)
