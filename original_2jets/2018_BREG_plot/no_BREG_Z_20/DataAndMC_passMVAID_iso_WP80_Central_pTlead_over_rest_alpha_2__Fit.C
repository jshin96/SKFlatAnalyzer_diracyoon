void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_2__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 19:10:01 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-27.64544,2.25,208.0909);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3560ff70__17 = new TH1D("frame_3560ff70__17","p_T Balance",25,0,2);
   frame_3560ff70__17->SetBinContent(1,184.5172);
   frame_3560ff70__17->SetMinimum(-8.786535);
   frame_3560ff70__17->SetMaximum(184.5172);
   frame_3560ff70__17->SetEntries(1);
   frame_3560ff70__17->SetDirectory(0);
   frame_3560ff70__17->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_3560ff70__17->SetLineColor(ci);
   frame_3560ff70__17->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3560ff70__17->GetXaxis()->SetLabelFont(42);
   frame_3560ff70__17->GetXaxis()->SetTitleOffset(1);
   frame_3560ff70__17->GetXaxis()->SetTitleFont(42);
   frame_3560ff70__17->GetYaxis()->SetTitle("1/Events");
   frame_3560ff70__17->GetYaxis()->SetLabelFont(42);
   frame_3560ff70__17->GetYaxis()->SetTitleFont(42);
   frame_3560ff70__17->GetZaxis()->SetLabelFont(42);
   frame_3560ff70__17->GetZaxis()->SetTitleOffset(1);
   frame_3560ff70__17->GetZaxis()->SetTitleFont(42);
   frame_3560ff70__17->Draw("FUNC");
   
   Double_t h_dh_central2_fx3005[25] = {
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
   Double_t h_dh_central2_fy3005[25] = {
   0,
   1.217213,
   5.887394,
   9.241297,
   10.08583,
   14.33952,
   35.78846,
   55.31818,
   87.2378,
   125.912,
   146.4003,
   168.5349,
   123.5071,
   88.21878,
   49.28189,
   22.77924,
   13.09173,
   3.665472,
   2.733061,
   1.261726,
   0.5890622,
   0.2491598,
   0.2261633,
   0.1168146,
   0.001304937};
   Double_t h_dh_central2_felx3005[25] = {
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
   Double_t h_dh_central2_fely3005[25] = {
   0,
   0.405861,
   1.318201,
   1.791487,
   1.750357,
   2.096509,
   3.350704,
   4.277113,
   5.390616,
   6.215895,
   6.643332,
   7.195766,
   5.925767,
   4.907023,
   3.534906,
   2.307003,
   1.748536,
   0.7569863,
   0.6281002,
   0.6012452,
   0.2889978,
   0.1830465,
   0.1559852,
   0.06658183,
   0.001304937};
   Double_t h_dh_central2_fehx3005[25] = {
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
   Double_t h_dh_central2_fehy3005[25] = {
   0,
   0.405861,
   1.318201,
   1.791487,
   1.750357,
   2.096509,
   3.350704,
   4.277113,
   5.390616,
   6.215895,
   6.643332,
   7.195766,
   5.925767,
   4.907023,
   3.534906,
   2.307003,
   1.748536,
   0.7569863,
   0.6281002,
   0.6012452,
   0.2889978,
   0.1830465,
   0.1559852,
   0.06658183,
   0.001304937};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3005,h_dh_central2_fy3005,h_dh_central2_felx3005,h_dh_central2_fehx3005,h_dh_central2_fely3005,h_dh_central2_fehy3005);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23005 = new TH1F("Graph_h_dh_central23005","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23005->SetMinimum(-17.57307);
   Graph_h_dh_central23005->SetMaximum(193.3038);
   Graph_h_dh_central23005->SetDirectory(0);
   Graph_h_dh_central23005->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_central23005->SetLineColor(ci);
   Graph_h_dh_central23005->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_central23005->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_central23005->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_central23005->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_central23005->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_central23005->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_central23005->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_central23005->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_central23005);
   
   grae->Draw("p");
   
   Double_t Central_fx5[52] = {
   0.4388061,
   0.4567264,
   0.4746467,
   0.492567,
   0.5104873,
   0.5284076,
   0.546328,
   0.5642483,
   0.5821686,
   0.6000889,
   0.6180092,
   0.6538498,
   0.6896904,
   0.7076107,
   0.725531,
   0.7434513,
   0.7613716,
   0.7792919,
   0.7972122,
   0.8151325,
   0.8330528,
   0.8420129,
   0.8509731,
   0.8599332,
   0.8688934,
   0.8778535,
   0.8868137,
   0.8957738,
   0.904734,
   0.9226543,
   0.9405746,
   0.9584949,
   0.9764152,
   0.9943355,
   1.012256,
   1.030176,
   1.048096,
   1.083937,
   1.119778,
   1.137698,
   1.155618,
   1.173539,
   1.191459,
   1.209379,
   1.227299,
   1.24522,
   1.26314,
   1.28106,
   1.298981,
   1.316901,
   1.334821,
   1.334821};
   Double_t Central_fy5[52] = {
   15.5557,
   18.70564,
   22.31844,
   26.42186,
   31.03641,
   36.17327,
   41.83237,
   48.00048,
   54.6496,
   61.73576,
   69.19823,
   84.92516,
   101.0209,
   108.8958,
   116.4715,
   123.6051,
   130.1552,
   135.9862,
   140.9733,
   145.0063,
   147.9945,
   149.0744,
   149.8692,
   150.3744,
   150.5871,
   150.5059,
   150.1313,
   149.4656,
   148.5126,
   145.7685,
   141.9621,
   137.1796,
   131.5271,
   125.1264,
   118.1112,
   110.6221,
   102.8018,
   86.72488,
   70.91207,
   63.37543,
   56.19919,
   49.44787,
   43.16914,
   37.39449,
   32.14032,
   27.40951,
   23.19319,
   19.47279,
   16.222,
   13.40876,
   10.99718,
   10.99718};
   TGraph *graph = new TGraph(52,Central_fx5,Central_fy5);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central5 = new TH1F("Graph_Central5","Projection of centralf DSCB fit",100,0.3492046,1.424423);
   Graph_Central5->SetMinimum(9.897466);
   Graph_Central5->SetMaximum(164.5461);
   Graph_Central5->SetDirectory(0);
   Graph_Central5->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Central5->SetLineColor(ci);
   Graph_Central5->GetXaxis()->SetLabelFont(42);
   Graph_Central5->GetXaxis()->SetTitleOffset(1);
   Graph_Central5->GetXaxis()->SetTitleFont(42);
   Graph_Central5->GetYaxis()->SetLabelFont(42);
   Graph_Central5->GetYaxis()->SetTitleFont(42);
   Graph_Central5->GetZaxis()->SetLabelFont(42);
   Graph_Central5->GetZaxis()->SetTitleOffset(1);
   Graph_Central5->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Central5);
   
   graph->Draw("l");
   
   TH1D *frame_3560ff70__18 = new TH1D("frame_3560ff70__18","p_T Balance",25,0,2);
   frame_3560ff70__18->SetBinContent(1,184.5172);
   frame_3560ff70__18->SetMinimum(-8.786535);
   frame_3560ff70__18->SetMaximum(184.5172);
   frame_3560ff70__18->SetEntries(1);
   frame_3560ff70__18->SetDirectory(0);
   frame_3560ff70__18->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3560ff70__18->SetLineColor(ci);
   frame_3560ff70__18->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3560ff70__18->GetXaxis()->SetLabelFont(42);
   frame_3560ff70__18->GetXaxis()->SetTitleOffset(1);
   frame_3560ff70__18->GetXaxis()->SetTitleFont(42);
   frame_3560ff70__18->GetYaxis()->SetTitle("1/Events");
   frame_3560ff70__18->GetYaxis()->SetLabelFont(42);
   frame_3560ff70__18->GetYaxis()->SetTitleFont(42);
   frame_3560ff70__18->GetZaxis()->SetLabelFont(42);
   frame_3560ff70__18->GetZaxis()->SetTitleOffset(1);
   frame_3560ff70__18->GetZaxis()->SetTitleFont(42);
   frame_3560ff70__18->Draw("AXISSAME");
   
   TH1D *norm_c__19 = new TH1D("norm_c__19","",25,0,2);
   norm_c__19->SetBinContent(2,1.217213);
   norm_c__19->SetBinContent(3,5.887394);
   norm_c__19->SetBinContent(4,9.241297);
   norm_c__19->SetBinContent(5,10.08583);
   norm_c__19->SetBinContent(6,14.33952);
   norm_c__19->SetBinContent(7,35.78845);
   norm_c__19->SetBinContent(8,55.31817);
   norm_c__19->SetBinContent(9,87.2378);
   norm_c__19->SetBinContent(10,125.912);
   norm_c__19->SetBinContent(11,146.4003);
   norm_c__19->SetBinContent(12,168.5349);
   norm_c__19->SetBinContent(13,123.5071);
   norm_c__19->SetBinContent(14,88.21878);
   norm_c__19->SetBinContent(15,49.28189);
   norm_c__19->SetBinContent(16,22.77924);
   norm_c__19->SetBinContent(17,13.09173);
   norm_c__19->SetBinContent(18,3.665472);
   norm_c__19->SetBinContent(19,2.733061);
   norm_c__19->SetBinContent(20,1.261726);
   norm_c__19->SetBinContent(21,0.5890622);
   norm_c__19->SetBinContent(22,0.2491598);
   norm_c__19->SetBinContent(23,0.2261633);
   norm_c__19->SetBinContent(24,0.1168146);
   norm_c__19->SetBinContent(25,0.001304937);
   norm_c__19->SetBinContent(26,0.5967358);
   norm_c__19->SetBinError(2,0.405861);
   norm_c__19->SetBinError(3,1.318201);
   norm_c__19->SetBinError(4,1.791487);
   norm_c__19->SetBinError(5,1.750357);
   norm_c__19->SetBinError(6,2.096509);
   norm_c__19->SetBinError(7,3.350704);
   norm_c__19->SetBinError(8,4.277113);
   norm_c__19->SetBinError(9,5.390616);
   norm_c__19->SetBinError(10,6.215895);
   norm_c__19->SetBinError(11,6.643332);
   norm_c__19->SetBinError(12,7.195766);
   norm_c__19->SetBinError(13,5.925767);
   norm_c__19->SetBinError(14,4.907023);
   norm_c__19->SetBinError(15,3.534906);
   norm_c__19->SetBinError(16,2.307003);
   norm_c__19->SetBinError(17,1.748536);
   norm_c__19->SetBinError(18,0.7569863);
   norm_c__19->SetBinError(19,0.6281002);
   norm_c__19->SetBinError(20,0.6012452);
   norm_c__19->SetBinError(21,0.2889978);
   norm_c__19->SetBinError(22,0.1830465);
   norm_c__19->SetBinError(23,0.1559852);
   norm_c__19->SetBinError(24,0.06658183);
   norm_c__19->SetBinError(25,0.001304937);
   norm_c__19->SetBinError(26,0.1740176);
   norm_c__19->SetEntries(5074);
   norm_c__19->SetStats(0);

   ci = 1319;
   color = new TColor(ci, 0.3, 0.3, 0.3, " ", 0.6);
   norm_c__19->SetFillColor(ci);
   norm_c__19->SetFillStyle(3144);
   norm_c__19->SetLineColor(2);
   norm_c__19->SetLineWidth(2);
   norm_c__19->GetXaxis()->SetRange(1,25);
   norm_c__19->GetXaxis()->SetLabelFont(42);
   norm_c__19->GetXaxis()->SetLabelSize(0.04);
   norm_c__19->GetXaxis()->SetTitleOffset(1);
   norm_c__19->GetXaxis()->SetTitleFont(42);
   norm_c__19->GetYaxis()->SetLabelFont(42);
   norm_c__19->GetYaxis()->SetTitleFont(42);
   norm_c__19->GetZaxis()->SetLabelFont(42);
   norm_c__19->GetZaxis()->SetTitleOffset(1);
   norm_c__19->GetZaxis()->SetTitleFont(42);
   norm_c__19->Draw("e1 same");
   
   TLegend *leg = new TLegend(0.65,0.5,0.93,0.87,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.03);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("norm_c","Central","lpf");

   ci = 1319;
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
   entry=leg->AddEntry("frame_x_c2_3560ff70","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.883041 #pm 0.007911","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.183270 #pm 0.007516","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.648000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3560ff70_copy__20 = new TH1D("frame_3560ff70_copy__20","p_T Balance",25,0,2);
   frame_3560ff70_copy__20->SetBinContent(1,184.5172);
   frame_3560ff70_copy__20->SetMinimum(-8.786535);
   frame_3560ff70_copy__20->SetMaximum(184.5172);
   frame_3560ff70_copy__20->SetEntries(1);
   frame_3560ff70_copy__20->SetDirectory(0);
   frame_3560ff70_copy__20->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3560ff70_copy__20->SetLineColor(ci);
   frame_3560ff70_copy__20->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3560ff70_copy__20->GetXaxis()->SetLabelFont(42);
   frame_3560ff70_copy__20->GetXaxis()->SetTitleOffset(1);
   frame_3560ff70_copy__20->GetXaxis()->SetTitleFont(42);
   frame_3560ff70_copy__20->GetYaxis()->SetTitle("1/Events");
   frame_3560ff70_copy__20->GetYaxis()->SetLabelFont(42);
   frame_3560ff70_copy__20->GetYaxis()->SetTitleFont(42);
   frame_3560ff70_copy__20->GetZaxis()->SetLabelFont(42);
   frame_3560ff70_copy__20->GetZaxis()->SetTitleOffset(1);
   frame_3560ff70_copy__20->GetZaxis()->SetTitleFont(42);
   frame_3560ff70_copy__20->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-17.43943,2.25,200.5534);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_355fe120__21 = new TH1D("frame_355fe120__21","p_T Balance",25,0,2);
   frame_355fe120__21->SetBinContent(1,178.7541);
   frame_355fe120__21->SetMaximum(178.7541);
   frame_355fe120__21->SetEntries(1);
   frame_355fe120__21->SetDirectory(0);
   frame_355fe120__21->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_355fe120__21->SetLineColor(ci);
   frame_355fe120__21->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_355fe120__21->GetXaxis()->SetLabelFont(42);
   frame_355fe120__21->GetXaxis()->SetTitleOffset(1);
   frame_355fe120__21->GetXaxis()->SetTitleFont(42);
   frame_355fe120__21->GetYaxis()->SetTitle("1/Events");
   frame_355fe120__21->GetYaxis()->SetLabelFont(42);
   frame_355fe120__21->GetYaxis()->SetTitleFont(42);
   frame_355fe120__21->GetZaxis()->SetLabelFont(42);
   frame_355fe120__21->GetZaxis()->SetTitleOffset(1);
   frame_355fe120__21->GetZaxis()->SetTitleFont(42);
   frame_355fe120__21->Draw("FUNC");
   
   Double_t h_dh_up2_fx3006[25] = {
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
   Double_t h_dh_up2_fy3006[25] = {
   0,
   1.162671,
   7.269999,
   8.564756,
   7.628928,
   14.50317,
   33.48042,
   55.52073,
   82.57123,
   116.1702,
   152.1991,
   163.2631,
   140.6416,
   92.15078,
   56.32328,
   24.50538,
   15.74754,
   3.642902,
   2.649453,
   1.517478,
   0.7559038,
   0.4679131,
   0.09702577,
   0.1557507,
   0.04529044};
   Double_t h_dh_up2_felx3006[25] = {
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
   Double_t h_dh_up2_fely3006[25] = {
   0,
   0.3960466,
   1.557425,
   1.576341,
   1.4515,
   2.096532,
   3.353148,
   4.346195,
   5.283139,
   5.937592,
   6.854293,
   6.978882,
   6.491198,
   4.988228,
   3.864681,
   2.266847,
   2.010129,
   0.7605544,
   0.6950076,
   0.7190718,
   0.3356215,
   0.2649348,
   0.0696645,
   0.07740272,
   0.04401659};
   Double_t h_dh_up2_fehx3006[25] = {
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
   Double_t h_dh_up2_fehy3006[25] = {
   0,
   0.3960466,
   1.557425,
   1.576341,
   1.4515,
   2.096532,
   3.353148,
   4.346195,
   5.283139,
   5.937592,
   6.854293,
   6.978882,
   6.491198,
   4.988228,
   3.864681,
   2.266847,
   2.010129,
   0.7605544,
   0.6950076,
   0.7190718,
   0.3356215,
   0.2649348,
   0.0696645,
   0.07740272,
   0.04401659};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3006,h_dh_up2_fy3006,h_dh_up2_felx3006,h_dh_up2_fehx3006,h_dh_up2_fely3006,h_dh_up2_fehy3006);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23006 = new TH1F("Graph_h_dh_up23006","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23006->SetMinimum(0);
   Graph_h_dh_up23006->SetMaximum(187.2662);
   Graph_h_dh_up23006->SetDirectory(0);
   Graph_h_dh_up23006->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_up23006->SetLineColor(ci);
   Graph_h_dh_up23006->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_up23006->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_up23006->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_up23006->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_up23006->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_up23006->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_up23006->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_up23006->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_up23006);
   
   grae->Draw("p");
   
   Double_t up_fx6[58] = {
   0.3827882,
   0.4026927,
   0.4225973,
   0.4425019,
   0.4624064,
   0.482311,
   0.5022156,
   0.5221201,
   0.5420247,
   0.5619293,
   0.5818338,
   0.6017384,
   0.621643,
   0.6415475,
   0.6614521,
   0.7012612,
   0.7211658,
   0.7410704,
   0.7609749,
   0.7808795,
   0.8007841,
   0.8107363,
   0.8206886,
   0.8306409,
   0.8405932,
   0.8505455,
   0.8604978,
   0.87045,
   0.8804023,
   0.8903546,
   0.9003069,
   0.9102592,
   0.9202115,
   0.9301637,
   0.940116,
   0.9500683,
   0.9600206,
   0.9799252,
   0.9998297,
   1.019734,
   1.039639,
   1.059543,
   1.099353,
   1.119257,
   1.139162,
   1.159066,
   1.178971,
   1.198875,
   1.21878,
   1.238685,
   1.258589,
   1.278494,
   1.298398,
   1.318303,
   1.338207,
   1.358112,
   1.378016,
   1.378016};
   Double_t up_fy6[58] = {
   5.930486,
   7.653337,
   9.774994,
   12.35627,
   15.45836,
   19.14011,
   23.45475,
   28.44607,
   34.14435,
   40.56212,
   47.69003,
   55.49319,
   63.90825,
   72.84158,
   82.16879,
   101.3626,
   110.8461,
   119.9689,
   128.5056,
   136.2325,
   142.9369,
   145.8447,
   148.4271,
   150.6649,
   152.5412,
   154.0418,
   155.1552,
   155.8728,
   156.1891,
   156.1016,
   155.611,
   154.721,
   153.4387,
   151.7737,
   149.7389,
   147.3496,
   144.6237,
   138.2451,
   130.7871,
   122.4575,
   113.4778,
   104.0739,
   84.86307,
   75.45099,
   66.39209,
   57.81931,
   49.83501,
   42.51101,
   35.89,
   29.98822,
   24.79893,
   20.29647,
   16.44043,
   13.17986,
   10.45716,
   8.211492,
   6.381685,
   6.381685};
   graph = new TGraph(58,up_fx6,up_fy6);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up6 = new TH1F("Graph_up6","Projection of upf DSCB fit",100,0.2832653,1.477539);
   Graph_up6->SetMinimum(5.337438);
   Graph_up6->SetMaximum(171.215);
   Graph_up6->SetDirectory(0);
   Graph_up6->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_up6->SetLineColor(ci);
   Graph_up6->GetXaxis()->SetLabelFont(42);
   Graph_up6->GetXaxis()->SetTitleOffset(1);
   Graph_up6->GetXaxis()->SetTitleFont(42);
   Graph_up6->GetYaxis()->SetLabelFont(42);
   Graph_up6->GetYaxis()->SetTitleFont(42);
   Graph_up6->GetZaxis()->SetLabelFont(42);
   Graph_up6->GetZaxis()->SetTitleOffset(1);
   Graph_up6->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_up6);
   
   graph->Draw("l");
   
   TH1D *frame_355fe120__22 = new TH1D("frame_355fe120__22","p_T Balance",25,0,2);
   frame_355fe120__22->SetBinContent(1,178.7541);
   frame_355fe120__22->SetMaximum(178.7541);
   frame_355fe120__22->SetEntries(1);
   frame_355fe120__22->SetDirectory(0);
   frame_355fe120__22->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_355fe120__22->SetLineColor(ci);
   frame_355fe120__22->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_355fe120__22->GetXaxis()->SetLabelFont(42);
   frame_355fe120__22->GetXaxis()->SetTitleOffset(1);
   frame_355fe120__22->GetXaxis()->SetTitleFont(42);
   frame_355fe120__22->GetYaxis()->SetTitle("1/Events");
   frame_355fe120__22->GetYaxis()->SetLabelFont(42);
   frame_355fe120__22->GetYaxis()->SetTitleFont(42);
   frame_355fe120__22->GetZaxis()->SetLabelFont(42);
   frame_355fe120__22->GetZaxis()->SetTitleOffset(1);
   frame_355fe120__22->GetZaxis()->SetTitleFont(42);
   frame_355fe120__22->Draw("AXISSAME");
   
   TH1D *norm_u__23 = new TH1D("norm_u__23","",25,0,2);
   norm_u__23->SetBinContent(2,1.162671);
   norm_u__23->SetBinContent(3,7.269999);
   norm_u__23->SetBinContent(4,8.564756);
   norm_u__23->SetBinContent(5,7.628928);
   norm_u__23->SetBinContent(6,14.50317);
   norm_u__23->SetBinContent(7,33.48042);
   norm_u__23->SetBinContent(8,55.52072);
   norm_u__23->SetBinContent(9,82.57123);
   norm_u__23->SetBinContent(10,116.1702);
   norm_u__23->SetBinContent(11,152.1991);
   norm_u__23->SetBinContent(12,163.2631);
   norm_u__23->SetBinContent(13,140.6416);
   norm_u__23->SetBinContent(14,92.15078);
   norm_u__23->SetBinContent(15,56.32328);
   norm_u__23->SetBinContent(16,24.50538);
   norm_u__23->SetBinContent(17,15.74754);
   norm_u__23->SetBinContent(18,3.642902);
   norm_u__23->SetBinContent(19,2.649453);
   norm_u__23->SetBinContent(20,1.517478);
   norm_u__23->SetBinContent(21,0.7559038);
   norm_u__23->SetBinContent(22,0.4679131);
   norm_u__23->SetBinContent(23,0.09702577);
   norm_u__23->SetBinContent(24,0.1557507);
   norm_u__23->SetBinContent(25,0.04529044);
   norm_u__23->SetBinContent(26,0.6894876);
   norm_u__23->SetBinError(2,0.3960466);
   norm_u__23->SetBinError(3,1.557425);
   norm_u__23->SetBinError(4,1.576341);
   norm_u__23->SetBinError(5,1.4515);
   norm_u__23->SetBinError(6,2.096532);
   norm_u__23->SetBinError(7,3.353148);
   norm_u__23->SetBinError(8,4.346195);
   norm_u__23->SetBinError(9,5.283139);
   norm_u__23->SetBinError(10,5.937592);
   norm_u__23->SetBinError(11,6.854293);
   norm_u__23->SetBinError(12,6.978882);
   norm_u__23->SetBinError(13,6.491198);
   norm_u__23->SetBinError(14,4.988228);
   norm_u__23->SetBinError(15,3.864681);
   norm_u__23->SetBinError(16,2.266847);
   norm_u__23->SetBinError(17,2.010129);
   norm_u__23->SetBinError(18,0.7605544);
   norm_u__23->SetBinError(19,0.6950076);
   norm_u__23->SetBinError(20,0.7190718);
   norm_u__23->SetBinError(21,0.3356215);
   norm_u__23->SetBinError(22,0.2649348);
   norm_u__23->SetBinError(23,0.0696645);
   norm_u__23->SetBinError(24,0.07740272);
   norm_u__23->SetBinError(25,0.04401659);
   norm_u__23->SetBinError(26,0.2050671);
   norm_u__23->SetEntries(5075);
   norm_u__23->SetStats(0);
   norm_u__23->SetLineColor(4);
   norm_u__23->SetLineWidth(2);
   norm_u__23->GetXaxis()->SetLabelFont(42);
   norm_u__23->GetXaxis()->SetTitleOffset(1);
   norm_u__23->GetXaxis()->SetTitleFont(42);
   norm_u__23->GetYaxis()->SetLabelFont(42);
   norm_u__23->GetYaxis()->SetTitleFont(42);
   norm_u__23->GetZaxis()->SetLabelFont(42);
   norm_u__23->GetZaxis()->SetTitleOffset(1);
   norm_u__23->GetZaxis()->SetTitleFont(42);
   norm_u__23->Draw("e1 same");
   
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
   entry=leg->AddEntry("frame_x_u2_355fe120","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.883219 #pm 0.006631","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.195653 #pm 0.005400","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.812000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_355fe120_copy__24 = new TH1D("frame_355fe120_copy__24","p_T Balance",25,0,2);
   frame_355fe120_copy__24->SetBinContent(1,178.7541);
   frame_355fe120_copy__24->SetMaximum(178.7541);
   frame_355fe120_copy__24->SetEntries(1);
   frame_355fe120_copy__24->SetDirectory(0);
   frame_355fe120_copy__24->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_355fe120_copy__24->SetLineColor(ci);
   frame_355fe120_copy__24->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_355fe120_copy__24->GetXaxis()->SetLabelFont(42);
   frame_355fe120_copy__24->GetXaxis()->SetTitleOffset(1);
   frame_355fe120_copy__24->GetXaxis()->SetTitleFont(42);
   frame_355fe120_copy__24->GetYaxis()->SetTitle("1/Events");
   frame_355fe120_copy__24->GetYaxis()->SetLabelFont(42);
   frame_355fe120_copy__24->GetYaxis()->SetTitleFont(42);
   frame_355fe120_copy__24->GetZaxis()->SetLabelFont(42);
   frame_355fe120_copy__24->GetZaxis()->SetTitleOffset(1);
   frame_355fe120_copy__24->GetZaxis()->SetTitleFont(42);
   frame_355fe120_copy__24->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-19.85932,2.25,178.7339);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_35610dc0__25 = new TH1D("frame_35610dc0__25","p_T Balance",25,0,2);
   frame_35610dc0__25->SetBinContent(1,174.762);
   frame_35610dc0__25->SetMaximum(174.762);
   frame_35610dc0__25->SetEntries(1);
   frame_35610dc0__25->SetDirectory(0);
   frame_35610dc0__25->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35610dc0__25->SetLineColor(ci);
   frame_35610dc0__25->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35610dc0__25->GetXaxis()->SetLabelFont(42);
   frame_35610dc0__25->GetXaxis()->SetTitleOffset(1);
   frame_35610dc0__25->GetXaxis()->SetTitleFont(42);
   frame_35610dc0__25->GetYaxis()->SetTitle("1/Events");
   frame_35610dc0__25->GetYaxis()->SetLabelFont(42);
   frame_35610dc0__25->GetYaxis()->SetTitleFont(42);
   frame_35610dc0__25->GetZaxis()->SetLabelFont(42);
   frame_35610dc0__25->GetZaxis()->SetTitleOffset(1);
   frame_35610dc0__25->GetZaxis()->SetTitleFont(42);
   frame_35610dc0__25->Draw("FUNC");
   
   Double_t h_dh_down2_fx3007[25] = {
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
   Double_t h_dh_down2_fy3007[25] = {
   0,
   1.341936,
   6.484713,
   9.95751,
   10.02179,
   16.18478,
   35.26773,
   62.17359,
   92.7608,
   138.6619,
   150.2083,
   159.5449,
   118.7909,
   82.56593,
   40.0181,
   18.50228,
   10.48657,
   3.323709,
   2.198903,
   1.07652,
   0.6714994,
   0.4750365,
   0.00851015,
   0.07877941,
   0.1710577};
   Double_t h_dh_down2_felx3007[25] = {
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
   Double_t h_dh_down2_fely3007[25] = {
   0,
   0.4231304,
   1.312005,
   1.858367,
   1.672655,
   2.070238,
   3.281402,
   4.501103,
   5.477243,
   6.550588,
   6.731204,
   6.895147,
   5.79066,
   4.822129,
   3.017527,
   1.966637,
   1.460046,
   0.6828586,
   0.5547988,
   0.4158943,
   0.3311115,
   0.2428655,
   0.006173032,
   0.05056975,
   0.08748679};
   Double_t h_dh_down2_fehx3007[25] = {
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
   Double_t h_dh_down2_fehy3007[25] = {
   0,
   0.4231304,
   1.312005,
   1.858367,
   1.672655,
   2.070238,
   3.281402,
   4.501103,
   5.477243,
   6.550588,
   6.731204,
   6.895147,
   5.79066,
   4.822129,
   3.017527,
   1.966637,
   1.460046,
   0.6828586,
   0.5547988,
   0.4158943,
   0.3311115,
   0.2428655,
   0.006173032,
   0.05056975,
   0.08748679};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3007,h_dh_down2_fy3007,h_dh_down2_felx3007,h_dh_down2_fehx3007,h_dh_down2_fely3007,h_dh_down2_fehy3007);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23007 = new TH1F("Graph_h_dh_down23007","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23007->SetMinimum(0);
   Graph_h_dh_down23007->SetMaximum(183.084);
   Graph_h_dh_down23007->SetDirectory(0);
   Graph_h_dh_down23007->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_down23007->SetLineColor(ci);
   Graph_h_dh_down23007->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_down23007->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_down23007->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_down23007->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_down23007->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_down23007->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_down23007->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_down23007->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_down23007);
   
   grae->Draw("p");
   
   Double_t down_fx7[60] = {
   0.4001849,
   0.4376103,
   0.456323,
   0.4750357,
   0.4937484,
   0.5124611,
   0.5311738,
   0.5498865,
   0.5592428,
   0.5685992,
   0.5873118,
   0.6060245,
   0.6247372,
   0.6434499,
   0.6621626,
   0.699588,
   0.7183007,
   0.7370134,
   0.7557261,
   0.7744388,
   0.7837951,
   0.7931515,
   0.8025078,
   0.8118641,
   0.8212205,
   0.8305768,
   0.8399332,
   0.8492895,
   0.8586459,
   0.8680022,
   0.8773586,
   0.8867149,
   0.8960713,
   0.9054276,
   0.914784,
   0.9241403,
   0.9334966,
   0.942853,
   0.9615657,
   0.9802784,
   0.9989911,
   1.017704,
   1.036416,
   1.073842,
   1.092555,
   1.111267,
   1.12998,
   1.148693,
   1.167405,
   1.186118,
   1.204831,
   1.223543,
   1.242256,
   1.260969,
   1.265647,
   1.270325,
   1.279681,
   1.298394,
   1.33582,
   1.33582};
   Double_t down_fy7[60] = {
   14.32806,
   18.07608,
   20.41033,
   23.13382,
   26.32712,
   30.09093,
   34.55204,
   39.87137,
   42.9151,
   46.2549,
   53.82306,
   62.08693,
   70.89881,
   80.14654,
   89.68867,
   108.9593,
   118.2873,
   127.1215,
   135.2406,
   142.4301,
   145.6136,
   148.4923,
   151.0454,
   153.2544,
   155.1029,
   156.5773,
   157.6665,
   158.3623,
   158.6594,
   158.5557,
   158.0518,
   157.1516,
   155.8619,
   154.1924,
   152.1555,
   149.7663,
   147.0422,
   144.0032,
   137.0683,
   129.1544,
   120.4726,
   111.2435,
   101.6875,
   82.42806,
   73.09527,
   64.16682,
   55.76205,
   47.97047,
   40.85228,
   34.44019,
   28.74233,
   23.74571,
   19.42028,
   15.72291,
   14.89093,
   14.35954,
   13.85904,
   13.38153,
   12.9231,
   12.9231};
   graph = new TGraph(60,down_fx7,down_fy7);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down7 = new TH1F("Graph_down7","Projection of downf DSCB fit",100,0.3066215,1.429383);
   Graph_down7->SetMinimum(11.63079);
   Graph_down7->SetMaximum(173.2331);
   Graph_down7->SetDirectory(0);
   Graph_down7->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_down7->SetLineColor(ci);
   Graph_down7->GetXaxis()->SetLabelFont(42);
   Graph_down7->GetXaxis()->SetTitleOffset(1);
   Graph_down7->GetXaxis()->SetTitleFont(42);
   Graph_down7->GetYaxis()->SetLabelFont(42);
   Graph_down7->GetYaxis()->SetTitleFont(42);
   Graph_down7->GetZaxis()->SetLabelFont(42);
   Graph_down7->GetZaxis()->SetTitleOffset(1);
   Graph_down7->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_down7);
   
   graph->Draw("l");
   
   TH1D *frame_35610dc0__26 = new TH1D("frame_35610dc0__26","p_T Balance",25,0,2);
   frame_35610dc0__26->SetBinContent(1,174.762);
   frame_35610dc0__26->SetMaximum(174.762);
   frame_35610dc0__26->SetEntries(1);
   frame_35610dc0__26->SetDirectory(0);
   frame_35610dc0__26->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35610dc0__26->SetLineColor(ci);
   frame_35610dc0__26->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35610dc0__26->GetXaxis()->SetLabelFont(42);
   frame_35610dc0__26->GetXaxis()->SetTitleOffset(1);
   frame_35610dc0__26->GetXaxis()->SetTitleFont(42);
   frame_35610dc0__26->GetYaxis()->SetTitle("1/Events");
   frame_35610dc0__26->GetYaxis()->SetLabelFont(42);
   frame_35610dc0__26->GetYaxis()->SetTitleFont(42);
   frame_35610dc0__26->GetZaxis()->SetLabelFont(42);
   frame_35610dc0__26->GetZaxis()->SetTitleOffset(1);
   frame_35610dc0__26->GetZaxis()->SetTitleFont(42);
   frame_35610dc0__26->Draw("AXISSAME");
   
   TH1D *norm_d__27 = new TH1D("norm_d__27","",25,0,2);
   norm_d__27->SetBinContent(2,1.341936);
   norm_d__27->SetBinContent(3,6.484713);
   norm_d__27->SetBinContent(4,9.95751);
   norm_d__27->SetBinContent(5,10.02179);
   norm_d__27->SetBinContent(6,16.18478);
   norm_d__27->SetBinContent(7,35.26773);
   norm_d__27->SetBinContent(8,62.17359);
   norm_d__27->SetBinContent(9,92.76081);
   norm_d__27->SetBinContent(10,138.6619);
   norm_d__27->SetBinContent(11,150.2083);
   norm_d__27->SetBinContent(12,159.5449);
   norm_d__27->SetBinContent(13,118.7909);
   norm_d__27->SetBinContent(14,82.56593);
   norm_d__27->SetBinContent(15,40.0181);
   norm_d__27->SetBinContent(16,18.50228);
   norm_d__27->SetBinContent(17,10.48657);
   norm_d__27->SetBinContent(18,3.323709);
   norm_d__27->SetBinContent(19,2.198903);
   norm_d__27->SetBinContent(20,1.07652);
   norm_d__27->SetBinContent(21,0.6714994);
   norm_d__27->SetBinContent(22,0.4750365);
   norm_d__27->SetBinContent(23,0.00851015);
   norm_d__27->SetBinContent(24,0.0787794);
   norm_d__27->SetBinContent(25,0.1710577);
   norm_d__27->SetBinContent(26,0.4938478);
   norm_d__27->SetBinError(2,0.4231304);
   norm_d__27->SetBinError(3,1.312005);
   norm_d__27->SetBinError(4,1.858367);
   norm_d__27->SetBinError(5,1.672655);
   norm_d__27->SetBinError(6,2.070238);
   norm_d__27->SetBinError(7,3.281402);
   norm_d__27->SetBinError(8,4.501103);
   norm_d__27->SetBinError(9,5.477243);
   norm_d__27->SetBinError(10,6.550588);
   norm_d__27->SetBinError(11,6.731204);
   norm_d__27->SetBinError(12,6.895147);
   norm_d__27->SetBinError(13,5.79066);
   norm_d__27->SetBinError(14,4.822129);
   norm_d__27->SetBinError(15,3.017527);
   norm_d__27->SetBinError(16,1.966637);
   norm_d__27->SetBinError(17,1.460046);
   norm_d__27->SetBinError(18,0.6828586);
   norm_d__27->SetBinError(19,0.5547988);
   norm_d__27->SetBinError(20,0.4158943);
   norm_d__27->SetBinError(21,0.3311115);
   norm_d__27->SetBinError(22,0.2428655);
   norm_d__27->SetBinError(23,0.006173032);
   norm_d__27->SetBinError(24,0.05056975);
   norm_d__27->SetBinError(25,0.08748679);
   norm_d__27->SetBinError(26,0.1282724);
   norm_d__27->SetEntries(5167);
   norm_d__27->SetStats(0);
   norm_d__27->SetLineColor(7);
   norm_d__27->SetLineWidth(2);
   norm_d__27->GetXaxis()->SetLabelFont(42);
   norm_d__27->GetXaxis()->SetTitleOffset(1);
   norm_d__27->GetXaxis()->SetTitleFont(42);
   norm_d__27->GetYaxis()->SetLabelFont(42);
   norm_d__27->GetYaxis()->SetTitleFont(42);
   norm_d__27->GetZaxis()->SetLabelFont(42);
   norm_d__27->GetZaxis()->SetTitleOffset(1);
   norm_d__27->GetZaxis()->SetTitleFont(42);
   norm_d__27->Draw("same e1");
   
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
   entry=leg->AddEntry("frame_x_d2_35610dc0","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.858726 #pm 0.006728","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.193534 #pm 0.005675","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.984000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_35610dc0_copy__28 = new TH1D("frame_35610dc0_copy__28","p_T Balance",25,0,2);
   frame_35610dc0_copy__28->SetBinContent(1,174.762);
   frame_35610dc0_copy__28->SetMaximum(174.762);
   frame_35610dc0_copy__28->SetEntries(1);
   frame_35610dc0_copy__28->SetDirectory(0);
   frame_35610dc0_copy__28->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35610dc0_copy__28->SetLineColor(ci);
   frame_35610dc0_copy__28->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35610dc0_copy__28->GetXaxis()->SetLabelFont(42);
   frame_35610dc0_copy__28->GetXaxis()->SetTitleOffset(1);
   frame_35610dc0_copy__28->GetXaxis()->SetTitleFont(42);
   frame_35610dc0_copy__28->GetYaxis()->SetTitle("1/Events");
   frame_35610dc0_copy__28->GetYaxis()->SetLabelFont(42);
   frame_35610dc0_copy__28->GetYaxis()->SetTitleFont(42);
   frame_35610dc0_copy__28->GetZaxis()->SetLabelFont(42);
   frame_35610dc0_copy__28->GetZaxis()->SetTitleOffset(1);
   frame_35610dc0_copy__28->GetZaxis()->SetTitleFont(42);
   frame_35610dc0_copy__28->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-24.0049,2.25,216.0441);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_356001c0__29 = new TH1D("frame_356001c0__29","p_T Balance",25,0,2);
   frame_356001c0__29->SetBinContent(1,211.2431);
   frame_356001c0__29->SetMaximum(211.2431);
   frame_356001c0__29->SetEntries(1);
   frame_356001c0__29->SetDirectory(0);
   frame_356001c0__29->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_356001c0__29->SetLineColor(ci);
   frame_356001c0__29->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_356001c0__29->GetXaxis()->SetLabelFont(42);
   frame_356001c0__29->GetXaxis()->SetTitleOffset(1);
   frame_356001c0__29->GetXaxis()->SetTitleFont(42);
   frame_356001c0__29->GetYaxis()->SetTitle("1/Events");
   frame_356001c0__29->GetYaxis()->SetLabelFont(42);
   frame_356001c0__29->GetYaxis()->SetTitleFont(42);
   frame_356001c0__29->GetZaxis()->SetLabelFont(42);
   frame_356001c0__29->GetZaxis()->SetTitleOffset(1);
   frame_356001c0__29->GetZaxis()->SetTitleFont(42);
   frame_356001c0__29->Draw("FUNC");
   
   Double_t h_dh_data2_fx3008[25] = {
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
   Double_t h_dh_data2_fy3008[25] = {
   0,
   2,
   14,
   12,
   13,
   30,
   48,
   75,
   131,
   171,
   187,
   164,
   166,
   110,
   66,
   27,
   14,
   1,
   4,
   2,
   1,
   0,
   0,
   0,
   0};
   Double_t h_dh_data2_felx3008[25] = {
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
   Double_t h_dh_data2_fely3008[25] = {
   0,
   1.291815,
   3.6965,
   3.415266,
   3.558662,
   5.446522,
   6.903979,
   8.640903,
   10.95644,
   12.58625,
   13.18393,
   12.31601,
   12.3938,
   10,
   8.103403,
   5.163771,
   3.6965,
   0.8272462,
   1.914339,
   1.291815,
   0.8272462,
   0,
   0,
   0,
   0};
   Double_t h_dh_data2_fehx3008[25] = {
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
   Double_t h_dh_data2_fehy3008[25] = {
   1.147874,
   2.63786,
   4.830381,
   4.559819,
   4.697573,
   6.538046,
   7.97633,
   9.698771,
   11.95644,
   13.58625,
   14.18393,
   13.31601,
   13.3938,
   11,
   9.165094,
   6.260244,
   4.830381,
   2.299527,
   3.162753,
   2.63786,
   2.299527,
   1.147874,
   1.147874,
   1.147874,
   1.147874};
   grae = new TGraphAsymmErrors(25,h_dh_data2_fx3008,h_dh_data2_fy3008,h_dh_data2_felx3008,h_dh_data2_fehx3008,h_dh_data2_fely3008,h_dh_data2_fehy3008);
   grae->SetName("h_dh_data2");
   grae->SetTitle("Histogram of dh_data2_plot__x_o2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_data23008 = new TH1F("Graph_h_dh_data23008","Histogram of dh_data2_plot__x_o2",100,0,2.2);
   Graph_h_dh_data23008->SetMinimum(0);
   Graph_h_dh_data23008->SetMaximum(221.3023);
   Graph_h_dh_data23008->SetDirectory(0);
   Graph_h_dh_data23008->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_data23008->SetLineColor(ci);
   Graph_h_dh_data23008->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_data23008->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_data23008->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_data23008->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_data23008->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_data23008->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_data23008->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_data23008->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_data23008);
   
   grae->Draw("p");
   
   Double_t observation_fx8[57] = {
   0.3489092,
   0.3894604,
   0.4300116,
   0.4502872,
   0.4705628,
   0.4908384,
   0.511114,
   0.5313896,
   0.5516652,
   0.561803,
   0.5719408,
   0.5922164,
   0.612492,
   0.6327676,
   0.6733188,
   0.71387,
   0.7341456,
   0.7544212,
   0.7746968,
   0.7848346,
   0.7949724,
   0.8051102,
   0.815248,
   0.8253858,
   0.8355236,
   0.8456614,
   0.8557992,
   0.865937,
   0.8760748,
   0.8862126,
   0.8963505,
   0.9064883,
   0.9166261,
   0.9267639,
   0.9369017,
   0.9470395,
   0.9571773,
   0.9774529,
   0.9977285,
   1.018004,
   1.03828,
   1.078831,
   1.099106,
   1.119382,
   1.139658,
   1.159933,
   1.180209,
   1.200484,
   1.22076,
   1.241036,
   1.261311,
   1.281587,
   1.301862,
   1.322138,
   1.342414,
   1.362689,
   1.362689};
   Double_t observation_fy8[57] = {
   20.58607,
   24.17666,
   28.84641,
   31.7298,
   35.08827,
   39.03472,
   43.71822,
   49.33896,
   56.17113,
   60.15582,
   64.59866,
   74.67937,
   85.49374,
   96.85583,
   120.4708,
   143.7041,
   154.5074,
   164.3945,
   173.0944,
   176.9202,
   180.3584,
   183.3833,
   185.972,
   188.1048,
   189.7652,
   190.9403,
   191.6211,
   191.8021,
   191.4819,
   190.6631,
   189.352,
   187.5589,
   185.2976,
   182.5856,
   179.4434,
   175.8948,
   171.9662,
   163.0858,
   153.0549,
   142.1464,
   130.6419,
   106.9421,
   95.25071,
   83.95483,
   73.22863,
   63.20827,
   53.9914,
   45.63868,
   38.17678,
   31.60263,
   25.88838,
   20.98671,
   16.8361,
   13.36585,
   10.50048,
   8.163563,
   8.163563};
   graph = new TGraph(57,observation_fx8,observation_fy8);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation8 = new TH1F("Graph_observation8","Projection of obsf DSCB fit",100,0.2475312,1.464067);
   Graph_observation8->SetMinimum(7.347207);
   Graph_observation8->SetMaximum(210.1659);
   Graph_observation8->SetDirectory(0);
   Graph_observation8->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_observation8->SetLineColor(ci);
   Graph_observation8->GetXaxis()->SetLabelFont(42);
   Graph_observation8->GetXaxis()->SetTitleOffset(1);
   Graph_observation8->GetXaxis()->SetTitleFont(42);
   Graph_observation8->GetYaxis()->SetLabelFont(42);
   Graph_observation8->GetYaxis()->SetTitleFont(42);
   Graph_observation8->GetZaxis()->SetLabelFont(42);
   Graph_observation8->GetZaxis()->SetTitleOffset(1);
   Graph_observation8->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_observation8);
   
   graph->Draw("l");
   
   TH1D *frame_356001c0__30 = new TH1D("frame_356001c0__30","p_T Balance",25,0,2);
   frame_356001c0__30->SetBinContent(1,211.2431);
   frame_356001c0__30->SetMaximum(211.2431);
   frame_356001c0__30->SetEntries(1);
   frame_356001c0__30->SetDirectory(0);
   frame_356001c0__30->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_356001c0__30->SetLineColor(ci);
   frame_356001c0__30->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_356001c0__30->GetXaxis()->SetLabelFont(42);
   frame_356001c0__30->GetXaxis()->SetTitleOffset(1);
   frame_356001c0__30->GetXaxis()->SetTitleFont(42);
   frame_356001c0__30->GetYaxis()->SetTitle("1/Events");
   frame_356001c0__30->GetYaxis()->SetLabelFont(42);
   frame_356001c0__30->GetYaxis()->SetTitleFont(42);
   frame_356001c0__30->GetZaxis()->SetLabelFont(42);
   frame_356001c0__30->GetZaxis()->SetTitleOffset(1);
   frame_356001c0__30->GetZaxis()->SetTitleFont(42);
   frame_356001c0__30->Draw("AXISSAME");
   
   TH1D *norm_o__31 = new TH1D("norm_o__31","",25,0,2);
   norm_o__31->SetBinContent(2,2);
   norm_o__31->SetBinContent(3,14);
   norm_o__31->SetBinContent(4,12);
   norm_o__31->SetBinContent(5,13);
   norm_o__31->SetBinContent(6,30);
   norm_o__31->SetBinContent(7,48);
   norm_o__31->SetBinContent(8,75);
   norm_o__31->SetBinContent(9,131);
   norm_o__31->SetBinContent(10,171);
   norm_o__31->SetBinContent(11,187);
   norm_o__31->SetBinContent(12,164);
   norm_o__31->SetBinContent(13,166);
   norm_o__31->SetBinContent(14,110);
   norm_o__31->SetBinContent(15,66);
   norm_o__31->SetBinContent(16,27);
   norm_o__31->SetBinContent(17,14);
   norm_o__31->SetBinContent(18,1);
   norm_o__31->SetBinContent(19,4);
   norm_o__31->SetBinContent(20,2);
   norm_o__31->SetBinContent(21,1);
   norm_o__31->SetMinimum(0);
   norm_o__31->SetMaximum(411.4);
   norm_o__31->SetEntries(1238);
   norm_o__31->SetStats(0);
   norm_o__31->SetLineWidth(2);
   norm_o__31->SetMarkerStyle(8);
   norm_o__31->SetMarkerSize(0.4);
   norm_o__31->GetXaxis()->SetRange(1,25);
   norm_o__31->GetXaxis()->SetLabelFont(42);
   norm_o__31->GetXaxis()->SetLabelSize(0.04);
   norm_o__31->GetXaxis()->SetTitleOffset(1);
   norm_o__31->GetXaxis()->SetTitleFont(42);
   norm_o__31->GetYaxis()->SetTitle("Events");
   norm_o__31->GetYaxis()->SetLabelFont(42);
   norm_o__31->GetYaxis()->SetTitleOffset(1.4);
   norm_o__31->GetYaxis()->SetTitleFont(42);
   norm_o__31->GetZaxis()->SetLabelFont(42);
   norm_o__31->GetZaxis()->SetTitleOffset(1);
   norm_o__31->GetZaxis()->SetTitleFont(42);
   norm_o__31->Draw("same e1");
   
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
   entry=leg->AddEntry("frame_x_o2_356001c0","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.864528 #pm 0.006381","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.198258 #pm 0.005703","");
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
   
   TH1D *frame_356001c0_copy__32 = new TH1D("frame_356001c0_copy__32","p_T Balance",25,0,2);
   frame_356001c0_copy__32->SetBinContent(1,211.2431);
   frame_356001c0_copy__32->SetMaximum(211.2431);
   frame_356001c0_copy__32->SetEntries(1);
   frame_356001c0_copy__32->SetDirectory(0);
   frame_356001c0_copy__32->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_356001c0_copy__32->SetLineColor(ci);
   frame_356001c0_copy__32->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_356001c0_copy__32->GetXaxis()->SetLabelFont(42);
   frame_356001c0_copy__32->GetXaxis()->SetTitleOffset(1);
   frame_356001c0_copy__32->GetXaxis()->SetTitleFont(42);
   frame_356001c0_copy__32->GetYaxis()->SetTitle("1/Events");
   frame_356001c0_copy__32->GetYaxis()->SetLabelFont(42);
   frame_356001c0_copy__32->GetYaxis()->SetTitleFont(42);
   frame_356001c0_copy__32->GetZaxis()->SetLabelFont(42);
   frame_356001c0_copy__32->GetZaxis()->SetTitleOffset(1);
   frame_356001c0_copy__32->GetZaxis()->SetTitleFont(42);
   frame_356001c0_copy__32->Draw("sameaxis");
   
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
