

with open("token", "rb") as file:
    content = file.read()

result = "".join([chr((char - i) % 256) for i, char in enumerate(content)])
print(result)
