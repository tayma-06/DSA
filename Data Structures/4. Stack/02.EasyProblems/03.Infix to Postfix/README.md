# Infix to Postfix

🔗 **Problem Link:** [GeeksforGeeks - Infix to Postfix](https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1)

---

## Problem Statement

You are given a string `s` representing an **infix expression**. Convert this infix expression to a **postfix expression**.

- **Infix expression:** The expression of the form `a op b`. When an operator is in between every pair of operands.  
- **Postfix expression:** The expression of the form `a b op`. When an operator is **after** every pair of operands.

**Operator precedence:**
1. `^` → highest precedence, evaluated **right to left**
2. `*` and `/` → next, **left to right**
3. `+` and `-` → lowest, **left to right**

---

### Constraints
- `1 ≤ s.length ≤ 5*10³`  
- `s[i]` can be an **operand** (`a–z`, `A–Z`, `0–9`), an **operator** (`+`, `-`, `*`, `/`, `^`), or a **parenthesis** (`(`, `)`)

---
