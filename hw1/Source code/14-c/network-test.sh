true > network-test-latency.txt 
while read -r line; 
do
	name="$line"
	VAR1=`ping -c 3 "$name"`
	VAR2=`echo "$VAR1" | cut -b 24-| tr '/' '\n'| tail -3| head -1`
	VAR3="$name $VAR2"
	echo "$VAR3" >> network-test-latency.txt	
done < $1




