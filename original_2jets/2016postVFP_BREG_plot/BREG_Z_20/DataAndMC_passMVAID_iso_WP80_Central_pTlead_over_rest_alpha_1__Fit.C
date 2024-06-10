void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_1__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 17:48:17 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-2.003672,2.25,15.0819);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_30ee41f0__1 = new TH1D("frame_30ee41f0__1","p_T Balance",25,0,2);
   frame_30ee41f0__1->SetBinContent(1,13.37334);
   frame_30ee41f0__1->SetMinimum(-0.6368259);
   frame_30ee41f0__1->SetMaximum(13.37334);
   frame_30ee41f0__1->SetEntries(1);
   frame_30ee41f0__1->SetDirectory(0);
   frame_30ee41f0__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_30ee41f0__1->SetLineColor(ci);
   frame_30ee41f0__1->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30ee41f0__1->GetXaxis()->SetLabelFont(42);
   frame_30ee41f0__1->GetXaxis()->SetTitleOffset(1);
   frame_30ee41f0__1->GetXaxis()->SetTitleFont(42);
   frame_30ee41f0__1->GetYaxis()->SetTitle("1/Events");
   frame_30ee41f0__1->GetYaxis()->SetLabelFont(42);
   frame_30ee41f0__1->GetYaxis()->SetTitleFont(42);
   frame_30ee41f0__1->GetZaxis()->SetLabelFont(42);
   frame_30ee41f0__1->GetZaxis()->SetTitleOffset(1);
   frame_30ee41f0__1->GetZaxis()->SetTitleFont(42);
   frame_30ee41f0__1->Draw("FUNC");
   
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
   0,
   0.1823441,
   0,
   0.4141467,
   0.2023718,
   1.131626,
   0.5725149,
   1.837665,
   3.073196,
   5.734124,
   8.104193,
   11.40405,
   10.46133,
   6.264397,
   1.935703,
   0.3648703,
   0.5883027,
   0.06591415,
   0.04438194,
   0.01772166,
   0,
   0.004956421,
   0,
   0,
   0};
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
   0,
   0.1440736,
   0,
   0.2534822,
   0.1587935,
   0.4653244,
   0.4247483,
   0.564262,
   0.7146656,
   0.8995033,
   1.159998,
   1.332463,
   1.243682,
   1.036567,
   0.5435779,
   0.1958634,
   0.2947485,
   0.06591414,
   0.03652982,
   0.01256932,
   0,
   0.004956421,
   0,
   0,
   0};
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
   0,
   0.1440736,
   0,
   0.2534822,
   0.1587935,
   0.4653244,
   0.4247483,
   0.564262,
   0.7146656,
   0.8995033,
   1.159998,
   1.332463,
   1.243682,
   1.036567,
   0.5435779,
   0.1958634,
   0.2947485,
   0.06591414,
   0.03652982,
   0.01256932,
   0,
   0.004956421,
   0,
   0,
   0};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3001,h_dh_central2_fy3001,h_dh_central2_felx3001,h_dh_central2_fehx3001,h_dh_central2_fely3001,h_dh_central2_fehy3001);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23001 = new TH1F("Graph_h_dh_central23001","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23001->SetMinimum(-1.273652);
   Graph_h_dh_central23001->SetMaximum(14.01017);
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
   
   Double_t Central_fx1[55] = {
   0.6337968,
   0.6579028,
   0.6820089,
   0.7061149,
   0.7181679,
   0.730221,
   0.742274,
   0.754327,
   0.7663801,
   0.7784331,
   0.7904861,
   0.8025391,
   0.8145922,
   0.8266452,
   0.8507512,
   0.8628043,
   0.8748573,
   0.8869103,
   0.8929368,
   0.8989633,
   0.9049899,
   0.9110164,
   0.9170429,
   0.9230694,
   0.9290959,
   0.9351224,
   0.9411489,
   0.9471755,
   0.953202,
   0.9592285,
   0.965255,
   0.9712815,
   0.977308,
   0.9833345,
   0.9953876,
   1.007441,
   1.019494,
   1.031547,
   1.0436,
   1.067706,
   1.079759,
   1.091812,
   1.103865,
   1.115918,
   1.127971,
   1.140024,
   1.152077,
   1.16413,
   1.176183,
   1.188236,
   1.200289,
   1.212342,
   1.224395,
   1.236448,
   1.236448};
   Double_t Central_fy1[55] = {
   2.33888,
   2.673385,
   3.069889,
   3.542706,
   3.813269,
   4.110161,
   4.436518,
   4.795921,
   5.192467,
   5.630859,
   6.11651,
   6.655668,
   7.255564,
   7.924599,
   9.358173,
   10.01537,
   10.60669,
   11.11554,
   11.3343,
   11.52706,
   11.69234,
   11.82888,
   11.93563,
   12.01175,
   12.05664,
   12.06996,
   12.05161,
   12.00171,
   11.92067,
   11.80913,
   11.66794,
   11.49819,
   11.3012,
   11.07845,
   10.56247,
   9.965276,
   9.303591,
   8.595065,
   7.857513,
   6.363104,
   5.636597,
   4.940856,
   4.285731,
   3.678619,
   3.124512,
   2.626133,
   2.184182,
   1.797621,
   1.464013,
   1.179855,
   0.9409145,
   0.7425212,
   0.5798356,
   0.4480621,
   0.4480621};
   TGraph *graph = new TGraph(55,Central_fx1,Central_fy1);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central1 = new TH1F("Graph_Central1","Projection of centralf DSCB fit",100,0.5735316,1.296713);
   Graph_Central1->SetMinimum(0.4032559);
   Graph_Central1->SetMaximum(13.23216);
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
   
   TH1D *frame_30ee41f0__2 = new TH1D("frame_30ee41f0__2","p_T Balance",25,0,2);
   frame_30ee41f0__2->SetBinContent(1,13.37334);
   frame_30ee41f0__2->SetMinimum(-0.6368259);
   frame_30ee41f0__2->SetMaximum(13.37334);
   frame_30ee41f0__2->SetEntries(1);
   frame_30ee41f0__2->SetDirectory(0);
   frame_30ee41f0__2->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30ee41f0__2->SetLineColor(ci);
   frame_30ee41f0__2->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30ee41f0__2->GetXaxis()->SetLabelFont(42);
   frame_30ee41f0__2->GetXaxis()->SetTitleOffset(1);
   frame_30ee41f0__2->GetXaxis()->SetTitleFont(42);
   frame_30ee41f0__2->GetYaxis()->SetTitle("1/Events");
   frame_30ee41f0__2->GetYaxis()->SetLabelFont(42);
   frame_30ee41f0__2->GetYaxis()->SetTitleFont(42);
   frame_30ee41f0__2->GetZaxis()->SetLabelFont(42);
   frame_30ee41f0__2->GetZaxis()->SetTitleOffset(1);
   frame_30ee41f0__2->GetZaxis()->SetTitleFont(42);
   frame_30ee41f0__2->Draw("AXISSAME");
   
   TH1D *norm_c__3 = new TH1D("norm_c__3","",25,0,2);
   norm_c__3->SetBinContent(2,0.1823441);
   norm_c__3->SetBinContent(4,0.4141467);
   norm_c__3->SetBinContent(5,0.2023718);
   norm_c__3->SetBinContent(6,1.131626);
   norm_c__3->SetBinContent(7,0.5725149);
   norm_c__3->SetBinContent(8,1.837665);
   norm_c__3->SetBinContent(9,3.073196);
   norm_c__3->SetBinContent(10,5.734123);
   norm_c__3->SetBinContent(11,8.104193);
   norm_c__3->SetBinContent(12,11.40406);
   norm_c__3->SetBinContent(13,10.46133);
   norm_c__3->SetBinContent(14,6.264396);
   norm_c__3->SetBinContent(15,1.935703);
   norm_c__3->SetBinContent(16,0.3648703);
   norm_c__3->SetBinContent(17,0.5883027);
   norm_c__3->SetBinContent(18,0.06591414);
   norm_c__3->SetBinContent(19,0.04438194);
   norm_c__3->SetBinContent(20,0.01772166);
   norm_c__3->SetBinContent(22,0.004956421);
   norm_c__3->SetBinContent(26,0.01076375);
   norm_c__3->SetBinError(2,0.1440736);
   norm_c__3->SetBinError(4,0.2534822);
   norm_c__3->SetBinError(5,0.1587935);
   norm_c__3->SetBinError(6,0.4653244);
   norm_c__3->SetBinError(7,0.4247483);
   norm_c__3->SetBinError(8,0.564262);
   norm_c__3->SetBinError(9,0.7146656);
   norm_c__3->SetBinError(10,0.8995033);
   norm_c__3->SetBinError(11,1.159998);
   norm_c__3->SetBinError(12,1.332463);
   norm_c__3->SetBinError(13,1.243682);
   norm_c__3->SetBinError(14,1.036567);
   norm_c__3->SetBinError(15,0.5435779);
   norm_c__3->SetBinError(16,0.1958634);
   norm_c__3->SetBinError(17,0.2947485);
   norm_c__3->SetBinError(18,0.06591414);
   norm_c__3->SetBinError(19,0.03652982);
   norm_c__3->SetBinError(20,0.01256932);
   norm_c__3->SetBinError(22,0.004956421);
   norm_c__3->SetBinError(26,0.008575999);
   norm_c__3->SetEntries(617);
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
   entry=leg->AddEntry("frame_x_c2_30ee41f0","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.955648 #pm 0.020085","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.102649 #pm 0.017061","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 1.000000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_30ee41f0_copy__4 = new TH1D("frame_30ee41f0_copy__4","p_T Balance",25,0,2);
   frame_30ee41f0_copy__4->SetBinContent(1,13.37334);
   frame_30ee41f0_copy__4->SetMinimum(-0.6368259);
   frame_30ee41f0_copy__4->SetMaximum(13.37334);
   frame_30ee41f0_copy__4->SetEntries(1);
   frame_30ee41f0_copy__4->SetDirectory(0);
   frame_30ee41f0_copy__4->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30ee41f0_copy__4->SetLineColor(ci);
   frame_30ee41f0_copy__4->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30ee41f0_copy__4->GetXaxis()->SetLabelFont(42);
   frame_30ee41f0_copy__4->GetXaxis()->SetTitleOffset(1);
   frame_30ee41f0_copy__4->GetXaxis()->SetTitleFont(42);
   frame_30ee41f0_copy__4->GetYaxis()->SetTitle("1/Events");
   frame_30ee41f0_copy__4->GetYaxis()->SetLabelFont(42);
   frame_30ee41f0_copy__4->GetYaxis()->SetTitleFont(42);
   frame_30ee41f0_copy__4->GetZaxis()->SetLabelFont(42);
   frame_30ee41f0_copy__4->GetZaxis()->SetTitleOffset(1);
   frame_30ee41f0_copy__4->GetZaxis()->SetTitleFont(42);
   frame_30ee41f0_copy__4->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-1.881163,2.25,14.15976);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_30ee1970__5 = new TH1D("frame_30ee1970__5","p_T Balance",25,0,2);
   frame_30ee1970__5->SetBinContent(1,12.55567);
   frame_30ee1970__5->SetMinimum(-0.5978891);
   frame_30ee1970__5->SetMaximum(12.55567);
   frame_30ee1970__5->SetEntries(1);
   frame_30ee1970__5->SetDirectory(0);
   frame_30ee1970__5->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30ee1970__5->SetLineColor(ci);
   frame_30ee1970__5->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30ee1970__5->GetXaxis()->SetLabelFont(42);
   frame_30ee1970__5->GetXaxis()->SetTitleOffset(1);
   frame_30ee1970__5->GetXaxis()->SetTitleFont(42);
   frame_30ee1970__5->GetYaxis()->SetTitle("1/Events");
   frame_30ee1970__5->GetYaxis()->SetLabelFont(42);
   frame_30ee1970__5->GetYaxis()->SetTitleFont(42);
   frame_30ee1970__5->GetZaxis()->SetLabelFont(42);
   frame_30ee1970__5->GetZaxis()->SetTitleOffset(1);
   frame_30ee1970__5->GetZaxis()->SetTitleFont(42);
   frame_30ee1970__5->Draw("FUNC");
   
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
   0,
   0.1842998,
   0,
   0.4154146,
   0.2029337,
   0.44498,
   1.21149,
   1.868584,
   3.069284,
   4.83215,
   8.412854,
   10.67993,
   10.61315,
   6.879456,
   2.011174,
   0.5411205,
   0.5483358,
   0,
   0.01626766,
   0.0176309,
   0,
   0.004928898,
   0,
   0,
   0};
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
   0,
   0.1456743,
   0,
   0.2544202,
   0.1594054,
   0.2113403,
   0.6247107,
   0.5768892,
   0.7162336,
   0.8173951,
   1.172061,
   1.277853,
   1.253827,
   1.090405,
   0.5373718,
   0.2602756,
   0.2919466,
   0,
   0.01156496,
   0.01250534,
   0,
   0.004928898,
   0,
   0,
   0};
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
   0,
   0.1456743,
   0,
   0.2544202,
   0.1594054,
   0.2113403,
   0.6247107,
   0.5768892,
   0.7162336,
   0.8173951,
   1.172061,
   1.277853,
   1.253827,
   1.090405,
   0.5373718,
   0.2602756,
   0.2919466,
   0,
   0.01156496,
   0.01250534,
   0,
   0.004928898,
   0,
   0,
   0};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3002,h_dh_up2_fy3002,h_dh_up2_felx3002,h_dh_up2_fehx3002,h_dh_up2_fely3002,h_dh_up2_fehy3002);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23002 = new TH1F("Graph_h_dh_up23002","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23002->SetMinimum(-1.195778);
   Graph_h_dh_up23002->SetMaximum(13.15356);
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
   0.6159596,
   0.6420058,
   0.668052,
   0.6810751,
   0.6940982,
   0.7071213,
   0.7201444,
   0.7331675,
   0.7461906,
   0.7592137,
   0.7722368,
   0.7852599,
   0.798283,
   0.8113061,
   0.8243292,
   0.8373523,
   0.8503754,
   0.8633985,
   0.8764216,
   0.8829331,
   0.8894447,
   0.8959562,
   0.9024678,
   0.9089793,
   0.9154909,
   0.9220024,
   0.928514,
   0.9350255,
   0.9415371,
   0.9480486,
   0.9545602,
   0.9610717,
   0.9675833,
   0.9740948,
   0.9806064,
   0.987118,
   0.9936295,
   1.000141,
   1.006653,
   1.019676,
   1.032699,
   1.045722,
   1.058745,
   1.084791,
   1.097814,
   1.110837,
   1.123861,
   1.136884,
   1.149907,
   1.16293,
   1.175953,
   1.188976,
   1.201999,
   1.215022,
   1.228045,
   1.241068,
   1.254092,
   1.267115,
   1.267115};
   Double_t up_fy2[59] = {
   1.747147,
   2.040416,
   2.397885,
   2.605995,
   2.837179,
   3.094578,
   3.381841,
   3.703223,
   4.063706,
   4.469138,
   4.926418,
   5.443708,
   6.030712,
   6.699015,
   7.444906,
   8.191485,
   8.911907,
   9.587009,
   10.19765,
   10.47304,
   10.72561,
   10.95335,
   11.15445,
   11.32727,
   11.4704,
   11.58266,
   11.6631,
   11.71105,
   11.7261,
   11.70814,
   11.6573,
   11.57403,
   11.45901,
   11.31321,
   11.13783,
   10.93431,
   10.7043,
   10.44965,
   10.17234,
   9.558464,
   8.880957,
   8.158981,
   7.41168,
   5.912781,
   5.192616,
   4.509051,
   3.871584,
   3.286977,
   2.759366,
   2.290479,
   1.879958,
   1.525718,
   1.224349,
   0.9714946,
   0.7622199,
   0.5913229,
   0.4536006,
   0.3440545,
   0.3440545};
   graph = new TGraph(59,up_fx2,up_fy2);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up2 = new TH1F("Graph_up2","Projection of upf DSCB fit",100,0.5508441,1.33223);
   Graph_up2->SetMinimum(0.309649);
   Graph_up2->SetMaximum(12.86431);
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
   
   TH1D *frame_30ee1970__6 = new TH1D("frame_30ee1970__6","p_T Balance",25,0,2);
   frame_30ee1970__6->SetBinContent(1,12.55567);
   frame_30ee1970__6->SetMinimum(-0.5978891);
   frame_30ee1970__6->SetMaximum(12.55567);
   frame_30ee1970__6->SetEntries(1);
   frame_30ee1970__6->SetDirectory(0);
   frame_30ee1970__6->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30ee1970__6->SetLineColor(ci);
   frame_30ee1970__6->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30ee1970__6->GetXaxis()->SetLabelFont(42);
   frame_30ee1970__6->GetXaxis()->SetTitleOffset(1);
   frame_30ee1970__6->GetXaxis()->SetTitleFont(42);
   frame_30ee1970__6->GetYaxis()->SetTitle("1/Events");
   frame_30ee1970__6->GetYaxis()->SetLabelFont(42);
   frame_30ee1970__6->GetYaxis()->SetTitleFont(42);
   frame_30ee1970__6->GetZaxis()->SetLabelFont(42);
   frame_30ee1970__6->GetZaxis()->SetTitleOffset(1);
   frame_30ee1970__6->GetZaxis()->SetTitleFont(42);
   frame_30ee1970__6->Draw("AXISSAME");
   
   TH1D *norm_u__7 = new TH1D("norm_u__7","",25,0,2);
   norm_u__7->SetBinContent(2,0.1842998);
   norm_u__7->SetBinContent(4,0.4154146);
   norm_u__7->SetBinContent(5,0.2029337);
   norm_u__7->SetBinContent(6,0.44498);
   norm_u__7->SetBinContent(7,1.21149);
   norm_u__7->SetBinContent(8,1.868584);
   norm_u__7->SetBinContent(9,3.069284);
   norm_u__7->SetBinContent(10,4.832151);
   norm_u__7->SetBinContent(11,8.412854);
   norm_u__7->SetBinContent(12,10.67993);
   norm_u__7->SetBinContent(13,10.61315);
   norm_u__7->SetBinContent(14,6.879456);
   norm_u__7->SetBinContent(15,2.011174);
   norm_u__7->SetBinContent(16,0.5411205);
   norm_u__7->SetBinContent(17,0.5483358);
   norm_u__7->SetBinContent(19,0.01626766);
   norm_u__7->SetBinContent(20,0.01763091);
   norm_u__7->SetBinContent(22,0.004928898);
   norm_u__7->SetBinContent(26,0.002346652);
   norm_u__7->SetBinError(2,0.1456743);
   norm_u__7->SetBinError(4,0.2544202);
   norm_u__7->SetBinError(5,0.1594054);
   norm_u__7->SetBinError(6,0.2113403);
   norm_u__7->SetBinError(7,0.6247107);
   norm_u__7->SetBinError(8,0.5768892);
   norm_u__7->SetBinError(9,0.7162336);
   norm_u__7->SetBinError(10,0.8173951);
   norm_u__7->SetBinError(11,1.172061);
   norm_u__7->SetBinError(12,1.277853);
   norm_u__7->SetBinError(13,1.253827);
   norm_u__7->SetBinError(14,1.090405);
   norm_u__7->SetBinError(15,0.5373718);
   norm_u__7->SetBinError(16,0.2602756);
   norm_u__7->SetBinError(17,0.2919466);
   norm_u__7->SetBinError(19,0.01156496);
   norm_u__7->SetBinError(20,0.01250534);
   norm_u__7->SetBinError(22,0.004928898);
   norm_u__7->SetBinError(26,0.001662675);
   norm_u__7->SetEntries(608);
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
   entry=leg->AddEntry("frame_x_u2_30ee1970","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.940812 #pm 0.022736","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.119911 #pm 0.020216","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.993000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_30ee1970_copy__8 = new TH1D("frame_30ee1970_copy__8","p_T Balance",25,0,2);
   frame_30ee1970_copy__8->SetBinContent(1,12.55567);
   frame_30ee1970_copy__8->SetMinimum(-0.5978891);
   frame_30ee1970_copy__8->SetMaximum(12.55567);
   frame_30ee1970_copy__8->SetEntries(1);
   frame_30ee1970_copy__8->SetDirectory(0);
   frame_30ee1970_copy__8->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30ee1970_copy__8->SetLineColor(ci);
   frame_30ee1970_copy__8->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30ee1970_copy__8->GetXaxis()->SetLabelFont(42);
   frame_30ee1970_copy__8->GetXaxis()->SetTitleOffset(1);
   frame_30ee1970_copy__8->GetXaxis()->SetTitleFont(42);
   frame_30ee1970_copy__8->GetYaxis()->SetTitle("1/Events");
   frame_30ee1970_copy__8->GetYaxis()->SetLabelFont(42);
   frame_30ee1970_copy__8->GetYaxis()->SetTitleFont(42);
   frame_30ee1970_copy__8->GetZaxis()->SetLabelFont(42);
   frame_30ee1970_copy__8->GetZaxis()->SetTitleOffset(1);
   frame_30ee1970_copy__8->GetZaxis()->SetTitleFont(42);
   frame_30ee1970_copy__8->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-2.180543,2.25,13.39476);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_30ef60d0__9 = new TH1D("frame_30ef60d0__9","p_T Balance",25,0,2);
   frame_30ef60d0__9->SetBinContent(1,13.08325);
   frame_30ef60d0__9->SetMinimum(-0.6230121);
   frame_30ef60d0__9->SetMaximum(13.08325);
   frame_30ef60d0__9->SetEntries(1);
   frame_30ef60d0__9->SetDirectory(0);
   frame_30ef60d0__9->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30ef60d0__9->SetLineColor(ci);
   frame_30ef60d0__9->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30ef60d0__9->GetXaxis()->SetLabelFont(42);
   frame_30ef60d0__9->GetXaxis()->SetTitleOffset(1);
   frame_30ef60d0__9->GetXaxis()->SetTitleFont(42);
   frame_30ef60d0__9->GetYaxis()->SetTitle("1/Events");
   frame_30ef60d0__9->GetYaxis()->SetLabelFont(42);
   frame_30ef60d0__9->GetYaxis()->SetTitleFont(42);
   frame_30ef60d0__9->GetZaxis()->SetLabelFont(42);
   frame_30ef60d0__9->GetZaxis()->SetTitleOffset(1);
   frame_30ef60d0__9->GetZaxis()->SetTitleFont(42);
   frame_30ef60d0__9->Draw("FUNC");
   
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
   0,
   0.1828583,
   0.2095299,
   0.310573,
   0.2373215,
   0.9486898,
   0.784159,
   1.433575,
   3.491392,
   6.351968,
   10.44215,
   11.14904,
   8.385995,
   5.800105,
   1.460312,
   0.400752,
   0.592962,
   0.1021515,
   0,
   0.01940302,
   0.00499676,
   0.004622551,
   0,
   0,
   0};
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
   0,
   0.1446367,
   0.2095299,
   0.1789923,
   0.1626223,
   0.4287247,
   0.4668619,
   0.4786803,
   0.7808963,
   0.931941,
   1.381971,
   1.311202,
   1.083683,
   1.034961,
   0.4112211,
   0.2001832,
   0.2971654,
   0.07543368,
   0,
   0.01276464,
   0.004996761,
   0.00462255,
   0,
   0,
   0};
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
   0,
   0.1446367,
   0.2095299,
   0.1789923,
   0.1626223,
   0.4287247,
   0.4668619,
   0.4786803,
   0.7808963,
   0.931941,
   1.381971,
   1.311202,
   1.083683,
   1.034961,
   0.4112211,
   0.2001832,
   0.2971654,
   0.07543368,
   0,
   0.01276464,
   0.004996761,
   0.00462255,
   0,
   0,
   0};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3003,h_dh_down2_fy3003,h_dh_down2_felx3003,h_dh_down2_fehx3003,h_dh_down2_fely3003,h_dh_down2_fehy3003);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23003 = new TH1F("Graph_h_dh_down23003","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23003->SetMinimum(-1.246024);
   Graph_h_dh_down23003->SetMaximum(13.70627);
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
   0.5397621,
   0.5540056,
   0.5682491,
   0.5824926,
   0.5967361,
   0.6109796,
   0.6252231,
   0.6394666,
   0.6537101,
   0.6679536,
   0.6821971,
   0.6964406,
   0.7106841,
   0.7249276,
   0.7391711,
   0.7676581,
   0.7819016,
   0.7961452,
   0.8103887,
   0.8246322,
   0.8388757,
   0.8459974,
   0.8531192,
   0.8602409,
   0.8673627,
   0.8744844,
   0.8816062,
   0.8887279,
   0.8958497,
   0.9029714,
   0.9100932,
   0.9172149,
   0.9243367,
   0.9314584,
   0.9385802,
   0.9457019,
   0.9528237,
   0.9670672,
   0.9813107,
   0.9955542,
   1.009798,
   1.024041,
   1.052528,
   1.066772,
   1.081015,
   1.095259,
   1.109502,
   1.123746,
   1.137989,
   1.152233,
   1.166476,
   1.18072,
   1.194963,
   1.209207,
   1.22345,
   1.237694,
   1.251937,
   1.251937};
   Double_t down_fy3[58] = {
   0.4243354,
   0.5478172,
   0.6999484,
   0.8851165,
   1.107743,
   1.372086,
   1.682007,
   2.040696,
   2.450377,
   2.912001,
   3.424949,
   3.986766,
   4.592947,
   5.236801,
   5.909419,
   7.294816,
   7.980041,
   8.639726,
   9.257609,
   9.817518,
   10.30407,
   10.51541,
   10.70335,
   10.86648,
   11.00359,
   11.11363,
   11.19576,
   11.24934,
   11.27396,
   11.26943,
   11.23579,
   11.17329,
   11.08242,
   10.96388,
   10.81857,
   10.64759,
   10.45223,
   9.994293,
   9.457999,
   8.858302,
   8.211183,
   7.532949,
   6.146044,
   5.465967,
   4.811078,
   4.19104,
   3.61331,
   3.083136,
   2.60366,
   2.176105,
   1.800028,
   1.473611,
   1.193962,
   0.9574192,
   0.7598324,
   0.5968119,
   0.4639393,
   0.4639393};
   graph = new TGraph(58,down_fx3,down_fy3);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down3 = new TH1F("Graph_down3","Projection of downf DSCB fit",100,0.4685446,1.323155);
   Graph_down3->SetMinimum(0.3819019);
   Graph_down3->SetMaximum(12.35892);
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
   
   TH1D *frame_30ef60d0__10 = new TH1D("frame_30ef60d0__10","p_T Balance",25,0,2);
   frame_30ef60d0__10->SetBinContent(1,13.08325);
   frame_30ef60d0__10->SetMinimum(-0.6230121);
   frame_30ef60d0__10->SetMaximum(13.08325);
   frame_30ef60d0__10->SetEntries(1);
   frame_30ef60d0__10->SetDirectory(0);
   frame_30ef60d0__10->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30ef60d0__10->SetLineColor(ci);
   frame_30ef60d0__10->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30ef60d0__10->GetXaxis()->SetLabelFont(42);
   frame_30ef60d0__10->GetXaxis()->SetTitleOffset(1);
   frame_30ef60d0__10->GetXaxis()->SetTitleFont(42);
   frame_30ef60d0__10->GetYaxis()->SetTitle("1/Events");
   frame_30ef60d0__10->GetYaxis()->SetLabelFont(42);
   frame_30ef60d0__10->GetYaxis()->SetTitleFont(42);
   frame_30ef60d0__10->GetZaxis()->SetLabelFont(42);
   frame_30ef60d0__10->GetZaxis()->SetTitleOffset(1);
   frame_30ef60d0__10->GetZaxis()->SetTitleFont(42);
   frame_30ef60d0__10->Draw("AXISSAME");
   
   TH1D *norm_d__11 = new TH1D("norm_d__11","",25,0,2);
   norm_d__11->SetBinContent(2,0.1828583);
   norm_d__11->SetBinContent(3,0.2095299);
   norm_d__11->SetBinContent(4,0.3105729);
   norm_d__11->SetBinContent(5,0.2373215);
   norm_d__11->SetBinContent(6,0.9486898);
   norm_d__11->SetBinContent(7,0.784159);
   norm_d__11->SetBinContent(8,1.433575);
   norm_d__11->SetBinContent(9,3.491392);
   norm_d__11->SetBinContent(10,6.351968);
   norm_d__11->SetBinContent(11,10.44215);
   norm_d__11->SetBinContent(12,11.14904);
   norm_d__11->SetBinContent(13,8.385995);
   norm_d__11->SetBinContent(14,5.800105);
   norm_d__11->SetBinContent(15,1.460312);
   norm_d__11->SetBinContent(16,0.400752);
   norm_d__11->SetBinContent(17,0.592962);
   norm_d__11->SetBinContent(18,0.1021515);
   norm_d__11->SetBinContent(20,0.01940302);
   norm_d__11->SetBinContent(21,0.004996761);
   norm_d__11->SetBinContent(22,0.00462255);
   norm_d__11->SetBinContent(26,0.01084467);
   norm_d__11->SetBinError(2,0.1446367);
   norm_d__11->SetBinError(3,0.2095299);
   norm_d__11->SetBinError(4,0.1789923);
   norm_d__11->SetBinError(5,0.1626223);
   norm_d__11->SetBinError(6,0.4287247);
   norm_d__11->SetBinError(7,0.4668619);
   norm_d__11->SetBinError(8,0.4786803);
   norm_d__11->SetBinError(9,0.7808963);
   norm_d__11->SetBinError(10,0.931941);
   norm_d__11->SetBinError(11,1.381971);
   norm_d__11->SetBinError(12,1.311202);
   norm_d__11->SetBinError(13,1.083683);
   norm_d__11->SetBinError(14,1.034961);
   norm_d__11->SetBinError(15,0.4112211);
   norm_d__11->SetBinError(16,0.2001832);
   norm_d__11->SetBinError(17,0.2971654);
   norm_d__11->SetBinError(18,0.07543368);
   norm_d__11->SetBinError(20,0.01276464);
   norm_d__11->SetBinError(21,0.004996761);
   norm_d__11->SetBinError(22,0.00462255);
   norm_d__11->SetBinError(26,0.008644936);
   norm_d__11->SetEntries(617);
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
   entry=leg->AddEntry("frame_x_d2_30ef60d0","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.897475 #pm 0.020417","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.138759 #pm 0.016371","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.999000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_30ef60d0_copy__12 = new TH1D("frame_30ef60d0_copy__12","p_T Balance",25,0,2);
   frame_30ef60d0_copy__12->SetBinContent(1,13.08325);
   frame_30ef60d0_copy__12->SetMinimum(-0.6230121);
   frame_30ef60d0_copy__12->SetMaximum(13.08325);
   frame_30ef60d0_copy__12->SetEntries(1);
   frame_30ef60d0_copy__12->SetDirectory(0);
   frame_30ef60d0_copy__12->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30ef60d0_copy__12->SetLineColor(ci);
   frame_30ef60d0_copy__12->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30ef60d0_copy__12->GetXaxis()->SetLabelFont(42);
   frame_30ef60d0_copy__12->GetXaxis()->SetTitleOffset(1);
   frame_30ef60d0_copy__12->GetXaxis()->SetTitleFont(42);
   frame_30ef60d0_copy__12->GetYaxis()->SetTitle("1/Events");
   frame_30ef60d0_copy__12->GetYaxis()->SetLabelFont(42);
   frame_30ef60d0_copy__12->GetYaxis()->SetTitleFont(42);
   frame_30ef60d0_copy__12->GetZaxis()->SetLabelFont(42);
   frame_30ef60d0_copy__12->GetZaxis()->SetTitleOffset(1);
   frame_30ef60d0_copy__12->GetZaxis()->SetTitleFont(42);
   frame_30ef60d0_copy__12->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-2.78262,2.25,25.04358);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_30eda2c0__13 = new TH1D("frame_30eda2c0__13","p_T Balance",25,0,2);
   frame_30eda2c0__13->SetBinContent(1,24.48706);
   frame_30eda2c0__13->SetMaximum(24.48706);
   frame_30eda2c0__13->SetEntries(1);
   frame_30eda2c0__13->SetDirectory(0);
   frame_30eda2c0__13->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30eda2c0__13->SetLineColor(ci);
   frame_30eda2c0__13->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30eda2c0__13->GetXaxis()->SetLabelFont(42);
   frame_30eda2c0__13->GetXaxis()->SetTitleOffset(1);
   frame_30eda2c0__13->GetXaxis()->SetTitleFont(42);
   frame_30eda2c0__13->GetYaxis()->SetTitle("1/Events");
   frame_30eda2c0__13->GetYaxis()->SetLabelFont(42);
   frame_30eda2c0__13->GetYaxis()->SetTitleFont(42);
   frame_30eda2c0__13->GetZaxis()->SetLabelFont(42);
   frame_30eda2c0__13->GetZaxis()->SetTitleOffset(1);
   frame_30eda2c0__13->GetZaxis()->SetTitleFont(42);
   frame_30eda2c0__13->Draw("FUNC");
   
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
   0,
   0,
   0,
   0,
   1,
   3,
   1,
   0,
   6,
   11,
   18,
   16,
   10,
   3,
   2,
   0,
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
   0,
   0,
   0,
   0,
   0.8272462,
   1.632705,
   0.8272462,
   0,
   2.379931,
   3.265579,
   4.202887,
   3.957801,
   3.108694,
   1.632705,
   1.291815,
   0,
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
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   2.299527,
   2.918186,
   2.299527,
   1.147874,
   3.583642,
   4.416521,
   5.321007,
   5.083066,
   4.26695,
   2.918186,
   2.63786,
   1.147874,
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
   Graph_h_dh_data23004->SetMaximum(25.65311);
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
   
   Double_t observation_fx4[59] = {
   0.6622384,
   0.6735891,
   0.6849398,
   0.6962904,
   0.7076411,
   0.7189917,
   0.7303424,
   0.741693,
   0.7530437,
   0.7643944,
   0.775745,
   0.7870957,
   0.7984463,
   0.809797,
   0.8211476,
   0.843849,
   0.8551996,
   0.8665503,
   0.8779009,
   0.8892516,
   0.9006022,
   0.9062776,
   0.9119529,
   0.9176282,
   0.9233036,
   0.9289789,
   0.9346542,
   0.9403295,
   0.9460049,
   0.9516802,
   0.9573555,
   0.9630309,
   0.9687062,
   0.9743815,
   0.9800568,
   0.9857322,
   0.9914075,
   0.9970828,
   1.002758,
   1.014109,
   1.025459,
   1.03681,
   1.048161,
   1.070862,
   1.082213,
   1.093563,
   1.104914,
   1.116265,
   1.127615,
   1.138966,
   1.150317,
   1.161667,
   1.173018,
   1.184369,
   1.195719,
   1.20707,
   1.218421,
   1.229771,
   1.229771};
   Double_t observation_fy4[59] = {
   0.6156735,
   0.8041527,
   1.039007,
   1.327978,
   1.679017,
   2.099962,
   2.598124,
   3.179804,
   3.849753,
   4.610601,
   5.462283,
   6.401518,
   7.421366,
   8.510925,
   9.655211,
   12.0284,
   13.20898,
   14.34903,
   15.41941,
   16.39099,
   17.23593,
   17.60289,
   17.92901,
   18.21175,
   18.44888,
   18.63852,
   18.77914,
   18.86962,
   18.90922,
   18.89761,
   18.8349,
   18.72159,
   18.5586,
   18.34724,
   18.0892,
   17.78652,
   17.44156,
   17.05701,
   16.6358,
   15.69617,
   14.64995,
   13.52604,
   12.3537,
   9.975303,
   8.819191,
   7.713003,
   6.672834,
   5.710698,
   4.834596,
   4.048771,
   3.354118,
   2.748688,
   2.228254,
   1.786883,
   1.417488,
   1.112333,
   0.8634605,
   0.6645332,
   0.6645332};
   graph = new TGraph(59,observation_fx4,observation_fy4);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation4 = new TH1F("Graph_observation4","Projection of obsf DSCB fit",100,0.6054851,1.286525);
   Graph_observation4->SetMinimum(0.5541062);
   Graph_observation4->SetMaximum(20.73857);
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
   
   TH1D *frame_30eda2c0__14 = new TH1D("frame_30eda2c0__14","p_T Balance",25,0,2);
   frame_30eda2c0__14->SetBinContent(1,24.48706);
   frame_30eda2c0__14->SetMaximum(24.48706);
   frame_30eda2c0__14->SetEntries(1);
   frame_30eda2c0__14->SetDirectory(0);
   frame_30eda2c0__14->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30eda2c0__14->SetLineColor(ci);
   frame_30eda2c0__14->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30eda2c0__14->GetXaxis()->SetLabelFont(42);
   frame_30eda2c0__14->GetXaxis()->SetTitleOffset(1);
   frame_30eda2c0__14->GetXaxis()->SetTitleFont(42);
   frame_30eda2c0__14->GetYaxis()->SetTitle("1/Events");
   frame_30eda2c0__14->GetYaxis()->SetLabelFont(42);
   frame_30eda2c0__14->GetYaxis()->SetTitleFont(42);
   frame_30eda2c0__14->GetZaxis()->SetLabelFont(42);
   frame_30eda2c0__14->GetZaxis()->SetTitleOffset(1);
   frame_30eda2c0__14->GetZaxis()->SetTitleFont(42);
   frame_30eda2c0__14->Draw("AXISSAME");
   
   TH1D *norm_o__15 = new TH1D("norm_o__15","",25,0,2);
   norm_o__15->SetBinContent(6,1);
   norm_o__15->SetBinContent(7,3);
   norm_o__15->SetBinContent(8,1);
   norm_o__15->SetBinContent(10,6);
   norm_o__15->SetBinContent(11,11);
   norm_o__15->SetBinContent(12,18);
   norm_o__15->SetBinContent(13,16);
   norm_o__15->SetBinContent(14,10);
   norm_o__15->SetBinContent(15,3);
   norm_o__15->SetBinContent(16,2);
   norm_o__15->SetBinContent(18,1);
   norm_o__15->SetMinimum(0);
   norm_o__15->SetMaximum(39.6);
   norm_o__15->SetEntries(72);
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
   entry=leg->AddEntry("frame_x_o2_30eda2c0","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.947627 #pm 0.014121","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.108997 #pm 0.011275","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.994000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_30eda2c0_copy__16 = new TH1D("frame_30eda2c0_copy__16","p_T Balance",25,0,2);
   frame_30eda2c0_copy__16->SetBinContent(1,24.48706);
   frame_30eda2c0_copy__16->SetMaximum(24.48706);
   frame_30eda2c0_copy__16->SetEntries(1);
   frame_30eda2c0_copy__16->SetDirectory(0);
   frame_30eda2c0_copy__16->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30eda2c0_copy__16->SetLineColor(ci);
   frame_30eda2c0_copy__16->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30eda2c0_copy__16->GetXaxis()->SetLabelFont(42);
   frame_30eda2c0_copy__16->GetXaxis()->SetTitleOffset(1);
   frame_30eda2c0_copy__16->GetXaxis()->SetTitleFont(42);
   frame_30eda2c0_copy__16->GetYaxis()->SetTitle("1/Events");
   frame_30eda2c0_copy__16->GetYaxis()->SetLabelFont(42);
   frame_30eda2c0_copy__16->GetYaxis()->SetTitleFont(42);
   frame_30eda2c0_copy__16->GetZaxis()->SetLabelFont(42);
   frame_30eda2c0_copy__16->GetZaxis()->SetTitleOffset(1);
   frame_30eda2c0_copy__16->GetZaxis()->SetTitleFont(42);
   frame_30eda2c0_copy__16->Draw("sameaxis");
   
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
