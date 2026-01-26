Numerical Analysis? -
    Numerical Analysis is the study of methods to find approximate solutions to mathematical problems using numbers and computers.

Why “approximate” solutions?
    - Computers cannot store infinite digits
    - Real numbers like π, √2, e are irrational
    - Rounding is unavoidable

#### Numerical methods trade exactness for feasibility.

Why Numerical Methods Are Needed?

    Real-world problems:
        - Engineering equations
        - Physics simulations
        - Machine learning
        - Control systems
        - Cybersecurity simulations (optimization, crypto, modeling)

In C, the name of an array itself is a pointer to its first element.

###### **Function Prototyping:**

A function prototype is a declaration of a function that tells the compiler about the function's name, return type, and parameters before the     function is actually defined (written out).



Loss of Significance:
    - also called "Catastrophic Cancellation"
    - is a phenomenon in floating-point math where the precision of your result suddenly drops, often leaving you with a number that is mostly "garbage" or "noise."
    - It typically happens in two specific scenarios: when you subtract two numbers that are very close in value, or when you add/subtract numbers of wildly different scales.
     - The "Subtraction" Trap (Catastrophic Cancellation)
     - The "Scale" Trap (Absorption)



**Machine Epsilon:**
    - The smallest difference between 1.0 and the next representable floating-point number. 
    - It represents the "rounding unit" or the maximum relative error of a computer's number system. If a change is smaller than Epsilon, the computer "ignores" it.

**Interpolation:**
    - interpolation is estimating unknown data points between known values by fitting a simple function (like a line or curve) through the given points, effectively "filling the gaps" in a dataset to         predict intermediate values, unlike extrapolation, which guesses values outside the range.
    - Curve passes exactly through all data points
    - Used when data is accurate

**Approximation:**
    - Curve does not necessarily pass through all points
    - Used when data has errors/noise

**Lagrange Interpolation:**
    - Intuition: Imagine you have a few scattered points on a graph, and you want to find a smooth curve (a polynomial) that passes exactly through every single one of them.
    - Lagrange Interpolation is the formula that allows you to "construct" that curve.
    - Core Idea:
        - To find one big polynomial that fits all n points, let's create n smaller 'helper' polynomials. Each helper will be responsible for exactly one point
    - How it works:
        - Suppose we have three points: (x_0, y_0), (x_1, y_1), and (x_2, y_2).
        - Step 1:  The "Helper" Polynomials (L_i):
            - We create a special function for each x value. These are called Lagrange Basis Polynomials.
            - A helper function L_0 has a very specific job:
                - It must equal 1 when x = x_0.
                - It must equal 0 when x is any other given point (x_1 or x_2).
        - Step 2: Building the switch:
            - Build formula that makes x_1 and x_2 zero. 
                (x - x_1)(x - x_2)
        - Step 3: Now, to make sure it equals 1 when x = x_0, we divide it by those same values but with x_0 plugged in:
            L_0(x) = (x - x_1)(x - x_2)/(x_0 - x_1)(x_0 - x_2)
        - Step 3: Putting it all together:
            - Once we have all our helpers (L_0, L_1, L_2), we multiply each one by its corresponding y value and add them up:
                P(x) = y_0L_0(x) + y_1L_1(x) + y_2L_2(x)
    

- Pros & Cons:

        Pros                                Cons
        Simple to code: No complex matrix math needed.            Computationally Expensive: It takes O(n^2) time.
        Exact: It passes exactly through every point.            Wiggle Problem (Runge's Phenomenon): With too many points, the edges of the curve start to "wiggle" wildly.
        Direct: You don't need to solve for coefficients first.        Hard to update: Adding one new point requires recalculating everything.

| **Pros**                                               | **Cons**                                                                                                    |
| ------------------------------------------------------ | ----------------------------------------------------------------------------------------------------------- |
| Simple to code: No complex matrix math needed.         | Computationally Expensive: It takes O(n^2) time.                                                            |
| Exact: It passes exactly through every point.          | Wiggle Problem (Runge's Phenomenon): With too many points, the edges of the curve start to "wiggle" wildly. |
| Direct: You don't need to solve for coefficients first | Hard to update: Adding one new point requires recalculating everything.                                     |



**Newton’s Forward Interpolation:**


    - Newton’s method:
        Uses finite differences
        Easier to compute
    - Use Case Scenario:
        Data points are equally spaced
        Interpolation point is near the beginning of table
    - Advantages & Limitations
        Advantages
            - Efficient
            - Easy to update
            - Uses difference table

        Limitations
            - Equal spacing required
            - Accuracy reduces far from x₀
    
    - It is based on the idea of "Finite Differences"—looking at how the 1y values change step-by-step.
    - The Core Concept: The Difference Table
        - First Difference (△ y_0): y_1 - y_0
        - Second Difference (△^2 y_0): △ y_1 - △ y_0
    - The Formula:
        - y_x = y_0 + p * △ y_0 + p(p-1)/2! * △^2 y_0 + p(p-1)(p-2)/3! * △^3 y_0 + ....
    - What is p?
        - In Newton's method, we don't use x directly. We use a "normalized" distance called p (sometimes called u). It tells us how far we are from the start point (x_0)                 in terms of "steps": p = x - x_0/h
        - Where h is the fixed interval between points, like 1 or 10
    - constant difference [ the secret decoder]:
        - The computer doesn't know what your curve looks like. It just sees the numbers 1, 3, 6, 10.
    
        - By doing these subtractions, the computer discovers:
            - The Shape: "It took 2 steps to find a constant, so I need an x^2 formula."
            - The Growth: "The constant is 1, so I know exactly how much to bend the curve."
    - The "Secret" Summary:
        - If the 1st subtraction is constant -> The data is a Straight Line.
        - If the 2nd subtraction is constant -> The data is a Simple Curve (Parabola).
        - If the 3rd subtraction is constant -> The data is a Complex Curve (S-shape).
    -  Why p(p-1), p(p-1)(p-2), etc.?
        - they make sure the formula hits the data points exactly.
        - Think of them as "Safety Switches":At the 1st point (p=0):The term p becomes 0. This "shuts off" the Speed and the Bend, leaving you with only the Height.
        - At the 2nd point (p=1):The term (p-1) becomes (1-1) = 0. This "shuts off" the Bend, leaving you with just Height + Speed.
        - At the 3rd point (p=2):The term (p-2) would become 0, shutting off the next layer of complexity. 

Newton’s backward Interpolation:
    - If Newton Forward Interpolation is about starting at the beginning and looking ahead, Newton Backward Interpolation is about starting at the very end of your data and looking         back.
    - We use this when we want to estimate a value near the end of a table
    - Ex: if you have data for 2020, 2021, 2022, 2023, and 2024, and you want to predict something for late 2024



- Key difference:
          Feature,    Forward Difference,        Backward Difference
          Starting Point    Uses x0​ (First point),        Uses xn​ (Last point)
          Direction,    Looks forward (Δ),        Looks backward (∇)
          The "P" Formula    p=(x−x0​)/h,            p=(x−xn​)/h
          The "P" Product    p(p−1)(p−2)…,            p(p+1)(p+2)…

- The Backward Difference Table:
          - The table is built exactly the same way (by subtracting), but we focus on the bottom diagonal instead of the top.
          - The symbol for backward difference is ▽ (Nabla)
              -    ▽y_n = y_n - y_n-1 
              -    ▽^2y_n = ▽y_n - ▽y_n-1
      - The Formula:
          Because we are moving "backward" into the past relative to the last point, the signs in the formula change to plus:
          y = y_n + p▽y_n + p(p+1)/2! ▽^2y_n + p(p+1)(p+2)/3! ▽^3y_n + ...

    - Visual Intuition: 
        - The "End-Point Anchor"Imagine you are at the finish line of a race and you want to guess where a runner was 2 seconds ago.
        - Start: You start at the Finish Line height (y_n).
        - Speed: you use the runner's final speed (▽y_n) to project backward.
        - Bend: You use the final acceleration (▽^2y_n) to curve the path.

**Newton's Divided Difference:**
    - Forward and Backward methods require the x values to be perfectly spaced (like 1, 2, 3)
    - Divided Difference works for any x values (like 1, 5, 12, 100)
    - The Core Idea: "Slope of Slopes":
        - In the Forward method, we just subtracted y values
        - In Divided Difference, we calculate the actual slope (the rate of change) between points.
        - The notation looks like this: f[x_0, x_1]. This is just math-speak for:
                y_1 - y_0
                -----------
                x_1 - x_0

        - It’s essentially:     Change in Height
                    ------------------
                    Change in Distance
    
    - The Divided Difference Table:
        - How to calculate the layers:
        - 1st Difference: y_1 - y_0 / x_1 - x_0
        - 2nd Difference: (Result_2 - Result_1) / (x_2 - x_0) (we divide by the distance between x_2 and x_0)4
        - 3rd Difference: (Result_B - Result_A) / (x_3 - x_0)
    
    - The Formula:
        - Instead of a "step counter," we use the actual x distances:
        - P(x) = a_0 + a_1(x - x_0) + a_2(x - x_0)(x - x_1) + a_3(x - x_0)(x - x_1)(x - x_2) ....
        - a_0 = y_0 (The Height)
        - a_1 = f[x_0, x_1] (The Speed)
        - a_2 = f[x_0, x_1, x_2] (The Bend)

Errors in Interpolation & Numerical Errors:

    - Why Error Analysis Is Needed? 
        - Numerical methods give approximate answers, not exact ones.
    - So we must answer:
        - How close is the answer?
        - How much error is acceptable?
        - Will error grow with computation?
    - This is the core idea of numerical analysis
    
    - Types of Errors:
        - Absolute Error
            Absolute Error = ∣ True value − Approximate value ∣
            - Example: 
                True = 3.14159
                Approx = 3.14
                Absolute error = 0.00159
        - Relative Error
            Relative Error = Absolute Error
                    ---------------
                    True value
        - Percentage Error
            Percentage Error = Relative Error × 100
    
    - Errors in Interpolation:
        - Interpolation is the process of estimating a value between known data points. Even if your math is perfect, the "shape" of the formula you choose usually won't perfectly             match the real-world function.
    ​    - Why Interpolation Errors Happen?
            - Data Uncertainty: If your starting data points (x_i, y_i) are slightly wrong (due to measurement error), the resulting curve will be off.
            - Oscillations (Runge's Phenomenon): Using a very high-degree polynomial to fit many points often causes the curve to wiggle wildly near the edges, leading to                     massive errors.
            - Distance from Nodes: The error is usually zero at the data points themselves, but it grows as you move further away from them.
    
    - Numerical Errors:
        - Numerical errors generally fall into two categories: how computers store numbers and how we simplify math
        - Round-off Errors:
            - These occur because computers have finite memory. They cannot store an infinite string of digits (like pi or 1/3).
            - Cause: A computer typically uses 32 or 64 bits to represent a number. Any digits beyond that are either chopped (ignored) or rounded.
            - Example:     If a system only stores 4 decimal places, 1/3 approx 0.3333.
                    The "lost" 0.0000333... is the round-off error
        - Truncation Errors:
            - These are "mathematical" errors. 
            - They occur when we replace an infinite process with a finite one to make it solvable.
            - Cause: Most commonly found when using a Taylor Series expansion but stopping after a few terms.
            - Example:     The exact value of e^x is an infinite sum. 
                    If we only use the first three terms (1 + x + x^2/2), we "truncate" the rest. 
                    That missing part is the truncation error.
    
    - Error Propagation:
        - Small errors grow during calculations.
        - Example:     𝑧=𝑥−𝑦
        -  If x ≈ y, then:
            - Large relative error
            - Loss of significance

Why Polynomial Interpolation Fails?

    - The Problem with High-Degree Polynomials
        - When:
            - Number of data points increases
            - Degree of polynomial increases
            - Polynomial interpolation becomes unstable
            - This is called the Runge Phenomenon.
    
    - Imagine we have a set of data points (dots on a graph), and you want to draw a single, smooth curve that passes exactly through every single one of them. 
    - A common way to do this is by using a polynomial, which looks like this: P(x) = a_n x^n + a_{n-1} x^{n-1} + ... + a_1 x + a_0
    
    - The "failure" happens when we try to be too precise by adding too many points.  Here is the breakdown of why this goes wrong.
    
        - The "Wiggle" Problem (Runge's Phenomenon):
            -  In theory, adding more points should make the curve more accurate. However, in polynomial interpolation, the opposite often happens.
            -  As you increase the number of points, you increase the degree (the highest power of x) of the polynomial.
            -  High-degree polynomials are incredibly "springy" or "nervous."
            - To hit every single point exactly, the curve starts to oscillate—or wiggle—violently, especially near the beginning and the end of the data set.
    
        - The Problem with "Equally Spaced" Points:
            - Most of us naturally want to put our data points at equal intervals (e.g., at x = 1, 2, 3, 4). Surprisingly, this is actually the worst way to do polynomial                     interpolation.
            - When points are equally spaced, the "errors" or wiggles at the edges of the interval grow exponentially as you add more points. Instead of the curve getting                     closer to the "true" shape, it flies off the top or bottom of the graph.
    
        - How do we fix it?
            - Because "simple" polynomial interpolation often fails for large data sets, mathematicians use two main workarounds:
                - Splines (The "Connect-the-Dots" Method): Instead of using one giant, complex equation for the whole graph, we use many small, simple equations (usually                     cubics) and "glue" them together at the points. This is how almost all modern computer graphics and fonts are drawn.
                - Chebyshev Nodes: If you must use one single polynomial, you can avoid the wiggles by clustering your data points more densely at the edges and further                     apart in the middle.
    
    - 


