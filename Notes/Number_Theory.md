## **Congruence**

a ≡ b mod (m)

∴ a = km + b

<img src="file:///C:/Users/aksha/AppData/Roaming/marktext/images/2026-02-14-06-10-21-image.png" title="" alt="" width="96">

When a mathematician writes $a \equiv b \pmod{n}$, they are actually hiding a subtraction and division problem inside it.

The formal definition is:

$$n \mid (a - b)$$

*(This vertical bar symbol $|$ means "divides" or "is a factor of".)*

**Example: $17 \equiv 5 \pmod{6}$**

- **Translation:** $6$ divides $(17 - 5)$.

- **Check:** $17 - 5 = 12$. Since $6$ goes into $12$ perfectly, the notation is correct.

---

##### Analogy:

The easiest way to understand $a \equiv b \pmod{n}$ is to look at a standard 12-hour clock.

If it is 10:00 now, what time will it be in 5 hours? the brain doesn't say "15:00" (usually); it says "3:00."

In math terms: **$15 \equiv 3 \pmod{12}$**.

- **The Modulus ($n$):** This is the size of the circle (the 12 on the clock). It’s the point where we wrap back around to zero.

- **The Congruence ($\equiv$):** This symbol means "is equivalent to." 15 and 3 aren't the same number, but they land on the **same spot** on the 12-hour clock.

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
   
   > The GCD of two numbers doesn't change if you replace the larger number with the remainder of the larger divided by the smaller.
   
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
