#ifndef PARSON_H
#define PARSON_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

/**
 * @brief Analisa uma string JSON e retorna a raiz (JSON_Value*).
 * @param string Texto JSON (terminado em '\0').
 * @return Ponteiro para JSON_Value ou NULL em caso de erro.
 */
JSON_Value* json_parse_string(const char *string);

/**
 * @brief Converte um JSON_Value em string alocada dinamicamente.
 * @param value Raiz do JSON.
 * @return String recém-alocada (usar free), ou NULL em erro.
 */
char* json_serialize_to_string(const JSON_Value *value);

/**
 * @brief Libera recursivamente o JSON_Value.
 * @param value Raiz (ou subárvore) a ser liberada.
 */
void json_value_free(JSON_Value *value);

#ifdef __cplusplus
}
#endif

#endif /* PARSON_H */
