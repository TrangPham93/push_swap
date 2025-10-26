# push_swap

push_swap implements a sorting algorithm to **sort a list of integers** using a **limited set of stack operations** and **two stacks (A and B)**.
The **shortest possible sequence of operations** that sorts the stack in ascending order will be printed to standard output.

## Features:
🔹 Input requirements  
  - Duplicates, non-integer values are not allowed and integer overflow is detected.  
  - Handles both positive and negative integers.

🔹 Custom Stack Implementation
  - Built from scratch using linked lists.  
  - Supports stack operations like push, swap, rotate and reverse rotate.

🔹 Operation Set
  | Operation | Description |
  |------------|-------------|
  | `sa`, `sb` | Swap the top two elements of stack A or B |
  | `pa`, `pb` | Push top element from one B to A or A to B |
  | `ra`, `rb` | Shift all elements of stack A or B up by 1 position |
  | `rra`, `rrb` | Shift all elements of stack A or B down by 1 position |
  |`ss`, `rr`, `rrr` | Do swap or rotate or reverse rotate on both stacks at the same time |
  
🔹 Sorting Algorithm
  Depending on the size of the input:  
  - 1 element or already sorted list: no operation and return.
  - Small list (≤ 5 elements): Simple swaps and rotations (hardcoded patterns).  
  - If input list has more than 5 elements:
    - I use an array to save all the operation: push, swap, rotate and reverse rotate during the below process.
    - While there are more than 5 elements in stack A, repeat: find `mean` of the stack A: all elements smaller or equal to `mean` pushed to stack B, otherwise rotate stack A to the next element.
    - When stack A has only 5 elements left, use sorting function for 5 elements as above.
    - For each element in stack B, find the smallest element in stack A that is larger than the number in stack B (best friend), and calculate how many moves it takes for each element and its best friend to move to top. Implement the best move that has the smallest number of operations to move an element in stack B and its friend in stack A to top, and push the element from stack B to A. Repeating this process until there is nothing left in stack B.
    - Reorder the stack A in ascending order.
    - Finally, optimize the operation array and print to standard output: if 2 swap operations or 2 rotate operations or 2 reverse rotate operation are next to each other in the array, I use the `ss` or `rr` or `rrr` operation on both stacks at the same time instead.


## How To Run:

### Requirements:
Linux OS

### Installment:
#### 1. Clone the Repository
```bash
git clone https://github.com/TrangPham93/push_swap.git push_swap
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
Sort a simple list of interger and use checker_linux provided by the subject to recheck the sorting command.

<img width="632" height="252" alt="image" src="https://github.com/user-attachments/assets/07febf63-7ebc-4247-a360-15186171d84a" />

#### 5. Visualize the sorting algorithm
[This is a great tool I found to visualize the sorting process](https://push-swap42-visualizer.vercel.app/)

![Untitled video](https://github.com/user-attachments/assets/d6a934cd-c2ed-4b3d-b946-426149a93157)




