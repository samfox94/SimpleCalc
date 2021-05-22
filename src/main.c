#include <simplecalc.h>

int main(int input_string_count,  char *input_strings[])
{
    
    if(validate_simplecalc_inputs(input_string_count, input_strings)){
        simplecalc_print_answer_to_stdout(input_strings);
    }

    return 0;
}

