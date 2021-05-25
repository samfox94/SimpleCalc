#ifndef SIMPLECALC_H
#define SIMPLECALC_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

//Usage Manual
void display_manual();

//Operators
double add(char*, char*);
double subtract(char*, char*);
double multiply(char*, char*);
double divide(char*, char*);
double modulo(char*, char*);
int left_shift(char*, char*);
int right_shift(char*, char*);
int and(char*, char*);
int or(char*, char*);
int xor(char*, char*);
int rotate_left(char*, char*);
int rotate_right(char*, char*);

//Input Validation
bool validate_format(int, char*[]);
bool validate_operand_type(char *[]);
bool is_supported_operator(char*);
bool validate_simplecalc_inputs(int, char *[]);

//Terminal Interation
void simplecalc_print_answer_to_stdout(char *[]);

//Debugging
void echo_inputs(int, char *[]); 

#endif