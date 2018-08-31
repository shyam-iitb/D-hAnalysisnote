 void SuperimposeSystematic(Int_t binmin, Int_t binmax, Double_t thrmin, Double_t thrmax) {
  static const Int_t nbins = 13;  
  Int_t colors[50] = {1,2,3,4,6,7,8,9,11,12,20,28,29,32,33,36,38,41,42,46,48,49};

  TFile *fIn[50];
  fIn[0] = new TFile(Form("../FitRange/Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));
  fIn[1] = new TFile(Form("../SandB/BfromBinCount_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));
  fIn[2] = new TFile(Form("../SandB/SBfit_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));
  fIn[3] = new TFile(Form("../Rebin/Rebin1_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));
  fIn[4] = new TFile(Form("../Rebin/Rebin4_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));
  fIn[5] = new TFile(Form("../SignalRegion/1Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));
  fIn[6] = new TFile(Form("../SignalRegion/1.5Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));
  fIn[7] = new TFile(Form("../SignalRegion/3Sigma_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));
  fIn[8] = new TFile(Form("../FitRange/Range1_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));
  fIn[9] = new TFile(Form("../FitRange/Range2_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));
  fIn[10] = new TFile(Form("../FitRange/Range3_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));
  fIn[11] = new TFile(Form("../function/Poly2_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));
  fIn[12] = new TFile(Form("../function/Linear_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));


  
  TCanvas *c[50];
  TH1D *h[50];
  TH1D *hR[50];

  TCanvas *cOut = new TCanvas("c1","cOut",100,100,1200,800);  
  
  for(int i=0; i<nbins; i++) {
    c[i] = (TCanvas*)fIn[i]->Get(Form("cFinal_%1.1fto%1.1f",thrmin,thrmax));
    h[i] = (TH1D*)c[i]->FindObject("h1D_SubtrNorm");
    h[i]->SetName(Form("h%d",i));
    h[i]->SetLineColor(colors[i]);
    h[i]->SetMarkerColor(colors[i]);
    h[i]->SetStats(kFALSE);
    cOut->cd();
    if(i==0) h[i]->Draw();
    else h[i]->Draw("same");
  }

  TLegend* leg=new TLegend(0.82,0.10,1.0,0.50);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->AddEntry(h[0],"Standard","epl");
  leg->AddEntry(h[1],"BinCountBkg","epl");
  leg->AddEntry(h[2],"SandBviaFit","epl");
  leg->AddEntry(h[3],"Rebin1","epl");
  leg->AddEntry(h[4],"Rebin4","epl");
  leg->AddEntry(h[5],"S_1#sigma","epl");
  leg->AddEntry(h[6],"S_1.5#sigma","epl");
  leg->AddEntry(h[7],"S_3#sigma","epl");
  leg->AddEntry(h[8],"Fit1.65to2.05","epl");
  leg->AddEntry(h[9],"Fit1.7to2.08","epl");
  leg->AddEntry(h[10],"Fit1.7to2.1","epl");
  leg->AddEntry(h[11],"Bkg_Pol2","epl");
  leg->AddEntry(h[12],"Bkg_Linear","epl");

  leg->Draw();

 // cOut->SaveAs(Form("AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f_Superimp.root",binmin,binmax,thrmin,thrmax));
  cOut->SaveAs(Form("AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f_Superimp.png",binmin,binmax,thrmin,thrmax));
  
  cOut2 = new TCanvas("c2","cOut2",100,100,1200,800); 

  for(int i=0; i<nbins-1; i++) {
    hR[i] = (TH1D*)h[i+1]->Clone(Form("hR%d",i));
    hR[i]->Divide(h[0]);
    hR[i]->SetLineColor(colors[i+1]);
    hR[i]->SetMarkerColor(colors[i+1]);
    hR[i]->GetYaxis()->SetRangeUser(0.8,1.15);
    hR[i]->SetStats(kFALSE);
    for(int j=1;j<=hR[i]->GetNbinsX();j++) hR[i]->SetBinError(j,0.001);
    if(i==0) hR[i]->Draw();
    else hR[i]->Draw("same");
  }  
  
  TLegend* leg=new TLegend(0.82,0.10,1.0,0.50);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->AddEntry(hR[0],"BinCountBkg/Std","epl");
  leg->AddEntry(hR[1],"SandBviaFit/Std","epl");
  leg->AddEntry(hR[2],"Rebin1/Std","epl");
  leg->AddEntry(hR[3],"Rebin4/Std","epl");
  leg->AddEntry(hR[4],"S_1#sigma/Std","epl");
  leg->AddEntry(hR[5],"S_1.5#sigma/Std","epl");
  leg->AddEntry(hR[6],"S_3#sigma/Std","epl");
  leg->AddEntry(hR[7],"Fit1.65to2.05/Std","epl");
  leg->AddEntry(hR[8],"Fit1.7to2.08/Std","epl");
  leg->AddEntry(hR[9],"Fit1.7to2.1/Std","epl");
  leg->AddEntry(hR[10],"Bkg_Pol2/Std","epl");
  leg->AddEntry(hR[11],"Bkg_Linear/Std","epl");
  leg->Draw();  

  Double_t fitVal[50], fitErr[50];
  TPaveText *pt = new TPaveText(0.15,0.12,0.35,0.45,"NDC");
  pt->SetFillColor(kWhite);

  for(Int_t i=0; i<nbins-1; i++) {  
    TF1 *fitf = new TF1("fitf","[0]",-TMath::Pi()/2.,3*TMath::Pi()/2.);
    fitf->SetLineColor(colors[i+1]);
    fitf->SetLineWidth(1);
    hR[i]->Fit(fitf);

    fitVal[i] = fitf->GetParameter(0);
    fitErr[i] = fitf->GetParError(0);
    printf("Fit outcome for %d = %1.3f #pm %1.3f\n",i,fitVal[i],fitErr[i]);

    pt->AddText(Form("Fit %d = %1.3f",i,fitVal[i]));
  }

  pt->Draw("same");

  Double_t RMSvect[50];
  for(Int_t i=0; i<nbins-1; i++) RMSvect[i]=fitVal[i]-1;

  TPaveText *pt2 = new TPaveText(0.40,0.25,0.60,0.32,"NDC");
  pt2->SetFillColor(kWhite);
  pt2->AddText(Form("RMS = %1.3f",TMath::RMS(nbins-1,RMSvect)));
  pt2->Draw("same");
 // cOut2->SaveAs(Form("Ratio_AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));
  cOut2->SaveAs(Form("Ratio_AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.png",binmin,binmax,thrmin,thrmax));

}



