# <a href="https://arxiv.org/pdf/2005.05194.pdf" target=newwindow >Z'-explorer : a simple tool to probe Z' models against LHC data</a>

## A QUICK START USER GUIDE


### Ezequiel Álvarez, Rosa María Sandá Seoane, Mariel Estévez 


#### SET UP



Download main directory `/Z'-explorer/` into your system. To start, set on `/lib/` folder and run `make`. No aditionally steps are required. Repeat the same procedure when using the alternative version of the software (download `/Z'-explorer-BR/` instead).

The script runs on *C++*.

If changes in source code are done, set on `/lib/` folder again and repeat the above before running .





#### SET MODEL:


Information about the *Z'* model must be provided through an incard text file, that must be stored as `/incard/card_1.dat`. For each reference point in parameter space, the following information must be provided in columns (separated by spaces, no tabs):

~~~
M  guL guR  gdL  gdR  gcL  gcR  gsL  gsR  gbL  gbR  gtL  gtR  geL  geR  gμL  gμR  gτL  gτR  Γinv  Γww  ΓZh  Γxx
~~~

where `M` is the *Z'* mass (in TeV), `gfL/R` is the *Z'* coupling to the corresponding Left/Right fermion, and `Γinv`, `Γww`, `ΓZh` are the partial widths to invisible, *WW* and *Zh*. The total width to non SM particles can be added as `Γxx`.  If not, leave `Γxx` as 0.

Every reference point in parameter space should be set in a different row. There is no limit in the number of reference points (i.e. rows) that can be explored.

For users who prefer *Z'-explorer-BR*, the following per-line information must be included in `/incard/card_1.dat` (separated by spaces, no tabs), being cautiously to satisfy the narrow-width approximation:

~~~
M  σ(Z')  BR(jj)  BR(bb)  BR(tt)  BR(ee)  BR(μμ)  BR(ττ)  BR(inv)  BR(WW)  BR(Zh)  BR(xx)
~~~


In `/incard/example/SSM` can be found an incard example for a Sequential Standard Model *Z'* <a href="https://lib-extopc.kek.jp/preprints/PDF/1989/8906/8906326.pdf" target=newwindow >(Z. Phys. C45 (1989) 109)</a> to perform a test run and check the output card which will be placed at `/output/1.dat` .





#### RUN



After providing an incard, set on the main directory and enter `./program.out` .






#### EXPLORATION RESULTS:



The generated output file is saved in `/output/1.dat` . The output contains the following information for each reference point set in incard:
 
~~~
M  guL  guR  gdL  gdR  gcL  gcR  gsL  gsR  gbL  gbR  gtL  gtR  geL  geR  gμL  gμR  gτL  gτR  Γinv  Γww  Γzh  Γxx  Sjj  Sbb  Stt  See  Sμμ  Sττ  Sinv  SWW  SZh  Sxx   ΓZ'   WARNING:ΓZ'>5%
~~~

where `S` (defined as σ<sub>pred</sub>/σ<sub>lim</sub>) is the strength of the signal in each possible *Z'* decay channel, `ΓZ'` is the *Z'* total width and the warning displays 1 when `ΓZ'`>5% and 0 otherwise. 

In *Z'-explorer-BR*, only the strength in each channel is reported in `/output/1.dat`. 


More information about calculation can be found in `/extra/` folder:

- `2.dat` contains the estimated decay widths. 
- `3.dat` contains the estimated branching ratios.
- `4.dat` contains the estimated σ<sub>pred</sub>.
- `5.dat` contains the extracted σ<sub>lim</sub> from experimental data.





#### EXPERIMENTAL INFORMATION:

Available experimental data from LHC to all possible *Z'* decay channels is stored in  `/cards/` folder as experimental cards. Data is specified in two columns, where the first one is the corresponding *Z'* mass (in TeV) and the second one is the corresponding σ<sub>lim</sub> (in pb): 


- `exp_card_1.dat`-> *jj* <a href="https://arxiv.org/pdf/1910.08447.pdf" target=newwindow >(arXiv:1910.08447)</a>
- `exp_card_2.dat`-> *bb* <a href="https://arxiv.org/pdf/1805.09299.pdf" target=newwindow >(arXiv:1805.09299)</a> 
- `exp_card_3.dat`-> *tt* <a href="https://arxiv.org/pdf/1810.05905.pdf" target=newwindow >(arXiv:1810.05905)</a> 
- `exp_card_4.dat`-> *ee* <a href="https://cds.cern.ch/record/2684757/files/EXO-19-019-pas.pdf" target=newwindow >(CMS-PAS-EXO-19-019)</a>
- `exp_card_5.dat`-> *μμ* <a href="https://cds.cern.ch/record/2684757/files/EXO-19-019-pas.pdf" target=newwindow >(CMS-PAS-EXO-19-019)</a>
- `exp_card_6.dat`-> *ττ* <a href="https://arxiv.org/pdf/1709.07242.pdf" target=newwindow >(arXiv:1709.07242)</a>
- `exp_card_7.dat`-> *inv* -
- `exp_card_8.dat`-> *ww* <a href="https://arxiv.org/pdf/1710.07235.pdf" target=newwindow >(arXiv:1710.07235)</a>
- `exp_card_9.dat`-> *zh* <a href="https://arxiv.org/pdf/1906.00057.pdf" target=newwindow >(arXiv:1906.00057)</a>
- `exp_card_10.dat`-> *xx* -

User can update the experimental information just by replacing the corresponding experimental card. No other step is required. Note that `Sinv` and `Sxx` in `/output/1.dat` are left as dummy variables for future updates.





#### RECORDED SIMULATIONS USED BY Z'-EXPLORER:

For computing *Z'* production cross section, previously generated and recorded production cross section with *MadGraph5_aMC@NLO* <a href="https://arxiv.org/pdf/1405.0301.pdf" target=newwindow >(arXiv:1405.0301)</a> is stored in `/cards/` folder as simulation cards. These simulations were generated with a tailored *Z'* model which couples with unity to only one quark in the proton each time, at &radic; s = 13 TeV, and for M between 0.4 and 8 TeV (the range of masses that can be explored with *Z'-explorer*).

- `sim_card_1.dat`->  *uu-->Z'*
- `sim_card_2.dat`->  *dd-->Z'*
- `sim_card_3.dat`->  *cc-->Z'*
- `sim_card_4.dat`->  *ss-->Z'*
- `sim_card_5.dat`->  *bb-->Z'*

These simulations are combined with the incard data to calculate σ<sub>pred</sub>.

Since these simulations were peformed at leading order using the default tune in *MadGraph5_aMC@NLO*, the user can build alternative `sim_cards` customizing *PDF*, factorization scale, and other relevant parameters. See the README file inside `/TayloredPDFs/` for the instructions. 





For more information, please visit the associated publication <a href="https://arxiv.org/pdf/2005.05194.pdf" target=newwindow >*"Z'-explorer : a simple tool to probe Z' models against LHC data"*</a>.

