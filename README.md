# TP.PDS2
Trabalho Prático da disciplina Programação e Desenvolvimento de Software 2
- Consiste em uma maquina de busca que recebe como entrada uma expressão de busca, normaliza a mesma, e dá como saída os documentos que são mais relevantes para a consulta fornecida, levando em consideração a frequencia das palavras.
## Dependências:
- C++17
- Make
## Comandos Make:
- `make`: Compilar
- `make run`: Executar
## Informações:
- Seguindo as intruções fornecidas para o trabalho o sistema assume que os arquivos estarão em uma pasta `./documentos/`.
- A busca considera apenas arquivos em que todas as palavras estão presentes e ordena os documentos de acordo com a frequencia das palavras, em ordem decrescente.
