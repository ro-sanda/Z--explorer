#!/bin/bash

#Simulation Card 1: u u~ -> Z'

name="sim_card_1"

max=$(wc -l masses_couplings_sim_cards.dat | awk '1==1 {print $1}')
for (( linea=1; linea<="$max"; linea++ ))
do

        MGeV=$(awk 'NR=='"$linea"'{print $1}' masses_couplings_sim_cards.dat)
	MTeV=$(awk 'NR=='"$linea"'{print $2}' masses_couplings_sim_cards.dat)
        c1=$(awk 'NR=='"$linea"'{print $3}' masses_couplings_sim_cards.dat)
	c0=$(awk 'NR=='"$linea"'{print $4}' masses_couplings_sim_cards.dat)



        sed -i "s/32.*MZp/32     $MGeV   # MZp/" sim1uuZp/Cards/param_card.dat
        sed -i "s/1.*gZptL/1     $c0    # gZptL/" sim1uuZp/Cards/param_card.dat
        sed -i "s/2.*gZptR/2     $c0    # gZptR/" sim1uuZp/Cards/param_card.dat
        sed -i "s/3.*gZpbL/3     $c0    # gZpbL/" sim1uuZp/Cards/param_card.dat
        sed -i "s/4.*gZpbR/4     $c0    # gZpbR/" sim1uuZp/Cards/param_card.dat
        sed -i "s/5.*gZpcL/5     $c0    # gZpcL/" sim1uuZp/Cards/param_card.dat
        sed -i "s/6.*gZpcR/6     $c0    # gZpcR/" sim1uuZp/Cards/param_card.dat
        sed -i "s/7.*gZpsL/7     $c0    # gZpsL/" sim1uuZp/Cards/param_card.dat
        sed -i "s/8.*gZpsR/8     $c0    # gZpsR/" sim1uuZp/Cards/param_card.dat
        sed -i "s/9.*gZpuL/9     $c1    # gZpuL/" sim1uuZp/Cards/param_card.dat
        sed -i "s/10.*gZpuR/10     $c1    # gZpuR/" sim1uuZp/Cards/param_card.dat
        sed -i "s/11.*gZpdL/11     $c0    # gZpdL/" sim1uuZp/Cards/param_card.dat
        sed -i "s/12.*gZpdR/12     $c0    # gZpdR/" sim1uuZp/Cards/param_card.dat


        cd sim1uuZp/
	filename="$name-$linea"
        echo -e "\n"|./bin/generate_events $filename  # presses the 2 enters needed when run in 5.1.4
	gunzip Events/$filename/unweighted_events.lhe.gz
	xsection=$(awk '$2=="Integrated" {print $6}' Events/$filename/unweighted_events.lhe);
	echo  "$MTeV  $xsection" >> "$name".dat
	rm -rf Events/$filename
	cd ..
#	sleep 10

done
mv sim1uuZp/"$name".dat "$name".dat



#Simulation Card 2: d d~ -> Z'

name="sim_card_2"


for (( linea=1; linea<="$max"; linea++ ))
do

        MGeV=$(awk 'NR=='"$linea"'{print $1}' masses_couplings_sim_cards.dat)
	MTeV=$(awk 'NR=='"$linea"'{print $2}' masses_couplings_sim_cards.dat)
        c1=$(awk 'NR=='"$linea"'{print $3}' masses_couplings_sim_cards.dat)
	c0=$(awk 'NR=='"$linea"'{print $4}' masses_couplings_sim_cards.dat)



        sed -i "s/32.*MZp/32     $MGeV   # MZp/" sim2ddZp/Cards/param_card.dat
        sed -i "s/1.*gZptL/1     $c0    # gZptL/" sim2ddZp/Cards/param_card.dat
        sed -i "s/2.*gZptR/2     $c0    # gZptR/" sim2ddZp/Cards/param_card.dat
        sed -i "s/3.*gZpbL/3     $c0    # gZpbL/" sim2ddZp/Cards/param_card.dat
        sed -i "s/4.*gZpbR/4     $c0    # gZpbR/" sim2ddZp/Cards/param_card.dat
        sed -i "s/5.*gZpcL/5     $c0    # gZpcL/" sim2ddZp/Cards/param_card.dat
        sed -i "s/6.*gZpcR/6     $c0    # gZpcR/" sim2ddZp/Cards/param_card.dat
        sed -i "s/7.*gZpsL/7     $c0    # gZpsL/" sim2ddZp/Cards/param_card.dat
        sed -i "s/8.*gZpsR/8     $c0    # gZpsR/" sim2ddZp/Cards/param_card.dat
        sed -i "s/9.*gZpuL/9     $c0    # gZpuL/" sim2ddZp/Cards/param_card.dat
        sed -i "s/10.*gZpuR/10     $c0    # gZpuR/" sim2ddZp/Cards/param_card.dat
        sed -i "s/11.*gZpdL/11     $c1    # gZpdL/" sim2ddZp/Cards/param_card.dat
        sed -i "s/12.*gZpdR/12     $c1    # gZpdR/" sim2ddZp/Cards/param_card.dat


        cd sim2ddZp/
	filename="$name-$linea"
        echo -e "\n"|./bin/generate_events $filename  # presses the 2 enters needed when run in 5.1.4
	gunzip Events/$filename/unweighted_events.lhe.gz
	xsection=$(awk '$2=="Integrated" {print $6}' Events/$filename/unweighted_events.lhe);
	echo  "$MTeV  $xsection" >> "$name".dat
	rm -rf Events/$filename
	cd ..
#	sleep 10

done
mv sim2ddZp/"$name".dat "$name".dat




#Simulation Card 3: c c~ -> Z'

name="sim_card_3"


for (( linea=1; linea<="$max"; linea++ ))
do

        MGeV=$(awk 'NR=='"$linea"'{print $1}' masses_couplings_sim_cards.dat)
	MTeV=$(awk 'NR=='"$linea"'{print $2}' masses_couplings_sim_cards.dat)
        c1=$(awk 'NR=='"$linea"'{print $3}' masses_couplings_sim_cards.dat)
	c0=$(awk 'NR=='"$linea"'{print $4}' masses_couplings_sim_cards.dat)



        sed -i "s/32.*MZp/32     $MGeV   # MZp/" sim3ccZp/Cards/param_card.dat
        sed -i "s/1.*gZptL/1     $c0    # gZptL/" sim3ccZp/Cards/param_card.dat
        sed -i "s/2.*gZptR/2     $c0    # gZptR/" sim3ccZp/Cards/param_card.dat
        sed -i "s/3.*gZpbL/3     $c0    # gZpbL/" sim3ccZp/Cards/param_card.dat
        sed -i "s/4.*gZpbR/4     $c0    # gZpbR/" sim3ccZp/Cards/param_card.dat
        sed -i "s/5.*gZpcL/5     $c1    # gZpcL/" sim3ccZp/Cards/param_card.dat
        sed -i "s/6.*gZpcR/6     $c1    # gZpcR/" sim3ccZp/Cards/param_card.dat
        sed -i "s/7.*gZpsL/7     $c0    # gZpsL/" sim3ccZp/Cards/param_card.dat
        sed -i "s/8.*gZpsR/8     $c0    # gZpsR/" sim3ccZp/Cards/param_card.dat
        sed -i "s/9.*gZpuL/9     $c0    # gZpuL/" sim3ccZp/Cards/param_card.dat
        sed -i "s/10.*gZpuR/10     $c0    # gZpuR/" sim3ccZp/Cards/param_card.dat
        sed -i "s/11.*gZpdL/11     $c0    # gZpdL/" sim3ccZp/Cards/param_card.dat
        sed -i "s/12.*gZpdR/12     $c0    # gZpdR/" sim3ccZp/Cards/param_card.dat


        cd sim3ccZp/
	filename="$name-$linea"
        echo -e "\n"|./bin/generate_events $filename  # presses the 2 enters needed when run in 5.1.4
	gunzip Events/$filename/unweighted_events.lhe.gz
	xsection=$(awk '$2=="Integrated" {print $6}' Events/$filename/unweighted_events.lhe);
	echo  "$MTeV  $xsection" >> "$name".dat
	rm -rf Events/$filename
	cd ..
#	sleep 10

done
mv sim3ccZp/"$name".dat "$name".dat


#Simulation Card 4: s s~ -> Z'

name="sim_card_4"


for (( linea=1; linea<="$max"; linea++ ))
do

        MGeV=$(awk 'NR=='"$linea"'{print $1}' masses_couplings_sim_cards.dat)
	MTeV=$(awk 'NR=='"$linea"'{print $2}' masses_couplings_sim_cards.dat)
        c1=$(awk 'NR=='"$linea"'{print $3}' masses_couplings_sim_cards.dat)
	c0=$(awk 'NR=='"$linea"'{print $4}' masses_couplings_sim_cards.dat)



        sed -i "s/32.*MZp/32     $MGeV   # MZp/" sim4ssZp/Cards/param_card.dat
        sed -i "s/1.*gZptL/1     $c0    # gZptL/" sim4ssZp/Cards/param_card.dat
        sed -i "s/2.*gZptR/2     $c0    # gZptR/" sim4ssZp/Cards/param_card.dat
        sed -i "s/3.*gZpbL/3     $c0    # gZpbL/" sim4ssZp/Cards/param_card.dat
        sed -i "s/4.*gZpbR/4     $c0    # gZpbR/" sim4ssZp/Cards/param_card.dat
        sed -i "s/5.*gZpcL/5     $c0    # gZpcL/" sim4ssZp/Cards/param_card.dat
        sed -i "s/6.*gZpcR/6     $c0    # gZpcR/" sim4ssZp/Cards/param_card.dat
        sed -i "s/7.*gZpsL/7     $c1    # gZpsL/" sim4ssZp/Cards/param_card.dat
        sed -i "s/8.*gZpsR/8     $c1    # gZpsR/" sim4ssZp/Cards/param_card.dat
        sed -i "s/9.*gZpuL/9     $c0    # gZpuL/" sim4ssZp/Cards/param_card.dat
        sed -i "s/10.*gZpuR/10     $c0    # gZpuR/" sim4ssZp/Cards/param_card.dat
        sed -i "s/11.*gZpdL/11     $c0    # gZpdL/" sim4ssZp/Cards/param_card.dat
        sed -i "s/12.*gZpdR/12     $c0    # gZpdR/" sim4ssZp/Cards/param_card.dat


        cd sim4ssZp/
	filename="$name-$linea"
        echo -e "\n"|./bin/generate_events $filename  # presses the 2 enters needed when run in 5.1.4
	gunzip Events/$filename/unweighted_events.lhe.gz
	xsection=$(awk '$2=="Integrated" {print $6}' Events/$filename/unweighted_events.lhe);
	echo  "$MTeV  $xsection" >> "$name".dat
	rm -rf Events/$filename
	cd ..
#	sleep 10

done
mv sim4ssZp/"$name".dat "$name".dat





#Simulation Card 5: b b~ -> Z'

name="sim_card_5"


for (( linea=1; linea<="$max"; linea++ ))
do

        MGeV=$(awk 'NR=='"$linea"'{print $1}' masses_couplings_sim_cards.dat)
	MTeV=$(awk 'NR=='"$linea"'{print $2}' masses_couplings_sim_cards.dat)
        c1=$(awk 'NR=='"$linea"'{print $3}' masses_couplings_sim_cards.dat)
	c0=$(awk 'NR=='"$linea"'{print $4}' masses_couplings_sim_cards.dat)



        sed -i "s/32.*MZp/32     $MGeV   # MZp/" sim5bbZp/Cards/param_card.dat
        sed -i "s/1.*gZptL/1     $c0    # gZptL/" sim5bbZp/Cards/param_card.dat
        sed -i "s/2.*gZptR/2     $c0    # gZptR/" sim5bbZp/Cards/param_card.dat
        sed -i "s/3.*gZpbL/3     $c1    # gZpbL/" sim5bbZp/Cards/param_card.dat
        sed -i "s/4.*gZpbR/4     $c1    # gZpbR/" sim5bbZp/Cards/param_card.dat
        sed -i "s/5.*gZpcL/5     $c0    # gZpcL/" sim5bbZp/Cards/param_card.dat
        sed -i "s/6.*gZpcR/6     $c0    # gZpcR/" sim5bbZp/Cards/param_card.dat
        sed -i "s/7.*gZpsL/7     $c0    # gZpsL/" sim5bbZp/Cards/param_card.dat
        sed -i "s/8.*gZpsR/8     $c0    # gZpsR/" sim5bbZp/Cards/param_card.dat
        sed -i "s/9.*gZpuL/9     $c0    # gZpuL/" sim5bbZp/Cards/param_card.dat
        sed -i "s/10.*gZpuR/10     $c0    # gZpuR/" sim5bbZp/Cards/param_card.dat
        sed -i "s/11.*gZpdL/11     $c0    # gZpdL/" sim5bbZp/Cards/param_card.dat
        sed -i "s/12.*gZpdR/12     $c0    # gZpdR/" sim5bbZp/Cards/param_card.dat


        cd sim5bbZp/
	filename="$name-$linea"
        echo -e "\n"|./bin/generate_events $filename  # presses the 2 enters needed when run in 5.1.4
	gunzip Events/$filename/unweighted_events.lhe.gz
	xsection=$(awk '$2=="Integrated" {print $6}' Events/$filename/unweighted_events.lhe);
	echo  "$MTeV  $xsection" >> "$name".dat
	rm -rf Events/$filename
	cd ..
#	sleep 10

done
mv sim5bbZp/"$name".dat "$name".dat








