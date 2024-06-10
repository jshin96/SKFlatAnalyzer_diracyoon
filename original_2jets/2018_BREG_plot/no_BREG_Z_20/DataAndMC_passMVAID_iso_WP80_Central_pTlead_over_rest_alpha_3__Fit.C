void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_3__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 19:12:21 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-16.51363,2.25,189.9067);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3ad6f0f0__33 = new TH1D("frame_3ad6f0f0__33","p_T Balance",25,0,2);
   frame_3ad6f0f0__33->SetBinContent(1,169.2647);
   frame_3ad6f0f0__33->SetMaximum(169.2647);
   frame_3ad6f0f0__33->SetEntries(1);
   frame_3ad6f0f0__33->SetDirectory(0);
   frame_3ad6f0f0__33->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_3ad6f0f0__33->SetLineColor(ci);
   frame_3ad6f0f0__33->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ad6f0f0__33->GetXaxis()->SetLabelFont(42);
   frame_3ad6f0f0__33->GetXaxis()->SetTitleOffset(1);
   frame_3ad6f0f0__33->GetXaxis()->SetTitleFont(42);
   frame_3ad6f0f0__33->GetYaxis()->SetTitle("1/Events");
   frame_3ad6f0f0__33->GetYaxis()->SetLabelFont(42);
   frame_3ad6f0f0__33->GetYaxis()->SetTitleFont(42);
   frame_3ad6f0f0__33->GetZaxis()->SetLabelFont(42);
   frame_3ad6f0f0__33->GetZaxis()->SetTitleOffset(1);
   frame_3ad6f0f0__33->GetZaxis()->SetTitleFont(42);
   frame_3ad6f0f0__33->Draw("FUNC");
   
   Double_t h_dh_central2_fx3009[25] = {
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
   Double_t h_dh_central2_fy3009[25] = {
   0,
   0,
   8.376048,
   12.22624,
   21.04835,
   26.05464,
   50.51786,
   79.2306,
   114.4697,
   143.0919,
   153.5153,
   150.8001,
   124.0693,
   84.74329,
   53.23075,
   28.2545,
   15.20059,
   6.988966,
   3.334755,
   1.66571,
   0.4854639,
   0.09944494,
   0.1565465,
   0.3576441,
   0.1512988};
   Double_t h_dh_central2_felx3009[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_central2_fely3009[25] = {
   0,
   0,
   1.650382,
   1.970259,
   2.693786,
   3.074723,
   4.332654,
   5.546253,
   6.69551,
   7.472993,
   7.689102,
   7.622017,
   6.84666,
   5.577454,
   4.369727,
   3.057334,
   2.209905,
   1.395263,
   0.9284837,
   0.520886,
   0.2705242,
   0.06632731,
   0.08365455,
   0.1912035,
   0.08229726};
   Double_t h_dh_central2_fehx3009[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_central2_fehy3009[25] = {
   0,
   0,
   1.650382,
   1.970259,
   2.693786,
   3.074723,
   4.332654,
   5.546253,
   6.69551,
   7.472993,
   7.689102,
   7.622017,
   6.84666,
   5.577454,
   4.369727,
   3.057334,
   2.209905,
   1.395263,
   0.9284837,
   0.520886,
   0.2705242,
   0.06632731,
   0.08365455,
   0.1912035,
   0.08229726};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3009,h_dh_central2_fy3009,h_dh_central2_felx3009,h_dh_central2_fehx3009,h_dh_central2_fely3009,h_dh_central2_fehy3009);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23009 = new TH1F("Graph_h_dh_central23009","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23009->SetMinimum(0);
   Graph_h_dh_central23009->SetMaximum(177.3249);
   Graph_h_dh_central23009->SetDirectory(0);
   Graph_h_dh_central23009->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_central23009->SetLineColor(ci);
   Graph_h_dh_central23009->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_central23009->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_central23009->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_central23009->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_central23009->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_central23009->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_central23009->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_central23009->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_central23009);
   
   grae->Draw("p");
   
   Double_t Central_fx9[59] = {
   0.2751291,
   0.3202293,
   0.3653294,
   0.3878795,
   0.4104296,
   0.4160671,
   0.4217046,
   0.4329797,
   0.4555298,
   0.4780799,
   0.5006299,
   0.52318,
   0.5457301,
   0.5682802,
   0.5908303,
   0.6359304,
   0.6584805,
   0.6810306,
   0.7035807,
   0.7261308,
   0.7486809,
   0.7599559,
   0.7712309,
   0.782506,
   0.793781,
   0.8050561,
   0.8163311,
   0.8276062,
   0.8388812,
   0.8501562,
   0.8614313,
   0.8727063,
   0.8839814,
   0.8952564,
   0.9065315,
   0.9178065,
   0.9290815,
   0.9403566,
   0.9516316,
   0.9741817,
   0.9967318,
   1.019282,
   1.041832,
   1.086932,
   1.109482,
   1.132032,
   1.154582,
   1.177132,
   1.199683,
   1.222233,
   1.244783,
   1.267333,
   1.289883,
   1.312433,
   1.334983,
   1.346258,
   1.357533,
   1.402633,
   1.402633};
   Double_t Central_fy9[59] = {
   19.14267,
   19.49295,
   20.06125,
   20.56045,
   21.6228,
   22.24844,
   23.35184,
   25.78295,
   31.18056,
   37.30836,
   44.16716,
   51.73254,
   59.95137,
   68.73934,
   77.9799,
   97.19641,
   106.7924,
   116.0919,
   124.8631,
   132.8732,
   139.8981,
   142.9759,
   145.7327,
   148.1473,
   150.2012,
   151.8782,
   153.1654,
   154.0524,
   154.5322,
   154.6009,
   154.2582,
   153.5065,
   152.3521,
   150.8039,
   148.8743,
   146.5782,
   143.9335,
   140.9604,
   137.6814,
   130.3045,
   122.0155,
   113.0423,
   103.6188,
   84.32299,
   74.86111,
   65.75633,
   57.14653,
   49.13751,
   41.803,
   35.18623,
   29.30279,
   24.14439,
   19.68315,
   15.8761,
   12.66964,
   11.42528,
   10.97763,
   10.35716,
   10.35716};
   TGraph *graph = new TGraph(59,Central_fx9,Central_fy9);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central9 = new TH1F("Graph_Central9","Projection of centralf DSCB fit",100,0.1623787,1.515384);
   Graph_Central9->SetMinimum(9.32144);
   Graph_Central9->SetMaximum(169.0253);
   Graph_Central9->SetDirectory(0);
   Graph_Central9->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Central9->SetLineColor(ci);
   Graph_Central9->GetXaxis()->SetLabelFont(42);
   Graph_Central9->GetXaxis()->SetTitleOffset(1);
   Graph_Central9->GetXaxis()->SetTitleFont(42);
   Graph_Central9->GetYaxis()->SetLabelFont(42);
   Graph_Central9->GetYaxis()->SetTitleFont(42);
   Graph_Central9->GetZaxis()->SetLabelFont(42);
   Graph_Central9->GetZaxis()->SetTitleOffset(1);
   Graph_Central9->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Central9);
   
   graph->Draw("l");
   
   TH1D *frame_3ad6f0f0__34 = new TH1D("frame_3ad6f0f0__34","p_T Balance",25,0,2);
   frame_3ad6f0f0__34->SetBinContent(1,169.2647);
   frame_3ad6f0f0__34->SetMaximum(169.2647);
   frame_3ad6f0f0__34->SetEntries(1);
   frame_3ad6f0f0__34->SetDirectory(0);
   frame_3ad6f0f0__34->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3ad6f0f0__34->SetLineColor(ci);
   frame_3ad6f0f0__34->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ad6f0f0__34->GetXaxis()->SetLabelFont(42);
   frame_3ad6f0f0__34->GetXaxis()->SetTitleOffset(1);
   frame_3ad6f0f0__34->GetXaxis()->SetTitleFont(42);
   frame_3ad6f0f0__34->GetYaxis()->SetTitle("1/Events");
   frame_3ad6f0f0__34->GetYaxis()->SetLabelFont(42);
   frame_3ad6f0f0__34->GetYaxis()->SetTitleFont(42);
   frame_3ad6f0f0__34->GetZaxis()->SetLabelFont(42);
   frame_3ad6f0f0__34->GetZaxis()->SetTitleOffset(1);
   frame_3ad6f0f0__34->GetZaxis()->SetTitleFont(42);
   frame_3ad6f0f0__34->Draw("AXISSAME");
   
   TH1D *norm_c__35 = new TH1D("norm_c__35","",25,0,2);
   norm_c__35->SetBinContent(3,8.376048);
   norm_c__35->SetBinContent(4,12.22624);
   norm_c__35->SetBinContent(5,21.04835);
   norm_c__35->SetBinContent(6,26.05464);
   norm_c__35->SetBinContent(7,50.51787);
   norm_c__35->SetBinContent(8,79.2306);
   norm_c__35->SetBinContent(9,114.4697);
   norm_c__35->SetBinContent(10,143.0919);
   norm_c__35->SetBinContent(11,153.5153);
   norm_c__35->SetBinContent(12,150.8001);
   norm_c__35->SetBinContent(13,124.0692);
   norm_c__35->SetBinContent(14,84.74329);
   norm_c__35->SetBinContent(15,53.23075);
   norm_c__35->SetBinContent(16,28.25449);
   norm_c__35->SetBinContent(17,15.20059);
   norm_c__35->SetBinContent(18,6.988967);
   norm_c__35->SetBinContent(19,3.334755);
   norm_c__35->SetBinContent(20,1.66571);
   norm_c__35->SetBinContent(21,0.4854638);
   norm_c__35->SetBinContent(22,0.09944494);
   norm_c__35->SetBinContent(23,0.1565465);
   norm_c__35->SetBinContent(24,0.3576441);
   norm_c__35->SetBinContent(25,0.1512988);
   norm_c__35->SetBinContent(26,0.6381574);
   norm_c__35->SetBinError(3,1.650382);
   norm_c__35->SetBinError(4,1.970259);
   norm_c__35->SetBinError(5,2.693786);
   norm_c__35->SetBinError(6,3.074723);
   norm_c__35->SetBinError(7,4.332654);
   norm_c__35->SetBinError(8,5.546253);
   norm_c__35->SetBinError(9,6.69551);
   norm_c__35->SetBinError(10,7.472993);
   norm_c__35->SetBinError(11,7.689102);
   norm_c__35->SetBinError(12,7.622017);
   norm_c__35->SetBinError(13,6.84666);
   norm_c__35->SetBinError(14,5.577454);
   norm_c__35->SetBinError(15,4.369727);
   norm_c__35->SetBinError(16,3.057334);
   norm_c__35->SetBinError(17,2.209905);
   norm_c__35->SetBinError(18,1.395263);
   norm_c__35->SetBinError(19,0.9284837);
   norm_c__35->SetBinError(20,0.520886);
   norm_c__35->SetBinError(21,0.2705242);
   norm_c__35->SetBinError(22,0.06632731);
   norm_c__35->SetBinError(23,0.08365455);
   norm_c__35->SetBinError(24,0.1912035);
   norm_c__35->SetBinError(25,0.08229726);
   norm_c__35->SetBinError(26,0.1754071);
   norm_c__35->SetEntries(4810);
   norm_c__35->SetStats(0);

   ci = 1327;
   color = new TColor(ci, 0.3, 0.3, 0.3, " ", 0.6);
   norm_c__35->SetFillColor(ci);
   norm_c__35->SetFillStyle(3144);
   norm_c__35->SetLineColor(2);
   norm_c__35->SetLineWidth(2);
   norm_c__35->GetXaxis()->SetRange(1,25);
   norm_c__35->GetXaxis()->SetLabelFont(42);
   norm_c__35->GetXaxis()->SetLabelSize(0.04);
   norm_c__35->GetXaxis()->SetTitleOffset(1);
   norm_c__35->GetXaxis()->SetTitleFont(42);
   norm_c__35->GetYaxis()->SetLabelFont(42);
   norm_c__35->GetYaxis()->SetTitleFont(42);
   norm_c__35->GetZaxis()->SetLabelFont(42);
   norm_c__35->GetZaxis()->SetTitleOffset(1);
   norm_c__35->GetZaxis()->SetTitleFont(42);
   norm_c__35->Draw("e1 same");
   
   TLegend *leg = new TLegend(0.65,0.5,0.93,0.87,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.03);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("norm_c","Central","lpf");

   ci = 1327;
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
   entry=leg->AddEntry("frame_x_c2_3ad6f0f0","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.850369 #pm 0.007467","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.214258 #pm 0.006528","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.997000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3ad6f0f0_copy__36 = new TH1D("frame_3ad6f0f0_copy__36","p_T Balance",25,0,2);
   frame_3ad6f0f0_copy__36->SetBinContent(1,169.2647);
   frame_3ad6f0f0_copy__36->SetMaximum(169.2647);
   frame_3ad6f0f0_copy__36->SetEntries(1);
   frame_3ad6f0f0_copy__36->SetDirectory(0);
   frame_3ad6f0f0_copy__36->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3ad6f0f0_copy__36->SetLineColor(ci);
   frame_3ad6f0f0_copy__36->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ad6f0f0_copy__36->GetXaxis()->SetLabelFont(42);
   frame_3ad6f0f0_copy__36->GetXaxis()->SetTitleOffset(1);
   frame_3ad6f0f0_copy__36->GetXaxis()->SetTitleFont(42);
   frame_3ad6f0f0_copy__36->GetYaxis()->SetTitle("1/Events");
   frame_3ad6f0f0_copy__36->GetYaxis()->SetLabelFont(42);
   frame_3ad6f0f0_copy__36->GetYaxis()->SetTitleFont(42);
   frame_3ad6f0f0_copy__36->GetZaxis()->SetLabelFont(42);
   frame_3ad6f0f0_copy__36->GetZaxis()->SetTitleOffset(1);
   frame_3ad6f0f0_copy__36->GetZaxis()->SetTitleFont(42);
   frame_3ad6f0f0_copy__36->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-16.98204,2.25,195.2934);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3ad88390__37 = new TH1D("frame_3ad88390__37","p_T Balance",25,0,2);
   frame_3ad88390__37->SetBinContent(1,174.0659);
   frame_3ad88390__37->SetMaximum(174.0659);
   frame_3ad88390__37->SetEntries(1);
   frame_3ad88390__37->SetDirectory(0);
   frame_3ad88390__37->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3ad88390__37->SetLineColor(ci);
   frame_3ad88390__37->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ad88390__37->GetXaxis()->SetLabelFont(42);
   frame_3ad88390__37->GetXaxis()->SetTitleOffset(1);
   frame_3ad88390__37->GetXaxis()->SetTitleFont(42);
   frame_3ad88390__37->GetYaxis()->SetTitle("1/Events");
   frame_3ad88390__37->GetYaxis()->SetLabelFont(42);
   frame_3ad88390__37->GetYaxis()->SetTitleFont(42);
   frame_3ad88390__37->GetZaxis()->SetLabelFont(42);
   frame_3ad88390__37->GetZaxis()->SetTitleOffset(1);
   frame_3ad88390__37->GetZaxis()->SetTitleFont(42);
   frame_3ad88390__37->Draw("FUNC");
   
   Double_t h_dh_up2_fx3010[25] = {
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
   Double_t h_dh_up2_fy3010[25] = {
   0,
   0.150699,
   9.189609,
   12.38407,
   19.96251,
   21.92897,
   53.60038,
   74.29556,
   102.9369,
   157.1179,
   146.1905,
   157.9743,
   130.0013,
   92.84929,
   55.88594,
   30.17083,
   15.45188,
   7.336057,
   4.101598,
   1.665159,
   0.7835078,
   0.2682412,
   0.1968424,
   0.138333,
   0.1033718};
   Double_t h_dh_up2_felx3010[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_up2_fely3010[25] = {
   0,
   0.150699,
   1.93664,
   2.16116,
   2.810286,
   2.719066,
   4.562148,
   5.38072,
   6.329838,
   8.026125,
   7.554776,
   7.802725,
   7.019842,
   5.97193,
   4.45537,
   3.180544,
   2.176468,
   1.465225,
   0.9742149,
   0.5615095,
   0.3618515,
   0.1991561,
   0.1484679,
   0.08383946,
   0.07339093};
   Double_t h_dh_up2_fehx3010[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_up2_fehy3010[25] = {
   0,
   0.150699,
   1.93664,
   2.16116,
   2.810286,
   2.719066,
   4.562148,
   5.38072,
   6.329838,
   8.026125,
   7.554776,
   7.802725,
   7.019842,
   5.97193,
   4.45537,
   3.180544,
   2.176468,
   1.465225,
   0.9742149,
   0.5615095,
   0.3618515,
   0.1991561,
   0.1484679,
   0.08383946,
   0.07339093};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3010,h_dh_up2_fy3010,h_dh_up2_felx3010,h_dh_up2_fehx3010,h_dh_up2_fely3010,h_dh_up2_fehy3010);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23010 = new TH1F("Graph_h_dh_up23010","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23010->SetMinimum(0);
   Graph_h_dh_up23010->SetMaximum(182.3547);
   Graph_h_dh_up23010->SetDirectory(0);
   Graph_h_dh_up23010->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_up23010->SetLineColor(ci);
   Graph_h_dh_up23010->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_up23010->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_up23010->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_up23010->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_up23010->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_up23010->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_up23010->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_up23010->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_up23010);
   
   grae->Draw("p");
   
   Double_t up_fx10[56] = {
   0.3465965,
   0.3884233,
   0.4302501,
   0.4511635,
   0.4616202,
   0.472077,
   0.4825337,
   0.4929904,
   0.5139038,
   0.5348172,
   0.5557306,
   0.576644,
   0.5975574,
   0.6393842,
   0.681211,
   0.7021244,
   0.7230378,
   0.7439512,
   0.7648646,
   0.7753213,
   0.785778,
   0.7962347,
   0.8066914,
   0.8171481,
   0.8276048,
   0.8380615,
   0.8485183,
   0.858975,
   0.8694317,
   0.8798884,
   0.8903451,
   0.9008018,
   0.9112585,
   0.9217152,
   0.9321719,
   0.9530853,
   0.9739987,
   0.9949121,
   1.015825,
   1.057652,
   1.099479,
   1.120393,
   1.141306,
   1.162219,
   1.183133,
   1.204046,
   1.22496,
   1.245873,
   1.266786,
   1.2877,
   1.308613,
   1.329527,
   1.35044,
   1.371353,
   1.392267,
   1.392267};
   Double_t up_fy10[56] = {
   26.30614,
   26.79876,
   27.61009,
   28.34312,
   28.9479,
   30.04699,
   32.6509,
   35.65778,
   42.20999,
   49.46898,
   57.39938,
   65.93836,
   74.99387,
   94.13931,
   113.5384,
   122.8327,
   131.5653,
   139.5166,
   146.4761,
   149.5231,
   152.2525,
   154.6445,
   156.6818,
   158.3496,
   159.6355,
   160.53,
   161.0264,
   161.121,
   160.8131,
   160.105,
   159.0019,
   157.5121,
   155.6467,
   153.4193,
   150.8461,
   144.7388,
   137.4968,
   129.3174,
   120.4142,
   101.3187,
   81.90835,
   72.54916,
   63.61995,
   55.23456,
   47.4772,
   40.40323,
   34.0411,
   28.39539,
   23.45032,
   19.17372,
   15.52103,
   12.43917,
   9.870041,
   7.753596,
   6.030371,
   6.030371};
   graph = new TGraph(56,up_fx10,up_fy10);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up10 = new TH1F("Graph_up10","Projection of upf DSCB fit",100,0.2420295,1.496834);
   Graph_up10->SetMinimum(5.427334);
   Graph_up10->SetMaximum(176.6301);
   Graph_up10->SetDirectory(0);
   Graph_up10->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_up10->SetLineColor(ci);
   Graph_up10->GetXaxis()->SetLabelFont(42);
   Graph_up10->GetXaxis()->SetTitleOffset(1);
   Graph_up10->GetXaxis()->SetTitleFont(42);
   Graph_up10->GetYaxis()->SetLabelFont(42);
   Graph_up10->GetYaxis()->SetTitleFont(42);
   Graph_up10->GetZaxis()->SetLabelFont(42);
   Graph_up10->GetZaxis()->SetTitleOffset(1);
   Graph_up10->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_up10);
   
   graph->Draw("l");
   
   TH1D *frame_3ad88390__38 = new TH1D("frame_3ad88390__38","p_T Balance",25,0,2);
   frame_3ad88390__38->SetBinContent(1,174.0659);
   frame_3ad88390__38->SetMaximum(174.0659);
   frame_3ad88390__38->SetEntries(1);
   frame_3ad88390__38->SetDirectory(0);
   frame_3ad88390__38->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3ad88390__38->SetLineColor(ci);
   frame_3ad88390__38->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ad88390__38->GetXaxis()->SetLabelFont(42);
   frame_3ad88390__38->GetXaxis()->SetTitleOffset(1);
   frame_3ad88390__38->GetXaxis()->SetTitleFont(42);
   frame_3ad88390__38->GetYaxis()->SetTitle("1/Events");
   frame_3ad88390__38->GetYaxis()->SetLabelFont(42);
   frame_3ad88390__38->GetYaxis()->SetTitleFont(42);
   frame_3ad88390__38->GetZaxis()->SetLabelFont(42);
   frame_3ad88390__38->GetZaxis()->SetTitleOffset(1);
   frame_3ad88390__38->GetZaxis()->SetTitleFont(42);
   frame_3ad88390__38->Draw("AXISSAME");
   
   TH1D *norm_u__39 = new TH1D("norm_u__39","",25,0,2);
   norm_u__39->SetBinContent(2,0.150699);
   norm_u__39->SetBinContent(3,9.189609);
   norm_u__39->SetBinContent(4,12.38407);
   norm_u__39->SetBinContent(5,19.96251);
   norm_u__39->SetBinContent(6,21.92897);
   norm_u__39->SetBinContent(7,53.60038);
   norm_u__39->SetBinContent(8,74.29556);
   norm_u__39->SetBinContent(9,102.9369);
   norm_u__39->SetBinContent(10,157.1179);
   norm_u__39->SetBinContent(11,146.1905);
   norm_u__39->SetBinContent(12,157.9743);
   norm_u__39->SetBinContent(13,130.0013);
   norm_u__39->SetBinContent(14,92.84929);
   norm_u__39->SetBinContent(15,55.88594);
   norm_u__39->SetBinContent(16,30.17083);
   norm_u__39->SetBinContent(17,15.45188);
   norm_u__39->SetBinContent(18,7.336057);
   norm_u__39->SetBinContent(19,4.101598);
   norm_u__39->SetBinContent(20,1.665159);
   norm_u__39->SetBinContent(21,0.7835078);
   norm_u__39->SetBinContent(22,0.2682412);
   norm_u__39->SetBinContent(23,0.1968424);
   norm_u__39->SetBinContent(24,0.138333);
   norm_u__39->SetBinContent(25,0.1033718);
   norm_u__39->SetBinContent(26,0.807067);
   norm_u__39->SetBinError(2,0.150699);
   norm_u__39->SetBinError(3,1.93664);
   norm_u__39->SetBinError(4,2.16116);
   norm_u__39->SetBinError(5,2.810286);
   norm_u__39->SetBinError(6,2.719066);
   norm_u__39->SetBinError(7,4.562148);
   norm_u__39->SetBinError(8,5.38072);
   norm_u__39->SetBinError(9,6.329838);
   norm_u__39->SetBinError(10,8.026125);
   norm_u__39->SetBinError(11,7.554776);
   norm_u__39->SetBinError(12,7.802725);
   norm_u__39->SetBinError(13,7.019842);
   norm_u__39->SetBinError(14,5.97193);
   norm_u__39->SetBinError(15,4.45537);
   norm_u__39->SetBinError(16,3.180544);
   norm_u__39->SetBinError(17,2.176468);
   norm_u__39->SetBinError(18,1.465225);
   norm_u__39->SetBinError(19,0.9742149);
   norm_u__39->SetBinError(20,0.5615095);
   norm_u__39->SetBinError(21,0.3618515);
   norm_u__39->SetBinError(22,0.1991561);
   norm_u__39->SetBinError(23,0.1484679);
   norm_u__39->SetBinError(24,0.08383946);
   norm_u__39->SetBinError(25,0.07339093);
   norm_u__39->SetBinError(26,0.2018647);
   norm_u__39->SetEntries(4749);
   norm_u__39->SetStats(0);
   norm_u__39->SetLineColor(4);
   norm_u__39->SetLineWidth(2);
   norm_u__39->GetXaxis()->SetLabelFont(42);
   norm_u__39->GetXaxis()->SetTitleOffset(1);
   norm_u__39->GetXaxis()->SetTitleFont(42);
   norm_u__39->GetYaxis()->SetLabelFont(42);
   norm_u__39->GetYaxis()->SetTitleFont(42);
   norm_u__39->GetZaxis()->SetLabelFont(42);
   norm_u__39->GetZaxis()->SetTitleOffset(1);
   norm_u__39->GetZaxis()->SetTitleFont(42);
   norm_u__39->Draw("e1 same");
   
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
   entry=leg->AddEntry("frame_x_u2_3ad88390","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.856204 #pm 0.006830","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.209124 #pm 0.005619","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.913000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3ad88390_copy__40 = new TH1D("frame_3ad88390_copy__40","p_T Balance",25,0,2);
   frame_3ad88390_copy__40->SetBinContent(1,174.0659);
   frame_3ad88390_copy__40->SetMaximum(174.0659);
   frame_3ad88390_copy__40->SetEntries(1);
   frame_3ad88390_copy__40->SetDirectory(0);
   frame_3ad88390_copy__40->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3ad88390_copy__40->SetLineColor(ci);
   frame_3ad88390_copy__40->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ad88390_copy__40->GetXaxis()->SetLabelFont(42);
   frame_3ad88390_copy__40->GetXaxis()->SetTitleOffset(1);
   frame_3ad88390_copy__40->GetXaxis()->SetTitleFont(42);
   frame_3ad88390_copy__40->GetYaxis()->SetTitle("1/Events");
   frame_3ad88390_copy__40->GetYaxis()->SetLabelFont(42);
   frame_3ad88390_copy__40->GetYaxis()->SetTitleFont(42);
   frame_3ad88390_copy__40->GetZaxis()->SetLabelFont(42);
   frame_3ad88390_copy__40->GetZaxis()->SetTitleOffset(1);
   frame_3ad88390_copy__40->GetZaxis()->SetTitleFont(42);
   frame_3ad88390_copy__40->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-19.37277,2.25,174.3549);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3ad77870__41 = new TH1D("frame_3ad77870__41","p_T Balance",25,0,2);
   frame_3ad77870__41->SetBinContent(1,170.4804);
   frame_3ad77870__41->SetMaximum(170.4804);
   frame_3ad77870__41->SetEntries(1);
   frame_3ad77870__41->SetDirectory(0);
   frame_3ad77870__41->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3ad77870__41->SetLineColor(ci);
   frame_3ad77870__41->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ad77870__41->GetXaxis()->SetLabelFont(42);
   frame_3ad77870__41->GetXaxis()->SetTitleOffset(1);
   frame_3ad77870__41->GetXaxis()->SetTitleFont(42);
   frame_3ad77870__41->GetYaxis()->SetTitle("1/Events");
   frame_3ad77870__41->GetYaxis()->SetLabelFont(42);
   frame_3ad77870__41->GetYaxis()->SetTitleFont(42);
   frame_3ad77870__41->GetZaxis()->SetLabelFont(42);
   frame_3ad77870__41->GetZaxis()->SetTitleOffset(1);
   frame_3ad77870__41->GetZaxis()->SetTitleFont(42);
   frame_3ad77870__41->Draw("FUNC");
   
   Double_t h_dh_down2_fx3011[25] = {
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
   Double_t h_dh_down2_fy3011[25] = {
   0,
   0,
   8.872655,
   10.45867,
   19.62639,
   32.46194,
   54.01797,
   92.033,
   107.9452,
   146.1633,
   154.5882,
   143.8924,
   110.3293,
   87.87132,
   48.15897,
   25.56504,
   12.85651,
   5.387094,
   2.626582,
   1.191681,
   0.4475691,
   0.4249779,
   0.3386087,
   0.3723355,
   0.02615193};
   Double_t h_dh_down2_felx3011[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_down2_fely3011[25] = {
   0,
   0,
   1.767959,
   1.79918,
   2.478383,
   3.56696,
   4.410355,
   5.943002,
   6.368279,
   7.478135,
   7.774113,
   7.44093,
   6.410449,
   5.683222,
   4.116331,
   2.981322,
   2.009284,
   1.101624,
   0.8597919,
   0.4130588,
   0.2678186,
   0.2021461,
   0.1879034,
   0.1357837,
   0.01853642};
   Double_t h_dh_down2_fehx3011[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_down2_fehy3011[25] = {
   0,
   0,
   1.767959,
   1.79918,
   2.478383,
   3.56696,
   4.410355,
   5.943002,
   6.368279,
   7.478135,
   7.774113,
   7.44093,
   6.410449,
   5.683222,
   4.116331,
   2.981322,
   2.009284,
   1.101624,
   0.8597919,
   0.4130588,
   0.2678186,
   0.2021461,
   0.1879034,
   0.1357837,
   0.01853642};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3011,h_dh_down2_fy3011,h_dh_down2_felx3011,h_dh_down2_fehx3011,h_dh_down2_fely3011,h_dh_down2_fehy3011);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23011 = new TH1F("Graph_h_dh_down23011","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23011->SetMinimum(0);
   Graph_h_dh_down23011->SetMaximum(178.5985);
   Graph_h_dh_down23011->SetDirectory(0);
   Graph_h_dh_down23011->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_down23011->SetLineColor(ci);
   Graph_h_dh_down23011->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_down23011->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_down23011->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_down23011->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_down23011->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_down23011->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_down23011->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_down23011->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_down23011);
   
   grae->Draw("p");
   
   Double_t down_fx11[55] = {
   0.3362077,
   0.3773703,
   0.3979516,
   0.418533,
   0.4391143,
   0.4596956,
   0.480277,
   0.5008583,
   0.5214396,
   0.5420209,
   0.5626023,
   0.5831836,
   0.6243463,
   0.6655089,
   0.6860902,
   0.7066716,
   0.7272529,
   0.7478342,
   0.7684155,
   0.7787062,
   0.7889969,
   0.7992875,
   0.8095782,
   0.8198689,
   0.8301595,
   0.8404502,
   0.8507409,
   0.8610315,
   0.8713222,
   0.8816128,
   0.8919035,
   0.9021942,
   0.9124848,
   0.9330662,
   0.9536475,
   0.9742288,
   0.9948102,
   1.015391,
   1.035973,
   1.077135,
   1.097717,
   1.118298,
   1.138879,
   1.159461,
   1.180042,
   1.200623,
   1.221205,
   1.241786,
   1.262367,
   1.282949,
   1.30353,
   1.324111,
   1.344693,
   1.365274,
   1.365274};
   Double_t down_fy11[55] = {
   21.62778,
   26.01952,
   28.63377,
   31.58476,
   34.9259,
   38.72074,
   43.04529,
   47.99078,
   53.66735,
   60.20861,
   67.77755,
   76.26313,
   93.97852,
   111.627,
   119.9912,
   127.8017,
   134.8746,
   141.0361,
   146.1293,
   148.2324,
   150.0206,
   151.4817,
   152.6058,
   153.3853,
   153.8148,
   153.8913,
   153.6143,
   152.9857,
   152.0099,
   150.6934,
   149.0454,
   147.0769,
   144.8012,
   139.3902,
   132.9533,
   125.6529,
   117.6665,
   109.1791,
   100.3767,
   82.53535,
   73.8165,
   65.41443,
   57.43813,
   49.9728,
   43.07981,
   36.79768,
   31.14396,
   26.11764,
   21.70204,
   17.86792,
   14.57652,
   11.78259,
   9.437,
   7.489174,
   7.489174};
   graph = new TGraph(55,down_fx11,down_fy11);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down11 = new TH1F("Graph_down11","Projection of downf DSCB fit",100,0.233301,1.468181);
   Graph_down11->SetMinimum(6.740257);
   Graph_down11->SetMaximum(168.5315);
   Graph_down11->SetDirectory(0);
   Graph_down11->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_down11->SetLineColor(ci);
   Graph_down11->GetXaxis()->SetLabelFont(42);
   Graph_down11->GetXaxis()->SetTitleOffset(1);
   Graph_down11->GetXaxis()->SetTitleFont(42);
   Graph_down11->GetYaxis()->SetLabelFont(42);
   Graph_down11->GetYaxis()->SetTitleFont(42);
   Graph_down11->GetZaxis()->SetLabelFont(42);
   Graph_down11->GetZaxis()->SetTitleOffset(1);
   Graph_down11->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_down11);
   
   graph->Draw("l");
   
   TH1D *frame_3ad77870__42 = new TH1D("frame_3ad77870__42","p_T Balance",25,0,2);
   frame_3ad77870__42->SetBinContent(1,170.4804);
   frame_3ad77870__42->SetMaximum(170.4804);
   frame_3ad77870__42->SetEntries(1);
   frame_3ad77870__42->SetDirectory(0);
   frame_3ad77870__42->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3ad77870__42->SetLineColor(ci);
   frame_3ad77870__42->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ad77870__42->GetXaxis()->SetLabelFont(42);
   frame_3ad77870__42->GetXaxis()->SetTitleOffset(1);
   frame_3ad77870__42->GetXaxis()->SetTitleFont(42);
   frame_3ad77870__42->GetYaxis()->SetTitle("1/Events");
   frame_3ad77870__42->GetYaxis()->SetLabelFont(42);
   frame_3ad77870__42->GetYaxis()->SetTitleFont(42);
   frame_3ad77870__42->GetZaxis()->SetLabelFont(42);
   frame_3ad77870__42->GetZaxis()->SetTitleOffset(1);
   frame_3ad77870__42->GetZaxis()->SetTitleFont(42);
   frame_3ad77870__42->Draw("AXISSAME");
   
   TH1D *norm_d__43 = new TH1D("norm_d__43","",25,0,2);
   norm_d__43->SetBinContent(3,8.872655);
   norm_d__43->SetBinContent(4,10.45867);
   norm_d__43->SetBinContent(5,19.62639);
   norm_d__43->SetBinContent(6,32.46194);
   norm_d__43->SetBinContent(7,54.01797);
   norm_d__43->SetBinContent(8,92.03301);
   norm_d__43->SetBinContent(9,107.9452);
   norm_d__43->SetBinContent(10,146.1633);
   norm_d__43->SetBinContent(11,154.5882);
   norm_d__43->SetBinContent(12,143.8924);
   norm_d__43->SetBinContent(13,110.3293);
   norm_d__43->SetBinContent(14,87.87132);
   norm_d__43->SetBinContent(15,48.15897);
   norm_d__43->SetBinContent(16,25.56504);
   norm_d__43->SetBinContent(17,12.85651);
   norm_d__43->SetBinContent(18,5.387094);
   norm_d__43->SetBinContent(19,2.626582);
   norm_d__43->SetBinContent(20,1.191681);
   norm_d__43->SetBinContent(21,0.4475691);
   norm_d__43->SetBinContent(22,0.4249779);
   norm_d__43->SetBinContent(23,0.3386087);
   norm_d__43->SetBinContent(24,0.3723355);
   norm_d__43->SetBinContent(25,0.02615193);
   norm_d__43->SetBinContent(26,0.4065728);
   norm_d__43->SetBinError(3,1.767959);
   norm_d__43->SetBinError(4,1.79918);
   norm_d__43->SetBinError(5,2.478383);
   norm_d__43->SetBinError(6,3.56696);
   norm_d__43->SetBinError(7,4.410355);
   norm_d__43->SetBinError(8,5.943002);
   norm_d__43->SetBinError(9,6.368279);
   norm_d__43->SetBinError(10,7.478135);
   norm_d__43->SetBinError(11,7.774113);
   norm_d__43->SetBinError(12,7.44093);
   norm_d__43->SetBinError(13,6.410449);
   norm_d__43->SetBinError(14,5.683222);
   norm_d__43->SetBinError(15,4.116331);
   norm_d__43->SetBinError(16,2.981322);
   norm_d__43->SetBinError(17,2.009284);
   norm_d__43->SetBinError(18,1.101624);
   norm_d__43->SetBinError(19,0.8597919);
   norm_d__43->SetBinError(20,0.4130588);
   norm_d__43->SetBinError(21,0.2678186);
   norm_d__43->SetBinError(22,0.2021461);
   norm_d__43->SetBinError(23,0.1879034);
   norm_d__43->SetBinError(24,0.1357837);
   norm_d__43->SetBinError(25,0.01853642);
   norm_d__43->SetBinError(26,0.1546534);
   norm_d__43->SetEntries(4826);
   norm_d__43->SetStats(0);
   norm_d__43->SetLineColor(7);
   norm_d__43->SetLineWidth(2);
   norm_d__43->GetXaxis()->SetLabelFont(42);
   norm_d__43->GetXaxis()->SetTitleOffset(1);
   norm_d__43->GetXaxis()->SetTitleFont(42);
   norm_d__43->GetYaxis()->SetLabelFont(42);
   norm_d__43->GetYaxis()->SetTitleFont(42);
   norm_d__43->GetZaxis()->SetLabelFont(42);
   norm_d__43->GetZaxis()->SetTitleOffset(1);
   norm_d__43->GetZaxis()->SetTitleFont(42);
   norm_d__43->Draw("same e1");
   
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
   entry=leg->AddEntry("frame_x_d2_3ad77870","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.835926 #pm 0.008013","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.215801 #pm 0.007217","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 1.000000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3ad77870_copy__44 = new TH1D("frame_3ad77870_copy__44","p_T Balance",25,0,2);
   frame_3ad77870_copy__44->SetBinContent(1,170.4804);
   frame_3ad77870_copy__44->SetMaximum(170.4804);
   frame_3ad77870_copy__44->SetEntries(1);
   frame_3ad77870_copy__44->SetDirectory(0);
   frame_3ad77870_copy__44->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3ad77870_copy__44->SetLineColor(ci);
   frame_3ad77870_copy__44->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ad77870_copy__44->GetXaxis()->SetLabelFont(42);
   frame_3ad77870_copy__44->GetXaxis()->SetTitleOffset(1);
   frame_3ad77870_copy__44->GetXaxis()->SetTitleFont(42);
   frame_3ad77870_copy__44->GetYaxis()->SetTitle("1/Events");
   frame_3ad77870_copy__44->GetYaxis()->SetLabelFont(42);
   frame_3ad77870_copy__44->GetYaxis()->SetTitleFont(42);
   frame_3ad77870_copy__44->GetZaxis()->SetLabelFont(42);
   frame_3ad77870_copy__44->GetZaxis()->SetTitleOffset(1);
   frame_3ad77870_copy__44->GetZaxis()->SetTitleFont(42);
   frame_3ad77870_copy__44->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-21.52888,2.25,193.7599);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3ad5c110__45 = new TH1D("frame_3ad5c110__45","p_T Balance",25,0,2);
   frame_3ad5c110__45->SetBinContent(1,189.4541);
   frame_3ad5c110__45->SetMaximum(189.4541);
   frame_3ad5c110__45->SetEntries(1);
   frame_3ad5c110__45->SetDirectory(0);
   frame_3ad5c110__45->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3ad5c110__45->SetLineColor(ci);
   frame_3ad5c110__45->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ad5c110__45->GetXaxis()->SetLabelFont(42);
   frame_3ad5c110__45->GetXaxis()->SetTitleOffset(1);
   frame_3ad5c110__45->GetXaxis()->SetTitleFont(42);
   frame_3ad5c110__45->GetYaxis()->SetTitle("1/Events");
   frame_3ad5c110__45->GetYaxis()->SetLabelFont(42);
   frame_3ad5c110__45->GetYaxis()->SetTitleFont(42);
   frame_3ad5c110__45->GetZaxis()->SetLabelFont(42);
   frame_3ad5c110__45->GetZaxis()->SetTitleOffset(1);
   frame_3ad5c110__45->GetZaxis()->SetTitleFont(42);
   frame_3ad5c110__45->Draw("FUNC");
   
   Double_t h_dh_data2_fx3012[25] = {
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
   Double_t h_dh_data2_fy3012[25] = {
   0,
   0,
   5,
   20,
   21,
   31,
   70,
   104,
   162,
   166,
   167,
   146,
   138,
   100,
   60,
   26,
   17,
   8,
   3,
   5,
   2,
   1,
   2,
   0,
   0};
   Double_t h_dh_data2_felx3012[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_data2_fely3012[25] = {
   0,
   0,
   2.159691,
   4.434448,
   4.545807,
   5.537565,
   8.346566,
   9.710289,
   12.23774,
   12.3938,
   12.43252,
   11.59339,
   11.25798,
   9.983255,
   7.724317,
   5.066015,
   4.082184,
   2.768386,
   1.632705,
   2.159691,
   1.291815,
   0.8272462,
   1.291815,
   0,
   0};
   Double_t h_dh_data2_fehx3012[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_data2_fehy3012[25] = {
   1.147874,
   1.147874,
   3.382473,
   5.546519,
   5.655182,
   6.627601,
   9.406468,
   10.71029,
   13.23774,
   13.3938,
   13.43252,
   12.59339,
   12.25798,
   11.03336,
   8.789023,
   6.164324,
   5.203719,
   3.945142,
   2.918186,
   3.382473,
   2.63786,
   2.299527,
   2.63786,
   1.147874,
   1.147874};
   grae = new TGraphAsymmErrors(25,h_dh_data2_fx3012,h_dh_data2_fy3012,h_dh_data2_felx3012,h_dh_data2_fehx3012,h_dh_data2_fely3012,h_dh_data2_fehy3012);
   grae->SetName("h_dh_data2");
   grae->SetTitle("Histogram of dh_data2_plot__x_o2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_data23012 = new TH1F("Graph_h_dh_data23012","Histogram of dh_data2_plot__x_o2",100,0,2.2);
   Graph_h_dh_data23012->SetMinimum(0);
   Graph_h_dh_data23012->SetMaximum(198.4758);
   Graph_h_dh_data23012->SetDirectory(0);
   Graph_h_dh_data23012->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_data23012->SetLineColor(ci);
   Graph_h_dh_data23012->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_data23012->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_data23012->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_data23012->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_data23012->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_data23012->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_data23012->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_data23012->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_data23012);
   
   grae->Draw("p");
   
   Double_t observation_fx12[58] = {
   0.2382707,
   0.2614598,
   0.2846489,
   0.307838,
   0.3310272,
   0.3542163,
   0.3774054,
   0.4005946,
   0.4237837,
   0.4469728,
   0.470162,
   0.4933511,
   0.5165402,
   0.5397293,
   0.5629185,
   0.6092967,
   0.6324859,
   0.655675,
   0.6788641,
   0.7020533,
   0.7252424,
   0.7368369,
   0.7484315,
   0.7600261,
   0.7716206,
   0.7832152,
   0.7948098,
   0.8064043,
   0.8179989,
   0.8295935,
   0.841188,
   0.8527826,
   0.8643772,
   0.8759717,
   0.8875663,
   0.8991609,
   0.9107554,
   0.9339446,
   0.9571337,
   0.9803228,
   1.003512,
   1.026701,
   1.073079,
   1.096268,
   1.119458,
   1.142647,
   1.165836,
   1.189025,
   1.212214,
   1.235403,
   1.258592,
   1.281782,
   1.304971,
   1.32816,
   1.351349,
   1.374538,
   1.397727,
   1.397727};
   Double_t observation_fy12[58] = {
   6.583608,
   8.504179,
   10.87126,
   13.75327,
   17.21911,
   21.33509,
   26.16117,
   31.7467,
   38.12579,
   45.31249,
   53.29616,
   62.03726,
   71.46415,
   81.47092,
   91.91701,
   113.4015,
   124.0077,
   134.2014,
   143.729,
   152.3389,
   159.7923,
   163.017,
   165.8745,
   168.3434,
   170.405,
   172.0435,
   173.2462,
   174.004,
   174.3107,
   174.1642,
   173.5655,
   172.5192,
   171.0336,
   169.12,
   166.7931,
   164.0707,
   160.9733,
   153.7476,
   145.3254,
   135.942,
   125.8476,
   115.2961,
   93.79737,
   83.29079,
   73.19511,
   63.65698,
   54.78842,
   46.66706,
   39.33787,
   32.81634,
   27.09244,
   22.13528,
   17.89785,
   14.32173,
   11.34146,
   8.888348,
   6.896782,
   6.896782};
   graph = new TGraph(58,observation_fx12,observation_fy12);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation12 = new TH1F("Graph_observation12","Projection of obsf DSCB fit",100,0.122325,1.513673);
   Graph_observation12->SetMinimum(5.925247);
   Graph_observation12->SetMaximum(191.0835);
   Graph_observation12->SetDirectory(0);
   Graph_observation12->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_observation12->SetLineColor(ci);
   Graph_observation12->GetXaxis()->SetLabelFont(42);
   Graph_observation12->GetXaxis()->SetTitleOffset(1);
   Graph_observation12->GetXaxis()->SetTitleFont(42);
   Graph_observation12->GetYaxis()->SetLabelFont(42);
   Graph_observation12->GetYaxis()->SetTitleFont(42);
   Graph_observation12->GetZaxis()->SetLabelFont(42);
   Graph_observation12->GetZaxis()->SetTitleOffset(1);
   Graph_observation12->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_observation12);
   
   graph->Draw("l");
   
   TH1D *frame_3ad5c110__46 = new TH1D("frame_3ad5c110__46","p_T Balance",25,0,2);
   frame_3ad5c110__46->SetBinContent(1,189.4541);
   frame_3ad5c110__46->SetMaximum(189.4541);
   frame_3ad5c110__46->SetEntries(1);
   frame_3ad5c110__46->SetDirectory(0);
   frame_3ad5c110__46->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3ad5c110__46->SetLineColor(ci);
   frame_3ad5c110__46->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ad5c110__46->GetXaxis()->SetLabelFont(42);
   frame_3ad5c110__46->GetXaxis()->SetTitleOffset(1);
   frame_3ad5c110__46->GetXaxis()->SetTitleFont(42);
   frame_3ad5c110__46->GetYaxis()->SetTitle("1/Events");
   frame_3ad5c110__46->GetYaxis()->SetLabelFont(42);
   frame_3ad5c110__46->GetYaxis()->SetTitleFont(42);
   frame_3ad5c110__46->GetZaxis()->SetLabelFont(42);
   frame_3ad5c110__46->GetZaxis()->SetTitleOffset(1);
   frame_3ad5c110__46->GetZaxis()->SetTitleFont(42);
   frame_3ad5c110__46->Draw("AXISSAME");
   
   TH1D *norm_o__47 = new TH1D("norm_o__47","",25,0,2);
   norm_o__47->SetBinContent(3,5);
   norm_o__47->SetBinContent(4,20);
   norm_o__47->SetBinContent(5,21);
   norm_o__47->SetBinContent(6,31);
   norm_o__47->SetBinContent(7,70);
   norm_o__47->SetBinContent(8,104);
   norm_o__47->SetBinContent(9,162);
   norm_o__47->SetBinContent(10,166);
   norm_o__47->SetBinContent(11,167);
   norm_o__47->SetBinContent(12,146);
   norm_o__47->SetBinContent(13,138);
   norm_o__47->SetBinContent(14,100);
   norm_o__47->SetBinContent(15,60);
   norm_o__47->SetBinContent(16,26);
   norm_o__47->SetBinContent(17,17);
   norm_o__47->SetBinContent(18,8);
   norm_o__47->SetBinContent(19,3);
   norm_o__47->SetBinContent(20,5);
   norm_o__47->SetBinContent(21,2);
   norm_o__47->SetBinContent(22,1);
   norm_o__47->SetBinContent(23,2);
   norm_o__47->SetMinimum(0);
   norm_o__47->SetMaximum(367.4);
   norm_o__47->SetEntries(1254);
   norm_o__47->SetStats(0);
   norm_o__47->SetLineWidth(2);
   norm_o__47->SetMarkerStyle(8);
   norm_o__47->SetMarkerSize(0.4);
   norm_o__47->GetXaxis()->SetRange(1,25);
   norm_o__47->GetXaxis()->SetLabelFont(42);
   norm_o__47->GetXaxis()->SetLabelSize(0.04);
   norm_o__47->GetXaxis()->SetTitleOffset(1);
   norm_o__47->GetXaxis()->SetTitleFont(42);
   norm_o__47->GetYaxis()->SetTitle("Events");
   norm_o__47->GetYaxis()->SetLabelFont(42);
   norm_o__47->GetYaxis()->SetTitleOffset(1.4);
   norm_o__47->GetYaxis()->SetTitleFont(42);
   norm_o__47->GetZaxis()->SetLabelFont(42);
   norm_o__47->GetZaxis()->SetTitleOffset(1);
   norm_o__47->GetZaxis()->SetTitleFont(42);
   norm_o__47->Draw("same e1");
   
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
   entry=leg->AddEntry("frame_x_o2_3ad5c110","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.827794 #pm 0.006579","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.217373 #pm 0.005527","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.981000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3ad5c110_copy__48 = new TH1D("frame_3ad5c110_copy__48","p_T Balance",25,0,2);
   frame_3ad5c110_copy__48->SetBinContent(1,189.4541);
   frame_3ad5c110_copy__48->SetMaximum(189.4541);
   frame_3ad5c110_copy__48->SetEntries(1);
   frame_3ad5c110_copy__48->SetDirectory(0);
   frame_3ad5c110_copy__48->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3ad5c110_copy__48->SetLineColor(ci);
   frame_3ad5c110_copy__48->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ad5c110_copy__48->GetXaxis()->SetLabelFont(42);
   frame_3ad5c110_copy__48->GetXaxis()->SetTitleOffset(1);
   frame_3ad5c110_copy__48->GetXaxis()->SetTitleFont(42);
   frame_3ad5c110_copy__48->GetYaxis()->SetTitle("1/Events");
   frame_3ad5c110_copy__48->GetYaxis()->SetLabelFont(42);
   frame_3ad5c110_copy__48->GetYaxis()->SetTitleFont(42);
   frame_3ad5c110_copy__48->GetZaxis()->SetLabelFont(42);
   frame_3ad5c110_copy__48->GetZaxis()->SetTitleOffset(1);
   frame_3ad5c110_copy__48->GetZaxis()->SetTitleFont(42);
   frame_3ad5c110_copy__48->Draw("sameaxis");
   
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
