//------New Macro for comparison for Pass4 old Eff vs Pass4 New Eff-------------


//using namespace std::
TString directory = "";
const Int_t nhistos=20; //pPb !! IMPORTANT to change -->9 for pp
TString *filenames = new TString[nhistos];
TString assocpT = "2.0-3.0GeV";
TString path;
void Systematicfunc(){
        gStyle->SetOptStat(0);
        gStyle->SetTitleSize(0.06, "t");
    DoAllPlotsin1Canvas("Dplus", assocpT);
    
}

//1D_pp_DplusCorr_______________________________________________________________________
void DoAllPlotsin1Canvas(TString particle ="Dplus",TString assocpT = "dot3"){
   // gStyle->SetPalette(1);
    LoadFileNamespPbDMeson(particle,assocpT);
    TCanvas ** Canvas = new TCanvas *[nhistos];
    TH1F *hDraw;
    TH1F *hSignal1[nhistos], *hratioLow[nhistos], *hratioMid[nhistos], *hratioHigh[nhistos], *hratioVeryHigh[nhistos];
   
   for(Int_t k = 0; k<nhistos; k++){
        Canvas[k]=GetCanvasBFD(k,"corrMECorrected");
        hSignal1[k]=(TH1F*)Canvas[k]->FindObject("h1D_SubtrNorm");
        hSignal1[k]->SetMarkerSize(.60);
    }
    
   
    
   TCanvas *Comparison=new TCanvas("Ranges Systematic","Ranges Systematic",1100,800);
  // Comparison->SetMargin(1.0,0.01,0.01,0.01);
    Comparison->Divide(2,2);
    Comparison->cd(1);
    TPad* pad = (TPad*)Comparison->GetPad(1);
    pad->SetLeftMargin(0.1);
    pad->SetBottomMargin(0.12);
    pad->SetTopMargin(0.1);
    pad->SetRightMargin(0.001);
    hSignal1[0]->SetName(Form("(D^{+})LowpT - (h) >%s", assocpT.Data()));
    hSignal1[0]->SetTitle(Form("(D^{+})LowpT - (h)>%s", assocpT.Data()));
    hSignal1[0]->GetYaxis()->SetRangeUser(0.0,hSignal1[0]->GetMaximum()*1.1);
    hSignal1[0]->GetYaxis()->CenterTitle(true);
    hSignal1[0]->GetXaxis()->CenterTitle(true);
    hSignal1[0]->GetYaxis()->SetTitle("#frac{1}{N_{trig}(D^{+})}#frac{dN}{d#Delta#phi}^{asso} (rad^{-1})");
    hSignal1[0]->GetXaxis()->SetTitleSize(0.05);
    hSignal1[0]->SetTitleOffset (1.0,"X");
    hSignal1[0]->SetTitleOffset (1.0,"Y");
    hSignal1[0]->SetMarkerColor(1);
    hSignal1[0]->SetMarkerStyle(8);
    hSignal1[0]->SetMarkerSize(0.90);
    hSignal1[0]->SetStats(0);
    hSignal1[0]->Draw();
    for(Int_t color=1; color<4;color++)
    {
    hSignal1[color]->SetMarkerColor(color+1);
    hSignal1[color]->GetYaxis()->SetTitle("#frac{1}{N_{trig}(D^{+})}#frac{dN}{d#Delta#phi}^{asso} (rad^{-1})");
    hSignal1[color]->SetMarkerStyle(8);
    hSignal1[color]->SetMarkerSize(0.90);
    hSignal1[color]->SetStats(0);
    hSignal1[color]->Draw("same");
    }
    leg = new TLegend(0.60,0.75,0.999,0.93);
    leg->SetTextSize(0.05);
   // leg->SetHeader("Comparison: SB Ranges");
    leg->AddEntry(hSignal1[0],"4#sigma-8#sigma");
    leg->AddEntry(hSignal1[1],"5#sigma-7#sigma");
    leg->AddEntry(hSignal1[2],"5#sigma-11#sigma");
    leg->AddEntry(hSignal1[3],"3#sigma-9#sigma");
    leg->AddEntry(hSignal1[4],"5#sigma-9#sigma");
    leg->Draw();
    
    Comparison->cd(2);
    TPad* pad = (TPad*)Comparison->GetPad(2);
    pad->SetLeftMargin(0.1);
    pad->SetBottomMargin(0.12);
    pad->SetTopMargin(0.1);
    pad->SetRightMargin(0.001);
    hSignal1[4]->SetName(Form("(D^{+})MidpT - (h)>%s", assocpT.Data()));
    hSignal1[4]->SetTitle(Form("(D^{+})MidpT - (h)>%s", assocpT.Data()));
    hSignal1[4]->GetYaxis()->SetRangeUser(0.0,hSignal1[4]->GetMaximum()*1.1);
    hSignal1[4]->GetYaxis()->CenterTitle(true);
    hSignal1[4]->GetXaxis()->CenterTitle(true);
    hSignal1[4]->GetXaxis()->SetTitleSize(0.05);
    hSignal1[4]->SetTitleOffset (1.0,"X");
    hSignal1[4]->SetTitleOffset (1.0,"Y");
    hSignal1[4]->SetMarkerColor(1);
    hSignal1[4]->SetMarkerStyle(8);
    hSignal1[4]->SetMarkerSize(0.90);
    hSignal1[4]->SetStats(0);
    hSignal1[4]->Draw();
    for(Int_t color=5; color<8;color++)
    {
    hSignal1[color]->GetYaxis()->SetRangeUser(0.0,hSignal1[color]->GetMaximum()*1.1);
    hSignal1[color]->SetMarkerColor(color-3);
    hSignal1[color]->SetMarkerStyle(8);
    hSignal1[color]->SetMarkerSize(0.90);
    hSignal1[color]->SetStats(0);
    hSignal1[color]->Draw("same");
    }
    
    
    Comparison->cd(3);
    TPad* pad = (TPad*)Comparison->GetPad(3);
    pad->SetLeftMargin(0.1);
    pad->SetBottomMargin(0.12);
    pad->SetTopMargin(0.1);
    pad->SetRightMargin(0.001);
    hSignal1[8]->SetName(Form("(D^{+})HighpT - (h)>%s", assocpT.Data()));
    hSignal1[8]->SetTitle(Form("(D^{+})HighpT - (h)>%s", assocpT.Data()));
    hSignal1[8]->GetYaxis()->SetRangeUser(0.0,hSignal1[8]->GetMaximum()*1.1);
    hSignal1[8]->GetYaxis()->CenterTitle(true);
    hSignal1[8]->GetXaxis()->CenterTitle(true);
    hSignal1[8]->GetXaxis()->SetTitleSize(0.05);
    hSignal1[8]->SetTitleOffset (1.0,"X");
    hSignal1[8]->SetTitleOffset (1.0,"Y");
    hSignal1[8]->SetMarkerColor(1);
    hSignal1[8]->SetMarkerStyle(8);
    hSignal1[8]->SetMarkerSize(0.90);
    hSignal1[8]->SetStats(0);
    hSignal1[8]->Draw();
    for(Int_t color=9; color<12;color++)
    {
    hSignal1[color]->GetYaxis()->SetTitle("#frac{1}{N_{trig}(D^{+})}#frac{dN}{d#Delta#phi}^{asso} (rad^{-1})");
    hSignal1[color]->SetMarkerColor(color-7);
    hSignal1[color]->SetMarkerStyle(8);
    hSignal1[color]->SetMarkerSize(0.90);
    hSignal1[color]->SetStats(0);
    hSignal1[color]->Draw("same");
    }
    

    
    Comparison->cd(4);
    TPad* pad = (TPad*)Comparison->GetPad(4);
    pad->SetLeftMargin(0.1);
    pad->SetBottomMargin(0.12);
    pad->SetTopMargin(0.1);
    pad->SetRightMargin(0.001);
    hSignal1[12]->SetName(Form("(D^{+})Very HighpT - (h)>%s", assocpT.Data()));
    hSignal1[12]->SetTitle(Form("(D^{+})Very HighpT - (h)>%s", assocpT.Data()));
    hSignal1[12]->GetYaxis()->SetRangeUser(0.0,hSignal1[12]->GetMaximum()*1.1);
    hSignal1[12]->GetYaxis()->CenterTitle(true);
    hSignal1[12]->GetXaxis()->CenterTitle(true);
    hSignal1[12]->GetXaxis()->SetTitleSize(0.05);
    hSignal1[12]->SetTitleOffset (1.0,"X");
    hSignal1[12]->SetTitleOffset (1.0,"Y");
    hSignal1[12]->SetMarkerColor(1);
    hSignal1[12]->SetMarkerStyle(8);
    hSignal1[12]->SetMarkerSize(0.90);
    hSignal1[12]->SetStats(0);
    hSignal1[12]->Draw();
    for(Int_t color=13; color<16;color++)
    {
    hSignal1[color]->GetYaxis()->SetTitle("#frac{1}{N_{trig}(D^{+})}#frac{dN}{d#Delta#phi}^{asso} (rad^{-1})");
    hSignal1[color]->SetMarkerColor(color-11);
    hSignal1[color]->SetMarkerStyle(8);
    hSignal1[color]->SetMarkerSize(0.90);
    hSignal1[color]->SetStats(0);
    hSignal1[color]->Draw("same");
    }
    
    
    
    TPaveText* t[40];
    TCanvas *Ratio=new TCanvas("Ratio","Ratio",1100,1200);
    Ratio->Divide(2,2);
    Ratio->cd(1);
    TPad* pad = (TPad*)Ratio->GetPad(1);
    pad->SetLeftMargin(0.1);
    pad->SetBottomMargin(0.12);
    pad->SetTopMargin(0.1);
    pad->SetRightMargin(0.001);
    Double_t p=0.90;
    for (Int_t color=1;color<5;color++){
    hratioLow[color]=(TH1F*)hSignal1[color]->Clone(Form("ratioLow_%i_%d", 0,color));
    hratioLow[color]->SetName(Form("Changed SB region/Std (D^{+})LowpT - (h)>%s", assocpT.Data()));
    hratioLow[color]->SetTitle(Form("Changed SB region/Std (D^{+})LowpT - (h)>%s", assocpT.Data()));
    hratioLow[color]->GetYaxis()->SetRangeUser(0.6,1.5);
    hratioLow[color]->SetStats(0);
    hratioLow[color]->GetYaxis()->CenterTitle(true);
    hratioLow[color]->GetXaxis()->CenterTitle(true);
    hratioLow[color]->GetYaxis()->SetTitleSize(0.05);
    hratioLow[color]->GetYaxis()->SetTitle("Ratio");
    hratioLow[color]->Divide(hSignal1[0]);  ///ratio of two signals
    hratioLow[color]->SetLineColor(color);
    hratioLow[color]->SetMarkerColor(color);
    hratioLow[color]->SetMarkerSize(0.90);
    if (color==1) hratioLow[color]->Draw("");
    else hratioLow[color]->Draw("same");

    TF1 *fitf = new TF1("fitf","[0]",-TMath::Pi()/2.,3*TMath::Pi()/2.);
    fitf->SetLineColor(color);
    fitf->SetLineWidth(1);
    hratioLow[color]->Fit(fitf);
    Double_t par0 = fitf->GetParameter(0);
    Double_t err0 = fitf->GetParError(0);
    t[color]=new TPaveText(0.1,0.0+p,0.6,p,"NDC");
    t[color]->SetFillStyle(0);
    t[color]->SetBorderSize(0);
    t[color]->SetTextSize(0.06);
    t[color]->SetTextColor(color);
    t[color]->SetTextFont(42);
    t[color]->SetTextAlign(13);
    if(color==1) t[color]->AddText(0.,0.,Form("Mean = %.2f #pm %.2f [5#sigma-7#sigma/4#sigma-8#sigma]  ",par0,err0));
    else if(color==2) t[color]->AddText(0.,0.,Form("Mean = %.2f #pm %.2f [5#sigma-11#sigma/4#sigma-8#sigma]  ",par0,err0));
    if(color==3) t[color]->AddText(0.,0.,Form("Mean = %.2f #pm %.2f [3#sigma-9#sigma/4#sigma-8#sigma]  ",par0,err0));
    if(color==4) t[color]->AddText(0.,0.,Form("Mean = %.2f #pm %.2f [5#sigma-9#sigma/5#sigma-8#sigma]  ",par0,err0));
    t[color]->SetFillColor(color);
    if(color==1) t[color]->Draw();
    else t[color]->Draw("same");
    p-=0.050;
    }
    
    Ratio->cd(2);
    TPad* pad = (TPad*)Ratio->GetPad(2);
    pad->SetLeftMargin(0.1);
    pad->SetBottomMargin(0.12);
    pad->SetTopMargin(0.1);
    pad->SetRightMargin(0.001);
    Double_t p=0.90;
    for (Int_t color=6;color<10;color++){
    hratioMid[color]=(TH1F*)hSignal1[color]->Clone(Form("ratioMid_%i_%d", 0,color));
    hratioMid[color]->SetName(Form("Changed SB region/Std (D^{+})MidpT - (h)>%s", assocpT.Data()));
    hratioMid[color]->SetTitle(Form("Changed SB region/Std (D^{+})MidpT - (h)>%s", assocpT.Data()));
    hratioMid[color]->GetYaxis()->SetRangeUser(0.6,1.5);
    hratioMid[color]->SetStats(0);
    hratioMid[color]->GetYaxis()->CenterTitle(true);
    hratioMid[color]->GetXaxis()->CenterTitle(true);
    hratioMid[color]->GetYaxis()->SetTitleSize(0.05);
    hratioMid[color]->GetYaxis()->SetTitle("Ratio");
    hratioMid[color]->Divide(hSignal1[5]);  ///ratio of two signals
    hratioMid[color]->SetLineColor(color-5);
    hratioMid[color]->SetMarkerColor(color-5);
    hratioMid[color]->SetMarkerSize(0.90);
    if (color==6) hratioMid[color]->Draw("");
    else hratioMid[color]->Draw("same");
    TF1 *fitf = new TF1("fitf","[0]",-TMath::Pi()/2.,3*TMath::Pi()/2.);
    fitf->SetLineColor(color-5);
    fitf->SetLineWidth(1);
    hratioMid[color]->Fit(fitf);
    Double_t par0 = fitf->GetParameter(0);
    Double_t err0 = fitf->GetParError(0);
    t[color]=new TPaveText(0.1,0.0+p,0.6,p,"NDC");
    t[color]->SetFillStyle(0);
    t[color]->SetBorderSize(0);
    t[color]->SetTextSize(0.06);
    t[color]->SetTextColor(color-5);
    t[color]->SetTextFont(42);
    t[color]->SetTextAlign(13);
    if(color==6) t[color]->AddText(0.,0.,Form("Mean = %.2f #pm %.2f [5#sigma-7#sigma/4#sigma-8#sigma]  ",par0,err0));
    else if(color==7) t[color]->AddText(0.,0.,Form("Mean = %.2f #pm %.2f [5#sigma-11#sigma/4#sigma-8#sigma]  ",par0,err0));
    if(color==8) t[color]->AddText(0.,0.,Form("Mean = %.2f #pm %.2f [3#sigma-9#sigma/4#sigma-8#sigma]  ",par0,err0));
    if(color==9) t[color]->AddText(0.,0.,Form("Mean = %.2f #pm %.2f [5#sigma-9#sigma/4#sigma-8#sigma]  ",par0,err0));
    t[color]->SetFillColor(color-5);
    t[color]->Draw();
    p-=0.050;
    }
    Ratio->cd(3);
    TPad* pad = (TPad*)Ratio->GetPad(3);
    pad->SetLeftMargin(0.1);
    pad->SetBottomMargin(0.12);
    pad->SetTopMargin(0.1);
    pad->SetRightMargin(0.001);
    Double_t p=0.90;
    for (Int_t color=11;color<15;color++){
    hratioHigh[color]=(TH1F*)hSignal1[color]->Clone(Form("ratioHigh_%i_%d", 0,color));
    hratioHigh[color]->SetName(Form("Changed SB region/Std (D^{+})HighpT - (h)>%s", assocpT.Data()));
    hratioHigh[color]->SetTitle(Form("Changed SB region/Std (D^{+})HighpT - (h)>%s", assocpT.Data()));
    hratioHigh[color]->GetYaxis()->SetRangeUser(0.6,1.5);
    hratioHigh[color]->SetStats(0);
    hratioHigh[color]->GetYaxis()->CenterTitle(true);
    hratioHigh[color]->GetXaxis()->CenterTitle(true);
    hratioHigh[color]->GetYaxis()->SetTitleSize(0.05);
    hratioHigh[color]->GetYaxis()->SetTitle("Ratio");
    hratioHigh[color]->Divide(hSignal1[10]);  ///ratio of two signals
    hratioHigh[color]->SetLineColor(color-10);
    hratioHigh[color]->SetMarkerColor(color-10);
    hratioHigh[color]->SetMarkerSize(0.90);
    if (color==11) hratioHigh[color]->Draw("");
    else hratioHigh[color]->Draw("same");
    
    TF1 *fitf = new TF1("fitf","[0]",-TMath::Pi()/2.,3*TMath::Pi()/2.);
    fitf->SetLineColor(color-10);
    fitf->SetLineWidth(1);
    hratioHigh[color]->Fit(fitf);
    Double_t par0 = fitf->GetParameter(0);
    Double_t err0 = fitf->GetParError(0);
    t[color]=new TPaveText(0.1,0.0+p,0.6,p,"NDC");
    t[color]->SetFillStyle(0);
    t[color]->SetBorderSize(0);
    t[color]->SetTextSize(0.06);
    t[color]->SetTextColor(color-10);
    t[color]->SetTextFont(42);
    t[color]->SetTextAlign(13);
    if(color==11) t[color]->AddText(0.,0.,Form("Mean = %.2f #pm %.2f [5#sigma-7#sigma/4#sigma-8#sigma]  ",par0,err0));
    else if(color==12) t[color]->AddText(0.,0.,Form("Mean = %.2f #pm %.2f [5#sigma-11#sigma/4#sigma-8#sigma]  ",par0,err0));
    if(color==13) t[color]->AddText(0.,0.,Form("Mean = %.2f #pm %.2f [3#sigma-9#sigma/4#sigma-8#sigma]  ",par0,err0));
    if(color==14) t[color]->AddText(0.,0.,Form("Mean = %.2f #pm %.2f [5#sigma-9#sigma/4#sigma-8#sigma]  ",par0,err0));
    t[color]->SetFillColor(color-10);
    t[color]->Draw();
    p-=0.050;
    }  
      
     Ratio->cd(4);
    TPad* pad = (TPad*)Ratio->GetPad(4);
    pad->SetLeftMargin(0.1);
    pad->SetBottomMargin(0.12);
    pad->SetTopMargin(0.1);
    pad->SetRightMargin(0.001);
    Double_t p=0.90;
    for (Int_t color=16;color<20;color++){
    hratioVeryHigh[color]=(TH1F*)hSignal1[color]->Clone(Form("ratioLow_%i_%d", 0,color));
    hratioVeryHigh[color]->SetName(Form("Changed SB region/Std (D^{+})Very HighpT - (h)>%s", assocpT.Data()));
    hratioVeryHigh[color]->SetTitle(Form("Changed SB region/Std (D^{+})Very HighpT - (h)>%s", assocpT.Data()));
    hratioVeryHigh[color]->GetYaxis()->SetRangeUser(0.6,1.5);
    hratioVeryHigh[color]->SetStats(0);
    hratioVeryHigh[color]->GetYaxis()->CenterTitle(true);
    hratioVeryHigh[color]->GetXaxis()->CenterTitle(true);
    hratioVeryHigh[color]->GetYaxis()->SetTitleSize(0.05);
    hratioVeryHigh[color]->GetYaxis()->SetTitle("Ratio");
    hratioVeryHigh[color]->Divide(hSignal1[15]);  ///ratio of two signals
    hratioVeryHigh[color]->SetLineColor(color-15);
    hratioVeryHigh[color]->SetMarkerColor(color-15);
    hratioVeryHigh[color]->SetMarkerSize(0.90);
    if (color==16) hratioVeryHigh[color]->Draw("");
    else hratioVeryHigh[color]->Draw("same");

    TF1 *fitf = new TF1("fitf","[0]",-TMath::Pi()/2.,3*TMath::Pi()/2.);
    fitf->SetLineColor(color-15);

    fitf->SetLineWidth(1);
    hratioVeryHigh[color]->Fit(fitf);
    Double_t par0 = fitf->GetParameter(0);
    Double_t err0 = fitf->GetParError(0);

    t[color]=new TPaveText(0.1,0.0+p,0.6,p,"NDC");
    t[color]->SetFillStyle(0);
    t[color]->SetBorderSize(0);
    t[color]->SetTextSize(0.06);
    t[color]->SetTextColor(color-15);
    t[color]->SetTextFont(42);
    t[color]->SetTextAlign(13);
    if(color==16) t[color]->AddText(0.,0.,Form("Mean = %.2f #pm %.2f [5#sigma-7#sigma/4#sigma-8#sigma]  ",par0,err0));
    else if(color==17) t[color]->AddText(0.,0.,Form("Mean = %.2f #pm %.2f [5#sigma-11#sigma/4#sigma-8#sigma]  ",par0,err0));
    if(color==18) t[color]->AddText(0.,0.,Form("Mean = %.2f #pm %.2f [3#sigma-9#sigma/4#sigma-8#sigma]  ",par0,err0));
    if(color==19) t[color]->AddText(0.,0.,Form("Mean = %.2f #pm %.2f [5#sigma-9#sigma/4#sigma-8#sigma]  ",par0,err0));
    t[color]->SetFillColor(color-15);
    t[color]->Draw();
    p-=0.050;
    }
    Comparison->SaveAs(Form("compare%s.png",assocpT.Data()));
    Ratio->SaveAs(Form("Ratio%s.png",assocpT.Data()));
}


////1D_pp_DplusCorr_______________________________________________________________________
void LoadFileNamespPbDMeson(TString Part ="Dplus",TString assocpT = "dot5"){
    
    
    if(Part == "Dplus"){
        
        if(assocpT == "0.3GeV"){
            cout << " -------------------> Adding Dplus-pp 7TeV 0.3  GeV/c!!! " <<endl;
            filenames[0] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr0.3to99.0.root";
            filenames[1] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr0.3to99.0.root";
            filenames[2] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr0.3to99.0.root";
            filenames[3] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr0.3to99.0.root";
            filenames[4] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr0.3to99.0.root";

            filenames[5] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr0.3to99.0.root";
            filenames[6] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr0.3to99.0.root";
            filenames[7] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr0.3to99.0.root";
            filenames[8] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr0.3to99.0.root";
            filenames[9] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr0.3to99.0.root";

            filenames[10] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr0.3to99.0.root";
            filenames[11] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr0.3to99.0.root";
            filenames[12] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr0.3to99.0.root";
            filenames[13] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr0.3to99.0.root";
            filenames[14] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr0.3to99.0.root";

            filenames[15] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr0.3to99.0.root";
            filenames[16] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr0.3to99.0.root";
            filenames[17] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr0.3to99.0.root";
            filenames[18] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr0.3to99.0.root";
            filenames[19] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr0.3to99.0.root";
            
            
            
        } if(assocpT == "0.3-1.0GeV"){
            cout << " -------------------> Adding Dplus-pp 7TeV 0.3-1.0  GeV/c!!! " <<endl;
            filenames[0] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr0.3to1.0.root";
            filenames[1] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr0.3to1.0.root";
            filenames[2] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr0.3to1.0.root";
            filenames[3] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr0.3to1.0.root";
            filenames[4] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr0.3to1.0.root";

            filenames[5] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr0.3to1.0.root";
            filenames[6] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr0.3to1.0.root";
            filenames[7] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr0.3to1.0.root";
            filenames[8] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr0.3to1.0.root";
            filenames[9] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr0.3to1.0.root";

            filenames[10] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr0.3to1.0.root";
            filenames[11] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr0.3to1.0.root";
            filenames[12] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr0.3to1.0.root";
            filenames[13] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr0.3to1.0.root";
            filenames[14] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr0.3to1.0.root";

            filenames[15] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr0.3to1.0.root";
            filenames[16] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr0.3to1.0.root";
            filenames[17] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr0.3to1.0.root";
            filenames[18] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr0.3to1.0.root";
            filenames[19] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr0.3to1.0.root";

            
        }else if(assocpT == "1.0GeV"){
            cout << " -------------------> Adding Dplus-pp 7TeV 1  GeV/c!!! " <<endl;
            filenames[0] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr1.0to99.0.root";
            filenames[1] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr1.0to99.0.root";
            filenames[2] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr1.0to99.0.root";
            filenames[3] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr1.0to99.0.root";
            filenames[4] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr1.0to99.0.root";

            filenames[5] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr1.0to99.0.root";
            filenames[6] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr1.0to99.0.root";
            filenames[7] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr1.0to99.0.root";
            filenames[8] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr1.0to99.0.root";
            filenames[9] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr1.0to99.0.root";

            filenames[10] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr1.0to99.0.root";
            filenames[11] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr1.0to99.0.root";
            filenames[12] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr1.0to99.0.root";
            filenames[13] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr1.0to99.0.root";
            filenames[14] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr1.0to99.0.root";

            filenames[15] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr1.0to99.0.root";
            filenames[16] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr1.0to99.0.root";
            filenames[17] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr1.0to99.0.root";
            filenames[18] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr1.0to99.0.root";
            filenames[19] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr1.0to99.0.root";
            
            
        }
        else if(assocpT == "2.0GeV"){
            cout << " -------------------> Adding Dplus-pp 7TeV 1  GeV/c!!! " <<endl;
            filenames[0] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr2.0to99.0.root";
            filenames[1] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr2.0to99.0.root";
            filenames[2] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr2.0to99.0.root";
            filenames[3] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr2.0to99.0.root";
            filenames[4] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr2.0to99.0.root";

            filenames[5] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr2.0to99.0.root";
            filenames[6] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr2.0to99.0.root";
            filenames[7] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr2.0to99.0.root";
            filenames[8] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr2.0to99.0.root";
            filenames[9] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr2.0to99.0.root";

            filenames[10] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr2.0to99.0.root";
            filenames[11] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr2.0to99.0.root";
            filenames[12] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr2.0to99.0.root";
            filenames[13] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr2.0to99.0.root";
            filenames[14] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr2.0to99.0.root";

            filenames[15] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr2.0to99.0.root";
            filenames[16] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr2.0to99.0.root";
            filenames[17] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr2.0to99.0.root";
            filenames[18] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr2.0to99.0.root";
            filenames[19] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr2.0to99.0.root";
            
        }
        else if(assocpT == "3.0GeV"){
            cout << " -------------------> Adding Dplus-pp 7TeV 1  GeV/c!!! " <<endl;
            filenames[0] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr3.0to99.0.root";
            filenames[1] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr3.0to99.0.root";
            filenames[2] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr3.0to99.0.root";
            filenames[3] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr3.0to99.0.root";
            filenames[4] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr3.0to99.0.root";

            filenames[5] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr3.0to99.0.root";
            filenames[6] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr3.0to99.0.root";
            filenames[7] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr3.0to99.0.root";
            filenames[8] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr3.0to99.0.root";
            filenames[9] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr3.0to99.0.root";

            filenames[10] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr3.0to99.0.root";
            filenames[11] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr3.0to99.0.root";
            filenames[12] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr3.0to99.0.root";
            filenames[13] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr3.0to99.0.root";
            filenames[14] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr3.0to99.0.root";

            filenames[15] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr3.0to99.0.root";
            filenames[16] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr3.0to99.0.root";
            filenames[17] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr3.0to99.0.root";
            filenames[18] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr3.0to99.0.root";
            filenames[19] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr3.0to99.0.root";
            
            
        }
        else if(assocpT == "1.0-2.0GeV"){
            cout << " -------------------> Adding Dplus-pp 7TeV 1  GeV/c!!! " <<endl;
            filenames[0] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr1.0to2.0.root";
            filenames[1] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr1.0to2.0.root";
            filenames[2] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr1.0to2.0.root";
            filenames[3] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr1.0to2.0.root";
            filenames[4] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr1.0to2.0.root";

            filenames[5] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr1.0to2.0.root";
            filenames[6] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr1.0to2.0.root";
            filenames[7] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr1.0to2.0.root";
            filenames[8] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr1.0to2.0.root";
            filenames[9] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr1.0to2.0.root";

            filenames[10] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr1.0to2.0.root";
            filenames[11] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr1.0to2.0.root";
            filenames[12] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr1.0to2.0.root";
            filenames[13] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr1.0to2.0.root";
            filenames[14] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr1.0to2.0.root";

            filenames[15] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr1.0to2.0.root";
            filenames[16] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr1.0to2.0.root";
            filenames[17] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr1.0to2.0.root";
            filenames[18] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr1.0to2.0.root";
            filenames[19] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr1.0to2.0.root";
            
        }
         else if(assocpT == "2.0-3.0GeV"){
            cout << " -------------------> Adding Dplus-pp 7TeV 1  GeV/c!!! " <<endl;
            filenames[0] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr2.0to3.0.root";
            filenames[1] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr2.0to3.0.root";
            filenames[2] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr2.0to3.0.root";
            filenames[3] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr2.0to3.0.root";
            filenames[4] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr2.0to3.0.root";

            filenames[5] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr2.0to3.0.root";
            filenames[6] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr2.0to3.0.root";
            filenames[7] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr2.0to3.0.root";
            filenames[8] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr2.0to3.0.root";
            filenames[9] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr2.0to3.0.root";

            filenames[10] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr2.0to3.0.root";
            filenames[11] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr2.0to3.0.root";
            filenames[12] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr2.0to3.0.root";
            filenames[13] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr2.0to3.0.root";
            filenames[14] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr2.0to3.0.root";

            filenames[15] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr2.0to3.0.root";
            filenames[16] += "./5to7Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr2.0to3.0.root";
            filenames[17] += "./5to11Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr2.0to3.0.root";
            filenames[18] += "./3to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr2.0to3.0.root";
            filenames[19] += "./5to9Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr2.0to3.0.root";

            
            
        }
    }
    
}

//1D_pp_DplusCorr_______________________________________________________________________
TCanvas * GetCanvasBFD(Int_t i, TString canvasname = "corrMECorrected"){
    
    //load the histogram with
    TString path = filenames[i];
     if (assocpT == "0.3GeV") canvasname="cFinal_0.3to99.0";
     else if (assocpT == "0.5GeV") canvasname="cFinal_0.5to99.0";
     else if (assocpT == "1.0GeV") canvasname="cFinal_1.0to99.0";
     else if (assocpT == "2.0GeV") canvasname="cFinal_2.0to99.0";
     else if (assocpT == "3.0GeV") canvasname="cFinal_3.0to99.0";
     else if (assocpT == "0.3-1.0GeV") canvasname="cFinal_0.3to1.0"; 
     else if (assocpT == "1.0-2.0GeV") canvasname="cFinal_1.0to2.0";
     else if (assocpT == "2.0-3.0GeV") canvasname="cFinal_2.0to3.0";
     
    TFile * file = TFile::Open(path.Data(),"WRITE");
    TCanvas * c = (TCanvas*)file->Get(canvasname.Data());
    if(!c) std::cout<<"Canvas name not found !!!!!!!!!"<<std::endl;
    return c;
    
}









