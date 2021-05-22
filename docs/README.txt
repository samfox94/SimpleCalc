Use bash.sh to compile and build the simplecalc binary. The binary is output to SimpleCalc\build\Release directory.

**USAGE MANUAL for SimpleCalc**
simplecalc.exe [OPERAND1] [OPERATOR] [OPERAND2]
Valid Operators:
        "+"             Addition,                       Format: [DOUBLE] + [DOUBLE]
        "-"             Subtraction,                    Format: [DOUBLE] - [DOUBLE]
        "*"             Multiplication,                 Format: [DOUBLE] * [DOUBLE]
        "/"             Division,                       Format: [DOUBLE] / [DOUBLE]
        "%"             Modulus/Remainder,              Format: [INTEGER] % [INTEGER]
        "lshift"        Bitwise Shift Left,             Format: [INTEGER--decimal format of number being shifted] lshift [INTEGER--number of bits to shift]
        "rshift"        Bitwise Shift Right,            Format: [INTEGER--decimal format of number being shifted] rshift [INTEGER--number of bits to shift]
        "and"           Bitwise AND,                    Format: [INTEGER] AND [INTEGER]
        "or"            Bitwise OR,                     Format: [INTEGER] OR [INTEGER]
        "xor"           Bitwise XOR,                    Format: [INTEGER] XOR [INTEGER]
        "rotl"          Bitwise Rotate Left,            Format: [INTEGER--decimal format of number being shifted] rotl [INTEGER--number of bits to shift]
        "rotr"          Bitwise Rotate Right,           Format: [INTEGER--decimal format of number being shifted] rotr [INTEGER--number of bits to shift]