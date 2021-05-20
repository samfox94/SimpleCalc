#include "../hdrs/simplecalc.h"

int main(int argc,  char *argv[])
{
    if(validate_simplecalc_inputs(argc, argv)){
        simplecalc_print_answer_to_stdout(argv);
    }

    return 0;
}

