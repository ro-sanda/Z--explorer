#!/bin/bash


rm rows_card_1.dat

name="rows_card_1"

s1=$(grep -c '^' sim_card_1.dat)
s2=$(grep -c '^' sim_card_2.dat)
s3=$(grep -c '^' sim_card_3.dat)
s4=$(grep -c '^' sim_card_4.dat)
s5=$(grep -c '^' sim_card_5.dat)


e1=$(grep -c '^' exp_card_1.dat)
e2=$(grep -c '^' exp_card_2.dat)
e3=$(grep -c '^' exp_card_3.dat)
e4=$(grep -c '^' exp_card_4.dat)
e5=$(grep -c '^' exp_card_5.dat)
e6=$(grep -c '^' exp_card_6.dat)
e7=$(grep -c '^' exp_card_7.dat)
e8=$(grep -c '^' exp_card_8.dat)
e9=$(grep -c '^' exp_card_9.dat)
e10=$(grep -c '^' exp_card_10.dat)

ir=$(grep -c '^' ../incard/card_1.dat)
ic=$(awk -F"\t" '{print NF;exit}' ../incard/card_1.dat)

# -e allows the use of \n
echo  -e "$s1 $e1 \n$s2 $e2 \n$s3 $e3 \n$s4 $e4 \n$s5 $e5 \n0 $e6 \n0 $e7 \n0 $e8 \n0 $e9 \n0 $e10 \n$ir $ic" >> "$name".dat



