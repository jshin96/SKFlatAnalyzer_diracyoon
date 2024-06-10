void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_5__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 18:52:03 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-36.17616,2.25,416.0259);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_46fd2f00__65 = new TH1D("frame_46fd2f00__65","p_T Balance",25,0,2);
   frame_46fd2f00__65->SetBinContent(1,370.8057);
   frame_46fd2f00__65->SetMaximum(370.8057);
   frame_46fd2f00__65->SetEntries(1);
   frame_46fd2f00__65->SetDirectory(0);
   frame_46fd2f00__65->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_46fd2f00__65->SetLineColor(ci);
   frame_46fd2f00__65->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46fd2f00__65->GetXaxis()->SetLabelFont(42);
   frame_46fd2f00__65->GetXaxis()->SetTitleOffset(1);
   frame_46fd2f00__65->GetXaxis()->SetTitleFont(42);
   frame_46fd2f00__65->GetYaxis()->SetTitle("1/Events");
   frame_46fd2f00__65->GetYaxis()->SetLabelFont(42);
   frame_46fd2f00__65->GetYaxis()->SetTitleFont(42);
   frame_46fd2f00__65->GetZaxis()->SetLabelFont(42);
   frame_46fd2f00__65->GetZaxis()->SetTitleOffset(1);
   frame_46fd2f00__65->GetZaxis()->SetTitleFont(42);
   frame_46fd2f00__65->Draw("FUNC");
   
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
   0.05478632,
   21.07238,
   57.64273,
   115.25,
   169.3574,
   234.7821,
   281.8925,
   306.2143,
   339.6094,
   288.2499,
   259.483,
   211.4977,
   159.8655,
   99.67855,
   56.92509,
   43.50916,
   17.73796,
   7.267808,
   7.203281,
   7.210607,
   1.312825,
   2.105032,
   0.441778};
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
   0.03874095,
   3.021048,
   4.958599,
   7.469999,
   9.198497,
   11.01634,
   11.8866,
   12.54867,
   13.53889,
   12.47659,
   11.94646,
   10.61281,
   9.029795,
   6.707085,
   4.868317,
   4.216403,
   2.418699,
   1.397117,
   1.474894,
   1.550736,
   0.4358554,
   0.6851189,
   0.1351254};
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
   0.03874095,
   3.021048,
   4.958599,
   7.469999,
   9.198497,
   11.01634,
   11.8866,
   12.54867,
   13.53889,
   12.47659,
   11.94646,
   10.61281,
   9.029795,
   6.707085,
   4.868317,
   4.216403,
   2.418699,
   1.397117,
   1.474894,
   1.550736,
   0.4358554,
   0.6851189,
   0.1351254};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3017,h_dh_central2_fy3017,h_dh_central2_felx3017,h_dh_central2_fehx3017,h_dh_central2_fely3017,h_dh_central2_fehy3017);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23017 = new TH1F("Graph_h_dh_central23017","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23017->SetMinimum(0);
   Graph_h_dh_central23017->SetMaximum(388.4631);
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
   
   Double_t Central_fx17[59] = {
   0.1428236,
   0.1703337,
   0.1978438,
   0.2253539,
   0.2528639,
   0.280374,
   0.3078841,
   0.3353942,
   0.3629042,
   0.3904143,
   0.4179244,
   0.4454345,
   0.4729445,
   0.5004546,
   0.5279647,
   0.5829848,
   0.638005,
   0.6655151,
   0.6930251,
   0.7205352,
   0.7342903,
   0.7480453,
   0.7618003,
   0.7755554,
   0.7893104,
   0.8030654,
   0.8168205,
   0.8305755,
   0.8443306,
   0.8580856,
   0.8718406,
   0.8855957,
   0.8993507,
   0.9131057,
   0.9268608,
   0.9406158,
   0.9543709,
   0.9681259,
   0.995636,
   1.023146,
   1.050656,
   1.078166,
   1.133186,
   1.160696,
   1.188207,
   1.215717,
   1.243227,
   1.256982,
   1.270737,
   1.284492,
   1.298247,
   1.325757,
   1.353267,
   1.380777,
   1.408287,
   1.435797,
   1.463307,
   1.518327,
   1.518327};
   Double_t Central_fy17[59] = {
   7.394875,
   9.951828,
   13.23303,
   17.38602,
   22.56969,
   28.94911,
   36.68846,
   45.94182,
   56.84225,
   69.48944,
   83.93649,
   100.1768,
   118.1322,
   137.6428,
   158.4613,
   202.5891,
   246.8578,
   267.6324,
   286.6918,
   303.4423,
   310.7783,
   317.3375,
   323.0638,
   327.9074,
   331.8259,
   334.7845,
   336.757,
   337.7256,
   337.6817,
   336.6256,
   334.5668,
   331.5238,
   327.5236,
   322.6017,
   316.8012,
   310.1724,
   302.7719,
   294.6619,
   276.5854,
   256.5187,
   235.0679,
   212.8394,
   168.3149,
   147.0058,
   126.8618,
   108.1713,
   91.13332,
   83.27599,
   76.10308,
   69.68611,
   63.93146,
   54.09882,
   46.08592,
   39.50317,
   34.0549,
   29.51437,
   25.70599,
   19.76591,
   19.76591};
   TGraph *graph = new TGraph(59,Central_fx17,Central_fy17);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central17 = new TH1F("Graph_Central17","Projection of centralf DSCB fit",100,0.00527326,1.655878);
   Graph_Central17->SetMinimum(6.655388);
   Graph_Central17->SetMaximum(370.7587);
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
   
   TH1D *frame_46fd2f00__66 = new TH1D("frame_46fd2f00__66","p_T Balance",25,0,2);
   frame_46fd2f00__66->SetBinContent(1,370.8057);
   frame_46fd2f00__66->SetMaximum(370.8057);
   frame_46fd2f00__66->SetEntries(1);
   frame_46fd2f00__66->SetDirectory(0);
   frame_46fd2f00__66->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46fd2f00__66->SetLineColor(ci);
   frame_46fd2f00__66->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46fd2f00__66->GetXaxis()->SetLabelFont(42);
   frame_46fd2f00__66->GetXaxis()->SetTitleOffset(1);
   frame_46fd2f00__66->GetXaxis()->SetTitleFont(42);
   frame_46fd2f00__66->GetYaxis()->SetTitle("1/Events");
   frame_46fd2f00__66->GetYaxis()->SetLabelFont(42);
   frame_46fd2f00__66->GetYaxis()->SetTitleFont(42);
   frame_46fd2f00__66->GetZaxis()->SetLabelFont(42);
   frame_46fd2f00__66->GetZaxis()->SetTitleOffset(1);
   frame_46fd2f00__66->GetZaxis()->SetTitleFont(42);
   frame_46fd2f00__66->Draw("AXISSAME");
   
   TH1D *norm_c__67 = new TH1D("norm_c__67","",25,0,2);
   norm_c__67->SetBinContent(3,0.05478632);
   norm_c__67->SetBinContent(4,21.07238);
   norm_c__67->SetBinContent(5,57.64273);
   norm_c__67->SetBinContent(6,115.25);
   norm_c__67->SetBinContent(7,169.3574);
   norm_c__67->SetBinContent(8,234.7821);
   norm_c__67->SetBinContent(9,281.8925);
   norm_c__67->SetBinContent(10,306.2143);
   norm_c__67->SetBinContent(11,339.6094);
   norm_c__67->SetBinContent(12,288.2499);
   norm_c__67->SetBinContent(13,259.483);
   norm_c__67->SetBinContent(14,211.4977);
   norm_c__67->SetBinContent(15,159.8655);
   norm_c__67->SetBinContent(16,99.67855);
   norm_c__67->SetBinContent(17,56.92509);
   norm_c__67->SetBinContent(18,43.50915);
   norm_c__67->SetBinContent(19,17.73796);
   norm_c__67->SetBinContent(20,7.267808);
   norm_c__67->SetBinContent(21,7.203281);
   norm_c__67->SetBinContent(22,7.210606);
   norm_c__67->SetBinContent(23,1.312825);
   norm_c__67->SetBinContent(24,2.105032);
   norm_c__67->SetBinContent(25,0.441778);
   norm_c__67->SetBinContent(26,2.920374);
   norm_c__67->SetBinError(3,0.03874095);
   norm_c__67->SetBinError(4,3.021048);
   norm_c__67->SetBinError(5,4.958599);
   norm_c__67->SetBinError(6,7.469999);
   norm_c__67->SetBinError(7,9.198497);
   norm_c__67->SetBinError(8,11.01634);
   norm_c__67->SetBinError(9,11.8866);
   norm_c__67->SetBinError(10,12.54867);
   norm_c__67->SetBinError(11,13.53889);
   norm_c__67->SetBinError(12,12.47659);
   norm_c__67->SetBinError(13,11.94646);
   norm_c__67->SetBinError(14,10.61281);
   norm_c__67->SetBinError(15,9.029795);
   norm_c__67->SetBinError(16,6.707085);
   norm_c__67->SetBinError(17,4.868317);
   norm_c__67->SetBinError(18,4.216403);
   norm_c__67->SetBinError(19,2.418699);
   norm_c__67->SetBinError(20,1.397117);
   norm_c__67->SetBinError(21,1.474894);
   norm_c__67->SetBinError(22,1.550736);
   norm_c__67->SetBinError(23,0.4358554);
   norm_c__67->SetBinError(24,0.6851189);
   norm_c__67->SetBinError(25,0.1351254);
   norm_c__67->SetBinError(26,0.4820011);
   norm_c__67->SetEntries(11950);
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
   entry=leg->AddEntry("frame_x_c2_46fd2f00","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.842066 #pm 0.005140","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.257108 #pm 0.004060","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.722000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_46fd2f00_copy__68 = new TH1D("frame_46fd2f00_copy__68","p_T Balance",25,0,2);
   frame_46fd2f00_copy__68->SetBinContent(1,370.8057);
   frame_46fd2f00_copy__68->SetMaximum(370.8057);
   frame_46fd2f00_copy__68->SetEntries(1);
   frame_46fd2f00_copy__68->SetDirectory(0);
   frame_46fd2f00_copy__68->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46fd2f00_copy__68->SetLineColor(ci);
   frame_46fd2f00_copy__68->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46fd2f00_copy__68->GetXaxis()->SetLabelFont(42);
   frame_46fd2f00_copy__68->GetXaxis()->SetTitleOffset(1);
   frame_46fd2f00_copy__68->GetXaxis()->SetTitleFont(42);
   frame_46fd2f00_copy__68->GetYaxis()->SetTitle("1/Events");
   frame_46fd2f00_copy__68->GetYaxis()->SetLabelFont(42);
   frame_46fd2f00_copy__68->GetYaxis()->SetTitleFont(42);
   frame_46fd2f00_copy__68->GetZaxis()->SetLabelFont(42);
   frame_46fd2f00_copy__68->GetZaxis()->SetTitleOffset(1);
   frame_46fd2f00_copy__68->GetZaxis()->SetTitleFont(42);
   frame_46fd2f00_copy__68->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-36.09031,2.25,415.0386);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_46fc4e30__69 = new TH1D("frame_46fc4e30__69","p_T Balance",25,0,2);
   frame_46fc4e30__69->SetBinContent(1,369.9257);
   frame_46fc4e30__69->SetMaximum(369.9257);
   frame_46fc4e30__69->SetEntries(1);
   frame_46fc4e30__69->SetDirectory(0);
   frame_46fc4e30__69->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46fc4e30__69->SetLineColor(ci);
   frame_46fc4e30__69->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46fc4e30__69->GetXaxis()->SetLabelFont(42);
   frame_46fc4e30__69->GetXaxis()->SetTitleOffset(1);
   frame_46fc4e30__69->GetXaxis()->SetTitleFont(42);
   frame_46fc4e30__69->GetYaxis()->SetTitle("1/Events");
   frame_46fc4e30__69->GetYaxis()->SetLabelFont(42);
   frame_46fc4e30__69->GetYaxis()->SetTitleFont(42);
   frame_46fc4e30__69->GetZaxis()->SetLabelFont(42);
   frame_46fc4e30__69->GetZaxis()->SetTitleOffset(1);
   frame_46fc4e30__69->GetZaxis()->SetTitleFont(42);
   frame_46fc4e30__69->Draw("FUNC");
   
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
   0.4047002,
   15.28089,
   58.71127,
   101.7775,
   160.7246,
   221.0222,
   272.4231,
   322.8849,
   338.7212,
   300.9201,
   280.8371,
   238.1447,
   173.8872,
   103.3743,
   64.17101,
   45.46975,
   19.7802,
   9.747473,
   9.381035,
   6.101666,
   1.740842,
   2.198897,
   0.3239996};
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
   0.3764316,
   2.514732,
   5.213085,
   6.922093,
   9.220941,
   10.53705,
   11.78759,
   13.00996,
   13.58899,
   12.8846,
   12.4938,
   11.46941,
   9.617253,
   6.916384,
   5.43506,
   4.353944,
   2.70548,
   1.73071,
   1.709972,
   1.423902,
   0.646932,
   0.676868,
   0.1013058};
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
   0.3764316,
   2.514732,
   5.213085,
   6.922093,
   9.220941,
   10.53705,
   11.78759,
   13.00996,
   13.58899,
   12.8846,
   12.4938,
   11.46941,
   9.617253,
   6.916384,
   5.43506,
   4.353944,
   2.70548,
   1.73071,
   1.709972,
   1.423902,
   0.646932,
   0.676868,
   0.1013058};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3018,h_dh_up2_fy3018,h_dh_up2_felx3018,h_dh_up2_fehx3018,h_dh_up2_fely3018,h_dh_up2_fehy3018);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23018 = new TH1F("Graph_h_dh_up23018","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23018->SetMinimum(0);
   Graph_h_dh_up23018->SetMaximum(387.5412);
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
   
   Double_t up_fx18[58] = {
   0.1961936,
   0.2225069,
   0.2488202,
   0.2751335,
   0.3014467,
   0.32776,
   0.3540733,
   0.3803866,
   0.4066998,
   0.4330131,
   0.4593264,
   0.4856397,
   0.5119529,
   0.5382662,
   0.5645795,
   0.617206,
   0.6435193,
   0.6698326,
   0.6961458,
   0.7224591,
   0.7356157,
   0.7487724,
   0.761929,
   0.7750857,
   0.7882423,
   0.8013989,
   0.8145556,
   0.8277122,
   0.8408688,
   0.8540255,
   0.8671821,
   0.8803387,
   0.8934954,
   0.906652,
   0.9198087,
   0.9329653,
   0.9461219,
   0.9592786,
   0.9855918,
   1.011905,
   1.038218,
   1.064532,
   1.090845,
   1.143471,
   1.169785,
   1.196098,
   1.222411,
   1.248725,
   1.275038,
   1.301351,
   1.327664,
   1.353978,
   1.380291,
   1.406604,
   1.432917,
   1.459231,
   1.511857,
   1.511857};
   Double_t up_fy18[58] = {
   12.01441,
   15.653,
   20.17319,
   25.71781,
   32.43214,
   40.45752,
   49.92351,
   60.93869,
   73.58059,
   87.88517,
   103.8365,
   121.3575,
   140.3025,
   160.4525,
   181.5138,
   224.8446,
   246.2022,
   266.6759,
   285.7312,
   302.8404,
   310.5079,
   317.506,
   323.7814,
   329.2853,
   333.9746,
   337.8119,
   340.7666,
   342.8149,
   343.9401,
   344.1332,
   343.3925,
   341.7241,
   339.1415,
   335.6656,
   331.3243,
   326.1521,
   320.1899,
   313.4842,
   298.0529,
   280.3195,
   260.7926,
   240.0045,
   218.4871,
   175.2608,
   154.4321,
   134.6085,
   116.0619,
   98.98947,
   83.63701,
   70.93327,
   60.55253,
   52.00318,
   44.91083,
   38.9874,
   34.00915,
   29.80072,
   23.16744,
   23.16744};
   graph = new TGraph(58,up_fx18,up_fy18);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up18 = new TH1F("Graph_up18","Projection of upf DSCB fit",100,0.06462728,1.643424);
   Graph_up18->SetMinimum(10.81297);
   Graph_up18->SetMaximum(377.3451);
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
   
   TH1D *frame_46fc4e30__70 = new TH1D("frame_46fc4e30__70","p_T Balance",25,0,2);
   frame_46fc4e30__70->SetBinContent(1,369.9257);
   frame_46fc4e30__70->SetMaximum(369.9257);
   frame_46fc4e30__70->SetEntries(1);
   frame_46fc4e30__70->SetDirectory(0);
   frame_46fc4e30__70->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46fc4e30__70->SetLineColor(ci);
   frame_46fc4e30__70->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46fc4e30__70->GetXaxis()->SetLabelFont(42);
   frame_46fc4e30__70->GetXaxis()->SetTitleOffset(1);
   frame_46fc4e30__70->GetXaxis()->SetTitleFont(42);
   frame_46fc4e30__70->GetYaxis()->SetTitle("1/Events");
   frame_46fc4e30__70->GetYaxis()->SetLabelFont(42);
   frame_46fc4e30__70->GetYaxis()->SetTitleFont(42);
   frame_46fc4e30__70->GetZaxis()->SetLabelFont(42);
   frame_46fc4e30__70->GetZaxis()->SetTitleOffset(1);
   frame_46fc4e30__70->GetZaxis()->SetTitleFont(42);
   frame_46fc4e30__70->Draw("AXISSAME");
   
   TH1D *norm_u__71 = new TH1D("norm_u__71","",25,0,2);
   norm_u__71->SetBinContent(3,0.4047003);
   norm_u__71->SetBinContent(4,15.28089);
   norm_u__71->SetBinContent(5,58.71127);
   norm_u__71->SetBinContent(6,101.7776);
   norm_u__71->SetBinContent(7,160.7246);
   norm_u__71->SetBinContent(8,221.0222);
   norm_u__71->SetBinContent(9,272.4231);
   norm_u__71->SetBinContent(10,322.8849);
   norm_u__71->SetBinContent(11,338.7212);
   norm_u__71->SetBinContent(12,300.9201);
   norm_u__71->SetBinContent(13,280.8371);
   norm_u__71->SetBinContent(14,238.1447);
   norm_u__71->SetBinContent(15,173.8872);
   norm_u__71->SetBinContent(16,103.3743);
   norm_u__71->SetBinContent(17,64.17101);
   norm_u__71->SetBinContent(18,45.46974);
   norm_u__71->SetBinContent(19,19.78019);
   norm_u__71->SetBinContent(20,9.747473);
   norm_u__71->SetBinContent(21,9.381035);
   norm_u__71->SetBinContent(22,6.101666);
   norm_u__71->SetBinContent(23,1.740842);
   norm_u__71->SetBinContent(24,2.198897);
   norm_u__71->SetBinContent(25,0.3239996);
   norm_u__71->SetBinContent(26,2.87947);
   norm_u__71->SetBinError(3,0.3764316);
   norm_u__71->SetBinError(4,2.514732);
   norm_u__71->SetBinError(5,5.213085);
   norm_u__71->SetBinError(6,6.922093);
   norm_u__71->SetBinError(7,9.220941);
   norm_u__71->SetBinError(8,10.53705);
   norm_u__71->SetBinError(9,11.78759);
   norm_u__71->SetBinError(10,13.00996);
   norm_u__71->SetBinError(11,13.58899);
   norm_u__71->SetBinError(12,12.8846);
   norm_u__71->SetBinError(13,12.4938);
   norm_u__71->SetBinError(14,11.46941);
   norm_u__71->SetBinError(15,9.617253);
   norm_u__71->SetBinError(16,6.916384);
   norm_u__71->SetBinError(17,5.43506);
   norm_u__71->SetBinError(18,4.353944);
   norm_u__71->SetBinError(19,2.70548);
   norm_u__71->SetBinError(20,1.73071);
   norm_u__71->SetBinError(21,1.709972);
   norm_u__71->SetBinError(22,1.423902);
   norm_u__71->SetBinError(23,0.646932);
   norm_u__71->SetBinError(24,0.676868);
   norm_u__71->SetBinError(25,0.1013058);
   norm_u__71->SetBinError(26,0.4888979);
   norm_u__71->SetEntries(11804);
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
   entry=leg->AddEntry("frame_x_u2_46fc4e30","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.850186 #pm 0.005171","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.252481 #pm 0.004410","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.889000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_46fc4e30_copy__72 = new TH1D("frame_46fc4e30_copy__72","p_T Balance",25,0,2);
   frame_46fc4e30_copy__72->SetBinContent(1,369.9257);
   frame_46fc4e30_copy__72->SetMaximum(369.9257);
   frame_46fc4e30_copy__72->SetEntries(1);
   frame_46fc4e30_copy__72->SetDirectory(0);
   frame_46fc4e30_copy__72->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46fc4e30_copy__72->SetLineColor(ci);
   frame_46fc4e30_copy__72->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46fc4e30_copy__72->GetXaxis()->SetLabelFont(42);
   frame_46fc4e30_copy__72->GetXaxis()->SetTitleOffset(1);
   frame_46fc4e30_copy__72->GetXaxis()->SetTitleFont(42);
   frame_46fc4e30_copy__72->GetYaxis()->SetTitle("1/Events");
   frame_46fc4e30_copy__72->GetYaxis()->SetLabelFont(42);
   frame_46fc4e30_copy__72->GetYaxis()->SetTitleFont(42);
   frame_46fc4e30_copy__72->GetZaxis()->SetLabelFont(42);
   frame_46fc4e30_copy__72->GetZaxis()->SetTitleOffset(1);
   frame_46fc4e30_copy__72->GetZaxis()->SetTitleFont(42);
   frame_46fc4e30_copy__72->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-40.7333,2.25,366.5997);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_46fa8bf0__73 = new TH1D("frame_46fa8bf0__73","p_T Balance",25,0,2);
   frame_46fa8bf0__73->SetBinContent(1,358.4531);
   frame_46fa8bf0__73->SetMaximum(358.4531);
   frame_46fa8bf0__73->SetEntries(1);
   frame_46fa8bf0__73->SetDirectory(0);
   frame_46fa8bf0__73->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46fa8bf0__73->SetLineColor(ci);
   frame_46fa8bf0__73->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46fa8bf0__73->GetXaxis()->SetLabelFont(42);
   frame_46fa8bf0__73->GetXaxis()->SetTitleOffset(1);
   frame_46fa8bf0__73->GetXaxis()->SetTitleFont(42);
   frame_46fa8bf0__73->GetYaxis()->SetTitle("1/Events");
   frame_46fa8bf0__73->GetYaxis()->SetLabelFont(42);
   frame_46fa8bf0__73->GetYaxis()->SetTitleFont(42);
   frame_46fa8bf0__73->GetZaxis()->SetLabelFont(42);
   frame_46fa8bf0__73->GetZaxis()->SetTitleOffset(1);
   frame_46fa8bf0__73->GetZaxis()->SetTitleFont(42);
   frame_46fa8bf0__73->Draw("FUNC");
   
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
   0,
   22.4031,
   66.77049,
   123.8919,
   175.9912,
   242.4994,
   292.4341,
   288.598,
   328.2173,
   268.5995,
   237.5462,
   195.2582,
   136.9604,
   87.92754,
   52.4739,
   38.21453,
   18.6103,
   11.03923,
   4.769652,
   5.32604,
   1.271723,
   2.08268,
   0.6646144};
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
   0,
   2.984089,
   5.390481,
   7.647603,
   9.283718,
   10.97915,
   12.03912,
   11.92824,
   13.16655,
   12.03394,
   11.29221,
   10.08978,
   8.218301,
   6.254807,
   4.556213,
   3.785749,
   2.457292,
   1.939853,
   1.134505,
   1.225565,
   0.5038301,
   0.6888728,
   0.1834897};
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
   0,
   2.984089,
   5.390481,
   7.647603,
   9.283718,
   10.97915,
   12.03912,
   11.92824,
   13.16655,
   12.03394,
   11.29221,
   10.08978,
   8.218301,
   6.254807,
   4.556213,
   3.785749,
   2.457292,
   1.939853,
   1.134505,
   1.225565,
   0.5038301,
   0.6888728,
   0.1834897};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3019,h_dh_down2_fy3019,h_dh_down2_felx3019,h_dh_down2_fehx3019,h_dh_down2_fely3019,h_dh_down2_fehy3019);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23019 = new TH1F("Graph_h_dh_down23019","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23019->SetMinimum(0);
   Graph_h_dh_down23019->SetMaximum(375.5223);
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
   
   Double_t down_fx19[58] = {
   0.1305232,
   0.1576997,
   0.1848762,
   0.2120527,
   0.2392292,
   0.2664057,
   0.2935821,
   0.3207586,
   0.3479351,
   0.3751116,
   0.4022881,
   0.4294646,
   0.4566411,
   0.4838175,
   0.510994,
   0.565347,
   0.6197,
   0.6468765,
   0.6740529,
   0.7012294,
   0.7148177,
   0.7284059,
   0.7419942,
   0.7555824,
   0.7691706,
   0.7827589,
   0.7963471,
   0.8099354,
   0.8235236,
   0.8371119,
   0.8507001,
   0.8642883,
   0.8778766,
   0.8914648,
   0.9050531,
   0.9186413,
   0.9322295,
   0.9458178,
   0.9729943,
   1.000171,
   1.027347,
   1.054524,
   1.108877,
   1.136053,
   1.16323,
   1.176818,
   1.190406,
   1.203994,
   1.217583,
   1.244759,
   1.271936,
   1.299112,
   1.326289,
   1.353465,
   1.380642,
   1.434995,
   1.489347,
   1.489347};
   Double_t down_fy19[58] = {
   6.849617,
   9.257457,
   12.36008,
   16.30252,
   21.24184,
   27.34222,
   34.76798,
   43.67462,
   54.19796,
   66.4417,
   80.46418,
   96.26503,
   113.7728,
   132.835,
   153.2112,
   196.4983,
   240.0178,
   260.4604,
   279.2184,
   295.6995,
   302.9129,
   309.3578,
   314.978,
   319.7242,
   323.554,
   326.4331,
   328.3352,
   329.2432,
   329.1487,
   328.0526,
   325.9649,
   322.9046,
   318.8993,
   313.9851,
   308.2055,
   301.6115,
   294.26,
   286.2139,
   268.3105,
   248.4784,
   227.3232,
   205.4484,
   161.7831,
   140.9628,
   121.3332,
   112.0553,
   103.4935,
   95.84535,
   88.98745,
   77.24472,
   67.61531,
   59.62813,
   52.9353,
   47.27563,
   42.45008,
   34.7199,
   28.86947,
   28.86947};
   graph = new TGraph(58,down_fx19,down_fy19);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down19 = new TH1F("Graph_down19","Projection of downf DSCB fit",100,0,1.62523);
   Graph_down19->SetMinimum(6.164655);
   Graph_down19->SetMaximum(361.4825);
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
   
   TH1D *frame_46fa8bf0__74 = new TH1D("frame_46fa8bf0__74","p_T Balance",25,0,2);
   frame_46fa8bf0__74->SetBinContent(1,358.4531);
   frame_46fa8bf0__74->SetMaximum(358.4531);
   frame_46fa8bf0__74->SetEntries(1);
   frame_46fa8bf0__74->SetDirectory(0);
   frame_46fa8bf0__74->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46fa8bf0__74->SetLineColor(ci);
   frame_46fa8bf0__74->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46fa8bf0__74->GetXaxis()->SetLabelFont(42);
   frame_46fa8bf0__74->GetXaxis()->SetTitleOffset(1);
   frame_46fa8bf0__74->GetXaxis()->SetTitleFont(42);
   frame_46fa8bf0__74->GetYaxis()->SetTitle("1/Events");
   frame_46fa8bf0__74->GetYaxis()->SetLabelFont(42);
   frame_46fa8bf0__74->GetYaxis()->SetTitleFont(42);
   frame_46fa8bf0__74->GetZaxis()->SetLabelFont(42);
   frame_46fa8bf0__74->GetZaxis()->SetTitleOffset(1);
   frame_46fa8bf0__74->GetZaxis()->SetTitleFont(42);
   frame_46fa8bf0__74->Draw("AXISSAME");
   
   TH1D *norm_d__75 = new TH1D("norm_d__75","",25,0,2);
   norm_d__75->SetBinContent(4,22.4031);
   norm_d__75->SetBinContent(5,66.77049);
   norm_d__75->SetBinContent(6,123.8919);
   norm_d__75->SetBinContent(7,175.9912);
   norm_d__75->SetBinContent(8,242.4994);
   norm_d__75->SetBinContent(9,292.4341);
   norm_d__75->SetBinContent(10,288.598);
   norm_d__75->SetBinContent(11,328.2173);
   norm_d__75->SetBinContent(12,268.5995);
   norm_d__75->SetBinContent(13,237.5462);
   norm_d__75->SetBinContent(14,195.2582);
   norm_d__75->SetBinContent(15,136.9604);
   norm_d__75->SetBinContent(16,87.92755);
   norm_d__75->SetBinContent(17,52.4739);
   norm_d__75->SetBinContent(18,38.21453);
   norm_d__75->SetBinContent(19,18.6103);
   norm_d__75->SetBinContent(20,11.03923);
   norm_d__75->SetBinContent(21,4.769652);
   norm_d__75->SetBinContent(22,5.32604);
   norm_d__75->SetBinContent(23,1.271723);
   norm_d__75->SetBinContent(24,2.082681);
   norm_d__75->SetBinContent(25,0.6646144);
   norm_d__75->SetBinContent(26,2.934362);
   norm_d__75->SetBinError(4,2.984089);
   norm_d__75->SetBinError(5,5.390481);
   norm_d__75->SetBinError(6,7.647603);
   norm_d__75->SetBinError(7,9.283718);
   norm_d__75->SetBinError(8,10.97915);
   norm_d__75->SetBinError(9,12.03912);
   norm_d__75->SetBinError(10,11.92824);
   norm_d__75->SetBinError(11,13.16655);
   norm_d__75->SetBinError(12,12.03394);
   norm_d__75->SetBinError(13,11.29221);
   norm_d__75->SetBinError(14,10.08978);
   norm_d__75->SetBinError(15,8.218301);
   norm_d__75->SetBinError(16,6.254807);
   norm_d__75->SetBinError(17,4.556213);
   norm_d__75->SetBinError(18,3.785749);
   norm_d__75->SetBinError(19,2.457292);
   norm_d__75->SetBinError(20,1.939853);
   norm_d__75->SetBinError(21,1.134505);
   norm_d__75->SetBinError(22,1.225565);
   norm_d__75->SetBinError(23,0.5038301);
   norm_d__75->SetBinError(24,0.6888728);
   norm_d__75->SetBinError(25,0.1834897);
   norm_d__75->SetBinError(26,0.4770288);
   norm_d__75->SetEntries(12121);
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
   entry=leg->AddEntry("frame_x_d2_46fa8bf0","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.827771 #pm 0.005309","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.259930 #pm 0.004245","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.411000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_46fa8bf0_copy__76 = new TH1D("frame_46fa8bf0_copy__76","p_T Balance",25,0,2);
   frame_46fa8bf0_copy__76->SetBinContent(1,358.4531);
   frame_46fa8bf0_copy__76->SetMaximum(358.4531);
   frame_46fa8bf0_copy__76->SetEntries(1);
   frame_46fa8bf0_copy__76->SetDirectory(0);
   frame_46fa8bf0_copy__76->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46fa8bf0_copy__76->SetLineColor(ci);
   frame_46fa8bf0_copy__76->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46fa8bf0_copy__76->GetXaxis()->SetLabelFont(42);
   frame_46fa8bf0_copy__76->GetXaxis()->SetTitleOffset(1);
   frame_46fa8bf0_copy__76->GetXaxis()->SetTitleFont(42);
   frame_46fa8bf0_copy__76->GetYaxis()->SetTitle("1/Events");
   frame_46fa8bf0_copy__76->GetYaxis()->SetLabelFont(42);
   frame_46fa8bf0_copy__76->GetYaxis()->SetTitleFont(42);
   frame_46fa8bf0_copy__76->GetZaxis()->SetLabelFont(42);
   frame_46fa8bf0_copy__76->GetZaxis()->SetTitleOffset(1);
   frame_46fa8bf0_copy__76->GetZaxis()->SetTitleFont(42);
   frame_46fa8bf0_copy__76->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-43.93155,2.25,395.384);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_46fc09f0__77 = new TH1D("frame_46fc09f0__77","p_T Balance",25,0,2);
   frame_46fc09f0__77->SetBinContent(1,386.5976);
   frame_46fc09f0__77->SetMaximum(386.5976);
   frame_46fc09f0__77->SetEntries(1);
   frame_46fc09f0__77->SetDirectory(0);
   frame_46fc09f0__77->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46fc09f0__77->SetLineColor(ci);
   frame_46fc09f0__77->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46fc09f0__77->GetXaxis()->SetLabelFont(42);
   frame_46fc09f0__77->GetXaxis()->SetTitleOffset(1);
   frame_46fc09f0__77->GetXaxis()->SetTitleFont(42);
   frame_46fc09f0__77->GetYaxis()->SetTitle("1/Events");
   frame_46fc09f0__77->GetYaxis()->SetLabelFont(42);
   frame_46fc09f0__77->GetYaxis()->SetTitleFont(42);
   frame_46fc09f0__77->GetZaxis()->SetLabelFont(42);
   frame_46fc09f0__77->GetZaxis()->SetTitleOffset(1);
   frame_46fc09f0__77->GetZaxis()->SetTitleFont(42);
   frame_46fc09f0__77->Draw("FUNC");
   
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
   36,
   76,
   164,
   217,
   270,
   316,
   349,
   292,
   253,
   214,
   192,
   110,
   78,
   48,
   47,
   29,
   11,
   10,
   6,
   2,
   1,
   0};
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
   5.971996,
   8.698576,
   12.31601,
   14.2394,
   15.93928,
   17.28342,
   18.18823,
   16.59532,
   15.41383,
   14.13728,
   13.36542,
   10,
   8.812788,
   6.903979,
   6.831172,
   5.353932,
   3.265579,
   3.108694,
   2.379931,
   1.291815,
   0.8272462,
   0};
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
   7.055545,
   9.756061,
   13.31601,
   15.2394,
   16.93928,
   18.28342,
   19.18823,
   17.59532,
   16.41383,
   15.13728,
   14.36542,
   11,
   9.869531,
   7.97633,
   7.904289,
   6.44702,
   4.416521,
   4.26695,
   3.583642,
   2.63786,
   2.299527,
   1.147874};
   grae = new TGraphAsymmErrors(25,h_dh_data2_fx3020,h_dh_data2_fy3020,h_dh_data2_felx3020,h_dh_data2_fehx3020,h_dh_data2_fely3020,h_dh_data2_fehy3020);
   grae->SetName("h_dh_data2");
   grae->SetTitle("Histogram of dh_data2_plot__x_o2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_data23020 = new TH1F("Graph_h_dh_data23020","Histogram of dh_data2_plot__x_o2",100,0,2.2);
   Graph_h_dh_data23020->SetMinimum(0);
   Graph_h_dh_data23020->SetMaximum(405.0071);
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
   
   Double_t observation_fx20[60] = {
   0.002270875,
   0.06116742,
   0.120064,
   0.1495122,
   0.1789605,
   0.2084088,
   0.237857,
   0.2673053,
   0.2967536,
   0.3262018,
   0.3556501,
   0.3850984,
   0.4145467,
   0.4439949,
   0.4734432,
   0.5028915,
   0.5323397,
   0.561788,
   0.5912363,
   0.6206846,
   0.6354087,
   0.6501328,
   0.664857,
   0.6795811,
   0.6943052,
   0.7090294,
   0.7237535,
   0.7384776,
   0.7532018,
   0.7679259,
   0.78265,
   0.7973742,
   0.8120983,
   0.8268224,
   0.8415466,
   0.8562707,
   0.8709949,
   0.885719,
   0.9004431,
   0.9151673,
   0.9446155,
   1.003512,
   1.018236,
   1.03296,
   1.047684,
   1.062409,
   1.077133,
   1.091857,
   1.121305,
   1.150753,
   1.180202,
   1.20965,
   1.239098,
   1.268547,
   1.297995,
   1.327443,
   1.356891,
   1.415788,
   1.474684,
   1.474684};
   Double_t observation_fy20[60] = {
   1.195566,
   2.778558,
   6.035543,
   8.672792,
   12.25361,
   17.02285,
   23.25215,
   31.2289,
   41.23946,
   53.54661,
   68.36185,
   85.81404,
   105.917,
   128.5392,
   153.3799,
   179.9551,
   207.5976,
   235.4743,
   262.6197,
   287.9877,
   299.6717,
   310.5154,
   320.3955,
   329.1965,
   336.8138,
   343.1548,
   348.1417,
   351.7124,
   353.8221,
   354.4443,
   353.571,
   351.2134,
   347.4011,
   342.1818,
   335.6204,
   327.7974,
   318.8073,
   308.757,
   297.7632,
   285.9505,
   260.392,
   205.2531,
   191.3796,
   178.3139,
   166.3444,
   155.3626,
   145.2723,
   135.988,
   119.5416,
   105.508,
   93.4746,
   83.10888,
   74.141,
   66.35075,
   59.55733,
   53.61153,
   48.38953,
   39.72092,
   32.90939,
   32.90939};
   graph = new TGraph(60,observation_fx20,observation_fy20);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation20 = new TH1F("Graph_observation20","Projection of obsf DSCB fit",100,0,1.621926);
   Graph_observation20->SetMinimum(1.07601);
   Graph_observation20->SetMaximum(389.7692);
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
   
   TH1D *frame_46fc09f0__78 = new TH1D("frame_46fc09f0__78","p_T Balance",25,0,2);
   frame_46fc09f0__78->SetBinContent(1,386.5976);
   frame_46fc09f0__78->SetMaximum(386.5976);
   frame_46fc09f0__78->SetEntries(1);
   frame_46fc09f0__78->SetDirectory(0);
   frame_46fc09f0__78->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46fc09f0__78->SetLineColor(ci);
   frame_46fc09f0__78->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46fc09f0__78->GetXaxis()->SetLabelFont(42);
   frame_46fc09f0__78->GetXaxis()->SetTitleOffset(1);
   frame_46fc09f0__78->GetXaxis()->SetTitleFont(42);
   frame_46fc09f0__78->GetYaxis()->SetTitle("1/Events");
   frame_46fc09f0__78->GetYaxis()->SetLabelFont(42);
   frame_46fc09f0__78->GetYaxis()->SetTitleFont(42);
   frame_46fc09f0__78->GetZaxis()->SetLabelFont(42);
   frame_46fc09f0__78->GetZaxis()->SetTitleOffset(1);
   frame_46fc09f0__78->GetZaxis()->SetTitleFont(42);
   frame_46fc09f0__78->Draw("AXISSAME");
   
   TH1D *norm_o__79 = new TH1D("norm_o__79","",25,0,2);
   norm_o__79->SetBinContent(4,36);
   norm_o__79->SetBinContent(5,76);
   norm_o__79->SetBinContent(6,164);
   norm_o__79->SetBinContent(7,217);
   norm_o__79->SetBinContent(8,270);
   norm_o__79->SetBinContent(9,316);
   norm_o__79->SetBinContent(10,349);
   norm_o__79->SetBinContent(11,292);
   norm_o__79->SetBinContent(12,253);
   norm_o__79->SetBinContent(13,214);
   norm_o__79->SetBinContent(14,192);
   norm_o__79->SetBinContent(15,110);
   norm_o__79->SetBinContent(16,78);
   norm_o__79->SetBinContent(17,48);
   norm_o__79->SetBinContent(18,47);
   norm_o__79->SetBinContent(19,29);
   norm_o__79->SetBinContent(20,11);
   norm_o__79->SetBinContent(21,10);
   norm_o__79->SetBinContent(22,6);
   norm_o__79->SetBinContent(23,2);
   norm_o__79->SetBinContent(24,1);
   norm_o__79->SetBinContent(26,8);
   norm_o__79->SetMinimum(0);
   norm_o__79->SetMaximum(767.8);
   norm_o__79->SetEntries(2729);
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
   entry=leg->AddEntry("frame_x_o2_46fc09f0","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.797607 #pm 0.005038","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.254619 #pm 0.003835","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.440000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_46fc09f0_copy__80 = new TH1D("frame_46fc09f0_copy__80","p_T Balance",25,0,2);
   frame_46fc09f0_copy__80->SetBinContent(1,386.5976);
   frame_46fc09f0_copy__80->SetMaximum(386.5976);
   frame_46fc09f0_copy__80->SetEntries(1);
   frame_46fc09f0_copy__80->SetDirectory(0);
   frame_46fc09f0_copy__80->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46fc09f0_copy__80->SetLineColor(ci);
   frame_46fc09f0_copy__80->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46fc09f0_copy__80->GetXaxis()->SetLabelFont(42);
   frame_46fc09f0_copy__80->GetXaxis()->SetTitleOffset(1);
   frame_46fc09f0_copy__80->GetXaxis()->SetTitleFont(42);
   frame_46fc09f0_copy__80->GetYaxis()->SetTitle("1/Events");
   frame_46fc09f0_copy__80->GetYaxis()->SetLabelFont(42);
   frame_46fc09f0_copy__80->GetYaxis()->SetTitleFont(42);
   frame_46fc09f0_copy__80->GetZaxis()->SetLabelFont(42);
   frame_46fc09f0_copy__80->GetZaxis()->SetTitleOffset(1);
   frame_46fc09f0_copy__80->GetZaxis()->SetTitleFont(42);
   frame_46fc09f0_copy__80->Draw("sameaxis");
   
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
