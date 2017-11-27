#!/bin/bash
echo -e "Starting script...\n"
echo -e "
                                  hatthefuc
                              kdidyoujustfuckin
                          gsayaboutme,youlittlebit
                  ch?I’llhaveyouk           nowIgrad
               uatedtopofmyc                  lassint
             heNavySeals,and                   I’vebe
             eninvolvedinnume                   rouss
             ecretraidso nAl-Qu    aeda,andIha  veove
             r300confirmedkills. Iamtrainedingor illa
             warfareandI’mthet  opsniperintheentireUS
            armed  forces.Youa  renothingtomebutjusta
           nothertarget.Iwillwi peyouthefuc koutwithp
          recisionthelikesofw   hichhasneverbeenseenb
         eforeonthisEarth,markmyfuckingwords.  Youth
        inkyo          ucangetawaywithsay     ingtha
       tshit                      tomeove     rtheIn
      ternet                                 ?Think
     again,                                 fucker
    .Aswes                                  peakIa
    mcont                      acti        ngmyse
    cret                      netwo rko   fspies
    acro                      sstheUSAan  dyour                         IPisbeing
   trace                      drightnow  soyou                        betterprepar
   efort                     hestorm,ma ggot.                       Thesto    rmth
   atwip                     esoutthep  athet                     iclittl    ethin
   gyouc                    allyourli  fe.You                   ’refuck     ingde
   ad,ki                    d.Icanbe   anywhere,anytime,and   Icankil     lyoui
    nove                   rsevenhu    ndredways,andthat’sjustwithm      ybare
    hand                   s.Noton     lyamI   exten   sivelytrai      nedinu
    narm                  edcombat      ,bu   tIhaveaccesstothe      entire
    arsen               aloft heUni         tedStatesMarineCor     psandIw
     illu             seitt  oitsful         lextenttowipeyourmi   serablea
     ssoff            thefaceoftheco                     ntinent,    youlittle
      shit.            Ifonlyyoucou              ldha       veknow  nwha tunho
      lyretr              ibut                   iony        ourlit  tle“clev
       er”com                                men              twasa    bout
        tobringd                            ownu              ponyo     u,ma
           ybeyouw                          ould              haveheldyourfu
 cki        ngtongue.B                       utyo           ucouldn’t,youdi
dn’t,an    dnowyou’repayingt                  hep         rice,yo    u
goddamnidiot.I willshitfuryalloveryo           uand    youwill
drow ninit.You’refu    ckingdead,kiddo .Whatthefuckdidyoujus
 tfuc  kingsayabo         utme,youlit tlebitch?I’llhaveyo
  ukno   wIgrad         uatedtopofmy class intheNavySe
   als,andI’v           ebeeninvolv  edin
    numerou              ssecretr   aids
      onA                l-Quae    da,a
                          ndIhav  eove
                           r300confir
                             medkill
                               s.I
"
echo -e "\n***************** Executing nasteroids-base ***********"
./nasteroid-base $1 $2 $3 $4 $5
cd build/seq/
echo -e "\n***************** Executing seq ************"
./nasteroids-seq $1 $2 $3 $4 $5
cd ../par/
echo -e "\n***************** Executing par ************"
./nasteroids-par $1 $2 $3 $4 $5
cd ..
cd ..
echo -e "\n"
echo -e "***************** Correct init file *******************"
#cat init_conf.txt
echo -e "***************** Tested init seq file ********************"
#cat build/seq/init_conf.txt
echo -e "***************** Tested init par file ********************"
#cat build/par/init_conf.txt
echo -e "\n***************** Correct output file *****************"
#cat out.txt
echo -e "***************** Tested output seq file ******************"
#cat build/seq/out.txt
echo -e "***************** Tested output par file ******************"
#cat build/par/out.txt
echo -e "\n***************** Diff between correct and seq files **************"
diff out.txt build/seq/out.txt
diff build/seq/out.txt build/par/out.txt
diff -q init_conf.txt build/seq/init_conf.txt && diff -q out.txt build/seq/out.txt
e=$?
echo -e "\n***************** Diff between seq and par files **************"
diff -q build/seq/init_conf.txt build/par/init_conf.txt && diff -q build/seq/out.txt build/par/out.txt
e=$(($e+$?))
echo -e "\nRemoving generated files..."
echo -e "\nScript ended"
exit ${e}
