#include "../hdrs/simplecalc.h"

//Usage Manual
void display_manual(){
    printf("**USAGE MANUAL for SimpleCalc**\n");
    printf("simplecalc.exe [OPERAND1] [OPERATOR] [OPERAND2]\n");
    printf("Valid Operators:\n");
    printf("\t\"+\"\t\tAddition, \t\t\tFormat: [DOUBLE] + [DOUBLE]\n");
    printf("\t\"-\"\t\tSubtraction, \t\t\tFormat: [DOUBLE] - [DOUBLE]\n");
    printf("\t\"*\"\t\tMultiplication, \t\tFormat: [DOUBLE] * [DOUBLE]\n");
    printf("\t\"/\"\t\tDivision, \t\t\tFormat: [DOUBLE] / [DOUBLE]\n");
    printf("\t\"%%\"\t\tModulus/Remainder, \t\tFormat: [DOUBLE] %% [DOUBLE]\n");
    printf("\t\"lshift\"\tBitwise Shift Left, \t\tFormat: [INTEGER--decimal format of number being shifted] lshift [INTEGER--number of bits to shift]\n");
    printf("\t\"rshift\"\tBitwise Shift Right, \t\tFormat: [INTEGER--decimal format of number being shifted] rshift [INTEGER--number of bits to shift]\n");
    printf("\t\"and\"\t\tBitwise AND, \t\t\tFormat: [INTEGER] AND [INTEGER]\n");
    printf("\t\"or\"\t\tBitwise OR, \t\t\tFormat: [INTEGER] OR [INTEGER]\n");
    printf("\t\"xor\"\t\tBitwise XOR, \t\t\tFormat: [INTEGER] XOR [INTEGER]\n");
    printf("\t\"rotl\"\t\tBitwise Rotate Left, \t\tFormat: [INTEGER--decimal format of number being shifted] rotl [INTEGER--number of bits to shift]\n");
    printf("\t\"rotr\"\t\tBitwise Rotate Right, \t\tFormat: [INTEGER--decimal format of number being shifted] rotr [INTEGER--number of bits to shift]\n");
}

//Operator Functions
double add(char *op1, char *op2){
    return atof(op1) + atof(op2);
}

double subtract(char *op1, char *op2){
    return atof(op1) - atof(op2);
}

double multiply(char *op1, char *op2){
    return atof(op1) * atof(op2);
}

double divide(char *op1, char *op2){
    if(atof(op2) == 0){
        printf("\nDivision Error: cannot divide by ");
        return 0;
    }else{
        
        return atof(op1) / atof(op2);
    }
}

double modulo(char *op1, char *op2){
    return fmod(atof(op1), atof(op2));
}

int left_shift(char *op1, char *op2){
    return atoi(op1) << atoi(op2);
}

int right_shift(char *op1, char *op2){
    return atoi(op1) >> atoi(op2);
}

int and(char *op1, char *op2){
    return atoi(op1) & atoi(op2);
}

int or(char *op1, char *op2){
    return atoi(op1) | atoi(op2);
}

int xor(char *op1, char *op2){
    return atoi(op1) ^ atoi(op2);
}

int rotate_left(char *op1, char *op2){
    return (atoi(op1) << atoi(op2)) | (atoi(op1) >> (sizeof(op1) * 8 - atoi(op2)));
}

int rotate_right(char *op1, char *op2){
    return (atoi(op1) >> atoi(op2)) | (atoi(op1) << (sizeof(op1) * 8 - atoi(op2)));
}

//Input Validation
bool validate_format(int argc){
    if(argc == 4){
        return true;
    }else{
        return false;
    }
}

bool validate_simplecalc_inputs(int argc, char *argv[]){
    if(validate_format(argc)){
        return true;
    }else{
        display_manual();
        return false;
    }
}

//Output to Terminal
void simplecalc_print_answer_to_stdout(char *argv[]){
    if(strcmp(argv[2], "+") == 0){

        printf("%g", add(argv[1], argv[3]));
    
    }else if(strcmp(argv[2], "-") == 0){

        printf("%g", subtract(argv[1], argv[3]));

    }else if(strcmp(argv[2], "*") == 0){

        printf("%g", multiply(argv[1], argv[3]));
    
    }else if(strcmp(argv[2], "/") == 0){
    
        printf("%g", divide(argv[1], argv[3]));
    
    }else if(strcmp(argv[2], "%") == 0){
    
        printf("%g", modulo(argv[1], argv[3]));
    
    }else if(strcmp(argv[2], "lshift") == 0){
    
        printf("%d", left_shift(argv[1], argv[3]));
    
    }else if(strcmp(argv[2], "rshift") == 0){
    
        printf("%d", right_shift(argv[1], argv[3]));
    
    }else if(strcmp(argv[2], "and") == 0){
    
        printf("%d", and(argv[1], argv[3]));
    
    }else if(strcmp(argv[2], "or") == 0){
    
        printf("%d", or(argv[1], argv[3]));
    
    }else if(strcmp(argv[2], "xor") == 0){
    
        printf("%d", xor(argv[1], argv[3]));
    
    }else if(strcmp(argv[2], "rotr") == 0){
    
        printf("%d", rotate_right(argv[1], argv[3]));
    
    }else if(strcmp(argv[2], "rotl") == 0){
        
        printf("%d", rotate_left(argv[1], argv[3]));
    
    }else{
        
        printf("Operator type \"%s\" unsupported. \n", argv[2]);
        printf("Please use one of the following supported operators:\n");
        printf("+, -, *, /, %%, lshift, rshift, and, or, xor, rotl, rotr");
    
    }
}


//Debugging Aides/Optional Features
void echo_inputs(int argc, char *argv[]){
    if(argc > 1){
        
        for(int i = 1; i < argc; i++){
            printf("%s ", argv[i]);
        }

        printf("= ");
    }
}