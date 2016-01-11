﻿#!/bin/sh

if [ ! -n  "$1" ]
then
	echo "please use like: autotest.sh <-s nosec|tinydtls|dtls> "
	echo "[-1 xxx] [-2 xxx] [-3 xxx] [-4 xxx] [-a xxx]"
	exit
fi

cd ../../

while getopts ":s:1:2:3:4:a:" opt
do
        case $opt in
                s ) export APP_SEC_TYPE=$OPTARG;;
                1 ) export URL1=$OPTARG;;
                2 ) export URL2=$OPTARG;;
                3 ) export URL3=$OPTARG;;
                4 ) export URL4=$OPTARG;;
                a ) export AUTH=$OPTARG;;
#                ? ) echo "error"
#                    exit 1;;
        esac
done
echo ${APP_SEC_TYPE}

make test APP_SEC_TYPE=${APP_SEC_TYPE} URL1=${URL1} URL2=${URL2} URL3=${URL3} URL4=${URL4} AUTH=${AUTH}

./bin/test_limit
WD_LIMIT=$?

./bin/test_node
WD_NODE=$?

./bin/test_multipleHost
WD_MULTIPLEHOST=$?

./bin/test_step
WD_STEP=$?

./bin/test_disEvent
WD_DISEVENT=$?
make clean APP_SEC_TYPE=${APP_SEC_TYPE}
echo "\n*************************************************************************\n"

if [ ${WD_DISEVENT} -ne 0 ]
then
	echo "wilddog dis event test failed, please run test_disEvent to find more information!"
else
	echo "wilddog dis event test pass!"
fi

if [ ${WD_LIMIT} -ne 0 ]
then
	echo "wilddog limit test failed, please run test_limit to find more information!"
else
	echo "wilddog limit test pass!"
fi

if [ ${WD_NODE} -ne 0 ]
then
	echo "wilddog node test failed, please run test_node to find more information!"
else
	echo "wilddog node test pass!"
fi
if [ "${WD_MULTIPLEHOST}" -ne "0" ]
then
	echo "wilddog test_multipleHost test failed, please run test_multipleHost to find more information!"
else
	echo "wilddog test_multipleHost test pass!"
fi

if [ ${WD_STEP} -ne 0 ]
then
	echo "wilddog test_step test failed, please run test_step to find more information!"
else
	echo "wilddog test_step test pass!"
fi
echo "\n*************************************************************************\n"
