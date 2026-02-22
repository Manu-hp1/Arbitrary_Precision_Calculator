# 📘 **Arbitrary Precision Calculator (APC) using C**

A menu-driven **Arbitrary Precision Calculator** developed in **C**, designed to perform** arithmetic operations** on **very large integers** using custom **Doubly Linked List** implementation.

This project demonstrates strong fundamentals in Data Structures, C programming, memory management, and algorithm design.
---

## 🚀 Project Description

The **Arbitrary Precision Calculator (APC)** enables users to perform arithmetic operations on numbers that exceed the limit of standard C data types (int, long).

Instead of using built-in libraries, the calculator represents large numbers using a Doubly Linked List, where each node stores a single digit.

All arithmetic operations are implemented manually, ensuring a deep understanding of number manipulation and algorithm efficiency.

This project was developed as part of the **Advanced C** and **Linux Systems Programming** training at **Emertxe Information Technologies**.
---

## 🎯 Objective

- To implement** big-integer arithmetic** without using built-in large number libraries
- To apply **Data Structures (Doubly Linked Lists)** in real-world computation
- To understand algorithm **complexity and optimization**
- To strengthen memory management and modular programming skills
  
---

## ✨ Features

- Addition of large integers
- Subtraction with borrow handling
- Optimized multiplication using grade-school algorithm (O(n²))
- Long division implementation (O(n²))
- Proper comparison of large numbers
- Memory-safe dynamic allocation and deallocation
- Modular and structured code design

---

## 🛠️ Technologies & Concepts Used

- **C Programming**
- **Doubly Linked Lists**
- **Dynamic Memory Allocation (malloc, free)**
- **Pointers and Pointer-to-Pointer Handling**
- **Algorithm Optimization**
- **Time Complexity Analysis**
- **Modular Programming**
- **Input Validation**

---

## 🧠 How the Application Works

- Contact details are stored using **structures**  
- Data is written to and read from files to ensure persistence  
- Each operation (add, search, edit, delete) is handled through separate logical modules  
- Input validation is implemented to avoid invalid or duplicate entries  
- The program follows a clean control flow for better readability  

---

## 📂 Project Structure

```text
AddressBook/
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
└── contacts.csv
```

---

## ▶️ Compilation and Execution

### Compile and run:
```bash
gcc *.c -o address_book
./address_book
```

## Learning Outcome and Impact

This project strengthened my understanding of core C programming concepts such as structures, pointers, and file handling. It improved my problem-solving approach, debugging skills, and ability to design clean, modular applications. Working on this project increased my confidence in translating theoretical knowledge into a practical, working solution.

---

## Acknowledgment

I would like to sincerely thank Anand Lokhande Sir for his guidance and clear explanation of C programming concepts, which helped me build this project with a strong logical foundation.

---

## GitHub Repository

[https://github.com/Manu-hp1/Address_Book]

---

## About Me

I am an Embedded Systems Trainee at Emertxe Information Technologies, building strong fundamentals in C programming, Linux, and system-level concepts. I am passionate about writing clean code and continuously improving my technical skills.

---

## License

This project is developed for learning and educational purposes.

