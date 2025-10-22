# push_swap

## About Project 

push_swap is an individual project developed at Hive Helsinki (the 42 Network) as part of curriculum. 

The main goal is to **sort a list of integers** using a **limited set of stack operations** and **two stacks (A and B)**,
with the focus on **algorithmic optimization** and **time complexity**.
You are required to print to standard output the **shortest possible sequence of operations** that sorts the stack in ascending order.  
This project strengthens your understanding of **data structures**, **sorting algorithms**, and **algorithmic efficiency**.

## Features:
🔹 **Validated Input Handling**  
  - Detects duplicates, non-integer values, and integer overflow.  
  - Handles both positive and negative integers.

🔹 **Custom Stack Implementation**  
  - Built from scratch using linked lists.  
  - Supports efficient push, pop, rotate, and reverse operations.

🔹 **Operation Set Supported**  
  | Operation | Description |
  |------------|-------------|
  | `sa`, `sb`, `ss` | Swap the top two elements of stack A and/or B |
  | `pa`, `pb` | Push top element from one stack to another |
  | `ra`, `rb`, `rr` | Rotate stack upwards |
  | `rra`, `rrb`, `rrr` | Reverse rotate stack downwards |
  
🔹 **Efficient Sorting Algorithm**  
  Uses a combination of tailored sorting strategies depending on the size of the input:  
  - *Small inputs (≤ 5 elements)*: Simple swaps and rotations (hardcoded patterns).  
  - *Medium inputs (≤ 100 elements)*: Chunk-based sorting.  
  - *Large inputs (> 100 elements)*: Optimized radix sort or chunked approach for minimal operations.

## How To Run:

### Requirements:
Linux OS

### Installment:
#### 1. Clone the Repository
```bash
git clone git@github.com:TrangPham93/push_swap.git push_swap
cd push_swap
```
#### 2. Compile the Project
```bash
make
```
#### 3. Run the project
```bash
./push_swap [list of integers, inside or outside double quote]
```

#### 4. Examples

<img width="400" height="80" alt="image" src="https://github.com/user-attachments/assets/eda6adf1-7afe-4183-99cb-58d7672a393c" />


## Authors

Trang Pham – GitHub <https://github.com/TrangPham93>

