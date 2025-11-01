# PREFIX ALGORITHM
- Step 1. Scan the expression from right to left
- Step 2. Initialize an empty stack
- Step 3. If it is an operand, push it to stack
- Step 4. If it is an operator,
- - Pop two operands from stack
- - Perform operation: first popped operand operator second popped operand
- - Push result back to stack
- Step 5. Repeat steps 2–4 until all tokens are scanned
- Step 6. Top of stack is the final result