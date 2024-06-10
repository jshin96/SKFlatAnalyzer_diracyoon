void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_2__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 17:00:04 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-6.35585,2.25,73.09228);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_35f41860__17 = new TH1D("frame_35f41860__17","p_T Balance",25,0,2);
   frame_35f41860__17->SetBinContent(1,65.14746);
   frame_35f41860__17->SetMaximum(65.14746);
   frame_35f41860__17->SetEntries(1);
   frame_35f41860__17->SetDirectory(0);
   frame_35f41860__17->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_35f41860__17->SetLineColor(ci);
   frame_35f41860__17->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35f41860__17->GetXaxis()->SetLabelFont(42);
   frame_35f41860__17->GetXaxis()->SetTitleOffset(1);
   frame_35f41860__17->GetXaxis()->SetTitleFont(42);
   frame_35f41860__17->GetYaxis()->SetTitle("1/Events");
   frame_35f41860__17->GetYaxis()->SetLabelFont(42);
   frame_35f41860__17->GetYaxis()->SetTitleFont(42);
   frame_35f41860__17->GetZaxis()->SetLabelFont(42);
   frame_35f41860__17->GetZaxis()->SetTitleOffset(1);
   frame_35f41860__17->GetZaxis()->SetTitleFont(42);
   frame_35f41860__17->Draw("FUNC");
   
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
   0.2801271,
   0.6116095,
   4.33711,
   4.762161,
   6.889532,
   10.83101,
   21.52574,
   30.28334,
   43.17381,
   57.7578,
   53.28741,
   39.83002,
   30.22955,
   15.12614,
   9.075561,
   4.065908,
   0.891183,
   0.6208054,
   0.2421441,
   0.2124625,
   0.05994884,
   0.08955038,
   0,
   0.008200918};
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
   0.1900309,
   0.2669403,
   1.12152,
   1.309727,
   1.550934,
   1.942687,
   2.731076,
   2.974803,
   3.532444,
   4.287407,
   3.909935,
   3.498565,
   2.9652,
   1.938233,
   1.479005,
   0.9956245,
   0.5001547,
   0.3055223,
   0.109859,
   0.1235313,
   0.05888949,
   0.08955037,
   0,
   0.006572582};
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
   0.1900309,
   0.2669403,
   1.12152,
   1.309727,
   1.550934,
   1.942687,
   2.731076,
   2.974803,
   3.532444,
   4.287407,
   3.909935,
   3.498565,
   2.9652,
   1.938233,
   1.479005,
   0.9956245,
   0.5001547,
   0.3055223,
   0.109859,
   0.1235313,
   0.05888949,
   0.08955037,
   0,
   0.006572582};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3005,h_dh_central2_fy3005,h_dh_central2_felx3005,h_dh_central2_fehx3005,h_dh_central2_fely3005,h_dh_central2_fehy3005);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23005 = new TH1F("Graph_h_dh_central23005","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23005->SetMinimum(0);
   Graph_h_dh_central23005->SetMaximum(68.24973);
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
   
   Double_t Central_fx5[58] = {
   0.369907,
   0.3896821,
   0.4094571,
   0.4292321,
   0.4490072,
   0.4687822,
   0.4885572,
   0.5083323,
   0.5281073,
   0.5478823,
   0.5676574,
   0.5874324,
   0.6072074,
   0.6269824,
   0.6467575,
   0.6863075,
   0.7060826,
   0.7258576,
   0.7456326,
   0.7654077,
   0.7851827,
   0.7950702,
   0.8049577,
   0.8148452,
   0.8247328,
   0.8346203,
   0.8445078,
   0.8543953,
   0.8642828,
   0.8741703,
   0.8840578,
   0.8939454,
   0.9038329,
   0.9137204,
   0.9236079,
   0.9334954,
   0.9433829,
   0.963158,
   0.982933,
   1.002708,
   1.022483,
   1.042258,
   1.081808,
   1.101583,
   1.121358,
   1.141133,
   1.160908,
   1.180683,
   1.200458,
   1.220233,
   1.240008,
   1.259783,
   1.279558,
   1.299333,
   1.319109,
   1.338884,
   1.358659,
   1.358659};
   Double_t Central_fy5[58] = {
   2.118143,
   2.723083,
   3.465279,
   4.365029,
   5.442616,
   6.71738,
   8.20661,
   9.924287,
   11.87973,
   14.0762,
   16.50958,
   19.16717,
   22.02683,
   25.05633,
   28.21334,
   34.69316,
   37.8875,
   40.95621,
   43.82432,
   46.41755,
   48.66548,
   49.63977,
   50.50466,
   51.25379,
   51.88162,
   52.38343,
   52.75544,
   52.99482,
   53.09977,
   53.06946,
   52.90414,
   52.60506,
   52.17451,
   51.61573,
   50.93294,
   50.13122,
   49.2165,
   47.07544,
   44.57073,
   41.77118,
   38.75033,
   35.58326,
   29.10056,
   25.91711,
   22.84776,
   19.93757,
   17.22156,
   14.72463,
   12.462,
   10.44006,
   8.657451,
   7.106382,
   5.774027,
   4.643876,
   3.69704,
   2.913395,
   2.272564,
   2.272564};
   TGraph *graph = new TGraph(58,Central_fx5,Central_fy5);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central5 = new TH1F("Graph_Central5","Projection of centralf DSCB fit",100,0.2710319,1.457534);
   Graph_Central5->SetMinimum(1.906329);
   Graph_Central5->SetMaximum(58.19793);
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
   
   TH1D *frame_35f41860__18 = new TH1D("frame_35f41860__18","p_T Balance",25,0,2);
   frame_35f41860__18->SetBinContent(1,65.14746);
   frame_35f41860__18->SetMaximum(65.14746);
   frame_35f41860__18->SetEntries(1);
   frame_35f41860__18->SetDirectory(0);
   frame_35f41860__18->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35f41860__18->SetLineColor(ci);
   frame_35f41860__18->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35f41860__18->GetXaxis()->SetLabelFont(42);
   frame_35f41860__18->GetXaxis()->SetTitleOffset(1);
   frame_35f41860__18->GetXaxis()->SetTitleFont(42);
   frame_35f41860__18->GetYaxis()->SetTitle("1/Events");
   frame_35f41860__18->GetYaxis()->SetLabelFont(42);
   frame_35f41860__18->GetYaxis()->SetTitleFont(42);
   frame_35f41860__18->GetZaxis()->SetLabelFont(42);
   frame_35f41860__18->GetZaxis()->SetTitleOffset(1);
   frame_35f41860__18->GetZaxis()->SetTitleFont(42);
   frame_35f41860__18->Draw("AXISSAME");
   
   TH1D *norm_c__19 = new TH1D("norm_c__19","",25,0,2);
   norm_c__19->SetBinContent(2,0.2801271);
   norm_c__19->SetBinContent(3,0.6116095);
   norm_c__19->SetBinContent(4,4.337109);
   norm_c__19->SetBinContent(5,4.762161);
   norm_c__19->SetBinContent(6,6.889532);
   norm_c__19->SetBinContent(7,10.83101);
   norm_c__19->SetBinContent(8,21.52574);
   norm_c__19->SetBinContent(9,30.28334);
   norm_c__19->SetBinContent(10,43.17381);
   norm_c__19->SetBinContent(11,57.7578);
   norm_c__19->SetBinContent(12,53.28741);
   norm_c__19->SetBinContent(13,39.83003);
   norm_c__19->SetBinContent(14,30.22955);
   norm_c__19->SetBinContent(15,15.12614);
   norm_c__19->SetBinContent(16,9.075561);
   norm_c__19->SetBinContent(17,4.065908);
   norm_c__19->SetBinContent(18,0.891183);
   norm_c__19->SetBinContent(19,0.6208054);
   norm_c__19->SetBinContent(20,0.2421441);
   norm_c__19->SetBinContent(21,0.2124625);
   norm_c__19->SetBinContent(22,0.05994884);
   norm_c__19->SetBinContent(23,0.08955037);
   norm_c__19->SetBinContent(25,0.008200918);
   norm_c__19->SetBinContent(26,0.04981178);
   norm_c__19->SetBinError(2,0.1900309);
   norm_c__19->SetBinError(3,0.2669403);
   norm_c__19->SetBinError(4,1.12152);
   norm_c__19->SetBinError(5,1.309727);
   norm_c__19->SetBinError(6,1.550934);
   norm_c__19->SetBinError(7,1.942687);
   norm_c__19->SetBinError(8,2.731076);
   norm_c__19->SetBinError(9,2.974803);
   norm_c__19->SetBinError(10,3.532444);
   norm_c__19->SetBinError(11,4.287407);
   norm_c__19->SetBinError(12,3.909935);
   norm_c__19->SetBinError(13,3.498565);
   norm_c__19->SetBinError(14,2.9652);
   norm_c__19->SetBinError(15,1.938233);
   norm_c__19->SetBinError(16,1.479005);
   norm_c__19->SetBinError(17,0.9956245);
   norm_c__19->SetBinError(18,0.5001547);
   norm_c__19->SetBinError(19,0.3055223);
   norm_c__19->SetBinError(20,0.109859);
   norm_c__19->SetBinError(21,0.1235313);
   norm_c__19->SetBinError(22,0.05888949);
   norm_c__19->SetBinError(23,0.08955037);
   norm_c__19->SetBinError(25,0.006572582);
   norm_c__19->SetBinError(26,0.02340751);
   norm_c__19->SetEntries(1609);
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
   entry=leg->AddEntry("frame_x_c2_35f41860","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.866996 #pm 0.011401","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.195827 #pm 0.009361","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.948000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_35f41860_copy__20 = new TH1D("frame_35f41860_copy__20","p_T Balance",25,0,2);
   frame_35f41860_copy__20->SetBinContent(1,65.14746);
   frame_35f41860_copy__20->SetMaximum(65.14746);
   frame_35f41860_copy__20->SetEntries(1);
   frame_35f41860_copy__20->SetDirectory(0);
   frame_35f41860_copy__20->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35f41860_copy__20->SetLineColor(ci);
   frame_35f41860_copy__20->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35f41860_copy__20->GetXaxis()->SetLabelFont(42);
   frame_35f41860_copy__20->GetXaxis()->SetTitleOffset(1);
   frame_35f41860_copy__20->GetXaxis()->SetTitleFont(42);
   frame_35f41860_copy__20->GetYaxis()->SetTitle("1/Events");
   frame_35f41860_copy__20->GetYaxis()->SetLabelFont(42);
   frame_35f41860_copy__20->GetYaxis()->SetTitleFont(42);
   frame_35f41860_copy__20->GetZaxis()->SetLabelFont(42);
   frame_35f41860_copy__20->GetZaxis()->SetTitleOffset(1);
   frame_35f41860_copy__20->GetZaxis()->SetTitleFont(42);
   frame_35f41860_copy__20->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-9.412264,2.25,70.84735);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_35f2ed60__21 = new TH1D("frame_35f2ed60__21","p_T Balance",25,0,2);
   frame_35f2ed60__21->SetBinContent(1,62.82139);
   frame_35f2ed60__21->SetMinimum(-2.991495);
   frame_35f2ed60__21->SetMaximum(62.82139);
   frame_35f2ed60__21->SetEntries(1);
   frame_35f2ed60__21->SetDirectory(0);
   frame_35f2ed60__21->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35f2ed60__21->SetLineColor(ci);
   frame_35f2ed60__21->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35f2ed60__21->GetXaxis()->SetLabelFont(42);
   frame_35f2ed60__21->GetXaxis()->SetTitleOffset(1);
   frame_35f2ed60__21->GetXaxis()->SetTitleFont(42);
   frame_35f2ed60__21->GetYaxis()->SetTitle("1/Events");
   frame_35f2ed60__21->GetYaxis()->SetLabelFont(42);
   frame_35f2ed60__21->GetYaxis()->SetTitleFont(42);
   frame_35f2ed60__21->GetZaxis()->SetLabelFont(42);
   frame_35f2ed60__21->GetZaxis()->SetTitleOffset(1);
   frame_35f2ed60__21->GetZaxis()->SetTitleFont(42);
   frame_35f2ed60__21->Draw("FUNC");
   
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
   0.2852161,
   0.822569,
   3.087858,
   5.362821,
   4.700191,
   8.521415,
   20.2884,
   28.5443,
   42.20993,
   54.07393,
   55.77989,
   44.02129,
   33.04168,
   17.23927,
   9.365601,
   4.504175,
   0.4940784,
   0.4369937,
   0.5242503,
   0.1411795,
   0.1721013,
   0,
   0.08910879,
   0.006269748};
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
   0.1939352,
   0.3363886,
   0.9770739,
   1.395729,
   1.220253,
   1.746572,
   2.637114,
   3.008008,
   3.467116,
   4.131198,
   4.050005,
   3.742459,
   3.090932,
   2.203118,
   1.431862,
   1.034515,
   0.2345095,
   0.2407416,
   0.2511955,
   0.1008853,
   0.1002594,
   0,
   0.0891088,
   0.006269748};
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
   0.1939352,
   0.3363886,
   0.9770739,
   1.395729,
   1.220253,
   1.746572,
   2.637114,
   3.008008,
   3.467116,
   4.131198,
   4.050005,
   3.742459,
   3.090932,
   2.203118,
   1.431862,
   1.034515,
   0.2345095,
   0.2407416,
   0.2511955,
   0.1008853,
   0.1002594,
   0,
   0.0891088,
   0.006269748};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3006,h_dh_up2_fy3006,h_dh_up2_felx3006,h_dh_up2_fehx3006,h_dh_up2_fely3006,h_dh_up2_fehy3006);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23006 = new TH1F("Graph_h_dh_up23006","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23006->SetMinimum(-5.98299);
   Graph_h_dh_up23006->SetMaximum(65.81289);
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
   
   Double_t up_fx6[57] = {
   0.4127394,
   0.4503297,
   0.4691249,
   0.4785225,
   0.4832213,
   0.4879201,
   0.5067152,
   0.5255104,
   0.5443056,
   0.5631008,
   0.5818959,
   0.6006911,
   0.6194863,
   0.6382815,
   0.6758718,
   0.7134622,
   0.7322573,
   0.7510525,
   0.7698477,
   0.7886429,
   0.807438,
   0.8168356,
   0.8262332,
   0.8356308,
   0.8450284,
   0.854426,
   0.8638236,
   0.8732212,
   0.8826187,
   0.8920163,
   0.9014139,
   0.9108115,
   0.9202091,
   0.9296067,
   0.9390043,
   0.9484019,
   0.9577994,
   0.9765946,
   0.9953898,
   1.014185,
   1.03298,
   1.051775,
   1.089366,
   1.126956,
   1.145751,
   1.164546,
   1.183342,
   1.202137,
   1.220932,
   1.239727,
   1.258522,
   1.277317,
   1.296113,
   1.314908,
   1.333703,
   1.352498,
   1.352498};
   Double_t up_fy6[57] = {
   5.473724,
   5.656981,
   5.837277,
   6.00708,
   6.155995,
   6.433689,
   7.839277,
   9.460582,
   11.308,
   13.38688,
   15.69636,
   18.22823,
   20.96601,
   23.88433,
   30.11518,
   36.53941,
   39.67239,
   42.662,
   45.43807,
   47.93188,
   50.07893,
   51.00409,
   51.82168,
   52.52601,
   53.11214,
   53.57593,
   53.91406,
   54.12413,
   54.20461,
   54.15493,
   53.97545,
   53.66746,
   53.23316,
   52.67566,
   51.9989,
   51.20765,
   50.30741,
   48.2054,
   45.74939,
   43.00321,
   40.03523,
   36.91558,
   30.49454,
   24.24031,
   21.30272,
   18.54206,
   15.98478,
   13.64839,
   11.54202,
   9.66737,
   8.019748,
   6.589296,
   5.362203,
   4.321886,
   3.450081,
   2.727792,
   2.727792};
   graph = new TGraph(57,up_fx6,up_fy6);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up6 = new TH1F("Graph_up6","Projection of upf DSCB fit",100,0.3187635,1.446474);
   Graph_up6->SetMinimum(2.455013);
   Graph_up6->SetMaximum(59.35229);
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
   
   TH1D *frame_35f2ed60__22 = new TH1D("frame_35f2ed60__22","p_T Balance",25,0,2);
   frame_35f2ed60__22->SetBinContent(1,62.82139);
   frame_35f2ed60__22->SetMinimum(-2.991495);
   frame_35f2ed60__22->SetMaximum(62.82139);
   frame_35f2ed60__22->SetEntries(1);
   frame_35f2ed60__22->SetDirectory(0);
   frame_35f2ed60__22->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35f2ed60__22->SetLineColor(ci);
   frame_35f2ed60__22->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35f2ed60__22->GetXaxis()->SetLabelFont(42);
   frame_35f2ed60__22->GetXaxis()->SetTitleOffset(1);
   frame_35f2ed60__22->GetXaxis()->SetTitleFont(42);
   frame_35f2ed60__22->GetYaxis()->SetTitle("1/Events");
   frame_35f2ed60__22->GetYaxis()->SetLabelFont(42);
   frame_35f2ed60__22->GetYaxis()->SetTitleFont(42);
   frame_35f2ed60__22->GetZaxis()->SetLabelFont(42);
   frame_35f2ed60__22->GetZaxis()->SetTitleOffset(1);
   frame_35f2ed60__22->GetZaxis()->SetTitleFont(42);
   frame_35f2ed60__22->Draw("AXISSAME");
   
   TH1D *norm_u__23 = new TH1D("norm_u__23","",25,0,2);
   norm_u__23->SetBinContent(2,0.2852161);
   norm_u__23->SetBinContent(3,0.822569);
   norm_u__23->SetBinContent(4,3.087859);
   norm_u__23->SetBinContent(5,5.362821);
   norm_u__23->SetBinContent(6,4.700192);
   norm_u__23->SetBinContent(7,8.521415);
   norm_u__23->SetBinContent(8,20.2884);
   norm_u__23->SetBinContent(9,28.5443);
   norm_u__23->SetBinContent(10,42.20993);
   norm_u__23->SetBinContent(11,54.07393);
   norm_u__23->SetBinContent(12,55.77989);
   norm_u__23->SetBinContent(13,44.02129);
   norm_u__23->SetBinContent(14,33.04168);
   norm_u__23->SetBinContent(15,17.23927);
   norm_u__23->SetBinContent(16,9.365601);
   norm_u__23->SetBinContent(17,4.504175);
   norm_u__23->SetBinContent(18,0.4940784);
   norm_u__23->SetBinContent(19,0.4369936);
   norm_u__23->SetBinContent(20,0.5242503);
   norm_u__23->SetBinContent(21,0.1411795);
   norm_u__23->SetBinContent(22,0.1721014);
   norm_u__23->SetBinContent(24,0.0891088);
   norm_u__23->SetBinContent(25,0.006269748);
   norm_u__23->SetBinContent(26,0.05296382);
   norm_u__23->SetBinError(2,0.1939352);
   norm_u__23->SetBinError(3,0.3363886);
   norm_u__23->SetBinError(4,0.9770739);
   norm_u__23->SetBinError(5,1.395729);
   norm_u__23->SetBinError(6,1.220253);
   norm_u__23->SetBinError(7,1.746572);
   norm_u__23->SetBinError(8,2.637114);
   norm_u__23->SetBinError(9,3.008008);
   norm_u__23->SetBinError(10,3.467116);
   norm_u__23->SetBinError(11,4.131198);
   norm_u__23->SetBinError(12,4.050005);
   norm_u__23->SetBinError(13,3.742459);
   norm_u__23->SetBinError(14,3.090932);
   norm_u__23->SetBinError(15,2.203118);
   norm_u__23->SetBinError(16,1.431862);
   norm_u__23->SetBinError(17,1.034515);
   norm_u__23->SetBinError(18,0.2345095);
   norm_u__23->SetBinError(19,0.2407416);
   norm_u__23->SetBinError(20,0.2511955);
   norm_u__23->SetBinError(21,0.1008853);
   norm_u__23->SetBinError(22,0.1002594);
   norm_u__23->SetBinError(24,0.0891088);
   norm_u__23->SetBinError(25,0.006269748);
   norm_u__23->SetBinError(26,0.02411983);
   norm_u__23->SetEntries(1587);
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
   entry=leg->AddEntry("frame_x_u2_35f2ed60","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.879726 #pm 0.011184","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.192170 #pm 0.009042","");
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
   
   TH1D *frame_35f2ed60_copy__24 = new TH1D("frame_35f2ed60_copy__24","p_T Balance",25,0,2);
   frame_35f2ed60_copy__24->SetBinContent(1,62.82139);
   frame_35f2ed60_copy__24->SetMinimum(-2.991495);
   frame_35f2ed60_copy__24->SetMaximum(62.82139);
   frame_35f2ed60_copy__24->SetEntries(1);
   frame_35f2ed60_copy__24->SetDirectory(0);
   frame_35f2ed60_copy__24->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35f2ed60_copy__24->SetLineColor(ci);
   frame_35f2ed60_copy__24->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35f2ed60_copy__24->GetXaxis()->SetLabelFont(42);
   frame_35f2ed60_copy__24->GetXaxis()->SetTitleOffset(1);
   frame_35f2ed60_copy__24->GetXaxis()->SetTitleFont(42);
   frame_35f2ed60_copy__24->GetYaxis()->SetTitle("1/Events");
   frame_35f2ed60_copy__24->GetYaxis()->SetLabelFont(42);
   frame_35f2ed60_copy__24->GetYaxis()->SetTitleFont(42);
   frame_35f2ed60_copy__24->GetZaxis()->SetLabelFont(42);
   frame_35f2ed60_copy__24->GetZaxis()->SetTitleOffset(1);
   frame_35f2ed60_copy__24->GetZaxis()->SetTitleFont(42);
   frame_35f2ed60_copy__24->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-7.228753,2.25,65.05877);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_35f58580__25 = new TH1D("frame_35f58580__25","p_T Balance",25,0,2);
   frame_35f58580__25->SetBinContent(1,63.61302);
   frame_35f58580__25->SetMaximum(63.61302);
   frame_35f58580__25->SetEntries(1);
   frame_35f58580__25->SetDirectory(0);
   frame_35f58580__25->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35f58580__25->SetLineColor(ci);
   frame_35f58580__25->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35f58580__25->GetXaxis()->SetLabelFont(42);
   frame_35f58580__25->GetXaxis()->SetTitleOffset(1);
   frame_35f58580__25->GetXaxis()->SetTitleFont(42);
   frame_35f58580__25->GetYaxis()->SetTitle("1/Events");
   frame_35f58580__25->GetYaxis()->SetLabelFont(42);
   frame_35f58580__25->GetYaxis()->SetTitleFont(42);
   frame_35f58580__25->GetZaxis()->SetLabelFont(42);
   frame_35f58580__25->GetZaxis()->SetTitleOffset(1);
   frame_35f58580__25->GetZaxis()->SetTitleFont(42);
   frame_35f58580__25->Draw("FUNC");
   
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
   0.3595936,
   0.6220945,
   3.885424,
   5.488681,
   5.770103,
   11.01051,
   20.10663,
   32.96944,
   43.55145,
   56.4296,
   48.55304,
   39.96197,
   22.93943,
   15.42655,
   8.107187,
   3.944702,
   1.026423,
   0.589344,
   0.1869424,
   0.1430819,
   0.06042781,
   0.09028142,
   0,
   0.06522293};
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
   0.225796,
   0.2995459,
   1.070842,
   1.362378,
   1.398306,
   1.977096,
   2.620658,
   3.110989,
   3.569189,
   4.154228,
   3.738362,
   3.450728,
   2.469525,
   1.933803,
   1.420661,
   0.9813294,
   0.5509321,
   0.3044233,
   0.09482435,
   0.1022386,
   0.05936235,
   0.09028142,
   0,
   0.05734321};
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
   0.225796,
   0.2995459,
   1.070842,
   1.362378,
   1.398306,
   1.977096,
   2.620658,
   3.110989,
   3.569189,
   4.154228,
   3.738362,
   3.450728,
   2.469525,
   1.933803,
   1.420661,
   0.9813294,
   0.5509321,
   0.3044233,
   0.09482435,
   0.1022386,
   0.05936235,
   0.09028142,
   0,
   0.05734321};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3007,h_dh_down2_fy3007,h_dh_down2_felx3007,h_dh_down2_fehx3007,h_dh_down2_fely3007,h_dh_down2_fehy3007);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23007 = new TH1F("Graph_h_dh_down23007","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23007->SetMinimum(0);
   Graph_h_dh_down23007->SetMaximum(66.64221);
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
   
   Double_t down_fx7[58] = {
   0.3598934,
   0.3995308,
   0.4391683,
   0.458987,
   0.4788057,
   0.488715,
   0.4986244,
   0.5184431,
   0.5382618,
   0.5580806,
   0.5778993,
   0.597718,
   0.6175367,
   0.6373554,
   0.6769929,
   0.6968116,
   0.7166303,
   0.736449,
   0.7562677,
   0.7760865,
   0.7859958,
   0.7959052,
   0.8058145,
   0.8157239,
   0.8256333,
   0.8355426,
   0.845452,
   0.8553613,
   0.8652707,
   0.87518,
   0.8850894,
   0.8949988,
   0.9049081,
   0.9148175,
   0.9247268,
   0.9346362,
   0.9445456,
   0.9544549,
   0.9742736,
   0.9940924,
   1.013911,
   1.03373,
   1.073367,
   1.093186,
   1.113005,
   1.132823,
   1.152642,
   1.172461,
   1.19228,
   1.212098,
   1.231917,
   1.251736,
   1.271554,
   1.291373,
   1.311192,
   1.331011,
   1.350829,
   1.350829};
   Double_t down_fy7[58] = {
   7.157981,
   7.283541,
   7.482027,
   7.648512,
   7.962667,
   8.355622,
   9.185479,
   11.0332,
   13.11637,
   15.43261,
   17.97123,
   20.71234,
   23.62618,
   26.67294,
   32.95828,
   36.07287,
   39.07599,
   41.89404,
   44.45365,
   46.68481,
   47.65704,
   48.52401,
   49.27931,
   49.91727,
   50.43305,
   50.82272,
   51.08329,
   51.21274,
   51.21007,
   51.07531,
   50.8095,
   50.41468,
   49.89389,
   49.25111,
   48.49119,
   47.61984,
   46.64352,
   45.56936,
   43.15894,
   40.45588,
   37.53233,
   34.46215,
   28.16793,
   25.07441,
   22.0912,
   19.26287,
   16.62401,
   14.19918,
   12.00339,
   10.04286,
   8.316185,
   6.815593,
   5.528358,
   4.438147,
   3.526307,
   2.773011,
   2.158221,
   2.158221};
   graph = new TGraph(58,down_fx7,down_fy7);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down7 = new TH1F("Graph_down7","Projection of downf DSCB fit",100,0.2607998,1.449923);
   Graph_down7->SetMinimum(1.942399);
   Graph_down7->SetMaximum(56.11819);
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
   
   TH1D *frame_35f58580__26 = new TH1D("frame_35f58580__26","p_T Balance",25,0,2);
   frame_35f58580__26->SetBinContent(1,63.61302);
   frame_35f58580__26->SetMaximum(63.61302);
   frame_35f58580__26->SetEntries(1);
   frame_35f58580__26->SetDirectory(0);
   frame_35f58580__26->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35f58580__26->SetLineColor(ci);
   frame_35f58580__26->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35f58580__26->GetXaxis()->SetLabelFont(42);
   frame_35f58580__26->GetXaxis()->SetTitleOffset(1);
   frame_35f58580__26->GetXaxis()->SetTitleFont(42);
   frame_35f58580__26->GetYaxis()->SetTitle("1/Events");
   frame_35f58580__26->GetYaxis()->SetLabelFont(42);
   frame_35f58580__26->GetYaxis()->SetTitleFont(42);
   frame_35f58580__26->GetZaxis()->SetLabelFont(42);
   frame_35f58580__26->GetZaxis()->SetTitleOffset(1);
   frame_35f58580__26->GetZaxis()->SetTitleFont(42);
   frame_35f58580__26->Draw("AXISSAME");
   
   TH1D *norm_d__27 = new TH1D("norm_d__27","",25,0,2);
   norm_d__27->SetBinContent(2,0.3595936);
   norm_d__27->SetBinContent(3,0.6220945);
   norm_d__27->SetBinContent(4,3.885424);
   norm_d__27->SetBinContent(5,5.488681);
   norm_d__27->SetBinContent(6,5.770103);
   norm_d__27->SetBinContent(7,11.01051);
   norm_d__27->SetBinContent(8,20.10663);
   norm_d__27->SetBinContent(9,32.96944);
   norm_d__27->SetBinContent(10,43.55145);
   norm_d__27->SetBinContent(11,56.42961);
   norm_d__27->SetBinContent(12,48.55304);
   norm_d__27->SetBinContent(13,39.96197);
   norm_d__27->SetBinContent(14,22.93943);
   norm_d__27->SetBinContent(15,15.42655);
   norm_d__27->SetBinContent(16,8.107187);
   norm_d__27->SetBinContent(17,3.944702);
   norm_d__27->SetBinContent(18,1.026423);
   norm_d__27->SetBinContent(19,0.5893439);
   norm_d__27->SetBinContent(20,0.1869424);
   norm_d__27->SetBinContent(21,0.1430819);
   norm_d__27->SetBinContent(22,0.06042781);
   norm_d__27->SetBinContent(23,0.09028142);
   norm_d__27->SetBinContent(25,0.06522293);
   norm_d__27->SetBinContent(26,0.04407739);
   norm_d__27->SetBinError(2,0.225796);
   norm_d__27->SetBinError(3,0.2995459);
   norm_d__27->SetBinError(4,1.070842);
   norm_d__27->SetBinError(5,1.362378);
   norm_d__27->SetBinError(6,1.398306);
   norm_d__27->SetBinError(7,1.977096);
   norm_d__27->SetBinError(8,2.620658);
   norm_d__27->SetBinError(9,3.110989);
   norm_d__27->SetBinError(10,3.569189);
   norm_d__27->SetBinError(11,4.154228);
   norm_d__27->SetBinError(12,3.738362);
   norm_d__27->SetBinError(13,3.450728);
   norm_d__27->SetBinError(14,2.469525);
   norm_d__27->SetBinError(15,1.933803);
   norm_d__27->SetBinError(16,1.420661);
   norm_d__27->SetBinError(17,0.9813294);
   norm_d__27->SetBinError(18,0.5509321);
   norm_d__27->SetBinError(19,0.3044233);
   norm_d__27->SetBinError(20,0.09482435);
   norm_d__27->SetBinError(21,0.1022386);
   norm_d__27->SetBinError(22,0.05936235);
   norm_d__27->SetBinError(23,0.09028142);
   norm_d__27->SetBinError(25,0.05734321);
   norm_d__27->SetBinError(26,0.02277013);
   norm_d__27->SetEntries(1559);
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
   entry=leg->AddEntry("frame_x_d2_35f58580","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.857722 #pm 0.012445","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.177002 #pm 0.012809","");
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
   
   TH1D *frame_35f58580_copy__28 = new TH1D("frame_35f58580_copy__28","p_T Balance",25,0,2);
   frame_35f58580_copy__28->SetBinContent(1,63.61302);
   frame_35f58580_copy__28->SetMaximum(63.61302);
   frame_35f58580_copy__28->SetEntries(1);
   frame_35f58580_copy__28->SetDirectory(0);
   frame_35f58580_copy__28->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35f58580_copy__28->SetLineColor(ci);
   frame_35f58580_copy__28->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35f58580_copy__28->GetXaxis()->SetLabelFont(42);
   frame_35f58580_copy__28->GetXaxis()->SetTitleOffset(1);
   frame_35f58580_copy__28->GetXaxis()->SetTitleFont(42);
   frame_35f58580_copy__28->GetYaxis()->SetTitle("1/Events");
   frame_35f58580_copy__28->GetYaxis()->SetLabelFont(42);
   frame_35f58580_copy__28->GetYaxis()->SetTitleFont(42);
   frame_35f58580_copy__28->GetZaxis()->SetLabelFont(42);
   frame_35f58580_copy__28->GetZaxis()->SetTitleOffset(1);
   frame_35f58580_copy__28->GetZaxis()->SetTitleFont(42);
   frame_35f58580_copy__28->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-9.221704,2.25,82.99533);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_35f502e0__29 = new TH1D("frame_35f502e0__29","p_T Balance",25,0,2);
   frame_35f502e0__29->SetBinContent(1,81.15099);
   frame_35f502e0__29->SetMaximum(81.15099);
   frame_35f502e0__29->SetEntries(1);
   frame_35f502e0__29->SetDirectory(0);
   frame_35f502e0__29->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35f502e0__29->SetLineColor(ci);
   frame_35f502e0__29->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35f502e0__29->GetXaxis()->SetLabelFont(42);
   frame_35f502e0__29->GetXaxis()->SetTitleOffset(1);
   frame_35f502e0__29->GetXaxis()->SetTitleFont(42);
   frame_35f502e0__29->GetYaxis()->SetTitle("1/Events");
   frame_35f502e0__29->GetYaxis()->SetLabelFont(42);
   frame_35f502e0__29->GetYaxis()->SetTitleFont(42);
   frame_35f502e0__29->GetZaxis()->SetLabelFont(42);
   frame_35f502e0__29->GetZaxis()->SetTitleOffset(1);
   frame_35f502e0__29->GetZaxis()->SetTitleFont(42);
   frame_35f502e0__29->Draw("FUNC");
   
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
   1,
   1,
   3,
   4,
   6,
   15,
   18,
   39,
   55,
   68,
   67,
   37,
   30,
   24,
   11,
   9,
   1,
   0,
   0,
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
   0.8272462,
   0.8272462,
   1.632705,
   1.914339,
   2.379931,
   3.82938,
   4.202887,
   6.218102,
   7.39358,
   8.225883,
   8.164873,
   6.055143,
   5.446522,
   4.864612,
   3.265579,
   2.943461,
   0.8272462,
   0,
   0,
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
   2.299527,
   2.299527,
   2.918186,
   3.162753,
   3.583642,
   4.958738,
   5.321007,
   7.298372,
   8.461166,
   9.28666,
   9.226102,
   7.137555,
   6.538046,
   5.966932,
   4.416521,
   4.110204,
   2.299527,
   1.147874,
   1.147874,
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
   Graph_h_dh_data23008->SetMaximum(85.01533);
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
   
   Double_t observation_fx8[63] = {
   0.356014,
   0.3967859,
   0.4375578,
   0.4783297,
   0.4987156,
   0.5191016,
   0.5394875,
   0.5598735,
   0.5802594,
   0.5904524,
   0.6006454,
   0.6108383,
   0.6210313,
   0.6312243,
   0.6414173,
   0.6516102,
   0.6618032,
   0.6821891,
   0.722961,
   0.743347,
   0.75354,
   0.7637329,
   0.7739259,
   0.7841189,
   0.7943119,
   0.8045048,
   0.8146978,
   0.8248908,
   0.8350837,
   0.8452767,
   0.8554697,
   0.8656627,
   0.8758556,
   0.8860486,
   0.8962416,
   0.9064346,
   0.9166275,
   0.9268205,
   0.9370135,
   0.9472065,
   0.9573994,
   0.9675924,
   0.9879783,
   1.008364,
   1.018557,
   1.02875,
   1.038943,
   1.049136,
   1.059329,
   1.069522,
   1.089908,
   1.110294,
   1.13068,
   1.151066,
   1.171452,
   1.191838,
   1.212224,
   1.23261,
   1.252996,
   1.293768,
   1.334539,
   1.375311,
   1.375311};
   Double_t observation_fy8[63] = {
   5.937116,
   6.956512,
   8.261723,
   9.970243,
   11.02965,
   12.26668,
   13.72328,
   15.45457,
   17.53405,
   18.73425,
   20.06158,
   21.53461,
   23.17545,
   25.01052,
   27.07169,
   29.39761,
   31.92467,
   37.17535,
   47.91403,
   53.03245,
   55.44023,
   57.71263,
   59.82452,
   61.75188,
   63.47221,
   64.96502,
   66.21221,
   67.19844,
   67.91141,
   68.34219,
   68.48533,
   68.33902,
   67.90511,
   67.18908,
   66.19993,
   64.94995,
   63.45454,
   61.73182,
   59.80232,
   57.68854,
   55.41451,
   53.00539,
   47.88514,
   42.54215,
   40.00218,
   37.64898,
   35.4663,
   33.43953,
   31.55549,
   29.80229,
   26.64641,
   23.89742,
   21.49396,
   19.38521,
   17.52883,
   15.88945,
   14.43732,
   13.14735,
   11.99828,
   10.05324,
   8.486839,
   7.213977,
   7.213977};
   graph = new TGraph(63,observation_fx8,observation_fy8);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation8 = new TH1F("Graph_observation8","Projection of obsf DSCB fit",100,0.2540843,1.477241);
   Graph_observation8->SetMinimum(5.343404);
   Graph_observation8->SetMaximum(74.74015);
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
   
   TH1D *frame_35f502e0__30 = new TH1D("frame_35f502e0__30","p_T Balance",25,0,2);
   frame_35f502e0__30->SetBinContent(1,81.15099);
   frame_35f502e0__30->SetMaximum(81.15099);
   frame_35f502e0__30->SetEntries(1);
   frame_35f502e0__30->SetDirectory(0);
   frame_35f502e0__30->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35f502e0__30->SetLineColor(ci);
   frame_35f502e0__30->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35f502e0__30->GetXaxis()->SetLabelFont(42);
   frame_35f502e0__30->GetXaxis()->SetTitleOffset(1);
   frame_35f502e0__30->GetXaxis()->SetTitleFont(42);
   frame_35f502e0__30->GetYaxis()->SetTitle("1/Events");
   frame_35f502e0__30->GetYaxis()->SetLabelFont(42);
   frame_35f502e0__30->GetYaxis()->SetTitleFont(42);
   frame_35f502e0__30->GetZaxis()->SetLabelFont(42);
   frame_35f502e0__30->GetZaxis()->SetTitleOffset(1);
   frame_35f502e0__30->GetZaxis()->SetTitleFont(42);
   frame_35f502e0__30->Draw("AXISSAME");
   
   TH1D *norm_o__31 = new TH1D("norm_o__31","",25,0,2);
   norm_o__31->SetBinContent(2,1);
   norm_o__31->SetBinContent(3,1);
   norm_o__31->SetBinContent(4,3);
   norm_o__31->SetBinContent(5,4);
   norm_o__31->SetBinContent(6,6);
   norm_o__31->SetBinContent(7,15);
   norm_o__31->SetBinContent(8,18);
   norm_o__31->SetBinContent(9,39);
   norm_o__31->SetBinContent(10,55);
   norm_o__31->SetBinContent(11,68);
   norm_o__31->SetBinContent(12,67);
   norm_o__31->SetBinContent(13,37);
   norm_o__31->SetBinContent(14,30);
   norm_o__31->SetBinContent(15,24);
   norm_o__31->SetBinContent(16,11);
   norm_o__31->SetBinContent(17,9);
   norm_o__31->SetBinContent(18,1);
   norm_o__31->SetBinContent(21,1);
   norm_o__31->SetMinimum(0);
   norm_o__31->SetMaximum(149.6);
   norm_o__31->SetEntries(390);
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
   entry=leg->AddEntry("frame_x_o2_35f502e0","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.849677 #pm 0.013113","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.173832 #pm 0.011928","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.999000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_35f502e0_copy__32 = new TH1D("frame_35f502e0_copy__32","p_T Balance",25,0,2);
   frame_35f502e0_copy__32->SetBinContent(1,81.15099);
   frame_35f502e0_copy__32->SetMaximum(81.15099);
   frame_35f502e0_copy__32->SetEntries(1);
   frame_35f502e0_copy__32->SetDirectory(0);
   frame_35f502e0_copy__32->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35f502e0_copy__32->SetLineColor(ci);
   frame_35f502e0_copy__32->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35f502e0_copy__32->GetXaxis()->SetLabelFont(42);
   frame_35f502e0_copy__32->GetXaxis()->SetTitleOffset(1);
   frame_35f502e0_copy__32->GetXaxis()->SetTitleFont(42);
   frame_35f502e0_copy__32->GetYaxis()->SetTitle("1/Events");
   frame_35f502e0_copy__32->GetYaxis()->SetLabelFont(42);
   frame_35f502e0_copy__32->GetYaxis()->SetTitleFont(42);
   frame_35f502e0_copy__32->GetZaxis()->SetLabelFont(42);
   frame_35f502e0_copy__32->GetZaxis()->SetTitleOffset(1);
   frame_35f502e0_copy__32->GetZaxis()->SetTitleFont(42);
   frame_35f502e0_copy__32->Draw("sameaxis");
   
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
