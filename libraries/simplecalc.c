#include "simplecalc.h"

char *supported_operator_list[] = {
    "+", "-", "*", "/", "%", "lshift", "rshift", "and", "or", "xor", "rotl", "rotr"
};

int supported_operator_count = (sizeof supported_operator_list) / (sizeof supported_operator_list[0]);

//Usage Manual
void display_manual(){
    printf("**USAGE MANUAL for SimpleCalc**\n");
    printf("simplecalc.exe [OPERAND1] [OPERATOR] [OPERAND2]\n");
    printf("Valid Operators:\n");
    printf("\t\"+\"\t\tAddition, \t\t\tFormat: [DOUBLE] + [DOUBLE]\n");
    printf("\t\"-\"\t\tSubtraction, \t\t\tFormat: [DOUBLE] - [DOUBLE]\n");
    printf("\t\"*\"\t\tMultiplication, \t\tFormat: [DOUBLE] * [DOUBLE]\n");
    printf("\t\"/\"\t\tDivision, \t\t\tFormat: [DOUBLE] / [DOUBLE]\n");
    printf("\t\"%%\"\t\tModulus/Remainder, \t\tFormat: [INTEGER] %% [INTEGER]\n");
    printf("\t\"lshift\"\tBitwise Shift Left, \t\tFormat: [INTEGER--decimal format of number being shifted] lshift [INTEGER--number of bits to shift]\n");
    printf("\t\"rshift\"\tBitwise Shift Right, \t\tFormat: [INTEGER--decimal format of number being shifted] rshift [INTEGER--number of bits to shift]\n");
    printf("\t\"and\"\t\tBitwise AND, \t\t\tFormat: [INTEGER] AND [INTEGER]\n");
    printf("\t\"or\"\t\tBitwise OR, \t\t\tFormat: [INTEGER] OR [INTEGER]\n");
    printf("\t\"xor\"\t\tBitwise XOR, \t\t\tFormat: [INTEGER] XOR [INTEGER]\n");
    printf("\t\"rotl\"\t\tBitwise Rotate Left, \t\tFormat: [INTEGER--decimal format of number being shifted] rotl [INTEGER--number of bits to shift]\n");
    printf("\t\"rotr\"\t\tBitwise Rotate Right, \t\tFormat: [INTEGER--decimal format of number being shifted] rotr [INTEGER--number of bits to shift]\n");
}

//Operator Functions
double add(char *operand1, char *operand2){
    return strtof(operand1, NULL) + strtof(operand2, NULL);
}

double subtract(char *operand1, char *operand2){
    return strtof(operand1, NULL) - strtof(operand2, NULL);
}

double multiply(char *operand1, char *operand2){
    return strtof(operand1, NULL) * strtof(operand2, NULL);
}

double divide(char *operand1, char *operand2){
    if(strtof(operand2, NULL) == 0){
        printf("\nDivision Error: cannot divide by ");
        return 0;
    }else{
        
        return strtof(operand1, NULL) / strtof(operand2, NULL);
    }
}

double modulo(char *operand1, char *operand2){
    return strtol(operand1, NULL, 10) % strtol(operand2, NULL, 10);
}

int left_shift(char *operand1, char *operand2){
    return strtol(operand1, NULL, 10) << strtol(operand2, NULL, 10);
}

int right_shift(char *operand1, char *operand2){
    return strtol(operand1, NULL, 10) >> strtol(operand2, NULL, 10);
}

int and(char *operand1, char *operand2){
    return strtol(operand1, NULL, 10) & strtol(operand2, NULL, 10);
}

int or(char *operand1, char *operand2){
    return strtol(operand1, NULL, 10) | strtol(operand2, NULL, 10);
}

int xor(char *operand1, char *operand2){
    return strtol(operand1, NULL, 10) ^ strtol(operand2, NULL, 10);
}

int rotate_left(char *operand1, char *operand2){
    return (strtol(operand1, NULL, 10) << strtol(operand2, NULL, 10)) | (strtol(operand1, NULL, 10) >> (sizeof(operand1) * 8 - strtol(operand2, NULL, 10)));
}

int rotate_right(char *operand1, char *operand2){
    return (strtol(operand1, NULL, 10) >> strtol(operand2, NULL, 10)) | (strtol(operand1, NULL, 10) << (sizeof(operand1) * 8 - strtol(operand2, NULL, 10)));
}

//Input Validation
bool validate_format(int num_args, char *input_strings[]){
    if(num_args == 4 && is_supported_operator(input_strings[2]) && validate_operand_type(input_strings)){
        return true;
    }else{
        return false;
    }
}

bool validate_operand_type(char *input_strings[]){
    char *next_char_ptr;

    for(int i = 1; i <= 3; i+=2){

        if((strcmp(input_strings[i], "0") != 0)){
        
            if( (strcmp("+", input_strings[2]) == 0) || 
                (strcmp("-", input_strings[2]) == 0) || 
                (strcmp("*", input_strings[2]) == 0) || 
                (strcmp("/", input_strings[2]) == 0)){

                    double operator_d = strtod(input_strings[i], &next_char_ptr);

                    if(operator_d == 0 || (strcmp(next_char_ptr, "\0") != 0)){
                                            
                        printf("Error: Equation unsupported as input. \"%s\" unsupported as operand.\n", input_strings[i]);
                        printf("%s operator accepts operands of type DOUBLE\n", input_strings[2]);
                        printf("See usage manual below for supported operators and format\n\n", input_strings[2]);

                        return false;
                    }

            }else if((strcmp("%", input_strings[2]) == 0) || 
                    (strcmp("lshift", input_strings[2]) == 0) || 
                    (strcmp("rshift", input_strings[2]) == 0) || 
                    (strcmp("and", input_strings[2]) == 0) ||
                    (strcmp("or", input_strings[2]) == 0) ||
                    (strcmp("xor", input_strings[2]) == 0) ||
                    (strcmp("rotl", input_strings[2]) == 0) ||
                    (strcmp("rotr", input_strings[2]) == 0)){

                        long operator_l = strtol(input_strings[i], &next_char_ptr, 10);

                        if((strtol(input_strings[i], &next_char_ptr, 10) == 0) || strcmp(next_char_ptr, "\0") != 0){
                        
                            printf("Error: Equation unsupported as input. \"%s\" unsupported as operand.\n", input_strings[i]);
                            printf("%s operator accepts operands of type INTEGER\n", input_strings[2]);
                            printf("See usage manual below for supported operators and format\n\n", input_strings[2]);

                            return false;
                        }
            }
        }
    }  

    return true;
}

bool is_supported_operator(char *operator_string){
    for(int i = 0; i < supported_operator_count; i++){
        if(strcmp(operator_string, supported_operator_list[i]) == 0){
            return true;
        }
    }

    return false;
}

bool validate_simplecalc_inputs(int input_string_count, char *input_strings[]){
    if(validate_format(input_string_count, input_strings)){
        return true;
    }else{
        display_manual();
        return false;
    }
}

//Output to Terminal
void simplecalc_print_answer_to_stdout(char *input_strings[]){
    if(strcmp(input_strings[2], "+") == 0){

        printf("%g", add(input_strings[1], input_strings[3]));
    
    }else if(strcmp(input_strings[2], "-") == 0){

        printf("%g", subtract(input_strings[1], input_strings[3]));

    }else if(strcmp(input_strings[2], "*") == 0){

        printf("%g", multiply(input_strings[1], input_strings[3]));
    
    }else if(strcmp(input_strings[2], "/") == 0){
    
        printf("%g", divide(input_strings[1], input_strings[3]));
    
    }else if(strcmp(input_strings[2], "%") == 0){
    
        printf("%g", modulo(input_strings[1], input_strings[3]));
    
    }else if(strcmp(input_strings[2], "lshift") == 0){
    
        printf("%d", left_shift(input_strings[1], input_strings[3]));
    
    }else if(strcmp(input_strings[2], "rshift") == 0){
    
        printf("%d", right_shift(input_strings[1], input_strings[3]));
    
    }else if(strcmp(input_strings[2], "and") == 0){
    
        printf("%d", and(input_strings[1], input_strings[3]));
    
    }else if(strcmp(input_strings[2], "or") == 0){
    
        printf("%d", or(input_strings[1], input_strings[3]));
    
    }else if(strcmp(input_strings[2], "xor") == 0){
    
        printf("%d", xor(input_strings[1], input_strings[3]));
    
    }else if(strcmp(input_strings[2], "rotr") == 0){
    
        printf("%d", rotate_right(input_strings[1], input_strings[3]));
    
    }else if(strcmp(input_strings[2], "rotl") == 0){
        
        printf("%d", rotate_left(input_strings[1], input_strings[3]));
    
    }else{
        
        printf("Operator type \"%s\" unsupported. \n", input_strings[2]);
        printf("Please use one of the following supported operators:\n");
        printf("+, -, *, /, %%, lshift, rshift, and, or, xor, rotl, rotr\n");
    
    }
}


//Debugging Aides/Optional Features
void echo_inputs(int input_string_count, char *input_strings[]){
    if(input_string_count > 1){
        
        for(int i = 1; i < input_string_count; i++){
            printf("%s ", input_strings[i]);
        }

        printf("= ");
    }
}