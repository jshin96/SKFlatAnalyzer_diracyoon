void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_5__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 17:56:55 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-17.03584,2.25,195.9122);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_46eaba50__65 = new TH1D("frame_46eaba50__65","p_T Balance",25,0,2);
   frame_46eaba50__65->SetBinContent(1,174.6174);
   frame_46eaba50__65->SetMaximum(174.6174);
   frame_46eaba50__65->SetEntries(2);
   frame_46eaba50__65->SetDirectory(0);
   frame_46eaba50__65->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_46eaba50__65->SetLineColor(ci);
   frame_46eaba50__65->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46eaba50__65->GetXaxis()->SetLabelFont(42);
   frame_46eaba50__65->GetXaxis()->SetTitleOffset(1);
   frame_46eaba50__65->GetXaxis()->SetTitleFont(42);
   frame_46eaba50__65->GetYaxis()->SetTitle("1/Events");
   frame_46eaba50__65->GetYaxis()->SetLabelFont(42);
   frame_46eaba50__65->GetYaxis()->SetTitleFont(42);
   frame_46eaba50__65->GetZaxis()->SetLabelFont(42);
   frame_46eaba50__65->GetZaxis()->SetTitleOffset(1);
   frame_46eaba50__65->GetZaxis()->SetTitleFont(42);
   frame_46eaba50__65->Draw("FUNC");
   
   Double_t h_dh_central2_fx3017[25] = {
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
   Double_t h_dh_central2_fy3017[25] = {
   0,
   0,
   0.6447912,
   9.766522,
   30.46083,
   52.46674,
   94.18993,
   117.9211,
   152.7868,
   154.9136,
   143.9734,
   134.3157,
   119.4395,
   95.29388,
   70.72541,
   49.85095,
   24.18981,
   17.43342,
   10.84999,
   5.833586,
   2.860298,
   1.287653,
   1.1177,
   0.9221553,
   0.3080333};
   Double_t h_dh_central2_felx3017[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_central2_fely3017[25] = {
   0,
   0,
   0.6029965,
   1.863253,
   3.750904,
   4.86747,
   6.925392,
   7.651587,
   9.137174,
   9.048708,
   9.224098,
   9.083051,
   8.110607,
   7.10974,
   6.278061,
   4.857336,
   3.241474,
   2.699984,
   2.17288,
   1.436852,
   0.6623212,
   0.5854358,
   0.4424928,
   0.4969942,
   0.1487392};
   Double_t h_dh_central2_fehx3017[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_central2_fehy3017[25] = {
   0,
   0,
   0.6029965,
   1.863253,
   3.750904,
   4.86747,
   6.925392,
   7.651587,
   9.137174,
   9.048708,
   9.224098,
   9.083051,
   8.110607,
   7.10974,
   6.278061,
   4.857336,
   3.241474,
   2.699984,
   2.17288,
   1.436852,
   0.6623212,
   0.5854358,
   0.4424928,
   0.4969942,
   0.1487392};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3017,h_dh_central2_fy3017,h_dh_central2_felx3017,h_dh_central2_fehx3017,h_dh_central2_fely3017,h_dh_central2_fehy3017);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23017 = new TH1F("Graph_h_dh_central23017","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23017->SetMinimum(0);
   Graph_h_dh_central23017->SetMaximum(180.3585);
   Graph_h_dh_central23017->SetDirectory(0);
   Graph_h_dh_central23017->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_central23017->SetLineColor(ci);
   Graph_h_dh_central23017->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_central23017->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_central23017->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_central23017->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_central23017->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_central23017->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_central23017->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_central23017->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_central23017);
   
   grae->Draw("p");
   
   Double_t Central_fx17[58] = {
   0.09820447,
   0.154317,
   0.1823733,
   0.2104296,
   0.2384858,
   0.2665421,
   0.2945984,
   0.3226547,
   0.3507109,
   0.3787672,
   0.4068235,
   0.4348798,
   0.462936,
   0.4909923,
   0.5190486,
   0.5471048,
   0.6032174,
   0.6312737,
   0.6593299,
   0.6873862,
   0.7014143,
   0.7154425,
   0.7294706,
   0.7434988,
   0.7575269,
   0.771555,
   0.7855832,
   0.7996113,
   0.8136394,
   0.8276676,
   0.8416957,
   0.8557238,
   0.869752,
   0.8837801,
   0.8978083,
   0.9118364,
   0.9258645,
   0.9398927,
   0.9679489,
   0.9960052,
   1.052118,
   1.080174,
   1.10823,
   1.122258,
   1.136287,
   1.150315,
   1.164343,
   1.192399,
   1.220455,
   1.248512,
   1.276568,
   1.304624,
   1.33268,
   1.360737,
   1.388793,
   1.444906,
   1.501018,
   1.501018};
   Double_t Central_fy17[58] = {
   1.851749,
   3.650121,
   5.021829,
   6.813563,
   9.116838,
   12.03017,
   15.65515,
   20.09093,
   25.42733,
   31.7365,
   39.06384,
   47.41858,
   56.76489,
   67.01449,
   78.02168,
   89.58175,
   113.2664,
   124.7321,
   135.4606,
   145.0794,
   149.3606,
   153.2343,
   156.6625,
   159.6114,
   162.051,
   163.9568,
   165.3089,
   166.0935,
   166.3023,
   165.9332,
   164.9901,
   163.4827,
   161.4267,
   158.843,
   155.758,
   152.2025,
   148.2119,
   143.8247,
   134.0302,
   123.1769,
   99.78288,
   87.95405,
   76.4563,
   71.08279,
   66.17317,
   61.6802,
   57.56217,
   50.30737,
   44.16034,
   38.92417,
   34.44157,
   30.58607,
   27.25529,
   24.36581,
   21.84929,
   17.71959,
   14.52109,
   14.52109};
   TGraph *graph = new TGraph(58,Central_fx17,Central_fy17);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central17 = new TH1F("Graph_Central17","Projection of centralf DSCB fit",100,0,1.641299);
   Graph_Central17->SetMinimum(1.666574);
   Graph_Central17->SetMaximum(182.7473);
   Graph_Central17->SetDirectory(0);
   Graph_Central17->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Central17->SetLineColor(ci);
   Graph_Central17->GetXaxis()->SetLabelFont(42);
   Graph_Central17->GetXaxis()->SetTitleOffset(1);
   Graph_Central17->GetXaxis()->SetTitleFont(42);
   Graph_Central17->GetYaxis()->SetLabelFont(42);
   Graph_Central17->GetYaxis()->SetTitleFont(42);
   Graph_Central17->GetZaxis()->SetLabelFont(42);
   Graph_Central17->GetZaxis()->SetTitleOffset(1);
   Graph_Central17->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Central17);
   
   graph->Draw("l");
   
   TH1D *frame_46eaba50__66 = new TH1D("frame_46eaba50__66","p_T Balance",25,0,2);
   frame_46eaba50__66->SetBinContent(1,174.6174);
   frame_46eaba50__66->SetMaximum(174.6174);
   frame_46eaba50__66->SetEntries(2);
   frame_46eaba50__66->SetDirectory(0);
   frame_46eaba50__66->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46eaba50__66->SetLineColor(ci);
   frame_46eaba50__66->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46eaba50__66->GetXaxis()->SetLabelFont(42);
   frame_46eaba50__66->GetXaxis()->SetTitleOffset(1);
   frame_46eaba50__66->GetXaxis()->SetTitleFont(42);
   frame_46eaba50__66->GetYaxis()->SetTitle("1/Events");
   frame_46eaba50__66->GetYaxis()->SetLabelFont(42);
   frame_46eaba50__66->GetYaxis()->SetTitleFont(42);
   frame_46eaba50__66->GetZaxis()->SetLabelFont(42);
   frame_46eaba50__66->GetZaxis()->SetTitleOffset(1);
   frame_46eaba50__66->GetZaxis()->SetTitleFont(42);
   frame_46eaba50__66->Draw("AXISSAME");
   
   TH1D *norm_c__67 = new TH1D("norm_c__67","",25,0,2);
   norm_c__67->SetBinContent(3,0.6447912);
   norm_c__67->SetBinContent(4,9.766522);
   norm_c__67->SetBinContent(5,30.46083);
   norm_c__67->SetBinContent(6,52.46674);
   norm_c__67->SetBinContent(7,94.18993);
   norm_c__67->SetBinContent(8,117.9211);
   norm_c__67->SetBinContent(9,152.7868);
   norm_c__67->SetBinContent(10,154.9136);
   norm_c__67->SetBinContent(11,143.9734);
   norm_c__67->SetBinContent(12,134.3157);
   norm_c__67->SetBinContent(13,119.4395);
   norm_c__67->SetBinContent(14,95.29388);
   norm_c__67->SetBinContent(15,70.72541);
   norm_c__67->SetBinContent(16,49.85095);
   norm_c__67->SetBinContent(17,24.18981);
   norm_c__67->SetBinContent(18,17.43342);
   norm_c__67->SetBinContent(19,10.84999);
   norm_c__67->SetBinContent(20,5.833586);
   norm_c__67->SetBinContent(21,2.860298);
   norm_c__67->SetBinContent(22,1.287653);
   norm_c__67->SetBinContent(23,1.1177);
   norm_c__67->SetBinContent(24,0.9221553);
   norm_c__67->SetBinContent(25,0.3080333);
   norm_c__67->SetBinContent(26,1.733739);
   norm_c__67->SetBinError(3,0.6029965);
   norm_c__67->SetBinError(4,1.863253);
   norm_c__67->SetBinError(5,3.750904);
   norm_c__67->SetBinError(6,4.86747);
   norm_c__67->SetBinError(7,6.925392);
   norm_c__67->SetBinError(8,7.651587);
   norm_c__67->SetBinError(9,9.137174);
   norm_c__67->SetBinError(10,9.048708);
   norm_c__67->SetBinError(11,9.224098);
   norm_c__67->SetBinError(12,9.083051);
   norm_c__67->SetBinError(13,8.110607);
   norm_c__67->SetBinError(14,7.10974);
   norm_c__67->SetBinError(15,6.278061);
   norm_c__67->SetBinError(16,4.857336);
   norm_c__67->SetBinError(17,3.241474);
   norm_c__67->SetBinError(18,2.699984);
   norm_c__67->SetBinError(19,2.17288);
   norm_c__67->SetBinError(20,1.436852);
   norm_c__67->SetBinError(21,0.6623212);
   norm_c__67->SetBinError(22,0.5854358);
   norm_c__67->SetBinError(23,0.4424928);
   norm_c__67->SetBinError(24,0.4969942);
   norm_c__67->SetBinError(25,0.1487392);
   norm_c__67->SetBinError(26,0.5088063);
   norm_c__67->SetEntries(5927);
   norm_c__67->SetStats(0);

   ci = 1343;
   color = new TColor(ci, 0.3, 0.3, 0.3, " ", 0.6);
   norm_c__67->SetFillColor(ci);
   norm_c__67->SetFillStyle(3144);
   norm_c__67->SetLineColor(2);
   norm_c__67->SetLineWidth(2);
   norm_c__67->GetXaxis()->SetRange(1,25);
   norm_c__67->GetXaxis()->SetLabelFont(42);
   norm_c__67->GetXaxis()->SetLabelSize(0.04);
   norm_c__67->GetXaxis()->SetTitleOffset(1);
   norm_c__67->GetXaxis()->SetTitleFont(42);
   norm_c__67->GetYaxis()->SetLabelFont(42);
   norm_c__67->GetYaxis()->SetTitleFont(42);
   norm_c__67->GetZaxis()->SetLabelFont(42);
   norm_c__67->GetZaxis()->SetTitleOffset(1);
   norm_c__67->GetZaxis()->SetTitleFont(42);
   norm_c__67->Draw("e1 same");
   
   TLegend *leg = new TLegend(0.65,0.5,0.93,0.87,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.03);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("norm_c","Central","lpf");

   ci = 1343;
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
   entry=leg->AddEntry("frame_x_c2_46eaba50","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.819489 #pm 0.007194","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.244518 #pm 0.005780","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.562000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_46eaba50_copy__68 = new TH1D("frame_46eaba50_copy__68","p_T Balance",25,0,2);
   frame_46eaba50_copy__68->SetBinContent(1,174.6174);
   frame_46eaba50_copy__68->SetMaximum(174.6174);
   frame_46eaba50_copy__68->SetEntries(2);
   frame_46eaba50_copy__68->SetDirectory(0);
   frame_46eaba50_copy__68->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46eaba50_copy__68->SetLineColor(ci);
   frame_46eaba50_copy__68->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46eaba50_copy__68->GetXaxis()->SetLabelFont(42);
   frame_46eaba50_copy__68->GetXaxis()->SetTitleOffset(1);
   frame_46eaba50_copy__68->GetXaxis()->SetTitleFont(42);
   frame_46eaba50_copy__68->GetYaxis()->SetTitle("1/Events");
   frame_46eaba50_copy__68->GetYaxis()->SetLabelFont(42);
   frame_46eaba50_copy__68->GetYaxis()->SetTitleFont(42);
   frame_46eaba50_copy__68->GetZaxis()->SetLabelFont(42);
   frame_46eaba50_copy__68->GetZaxis()->SetTitleOffset(1);
   frame_46eaba50_copy__68->GetZaxis()->SetTitleFont(42);
   frame_46eaba50_copy__68->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-26.10926,2.25,197.4021);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_46e9cd60__69 = new TH1D("frame_46e9cd60__69","p_T Balance",25,0,2);
   frame_46e9cd60__69->SetBinContent(1,175.051);
   frame_46e9cd60__69->SetMinimum(-8.228345);
   frame_46e9cd60__69->SetMaximum(175.051);
   frame_46e9cd60__69->SetEntries(2);
   frame_46e9cd60__69->SetDirectory(0);
   frame_46e9cd60__69->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46e9cd60__69->SetLineColor(ci);
   frame_46e9cd60__69->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46e9cd60__69->GetXaxis()->SetLabelFont(42);
   frame_46e9cd60__69->GetXaxis()->SetTitleOffset(1);
   frame_46e9cd60__69->GetXaxis()->SetTitleFont(42);
   frame_46e9cd60__69->GetYaxis()->SetTitle("1/Events");
   frame_46e9cd60__69->GetYaxis()->SetLabelFont(42);
   frame_46e9cd60__69->GetYaxis()->SetTitleFont(42);
   frame_46e9cd60__69->GetZaxis()->SetLabelFont(42);
   frame_46e9cd60__69->GetZaxis()->SetTitleOffset(1);
   frame_46e9cd60__69->GetZaxis()->SetTitleFont(42);
   frame_46e9cd60__69->Draw("FUNC");
   
   Double_t h_dh_up2_fx3018[25] = {
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
   Double_t h_dh_up2_fy3018[25] = {
   0,
   0,
   0.02598028,
   11.40075,
   34.48967,
   47.01431,
   87.83042,
   114.9242,
   152.4197,
   151.9207,
   154.9621,
   134.428,
   137.1445,
   96.44996,
   78.22954,
   48.74393,
   30.86905,
   18.61856,
   10.44261,
   7.08838,
   2.467326,
   1.96041,
   1.04392,
   1.071239,
   0.3295996};
   Double_t h_dh_up2_felx3018[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_up2_fely3018[25] = {
   0,
   0,
   0.02598028,
   2.085421,
   4.260376,
   4.739271,
   6.808768,
   7.645253,
   9.141301,
   8.961841,
   9.604832,
   9.197258,
   8.833733,
   7.253645,
   6.642924,
   4.750365,
   3.82547,
   2.776201,
   2.147297,
   1.578359,
   0.6271762,
   0.7107782,
   0.4364252,
   0.5064607,
   0.1617907};
   Double_t h_dh_up2_fehx3018[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_up2_fehy3018[25] = {
   0,
   0,
   0.02598028,
   2.085421,
   4.260376,
   4.739271,
   6.808768,
   7.645253,
   9.141301,
   8.961841,
   9.604832,
   9.197258,
   8.833733,
   7.253645,
   6.642924,
   4.750365,
   3.82547,
   2.776201,
   2.147297,
   1.578359,
   0.6271762,
   0.7107782,
   0.4364252,
   0.5064607,
   0.1617907};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3018,h_dh_up2_fy3018,h_dh_up2_felx3018,h_dh_up2_fehx3018,h_dh_up2_fely3018,h_dh_up2_fehy3018);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23018 = new TH1F("Graph_h_dh_up23018","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23018->SetMinimum(-16.45669);
   Graph_h_dh_up23018->SetMaximum(181.0236);
   Graph_h_dh_up23018->SetDirectory(0);
   Graph_h_dh_up23018->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_up23018->SetLineColor(ci);
   Graph_h_dh_up23018->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_up23018->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_up23018->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_up23018->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_up23018->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_up23018->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_up23018->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_up23018->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_up23018);
   
   grae->Draw("p");
   
   Double_t up_fx18[57] = {
   0.1153437,
   0.1715605,
   0.1996688,
   0.2277772,
   0.2558856,
   0.283994,
   0.3121023,
   0.3402107,
   0.3683191,
   0.3964275,
   0.4245358,
   0.4526442,
   0.4807526,
   0.508861,
   0.5369693,
   0.5650777,
   0.6212944,
   0.6494028,
   0.6775112,
   0.7056196,
   0.7196738,
   0.7337279,
   0.7477821,
   0.7618363,
   0.7758905,
   0.7899447,
   0.8039989,
   0.8180531,
   0.8321073,
   0.8461614,
   0.8602156,
   0.8742698,
   0.888324,
   0.9023782,
   0.9164324,
   0.9304866,
   0.9445407,
   0.9585949,
   0.9867033,
   1.014812,
   1.04292,
   1.071028,
   1.127245,
   1.155354,
   1.183462,
   1.21157,
   1.225624,
   1.239679,
   1.267787,
   1.295895,
   1.324004,
   1.352112,
   1.380221,
   1.408329,
   1.464546,
   1.520762,
   1.520762};
   Double_t up_fy18[57] = {
   2.612847,
   4.894886,
   6.571894,
   8.710862,
   11.39867,
   14.72549,
   18.78053,
   23.64659,
   29.39353,
   36.07093,
   43.70041,
   52.26805,
   61.71767,
   71.94577,
   82.79871,
   94.07286,
   116.8459,
   127.7385,
   137.8646,
   146.8947,
   150.9007,
   154.5191,
   157.717,
   160.4651,
   162.7377,
   164.5135,
   165.7756,
   166.5118,
   166.7152,
   166.3838,
   165.5208,
   164.1344,
   162.2379,
   159.8493,
   156.991,
   153.6895,
   149.9752,
   145.8816,
   136.7033,
   126.4679,
   115.5058,
   104.1478,
   81.47231,
   70.68443,
   60.54246,
   51.25199,
   47.17691,
   43.49892,
   37.15801,
   31.93153,
   27.5925,
   23.96608,
   20.91632,
   18.33661,
   14.26719,
   11.2666,
   11.2666};
   graph = new TGraph(57,up_fx18,up_fy18);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up18 = new TH1F("Graph_up18","Projection of upf DSCB fit",100,0,1.661304);
   Graph_up18->SetMinimum(2.351563);
   Graph_up18->SetMaximum(183.1255);
   Graph_up18->SetDirectory(0);
   Graph_up18->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_up18->SetLineColor(ci);
   Graph_up18->GetXaxis()->SetLabelFont(42);
   Graph_up18->GetXaxis()->SetTitleOffset(1);
   Graph_up18->GetXaxis()->SetTitleFont(42);
   Graph_up18->GetYaxis()->SetLabelFont(42);
   Graph_up18->GetYaxis()->SetTitleFont(42);
   Graph_up18->GetZaxis()->SetLabelFont(42);
   Graph_up18->GetZaxis()->SetTitleOffset(1);
   Graph_up18->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_up18);
   
   graph->Draw("l");
   
   TH1D *frame_46e9cd60__70 = new TH1D("frame_46e9cd60__70","p_T Balance",25,0,2);
   frame_46e9cd60__70->SetBinContent(1,175.051);
   frame_46e9cd60__70->SetMinimum(-8.228345);
   frame_46e9cd60__70->SetMaximum(175.051);
   frame_46e9cd60__70->SetEntries(2);
   frame_46e9cd60__70->SetDirectory(0);
   frame_46e9cd60__70->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46e9cd60__70->SetLineColor(ci);
   frame_46e9cd60__70->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46e9cd60__70->GetXaxis()->SetLabelFont(42);
   frame_46e9cd60__70->GetXaxis()->SetTitleOffset(1);
   frame_46e9cd60__70->GetXaxis()->SetTitleFont(42);
   frame_46e9cd60__70->GetYaxis()->SetTitle("1/Events");
   frame_46e9cd60__70->GetYaxis()->SetLabelFont(42);
   frame_46e9cd60__70->GetYaxis()->SetTitleFont(42);
   frame_46e9cd60__70->GetZaxis()->SetLabelFont(42);
   frame_46e9cd60__70->GetZaxis()->SetTitleOffset(1);
   frame_46e9cd60__70->GetZaxis()->SetTitleFont(42);
   frame_46e9cd60__70->Draw("AXISSAME");
   
   TH1D *norm_u__71 = new TH1D("norm_u__71","",25,0,2);
   norm_u__71->SetBinContent(3,0.02598028);
   norm_u__71->SetBinContent(4,11.40075);
   norm_u__71->SetBinContent(5,34.48967);
   norm_u__71->SetBinContent(6,47.01431);
   norm_u__71->SetBinContent(7,87.83042);
   norm_u__71->SetBinContent(8,114.9242);
   norm_u__71->SetBinContent(9,152.4197);
   norm_u__71->SetBinContent(10,151.9207);
   norm_u__71->SetBinContent(11,154.9621);
   norm_u__71->SetBinContent(12,134.428);
   norm_u__71->SetBinContent(13,137.1445);
   norm_u__71->SetBinContent(14,96.44996);
   norm_u__71->SetBinContent(15,78.22954);
   norm_u__71->SetBinContent(16,48.74393);
   norm_u__71->SetBinContent(17,30.86904);
   norm_u__71->SetBinContent(18,18.61855);
   norm_u__71->SetBinContent(19,10.44261);
   norm_u__71->SetBinContent(20,7.08838);
   norm_u__71->SetBinContent(21,2.467326);
   norm_u__71->SetBinContent(22,1.96041);
   norm_u__71->SetBinContent(23,1.04392);
   norm_u__71->SetBinContent(24,1.071239);
   norm_u__71->SetBinContent(25,0.3295996);
   norm_u__71->SetBinContent(26,1.617716);
   norm_u__71->SetBinError(3,0.02598028);
   norm_u__71->SetBinError(4,2.085421);
   norm_u__71->SetBinError(5,4.260376);
   norm_u__71->SetBinError(6,4.739271);
   norm_u__71->SetBinError(7,6.808768);
   norm_u__71->SetBinError(8,7.645253);
   norm_u__71->SetBinError(9,9.141301);
   norm_u__71->SetBinError(10,8.961841);
   norm_u__71->SetBinError(11,9.604832);
   norm_u__71->SetBinError(12,9.197258);
   norm_u__71->SetBinError(13,8.833733);
   norm_u__71->SetBinError(14,7.253645);
   norm_u__71->SetBinError(15,6.642924);
   norm_u__71->SetBinError(16,4.750365);
   norm_u__71->SetBinError(17,3.82547);
   norm_u__71->SetBinError(18,2.776201);
   norm_u__71->SetBinError(19,2.147297);
   norm_u__71->SetBinError(20,1.578359);
   norm_u__71->SetBinError(21,0.6271762);
   norm_u__71->SetBinError(22,0.7107782);
   norm_u__71->SetBinError(23,0.4364252);
   norm_u__71->SetBinError(24,0.5064607);
   norm_u__71->SetBinError(25,0.1617907);
   norm_u__71->SetBinError(26,0.4829513);
   norm_u__71->SetEntries(5865);
   norm_u__71->SetStats(0);
   norm_u__71->SetLineColor(4);
   norm_u__71->SetLineWidth(2);
   norm_u__71->GetXaxis()->SetLabelFont(42);
   norm_u__71->GetXaxis()->SetTitleOffset(1);
   norm_u__71->GetXaxis()->SetTitleFont(42);
   norm_u__71->GetYaxis()->SetLabelFont(42);
   norm_u__71->GetYaxis()->SetTitleFont(42);
   norm_u__71->GetZaxis()->SetLabelFont(42);
   norm_u__71->GetZaxis()->SetTitleOffset(1);
   norm_u__71->GetZaxis()->SetTitleFont(42);
   norm_u__71->Draw("e1 same");
   
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
   entry=leg->AddEntry("frame_x_u2_46e9cd60","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.839887 #pm 0.007334","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.258117 #pm 0.005737","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.668000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_46e9cd60_copy__72 = new TH1D("frame_46e9cd60_copy__72","p_T Balance",25,0,2);
   frame_46e9cd60_copy__72->SetBinContent(1,175.051);
   frame_46e9cd60_copy__72->SetMinimum(-8.228345);
   frame_46e9cd60_copy__72->SetMaximum(175.051);
   frame_46e9cd60_copy__72->SetEntries(2);
   frame_46e9cd60_copy__72->SetDirectory(0);
   frame_46e9cd60_copy__72->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46e9cd60_copy__72->SetLineColor(ci);
   frame_46e9cd60_copy__72->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46e9cd60_copy__72->GetXaxis()->SetLabelFont(42);
   frame_46e9cd60_copy__72->GetXaxis()->SetTitleOffset(1);
   frame_46e9cd60_copy__72->GetXaxis()->SetTitleFont(42);
   frame_46e9cd60_copy__72->GetYaxis()->SetTitle("1/Events");
   frame_46e9cd60_copy__72->GetYaxis()->SetLabelFont(42);
   frame_46e9cd60_copy__72->GetYaxis()->SetTitleFont(42);
   frame_46e9cd60_copy__72->GetZaxis()->SetLabelFont(42);
   frame_46e9cd60_copy__72->GetZaxis()->SetTitleOffset(1);
   frame_46e9cd60_copy__72->GetZaxis()->SetTitleFont(42);
   frame_46e9cd60_copy__72->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-29.39814,2.25,180.5886);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_46eb85f0__73 = new TH1D("frame_46eb85f0__73","p_T Balance",25,0,2);
   frame_46eb85f0__73->SetBinContent(1,176.3888);
   frame_46eb85f0__73->SetMinimum(-8.399469);
   frame_46eb85f0__73->SetMaximum(176.3888);
   frame_46eb85f0__73->SetEntries(1);
   frame_46eb85f0__73->SetDirectory(0);
   frame_46eb85f0__73->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46eb85f0__73->SetLineColor(ci);
   frame_46eb85f0__73->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46eb85f0__73->GetXaxis()->SetLabelFont(42);
   frame_46eb85f0__73->GetXaxis()->SetTitleOffset(1);
   frame_46eb85f0__73->GetXaxis()->SetTitleFont(42);
   frame_46eb85f0__73->GetYaxis()->SetTitle("1/Events");
   frame_46eb85f0__73->GetYaxis()->SetLabelFont(42);
   frame_46eb85f0__73->GetYaxis()->SetTitleFont(42);
   frame_46eb85f0__73->GetZaxis()->SetLabelFont(42);
   frame_46eb85f0__73->GetZaxis()->SetTitleOffset(1);
   frame_46eb85f0__73->GetZaxis()->SetTitleFont(42);
   frame_46eb85f0__73->Draw("FUNC");
   
   Double_t h_dh_down2_fx3019[25] = {
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
   Double_t h_dh_down2_fy3019[25] = {
   0,
   0,
   0.02506543,
   10.40504,
   32.15253,
   60.28984,
   96.26003,
   123.4516,
   145.3875,
   158.4915,
   140.6564,
   119.3578,
   118.4332,
   85.64693,
   55.51047,
   49.3941,
   29.11942,
   13.73176,
   9.343434,
   5.363053,
   2.896685,
   1.822626,
   0.8466674,
   0.9512157,
   0.4702604};
   Double_t h_dh_down2_felx3019[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_down2_fely3019[25] = {
   0,
   0,
   0.02506543,
   2.077732,
   3.669099,
   5.383437,
   6.8168,
   7.618553,
   8.817612,
   9.497846,
   8.968654,
   8.532924,
   8.138504,
   6.610026,
   4.999135,
   4.91069,
   3.754149,
   2.134429,
   2.042026,
   1.248411,
   0.8909809,
   0.8206912,
   0.3030172,
   0.4993305,
   0.1816019};
   Double_t h_dh_down2_fehx3019[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_down2_fehy3019[25] = {
   0,
   0,
   0.02506543,
   2.077732,
   3.669099,
   5.383437,
   6.8168,
   7.618553,
   8.817612,
   9.497846,
   8.968654,
   8.532924,
   8.138504,
   6.610026,
   4.999135,
   4.91069,
   3.754149,
   2.134429,
   2.042026,
   1.248411,
   0.8909809,
   0.8206912,
   0.3030172,
   0.4993305,
   0.1816019};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3019,h_dh_down2_fy3019,h_dh_down2_felx3019,h_dh_down2_fehx3019,h_dh_down2_fely3019,h_dh_down2_fehy3019);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23019 = new TH1F("Graph_h_dh_down23019","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23019->SetMinimum(-16.79894);
   Graph_h_dh_down23019->SetMaximum(184.7883);
   Graph_h_dh_down23019->SetDirectory(0);
   Graph_h_dh_down23019->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_down23019->SetLineColor(ci);
   Graph_h_dh_down23019->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_down23019->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_down23019->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_down23019->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_down23019->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_down23019->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_down23019->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_down23019->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_down23019);
   
   grae->Draw("p");
   
   Double_t down_fx19[59] = {
   0.03730776,
   0.09652709,
   0.1557464,
   0.1853561,
   0.2149658,
   0.2445754,
   0.2741851,
   0.3037948,
   0.3334044,
   0.3630141,
   0.3926238,
   0.4222335,
   0.4518431,
   0.4814528,
   0.5110625,
   0.5702818,
   0.5998915,
   0.6295011,
   0.6591108,
   0.6739156,
   0.6887205,
   0.7035253,
   0.7183301,
   0.733135,
   0.7479398,
   0.7627446,
   0.7775495,
   0.7923543,
   0.8071592,
   0.821964,
   0.8367688,
   0.8515737,
   0.8663785,
   0.8811833,
   0.8959882,
   0.910793,
   0.9255978,
   0.9404027,
   0.9552075,
   0.9848172,
   1.044037,
   1.073646,
   1.088451,
   1.103256,
   1.118061,
   1.132866,
   1.14767,
   1.162475,
   1.192085,
   1.221695,
   1.251304,
   1.280914,
   1.310524,
   1.340133,
   1.369743,
   1.399353,
   1.458572,
   1.517791,
   1.517791};
   Double_t down_fy19[59] = {
   0.845073,
   1.860424,
   3.841754,
   5.389686,
   7.441274,
   10.1107,
   13.51964,
   17.79094,
   23.04002,
   29.36411,
   36.82992,
   45.46056,
   55.22284,
   66.01653,
   77.66702,
   102.4601,
   114.8917,
   126.7864,
   137.6914,
   142.6322,
   147.1604,
   151.2261,
   154.7836,
   157.7923,
   160.2172,
   162.0298,
   163.2086,
   163.7397,
   163.6165,
   162.8407,
   161.4215,
   159.3757,
   156.7276,
   153.5081,
   149.7544,
   145.5092,
   140.8198,
   135.7374,
   130.3161,
   118.6813,
   93.8211,
   81.43943,
   75.42157,
   69.75584,
   64.61222,
   59.93408,
   55.67177,
   51.78172,
   44.96953,
   39.24163,
   34.39736,
   30.27805,
   26.75734,
   23.73381,
   21.12553,
   18.86591,
   15.18447,
   12.35879,
   12.35879};
   graph = new TGraph(59,down_fx19,down_fy19);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down19 = new TH1F("Graph_down19","Projection of downf DSCB fit",100,0,1.66584);
   Graph_down19->SetMinimum(0.7605657);
   Graph_down19->SetMaximum(180.0291);
   Graph_down19->SetDirectory(0);
   Graph_down19->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_down19->SetLineColor(ci);
   Graph_down19->GetXaxis()->SetLabelFont(42);
   Graph_down19->GetXaxis()->SetTitleOffset(1);
   Graph_down19->GetXaxis()->SetTitleFont(42);
   Graph_down19->GetYaxis()->SetLabelFont(42);
   Graph_down19->GetYaxis()->SetTitleFont(42);
   Graph_down19->GetZaxis()->SetLabelFont(42);
   Graph_down19->GetZaxis()->SetTitleOffset(1);
   Graph_down19->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_down19);
   
   graph->Draw("l");
   
   TH1D *frame_46eb85f0__74 = new TH1D("frame_46eb85f0__74","p_T Balance",25,0,2);
   frame_46eb85f0__74->SetBinContent(1,176.3888);
   frame_46eb85f0__74->SetMinimum(-8.399469);
   frame_46eb85f0__74->SetMaximum(176.3888);
   frame_46eb85f0__74->SetEntries(1);
   frame_46eb85f0__74->SetDirectory(0);
   frame_46eb85f0__74->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46eb85f0__74->SetLineColor(ci);
   frame_46eb85f0__74->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46eb85f0__74->GetXaxis()->SetLabelFont(42);
   frame_46eb85f0__74->GetXaxis()->SetTitleOffset(1);
   frame_46eb85f0__74->GetXaxis()->SetTitleFont(42);
   frame_46eb85f0__74->GetYaxis()->SetTitle("1/Events");
   frame_46eb85f0__74->GetYaxis()->SetLabelFont(42);
   frame_46eb85f0__74->GetYaxis()->SetTitleFont(42);
   frame_46eb85f0__74->GetZaxis()->SetLabelFont(42);
   frame_46eb85f0__74->GetZaxis()->SetTitleOffset(1);
   frame_46eb85f0__74->GetZaxis()->SetTitleFont(42);
   frame_46eb85f0__74->Draw("AXISSAME");
   
   TH1D *norm_d__75 = new TH1D("norm_d__75","",25,0,2);
   norm_d__75->SetBinContent(3,0.02506543);
   norm_d__75->SetBinContent(4,10.40504);
   norm_d__75->SetBinContent(5,32.15253);
   norm_d__75->SetBinContent(6,60.28984);
   norm_d__75->SetBinContent(7,96.26003);
   norm_d__75->SetBinContent(8,123.4516);
   norm_d__75->SetBinContent(9,145.3875);
   norm_d__75->SetBinContent(10,158.4915);
   norm_d__75->SetBinContent(11,140.6564);
   norm_d__75->SetBinContent(12,119.3578);
   norm_d__75->SetBinContent(13,118.4332);
   norm_d__75->SetBinContent(14,85.64693);
   norm_d__75->SetBinContent(15,55.51047);
   norm_d__75->SetBinContent(16,49.3941);
   norm_d__75->SetBinContent(17,29.11942);
   norm_d__75->SetBinContent(18,13.73176);
   norm_d__75->SetBinContent(19,9.343434);
   norm_d__75->SetBinContent(20,5.363054);
   norm_d__75->SetBinContent(21,2.896685);
   norm_d__75->SetBinContent(22,1.822626);
   norm_d__75->SetBinContent(23,0.8466674);
   norm_d__75->SetBinContent(24,0.9512157);
   norm_d__75->SetBinContent(25,0.4702603);
   norm_d__75->SetBinContent(26,1.609757);
   norm_d__75->SetBinError(3,0.02506543);
   norm_d__75->SetBinError(4,2.077732);
   norm_d__75->SetBinError(5,3.669099);
   norm_d__75->SetBinError(6,5.383437);
   norm_d__75->SetBinError(7,6.8168);
   norm_d__75->SetBinError(8,7.618553);
   norm_d__75->SetBinError(9,8.817612);
   norm_d__75->SetBinError(10,9.497846);
   norm_d__75->SetBinError(11,8.968654);
   norm_d__75->SetBinError(12,8.532924);
   norm_d__75->SetBinError(13,8.138504);
   norm_d__75->SetBinError(14,6.610026);
   norm_d__75->SetBinError(15,4.999135);
   norm_d__75->SetBinError(16,4.91069);
   norm_d__75->SetBinError(17,3.754149);
   norm_d__75->SetBinError(18,2.134429);
   norm_d__75->SetBinError(19,2.042026);
   norm_d__75->SetBinError(20,1.248411);
   norm_d__75->SetBinError(21,0.8909809);
   norm_d__75->SetBinError(22,0.8206912);
   norm_d__75->SetBinError(23,0.3030172);
   norm_d__75->SetBinError(24,0.4993305);
   norm_d__75->SetBinError(25,0.1816019);
   norm_d__75->SetBinError(26,0.5071365);
   norm_d__75->SetEntries(5969);
   norm_d__75->SetStats(0);
   norm_d__75->SetLineColor(7);
   norm_d__75->SetLineWidth(2);
   norm_d__75->GetXaxis()->SetLabelFont(42);
   norm_d__75->GetXaxis()->SetTitleOffset(1);
   norm_d__75->GetXaxis()->SetTitleFont(42);
   norm_d__75->GetYaxis()->SetLabelFont(42);
   norm_d__75->GetYaxis()->SetTitleFont(42);
   norm_d__75->GetZaxis()->SetLabelFont(42);
   norm_d__75->GetZaxis()->SetTitleOffset(1);
   norm_d__75->GetZaxis()->SetTitleFont(42);
   norm_d__75->Draw("same e1");
   
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
   entry=leg->AddEntry("frame_x_d2_46eb85f0","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.819445 #pm 0.007384","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.255863 #pm 0.005613","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.613000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_46eb85f0_copy__76 = new TH1D("frame_46eb85f0_copy__76","p_T Balance",25,0,2);
   frame_46eb85f0_copy__76->SetBinContent(1,176.3888);
   frame_46eb85f0_copy__76->SetMinimum(-8.399469);
   frame_46eb85f0_copy__76->SetMaximum(176.3888);
   frame_46eb85f0_copy__76->SetEntries(1);
   frame_46eb85f0_copy__76->SetDirectory(0);
   frame_46eb85f0_copy__76->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46eb85f0_copy__76->SetLineColor(ci);
   frame_46eb85f0_copy__76->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46eb85f0_copy__76->GetXaxis()->SetLabelFont(42);
   frame_46eb85f0_copy__76->GetXaxis()->SetTitleOffset(1);
   frame_46eb85f0_copy__76->GetXaxis()->SetTitleFont(42);
   frame_46eb85f0_copy__76->GetYaxis()->SetTitle("1/Events");
   frame_46eb85f0_copy__76->GetYaxis()->SetLabelFont(42);
   frame_46eb85f0_copy__76->GetYaxis()->SetTitleFont(42);
   frame_46eb85f0_copy__76->GetZaxis()->SetLabelFont(42);
   frame_46eb85f0_copy__76->GetZaxis()->SetTitleOffset(1);
   frame_46eb85f0_copy__76->GetZaxis()->SetTitleFont(42);
   frame_46eb85f0_copy__76->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-23.26262,2.25,209.3636);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_46ea6750__77 = new TH1D("frame_46ea6750__77","p_T Balance",25,0,2);
   frame_46ea6750__77->SetBinContent(1,204.7111);
   frame_46ea6750__77->SetMaximum(204.7111);
   frame_46ea6750__77->SetEntries(1);
   frame_46ea6750__77->SetDirectory(0);
   frame_46ea6750__77->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46ea6750__77->SetLineColor(ci);
   frame_46ea6750__77->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46ea6750__77->GetXaxis()->SetLabelFont(42);
   frame_46ea6750__77->GetXaxis()->SetTitleOffset(1);
   frame_46ea6750__77->GetXaxis()->SetTitleFont(42);
   frame_46ea6750__77->GetYaxis()->SetTitle("1/Events");
   frame_46ea6750__77->GetYaxis()->SetLabelFont(42);
   frame_46ea6750__77->GetYaxis()->SetTitleFont(42);
   frame_46ea6750__77->GetZaxis()->SetLabelFont(42);
   frame_46ea6750__77->GetZaxis()->SetTitleOffset(1);
   frame_46ea6750__77->GetZaxis()->SetTitleFont(42);
   frame_46ea6750__77->Draw("FUNC");
   
   Double_t h_dh_data2_fx3020[25] = {
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
   Double_t h_dh_data2_fy3020[25] = {
   0,
   0,
   0,
   16,
   30,
   49,
   99,
   122,
   181,
   170,
   166,
   143,
   107,
   76,
   59,
   42,
   27,
   13,
   14,
   9,
   7,
   3,
   1,
   1,
   2};
   Double_t h_dh_data2_felx3020[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_data2_fely3020[25] = {
   0,
   0,
   0,
   3.957801,
   5.446522,
   6.976026,
   9.933044,
   10.55667,
   12.96291,
   12.54799,
   12.3938,
   11.46871,
   9.856158,
   8.698576,
   7.659312,
   6.454831,
   5.163771,
   3.558662,
   3.6965,
   2.943461,
   2.58147,
   1.632705,
   0.8272462,
   0.8272462,
   1.291815};
   Double_t h_dh_data2_fehx3020[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_data2_fehy3020[25] = {
   1.147874,
   1.147874,
   1.147874,
   5.083066,
   6.538046,
   8.047634,
   10.9834,
   11.55667,
   13.96291,
   13.54799,
   13.3938,
   12.46871,
   10.85616,
   9.756061,
   8.724565,
   7.53218,
   6.260244,
   4.697573,
   4.830381,
   4.110204,
   3.770281,
   2.918186,
   2.299527,
   2.299527,
   2.63786};
   grae = new TGraphAsymmErrors(25,h_dh_data2_fx3020,h_dh_data2_fy3020,h_dh_data2_felx3020,h_dh_data2_fehx3020,h_dh_data2_fely3020,h_dh_data2_fehy3020);
   grae->SetName("h_dh_data2");
   grae->SetTitle("Histogram of dh_data2_plot__x_o2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_data23020 = new TH1F("Graph_h_dh_data23020","Histogram of dh_data2_plot__x_o2",100,0,2.2);
   Graph_h_dh_data23020->SetMinimum(0);
   Graph_h_dh_data23020->SetMaximum(214.4592);
   Graph_h_dh_data23020->SetDirectory(0);
   Graph_h_dh_data23020->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_data23020->SetLineColor(ci);
   Graph_h_dh_data23020->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_data23020->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_data23020->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_data23020->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_data23020->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_data23020->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_data23020->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_data23020->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_data23020);
   
   grae->Draw("p");
   
   Double_t observation_fx20[59] = {
   0.1373591,
   0.1876186,
   0.2127484,
   0.2378782,
   0.263008,
   0.2881378,
   0.3132676,
   0.3383974,
   0.3635272,
   0.388657,
   0.4137868,
   0.4389166,
   0.4640463,
   0.4891761,
   0.5143059,
   0.5394357,
   0.5896953,
   0.6148251,
   0.6399549,
   0.6650847,
   0.6776496,
   0.6902145,
   0.7027794,
   0.7153443,
   0.7279092,
   0.740474,
   0.7530389,
   0.7656038,
   0.7781687,
   0.7907336,
   0.8032985,
   0.8158634,
   0.8284283,
   0.8409932,
   0.8535581,
   0.866123,
   0.8786879,
   0.8912528,
   0.9163826,
   0.9415124,
   0.9666422,
   0.991772,
   1.016902,
   1.029467,
   1.042032,
   1.054596,
   1.067161,
   1.092291,
   1.117421,
   1.142551,
   1.167681,
   1.19281,
   1.21794,
   1.24307,
   1.2682,
   1.293329,
   1.343589,
   1.393849,
   1.393849};
   Double_t observation_fy20[59] = {
   2.154914,
   4.205021,
   5.755144,
   7.770046,
   10.34833,
   13.59553,
   17.61982,
   22.5261,
   28.40861,
   35.34216,
   43.37261,
   52.50702,
   62.70445,
   73.8684,
   85.84171,
   98.40503,
   124.1347,
   136.5997,
   148.2812,
   158.7821,
   163.4703,
   167.7244,
   171.5036,
   174.7713,
   177.4953,
   179.6484,
   181.209,
   182.1613,
   182.4955,
   182.2082,
   181.3024,
   179.7873,
   177.6783,
   174.9966,
   171.7689,
   168.0271,
   163.8076,
   159.1507,
   148.702,
   137.058,
   124.6153,
   111.7681,
   98.88916,
   92.77854,
   87.1327,
   81.90986,
   77.07255,
   68.42329,
   60.954,
   54.47667,
   48.83734,
   43.9092,
   39.58729,
   35.78429,
   32.42719,
   29.4547,
   24.46473,
   20.48811,
   20.48811};
   graph = new TGraph(59,observation_fx20,observation_fy20);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation20 = new TH1F("Graph_observation20","Projection of obsf DSCB fit",100,0.0117101,1.519498);
   Graph_observation20->SetMinimum(1.939422);
   Graph_observation20->SetMaximum(200.5295);
   Graph_observation20->SetDirectory(0);
   Graph_observation20->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_observation20->SetLineColor(ci);
   Graph_observation20->GetXaxis()->SetLabelFont(42);
   Graph_observation20->GetXaxis()->SetTitleOffset(1);
   Graph_observation20->GetXaxis()->SetTitleFont(42);
   Graph_observation20->GetYaxis()->SetLabelFont(42);
   Graph_observation20->GetYaxis()->SetTitleFont(42);
   Graph_observation20->GetZaxis()->SetLabelFont(42);
   Graph_observation20->GetZaxis()->SetTitleOffset(1);
   Graph_observation20->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_observation20);
   
   graph->Draw("l");
   
   TH1D *frame_46ea6750__78 = new TH1D("frame_46ea6750__78","p_T Balance",25,0,2);
   frame_46ea6750__78->SetBinContent(1,204.7111);
   frame_46ea6750__78->SetMaximum(204.7111);
   frame_46ea6750__78->SetEntries(1);
   frame_46ea6750__78->SetDirectory(0);
   frame_46ea6750__78->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46ea6750__78->SetLineColor(ci);
   frame_46ea6750__78->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46ea6750__78->GetXaxis()->SetLabelFont(42);
   frame_46ea6750__78->GetXaxis()->SetTitleOffset(1);
   frame_46ea6750__78->GetXaxis()->SetTitleFont(42);
   frame_46ea6750__78->GetYaxis()->SetTitle("1/Events");
   frame_46ea6750__78->GetYaxis()->SetLabelFont(42);
   frame_46ea6750__78->GetYaxis()->SetTitleFont(42);
   frame_46ea6750__78->GetZaxis()->SetLabelFont(42);
   frame_46ea6750__78->GetZaxis()->SetTitleOffset(1);
   frame_46ea6750__78->GetZaxis()->SetTitleFont(42);
   frame_46ea6750__78->Draw("AXISSAME");
   
   TH1D *norm_o__79 = new TH1D("norm_o__79","",25,0,2);
   norm_o__79->SetBinContent(4,16);
   norm_o__79->SetBinContent(5,30);
   norm_o__79->SetBinContent(6,49);
   norm_o__79->SetBinContent(7,99);
   norm_o__79->SetBinContent(8,122);
   norm_o__79->SetBinContent(9,181);
   norm_o__79->SetBinContent(10,170);
   norm_o__79->SetBinContent(11,166);
   norm_o__79->SetBinContent(12,143);
   norm_o__79->SetBinContent(13,107);
   norm_o__79->SetBinContent(14,76);
   norm_o__79->SetBinContent(15,59);
   norm_o__79->SetBinContent(16,42);
   norm_o__79->SetBinContent(17,27);
   norm_o__79->SetBinContent(18,13);
   norm_o__79->SetBinContent(19,14);
   norm_o__79->SetBinContent(20,9);
   norm_o__79->SetBinContent(21,7);
   norm_o__79->SetBinContent(22,3);
   norm_o__79->SetBinContent(23,1);
   norm_o__79->SetBinContent(24,1);
   norm_o__79->SetBinContent(25,2);
   norm_o__79->SetBinContent(26,1);
   norm_o__79->SetMinimum(0);
   norm_o__79->SetMaximum(398.2);
   norm_o__79->SetEntries(1338);
   norm_o__79->SetStats(0);
   norm_o__79->SetLineWidth(2);
   norm_o__79->SetMarkerStyle(8);
   norm_o__79->SetMarkerSize(0.4);
   norm_o__79->GetXaxis()->SetRange(1,25);
   norm_o__79->GetXaxis()->SetLabelFont(42);
   norm_o__79->GetXaxis()->SetLabelSize(0.04);
   norm_o__79->GetXaxis()->SetTitleOffset(1);
   norm_o__79->GetXaxis()->SetTitleFont(42);
   norm_o__79->GetYaxis()->SetTitle("Events");
   norm_o__79->GetYaxis()->SetLabelFont(42);
   norm_o__79->GetYaxis()->SetTitleOffset(1.4);
   norm_o__79->GetYaxis()->SetTitleFont(42);
   norm_o__79->GetZaxis()->SetLabelFont(42);
   norm_o__79->GetZaxis()->SetTitleOffset(1);
   norm_o__79->GetZaxis()->SetTitleFont(42);
   norm_o__79->Draw("same e1");
   
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
   entry=leg->AddEntry("frame_x_o2_46ea6750","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.802798 #pm 0.006853","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.237428 #pm 0.005435","");
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
   
   TH1D *frame_46ea6750_copy__80 = new TH1D("frame_46ea6750_copy__80","p_T Balance",25,0,2);
   frame_46ea6750_copy__80->SetBinContent(1,204.7111);
   frame_46ea6750_copy__80->SetMaximum(204.7111);
   frame_46ea6750_copy__80->SetEntries(1);
   frame_46ea6750_copy__80->SetDirectory(0);
   frame_46ea6750_copy__80->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46ea6750_copy__80->SetLineColor(ci);
   frame_46ea6750_copy__80->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46ea6750_copy__80->GetXaxis()->SetLabelFont(42);
   frame_46ea6750_copy__80->GetXaxis()->SetTitleOffset(1);
   frame_46ea6750_copy__80->GetXaxis()->SetTitleFont(42);
   frame_46ea6750_copy__80->GetYaxis()->SetTitle("1/Events");
   frame_46ea6750_copy__80->GetYaxis()->SetLabelFont(42);
   frame_46ea6750_copy__80->GetYaxis()->SetTitleFont(42);
   frame_46ea6750_copy__80->GetZaxis()->SetLabelFont(42);
   frame_46ea6750_copy__80->GetZaxis()->SetTitleOffset(1);
   frame_46ea6750_copy__80->GetZaxis()->SetTitleFont(42);
   frame_46ea6750_copy__80->Draw("sameaxis");
   
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
