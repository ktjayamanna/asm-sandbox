# Converting Decimal Fractions to Binary

## The Multiply-by-2 Algorithm

### Steps

1. Multiply the fraction by 2
2. If result ≥ 1: write down **1**, subtract 1, continue with remainder
3. If result < 1: write down **0**, continue with the result
4. Repeat until you get 0 (terminates) or recognize a pattern (repeats)

### Example 1: 0.625

```
0.625 × 2 = 1.25  → 1 (take 0.25 forward)
0.25  × 2 = 0.5   → 0 (take 0.5 forward)
0.5   × 2 = 1.0   → 1 (done! reached 0)
```

**Result: 0.625₁₀ = 0.101₂**

**Verification:**
```
0.101₂ = 1×2⁻¹ + 0×2⁻² + 1×2⁻³ 
       = 0.5 + 0 + 0.125 
       = 0.625 ✓
```

### Example 2: 0.375

```
0.375 × 2 = 0.75  → 0
0.75  × 2 = 1.5   → 1 (take 0.5 forward)
0.5   × 2 = 1.0   → 1 (done!)
```

**Result: 0.375₁₀ = 0.011₂**

**Verification:**
```
0.011₂ = 0×2⁻¹ + 1×2⁻² + 1×2⁻³ 
       = 0 + 0.25 + 0.125 
       = 0.375 ✓
```

### Example 3: 0.1 (Repeating)

```
0.1 × 2 = 0.2  → 0
0.2 × 2 = 0.4  → 0
0.4 × 2 = 0.8  → 0
0.8 × 2 = 1.6  → 1 (take 0.6 forward)
0.6 × 2 = 1.2  → 1 (take 0.2 forward)
0.2 × 2 = 0.4  → 0 (we've seen 0.2 before - repeats!)
...
```

**Result: 0.1₁₀ = 0.0001100110011...₂** 

Pattern **0011** repeats infinitely.

### Example 4: 0.14159

```
0.14159 × 2 = 0.28318 → 0
0.28318 × 2 = 0.56636 → 0
0.56636 × 2 = 1.13272 → 1
0.13272 × 2 = 0.26544 → 0
0.26544 × 2 = 0.53088 → 0
0.53088 × 2 = 1.06176 → 1
0.06176 × 2 = 0.12352 → 0
0.12352 × 2 = 0.24704 → 0
0.24704 × 2 = 0.49408 → 0
0.49408 × 2 = 0.98816 → 0
0.98816 × 2 = 1.97632 → 1
0.97632 × 2 = 1.95264 → 1
...
```

**Result: 0.14159₁₀ = 0.00100100001111...₂**

## Why This Works

Each binary position after the decimal point represents a negative power of 2:

```
0.b₁b₂b₃b₄... = b₁×2⁻¹ + b₂×2⁻² + b₃×2⁻³ + b₄×2⁻⁴ + ...
                = b₁/2 + b₂/4 + b₃/8 + b₄/16 + ...
```

When you multiply by 2, you shift left by one position. If the result is ≥ 1, that bit position contains a 1.

## Algorithm Summary

```
fraction = decimal_fraction
binary_result = "0."

repeat:
    fraction = fraction × 2
    
    if fraction ≥ 1:
        binary_result += "1"
        fraction = fraction - 1
    else:
        binary_result += "0"
        
until: fraction = 0 or pattern repeats
```

## Key Points

- Not all decimal fractions can be exactly represented in binary
- Fractions like 0.1, 0.2, 0.3 have infinite repeating binary representations
- Fractions like 0.5, 0.25, 0.125 (powers of 2) terminate perfectly
- This is why floating-point arithmetic can have precision errors