#Tester le int min int et le -1 max et le +1
#Tester les cas d erreur , pas un int, pas un chiffre, pas un doublon
#!/bin/sh

echo "Script-shell for testing the program push_swap\n\n"
echo "Recompiling the program\n\n"
make re
echo "\nTeste with one argument: (INT MIN)"
#./push_swap -2147483648
if (diff -2147483648 <(./push_swap -2147483648))
echo "\nTeste with one argument: (INT MAX)"
./push_swap 2147483647
echo "\nTeste with one argument: (INT MIN - 1)"
./push_swap -2147483649
echo "\nTeste with one argument: (INT MAX + 1)"
./push_swap 2147483648
