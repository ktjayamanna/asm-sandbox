#!/bin/bash

# Integration test script for calculator
echo "Running integration tests for calculator..."

cd "$(dirname "$0")/.."

# Test 1: Basic addition
echo "Test 1: Basic addition (5 + 3)"
echo -e "5\n3\na\n0" | ./main.exe > test_output.txt 2>&1
if grep -q "Result: 8.000000" test_output.txt; then
    echo "✓ Addition test passed"
else
    echo "✗ Addition test failed"
    cat test_output.txt
fi

# Test 2: Subtraction
echo "Test 2: Subtraction (10 - 4)"
echo -e "10\n4\ns\n0" | ./main.exe > test_output.txt 2>&1
if grep -q "Result: 6.000000" test_output.txt; then
    echo "✓ Subtraction test passed"
else
    echo "✗ Subtraction test failed"
    cat test_output.txt
fi

# Test 3: Multiplication
echo "Test 3: Multiplication (3 * 4)"
echo -e "3\n4\nm\n0" | ./main.exe > test_output.txt 2>&1
if grep -q "Result: 12.000000" test_output.txt; then
    echo "✓ Multiplication test passed"
else
    echo "✗ Multiplication test failed"
    cat test_output.txt
fi

# Test 4: Division
echo "Test 4: Division (15 / 3)"
echo -e "15\n3\nd\n0" | ./main.exe > test_output.txt 2>&1
if grep -q "Result: 5.000000" test_output.txt; then
    echo "✓ Division test passed"
else
    echo "✗ Division test failed"
    cat test_output.txt
fi

# Test 5: Division by zero
echo "Test 5: Division by zero (10 / 0)"
echo -e "10\n0\nd\n0" | ./main.exe > test_output.txt 2>&1
if grep -q "Error: Division by zero!" test_output.txt && grep -q "Result: 0.000000" test_output.txt; then
    echo "✓ Division by zero test passed"
else
    echo "✗ Division by zero test failed"
    cat test_output.txt
fi

# Test 6: Invalid operation choice
echo "Test 6: Invalid operation choice"
echo -e "5\n3\nx\na\n0" | ./main.exe > test_output.txt 2>&1
if grep -q "Invalid choice!" test_output.txt && grep -q "Result: 8.000000" test_output.txt; then
    echo "✓ Invalid choice handling test passed"
else
    echo "✗ Invalid choice handling test failed"
    cat test_output.txt
fi

# Test 7: Continue calculation
echo "Test 7: Multiple calculations"
echo -e "2\n3\na\n1\n10\n5\ns\n0" | ./main.exe > test_output.txt 2>&1
if grep -q "Result: 5.000000" test_output.txt && grep -q "Result: 5.000000" test_output.txt; then
    echo "✓ Multiple calculations test passed"
else
    echo "✗ Multiple calculations test failed"
    cat test_output.txt
fi

# Test 8: Decimal numbers
echo "Test 8: Decimal numbers (2.5 + 1.5)"
echo -e "2.5\n1.5\na\n0" | ./main.exe > test_output.txt 2>&1
if grep -q "Result: 4.000000" test_output.txt; then
    echo "✓ Decimal numbers test passed"
else
    echo "✗ Decimal numbers test failed"
    cat test_output.txt
fi

# Clean up
rm -f test_output.txt

echo "Integration tests completed!"
