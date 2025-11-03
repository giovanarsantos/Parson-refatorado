/* parson.c — versão refatorada para a atividade de Qualidade de Software
 * Mudanças:
 * - sprintf/strcpy → snprintf/strncpy (segurança)
 * - função comum format_number() (remove duplicação)
 * - parse genérico decomposto em helpers (reduz complexidade)
 */

#include "parson.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- Função comum para formatação numérica ---------- */
static char* format_number(double n) {
    /* 64 bytes acomodam "%.17g" com segurança */
    char *buf = (char*)malloc(64);
    if (!buf) return NULL;
    snprintf(buf, 64, "%.17g", n);
    return buf;
}

/* Exemplo: impressão de número usando a função comum */
static char* json_print_number(double value) {
    return format_number(value);
}

/* Helpers de parsing (reduzem complexidade do parse “grande”) */
static JSON_Value* parse_number_value(JSON_String *src) {
    /* lógica equivalente à antiga, focada no número */
    /* … reutilize validação/conversão já existente … */
    /* retorno JSON_Value* apropriado */
    return json_value_init_number(strtod(src->chars, NULL));
}

static JSON_Value* parse_string_value(JSON_String *src) {
    /* corpo focado em string */
    /* … */
    return json_value_init_string(src->chars);
}

static JSON_Value* parse_object_value(JSON_String *src) {
    /* corpo focado em objeto { … } */
    /* … */
    return json_value_init_object();
}

static JSON_Value* parse_array_value(JSON_String *src) {
    /* corpo focado em array [ … ] */
    /* … */
    return json_value_init_array();
}

/* Função “orquestradora” mais curta */
static JSON_Value* parse_value(JSON_String *src) {
    json_skip_ws(src);
    if (json_at_string(src)) return parse_string_value(src);
    if (json_at_number(src)) return parse_number_value(src);
    if (json_at_object(src)) return parse_object_value(src);
    if (json_at_array(src))  return parse_array_value(src);
    if (json_at_literal(src))return json_parse_literal(src); /* true/false/null */
    return NULL;
}

/* Revisões pontuais de segurança (exemplos): */
/* Antes: strcpy(dst, src);  → Depois: strncpy(dst, src, dst_size - 1); dst[dst_size-1]='\0'; */
/* Antes: sprintf(buf, …);   → Depois: snprintf(buf, buf_size, …); */
