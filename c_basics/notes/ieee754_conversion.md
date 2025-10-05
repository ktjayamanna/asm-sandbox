# IEEE 754 Single-Precision Conversion

## Format
```
[Sign: 1 bit][Exponent: 8 bits][Mantissa: 23 bits]
```

## Algorithm

### 1. Convert to Binary
- **Integer part:** Divide by 2 repeatedly, read remainders bottom-up
- **Fractional part:** Multiply by 2 repeatedly, take integer parts

### 2. Normalize
Express as: **1.xxxxx × 2^E**

Move binary point until one `1` remains on left.

### 3. Extract Components
- **Sign:** 0 if positive, 1 if negative
- **Exponent:** E + 127 (convert to 8-bit binary)
- **Mantissa:** Fractional part after "1." (pad right to 23 bits)

### 4. Assemble
Concatenate: `[Sign][Exponent][Mantissa]`

## Example: 12.375

**Convert:**
- 12 = 1100₂
- 0.375 = 0.011₂
- Result: 1100.011₂

**Normalize:**
```
1100.011 = 1.100011 × 2³
```

**Extract:**
- Sign: `0`
- Exponent: 3 + 127 = 130 = `10000010`
- Mantissa: `10001100000000000000000`

**Final:**
```
0 10000010 10001100000000000000000
```

## Representation Equation
```
Value = (-1)^Sign × (1 + Mantissa) × 2^(Exponent - 127)
```

Where Mantissa is interpreted as a binary fraction:
```
Mantissa = b₁×2⁻¹ + b₂×2⁻² + b₃×2⁻³ + ... + b₂₃×2⁻²³
```