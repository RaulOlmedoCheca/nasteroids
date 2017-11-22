#!/bin/bash
echo -e "Starting script...\n"
echo -e "
       m$$@$@@$@@$@@@,
                                      n@@@%@#jC](x @@@@#@?
                                   x@@%@$@x          ;@@@@@
                                 $@#@@@_ .             @@@@@@.
                         -Q@$@@@$$@                      @@@$@@
                      ($@@@%$@@$@@?.                     -@#@@@
                     @@@#@@#@@@W1$@                       x@@@@+
                    >@@@@@@&$&@$ @@|                       @@#@n
                    $@@@@@@@@@@z !@@i                      <@@$]
                    @@@@@@@$@@@  ,$@f         x@@$@Y}       !@%r
                    @@@@@@@$@    n#@]#@<    v@@@@@@@@@$?    ]@@c
                    @@@@@@@B?i-_v#@@@#@    $@@@@#@@$$i@@#   1@@[
                    {@@@&@@@@$%@#@@f      v@@@@@@@$@@  @@@U j@$x
                    @@@     J@@@@  Jc    j@@@@@@@$@#@  t$#@.C@$1
                   @$@L    x@%@@   ]@p   #@#$@@@@@@##  !@@@ #@@+
                   @@8     _@@$@@@@@$@<  #@@@@@$@@@B.   $@iY$@@
                 @@@@@@@@*(l     .       ~@@@@mI       %@  @$#@
                !@@@$@@@@@@@@@@@}l         @@@@@@@@@@@#h   @@@#
               _@@@( .I!p$@@@@@@@@@$@kJ       1&@$#@@@x   )@@@8
               ##@$          (tB@@$@@##@#$@ti             B#@#J
              z@#@_                    ;!;t###@@@U1      }@@@#
             r@#@?                                       #@$@n
             @@@@                                        @$@@
            >@@@L.                                      z@@@@
           ~$@@!                                       ]@@#@n
           @$@#                                        ##@&Q
          x@@@u                                        $@$@
         I@@#U                                        |@@@$
         (@@@.                          |@#          |@@$;
         [@@@                           @@@   @@<    @@@@
         n@@@                          U@@]  @@@J    @&@x                               1aqU>
         j@@@                          @@$>  @@@|   (@@@                              J@$W#@@@t
         J@@m                          @@}  z@@1   1@@@                             q@@$     @@M
         J@@x                          @$. {@@@.   @@@@                            $@@@      @@@.
         J@#Z                         v@$  @#@Z    @#@,                          Z@@$%       @@C
         J@@Y                         k$Z  @##    {@&@,                         }@@@@        @%
         J@@C                        f@]  >@@    i@@#n                         @@#@        i#@J
         J@@U                        @@  X@@@    t##@                        o@@@x         @@i
         J@@Y                        @@  @@@     z@@@  -*@#@@@@@@@@@J       Z$@@n        ~@@@
         z@@{                        @0 {@#~     f#@@@@@$@$@@@$@@@@@$@@    @@@@ .        @@C
         )#@$                       ;8 c@@&      j$$@l    ~jI      1w@@$@M#$@          @@@C
         !@@#                      +@! @@@       1%@#      @@@-       >%@@@          Z@#@>
          @@#                      ##  @$)         ,;      @#@/        @@]          !#@@*
          W@@                      @$  @&                  uUW8@@BQx>m$@z          #@$@L
          [@@)                   @@;    X@h            @@@@@@@%@#@@##$@@I        @@@@@j
           @@b                 #Z        U@]            !1/_,;_(rx##@@#@#@u     i###@U_
           ###]               @      [@t  .@v.                      .|%@#@@x       #@@@@L
           a@@@               #@@@@  @@@$ .@?                          {@@@@@         _i@$@
           <@@@!                 @@Lj@@.;@@                  @@          ##@$@           @$f
            >@@@~                 o@@@I                     Y@@           t#@@@   nY(  _x@#
             @@%@                  1[ .                      cY            @@@$   .(@@@$h
             W@@@z                                                         @@@@      @@I
               @@@@                                    /@@r                ?@@@       _@@
               .@@@@o                                  @@@c                X#$@        @@
                 d#@@@)                                $@                  }$#@        $@
                   @$@@@I                                                  @@#@@@f{l|[#@#.
                   @@@@#@@#I                           >@@@               p@@+Ijm@@@@@}
      @@@)        C@#[ ;U$@@%01                         . .             ]@@@>. .
     /@ }@#      @@@m    @@@@@@@@C<                                    @@@#
     /@( i@#m   n@#I   x@@} }@@@@@@@#@t|,                 ~@d        @@@$~
      0@   r@@[@@Z   }@@&     .  Xq@@@@@@@@@@n             YB     |&$$@
      (@U    #@@@   ?@@              iz#@@@$@@|  @@@@@&&nr?    )@@@@$ .
       $@     J;   @@@+                  C@$@;   $@@@@@@@@@@$@@#@@@
       @#        {$@@            ?t%dzi  @@#u   Y@@   -X0@@@$@@Y
        o@-    Y@@@ .            @$#$@@@@@$    ;$@?
         @@  +#@@[               @@@v##@@@Z    @@r
         i@@@@@@[                #@$#  n}      $@
           @@#@                  z@#@         @@x
                                  }@@@       @@]
                                   @@#B     >@@
                                   +@@@    }@@z
                                     @$@-  @@(
                                      L@$@@%;
                                      .U@@@.
"
echo -e "\n***************** Executing nasteroids-base ***********"
./nasteroid-base $1 $2 $3 $4 $5
echo -e "\n***************** Executing nasteroids-seq ************"
cd build
./nasteroids-seq $1 $2 $3 $4 $5
cp init_conf.txt ../init_conf_seq.txt
cp out.txt ../out_seq.txt
./nasteroids-par $1 $2 $3 $4 $5
cp init_conf.txt ../init_conf_par.txt
cp out.txt ../out_par.txt
cd ..
echo -e "\n"
echo -e "***************** Correct init file *******************"
cat init_conf.txt
echo -e "***************** Tested init seq file ********************"
cat init_conf_seq.txt
echo -e "***************** Tested init par file ********************"
cat init_conf_par.txt
echo -e "\n***************** Correct output file *****************"
cat out.txt
echo -e "***************** Tested output seq file ******************"
cat out_seq.txt
echo -e "***************** Tested output par file ******************"
cat out_par.txt
echo -e "\n***************** Diff between correct and seq files **************"
diff -q init_conf.txt init_conf_seq.txt && diff -q out.txt out_seq.txt
e=$?
echo -e "\n***************** Diff between seq and par files **************"
diff -q init_conf.txt init_conf_par.txt && diff -q out.txt out_par.txt
e=$?
echo -e "\nRemoving generated files..."
rm -rf build/
rm -rf out.txt
rm -rf init_conf.txt
echo -e "\nScript ended"
exit ${e}
