#!/bin/bash

# Test input validation for calculator
echo "Testing input validation..."

cd "$(dirname "$0")/.."

# Test 1: Invalid number input
echo "Test 1: Invalid number input (letters instead of numbers)"
echo -e "abc\n5\n3\na\n0" | timeout 10 ./main.exe > test_output.txt 2>&1
if grep -q "Invalid input! Please try again." test_output.txt; then
    echo "✓ Invalid number input handling test passed"
else
    echo "✗ Invalid number input handling test failed"
    cat test_output.txt
fi

# Test 2: Invalid boolean input
echo "Test 2: Invalid boolean input for continue prompt"
echo -e "5\n3\na\nabc\n0" | timeout 10 ./main.exe > test_output.txt 2>&1
if grep -q "Invalid input! Please try again." test_output.txt; then
    echo "✓ Invalid boolean input handling test passed"
else
    echo "✗ Invalid boolean input handling test failed"
    cat test_output.txt
fi

# Test 3: Multiple invalid operation choices
echo "Test 3: Multiple invalid operation choices"
echo -e "5\n3\nx\ny\nz\na\n0" | timeout 10 ./main.exe > test_output.txt 2>&1
invalid_count=$(grep -c "Invalid choice!" test_output.txt)
if [ "$invalid_count" -ge 3 ]; then
    echo "✓ Multiple invalid operation choices test passed"
else
    echo "✗ Multiple invalid operation choices test failed (found $invalid_count invalid messages)"
    cat test_output.txt
fi

# Test 4: Negative numbers
echo "Test 4: Negative numbers (-5 + -3)"
echo -e "-5\n-3\na\n0" | timeout 10 ./main.exe > test_output.txt 2>&1
if grep -q "Result: -8.000000" test_output.txt; then
    echo "✓ Negative numbers test passed"
else
    echo "✗ Negative numbers test failed"
    cat test_output.txt
fi

# Test 5: Very large numbers
echo "Test 5: Large numbers (1000000 * 1000000)"
echo -e "1000000\n1000000\nm\n0" | timeout 10 ./main.exe > test_output.txt 2>&1
if grep -q "Result:" test_output.txt; then
    echo "✓ Large numbers test passed"
else
    echo "✗ Large numbers test failed"
    cat test_output.txt
fi

# Clean up
rm -f test_output.txt

echo "Input validation tests completed!"
