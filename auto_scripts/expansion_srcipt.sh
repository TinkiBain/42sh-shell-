#! /bin/bash

TEST='|U hate this|'
echo -e "\033[0;32m*** Simple tests ***\033[0m"
echo -e "\033[1;34m~~~~~~~~~~~~1~~~~~~~~~~~~\033[0m"
echo ${TEST}
echo -e "\033[0;31m|U hate this|\033[0m"
echo -e "\033[1;34m~~~~~~~~~~~~2~~~~~~~~~~~~\033[0m"
echo ${TEST}$TEST
echo -e "\033[0;31m|U hate this||U hate this|\033[0m"
echo -e "\033[1;34m~~~~~~~~~~~~3~~~~~~~~~~~~\033[0m"
echo ${TES}$TEST
echo -e "\033[0;31m|U hate this|\033[0m"
echo -e "\033[1;34m~~~~~~~~~~~~4~~~~~~~~~~~~\033[0m"
echo $TEST${TEST}
echo -e "\033[0;31m|U hate this||U hate this|\033[0m"
echo -e "\033[1;34m~~~~~~~~~~~~5~~~~~~~~~~~~\033[0m"
echo ${TEST}AAAA
echo -e "\033[0;31m|U hate this|AAAA\033[0m"
echo -e "\033[1;34m~~~~~~~~~~~~6~~~~~~~~~~~~\033[0m"
echo AAAA${TEST}AAAA
echo -e "\033[0;31mAAAA|U hate this|AAAA\033[0m"
echo -e "\033[1;34m~~~~~~~~~~~~7~~~~~~~~~~~~\033[0m"
echo AAAA${TST}AAAA
echo -e "\033[0;31mAAAAAAAA\033[0m"
echo -e "\033[1;34m~~~~~~~~~~~~8~~~~~~~~~~~~\033[0m"
echo AAAA${TEST}AAAA$TEST
echo -e "\033[0;31mAAAA|U hate this|AAAA|U hate this|\033[0m"
echo -e "\033[1;34m~~~~~~~~~~~~9~~~~~~~~~~~~\033[0m"
echo $TESTasdf
echo -e "\033[0;31m\033[0m"
echo -e "\033[1;34m~~~~~~~~~~~~10~~~~~~~~~~~\033[0m"
echo AAA$TEST
echo -e "\033[0;31mAAA|U hate this|\033[0m"
echo -e "\033[1;34m~~~~~~~~~~~~11~~~~~~~~~~~\033[0m"
echo AAA$TET
echo -e "\033[0;31mAAA\033[0m"
echo -e "\033[1;34m~~~~~~~~~~~~12~~~~~~~~~~~\033[0m"
echo $$
echo -e "\033[1;34m~~~~~~~~~~~~13~~~~~~~~~~~\033[0m"
echo $$$TEST
echo -e "\033[1;34m~~~~~~~~~~~~13~~~~~~~~~~~\033[0m"
echo $$$$TEST
echo -e "\033[1;34m~~~~~~~~~~~~13~~~~~~~~~~~\033[0m"

echo -e "\033[0;32m*** Middle tests ***\033[0m"

TEST2='|JTERRY|'
TEST1='|GGWIN-GO|'
echo -e "\033[1;34m~~~~~~~~~~~~1~~~~~~~~~~~~\033[0m"
echo ${TEST2:-$TEST1}
echo -e "\033[0;31m|JTERRY|\033[0m"
echo -e "\033[1;34m~~~~~~~~~~~~2~~~~~~~~~~~~\033[0m"
echo ${TES2:-$TEST1}
echo -e "\033[0;31m|GGWIN-GO|\033[0m"
echo -e "\033[1;34m~~~~~~~~~~~~3~~~~~~~~~~~~\033[0m"
echo ${TES2:-$TES1}
echo -e "\033[0;31m\033[0m"
echo -e "\033[1;34m~~~~~~~~~~~~4~~~~~~~~~~~~\033[0m"
echo ${TEST2:+$TEST1}
echo -e "\033[0;31m|GGWIN-GO|\033[0m"
echo -e "\033[1;34m~~~~~~~~~~~~5~~~~~~~~~~~~\033[0m"
echo ${TET2:+$TEST1}
echo -e "\033[0;31m\033[0m"
echo -e "\033[1;34m~~~~~~~~~~~~6~~~~~~~~~~~~\033[0m"
echo ${TEST2:=$TEST1}
echo -e "\033[0;31m|JTERRY|\033[0m"
echo -e "\033[1;34m~~~~~~~~~~~~6~~~~~~~~~~~~\033[0m"
echo ${TET2:=$TEST1}
echo -e "\033[0;31m|GGWIN-GO|\033[0m"
echo -e "\033[1;34m~~~~~~~~~~~~7~~~~~~~~~~~~\033[0m"
echo ${TET2}
echo -e "\033[0;31m|GGWIN-GO|\033[0m"
echo -e "\033[1;34m~~~~~~~~~~~~8~~~~~~~~~~~~\033[0m"
echo ${PWD:PWD} 
echo -e "\033[0;31m42sh: unrecognized modifier \`P\'\033[0m"