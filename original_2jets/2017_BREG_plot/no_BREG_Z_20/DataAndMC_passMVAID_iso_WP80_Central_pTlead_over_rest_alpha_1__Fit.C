void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_1__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 18:13:23 2024) by ROOT version 6.24/07
   TCanvas *cvs = new TCanvas("cvs", "",0,0,1000,1000);
   cvs->SetHighLightColor(2);
   cvs->Range(0,0,1,1);
   cvs->SetFillColor(0);
   cvs->SetBorderMode(0);
   cvs->SetBorderSize(2);
   cvs->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad_up
   TPad *pad_up = new TPad("pad_up", "",0,0.5,0.5,1);
   pad_up->Draw();
   pad_up->cd();
   pad_up->Range(-0.25,-2.762561,2.25,31.76945);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3094f890__1 = new TH1D("frame_3094f890__1","p_T Balance",25,0,2);
   frame_3094f890__1->SetBinContent(1,28.31625);
   frame_3094f890__1->SetMaximum(28.31625);
   frame_3094f890__1->SetEntries(1);
   frame_3094f890__1->SetDirectory(0);
   frame_3094f890__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_3094f890__1->SetLineColor(ci);
   frame_3094f890__1->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3094f890__1->GetXaxis()->SetLabelFont(42);
   frame_3094f890__1->GetXaxis()->SetTitleOffset(1);
   frame_3094f890__1->GetXaxis()->SetTitleFont(42);
   frame_3094f890__1->GetYaxis()->SetTitle("1/Events");
   frame_3094f890__1->GetYaxis()->SetLabelFont(42);
   frame_3094f890__1->GetYaxis()->SetTitleFont(42);
   frame_3094f890__1->GetZaxis()->SetLabelFont(42);
   frame_3094f890__1->GetZaxis()->SetTitleOffset(1);
   frame_3094f890__1->GetZaxis()->SetTitleFont(42);
   frame_3094f890__1->Draw("FUNC");
   
   Double_t h_dh_central2_fx3001[25] = {
   0.04,
   0.12,
   0.2,
   0.28,
   0.36,
   0.44,
   0.52,
   0.6,
   0.68,
   0.76,
   0.84,
   0.92,
   1,
   1.08,
   1.16,
   1.24,
   1.32,
   1.4,
   1.48,
   1.56,
   1.64,
   1.72,
   1.8,
   1.88,
   1.96};
   Double_t h_dh_central2_fy3001[25] = {
   0.0129337,
   0.1752836,
   0.1390895,
   0.5074463,
   0.4497176,
   1.086865,
   0.7384165,
   2.679247,
   7.341757,
   12.01181,
   20.85939,
   25.22239,
   21.78234,
   12.92519,
   5.412145,
   2.002641,
   0.5319692,
   0.4889989,
   0.174519,
   0.1091394,
   0,
   0.01676123,
   0.01356052,
   0.007507058,
   0.01170097};
   Double_t h_dh_central2_felx3001[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04};
   Double_t h_dh_central2_fely3001[25] = {
   0.0129337,
   0.1002886,
   0.09251765,
   0.2161304,
   0.2077408,
   0.3739444,
   0.2927962,
   0.6049742,
   0.9858009,
   1.245443,
   1.611105,
   1.745468,
   1.65631,
   1.249146,
   0.8062269,
   0.4662153,
   0.2228393,
   0.2358845,
   0.09408617,
   0.07189102,
   0,
   0.0121639,
   0.00884204,
   0.006441473,
   0.008273933};
   Double_t h_dh_central2_fehx3001[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04};
   Double_t h_dh_central2_fehy3001[25] = {
   0.0129337,
   0.1002886,
   0.09251765,
   0.2161304,
   0.2077408,
   0.3739444,
   0.2927962,
   0.6049742,
   0.9858009,
   1.245443,
   1.611105,
   1.745468,
   1.65631,
   1.249146,
   0.8062269,
   0.4662153,
   0.2228393,
   0.2358845,
   0.09408617,
   0.07189102,
   0,
   0.0121639,
   0.00884204,
   0.006441473,
   0.008273933};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3001,h_dh_central2_fy3001,h_dh_central2_felx3001,h_dh_central2_fehx3001,h_dh_central2_fely3001,h_dh_central2_fehy3001);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23001 = new TH1F("Graph_h_dh_central23001","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23001->SetMinimum(0);
   Graph_h_dh_central23001->SetMaximum(29.66464);
   Graph_h_dh_central23001->SetDirectory(0);
   Graph_h_dh_central23001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_central23001->SetLineColor(ci);
   Graph_h_dh_central23001->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_central23001->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_central23001->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_central23001->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_central23001->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_central23001->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_central23001->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_central23001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_central23001);
   
   grae->Draw("p");
   
   Double_t Central_fx1[57] = {
   0.553061,
   0.5820349,
   0.5965219,
   0.6110089,
   0.6254958,
   0.6399828,
   0.6544698,
   0.6689568,
   0.6834437,
   0.6979307,
   0.7124177,
   0.7269047,
   0.7413916,
   0.7558786,
   0.7848526,
   0.7993395,
   0.8138265,
   0.8283135,
   0.8428005,
   0.8572874,
   0.8645309,
   0.8717744,
   0.8790179,
   0.8862614,
   0.8935049,
   0.9007484,
   0.9079919,
   0.9152353,
   0.9224788,
   0.9297223,
   0.9369658,
   0.9442093,
   0.9514528,
   0.9586963,
   0.9659398,
   0.9731832,
   0.9876702,
   1.002157,
   1.016644,
   1.031131,
   1.045618,
   1.074592,
   1.089079,
   1.103566,
   1.118053,
   1.13254,
   1.147027,
   1.161514,
   1.176001,
   1.190488,
   1.204975,
   1.219462,
   1.233949,
   1.248436,
   1.262923,
   1.27741,
   1.27741};
   Double_t Central_fy1[57] = {
   1.542511,
   2.051002,
   2.384113,
   2.787784,
   3.280754,
   3.887836,
   4.642283,
   5.555801,
   6.583844,
   7.722603,
   8.96601,
   10.30353,
   11.7199,
   13.19512,
   16.21982,
   17.70881,
   19.13744,
   20.47056,
   21.6734,
   22.71305,
   23.16229,
   23.56,
   23.90325,
   24.18947,
   24.41651,
   24.58265,
   24.68662,
   24.72762,
   24.70535,
   24.61996,
   24.47212,
   24.26295,
   23.99405,
   23.66743,
   23.28556,
   22.85125,
   21.83837,
   20.65769,
   19.34169,
   17.92497,
   16.44273,
   13.4171,
   11.93515,
   10.50868,
   9.158413,
   7.900296,
   6.745557,
   5.700902,
   4.768927,
   3.951302,
   3.286048,
   2.755535,
   2.328234,
   1.980911,
   1.696218,
   1.461051,
   1.461051};
   TGraph *graph = new TGraph(57,Central_fx1,Central_fy1);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central1 = new TH1F("Graph_Central1","Projection of centralf DSCB fit",100,0.4806261,1.349845);
   Graph_Central1->SetMinimum(1.314946);
   Graph_Central1->SetMaximum(27.05428);
   Graph_Central1->SetDirectory(0);
   Graph_Central1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Central1->SetLineColor(ci);
   Graph_Central1->GetXaxis()->SetLabelFont(42);
   Graph_Central1->GetXaxis()->SetTitleOffset(1);
   Graph_Central1->GetXaxis()->SetTitleFont(42);
   Graph_Central1->GetYaxis()->SetLabelFont(42);
   Graph_Central1->GetYaxis()->SetTitleFont(42);
   Graph_Central1->GetZaxis()->SetLabelFont(42);
   Graph_Central1->GetZaxis()->SetTitleOffset(1);
   Graph_Central1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Central1);
   
   graph->Draw("l");
   
   TH1D *frame_3094f890__2 = new TH1D("frame_3094f890__2","p_T Balance",25,0,2);
   frame_3094f890__2->SetBinContent(1,28.31625);
   frame_3094f890__2->SetMaximum(28.31625);
   frame_3094f890__2->SetEntries(1);
   frame_3094f890__2->SetDirectory(0);
   frame_3094f890__2->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3094f890__2->SetLineColor(ci);
   frame_3094f890__2->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3094f890__2->GetXaxis()->SetLabelFont(42);
   frame_3094f890__2->GetXaxis()->SetTitleOffset(1);
   frame_3094f890__2->GetXaxis()->SetTitleFont(42);
   frame_3094f890__2->GetYaxis()->SetTitle("1/Events");
   frame_3094f890__2->GetYaxis()->SetLabelFont(42);
   frame_3094f890__2->GetYaxis()->SetTitleFont(42);
   frame_3094f890__2->GetZaxis()->SetLabelFont(42);
   frame_3094f890__2->GetZaxis()->SetTitleOffset(1);
   frame_3094f890__2->GetZaxis()->SetTitleFont(42);
   frame_3094f890__2->Draw("AXISSAME");
   
   TH1D *norm_c__3 = new TH1D("norm_c__3","",25,0,2);
   norm_c__3->SetBinContent(1,0.0129337);
   norm_c__3->SetBinContent(2,0.1752836);
   norm_c__3->SetBinContent(3,0.1390895);
   norm_c__3->SetBinContent(4,0.5074463);
   norm_c__3->SetBinContent(5,0.4497176);
   norm_c__3->SetBinContent(6,1.086865);
   norm_c__3->SetBinContent(7,0.7384165);
   norm_c__3->SetBinContent(8,2.679247);
   norm_c__3->SetBinContent(9,7.341757);
   norm_c__3->SetBinContent(10,12.01181);
   norm_c__3->SetBinContent(11,20.85939);
   norm_c__3->SetBinContent(12,25.22239);
   norm_c__3->SetBinContent(13,21.78234);
   norm_c__3->SetBinContent(14,12.92519);
   norm_c__3->SetBinContent(15,5.412145);
   norm_c__3->SetBinContent(16,2.002641);
   norm_c__3->SetBinContent(17,0.5319692);
   norm_c__3->SetBinContent(18,0.4889989);
   norm_c__3->SetBinContent(19,0.174519);
   norm_c__3->SetBinContent(20,0.1091394);
   norm_c__3->SetBinContent(22,0.01676123);
   norm_c__3->SetBinContent(23,0.01356052);
   norm_c__3->SetBinContent(24,0.007507058);
   norm_c__3->SetBinContent(25,0.01170097);
   norm_c__3->SetBinContent(26,0.02048202);
   norm_c__3->SetBinError(1,0.0129337);
   norm_c__3->SetBinError(2,0.1002886);
   norm_c__3->SetBinError(3,0.09251765);
   norm_c__3->SetBinError(4,0.2161304);
   norm_c__3->SetBinError(5,0.2077408);
   norm_c__3->SetBinError(6,0.3739444);
   norm_c__3->SetBinError(7,0.2927962);
   norm_c__3->SetBinError(8,0.6049742);
   norm_c__3->SetBinError(9,0.9858009);
   norm_c__3->SetBinError(10,1.245443);
   norm_c__3->SetBinError(11,1.611105);
   norm_c__3->SetBinError(12,1.745468);
   norm_c__3->SetBinError(13,1.65631);
   norm_c__3->SetBinError(14,1.249146);
   norm_c__3->SetBinError(15,0.8062269);
   norm_c__3->SetBinError(16,0.4662153);
   norm_c__3->SetBinError(17,0.2228393);
   norm_c__3->SetBinError(18,0.2358845);
   norm_c__3->SetBinError(19,0.09408617);
   norm_c__3->SetBinError(20,0.07189102);
   norm_c__3->SetBinError(22,0.0121639);
   norm_c__3->SetBinError(23,0.00884204);
   norm_c__3->SetBinError(24,0.006441473);
   norm_c__3->SetBinError(25,0.008273933);
   norm_c__3->SetBinError(26,0.009237208);
   norm_c__3->SetEntries(1519);
   norm_c__3->SetStats(0);

   ci = 1311;
   color = new TColor(ci, 0.3, 0.3, 0.3, " ", 0.6);
   norm_c__3->SetFillColor(ci);
   norm_c__3->SetFillStyle(3144);
   norm_c__3->SetLineColor(2);
   norm_c__3->SetLineWidth(2);
   norm_c__3->GetXaxis()->SetRange(1,25);
   norm_c__3->GetXaxis()->SetLabelFont(42);
   norm_c__3->GetXaxis()->SetLabelSize(0.04);
   norm_c__3->GetXaxis()->SetTitleOffset(1);
   norm_c__3->GetXaxis()->SetTitleFont(42);
   norm_c__3->GetYaxis()->SetLabelFont(42);
   norm_c__3->GetYaxis()->SetTitleFont(42);
   norm_c__3->GetZaxis()->SetLabelFont(42);
   norm_c__3->GetZaxis()->SetTitleOffset(1);
   norm_c__3->GetZaxis()->SetTitleFont(42);
   norm_c__3->Draw("e1 same");
   
   TLegend *leg = new TLegend(0.65,0.5,0.93,0.87,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.03);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("norm_c","Central","lpf");

   ci = 1311;
   color = new TColor(ci, 0.3, 0.3, 0.3, " ", 0.6);
   entry->SetFillColor(ci);
   entry->SetFillStyle(3144);
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("frame_x_c2_3094f890","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.915118 #pm 0.014546","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.144746 #pm 0.011482","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.998000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3094f890_copy__4 = new TH1D("frame_3094f890_copy__4","p_T Balance",25,0,2);
   frame_3094f890_copy__4->SetBinContent(1,28.31625);
   frame_3094f890_copy__4->SetMaximum(28.31625);
   frame_3094f890_copy__4->SetEntries(1);
   frame_3094f890_copy__4->SetDirectory(0);
   frame_3094f890_copy__4->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3094f890_copy__4->SetLineColor(ci);
   frame_3094f890_copy__4->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3094f890_copy__4->GetXaxis()->SetLabelFont(42);
   frame_3094f890_copy__4->GetXaxis()->SetTitleOffset(1);
   frame_3094f890_copy__4->GetXaxis()->SetTitleFont(42);
   frame_3094f890_copy__4->GetYaxis()->SetTitle("1/Events");
   frame_3094f890_copy__4->GetYaxis()->SetLabelFont(42);
   frame_3094f890_copy__4->GetYaxis()->SetTitleFont(42);
   frame_3094f890_copy__4->GetZaxis()->SetLabelFont(42);
   frame_3094f890_copy__4->GetZaxis()->SetTitleOffset(1);
   frame_3094f890_copy__4->GetZaxis()->SetTitleFont(42);
   frame_3094f890_copy__4->Draw("sameaxis");
   
   TPaveText *pt = new TPaveText(0.3424096,0.9332716,0.6575904,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("p_T Balance");
   pt->Draw();
   pad_up->Modified();
   cvs->cd();
  
// ------------>Primitives in pad: pad_up
   TPad *pad_up = new TPad("pad_up", "",0.5,0.5,1,1);
   pad_up->Draw();
   pad_up->cd();
   pad_up->Range(-0.25,-2.767338,2.25,31.82439);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_309055b0__5 = new TH1D("frame_309055b0__5","p_T Balance",25,0,2);
   frame_309055b0__5->SetBinContent(1,28.36522);
   frame_309055b0__5->SetMaximum(28.36522);
   frame_309055b0__5->SetEntries(1);
   frame_309055b0__5->SetDirectory(0);
   frame_309055b0__5->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_309055b0__5->SetLineColor(ci);
   frame_309055b0__5->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_309055b0__5->GetXaxis()->SetLabelFont(42);
   frame_309055b0__5->GetXaxis()->SetTitleOffset(1);
   frame_309055b0__5->GetXaxis()->SetTitleFont(42);
   frame_309055b0__5->GetYaxis()->SetTitle("1/Events");
   frame_309055b0__5->GetYaxis()->SetLabelFont(42);
   frame_309055b0__5->GetYaxis()->SetTitleFont(42);
   frame_309055b0__5->GetZaxis()->SetLabelFont(42);
   frame_309055b0__5->GetZaxis()->SetTitleOffset(1);
   frame_309055b0__5->GetZaxis()->SetTitleFont(42);
   frame_309055b0__5->Draw("FUNC");
   
   Double_t h_dh_up2_fx3002[25] = {
   0.04,
   0.12,
   0.2,
   0.28,
   0.36,
   0.44,
   0.52,
   0.6,
   0.68,
   0.76,
   0.84,
   0.92,
   1,
   1.08,
   1.16,
   1.24,
   1.32,
   1.4,
   1.48,
   1.56,
   1.64,
   1.72,
   1.8,
   1.88,
   1.96};
   Double_t h_dh_up2_fy3002[25] = {
   0.01399929,
   0.3293464,
   0.2990946,
   0.3980331,
   0.7639688,
   1.039856,
   1.050122,
   3.753894,
   6.708328,
   10.99677,
   20.318,
   25.25015,
   22.93333,
   12.78046,
   5.513435,
   2.153262,
   0.5703907,
   0.3085327,
   0.230572,
   0.1086667,
   0,
   0.01806151,
   0.01349559,
   0.007477146,
   0.01768959};
   Double_t h_dh_up2_felx3002[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04};
   Double_t h_dh_up2_fely3002[25] = {
   0.01399929,
   0.1828114,
   0.168972,
   0.1954239,
   0.3052778,
   0.3547645,
   0.3750486,
   0.7796758,
   0.9354126,
   1.207229,
   1.633269,
   1.764348,
   1.706046,
   1.245296,
   0.8207207,
   0.4988011,
   0.22744,
   0.1715694,
   0.1049079,
   0.07140509,
   0,
   0.01243738,
   0.008798115,
   0.006418851,
   0.01021555};
   Double_t h_dh_up2_fehx3002[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04};
   Double_t h_dh_up2_fehy3002[25] = {
   0.01399929,
   0.1828114,
   0.168972,
   0.1954239,
   0.3052778,
   0.3547645,
   0.3750486,
   0.7796758,
   0.9354126,
   1.207229,
   1.633269,
   1.764348,
   1.706046,
   1.245296,
   0.8207207,
   0.4988011,
   0.22744,
   0.1715694,
   0.1049079,
   0.07140509,
   0,
   0.01243738,
   0.008798115,
   0.006418851,
   0.01021555};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3002,h_dh_up2_fy3002,h_dh_up2_felx3002,h_dh_up2_fehx3002,h_dh_up2_fely3002,h_dh_up2_fehy3002);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23002 = new TH1F("Graph_h_dh_up23002","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23002->SetMinimum(0);
   Graph_h_dh_up23002->SetMaximum(29.71594);
   Graph_h_dh_up23002->SetDirectory(0);
   Graph_h_dh_up23002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_up23002->SetLineColor(ci);
   Graph_h_dh_up23002->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_up23002->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_up23002->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_up23002->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_up23002->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_up23002->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_up23002->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_up23002->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_up23002);
   
   grae->Draw("p");
   
   Double_t up_fx2[59] = {
   0.5837798,
   0.6112027,
   0.6386255,
   0.6660484,
   0.6797598,
   0.6934712,
   0.7071827,
   0.7208941,
   0.7346055,
   0.7483169,
   0.7620284,
   0.7757398,
   0.7825955,
   0.7894512,
   0.7963069,
   0.8031627,
   0.8305855,
   0.8442969,
   0.8580084,
   0.8717198,
   0.8785755,
   0.8854312,
   0.8922869,
   0.8991426,
   0.9059984,
   0.9128541,
   0.9197098,
   0.9265655,
   0.9334212,
   0.9402769,
   0.9471326,
   0.9539884,
   0.9608441,
   0.9676998,
   0.9745555,
   0.9814112,
   0.9882669,
   0.9951226,
   1.001978,
   1.008834,
   1.022545,
   1.036257,
   1.049968,
   1.077391,
   1.091103,
   1.104814,
   1.118525,
   1.132237,
   1.145948,
   1.15966,
   1.173371,
   1.187083,
   1.193938,
   1.197366,
   1.200794,
   1.214505,
   1.241928,
   1.269351,
   1.269351};
   Double_t up_fy2[59] = {
   4.920011,
   5.419904,
   6.016412,
   6.738671,
   7.159324,
   7.62838,
   8.154221,
   8.747221,
   9.420366,
   10.19011,
   11.07758,
   12.11036,
   12.69223,
   13.32505,
   14.01546,
   14.77126,
   18.19088,
   19.84861,
   21.39654,
   22.78736,
   23.40969,
   23.97626,
   24.48227,
   24.92333,
   25.29559,
   25.59574,
   25.82111,
   25.96967,
   26.04007,
   26.03168,
   25.94457,
   25.77953,
   25.53805,
   25.22231,
   24.83511,
   24.37989,
   23.86061,
   23.28175,
   22.64822,
   21.96528,
   20.47363,
   18.85341,
   17.15229,
   13.68981,
   12.00994,
   10.40929,
   8.913304,
   7.540379,
   6.302092,
   5.203713,
   4.245012,
   3.421225,
   3.05745,
   2.888135,
   2.788144,
   2.638113,
   2.52841,
   2.471838,
   2.471838};
   graph = new TGraph(59,up_fx2,up_fy2);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up2 = new TH1F("Graph_up2","Projection of upf DSCB fit",100,0.5152227,1.337908);
   Graph_up2->SetMinimum(0.1150142);
   Graph_up2->SetMaximum(28.39689);
   Graph_up2->SetDirectory(0);
   Graph_up2->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_up2->SetLineColor(ci);
   Graph_up2->GetXaxis()->SetLabelFont(42);
   Graph_up2->GetXaxis()->SetTitleOffset(1);
   Graph_up2->GetXaxis()->SetTitleFont(42);
   Graph_up2->GetYaxis()->SetLabelFont(42);
   Graph_up2->GetYaxis()->SetTitleFont(42);
   Graph_up2->GetZaxis()->SetLabelFont(42);
   Graph_up2->GetZaxis()->SetTitleOffset(1);
   Graph_up2->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_up2);
   
   graph->Draw("l");
   
   TH1D *frame_309055b0__6 = new TH1D("frame_309055b0__6","p_T Balance",25,0,2);
   frame_309055b0__6->SetBinContent(1,28.36522);
   frame_309055b0__6->SetMaximum(28.36522);
   frame_309055b0__6->SetEntries(1);
   frame_309055b0__6->SetDirectory(0);
   frame_309055b0__6->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_309055b0__6->SetLineColor(ci);
   frame_309055b0__6->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_309055b0__6->GetXaxis()->SetLabelFont(42);
   frame_309055b0__6->GetXaxis()->SetTitleOffset(1);
   frame_309055b0__6->GetXaxis()->SetTitleFont(42);
   frame_309055b0__6->GetYaxis()->SetTitle("1/Events");
   frame_309055b0__6->GetYaxis()->SetLabelFont(42);
   frame_309055b0__6->GetYaxis()->SetTitleFont(42);
   frame_309055b0__6->GetZaxis()->SetLabelFont(42);
   frame_309055b0__6->GetZaxis()->SetTitleOffset(1);
   frame_309055b0__6->GetZaxis()->SetTitleFont(42);
   frame_309055b0__6->Draw("AXISSAME");
   
   TH1D *norm_u__7 = new TH1D("norm_u__7","",25,0,2);
   norm_u__7->SetBinContent(1,0.01399929);
   norm_u__7->SetBinContent(2,0.3293464);
   norm_u__7->SetBinContent(3,0.2990947);
   norm_u__7->SetBinContent(4,0.3980331);
   norm_u__7->SetBinContent(5,0.7639688);
   norm_u__7->SetBinContent(6,1.039856);
   norm_u__7->SetBinContent(7,1.050122);
   norm_u__7->SetBinContent(8,3.753894);
   norm_u__7->SetBinContent(9,6.708328);
   norm_u__7->SetBinContent(10,10.99677);
   norm_u__7->SetBinContent(11,20.318);
   norm_u__7->SetBinContent(12,25.25015);
   norm_u__7->SetBinContent(13,22.93333);
   norm_u__7->SetBinContent(14,12.78046);
   norm_u__7->SetBinContent(15,5.513435);
   norm_u__7->SetBinContent(16,2.153262);
   norm_u__7->SetBinContent(17,0.5703907);
   norm_u__7->SetBinContent(18,0.3085327);
   norm_u__7->SetBinContent(19,0.230572);
   norm_u__7->SetBinContent(20,0.1086667);
   norm_u__7->SetBinContent(22,0.01806151);
   norm_u__7->SetBinContent(23,0.01349559);
   norm_u__7->SetBinContent(24,0.007477146);
   norm_u__7->SetBinContent(25,0.0176896);
   norm_u__7->SetBinContent(26,0.01512182);
   norm_u__7->SetBinError(1,0.01399929);
   norm_u__7->SetBinError(2,0.1828114);
   norm_u__7->SetBinError(3,0.168972);
   norm_u__7->SetBinError(4,0.1954239);
   norm_u__7->SetBinError(5,0.3052778);
   norm_u__7->SetBinError(6,0.3547645);
   norm_u__7->SetBinError(7,0.3750486);
   norm_u__7->SetBinError(8,0.7796758);
   norm_u__7->SetBinError(9,0.9354126);
   norm_u__7->SetBinError(10,1.207229);
   norm_u__7->SetBinError(11,1.633269);
   norm_u__7->SetBinError(12,1.764348);
   norm_u__7->SetBinError(13,1.706046);
   norm_u__7->SetBinError(14,1.245296);
   norm_u__7->SetBinError(15,0.8207207);
   norm_u__7->SetBinError(16,0.4988011);
   norm_u__7->SetBinError(17,0.22744);
   norm_u__7->SetBinError(18,0.1715694);
   norm_u__7->SetBinError(19,0.1049079);
   norm_u__7->SetBinError(20,0.07140509);
   norm_u__7->SetBinError(22,0.01243738);
   norm_u__7->SetBinError(23,0.008798115);
   norm_u__7->SetBinError(24,0.006418851);
   norm_u__7->SetBinError(25,0.01021555);
   norm_u__7->SetBinError(26,0.007544411);
   norm_u__7->SetEntries(1476);
   norm_u__7->SetStats(0);
   norm_u__7->SetLineColor(4);
   norm_u__7->SetLineWidth(2);
   norm_u__7->GetXaxis()->SetLabelFont(42);
   norm_u__7->GetXaxis()->SetTitleOffset(1);
   norm_u__7->GetXaxis()->SetTitleFont(42);
   norm_u__7->GetYaxis()->SetLabelFont(42);
   norm_u__7->GetYaxis()->SetTitleFont(42);
   norm_u__7->GetZaxis()->SetLabelFont(42);
   norm_u__7->GetZaxis()->SetTitleOffset(1);
   norm_u__7->GetZaxis()->SetTitleFont(42);
   norm_u__7->Draw("e1 same");
   
   leg = new TLegend(0.65,0.5,0.93,0.87,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.03);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   entry=leg->AddEntry("norm_u","JEC up","lpf");
   entry->SetFillStyle(1001);
   entry->SetLineColor(4);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("frame_x_u2_309055b0","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.930184 #pm 0.014007","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.129001 #pm 0.012620","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.943000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_309055b0_copy__8 = new TH1D("frame_309055b0_copy__8","p_T Balance",25,0,2);
   frame_309055b0_copy__8->SetBinContent(1,28.36522);
   frame_309055b0_copy__8->SetMaximum(28.36522);
   frame_309055b0_copy__8->SetEntries(1);
   frame_309055b0_copy__8->SetDirectory(0);
   frame_309055b0_copy__8->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_309055b0_copy__8->SetLineColor(ci);
   frame_309055b0_copy__8->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_309055b0_copy__8->GetXaxis()->SetLabelFont(42);
   frame_309055b0_copy__8->GetXaxis()->SetTitleOffset(1);
   frame_309055b0_copy__8->GetXaxis()->SetTitleFont(42);
   frame_309055b0_copy__8->GetYaxis()->SetTitle("1/Events");
   frame_309055b0_copy__8->GetYaxis()->SetLabelFont(42);
   frame_309055b0_copy__8->GetYaxis()->SetTitleFont(42);
   frame_309055b0_copy__8->GetZaxis()->SetLabelFont(42);
   frame_309055b0_copy__8->GetZaxis()->SetTitleOffset(1);
   frame_309055b0_copy__8->GetZaxis()->SetTitleFont(42);
   frame_309055b0_copy__8->Draw("sameaxis");
   
   pt = new TPaveText(0.3424096,0.9332716,0.6575904,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   pt_LaTex = pt->AddText("p_T Balance");
   pt->Draw();
   pad_up->Modified();
   cvs->cd();
  
// ------------>Primitives in pad: pad_up
   TPad *pad_up = new TPad("pad_up", "",0,0,0.5,0.5);
   pad_up->Draw();
   pad_up->cd();
   pad_up->Range(-0.25,-4.711286,2.25,28.94075);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3095d020__9 = new TH1D("frame_3095d020__9","p_T Balance",25,0,2);
   frame_3095d020__9->SetBinContent(1,28.26771);
   frame_3095d020__9->SetMinimum(-1.346082);
   frame_3095d020__9->SetMaximum(28.26771);
   frame_3095d020__9->SetEntries(1);
   frame_3095d020__9->SetDirectory(0);
   frame_3095d020__9->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3095d020__9->SetLineColor(ci);
   frame_3095d020__9->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3095d020__9->GetXaxis()->SetLabelFont(42);
   frame_3095d020__9->GetXaxis()->SetTitleOffset(1);
   frame_3095d020__9->GetXaxis()->SetTitleFont(42);
   frame_3095d020__9->GetYaxis()->SetTitle("1/Events");
   frame_3095d020__9->GetYaxis()->SetLabelFont(42);
   frame_3095d020__9->GetYaxis()->SetTitleFont(42);
   frame_3095d020__9->GetZaxis()->SetLabelFont(42);
   frame_3095d020__9->GetZaxis()->SetTitleOffset(1);
   frame_3095d020__9->GetZaxis()->SetTitleFont(42);
   frame_3095d020__9->Draw("FUNC");
   
   Double_t h_dh_down2_fx3003[25] = {
   0.04,
   0.12,
   0.2,
   0.28,
   0.36,
   0.44,
   0.52,
   0.6,
   0.68,
   0.76,
   0.84,
   0.92,
   1,
   1.08,
   1.16,
   1.24,
   1.32,
   1.4,
   1.48,
   1.56,
   1.64,
   1.72,
   1.8,
   1.88,
   1.96};
   Double_t h_dh_down2_fy3003[25] = {
   0.01193334,
   0.1117746,
   0.2666887,
   0.2225737,
   0.4127199,
   0.9623217,
   1.343915,
   3.125062,
   7.92321,
   13.68684,
   21.88731,
   25.17333,
   21.24983,
   13.25774,
   4.483509,
   2.193106,
   0.2170324,
   0.3916328,
   0.1904503,
   0.008711135,
   0,
   0.03727381,
   0.01484395,
   0.01231077,
   0.007025328};
   Double_t h_dh_down2_felx3003[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04};
   Double_t h_dh_down2_fely3003[25] = {
   0.01193334,
   0.0546769,
   0.158034,
   0.08936193,
   0.2044579,
   0.327118,
   0.4208503,
   0.6705472,
   1.032529,
   1.340471,
   1.659513,
   1.7483,
   1.634509,
   1.279905,
   0.7355503,
   0.4957134,
   0.08753765,
   0.1818879,
   0.1019407,
   0.008711135,
   0,
   0.01920255,
   0.00898593,
   0.008710625,
   0.005985638};
   Double_t h_dh_down2_fehx3003[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04};
   Double_t h_dh_down2_fehy3003[25] = {
   0.01193334,
   0.0546769,
   0.158034,
   0.08936193,
   0.2044579,
   0.327118,
   0.4208503,
   0.6705472,
   1.032529,
   1.340471,
   1.659513,
   1.7483,
   1.634509,
   1.279905,
   0.7355503,
   0.4957134,
   0.08753765,
   0.1818879,
   0.1019407,
   0.008711135,
   0,
   0.01920255,
   0.00898593,
   0.008710625,
   0.005985638};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3003,h_dh_down2_fy3003,h_dh_down2_felx3003,h_dh_down2_fehx3003,h_dh_down2_fely3003,h_dh_down2_fehy3003);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23003 = new TH1F("Graph_h_dh_down23003","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23003->SetMinimum(-2.692163);
   Graph_h_dh_down23003->SetMaximum(29.6138);
   Graph_h_dh_down23003->SetDirectory(0);
   Graph_h_dh_down23003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_down23003->SetLineColor(ci);
   Graph_h_dh_down23003->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_down23003->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_down23003->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_down23003->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_down23003->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_down23003->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_down23003->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_down23003->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_down23003);
   
   grae->Draw("p");
   
   Double_t down_fx3[58] = {
   0.5394876,
   0.554169,
   0.5688504,
   0.5835319,
   0.5982133,
   0.6128947,
   0.6275762,
   0.6422576,
   0.6569391,
   0.6716205,
   0.6863019,
   0.7009834,
   0.7156648,
   0.7303463,
   0.7450277,
   0.7743906,
   0.789072,
   0.8037534,
   0.8184349,
   0.8331163,
   0.8477978,
   0.8551385,
   0.8624792,
   0.8698199,
   0.8771606,
   0.8845014,
   0.8918421,
   0.8991828,
   0.9065235,
   0.9138642,
   0.921205,
   0.9285457,
   0.9358864,
   0.9432271,
   0.9505678,
   0.9579085,
   0.9652493,
   0.9799307,
   0.9946121,
   1.009294,
   1.023975,
   1.038656,
   1.068019,
   1.082701,
   1.097382,
   1.112064,
   1.126745,
   1.141427,
   1.156108,
   1.170789,
   1.185471,
   1.200152,
   1.214834,
   1.229515,
   1.244197,
   1.258878,
   1.273559,
   1.273559};
   Double_t down_fy3[58] = {
   1.031214,
   1.320345,
   1.675026,
   2.103742,
   2.615776,
   3.219923,
   3.923985,
   4.734196,
   5.654603,
   6.686439,
   7.827529,
   9.071757,
   10.40867,
   11.82322,
   13.29577,
   16.31472,
   17.80197,
   19.23063,
   20.56629,
   21.77486,
   22.82399,
   23.2795,
   23.68454,
   24.03618,
   24.33186,
   24.56938,
   24.747,
   24.86337,
   24.91763,
   24.90937,
   24.83864,
   24.70599,
   24.51241,
   24.25934,
   23.94866,
   23.58265,
   23.16398,
   22.18106,
   21.02753,
   19.73473,
   18.33627,
   16.86662,
   13.84754,
   12.35948,
   10.92107,
   9.553594,
   8.273808,
   7.093834,
   6.021346,
   5.059914,
   4.209492,
   3.466994,
   2.82692,
   2.281975,
   1.823666,
   1.442835,
   1.130121,
   1.130121};
   graph = new TGraph(58,down_fx3,down_fy3);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down3 = new TH1F("Graph_down3","Projection of downf DSCB fit",100,0.4660804,1.346967);
   Graph_down3->SetMinimum(0.928093);
   Graph_down3->SetMaximum(27.30627);
   Graph_down3->SetDirectory(0);
   Graph_down3->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_down3->SetLineColor(ci);
   Graph_down3->GetXaxis()->SetLabelFont(42);
   Graph_down3->GetXaxis()->SetTitleOffset(1);
   Graph_down3->GetXaxis()->SetTitleFont(42);
   Graph_down3->GetYaxis()->SetLabelFont(42);
   Graph_down3->GetYaxis()->SetTitleFont(42);
   Graph_down3->GetZaxis()->SetLabelFont(42);
   Graph_down3->GetZaxis()->SetTitleOffset(1);
   Graph_down3->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_down3);
   
   graph->Draw("l");
   
   TH1D *frame_3095d020__10 = new TH1D("frame_3095d020__10","p_T Balance",25,0,2);
   frame_3095d020__10->SetBinContent(1,28.26771);
   frame_3095d020__10->SetMinimum(-1.346082);
   frame_3095d020__10->SetMaximum(28.26771);
   frame_3095d020__10->SetEntries(1);
   frame_3095d020__10->SetDirectory(0);
   frame_3095d020__10->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3095d020__10->SetLineColor(ci);
   frame_3095d020__10->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3095d020__10->GetXaxis()->SetLabelFont(42);
   frame_3095d020__10->GetXaxis()->SetTitleOffset(1);
   frame_3095d020__10->GetXaxis()->SetTitleFont(42);
   frame_3095d020__10->GetYaxis()->SetTitle("1/Events");
   frame_3095d020__10->GetYaxis()->SetLabelFont(42);
   frame_3095d020__10->GetYaxis()->SetTitleFont(42);
   frame_3095d020__10->GetZaxis()->SetLabelFont(42);
   frame_3095d020__10->GetZaxis()->SetTitleOffset(1);
   frame_3095d020__10->GetZaxis()->SetTitleFont(42);
   frame_3095d020__10->Draw("AXISSAME");
   
   TH1D *norm_d__11 = new TH1D("norm_d__11","",25,0,2);
   norm_d__11->SetBinContent(1,0.01193334);
   norm_d__11->SetBinContent(2,0.1117746);
   norm_d__11->SetBinContent(3,0.2666887);
   norm_d__11->SetBinContent(4,0.2225737);
   norm_d__11->SetBinContent(5,0.4127199);
   norm_d__11->SetBinContent(6,0.9623217);
   norm_d__11->SetBinContent(7,1.343915);
   norm_d__11->SetBinContent(8,3.125061);
   norm_d__11->SetBinContent(9,7.92321);
   norm_d__11->SetBinContent(10,13.68684);
   norm_d__11->SetBinContent(11,21.88731);
   norm_d__11->SetBinContent(12,25.17333);
   norm_d__11->SetBinContent(13,21.24983);
   norm_d__11->SetBinContent(14,13.25774);
   norm_d__11->SetBinContent(15,4.483509);
   norm_d__11->SetBinContent(16,2.193106);
   norm_d__11->SetBinContent(17,0.2170324);
   norm_d__11->SetBinContent(18,0.3916328);
   norm_d__11->SetBinContent(19,0.1904503);
   norm_d__11->SetBinContent(20,0.008711135);
   norm_d__11->SetBinContent(22,0.03727381);
   norm_d__11->SetBinContent(23,0.01484395);
   norm_d__11->SetBinContent(24,0.01231077);
   norm_d__11->SetBinContent(25,0.007025328);
   norm_d__11->SetBinContent(26,0.02066669);
   norm_d__11->SetBinError(1,0.01193334);
   norm_d__11->SetBinError(2,0.0546769);
   norm_d__11->SetBinError(3,0.158034);
   norm_d__11->SetBinError(4,0.08936193);
   norm_d__11->SetBinError(5,0.2044579);
   norm_d__11->SetBinError(6,0.327118);
   norm_d__11->SetBinError(7,0.4208503);
   norm_d__11->SetBinError(8,0.6705472);
   norm_d__11->SetBinError(9,1.032529);
   norm_d__11->SetBinError(10,1.340471);
   norm_d__11->SetBinError(11,1.659513);
   norm_d__11->SetBinError(12,1.7483);
   norm_d__11->SetBinError(13,1.634509);
   norm_d__11->SetBinError(14,1.279905);
   norm_d__11->SetBinError(15,0.7355503);
   norm_d__11->SetBinError(16,0.4957134);
   norm_d__11->SetBinError(17,0.08753765);
   norm_d__11->SetBinError(18,0.1818879);
   norm_d__11->SetBinError(19,0.1019407);
   norm_d__11->SetBinError(20,0.008711135);
   norm_d__11->SetBinError(22,0.01920255);
   norm_d__11->SetBinError(23,0.00898593);
   norm_d__11->SetBinError(24,0.008710625);
   norm_d__11->SetBinError(25,0.005985638);
   norm_d__11->SetBinError(26,0.009116386);
   norm_d__11->SetEntries(1547);
   norm_d__11->SetStats(0);
   norm_d__11->SetLineColor(7);
   norm_d__11->SetLineWidth(2);
   norm_d__11->GetXaxis()->SetLabelFont(42);
   norm_d__11->GetXaxis()->SetTitleOffset(1);
   norm_d__11->GetXaxis()->SetTitleFont(42);
   norm_d__11->GetYaxis()->SetLabelFont(42);
   norm_d__11->GetYaxis()->SetTitleFont(42);
   norm_d__11->GetZaxis()->SetLabelFont(42);
   norm_d__11->GetZaxis()->SetTitleOffset(1);
   norm_d__11->GetZaxis()->SetTitleFont(42);
   norm_d__11->Draw("same e1");
   
   leg = new TLegend(0.65,0.5,0.93,0.87,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.03);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   entry=leg->AddEntry("norm_d","JEC down","lpf");
   entry->SetFillStyle(1001);
   entry->SetLineColor(7);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("frame_x_d2_3095d020","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.909234 #pm 0.014424","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.146531 #pm 0.011977","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.986000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3095d020_copy__12 = new TH1D("frame_3095d020_copy__12","p_T Balance",25,0,2);
   frame_3095d020_copy__12->SetBinContent(1,28.26771);
   frame_3095d020_copy__12->SetMinimum(-1.346082);
   frame_3095d020_copy__12->SetMaximum(28.26771);
   frame_3095d020_copy__12->SetEntries(1);
   frame_3095d020_copy__12->SetDirectory(0);
   frame_3095d020_copy__12->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3095d020_copy__12->SetLineColor(ci);
   frame_3095d020_copy__12->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3095d020_copy__12->GetXaxis()->SetLabelFont(42);
   frame_3095d020_copy__12->GetXaxis()->SetTitleOffset(1);
   frame_3095d020_copy__12->GetXaxis()->SetTitleFont(42);
   frame_3095d020_copy__12->GetYaxis()->SetTitle("1/Events");
   frame_3095d020_copy__12->GetYaxis()->SetLabelFont(42);
   frame_3095d020_copy__12->GetYaxis()->SetTitleFont(42);
   frame_3095d020_copy__12->GetZaxis()->SetLabelFont(42);
   frame_3095d020_copy__12->GetZaxis()->SetTitleOffset(1);
   frame_3095d020_copy__12->GetZaxis()->SetTitleFont(42);
   frame_3095d020_copy__12->Draw("sameaxis");
   
   pt = new TPaveText(0.3424096,0.9332716,0.6575904,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   pt_LaTex = pt->AddText("p_T Balance");
   pt->Draw();
   pad_up->Modified();
   cvs->cd();
  
// ------------>Primitives in pad: pad_up
   TPad *pad_up = new TPad("pad_up", "",0.5,0,1,0.5);
   pad_up->Draw();
   pad_up->cd();
   pad_up->Range(-0.25,-5.781585,2.25,52.03426);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_30960ea0__13 = new TH1D("frame_30960ea0__13","p_T Balance",25,0,2);
   frame_30960ea0__13->SetBinContent(1,50.87794);
   frame_30960ea0__13->SetMaximum(50.87794);
   frame_30960ea0__13->SetEntries(1);
   frame_30960ea0__13->SetDirectory(0);
   frame_30960ea0__13->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30960ea0__13->SetLineColor(ci);
   frame_30960ea0__13->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30960ea0__13->GetXaxis()->SetLabelFont(42);
   frame_30960ea0__13->GetXaxis()->SetTitleOffset(1);
   frame_30960ea0__13->GetXaxis()->SetTitleFont(42);
   frame_30960ea0__13->GetYaxis()->SetTitle("1/Events");
   frame_30960ea0__13->GetYaxis()->SetLabelFont(42);
   frame_30960ea0__13->GetYaxis()->SetTitleFont(42);
   frame_30960ea0__13->GetZaxis()->SetLabelFont(42);
   frame_30960ea0__13->GetZaxis()->SetTitleOffset(1);
   frame_30960ea0__13->GetZaxis()->SetTitleFont(42);
   frame_30960ea0__13->Draw("FUNC");
   
   Double_t h_dh_data2_fx3004[25] = {
   0.04,
   0.12,
   0.2,
   0.28,
   0.36,
   0.44,
   0.52,
   0.6,
   0.68,
   0.76,
   0.84,
   0.92,
   1,
   1.08,
   1.16,
   1.24,
   1.32,
   1.4,
   1.48,
   1.56,
   1.64,
   1.72,
   1.8,
   1.88,
   1.96};
   Double_t h_dh_data2_fy3004[25] = {
   0,
   1,
   2,
   1,
   0,
   0,
   2,
   1,
   10,
   21,
   36,
   41,
   27,
   23,
   10,
   3,
   2,
   1,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t h_dh_data2_felx3004[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04};
   Double_t h_dh_data2_fely3004[25] = {
   0,
   0.8272462,
   1.291815,
   0.8272462,
   0,
   0,
   1.291815,
   0.8272462,
   3.108694,
   4.545807,
   5.971996,
   6.376898,
   5.163771,
   4.760717,
   3.108694,
   1.632705,
   1.291815,
   0.8272462,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t h_dh_data2_fehx3004[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04};
   Double_t h_dh_data2_fehy3004[25] = {
   1.147874,
   2.299527,
   2.63786,
   2.299527,
   1.147874,
   1.147874,
   2.63786,
   2.299527,
   4.26695,
   5.655182,
   7.055545,
   7.455185,
   6.260244,
   5.865235,
   4.26695,
   2.918186,
   2.63786,
   2.299527,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874};
   grae = new TGraphAsymmErrors(25,h_dh_data2_fx3004,h_dh_data2_fy3004,h_dh_data2_felx3004,h_dh_data2_fehx3004,h_dh_data2_fely3004,h_dh_data2_fehy3004);
   grae->SetName("h_dh_data2");
   grae->SetTitle("Histogram of dh_data2_plot__x_o2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_data23004 = new TH1F("Graph_h_dh_data23004","Histogram of dh_data2_plot__x_o2",100,0,2.2);
   Graph_h_dh_data23004->SetMinimum(0);
   Graph_h_dh_data23004->SetMaximum(53.3007);
   Graph_h_dh_data23004->SetDirectory(0);
   Graph_h_dh_data23004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_data23004->SetLineColor(ci);
   Graph_h_dh_data23004->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_data23004->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_data23004->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_data23004->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_data23004->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_data23004->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_data23004->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_data23004->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_data23004);
   
   grae->Draw("p");
   
   Double_t observation_fx4[58] = {
   0.554238,
   0.5690755,
   0.5839131,
   0.5987507,
   0.6135883,
   0.6284259,
   0.6432634,
   0.658101,
   0.6729386,
   0.6877762,
   0.7026138,
   0.7174513,
   0.7322889,
   0.7471265,
   0.7619641,
   0.7916392,
   0.8064768,
   0.8213144,
   0.836152,
   0.8509895,
   0.8584083,
   0.8658271,
   0.8732459,
   0.8806647,
   0.8880835,
   0.8955023,
   0.9029211,
   0.9103399,
   0.9177587,
   0.9251774,
   0.9325962,
   0.940015,
   0.9474338,
   0.9548526,
   0.9622714,
   0.9696902,
   0.977109,
   0.9845278,
   0.9993653,
   1.014203,
   1.02904,
   1.058716,
   1.088391,
   1.103228,
   1.118066,
   1.132904,
   1.147741,
   1.162579,
   1.177416,
   1.192254,
   1.207091,
   1.221929,
   1.236767,
   1.251604,
   1.266442,
   1.281279,
   1.296117,
   1.296117};
   Double_t observation_fy4[58] = {
   1.175237,
   1.554194,
   2.03178,
   2.625668,
   3.354243,
   4.235854,
   5.28785,
   6.525427,
   7.960317,
   9.599387,
   11.44322,
   13.48481,
   15.70843,
   18.08892,
   20.59131,
   25.77519,
   28.34316,
   30.80962,
   33.10672,
   35.16718,
   36.0886,
   36.92756,
   37.67723,
   38.33146,
   38.88477,
   39.33252,
   39.67088,
   39.89696,
   40.00882,
   40.00548,
   39.88699,
   39.65436,
   39.30959,
   38.85563,
   38.29635,
   37.63645,
   36.88145,
   36.03754,
   34.1109,
   31.91706,
   29.52189,
   24.39844,
   19.25513,
   16.81226,
   14.511,
   12.38113,
   10.44276,
   8.706859,
   7.176282,
   5.846948,
   4.709237,
   3.749415,
   2.950993,
   2.295961,
   1.765845,
   1.342555,
   1.009029,
   1.009029};
   graph = new TGraph(58,observation_fx4,observation_fy4);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation4 = new TH1F("Graph_observation4","Projection of obsf DSCB fit",100,0.4800501,1.370305);
   Graph_observation4->SetMinimum(0.9081259);
   Graph_observation4->SetMaximum(43.90879);
   Graph_observation4->SetDirectory(0);
   Graph_observation4->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_observation4->SetLineColor(ci);
   Graph_observation4->GetXaxis()->SetLabelFont(42);
   Graph_observation4->GetXaxis()->SetTitleOffset(1);
   Graph_observation4->GetXaxis()->SetTitleFont(42);
   Graph_observation4->GetYaxis()->SetLabelFont(42);
   Graph_observation4->GetYaxis()->SetTitleFont(42);
   Graph_observation4->GetZaxis()->SetLabelFont(42);
   Graph_observation4->GetZaxis()->SetTitleOffset(1);
   Graph_observation4->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_observation4);
   
   graph->Draw("l");
   
   TH1D *frame_30960ea0__14 = new TH1D("frame_30960ea0__14","p_T Balance",25,0,2);
   frame_30960ea0__14->SetBinContent(1,50.87794);
   frame_30960ea0__14->SetMaximum(50.87794);
   frame_30960ea0__14->SetEntries(1);
   frame_30960ea0__14->SetDirectory(0);
   frame_30960ea0__14->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30960ea0__14->SetLineColor(ci);
   frame_30960ea0__14->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30960ea0__14->GetXaxis()->SetLabelFont(42);
   frame_30960ea0__14->GetXaxis()->SetTitleOffset(1);
   frame_30960ea0__14->GetXaxis()->SetTitleFont(42);
   frame_30960ea0__14->GetYaxis()->SetTitle("1/Events");
   frame_30960ea0__14->GetYaxis()->SetLabelFont(42);
   frame_30960ea0__14->GetYaxis()->SetTitleFont(42);
   frame_30960ea0__14->GetZaxis()->SetLabelFont(42);
   frame_30960ea0__14->GetZaxis()->SetTitleOffset(1);
   frame_30960ea0__14->GetZaxis()->SetTitleFont(42);
   frame_30960ea0__14->Draw("AXISSAME");
   
   TH1D *norm_o__15 = new TH1D("norm_o__15","",25,0,2);
   norm_o__15->SetBinContent(2,1);
   norm_o__15->SetBinContent(3,2);
   norm_o__15->SetBinContent(4,1);
   norm_o__15->SetBinContent(7,2);
   norm_o__15->SetBinContent(8,1);
   norm_o__15->SetBinContent(9,10);
   norm_o__15->SetBinContent(10,21);
   norm_o__15->SetBinContent(11,36);
   norm_o__15->SetBinContent(12,41);
   norm_o__15->SetBinContent(13,27);
   norm_o__15->SetBinContent(14,23);
   norm_o__15->SetBinContent(15,10);
   norm_o__15->SetBinContent(16,3);
   norm_o__15->SetBinContent(17,2);
   norm_o__15->SetBinContent(18,1);
   norm_o__15->SetMinimum(0);
   norm_o__15->SetMaximum(90.2);
   norm_o__15->SetEntries(181);
   norm_o__15->SetStats(0);
   norm_o__15->SetLineWidth(2);
   norm_o__15->SetMarkerStyle(8);
   norm_o__15->SetMarkerSize(0.4);
   norm_o__15->GetXaxis()->SetRange(1,25);
   norm_o__15->GetXaxis()->SetLabelFont(42);
   norm_o__15->GetXaxis()->SetLabelSize(0.04);
   norm_o__15->GetXaxis()->SetTitleOffset(1);
   norm_o__15->GetXaxis()->SetTitleFont(42);
   norm_o__15->GetYaxis()->SetTitle("Events");
   norm_o__15->GetYaxis()->SetLabelFont(42);
   norm_o__15->GetYaxis()->SetTitleOffset(1.4);
   norm_o__15->GetYaxis()->SetTitleFont(42);
   norm_o__15->GetZaxis()->SetLabelFont(42);
   norm_o__15->GetZaxis()->SetTitleOffset(1);
   norm_o__15->GetZaxis()->SetTitleFont(42);
   norm_o__15->Draw("same e1");
   
   leg = new TLegend(0.65,0.5,0.93,0.87,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.03);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   entry=leg->AddEntry("norm_o","Data","lpf");
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(8);
   entry->SetMarkerSize(0.4);
   entry->SetTextFont(42);
   entry=leg->AddEntry("frame_x_o2_30960ea0","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.921166 #pm 0.010859","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.138191 #pm 0.008628","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.995000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_30960ea0_copy__16 = new TH1D("frame_30960ea0_copy__16","p_T Balance",25,0,2);
   frame_30960ea0_copy__16->SetBinContent(1,50.87794);
   frame_30960ea0_copy__16->SetMaximum(50.87794);
   frame_30960ea0_copy__16->SetEntries(1);
   frame_30960ea0_copy__16->SetDirectory(0);
   frame_30960ea0_copy__16->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30960ea0_copy__16->SetLineColor(ci);
   frame_30960ea0_copy__16->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30960ea0_copy__16->GetXaxis()->SetLabelFont(42);
   frame_30960ea0_copy__16->GetXaxis()->SetTitleOffset(1);
   frame_30960ea0_copy__16->GetXaxis()->SetTitleFont(42);
   frame_30960ea0_copy__16->GetYaxis()->SetTitle("1/Events");
   frame_30960ea0_copy__16->GetYaxis()->SetLabelFont(42);
   frame_30960ea0_copy__16->GetYaxis()->SetTitleFont(42);
   frame_30960ea0_copy__16->GetZaxis()->SetLabelFont(42);
   frame_30960ea0_copy__16->GetZaxis()->SetTitleOffset(1);
   frame_30960ea0_copy__16->GetZaxis()->SetTitleFont(42);
   frame_30960ea0_copy__16->Draw("sameaxis");
   
   pt = new TPaveText(0.3424096,0.9332716,0.6575904,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   pt_LaTex = pt->AddText("p_T Balance");
   pt->Draw();
   pad_up->Modified();
   cvs->cd();
   cvs->Modified();
   cvs->cd();
   cvs->SetSelected(cvs);
}
