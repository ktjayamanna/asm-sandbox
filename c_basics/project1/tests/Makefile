# Test Makefile for calculator project

# Compile the main program
../main.exe: ../main.c
	cd .. && gcc -o main.exe main.c

# Compile unit tests
test_basic_operations: test_basic_operations.c ../main.c
	gcc -o test_basic_operations test_basic_operations.c -lm -DUNIT_TEST

# Run unit tests
unit_tests: test_basic_operations
	./test_basic_operations

# Run integration tests
integration_tests: ../main.exe
	chmod +x test_integration.sh
	./test_integration.sh

# Run all tests
all_tests: unit_tests integration_tests
	echo "All tests completed!"

# Clean test files
clean:
	rm -f test_basic_operations
	rm -f test_output.txt

.PHONY: unit_tests integration_tests all_tests clean
