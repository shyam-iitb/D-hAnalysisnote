{
gSystem->SetIncludePath("-I. -I$ALICE_ROOT/include -I$ALICE_PHYSICS/include -I$ALICE_ROOT/ANALYSIS/macros -I$ROOTSYS/include");
//gROOT->LoadMacro("AliDhCorrelationExtraction.cxx++g");
//gROOT->LoadMacro("AliDhCorrelationExtractionOff.cxx++g");
gROOT->ProcessLine(".L SuperimposeDistr.C++");
gROOT->ProcessLine("SuperimposeDistr()");
}

