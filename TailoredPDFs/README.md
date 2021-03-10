#### IMPLENTING Z'-EXPLORER WITH TAILORED SCALES AND PDFS



Download the UFO-model */extra-Zprime/* and set it into the */models/* folder of your *MadGraph5_aMC@NLO* main directory to implement the Z' effective lagrangian. 

Download all the files in */TailoredPDFs/*  and copy them into your *MadGraph5_aMC@NLO* main directory. 

Once in the directory, enter *bash sim_card_generator_1.bash*. It will generate five folders with *MadGraph5_aMC@NLO* (*/sim1uu/*, */sim2dd/*,*/sim3cc/*,
*/sim4ss/*, */sim5bb/*), each of them with the Z' production process associated to the annhilation of the corresponding quark-antiquark pair. 

Go to the */Cards/run_card.dat* inside each folder to modify the default PDF set, factorization and normalization scales, and other customizable parameters for
the event generation. 

After that, once in the *MadGraph5_aMC@NLO* main directory again, enter *bash sim_card_generator_2.bash*.

The five *sim_cards* will be generated inside your *MadGraph5_aMC@NLO* main directory during execution for a set of values of M between 0.4 and 8.1 TeV, 
with a step of 0.01 TeV, and at sqrt(s)=13 TeV. Changes inside the */Cards/param_card.dat* of each folder are automatically done to ensure that the
corresponding quark couples with unity to Z' in each folder. 

After execution, the *sim_cards* are ready to be use by the software. Copy them into */Z'-explorer/cards/*. No other step is required.





































