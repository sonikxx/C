#!/bin/bash
COUNTER=0;
SUCCESS=0
FAILED=0
DIFF=""
# Colors_________
red='\033[0;31m'
green='\033[0;32m'
yellow='\033[0;33m'
cyanide='\033[0;34m'
purple='\033[0;35m'
clear='\033[0m'
# Commands_______
sys_command=(
    "grep"
)
s21_command=(
    "./s21_grep"
)

patternForTestingEflag=("-e int -e for" "-e ^int -e while" "-ve ^int -ve for" "-oe ^int" "-oe int -oe main" "-ie clean")

flagArray=(
     "-c" "-l" "-n" "-h" "-i" "-s" "-o" "-v"
    )
pairFlagArray=(
    "-no" "-vc" "-vl" "-vn" "-vi" "-vi" "-vs" "-vo"
    "-vcl" "-vcn" "-vch" "-vci" "-vco" "-vln" "-vlh"
    "-vnh" "-vni" "-vns" "-vno" "-vhi" "-vhs" "-vho"
    "-vcln" "-vclh" "-vcli" "-vcls" "-vclo" "-vcnh"
    "-vclnhiso"
    ) 
fileArray=(
    "test_files/test_0_grep.txt" "test_files/test_1_grep.txt" "test_files/test_2_grep.txt" 
    "test_files/test_3_grep.txt" "test_files/test_4_grep.txt" "test_files/test_5_grep.txt"
    "test_files/test_6_grep.txt" "test_files/test_7_grep.txt" "test_files/test_ptrn_grep.txt"
    )
multipleFilesArray=(
    "test_files/test_0_grep.txt test_files/test_1_grep.txt test_files/test_2_grep.txt"
    "test_files/test_1_grep.txt test_files/test_2_grep.txt test_files/test_3_grep.txt"
    "test_files/test_3_grep.txt test_files/test_4_grep.txt test_files/test_5_grep.txt"
    "test_files/test_5_grep.txt test_files/test_6_grep.txt test_files/test_7_grep.txt" 
    "test_files/test_6_grep.txt test_files/test_7_grep.txt test_files/test_ptrn_grep.txt"
    "test_files/test_0_grep.txt test_files/test_1_grep.txt test_files/test_ptrn_grep.txt"
    "test_files/test_1_grep.txt test_files/test_2_grep.txt test_files/test_ptrn_grep.txt"
    "test_files/test_4_grep.txt test_files/test_3_grep.txt test_files/test_ptrn_grep.txt"
    "test_files/test_5_grep.txt test_files/test_6_grep.txt test_files/test_ptrn_grep.txt"

)
patternArray=(
    "FLAGS" "for" "^int" "^print" "intel" "int" "regex" "while" "void" "'.'"
)



printf "******************************************************\n"
printf "*                                                    *\n"
printf "*                                                    *\n"
printf "*                  TESTING -e FLAG                   *\n"
printf "*                                                    *\n"
printf "*                                                    *\n"
printf "******************************************************\n"

for files in "${fileArray[@]}"; do
        for patterns in "${patternForTestingEflag[@]}"; do
            "${s21_command[@]}" $patterns $files > "${s21_command[@]}".log
            "${sys_command[@]}" $patterns $files > "${sys_command[@]}".log
            let "COUNTER++"
            DIFF="$(diff -s "${s21_command[@]}".log "${sys_command[@]}".log)"
            if [ "$DIFF" == "Files "${s21_command[@]}".log and "${sys_command[@]}".log are identical" ]
            then
                echo -e ${COUNTER} - ${green}Success${clear} $patterns $files
                let "SUCCESS++"
                printf "\n"
            else
                echo -e ${COUNTER} - ${red}Failed${clear} $patterns $files
                printf "\n"
                "$(diff -s "${s21_command[@]}".log "${sys_command[@]}".log)"
                echo "${s21_command[@]}" $patterns $files >> "${s21_command[@]}_errors".log
                let "FAILED++"
                printf "\n"
            fi
                rm -f "${sys_command[@]}".log
                rm -f "${s21_command[@]}".log
        done
done

for files in "${multipleFilesArray[@]}"; do
        for patterns in "${patternForTestingEflag[@]}"; do
            "${s21_command[@]}" $patterns $files > "${s21_command[@]}".log
            "${sys_command[@]}" $patterns $files > "${sys_command[@]}".log
            let "COUNTER++"
            DIFF="$(diff -s "${s21_command[@]}".log "${sys_command[@]}".log)"
            if [ "$DIFF" == "Files "${s21_command[@]}".log and "${sys_command[@]}".log are identical" ]
            then
                echo -e ${COUNTER} - ${green}Success${clear} $patterns $files
                let "SUCCESS++"
                printf "\n"
            else
                echo -e ${COUNTER} - ${red}Failed${clear} $patterns $files
                printf "\n"
                "$(diff -s "${s21_command[@]}".log "${sys_command[@]}".log)"
                echo "${s21_command[@]}" $patterns $files >> "${s21_command[@]}_errors".log
                let "FAILED++"
                printf "\n"
            fi
                rm -f "${sys_command[@]}".log
                rm -f "${s21_command[@]}".log
        done
done

printf "******************************************************\n"
printf "*                                                    *\n"
printf "*                                                    *\n"
printf "*           TESTING WITH 1 FLAG AND 1 FILE           *\n"
printf "*                                                    *\n"
printf "*                                                    *\n"
printf "******************************************************\n"

for files in "${fileArray[@]}"; do
    for flags in "${flagArray[@]}"; do
        for patterns in "${patternArray[@]}"; do
            "${s21_command[@]}" $flags $patterns $files > "${s21_command[@]}".log
            "${sys_command[@]}" $flags $patterns $files > "${sys_command[@]}".log
            let "COUNTER++"
            DIFF="$(diff -s "${s21_command[@]}".log "${sys_command[@]}".log)"
            if [ "$DIFF" == "Files "${s21_command[@]}".log and "${sys_command[@]}".log are identical" ]
            then
                echo -e ${COUNTER} - ${green}Success${clear} $flags $files
                let "SUCCESS++"
                printf "\n"
            else
                echo -e ${COUNTER} - ${red}Failed${clear} $flags $patterns $files
                printf "\n"
                "$(diff -s "${s21_command[@]}".log "${sys_command[@]}".log)"
                echo "${s21_command[@]}" $flags $patterns $files >> "${s21_command[@]}_errors".log
                let "FAILED++"
                printf "\n"
            fi
                rm -f "${sys_command[@]}".log
                rm -f "${s21_command[@]}".log
        done
    done
done

printf "******************************************************\n"
printf "*                                                    *\n"
printf "*                                                    *\n"
printf "*          TESTING WITH 2 FLAGS AND 1 FILE           *\n"
printf "*                                                    *\n"
printf "*                                                    *\n"
printf "******************************************************\n"
for files in "${fileArray[@]}"; do
    for pairFlags in "${pairFlagArray[@]}"; do
        for patterns in "${patternArray[@]}"; do
            "${s21_command[@]}" $pairFlags $patterns $files > "${s21_command[@]}".log
            "${sys_command[@]}" $pairFlags $patterns $files > "${sys_command[@]}".log
            let "COUNTER++"
            DIFF="$(diff -s "${s21_command[@]}".log "${sys_command[@]}".log)"
            if [ "$DIFF" == "Files "${s21_command[@]}".log and "${sys_command[@]}".log are identical" ]
            then
                echo -e ${COUNTER} - ${green}Success${clear} $pairFlags $files
                let "SUCCESS++"
                printf "\n"
            else
                echo -e ${COUNTER} - ${red}Failed${clear} $pairFlags $patterns $files
                printf "\n"
                "$(diff -s "${s21_command[@]}".log "${sys_command[@]}".log)"
                echo "${s21_command[@]}" $pairFlags $patterns $files >> "${s21_command[@]}_errors".log
                let "FAILED++"
                printf "\n"
            fi
                rm -f "${sys_command[@]}".log
                rm -f "${s21_command[@]}".log
        done
    done
done
printf "******************************************************\n"
printf "*                                                    *\n"
printf "*                                                    *\n"
printf "*         TESTING WITH 1 FLAG AND 1+ FILES           *\n"
printf "*                                                    *\n"
printf "*                                                    *\n"
printf "******************************************************\n"

for multipleFiles in "${multipleFilesArray[@]}"; do
    for flags in "${flagArray[@]}"; do
        for patterns in "${patternArray[@]}"; do
            "${s21_command[@]}" $flags $patterns $multipleFiles > "${s21_command[@]}".log
            "${sys_command[@]}" $flags $patterns $multipleFiles > "${sys_command[@]}".log
            let "COUNTER++"
            DIFF="$(diff -s "${s21_command[@]}".log "${sys_command[@]}".log)"
            if [ "$DIFF" == "Files "${s21_command[@]}".log and "${sys_command[@]}".log are identical" ]
            then
                echo -e ${COUNTER} - ${green}Success${clear} $flags $multipleFiles
                let "SUCCESS++"
                printf "\n"
            else
                echo -e ${COUNTER} - ${red}Failed${clear} $flags $patterns $multipleFiles
                printf "\n"
                "$(diff -s "${s21_command[@]}".log "${sys_command[@]}".log)"
                echo "${s21_command[@]}" $flags $patterns $multipleFiles >> "${s21_command[@]}_errors".log
                let "FAILED++"
                printf "\n"
            fi
                rm -f "${sys_command[@]}".log
                rm -f "${s21_command[@]}".log
        done
    done
done

printf "******************************************************\n"
printf "*                                                    *\n"
printf "*                                                    *\n"
printf "*        TESTING WITH 1+ FLAG AND 1+ FILES           *\n"
printf "*                                                    *\n"
printf "*                                                    *\n"
printf "******************************************************\n"
for multipleFiles in "${multipleFilesArray[@]}"; do
    for pairFlags in "${pairFlagArray[@]}"; do
        for patterns in "${patternArray[@]}"; do
            "${s21_command[@]}" $flags $patterns $multipleFiles > "${s21_command[@]}".log
            "${sys_command[@]}" $flags $patterns $multipleFiles > "${sys_command[@]}".log
            let "COUNTER++"
            DIFF="$(diff -s "${s21_command[@]}".log "${sys_command[@]}".log)"
            if [ "$DIFF" == "Files "${s21_command[@]}".log and "${sys_command[@]}".log are identical" ]
            then
                echo -e ${COUNTER} - ${green}Success${clear} $pairFlags $patterns $multipleFiles
                let "SUCCESS++"
                printf "\n"
            else
                echo -e ${COUNTER} - ${red}Failed${clear} $pairFlags $patterns $multipleFiles
                printf "\n"
                "$(diff -s "${s21_command[@]}".log "${sys_command[@]}".log)"
                echo "${s21_command[@]}" $flags $patterns $multipleFiles >> "${s21_command[@]}_errors".log
                let "FAILED++"
                printf "\n"
            fi
                rm -f "${sys_command[@]}".log
                rm -f "${s21_command[@]}".log
        done
    done
done


echo -e SUCCESSED:${green} ${SUCCESS} ${clear}
echo -e FAILED:${red} ${FAILED} ${clear}

