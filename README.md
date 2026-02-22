# 📘 Arbitrary Precision Calculator (APC) using C

A **menu-driven Arbitrary Precision Calculator developed in C**, designed to perform arithmetic operations on very large integers using a **custom Doubly Linked List implementation**.

This project demonstrates strong fundamentals in **Data Structures, C programming, memory management, and algorithm design**.

---

## 🚀 Project Description

The Arbitrary Precision Calculator (APC) enables users to perform arithmetic operations on numbers that exceed the limit of standard C data types (int, long).

Instead of using built-in libraries, the calculator represents large numbers using a **Doubly Linked List**, where each node stores a single digit.

All arithmetic operations are implemented manually to ensure a deep understanding of number manipulation and algorithm efficiency.

This project was developed as part of the **Advanced C and Linux Systems Programming training at Emertxe Information Technologies**.

---

## 🎯 Objective

- Implement big-integer arithmetic without using built-in large number libraries  
- Apply **Data Structures (Doubly Linked Lists)** in real-world computation  
- Understand algorithm complexity and optimization  
- Strengthen memory management and modular programming skills  

---

## ✨ Features

- Addition of large integers  
- Subtraction with proper borrow handling  
- Optimized multiplication using grade-school algorithm (O(n²))  
- Long division implementation (O(n²))  
- Comparison of large numbers  
- Dynamic memory allocation and safe deallocation  
- Clean modular code structure  

---

## 🛠️ Technologies & Concepts Used

- **C Programming**
- **Doubly Linked Lists**
- **Dynamic Memory Allocation (malloc, free)**
- **Pointers & Pointer-to-Pointer Handling**
- **Algorithm Optimization**
- **Time Complexity Analysis**
- **Modular Programming**
- **Input Validation**

---

## 🧠 How the Application Works

- Each number is stored as a **Doubly Linked List**
  - Head → Most Significant Digit (MSB)
  - Tail → Least Significant Digit (LSB)
- Arithmetic operations traverse from tail to head to handle carry and borrow.
- Multiplication uses the grade-school method.
- Division uses an optimized long-division approach instead of repeated subtraction.
- Temporary lists are deleted properly to avoid memory leaks.
- Modular design improves readability and maintainability.

---

## 📂 Project Structure

```
APC/
├── main.c
├── addition.c
├── subtraction.c
├── multiplication.c
├── division.c
├── insert_delete.c
├── validate.c
├── print_list.c
└── main.h
```

---

## ▶️ Compilation and Execution

### Compile:
```bash
gcc *.c -o apc
```

### Run:
```bash
./apc
```

---

## 📊 Time Complexity

| Operation       | Time Complexity |
|----------------|----------------|
| Addition       | O(n)           |
| Subtraction    | O(n)           |
| Multiplication | O(n²)          |
| Division       | O(n²)          |

---

## 🧪 Sample Usage

```
Enter first number  : 123456789123456789
Enter operator      : *
Enter second number : 987654321987654321

Result:
121932631356500531347203169112635269
```

---

## 📈 Learning Outcome

This project strengthened my understanding of:

- Data Structures and algorithm design  
- Big-integer arithmetic implementation  
- Memory management and pointer handling  
- Time complexity optimization  
- Writing clean, modular C code  

It improved my confidence in solving logic-intensive problems and implementing system-level solutions.

---

## 👨‍💻 Author

**Manu H P**  
Embedded Systems Enthusiast  
Skilled in C Programming, Linux Internals, and Data Structures  

---

## 📎 GitHub Repository

```
https://github.com/Manu-hp1/Arbitrary_Precision_Calculator
```

---

## 📄 License

This project is developed for learning and educational purposes.
