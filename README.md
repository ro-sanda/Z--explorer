# Z'-explorer : a simple tool to probe Z' models against LHC data

## A QUICK START USER GUIDE


### Ezequiel Álvarez, Rosa María Sandá Seoane, Mariel Estévez 


#### SET UP



Download main directory into your system. To start, set on lib folder and put make. No aditionally steps are required.

The script runs on C++.

If changes in source code are done, set on lib folder again and put make before running.





#### SET MODEL:



Information about the Z' model must be provided through an incard, that must be stored as /incard/card_1.dat. For each reference point in parameter space, the following information must be provided in columns (separate by space):


M  guL guR  gdL  gdR  gcL  gcR  gsL  gsR  gbL  gbR  gtL  gtR  geL  geR  gμL  gμR  gτL  gτR  Γinv  Γww  Γzh  Γxx


where M is de Z' mass (in TeV), gfL/R is the coupling of the Z' to the corresponding left/right fermion, and Γinv, Γww, Γhz are the partial widths to inv, WW and ZH. The total width to non SM particles  can be added as Γxx.

Every reference point in parameter space should be set in a different row. There is no limit in the number of reference points that can be explored.


In /incard/example/SSM can be found an incard example for a Sequential Standard Model Z' (Z. Phys. C45 (1989) 109).







#### RUN



After providing an incard, set on the main directory and write ./program.out.






#### EXPLORATION RESULTS:



The generated output file is saved in /output/1.dat. The output contains the following information for each reference point set in incard:
 

M  guL  guR  gdL  gdR  gcL  gcR  gsL  gsR  gbL  gbR  gtL  gtR  geL  geR  gμL  gμR  gτL  gτR  Γinv  Γww  Γzh  Γxx  Sjj  Sbb  Stt  See  Sμμ  Sττ  Sinv  SWW  SZH  Sxx


where S(defined as σpred/σlim) is the strength of the signal in each possible Z' decay channel.


More information about calculation can be found in /extra folder:

2.dat contains the estimated decay widths. 
3.dat contains the estimated branching ratios.
4.dat contains the estimated σpred.
5.dat contains the extracted σlim from experimental data.





#### EXPERIMENTAL INFORMATION:

Available experimental data from LHC to all possible Z' decay channels is stored in  /cards folder as experimental cards. Data is specified in two columns, where first one is the corresponding Z'mass (in TeV) and second one is the corresponding σlim (in pb): 


exp_card_1.dat-> jj (arXiv:1910.08447)
exp_card_2.dat-> bb (arXiv:1805.09299)
exp_card_3.dat-> tt (arXiv:1810.05955)
exp_card_4.dat-> ee (CMS-PAS-EXO-10-019)
exp_card_5.dat-> μμ (CMS-PAS-EXO-10-019)
exp_card_6.dat-> ττ (arXiv:1709.07242)
exp_card_7.dat->inv -
exp_card_8.dat-> ww (arXiv:1710.07235)
exp_card_9.dat-> zh (arXiv:1906.00057)
exp_card_10.dat-> xx -


User can update the experimental information just by replacing the corresponding experimental card. No other step is requiered. Note that Sinv and Sxx in /output/1.dat are left as dummy variables until the eventual addition of the corresponding experimental data.





#### RECORDED SIMULATIONS USED BY Z'-EXPLORER:

For computing Z' production cross section, previously generated and recorded production cross section with MadGraph5_aMC@NLO (arXiv:1405.0301) is stored in /cards folder as simulation cards. These simulations were generated with a tailored Z' model which couples with unity to only one quark in the proton each time, at sqrt(s) = 13 TeV. 

sim_card_1.dat->  uu-->Z'
sim_card_2.dat->  dd-->Z'
sim_card_3.dat->  cc-->Z'
sim_card_4.dat->  ss-->Z'
sim_card_5.dat->  bb-->Z'

These simulations are adjusted using incard data to calculate σpred.








For more information, please visit the associated publication "Z'-explorer : a simple tool to probe Z' models against LHC data".

