read -p "Enter values of i, j, k seperated by space" i j k l
if [[ $l == '' ]]
then
	if [[ $i != '' ]] && [[ $j != '' ]] && [[ $k != '' ]] 
	then
		VARI=$(echo $i | awk '/regex|^[0-9]+$/{print "I"}') 
		VARJ=$(echo $j | awk '/regex|^[0-9]+$/{print "J"}')
		VARK=$(echo $k | awk '/regex|^[0-9]+$/{print "K"}')
		if [[ $VARI == 'I' ]] && [[ $VARJ == 'J' ]] && [[ $VARK == 'K' ]]
		then
			for ((a=0; a<=$i; a++))
			do
				for ((b=0; b<=$j; b++))
				do
					for ((c=0; c<=$k; c++))
					do
					echo "Inside 3"
					done
				echo "Inside 2"
				done
			echo "Inside 1"
			done
		else
		echo "Please enter positive integer values for i, j, k"
		fi
		
	else
	echo "Please enter values for all variables"	
	fi
else
echo "Please enter only three values"
fi



 

