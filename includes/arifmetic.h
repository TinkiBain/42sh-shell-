/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arifmetic.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:39:31 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/01 20:48:57 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARIFMETIC_H
# define ARIFMETIC_H

# include "lexer.h"
# include "sh.h"

# define VAR			1
# define DIGIT			2
# define ASSIGNMENT		3
# define ADD_ASSIGNMENT	4
# define MIN_ASSIGNMENT	5
# define MUL_ASSIGNMENT	6
# define DIV_ASSIGNMENT	7
# define MOD_ASSIGNMENT	8
# define DLS_ASSIGNMENT	9
# define DGR_ASSIGNMENT	10
# define AND_ASSIGNMENT	11
# define OR_ASSIGNMENT	12
# define OR				13
# define AND			14
# define LOGICAL_OR		15
# define LOGICAL_AND	16
# define EQUAL_IF		17
# define NOT_EQUAL_IF	18
# define LESS_IF		19
# define LESS_EQ		20
# define GREAT_IF		21
# define GREAT_EQ		22
# define LEFT_SHIFT		23
# define RIGHT_SHIFT	24
# define PLUS			25
# define MINUS			26
# define MULTI			27
# define DIVISION		28
# define MODULE			29
# define SUFFIX_ADD		30
# define SUFFIX_MIN		31
# define PREFIX_ADD		32
# define PREFIX_MIN		33
# define LBRACKET_ARIF	34
# define RBRACKET_ARIF	35
# define DIVISION_NULL	36
# define EOF_AR			37
# define EXCLUSIVE_OR	38
# define LOGICAL_NOT	39

t_lex		*g_error_arifmetic;
t_lex		*g_lex_arif;

t_lex		*arifmetic_lexer(char *str);
char		*arifmetic_lexer_great(char *str, t_lex **lex);
char		*arifmetic_lexer_less(char *str, t_lex **lex);
char		*arifmetic_lexer_assignment(char *str, t_lex **lex);
char		*arifmetic_lexer_or(char *str, t_lex **lex);
char		*arifmetic_lexer_and(char *str, t_lex **lex);
char		*arifmetic_lexer_plus(char *str, t_lex **lex);
char		*arifmetic_lexer_minus(char *str, t_lex **lex);
char		*arifmetic_lexer_multi(char *str, t_lex **lex);
char		*arifmetic_lexer_division(char *str, t_lex **lex);
char		*arifmetic_lexer_module(char *str, t_lex **lex);
char		*arifmetic_lexer_check_token(char *str, t_lex **lex);
char		*arifmetic_lexer_var(char *str, t_lex **lex);
char		*arifmetic_lexer_digit(char *str, t_lex **lex);
char		*arifmetic_exp(char *str);

size_t		expr(void);
size_t		expr_or(void);
size_t		expr_and(void);
size_t		expr_logic_or(void);
size_t		expr_exclusive_or(void);
size_t		expr_logic_and(void);
size_t		expr_equal(void);
size_t		expr_relat_op(void);
size_t		expr_shift(void);
size_t		expr_additive(void);
size_t		expr_multiplicativ(void);
size_t		expr_prefix(void);
size_t		expr_suffix(void);
size_t		expr_unar(void);
size_t		expr_get_var_value(void);
size_t		expr_return_value(void);
size_t		expr_digit(void);
size_t		expr_bracket(void);

/*
size_t		expr(void);
size_t		expr_logical_op(void);
size_t		expr_equal(void);
size_t		expr_less_great(void);
size_t		expr_shift_bits(void);
size_t		expr_arifmetic(void);
size_t		expr_arifmetic_mul(void);
size_t		expr_check_div_null(size_t right_value, size_t left_value, int op);
size_t		xpr_prefix(void);
size_t		expr_unar_op(void);
size_t		expr_suffix(void);
size_t		expr_bracket(void);
size_t		expr_check_var(void);
size_t		expr_get_var_value(void);
size_t		expr_digit(void);
*/

#endif
