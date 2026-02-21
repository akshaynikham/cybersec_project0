## **Congruence**

a ≡ b mod (m)



looks like an equation… but it is **NOT an equation**.

It is a **relationship**.



a congruent to b mod m

> a equals b after division” ❌ Not correct
> 
> We are not comparing the numbers themselves.
> 
> We are comparing their behaviour under a rule.





∴ a = km + b

<img src="file:///C:/Users/aksha/AppData/Roaming/marktext/images/2026-02-14-06-10-21-image.png" title="" alt="" width="96">

When a mathematician writes $a \equiv b \pmod{n}$, they are actually hiding a subtraction and division problem inside it.

The formal definition is:

**n | (a - b)**



Two numbers are congruent if:

                           **n | ( a -b )**

which means they differ by a multiple of n.



*(This vertical bar symbol $|$ means "divides" or "is a factor of".)*

**Example: $17 \equiv 5 \pmod{6}$**

- **Translation:** $6$ divides $(17 - 5)$.

- **Check:** $17 - 5 = 12$. Since $6$ goes into $12$ perfectly, the notation is correct.



So they lie on the same cycle step.

Think:

> Congruence = Same location on an infinite repeating track



> Congruence does NOT say two numbers are equal.  
> It says the system you are working in cannot tell them apart.



# Deep Intuition:

---

## 1. Meaning of Congruence

$$
[ a \equiv b \pmod n ]
$$



**Core meaning:**

> a and b differ by a multiple of n

$$
[ a - b = kn \quad (k \in \mathbb{Z}) ]
$$



So congruence is **not equality**.  It is equality after ignoring blocks of size n.

---

### Mental Interpretation

Congruence means:

> a and b belong to the same remainder family when numbers are grouped in n’s.

So in mod-n arithmetic, they can replace each other safely.

$$
Example: [ 17 \equiv 5 \pmod{12} ]
$$

Because:  [  17 - 5 = 12  ]

---

## 2. Residue Classes

A residue class is a set of all integers congruent to a number.

$$
[  
[a] = { a + kn \mid k \in \mathbb{Z} }  
]
$$

Example (mod 5):

$$
[  
[2] = { ..., -8, -3, 2, 7, 12, 17, ... }  
]
$$

All numbers in the same class behave identically in mod-5 arithmetic.

$$
[  
\mathbb{Z}_5 = {[0],[1],[2],[3],[4]}  
]
$$

We perform arithmetic on these classes.

---

## 3. Modular Arithmetic as a Circle

Modulo n behaves like positions on a circular track.

Numbers wrap around after n.

Example mod 5:

0 → 1 → 2 → 3 → 4 → back to 0

So numbers represent positions, not size.

---

## 4. Multiplication = Fixed Jump Size

Multiplying by a number a means:

> Move around the circle using jump length a.

Example: multiply by 2 in mod 5

0 → 2 → 4 → 1 → 3 → 0

All positions visited → full shuffle.

---

## 5. When Division Exists

Division means multiplication can be reversed.

This requires:

> Every output must come from exactly one input

If multiplication merges positions → division impossible.

---

### Example: mod 5 (works)

Multiply by 2:

| Input | Output |
| ----- | ------ |
| 0     | 0      |
| 1     | 2      |
| 2     | 4      |
| 3     | 1      |
| 4     | 3      |

Every output unique → reversible → inverse exists.

---

### Example: mod 6 (fails)

Multiply by 2:

| Input | Output |
| ----- | ------ |
| 0     | 0      |
| 1     | 2      |
| 2     | 4      |
| 3     | 0      |
| 4     | 2      |
| 5     | 4      |

Outputs repeat → cannot reverse → no inverse.

---

## 6. Role of GCD

Division in mod n exists only when:

$$
[  
\gcd(a,n)=1  
]
$$

Reason:  
If gcd(a,n) > 1, jumps repeat early and cover only part of the circle.

Cycle length:

$$
[  
\text{positions visited} = \frac{n}{\gcd(a,n)}  
]
$$

So only gcd=1 visits entire circle.

---

## 7. Final Intuition Summary

Congruence:

> equality ignoring multiples of n

Residue class:

> family of indistinguishable numbers

Modulo arithmetic:

> arithmetic of positions on a cycle

Division exists:

> only when multiplication does not collapse positions

$$
Condition:   
[  
\gcd(a,n)=1  
]
$$

---

# GCD, Cycles, and Why Division Works in Modular Arithmetic



## 1. Modular Arithmetic as a Circle

Working **mod n** means numbers are positions on a circle with n equally spaced points.

Example: mod 6  
Positions: 0,1,2,3,4,5 (then repeat)

Numbers don’t grow — they wrap.

---

## 2. Multiplication = Fixed Step Movement

Multiplying by a number **a** means:

> Move around the circle using step size a

So the positions visited are:

0 → a → 2a → 3a → 4a → … (mod n)

We keep walking until we return to 0.

---

## 3. What We Are Checking

We want to know:

Does this movement visit **every position once**  

OR  

Does it get trapped in a smaller loop?

This determines whether division is possible.

---

## 4. When Positions Collapse (gcd(a,n) > 1)

If a and n share a common factor **d > 1**,  
the circle splits into **d separate lanes**.

We can only move inside one lane.

### Example: mod 6, step 2

gcd(2,6)=2

Lanes formed:

Lane A: 0,2,4  

Lane B: 1,3,5

Walking:

0 → 2 → 4 → 0 → …

We never reach the other lane.

So multiple starting points land on same output:

1×2 ≡ 2  

4×2 ≡ 2

Multiplication merges numbers → division impossible.

---

## 5. When Perfect Shuffle Happens (gcd(a,n)=1)

If a and n share no common factor:

There is only ONE lane (entire circle).

### Example: mod 5, step 2

gcd(2,5)=1

Walk:

0 → 2 → 4 → 1 → 3 → 0

All positions visited exactly once.

Multiplication becomes reversible → division exists.

---

## 6. Meaning of GCD (Geometric Interpretation)

$$
[  
\gcd(a,n) = \text{number of lanes formed in the circle}  
]
$$

Number of positions in each lane:

$$
[  
n / \gcd(a,n)  
]
$$

So:

- gcd = 1 → 1 lane → full coverage

- gcd > 1 → multiple lanes → trapped movement

---

## 7. Connection to Division

Division means reversing multiplication.

Reversal possible only if each output comes from exactly one input.

Therefore:

$$
[  
a^{-1} \text{ exists mod n } \iff \gcd(a,n)=1  
]
$$

---

## 8. Final Intuition

Modular multiplication is movement on a circular track.

If the step size splits the circle into smaller repeating tracks → numbers collide → no division.

If the step size sweeps the whole circle → perfect shuffle → division works.

---

**Memory Anchor:**

GCD counts how many tracks the circle breaks into.

One track → invertible  

Many tracks → not invertible

---

# 

---

##### Common notations:

| **Notation**          | **Meaning**                                                                         |
| --------------------- | ----------------------------------------------------------------------------------- |
| $a \pmod{n}$          | Often used in computer science as a **function** (the remainder of $a/n$).          |
| $a \equiv b \pmod{n}$ | Used in Number Theory as a **relation** between two numbers.                        |
| $\mathbb{Z}_n$        | The set of all possible remainders $\{0, 1, 2, \dots, n-1\}$.                       |
| $[a]_n$               | The "Residue Class" of $a$. It represents *every* number congruent to $a \pmod{n}$. |

---

##### Properties:

<img src="file:///C:/Users/aksha/AppData/Roaming/marktext/images/2026-02-14-06-31-20-image.png" title="" alt="" width="569">

![](C:\Users\aksha\AppData\Roaming\marktext\images\2026-02-14-06-34-00-image.png)

---

## Euclidean Algorithm

1. fast, recursive way to find the **GCD** (Greatest Common Divisor) of two numbers. Instead of listing all the factors, we use the "remainder" logic.

#### Core logic:

1. The algorithm is based on this one fact:
   
   > The GCD of two numbers doesn't change if we replace the larger number with the remainder of the larger divided by the smaller.
   
   **Formally:** $\gcd(a, b) = \gcd(b, a \pmod{b})$

##### Example:

$\gcd(105, 45)$

We repeat the division process until the remainder is **0**. The last non-zero remainder is our answer.

- **Step 1:** Divide 105 by 45.
  
  - $105 = 2 \times 45 + \mathbf{15}$

- **Step 2:** Now, bring down the **45** and the **15**. Divide 45 by 15.
  
  - $45 = 3 \times 15 + \mathbf{0}$

- **Step 3:** The remainder is now 0.
  
  - Look at the line above. The last non-zero remainder was **15**.

**Answer:** $\gcd(105, 45) = 15$.

---

### The Fundamental Theorem of Arithmetic - FTA ("Unique Factorization Theorem.")

The **Fundamental Theorem of Arithmetic** states that every integer greater than 1 is either a **prime number** or can be represented as a **unique product of primes**.

The best way to think about it is that **Prime Numbers are the Atoms of Mathematics.** Just as every molecule in the universe is built from a specific "recipe" of atoms (like $H_2O$), every number in the universe has a unique "recipe" of primes.

- **Example:** $60 = 2 \times 2 \times 3 \times 5$ (or $2^2 \cdot 3 \cdot 5$)

- No matter how we try to break 60 down, we will *always* end up with two 2s, one 3, and one 5. This is the "Unique Factorization."

###### 1. The Two Parts of the Theorem

The theorem makes two very bold claims about any integer greater than 1:

1. **Existence:** You can *always* break a number down into primes. You will never find a number that "resists" being factored into primes.

2. **Uniqueness:** There is **only one way** to do it (ignoring the order of the numbers).

**Example:** The number 12

You can start factoring 12 in different ways:

- $12 = 6 \times 2 \rightarrow (3 \times 2) \times 2$

- $12 = 4 \times 3 \rightarrow (2 \times 2) \times 3$

Notice that no matter which path you took, we ended up with **two 2s and one 3**. This is the "Unique Signature" of 12.

###### 2. The Standard Notation

$$
n = p_1^{a_1} * p_2^{a_2} ... p_k^{a_k}
$$

This is just a fancy way of saying: "A number $n$ equals a bunch of primes ($p$) raised to certain powers ($a$)."

- For **60**, it would be: $60 = 2^2 \cdot 3^1 \cdot 5^1$.

###### 3. How this connects to GCD

The FTA gives a very easy way to find the GCD of two numbers if we know their prime factors.

- **Step 1:** Write the prime factorization of both numbers.

- **Step 2:** For each prime they share, take the **lowest power**.

**Example:** Find $\gcd(60, 24)$

- $60 = 2^2 \cdot 3^1 \cdot 5^1$

- $24 = 2^3 \cdot 3^1$

- Shared primes: $2$ (lowest power is $2^2$) and $3$ (lowest power is $3^1$).

- **$\gcd = 2^2 \cdot 3 = 12$**.

**Note**: The FTA is the reason **1 is excluded from the prime numbers**.

If 1 were prime, uniqueness would break! You could write $12 = 2 \times 2 \times 3$, or $12 = 2 \times 2 \times 3 \times 1$, or $12 = 2 \times 2 \times 3 \times 1^5$.

To keep the "recipe" unique, we define primes as starting from **2**.

---

#### <u>Special Numbers</u>

###### 1. Mersenne Primes ($M_p$):

A Mersenne number is any number that is one less than a power of two. However, it is only a **Mersenne Prime** if the result is a prime number.

##### The Formula

$$
M_p = 2^p - 1
$$

**The Golden Rule**: For $M_p$ to be prime, the exponent $p$ **must** itself be a prime number. (Note: Just because $p$ is prime doesn't *guarantee* $M_p$ is prime, but it’s a required starting point).

###### 2. Fermat Numbers ($F_n$)

Pierre de Fermat (a famous 17th-century mathematician) noticed a different pattern using "double exponents."

###### The Formula

$$
F_n = 2^{2^n} + 1
$$

###### The Famous "Mistake"

Fermat looked at these first five numbers and saw they were all prime. He famously conjectured that **all** Fermat numbers are prime.

He was wrong. Years later, Euler discovered that $F_5$ ($2^{32} + 1$) is divisible by $641$. In fact, we haven't found a single prime Fermat number after $F_4$!

###### 3. Perfect Numbers

A number is "Perfect" if the sum of its **proper divisors** (all factors except the number itself) equals the number itself.

- **Example: 6**
  
  - Factors of 6: 1, 2, 3.
  
  - Sum: $1 + 2 + 3 = 6$. (Perfect!)

- **Example: 28**
  
  - Factors: 1, 2, 4, 7, 14.
  
  - Sum: $1 + 2 + 4 + 7 + 14 = 28$. (Perfect!)

**The Secret Link:** There is a beautiful connection between Mersenne Primes and Perfect Numbers. If $2^p - 1$ is a Mersenne Prime, then $2^{p-1}(2^p - 1)$ is always an even Perfect Number!

###### 4. Carmichael Numbers (The "Imposter" Primes)

These are very important for Unit V (Pseudorandomness) and Unit I (Fermat's Theorem).

Recall **Fermat's Little Theorem**: If $p$ is prime, then $a^p \equiv a \pmod p$.

**Carmichael Numbers** are composite numbers (like 561) that "trick" Fermat's test. They satisfy the formula even though they are **not** prime. In cryptography, we call these **"Absolute Pseudoprimes."** They are the reason we need more advanced tests than just Fermat’s to prove a number is prime.

###### 5. Sophie Germain Primes

A prime $p$ is a Sophie Germain prime if $2p + 1$ is also prime.

- **Example:** $2$ is a Sophie Germain prime because $2(2) + 1 = 5$ (also prime).

- **Example:** $5$ is one because $2(5) + 1 = 11$ (also prime).

**Why they matter:** They are considered "Safe Primes" in cryptography. If we use them to build your encryption keys, certain types of attacks (like the Pohlig-Hellman algorithm) become much harder to execute.

---

### ⚡ Summary for the Exam

| **Number Type**    | **Identification Key**          | **Quick Example**  |
| ------------------ | ------------------------------- | ------------------ |
| **Mersenne**       | $2^p - 1$                       | $7, 31$            |
| **Fermat**         | $2^{2^n} + 1$                   | $17, 257$          |
| **Perfect**        | Sum of factors = Number         | $6, 28$            |
| **Carmichael**     | Fake prime (passes Fermat test) | $561$              |
| **Sophie Germain** | $p$ and $2p+1$ are both prime   | $5 \rightarrow 11$ |
