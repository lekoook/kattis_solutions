#!/bin/bash

clear

echo -n "Input program name (case-sensitive!): "
read programName
if [ ! -f ./${programName} ]; then
	echo "Program does not exist! Exiting."
	exit
fi

# Concatenate output of program to temporary output files
# First retrieve the number of input files by looking for the number 
# of *.in files
numOfInputs="$(ls -l *.in | wc -l)"
echo -n "Input input files prefix (case-sensitive!): "
read inputPrefix
if [ $(ls -l ${inputPrefix}*.in | wc -l) == 0 ]; then
	echo "No such prefix exists! Exiting."
	exit
fi
outputPrefix="temp"
if [ ${inputPrefix} == "temp" ]; then
	outputPrefix="temp_output"
fi
for ((inputNum=1; inputNum<=numOfInputs; inputNum++));
	do
		inputFileName="${inputPrefix}${inputNum}.in"
		outputFileName="${outputPrefix}${inputNum}.ans"
		./${programName} < ./${inputFileName} > ${outputFileName}
		echo "${outputFileName} created from ${inputFileName}"
	done

# Test for difference between the temporary output and source output files
# Ouput SUCCESS or FAILURE for each output test
echo ""
echo "***************************************************************"
for ((outputNum=1; outputNum<=numOfInputs; outputNum++));
	do
		sourceOutputName="${inputPrefix}${outputNum}.ans"
		outputFileName="${outputPrefix}${outputNum}.ans"
		#if [ "$(diff "${outputFileName}" "${sourceOutputName}")" ]; then
		if diff "${outputFileName}" "${sourceOutputName}" ; then
			echo "* Tested ${outputFileName} against ${sourceOutputName} - SUCCESS!"
		else
			echo ""
			echo "* Tested ${outputFileName} against ${sourceOutputName} - FAILED!"
			echo "* The first output is the program output."
		fi
		if [ ${outputNum} != ${numOfInputs} ]; then
			echo "---------------------------------------------------------------"
		fi
	done
echo "***************************************************************"
echo ""

# Clean up all temporary output files
rm -v ${outputPrefix}*.ans

echo -e "\nPress return to exit..."
read
