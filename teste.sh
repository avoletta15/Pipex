#!/bin/bash

# ANSI color escape sequences
RED='\033[1;31m'
GREEN='\033[1;32m'
WHITE='\033[1;37m'
BLUE='\033[1;34m'
CYAN='\033[1;36m'
UNDERLINE='\033[4m'
RESET='\033[0m'

infile="Makefile"

# Function to execute the program and compare output
execute_test() {
    local test_number=$1
    local command1=$2
    local command2=$3

    # Execute the program
    ./pipex $infile "$command1" "$command2" out_pipex
    < $infile $command1 | $command2 > out_bash

    # Compare the output with the expected result
    if diff -q out_pipex out_bash > /dev/null 2>&1; then
        echo -ne "${GREEN} [OK]${RESET}"
    else
        echo -ne "${RED} [KO]${RESET}"
    fi
}

# Function to run all test cases
run_tests() {
    local tests=(
        "cat|wc"
        "cat|cat"
        "/bin/cat|/bin/wc"
        "/bin/cat -e|/bin/wc -l"
        "/bin/cat|/bin/wc -l"
        "/bin/cat -e|/bin/wc"
        "/bin/cat|/bin/wc -l -c -w"
        "/bin/wc -l -c -w|/bin/cat"
        "/bin/wc -l -c -w|/bin/ls -l -a -c -d"
        "/bin/cat|/bin/ls -l -a -c -d"
        "/bin/cat|/bin/cat"
        "ls -l|grep Makefile"
        "cat|hostname"
        "cat|wc -l -c -w"
        ""
        "|"
        "cat|"
        "|cat"
        "abc|abc"
        "abc|"
        "|abc"
        "abc|ls"
        "wc -x|ls -."
        "0|0"
        "wc -x|"
        "|ls -."
        "wc 0|ls 0"
        "/bin/xxx|/bin/xxx"
        "/bin/xxx -x|/bin/xxx -x"
        "/bin/xxx -x|/bin/xxx"
        "/bin/xxx|/bin/xxx -x"
        "/bin/xxx -x -y -z|/bin/xxx -x -y -z"
        "/bin/xxx|/bin/xxx -x -y -z"
        "/bin/xxx -x -y -z|/bin/xxx"
        "/bin/190i90qs01w9jç|/bin/190i90qs01w9jç"
    )

    for ((i = 0; i < ${#tests[@]}; i++)); do
        local test_number=$((i + 1))
        local commands="${tests[$i]}"
        IFS='|' read -r command1 command2 <<< "$commands"

        echo -ne "${WHITE}Test $test_number: $command1 | $command2${RESET}"
        execute_test "$test_number" "$command1" "$command2"
        echo ""
    done
}

echo -e "\\n ${CYAN}${UNDERLINE}PIPEX TESTER${RESET}\\n"
run_tests

# Remove the output files
rm -f out_pipex out_bash