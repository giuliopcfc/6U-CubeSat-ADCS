  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.data
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% rtP.RandomNumber1_Mean
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.RandomNumber1_StdDev
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.RandomNumber1_Seed
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 4;
	
	  ;% rtP.RandomNumber_Mean
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 7;
	
	  ;% rtP.RandomNumber_StdDev
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 8;
	
	  ;% rtP.RandomNumber_Seed
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 16;
	
	  ;% rtP.RandomNumber1_Mean_bjj4nzkohe
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 24;
	
	  ;% rtP.RandomNumber1_StdDev_pxu4l4yv2r
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 25;
	
	  ;% rtP.RandomNumber1_Seed_cspndgusfq
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 29;
	
	  ;% rtP.UniformRandomNumber_Minimum
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 33;
	
	  ;% rtP.UniformRandomNumber_Maximum
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 34;
	
	  ;% rtP.UniformRandomNumber_Seed
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 35;
	
	  ;% rtP.RandomNumber_Mean_jleeh3nxmy
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 43;
	
	  ;% rtP.RandomNumber_StdDev_fffkyslftj
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 44;
	
	  ;% rtP.RandomNumber_Seed_g3q3oeokt3
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 47;
	
	  ;% rtP.RandomNumber1_Mean_dlj5kv1b54
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 50;
	
	  ;% rtP.RandomNumber1_StdDev_lesrfxv0lg
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 51;
	
	  ;% rtP.RandomNumber1_Seed_ow4kdudteh
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 54;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 14;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 30;
      section.data(30)  = dumData; %prealloc
      
	  ;% rtB.haaoe3krmo
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.izl1q5sazi
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 9;
	
	  ;% rtB.p51cv010io
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 10;
	
	  ;% rtB.jpaphc4vt2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 13;
	
	  ;% rtB.nxkkb43lmg
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 16;
	
	  ;% rtB.kj0hrlovtd
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 19;
	
	  ;% rtB.jnakfltztn
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 22;
	
	  ;% rtB.ehirxkx1np
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 25;
	
	  ;% rtB.k0b2i5iiue
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 28;
	
	  ;% rtB.fonazkfutz
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 37;
	
	  ;% rtB.n4mzmf5vo5
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 46;
	
	  ;% rtB.d4wo1qk3qg
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 47;
	
	  ;% rtB.n4ileghqyp
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 50;
	
	  ;% rtB.p0sytp1tyb
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 51;
	
	  ;% rtB.dam0bfwzoj
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 54;
	
	  ;% rtB.mk02jshpdk
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 57;
	
	  ;% rtB.apuiamofe1
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 60;
	
	  ;% rtB.lo3kkfxdkz
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 63;
	
	  ;% rtB.hla54xlqcw
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 66;
	
	  ;% rtB.dk2a4uugl1
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 69;
	
	  ;% rtB.ex4pku1fge
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 72;
	
	  ;% rtB.jx5wap4com
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 75;
	
	  ;% rtB.ap5nsqw1en
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 78;
	
	  ;% rtB.fd3qlfq0pf
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 81;
	
	  ;% rtB.mymck1p5dr
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 90;
	
	  ;% rtB.gkxr4i513p
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 99;
	
	  ;% rtB.d155gslfmi
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 100;
	
	  ;% rtB.kokf4n2mhf
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 109;
	
	  ;% rtB.gdcysdgjg5
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 112;
	
	  ;% rtB.hpj2uj2i4a
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 121;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.mkszl352m3
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.eje25gfouo.g540wbqcci
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.nzapizli54.fws4iwogpu
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtB.hid2a3ighm.a4etz1spm4
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.hid2a3ighm.edrpaasu4j
	  section.data(2).logicalSrcIdx = 34;
	  section.data(2).dtTransOffset = 3;
	
	  ;% rtB.hid2a3ighm.nmcsp5dcxo
	  section.data(3).logicalSrcIdx = 35;
	  section.data(3).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.cz1perd2ej.gmfjxhcwab
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.arbgebpnzf.ekyf2ft5xv
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.mssjub5nr2.fyfzf3djiy
	  section.data(1).logicalSrcIdx = 38;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.gwhniowyem.g540wbqcci
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.lb5tuw34lz.fws4iwogpu
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtB.ituo30pkvd.a4etz1spm4
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.ituo30pkvd.edrpaasu4j
	  section.data(2).logicalSrcIdx = 42;
	  section.data(2).dtTransOffset = 3;
	
	  ;% rtB.ituo30pkvd.nmcsp5dcxo
	  section.data(3).logicalSrcIdx = 43;
	  section.data(3).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.imixbcpj4x.gmfjxhcwab
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.eagdjb5elr.ekyf2ft5xv
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.lqknz2kefj.fyfzf3djiy
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(14) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 14;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtDW.n1mf5f1loj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.j4zaai5afv
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% rtDW.ofluvtqt5p
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 11;
	
	  ;% rtDW.o221ifynn5
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 15;
	
	  ;% rtDW.kqelrtffwz
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 23;
	
	  ;% rtDW.gubqowflu1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 26;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% rtDW.npodssysd1.LoggedData
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.lmb5hcu4yy.LoggedData
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.b2ohgjv3mg.LoggedData
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.f5asnft4wp.LoggedData
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.emrji4re2y.LoggedData
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtDW.ewjz1wr2fe
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.bnvhkeklee
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 3;
	
	  ;% rtDW.k10aogs3q2
	  section.data(3).logicalSrcIdx = 13;
	  section.data(3).dtTransOffset = 11;
	
	  ;% rtDW.c5xg33ddc3
	  section.data(4).logicalSrcIdx = 14;
	  section.data(4).dtTransOffset = 15;
	
	  ;% rtDW.j05iyjbst5
	  section.data(5).logicalSrcIdx = 15;
	  section.data(5).dtTransOffset = 23;
	
	  ;% rtDW.mgrhzfgfnu
	  section.data(6).logicalSrcIdx = 16;
	  section.data(6).dtTransOffset = 26;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.h5pffuqljc
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.mstj5paygm
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtDW.e4nx2k2d02
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.mgkojscrve
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.bt5mj1ckkg
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 469362051;
  targMap.checksum1 = 2005292047;
  targMap.checksum2 = 1163668803;
  targMap.checksum3 = 920400502;

