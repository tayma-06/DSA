# Infix to Prefix

🔗 **Problem Link:** [GeeksforGeeks - Infix to Prefix](https://www.geeksforgeeks.org/problems/infix-to-prefix-1587115621/1)

---

## Problem Statement

You are given a string `s` representing an **infix expression**. Convert this infix expression to a **prefix expression**.

- **Infix expression:** The expression of the form `a op b`. The operator is placed **between operands**.  
- **Prefix expression:** The expression of the form `op a b`. The operator comes **before its two operands**.

**Operator precedence:**
1. `^` → highest precedence, evaluated **right to left**  
2. `*` and `/` → next, **left to right**  
3. `+` and `-` → lowest, **left to right**

---

### Constraints
- `3 ≤ s.length ≤ 5*10³`  
- `s[i]` can be an **operand** (`a–z`, `A–Z`, `0–9`), an **operator** (`+`, `-`, `*`, `/`, `^`), or a **parenthesis** (`(`, `)`)

---