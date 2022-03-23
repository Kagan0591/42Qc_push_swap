#!/bin/bash

# Color code
END="\033[0;0m"
BOLD="\033[0;1m"
BOLD_BLUE="\033[34;1m"
ITALIC="\033[0;3m"
ITALIC_CYAN="\033[36;3m"
UNDERLINE="\033[0;4m"
BLINK="\033[0;5m"
BLINK2="\033[0;6m"
SELECTED="\033[44;30m"
SELECTEDLINE="\033[K\033[0m"
BLACK="\033[0;30m"
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
BLUE="\033[1;34m"
VIOLET="\033[0;35m"
CYAN="\033[0;36m"
LIGHTGRAY="\033[1;38m"
WITHE="\033[1;37"

# Compiling and program launch
clear
echo "${BOLD}${UNDERLINE}Script-shell for testing the program push_swap${END}"
sleep 2
clear

echo "${BOLD}${UNDERLINE}Script-shell for testing the program push_swap${END}"
echo "${SELECTED}Compiling the program${SELECTEDLINE}"
make --silent
sleep 1
clear

echo "${BOLD}${UNDERLINE}Script-shell for testing the program push_swap${END}"
echo "${SELECTED}Checking for leaks Test 1 of 5${SELECTEDLINE}"
sleep 0.8
SILENTCMD='/dev/null'
valgrind --leak-check=full ./push_swap > $SILENTCMD
echo "${GREEN}Press a enter to continue${END}"
# read to a dummy variable. Read fonction with sh have not the option
# like -t -r or -n so it is a very limited option but it's work.
read dummy_variable

echo "${SELECTED}Checking for leaks Test 2 of 5${SELECTEDLINE}"
sleep 0.8
valgrind --leak-check=full ./push_swap 3 1 2 > $SILENTCMD
echo "${GREEN}Press a enter to continue${END}"
read dummy_variable

echo "${SELECTED}Checking for leaks Test 3 of 5${SELECTEDLINE}"
sleep 0.8
valgrind --leak-check=full ./push_swap 3 2 1 5 4 > $SILENTCMD
echo "${GREEN}Press a enter to continue${END}"
read dummy_variable

echo "${SELECTED}Checking for leaks Test 4 of 5${SELECTEDLINE}"
sleep 0.8
ARGS=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; valgrind --leak-check=full ./push_swap $ARGS > $SILENTCMD
echo "${GREEN}Press a enter to continue${END}"
read dummy_variable

echo "${SELECTED}Checking for leaks Test 5 of 5${SELECTEDLINE}"
sleep 0.8
ARGS=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; valgrind --leak-check=full ./push_swap 3 $ARGS > $SILENTCMD
echo "${GREEN}Press a enter to continue${END}"
read dummy_variable
clear

echo "${SELECTED}Executing the test ......${SELECTEDLINE}"
sleep 0.9
clear

echo "${SELECTED}Executing the test ....${SELECTEDLINE}"
sleep 0.9
clear

echo "${SELECTED}Executing the test ..${SELECTEDLINE}"
sleep 1.5
clear

# Tests
echo "${SELECTED}Script-shell for testing the program push_swap${SELECTEDLINE}"
echo ""

echo "${BOLD_BLUE}Sorting checker tests${END}"
echo "${VIOLET}Enter your OS, if is Linux type linux, if is Darwin, type Mac${END}"
read OS
clear

echo "${SELECTED}Script-shell for testing the program push_swap${SELECTEDLINE}"
echo ""
echo ""
echo "${GREEN}--------------------=--===---=====-----==========###+${BOLD_BLUE}Attempt to trigger an error${GREEN}+###==========-----=====---===--=--------------------- ${END}"
sleep 2
echo ""
echo "${ITALIC_CYAN}Test with 1 numbers${END}"
sleep 0.8
echo ""
echo ""
echo "${ITALIC_CYAN}Test with 3 numbers${END}"
sleep 0.8
echo "Attempt to trigger a repeating numbers error (test 1 with 3 nbrs): " && ./push_swap 8 4 8
echo "Attempt to trigger a repeating numbers error (test 2 with 3 nbrs): " && ./push_swap 4 1 1
echo "Attempt to trigger a repeating numbers error (test 3 with 3 nbrs (${GREEN}Not supposed to be an error${END})): " && ./push_swap 4 11 1
echo "Attempt to trigger a repeating numbers error (test 4 with 3 nbrs including a string of numbers): " && ./push_swap "4 2" 2
echo "Attempt to trigger a repeating numbers error (test 5 with 3 nbrs including a string of numbers): " && ./push_swap "4 -2" -2
echo "Attempt to trigger a not a number error (test 1 with 3 nbrs): " && ./push_swap a 4 1
echo "Attempt to trigger a not a number error (test 2 with 3 nbrs): " && ./push_swap -19 - 8
echo "Attempt to trigger a not an int error (test 1 with 3 nbrs including INT_MIN - 1): " && ./push_swap -2147483649 4 1
echo "Attempt to trigger a not an int error (test 2 with 3 nbrs including INT_MIN - 1): " && ./push_swap 4 -2147483649 1
echo "Attempt to trigger a not an int error (test 3 with 3 nbrs including INT_MAX + 1): " && ./push_swap 2147483648 4 1
echo "Attempt to trigger a not an int error (test 4 with 3 nbrs including INT_MAX + 1): " && ./push_swap 4 2147483648 1
echo "Attempt to trigger a not an int error (test 5 with 3 nbrs including INT_MAX + 10): " && ./push_swap 4 2147483657 1
echo "Attempt to trigger a not an int error (test 6 with 3 nbrs including INT_MIN - 10): " && ./push_swap -2147483658 4 1
echo ""
echo ""
echo "${ITALIC_CYAN}Test with 5 numbers${END}"
sleep 0.8
echo "Attempt to trigger a repeating numbers error (test 1 with 5 nbrs): " && ./push_swap 8 4 1 8 2
echo "Attempt to trigger a repeating numbers error (test 2 with 5 nbrs): " && ./push_swap 8 8 4 1 8
echo "Attempt to trigger a repeating numbers error (test 3 with 5 nbrs (${GREEN}Not supposed to be an error${END})): " && ./push_swap 4 11 1 3 2
echo "Attempt to trigger a repeating numbers error (test 4 with 5 nbrs including a string of numbers): " && ./push_swap "4 11 1" 1 2
echo "Attempt to trigger a repeating numbers error (test 5 with 5 nbrs including a string of numbers): " && ./push_swap "4 11 -1" -1 2
echo "Attempt to trigger a not a number error (test 1 with 5 nbrs): " && ./push_swap a 4 1 8 z
echo "Attempt to trigger a not a number error (test 2 with 5 nbrs): " && ./push_swap -19 4 - 8 z
echo "Attempt to trigger a not an int error (test 1 with 5 nbrs including INT_MIN - 1): " && ./push_swap -2147483649 4 1 8 0
echo "Attempt to trigger a not an int error (test 2 with 5 nbrs including INT_MIN - 1): " && ./push_swap 4 -2147483649 1 8 0
echo "Attempt to trigger a not an int error (test 3 with 5 nbrs including INT_MAX + 1): " && ./push_swap 2147483648 4 1 8 0
echo "Attempt to trigger a not an int error (test 4 with 5 nbrs including INT_MAX + 1): " && ./push_swap 4 2147483648 1 8 0
echo "Attempt to trigger a not an int error (test 5 with 5 nbrs including INT_MAX + 10): " && ./push_swap 4 2147483657 1 8 0
echo "Attempt to trigger a not an int error (test 6 with 5 nbrs including INT_MIN - 10): " && ./push_swap -2147483658 4 1 8 0
echo ""
echo ""
echo "${ITALIC_CYAN}Test with 100 & 500 numbers${END}"
sleep 0.8
ARGS=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a repeating numbers error (test 1 with 100 nbrs): " && ./push_swap 50 $ARGS
ARGS=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a repeating numbers error (test 2 with 100 nbrs): " && ./push_swap 50 $ARGS 40
ARGS=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a repeating numbers error (test 3 with 100 nbrs): " && ./push_swap 50 50 $ARGS
ARGS=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a repeating numbers error (test 1 with 500 nbrs): " && ./push_swap 250 $ARGS
ARGS=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a repeating numbers error (test 2 with 500 nbrs): " && ./push_swap 250 $ARGS 140
ARGS=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a repeating numbers error (test 3 with 500 nbrs): " && ./push_swap 250 250 $ARGS
ARGS=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not a number error (test 1 with 100 nbrs): " && ./push_swap - $ARGS
ARGS=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not a number error (test 2 with 100 nbrs): " && ./push_swap $ARGS a
ARGS_1=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`; ARGS_2=`ruby -e "puts (52..100).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not a number error (test 3 with 100 nbrs): " && ./push_swap $ARGS_1 a $ARGS_2
ARGS=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not a number error (test 1 with 500 nbrs): " && ./push_swap - $ARGS
ARGS=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not a number error (test 2 with 500 nbrs): " && ./push_swap $ARGS z
ARGS_1=`ruby -e "puts (1..250).to_a.shuffle.join(' ')"`; ARGS_2=`ruby -e "puts (252..500).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not a number error (test 3 with 500 nbrs): " && ./push_swap $ARGS_1 - $ARGS_2
ARGS=`ruby -e "puts (1..99).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not an int error (test 1 with 100 nbrs including INT_MIN - 1): " && ./push_swap -2147483649 $ARGS
ARGS=`ruby -e "puts (1..99).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not an int error (test 2 with 100 nbrs including INT_MAX + 1): " && ./push_swap 2147483648 $ARGS
ARGS=`ruby -e "puts (1..99).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not an int error (test 3 with 100 nbrs including INT_MIN - 10): " && ./push_swap -2147483658 $ARGS
ARGS=`ruby -e "puts (1..99).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not an int error (test 4 with 100 nbrs including INT_MAX + 10): " && ./push_swap 2147483657 $ARGS
ARGS_1=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`; ARGS_2=`ruby -e "puts (52..100).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not an int error (test 5 with 100 nbrs including INT_MIN - 1): " && ./push_swap $ARGS_1 -2147483649 $ARGS_2
ARGS_1=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`; ARGS_2=`ruby -e "puts (52..100).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not an int error (test 6 with 100 nbrs including INT_MAX + 1): " && ./push_swap $ARGS_1 2147483648 $ARGS_2
ARGS_1=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`; ARGS_2=`ruby -e "puts (52..100).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not an int error (test 7 with 100 nbrs including INT_MIN - 10): " && ./push_swap $ARGS_1 -2147483658 $ARGS_2
ARGS_1=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`; ARGS_2=`ruby -e "puts (52..100).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not an int error (test 8 with 100 nbrs including INT_MAX + 10): " && ./push_swap $ARGS_1 2147483657 $ARGS_2
ARGS=`ruby -e "puts (1..499).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not an int error (test 1 with 500 nbrs including INT_MIN - 1): " && ./push_swap -2147483649 $ARGS
ARGS=`ruby -e "puts (1..499).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not an int error (test 2 with 500 nbrs including INT_MAX + 1): " && ./push_swap 2147483648 $ARGS
ARGS=`ruby -e "puts (1..499).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not an int error (test 3 with 500 nbrs including INT_MIN - 10): " && ./push_swap -2147483658 $ARGS
ARGS=`ruby -e "puts (1..499).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not an int error (test 4 with 500 nbrs including INT_MAX + 10): " && ./push_swap 2147483657 $ARGS
ARGS_1=`ruby -e "puts (1..250).to_a.shuffle.join(' ')"`; ARGS_2=`ruby -e "puts (252..500).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not an int error (test 5 with 500 nbrs including INT_MIN - 1): " && ./push_swap $ARGS_1 -2147483649 $ARGS_2
ARGS_1=`ruby -e "puts (1..250).to_a.shuffle.join(' ')"`; ARGS_2=`ruby -e "puts (52..500).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not an int error (test 6 with 500 nbrs including INT_MAX + 1): " && ./push_swap $ARGS_1 2147483648 $ARGS_2
ARGS_1=`ruby -e "puts (1..250).to_a.shuffle.join(' ')"`; ARGS_2=`ruby -e "puts (52..500).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not an int error (test 7 with 500 nbrs including INT_MIN - 10): " && ./push_swap $ARGS_1 -2147483658 $ARGS_2
ARGS_1=`ruby -e "puts (1..250).to_a.shuffle.join(' ')"`; ARGS_2=`ruby -e "puts (52..500).to_a.shuffle.join(' ')"`; echo "Attempt to trigger a not an int error (test 8 with 500 nbrs including INT_MAX + 10): " && ./push_swap $ARGS_1 2147483657 $ARGS_2
echo ""
echo ""
echo "${ITALIC_CYAN}À partir d'ici, les erreurs ne devrait plus être visible, puisque la sortie d'erreur standard est redirigé vers un fichier${END}"
sleep 0.8
echo "Attempt to trigger a repeating numbers error (test 1 with 3 nbrs): " && ./push_swap 8 4 8 2> '/dev/null'
echo "Attempt to trigger a repeating numbers error (test 2 with 3 nbrs): " && ./push_swap 4 1 1 2> '/dev/null'
echo "Attempt to trigger a repeating numbers error (test 1 with 5 nbrs): " && ./push_swap 8 4 1 8 2 2> '/dev/null'
echo "Attempt to trigger a repeating numbers error (test 2 with 5 nbrs): " && ./push_swap 8 8 4 1 8 2> '/dev/null'
echo ""
echo ""
echo ""
echo "${GREEN}----------------------------=--===---=====-----==========###+${BOLD_BLUE}Sorting tests${GREEN}+###==========-----=====---===--=----------------------------- ${END}"
sleep 2
echo ""
echo "${BOLD_BLUE}Test with 1 argument${END}"
sleep 0.8
echo ""
echo "1 Arg INT MIN: "$(./push_swap -2147483648) $(./push_swap -2147483648 | ./checker_$OS -2147483648)
echo "1 Arg INT MAX: "$(./push_swap 2147483647) $(./push_swap -2147483648 | ./checker_$OS -2147483648)
echo "1 Arg 65353: "$(./push_swap 65353) $(./push_swap 65353 | ./checker_$OS 65353)
echo ""
echo ""
echo "${BOLD_BLUE}Test with 3 arguments${END}"
sleep 0.8
echo ""
echo "3 arg including INT MIN: "$(./push_swap -2147483648 10 5 | wc -l) $(./push_swap -2147483648 10 5 | ./checker_$OS -2147483648 10 5)
echo "3 arg including INT MAX: "$(./push_swap 2147483647 10 5 | wc -l) $(./push_swap 2147483647 10 5 | ./checker_$OS 2147483647 10 5)
echo "3 arg 3 2 1: "$(./push_swap 3 2 1 | wc -l) $(./push_swap 3 2 1 | ./checker_$OS 3 2 1)
echo "3 arg 3 1 2: "$(./push_swap 3 1 2 | wc -l) $(./push_swap 3 1 2 | ./checker_$OS 3 1 2)
echo "3 arg 2 1 3: "$(./push_swap 2 1 3 | wc -l) $(./push_swap 2 1 3 | ./checker_$OS 2 1 3)
echo "3 arg 2 3 1: "$(./push_swap 2 3 1 | wc -l) $(./push_swap 2 3 1 | ./checker_$OS 2 3 1)
echo "3 arg 1 3 2: "$(./push_swap 1 3 2 | wc -l) $(./push_swap 1 3 2 | ./checker_$OS 1 3 2)
echo "3 arg 1 2 3: "$(./push_swap 1 2 3 | wc -l) $(./push_swap 1 2 3 | ./checker_$OS 1 2 3)
echo ""
echo ""
echo "${BOLD_BLUE}Test with 5 arguments${END}"
sleep 0.8
echo ""
echo "5 arg including INT MIN: "$(./push_swap 16 2 -2147483648 10 5 | wc -l) $(./push_swap 16 2 -2147483648 10 5 | ./checker_$OS 16 2 -2147483648 10 5)
echo "5 arg including INT MAX: "$(./push_swap 16 2 2147483647 10 5 | wc -l) $(./push_swap 16 2 2147483647 10 5 | ./checker_$OS 16 2 2147483647 10 5)
echo "${ITALIC_CYAN}10 test with 5 random generated numbers${END}"
ARGS=`ruby -e "puts (10..14).to_a.shuffle.join(' ')"`; echo "5 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-14..-10).to_a.shuffle.join(' ')"`; echo "5 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..14).to_a.shuffle.join(' ')"`; echo "5 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..14).to_a.shuffle.join(' ')"`; echo "5 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-14..-10).to_a.shuffle.join(' ')"`; echo "5 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..14).to_a.shuffle.join(' ')"`; echo "5 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..14).to_a.shuffle.join(' ')"`; echo "5 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-14..-10).to_a.shuffle.join(' ')"`; echo "5 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..14).to_a.shuffle.join(' ')"`; echo "5 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..14).to_a.shuffle.join(' ')"`; echo "5 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
echo ""
echo ""
echo "${BOLD_BLUE}Test with 100 arguments${END}"
sleep 0.8
echo ""
echo "${ITALIC_CYAN}50 test with 100 random generated numbers${END}"
ARGS=`ruby -e "puts (10..108).to_a.shuffle.join(' ')"`; echo "100 arg randomized including one INT MIN: "$(./push_swap -2147483648 $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..108).to_a.shuffle.join(' ')"`; echo "100 arg randomized including one INT MAX: "$(./push_swap 2147483647 $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
echo ""
echo ""
echo "${BOLD_BLUE}Test with 500 arguments${END}"
sleep 0.8
echo ""
echo "${ITALIC_CYAN}50 test with 500 random generated numbers${END}"
ARGS=`ruby -e "puts (10..508).to_a.shuffle.join(' ')"`; echo "500 arg randomized including one INT MIN: "$(./push_swap -2147483648 $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..508).to_a.shuffle.join(' ')"`; echo "500 arg randomized including one INT MAX: "$(./push_swap 2147483647 $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "500 arg randomized: "$(./push_swap $ARGS | wc -l) $(./push_swap $ARGS | ./checker_$OS $ARGS)
echo ""
echo ""
echo "${BOLD}Script by Thomas Chalifour ${BLUE}tchalifour91@gmail.com${END}"
echo ""
echo "Somewere between the last lines of code, Press a enter to quit"
read dummy_variable
clear
