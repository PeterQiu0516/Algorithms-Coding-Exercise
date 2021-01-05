# Week 1 - Merge Sort, "big-oh" notation and asymptotic analysis



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
  Basic sorting algorithm based on Divide and Conquer:
  + Step 1: recursively sort first half of the input array
  + Step 2: recursively sort second half of the unput array
  + Step 3: merge two sorted sublists into one
  
    Code written in `Python` (You may also refer to the `MergeSort.py` file):
    ```
    def merge_sort(arr):
      n = len(arr)
      if (n <= 1):
          return arr
      elif (n == 2):
          if (arr[0] >= arr[1]):
              t = arr[0]
              arr[0] = arr[1]
              arr[1] = t
          return arr
      else:
          A = merge_sort(arr[:int(n/2)])
          B = merge_sort(arr[int(n/2):])

          #Merge A & B
          arr = list(np.zeros(n))
          i = 0
          j = 0
          for k in range(0,n):
              if i < int(n/2) and (j == len(B) or A[i]<=B[j]):
                  arr[k] = A[i]
                  i = i + 1
              else:
                  arr[k] = B[j]
                  j = j + 1
          print(arr)
          return arr
    ```
+ ### Asymptotic Analysis
  + O(n) (Big O Notation) : less than or equal to (upper bound)
  + Ω(n) (Big Omega Notation) : greater than or equal to (lower bound)
  + Θ(n) (Big theta notation) : both O(n) & Ω(n), equal to
  
  `E.g. T(n) for merge sort <= 4nlogn + 6n = O(nlogn) = O(n^2) = Ω(nlogn) = Ω(n) = Θ(nlogn) ≠ Θ(n)`



## Lecture Slides

+ [Intro & Karatsuba & MergeSort]()
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


### Solutions:

Code written in `C++`, included in the `Karatsuba.cpp` file.


