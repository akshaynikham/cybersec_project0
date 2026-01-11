# Linear Algebra Refresher Notes

Reference - Linear Algebra Step-By-Step by **kuldeep singh**

# --------------------------------------------------------------------------------------------------------------------------------------



# **Linear Equations and Matrices**

## 

## <u>Intro to linear algebra</u>





##### **- Linear equation?**

1. An equation is where two mathematical expressions are defined as being equal.

2. A Liner equation is one where all the variable such as x,y, z have index (power) of 1 or 0 only, for example:
   
   $$
   x+2y+z = 5
   $$

Note: if an equation contains an argument of trigonometric, eponential, logarithmic or hyoerbolic funcitons then the equation is not linear.



A set of linear equations is called a **linear system**

Linear algebra is a systematic exploration of linear equations and is related to a new kind of arihmetic called the arithematic of matrices.

**system of linear equations or linear system:**

- Generally a finite number of linear equations with finite number of unknown x,y,z,w,.... is called system of linear equations or linear system.

- For example, the following is a linear system of three simultaneous equations with three unknowns x, y and z:

$$
x + 2y − 3z = 3
$$

$$
2x − y − z = 11
$$

$$
3x + 2y + z = −5
$$





In general, a linear system of m equations in n unknowns x1, x2, x3, ... , xn is written
mathematically as

                    ![](C:\Users\aksha\AppData\Roaming\marktext\images\2026-01-11-14-02-38-image.png)

where the coefficients aij and bj represent real numbers. The unknowns x1, x2, ... , xn are placeholders for real numbers.



##### **Types of solutions**

- A system that has no solution is called **inconsistent**.

- If the linear system has at least one solution then we say the system is consistent

        ![](C:\Users\aksha\AppData\Roaming\marktext\images\2026-01-11-14-09-10-image.png)



------------------------------------------------------------------------------------------------------------------------------

## - Gaussian Elimination



##### **Introduction to matrices:**

##### 

$$
2x + 2y = 3
$$

$$
2x + y = 2.5
$$


                                                    ![](C:\Users\aksha\AppData\Roaming\marktext\images\2026-01-11-14-19-54-image.png)


- The brackets on the left contain the coefficients from the problem, and is referred to as the **matrix** of coefficients.

- The brackets on the right hand side contain the total cost in a
  single column, and is referred to as a **vector**.



##### Elementary row operations:

- Suppose we have a general linear system of m equations with n unknowns labelled
  x1, x2, x3, ... and xn given by:
  
  - ![](C:\Users\aksha\AppData\Roaming\marktext\images\2026-01-11-14-24-11-image.png)
  
  - where the coefficients aij, bi are real numbers and x1, x2, x3, ... and xn are placeholders for real numbers that satisfy the equations.

- This general system can be stored in matrix form as:
  
  - ![](C:\Users\aksha\AppData\Roaming\marktext\images\2026-01-11-14-25-51-image.png)
  
  - This is an **augmented matrix**, which is a matrix containing the coefficients of the unknowns x1, x2, x3, ... , xn and the constant values on the right hand side of the equations
  
  - In everyday English language, augmented means **‘to increase’.**
  
  - **Augmenting a matrix** means adding **one or more columns to the original matrix.**

- **elementary row operations:**
  
  1. Multiply a row by a non-zero constant.
  
  2. Add or subtract a multiple of one row to another.
  
  3. Interchange rows.



##### Gaussian elimination:

- The aim of Gaussian elimination is to produce a ‘triangular’ matrix with zeros in the bottom left corner of the matrix.

- This is achieved by the elementary row operations:
  
  1. Multiply a row by a non-zero constant.
  
  2. Add or subtract a multiple of one row from another.
  
  3. Interchange rows.

- We say two matrices are **row equivalent** if one matrix is derived from the other by using these three operations.



##### Extending row operations:

- The Gaussian elimination process can be extended in the above example so that the first non-zero number in the bottom row of (∗) is 1, that is 
  
  - ![](C:\Users\aksha\AppData\Roaming\marktext\images\2026-01-11-14-46-31-image.png)



- The advantage of this is that we get the **z** value**directly**.

- This augmented matrix (∗) is said to be in **reduced row echelon form** normally abbreviated to **rref**, if it satisfies all the following conditions:
  
  - If there are any rows containing only zero entries then they are located in the bottom part of the matrix.
  
  - If a row contains non-zero entries then the first non-zero entry is a 1. This 1 is called a **leading 1**.
  
  - The leading 1’s of two consecutive non-zero rows go strictly from top left to bottom right of the matrix.
  
  - The only non-zero entry in a column containing a leading 1 is the leading 1.



- **The procedure which places an augmented matrix into row echelon form is called Gaussian elimination**

- **The algorithm which places an augmented matrix into a reduced
  row echelon form is called Gauss–Jordan elimination.**



------------------------------------------------------------------------------------------------------------------------------

## - Vector Arithmetic



#### **Vectors and Scalars**

- **The physical interpretation of a **vector **is a quantity that has size (magnitude) and direction**.

- Velocity, acceleration, force and displacement are all vector quantities.

- A scalar is a number that measures the size of a particular quantity.



##### Vectors in R^2

- R^2 is the x − y plane representing the Cartesian coordinate system named after the French mathematician and philosopher Rene Descartes.

- The points in the Cartesian plane are ordered pairs with reference to the origin, which is denoted by O.

- The order of the entries matters, that is the coordinate 
  a, b is different from b, a provided a = b



##### Vectors in R^3

- R3 is the set of all ordered triples of real numbers and is also called 3-space.

- The x − y plane can be extended to cover three dimensions by including a third axis
  called the z axis.



##### Vector addition in R^n is defined as

                        ![](C:\Users\aksha\AppData\Roaming\marktext\images\2026-01-11-15-05-57-image.png)



- The sum of the vectors u and v is calculated by adding the corresponding components.

- Note that u + v is also a vector in R^n

- Scalar multiplication kv is carried out by multiplying each component of the vector v by the scalar k:

                                       ![](C:\Users\aksha\AppData\Roaming\marktext\images\2026-01-11-15-07-26-image.png)

- Again kv is a vector in R^n. This R^n is called **Euclidean space**

- **Euclidean space** is the space of all n-tuples of real numbers. Here n is any natural number 1, 2, 3, 4, ... and is called the dimension of R^n



##### Introduction to the dot (inner) product

- One way is to take the dot product:
  
  - Let ![](C:\Users\aksha\AppData\Roaming\marktext\images\2026-01-11-15-35-46-image.png) be vectors in R^n, then the **dot product** of u and v which is denoted by u · v is the quantity given by

$$
u · v = u_1v_1 + u_2v_2 + u_3v_3 +···+ u_nv_n
$$

- This multiplication is called the dot or inner product of the vectors **u** and **v**



##### Linear combination of vectors

- Let v1, v2, ... , vn be vectors in Rn and k1, k2, ... , kn be scalars, then the dot product
  
  
  ![](C:\Users\aksha\AppData\Roaming\marktext\images\2026-01-11-15-41-02-image.png)



- Note that for any vector **v** we have:
  
                                          ![](C:\Users\aksha\AppData\Roaming\marktext\images\2026-01-11-15-42-03-image.png)

- The zero vector in R^n is denoted by O and is defined as being **‘non-empty**’, although all entries are **zero**



------------------------------------------------------------------------------------------------------------------------------

### - Arithmetic of Matrices





#### Matrices revisited

- A **matrix **is an array of numbers enclosed in brackets.

- The numbers in the array are called the **entries** or the **elements of the matrix**. 

- The term **matrices** is the **plural** of matrix.

- The size of a matrix is given by the **number of rows and columns**.

- The columns of a matrix are called the **column vectors** of the matrix. The rows of a matrix are called the **row vectors** of the matrix.



##### **scalar multiplication mean?**

- A scalar is a number which is used to multiply the entries of a matrix.

- Let **A** be a matrix and k be a scalar, then the scalar multiplication kA is the matrix constructed by multiplying each entry of **A** by k.
  
  - ![](C:\Users\aksha\AppData\Roaming\marktext\images\2026-01-11-15-56-26-image.png)

- Note that scalar multiplication of a matrix results in a matrix of the same size.





##### Matrix addition

- The sum of matrices of size m by n (m rows by n columns) is defined by:

    ![](C:\Users\aksha\AppData\Roaming\marktext\images\2026-01-11-16-01-31-image.png)

- Similarly the subtraction of these matrices is:
  

![](C:\Users\aksha\AppData\Roaming\marktext\images\2026-01-11-16-01-58-image.png)

- The result of Addition or Substraction is another matrix of the same size as the initial matrices.

- This is also the case for vector addition and subtraction, because a vector is simply a particular type of matrix.



##### Matrix vector product

- we need to define matrix times a vector as the product of row by columns
  
  - ![](C:\Users\aksha\AppData\Roaming\marktext\images\2026-01-11-16-05-24-image.png)
    
    
    
    ![](C:\Users\aksha\AppData\Roaming\marktext\images\2026-01-11-16-06-07-image.png)



##### Matrix times matrix

- Matrix multiplication of matrix A with n columns, and matrix B = (c_1 c_2 ··· c_k) with n rows and k columns, is defined as

$$
AB = A(c_1 c_2 ··· c_k) = (Ac_1 Ac_2 ··· Ac_k)
$$

- Matrix multiplication **AB** means that the matrix A acts on each of the column vectors of **B**.

- For **AB** we must have
  
  - **Number of columns of matrix A = Number of rows of matrix B.**

- In general, if **A** is a m × r (m rows by r columns) matrix and **B** is a r × n (r rows by n columns) matrix then the multiplication **AB** results in a m × n matrix.

- A matrix with just one row such as (3 4) is called a **row matrix** or **row vector**.

- A matrix of size n × 1 (n rows by one column) is generally called a **column vector**



---

### **- Matrix Algebra**





##### Properties of matrix addition

- **zero matrix means:**
  
  - A zero matrix is a matrix which has all zero entries and it is denoted by O
  
  - ![](C:\Users\aksha\AppData\Roaming\marktext\images\2026-01-11-17-18-33-image.png)

       

- **Properties of Matrix Addition**
  
  - **A** + **B**= **B** + **A**
  
  -  (**A**+ **B**) + **C** = **A** + (**B** + **C**) (Associative law for addition)
  
  - ![](C:\Users\aksha\AppData\Roaming\marktext\images\2026-01-11-17-23-46-image.png)
  
  - There is an m × n matrix called the zero matrix, denoted O, which has the property:
    
    - **A** + **O** = **A**
  
  - There is a matrix denoted **−A** such that:
    
    - **A** + (**−A**) = **A** − **A** = **O**
    
    - This matrix **−A** is called the additive inverse of A



##### Properties of scalar multiplication

- ck**A** = c (k**A**)

- k (**A**+ **B**) = k**A** + k**B**

- (c + k) **A**= c**A**+ k**A**



##### Properties of matrix multiplication

- (**AB**)**C** = **A** (**BC**) (associative law for multiplication).

- **A** (**B** + **C**) = **AB** + **AC** (left distributive law).

- (**B** + **C**) **A** = **BA** + **CA** (right distributive law).

- **A** × **O** = **O** × **A** = **O**. Note that multiplication is commutative in this case.



---

### The Transpose and Inverse of a Matrix



- You cannot divide matrices. The nearest operation to division of matrices is the **inverse matrix**



##### **Transpose of a matrix**

- In general, the entry aij (ith row by jth column) of matrix A is transposed to aji (jth row by ith column) in A^T.

- A column vector such as <img src="file:///C:/Users/aksha/AppData/Roaming/marktext/images/2026-01-11-18-49-31-image.png" title="" alt="" width="56"> can be written as the transpose of a row vector, that is <img src="file:///C:/Users/aksha/AppData/Roaming/marktext/images/2026-01-11-18-50-06-image.png" title="" alt="" width="99">

- Note, that transposing a matrix of size m × n (m rows by n columns) gives a matrix of size n × m (n rows by m columns). 

- If m != n then transposing changes the shape of the matrix.



##### Properties of matrix transpose:

$$
(A^T)^T = A
$$

$$
(kA)^T = kA^T
$$

$$
(A + b)^T = A^T + B^T
$$

$$
(AB)^T = B^T A^T
$$

##### Identity matrix:

- The identity matrix is a matrix denoted by **I** such that
                          **AI**= **A** for any matrix **A**

- **Identity must be a square matrix**

- **Definition**. An identity matrix is a square matrix denoted by **I** and defined by

                            ![](C:\Users\aksha\AppData\Roaming\marktext\images\2026-01-11-19-00-27-image.png)

- All the entries in the leading diagonal (top left to bottom right) of a matrix I are 1, that is            i_11 = i_22 = i_33 = i_44 =···= 1

- **Pre-multiplying by I mean?**
  
  - It means the left hand matrix in a matrix multiplication is **I**.

- **Post-multiplying by I mean?**
  
  - It means the right hand matrix in a matrix multiplication is **I**.

- Let I be the identity matrix. Then 
  
  $$
  I^T = I
  $$



##### <u>Inverse matrix</u>



- Let x != 0 be a real number then the inverse of x is a real number x^−1 such that
  
  $$
  x(x^{-1}) = I
  $$

- Given a square matrix **A** then the inverse of **A** is a square matrix **B** such that
  
  $$
  AB = I
  $$

        where I is the identity matrix defined earlier.

- $$
  Note : A^{-1} != 1/A
  $$

- **Definition**. A square matrix **A** is said to be **invertible** or **non-singular** if there is
  a matrix **B** of the same size such that

$$
AB = BA = I
$$

        Matrix **B** is called the (**multiplicative**) inverse of **A** and is denoted by **A^−1**

- If matrices A and B are of the same size then it can be shown that **AB = I** ,if and only if **BA = I**. In this case, matrix multiplication is commutative, which means it does not matter about the order of multiplication.

- If **BA = I** then we call matrix **B** the **left inverse of A**.

- if **AC = I** then we call matrix **C** the **right inverse of A**.
  
  

- **<u>Why is the inverse matrix important?</u>**
  
  - We want to use matrices to solve a system of linear equations which we can generally write as **Ax = b** where **x** is the vector of unknowns that we need to find.
  
  - If we multiply both sides of this **Ax = b** by the inverse matrix **A^−1** we obtain:

$$
A^{−1} (Ax) = A^{−1}b
$$

$$
A^{-1}Ax = Ix = x = A^{-1}b
$$

- Hence we can find the **unknowns by finding the inverse matrix, because**
  
  $$
  x = A^{−1}b
  $$

- **Non-Invertible Matrix**:
  
  - **Definition.** A square matrix **A** is said to be **non-invertible** or **singular** if there is no
    matrix **B** such that **AB = BA = I**.
  
  - The zero matrix **O** has no inverse. We say the zero matrix is non-invertible.


