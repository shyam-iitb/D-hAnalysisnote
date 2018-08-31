//------New Macro for comparison for Pass4 old Eff vs Pass4 New Eff-------------


//using namespace std::
TString directory = "";
const Int_t nhistos=8; //pPb !! IMPORTANT to change -->9 for pp
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
    
   
    
   TCanvas *Comparison=new TCanvas("Ranges Systematic","Ranges Systematic",1100,1200);
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
    hSignal1[0]->SetMarkerColor(kBlue);
    hSignal1[0]->SetMarkerStyle(8);
    hSignal1[0]->SetMarkerSize(0.90);
    hSignal1[0]->SetStats(0);
    hSignal1[0]->Draw();
    hSignal1[1]->SetMarkerStyle(8);
    hSignal1[1]->SetMarkerSize(0.90);
    hSignal1[1]->SetMarkerColor(kRed);
    hSignal1[1]->SetStats(0);
    hSignal1[1]->Draw("same");
    leg = new TLegend(0.2,0.75,0.90,0.9);
    leg->SetTextSize(0.05);
    leg->SetHeader("Comparison: Different fit function");
    leg->AddEntry(hSignal1[0],"Exponential");
    leg->AddEntry(hSignal1[1],"Poly2");
    leg->Draw();
    
    Comparison->cd(2);
    TPad* pad = (TPad*)Comparison->GetPad(2);
    pad->SetLeftMargin(0.1);
    pad->SetBottomMargin(0.12);
    pad->SetTopMargin(0.1);
    pad->SetRightMargin(0.001);
    hSignal1[2]->SetName(Form("(D^{+})MidpT - (h)>%s", assocpT.Data()));
    hSignal1[2]->SetTitle(Form("(D^{+})MidpT - (h)>%s", assocpT.Data()));
    hSignal1[2]->GetYaxis()->SetRangeUser(0.0,hSignal1[0]->GetMaximum()*1.1);
    hSignal1[2]->GetYaxis()->CenterTitle(true);
    hSignal1[2]->GetXaxis()->CenterTitle(true);
    hSignal1[2]->GetXaxis()->SetTitleSize(0.05);
    hSignal1[2]->SetTitleOffset (1.0,"X");
    hSignal1[2]->SetTitleOffset (1.0,"Y");
    hSignal1[2]->SetMarkerColor(kBlue);
    hSignal1[2]->SetMarkerStyle(8);
    hSignal1[2]->SetMarkerSize(0.90);
    hSignal1[2]->SetStats(0);
    hSignal1[2]->Draw();
    hSignal1[3]->SetMarkerStyle(8);
    hSignal1[3]->SetMarkerSize(0.90);
    hSignal1[3]->SetMarkerColor(kRed);
    hSignal1[3]->SetStats(0);
    hSignal1[3]->Draw("same");
    
    Comparison->cd(3);
    TPad* pad = (TPad*)Comparison->GetPad(3);
    pad->SetLeftMargin(0.1);
    pad->SetBottomMargin(0.12);
    pad->SetTopMargin(0.1);
    pad->SetRightMargin(0.001);
    hSignal1[4]->SetName(Form("(D^{+})HighpT - (h)>%s", assocpT.Data()));
    hSignal1[4]->SetTitle(Form("(D^{+})HighpT - (h)>%s", assocpT.Data()));
    hSignal1[4]->GetYaxis()->SetRangeUser(0.0,hSignal1[0]->GetMaximum()*1.1);
    hSignal1[4]->GetYaxis()->CenterTitle(true);
    hSignal1[4]->GetXaxis()->CenterTitle(true);
    hSignal1[4]->GetXaxis()->SetTitleSize(0.05);
    hSignal1[4]->SetTitleOffset (1.0,"X");
    hSignal1[4]->SetTitleOffset (1.0,"Y");
    hSignal1[4]->SetMarkerColor(kBlue);
    hSignal1[4]->SetMarkerStyle(8);
    hSignal1[4]->SetMarkerSize(0.90);
    hSignal1[4]->SetStats(0);
    hSignal1[4]->Draw();
    hSignal1[5]->SetMarkerStyle(8);
    hSignal1[5]->SetMarkerSize(0.90);
    hSignal1[5]->SetMarkerColor(kRed);
    hSignal1[5]->SetStats(0);
    hSignal1[5]->Draw("same");

    
    Comparison->cd(4);
    TPad* pad = (TPad*)Comparison->GetPad(4);
    pad->SetLeftMargin(0.1);
    pad->SetBottomMargin(0.12);
    pad->SetTopMargin(0.1);
    pad->SetRightMargin(0.001);
    hSignal1[6]->SetName(Form("(D^{+})Very HighpT - (h)>%s", assocpT.Data()));
    hSignal1[6]->SetTitle(Form("(D^{+})Very HighpT - (h)>%s", assocpT.Data()));
    hSignal1[6]->GetYaxis()->SetRangeUser(0.0,hSignal1[0]->GetMaximum()*1.1);
    hSignal1[6]->GetYaxis()->CenterTitle(true);
    hSignal1[6]->GetXaxis()->CenterTitle(true);
    hSignal1[6]->GetXaxis()->SetTitleSize(0.05);
    hSignal1[6]->SetTitleOffset (1.0,"X");
    hSignal1[6]->SetTitleOffset (1.0,"Y");
    hSignal1[6]->SetMarkerColor(kBlue);
    hSignal1[6]->SetMarkerStyle(8);
    hSignal1[6]->SetMarkerSize(0.90);
    hSignal1[6]->SetStats(0);
    hSignal1[6]->Draw();
    hSignal1[7]->SetMarkerStyle(8);
    hSignal1[7]->SetMarkerSize(0.90);
    hSignal1[7]->SetMarkerColor(kRed);
    hSignal1[7]->SetStats(0);
    hSignal1[7]->Draw("same");

    
    
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
    for (Int_t color=1;color<2;color++){
    hratioLow[color]=(TH1F*)hSignal1[color]->Clone(Form("ratioLow_%i_%d", 0,color));
    hratioLow[color]->SetName(Form("Poly2/Std (D^{+})LowpT - (h)>%s", assocpT.Data()));
    hratioLow[color]->SetTitle(Form("Poly2/Std (D^{+})LowpT - (h)>%s", assocpT.Data()));
    hratioLow[color]->GetYaxis()->SetRangeUser(0.6,1.4);
    hratioLow[color]->SetStats(0);
    hratioLow[color]->GetYaxis()->CenterTitle(true);
    hratioLow[color]->GetXaxis()->CenterTitle(true);
    hratioLow[color]->GetYaxis()->SetTitleSize(0.05);
    hratioLow[color]->GetYaxis()->SetTitle("Ratio");
    hratioLow[color]->Divide(hSignal1[0]);  ///ratio of two signals
    hratioLow[color]->SetLineColor(kBlue);
    hratioLow[color]->SetMarkerColor(kBlue);
    hratioLow[color]->SetMarkerSize(0.90);
    hratioLow[color]->Draw("");

    TF1 *fitf = new TF1("fitf","[0]",-TMath::Pi()/2.,3*TMath::Pi()/2.);
    fitf->SetLineColor(kBlue);
    fitf->SetLineWidth(1);
    hratioLow[color]->Fit(fitf);
    Double_t par0 = fitf->GetParameter(0);
    Double_t err0 = fitf->GetParError(0);
    t[color]=new TPaveText(0.1,0.0+p,0.6,p,"NDC");
    t[color]->SetFillStyle(0);
    t[color]->SetBorderSize(0);
    t[color]->SetTextSize(0.06);
    t[color]->SetTextColor(kBlue);
    t[color]->SetTextFont(42);
    t[color]->SetTextAlign(13);
    t[color]->AddText(0.,0.,Form("Mean = %.2f #pm %.2f",par0,err0));
    t[color]->SetFillColor(color);
    t[color]->Draw();
    p-=0.040;
    }
    
    Ratio->cd(2);
    TPad* pad = (TPad*)Ratio->GetPad(2);
    pad->SetLeftMargin(0.1);
    pad->SetBottomMargin(0.12);
    pad->SetTopMargin(0.1);
    pad->SetRightMargin(0.001);
    Double_t p=0.90;
    for (Int_t color=3;color<4;color++){
    hratioMid[color]=(TH1F*)hSignal1[color]->Clone(Form("ratioMid_%i_%d", 0,color));
    hratioMid[color]->SetName(Form("Poly2/Std (D^{+})MidpT - (h)>%s", assocpT.Data()));
    hratioMid[color]->SetTitle(Form("Poly2/Std (D^{+})MidpT - (h)>%s", assocpT.Data()));
    hratioMid[color]->GetYaxis()->SetRangeUser(0.6,1.4);
    hratioMid[color]->SetStats(0);
    hratioMid[color]->GetYaxis()->CenterTitle(true);
    hratioMid[color]->GetXaxis()->CenterTitle(true);
    hratioMid[color]->GetYaxis()->SetTitleSize(0.05);
    hratioMid[color]->GetYaxis()->SetTitle("Ratio");
    hratioMid[color]->Divide(hSignal1[2]);  ///ratio of two signals
    hratioMid[color]->SetLineColor(kBlue);
    hratioMid[color]->SetMarkerColor(kBlue);
    hratioMid[color]->SetMarkerSize(0.90);
    hratioMid[color]->Draw("");
    TF1 *fitf = new TF1("fitf","[0]",-TMath::Pi()/2.,3*TMath::Pi()/2.);
    fitf->SetLineColor(kBlue);
    fitf->SetLineWidth(1);
    hratioMid[color]->Fit(fitf);
    Double_t par0 = fitf->GetParameter(0);
    Double_t err0 = fitf->GetParError(0);
    t[color]=new TPaveText(0.1,0.0+p,0.6,p,"NDC");
    t[color]->SetFillStyle(0);
    t[color]->SetBorderSize(0);
    t[color]->SetTextSize(0.06);
    t[color]->SetTextColor(kBlue);
    t[color]->SetTextFont(42);
    t[color]->SetTextAlign(13);
    t[color]->AddText(0.,0.,Form("Mean = %.2f #pm %.2f",par0,err0));
    t[color]->SetFillColor(kBlue);
    t[color]->Draw();
    p-=0.040;
    }
    Ratio->cd(3);
    TPad* pad = (TPad*)Ratio->GetPad(3);
    pad->SetLeftMargin(0.1);
    pad->SetBottomMargin(0.12);
    pad->SetTopMargin(0.1);
    pad->SetRightMargin(0.001);
    Double_t p=0.90;
    for (Int_t color=5;color<6;color++){
    hratioHigh[color]=(TH1F*)hSignal1[color]->Clone(Form("ratioHigh_%i_%d", 0,color));
    hratioHigh[color]->SetName(Form("Poly2/Std (D^{+})HighpT - (h)>%s", assocpT.Data()));
    hratioHigh[color]->SetTitle(Form("Poly2/Std (D^{+})HighpT - (h)>%s", assocpT.Data()));
    hratioHigh[color]->GetYaxis()->SetRangeUser(0.6,1.4);
    hratioHigh[color]->SetStats(0);
    hratioHigh[color]->GetYaxis()->CenterTitle(true);
    hratioHigh[color]->GetXaxis()->CenterTitle(true);
    hratioHigh[color]->GetYaxis()->SetTitleSize(0.05);
    hratioHigh[color]->GetYaxis()->SetTitle("Ratio");
    hratioHigh[color]->Divide(hSignal1[4]);  ///ratio of two signals
    hratioHigh[color]->SetLineColor(kBlue);
    hratioHigh[color]->SetMarkerColor(kBlue);
    hratioHigh[color]->SetMarkerSize(0.90);
    hratioHigh[color]->Draw("");
    
    TF1 *fitf = new TF1("fitf","[0]",-TMath::Pi()/2.,3*TMath::Pi()/2.);
    fitf->SetLineColor(kBlue);
    fitf->SetLineWidth(1);
    hratioHigh[color]->Fit(fitf);
    Double_t par0 = fitf->GetParameter(0);
    Double_t err0 = fitf->GetParError(0);
    t[color]=new TPaveText(0.1,0.0+p,0.6,p,"NDC");
    t[color]->SetFillStyle(0);
    t[color]->SetBorderSize(0);
    t[color]->SetTextSize(0.06);
    t[color]->SetTextColor(kBlue);
    t[color]->SetTextFont(42);
    t[color]->SetTextAlign(13);
    t[color]->AddText(0.,0.,Form("Mean = %.2f #pm %.2f",par0,err0));
    t[color]->SetFillColor(kBlue);
    t[color]->Draw();
    p-=0.040;
    }  
      
     Ratio->cd(4);
    TPad* pad = (TPad*)Ratio->GetPad(4);
    pad->SetLeftMargin(0.1);
    pad->SetBottomMargin(0.12);
    pad->SetTopMargin(0.1);
    pad->SetRightMargin(0.001);
    Double_t p=0.90;
    for (Int_t color=7;color<8;color++){
    hratioVeryHigh[color]=(TH1F*)hSignal1[color]->Clone(Form("ratioLow_%i_%d", 0,color));
    hratioVeryHigh[color]->SetName(Form("Poly2/Std (D^{+})Very HighpT - (h)>%s", assocpT.Data()));
    hratioVeryHigh[color]->SetTitle(Form("Poly2/Std (D^{+})Very HighpT - (h)>%s", assocpT.Data()));
    hratioVeryHigh[color]->GetYaxis()->SetRangeUser(0.6,1.4);
    hratioVeryHigh[color]->SetStats(0);
    hratioVeryHigh[color]->GetYaxis()->CenterTitle(true);
    hratioVeryHigh[color]->GetXaxis()->CenterTitle(true);
    hratioVeryHigh[color]->GetYaxis()->SetTitleSize(0.05);
    hratioVeryHigh[color]->GetYaxis()->SetTitle("Ratio");
    hratioVeryHigh[color]->Divide(hSignal1[6]);  ///ratio of two signals
    hratioVeryHigh[color]->SetLineColor(kBlue);
    hratioVeryHigh[color]->SetMarkerColor(kBlue);
    hratioVeryHigh[color]->SetMarkerSize(0.90);
    hratioVeryHigh[color]->Draw("");

    TF1 *fitf = new TF1("fitf","[0]",-TMath::Pi()/2.,3*TMath::Pi()/2.);
    fitf->SetLineColor(kBlue);

    fitf->SetLineWidth(1);
    hratioVeryHigh[color]->Fit(fitf);
    Double_t par0 = fitf->GetParameter(0);
    Double_t err0 = fitf->GetParError(0);

    t[color]=new TPaveText(0.1,0.0+p,0.6,p,"NDC");
    t[color]->SetFillStyle(0);
    t[color]->SetBorderSize(0);
    t[color]->SetTextSize(0.06);
    t[color]->SetTextColor(kBlue);
    t[color]->SetTextFont(42);
    t[color]->SetTextAlign(13);
    t[color]->AddText(0.,0.,Form("Mean = %.2f #pm %.2f",par0,err0));
    t[color]->SetFillColor(kBlue);
    t[color]->Draw();
    p-=0.040;
    }
    Comparison->Print(Form("compare%s.eps",assocpT.Data()));
    Ratio->Print(Form("Ratio%s.eps",assocpT.Data()));
}


////1D_pp_DplusCorr_______________________________________________________________________
void LoadFileNamespPbDMeson(TString Part ="Dplus",TString assocpT = "dot5"){
    
    
    if(Part == "Dplus"){
        
        if(assocpT == "0.3GeV"){
            cout << " -------------------> Adding Dplus-pp 7TeV 0.3  GeV/c!!! " <<endl;
            filenames[0] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr0.3to99.0.root";
            filenames[1] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr0.3to99.0.root";

            filenames[2] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr0.3to99.0.root";
            filenames[3] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr0.3to99.0.root";

            filenames[4] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr0.3to99.0.root";
            filenames[5] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr0.3to99.0.root";

            filenames[6] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr0.3to99.0.root";
            filenames[7] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr0.3to99.0.root";
            
            
            
        } if(assocpT == "0.3-1.0GeV"){
            cout << " -------------------> Adding Dplus-pp 7TeV 0.3-1.0  GeV/c!!! " <<endl;
            filenames[0] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr0.3to1.0.root";
            filenames[1] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr0.3to1.0.root";

            filenames[2] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr0.3to1.0.root";
            filenames[3] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr0.3to1.0.root";

            filenames[4] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr0.3to1.0.root";
            filenames[5] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr0.3to1.0.root";

            filenames[6] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr0.3to1.0.root";
            filenames[7] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr0.3to1.0.root";

            
        }else if(assocpT == "1.0GeV"){
            cout << " -------------------> Adding Dplus-pp 7TeV 1  GeV/c!!! " <<endl;
            filenames[0] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr1.0to99.0.root";
            filenames[1] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr1.0to99.0.root";

            filenames[2] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr1.0to99.0.root";
            filenames[3] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr1.0to99.0.root";

            filenames[4] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr1.0to99.0.root";
            filenames[5] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr1.0to99.0.root";

            filenames[6] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr1.0to99.0.root";
            filenames[7] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr1.0to99.0.root";
            
            
        }
        else if(assocpT == "2.0GeV"){
            cout << " -------------------> Adding Dplus-pp 7TeV 1  GeV/c!!! " <<endl;
             filenames[0] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr2.0to99.0.root";
            filenames[1] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr2.0to99.0.root";

            filenames[2] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr2.0to99.0.root";
            filenames[3] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr2.0to99.0.root";

            filenames[4] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr2.0to99.0.root";
            filenames[5] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr2.0to99.0.root";

            filenames[6] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr2.0to99.0.root";
            filenames[7] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr2.0to99.0.root";
            
        }
        else if(assocpT == "3.0GeV"){
            cout << " -------------------> Adding Dplus-pp 7TeV 1  GeV/c!!! " <<endl;
            filenames[0] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr3.0to99.0.root";
            filenames[1] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr3.0to99.0.root";

            filenames[2] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr3.0to99.0.root";
            filenames[3] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr3.0to99.0.root";

            filenames[4] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr3.0to99.0.root";
            filenames[5] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr3.0to99.0.root";

            filenames[6] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr3.0to99.0.root";
            filenames[7] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr3.0to99.0.root";
            
            
        }
        else if(assocpT == "1.0-2.0GeV"){
            cout << " -------------------> Adding Dplus-pp 7TeV 1  GeV/c!!! " <<endl;
            filenames[0] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr1.0to2.0.root";
            filenames[1] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr1.0to2.0.root";

            filenames[2] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr1.0to2.0.root";
            filenames[3] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr1.0to2.0.root";

            filenames[4] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr1.0to2.0.root";
            filenames[5] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr1.0to2.0.root";

            filenames[6] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr1.0to2.0.root";
            filenames[7] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr1.0to2.0.root";
            
        }
         else if(assocpT == "2.0-3.0GeV"){
            cout << " -------------------> Adding Dplus-pp 7TeV 1  GeV/c!!! " <<endl;
            filenames[0] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr2.0to3.0.root";
            filenames[1] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins3to4_PoolInt_thr2.0to3.0.root";

            filenames[2] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr2.0to3.0.root";
            filenames[3] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins5to7_PoolInt_thr2.0to3.0.root";

            filenames[4] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr2.0to3.0.root";
            filenames[5] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins8to10_PoolInt_thr2.0to3.0.root";

            filenames[6] += "./Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr2.0to3.0.root";
            filenames[7] += "./Poly_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins11to11_PoolInt_thr2.0to3.0.root";

            
            
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









