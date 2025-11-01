# INFIX ALGORITHM

- Step 1. Initialize two stacks: one for operands, one for operators
- Step 2. Scan the expression from left to right
- Step 3. If it is an operand, push it to operand stack
- Step 4. If it is an operator,
- -  While operator stack is not empty and top operator has higher or equal precedence,
- - Pop operator from operator stack
- - Pop two operands from operand stack
- - Perform operation and push result back to operand stack
- - Push current operator to operator stack
- Step 5. If it is ‘(’, push it to operator stack
- Step 6. If it is ‘)’,
- - While top of operator stack is not ‘(’,
- - Pop operator and two operands, perform operation, push result back
- - Pop the ‘(’ from operator stack
- Step 7. Repeat steps 2–6 until all tokens are scanned
- Step 8. While operator stack is not empty,
- - Pop operator and two operands, perform operation, push result back
- Step 9. Top of operand stack is the final result