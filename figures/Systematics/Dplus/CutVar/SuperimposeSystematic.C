 void SuperimposeSystematic(Int_t binmin, Int_t binmax, Double_t thrmin, Double_t thrmax) {
  static const Int_t nbins = 7;  
  Int_t colors[50] = {1,2,3,4,6,7,8,9,11,12,20,28,29,32,33,36,38,41,42,46,48,49};

  TFile *fIn[50];
  fIn[0] = new TFile(Form("../Std_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));
  fIn[1] = new TFile(Form("../Cut1_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));
  fIn[2] = new TFile(Form("../Cut2_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));
  fIn[3] = new TFile(Form("../Cut3_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));
  fIn[4] = new TFile(Form("../Cut4_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));
  fIn[5] = new TFile(Form("../Cut5_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));
  fIn[6] = new TFile(Form("../Cut6_Root/AzimCorrDistr_Dplus_Canvas_PtIntBins%dto%d_PoolInt_thr%1.1fto%1.1f.root",binmin,binmax,thrmin,thrmax));


  
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
  leg->AddEntry(h[0],"Std","epl");
  leg->AddEntry(h[1],"Cut1","epl");
  leg->AddEntry(h[2],"Cut2","epl");
  leg->AddEntry(h[3],"Cut3","epl");
  leg->AddEntry(h[4],"Cut4","epl");
  leg->AddEntry(h[5],"Cut5","epl");
  leg->AddEntry(h[6],"Cut6","epl");

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
  leg->AddEntry(hR[0],"Cut1/Std","epl");
  leg->AddEntry(hR[1],"Cut2/Std","epl");
  leg->AddEntry(hR[2],"Cut3/Std","epl");
  leg->AddEntry(hR[3],"Cut4/Std","epl");
  leg->AddEntry(hR[4],"Cut5/Std","epl");
  leg->AddEntry(hR[5],"Cut6/Std","epl");
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



