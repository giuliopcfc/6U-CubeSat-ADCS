  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
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
      section.nData     = 42;
      section.data(42)  = dumData; %prealloc
      
	  ;% rtP.Integrator_IC
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.Integrator_IC_ifj3pkofzc
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.RandomNumber1_Mean
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 10;
	
	  ;% rtP.RandomNumber1_StdDev
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 11;
	
	  ;% rtP.RandomNumber1_Seed
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 14;
	
	  ;% rtP.TransportDelay_Delay
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 17;
	
	  ;% rtP.TransportDelay_InitOutput
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 18;
	
	  ;% rtP.Integrator_IC_c5e44kpjcd
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 21;
	
	  ;% rtP.RandomNumber_Mean
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 24;
	
	  ;% rtP.RandomNumber_StdDev
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 25;
	
	  ;% rtP.RandomNumber_Seed
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 28;
	
	  ;% rtP.Integrator_IC_juij5hh4y1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 31;
	
	  ;% rtP.Integrator_IC_lc2l1uvn30
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 34;
	
	  ;% rtP.RandomNumber1_Mean_pp0amcle2e
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 35;
	
	  ;% rtP.RandomNumber1_StdDev_cudqkp3bpx
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 36;
	
	  ;% rtP.RandomNumber1_Seed_gnd4ve32hq
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 39;
	
	  ;% rtP.Constant9_Value
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 42;
	
	  ;% rtP.Constant_Value
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 45;
	
	  ;% rtP.Constant1_Value
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 46;
	
	  ;% rtP.Constant2_Value
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 47;
	
	  ;% rtP.Constant3_Value
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 48;
	
	  ;% rtP.Constant4_Value
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 49;
	
	  ;% rtP.Constant5_Value
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 50;
	
	  ;% rtP.Constant6_Value
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 53;
	
	  ;% rtP.Constant7_Value
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 54;
	
	  ;% rtP.Constant_Value_nedwe54uwp
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 55;
	
	  ;% rtP.Constant1_Value_iuwa1a4rwo
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 64;
	
	  ;% rtP.Constant2_Value_p0tf13dhms
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 67;
	
	  ;% rtP.Constant3_Value_mitst2s14q
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 81;
	
	  ;% rtP.Constant4_Value_hr4vhts24r
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 95;
	
	  ;% rtP.Constant5_Value_oj3yslavn5
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 137;
	
	  ;% rtP.Constant6_Value_bsw1z5ftyf
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 179;
	
	  ;% rtP.Constant_Value_kb0zyegq3x
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 193;
	
	  ;% rtP.Constant1_Value_lapgl51prt
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 194;
	
	  ;% rtP.Constant2_Value_pn5msfmygz
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 195;
	
	  ;% rtP.Constant3_Value_lnlpkng3dr
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 196;
	
	  ;% rtP.Constant4_Value_plq0xk0dqt
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 197;
	
	  ;% rtP.Constant_Value_noh4pr4dj2
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 198;
	
	  ;% rtP.Constant_Value_jedkd3oz4q
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 207;
	
	  ;% rtP.Constant_Value_m3i1kxbif4
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 208;
	
	  ;% rtP.Constant1_Value_cw3pti1zff
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 217;
	
	  ;% rtP.Constant2_Value_jgk4nzciuj
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 218;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
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
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 31;
      section.data(31)  = dumData; %prealloc
      
	  ;% rtB.ela1rhmmmi
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.jbo3v4ajb3
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.ahdpwrjj5d
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 10;
	
	  ;% rtB.bqon2dgr5d
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 13;
	
	  ;% rtB.nrhgec3vav
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 16;
	
	  ;% rtB.fh0tz1ct3t
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 19;
	
	  ;% rtB.c1dnkkzf2p
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 22;
	
	  ;% rtB.l1nazchf2g
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 25;
	
	  ;% rtB.kl0s5rlxlx
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 26;
	
	  ;% rtB.dlgknc2iej
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 29;
	
	  ;% rtB.d0bsyboket
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 32;
	
	  ;% rtB.lkneu0sjol
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 35;
	
	  ;% rtB.gcsyrgudhi
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 38;
	
	  ;% rtB.pkc5yfmw2v
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 41;
	
	  ;% rtB.h2dle1tjk3
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 44;
	
	  ;% rtB.cw2k3svoeb
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 45;
	
	  ;% rtB.ey2mmw0csp
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 48;
	
	  ;% rtB.jd4glhy2th
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 51;
	
	  ;% rtB.bgsqzfr5vf
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 54;
	
	  ;% rtB.ptpgqwsog2
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 57;
	
	  ;% rtB.cncjtrvy1r
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 60;
	
	  ;% rtB.pxjxltf32i
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 61;
	
	  ;% rtB.bx5l1cxe42
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 64;
	
	  ;% rtB.fiyrbaaxb5
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 67;
	
	  ;% rtB.farw3endkt
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 70;
	
	  ;% rtB.gnn2xcjhaq
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 73;
	
	  ;% rtB.p13uq5o22a
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 74;
	
	  ;% rtB.e1l1mwc2wk
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 83;
	
	  ;% rtB.e4c42ch1lv
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 92;
	
	  ;% rtB.nvcvw4zh5h
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 93;
	
	  ;% rtB.pldpuimngh
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 96;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.b13up4rwa2
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
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
    sectIdxOffset = 2;
    
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
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.a5tv4scxvv
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.donz0qvylr
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% rtDW.mdfoxg3mo4
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% rtDW.eqrezujrj5.modelTStart
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtDW.ja1mjqygva.TUbufferPtrs
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.gt4jdlhghh.LoggedData
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 6;
	
	  ;% rtDW.azun1jdpk2.LoggedData
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 7;
	
	  ;% rtDW.isg0e1befe.LoggedData
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 8;
	
	  ;% rtDW.fwhm2dya5u.LoggedData
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 9;
	
	  ;% rtDW.j04ekmbaka.LoggedData
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtDW.p3k2zi5joj
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.apy12dao0a
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 3;
	
	  ;% rtDW.lfp1taz3l3
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.hxmmr0vle1.Tail
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.m3xid4gzul
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.klnbyfrse2
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.bhvnvcv2we
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
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


  targMap.checksum0 = 2063736516;
  targMap.checksum1 = 611031575;
  targMap.checksum2 = 3190133955;
  targMap.checksum3 = 305185540;

