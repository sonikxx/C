#!/bin/bash
COUNTER=0
SUCCESS=0
FAILED=0
DIFF=""
# Colors
red='\033[0;31m'
green='\033[0;32m'
clear='\033[0m'
# Commands
sys_command=(
    "cat"
)
s21_command=(
    "./s21_cat"
)
flagArray=("-b" "-s" "-t" "-v" "-e" "-n")
multipleFlagsArray=("-bs" "-bt" "-bv" "-be" "-st" "-sv" "-sn" "-vn" "-bst" "-bse" "-bsv" 
"-nst" "-nse" "-nsv" "-vtsn" "-vtsb" "-vtns" "-vtne" "-vtnb" "-vtes" "-vten" "-vteb" "-vtbs" "-vtbn" "-vtbe" "-vstn" "-vsnb"
"-vsbt" "-vnts" "-vnte" "-bstv" "-bste" "-bstn" "-btve" "-btvn" "-btsv" "-bvst" "-bvte" "-bven" "-bvtn" "-sbtv" "-stve"
"-stvn" "-steb" "-stet" "-stnv" "-benstv") 
fileArray=("test_files/test_1_cat.txt" "test_files/test_2_cat.txt" "test_files/test_3_cat.txt"
 "test_files/test_4_cat.txt" "test_files/test_5_cat.txt" "test_files/test_6_cat.txt" 
 "test_files/test_case_cat.txt")
 multipleFilesArray=("test_files/test_1_cat.txt test_files/test_2_cat.txt" "test_files/test_1_cat.txt test_files/test_2_cat.txt test_files/test_3_cat.txt" 
 "test_files/test_3_cat.txt test_files/test_4_cat.txt" "test_files/test_5_cat.txt test_files/test_6_cat.txt"
 "test_files/test_1_cat.txt test_files/test_case_cat.txt" "test_files/test_6_cat.txt test_files/test_case_cat.txt"
 "test_files/test_2_cat.txt test_files/test_3_cat.txt" "test_files/test_3_cat.txt test_files/test_4_cat.txt"
 "test_files/test_4_cat.txt test_files/test_5_cat.txt" "test_files/test_5_cat.txt test_files/test_6_cat.txt"
 "test_files/test_case_cat.txt test_files/test_2_cat.txt" "test_files/test_case_cat.txt test_files/test_3_cat.txt"  
 "test_files/test_case_cat.txt test_files/test_4_cat.txt" "test_files/test_case_cat.txt test_files/test_5_cat.txt"
)


for files in "${fileArray[@]}"; do
        for flags in "${flagArray[@]}"; do
            let "COUNTER++"
            "${s21_command[@]}" $flags $files > "${s21_command[@]}".log
            "${sys_command[@]}" $flags $files > "${sys_command[@]}".log
            DIFF="$(diff -s "${s21_command[@]}".log "${sys_command[@]}".log)"
            if [ "$DIFF" == "Files "${s21_command[@]}".log and "${sys_command[@]}".log are identical" ]
            then
                echo -e ${COUNTER} - ${green}SUCCESS${clear} $flags $files
                let "SUCCESS++"
                printf "\n"
            else
                echo -e ${COUNTER$} - ${red}FAILED${clear} $flags $files
                let "FAILED++"
                printf "\n"
            fi
            rm -f "${s21_command[@]}".log
	        rm -f "${sys_command[@]}".log
        done
done

for files in "${multipleFilesArray[@]}"; do
        for flags in "${multipleFlagsArray[@]}"; do
        let "COUNTER++"
            "${s21_command[@]}" $flags $files > "${s21_command[@]}".log
            "${sys_command[@]}" $flags $files > "${sys_command[@]}".log
            DIFF="$(diff -s "${s21_command[@]}".log "${sys_command[@]}".log)"
            if [ "$DIFF" == "Files "${s21_command[@]}".log and "${sys_command[@]}".log are identical" ]
            then
                echo -e ${COUNTER} - ${green}SUCCESS${clear} $flags $files
                let "SUCCESS++"
                printf "\n"
            else
                echo -e ${COUNTER} - ${red}FAILED${clear} $flags $files
                let "FAILED++"
                printf "\n"
            fi
            rm -f "${s21_command[@]}".log
	        rm -f "${sys_command[@]}".log
        done
done
echo ALL: ${COUNTER}
echo -e SUCCESSED: ${SUCCESS}
echo -e FAILED: ${FAILED}

