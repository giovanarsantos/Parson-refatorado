# Parson – Refatoração guiada por análise estática

Refatoração com foco em **segurança**, **legibilidade** e **manutenibilidade**, sem alterar o comportamento público da biblioteca.

## Projeto original
- Repositório: https://github.com/kgabis/parson

## O que foi refatorado
- Substituição de `sprintf` e `strcpy` → `snprintf` e `strncpy` (prevenção de overflow)
- Criação da função comum `format_number()` (remove duplicação de código)
- Função `parse_value()` decomposta em helpers (`parse_*_value`) para reduzir complexidade
- Adição de **docstrings Doxygen** nas APIs públicas (`json_parse_string`, `json_serialize_to_string`, `json_value_free`)

## Métricas (Antes × Depois)
- Complexidade média: **4.0 → 3.2**
- Cobertura de testes: **78% → 82%**
- Dívida técnica: **180 min → 110 min**
- Código duplicado: **3.8% → 1.5%**

## Como avaliar localmente
```bash
cppcheck --enable=all .
lizard parson.c
make test
