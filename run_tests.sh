#!/bin/bash

# Test runner script for libft
# Usage: ./run_tests.sh [options]

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
NC='\033[0m' # No Color

# Default values
RUN_VALGRIND=false
MANDATORY_ONLY=false
VERBOSE=false
CHECK_NORM=false
NORM_ONLY=false

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        -v|--valgrind)
            RUN_VALGRIND=true
            shift
            ;;
        -m|--mandatory)
            MANDATORY_ONLY=true
            shift
            ;;
        --verbose)
            VERBOSE=true
            shift
            ;;
        -n|--norm)
            CHECK_NORM=true
            shift
            ;;
        --norm-only)
            NORM_ONLY=true
            CHECK_NORM=true
            shift
            ;;
        -f|--full)
            CHECK_NORM=true
            shift
            ;;
        -h|--help)
            echo "Usage: $0 [options]"
            echo "Options:"
            echo "  -v, --valgrind    Run tests with valgrind"
            echo "  -m, --mandatory   Test only mandatory functions"
            echo "  -n, --norm        Check norminette compliance before running tests"
            echo "  --norm-only       Only check norminette compliance (don't run tests)"
            echo "  -f, --full        Run norminette check + all tests (equivalent to --norm)"
            echo "  --verbose         Enable verbose output"
            echo "  -h, --help        Show this help message"
            echo ""
            echo "Examples:"
            echo "  $0                # Run all tests"
            echo "  $0 --norm         # Check norminette + run tests"
            echo "  $0 --norm-only    # Only check norminette"
            echo "  $0 -m --norm      # Check norminette + run mandatory tests only"
            exit 0
            ;;
        *)
            echo "Unknown option: $1"
            echo "Use -h or --help for usage information"
            exit 1
            ;;
    esac
done

echo -e "${BLUE}=======================================${NC}"
echo -e "${BLUE}       LIBFT TEST SUITE RUNNER       ${NC}"
echo -e "${BLUE}=======================================${NC}"

# Check if libft.h exists in parent directory
if [ ! -f "../libft.h" ]; then
    echo -e "${RED}Error: libft.h not found in parent directory${NC}"
    echo -e "${RED}Make sure you run this script from the tester directory${NC}"
    exit 1
fi

# Function to check norminette
check_norminette() {
    echo -e "${PURPLE}=======================================${NC}"
    echo -e "${PURPLE}        NORMINETTE COMPLIANCE        ${NC}"
    echo -e "${PURPLE}=======================================${NC}"

    if command -v norminette >/dev/null 2>&1; then
        echo -e "${YELLOW}Checking norminette compliance...${NC}"
        echo ""

        # Build list of files to check (only C source files and header)
        FILES_TO_CHECK=""

        # Add header file
        if [ -f "../libft.h" ]; then
            FILES_TO_CHECK="../libft.h"
        fi

        # Add all ft_*.c files from parent directory
        for file in ../ft_*.c; do
            if [ -f "$file" ]; then
                FILES_TO_CHECK="$FILES_TO_CHECK $file"
            fi
        done

        if [ -z "$FILES_TO_CHECK" ]; then
            echo -e "${RED}No libft source files found in parent directory${NC}"
            return 1
        fi

        # Run norminette on the specific files
        NORM_OUTPUT=$(norminette $FILES_TO_CHECK 2>&1)

        # Count errors more reliably
        NORM_ERRORS=$(echo "$NORM_OUTPUT" | grep "Error" | wc -l)
        NORM_ERRORS=$(echo $NORM_ERRORS | tr -d ' ')  # Remove any whitespace

        if [ "$NORM_ERRORS" -eq 0 ]; then
            echo -e "${GREEN}✅ All files are norminette compliant!${NC}"
            echo ""
            if [ "$VERBOSE" = true ]; then
                echo "$NORM_OUTPUT"
                echo ""
            fi
            return 0
        else
            echo -e "${RED}❌ Found $NORM_ERRORS norminette error(s):${NC}"
            echo ""
            # Show errors in red
            echo "$NORM_OUTPUT" | while IFS= read -r line; do
                if [[ $line == *"Error"* ]]; then
                    echo -e "${RED}$line${NC}"
                else
                    echo "$line"
                fi
            done
            echo ""
            echo -e "${YELLOW}Please fix norminette errors before proceeding.${NC}"
            return 1
        fi
    else
        echo -e "${YELLOW}⚠️  Norminette not found.${NC}"
        echo -e "${YELLOW}Install norminette to check code style compliance:${NC}"
        echo -e "${YELLOW}    pip3 install --user norminette${NC}"
        echo ""
        return 0
    fi
}

# Check norminette if requested
if [ "$CHECK_NORM" = true ]; then
    check_norminette
    NORM_EXIT_CODE=$?

    if [ "$NORM_ONLY" = true ]; then
        exit $NORM_EXIT_CODE
    fi

    if [ $NORM_EXIT_CODE -ne 0 ]; then
        echo -e "${RED}Norminette check failed. Use --verbose to see details.${NC}"
        echo -e "${YELLOW}You can still run tests by omitting the --norm flag.${NC}"
        exit 1
    fi
    echo ""
fi

# Clean previous builds
echo -e "${YELLOW}Cleaning previous builds...${NC}"
make -f Makefile.test fclean > /dev/null 2>&1

# Build the appropriate test suite
if [ "$MANDATORY_ONLY" = true ]; then
    echo -e "${YELLOW}Building test suite for mandatory functions only...${NC}"
    if [ "$VERBOSE" = true ]; then
        make -f Makefile.test mandatory
    else
        make -f Makefile.test mandatory > /dev/null 2>&1
    fi
    TEST_EXECUTABLE="./test_libft_mandatory"
else
    echo -e "${YELLOW}Building complete test suite (mandatory + bonus)...${NC}"
    if [ "$VERBOSE" = true ]; then
        make -f Makefile.test all
    else
        make -f Makefile.test all > /dev/null 2>&1
    fi
    TEST_EXECUTABLE="./test_libft"
fi

# Check if build was successful
if [ $? -eq 0 ]; then
    echo -e "${GREEN}Build successful!${NC}"
else
    echo -e "${RED}Build failed!${NC}"
    exit 1
fi

echo ""
echo -e "${BLUE}=======================================${NC}"
echo -e "${BLUE}           RUNNING TESTS              ${NC}"
echo -e "${BLUE}=======================================${NC}"

# Run the tests
if [ "$RUN_VALGRIND" = true ]; then
    if command -v valgrind >/dev/null 2>&1; then
        echo -e "${YELLOW}Running tests with valgrind...${NC}"
        echo ""
        valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $TEST_EXECUTABLE
    else
        echo -e "${YELLOW}Valgrind not found, running tests without memory checking...${NC}"
        echo ""
        $TEST_EXECUTABLE
    fi
else
    echo -e "${YELLOW}Running tests...${NC}"
    echo ""
    $TEST_EXECUTABLE
fi

# Store the exit code
TEST_EXIT_CODE=$?

echo ""

# Final summary
if [ $TEST_EXIT_CODE -eq 0 ]; then
    echo -e "${GREEN}=======================================${NC}"
    echo -e "${GREEN}    🎉 ALL TESTS PASSED! 🎉           ${NC}"
    if [ "$CHECK_NORM" = true ]; then
        echo -e "${GREEN}    ✅ NORMINETTE COMPLIANT ✅        ${NC}"
    fi
    echo -e "${GREEN}=======================================${NC}"
else
    echo -e "${RED}=======================================${NC}"
    echo -e "${RED}    ❌ SOME TESTS FAILED ❌           ${NC}"
    echo -e "${RED}=======================================${NC}"
fi

# Clean up
echo -e "${YELLOW}Cleaning up...${NC}"
make -f Makefile.test clean > /dev/null 2>&1

exit $TEST_EXIT_CODE
