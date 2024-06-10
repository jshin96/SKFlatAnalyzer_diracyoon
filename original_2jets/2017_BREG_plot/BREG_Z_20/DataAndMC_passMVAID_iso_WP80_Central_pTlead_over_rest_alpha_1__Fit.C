void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_1__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 18:41:45 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-4.328622,2.25,32.58211);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_30f502b0__1 = new TH1D("frame_30f502b0__1","p_T Balance",25,0,2);
   frame_30f502b0__1->SetBinContent(1,28.89104);
   frame_30f502b0__1->SetMinimum(-1.375764);
   frame_30f502b0__1->SetMaximum(28.89104);
   frame_30f502b0__1->SetEntries(1);
   frame_30f502b0__1->SetDirectory(0);
   frame_30f502b0__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_30f502b0__1->SetLineColor(ci);
   frame_30f502b0__1->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30f502b0__1->GetXaxis()->SetLabelFont(42);
   frame_30f502b0__1->GetXaxis()->SetTitleOffset(1);
   frame_30f502b0__1->GetXaxis()->SetTitleFont(42);
   frame_30f502b0__1->GetYaxis()->SetTitle("1/Events");
   frame_30f502b0__1->GetYaxis()->SetLabelFont(42);
   frame_30f502b0__1->GetYaxis()->SetTitleFont(42);
   frame_30f502b0__1->GetZaxis()->SetLabelFont(42);
   frame_30f502b0__1->GetZaxis()->SetTitleOffset(1);
   frame_30f502b0__1->GetZaxis()->SetTitleFont(42);
   frame_30f502b0__1->Draw("FUNC");
   
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
   0.01855765,
   0.1355215,
   0.1635461,
   0.4805737,
   0.3943414,
   0.8150992,
   0.9250298,
   2.260754,
   6.983385,
   11.3321,
   21.40771,
   25.74468,
   22.21238,
   13.83856,
   4.560253,
   1.792142,
   0.7449834,
   0.5405346,
   0.2326262,
   0.04553338,
   0.00864955,
   0.01794629,
   0.01354881,
   0,
   0.01803467};
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
   0.01410353,
   0.09648965,
   0.1006993,
   0.2127881,
   0.1876602,
   0.3068595,
   0.3496617,
   0.5371335,
   0.9652409,
   1.213417,
   1.639017,
   1.770596,
   1.660522,
   1.307164,
   0.7177408,
   0.4442927,
   0.2641591,
   0.2395821,
   0.1101686,
   0.04553338,
   0.008649551,
   0.01222149,
   0.008840479,
   0,
   0.01041987};
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
   0.01410353,
   0.09648965,
   0.1006993,
   0.2127881,
   0.1876602,
   0.3068595,
   0.3496617,
   0.5371335,
   0.9652409,
   1.213417,
   1.639017,
   1.770596,
   1.660522,
   1.307164,
   0.7177408,
   0.4442927,
   0.2641591,
   0.2395821,
   0.1101686,
   0.04553338,
   0.008649551,
   0.01222149,
   0.008840479,
   0,
   0.01041987};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3001,h_dh_central2_fy3001,h_dh_central2_felx3001,h_dh_central2_fehx3001,h_dh_central2_fely3001,h_dh_central2_fehy3001);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23001 = new TH1F("Graph_h_dh_central23001","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23001->SetMinimum(-2.751527);
   Graph_h_dh_central23001->SetMaximum(30.2668);
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
   0.5773588,
   0.6046368,
   0.6319148,
   0.6455538,
   0.6591928,
   0.6728318,
   0.6864708,
   0.7001098,
   0.7137488,
   0.7273879,
   0.7342074,
   0.7410269,
   0.7546659,
   0.7683049,
   0.7955829,
   0.8092219,
   0.8228609,
   0.8364999,
   0.8501389,
   0.8637779,
   0.8705974,
   0.8774169,
   0.8842364,
   0.8910559,
   0.8978754,
   0.9046949,
   0.9115144,
   0.918334,
   0.9251535,
   0.931973,
   0.9387925,
   0.945612,
   0.9524315,
   0.959251,
   0.9660705,
   0.97289,
   0.9797095,
   0.986529,
   1.000168,
   1.013807,
   1.027446,
   1.041085,
   1.068363,
   1.095641,
   1.10928,
   1.122919,
   1.136558,
   1.150197,
   1.163836,
   1.177475,
   1.191114,
   1.204753,
   1.218392,
   1.232031,
   1.24567,
   1.259309,
   1.259309};
   Double_t Central_fy1[57] = {
   2.770832,
   3.35607,
   4.10433,
   4.556752,
   5.073275,
   5.66511,
   6.345832,
   7.131951,
   8.043674,
   9.105872,
   9.702753,
   10.34936,
   11.78192,
   13.2931,
   16.41525,
   17.96629,
   19.46568,
   20.87762,
   22.16628,
   23.29726,
   23.79365,
   24.23914,
   24.63051,
   24.9649,
   25.23981,
   25.45321,
   25.60349,
   25.6895,
   25.71061,
   25.66664,
   25.55794,
   25.38533,
   25.1501,
   24.85402,
   24.4993,
   24.08856,
   23.6248,
   23.11135,
   21.95028,
   20.63741,
   19.20748,
   17.69644,
   14.57196,
   11.52261,
   10.09178,
   8.749536,
   7.509353,
   6.379993,
   5.365846,
   4.467417,
   3.681926,
   3.003958,
   2.426124,
   1.93969,
   1.535154,
   1.20274,
   1.20274};
   TGraph *graph = new TGraph(57,Central_fx1,Central_fy1);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central1 = new TH1F("Graph_Central1","Projection of centralf DSCB fit",100,0.5091637,1.327504);
   Graph_Central1->SetMinimum(1.082466);
   Graph_Central1->SetMaximum(28.1614);
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
   
   TH1D *frame_30f502b0__2 = new TH1D("frame_30f502b0__2","p_T Balance",25,0,2);
   frame_30f502b0__2->SetBinContent(1,28.89104);
   frame_30f502b0__2->SetMinimum(-1.375764);
   frame_30f502b0__2->SetMaximum(28.89104);
   frame_30f502b0__2->SetEntries(1);
   frame_30f502b0__2->SetDirectory(0);
   frame_30f502b0__2->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30f502b0__2->SetLineColor(ci);
   frame_30f502b0__2->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30f502b0__2->GetXaxis()->SetLabelFont(42);
   frame_30f502b0__2->GetXaxis()->SetTitleOffset(1);
   frame_30f502b0__2->GetXaxis()->SetTitleFont(42);
   frame_30f502b0__2->GetYaxis()->SetTitle("1/Events");
   frame_30f502b0__2->GetYaxis()->SetLabelFont(42);
   frame_30f502b0__2->GetYaxis()->SetTitleFont(42);
   frame_30f502b0__2->GetZaxis()->SetLabelFont(42);
   frame_30f502b0__2->GetZaxis()->SetTitleOffset(1);
   frame_30f502b0__2->GetZaxis()->SetTitleFont(42);
   frame_30f502b0__2->Draw("AXISSAME");
   
   TH1D *norm_c__3 = new TH1D("norm_c__3","",25,0,2);
   norm_c__3->SetBinContent(1,0.01855765);
   norm_c__3->SetBinContent(2,0.1355215);
   norm_c__3->SetBinContent(3,0.1635461);
   norm_c__3->SetBinContent(4,0.4805737);
   norm_c__3->SetBinContent(5,0.3943414);
   norm_c__3->SetBinContent(6,0.8150992);
   norm_c__3->SetBinContent(7,0.9250298);
   norm_c__3->SetBinContent(8,2.260754);
   norm_c__3->SetBinContent(9,6.983385);
   norm_c__3->SetBinContent(10,11.3321);
   norm_c__3->SetBinContent(11,21.40772);
   norm_c__3->SetBinContent(12,25.74468);
   norm_c__3->SetBinContent(13,22.21238);
   norm_c__3->SetBinContent(14,13.83856);
   norm_c__3->SetBinContent(15,4.560253);
   norm_c__3->SetBinContent(16,1.792142);
   norm_c__3->SetBinContent(17,0.7449834);
   norm_c__3->SetBinContent(18,0.5405346);
   norm_c__3->SetBinContent(19,0.2326262);
   norm_c__3->SetBinContent(20,0.04553338);
   norm_c__3->SetBinContent(21,0.008649551);
   norm_c__3->SetBinContent(22,0.01794629);
   norm_c__3->SetBinContent(23,0.01354881);
   norm_c__3->SetBinContent(25,0.01803467);
   norm_c__3->SetBinContent(26,0.02048202);
   norm_c__3->SetBinError(1,0.01410353);
   norm_c__3->SetBinError(2,0.09648965);
   norm_c__3->SetBinError(3,0.1006993);
   norm_c__3->SetBinError(4,0.2127881);
   norm_c__3->SetBinError(5,0.1876602);
   norm_c__3->SetBinError(6,0.3068595);
   norm_c__3->SetBinError(7,0.3496617);
   norm_c__3->SetBinError(8,0.5371335);
   norm_c__3->SetBinError(9,0.9652409);
   norm_c__3->SetBinError(10,1.213417);
   norm_c__3->SetBinError(11,1.639017);
   norm_c__3->SetBinError(12,1.770596);
   norm_c__3->SetBinError(13,1.660522);
   norm_c__3->SetBinError(14,1.307164);
   norm_c__3->SetBinError(15,0.7177408);
   norm_c__3->SetBinError(16,0.4442927);
   norm_c__3->SetBinError(17,0.2641591);
   norm_c__3->SetBinError(18,0.2395821);
   norm_c__3->SetBinError(19,0.1101686);
   norm_c__3->SetBinError(20,0.04553338);
   norm_c__3->SetBinError(21,0.008649551);
   norm_c__3->SetBinError(22,0.01222149);
   norm_c__3->SetBinError(23,0.008840479);
   norm_c__3->SetBinError(25,0.01041987);
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
   entry=leg->AddEntry("frame_x_c2_30f502b0","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.920021 #pm 0.013921","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.139623 #pm 0.011303","");
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
   
   TH1D *frame_30f502b0_copy__4 = new TH1D("frame_30f502b0_copy__4","p_T Balance",25,0,2);
   frame_30f502b0_copy__4->SetBinContent(1,28.89104);
   frame_30f502b0_copy__4->SetMinimum(-1.375764);
   frame_30f502b0_copy__4->SetMaximum(28.89104);
   frame_30f502b0_copy__4->SetEntries(1);
   frame_30f502b0_copy__4->SetDirectory(0);
   frame_30f502b0_copy__4->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30f502b0_copy__4->SetLineColor(ci);
   frame_30f502b0_copy__4->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30f502b0_copy__4->GetXaxis()->SetLabelFont(42);
   frame_30f502b0_copy__4->GetXaxis()->SetTitleOffset(1);
   frame_30f502b0_copy__4->GetXaxis()->SetTitleFont(42);
   frame_30f502b0_copy__4->GetYaxis()->SetTitle("1/Events");
   frame_30f502b0_copy__4->GetYaxis()->SetLabelFont(42);
   frame_30f502b0_copy__4->GetYaxis()->SetTitleFont(42);
   frame_30f502b0_copy__4->GetZaxis()->SetLabelFont(42);
   frame_30f502b0_copy__4->GetZaxis()->SetTitleOffset(1);
   frame_30f502b0_copy__4->GetZaxis()->SetTitleFont(42);
   frame_30f502b0_copy__4->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-4.289508,2.25,32.28769);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_30f40480__5 = new TH1D("frame_30f40480__5","p_T Balance",25,0,2);
   frame_30f40480__5->SetBinContent(1,28.62997);
   frame_30f40480__5->SetMinimum(-1.363332);
   frame_30f40480__5->SetMaximum(28.62997);
   frame_30f40480__5->SetEntries(1);
   frame_30f40480__5->SetDirectory(0);
   frame_30f40480__5->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30f40480__5->SetLineColor(ci);
   frame_30f40480__5->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30f40480__5->GetXaxis()->SetLabelFont(42);
   frame_30f40480__5->GetXaxis()->SetTitleOffset(1);
   frame_30f40480__5->GetXaxis()->SetTitleFont(42);
   frame_30f40480__5->GetYaxis()->SetTitle("1/Events");
   frame_30f40480__5->GetYaxis()->SetLabelFont(42);
   frame_30f40480__5->GetYaxis()->SetTitleFont(42);
   frame_30f40480__5->GetZaxis()->SetLabelFont(42);
   frame_30f40480__5->GetZaxis()->SetTitleOffset(1);
   frame_30f40480__5->GetZaxis()->SetTitleFont(42);
   frame_30f40480__5->Draw("FUNC");
   
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
   0.01963496,
   0.3237108,
   0.3002002,
   0.1885535,
   0.7310953,
   0.7503091,
   1.335474,
   2.451653,
   7.214558,
   11.21264,
   20.47267,
   25.48752,
   22.71525,
   13.49834,
   5.620312,
   1.814852,
   0.6599922,
   0.3872403,
   0.1160028,
   0.1817605,
   0.0085961,
   0.01924257,
   0.01231453,
   0.00116488,
   0.02400186};
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
   0.01509109,
   0.1827245,
   0.1695045,
   0.09377135,
   0.3037639,
   0.2988255,
   0.4313941,
   0.5391137,
   1.038502,
   1.229963,
   1.643812,
   1.779116,
   1.676778,
   1.290054,
   0.8176119,
   0.45562,
   0.2568204,
   0.1799907,
   0.05703744,
   0.1083599,
   0.0085961,
   0.01249333,
   0.008718483,
   0.00116488,
   0.01200842};
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
   0.01509109,
   0.1827245,
   0.1695045,
   0.09377135,
   0.3037639,
   0.2988255,
   0.4313941,
   0.5391137,
   1.038502,
   1.229963,
   1.643812,
   1.779116,
   1.676778,
   1.290054,
   0.8176119,
   0.45562,
   0.2568204,
   0.1799907,
   0.05703744,
   0.1083599,
   0.0085961,
   0.01249333,
   0.008718483,
   0.00116488,
   0.01200842};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3002,h_dh_up2_fy3002,h_dh_up2_felx3002,h_dh_up2_fehx3002,h_dh_up2_fely3002,h_dh_up2_fehy3002);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23002 = new TH1F("Graph_h_dh_up23002","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23002->SetMinimum(-2.726664);
   Graph_h_dh_up23002->SetMaximum(29.9933);
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
   
   Double_t up_fx2[60] = {
   0.5862841,
   0.6135289,
   0.6271513,
   0.6407737,
   0.6543961,
   0.6680185,
   0.6816409,
   0.6952633,
   0.7088857,
   0.7225081,
   0.7361305,
   0.7429417,
   0.7497529,
   0.7633753,
   0.7769977,
   0.8042425,
   0.8178648,
   0.8314872,
   0.8451096,
   0.858732,
   0.8655432,
   0.8723544,
   0.8791656,
   0.8859768,
   0.892788,
   0.8995992,
   0.9064104,
   0.9132216,
   0.9200328,
   0.926844,
   0.9336552,
   0.9404664,
   0.9472776,
   0.9540888,
   0.9609,
   0.9677112,
   0.9745224,
   0.9813336,
   0.994956,
   1.008578,
   1.022201,
   1.035823,
   1.049446,
   1.07669,
   1.090313,
   1.103935,
   1.117558,
   1.13118,
   1.144802,
   1.158425,
   1.172047,
   1.18567,
   1.199292,
   1.206103,
   1.209509,
   1.212914,
   1.226537,
   1.240159,
   1.267404,
   1.267404};
   Double_t up_fy2[60] = {
   3.219161,
   3.861643,
   4.243042,
   4.672712,
   5.158174,
   5.70835,
   6.333874,
   7.047476,
   7.864466,
   8.803351,
   9.886621,
   10.49076,
   11.14176,
   12.59005,
   14.12136,
   17.23387,
   18.75168,
   20.19764,
   21.53595,
   22.73161,
   23.2656,
   23.75195,
   24.18716,
   24.56808,
   24.89191,
   25.15625,
   25.35914,
   25.49903,
   25.57488,
   25.58611,
   25.53264,
   25.41487,
   25.23369,
   24.99046,
   24.68701,
   24.3256,
   23.90888,
   23.4399,
   22.35892,
   21.11294,
   19.73557,
   18.26221,
   16.72861,
   13.61701,
   12.10033,
   10.64426,
   9.269076,
   7.99025,
   6.818475,
   5.759927,
   4.8167,
   3.987357,
   3.26756,
   2.946754,
   2.826248,
   2.762186,
   2.640021,
   2.579079,
   2.508177,
   2.508177};
   graph = new TGraph(60,up_fx2,up_fy2);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up2 = new TH1F("Graph_up2","Projection of upf DSCB fit",100,0.5181721,1.335516);
   Graph_up2->SetMinimum(0.2003831);
   Graph_up2->SetMaximum(27.89391);
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
   
   TH1D *frame_30f40480__6 = new TH1D("frame_30f40480__6","p_T Balance",25,0,2);
   frame_30f40480__6->SetBinContent(1,28.62997);
   frame_30f40480__6->SetMinimum(-1.363332);
   frame_30f40480__6->SetMaximum(28.62997);
   frame_30f40480__6->SetEntries(1);
   frame_30f40480__6->SetDirectory(0);
   frame_30f40480__6->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30f40480__6->SetLineColor(ci);
   frame_30f40480__6->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30f40480__6->GetXaxis()->SetLabelFont(42);
   frame_30f40480__6->GetXaxis()->SetTitleOffset(1);
   frame_30f40480__6->GetXaxis()->SetTitleFont(42);
   frame_30f40480__6->GetYaxis()->SetTitle("1/Events");
   frame_30f40480__6->GetYaxis()->SetLabelFont(42);
   frame_30f40480__6->GetYaxis()->SetTitleFont(42);
   frame_30f40480__6->GetZaxis()->SetLabelFont(42);
   frame_30f40480__6->GetZaxis()->SetTitleOffset(1);
   frame_30f40480__6->GetZaxis()->SetTitleFont(42);
   frame_30f40480__6->Draw("AXISSAME");
   
   TH1D *norm_u__7 = new TH1D("norm_u__7","",25,0,2);
   norm_u__7->SetBinContent(1,0.01963496);
   norm_u__7->SetBinContent(2,0.3237108);
   norm_u__7->SetBinContent(3,0.3002002);
   norm_u__7->SetBinContent(4,0.1885535);
   norm_u__7->SetBinContent(5,0.7310953);
   norm_u__7->SetBinContent(6,0.7503091);
   norm_u__7->SetBinContent(7,1.335474);
   norm_u__7->SetBinContent(8,2.451653);
   norm_u__7->SetBinContent(9,7.214558);
   norm_u__7->SetBinContent(10,11.21264);
   norm_u__7->SetBinContent(11,20.47267);
   norm_u__7->SetBinContent(12,25.48752);
   norm_u__7->SetBinContent(13,22.71525);
   norm_u__7->SetBinContent(14,13.49834);
   norm_u__7->SetBinContent(15,5.620312);
   norm_u__7->SetBinContent(16,1.814853);
   norm_u__7->SetBinContent(17,0.6599922);
   norm_u__7->SetBinContent(18,0.3872403);
   norm_u__7->SetBinContent(19,0.1160028);
   norm_u__7->SetBinContent(20,0.1817605);
   norm_u__7->SetBinContent(21,0.0085961);
   norm_u__7->SetBinContent(22,0.01924257);
   norm_u__7->SetBinContent(23,0.01231453);
   norm_u__7->SetBinContent(24,0.00116488);
   norm_u__7->SetBinContent(25,0.02400186);
   norm_u__7->SetBinContent(26,0.01512182);
   norm_u__7->SetBinError(1,0.01509109);
   norm_u__7->SetBinError(2,0.1827245);
   norm_u__7->SetBinError(3,0.1695045);
   norm_u__7->SetBinError(4,0.09377135);
   norm_u__7->SetBinError(5,0.3037639);
   norm_u__7->SetBinError(6,0.2988255);
   norm_u__7->SetBinError(7,0.4313941);
   norm_u__7->SetBinError(8,0.5391137);
   norm_u__7->SetBinError(9,1.038502);
   norm_u__7->SetBinError(10,1.229963);
   norm_u__7->SetBinError(11,1.643812);
   norm_u__7->SetBinError(12,1.779116);
   norm_u__7->SetBinError(13,1.676778);
   norm_u__7->SetBinError(14,1.290054);
   norm_u__7->SetBinError(15,0.8176119);
   norm_u__7->SetBinError(16,0.45562);
   norm_u__7->SetBinError(17,0.2568204);
   norm_u__7->SetBinError(18,0.1799907);
   norm_u__7->SetBinError(19,0.05703744);
   norm_u__7->SetBinError(20,0.1083599);
   norm_u__7->SetBinError(21,0.0085961);
   norm_u__7->SetBinError(22,0.01249333);
   norm_u__7->SetBinError(23,0.008718483);
   norm_u__7->SetBinError(24,0.00116488);
   norm_u__7->SetBinError(25,0.01200842);
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
   entry=leg->AddEntry("frame_x_u2_30f40480","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.934450 #pm 0.016324","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.126193 #pm 0.014880","");
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
   
   TH1D *frame_30f40480_copy__8 = new TH1D("frame_30f40480_copy__8","p_T Balance",25,0,2);
   frame_30f40480_copy__8->SetBinContent(1,28.62997);
   frame_30f40480_copy__8->SetMinimum(-1.363332);
   frame_30f40480_copy__8->SetMaximum(28.62997);
   frame_30f40480_copy__8->SetEntries(1);
   frame_30f40480_copy__8->SetDirectory(0);
   frame_30f40480_copy__8->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30f40480_copy__8->SetLineColor(ci);
   frame_30f40480_copy__8->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30f40480_copy__8->GetXaxis()->SetLabelFont(42);
   frame_30f40480_copy__8->GetXaxis()->SetTitleOffset(1);
   frame_30f40480_copy__8->GetXaxis()->SetTitleFont(42);
   frame_30f40480_copy__8->GetYaxis()->SetTitle("1/Events");
   frame_30f40480_copy__8->GetYaxis()->SetLabelFont(42);
   frame_30f40480_copy__8->GetYaxis()->SetTitleFont(42);
   frame_30f40480_copy__8->GetZaxis()->SetLabelFont(42);
   frame_30f40480_copy__8->GetZaxis()->SetTitleOffset(1);
   frame_30f40480_copy__8->GetZaxis()->SetTitleFont(42);
   frame_30f40480_copy__8->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-3.394559,2.25,30.55103);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_30f5ec50__9 = new TH1D("frame_30f5ec50__9","p_T Balance",25,0,2);
   frame_30f5ec50__9->SetBinContent(1,29.87212);
   frame_30f5ec50__9->SetMaximum(29.87212);
   frame_30f5ec50__9->SetEntries(1);
   frame_30f5ec50__9->SetDirectory(0);
   frame_30f5ec50__9->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30f5ec50__9->SetLineColor(ci);
   frame_30f5ec50__9->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30f5ec50__9->GetXaxis()->SetLabelFont(42);
   frame_30f5ec50__9->GetXaxis()->SetTitleOffset(1);
   frame_30f5ec50__9->GetXaxis()->SetTitleFont(42);
   frame_30f5ec50__9->GetYaxis()->SetTitle("1/Events");
   frame_30f5ec50__9->GetYaxis()->SetLabelFont(42);
   frame_30f5ec50__9->GetYaxis()->SetTitleFont(42);
   frame_30f5ec50__9->GetZaxis()->SetLabelFont(42);
   frame_30f5ec50__9->GetZaxis()->SetTitleOffset(1);
   frame_30f5ec50__9->GetZaxis()->SetTitleFont(42);
   frame_30f5ec50__9->Draw("FUNC");
   
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
   0.01753822,
   0.04374358,
   0.313192,
   0.1982788,
   0.3515835,
   0.8530592,
   1.363211,
   2.698716,
   7.698515,
   12.89405,
   21.5239,
   26.63906,
   21.75616,
   13.78265,
   3.636533,
   2.454674,
   0.1737483,
   0.4201988,
   0.2343439,
   0.01471805,
   0.008711135,
   0.03846692,
   0.01365085,
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
   0.01318405,
   0.03021749,
   0.1635579,
   0.0812191,
   0.1826608,
   0.2962901,
   0.4311966,
   0.5962906,
   1.021432,
   1.309752,
   1.646982,
   1.810579,
   1.648415,
   1.309034,
   0.6317992,
   0.5379361,
   0.07639235,
   0.1862623,
   0.110989,
   0.01471805,
   0.008711135,
   0.01923958,
   0.008906371,
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
   0.01318405,
   0.03021749,
   0.1635579,
   0.0812191,
   0.1826608,
   0.2962901,
   0.4311966,
   0.5962906,
   1.021432,
   1.309752,
   1.646982,
   1.810579,
   1.648415,
   1.309034,
   0.6317992,
   0.5379361,
   0.07639235,
   0.1862623,
   0.110989,
   0.01471805,
   0.008711135,
   0.01923958,
   0.008906371,
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
   Graph_h_dh_down23003->SetMinimum(3.657579e-11);
   Graph_h_dh_down23003->SetMaximum(31.2946);
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
   0.5628665,
   0.5909007,
   0.6189348,
   0.6329519,
   0.646969,
   0.6609861,
   0.6750031,
   0.6890202,
   0.7030373,
   0.7170544,
   0.7240629,
   0.7310714,
   0.7450885,
   0.7591056,
   0.7871397,
   0.8011568,
   0.8151739,
   0.829191,
   0.843208,
   0.8572251,
   0.8642336,
   0.8712422,
   0.8782507,
   0.8852593,
   0.8922678,
   0.8992763,
   0.9062849,
   0.9132934,
   0.9203019,
   0.9273105,
   0.934319,
   0.9413276,
   0.9483361,
   0.9553446,
   0.9623532,
   0.9693617,
   0.9763702,
   0.9833788,
   0.9973959,
   1.011413,
   1.02543,
   1.039447,
   1.067481,
   1.081498,
   1.095515,
   1.109532,
   1.12355,
   1.137567,
   1.151584,
   1.165601,
   1.179618,
   1.193635,
   1.207652,
   1.221669,
   1.235686,
   1.249703,
   1.26372,
   1.26372};
   Double_t down_fy3[58] = {
   2.708526,
   3.291589,
   4.040356,
   4.494675,
   5.014692,
   5.612143,
   6.301288,
   7.099545,
   8.028319,
   9.114078,
   9.725822,
   10.38977,
   11.84394,
   13.36926,
   16.51986,
   18.084,
   19.59483,
   21.01588,
   22.31067,
   23.44426,
   23.9405,
   24.38482,
   24.77397,
   25.10507,
   25.37564,
   25.58364,
   25.72749,
   25.80609,
   25.81884,
   25.76565,
   25.64692,
   25.46355,
   25.21695,
   24.90897,
   24.54193,
   24.11857,
   23.64199,
   23.11566,
   21.92906,
   20.59173,
   19.13923,
   17.60821,
   14.45352,
   12.89559,
   11.38853,
   9.955275,
   8.61386,
   7.377366,
   6.254085,
   5.247897,
   4.358788,
   3.583481,
   2.916108,
   2.348881,
   1.872739,
   1.477926,
   1.154481,
   1.154481};
   graph = new TGraph(58,down_fx3,down_fy3);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down3 = new TH1F("Graph_down3","Projection of downf DSCB fit",100,0.4927812,1.333806);
   Graph_down3->SetMinimum(1.039033);
   Graph_down3->SetMaximum(28.28528);
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
   
   TH1D *frame_30f5ec50__10 = new TH1D("frame_30f5ec50__10","p_T Balance",25,0,2);
   frame_30f5ec50__10->SetBinContent(1,29.87212);
   frame_30f5ec50__10->SetMaximum(29.87212);
   frame_30f5ec50__10->SetEntries(1);
   frame_30f5ec50__10->SetDirectory(0);
   frame_30f5ec50__10->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30f5ec50__10->SetLineColor(ci);
   frame_30f5ec50__10->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30f5ec50__10->GetXaxis()->SetLabelFont(42);
   frame_30f5ec50__10->GetXaxis()->SetTitleOffset(1);
   frame_30f5ec50__10->GetXaxis()->SetTitleFont(42);
   frame_30f5ec50__10->GetYaxis()->SetTitle("1/Events");
   frame_30f5ec50__10->GetYaxis()->SetLabelFont(42);
   frame_30f5ec50__10->GetYaxis()->SetTitleFont(42);
   frame_30f5ec50__10->GetZaxis()->SetLabelFont(42);
   frame_30f5ec50__10->GetZaxis()->SetTitleOffset(1);
   frame_30f5ec50__10->GetZaxis()->SetTitleFont(42);
   frame_30f5ec50__10->Draw("AXISSAME");
   
   TH1D *norm_d__11 = new TH1D("norm_d__11","",25,0,2);
   norm_d__11->SetBinContent(1,0.01753822);
   norm_d__11->SetBinContent(2,0.04374358);
   norm_d__11->SetBinContent(3,0.313192);
   norm_d__11->SetBinContent(4,0.1982788);
   norm_d__11->SetBinContent(5,0.3515834);
   norm_d__11->SetBinContent(6,0.8530592);
   norm_d__11->SetBinContent(7,1.363211);
   norm_d__11->SetBinContent(8,2.698716);
   norm_d__11->SetBinContent(9,7.698515);
   norm_d__11->SetBinContent(10,12.89405);
   norm_d__11->SetBinContent(11,21.5239);
   norm_d__11->SetBinContent(12,26.63906);
   norm_d__11->SetBinContent(13,21.75616);
   norm_d__11->SetBinContent(14,13.78265);
   norm_d__11->SetBinContent(15,3.636534);
   norm_d__11->SetBinContent(16,2.454674);
   norm_d__11->SetBinContent(17,0.1737483);
   norm_d__11->SetBinContent(18,0.4201988);
   norm_d__11->SetBinContent(19,0.2343439);
   norm_d__11->SetBinContent(20,0.01471805);
   norm_d__11->SetBinContent(21,0.008711135);
   norm_d__11->SetBinContent(22,0.03846691);
   norm_d__11->SetBinContent(23,0.01365085);
   norm_d__11->SetBinContent(24,0.01231077);
   norm_d__11->SetBinContent(25,0.007025328);
   norm_d__11->SetBinContent(26,0.02066669);
   norm_d__11->SetBinError(1,0.01318405);
   norm_d__11->SetBinError(2,0.03021749);
   norm_d__11->SetBinError(3,0.1635579);
   norm_d__11->SetBinError(4,0.0812191);
   norm_d__11->SetBinError(5,0.1826608);
   norm_d__11->SetBinError(6,0.2962901);
   norm_d__11->SetBinError(7,0.4311966);
   norm_d__11->SetBinError(8,0.5962906);
   norm_d__11->SetBinError(9,1.021432);
   norm_d__11->SetBinError(10,1.309752);
   norm_d__11->SetBinError(11,1.646982);
   norm_d__11->SetBinError(12,1.810579);
   norm_d__11->SetBinError(13,1.648415);
   norm_d__11->SetBinError(14,1.309034);
   norm_d__11->SetBinError(15,0.6317992);
   norm_d__11->SetBinError(16,0.5379361);
   norm_d__11->SetBinError(17,0.07639235);
   norm_d__11->SetBinError(18,0.1862623);
   norm_d__11->SetBinError(19,0.110989);
   norm_d__11->SetBinError(20,0.01471805);
   norm_d__11->SetBinError(21,0.008711135);
   norm_d__11->SetBinError(22,0.01923958);
   norm_d__11->SetBinError(23,0.008906371);
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
   entry=leg->AddEntry("frame_x_d2_30f5ec50","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.914842 #pm 0.014000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.141761 #pm 0.012583","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.991000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_30f5ec50_copy__12 = new TH1D("frame_30f5ec50_copy__12","p_T Balance",25,0,2);
   frame_30f5ec50_copy__12->SetBinContent(1,29.87212);
   frame_30f5ec50_copy__12->SetMaximum(29.87212);
   frame_30f5ec50_copy__12->SetEntries(1);
   frame_30f5ec50_copy__12->SetDirectory(0);
   frame_30f5ec50_copy__12->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30f5ec50_copy__12->SetLineColor(ci);
   frame_30f5ec50_copy__12->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30f5ec50_copy__12->GetXaxis()->SetLabelFont(42);
   frame_30f5ec50_copy__12->GetXaxis()->SetTitleOffset(1);
   frame_30f5ec50_copy__12->GetXaxis()->SetTitleFont(42);
   frame_30f5ec50_copy__12->GetYaxis()->SetTitle("1/Events");
   frame_30f5ec50_copy__12->GetYaxis()->SetLabelFont(42);
   frame_30f5ec50_copy__12->GetYaxis()->SetTitleFont(42);
   frame_30f5ec50_copy__12->GetZaxis()->SetLabelFont(42);
   frame_30f5ec50_copy__12->GetZaxis()->SetTitleOffset(1);
   frame_30f5ec50_copy__12->GetZaxis()->SetTitleFont(42);
   frame_30f5ec50_copy__12->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-5.652969,2.25,50.87672);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_30f3cda0__13 = new TH1D("frame_30f3cda0__13","p_T Balance",25,0,2);
   frame_30f3cda0__13->SetBinContent(1,49.74612);
   frame_30f3cda0__13->SetMaximum(49.74612);
   frame_30f3cda0__13->SetEntries(1);
   frame_30f3cda0__13->SetDirectory(0);
   frame_30f3cda0__13->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30f3cda0__13->SetLineColor(ci);
   frame_30f3cda0__13->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30f3cda0__13->GetXaxis()->SetLabelFont(42);
   frame_30f3cda0__13->GetXaxis()->SetTitleOffset(1);
   frame_30f3cda0__13->GetXaxis()->SetTitleFont(42);
   frame_30f3cda0__13->GetYaxis()->SetTitle("1/Events");
   frame_30f3cda0__13->GetYaxis()->SetLabelFont(42);
   frame_30f3cda0__13->GetYaxis()->SetTitleFont(42);
   frame_30f3cda0__13->GetZaxis()->SetLabelFont(42);
   frame_30f3cda0__13->GetZaxis()->SetTitleOffset(1);
   frame_30f3cda0__13->GetZaxis()->SetTitleFont(42);
   frame_30f3cda0__13->Draw("FUNC");
   
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
   3,
   1,
   0,
   0,
   1,
   2,
   9,
   20,
   36,
   40,
   34,
   17,
   13,
   3,
   1,
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
   1.632705,
   0.8272462,
   0,
   0,
   0.8272462,
   1.291815,
   2.943461,
   4.434448,
   5.971996,
   6.298,
   5.802128,
   4.082184,
   3.558662,
   1.632705,
   0.8272462,
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
   2.918186,
   2.299527,
   1.147874,
   1.147874,
   2.299527,
   2.63786,
   4.110204,
   5.546519,
   7.055545,
   7.377261,
   6.888101,
   5.203719,
   4.697573,
   2.918186,
   2.299527,
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
   Graph_h_dh_data23004->SetMaximum(52.11499);
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
   0.5599357,
   0.574558,
   0.5891803,
   0.6038026,
   0.6184249,
   0.6330472,
   0.6476695,
   0.6622918,
   0.6769141,
   0.6915364,
   0.7061587,
   0.720781,
   0.7354033,
   0.7500256,
   0.7646479,
   0.7938925,
   0.8085148,
   0.8231371,
   0.8377594,
   0.8523817,
   0.8596928,
   0.867004,
   0.8743151,
   0.8816263,
   0.8889374,
   0.8962486,
   0.9035597,
   0.9108709,
   0.918182,
   0.9254932,
   0.9328043,
   0.9401155,
   0.9474266,
   0.9547378,
   0.9620489,
   0.9693601,
   0.9766712,
   0.9839824,
   0.9986047,
   1.013227,
   1.027849,
   1.042472,
   1.057094,
   1.086338,
   1.100961,
   1.115583,
   1.130205,
   1.144828,
   1.15945,
   1.174072,
   1.188695,
   1.203317,
   1.217939,
   1.232561,
   1.247184,
   1.261806,
   1.276428,
   1.291051,
   1.291051};
   Double_t observation_fy4[59] = {
   1.371389,
   1.789116,
   2.308754,
   2.946982,
   3.720816,
   4.646863,
   5.740403,
   7.014325,
   8.477938,
   10.13574,
   11.9862,
   14.02067,
   16.22246,
   18.56631,
   21.01819,
   26.0686,
   28.56079,
   30.95163,
   33.17859,
   35.17978,
   36.07726,
   36.89684,
   37.63224,
   38.27773,
   38.82823,
   39.27933,
   39.62743,
   39.8697,
   40.00416,
   40.02973,
   39.94619,
   39.75422,
   39.4554,
   39.05214,
   38.54769,
   37.94611,
   37.25214,
   36.47124,
   34.67327,
   32.60618,
   30.32955,
   27.9057,
   25.3969,
   20.35819,
   17.93121,
   15.62216,
   13.46274,
   11.4759,
   9.676113,
   8.070046,
   6.657512,
   5.432614,
   4.38497,
   3.500945,
   2.764807,
   2.159759,
   1.668809,
   1.275466,
   1.275466};
   graph = new TGraph(59,observation_fx4,observation_fy4);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation4 = new TH1F("Graph_observation4","Projection of obsf DSCB fit",100,0.4868242,1.364162);
   Graph_observation4->SetMinimum(1.14792);
   Graph_observation4->SetMaximum(43.90516);
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
   
   TH1D *frame_30f3cda0__14 = new TH1D("frame_30f3cda0__14","p_T Balance",25,0,2);
   frame_30f3cda0__14->SetBinContent(1,49.74612);
   frame_30f3cda0__14->SetMaximum(49.74612);
   frame_30f3cda0__14->SetEntries(1);
   frame_30f3cda0__14->SetDirectory(0);
   frame_30f3cda0__14->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30f3cda0__14->SetLineColor(ci);
   frame_30f3cda0__14->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30f3cda0__14->GetXaxis()->SetLabelFont(42);
   frame_30f3cda0__14->GetXaxis()->SetTitleOffset(1);
   frame_30f3cda0__14->GetXaxis()->SetTitleFont(42);
   frame_30f3cda0__14->GetYaxis()->SetTitle("1/Events");
   frame_30f3cda0__14->GetYaxis()->SetLabelFont(42);
   frame_30f3cda0__14->GetYaxis()->SetTitleFont(42);
   frame_30f3cda0__14->GetZaxis()->SetLabelFont(42);
   frame_30f3cda0__14->GetZaxis()->SetTitleOffset(1);
   frame_30f3cda0__14->GetZaxis()->SetTitleFont(42);
   frame_30f3cda0__14->Draw("AXISSAME");
   
   TH1D *norm_o__15 = new TH1D("norm_o__15","",25,0,2);
   norm_o__15->SetBinContent(3,3);
   norm_o__15->SetBinContent(4,1);
   norm_o__15->SetBinContent(7,1);
   norm_o__15->SetBinContent(8,2);
   norm_o__15->SetBinContent(9,9);
   norm_o__15->SetBinContent(10,20);
   norm_o__15->SetBinContent(11,36);
   norm_o__15->SetBinContent(12,40);
   norm_o__15->SetBinContent(13,34);
   norm_o__15->SetBinContent(14,17);
   norm_o__15->SetBinContent(15,13);
   norm_o__15->SetBinContent(16,3);
   norm_o__15->SetBinContent(17,1);
   norm_o__15->SetBinContent(18,1);
   norm_o__15->SetMinimum(0);
   norm_o__15->SetMaximum(88);
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
   entry=leg->AddEntry("frame_x_o2_30f3cda0","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.923542 #pm 0.010998","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.139969 #pm 0.008871","");
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
   
   TH1D *frame_30f3cda0_copy__16 = new TH1D("frame_30f3cda0_copy__16","p_T Balance",25,0,2);
   frame_30f3cda0_copy__16->SetBinContent(1,49.74612);
   frame_30f3cda0_copy__16->SetMaximum(49.74612);
   frame_30f3cda0_copy__16->SetEntries(1);
   frame_30f3cda0_copy__16->SetDirectory(0);
   frame_30f3cda0_copy__16->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30f3cda0_copy__16->SetLineColor(ci);
   frame_30f3cda0_copy__16->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30f3cda0_copy__16->GetXaxis()->SetLabelFont(42);
   frame_30f3cda0_copy__16->GetXaxis()->SetTitleOffset(1);
   frame_30f3cda0_copy__16->GetXaxis()->SetTitleFont(42);
   frame_30f3cda0_copy__16->GetYaxis()->SetTitle("1/Events");
   frame_30f3cda0_copy__16->GetYaxis()->SetLabelFont(42);
   frame_30f3cda0_copy__16->GetYaxis()->SetTitleFont(42);
   frame_30f3cda0_copy__16->GetZaxis()->SetLabelFont(42);
   frame_30f3cda0_copy__16->GetZaxis()->SetTitleOffset(1);
   frame_30f3cda0_copy__16->GetZaxis()->SetTitleFont(42);
   frame_30f3cda0_copy__16->Draw("sameaxis");
   
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
