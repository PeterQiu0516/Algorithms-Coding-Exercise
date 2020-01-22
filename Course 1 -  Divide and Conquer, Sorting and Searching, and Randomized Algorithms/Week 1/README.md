# Week 1

## Summary
+ ### Karatsuba
  To compute the product of two decimal integers `x` and `y` with approximately `n` digits.
  
  Take `x = 5678, y = 1234` as an example.
  
  + Step 1: Write `x = 10^(n/2) * a + b , y = 10^(n/2) * c + d`, where `a = 56, b= 78, c = 12, d = 34` are n/2-digit numbers.
  + Step 2: Compute `ac` and `bd` and `t = (a+b)(c+d)` 
  + Step 3: `xy = 10^n*ac+10^(n/2)*(ad+bc)+bd = 10^n*ac+10^(n/2)*(t-ac-bd)+bd (*)`
  + Step 4: Recursively compute `ac, bd and t` until the multiplcation get down to 1-digit simple calculation.
  
    E.g.: `ac = 56*12 = (5*10 + 6) * (1*10 +2) = 100*(5*1) + 10*[(5+6)*(1+2)-5*1-6*2] + (6*2) = 672`
+ ### Merge Sort
+ ### Asymptotic Analysis

## Lecture Slides
+ [Intro&Karatsuba&MergeSort]()
+ [Asymptotic Analysis]()

## Problem Set #1

Some conceptional questions about the course content.

## Programming Assignment #1

### Instructions:
In this programming assignment, you will implement one or more of the integer multiplication algorithms described in lecture.

To get the most out of this assignment, your program should restrict itself to multiplying only pairs of single-digit numbers by implementing **recursive integer multiplication and/or Karatsuba's algorithm.**

So: *what's the product of the following two 64-digit numbers?*

> **3141592653589793238462643383279502884197169399375105820974944592**

> **2718281828459045235360287471352662497757247093699959574966967627**

---
[Food for thought: the number of digits in each input number is a power of 2. Does this make your life easier? Does it depend on which algorithm you're implementing?]
