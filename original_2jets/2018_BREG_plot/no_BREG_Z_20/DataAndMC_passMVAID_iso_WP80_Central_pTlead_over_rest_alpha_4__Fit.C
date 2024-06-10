void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_4__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 19:14:48 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-32.01559,2.25,368.1793);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_405fc800__49 = new TH1D("frame_405fc800__49","p_T Balance",25,0,2);
   frame_405fc800__49->SetBinContent(1,328.1598);
   frame_405fc800__49->SetMaximum(328.1598);
   frame_405fc800__49->SetEntries(1);
   frame_405fc800__49->SetDirectory(0);
   frame_405fc800__49->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_405fc800__49->SetLineColor(ci);
   frame_405fc800__49->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_405fc800__49->GetXaxis()->SetLabelFont(42);
   frame_405fc800__49->GetXaxis()->SetTitleOffset(1);
   frame_405fc800__49->GetXaxis()->SetTitleFont(42);
   frame_405fc800__49->GetYaxis()->SetTitle("1/Events");
   frame_405fc800__49->GetYaxis()->SetLabelFont(42);
   frame_405fc800__49->GetYaxis()->SetTitleFont(42);
   frame_405fc800__49->GetZaxis()->SetLabelFont(42);
   frame_405fc800__49->GetZaxis()->SetTitleOffset(1);
   frame_405fc800__49->GetZaxis()->SetTitleFont(42);
   frame_405fc800__49->Draw("FUNC");
   
   Double_t h_dh_central2_fx3013[25] = {
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
   Double_t h_dh_central2_fy3013[25] = {
   0,
   0,
   10.09296,
   33.97348,
   63.87997,
   94.89487,
   145.0795,
   204.1375,
   264.7485,
   300.7262,
   284.3581,
   258.6685,
   205.7231,
   169.9332,
   107.1905,
   71.94771,
   39.27298,
   21.20856,
   13.8938,
   6.256729,
   3.172449,
   2.460447,
   1.3175,
   0.3447447,
   0.2835708};
   Double_t h_dh_central2_felx3013[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_central2_fely3013[25] = {
   0,
   0,
   2.107356,
   3.72973,
   5.342266,
   6.55434,
   8.088328,
   9.653933,
   11.08908,
   11.80695,
   11.61604,
   10.73279,
   9.556141,
   8.65165,
   6.573968,
   5.402023,
   3.750857,
   2.62307,
   2.170456,
   1.295861,
   0.8549083,
   0.6957191,
   0.4189221,
   0.116761,
   0.1192954};
   Double_t h_dh_central2_fehx3013[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_central2_fehy3013[25] = {
   0,
   0,
   2.107356,
   3.72973,
   5.342266,
   6.55434,
   8.088328,
   9.653933,
   11.08908,
   11.80695,
   11.61604,
   10.73279,
   9.556141,
   8.65165,
   6.573968,
   5.402023,
   3.750857,
   2.62307,
   2.170456,
   1.295861,
   0.8549083,
   0.6957191,
   0.4189221,
   0.116761,
   0.1192954};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3013,h_dh_central2_fy3013,h_dh_central2_felx3013,h_dh_central2_fehx3013,h_dh_central2_fely3013,h_dh_central2_fehy3013);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23013 = new TH1F("Graph_h_dh_central23013","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23013->SetMinimum(0);
   Graph_h_dh_central23013->SetMaximum(343.7865);
   Graph_h_dh_central23013->SetDirectory(0);
   Graph_h_dh_central23013->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_central23013->SetLineColor(ci);
   Graph_h_dh_central23013->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_central23013->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_central23013->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_central23013->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_central23013->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_central23013->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_central23013->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_central23013->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_central23013);
   
   grae->Draw("p");
   
   Double_t Central_fx13[59] = {
   0.1525414,
   0.178719,
   0.2048967,
   0.2310744,
   0.2572521,
   0.2834298,
   0.3096075,
   0.3357852,
   0.3619629,
   0.3881405,
   0.4143182,
   0.4404959,
   0.4666736,
   0.4928513,
   0.519029,
   0.5713843,
   0.597562,
   0.6237397,
   0.6499174,
   0.6760951,
   0.7022728,
   0.7153616,
   0.7284505,
   0.7415393,
   0.7546282,
   0.767717,
   0.7808058,
   0.7938947,
   0.8069835,
   0.8200724,
   0.8331612,
   0.8462501,
   0.8593389,
   0.8724278,
   0.8855166,
   0.8986054,
   0.9116943,
   0.9247831,
   0.937872,
   0.9640497,
   0.9902273,
   1.016405,
   1.042583,
   1.094938,
   1.121116,
   1.147293,
   1.173471,
   1.199649,
   1.225827,
   1.252004,
   1.278182,
   1.30436,
   1.330537,
   1.356715,
   1.382893,
   1.40907,
   1.435248,
   1.461426,
   1.461426};
   Double_t Central_fy13[59] = {
   9.29439,
   12.15827,
   15.73906,
   20.15313,
   25.52482,
   31.97713,
   39.62532,
   48.56938,
   58.88556,
   70.61739,
   83.76663,
   98.28493,
   114.0668,
   130.9448,
   148.6873,
   185.53,
   203.8775,
   221.6057,
   238.2588,
   253.3807,
   266.5353,
   272.2491,
   277.3272,
   281.7296,
   285.4214,
   288.3732,
   290.561,
   291.9671,
   292.58,
   292.3946,
   291.4126,
   289.6419,
   287.097,
   283.7984,
   279.7728,
   275.0522,
   269.6739,
   263.6797,
   257.1158,
   242.4796,
   226.1924,
   208.7072,
   190.4818,
   153.5519,
   135.6253,
   118.4903,
   102.3956,
   87.52588,
   74.0028,
   61.88941,
   51.19659,
   41.89115,
   33.90471,
   27.14278,
   21.4934,
   16.83498,
   13.04297,
   9.995323,
   9.995323};
   TGraph *graph = new TGraph(59,Central_fx13,Central_fy13);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central13 = new TH1F("Graph_Central13","Projection of centralf DSCB fit",100,0.02165292,1.592314);
   Graph_Central13->SetMinimum(8.364951);
   Graph_Central13->SetMaximum(320.9085);
   Graph_Central13->SetDirectory(0);
   Graph_Central13->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Central13->SetLineColor(ci);
   Graph_Central13->GetXaxis()->SetLabelFont(42);
   Graph_Central13->GetXaxis()->SetTitleOffset(1);
   Graph_Central13->GetXaxis()->SetTitleFont(42);
   Graph_Central13->GetYaxis()->SetLabelFont(42);
   Graph_Central13->GetYaxis()->SetTitleFont(42);
   Graph_Central13->GetZaxis()->SetLabelFont(42);
   Graph_Central13->GetZaxis()->SetTitleOffset(1);
   Graph_Central13->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Central13);
   
   graph->Draw("l");
   
   TH1D *frame_405fc800__50 = new TH1D("frame_405fc800__50","p_T Balance",25,0,2);
   frame_405fc800__50->SetBinContent(1,328.1598);
   frame_405fc800__50->SetMaximum(328.1598);
   frame_405fc800__50->SetEntries(1);
   frame_405fc800__50->SetDirectory(0);
   frame_405fc800__50->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_405fc800__50->SetLineColor(ci);
   frame_405fc800__50->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_405fc800__50->GetXaxis()->SetLabelFont(42);
   frame_405fc800__50->GetXaxis()->SetTitleOffset(1);
   frame_405fc800__50->GetXaxis()->SetTitleFont(42);
   frame_405fc800__50->GetYaxis()->SetTitle("1/Events");
   frame_405fc800__50->GetYaxis()->SetLabelFont(42);
   frame_405fc800__50->GetYaxis()->SetTitleFont(42);
   frame_405fc800__50->GetZaxis()->SetLabelFont(42);
   frame_405fc800__50->GetZaxis()->SetTitleOffset(1);
   frame_405fc800__50->GetZaxis()->SetTitleFont(42);
   frame_405fc800__50->Draw("AXISSAME");
   
   TH1D *norm_c__51 = new TH1D("norm_c__51","",25,0,2);
   norm_c__51->SetBinContent(3,10.09296);
   norm_c__51->SetBinContent(4,33.97348);
   norm_c__51->SetBinContent(5,63.87998);
   norm_c__51->SetBinContent(6,94.89487);
   norm_c__51->SetBinContent(7,145.0794);
   norm_c__51->SetBinContent(8,204.1374);
   norm_c__51->SetBinContent(9,264.7485);
   norm_c__51->SetBinContent(10,300.7262);
   norm_c__51->SetBinContent(11,284.3581);
   norm_c__51->SetBinContent(12,258.6685);
   norm_c__51->SetBinContent(13,205.7231);
   norm_c__51->SetBinContent(14,169.9332);
   norm_c__51->SetBinContent(15,107.1905);
   norm_c__51->SetBinContent(16,71.94771);
   norm_c__51->SetBinContent(17,39.27298);
   norm_c__51->SetBinContent(18,21.20856);
   norm_c__51->SetBinContent(19,13.8938);
   norm_c__51->SetBinContent(20,6.256729);
   norm_c__51->SetBinContent(21,3.172449);
   norm_c__51->SetBinContent(22,2.460447);
   norm_c__51->SetBinContent(23,1.3175);
   norm_c__51->SetBinContent(24,0.3447447);
   norm_c__51->SetBinContent(25,0.2835708);
   norm_c__51->SetBinContent(26,1.497063);
   norm_c__51->SetBinError(3,2.107356);
   norm_c__51->SetBinError(4,3.72973);
   norm_c__51->SetBinError(5,5.342266);
   norm_c__51->SetBinError(6,6.55434);
   norm_c__51->SetBinError(7,8.088328);
   norm_c__51->SetBinError(8,9.653933);
   norm_c__51->SetBinError(9,11.08908);
   norm_c__51->SetBinError(10,11.80695);
   norm_c__51->SetBinError(11,11.61604);
   norm_c__51->SetBinError(12,10.73279);
   norm_c__51->SetBinError(13,9.556141);
   norm_c__51->SetBinError(14,8.65165);
   norm_c__51->SetBinError(15,6.573968);
   norm_c__51->SetBinError(16,5.402023);
   norm_c__51->SetBinError(17,3.750857);
   norm_c__51->SetBinError(18,2.62307);
   norm_c__51->SetBinError(19,2.170456);
   norm_c__51->SetBinError(20,1.295861);
   norm_c__51->SetBinError(21,0.8549083);
   norm_c__51->SetBinError(22,0.6957191);
   norm_c__51->SetBinError(23,0.4189221);
   norm_c__51->SetBinError(24,0.116761);
   norm_c__51->SetBinError(25,0.1192954);
   norm_c__51->SetBinError(26,0.3437796);
   norm_c__51->SetEntries(10045);
   norm_c__51->SetStats(0);

   ci = 1335;
   color = new TColor(ci, 0.3, 0.3, 0.3, " ", 0.6);
   norm_c__51->SetFillColor(ci);
   norm_c__51->SetFillStyle(3144);
   norm_c__51->SetLineColor(2);
   norm_c__51->SetLineWidth(2);
   norm_c__51->GetXaxis()->SetRange(1,25);
   norm_c__51->GetXaxis()->SetLabelFont(42);
   norm_c__51->GetXaxis()->SetLabelSize(0.04);
   norm_c__51->GetXaxis()->SetTitleOffset(1);
   norm_c__51->GetXaxis()->SetTitleFont(42);
   norm_c__51->GetYaxis()->SetLabelFont(42);
   norm_c__51->GetYaxis()->SetTitleFont(42);
   norm_c__51->GetZaxis()->SetLabelFont(42);
   norm_c__51->GetZaxis()->SetTitleOffset(1);
   norm_c__51->GetZaxis()->SetTitleFont(42);
   norm_c__51->Draw("e1 same");
   
   TLegend *leg = new TLegend(0.65,0.5,0.93,0.87,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.03);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("norm_c","Central","lpf");

   ci = 1335;
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
   entry=leg->AddEntry("frame_x_c2_405fc800","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.810486 #pm 0.005442","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.250473 #pm 0.004359","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.985000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_405fc800_copy__52 = new TH1D("frame_405fc800_copy__52","p_T Balance",25,0,2);
   frame_405fc800_copy__52->SetBinContent(1,328.1598);
   frame_405fc800_copy__52->SetMaximum(328.1598);
   frame_405fc800_copy__52->SetEntries(1);
   frame_405fc800_copy__52->SetDirectory(0);
   frame_405fc800_copy__52->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_405fc800_copy__52->SetLineColor(ci);
   frame_405fc800_copy__52->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_405fc800_copy__52->GetXaxis()->SetLabelFont(42);
   frame_405fc800_copy__52->GetXaxis()->SetTitleOffset(1);
   frame_405fc800_copy__52->GetXaxis()->SetTitleFont(42);
   frame_405fc800_copy__52->GetYaxis()->SetTitle("1/Events");
   frame_405fc800_copy__52->GetYaxis()->SetLabelFont(42);
   frame_405fc800_copy__52->GetYaxis()->SetTitleFont(42);
   frame_405fc800_copy__52->GetZaxis()->SetLabelFont(42);
   frame_405fc800_copy__52->GetZaxis()->SetTitleOffset(1);
   frame_405fc800_copy__52->GetZaxis()->SetTitleFont(42);
   frame_405fc800_copy__52->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-33.07922,2.25,380.4111);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_40624ac0__53 = new TH1D("frame_40624ac0__53","p_T Balance",25,0,2);
   frame_40624ac0__53->SetBinContent(1,339.062);
   frame_40624ac0__53->SetMaximum(339.062);
   frame_40624ac0__53->SetEntries(1);
   frame_40624ac0__53->SetDirectory(0);
   frame_40624ac0__53->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40624ac0__53->SetLineColor(ci);
   frame_40624ac0__53->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40624ac0__53->GetXaxis()->SetLabelFont(42);
   frame_40624ac0__53->GetXaxis()->SetTitleOffset(1);
   frame_40624ac0__53->GetXaxis()->SetTitleFont(42);
   frame_40624ac0__53->GetYaxis()->SetTitle("1/Events");
   frame_40624ac0__53->GetYaxis()->SetLabelFont(42);
   frame_40624ac0__53->GetYaxis()->SetTitleFont(42);
   frame_40624ac0__53->GetZaxis()->SetLabelFont(42);
   frame_40624ac0__53->GetZaxis()->SetTitleOffset(1);
   frame_40624ac0__53->GetZaxis()->SetTitleFont(42);
   frame_40624ac0__53->Draw("FUNC");
   
   Double_t h_dh_up2_fx3014[25] = {
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
   Double_t h_dh_up2_fy3014[25] = {
   0,
   0,
   6.82326,
   31.09138,
   57.64509,
   84.36214,
   125.8401,
   187.8408,
   266.3006,
   292.5021,
   310.6301,
   281.1103,
   235.3616,
   191.1668,
   131.1479,
   73.55241,
   43.8914,
   26.83182,
   12.37088,
   7.530888,
   2.302067,
   2.359711,
   1.0404,
   0.5787216,
   0.2231152};
   Double_t h_dh_up2_felx3014[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_up2_fely3014[25] = {
   0,
   0,
   1.612631,
   3.660715,
   5.091685,
   6.255583,
   7.618388,
   9.279012,
   11.24867,
   11.66438,
   12.28609,
   11.44486,
   10.36327,
   9.35438,
   7.472449,
   5.549646,
   4.01603,
   3.000507,
   2.004683,
   1.464644,
   0.7154964,
   0.6495172,
   0.404564,
   0.2323157,
   0.106042};
   Double_t h_dh_up2_fehx3014[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_up2_fehy3014[25] = {
   0,
   0,
   1.612631,
   3.660715,
   5.091685,
   6.255583,
   7.618388,
   9.279012,
   11.24867,
   11.66438,
   12.28609,
   11.44486,
   10.36327,
   9.35438,
   7.472449,
   5.549646,
   4.01603,
   3.000507,
   2.004683,
   1.464644,
   0.7154964,
   0.6495172,
   0.404564,
   0.2323157,
   0.106042};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3014,h_dh_up2_fy3014,h_dh_up2_felx3014,h_dh_up2_fehx3014,h_dh_up2_fely3014,h_dh_up2_fehy3014);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23014 = new TH1F("Graph_h_dh_up23014","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23014->SetMinimum(0);
   Graph_h_dh_up23014->SetMaximum(355.2078);
   Graph_h_dh_up23014->SetDirectory(0);
   Graph_h_dh_up23014->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_up23014->SetLineColor(ci);
   Graph_h_dh_up23014->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_up23014->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_up23014->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_up23014->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_up23014->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_up23014->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_up23014->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_up23014->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_up23014);
   
   grae->Draw("p");
   
   Double_t up_fx14[58] = {
   0.1970697,
   0.222398,
   0.2477262,
   0.2730545,
   0.2983827,
   0.323711,
   0.3490392,
   0.3743675,
   0.3996957,
   0.425024,
   0.4503522,
   0.4756804,
   0.5010087,
   0.5263369,
   0.5516652,
   0.6023217,
   0.6276499,
   0.6529782,
   0.6783064,
   0.7036347,
   0.7289629,
   0.741627,
   0.7542912,
   0.7669553,
   0.7796194,
   0.7922835,
   0.8049477,
   0.8176118,
   0.8302759,
   0.84294,
   0.8556041,
   0.8682683,
   0.8809324,
   0.8935965,
   0.9062606,
   0.9189248,
   0.9315889,
   0.9569171,
   0.9822454,
   1.007574,
   1.032902,
   1.05823,
   1.108887,
   1.134215,
   1.159543,
   1.184871,
   1.2102,
   1.235528,
   1.260856,
   1.286184,
   1.311513,
   1.336841,
   1.362169,
   1.387497,
   1.412826,
   1.438154,
   1.463482,
   1.463482};
   Double_t up_fy14[58] = {
   12.01604,
   15.47285,
   19.71982,
   24.87481,
   31.05564,
   38.37471,
   46.93249,
   56.81017,
   68.06166,
   80.70545,
   94.71683,
   110.0209,
   126.4875,
   143.9274,
   162.0928,
   199.3313,
   217.6543,
   235.2248,
   251.607,
   266.3707,
   279.1091,
   284.6029,
   289.458,
   293.6383,
   297.1125,
   299.8542,
   301.8425,
   303.062,
   303.5034,
   303.1634,
   302.0445,
   300.1553,
   297.5103,
   294.1299,
   290.0395,
   285.2701,
   279.857,
   267.2632,
   252.6191,
   236.329,
   218.8224,
   200.5351,
   163.29,
   145.0876,
   127.5924,
   111.0563,
   95.67212,
   81.57398,
   68.84016,
   57.49843,
   47.53287,
   38.89162,
   31.49503,
   25.24363,
   20.02561,
   15.72329,
   12.2187,
   12.2187};
   graph = new TGraph(58,up_fx14,up_fy14);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up14 = new TH1F("Graph_up14","Projection of upf DSCB fit",100,0.0704285,1.590123);
   Graph_up14->SetMinimum(10.81444);
   Graph_up14->SetMaximum(332.6522);
   Graph_up14->SetDirectory(0);
   Graph_up14->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_up14->SetLineColor(ci);
   Graph_up14->GetXaxis()->SetLabelFont(42);
   Graph_up14->GetXaxis()->SetTitleOffset(1);
   Graph_up14->GetXaxis()->SetTitleFont(42);
   Graph_up14->GetYaxis()->SetLabelFont(42);
   Graph_up14->GetYaxis()->SetTitleFont(42);
   Graph_up14->GetZaxis()->SetLabelFont(42);
   Graph_up14->GetZaxis()->SetTitleOffset(1);
   Graph_up14->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_up14);
   
   graph->Draw("l");
   
   TH1D *frame_40624ac0__54 = new TH1D("frame_40624ac0__54","p_T Balance",25,0,2);
   frame_40624ac0__54->SetBinContent(1,339.062);
   frame_40624ac0__54->SetMaximum(339.062);
   frame_40624ac0__54->SetEntries(1);
   frame_40624ac0__54->SetDirectory(0);
   frame_40624ac0__54->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40624ac0__54->SetLineColor(ci);
   frame_40624ac0__54->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40624ac0__54->GetXaxis()->SetLabelFont(42);
   frame_40624ac0__54->GetXaxis()->SetTitleOffset(1);
   frame_40624ac0__54->GetXaxis()->SetTitleFont(42);
   frame_40624ac0__54->GetYaxis()->SetTitle("1/Events");
   frame_40624ac0__54->GetYaxis()->SetLabelFont(42);
   frame_40624ac0__54->GetYaxis()->SetTitleFont(42);
   frame_40624ac0__54->GetZaxis()->SetLabelFont(42);
   frame_40624ac0__54->GetZaxis()->SetTitleOffset(1);
   frame_40624ac0__54->GetZaxis()->SetTitleFont(42);
   frame_40624ac0__54->Draw("AXISSAME");
   
   TH1D *norm_u__55 = new TH1D("norm_u__55","",25,0,2);
   norm_u__55->SetBinContent(3,6.82326);
   norm_u__55->SetBinContent(4,31.09138);
   norm_u__55->SetBinContent(5,57.64509);
   norm_u__55->SetBinContent(6,84.36214);
   norm_u__55->SetBinContent(7,125.8401);
   norm_u__55->SetBinContent(8,187.8408);
   norm_u__55->SetBinContent(9,266.3006);
   norm_u__55->SetBinContent(10,292.5021);
   norm_u__55->SetBinContent(11,310.6301);
   norm_u__55->SetBinContent(12,281.1103);
   norm_u__55->SetBinContent(13,235.3616);
   norm_u__55->SetBinContent(14,191.1668);
   norm_u__55->SetBinContent(15,131.1479);
   norm_u__55->SetBinContent(16,73.55241);
   norm_u__55->SetBinContent(17,43.8914);
   norm_u__55->SetBinContent(18,26.83182);
   norm_u__55->SetBinContent(19,12.37088);
   norm_u__55->SetBinContent(20,7.530888);
   norm_u__55->SetBinContent(21,2.302066);
   norm_u__55->SetBinContent(22,2.359711);
   norm_u__55->SetBinContent(23,1.0404);
   norm_u__55->SetBinContent(24,0.5787216);
   norm_u__55->SetBinContent(25,0.2231152);
   norm_u__55->SetBinContent(26,1.667104);
   norm_u__55->SetBinError(3,1.612631);
   norm_u__55->SetBinError(4,3.660715);
   norm_u__55->SetBinError(5,5.091685);
   norm_u__55->SetBinError(6,6.255583);
   norm_u__55->SetBinError(7,7.618388);
   norm_u__55->SetBinError(8,9.279012);
   norm_u__55->SetBinError(9,11.24867);
   norm_u__55->SetBinError(10,11.66438);
   norm_u__55->SetBinError(11,12.28609);
   norm_u__55->SetBinError(12,11.44486);
   norm_u__55->SetBinError(13,10.36327);
   norm_u__55->SetBinError(14,9.35438);
   norm_u__55->SetBinError(15,7.472449);
   norm_u__55->SetBinError(16,5.549646);
   norm_u__55->SetBinError(17,4.01603);
   norm_u__55->SetBinError(18,3.000507);
   norm_u__55->SetBinError(19,2.004683);
   norm_u__55->SetBinError(20,1.464644);
   norm_u__55->SetBinError(21,0.7154964);
   norm_u__55->SetBinError(22,0.6495172);
   norm_u__55->SetBinError(23,0.404564);
   norm_u__55->SetBinError(24,0.2323157);
   norm_u__55->SetBinError(25,0.106042);
   norm_u__55->SetBinError(26,0.3686612);
   norm_u__55->SetEntries(9947);
   norm_u__55->SetStats(0);
   norm_u__55->SetLineColor(4);
   norm_u__55->SetLineWidth(2);
   norm_u__55->GetXaxis()->SetLabelFont(42);
   norm_u__55->GetXaxis()->SetTitleOffset(1);
   norm_u__55->GetXaxis()->SetTitleFont(42);
   norm_u__55->GetYaxis()->SetLabelFont(42);
   norm_u__55->GetYaxis()->SetTitleFont(42);
   norm_u__55->GetZaxis()->SetLabelFont(42);
   norm_u__55->GetZaxis()->SetTitleOffset(1);
   norm_u__55->GetZaxis()->SetTitleFont(42);
   norm_u__55->Draw("e1 same");
   
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
   entry=leg->AddEntry("frame_x_u2_40624ac0","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.831413 #pm 0.005285","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.248963 #pm 0.004111","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.988000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_40624ac0_copy__56 = new TH1D("frame_40624ac0_copy__56","p_T Balance",25,0,2);
   frame_40624ac0_copy__56->SetBinContent(1,339.062);
   frame_40624ac0_copy__56->SetMaximum(339.062);
   frame_40624ac0_copy__56->SetEntries(1);
   frame_40624ac0_copy__56->SetDirectory(0);
   frame_40624ac0_copy__56->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40624ac0_copy__56->SetLineColor(ci);
   frame_40624ac0_copy__56->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40624ac0_copy__56->GetXaxis()->SetLabelFont(42);
   frame_40624ac0_copy__56->GetXaxis()->SetTitleOffset(1);
   frame_40624ac0_copy__56->GetXaxis()->SetTitleFont(42);
   frame_40624ac0_copy__56->GetYaxis()->SetTitle("1/Events");
   frame_40624ac0_copy__56->GetYaxis()->SetLabelFont(42);
   frame_40624ac0_copy__56->GetYaxis()->SetTitleFont(42);
   frame_40624ac0_copy__56->GetZaxis()->SetLabelFont(42);
   frame_40624ac0_copy__56->GetZaxis()->SetTitleOffset(1);
   frame_40624ac0_copy__56->GetZaxis()->SetTitleFont(42);
   frame_40624ac0_copy__56->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-36.65768,2.25,329.9191);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_40624bd0__57 = new TH1D("frame_40624bd0__57","p_T Balance",25,0,2);
   frame_40624bd0__57->SetBinContent(1,322.5876);
   frame_40624bd0__57->SetMaximum(322.5876);
   frame_40624bd0__57->SetEntries(1);
   frame_40624bd0__57->SetDirectory(0);
   frame_40624bd0__57->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40624bd0__57->SetLineColor(ci);
   frame_40624bd0__57->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40624bd0__57->GetXaxis()->SetLabelFont(42);
   frame_40624bd0__57->GetXaxis()->SetTitleOffset(1);
   frame_40624bd0__57->GetXaxis()->SetTitleFont(42);
   frame_40624bd0__57->GetYaxis()->SetTitle("1/Events");
   frame_40624bd0__57->GetYaxis()->SetLabelFont(42);
   frame_40624bd0__57->GetYaxis()->SetTitleFont(42);
   frame_40624bd0__57->GetZaxis()->SetLabelFont(42);
   frame_40624bd0__57->GetZaxis()->SetTitleOffset(1);
   frame_40624bd0__57->GetZaxis()->SetTitleFont(42);
   frame_40624bd0__57->Draw("FUNC");
   
   Double_t h_dh_down2_fx3015[25] = {
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
   Double_t h_dh_down2_fy3015[25] = {
   0,
   0,
   8.806587,
   42.28962,
   70.35818,
   112.4377,
   159.2774,
   222.6812,
   265.2895,
   295.6139,
   275.2493,
   249.7703,
   185.7621,
   135.8192,
   92.21539,
   64.87997,
   31.79968,
   20.07082,
   10.85938,
   6.441949,
   2.83614,
   1.916877,
   0.9015616,
   0.2792785,
   0.2626838};
   Double_t h_dh_down2_felx3015[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_down2_fely3015[25] = {
   0,
   0,
   1.900627,
   4.045864,
   5.53807,
   7.123879,
   8.516734,
   10.17864,
   10.9461,
   11.61235,
   11.23779,
   10.58213,
   9.025189,
   7.704316,
   5.975319,
   5.093686,
   3.191891,
   2.559951,
   1.860948,
   1.330847,
   0.6456886,
   0.6351499,
   0.2998864,
   0.09718005,
   0.1211086};
   Double_t h_dh_down2_fehx3015[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_down2_fehy3015[25] = {
   0,
   0,
   1.900627,
   4.045864,
   5.53807,
   7.123879,
   8.516734,
   10.17864,
   10.9461,
   11.61235,
   11.23779,
   10.58213,
   9.025189,
   7.704316,
   5.975319,
   5.093686,
   3.191891,
   2.559951,
   1.860948,
   1.330847,
   0.6456886,
   0.6351499,
   0.2998864,
   0.09718005,
   0.1211086};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3015,h_dh_down2_fy3015,h_dh_down2_felx3015,h_dh_down2_fehx3015,h_dh_down2_fely3015,h_dh_down2_fehy3015);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23015 = new TH1F("Graph_h_dh_down23015","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23015->SetMinimum(0);
   Graph_h_dh_down23015->SetMaximum(337.9489);
   Graph_h_dh_down23015->SetDirectory(0);
   Graph_h_dh_down23015->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_down23015->SetLineColor(ci);
   Graph_h_dh_down23015->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_down23015->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_down23015->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_down23015->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_down23015->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_down23015->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_down23015->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_down23015->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_down23015);
   
   grae->Draw("p");
   
   Double_t down_fx15[57] = {
   0.1545706,
   0.1798574,
   0.2051442,
   0.2304309,
   0.2557177,
   0.2810045,
   0.3062912,
   0.331578,
   0.3568647,
   0.3821515,
   0.4074383,
   0.432725,
   0.4580118,
   0.4832986,
   0.5085853,
   0.5591589,
   0.5844456,
   0.6097324,
   0.6350192,
   0.6603059,
   0.6729493,
   0.6855927,
   0.6982361,
   0.7108795,
   0.7235228,
   0.7361662,
   0.7488096,
   0.761453,
   0.7740964,
   0.7867398,
   0.7993831,
   0.8120265,
   0.8246699,
   0.8373133,
   0.8499567,
   0.8626001,
   0.8752434,
   0.8878868,
   0.9131736,
   0.9384603,
   0.9637471,
   1.014321,
   1.064894,
   1.090181,
   1.115468,
   1.128111,
   1.140754,
   1.166041,
   1.191328,
   1.216615,
   1.241902,
   1.267188,
   1.292475,
   1.317762,
   1.368335,
   1.418909,
   1.418909};
   Double_t down_fy15[57] = {
   10.49709,
   13.66774,
   17.6029,
   22.42496,
   28.25785,
   35.22137,
   43.42433,
   52.95658,
   63.88025,
   76.22072,
   89.95791,
   105.0184,
   121.2695,
   138.5151,
   156.4958,
   193.3274,
   211.3871,
   228.6249,
   244.5841,
   258.817,
   265.1536,
   270.9051,
   276.0272,
   280.4797,
   284.2275,
   287.2404,
   289.4943,
   290.9708,
   291.6579,
   291.5501,
   290.6481,
   288.9593,
   286.4976,
   283.2827,
   279.3407,
   274.7029,
   269.4061,
   263.4913,
   249.9938,
   234.6129,
   217.7882,
   181.6264,
   144.9983,
   127.4514,
   110.8118,
   103.0949,
   96.03796,
   83.64596,
   73.18974,
   64.3175,
   56.74983,
   50.26317,
   44.67738,
   39.84643,
   31.99373,
   25.98366,
   25.98366};
   graph = new TGraph(57,down_fx15,down_fy15);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down15 = new TH1F("Graph_down15","Projection of downf DSCB fit",100,0.0281368,1.545343);
   Graph_down15->SetMinimum(9.447378);
   Graph_down15->SetMaximum(319.774);
   Graph_down15->SetDirectory(0);
   Graph_down15->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_down15->SetLineColor(ci);
   Graph_down15->GetXaxis()->SetLabelFont(42);
   Graph_down15->GetXaxis()->SetTitleOffset(1);
   Graph_down15->GetXaxis()->SetTitleFont(42);
   Graph_down15->GetYaxis()->SetLabelFont(42);
   Graph_down15->GetYaxis()->SetTitleFont(42);
   Graph_down15->GetZaxis()->SetLabelFont(42);
   Graph_down15->GetZaxis()->SetTitleOffset(1);
   Graph_down15->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_down15);
   
   graph->Draw("l");
   
   TH1D *frame_40624bd0__58 = new TH1D("frame_40624bd0__58","p_T Balance",25,0,2);
   frame_40624bd0__58->SetBinContent(1,322.5876);
   frame_40624bd0__58->SetMaximum(322.5876);
   frame_40624bd0__58->SetEntries(1);
   frame_40624bd0__58->SetDirectory(0);
   frame_40624bd0__58->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40624bd0__58->SetLineColor(ci);
   frame_40624bd0__58->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40624bd0__58->GetXaxis()->SetLabelFont(42);
   frame_40624bd0__58->GetXaxis()->SetTitleOffset(1);
   frame_40624bd0__58->GetXaxis()->SetTitleFont(42);
   frame_40624bd0__58->GetYaxis()->SetTitle("1/Events");
   frame_40624bd0__58->GetYaxis()->SetLabelFont(42);
   frame_40624bd0__58->GetYaxis()->SetTitleFont(42);
   frame_40624bd0__58->GetZaxis()->SetLabelFont(42);
   frame_40624bd0__58->GetZaxis()->SetTitleOffset(1);
   frame_40624bd0__58->GetZaxis()->SetTitleFont(42);
   frame_40624bd0__58->Draw("AXISSAME");
   
   TH1D *norm_d__59 = new TH1D("norm_d__59","",25,0,2);
   norm_d__59->SetBinContent(3,8.806588);
   norm_d__59->SetBinContent(4,42.28962);
   norm_d__59->SetBinContent(5,70.35819);
   norm_d__59->SetBinContent(6,112.4377);
   norm_d__59->SetBinContent(7,159.2774);
   norm_d__59->SetBinContent(8,222.6812);
   norm_d__59->SetBinContent(9,265.2895);
   norm_d__59->SetBinContent(10,295.6139);
   norm_d__59->SetBinContent(11,275.2493);
   norm_d__59->SetBinContent(12,249.7703);
   norm_d__59->SetBinContent(13,185.7621);
   norm_d__59->SetBinContent(14,135.8191);
   norm_d__59->SetBinContent(15,92.2154);
   norm_d__59->SetBinContent(16,64.87998);
   norm_d__59->SetBinContent(17,31.79968);
   norm_d__59->SetBinContent(18,20.07082);
   norm_d__59->SetBinContent(19,10.85938);
   norm_d__59->SetBinContent(20,6.441949);
   norm_d__59->SetBinContent(21,2.83614);
   norm_d__59->SetBinContent(22,1.916877);
   norm_d__59->SetBinContent(23,0.9015615);
   norm_d__59->SetBinContent(24,0.2792785);
   norm_d__59->SetBinContent(25,0.2626838);
   norm_d__59->SetBinContent(26,2.070913);
   norm_d__59->SetBinError(3,1.900627);
   norm_d__59->SetBinError(4,4.045864);
   norm_d__59->SetBinError(5,5.53807);
   norm_d__59->SetBinError(6,7.123879);
   norm_d__59->SetBinError(7,8.516734);
   norm_d__59->SetBinError(8,10.17864);
   norm_d__59->SetBinError(9,10.9461);
   norm_d__59->SetBinError(10,11.61235);
   norm_d__59->SetBinError(11,11.23779);
   norm_d__59->SetBinError(12,10.58213);
   norm_d__59->SetBinError(13,9.025189);
   norm_d__59->SetBinError(14,7.704316);
   norm_d__59->SetBinError(15,5.975319);
   norm_d__59->SetBinError(16,5.093686);
   norm_d__59->SetBinError(17,3.191891);
   norm_d__59->SetBinError(18,2.559951);
   norm_d__59->SetBinError(19,1.860948);
   norm_d__59->SetBinError(20,1.330847);
   norm_d__59->SetBinError(21,0.6456886);
   norm_d__59->SetBinError(22,0.6351499);
   norm_d__59->SetBinError(23,0.2998864);
   norm_d__59->SetBinError(24,0.09718005);
   norm_d__59->SetBinError(25,0.1211086);
   norm_d__59->SetBinError(26,0.4431173);
   norm_d__59->SetEntries(10152);
   norm_d__59->SetStats(0);
   norm_d__59->SetLineColor(7);
   norm_d__59->SetLineWidth(2);
   norm_d__59->GetXaxis()->SetLabelFont(42);
   norm_d__59->GetXaxis()->SetTitleOffset(1);
   norm_d__59->GetXaxis()->SetTitleFont(42);
   norm_d__59->GetYaxis()->SetLabelFont(42);
   norm_d__59->GetYaxis()->SetTitleFont(42);
   norm_d__59->GetZaxis()->SetLabelFont(42);
   norm_d__59->GetZaxis()->SetTitleOffset(1);
   norm_d__59->GetZaxis()->SetTitleFont(42);
   norm_d__59->Draw("same e1");
   
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
   entry=leg->AddEntry("frame_x_d2_40624bd0","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.782449 #pm 0.005955","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.245671 #pm 0.005246","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.971000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_40624bd0_copy__60 = new TH1D("frame_40624bd0_copy__60","p_T Balance",25,0,2);
   frame_40624bd0_copy__60->SetBinContent(1,322.5876);
   frame_40624bd0_copy__60->SetMaximum(322.5876);
   frame_40624bd0_copy__60->SetEntries(1);
   frame_40624bd0_copy__60->SetDirectory(0);
   frame_40624bd0_copy__60->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40624bd0_copy__60->SetLineColor(ci);
   frame_40624bd0_copy__60->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40624bd0_copy__60->GetXaxis()->SetLabelFont(42);
   frame_40624bd0_copy__60->GetXaxis()->SetTitleOffset(1);
   frame_40624bd0_copy__60->GetXaxis()->SetTitleFont(42);
   frame_40624bd0_copy__60->GetYaxis()->SetTitle("1/Events");
   frame_40624bd0_copy__60->GetYaxis()->SetLabelFont(42);
   frame_40624bd0_copy__60->GetYaxis()->SetTitleFont(42);
   frame_40624bd0_copy__60->GetZaxis()->SetLabelFont(42);
   frame_40624bd0_copy__60->GetZaxis()->SetTitleOffset(1);
   frame_40624bd0_copy__60->GetZaxis()->SetTitleFont(42);
   frame_40624bd0_copy__60->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-39.14996,2.25,352.3496);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_405f6420__61 = new TH1D("frame_405f6420__61","p_T Balance",25,0,2);
   frame_405f6420__61->SetBinContent(1,344.5196);
   frame_405f6420__61->SetMaximum(344.5196);
   frame_405f6420__61->SetEntries(1);
   frame_405f6420__61->SetDirectory(0);
   frame_405f6420__61->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_405f6420__61->SetLineColor(ci);
   frame_405f6420__61->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_405f6420__61->GetXaxis()->SetLabelFont(42);
   frame_405f6420__61->GetXaxis()->SetTitleOffset(1);
   frame_405f6420__61->GetXaxis()->SetTitleFont(42);
   frame_405f6420__61->GetYaxis()->SetTitle("1/Events");
   frame_405f6420__61->GetYaxis()->SetLabelFont(42);
   frame_405f6420__61->GetYaxis()->SetTitleFont(42);
   frame_405f6420__61->GetZaxis()->SetLabelFont(42);
   frame_405f6420__61->GetZaxis()->SetTitleOffset(1);
   frame_405f6420__61->GetZaxis()->SetTitleFont(42);
   frame_405f6420__61->Draw("FUNC");
   
   Double_t h_dh_data2_fx3016[25] = {
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
   Double_t h_dh_data2_fy3016[25] = {
   0,
   0,
   7,
   49,
   81,
   111,
   159,
   225,
   302,
   310,
   307,
   280,
   193,
   152,
   123,
   72,
   48,
   26,
   21,
   5,
   2,
   3,
   1,
   2,
   2};
   Double_t h_dh_data2_felx3016[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_data2_fely3016[25] = {
   0,
   0,
   2.58147,
   6.976026,
   8.981384,
   10.04751,
   12.11943,
   14.50833,
   16.88534,
   17.11391,
   17.02855,
   16.24067,
   13.40144,
   11.83896,
   10.6018,
   8.465529,
   6.903979,
   5.066015,
   4.545807,
   2.159691,
   1.291815,
   1.632705,
   0.8272462,
   1.291815,
   1.291815};
   Double_t h_dh_data2_fehx3016[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_data2_fehy3016[25] = {
   1.147874,
   1.147874,
   3.770281,
   8.047634,
   10.03706,
   11.04751,
   13.11943,
   15.50833,
   17.88534,
   18.11391,
   18.02855,
   17.24067,
   14.40144,
   12.83896,
   11.6018,
   9.524592,
   7.97633,
   6.164324,
   5.655182,
   3.382473,
   2.63786,
   2.918186,
   2.299527,
   2.63786,
   2.63786};
   grae = new TGraphAsymmErrors(25,h_dh_data2_fx3016,h_dh_data2_fy3016,h_dh_data2_felx3016,h_dh_data2_fehx3016,h_dh_data2_fely3016,h_dh_data2_fehy3016);
   grae->SetName("h_dh_data2");
   grae->SetTitle("Histogram of dh_data2_plot__x_o2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_data23016 = new TH1F("Graph_h_dh_data23016","Histogram of dh_data2_plot__x_o2",100,0,2.2);
   Graph_h_dh_data23016->SetMinimum(0);
   Graph_h_dh_data23016->SetMaximum(360.9253);
   Graph_h_dh_data23016->SetDirectory(0);
   Graph_h_dh_data23016->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_data23016->SetLineColor(ci);
   Graph_h_dh_data23016->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_data23016->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_data23016->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_data23016->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_data23016->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_data23016->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_data23016->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_data23016->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_data23016);
   
   grae->Draw("p");
   
   Double_t observation_fx16[57] = {
   0.1646649,
   0.1898756,
   0.2150863,
   0.240297,
   0.2655077,
   0.2907184,
   0.3159291,
   0.3411397,
   0.3663504,
   0.3915611,
   0.4167718,
   0.4419825,
   0.4671932,
   0.4924039,
   0.5176146,
   0.568036,
   0.5932467,
   0.6184573,
   0.643668,
   0.6688787,
   0.6814841,
   0.6940894,
   0.7066948,
   0.7193001,
   0.7319055,
   0.7445108,
   0.7571162,
   0.7697215,
   0.7823268,
   0.7949322,
   0.8075375,
   0.8201429,
   0.8327482,
   0.8453536,
   0.8579589,
   0.8705643,
   0.8831696,
   0.895775,
   0.9209856,
   0.9461963,
   0.971407,
   0.9966177,
   1.021828,
   1.07225,
   1.09746,
   1.122671,
   1.147882,
   1.173093,
   1.198303,
   1.223514,
   1.248725,
   1.273935,
   1.299146,
   1.324357,
   1.374778,
   1.425199,
   1.425199};
   Double_t observation_fy16[57] = {
   12.82593,
   16.52159,
   21.06077,
   26.56784,
   33.16635,
   40.9731,
   50.09096,
   60.60095,
   72.55362,
   85.96036,
   100.7852,
   116.9379,
   134.2681,
   152.5633,
   171.5485,
   210.2031,
   229.0627,
   247.0184,
   263.6111,
   278.3926,
   284.9719,
   290.9452,
   296.2684,
   300.9014,
   304.8092,
   307.9617,
   310.3347,
   311.9096,
   312.6743,
   312.6226,
   311.755,
   310.0784,
   307.6057,
   304.3562,
   300.3549,
   295.6326,
   290.2249,
   284.1725,
   270.3157,
   254.4603,
   237.0436,
   218.5224,
   199.3533,
   160.7891,
   142.1551,
   124.737,
   109.8013,
   97.03555,
   86.07228,
   76.61452,
   68.42084,
   61.29382,
   55.07108,
   49.61836,
   40.59516,
   33.53295,
   33.53295};
   graph = new TGraph(57,observation_fx16,observation_fy16);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation16 = new TH1F("Graph_observation16","Projection of obsf DSCB fit",100,0.03861146,1.551253);
   Graph_observation16->SetMinimum(11.54334);
   Graph_observation16->SetMaximum(342.6591);
   Graph_observation16->SetDirectory(0);
   Graph_observation16->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_observation16->SetLineColor(ci);
   Graph_observation16->GetXaxis()->SetLabelFont(42);
   Graph_observation16->GetXaxis()->SetTitleOffset(1);
   Graph_observation16->GetXaxis()->SetTitleFont(42);
   Graph_observation16->GetYaxis()->SetLabelFont(42);
   Graph_observation16->GetYaxis()->SetTitleFont(42);
   Graph_observation16->GetZaxis()->SetLabelFont(42);
   Graph_observation16->GetZaxis()->SetTitleOffset(1);
   Graph_observation16->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_observation16);
   
   graph->Draw("l");
   
   TH1D *frame_405f6420__62 = new TH1D("frame_405f6420__62","p_T Balance",25,0,2);
   frame_405f6420__62->SetBinContent(1,344.5196);
   frame_405f6420__62->SetMaximum(344.5196);
   frame_405f6420__62->SetEntries(1);
   frame_405f6420__62->SetDirectory(0);
   frame_405f6420__62->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_405f6420__62->SetLineColor(ci);
   frame_405f6420__62->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_405f6420__62->GetXaxis()->SetLabelFont(42);
   frame_405f6420__62->GetXaxis()->SetTitleOffset(1);
   frame_405f6420__62->GetXaxis()->SetTitleFont(42);
   frame_405f6420__62->GetYaxis()->SetTitle("1/Events");
   frame_405f6420__62->GetYaxis()->SetLabelFont(42);
   frame_405f6420__62->GetYaxis()->SetTitleFont(42);
   frame_405f6420__62->GetZaxis()->SetLabelFont(42);
   frame_405f6420__62->GetZaxis()->SetTitleOffset(1);
   frame_405f6420__62->GetZaxis()->SetTitleFont(42);
   frame_405f6420__62->Draw("AXISSAME");
   
   TH1D *norm_o__63 = new TH1D("norm_o__63","",25,0,2);
   norm_o__63->SetBinContent(3,7);
   norm_o__63->SetBinContent(4,49);
   norm_o__63->SetBinContent(5,81);
   norm_o__63->SetBinContent(6,111);
   norm_o__63->SetBinContent(7,159);
   norm_o__63->SetBinContent(8,225);
   norm_o__63->SetBinContent(9,302);
   norm_o__63->SetBinContent(10,310);
   norm_o__63->SetBinContent(11,307);
   norm_o__63->SetBinContent(12,280);
   norm_o__63->SetBinContent(13,193);
   norm_o__63->SetBinContent(14,152);
   norm_o__63->SetBinContent(15,123);
   norm_o__63->SetBinContent(16,72);
   norm_o__63->SetBinContent(17,48);
   norm_o__63->SetBinContent(18,26);
   norm_o__63->SetBinContent(19,21);
   norm_o__63->SetBinContent(20,5);
   norm_o__63->SetBinContent(21,2);
   norm_o__63->SetBinContent(22,3);
   norm_o__63->SetBinContent(23,1);
   norm_o__63->SetBinContent(24,2);
   norm_o__63->SetBinContent(25,2);
   norm_o__63->SetBinContent(26,1);
   norm_o__63->SetMinimum(0);
   norm_o__63->SetMaximum(682);
   norm_o__63->SetEntries(2482);
   norm_o__63->SetStats(0);
   norm_o__63->SetLineWidth(2);
   norm_o__63->SetMarkerStyle(8);
   norm_o__63->SetMarkerSize(0.4);
   norm_o__63->GetXaxis()->SetRange(1,25);
   norm_o__63->GetXaxis()->SetLabelFont(42);
   norm_o__63->GetXaxis()->SetLabelSize(0.04);
   norm_o__63->GetXaxis()->SetTitleOffset(1);
   norm_o__63->GetXaxis()->SetTitleFont(42);
   norm_o__63->GetYaxis()->SetTitle("Events");
   norm_o__63->GetYaxis()->SetLabelFont(42);
   norm_o__63->GetYaxis()->SetTitleOffset(1.4);
   norm_o__63->GetYaxis()->SetTitleFont(42);
   norm_o__63->GetZaxis()->SetLabelFont(42);
   norm_o__63->GetZaxis()->SetTitleOffset(1);
   norm_o__63->GetZaxis()->SetTitleFont(42);
   norm_o__63->Draw("same e1");
   
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
   entry=leg->AddEntry("frame_x_o2_405f6420","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.787823 #pm 0.005665","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.246551 #pm 0.004930","");
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
   
   TH1D *frame_405f6420_copy__64 = new TH1D("frame_405f6420_copy__64","p_T Balance",25,0,2);
   frame_405f6420_copy__64->SetBinContent(1,344.5196);
   frame_405f6420_copy__64->SetMaximum(344.5196);
   frame_405f6420_copy__64->SetEntries(1);
   frame_405f6420_copy__64->SetDirectory(0);
   frame_405f6420_copy__64->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_405f6420_copy__64->SetLineColor(ci);
   frame_405f6420_copy__64->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_405f6420_copy__64->GetXaxis()->SetLabelFont(42);
   frame_405f6420_copy__64->GetXaxis()->SetTitleOffset(1);
   frame_405f6420_copy__64->GetXaxis()->SetTitleFont(42);
   frame_405f6420_copy__64->GetYaxis()->SetTitle("1/Events");
   frame_405f6420_copy__64->GetYaxis()->SetLabelFont(42);
   frame_405f6420_copy__64->GetYaxis()->SetTitleFont(42);
   frame_405f6420_copy__64->GetZaxis()->SetLabelFont(42);
   frame_405f6420_copy__64->GetZaxis()->SetTitleOffset(1);
   frame_405f6420_copy__64->GetZaxis()->SetTitleFont(42);
   frame_405f6420_copy__64->Draw("sameaxis");
   
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
