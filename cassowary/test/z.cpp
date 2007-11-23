#include "SimplexSolver.h"
#include "LinearEquation.h"
#include "LinearInequality.h"

void model( SimplexSolver & s) {
Variable v1V_7( "v1V_7" ); //[00_1.dL:7]
 s.AddStay(v1V_7);
Variable v2V_0( "v2V_0" ); //[00_1.подход1.dL:0]
 s.AddStay(v2V_0);
Variable v3V_25( "v3V_25" ); //[00_1.подход1.край.R:25]
 s.AddStay(v3V_25);
Variable v4V_7( "v4V_7" ); //[00_1.подход1.край.X:7]
 s.AddStay(v4V_7);
Variable v5V_1( "v5V_1" ); //[00_1.подход2.dL:1]
 s.AddStay(v5V_1);
Variable v6V_0( "v6V_0" ); //[00_1.подход2.край.X:0]
 s.AddStay(v6V_0);
Variable v7V_6( "v7V_6" ); //[00_1.остатък.dL:6]
 s.AddStay(v7V_6);
Variable v8V_16( "v8V_16" ); //[ляво чело_1.dL:16]
 s.AddStay(v8V_16);
Variable v9V_0_267949( "v9V_0_267949" ); //[ляво чело_1.подход1.dL:0.267949]
 s.AddStay(v9V_0_267949);
Variable v10V_2( "v10V_2" ); //[ляво чело_1.подход2.dL:2]
 s.AddStay(v10V_2);
Variable v11V_13_7321( "v11V_13_7321" ); //[ляво чело_1.остатък.dL:13.7321]
 s.AddStay(v11V_13_7321);
Variable v12V_12( "v12V_12" ); //[цилиндър_1.dL:12]
 s.AddStay(v12V_12);
Variable v13V_2( "v13V_2" ); //[цилиндър_1.подход1.dL:2]
 s.AddStay(v13V_2);
Variable v14V_41( "v14V_41" ); //[цилиндър_1.подход1.край.R:41]
 s.AddStay(v14V_41);
Variable v15V_0( "v15V_0" ); //[цилиндър_1.подход1.край.X:0]
 s.AddStay(v15V_0);
Variable v16V_0( "v16V_0" ); //[цилиндър_1.подход2.dL:0]
 s.AddStay(v16V_0);
Variable v17V_12( "v17V_12" ); //[цилиндър_1.подход2.край.X:12]
 s.AddStay(v17V_12);
Variable v18V_10( "v18V_10" ); //[цилиндър_1.остатък.dL:10]
 s.AddStay(v18V_10);
Variable v19V_3_5( "v19V_3_5" ); //[дясно чело_4.dL:3.5]
 s.AddStay(v19V_3_5);
Variable v20V_0( "v20V_0" ); //[дясно чело_4.подход1.dL:0]
 s.AddStay(v20V_0);
Variable v21V_0( "v21V_0" ); //[дясно чело_4.подход2.dL:0]
 s.AddStay(v21V_0);
Variable v22V_37_5( "v22V_37_5" ); //[дясно чело_4.подход2.край.R:37.5]
 s.AddStay(v22V_37_5);
Variable v23V_3_5( "v23V_3_5" ); //[дясно чело_4.остатък.dL:3.5]
 s.AddStay(v23V_3_5);
Variable v24V_2( "v24V_2" ); //[дясно чело_2.dL:2]
 s.AddStay(v24V_2);
Variable v25V_0( "v25V_0" ); //[дясно чело_2.подход1.dL:0]
 s.AddStay(v25V_0);
Variable v26V_1( "v26V_1" ); //[дясно чело_2.подход2.dL:1]
 s.AddStay(v26V_1);
Variable v27V_1( "v27V_1" ); //[дясно чело_2.остатък.dL:1]
 s.AddStay(v27V_1);
Variable v28V_2( "v28V_2" ); //[цилиндър_2.dL:2]
 s.AddStay(v28V_2);
Variable v29V_1( "v29V_1" ); //[цилиндър_2.подход1.dL:1]
 s.AddStay(v29V_1);
Variable v30V_35_5( "v30V_35_5" ); //[цилиндър_2.подход1.край.R:35.5]
 s.AddStay(v30V_35_5);
Variable v31V_12( "v31V_12" ); //[цилиндър_2.подход1.край.X:12]
 s.AddStay(v31V_12);
Variable v32V_0( "v32V_0" ); //[цилиндър_2.подход2.dL:0]
 s.AddStay(v32V_0);
Variable v33V_14( "v33V_14" ); //[цилиндър_2.подход2.край.X:14]
 s.AddStay(v33V_14);
Variable v34V_1( "v34V_1" ); //[цилиндър_2.остатък.dL:1]
 s.AddStay(v34V_1);
Variable v35V_2_82843( "v35V_2_82843" ); //[конус_1.dL:2.82843]
 s.AddStay(v35V_2_82843);
Variable v36V_2( "v36V_2" ); //[конус_1.dX:2]
 s.AddStay(v36V_2);
Variable v37V_2( "v37V_2" ); //[конус_1.dR:2]
 s.AddStay(v37V_2);
Variable v38V_0( "v38V_0" ); //[конус_1.подход1.dL:0]
 s.AddStay(v38V_0);
Variable v39V_0( "v39V_0" ); //[конус_1.подход2.dL:0]
 s.AddStay(v39V_0);
Variable v40V_2_82843( "v40V_2_82843" ); //[конус_1.остатък.dL:2.82843]
 s.AddStay(v40V_2_82843);
Variable v41V_25_5( "v41V_25_5" ); //[цилиндър_3.dL:25.5]
 s.AddStay(v41V_25_5);
Variable v42V_0( "v42V_0" ); //[цилиндър_3.подход1.dL:0]
 s.AddStay(v42V_0);
Variable v43V_37_5( "v43V_37_5" ); //[цилиндър_3.подход1.край.R:37.5]
 s.AddStay(v43V_37_5);
Variable v44V_16( "v44V_16" ); //[цилиндър_3.подход1.край.X:16]
 s.AddStay(v44V_16);
Variable v45V_0( "v45V_0" ); //[цилиндър_3.подход2.dL:0]
 s.AddStay(v45V_0);
Variable v46V_41_5( "v46V_41_5" ); //[цилиндър_3.подход2.край.X:41.5]
 s.AddStay(v46V_41_5);
Variable v47V_25_5( "v47V_25_5" ); //[цилиндър_3.остатък.dL:25.5]
 s.AddStay(v47V_25_5);
Variable v48V_3_53553( "v48V_3_53553" ); //[конус_2.dL:3.53553]
 s.AddStay(v48V_3_53553);
Variable v49V_2_5( "v49V_2_5" ); //[конус_2.dX:2.5]
 s.AddStay(v49V_2_5);
Variable v50V__2_5( "v50V__2_5" ); //[конус_2.dR:-2.5]
 s.AddStay(v50V__2_5);
Variable v51V_0( "v51V_0" ); //[конус_2.подход1.dL:0]
 s.AddStay(v51V_0);
Variable v52V_0( "v52V_0" ); //[конус_2.подход2.dL:0]
 s.AddStay(v52V_0);
Variable v53V_35( "v53V_35" ); //[конус_2.подход2.край.R:35]
 s.AddStay(v53V_35);
Variable v54V_44( "v54V_44" ); //[конус_2.подход2.край.X:44]
 s.AddStay(v54V_44);
Variable v55V_3_53553( "v55V_3_53553" ); //[конус_2.остатък.dL:3.53553]
 s.AddStay(v55V_3_53553);
Variable v56V_0( "v56V_0" ); //[дясно чело_3.dL:0]
 s.AddStay(v56V_0);
Variable v57V_0( "v57V_0" ); //[дясно чело_3.подход1.dL:0]
 s.AddStay(v57V_0);
Variable v58V_0( "v58V_0" ); //[дясно чело_3.подход2.dL:0]
 s.AddStay(v58V_0);
Variable v59V_0( "v59V_0" ); //[дясно чело_3.остатък.dL:0]
 s.AddStay(v59V_0);
Variable v60V_13( "v60V_13" ); //[цилиндър_4.dL:13]
 s.AddStay(v60V_13);
Variable v61V_0( "v61V_0" ); //[цилиндър_4.подход1.dL:0]
 s.AddStay(v61V_0);
Variable v62V_35( "v62V_35" ); //[цилиндър_4.подход1.край.R:35]
 s.AddStay(v62V_35);
Variable v63V_44( "v63V_44" ); //[цилиндър_4.подход1.край.X:44]
 s.AddStay(v63V_44);
Variable v64V_0( "v64V_0" ); //[цилиндър_4.подход2.dL:0]
 s.AddStay(v64V_0);
Variable v65V_57( "v65V_57" ); //[цилиндър_4.подход2.край.X:57]
 s.AddStay(v65V_57);
Variable v66V_13( "v66V_13" ); //[цилиндър_4.остатък.dL:13]
 s.AddStay(v66V_13);
Variable v67V_0_1( "v67V_0_1" ); //[дясно чело_5.dL:0.1]
 s.AddStay(v67V_0_1);
Variable v68V_0( "v68V_0" ); //[дясно чело_5.подход1.dL:0]
 s.AddStay(v68V_0);
Variable v69V_0( "v69V_0" ); //[дясно чело_5.подход2.dL:0]
 s.AddStay(v69V_0);
Variable v70V_0_1( "v70V_0_1" ); //[дясно чело_5.остатък.dL:0.1]
 s.AddStay(v70V_0_1);
Variable v71V_8( "v71V_8" ); //[цилиндър_5.dL:8]
 s.AddStay(v71V_8);
Variable v72V_0( "v72V_0" ); //[цилиндър_5.подход1.dL:0]
 s.AddStay(v72V_0);
Variable v73V_34_9( "v73V_34_9" ); //[цилиндър_5.подход1.край.R:34.9]
 s.AddStay(v73V_34_9);
Variable v74V_57( "v74V_57" ); //[цилиндър_5.подход1.край.X:57]
 s.AddStay(v74V_57);
Variable v75V_0( "v75V_0" ); //[цилиндър_5.подход2.dL:0]
 s.AddStay(v75V_0);
Variable v76V_65( "v76V_65" ); //[цилиндър_5.подход2.край.X:65]
 s.AddStay(v76V_65);
Variable v77V_0( "v77V_0" ); //[цилиндър_5.остатък.dL:0]
 s.AddStay(v77V_0);
Variable v78V_7_07107( "v78V_7_07107" ); //[конус_3.dL:7.07107]
 s.AddStay(v78V_7_07107);
Variable v79V_5( "v79V_5" ); //[конус_3.dX:5]
 s.AddStay(v79V_5);
Variable v80V__5( "v80V__5" ); //[конус_3.dR:-5]
 s.AddStay(v80V__5);
Variable v81V_0( "v81V_0" ); //[конус_3.подход1.dL:0]
 s.AddStay(v81V_0);
Variable v82V_0( "v82V_0" ); //[конус_3.подход2.dL:0]
 s.AddStay(v82V_0);
Variable v83V_29_9( "v83V_29_9" ); //[конус_3.подход2.край.R:29.9]
 s.AddStay(v83V_29_9);
Variable v84V_70( "v84V_70" ); //[конус_3.подход2.край.X:70]
 s.AddStay(v84V_70);
Variable v85V_7_07107( "v85V_7_07107" ); //[конус_3.остатък.dL:7.07107]
 s.AddStay(v85V_7_07107);
Variable v86V_9_9( "v86V_9_9" ); //[дясно чело_1.dL:9.9]
 s.AddStay(v86V_9_9);
Variable v87V_0( "v87V_0" ); //[дясно чело_1.подход1.dL:0]
 s.AddStay(v87V_0);
Variable v88V_1_5( "v88V_1_5" ); //[дясно чело_1.подход2.dL:1.5]
 s.AddStay(v88V_1_5);
Variable v89V_8_4( "v89V_8_4" ); //[дясно чело_1.остатък.dL:8.4]
 s.AddStay(v89V_8_4);
Variable v90V_47_6( "v90V_47_6" ); //[цил_отвор_2.dL:47.6]
 s.AddStay(v90V_47_6);
Variable v91V_1_5( "v91V_1_5" ); //[цил_отвор_2.подход1.dL:1.5]
 s.AddStay(v91V_1_5);
Variable v92V_20( "v92V_20" ); //[цил_отвор_2.подход1.край.R:20]
 s.AddStay(v92V_20);
Variable v93V_70( "v93V_70" ); //[цил_отвор_2.подход1.край.X:70]
 s.AddStay(v93V_70);
Variable v94V_0( "v94V_0" ); //[цил_отвор_2.подход2.dL:0]
 s.AddStay(v94V_0);
Variable v95V_22_4( "v95V_22_4" ); //[цил_отвор_2.подход2.край.X:22.4]
 s.AddStay(v95V_22_4);
Variable v96V_46_1( "v96V_46_1" ); //[цил_отвор_2.остатък.dL:46.1]
 s.AddStay(v96V_46_1);
Variable v97V_0( "v97V_0" ); //[ляво чело_3.dL:0]
 s.AddStay(v97V_0);
Variable v98V_0( "v98V_0" ); //[ляво чело_3.подход1.dL:0]
 s.AddStay(v98V_0);
Variable v99V_0( "v99V_0" ); //[ляво чело_3.подход2.dL:0]
 s.AddStay(v99V_0);
Variable v100V_0( "v100V_0" ); //[ляво чело_3.остатък.dL:0]
 s.AddStay(v100V_0);
Variable v101V_15_4( "v101V_15_4" ); //[цил_отвор_3.dL:15.4]
 s.AddStay(v101V_15_4);
Variable v102V_0( "v102V_0" ); //[цил_отвор_3.подход1.dL:0]
 s.AddStay(v102V_0);
Variable v103V_20( "v103V_20" ); //[цил_отвор_3.подход1.край.R:20]
 s.AddStay(v103V_20);
Variable v104V_22_4( "v104V_22_4" ); //[цил_отвор_3.подход1.край.X:22.4]
 s.AddStay(v104V_22_4);
Variable v105V_0( "v105V_0" ); //[цил_отвор_3.подход2.dL:0]
 s.AddStay(v105V_0);
Variable v106V_7( "v106V_7" ); //[цил_отвор_3.подход2.край.X:7]
 s.AddStay(v106V_7);
Variable v107V_0( "v107V_0" ); //[цил_отвор_3.остатък.dL:0]
 s.AddStay(v107V_0);
Variable v108V_5( "v108V_5" ); //[ляво чело_2.dL:5]
 s.AddStay(v108V_5);
Variable v109V_0( "v109V_0" ); //[ляво чело_2.подход1.dL:0]
 s.AddStay(v109V_0);
Variable v110V_0( "v110V_0" ); //[ляво чело_2.подход2.dL:0]
 s.AddStay(v110V_0);
Variable v111V_5( "v111V_5" ); //[ляво чело_2.остатък.dL:5]
 s.AddStay(v111V_5);
Variable v112V_0( "v112V_0" ); //[00_1.превкл1.изх_към.dL:0]
 s.AddStay(v112V_0);
Variable v113V_25( "v113V_25" ); //[00_1.превкл1.изх_към.край.R:25]
 s.AddStay(v113V_25);
Variable v114V_1( "v114V_1" ); //[00_1.превкл1.изх_към.край.X:1]
 s.AddStay(v114V_1);
Variable v115V_0( "v115V_0" ); //[00_1.превкл1.място.dL:0]
 s.AddStay(v115V_0);
Variable v116V_0( "v116V_0" ); //[00_1.превкл1.вход_от.dL:0]
 s.AddStay(v116V_0);
Variable v117V_25( "v117V_25" ); //[00_1.превкл1.вход_от.край.R:25]
 s.AddStay(v117V_25);
Variable v118V_1( "v118V_1" ); //[00_1.превкл1.вход_от.край.X:1]
 s.AddStay(v118V_1);
Variable v119V_0( "v119V_0" ); //[00_1.превкл1.остатък.dL:0]
 s.AddStay(v119V_0);
Variable v120V_0( "v120V_0" ); //[цилиндър_5.превкл1.изх_към.dL:0]
 s.AddStay(v120V_0);
Variable v121V_4( "v121V_4" ); //[цилиндър_5.превкл1.място.dL:4]
 s.AddStay(v121V_4);
Variable v122V_0( "v122V_0" ); //[цилиндър_5.превкл1.вход_от.dL:0]
 s.AddStay(v122V_0);
Variable v123V_4( "v123V_4" ); //[цилиндър_5.превкл1.остатък.dL:4]
 s.AddStay(v123V_4);
Variable v124V_0( "v124V_0" ); //[цил_отвор_3.превкл1.изх_към.dL:0]
 s.AddStay(v124V_0);
Variable v125V_6_4( "v125V_6_4" ); //[цил_отвор_3.превкл1.място.dL:6.4]
 s.AddStay(v125V_6_4);
Variable v126V_0( "v126V_0" ); //[цил_отвор_3.превкл1.вход_от.dL:0]
 s.AddStay(v126V_0);
Variable v127V_9( "v127V_9" ); //[цил_отвор_3.превкл1.остатък.dL:9]
 s.AddStay(v127V_9);
Variable v128V_2_35( "v128V_2_35" ); //[цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.dL:2.35]
 s.AddStay(v128V_2_35);
Variable v129V_0( "v129V_0" ); //[цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход1.dL:0]
 s.AddStay(v129V_0);
Variable v130V_34_9( "v130V_34_9" ); //[цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход1.край.R:34.9]
 s.AddStay(v130V_34_9);
Variable v131V_57( "v131V_57" ); //[цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход1.край.X:57]
 s.AddStay(v131V_57);
Variable v132V_0_2( "v132V_0_2" ); //[цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход2.dL:0.2]
 s.AddStay(v132V_0_2);
Variable v133V_2_15( "v133V_2_15" ); //[цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.остатък.dL:2.15]
 s.AddStay(v133V_2_15);
Variable v134V_4( "v134V_4" ); //[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.dL:4]
 s.AddStay(v134V_4);
Variable v135V_0_2( "v135V_0_2" ); //[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.dL:0.2]
 s.AddStay(v135V_0_2);
Variable v136V_32_55( "v136V_32_55" ); //[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край.R:32.55]
 s.AddStay(v136V_32_55);
Variable v137V_57( "v137V_57" ); //[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край.X:57]
 s.AddStay(v137V_57);
Variable v138V_0_2( "v138V_0_2" ); //[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход2.dL:0.2]
 s.AddStay(v138V_0_2);
Variable v139V_61( "v139V_61" ); //[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход2.край.X:61]
 s.AddStay(v139V_61);
Variable v140V_3_6( "v140V_3_6" ); //[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.остатък.dL:3.6]
 s.AddStay(v140V_3_6);
Variable v141V_2_35( "v141V_2_35" ); //[цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.dL:2.35]
 s.AddStay(v141V_2_35);
Variable v142V_0_2( "v142V_0_2" ); //[цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.подход1.dL:0.2]
 s.AddStay(v142V_0_2);
Variable v143V_0( "v143V_0" ); //[цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.подход2.dL:0]
 s.AddStay(v143V_0);
Variable v144V_34_9( "v144V_34_9" ); //[цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.подход2.край.R:34.9]
 s.AddStay(v144V_34_9);
Variable v145V_2_15( "v145V_2_15" ); //[цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.остатък.dL:2.15]
 s.AddStay(v145V_2_15);
Variable v146V_4( "v146V_4" ); //[цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.dL:4]
 s.AddStay(v146V_4);
Variable v147V_0( "v147V_0" ); //[цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход1.dL:0]
 s.AddStay(v147V_0);
Variable v148V_20( "v148V_20" ); //[цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход1.край.R:20]
 s.AddStay(v148V_20);
Variable v149V_22_4( "v149V_22_4" ); //[цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход1.край.X:22.4]
 s.AddStay(v149V_22_4);
Variable v150V_0( "v150V_0" ); //[цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход2.dL:0]
 s.AddStay(v150V_0);
Variable v151V_4( "v151V_4" ); //[цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.остатък.dL:4]
 s.AddStay(v151V_4);
Variable v152V_6_4( "v152V_6_4" ); //[цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.dL:6.4]
 s.AddStay(v152V_6_4);
Variable v153V_0( "v153V_0" ); //[цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1.dL:0]
 s.AddStay(v153V_0);
Variable v154V_24( "v154V_24" ); //[цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1.край.R:24]
 s.AddStay(v154V_24);
Variable v155V_22_4( "v155V_22_4" ); //[цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1.край.X:22.4]
 s.AddStay(v155V_22_4);
Variable v156V_0( "v156V_0" ); //[цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход2.dL:0]
 s.AddStay(v156V_0);
Variable v157V_16( "v157V_16" ); //[цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход2.край.X:16]
 s.AddStay(v157V_16);
Variable v158V_6_4( "v158V_6_4" ); //[цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.остатък.dL:6.4]
 s.AddStay(v158V_6_4);
Variable v159V_4( "v159V_4" ); //[цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.dL:4]
 s.AddStay(v159V_4);
Variable v160V_0( "v160V_0" ); //[цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.подход1.dL:0]
 s.AddStay(v160V_0);
Variable v161V_0( "v161V_0" ); //[цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.подход2.dL:0]
 s.AddStay(v161V_0);
Variable v162V_20( "v162V_20" ); //[цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.подход2.край.R:20]
 s.AddStay(v162V_20);
Variable v163V_4( "v163V_4" ); //[цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.остатък.dL:4]
 s.AddStay(v163V_4);
Variable v164V_1_03528( "v164V_1_03528" ); //[00_1.подход2.край.преход.фаска-Алт1.dL:1.03528]
 s.AddStay(v164V_1_03528);
Variable v165V_1( "v165V_1" ); //[00_1.подход2.край.преход.фаска-Алт1.dL1:1]
 s.AddStay(v165V_1);
Variable v166V_0_267949( "v166V_0_267949" ); //[00_1.подход2.край.преход.фаска-Алт1.dL2:0.267949]
 s.AddStay(v166V_0_267949);
Variable v167V_2_82843( "v167V_2_82843" ); //[цилиндър_1.подход1.край.преход.фаска-Алт2.dL:2.82843]
 s.AddStay(v167V_2_82843);
Variable v168V_2( "v168V_2" ); //[цилиндър_1.подход1.край.преход.фаска-Алт2.dL1:2]
 s.AddStay(v168V_2);
Variable v169V_2( "v169V_2" ); //[цилиндър_1.подход1.край.преход.фаска-Алт2.dL2:2]
 s.AddStay(v169V_2);
Variable v170V_1( "v170V_1" ); //[цилиндър_2.подход1.край.преход.закръгление-Алт1.r:1]
 s.AddStay(v170V_1);
Variable v171V_2_12132( "v171V_2_12132" ); //[цил_отвор_2.подход1.край.преход.фаска-Алт1.dL:2.12132]
 s.AddStay(v171V_2_12132);
Variable v172V_1_5( "v172V_1_5" ); //[цил_отвор_2.подход1.край.преход.фаска-Алт1.dL1:1.5]
 s.AddStay(v172V_1_5);
Variable v173V_1_5( "v173V_1_5" ); //[цил_отвор_2.подход1.край.преход.фаска-Алт1.dL2:1.5]
 s.AddStay(v173V_1_5);
Variable v174V_0_2( "v174V_0_2" ); //[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край.преход.закръгление-Алт1.r:0.2]
 s.AddStay(v174V_0_2);
Variable v175V_0_2( "v175V_0_2" ); //[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход2.край.преход.закръгление-Алт1.r:0.2]
 s.AddStay(v175V_0_2);
Variable v176V_0( "v176V_0" ); //[размери.размер_dR_2.v:0]
 s.AddStay(v176V_0);
Variable v177V_13( "v177V_13" ); //[размери.размер_dX_1.v:13]
 s.AddStay(v177V_13);
Variable v178V_26( "v178V_26" ); //[размери.размер_dX_2.v:26]
 s.AddStay(v178V_26);
Variable v179V_58( "v179V_58" ); //[размери.размер_dX_3.v:58]
 s.AddStay(v179V_58);
Variable v180V_70( "v180V_70" ); //[размери.размер_dX_4.v:70]
 s.AddStay(v180V_70);
Variable v181V_4( "v181V_4" ); //[размери.размер_dX_5.v:4]
 s.AddStay(v181V_4);
Variable v182V_75( "v182V_75" ); //[размери.резбаD_1.v_input:75]
 s.AddStay(v182V_75);
Variable v183V_0( "v183V_0" ); //[размери.размер_dX_8.v:0]
 s.AddStay(v183V_0);
Variable v184V_0( "v184V_0" ); //[размери.размер_dX_10.v:0]
 s.AddStay(v184V_0);
Variable v185V_22_4( "v185V_22_4" ); //[размери.размер_dX_11.v:22.4]
 s.AddStay(v185V_22_4);
s.AddConstraint( new LinearEquation( LinearExpression( -0.707107*v39V_0 + 1*v43V_37_5), 1*v30V_35_5 + 0.707107*v38V_0 + 0.707107*v40V_2_82843)); //= Eq(-0.707107*[конус_1.подход2.dL:0] + 1*[цилиндър_3.подход1.край.R:37.5],1*[цилиндър_2.подход1.край.R:35.5] + 0.707107*[конус_1.подход1.dL:0] + 0.707107*[конус_1.остатък.dL:2.82843],) sent,by koren.конус_1
s.AddConstraint( new LinearEquation( LinearExpression( -0.707107*v39V_0 + 1*v44V_16), 0.707107*v38V_0 + 1*v33V_14 + 0.707107*v40V_2_82843)); //= Eq(-0.707107*[конус_1.подход2.dL:0] + 1*[цилиндър_3.подход1.край.X:16],0.707107*[конус_1.подход1.dL:0] + 1*[цилиндър_2.подход2.край.X:14] + 0.707107*[конус_1.остатък.dL:2.82843],) sent,by koren.конус_1
s.AddConstraint( new LinearEquation( LinearExpression( -0.707107*v82V_0 + 1*v84V_70), 0.707107*v81V_0 + 0.707107*v85V_7_07107 + 1*v76V_65)); //= Eq(-0.707107*[конус_3.подход2.dL:0] + 1*[конус_3.подход2.край.X:70],0.707107*[конус_3.подход1.dL:0] + 0.707107*[конус_3.остатък.dL:7.07107] + 1*[цилиндър_5.подход2.край.X:65],) sent,by koren.конус_3
s.AddConstraint( new LinearEquation( LinearExpression( -1*v86V_9_9), -1*v83V_29_9 + 1*v92V_20)); //= Eq(-1*[дясно чело_1.dL:9.9],-1*[конус_3.подход2.край.R:29.9] + 1*[цил_отвор_2.подход1.край.R:20],) sent,by koren.дясно чело_1
s.AddConstraint( new LinearEquation( LinearExpression( -1*v24V_2), -1*v22V_37_5 + 1*v30V_35_5)); //= Eq(-1*[дясно чело_2.dL:2],-1*[дясно чело_4.подход2.край.R:37.5] + 1*[цилиндър_2.подход1.край.R:35.5],) sent,by koren.дясно чело_2
s.AddConstraint( new LinearEquation( LinearExpression( -1*v56V_0), 1*v62V_35 + -1*v53V_35)); //= Eq(-1*[дясно чело_3.dL:0],1*[цилиндър_4.подход1.край.R:35] + -1*[конус_2.подход2.край.R:35],) sent,by koren.дясно чело_3
s.AddConstraint( new LinearEquation( LinearExpression( -1*v19V_3_5), 1*v22V_37_5 + -1*v14V_41)); //= Eq(-1*[дясно чело_4.dL:3.5],1*[дясно чело_4.подход2.край.R:37.5] + -1*[цилиндър_1.подход1.край.R:41],) sent,by koren.дясно чело_4
s.AddConstraint( new LinearEquation( LinearExpression( -1*v67V_0_1), -1*v62V_35 + 1*v73V_34_9)); //= Eq(-1*[дясно чело_5.dL:0.1],-1*[цилиндър_4.подход1.край.R:35] + 1*[цилиндър_5.подход1.край.R:34.9],) sent,by koren.дясно чело_5
s.AddConstraint( new LinearEquation( LinearExpression( -1*v10V_2 + 1*v14V_41), 1*v9V_0_267949 + 1*v11V_13_7321 + 1*v3V_25)); //= Eq(-1*[ляво чело_1.подход2.dL:2] + 1*[цилиндър_1.подход1.край.R:41],1*[ляво чело_1.подход1.dL:0.267949] + 1*[ляво чело_1.остатък.dL:13.7321] + 1*[00_1.подход1.край.R:25],) sent,by koren.ляво чело_1
s.AddConstraint( new LinearEquation( LinearExpression( -1*v159V_4), -1*v154V_24 + 1*v162V_20)); //= Eq(-1*[цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.dL:4],-1*[цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1.край.R:24] + 1*[цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.подход2.край.R:20],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2
s.AddConstraint( new LinearEquation( LinearExpression( -1*v150V_0 + 1*v154V_24), 1*v151V_4 + 1*v147V_0 + 1*v148V_20)); //= Eq(-1*[цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход2.dL:0] + 1*[цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1.край.R:24],1*[цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.остатък.dL:4] + 1*[цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход1.dL:0] + 1*[цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход1.край.R:20],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2
s.AddConstraint( new LinearEquation( LinearExpression( -1*v16V_0 + 1*v17V_12), 1*v15V_0 + 1*v13V_2 + 1*v18V_10)); //= Eq(-1*[цилиндър_1.подход2.dL:0] + 1*[цилиндър_1.подход2.край.X:12],1*[цилиндър_1.подход1.край.X:0] + 1*[цилиндър_1.подход1.dL:2] + 1*[цилиндър_1.остатък.dL:10],) sent,by koren.цилиндър_1
s.AddConstraint( new LinearEquation( LinearExpression( -1*v32V_0 + 1*v33V_14), 1*v29V_1 + 1*v34V_1 + 1*v31V_12)); //= Eq(-1*[цилиндър_2.подход2.dL:0] + 1*[цилиндър_2.подход2.край.X:14],1*[цилиндър_2.подход1.dL:1] + 1*[цилиндър_2.остатък.dL:1] + 1*[цилиндър_2.подход1.край.X:12],) sent,by koren.цилиндър_2
s.AddConstraint( new LinearEquation( LinearExpression( -1*v128V_2_35), 1*v136V_32_55 + -1*v130V_34_9)); //= Eq(-1*[цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.dL:2.35],1*[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край.R:32.55] + -1*[цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход1.край.R:34.9],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2
s.AddConstraint( new LinearEquation( LinearExpression( 0.258819*v5V_1), 0.965926*v9V_0_267949)); //= Eq(0.258819*[00_1.подход2.dL:1],0.965926*[ляво чело_1.подход1.dL:0.267949],) sent,by koren.00_1.подход2.край.преход.фаска-Алт1
s.AddConstraint( new LinearEquation( LinearExpression( 0.707107*v88V_1_5), 0.707107*v91V_1_5)); //= Eq(0.707107*[дясно чело_1.подход2.dL:1.5],0.707107*[цил_отвор_2.подход1.dL:1.5],) sent,by koren.цил_отвор_2.подход1.край.преход.фаска-Алт1
s.AddConstraint( new LinearEquation( LinearExpression( 0.707107*v82V_0 + 1*v83V_29_9), -0.707107*v81V_0 + -0.707107*v85V_7_07107 + 1*v73V_34_9)); //= Eq(0.707107*[конус_3.подход2.dL:0] + 1*[конус_3.подход2.край.R:29.9],-0.707107*[конус_3.подход1.dL:0] + -0.707107*[конус_3.остатък.dL:7.07107] + 1*[цилиндър_5.подход1.край.R:34.9],) sent,by koren.конус_3
s.AddConstraint( new LinearEquation( LinearExpression( 0.707107*v10V_2), 0.707107*v13V_2)); //= Eq(0.707107*[ляво чело_1.подход2.dL:2],0.707107*[цилиндър_1.подход1.dL:2],) sent,by koren.цилиндър_1.подход1.край.преход.фаска-Алт2
s.AddConstraint( new LinearEquation( LinearExpression( 1*v3V_25 + -1*v110V_0), 1*v103V_20 + 1*v109V_0 + 1*v111V_5)); //= Eq(1*[00_1.подход1.край.R:25] + -1*[ляво чело_2.подход2.dL:0],1*[цил_отвор_3.подход1.край.R:20] + 1*[ляво чело_2.подход1.dL:0] + 1*[ляво чело_2.остатък.dL:5],) sent,by koren.ляво чело_2
s.AddConstraint( new LinearEquation( LinearExpression( 1*v3V_25), 1*v117V_25)); //= Eq(1*[00_1.подход1.край.R:25],1*[00_1.превкл1.вход_от.край.R:25],) sent,by koren.00_1
s.AddConstraint( new LinearEquation( LinearExpression( 1*v4V_7), 1*v106V_7)); //= Eq(1*[00_1.подход1.край.X:7],1*[цил_отвор_3.подход2.край.X:7],) sent,by koren.ляво чело_2
s.AddConstraint( new LinearEquation( LinearExpression( 1*v6V_0 + 1*v5V_1), -1*v119V_0 + -1*v116V_0 + 1*v118V_1)); //= Eq(1*[00_1.подход2.край.X:0] + 1*[00_1.подход2.dL:1],-1*[00_1.превкл1.остатък.dL:0] + -1*[00_1.превкл1.вход_от.dL:0] + 1*[00_1.превкл1.вход_от.край.X:1],) sent,by koren.00_1
s.AddConstraint( new LinearEquation( LinearExpression( 1*v112V_0 + 1*v114V_1), 1*v4V_7 + -1*v7V_6 + -1*v2V_0)); //= Eq(1*[00_1.превкл1.изх_към.dL:0] + 1*[00_1.превкл1.изх_към.край.X:1],1*[00_1.подход1.край.X:7] + -1*[00_1.остатък.dL:6] + -1*[00_1.подход1.dL:0],) sent,by koren.00_1
s.AddConstraint( new LinearEquation( LinearExpression( 1*v113V_25), 1*v3V_25)); //= Eq(1*[00_1.превкл1.изх_към.край.R:25],1*[00_1.подход1.край.R:25],) sent,by koren.00_1
s.AddConstraint( new LinearEquation( LinearExpression( 1*v22V_37_5 + 1*v21V_0), -1*v20V_0 + 1*v14V_41 + -1*v23V_3_5)); //= Eq(1*[дясно чело_4.подход2.край.R:37.5] + 1*[дясно чело_4.подход2.dL:0],-1*[дясно чело_4.подход1.dL:0] + 1*[цилиндър_1.подход1.край.R:41] + -1*[дясно чело_4.остатък.dL:3.5],) sent,by koren.дясно чело_4
s.AddConstraint( new LinearEquation( LinearExpression( 1*v69V_0 + 1*v73V_34_9), 1*v62V_35 + -1*v70V_0_1 + -1*v68V_0)); //= Eq(1*[дясно чело_5.подход2.dL:0] + 1*[цилиндър_5.подход1.край.R:34.9],1*[цилиндър_4.подход1.край.R:35] + -1*[дясно чело_5.остатък.dL:0.1] + -1*[дясно чело_5.подход1.dL:0],) sent,by koren.дясно чело_5
s.AddConstraint( new LinearEquation( LinearExpression( 1*v53V_35 + 0.707107*v52V_0), -0.707107*v51V_0 + 1*v43V_37_5 + -0.707107*v55V_3_53553)); //= Eq(1*[конус_2.подход2.край.R:35] + 0.707107*[конус_2.подход2.dL:0],-0.707107*[конус_2.подход1.dL:0] + 1*[цилиндър_3.подход1.край.R:37.5] + -0.707107*[конус_2.остатък.dL:3.53553],) sent,by koren.конус_2
s.AddConstraint( new LinearEquation( LinearExpression( 1*v54V_44 + -0.707107*v52V_0), 0.707107*v51V_0 + 1*v46V_41_5 + 0.707107*v55V_3_53553)); //= Eq(1*[конус_2.подход2.край.X:44] + -0.707107*[конус_2.подход2.dL:0],0.707107*[конус_2.подход1.dL:0] + 1*[цилиндър_3.подход2.край.X:41.5] + 0.707107*[конус_2.остатък.dL:3.53553],) sent,by koren.конус_2
s.AddConstraint( new LinearEquation( LinearExpression( 1*v9V_0_267949), 0.258819*v164V_1_03528)); //= Eq(1*[ляво чело_1.подход1.dL:0.267949],0.258819*[00_1.подход2.край.преход.фаска-Алт1.dL:1.03528],) sent,by koren.00_1.подход2.край.преход.фаска-Алт1
s.AddConstraint( new LinearEquation( LinearExpression( 1*v91V_1_5), 0.707107*v171V_2_12132)); //= Eq(1*[цил_отвор_2.подход1.dL:1.5],0.707107*[цил_отвор_2.подход1.край.преход.фаска-Алт1.dL:2.12132],) sent,by koren.цил_отвор_2.подход1.край.преход.фаска-Алт1
s.AddConstraint( new LinearEquation( LinearExpression( 1*v92V_20 + 1*v88V_1_5), 1*v83V_29_9 + -1*v87V_0 + -1*v89V_8_4)); //= Eq(1*[цил_отвор_2.подход1.край.R:20] + 1*[дясно чело_1.подход2.dL:1.5],1*[конус_3.подход2.край.R:29.9] + -1*[дясно чело_1.подход1.dL:0] + -1*[дясно чело_1.остатък.dL:8.4],) sent,by koren.дясно чело_1
s.AddConstraint( new LinearEquation( LinearExpression( 1*v93V_70), 1*v84V_70)); //= Eq(1*[цил_отвор_2.подход1.край.X:70],1*[конус_3.подход2.край.X:70],) sent,by koren.дясно чело_1
s.AddConstraint( new LinearEquation( LinearExpression( 1*v95V_22_4 + 1*v94V_0), -1*v91V_1_5 + 1*v93V_70 + -1*v96V_46_1)); //= Eq(1*[цил_отвор_2.подход2.край.X:22.4] + 1*[цил_отвор_2.подход2.dL:0],-1*[цил_отвор_2.подход1.dL:1.5] + 1*[цил_отвор_2.подход1.край.X:70] + -1*[цил_отвор_2.остатък.dL:46.1],) sent,by koren.цил_отвор_2
s.AddConstraint( new LinearEquation( LinearExpression( 1*v103V_20 + -1*v99V_0), 1*v98V_0 + 1*v92V_20 + 1*v100V_0)); //= Eq(1*[цил_отвор_3.подход1.край.R:20] + -1*[ляво чело_3.подход2.dL:0],1*[ляво чело_3.подход1.dL:0] + 1*[цил_отвор_2.подход1.край.R:20] + 1*[ляво чело_3.остатък.dL:0],) sent,by koren.ляво чело_3
s.AddConstraint( new LinearEquation( LinearExpression( 1*v103V_20), 1*v162V_20)); //= Eq(1*[цил_отвор_3.подход1.край.R:20],1*[цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.подход2.край.R:20],) sent,by koren.цил_отвор_3
s.AddConstraint( new LinearEquation( LinearExpression( 1*v104V_22_4), 1*v95V_22_4)); //= Eq(1*[цил_отвор_3.подход1.край.X:22.4],1*[цил_отвор_2.подход2.край.X:22.4],) sent,by koren.ляво чело_3
s.AddConstraint( new LinearEquation( LinearExpression( 1*v105V_0 + 1*v106V_7), -1*v127V_9 + -1*v126V_0 + 1*v157V_16)); //= Eq(1*[цил_отвор_3.подход2.dL:0] + 1*[цил_отвор_3.подход2.край.X:7],-1*[цил_отвор_3.превкл1.остатък.dL:9] + -1*[цил_отвор_3.превкл1.вход_от.dL:0] + 1*[цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход2.край.X:16],) sent,by koren.цил_отвор_3
s.AddConstraint( new LinearEquation( LinearExpression( 1*v162V_20 + 1*v161V_0), 1*v154V_24 + -1*v163V_4 + -1*v160V_0)); //= Eq(1*[цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.подход2.край.R:20] + 1*[цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.подход2.dL:0],1*[цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1.край.R:24] + -1*[цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.остатък.dL:4] + -1*[цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.подход1.dL:0],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2
s.AddConstraint( new LinearEquation( LinearExpression( 1*v148V_20), 1*v103V_20)); //= Eq(1*[цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход1.край.R:20],1*[цил_отвор_3.подход1.край.R:20],) sent,by koren.цил_отвор_3
s.AddConstraint( new LinearEquation( LinearExpression( 1*v155V_22_4), 1*v149V_22_4)); //= Eq(1*[цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1.край.X:22.4],1*[цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход1.край.X:22.4],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2
s.AddConstraint( new LinearEquation( LinearExpression( 1*v156V_0 + 1*v157V_16), -1*v153V_0 + 1*v155V_22_4 + -1*v158V_6_4)); //= Eq(1*[цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход2.dL:0] + 1*[цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход2.край.X:16],-1*[цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1.dL:0] + 1*[цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1.край.X:22.4] + -1*[цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.остатък.dL:6.4],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3
s.AddConstraint( new LinearEquation( LinearExpression( 1*v124V_0 + 1*v149V_22_4), 1*v104V_22_4 + -1*v107V_0 + -1*v102V_0)); //= Eq(1*[цил_отвор_3.превкл1.изх_към.dL:0] + 1*[цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход1.край.X:22.4],1*[цил_отвор_3.подход1.край.X:22.4] + -1*[цил_отвор_3.остатък.dL:0] + -1*[цил_отвор_3.подход1.dL:0],) sent,by koren.цил_отвор_3
s.AddConstraint( new LinearEquation( LinearExpression( 1*v13V_2), 0.707107*v167V_2_82843)); //= Eq(1*[цилиндър_1.подход1.dL:2],0.707107*[цилиндър_1.подход1.край.преход.фаска-Алт2.dL:2.82843],) sent,by koren.цилиндър_1.подход1.край.преход.фаска-Алт2
s.AddConstraint( new LinearEquation( LinearExpression( 1*v15V_0), 1*v6V_0)); //= Eq(1*[цилиндър_1.подход1.край.X:0],1*[00_1.подход2.край.X:0],) sent,by koren.ляво чело_1
s.AddConstraint( new LinearEquation( LinearExpression( 1*v30V_35_5 + 1*v26V_1), 1*v22V_37_5 + -1*v27V_1 + -1*v25V_0)); //= Eq(1*[цилиндър_2.подход1.край.R:35.5] + 1*[дясно чело_2.подход2.dL:1],1*[дясно чело_4.подход2.край.R:37.5] + -1*[дясно чело_2.остатък.dL:1] + -1*[дясно чело_2.подход1.dL:0],) sent,by koren.дясно чело_2
s.AddConstraint( new LinearEquation( LinearExpression( 1*v31V_12), 1*v17V_12)); //= Eq(1*[цилиндър_2.подход1.край.X:12],1*[цилиндър_1.подход2.край.X:12],) sent,by koren.дясно чело_2
s.AddConstraint( new LinearEquation( LinearExpression( 1*v46V_41_5 + -1*v45V_0), 1*v47V_25_5 + 1*v42V_0 + 1*v44V_16)); //= Eq(1*[цилиндър_3.подход2.край.X:41.5] + -1*[цилиндър_3.подход2.dL:0],1*[цилиндър_3.остатък.dL:25.5] + 1*[цилиндър_3.подход1.dL:0] + 1*[цилиндър_3.подход1.край.X:16],) sent,by koren.цилиндър_3
s.AddConstraint( new LinearEquation( LinearExpression( 1*v62V_35 + 1*v58V_0), -1*v57V_0 + 1*v53V_35 + -1*v59V_0)); //= Eq(1*[цилиндър_4.подход1.край.R:35] + 1*[дясно чело_3.подход2.dL:0],-1*[дясно чело_3.подход1.dL:0] + 1*[конус_2.подход2.край.R:35] + -1*[дясно чело_3.остатък.dL:0],) sent,by koren.дясно чело_3
s.AddConstraint( new LinearEquation( LinearExpression( 1*v63V_44), 1*v54V_44)); //= Eq(1*[цилиндър_4.подход1.край.X:44],1*[конус_2.подход2.край.X:44],) sent,by koren.дясно чело_3
s.AddConstraint( new LinearEquation( LinearExpression( 1*v65V_57 + -1*v64V_0), 1*v63V_44 + 1*v61V_0 + 1*v66V_13)); //= Eq(1*[цилиндър_4.подход2.край.X:57] + -1*[цилиндър_4.подход2.dL:0],1*[цилиндър_4.подход1.край.X:44] + 1*[цилиндър_4.подход1.dL:0] + 1*[цилиндър_4.остатък.dL:13],) sent,by koren.цилиндър_4
s.AddConstraint( new LinearEquation( LinearExpression( 1*v73V_34_9), 1*v144V_34_9)); //= Eq(1*[цилиндър_5.подход1.край.R:34.9],1*[цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.подход2.край.R:34.9],) sent,by koren.цилиндър_5
s.AddConstraint( new LinearEquation( LinearExpression( 1*v74V_57), 1*v65V_57)); //= Eq(1*[цилиндър_5.подход1.край.X:57],1*[цилиндър_4.подход2.край.X:57],) sent,by koren.дясно чело_5
s.AddConstraint( new LinearEquation( LinearExpression( 1*v76V_65 + -1*v75V_0), 1*v139V_61 + 1*v122V_0 + 1*v123V_4)); //= Eq(1*[цилиндър_5.подход2.край.X:65] + -1*[цилиндър_5.подход2.dL:0],1*[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход2.край.X:61] + 1*[цилиндър_5.превкл1.вход_от.dL:0] + 1*[цилиндър_5.превкл1.остатък.dL:4],) sent,by koren.цилиндър_5
s.AddConstraint( new LinearEquation( LinearExpression( 1*v130V_34_9), 1*v73V_34_9)); //= Eq(1*[цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход1.край.R:34.9],1*[цилиндър_5.подход1.край.R:34.9],) sent,by koren.цилиндър_5
s.AddConstraint( new LinearEquation( LinearExpression( 1*v131V_57 + -1*v120V_0), 1*v74V_57 + 1*v72V_0 + 1*v77V_0)); //= Eq(1*[цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход1.край.X:57] + -1*[цилиндър_5.превкл1.изх_към.dL:0],1*[цилиндър_5.подход1.край.X:57] + 1*[цилиндър_5.подход1.dL:0] + 1*[цилиндър_5.остатък.dL:0],) sent,by koren.цилиндър_5
s.AddConstraint( new LinearEquation( LinearExpression( 1*v144V_34_9 + -1*v143V_0), 1*v145V_2_15 + 1*v136V_32_55 + 1*v142V_0_2)); //= Eq(1*[цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.подход2.край.R:34.9] + -1*[цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.подход2.dL:0],1*[цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.остатък.dL:2.15] + 1*[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край.R:32.55] + 1*[цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.подход1.dL:0.2],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2
s.AddConstraint( new LinearEquation( LinearExpression( 1*v136V_32_55 + 1*v132V_0_2), -1*v133V_2_15 + 1*v130V_34_9 + -1*v129V_0)); //= Eq(1*[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край.R:32.55] + 1*[цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход2.dL:0.2],-1*[цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.остатък.dL:2.15] + 1*[цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход1.край.R:34.9] + -1*[цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход1.dL:0],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2
s.AddConstraint( new LinearEquation( LinearExpression( 1*v137V_57), 1*v131V_57)); //= Eq(1*[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край.X:57],1*[цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход1.край.X:57],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2
s.AddConstraint( new LinearEquation( LinearExpression( 1*v139V_61 + -1*v138V_0_2), 1*v140V_3_6 + 1*v137V_57 + 1*v135V_0_2)); //= Eq(1*[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход2.край.X:61] + -1*[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход2.dL:0.2],1*[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.остатък.dL:3.6] + 1*[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край.X:57] + 1*[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.dL:0.2],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2
s.AddConstraint( new LinearEquation( LinearExpression( 2*v43V_37_5), v182V_75)); //= Eq(2*[цилиндър_3.подход1.край.R:37.5],[размери.резбаD_1.v_input:75],) sent,by koren.размери.резбаD_1
s.AddConstraint( new LinearEquation( LinearExpression( v2V_0), 0)); //= Eq([00_1.подход1.dL:0],0,) sent,by koren.00_1.подход1.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v4V_7), 1*v106V_7)); //= Eq([00_1.подход1.край.X:7],1*[цил_отвор_3.подход2.край.X:7],) sent,by koren.ляво чело_2
s.AddConstraint( new LinearEquation( LinearExpression( v6V_0), 1*v4V_7 + -1*v1V_7)); //= Eq([00_1.подход2.край.X:0],1*[00_1.подход1.край.X:7] + -1*[00_1.dL:7],) sent,by koren.00_1
s.AddConstraint( new LinearEquation( LinearExpression( v116V_0), 0)); //= Eq([00_1.превкл1.вход_от.dL:0],0,) sent,by koren.00_1.превкл1.вход_от.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v117V_25), 1*v113V_25)); //= Eq([00_1.превкл1.вход_от.край.R:25],1*[00_1.превкл1.изх_към.край.R:25],) sent,by koren.00_1
s.AddConstraint( new LinearEquation( LinearExpression( v118V_1), -1*v115V_0 + 1*v114V_1)); //= Eq([00_1.превкл1.вход_от.край.X:1],-1*[00_1.превкл1.място.dL:0] + 1*[00_1.превкл1.изх_към.край.X:1],) sent,by koren.00_1
s.AddConstraint( new LinearEquation( LinearExpression( v112V_0), 0)); //= Eq([00_1.превкл1.изх_към.dL:0],0,) sent,by koren.00_1.превкл1.изх_към.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v115V_0), 0)); //= Eq([00_1.превкл1.място.dL:0],0,) sent,by koren.00_1.превкл1.празен-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v119V_0), 0)); //= Eq([00_1.превкл1.остатък.dL:0],0,) sent,by koren.00_1.превкл1.празен-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v87V_0), 0)); //= Eq([дясно чело_1.подход1.dL:0],0,) sent,by koren.конус_3.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v25V_0), 0)); //= Eq([дясно чело_2.подход1.dL:0],0,) sent,by koren.дясно чело_4.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v57V_0), 0)); //= Eq([дясно чело_3.подход1.dL:0],0,) sent,by koren.конус_2.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v58V_0), 0)); //= Eq([дясно чело_3.подход2.dL:0],0,) sent,by koren.цилиндър_4.подход1.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v20V_0), 0)); //= Eq([дясно чело_4.подход1.dL:0],0,) sent,by koren.цилиндър_1.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v21V_0), 0)); //= Eq([дясно чело_4.подход2.dL:0],0,) sent,by koren.дясно чело_4.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v68V_0), 0)); //= Eq([дясно чело_5.подход1.dL:0],0,) sent,by koren.цилиндър_4.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v69V_0), 0)); //= Eq([дясно чело_5.подход2.dL:0],0,) sent,by koren.цилиндър_5.подход1.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v37V_2), -1*v30V_35_5 + 1*v43V_37_5)); //= Eq([конус_1.dR:2],-1*[цилиндър_2.подход1.край.R:35.5] + 1*[цилиндър_3.подход1.край.R:37.5],) sent,by koren.конус_1
s.AddConstraint( new LinearEquation( LinearExpression( v37V_2), 0.707107*v35V_2_82843)); //= Eq([конус_1.dR:2],0.707107*[конус_1.dL:2.82843],) sent,by koren.конус_1
s.AddConstraint( new LinearEquation( LinearExpression( v36V_2), 0.707107*v35V_2_82843)); //= Eq([конус_1.dX:2],0.707107*[конус_1.dL:2.82843],) sent,by koren.конус_1
s.AddConstraint( new LinearEquation( LinearExpression( v38V_0), 0)); //= Eq([конус_1.подход1.dL:0],0,) sent,by koren.цилиндър_2.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v39V_0), 0)); //= Eq([конус_1.подход2.dL:0],0,) sent,by koren.цилиндър_3.подход1.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v50V__2_5), -0.707107*v48V_3_53553)); //= Eq([конус_2.dR:-2.5],-0.707107*[конус_2.dL:3.53553],) sent,by koren.конус_2
s.AddConstraint( new LinearEquation( LinearExpression( v50V__2_5), 1*v53V_35 + -1*v43V_37_5)); //= Eq([конус_2.dR:-2.5],1*[конус_2.подход2.край.R:35] + -1*[цилиндър_3.подход1.край.R:37.5],) sent,by koren.конус_2
s.AddConstraint( new LinearEquation( LinearExpression( v49V_2_5), 0.707107*v48V_3_53553)); //= Eq([конус_2.dX:2.5],0.707107*[конус_2.dL:3.53553],) sent,by koren.конус_2
s.AddConstraint( new LinearEquation( LinearExpression( v51V_0), 0)); //= Eq([конус_2.подход1.dL:0],0,) sent,by koren.цилиндър_3.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v52V_0), 0)); //= Eq([конус_2.подход2.dL:0],0,) sent,by koren.конус_2.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v54V_44), 1*v46V_41_5 + 1*v49V_2_5)); //= Eq([конус_2.подход2.край.X:44],1*[цилиндър_3.подход2.край.X:41.5] + 1*[конус_2.dX:2.5],) sent,by koren.конус_2
s.AddConstraint( new LinearEquation( LinearExpression( v80V__5), -0.707107*v78V_7_07107)); //= Eq([конус_3.dR:-5],-0.707107*[конус_3.dL:7.07107],) sent,by koren.конус_3
s.AddConstraint( new LinearEquation( LinearExpression( v80V__5), -1*v73V_34_9 + 1*v83V_29_9)); //= Eq([конус_3.dR:-5],-1*[цилиндър_5.подход1.край.R:34.9] + 1*[конус_3.подход2.край.R:29.9],) sent,by koren.конус_3
s.AddConstraint( new LinearEquation( LinearExpression( v79V_5), 0.707107*v78V_7_07107)); //= Eq([конус_3.dX:5],0.707107*[конус_3.dL:7.07107],) sent,by koren.конус_3
s.AddConstraint( new LinearEquation( LinearExpression( v81V_0), 0)); //= Eq([конус_3.подход1.dL:0],0,) sent,by koren.цилиндър_5.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v82V_0), 0)); //= Eq([конус_3.подход2.dL:0],0,) sent,by koren.конус_3.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v84V_70), 1*v76V_65 + 1*v79V_5)); //= Eq([конус_3.подход2.край.X:70],1*[цилиндър_5.подход2.край.X:65] + 1*[конус_3.dX:5],) sent,by koren.конус_3
s.AddConstraint( new LinearEquation( LinearExpression( v8V_16), 1*v14V_41 + -1*v3V_25)); //= Eq([ляво чело_1.dL:16],1*[цилиндър_1.подход1.край.R:41] + -1*[00_1.подход1.край.R:25],) sent,by koren.ляво чело_1
s.AddConstraint( new LinearEquation( LinearExpression( v108V_5), 1*v3V_25 + -1*v103V_20)); //= Eq([ляво чело_2.dL:5],1*[00_1.подход1.край.R:25] + -1*[цил_отвор_3.подход1.край.R:20],) sent,by koren.ляво чело_2
s.AddConstraint( new LinearEquation( LinearExpression( v109V_0), 0)); //= Eq([ляво чело_2.подход1.dL:0],0,) sent,by koren.цил_отвор_3.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v110V_0), 0)); //= Eq([ляво чело_2.подход2.dL:0],0,) sent,by koren.00_1.подход1.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v97V_0), 1*v103V_20 + -1*v92V_20)); //= Eq([ляво чело_3.dL:0],1*[цил_отвор_3.подход1.край.R:20] + -1*[цил_отвор_2.подход1.край.R:20],) sent,by koren.ляво чело_3
s.AddConstraint( new LinearEquation( LinearExpression( v98V_0), 0)); //= Eq([ляво чело_3.подход1.dL:0],0,) sent,by koren.цил_отвор_2.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v99V_0), 0)); //= Eq([ляво чело_3.подход2.dL:0],0,) sent,by koren.цил_отвор_3.подход1.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v176V_0), 1*v22V_37_5 + -1*v43V_37_5)); //= Eq([размери.размер_dR_2.v:0],1*[дясно чело_4.подход2.край.R:37.5] + -1*[цилиндър_3.подход1.край.R:37.5],) sent,by koren.размери.размер_dR_2
s.AddConstraint( new LinearEquation( LinearExpression( v177V_13), -1*v65V_57 + 1*v84V_70)); //= Eq([размери.размер_dX_1.v:13],-1*[цилиндър_4.подход2.край.X:57] + 1*[конус_3.подход2.край.X:70],) sent,by koren.размери.размер_dX_1
s.AddConstraint( new LinearEquation( LinearExpression( v184V_0), -1*v65V_57 + 1*v131V_57)); //= Eq([размери.размер_dX_10.v:0],-1*[цилиндър_4.подход2.край.X:57] + 1*[цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход1.край.X:57],) sent,by koren.размери.размер_dX_10
s.AddConstraint( new LinearEquation( LinearExpression( v185V_22_4), -1*v6V_0 + 1*v104V_22_4)); //= Eq([размери.размер_dX_11.v:22.4],-1*[00_1.подход2.край.X:0] + 1*[цил_отвор_3.подход1.край.X:22.4],) sent,by koren.размери.размер_dX_11
s.AddConstraint( new LinearEquation( LinearExpression( v178V_26), -1*v54V_44 + 1*v84V_70)); //= Eq([размери.размер_dX_2.v:26],-1*[конус_2.подход2.край.X:44] + 1*[конус_3.подход2.край.X:70],) sent,by koren.размери.размер_dX_2
s.AddConstraint( new LinearEquation( LinearExpression( v179V_58), -1*v17V_12 + 1*v84V_70)); //= Eq([размери.размер_dX_3.v:58],-1*[цилиндър_1.подход2.край.X:12] + 1*[конус_3.подход2.край.X:70],) sent,by koren.размери.размер_dX_3
s.AddConstraint( new LinearEquation( LinearExpression( v180V_70), -1*v6V_0 + 1*v84V_70)); //= Eq([размери.размер_dX_4.v:70],-1*[00_1.подход2.край.X:0] + 1*[конус_3.подход2.край.X:70],) sent,by koren.размери.размер_dX_4
s.AddConstraint( new LinearEquation( LinearExpression( v181V_4), -1*v17V_12 + 1*v44V_16)); //= Eq([размери.размер_dX_5.v:4],-1*[цилиндър_1.подход2.край.X:12] + 1*[цилиндър_3.подход1.край.X:16],) sent,by koren.размери.размер_dX_5
s.AddConstraint( new LinearEquation( LinearExpression( v183V_0), 1*v95V_22_4 + -1*v149V_22_4)); //= Eq([размери.размер_dX_8.v:0],1*[цил_отвор_2.подход2.край.X:22.4] + -1*[цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход1.край.X:22.4],) sent,by koren.размери.размер_dX_8
s.AddConstraint( new LinearEquation( LinearExpression( v93V_70), 1*v84V_70)); //= Eq([цил_отвор_2.подход1.край.X:70],1*[конус_3.подход2.край.X:70],) sent,by koren.дясно чело_1
s.AddConstraint( new LinearEquation( LinearExpression( v94V_0), 0)); //= Eq([цил_отвор_2.подход2.dL:0],0,) sent,by koren.цил_отвор_2.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v95V_22_4), -1*v90V_47_6 + 1*v93V_70)); //= Eq([цил_отвор_2.подход2.край.X:22.4],-1*[цил_отвор_2.dL:47.6] + 1*[цил_отвор_2.подход1.край.X:70],) sent,by koren.цил_отвор_2
s.AddConstraint( new LinearEquation( LinearExpression( v102V_0), 0)); //= Eq([цил_отвор_3.подход1.dL:0],0,) sent,by koren.цил_отвор_3.подход1.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v104V_22_4), 1*v95V_22_4)); //= Eq([цил_отвор_3.подход1.край.X:22.4],1*[цил_отвор_2.подход2.край.X:22.4],) sent,by koren.ляво чело_3
s.AddConstraint( new LinearEquation( LinearExpression( v105V_0), 0)); //= Eq([цил_отвор_3.подход2.dL:0],0,) sent,by koren.цил_отвор_3.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v106V_7), 1*v104V_22_4 + -1*v101V_15_4)); //= Eq([цил_отвор_3.подход2.край.X:7],1*[цил_отвор_3.подход1.край.X:22.4] + -1*[цил_отвор_3.dL:15.4],) sent,by koren.цил_отвор_3
s.AddConstraint( new LinearEquation( LinearExpression( v160V_0), 0)); //= Eq([цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.подход1.dL:0],0,) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v161V_0), 0)); //= Eq([цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.подход2.dL:0],0,) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v162V_20), 1*v148V_20)); //= Eq([цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.подход2.край.R:20],1*[цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход1.край.R:20],) sent,by koren.цил_отвор_3
s.AddConstraint( new LinearEquation( LinearExpression( v146V_4), 1*v154V_24 + -1*v148V_20)); //= Eq([цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.dL:4],1*[цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1.край.R:24] + -1*[цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход1.край.R:20],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2
s.AddConstraint( new LinearEquation( LinearExpression( v147V_0), 0)); //= Eq([цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход1.dL:0],0,) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход1.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v150V_0), 0)); //= Eq([цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход2.dL:0],0,) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v153V_0), 0)); //= Eq([цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1.dL:0],0,) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v155V_22_4), 1*v149V_22_4)); //= Eq([цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1.край.X:22.4],1*[цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход1.край.X:22.4],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2
s.AddConstraint( new LinearEquation( LinearExpression( v156V_0), 0)); //= Eq([цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход2.dL:0],0,) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v157V_16), -1*v152V_6_4 + 1*v155V_22_4)); //= Eq([цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход2.край.X:16],-1*[цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.dL:6.4] + 1*[цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1.край.X:22.4],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3
s.AddConstraint( new LinearEquation( LinearExpression( v157V_16), -1*v125V_6_4 + 1*v149V_22_4)); //= Eq([цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход2.край.X:16],-1*[цил_отвор_3.превкл1.място.dL:6.4] + 1*[цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход1.край.X:22.4],) sent,by koren.цил_отвор_3
s.AddConstraint( new LinearEquation( LinearExpression( v126V_0), 0)); //= Eq([цил_отвор_3.превкл1.вход_от.dL:0],0,) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v124V_0), 0)); //= Eq([цил_отвор_3.превкл1.изх_към.dL:0],0,) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход1.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v15V_0), 1*v6V_0)); //= Eq([цилиндър_1.подход1.край.X:0],1*[00_1.подход2.край.X:0],) sent,by koren.ляво чело_1
s.AddConstraint( new LinearEquation( LinearExpression( v16V_0), 0)); //= Eq([цилиндър_1.подход2.dL:0],0,) sent,by koren.цилиндър_1.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v17V_12), 1*v15V_0 + 1*v12V_12)); //= Eq([цилиндър_1.подход2.край.X:12],1*[цилиндър_1.подход1.край.X:0] + 1*[цилиндър_1.dL:12],) sent,by koren.цилиндър_1
s.AddConstraint( new LinearEquation( LinearExpression( v31V_12), 1*v17V_12)); //= Eq([цилиндър_2.подход1.край.X:12],1*[цилиндър_1.подход2.край.X:12],) sent,by koren.дясно чело_2
s.AddConstraint( new LinearEquation( LinearExpression( v170V_1), 1*v26V_1)); //= Eq([цилиндър_2.подход1.край.преход.закръгление-Алт1.r:1],1*[дясно чело_2.подход2.dL:1],) sent,by koren.цилиндър_2.подход1.край.преход.закръгление-Алт1
s.AddConstraint( new LinearEquation( LinearExpression( v32V_0), 0)); //= Eq([цилиндър_2.подход2.dL:0],0,) sent,by koren.цилиндър_2.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v33V_14), 1*v28V_2 + 1*v31V_12)); //= Eq([цилиндър_2.подход2.край.X:14],1*[цилиндър_2.dL:2] + 1*[цилиндър_2.подход1.край.X:12],) sent,by koren.цилиндър_2
s.AddConstraint( new LinearEquation( LinearExpression( v42V_0), 0)); //= Eq([цилиндър_3.подход1.dL:0],0,) sent,by koren.цилиндър_3.подход1.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v44V_16), 1*v36V_2 + 1*v33V_14)); //= Eq([цилиндър_3.подход1.край.X:16],1*[конус_1.dX:2] + 1*[цилиндър_2.подход2.край.X:14],) sent,by koren.конус_1
s.AddConstraint( new LinearEquation( LinearExpression( v45V_0), 0)); //= Eq([цилиндър_3.подход2.dL:0],0,) sent,by koren.цилиндър_3.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v46V_41_5), 1*v41V_25_5 + 1*v44V_16)); //= Eq([цилиндър_3.подход2.край.X:41.5],1*[цилиндър_3.dL:25.5] + 1*[цилиндър_3.подход1.край.X:16],) sent,by koren.цилиндър_3
s.AddConstraint( new LinearEquation( LinearExpression( v61V_0), 0)); //= Eq([цилиндър_4.подход1.dL:0],0,) sent,by koren.цилиндър_4.подход1.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v63V_44), 1*v54V_44)); //= Eq([цилиндър_4.подход1.край.X:44],1*[конус_2.подход2.край.X:44],) sent,by koren.дясно чело_3
s.AddConstraint( new LinearEquation( LinearExpression( v64V_0), 0)); //= Eq([цилиндър_4.подход2.dL:0],0,) sent,by koren.цилиндър_4.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v65V_57), 1*v60V_13 + 1*v63V_44)); //= Eq([цилиндър_4.подход2.край.X:57],1*[цилиндър_4.dL:13] + 1*[цилиндър_4.подход1.край.X:44],) sent,by koren.цилиндър_4
s.AddConstraint( new LinearEquation( LinearExpression( v72V_0), 0)); //= Eq([цилиндър_5.подход1.dL:0],0,) sent,by koren.цилиндър_5.подход1.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v74V_57), 1*v65V_57)); //= Eq([цилиндър_5.подход1.край.X:57],1*[цилиндър_4.подход2.край.X:57],) sent,by koren.дясно чело_5
s.AddConstraint( new LinearEquation( LinearExpression( v75V_0), 0)); //= Eq([цилиндър_5.подход2.dL:0],0,) sent,by koren.цилиндър_5.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v76V_65), 1*v74V_57 + 1*v71V_8)); //= Eq([цилиндър_5.подход2.край.X:65],1*[цилиндър_5.подход1.край.X:57] + 1*[цилиндър_5.dL:8],) sent,by koren.цилиндър_5
s.AddConstraint( new LinearEquation( LinearExpression( v129V_0), 0)); //= Eq([цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход1.dL:0],0,) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход1.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v141V_2_35), -1*v136V_32_55 + 1*v144V_34_9)); //= Eq([цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.dL:2.35],-1*[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край.R:32.55] + 1*[цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.подход2.край.R:34.9],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2
s.AddConstraint( new LinearEquation( LinearExpression( v143V_0), 0)); //= Eq([цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.подход2.dL:0],0,) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v144V_34_9), 1*v130V_34_9)); //= Eq([цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.подход2.край.R:34.9],1*[цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход1.край.R:34.9],) sent,by koren.цилиндър_5
s.AddConstraint( new LinearEquation( LinearExpression( v137V_57), 1*v131V_57)); //= Eq([цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край.X:57],1*[цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход1.край.X:57],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2
s.AddConstraint( new LinearEquation( LinearExpression( v174V_0_2), 1*v132V_0_2)); //= Eq([цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край.преход.закръгление-Алт1.r:0.2],1*[цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход2.dL:0.2],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край.преход.закръгление-Алт1
s.AddConstraint( new LinearEquation( LinearExpression( v139V_61), 1*v134V_4 + 1*v137V_57)); //= Eq([цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход2.край.X:61],1*[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.dL:4] + 1*[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край.X:57],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2
s.AddConstraint( new LinearEquation( LinearExpression( v139V_61), 1*v121V_4 + 1*v131V_57)); //= Eq([цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход2.край.X:61],1*[цилиндър_5.превкл1.място.dL:4] + 1*[цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход1.край.X:57],) sent,by koren.цилиндър_5
s.AddConstraint( new LinearEquation( LinearExpression( v175V_0_2), 1*v138V_0_2)); //= Eq([цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход2.край.преход.закръгление-Алт1.r:0.2],1*[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход2.dL:0.2],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход2.край.преход.закръгление-Алт1
s.AddConstraint( new LinearEquation( LinearExpression( v122V_0), 0)); //= Eq([цилиндър_5.превкл1.вход_от.dL:0],0,) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.подход2.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v120V_0), 0)); //= Eq([цилиндър_5.превкл1.изх_към.dL:0],0,) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход1.край.преход.пряк-Алт0
s.AddConstraint( new LinearEquation( LinearExpression( v165V_1), v5V_1)); //= EqVar([00_1.подход2.край.преход.фаска-Алт1.dL1:1],[00_1.подход2.dL:1],) sent,by koren.00_1.подход2.край.преход.фаска-Алт1
s.AddConstraint( new LinearEquation( LinearExpression( v166V_0_267949), v9V_0_267949)); //= EqVar([00_1.подход2.край.преход.фаска-Алт1.dL2:0.267949],[ляво чело_1.подход1.dL:0.267949],) sent,by koren.00_1.подход2.край.преход.фаска-Алт1
s.AddConstraint( new LinearEquation( LinearExpression( v26V_1), v29V_1)); //= EqVar([дясно чело_2.подход2.dL:1],[цилиндър_2.подход1.dL:1],) sent,by koren.цилиндър_2.подход1.край.преход.закръгление-Алт1
s.AddConstraint( new LinearEquation( LinearExpression( v172V_1_5), v88V_1_5)); //= EqVar([цил_отвор_2.подход1.край.преход.фаска-Алт1.dL1:1.5],[дясно чело_1.подход2.dL:1.5],) sent,by koren.цил_отвор_2.подход1.край.преход.фаска-Алт1
s.AddConstraint( new LinearEquation( LinearExpression( v173V_1_5), v91V_1_5)); //= EqVar([цил_отвор_2.подход1.край.преход.фаска-Алт1.dL2:1.5],[цил_отвор_2.подход1.dL:1.5],) sent,by koren.цил_отвор_2.подход1.край.преход.фаска-Алт1
s.AddConstraint( new LinearEquation( LinearExpression( v168V_2), v10V_2)); //= EqVar([цилиндър_1.подход1.край.преход.фаска-Алт2.dL1:2],[ляво чело_1.подход2.dL:2],) sent,by koren.цилиндър_1.подход1.край.преход.фаска-Алт2
s.AddConstraint( new LinearEquation( LinearExpression( v169V_2), v13V_2)); //= EqVar([цилиндър_1.подход1.край.преход.фаска-Алт2.dL2:2],[цилиндър_1.подход1.dL:2],) sent,by koren.цилиндър_1.подход1.край.преход.фаска-Алт2
s.AddConstraint( new LinearEquation( LinearExpression( v132V_0_2), v135V_0_2)); //= EqVar([цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход2.dL:0.2],[цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.dL:0.2],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край.преход.закръгление-Алт1
s.AddConstraint( new LinearEquation( LinearExpression( v138V_0_2), v142V_0_2)); //= EqVar([цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход2.dL:0.2],[цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.подход1.dL:0.2],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход2.край.преход.закръгление-Алт1
s.AddConstraint( new LinearInequality( v1V_7)); //= Positive0([00_1.dL:7],) sent,by koren.00_1
s.AddConstraint( new LinearInequality( v7V_6)); //= Positive0([00_1.остатък.dL:6],) sent,by koren.00_1.остатък
s.AddConstraint( new LinearInequality( v2V_0)); //= Positive0([00_1.подход1.dL:0],) sent,by koren.00_1.подход1
s.AddConstraint( new LinearInequality( v3V_25)); //= Positive0([00_1.подход1.край.R:25],) sent,by koren.00_1.подход1.край
s.AddConstraint( new LinearInequality( v5V_1)); //= Positive0([00_1.подход2.dL:1],) sent,by koren.00_1.подход2
s.AddConstraint( new LinearInequality( v165V_1)); //= Positive0([00_1.подход2.край.преход.фаска-Алт1.dL1:1],) sent,by koren.00_1.подход2.край.преход.фаска-Алт1
s.AddConstraint( new LinearInequality( v166V_0_267949)); //= Positive0([00_1.подход2.край.преход.фаска-Алт1.dL2:0.267949],) sent,by koren.00_1.подход2.край.преход.фаска-Алт1
s.AddConstraint( new LinearInequality( v164V_1_03528)); //= Positive0([00_1.подход2.край.преход.фаска-Алт1.dL:1.03528],) sent,by koren.00_1.подход2.край.преход.фаска-Алт1
s.AddConstraint( new LinearInequality( v116V_0)); //= Positive0([00_1.превкл1.вход_от.dL:0],) sent,by koren.00_1.превкл1.вход_от
s.AddConstraint( new LinearInequality( v117V_25)); //= Positive0([00_1.превкл1.вход_от.край.R:25],) sent,by koren.00_1.превкл1.вход_от.край
s.AddConstraint( new LinearInequality( v112V_0)); //= Positive0([00_1.превкл1.изх_към.dL:0],) sent,by koren.00_1.превкл1.изх_към
s.AddConstraint( new LinearInequality( v113V_25)); //= Positive0([00_1.превкл1.изх_към.край.R:25],) sent,by koren.00_1.превкл1.изх_към.край
s.AddConstraint( new LinearInequality( v115V_0)); //= Positive0([00_1.превкл1.място.dL:0],) sent,by koren.00_1.превкл1.място
s.AddConstraint( new LinearInequality( v119V_0)); //= Positive0([00_1.превкл1.остатък.dL:0],) sent,by koren.00_1.превкл1.остатък
s.AddConstraint( new LinearInequality( v86V_9_9)); //= Positive0([дясно чело_1.dL:9.9],) sent,by koren.дясно чело_1
s.AddConstraint( new LinearInequality( v89V_8_4)); //= Positive0([дясно чело_1.остатък.dL:8.4],) sent,by koren.дясно чело_1.остатък
s.AddConstraint( new LinearInequality( v87V_0)); //= Positive0([дясно чело_1.подход1.dL:0],) sent,by koren.дясно чело_1.подход1
s.AddConstraint( new LinearInequality( v88V_1_5)); //= Positive0([дясно чело_1.подход2.dL:1.5],) sent,by koren.дясно чело_1.подход2
s.AddConstraint( new LinearInequality( v24V_2)); //= Positive0([дясно чело_2.dL:2],) sent,by koren.дясно чело_2
s.AddConstraint( new LinearInequality( v27V_1)); //= Positive0([дясно чело_2.остатък.dL:1],) sent,by koren.дясно чело_2.остатък
s.AddConstraint( new LinearInequality( v25V_0)); //= Positive0([дясно чело_2.подход1.dL:0],) sent,by koren.дясно чело_2.подход1
s.AddConstraint( new LinearInequality( v26V_1)); //= Positive0([дясно чело_2.подход2.dL:1],) sent,by koren.дясно чело_2.подход2
s.AddConstraint( new LinearInequality( v56V_0)); //= Positive0([дясно чело_3.dL:0],) sent,by koren.дясно чело_3
s.AddConstraint( new LinearInequality( v59V_0)); //= Positive0([дясно чело_3.остатък.dL:0],) sent,by koren.дясно чело_3.остатък
s.AddConstraint( new LinearInequality( v57V_0)); //= Positive0([дясно чело_3.подход1.dL:0],) sent,by koren.дясно чело_3.подход1
s.AddConstraint( new LinearInequality( v58V_0)); //= Positive0([дясно чело_3.подход2.dL:0],) sent,by koren.дясно чело_3.подход2
s.AddConstraint( new LinearInequality( v19V_3_5)); //= Positive0([дясно чело_4.dL:3.5],) sent,by koren.дясно чело_4
s.AddConstraint( new LinearInequality( v23V_3_5)); //= Positive0([дясно чело_4.остатък.dL:3.5],) sent,by koren.дясно чело_4.остатък
s.AddConstraint( new LinearInequality( v20V_0)); //= Positive0([дясно чело_4.подход1.dL:0],) sent,by koren.дясно чело_4.подход1
s.AddConstraint( new LinearInequality( v21V_0)); //= Positive0([дясно чело_4.подход2.dL:0],) sent,by koren.дясно чело_4.подход2
s.AddConstraint( new LinearInequality( v22V_37_5)); //= Positive0([дясно чело_4.подход2.край.R:37.5],) sent,by koren.дясно чело_4.подход2.край
s.AddConstraint( new LinearInequality( v67V_0_1)); //= Positive0([дясно чело_5.dL:0.1],) sent,by koren.дясно чело_5
s.AddConstraint( new LinearInequality( v70V_0_1)); //= Positive0([дясно чело_5.остатък.dL:0.1],) sent,by koren.дясно чело_5.остатък
s.AddConstraint( new LinearInequality( v68V_0)); //= Positive0([дясно чело_5.подход1.dL:0],) sent,by koren.дясно чело_5.подход1
s.AddConstraint( new LinearInequality( v69V_0)); //= Positive0([дясно чело_5.подход2.dL:0],) sent,by koren.дясно чело_5.подход2
s.AddConstraint( new LinearInequality( v35V_2_82843)); //= Positive0([конус_1.dL:2.82843],) sent,by koren.конус_1
s.AddConstraint( new LinearInequality( v40V_2_82843)); //= Positive0([конус_1.остатък.dL:2.82843],) sent,by koren.конус_1.остатък
s.AddConstraint( new LinearInequality( v38V_0)); //= Positive0([конус_1.подход1.dL:0],) sent,by koren.конус_1.подход1
s.AddConstraint( new LinearInequality( v39V_0)); //= Positive0([конус_1.подход2.dL:0],) sent,by koren.конус_1.подход2
s.AddConstraint( new LinearInequality( v48V_3_53553)); //= Positive0([конус_2.dL:3.53553],) sent,by koren.конус_2
s.AddConstraint( new LinearInequality( v55V_3_53553)); //= Positive0([конус_2.остатък.dL:3.53553],) sent,by koren.конус_2.остатък
s.AddConstraint( new LinearInequality( v51V_0)); //= Positive0([конус_2.подход1.dL:0],) sent,by koren.конус_2.подход1
s.AddConstraint( new LinearInequality( v52V_0)); //= Positive0([конус_2.подход2.dL:0],) sent,by koren.конус_2.подход2
s.AddConstraint( new LinearInequality( v53V_35)); //= Positive0([конус_2.подход2.край.R:35],) sent,by koren.конус_2.подход2.край
s.AddConstraint( new LinearInequality( v78V_7_07107)); //= Positive0([конус_3.dL:7.07107],) sent,by koren.конус_3
s.AddConstraint( new LinearInequality( v85V_7_07107)); //= Positive0([конус_3.остатък.dL:7.07107],) sent,by koren.конус_3.остатък
s.AddConstraint( new LinearInequality( v81V_0)); //= Positive0([конус_3.подход1.dL:0],) sent,by koren.конус_3.подход1
s.AddConstraint( new LinearInequality( v82V_0)); //= Positive0([конус_3.подход2.dL:0],) sent,by koren.конус_3.подход2
s.AddConstraint( new LinearInequality( v83V_29_9)); //= Positive0([конус_3.подход2.край.R:29.9],) sent,by koren.конус_3.подход2.край
s.AddConstraint( new LinearInequality( v8V_16)); //= Positive0([ляво чело_1.dL:16],) sent,by koren.ляво чело_1
s.AddConstraint( new LinearInequality( v11V_13_7321)); //= Positive0([ляво чело_1.остатък.dL:13.7321],) sent,by koren.ляво чело_1.остатък
s.AddConstraint( new LinearInequality( v9V_0_267949)); //= Positive0([ляво чело_1.подход1.dL:0.267949],) sent,by koren.ляво чело_1.подход1
s.AddConstraint( new LinearInequality( v10V_2)); //= Positive0([ляво чело_1.подход2.dL:2],) sent,by koren.ляво чело_1.подход2
s.AddConstraint( new LinearInequality( v108V_5)); //= Positive0([ляво чело_2.dL:5],) sent,by koren.ляво чело_2
s.AddConstraint( new LinearInequality( v111V_5)); //= Positive0([ляво чело_2.остатък.dL:5],) sent,by koren.ляво чело_2.остатък
s.AddConstraint( new LinearInequality( v109V_0)); //= Positive0([ляво чело_2.подход1.dL:0],) sent,by koren.ляво чело_2.подход1
s.AddConstraint( new LinearInequality( v110V_0)); //= Positive0([ляво чело_2.подход2.dL:0],) sent,by koren.ляво чело_2.подход2
s.AddConstraint( new LinearInequality( v97V_0)); //= Positive0([ляво чело_3.dL:0],) sent,by koren.ляво чело_3
s.AddConstraint( new LinearInequality( v100V_0)); //= Positive0([ляво чело_3.остатък.dL:0],) sent,by koren.ляво чело_3.остатък
s.AddConstraint( new LinearInequality( v98V_0)); //= Positive0([ляво чело_3.подход1.dL:0],) sent,by koren.ляво чело_3.подход1
s.AddConstraint( new LinearInequality( v99V_0)); //= Positive0([ляво чело_3.подход2.dL:0],) sent,by koren.ляво чело_3.подход2
s.AddConstraint( new LinearInequality( v176V_0)); //= Positive0([размери.размер_dR_2.v:0],) sent,by koren.размери.размер_dR_2
s.AddConstraint( new LinearInequality( v177V_13)); //= Positive0([размери.размер_dX_1.v:13],) sent,by koren.размери.размер_dX_1
s.AddConstraint( new LinearInequality( v184V_0)); //= Positive0([размери.размер_dX_10.v:0],) sent,by koren.размери.размер_dX_10
s.AddConstraint( new LinearInequality( v185V_22_4)); //= Positive0([размери.размер_dX_11.v:22.4],) sent,by koren.размери.размер_dX_11
s.AddConstraint( new LinearInequality( v178V_26)); //= Positive0([размери.размер_dX_2.v:26],) sent,by koren.размери.размер_dX_2
s.AddConstraint( new LinearInequality( v179V_58)); //= Positive0([размери.размер_dX_3.v:58],) sent,by koren.размери.размер_dX_3
s.AddConstraint( new LinearInequality( v180V_70)); //= Positive0([размери.размер_dX_4.v:70],) sent,by koren.размери.размер_dX_4
s.AddConstraint( new LinearInequality( v181V_4)); //= Positive0([размери.размер_dX_5.v:4],) sent,by koren.размери.размер_dX_5
s.AddConstraint( new LinearInequality( v183V_0)); //= Positive0([размери.размер_dX_8.v:0],) sent,by koren.размери.размер_dX_8
s.AddConstraint( new LinearInequality( v90V_47_6)); //= Positive0([цил_отвор_2.dL:47.6],) sent,by koren.цил_отвор_2
s.AddConstraint( new LinearInequality( v96V_46_1)); //= Positive0([цил_отвор_2.остатък.dL:46.1],) sent,by koren.цил_отвор_2.остатък
s.AddConstraint( new LinearInequality( v91V_1_5)); //= Positive0([цил_отвор_2.подход1.dL:1.5],) sent,by koren.цил_отвор_2.подход1
s.AddConstraint( new LinearInequality( v92V_20)); //= Positive0([цил_отвор_2.подход1.край.R:20],) sent,by koren.цил_отвор_2.подход1.край
s.AddConstraint( new LinearInequality( v172V_1_5)); //= Positive0([цил_отвор_2.подход1.край.преход.фаска-Алт1.dL1:1.5],) sent,by koren.цил_отвор_2.подход1.край.преход.фаска-Алт1
s.AddConstraint( new LinearInequality( v173V_1_5)); //= Positive0([цил_отвор_2.подход1.край.преход.фаска-Алт1.dL2:1.5],) sent,by koren.цил_отвор_2.подход1.край.преход.фаска-Алт1
s.AddConstraint( new LinearInequality( v171V_2_12132)); //= Positive0([цил_отвор_2.подход1.край.преход.фаска-Алт1.dL:2.12132],) sent,by koren.цил_отвор_2.подход1.край.преход.фаска-Алт1
s.AddConstraint( new LinearInequality( v94V_0)); //= Positive0([цил_отвор_2.подход2.dL:0],) sent,by koren.цил_отвор_2.подход2
s.AddConstraint( new LinearInequality( v101V_15_4)); //= Positive0([цил_отвор_3.dL:15.4],) sent,by koren.цил_отвор_3
s.AddConstraint( new LinearInequality( v107V_0)); //= Positive0([цил_отвор_3.остатък.dL:0],) sent,by koren.цил_отвор_3.остатък
s.AddConstraint( new LinearInequality( v102V_0)); //= Positive0([цил_отвор_3.подход1.dL:0],) sent,by koren.цил_отвор_3.подход1
s.AddConstraint( new LinearInequality( v103V_20)); //= Positive0([цил_отвор_3.подход1.край.R:20],) sent,by koren.цил_отвор_3.подход1.край
s.AddConstraint( new LinearInequality( v105V_0)); //= Positive0([цил_отвор_3.подход2.dL:0],) sent,by koren.цил_отвор_3.подход2
s.AddConstraint( new LinearInequality( v159V_4)); //= Positive0([цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.dL:4],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2
s.AddConstraint( new LinearInequality( v163V_4)); //= Positive0([цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.остатък.dL:4],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.остатък
s.AddConstraint( new LinearInequality( v160V_0)); //= Positive0([цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.подход1.dL:0],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.подход1
s.AddConstraint( new LinearInequality( v161V_0)); //= Positive0([цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.подход2.dL:0],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.подход2
s.AddConstraint( new LinearInequality( v162V_20)); //= Positive0([цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.подход2.край.R:20],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.дясно чело_2.подход2.край
s.AddConstraint( new LinearInequality( v146V_4)); //= Positive0([цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.dL:4],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2
s.AddConstraint( new LinearInequality( v151V_4)); //= Positive0([цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.остатък.dL:4],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.остатък
s.AddConstraint( new LinearInequality( v147V_0)); //= Positive0([цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход1.dL:0],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход1
s.AddConstraint( new LinearInequality( v148V_20)); //= Positive0([цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход1.край.R:20],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход1.край
s.AddConstraint( new LinearInequality( v150V_0)); //= Positive0([цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход2.dL:0],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.ляво чело_2.подход2
s.AddConstraint( new LinearInequality( v152V_6_4)); //= Positive0([цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.dL:6.4],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3
s.AddConstraint( new LinearInequality( v158V_6_4)); //= Positive0([цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.остатък.dL:6.4],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.остатък
s.AddConstraint( new LinearInequality( v153V_0)); //= Positive0([цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1.dL:0],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1
s.AddConstraint( new LinearInequality( v154V_24)); //= Positive0([цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1.край.R:24],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1.край
s.AddConstraint( new LinearInequality( v156V_0)); //= Positive0([цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход2.dL:0],) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход2
s.AddConstraint( new LinearInequality( v126V_0)); //= Positive0([цил_отвор_3.превкл1.вход_от.dL:0],) sent,by koren.цил_отвор_3.превкл1.вход_от
s.AddConstraint( new LinearInequality( v124V_0)); //= Positive0([цил_отвор_3.превкл1.изх_към.dL:0],) sent,by koren.цил_отвор_3.превкл1.изх_към
s.AddConstraint( new LinearInequality( v125V_6_4)); //= Positive0([цил_отвор_3.превкл1.място.dL:6.4],) sent,by koren.цил_отвор_3.превкл1.място
s.AddConstraint( new LinearInequality( v127V_9)); //= Positive0([цил_отвор_3.превкл1.остатък.dL:9],) sent,by koren.цил_отвор_3.превкл1.остатък
s.AddConstraint( new LinearInequality( v12V_12)); //= Positive0([цилиндър_1.dL:12],) sent,by koren.цилиндър_1
s.AddConstraint( new LinearInequality( v18V_10)); //= Positive0([цилиндър_1.остатък.dL:10],) sent,by koren.цилиндър_1.остатък
s.AddConstraint( new LinearInequality( v13V_2)); //= Positive0([цилиндър_1.подход1.dL:2],) sent,by koren.цилиндър_1.подход1
s.AddConstraint( new LinearInequality( v14V_41)); //= Positive0([цилиндър_1.подход1.край.R:41],) sent,by koren.цилиндър_1.подход1.край
s.AddConstraint( new LinearInequality( v168V_2)); //= Positive0([цилиндър_1.подход1.край.преход.фаска-Алт2.dL1:2],) sent,by koren.цилиндър_1.подход1.край.преход.фаска-Алт2
s.AddConstraint( new LinearInequality( v169V_2)); //= Positive0([цилиндър_1.подход1.край.преход.фаска-Алт2.dL2:2],) sent,by koren.цилиндър_1.подход1.край.преход.фаска-Алт2
s.AddConstraint( new LinearInequality( v167V_2_82843)); //= Positive0([цилиндър_1.подход1.край.преход.фаска-Алт2.dL:2.82843],) sent,by koren.цилиндър_1.подход1.край.преход.фаска-Алт2
s.AddConstraint( new LinearInequality( v16V_0)); //= Positive0([цилиндър_1.подход2.dL:0],) sent,by koren.цилиндър_1.подход2
s.AddConstraint( new LinearInequality( v28V_2)); //= Positive0([цилиндър_2.dL:2],) sent,by koren.цилиндър_2
s.AddConstraint( new LinearInequality( v34V_1)); //= Positive0([цилиндър_2.остатък.dL:1],) sent,by koren.цилиндър_2.остатък
s.AddConstraint( new LinearInequality( v29V_1)); //= Positive0([цилиндър_2.подход1.dL:1],) sent,by koren.цилиндър_2.подход1
s.AddConstraint( new LinearInequality( v30V_35_5)); //= Positive0([цилиндър_2.подход1.край.R:35.5],) sent,by koren.цилиндър_2.подход1.край
s.AddConstraint( new LinearInequality( v170V_1)); //= Positive0([цилиндър_2.подход1.край.преход.закръгление-Алт1.r:1],) sent,by koren.цилиндър_2.подход1.край.преход.закръгление-Алт1
s.AddConstraint( new LinearInequality( v32V_0)); //= Positive0([цилиндър_2.подход2.dL:0],) sent,by koren.цилиндър_2.подход2
s.AddConstraint( new LinearInequality( v41V_25_5)); //= Positive0([цилиндър_3.dL:25.5],) sent,by koren.цилиндър_3
s.AddConstraint( new LinearInequality( v47V_25_5)); //= Positive0([цилиндър_3.остатък.dL:25.5],) sent,by koren.цилиндър_3.остатък
s.AddConstraint( new LinearInequality( v42V_0)); //= Positive0([цилиндър_3.подход1.dL:0],) sent,by koren.цилиндър_3.подход1
s.AddConstraint( new LinearInequality( v43V_37_5)); //= Positive0([цилиндър_3.подход1.край.R:37.5],) sent,by koren.цилиндър_3.подход1.край
s.AddConstraint( new LinearInequality( v45V_0)); //= Positive0([цилиндър_3.подход2.dL:0],) sent,by koren.цилиндър_3.подход2
s.AddConstraint( new LinearInequality( v60V_13)); //= Positive0([цилиндър_4.dL:13],) sent,by koren.цилиндър_4
s.AddConstraint( new LinearInequality( v66V_13)); //= Positive0([цилиндър_4.остатък.dL:13],) sent,by koren.цилиндър_4.остатък
s.AddConstraint( new LinearInequality( v61V_0)); //= Positive0([цилиндър_4.подход1.dL:0],) sent,by koren.цилиндър_4.подход1
s.AddConstraint( new LinearInequality( v62V_35)); //= Positive0([цилиндър_4.подход1.край.R:35],) sent,by koren.цилиндър_4.подход1.край
s.AddConstraint( new LinearInequality( v64V_0)); //= Positive0([цилиндър_4.подход2.dL:0],) sent,by koren.цилиндър_4.подход2
s.AddConstraint( new LinearInequality( v71V_8)); //= Positive0([цилиндър_5.dL:8],) sent,by koren.цилиндър_5
s.AddConstraint( new LinearInequality( v77V_0)); //= Positive0([цилиндър_5.остатък.dL:0],) sent,by koren.цилиндър_5.остатък
s.AddConstraint( new LinearInequality( v72V_0)); //= Positive0([цилиндър_5.подход1.dL:0],) sent,by koren.цилиндър_5.подход1
s.AddConstraint( new LinearInequality( v73V_34_9)); //= Positive0([цилиндър_5.подход1.край.R:34.9],) sent,by koren.цилиндър_5.подход1.край
s.AddConstraint( new LinearInequality( v75V_0)); //= Positive0([цилиндър_5.подход2.dL:0],) sent,by koren.цилиндър_5.подход2
s.AddConstraint( new LinearInequality( v128V_2_35)); //= Positive0([цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.dL:2.35],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2
s.AddConstraint( new LinearInequality( v133V_2_15)); //= Positive0([цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.остатък.dL:2.15],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.остатък
s.AddConstraint( new LinearInequality( v129V_0)); //= Positive0([цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход1.dL:0],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход1
s.AddConstraint( new LinearInequality( v130V_34_9)); //= Positive0([цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход1.край.R:34.9],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход1.край
s.AddConstraint( new LinearInequality( v132V_0_2)); //= Positive0([цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход2.dL:0.2],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.дясно чело_2.подход2
s.AddConstraint( new LinearInequality( v141V_2_35)); //= Positive0([цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.dL:2.35],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2
s.AddConstraint( new LinearInequality( v145V_2_15)); //= Positive0([цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.остатък.dL:2.15],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.остатък
s.AddConstraint( new LinearInequality( v142V_0_2)); //= Positive0([цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.подход1.dL:0.2],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.подход1
s.AddConstraint( new LinearInequality( v143V_0)); //= Positive0([цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.подход2.dL:0],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.подход2
s.AddConstraint( new LinearInequality( v144V_34_9)); //= Positive0([цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.подход2.край.R:34.9],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.ляво чело_2.подход2.край
s.AddConstraint( new LinearInequality( v134V_4)); //= Positive0([цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.dL:4],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2
s.AddConstraint( new LinearInequality( v140V_3_6)); //= Positive0([цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.остатък.dL:3.6],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.остатък
s.AddConstraint( new LinearInequality( v135V_0_2)); //= Positive0([цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.dL:0.2],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1
s.AddConstraint( new LinearInequality( v136V_32_55)); //= Positive0([цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край.R:32.55],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край
s.AddConstraint( new LinearInequality( v174V_0_2)); //= Positive0([цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край.преход.закръгление-Алт1.r:0.2],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край.преход.закръгление-Алт1
s.AddConstraint( new LinearInequality( v138V_0_2)); //= Positive0([цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход2.dL:0.2],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход2
s.AddConstraint( new LinearInequality( v175V_0_2)); //= Positive0([цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход2.край.преход.закръгление-Алт1.r:0.2],) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход2.край.преход.закръгление-Алт1
s.AddConstraint( new LinearInequality( v122V_0)); //= Positive0([цилиндър_5.превкл1.вход_от.dL:0],) sent,by koren.цилиндър_5.превкл1.вход_от
s.AddConstraint( new LinearInequality( v120V_0)); //= Positive0([цилиндър_5.превкл1.изх_към.dL:0],) sent,by koren.цилиндър_5.превкл1.изх_към
s.AddConstraint( new LinearInequality( v121V_4)); //= Positive0([цилиндър_5.превкл1.място.dL:4],) sent,by koren.цилиндър_5.превкл1.място
s.AddConstraint( new LinearInequality( v123V_4)); //= Positive0([цилиндър_5.превкл1.остатък.dL:4],) sent,by koren.цилиндър_5.превкл1.остатък
s.AddConstraint( new LinearEquation( v1V_7, 7.0)); //v= Eq0([00_1.dL:7],7.0,) sent,by koren.00_1
s.AddConstraint( new LinearEquation( v3V_25, 25.0)); //v= Eq0([00_1.подход1.край.R:25],25.0,) sent,by koren.00_1.подход1.край
s.AddConstraint( new LinearEquation( v6V_0, 0.0)); //v= Eq0([00_1.подход2.край.X:0],0.0,) sent,by koren.00_1.подход2.край
s.AddConstraint( new LinearEquation( v14V_41, 41.0)); //v= Eq0([цилиндър_1.подход1.край.R:41],41.0,) sent,by koren.цилиндър_1.подход1.край
s.AddConstraint( new LinearEquation( v30V_35_5, 35.5)); //v= Eq0([цилиндър_2.подход1.край.R:35.5],35.5,) sent,by koren.цилиндър_2.подход1.край
s.AddConstraint( new LinearEquation( v56V_0, 0.0)); //v= Eq0([дясно чело_3.dL:0],0.0,) sent,by koren.дясно чело_3
s.AddConstraint( new LinearEquation( v62V_35, 35.0)); //v= Eq0([цилиндър_4.подход1.край.R:35],35.0,) sent,by koren.цилиндър_4.подход1.край
s.AddConstraint( new LinearEquation( v73V_34_9, 34.9)); //v= Eq0([цилиндър_5.подход1.край.R:34.9],34.9,) sent,by koren.цилиндър_5.подход1.край
s.AddConstraint( new LinearEquation( v79V_5, 5.0)); //v= Eq0([конус_3.dX:5],5.0,) sent,by koren.конус_3
s.AddConstraint( new LinearEquation( v92V_20, 20.0)); //v= Eq0([цил_отвор_2.подход1.край.R:20],20.0,) sent,by koren.цил_отвор_2.подход1.край
s.AddConstraint( new LinearEquation( v97V_0, 0.0)); //v= Eq0([ляво чело_3.dL:0],0.0,) sent,by koren.ляво чело_3
s.AddConstraint( new LinearEquation( v134V_4, 4.0)); //v= Eq0([цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.dL:4],4.0,) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2
s.AddConstraint( new LinearEquation( v136V_32_55, 32.55)); //v= Eq0([цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край.R:32.55],32.55,) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край
s.AddConstraint( new LinearEquation( v152V_6_4, 6.4)); //v= Eq0([цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.dL:6.4],6.4,) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3
s.AddConstraint( new LinearEquation( v154V_24, 24.0)); //v= Eq0([цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1.край.R:24],24.0,) sent,by koren.цил_отвор_3.превкл1.KVtMan-Алт1.цил_отвор_3.подход1.край
s.AddConstraint( new LinearEquation( v165V_1, 1.0)); //v= Eq0([00_1.подход2.край.преход.фаска-Алт1.dL1:1],1.0,) sent,by koren.00_1.подход2.край.преход.фаска-Алт1
s.AddConstraint( new LinearEquation( v168V_2, 2.0)); //v= Eq0([цилиндър_1.подход1.край.преход.фаска-Алт2.dL1:2],2.0,) sent,by koren.цилиндър_1.подход1.край.преход.фаска-Алт2
s.AddConstraint( new LinearEquation( v170V_1, 1.0)); //v= Eq0([цилиндър_2.подход1.край.преход.закръгление-Алт1.r:1],1.0,) sent,by koren.цилиндър_2.подход1.край.преход.закръгление-Алт1
s.AddConstraint( new LinearEquation( v173V_1_5, 1.5)); //v= Eq0([цил_отвор_2.подход1.край.преход.фаска-Алт1.dL2:1.5],1.5,) sent,by koren.цил_отвор_2.подход1.край.преход.фаска-Алт1
s.AddConstraint( new LinearEquation( v174V_0_2, 0.2)); //v= Eq0([цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край.преход.закръгление-Алт1.r:0.2],0.2,) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход1.край.преход.закръгление-Алт1
s.AddConstraint( new LinearEquation( v175V_0_2, 0.2)); //v= Eq0([цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход2.край.преход.закръгление-Алт1.r:0.2],0.2,) sent,by koren.цилиндър_5.превкл1.KVnO-Алт1.цилиндър_2.подход2.край.преход.закръгление-Алт1
s.AddConstraint( new LinearEquation( v176V_0, 0.0)); //v= Eq0([размери.размер_dR_2.v:0],0.0,) sent,by koren.размери.размер_dR_2
s.AddConstraint( new LinearEquation( v177V_13, 13.0)); //v= Eq0([размери.размер_dX_1.v:13],13.0,) sent,by koren.размери.размер_dX_1
s.AddConstraint( new LinearEquation( v178V_26, 26.0)); //v= Eq0([размери.размер_dX_2.v:26],26.0,) sent,by koren.размери.размер_dX_2
s.AddConstraint( new LinearEquation( v179V_58, 58.0)); //v= Eq0([размери.размер_dX_3.v:58],58.0,) sent,by koren.размери.размер_dX_3
s.AddConstraint( new LinearEquation( v180V_70, 70.0)); //v= Eq0([размери.размер_dX_4.v:70],70.0,) sent,by koren.размери.размер_dX_4
s.AddConstraint( new LinearEquation( v181V_4, 4.0)); //v= Eq0([размери.размер_dX_5.v:4],4.0,) sent,by koren.размери.размер_dX_5
s.AddConstraint( new LinearEquation( v182V_75, 75.0)); //v= Eq0([размери.резбаD_1.v_input:75],75.0,) sent,by koren.размери.резбаD_1
s.AddConstraint( new LinearEquation( v183V_0, 0.0)); //v= Eq0([размери.размер_dX_8.v:0],0.0,) sent,by koren.размери.размер_dX_8
s.AddConstraint( new LinearEquation( v184V_0, 0.0)); //v= Eq0([размери.размер_dX_10.v:0],0.0,) sent,by koren.размери.размер_dX_10
s.AddConstraint( new LinearEquation( v185V_22_4, 22.4)); //v= Eq0([размери.размер_dX_11.v:22.4],22.4,) sent,by koren.размери.размер_dX_11

#define EQ(x,y) (((x<y)?(y-x):(x-y))<1e-5)
  if (!EQ(v100V_0.Value(),0))  cout << "diff " << v100V_0 << 0 <<endl;
  if (!EQ(v101V_15_4.Value(),15.4))  cout << "diff " << v101V_15_4 << 15.4 <<endl;
  if (!EQ(v102V_0.Value(),0))  cout << "diff " << v102V_0 << 0 <<endl;
  if (!EQ(v103V_20.Value(),20))  cout << "diff " << v103V_20 << 20 <<endl;
  if (!EQ(v104V_22_4.Value(),22.4))  cout << "diff " << v104V_22_4 << 22.4 <<endl;
  if (!EQ(v105V_0.Value(),0))  cout << "diff " << v105V_0 << 0 <<endl;
  if (!EQ(v106V_7.Value(),7))  cout << "diff " << v106V_7 << 7 <<endl;
  if (!EQ(v107V_0.Value(),0))  cout << "diff " << v107V_0 << 0 <<endl;
  if (!EQ(v108V_5.Value(),5))  cout << "diff " << v108V_5 << 5 <<endl;
  if (!EQ(v109V_0.Value(),0))  cout << "diff " << v109V_0 << 0 <<endl;
  if (!EQ(v10V_2.Value(),2))  cout << "diff " << v10V_2 << 2 <<endl;
  if (!EQ(v110V_0.Value(),0))  cout << "diff " << v110V_0 << 0 <<endl;
  if (!EQ(v111V_5.Value(),5))  cout << "diff " << v111V_5 << 5 <<endl;
  if (!EQ(v112V_0.Value(),0))  cout << "diff " << v112V_0 << 0 <<endl;
  if (!EQ(v113V_25.Value(),25))  cout << "diff " << v113V_25 << 25 <<endl;
  if (!EQ(v114V_1.Value(),1))  cout << "diff " << v114V_1 << 1 <<endl;
  if (!EQ(v115V_0.Value(),0))  cout << "diff " << v115V_0 << 0 <<endl;
  if (!EQ(v116V_0.Value(),0))  cout << "diff " << v116V_0 << 0 <<endl;
  if (!EQ(v117V_25.Value(),25))  cout << "diff " << v117V_25 << 25 <<endl;
  if (!EQ(v118V_1.Value(),1))  cout << "diff " << v118V_1 << 1 <<endl;
  if (!EQ(v119V_0.Value(),0))  cout << "diff " << v119V_0 << 0 <<endl;
  if (!EQ(v11V_13_7321.Value(),13.7321))  cout << "diff " << v11V_13_7321 << 13.7321 <<endl;
  if (!EQ(v120V_0.Value(),0))  cout << "diff " << v120V_0 << 0 <<endl;
  if (!EQ(v121V_4.Value(),4))  cout << "diff " << v121V_4 << 4 <<endl;
  if (!EQ(v122V_0.Value(),0))  cout << "diff " << v122V_0 << 0 <<endl;
  if (!EQ(v123V_4.Value(),4))  cout << "diff " << v123V_4 << 4 <<endl;
  if (!EQ(v124V_0.Value(),0))  cout << "diff " << v124V_0 << 0 <<endl;
  if (!EQ(v125V_6_4.Value(),6.4))  cout << "diff " << v125V_6_4 << 6.4 <<endl;
  if (!EQ(v126V_0.Value(),0))  cout << "diff " << v126V_0 << 0 <<endl;
  if (!EQ(v127V_9.Value(),9))  cout << "diff " << v127V_9 << 9 <<endl;
  if (!EQ(v128V_2_35.Value(),2.35))  cout << "diff " << v128V_2_35 << 2.35 <<endl;
  if (!EQ(v129V_0.Value(),0))  cout << "diff " << v129V_0 << 0 <<endl;
  if (!EQ(v12V_12.Value(),12))  cout << "diff " << v12V_12 << 12 <<endl;
  if (!EQ(v130V_34_9.Value(),34.9))  cout << "diff " << v130V_34_9 << 34.9 <<endl;
  if (!EQ(v131V_57.Value(),57))  cout << "diff " << v131V_57 << 57 <<endl;
  if (!EQ(v132V_0_2.Value(),0.2))  cout << "diff " << v132V_0_2 << 0.2 <<endl;
  if (!EQ(v133V_2_15.Value(),2.15))  cout << "diff " << v133V_2_15 << 2.15 <<endl;
  if (!EQ(v134V_4.Value(),4))  cout << "diff " << v134V_4 << 4 <<endl;
  if (!EQ(v135V_0_2.Value(),0.2))  cout << "diff " << v135V_0_2 << 0.2 <<endl;
  if (!EQ(v136V_32_55.Value(),32.55))  cout << "diff " << v136V_32_55 << 32.55 <<endl;
  if (!EQ(v137V_57.Value(),57))  cout << "diff " << v137V_57 << 57 <<endl;
  if (!EQ(v138V_0_2.Value(),0.2))  cout << "diff " << v138V_0_2 << 0.2 <<endl;
  if (!EQ(v139V_61.Value(),61))  cout << "diff " << v139V_61 << 61 <<endl;
  if (!EQ(v13V_2.Value(),2))  cout << "diff " << v13V_2 << 2 <<endl;
  if (!EQ(v140V_3_6.Value(),3.6))  cout << "diff " << v140V_3_6 << 3.6 <<endl;
  if (!EQ(v141V_2_35.Value(),2.35))  cout << "diff " << v141V_2_35 << 2.35 <<endl;
  if (!EQ(v142V_0_2.Value(),0.2))  cout << "diff " << v142V_0_2 << 0.2 <<endl;
  if (!EQ(v143V_0.Value(),0))  cout << "diff " << v143V_0 << 0 <<endl;
  if (!EQ(v144V_34_9.Value(),34.9))  cout << "diff " << v144V_34_9 << 34.9 <<endl;
  if (!EQ(v145V_2_15.Value(),2.15))  cout << "diff " << v145V_2_15 << 2.15 <<endl;
  if (!EQ(v146V_4.Value(),4))  cout << "diff " << v146V_4 << 4 <<endl;
  if (!EQ(v147V_0.Value(),0))  cout << "diff " << v147V_0 << 0 <<endl;
  if (!EQ(v148V_20.Value(),20))  cout << "diff " << v148V_20 << 20 <<endl;
  if (!EQ(v149V_22_4.Value(),22.4))  cout << "diff " << v149V_22_4 << 22.4 <<endl;
  if (!EQ(v14V_41.Value(),41))  cout << "diff " << v14V_41 << 41 <<endl;
  if (!EQ(v150V_0.Value(),0))  cout << "diff " << v150V_0 << 0 <<endl;
  if (!EQ(v151V_4.Value(),4))  cout << "diff " << v151V_4 << 4 <<endl;
  if (!EQ(v152V_6_4.Value(),6.4))  cout << "diff " << v152V_6_4 << 6.4 <<endl;
  if (!EQ(v153V_0.Value(),0))  cout << "diff " << v153V_0 << 0 <<endl;
  if (!EQ(v154V_24.Value(),24))  cout << "diff " << v154V_24 << 24 <<endl;
  if (!EQ(v155V_22_4.Value(),22.4))  cout << "diff " << v155V_22_4 << 22.4 <<endl;
  if (!EQ(v156V_0.Value(),0))  cout << "diff " << v156V_0 << 0 <<endl;
  if (!EQ(v157V_16.Value(),16))  cout << "diff " << v157V_16 << 16 <<endl;
  if (!EQ(v158V_6_4.Value(),6.4))  cout << "diff " << v158V_6_4 << 6.4 <<endl;
  if (!EQ(v159V_4.Value(),4))  cout << "diff " << v159V_4 << 4 <<endl;
  if (!EQ(v15V_0.Value(),0))  cout << "diff " << v15V_0 << 0 <<endl;
  if (!EQ(v160V_0.Value(),0))  cout << "diff " << v160V_0 << 0 <<endl;
  if (!EQ(v161V_0.Value(),0))  cout << "diff " << v161V_0 << 0 <<endl;
  if (!EQ(v162V_20.Value(),20))  cout << "diff " << v162V_20 << 20 <<endl;
  if (!EQ(v163V_4.Value(),4))  cout << "diff " << v163V_4 << 4 <<endl;
  if (!EQ(v164V_1_03528.Value(),1.03528))  cout << "diff " << v164V_1_03528 << 1.03528 <<endl;
  if (!EQ(v165V_1.Value(),1))  cout << "diff " << v165V_1 << 1 <<endl;
  if (!EQ(v166V_0_267949.Value(),0.267949))  cout << "diff " << v166V_0_267949 << 0.267949 <<endl;
  if (!EQ(v167V_2_82843.Value(),2.82843))  cout << "diff " << v167V_2_82843 << 2.82843 <<endl;
  if (!EQ(v168V_2.Value(),2))  cout << "diff " << v168V_2 << 2 <<endl;
  if (!EQ(v169V_2.Value(),2))  cout << "diff " << v169V_2 << 2 <<endl;
  if (!EQ(v16V_0.Value(),0))  cout << "diff " << v16V_0 << 0 <<endl;
  if (!EQ(v170V_1.Value(),1))  cout << "diff " << v170V_1 << 1 <<endl;
  if (!EQ(v171V_2_12132.Value(),2.12132))  cout << "diff " << v171V_2_12132 << 2.12132 <<endl;
  if (!EQ(v172V_1_5.Value(),1.5))  cout << "diff " << v172V_1_5 << 1.5 <<endl;
  if (!EQ(v173V_1_5.Value(),1.5))  cout << "diff " << v173V_1_5 << 1.5 <<endl;
  if (!EQ(v174V_0_2.Value(),0.2))  cout << "diff " << v174V_0_2 << 0.2 <<endl;
  if (!EQ(v175V_0_2.Value(),0.2))  cout << "diff " << v175V_0_2 << 0.2 <<endl;
  if (!EQ(v176V_0.Value(),0))  cout << "diff " << v176V_0 << 0 <<endl;
  if (!EQ(v177V_13.Value(),13))  cout << "diff " << v177V_13 << 13 <<endl;
  if (!EQ(v178V_26.Value(),26))  cout << "diff " << v178V_26 << 26 <<endl;
  if (!EQ(v179V_58.Value(),58))  cout << "diff " << v179V_58 << 58 <<endl;
  if (!EQ(v17V_12.Value(),12))  cout << "diff " << v17V_12 << 12 <<endl;
  if (!EQ(v180V_70.Value(),70))  cout << "diff " << v180V_70 << 70 <<endl;
  if (!EQ(v181V_4.Value(),4))  cout << "diff " << v181V_4 << 4 <<endl;
  if (!EQ(v182V_75.Value(),75))  cout << "diff " << v182V_75 << 75 <<endl;
  if (!EQ(v183V_0.Value(),0))  cout << "diff " << v183V_0 << 0 <<endl;
  if (!EQ(v184V_0.Value(),0))  cout << "diff " << v184V_0 << 0 <<endl;
  if (!EQ(v185V_22_4.Value(),22.4))  cout << "diff " << v185V_22_4 << 22.4 <<endl;
  if (!EQ(v18V_10.Value(),10))  cout << "diff " << v18V_10 << 10 <<endl;
  if (!EQ(v19V_3_5.Value(),3.5))  cout << "diff " << v19V_3_5 << 3.5 <<endl;
  if (!EQ(v1V_7.Value(),7))  cout << "diff " << v1V_7 << 7 <<endl;
  if (!EQ(v20V_0.Value(),0))  cout << "diff " << v20V_0 << 0 <<endl;
  if (!EQ(v21V_0.Value(),0))  cout << "diff " << v21V_0 << 0 <<endl;
  if (!EQ(v22V_37_5.Value(),37.5))  cout << "diff " << v22V_37_5 << 37.5 <<endl;
  if (!EQ(v23V_3_5.Value(),3.5))  cout << "diff " << v23V_3_5 << 3.5 <<endl;
  if (!EQ(v24V_2.Value(),2))  cout << "diff " << v24V_2 << 2 <<endl;
  if (!EQ(v25V_0.Value(),0))  cout << "diff " << v25V_0 << 0 <<endl;
  if (!EQ(v26V_1.Value(),1))  cout << "diff " << v26V_1 << 1 <<endl;
  if (!EQ(v27V_1.Value(),1))  cout << "diff " << v27V_1 << 1 <<endl;
  if (!EQ(v28V_2.Value(),2))  cout << "diff " << v28V_2 << 2 <<endl;
  if (!EQ(v29V_1.Value(),1))  cout << "diff " << v29V_1 << 1 <<endl;
  if (!EQ(v2V_0.Value(),0))  cout << "diff " << v2V_0 << 0 <<endl;
  if (!EQ(v30V_35_5.Value(),35.5))  cout << "diff " << v30V_35_5 << 35.5 <<endl;
  if (!EQ(v31V_12.Value(),12))  cout << "diff " << v31V_12 << 12 <<endl;
  if (!EQ(v32V_0.Value(),0))  cout << "diff " << v32V_0 << 0 <<endl;
  if (!EQ(v33V_14.Value(),14))  cout << "diff " << v33V_14 << 14 <<endl;
  if (!EQ(v34V_1.Value(),1))  cout << "diff " << v34V_1 << 1 <<endl;
  if (!EQ(v35V_2_82843.Value(),2.82843))  cout << "diff " << v35V_2_82843 << 2.82843 <<endl;
  if (!EQ(v36V_2.Value(),2))  cout << "diff " << v36V_2 << 2 <<endl;
  if (!EQ(v37V_2.Value(),2))  cout << "diff " << v37V_2 << 2 <<endl;
  if (!EQ(v38V_0.Value(),0))  cout << "diff " << v38V_0 << 0 <<endl;
  if (!EQ(v39V_0.Value(),0))  cout << "diff " << v39V_0 << 0 <<endl;
  if (!EQ(v3V_25.Value(),25))  cout << "diff " << v3V_25 << 25 <<endl;
  if (!EQ(v40V_2_82843.Value(),2.82843))  cout << "diff " << v40V_2_82843 << 2.82843 <<endl;
  if (!EQ(v41V_25_5.Value(),25.5))  cout << "diff " << v41V_25_5 << 25.5 <<endl;
  if (!EQ(v42V_0.Value(),0))  cout << "diff " << v42V_0 << 0 <<endl;
  if (!EQ(v43V_37_5.Value(),37.5))  cout << "diff " << v43V_37_5 << 37.5 <<endl;
  if (!EQ(v44V_16.Value(),16))  cout << "diff " << v44V_16 << 16 <<endl;
  if (!EQ(v45V_0.Value(),0))  cout << "diff " << v45V_0 << 0 <<endl;
  if (!EQ(v46V_41_5.Value(),41.5))  cout << "diff " << v46V_41_5 << 41.5 <<endl;
  if (!EQ(v47V_25_5.Value(),25.5))  cout << "diff " << v47V_25_5 << 25.5 <<endl;
  if (!EQ(v48V_3_53553.Value(),3.53553))  cout << "diff " << v48V_3_53553 << 3.53553 <<endl;
  if (!EQ(v49V_2_5.Value(),2.5))  cout << "diff " << v49V_2_5 << 2.5 <<endl;
  if (!EQ(v4V_7.Value(),7))  cout << "diff " << v4V_7 << 7 <<endl;
  if (!EQ(v50V__2_5.Value(),-2.5))  cout << "diff " << v50V__2_5 << -2.5 <<endl;
  if (!EQ(v51V_0.Value(),0))  cout << "diff " << v51V_0 << 0 <<endl;
  if (!EQ(v52V_0.Value(),0))  cout << "diff " << v52V_0 << 0 <<endl;
  if (!EQ(v53V_35.Value(),35))  cout << "diff " << v53V_35 << 35 <<endl;
  if (!EQ(v54V_44.Value(),44))  cout << "diff " << v54V_44 << 44 <<endl;
  if (!EQ(v55V_3_53553.Value(),3.53553))  cout << "diff " << v55V_3_53553 << 3.53553 <<endl;
  if (!EQ(v56V_0.Value(),0))  cout << "diff " << v56V_0 << 0 <<endl;
  if (!EQ(v57V_0.Value(),0))  cout << "diff " << v57V_0 << 0 <<endl;
  if (!EQ(v58V_0.Value(),0))  cout << "diff " << v58V_0 << 0 <<endl;
  if (!EQ(v59V_0.Value(),0))  cout << "diff " << v59V_0 << 0 <<endl;
  if (!EQ(v5V_1.Value(),1))  cout << "diff " << v5V_1 << 1 <<endl;
  if (!EQ(v60V_13.Value(),13))  cout << "diff " << v60V_13 << 13 <<endl;
  if (!EQ(v61V_0.Value(),0))  cout << "diff " << v61V_0 << 0 <<endl;
  if (!EQ(v62V_35.Value(),35))  cout << "diff " << v62V_35 << 35 <<endl;
  if (!EQ(v63V_44.Value(),44))  cout << "diff " << v63V_44 << 44 <<endl;
  if (!EQ(v64V_0.Value(),0))  cout << "diff " << v64V_0 << 0 <<endl;
  if (!EQ(v65V_57.Value(),57))  cout << "diff " << v65V_57 << 57 <<endl;
  if (!EQ(v66V_13.Value(),13))  cout << "diff " << v66V_13 << 13 <<endl;
  if (!EQ(v67V_0_1.Value(),0.1))  cout << "diff " << v67V_0_1 << 0.1 <<endl;
  if (!EQ(v68V_0.Value(),0))  cout << "diff " << v68V_0 << 0 <<endl;
  if (!EQ(v69V_0.Value(),0))  cout << "diff " << v69V_0 << 0 <<endl;
  if (!EQ(v6V_0.Value(),0))  cout << "diff " << v6V_0 << 0 <<endl;
  if (!EQ(v70V_0_1.Value(),0.1))  cout << "diff " << v70V_0_1 << 0.1 <<endl;
  if (!EQ(v71V_8.Value(),8))  cout << "diff " << v71V_8 << 8 <<endl;
  if (!EQ(v72V_0.Value(),0))  cout << "diff " << v72V_0 << 0 <<endl;
  if (!EQ(v73V_34_9.Value(),34.9))  cout << "diff " << v73V_34_9 << 34.9 <<endl;
  if (!EQ(v74V_57.Value(),57))  cout << "diff " << v74V_57 << 57 <<endl;
  if (!EQ(v75V_0.Value(),0))  cout << "diff " << v75V_0 << 0 <<endl;
  if (!EQ(v76V_65.Value(),65))  cout << "diff " << v76V_65 << 65 <<endl;
  if (!EQ(v77V_0.Value(),0))  cout << "diff " << v77V_0 << 0 <<endl;
  if (!EQ(v78V_7_07107.Value(),7.07107))  cout << "diff " << v78V_7_07107 << 7.07107 <<endl;
  if (!EQ(v79V_5.Value(),5))  cout << "diff " << v79V_5 << 5 <<endl;
  if (!EQ(v7V_6.Value(),6))  cout << "diff " << v7V_6 << 6 <<endl;
  if (!EQ(v80V__5.Value(),-5))  cout << "diff " << v80V__5 << -5 <<endl;
  if (!EQ(v81V_0.Value(),0))  cout << "diff " << v81V_0 << 0 <<endl;
  if (!EQ(v82V_0.Value(),0))  cout << "diff " << v82V_0 << 0 <<endl;
  if (!EQ(v83V_29_9.Value(),29.9))  cout << "diff " << v83V_29_9 << 29.9 <<endl;
  if (!EQ(v84V_70.Value(),70))  cout << "diff " << v84V_70 << 70 <<endl;
  if (!EQ(v85V_7_07107.Value(),7.07107))  cout << "diff " << v85V_7_07107 << 7.07107 <<endl;
  if (!EQ(v86V_9_9.Value(),9.9))  cout << "diff " << v86V_9_9 << 9.9 <<endl;
  if (!EQ(v87V_0.Value(),0))  cout << "diff " << v87V_0 << 0 <<endl;
  if (!EQ(v88V_1_5.Value(),1.5))  cout << "diff " << v88V_1_5 << 1.5 <<endl;
  if (!EQ(v89V_8_4.Value(),8.4))  cout << "diff " << v89V_8_4 << 8.4 <<endl;
  if (!EQ(v8V_16.Value(),16))  cout << "diff " << v8V_16 << 16 <<endl;
  if (!EQ(v90V_47_6.Value(),47.6))  cout << "diff " << v90V_47_6 << 47.6 <<endl;
  if (!EQ(v91V_1_5.Value(),1.5))  cout << "diff " << v91V_1_5 << 1.5 <<endl;
  if (!EQ(v92V_20.Value(),20))  cout << "diff " << v92V_20 << 20 <<endl;
  if (!EQ(v93V_70.Value(),70))  cout << "diff " << v93V_70 << 70 <<endl;
  if (!EQ(v94V_0.Value(),0))  cout << "diff " << v94V_0 << 0 <<endl;
  if (!EQ(v95V_22_4.Value(),22.4))  cout << "diff " << v95V_22_4 << 22.4 <<endl;
  if (!EQ(v96V_46_1.Value(),46.1))  cout << "diff " << v96V_46_1 << 46.1 <<endl;
  if (!EQ(v97V_0.Value(),0))  cout << "diff " << v97V_0 << 0 <<endl;
  if (!EQ(v98V_0.Value(),0))  cout << "diff " << v98V_0 << 0 <<endl;
  if (!EQ(v99V_0.Value(),0))  cout << "diff " << v99V_0 << 0 <<endl;
  if (!EQ(v9V_0_267949.Value(),0.267949))  cout << "diff " << v9V_0_267949 << 0.267949 <<endl;
}
int main() {
  for (int i=10;i--;) { cout<<i<<endl;
    SimplexSolver s;
	  model(s);
  }
  return 0;
}
