#!/bin/sh
# Author: James Anderson 
# Class: CS284
# Assignment: 1 - Shell Script




while [ 1 ]
do

  clear
  echo "---------------------------------------------------------"
  echo "---------------------WELCOME-----------------------------"
  echo "---------------------------------------------------------"
  echo "Please select a menu option"
  echo "1- ancestry history"
  echo "2- who is on-line"
  echo "3- what process any user is running"
  echo "4- exit"
  echo "---------------------------------------------------------"

  read choice								# read the users's menu option

  case $choice in

    1)
    
   		clear
    
		pid=$$  # get current process ID
		ps -acefl > tempFile    # store the process listing in a temporary file
		
		
		echo  "Ancestry Tree for" $pid  #prints title
		
		while [ $pid != 0 ]     # go until we reach the root process
		do
		
		    pname=$(awk '{ if ($4 == '$pid'  ) print $14}' tempFile)    #get the name of the process
			
			echo $pid' : '$pname   #print the process and name
			
			if [ $pid != 1 ] # if its not the root process add a branch
			then
				echo "      | " 
			fi 
			
			
			pid=$( awk '{ if ($4 == '$pid'  ) print $5}' tempFile )  #set pid to parrents pid

			
		done
		
		rm tempFile #get rid of tempFile
		
		read foo #pause for enter
    ;;
      
    2)
    	clear
    	
		echo "The users on the system are:"
		
		who | awk '{print $1}' | uniq #print only the unique line ones of the who comand
		
		read foo #pause for enter
    ;;
      
    3)
      
      clear
      
      echo "Please select a user:"
      
      who | awk '{print $1}' | uniq > tempFile
   
	
      users=$(wc -l tempFile | awk '{print $1}')  # get number of users
      
      
      i=0
      
      while [  $i != $users  ]
      do
       
        i=$(expr $i + 1) 
       	user=$(awk 'NR == '$i'' tempFile)
        echo "$i) $user"
       
      done
      	
      read user_num
      
      clear
      
      user=$(awk 'NR == '$user_num'' tempFile)
      
      echo "User $user's process are:"
      
      echo "----------------------------------------------------------"
      
      ps -ef | awk 'NR == 1' 
      
      echo "----------------------------------------------------------"
      
      ps -ef | grep $user | less -SEX
      
      rm tempFile #get rid of tempFile     
        
      read foo #pause for enter
	   
    ;;
    
    4)
      clear
      echo "-----Thank You For Choosing Anderson Shells-----"
      exit 1
    ;;
    
    42)
        clear
    	echo "            Congratulations!!!          "
    	echo "         You Found the Easter Egg       "
		echo "                  .....                 "
		echo "              .-/oossso+:.              "
		echo "            .:/+osssssooo+/-            "
		echo "           -//++++ooo++++++/:           "
		echo "          .-:://++++++++++///:.         "
		echo "         .----::///////////::/:         "
		echo "         -----::///////////////:        "
		echo "        -:::::///+++oo+++++//+++.       "
		echo "        -:::-:/++oooooooooo+++++-       "
		echo "        -:::../++oosssssoooo++oo:       "
		echo "        ---:..:/+ooossssoooooooo.       "
		echo "         -:::--/++oosssssssssso/        "
		echo "         .://///+ossyyyyyyssso/         "
		echo "          .://--/ossyyyyyssso/          "
		echo "            .:::/+oosssssso/.           "
		echo "               -:/++oooo+:.             "
		echo "                ..-::::-.               "
		echo "             ''....-------.'            "
		echo "           '''''....------...'          "
		echo "          '''''''.............'         "
		echo "         '''''''''''''''''''''''        "
		echo "                ''''''''''''''''        " 
		
		read foo
		clear
    ;; 
    
    *) 
      clear
      echo "---------------------------------------------------------"
      echo ------------Sorry $choice is not a vald option-----------------
      echo "---------------------------------------------------------"
      
      read foo #pause for enter
    ;; 
    
    esac
done
