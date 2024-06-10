void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_1__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 19:33:16 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-6.632213,2.25,49.92154);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_30ed32e0__1 = new TH1D("frame_30ed32e0__1","p_T Balance",25,0,2);
   frame_30ed32e0__1->SetBinContent(1,44.26617);
   frame_30ed32e0__1->SetMinimum(-2.107913);
   frame_30ed32e0__1->SetMaximum(44.26617);
   frame_30ed32e0__1->SetEntries(1);
   frame_30ed32e0__1->SetDirectory(0);
   frame_30ed32e0__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_30ed32e0__1->SetLineColor(ci);
   frame_30ed32e0__1->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30ed32e0__1->GetXaxis()->SetLabelFont(42);
   frame_30ed32e0__1->GetXaxis()->SetTitleOffset(1);
   frame_30ed32e0__1->GetXaxis()->SetTitleFont(42);
   frame_30ed32e0__1->GetYaxis()->SetTitle("1/Events");
   frame_30ed32e0__1->GetYaxis()->SetLabelFont(42);
   frame_30ed32e0__1->GetYaxis()->SetTitleFont(42);
   frame_30ed32e0__1->GetZaxis()->SetLabelFont(42);
   frame_30ed32e0__1->GetZaxis()->SetTitleOffset(1);
   frame_30ed32e0__1->GetZaxis()->SetTitleFont(42);
   frame_30ed32e0__1->Draw("FUNC");
   
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
   0.04573063,
   0.5207778,
   1.372599,
   0.5532392,
   0.8737007,
   1.219354,
   2.84256,
   5.15957,
   12.38669,
   22.96076,
   30.82337,
   39.86324,
   34.36935,
   19.2649,
   9.436061,
   2.819198,
   1.133008,
   0.3053454,
   0.1715413,
   0.2160445,
   0,
   0.05842585,
   0.0709568,
   0.001304373,
   0.00274297};
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
   0.03937224,
   0.2248669,
   0.419225,
   0.2538341,
   0.3356817,
   0.3899838,
   0.6327285,
   0.8218875,
   1.326538,
   1.777224,
   2.024535,
   2.295016,
   2.099105,
   1.519278,
   1.116406,
   0.6040185,
   0.3673021,
   0.1171076,
   0.08166948,
   0.1550333,
   0,
   0.02550578,
   0.04750128,
   0.001304373,
   0.001952796};
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
   0.03937224,
   0.2248669,
   0.419225,
   0.2538341,
   0.3356817,
   0.3899838,
   0.6327285,
   0.8218875,
   1.326538,
   1.777224,
   2.024535,
   2.295016,
   2.099105,
   1.519278,
   1.116406,
   0.6040185,
   0.3673021,
   0.1171076,
   0.08166948,
   0.1550333,
   0,
   0.02550578,
   0.04750128,
   0.001304373,
   0.001952796};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3001,h_dh_central2_fy3001,h_dh_central2_felx3001,h_dh_central2_fehx3001,h_dh_central2_fely3001,h_dh_central2_fehy3001);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23001 = new TH1F("Graph_h_dh_central23001","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23001->SetMinimum(-4.215826);
   Graph_h_dh_central23001->SetMaximum(46.37408);
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
   0.545278,
   0.5599466,
   0.5746153,
   0.5892839,
   0.6039525,
   0.6186212,
   0.6332898,
   0.6479584,
   0.6626271,
   0.6772957,
   0.6919643,
   0.7066329,
   0.7213016,
   0.7506388,
   0.7799761,
   0.7946447,
   0.8093134,
   0.823982,
   0.8386506,
   0.8533193,
   0.8606536,
   0.8679879,
   0.8753222,
   0.8826565,
   0.8899909,
   0.8973252,
   0.9046595,
   0.9119938,
   0.9193281,
   0.9266624,
   0.9339968,
   0.9413311,
   0.9486654,
   0.9559997,
   0.963334,
   0.9706683,
   0.985337,
   1.000006,
   1.014674,
   1.029343,
   1.044012,
   1.073349,
   1.088017,
   1.102686,
   1.117355,
   1.132023,
   1.146692,
   1.161361,
   1.176029,
   1.190698,
   1.205366,
   1.220035,
   1.234704,
   1.249372,
   1.264041,
   1.27871,
   1.27871};
   Double_t Central_fy1[57] = {
   1.933329,
   2.447309,
   3.068207,
   3.809566,
   4.684479,
   5.704824,
   6.88047,
   8.218434,
   9.721986,
   11.3898,
   13.21514,
   15.18528,
   17.281,
   21.73932,
   26.30892,
   28.52489,
   30.62951,
   32.57251,
   34.30499,
   35.78149,
   36.41096,
   36.96192,
   37.43051,
   37.8134,
   38.10785,
   38.31174,
   38.4236,
   38.44262,
   38.36867,
   38.20227,
   37.94464,
   37.59763,
   37.16372,
   36.646,
   36.04814,
   35.3743,
   33.8177,
   32.01809,
   30.02214,
   27.87937,
   25.64007,
   21.06575,
   18.81907,
   16.65001,
   14.58901,
   12.65996,
   10.88012,
   9.260408,
   7.805875,
   6.516404,
   5.387527,
   4.411293,
   3.577152,
   2.87279,
   2.284891,
   1.799791,
   1.799791};
   TGraph *graph = new TGraph(57,Central_fx1,Central_fy1);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central1 = new TH1F("Graph_Central1","Projection of centralf DSCB fit",100,0.4719348,1.352053);
   Graph_Central1->SetMinimum(1.619811);
   Graph_Central1->SetMaximum(42.10691);
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
   
   TH1D *frame_30ed32e0__2 = new TH1D("frame_30ed32e0__2","p_T Balance",25,0,2);
   frame_30ed32e0__2->SetBinContent(1,44.26617);
   frame_30ed32e0__2->SetMinimum(-2.107913);
   frame_30ed32e0__2->SetMaximum(44.26617);
   frame_30ed32e0__2->SetEntries(1);
   frame_30ed32e0__2->SetDirectory(0);
   frame_30ed32e0__2->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30ed32e0__2->SetLineColor(ci);
   frame_30ed32e0__2->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30ed32e0__2->GetXaxis()->SetLabelFont(42);
   frame_30ed32e0__2->GetXaxis()->SetTitleOffset(1);
   frame_30ed32e0__2->GetXaxis()->SetTitleFont(42);
   frame_30ed32e0__2->GetYaxis()->SetTitle("1/Events");
   frame_30ed32e0__2->GetYaxis()->SetLabelFont(42);
   frame_30ed32e0__2->GetYaxis()->SetTitleFont(42);
   frame_30ed32e0__2->GetZaxis()->SetLabelFont(42);
   frame_30ed32e0__2->GetZaxis()->SetTitleOffset(1);
   frame_30ed32e0__2->GetZaxis()->SetTitleFont(42);
   frame_30ed32e0__2->Draw("AXISSAME");
   
   TH1D *norm_c__3 = new TH1D("norm_c__3","",25,0,2);
   norm_c__3->SetBinContent(1,0.04573063);
   norm_c__3->SetBinContent(2,0.5207778);
   norm_c__3->SetBinContent(3,1.372599);
   norm_c__3->SetBinContent(4,0.5532392);
   norm_c__3->SetBinContent(5,0.8737007);
   norm_c__3->SetBinContent(6,1.219354);
   norm_c__3->SetBinContent(7,2.842559);
   norm_c__3->SetBinContent(8,5.15957);
   norm_c__3->SetBinContent(9,12.38669);
   norm_c__3->SetBinContent(10,22.96076);
   norm_c__3->SetBinContent(11,30.82337);
   norm_c__3->SetBinContent(12,39.86324);
   norm_c__3->SetBinContent(13,34.36935);
   norm_c__3->SetBinContent(14,19.2649);
   norm_c__3->SetBinContent(15,9.436061);
   norm_c__3->SetBinContent(16,2.819198);
   norm_c__3->SetBinContent(17,1.133008);
   norm_c__3->SetBinContent(18,0.3053454);
   norm_c__3->SetBinContent(19,0.1715413);
   norm_c__3->SetBinContent(20,0.2160445);
   norm_c__3->SetBinContent(22,0.05842585);
   norm_c__3->SetBinContent(23,0.0709568);
   norm_c__3->SetBinContent(24,0.001304373);
   norm_c__3->SetBinContent(25,0.00274297);
   norm_c__3->SetBinContent(26,0.1363668);
   norm_c__3->SetBinError(1,0.03937224);
   norm_c__3->SetBinError(2,0.2248669);
   norm_c__3->SetBinError(3,0.419225);
   norm_c__3->SetBinError(4,0.2538341);
   norm_c__3->SetBinError(5,0.3356817);
   norm_c__3->SetBinError(6,0.3899838);
   norm_c__3->SetBinError(7,0.6327285);
   norm_c__3->SetBinError(8,0.8218875);
   norm_c__3->SetBinError(9,1.326538);
   norm_c__3->SetBinError(10,1.777224);
   norm_c__3->SetBinError(11,2.024535);
   norm_c__3->SetBinError(12,2.295016);
   norm_c__3->SetBinError(13,2.099105);
   norm_c__3->SetBinError(14,1.519278);
   norm_c__3->SetBinError(15,1.116406);
   norm_c__3->SetBinError(16,0.6040185);
   norm_c__3->SetBinError(17,0.3673021);
   norm_c__3->SetBinError(18,0.1171076);
   norm_c__3->SetBinError(19,0.08166948);
   norm_c__3->SetBinError(20,0.1550333);
   norm_c__3->SetBinError(22,0.02550578);
   norm_c__3->SetBinError(23,0.04750128);
   norm_c__3->SetBinError(24,0.001304373);
   norm_c__3->SetBinError(25,0.001952796);
   norm_c__3->SetBinError(26,0.1170732);
   norm_c__3->SetEntries(2350);
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
   entry=leg->AddEntry("frame_x_c2_30ed32e0","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.909862 #pm 0.011783","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.149036 #pm 0.009882","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.910000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_30ed32e0_copy__4 = new TH1D("frame_30ed32e0_copy__4","p_T Balance",25,0,2);
   frame_30ed32e0_copy__4->SetBinContent(1,44.26617);
   frame_30ed32e0_copy__4->SetMinimum(-2.107913);
   frame_30ed32e0_copy__4->SetMaximum(44.26617);
   frame_30ed32e0_copy__4->SetEntries(1);
   frame_30ed32e0_copy__4->SetDirectory(0);
   frame_30ed32e0_copy__4->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30ed32e0_copy__4->SetLineColor(ci);
   frame_30ed32e0_copy__4->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30ed32e0_copy__4->GetXaxis()->SetLabelFont(42);
   frame_30ed32e0_copy__4->GetXaxis()->SetTitleOffset(1);
   frame_30ed32e0_copy__4->GetXaxis()->SetTitleFont(42);
   frame_30ed32e0_copy__4->GetYaxis()->SetTitle("1/Events");
   frame_30ed32e0_copy__4->GetYaxis()->SetLabelFont(42);
   frame_30ed32e0_copy__4->GetYaxis()->SetTitleFont(42);
   frame_30ed32e0_copy__4->GetZaxis()->SetLabelFont(42);
   frame_30ed32e0_copy__4->GetZaxis()->SetTitleOffset(1);
   frame_30ed32e0_copy__4->GetZaxis()->SetTitleFont(42);
   frame_30ed32e0_copy__4->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-4.405188,2.25,50.65966);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_30eb7fd0__5 = new TH1D("frame_30eb7fd0__5","p_T Balance",25,0,2);
   frame_30eb7fd0__5->SetBinContent(1,45.15317);
   frame_30eb7fd0__5->SetMaximum(45.15317);
   frame_30eb7fd0__5->SetEntries(1);
   frame_30eb7fd0__5->SetDirectory(0);
   frame_30eb7fd0__5->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30eb7fd0__5->SetLineColor(ci);
   frame_30eb7fd0__5->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30eb7fd0__5->GetXaxis()->SetLabelFont(42);
   frame_30eb7fd0__5->GetXaxis()->SetTitleOffset(1);
   frame_30eb7fd0__5->GetXaxis()->SetTitleFont(42);
   frame_30eb7fd0__5->GetYaxis()->SetTitle("1/Events");
   frame_30eb7fd0__5->GetYaxis()->SetLabelFont(42);
   frame_30eb7fd0__5->GetYaxis()->SetTitleFont(42);
   frame_30eb7fd0__5->GetZaxis()->SetLabelFont(42);
   frame_30eb7fd0__5->GetZaxis()->SetTitleOffset(1);
   frame_30eb7fd0__5->GetZaxis()->SetTitleFont(42);
   frame_30eb7fd0__5->Draw("FUNC");
   
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
   0.04599707,
   0.837185,
   1.379492,
   0.7336914,
   1.193362,
   0.9604119,
   2.705232,
   5.149274,
   11.50684,
   19.8605,
   31.33953,
   40.69333,
   35.54922,
   20.04837,
   9.754871,
   2.702362,
   1.358565,
   0.3823539,
   0.152825,
   0.1705246,
   0.005633077,
   0.07260654,
   0.02855809,
   0.007509906,
   0.002713891};
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
   0.03957572,
   0.3122493,
   0.4303521,
   0.308504,
   0.4089487,
   0.3408945,
   0.6330043,
   0.8156326,
   1.266708,
   1.646104,
   2.041804,
   2.309697,
   2.132556,
   1.580658,
   1.103027,
   0.5959034,
   0.3999217,
   0.1891441,
   0.07241992,
   0.1473334,
   0.005633077,
   0.02903239,
   0.02455774,
   0.006349505,
   0.001931519};
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
   0.03957572,
   0.3122493,
   0.4303521,
   0.308504,
   0.4089487,
   0.3408945,
   0.6330043,
   0.8156326,
   1.266708,
   1.646104,
   2.041804,
   2.309697,
   2.132556,
   1.580658,
   1.103027,
   0.5959034,
   0.3999217,
   0.1891441,
   0.07241992,
   0.1473334,
   0.005633077,
   0.02903239,
   0.02455774,
   0.006349505,
   0.001931519};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3002,h_dh_up2_fy3002,h_dh_up2_felx3002,h_dh_up2_fehx3002,h_dh_up2_fely3002,h_dh_up2_fehy3002);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23002 = new TH1F("Graph_h_dh_up23002","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23002->SetMinimum(2.375041e-11);
   Graph_h_dh_up23002->SetMaximum(47.30332);
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
   
   Double_t up_fx2[58] = {
   0.577174,
   0.6048284,
   0.6324827,
   0.6601371,
   0.6739642,
   0.6877914,
   0.7016186,
   0.7154457,
   0.7292729,
   0.7431001,
   0.7569272,
   0.7707544,
   0.7845816,
   0.7984088,
   0.8122359,
   0.8260631,
   0.8398903,
   0.8537174,
   0.8675446,
   0.8744582,
   0.8813718,
   0.8882854,
   0.8951989,
   0.9021125,
   0.9090261,
   0.9159397,
   0.9228533,
   0.9297669,
   0.9366804,
   0.943594,
   0.9505076,
   0.9574212,
   0.9643348,
   0.9712484,
   0.978162,
   0.9850755,
   0.9919891,
   0.9989027,
   1.005816,
   1.019643,
   1.033471,
   1.047298,
   1.074952,
   1.088779,
   1.102606,
   1.116434,
   1.130261,
   1.144088,
   1.157915,
   1.171742,
   1.18557,
   1.199397,
   1.20631,
   1.213224,
   1.227051,
   1.240878,
   1.268533,
   1.268533};
   Double_t up_fy2[58] = {
   6.582222,
   7.578096,
   8.769645,
   10.20487,
   11.03266,
   11.9461,
   12.95607,
   14.07507,
   15.31753,
   16.70017,
   18.24239,
   19.96683,
   21.89993,
   24.07275,
   26.52185,
   29.14109,
   31.65604,
   33.99323,
   36.08388,
   37.0163,
   37.86335,
   38.61813,
   39.27442,
   39.82671,
   40.27035,
   40.60155,
   40.81747,
   40.91624,
   40.89701,
   40.75996,
   40.50626,
   40.13809,
   39.65862,
   39.07192,
   38.38292,
   37.59738,
   36.72175,
   35.76313,
   34.72912,
   32.46751,
   30.0047,
   27.41034,
   22.09631,
   19.49844,
   17.00845,
   14.66611,
   12.50114,
   10.53342,
   8.773531,
   7.223775,
   5.87948,
   4.730408,
   4.224719,
   3.977119,
   3.806569,
   3.720044,
   3.618716,
   3.618716};
   graph = new TGraph(58,up_fx2,up_fy2);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up2 = new TH1F("Graph_up2","Projection of upf DSCB fit",100,0.5080382,1.337668);
   Graph_up2->SetMinimum(3.256845);
   Graph_up2->SetMaximum(44.64599);
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
   
   TH1D *frame_30eb7fd0__6 = new TH1D("frame_30eb7fd0__6","p_T Balance",25,0,2);
   frame_30eb7fd0__6->SetBinContent(1,45.15317);
   frame_30eb7fd0__6->SetMaximum(45.15317);
   frame_30eb7fd0__6->SetEntries(1);
   frame_30eb7fd0__6->SetDirectory(0);
   frame_30eb7fd0__6->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30eb7fd0__6->SetLineColor(ci);
   frame_30eb7fd0__6->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30eb7fd0__6->GetXaxis()->SetLabelFont(42);
   frame_30eb7fd0__6->GetXaxis()->SetTitleOffset(1);
   frame_30eb7fd0__6->GetXaxis()->SetTitleFont(42);
   frame_30eb7fd0__6->GetYaxis()->SetTitle("1/Events");
   frame_30eb7fd0__6->GetYaxis()->SetLabelFont(42);
   frame_30eb7fd0__6->GetYaxis()->SetTitleFont(42);
   frame_30eb7fd0__6->GetZaxis()->SetLabelFont(42);
   frame_30eb7fd0__6->GetZaxis()->SetTitleOffset(1);
   frame_30eb7fd0__6->GetZaxis()->SetTitleFont(42);
   frame_30eb7fd0__6->Draw("AXISSAME");
   
   TH1D *norm_u__7 = new TH1D("norm_u__7","",25,0,2);
   norm_u__7->SetBinContent(1,0.04599707);
   norm_u__7->SetBinContent(2,0.837185);
   norm_u__7->SetBinContent(3,1.379492);
   norm_u__7->SetBinContent(4,0.7336914);
   norm_u__7->SetBinContent(5,1.193362);
   norm_u__7->SetBinContent(6,0.9604119);
   norm_u__7->SetBinContent(7,2.705232);
   norm_u__7->SetBinContent(8,5.149274);
   norm_u__7->SetBinContent(9,11.50684);
   norm_u__7->SetBinContent(10,19.8605);
   norm_u__7->SetBinContent(11,31.33953);
   norm_u__7->SetBinContent(12,40.69333);
   norm_u__7->SetBinContent(13,35.54922);
   norm_u__7->SetBinContent(14,20.04837);
   norm_u__7->SetBinContent(15,9.754871);
   norm_u__7->SetBinContent(16,2.702362);
   norm_u__7->SetBinContent(17,1.358565);
   norm_u__7->SetBinContent(18,0.3823539);
   norm_u__7->SetBinContent(19,0.152825);
   norm_u__7->SetBinContent(20,0.1705246);
   norm_u__7->SetBinContent(21,0.005633077);
   norm_u__7->SetBinContent(22,0.07260654);
   norm_u__7->SetBinContent(23,0.02855809);
   norm_u__7->SetBinContent(24,0.007509906);
   norm_u__7->SetBinContent(25,0.002713891);
   norm_u__7->SetBinContent(26,0.02086393);
   norm_u__7->SetBinError(1,0.03957572);
   norm_u__7->SetBinError(2,0.3122493);
   norm_u__7->SetBinError(3,0.4303521);
   norm_u__7->SetBinError(4,0.308504);
   norm_u__7->SetBinError(5,0.4089487);
   norm_u__7->SetBinError(6,0.3408945);
   norm_u__7->SetBinError(7,0.6330043);
   norm_u__7->SetBinError(8,0.8156326);
   norm_u__7->SetBinError(9,1.266708);
   norm_u__7->SetBinError(10,1.646104);
   norm_u__7->SetBinError(11,2.041804);
   norm_u__7->SetBinError(12,2.309697);
   norm_u__7->SetBinError(13,2.132556);
   norm_u__7->SetBinError(14,1.580658);
   norm_u__7->SetBinError(15,1.103027);
   norm_u__7->SetBinError(16,0.5959034);
   norm_u__7->SetBinError(17,0.3999217);
   norm_u__7->SetBinError(18,0.1891441);
   norm_u__7->SetBinError(19,0.07241992);
   norm_u__7->SetBinError(20,0.1473334);
   norm_u__7->SetBinError(21,0.005633077);
   norm_u__7->SetBinError(22,0.02903239);
   norm_u__7->SetBinError(23,0.02455774);
   norm_u__7->SetBinError(24,0.006349505);
   norm_u__7->SetBinError(25,0.001931519);
   norm_u__7->SetBinError(26,0.009839689);
   norm_u__7->SetEntries(2331);
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
   entry=leg->AddEntry("frame_x_u2_30eb7fd0","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.924377 #pm 0.013111","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.135038 #pm 0.012404","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.955000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_30eb7fd0_copy__8 = new TH1D("frame_30eb7fd0_copy__8","p_T Balance",25,0,2);
   frame_30eb7fd0_copy__8->SetBinContent(1,45.15317);
   frame_30eb7fd0_copy__8->SetMaximum(45.15317);
   frame_30eb7fd0_copy__8->SetEntries(1);
   frame_30eb7fd0_copy__8->SetDirectory(0);
   frame_30eb7fd0_copy__8->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30eb7fd0_copy__8->SetLineColor(ci);
   frame_30eb7fd0_copy__8->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30eb7fd0_copy__8->GetXaxis()->SetLabelFont(42);
   frame_30eb7fd0_copy__8->GetXaxis()->SetTitleOffset(1);
   frame_30eb7fd0_copy__8->GetXaxis()->SetTitleFont(42);
   frame_30eb7fd0_copy__8->GetYaxis()->SetTitle("1/Events");
   frame_30eb7fd0_copy__8->GetYaxis()->SetLabelFont(42);
   frame_30eb7fd0_copy__8->GetYaxis()->SetTitleFont(42);
   frame_30eb7fd0_copy__8->GetZaxis()->SetLabelFont(42);
   frame_30eb7fd0_copy__8->GetZaxis()->SetTitleOffset(1);
   frame_30eb7fd0_copy__8->GetZaxis()->SetTitleFont(42);
   frame_30eb7fd0_copy__8->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-4.706515,2.25,42.35864);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_30ee8960__9 = new TH1D("frame_30ee8960__9","p_T Balance",25,0,2);
   frame_30ee8960__9->SetBinContent(1,41.41733);
   frame_30ee8960__9->SetMaximum(41.41733);
   frame_30ee8960__9->SetEntries(1);
   frame_30ee8960__9->SetDirectory(0);
   frame_30ee8960__9->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30ee8960__9->SetLineColor(ci);
   frame_30ee8960__9->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30ee8960__9->GetXaxis()->SetLabelFont(42);
   frame_30ee8960__9->GetXaxis()->SetTitleOffset(1);
   frame_30ee8960__9->GetXaxis()->SetTitleFont(42);
   frame_30ee8960__9->GetYaxis()->SetTitle("1/Events");
   frame_30ee8960__9->GetYaxis()->SetLabelFont(42);
   frame_30ee8960__9->GetYaxis()->SetTitleFont(42);
   frame_30ee8960__9->GetZaxis()->SetLabelFont(42);
   frame_30ee8960__9->GetZaxis()->SetTitleOffset(1);
   frame_30ee8960__9->GetZaxis()->SetTitleFont(42);
   frame_30ee8960__9->Draw("FUNC");
   
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
   0.04534509,
   0.4756794,
   1.856302,
   0.7336146,
   0.882734,
   1.526762,
   3.828523,
   5.561957,
   12.06504,
   25.47416,
   30.8263,
   37.25235,
   31.86331,
   17.16235,
   8.278224,
   2.587356,
   0.7526142,
   0.2182192,
   0.194628,
   0.05287037,
   0.03611729,
   0.1038386,
   0.04666126,
   0.002769059,
   0.008587877};
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
   0.03903719,
   0.2175544,
   0.5039587,
   0.3015658,
   0.3450102,
   0.44783,
   0.7244283,
   0.8484283,
   1.304359,
   1.895136,
   2.030452,
   2.192735,
   2.016573,
   1.425216,
   1.031023,
   0.5607512,
   0.2597467,
   0.09653997,
   0.08366841,
   0.04465873,
   0.01850934,
   0.05756831,
   0.029213,
   0.00197159,
   0.008587877};
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
   0.03903719,
   0.2175544,
   0.5039587,
   0.3015658,
   0.3450102,
   0.44783,
   0.7244283,
   0.8484283,
   1.304359,
   1.895136,
   2.030452,
   2.192735,
   2.016573,
   1.425216,
   1.031023,
   0.5607512,
   0.2597467,
   0.09653997,
   0.08366841,
   0.04465873,
   0.01850934,
   0.05756831,
   0.029213,
   0.00197159,
   0.008587877};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3003,h_dh_down2_fy3003,h_dh_down2_felx3003,h_dh_down2_fehx3003,h_dh_down2_fely3003,h_dh_down2_fehy3003);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23003 = new TH1F("Graph_h_dh_down23003","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23003->SetMinimum(3.185554e-10);
   Graph_h_dh_down23003->SetMaximum(43.38959);
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
   
   Double_t down_fx3[57] = {
   0.5371654,
   0.5518268,
   0.5664883,
   0.5811498,
   0.5958112,
   0.6104727,
   0.6251342,
   0.6397956,
   0.6544571,
   0.6691185,
   0.68378,
   0.6984415,
   0.7131029,
   0.7424259,
   0.7717488,
   0.7864102,
   0.8010717,
   0.8157332,
   0.8303946,
   0.8450561,
   0.8523868,
   0.8597176,
   0.8670483,
   0.874379,
   0.8817097,
   0.8890405,
   0.8963712,
   0.9037019,
   0.9110327,
   0.9183634,
   0.9256941,
   0.9330249,
   0.9403556,
   0.9476863,
   0.9550171,
   0.9623478,
   0.9770092,
   0.9916707,
   1.006332,
   1.020994,
   1.035655,
   1.064978,
   1.079639,
   1.094301,
   1.108962,
   1.123624,
   1.138285,
   1.152947,
   1.167608,
   1.18227,
   1.196931,
   1.211593,
   1.226254,
   1.240916,
   1.255577,
   1.270238,
   1.270238};
   Double_t down_fy3[57] = {
   1.8875,
   2.386953,
   2.989615,
   3.708524,
   4.556184,
   5.543904,
   6.681048,
   7.974214,
   9.426392,
   11.03615,
   12.79687,
   14.69618,
   16.71551,
   21.0084,
   25.40527,
   27.53663,
   29.56052,
   31.4288,
   33.09466,
   34.51456,
   35.12004,
   35.65014,
   36.10115,
   36.46989,
   36.75373,
   36.95064,
   37.05921,
   37.07865,
   37.00882,
   36.85023,
   36.60402,
   36.27195,
   35.8564,
   35.3603,
   34.78715,
   34.14093,
   32.64744,
   30.91985,
   29.0028,
   26.94367,
   24.79066,
   20.3889,
   18.22503,
   16.13455,
   14.14686,
   12.28507,
   10.56597,
   9.000274,
   7.593052,
   6.344412,
   5.250259,
   4.30313,
   3.493032,
   2.808246,
   2.236052,
   1.763369,
   1.763369};
   graph = new TGraph(57,down_fx3,down_fy3);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down3 = new TH1F("Graph_down3","Projection of downf DSCB fit",100,0.4638581,1.343546);
   Graph_down3->SetMinimum(1.587032);
   Graph_down3->SetMaximum(40.61018);
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
   
   TH1D *frame_30ee8960__10 = new TH1D("frame_30ee8960__10","p_T Balance",25,0,2);
   frame_30ee8960__10->SetBinContent(1,41.41733);
   frame_30ee8960__10->SetMaximum(41.41733);
   frame_30ee8960__10->SetEntries(1);
   frame_30ee8960__10->SetDirectory(0);
   frame_30ee8960__10->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30ee8960__10->SetLineColor(ci);
   frame_30ee8960__10->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30ee8960__10->GetXaxis()->SetLabelFont(42);
   frame_30ee8960__10->GetXaxis()->SetTitleOffset(1);
   frame_30ee8960__10->GetXaxis()->SetTitleFont(42);
   frame_30ee8960__10->GetYaxis()->SetTitle("1/Events");
   frame_30ee8960__10->GetYaxis()->SetLabelFont(42);
   frame_30ee8960__10->GetYaxis()->SetTitleFont(42);
   frame_30ee8960__10->GetZaxis()->SetLabelFont(42);
   frame_30ee8960__10->GetZaxis()->SetTitleOffset(1);
   frame_30ee8960__10->GetZaxis()->SetTitleFont(42);
   frame_30ee8960__10->Draw("AXISSAME");
   
   TH1D *norm_d__11 = new TH1D("norm_d__11","",25,0,2);
   norm_d__11->SetBinContent(1,0.04534509);
   norm_d__11->SetBinContent(2,0.4756794);
   norm_d__11->SetBinContent(3,1.856302);
   norm_d__11->SetBinContent(4,0.7336146);
   norm_d__11->SetBinContent(5,0.882734);
   norm_d__11->SetBinContent(6,1.526762);
   norm_d__11->SetBinContent(7,3.828523);
   norm_d__11->SetBinContent(8,5.561958);
   norm_d__11->SetBinContent(9,12.06504);
   norm_d__11->SetBinContent(10,25.47416);
   norm_d__11->SetBinContent(11,30.8263);
   norm_d__11->SetBinContent(12,37.25234);
   norm_d__11->SetBinContent(13,31.86331);
   norm_d__11->SetBinContent(14,17.16235);
   norm_d__11->SetBinContent(15,8.278224);
   norm_d__11->SetBinContent(16,2.587356);
   norm_d__11->SetBinContent(17,0.7526142);
   norm_d__11->SetBinContent(18,0.2182192);
   norm_d__11->SetBinContent(19,0.194628);
   norm_d__11->SetBinContent(20,0.05287037);
   norm_d__11->SetBinContent(21,0.03611729);
   norm_d__11->SetBinContent(22,0.1038386);
   norm_d__11->SetBinContent(23,0.04666126);
   norm_d__11->SetBinContent(24,0.002769059);
   norm_d__11->SetBinContent(25,0.008587877);
   norm_d__11->SetBinContent(26,0.1355334);
   norm_d__11->SetBinError(1,0.03903719);
   norm_d__11->SetBinError(2,0.2175544);
   norm_d__11->SetBinError(3,0.5039587);
   norm_d__11->SetBinError(4,0.3015658);
   norm_d__11->SetBinError(5,0.3450102);
   norm_d__11->SetBinError(6,0.44783);
   norm_d__11->SetBinError(7,0.7244283);
   norm_d__11->SetBinError(8,0.8484283);
   norm_d__11->SetBinError(9,1.304359);
   norm_d__11->SetBinError(10,1.895136);
   norm_d__11->SetBinError(11,2.030452);
   norm_d__11->SetBinError(12,2.192735);
   norm_d__11->SetBinError(13,2.016573);
   norm_d__11->SetBinError(14,1.425216);
   norm_d__11->SetBinError(15,1.031023);
   norm_d__11->SetBinError(16,0.5607512);
   norm_d__11->SetBinError(17,0.2597467);
   norm_d__11->SetBinError(18,0.09653997);
   norm_d__11->SetBinError(19,0.08366841);
   norm_d__11->SetBinError(20,0.04465873);
   norm_d__11->SetBinError(21,0.01850934);
   norm_d__11->SetBinError(22,0.05756831);
   norm_d__11->SetBinError(23,0.029213);
   norm_d__11->SetBinError(24,0.00197159);
   norm_d__11->SetBinError(25,0.008587877);
   norm_d__11->SetBinError(26,0.1181754);
   norm_d__11->SetEntries(2358);
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
   entry=leg->AddEntry("frame_x_d2_30ee8960","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.899938 #pm 0.011732","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.147102 #pm 0.009464","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.662000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_30ee8960_copy__12 = new TH1D("frame_30ee8960_copy__12","p_T Balance",25,0,2);
   frame_30ee8960_copy__12->SetBinContent(1,41.41733);
   frame_30ee8960_copy__12->SetMaximum(41.41733);
   frame_30ee8960_copy__12->SetEntries(1);
   frame_30ee8960_copy__12->SetDirectory(0);
   frame_30ee8960_copy__12->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30ee8960_copy__12->SetLineColor(ci);
   frame_30ee8960_copy__12->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30ee8960_copy__12->GetXaxis()->SetLabelFont(42);
   frame_30ee8960_copy__12->GetXaxis()->SetTitleOffset(1);
   frame_30ee8960_copy__12->GetXaxis()->SetTitleFont(42);
   frame_30ee8960_copy__12->GetYaxis()->SetTitle("1/Events");
   frame_30ee8960_copy__12->GetYaxis()->SetLabelFont(42);
   frame_30ee8960_copy__12->GetYaxis()->SetTitleFont(42);
   frame_30ee8960_copy__12->GetZaxis()->SetLabelFont(42);
   frame_30ee8960_copy__12->GetZaxis()->SetTitleOffset(1);
   frame_30ee8960_copy__12->GetZaxis()->SetTitleFont(42);
   frame_30ee8960_copy__12->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-8.080772,2.25,72.72695);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_30eebf50__13 = new TH1D("frame_30eebf50__13","p_T Balance",25,0,2);
   frame_30eebf50__13->SetBinContent(1,71.11079);
   frame_30eebf50__13->SetMaximum(71.11079);
   frame_30eebf50__13->SetEntries(1);
   frame_30eebf50__13->SetDirectory(0);
   frame_30eebf50__13->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30eebf50__13->SetLineColor(ci);
   frame_30eebf50__13->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30eebf50__13->GetXaxis()->SetLabelFont(42);
   frame_30eebf50__13->GetXaxis()->SetTitleOffset(1);
   frame_30eebf50__13->GetXaxis()->SetTitleFont(42);
   frame_30eebf50__13->GetYaxis()->SetTitle("1/Events");
   frame_30eebf50__13->GetYaxis()->SetLabelFont(42);
   frame_30eebf50__13->GetYaxis()->SetTitleFont(42);
   frame_30eebf50__13->GetZaxis()->SetLabelFont(42);
   frame_30eebf50__13->GetZaxis()->SetTitleOffset(1);
   frame_30eebf50__13->GetZaxis()->SetTitleFont(42);
   frame_30eebf50__13->Draw("FUNC");
   
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
   1,
   2,
   1,
   2,
   6,
   11,
   13,
   38,
   52,
   59,
   46,
   29,
   13,
   3,
   2,
   3,
   0,
   0,
   0,
   0,
   0,
   0,
   1};
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
   0.8272462,
   1.291815,
   0.8272462,
   1.291815,
   2.379931,
   3.265579,
   3.558662,
   6.137163,
   7.187836,
   7.659312,
   6.757581,
   5.353932,
   3.558662,
   1.632705,
   1.291815,
   1.632705,
   0,
   0,
   0,
   0,
   0,
   0,
   0.8272462};
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
   2.299527,
   2.63786,
   2.299527,
   2.63786,
   3.583642,
   4.416521,
   4.697573,
   7.218484,
   8.257346,
   8.724565,
   7.831489,
   6.44702,
   4.697573,
   2.918186,
   2.63786,
   2.918186,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   2.299527};
   grae = new TGraphAsymmErrors(25,h_dh_data2_fx3004,h_dh_data2_fy3004,h_dh_data2_felx3004,h_dh_data2_fehx3004,h_dh_data2_fely3004,h_dh_data2_fehy3004);
   grae->SetName("h_dh_data2");
   grae->SetTitle("Histogram of dh_data2_plot__x_o2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_data23004 = new TH1F("Graph_h_dh_data23004","Histogram of dh_data2_plot__x_o2",100,0,2.2);
   Graph_h_dh_data23004->SetMinimum(0);
   Graph_h_dh_data23004->SetMaximum(74.49702);
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
   0.5280716,
   0.5588185,
   0.5741919,
   0.5895654,
   0.6049388,
   0.6203123,
   0.6356857,
   0.6510592,
   0.6587459,
   0.6664326,
   0.6818061,
   0.6971795,
   0.7125529,
   0.7279264,
   0.7432998,
   0.7740467,
   0.7894202,
   0.8047936,
   0.820167,
   0.8355405,
   0.8432272,
   0.8509139,
   0.8586007,
   0.8662874,
   0.8739741,
   0.8816608,
   0.8893475,
   0.8970343,
   0.904721,
   0.9124077,
   0.9200944,
   0.9277812,
   0.9354679,
   0.9431546,
   0.9508413,
   0.958528,
   0.9662148,
   0.9739015,
   0.9892749,
   1.004648,
   1.020022,
   1.050769,
   1.081516,
   1.096889,
   1.112262,
   1.127636,
   1.143009,
   1.158383,
   1.173756,
   1.18913,
   1.204503,
   1.219877,
   1.23525,
   1.250623,
   1.265997,
   1.28137,
   1.296744,
   1.296744};
   Double_t observation_fy4[58] = {
   3.852918,
   4.984111,
   5.70566,
   6.562638,
   7.586725,
   8.818594,
   10.31095,
   12.13278,
   13.19469,
   14.37536,
   17.11598,
   20.18709,
   23.53108,
   27.10855,
   30.86506,
   38.62584,
   42.45491,
   46.1184,
   49.51273,
   52.53587,
   53.87801,
   55.09235,
   56.1688,
   57.09828,
   57.87287,
   58.4859,
   58.93202,
   59.20735,
   59.30946,
   59.23746,
   58.99198,
   58.57518,
   57.9907,
   57.24364,
   56.34043,
   55.28879,
   54.09763,
   52.77684,
   49.79045,
   46.42427,
   42.77996,
   35.06875,
   27.42745,
   23.83212,
   20.46615,
   17.37025,
   14.57043,
   12.07911,
   9.896781,
   8.013999,
   6.413587,
   5.072815,
   3.965459,
   3.063615,
   2.339222,
   1.765245,
   1.316542,
   1.316542};
   graph = new TGraph(58,observation_fx4,observation_fy4);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation4 = new TH1F("Graph_observation4","Projection of obsf DSCB fit",100,0.4512044,1.373611);
   Graph_observation4->SetMinimum(1.184888);
   Graph_observation4->SetMaximum(65.10875);
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
   
   TH1D *frame_30eebf50__14 = new TH1D("frame_30eebf50__14","p_T Balance",25,0,2);
   frame_30eebf50__14->SetBinContent(1,71.11079);
   frame_30eebf50__14->SetMaximum(71.11079);
   frame_30eebf50__14->SetEntries(1);
   frame_30eebf50__14->SetDirectory(0);
   frame_30eebf50__14->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30eebf50__14->SetLineColor(ci);
   frame_30eebf50__14->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30eebf50__14->GetXaxis()->SetLabelFont(42);
   frame_30eebf50__14->GetXaxis()->SetTitleOffset(1);
   frame_30eebf50__14->GetXaxis()->SetTitleFont(42);
   frame_30eebf50__14->GetYaxis()->SetTitle("1/Events");
   frame_30eebf50__14->GetYaxis()->SetLabelFont(42);
   frame_30eebf50__14->GetYaxis()->SetTitleFont(42);
   frame_30eebf50__14->GetZaxis()->SetLabelFont(42);
   frame_30eebf50__14->GetZaxis()->SetTitleOffset(1);
   frame_30eebf50__14->GetZaxis()->SetTitleFont(42);
   frame_30eebf50__14->Draw("AXISSAME");
   
   TH1D *norm_o__15 = new TH1D("norm_o__15","",25,0,2);
   norm_o__15->SetBinContent(2,1);
   norm_o__15->SetBinContent(3,1);
   norm_o__15->SetBinContent(4,2);
   norm_o__15->SetBinContent(5,1);
   norm_o__15->SetBinContent(6,2);
   norm_o__15->SetBinContent(7,6);
   norm_o__15->SetBinContent(8,11);
   norm_o__15->SetBinContent(9,13);
   norm_o__15->SetBinContent(10,38);
   norm_o__15->SetBinContent(11,52);
   norm_o__15->SetBinContent(12,59);
   norm_o__15->SetBinContent(13,46);
   norm_o__15->SetBinContent(14,29);
   norm_o__15->SetBinContent(15,13);
   norm_o__15->SetBinContent(16,3);
   norm_o__15->SetBinContent(17,2);
   norm_o__15->SetBinContent(18,3);
   norm_o__15->SetBinContent(25,1);
   norm_o__15->SetMinimum(0);
   norm_o__15->SetMaximum(129.8);
   norm_o__15->SetEntries(283);
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
   entry=leg->AddEntry("frame_x_o2_30eebf50","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.902392 #pm 0.009229","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.145058 #pm 0.007383","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.978000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_30eebf50_copy__16 = new TH1D("frame_30eebf50_copy__16","p_T Balance",25,0,2);
   frame_30eebf50_copy__16->SetBinContent(1,71.11079);
   frame_30eebf50_copy__16->SetMaximum(71.11079);
   frame_30eebf50_copy__16->SetEntries(1);
   frame_30eebf50_copy__16->SetDirectory(0);
   frame_30eebf50_copy__16->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30eebf50_copy__16->SetLineColor(ci);
   frame_30eebf50_copy__16->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30eebf50_copy__16->GetXaxis()->SetLabelFont(42);
   frame_30eebf50_copy__16->GetXaxis()->SetTitleOffset(1);
   frame_30eebf50_copy__16->GetXaxis()->SetTitleFont(42);
   frame_30eebf50_copy__16->GetYaxis()->SetTitle("1/Events");
   frame_30eebf50_copy__16->GetYaxis()->SetLabelFont(42);
   frame_30eebf50_copy__16->GetYaxis()->SetTitleFont(42);
   frame_30eebf50_copy__16->GetZaxis()->SetLabelFont(42);
   frame_30eebf50_copy__16->GetZaxis()->SetTitleOffset(1);
   frame_30eebf50_copy__16->GetZaxis()->SetTitleFont(42);
   frame_30eebf50_copy__16->Draw("sameaxis");
   
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
