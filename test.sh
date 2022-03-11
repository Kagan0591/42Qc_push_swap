#Tester le int min int et le -1 max et le +1
#Tester les cas d erreur , pas un int, pas un chiffre, pas un doublon
#!/bin/sh

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
LIGHTGRAY="\033[0;37m"
WITHE="\033[1;37"

# Compiling and program launch
clear
echo -e "${BOLD}${UNDERLINE}Script-shell for testing the program push_swap${END}"
sleep 2
clear

echo -e "${BOLD}${UNDERLINE}Script-shell for testing the program push_swap${END}"
echo -e "${SELECTED}Recompiling the program${SELECTEDLINE}"
make --silent
sleep 1
clear

echo -e "${BOLD}${UNDERLINE}Script-shell for testing the program push_swap${END}"
echo -e "${SELECTED}Executing the script ......${SELECTEDLINE}"
sleep 0.9
clear

echo -e "${BOLD}${UNDERLINE}Script-shell for testing the program push_swap${END}"
echo -e "${SELECTED}Executing the script ....${SELECTEDLINE}"
sleep 0.9
clear

echo -e "${BOLD}${UNDERLINE}Script-shell for testing the program push_swap${END}"
echo -e "${SELECTED}Executing the script ..${SELECTEDLINE}"
sleep 1.5
clear

# Tests
echo -e "${SELECTED}Script-shell for testing the program push_swap${SELECTEDLINE}"
echo ""
echo -e "${BOLD_BLUE}Trigger an error${END}"
echo ""
echo "2 args are the same: " && $(./push_swap 8 4 1 8)
echo "At least 1 arg is not a number 1: " && $(./push_swap a 4 1 8)
echo "At least 1 arg is not a number 2: " && $(./push_swap -19 4 - 8)
echo "At least 1 arg is not a integrer INT MIN - 1: " && $(./push_swap -2147483649 4 1 8)
echo "At least 1 arg is not a integrer INT MAX + 1: " && $(./push_swap 2147483648 4 1 8)
echo ""

echo -e "${BOLD_BLUE}Test with 1 argument${END}"
echo ""
echo "1 Arg INT MIN: "$(./push_swap -2147483648)
echo "1 Arg INT MAX: "$(./push_swap 2147483647)
echo "1 Arg 65353: "$(./push_swap 65353)
echo ""
echo ""

echo -e "${BOLD_BLUE}Test with 3 arguments${END}"
echo ""
echo "3 arg including INT MIN: "$(./push_swap -2147483648 10 5 | wc -l)
echo "3 arg including INT MAX: "$(./push_swap 2147483647 10 5 | wc -l)
echo "3 arg 3 2 1: "$(./push_swap 3 2 1 | wc -l)
echo "3 arg 3 1 2: "$(./push_swap 3 1 2 | wc -l)
echo "3 arg 2 1 3: "$(./push_swap 2 1 3 | wc -l)
echo "3 arg 2 3 1: "$(./push_swap 2 3 1 | wc -l)
echo "3 arg 1 3 2: "$(./push_swap 1 3 2 | wc -l)
echo "3 arg 1 2 3: "$(./push_swap 1 2 3 | wc -l)
echo ""
echo ""

echo -e "${BOLD_BLUE}Test with 5 arguments${END}"
echo ""
echo "5 arg including INT MIN: "$(./push_swap 16 2 -2147483648 10 5 | wc -l)
echo "5 arg including INT MAX: "$(./push_swap 16 2 2147483647 10 5 | wc -l)
echo -e "${ITALIC_CYAN}10 test with 5 random generated numbers${END}"
ARGS=`ruby -e "puts (10..14).to_a.shuffle.join(' ')"`; echo "5 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-14..-10).to_a.shuffle.join(' ')"`; echo "5 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..14).to_a.shuffle.join(' ')"`; echo "5 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..14).to_a.shuffle.join(' ')"`; echo "5 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-14..-10).to_a.shuffle.join(' ')"`; echo "5 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..14).to_a.shuffle.join(' ')"`; echo "5 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..14).to_a.shuffle.join(' ')"`; echo "5 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-14..-10).to_a.shuffle.join(' ')"`; echo "5 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..14).to_a.shuffle.join(' ')"`; echo "5 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..14).to_a.shuffle.join(' ')"`; echo "5 arg randomized: "$(./push_swap $ARGS | wc -l)
echo ""
echo ""

echo -e "${BOLD_BLUE}Test with 100 arguments${END}"
echo ""
echo -e "${ITALIC_CYAN}50 test with 100 random generated numbers${END}"
ARGS=`ruby -e "puts (10..108).to_a.shuffle.join(' ')"`; echo "100 arg randomized including one INT MIN: "$(./push_swap -2147483648 $ARGS | wc -l)
ARGS=`ruby -e "puts (10..108).to_a.shuffle.join(' ')"`; echo "100 arg randomized including one INT MAX: "$(./push_swap 2147483647 $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-108..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)


echo ""
echo ""

echo -e "${BOLD_BLUE}Test with 500 arguments${END}"
echo ""
echo -e "${ITALIC_CYAN}50 test with 100 random generated numbers${END}"
ARGS=`ruby -e "puts (10..508).to_a.shuffle.join(' ')"`; echo "100 arg randomized including one INT MIN: "$(./push_swap -2147483648 $ARGS | wc -l)
ARGS=`ruby -e "puts (10..508).to_a.shuffle.join(' ')"`; echo "100 arg randomized including one INT MAX: "$(./push_swap 2147483647 $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (10..509).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
ARGS=`ruby -e "puts (-508..-10).to_a.shuffle.join(' ')"`; echo "100 arg randomized: "$(./push_swap $ARGS | wc -l)
echo ""
echo ""

echo -e "${BOLD}Script by Thomas Chalifour ${BLUE}tchalifour91@gmail.com${END}"
