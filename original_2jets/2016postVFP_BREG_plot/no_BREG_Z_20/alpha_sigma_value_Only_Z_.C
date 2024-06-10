void alpha_sigma_value_Only_Z_()
{
//=========Macro generated from canvas: c1_n3/
//=========  (Wed Mar 20 17:32:14 2024) by ROOT version 6.24/07
   TCanvas *c1_n3 = new TCanvas("c1_n3", "",0,0,680,680);
   c1_n3->SetHighLightColor(2);
   c1_n3->Range(-0.0375,-0.0625,0.3375,0.5625);
   c1_n3->SetFillColor(0);
   c1_n3->SetBorderMode(0);
   c1_n3->SetBorderSize(2);
   c1_n3->SetFrameBorderMode(0);
   c1_n3->SetFrameBorderMode(0);
   Double_t xAxis10[6] = {0, 0.1, 0.155, 0.185, 0.23, 0.3}; 
   
   TH1F *Central_resolutionOnly_Z__90 = new TH1F("Central_resolutionOnly_Z__90","2016postVFP #sigma",5, xAxis10);
   Central_resolutionOnly_Z__90->SetBinContent(1,0.1250712);
   Central_resolutionOnly_Z__90->SetBinContent(2,0.2010733);
   Central_resolutionOnly_Z__90->SetBinContent(3,0.2199973);
   Central_resolutionOnly_Z__90->SetBinContent(4,0.2540642);
   Central_resolutionOnly_Z__90->SetBinContent(5,0.2410547);
   Central_resolutionOnly_Z__90->SetBinError(1,0.01944245);
   Central_resolutionOnly_Z__90->SetBinError(2,0.01182934);
   Central_resolutionOnly_Z__90->SetBinError(3,0.01417404);
   Central_resolutionOnly_Z__90->SetBinError(4,0.008319805);
   Central_resolutionOnly_Z__90->SetBinError(5,0.005695927);
   Central_resolutionOnly_Z__90->SetMinimum(0);
   Central_resolutionOnly_Z__90->SetMaximum(0.5);
   Central_resolutionOnly_Z__90->SetEntries(5);
   Central_resolutionOnly_Z__90->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   Central_resolutionOnly_Z__90->SetLineColor(ci);
   Central_resolutionOnly_Z__90->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   Central_resolutionOnly_Z__90->SetMarkerColor(ci);
   Central_resolutionOnly_Z__90->SetMarkerStyle(20);
   Central_resolutionOnly_Z__90->GetXaxis()->SetTitle("#alpha");
   Central_resolutionOnly_Z__90->GetXaxis()->SetLabelFont(42);
   Central_resolutionOnly_Z__90->GetXaxis()->SetTitleOffset(1);
   Central_resolutionOnly_Z__90->GetXaxis()->SetTitleFont(42);
   Central_resolutionOnly_Z__90->GetYaxis()->SetTitle("#sigma");
   Central_resolutionOnly_Z__90->GetYaxis()->SetLabelFont(42);
   Central_resolutionOnly_Z__90->GetYaxis()->SetTitleFont(42);
   Central_resolutionOnly_Z__90->GetZaxis()->SetLabelFont(42);
   Central_resolutionOnly_Z__90->GetZaxis()->SetTitleOffset(1);
   Central_resolutionOnly_Z__90->GetZaxis()->SetTitleFont(42);
   Central_resolutionOnly_Z__90->Draw("e x0 *");
   Double_t xAxis11[6] = {0, 0.1, 0.155, 0.185, 0.23, 0.3}; 
   
   TH1F *Up_resolutionOnly_Z__91 = new TH1F("Up_resolutionOnly_Z__91","up",5, xAxis11);
   Up_resolutionOnly_Z__91->SetBinContent(1,0.1301219);
   Up_resolutionOnly_Z__91->SetBinContent(2,0.1965761);
   Up_resolutionOnly_Z__91->SetBinContent(3,0.2236406);
   Up_resolutionOnly_Z__91->SetBinContent(4,0.2516823);
   Up_resolutionOnly_Z__91->SetBinContent(5,0.2426618);
   Up_resolutionOnly_Z__91->SetBinError(1,0.005050705);
   Up_resolutionOnly_Z__91->SetBinError(2,0.004497158);
   Up_resolutionOnly_Z__91->SetBinError(3,0.003643307);
   Up_resolutionOnly_Z__91->SetBinError(4,0.002381984);
   Up_resolutionOnly_Z__91->SetBinError(5,0.001607084);
   Up_resolutionOnly_Z__91->SetEntries(5);
   Up_resolutionOnly_Z__91->SetStats(0);

   ci = TColor::GetColor("#0000ff");
   Up_resolutionOnly_Z__91->SetFillColor(ci);
   Up_resolutionOnly_Z__91->SetFillStyle(3135);

   ci = TColor::GetColor("#0000ff");
   Up_resolutionOnly_Z__91->SetLineColor(ci);
   Up_resolutionOnly_Z__91->GetXaxis()->SetLabelFont(42);
   Up_resolutionOnly_Z__91->GetXaxis()->SetTitleOffset(1);
   Up_resolutionOnly_Z__91->GetXaxis()->SetTitleFont(42);
   Up_resolutionOnly_Z__91->GetYaxis()->SetLabelFont(42);
   Up_resolutionOnly_Z__91->GetYaxis()->SetTitleFont(42);
   Up_resolutionOnly_Z__91->GetZaxis()->SetLabelFont(42);
   Up_resolutionOnly_Z__91->GetZaxis()->SetTitleOffset(1);
   Up_resolutionOnly_Z__91->GetZaxis()->SetTitleFont(42);
   Up_resolutionOnly_Z__91->Draw("SAME e2 L ");
   Double_t xAxis12[6] = {0, 0.1, 0.155, 0.185, 0.23, 0.3}; 
   
   TH1F *Down_resolutionOnly_Z__92 = new TH1F("Down_resolutionOnly_Z__92","down",5, xAxis12);
   Down_resolutionOnly_Z__92->SetBinContent(1,0.1273503);
   Down_resolutionOnly_Z__92->SetBinContent(2,0.1981443);
   Down_resolutionOnly_Z__92->SetBinContent(3,0.2259182);
   Down_resolutionOnly_Z__92->SetBinContent(4,0.2526306);
   Down_resolutionOnly_Z__92->SetBinContent(5,0.2494496);
   Down_resolutionOnly_Z__92->SetBinError(1,0.00227904);
   Down_resolutionOnly_Z__92->SetBinError(2,0.002928963);
   Down_resolutionOnly_Z__92->SetBinError(3,0.005920894);
   Down_resolutionOnly_Z__92->SetBinError(4,0.00143361);
   Down_resolutionOnly_Z__92->SetBinError(5,0.008394884);
   Down_resolutionOnly_Z__92->SetEntries(5);
   Down_resolutionOnly_Z__92->SetStats(0);

   ci = TColor::GetColor("#00ffff");
   Down_resolutionOnly_Z__92->SetFillColor(ci);
   Down_resolutionOnly_Z__92->SetFillStyle(3145);

   ci = TColor::GetColor("#00ffff");
   Down_resolutionOnly_Z__92->SetLineColor(ci);
   Down_resolutionOnly_Z__92->GetXaxis()->SetLabelFont(42);
   Down_resolutionOnly_Z__92->GetXaxis()->SetTitleOffset(1);
   Down_resolutionOnly_Z__92->GetXaxis()->SetTitleFont(42);
   Down_resolutionOnly_Z__92->GetYaxis()->SetLabelFont(42);
   Down_resolutionOnly_Z__92->GetYaxis()->SetTitleFont(42);
   Down_resolutionOnly_Z__92->GetZaxis()->SetLabelFont(42);
   Down_resolutionOnly_Z__92->GetZaxis()->SetTitleOffset(1);
   Down_resolutionOnly_Z__92->GetZaxis()->SetTitleFont(42);
   Down_resolutionOnly_Z__92->Draw("SAME e2 L");
   Double_t xAxis13[6] = {0, 0.1, 0.155, 0.185, 0.23, 0.3}; 
   
   TH1F *Data_resolutionOnly_Z__93 = new TH1F("Data_resolutionOnly_Z__93","data",5, xAxis13);
   Data_resolutionOnly_Z__93->SetBinContent(1,0.1248835);
   Data_resolutionOnly_Z__93->SetBinContent(2,0.1721369);
   Data_resolutionOnly_Z__93->SetBinContent(3,0.2008936);
   Data_resolutionOnly_Z__93->SetBinContent(4,0.2601116);
   Data_resolutionOnly_Z__93->SetBinContent(5,0.2216604);
   Data_resolutionOnly_Z__93->SetBinError(1,0.01335925);
   Data_resolutionOnly_Z__93->SetBinError(2,0.0136748);
   Data_resolutionOnly_Z__93->SetBinError(3,0.01131347);
   Data_resolutionOnly_Z__93->SetBinError(4,0.008622371);
   Data_resolutionOnly_Z__93->SetBinError(5,0.00550386);
   Data_resolutionOnly_Z__93->SetEntries(5);
   Data_resolutionOnly_Z__93->SetStats(0);
   Data_resolutionOnly_Z__93->SetLineWidth(2);
   Data_resolutionOnly_Z__93->SetMarkerStyle(20);
   Data_resolutionOnly_Z__93->GetXaxis()->SetLabelFont(42);
   Data_resolutionOnly_Z__93->GetXaxis()->SetTitleOffset(1);
   Data_resolutionOnly_Z__93->GetXaxis()->SetTitleFont(42);
   Data_resolutionOnly_Z__93->GetYaxis()->SetLabelFont(42);
   Data_resolutionOnly_Z__93->GetYaxis()->SetTitleFont(42);
   Data_resolutionOnly_Z__93->GetZaxis()->SetLabelFont(42);
   Data_resolutionOnly_Z__93->GetZaxis()->SetTitleOffset(1);
   Data_resolutionOnly_Z__93->GetZaxis()->SetTitleFont(42);
   Data_resolutionOnly_Z__93->Draw("SAME e x0 *");
   Double_t xAxis14[6] = {0, 0.1, 0.155, 0.185, 0.23, 0.3}; 
   
   TH1F *resolution__94 = new TH1F("resolution__94","resolution",5, xAxis14);
   resolution__94->SetBinContent(1,0.2097998);
   resolution__94->SetBinContent(2,0.2260049);
   resolution__94->SetBinContent(3,0.1962583);
   resolution__94->SetBinContent(4,0.2422063);
   resolution__94->SetBinContent(5,0.223419);
   resolution__94->SetBinError(1,0.03190219);
   resolution__94->SetBinError(2,0.01356835);
   resolution__94->SetBinError(3,0.01155674);
   resolution__94->SetBinError(4,0.00930433);
   resolution__94->SetBinError(5,0.006190428);
   resolution__94->SetEntries(5);
   resolution__94->SetStats(0);

   ci = TColor::GetColor("#00ff00");
   resolution__94->SetLineColor(ci);
   resolution__94->SetLineWidth(2);

   ci = TColor::GetColor("#00ff00");
   resolution__94->SetMarkerColor(ci);
   resolution__94->SetMarkerStyle(20);
   resolution__94->GetXaxis()->SetLabelFont(42);
   resolution__94->GetXaxis()->SetTitleOffset(1);
   resolution__94->GetXaxis()->SetTitleFont(42);
   resolution__94->GetYaxis()->SetLabelFont(42);
   resolution__94->GetYaxis()->SetTitleFont(42);
   resolution__94->GetZaxis()->SetLabelFont(42);
   resolution__94->GetZaxis()->SetTitleOffset(1);
   resolution__94->GetZaxis()->SetTitleFont(42);
   resolution__94->Draw("SAME e x0 *");
   Double_t xAxis15[6] = {0, 0.1, 0.155, 0.185, 0.23, 0.3}; 
   
   TH1F *Central_resolutionOnly_Z__95 = new TH1F("Central_resolutionOnly_Z__95","2016postVFP #sigma",5, xAxis15);
   Central_resolutionOnly_Z__95->SetBinContent(1,0.1250712);
   Central_resolutionOnly_Z__95->SetBinContent(2,0.2010733);
   Central_resolutionOnly_Z__95->SetBinContent(3,0.2199973);
   Central_resolutionOnly_Z__95->SetBinContent(4,0.2540642);
   Central_resolutionOnly_Z__95->SetBinContent(5,0.2410547);
   Central_resolutionOnly_Z__95->SetBinError(1,0.01944245);
   Central_resolutionOnly_Z__95->SetBinError(2,0.01182934);
   Central_resolutionOnly_Z__95->SetBinError(3,0.01417404);
   Central_resolutionOnly_Z__95->SetBinError(4,0.008319805);
   Central_resolutionOnly_Z__95->SetBinError(5,0.005695927);
   Central_resolutionOnly_Z__95->SetMinimum(0);
   Central_resolutionOnly_Z__95->SetMaximum(0.5);
   Central_resolutionOnly_Z__95->SetEntries(5);
   Central_resolutionOnly_Z__95->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   Central_resolutionOnly_Z__95->SetLineColor(ci);
   Central_resolutionOnly_Z__95->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   Central_resolutionOnly_Z__95->SetMarkerColor(ci);
   Central_resolutionOnly_Z__95->SetMarkerStyle(20);
   Central_resolutionOnly_Z__95->GetXaxis()->SetTitle("#alpha");
   Central_resolutionOnly_Z__95->GetXaxis()->SetLabelFont(42);
   Central_resolutionOnly_Z__95->GetXaxis()->SetTitleOffset(1);
   Central_resolutionOnly_Z__95->GetXaxis()->SetTitleFont(42);
   Central_resolutionOnly_Z__95->GetYaxis()->SetTitle("#sigma");
   Central_resolutionOnly_Z__95->GetYaxis()->SetLabelFont(42);
   Central_resolutionOnly_Z__95->GetYaxis()->SetTitleFont(42);
   Central_resolutionOnly_Z__95->GetZaxis()->SetLabelFont(42);
   Central_resolutionOnly_Z__95->GetZaxis()->SetTitleOffset(1);
   Central_resolutionOnly_Z__95->GetZaxis()->SetTitleFont(42);
   Central_resolutionOnly_Z__95->Draw("SAME e x0 *");
   
   TLegend *leg = new TLegend(0.65,0.7,0.93,0.87,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.02);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("data_resolution","Data","lpf");
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("central_resolution","Central","lpf");
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("up_resolution","JEC up","lpf");
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("down_resolution","JEC down","lpf");
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#00ffff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("blank","JEC SF: 0.934940 #pm 0.023383","lpf");
   entry->SetFillStyle(1001);
   entry->SetLineStyle(1);
   entry->SetMarkerStyle(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.3110059,0.9342638,0.6889941,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("2016postVFP #sigma");
   pt->Draw();
   c1_n3->Modified();
   c1_n3->cd();
   c1_n3->SetSelected(c1_n3);
}
