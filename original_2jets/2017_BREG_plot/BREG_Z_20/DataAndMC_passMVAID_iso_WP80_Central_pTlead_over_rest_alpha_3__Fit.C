void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_3__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 18:46:54 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-12.26038,2.25,140.9944);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3bf6e940__33 = new TH1D("frame_3bf6e940__33","p_T Balance",25,0,2);
   frame_3bf6e940__33->SetBinContent(1,125.6689);
   frame_3bf6e940__33->SetMaximum(125.6689);
   frame_3bf6e940__33->SetEntries(1);
   frame_3bf6e940__33->SetDirectory(0);
   frame_3bf6e940__33->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_3bf6e940__33->SetLineColor(ci);
   frame_3bf6e940__33->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf6e940__33->GetXaxis()->SetLabelFont(42);
   frame_3bf6e940__33->GetXaxis()->SetTitleOffset(1);
   frame_3bf6e940__33->GetXaxis()->SetTitleFont(42);
   frame_3bf6e940__33->GetYaxis()->SetTitle("1/Events");
   frame_3bf6e940__33->GetYaxis()->SetLabelFont(42);
   frame_3bf6e940__33->GetYaxis()->SetTitleFont(42);
   frame_3bf6e940__33->GetZaxis()->SetLabelFont(42);
   frame_3bf6e940__33->GetZaxis()->SetTitleOffset(1);
   frame_3bf6e940__33->GetZaxis()->SetTitleFont(42);
   frame_3bf6e940__33->Draw("FUNC");
   
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
   3.403433,
   4.287903,
   6.993434,
   15.04974,
   25.91618,
   37.5176,
   63.67803,
   78.30014,
   113.2039,
   99.12114,
   81.69008,
   62.78023,
   36.35096,
   20.1354,
   11.26146,
   6.208357,
   2.840272,
   1.50145,
   0.6352131,
   0.3321989,
   0.05782757,
   0,
   0};
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
   1.077482,
   1.001365,
   1.358436,
   2.291088,
   2.996887,
   3.649234,
   4.808253,
   5.335889,
   6.480709,
   5.958101,
   5.419437,
   4.696188,
   3.327845,
   2.521506,
   1.790276,
   1.318656,
   0.8255637,
   0.5081452,
   0.3024309,
   0.2248767,
   0.0463054,
   0,
   0};
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
   1.077482,
   1.001365,
   1.358436,
   2.291088,
   2.996887,
   3.649234,
   4.808253,
   5.335889,
   6.480709,
   5.958101,
   5.419437,
   4.696188,
   3.327845,
   2.521506,
   1.790276,
   1.318656,
   0.8255637,
   0.5081452,
   0.3024309,
   0.2248767,
   0.0463054,
   0,
   0};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3009,h_dh_central2_fy3009,h_dh_central2_felx3009,h_dh_central2_fehx3009,h_dh_central2_fely3009,h_dh_central2_fehy3009);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23009 = new TH1F("Graph_h_dh_central23009","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23009->SetMinimum(0);
   Graph_h_dh_central23009->SetMaximum(131.6531);
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
   
   Double_t Central_fx9[57] = {
   0.4197567,
   0.4570332,
   0.4943097,
   0.512948,
   0.5315863,
   0.5502245,
   0.5688628,
   0.587501,
   0.6061393,
   0.6247776,
   0.6340967,
   0.6434158,
   0.6620541,
   0.6806923,
   0.7179689,
   0.7366071,
   0.7552454,
   0.7738836,
   0.7925219,
   0.8111602,
   0.8204793,
   0.8297984,
   0.8391176,
   0.8484367,
   0.8577558,
   0.8670749,
   0.8763941,
   0.8857132,
   0.8950323,
   0.9043515,
   0.9136706,
   0.9229897,
   0.9323089,
   0.941628,
   0.9509471,
   0.9602662,
   0.9789045,
   0.9975428,
   1.016181,
   1.034819,
   1.053458,
   1.090734,
   1.128011,
   1.146649,
   1.165287,
   1.183925,
   1.202564,
   1.221202,
   1.23984,
   1.258478,
   1.267798,
   1.272457,
   1.277117,
   1.295755,
   1.314393,
   1.35167,
   1.35167};
   Double_t Central_fy9[57] = {
   18.73478,
   21.15537,
   24.15627,
   25.93835,
   27.95459,
   30.25078,
   32.88495,
   35.93164,
   39.48805,
   43.68306,
   46.07221,
   48.69093,
   54.51714,
   60.53665,
   72.6008,
   78.41138,
   83.90754,
   88.96249,
   93.45381,
   97.26828,
   98.89,
   100.3066,
   101.5086,
   102.4878,
   103.2375,
   103.7525,
   104.0294,
   104.0661,
   103.8625,
   103.4199,
   102.7414,
   101.8317,
   100.697,
   99.34506,
   97.78491,
   96.02703,
   91.96548,
   87.26504,
   82.04269,
   76.42292,
   70.53286,
   58.43588,
   46.65564,
   41.11427,
   35.89759,
   31.05432,
   26.61723,
   22.60413,
   19.0194,
   15.85587,
   14.42716,
   13.75598,
   13.33977,
   12.66222,
   12.35005,
   11.99704,
   11.99704};
   TGraph *graph = new TGraph(57,Central_fx9,Central_fy9);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central9 = new TH1F("Graph_Central9","Projection of centralf DSCB fit",100,0.3265654,1.444861);
   Graph_Central9->SetMinimum(2.790128);
   Graph_Central9->SetMaximum(113.273);
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
   
   TH1D *frame_3bf6e940__34 = new TH1D("frame_3bf6e940__34","p_T Balance",25,0,2);
   frame_3bf6e940__34->SetBinContent(1,125.6689);
   frame_3bf6e940__34->SetMaximum(125.6689);
   frame_3bf6e940__34->SetEntries(1);
   frame_3bf6e940__34->SetDirectory(0);
   frame_3bf6e940__34->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf6e940__34->SetLineColor(ci);
   frame_3bf6e940__34->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf6e940__34->GetXaxis()->SetLabelFont(42);
   frame_3bf6e940__34->GetXaxis()->SetTitleOffset(1);
   frame_3bf6e940__34->GetXaxis()->SetTitleFont(42);
   frame_3bf6e940__34->GetYaxis()->SetTitle("1/Events");
   frame_3bf6e940__34->GetYaxis()->SetLabelFont(42);
   frame_3bf6e940__34->GetYaxis()->SetTitleFont(42);
   frame_3bf6e940__34->GetZaxis()->SetLabelFont(42);
   frame_3bf6e940__34->GetZaxis()->SetTitleOffset(1);
   frame_3bf6e940__34->GetZaxis()->SetTitleFont(42);
   frame_3bf6e940__34->Draw("AXISSAME");
   
   TH1D *norm_c__35 = new TH1D("norm_c__35","",25,0,2);
   norm_c__35->SetBinContent(3,3.403432);
   norm_c__35->SetBinContent(4,4.287903);
   norm_c__35->SetBinContent(5,6.993434);
   norm_c__35->SetBinContent(6,15.04974);
   norm_c__35->SetBinContent(7,25.91618);
   norm_c__35->SetBinContent(8,37.51761);
   norm_c__35->SetBinContent(9,63.67803);
   norm_c__35->SetBinContent(10,78.30014);
   norm_c__35->SetBinContent(11,113.2039);
   norm_c__35->SetBinContent(12,99.12114);
   norm_c__35->SetBinContent(13,81.69008);
   norm_c__35->SetBinContent(14,62.78023);
   norm_c__35->SetBinContent(15,36.35096);
   norm_c__35->SetBinContent(16,20.1354);
   norm_c__35->SetBinContent(17,11.26146);
   norm_c__35->SetBinContent(18,6.208357);
   norm_c__35->SetBinContent(19,2.840272);
   norm_c__35->SetBinContent(20,1.50145);
   norm_c__35->SetBinContent(21,0.6352132);
   norm_c__35->SetBinContent(22,0.3321989);
   norm_c__35->SetBinContent(23,0.05782757);
   norm_c__35->SetBinContent(26,0.287201);
   norm_c__35->SetBinError(3,1.077482);
   norm_c__35->SetBinError(4,1.001365);
   norm_c__35->SetBinError(5,1.358436);
   norm_c__35->SetBinError(6,2.291088);
   norm_c__35->SetBinError(7,2.996887);
   norm_c__35->SetBinError(8,3.649234);
   norm_c__35->SetBinError(9,4.808253);
   norm_c__35->SetBinError(10,5.335889);
   norm_c__35->SetBinError(11,6.480709);
   norm_c__35->SetBinError(12,5.958101);
   norm_c__35->SetBinError(13,5.419437);
   norm_c__35->SetBinError(14,4.696188);
   norm_c__35->SetBinError(15,3.327845);
   norm_c__35->SetBinError(16,2.521506);
   norm_c__35->SetBinError(17,1.790276);
   norm_c__35->SetBinError(18,1.318656);
   norm_c__35->SetBinError(19,0.8255637);
   norm_c__35->SetBinError(20,0.5081452);
   norm_c__35->SetBinError(21,0.3024309);
   norm_c__35->SetBinError(22,0.2248767);
   norm_c__35->SetBinError(23,0.0463054);
   norm_c__35->SetBinError(26,0.1280197);
   norm_c__35->SetEntries(3130);
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
   entry=leg->AddEntry("frame_x_c2_3bf6e940","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.870652 #pm 0.009218","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.213673 #pm 0.008431","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.973000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3bf6e940_copy__36 = new TH1D("frame_3bf6e940_copy__36","p_T Balance",25,0,2);
   frame_3bf6e940_copy__36->SetBinContent(1,125.6689);
   frame_3bf6e940_copy__36->SetMaximum(125.6689);
   frame_3bf6e940_copy__36->SetEntries(1);
   frame_3bf6e940_copy__36->SetDirectory(0);
   frame_3bf6e940_copy__36->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf6e940_copy__36->SetLineColor(ci);
   frame_3bf6e940_copy__36->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf6e940_copy__36->GetXaxis()->SetLabelFont(42);
   frame_3bf6e940_copy__36->GetXaxis()->SetTitleOffset(1);
   frame_3bf6e940_copy__36->GetXaxis()->SetTitleFont(42);
   frame_3bf6e940_copy__36->GetYaxis()->SetTitle("1/Events");
   frame_3bf6e940_copy__36->GetYaxis()->SetLabelFont(42);
   frame_3bf6e940_copy__36->GetYaxis()->SetTitleFont(42);
   frame_3bf6e940_copy__36->GetZaxis()->SetLabelFont(42);
   frame_3bf6e940_copy__36->GetZaxis()->SetTitleOffset(1);
   frame_3bf6e940_copy__36->GetZaxis()->SetTitleFont(42);
   frame_3bf6e940_copy__36->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-17.83541,2.25,134.2495);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3bf66890__37 = new TH1D("frame_3bf66890__37","p_T Balance",25,0,2);
   frame_3bf66890__37->SetBinContent(1,119.041);
   frame_3bf66890__37->SetMinimum(-5.668618);
   frame_3bf66890__37->SetMaximum(119.041);
   frame_3bf66890__37->SetEntries(1);
   frame_3bf66890__37->SetDirectory(0);
   frame_3bf66890__37->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf66890__37->SetLineColor(ci);
   frame_3bf66890__37->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf66890__37->GetXaxis()->SetLabelFont(42);
   frame_3bf66890__37->GetXaxis()->SetTitleOffset(1);
   frame_3bf66890__37->GetXaxis()->SetTitleFont(42);
   frame_3bf66890__37->GetYaxis()->SetTitle("1/Events");
   frame_3bf66890__37->GetYaxis()->SetLabelFont(42);
   frame_3bf66890__37->GetYaxis()->SetTitleFont(42);
   frame_3bf66890__37->GetZaxis()->SetLabelFont(42);
   frame_3bf66890__37->GetZaxis()->SetTitleOffset(1);
   frame_3bf66890__37->GetZaxis()->SetTitleFont(42);
   frame_3bf66890__37->Draw("FUNC");
   
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
   0,
   2.692057,
   4.048192,
   8.25489,
   12.36158,
   28.00796,
   38.1086,
   62.89472,
   79.03357,
   106.2732,
   107.0874,
   83.05733,
   61.1104,
   43.21013,
   21.24773,
   9.946016,
   5.411953,
   2.349978,
   1.624463,
   0.6284212,
   0.342915,
   0.1998825,
   0.03146754,
   0.1632003};
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
   0,
   0.9297343,
   0.957494,
   1.675869,
   2.002482,
   3.150916,
   3.696623,
   4.837113,
   5.449904,
   6.234398,
   6.284999,
   5.469787,
   4.598321,
   3.77043,
   2.584726,
   1.70556,
   1.27317,
   0.7041262,
   0.5135353,
   0.3039048,
   0.2245888,
   0.1869164,
   0.03146754,
   0.1632003};
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
   0,
   0.9297343,
   0.957494,
   1.675869,
   2.002482,
   3.150916,
   3.696623,
   4.837113,
   5.449904,
   6.234398,
   6.284999,
   5.469787,
   4.598321,
   3.77043,
   2.584726,
   1.70556,
   1.27317,
   0.7041262,
   0.5135353,
   0.3039048,
   0.2245888,
   0.1869164,
   0.03146754,
   0.1632003};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3010,h_dh_up2_fy3010,h_dh_up2_felx3010,h_dh_up2_fehx3010,h_dh_up2_fely3010,h_dh_up2_fehy3010);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23010 = new TH1F("Graph_h_dh_up23010","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23010->SetMinimum(-11.33724);
   Graph_h_dh_up23010->SetMaximum(124.7096);
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
   
   Double_t up_fx10[59] = {
   0.3331592,
   0.3763497,
   0.4195402,
   0.4411354,
   0.4627306,
   0.4843259,
   0.5059211,
   0.5275163,
   0.5491116,
   0.5599092,
   0.5707068,
   0.5815044,
   0.592302,
   0.6138973,
   0.6354925,
   0.678683,
   0.7218734,
   0.7434687,
   0.7650639,
   0.7758615,
   0.7866591,
   0.7974567,
   0.8082544,
   0.819052,
   0.8298496,
   0.8406472,
   0.8514448,
   0.8622424,
   0.8730401,
   0.8838377,
   0.8946353,
   0.9054329,
   0.9162305,
   0.9270281,
   0.9378258,
   0.9486234,
   0.959421,
   0.9702186,
   0.9810162,
   1.002611,
   1.024207,
   1.045802,
   1.067397,
   1.110588,
   1.132183,
   1.153778,
   1.175373,
   1.196969,
   1.218564,
   1.240159,
   1.261754,
   1.283349,
   1.294147,
   1.304945,
   1.32654,
   1.348135,
   1.36973,
   1.412921,
   1.412921};
   Double_t up_fy10[59] = {
   8.399021,
   10.35018,
   12.92441,
   14.52221,
   16.38302,
   18.56172,
   21.12726,
   24.16695,
   27.7924,
   29.86824,
   32.14761,
   34.65545,
   37.41477,
   43.34552,
   49.64375,
   62.91626,
   76.16194,
   82.3672,
   88.06226,
   90.66503,
   93.07746,
   95.28051,
   97.25645,
   98.98915,
   100.4642,
   101.6694,
   102.5944,
   103.2315,
   103.5751,
   103.6223,
   103.3727,
   102.8285,
   101.9943,
   100.8772,
   99.48665,
   97.83438,
   95.9341,
   93.8014,
   91.45352,
   86.18805,
   80.2995,
   73.96016,
   67.34448,
   53.94708,
   47.46021,
   41.27724,
   35.49039,
   30.16686,
   25.34945,
   21.05844,
   17.29431,
   14.04807,
   12.8507,
   11.96887,
   10.72413,
   9.863488,
   9.218809,
   8.295126,
   8.295126};
   graph = new TGraph(59,up_fx10,up_fy10);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up10 = new TH1F("Graph_up10","Projection of upf DSCB fit",100,0.2251831,1.520897);
   Graph_up10->SetMinimum(7.465614);
   Graph_up10->SetMaximum(113.155);
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
   
   TH1D *frame_3bf66890__38 = new TH1D("frame_3bf66890__38","p_T Balance",25,0,2);
   frame_3bf66890__38->SetBinContent(1,119.041);
   frame_3bf66890__38->SetMinimum(-5.668618);
   frame_3bf66890__38->SetMaximum(119.041);
   frame_3bf66890__38->SetEntries(1);
   frame_3bf66890__38->SetDirectory(0);
   frame_3bf66890__38->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf66890__38->SetLineColor(ci);
   frame_3bf66890__38->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf66890__38->GetXaxis()->SetLabelFont(42);
   frame_3bf66890__38->GetXaxis()->SetTitleOffset(1);
   frame_3bf66890__38->GetXaxis()->SetTitleFont(42);
   frame_3bf66890__38->GetYaxis()->SetTitle("1/Events");
   frame_3bf66890__38->GetYaxis()->SetLabelFont(42);
   frame_3bf66890__38->GetYaxis()->SetTitleFont(42);
   frame_3bf66890__38->GetZaxis()->SetLabelFont(42);
   frame_3bf66890__38->GetZaxis()->SetTitleOffset(1);
   frame_3bf66890__38->GetZaxis()->SetTitleFont(42);
   frame_3bf66890__38->Draw("AXISSAME");
   
   TH1D *norm_u__39 = new TH1D("norm_u__39","",25,0,2);
   norm_u__39->SetBinContent(3,2.692057);
   norm_u__39->SetBinContent(4,4.048192);
   norm_u__39->SetBinContent(5,8.25489);
   norm_u__39->SetBinContent(6,12.36158);
   norm_u__39->SetBinContent(7,28.00796);
   norm_u__39->SetBinContent(8,38.1086);
   norm_u__39->SetBinContent(9,62.89472);
   norm_u__39->SetBinContent(10,79.03357);
   norm_u__39->SetBinContent(11,106.2732);
   norm_u__39->SetBinContent(12,107.0874);
   norm_u__39->SetBinContent(13,83.05734);
   norm_u__39->SetBinContent(14,61.1104);
   norm_u__39->SetBinContent(15,43.21013);
   norm_u__39->SetBinContent(16,21.24773);
   norm_u__39->SetBinContent(17,9.946017);
   norm_u__39->SetBinContent(18,5.411954);
   norm_u__39->SetBinContent(19,2.349978);
   norm_u__39->SetBinContent(20,1.624463);
   norm_u__39->SetBinContent(21,0.6284212);
   norm_u__39->SetBinContent(22,0.342915);
   norm_u__39->SetBinContent(23,0.1998825);
   norm_u__39->SetBinContent(24,0.03146754);
   norm_u__39->SetBinContent(25,0.1632003);
   norm_u__39->SetBinContent(26,0.2810323);
   norm_u__39->SetBinError(3,0.9297343);
   norm_u__39->SetBinError(4,0.957494);
   norm_u__39->SetBinError(5,1.675869);
   norm_u__39->SetBinError(6,2.002482);
   norm_u__39->SetBinError(7,3.150916);
   norm_u__39->SetBinError(8,3.696623);
   norm_u__39->SetBinError(9,4.837113);
   norm_u__39->SetBinError(10,5.449904);
   norm_u__39->SetBinError(11,6.234398);
   norm_u__39->SetBinError(12,6.284999);
   norm_u__39->SetBinError(13,5.469787);
   norm_u__39->SetBinError(14,4.598321);
   norm_u__39->SetBinError(15,3.77043);
   norm_u__39->SetBinError(16,2.584726);
   norm_u__39->SetBinError(17,1.70556);
   norm_u__39->SetBinError(18,1.27317);
   norm_u__39->SetBinError(19,0.7041262);
   norm_u__39->SetBinError(20,0.5135353);
   norm_u__39->SetBinError(21,0.3039048);
   norm_u__39->SetBinError(22,0.2245888);
   norm_u__39->SetBinError(23,0.1869164);
   norm_u__39->SetBinError(24,0.03146754);
   norm_u__39->SetBinError(25,0.1632003);
   norm_u__39->SetBinError(26,0.1283891);
   norm_u__39->SetEntries(3107);
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
   entry=leg->AddEntry("frame_x_u2_3bf66890","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.880064 #pm 0.008751","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.209922 #pm 0.007598","");
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
   
   TH1D *frame_3bf66890_copy__40 = new TH1D("frame_3bf66890_copy__40","p_T Balance",25,0,2);
   frame_3bf66890_copy__40->SetBinContent(1,119.041);
   frame_3bf66890_copy__40->SetMinimum(-5.668618);
   frame_3bf66890_copy__40->SetMaximum(119.041);
   frame_3bf66890_copy__40->SetEntries(1);
   frame_3bf66890_copy__40->SetDirectory(0);
   frame_3bf66890_copy__40->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf66890_copy__40->SetLineColor(ci);
   frame_3bf66890_copy__40->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf66890_copy__40->GetXaxis()->SetLabelFont(42);
   frame_3bf66890_copy__40->GetXaxis()->SetTitleOffset(1);
   frame_3bf66890_copy__40->GetXaxis()->SetTitleFont(42);
   frame_3bf66890_copy__40->GetYaxis()->SetTitle("1/Events");
   frame_3bf66890_copy__40->GetYaxis()->SetLabelFont(42);
   frame_3bf66890_copy__40->GetYaxis()->SetTitleFont(42);
   frame_3bf66890_copy__40->GetZaxis()->SetLabelFont(42);
   frame_3bf66890_copy__40->GetZaxis()->SetTitleOffset(1);
   frame_3bf66890_copy__40->GetZaxis()->SetTitleFont(42);
   frame_3bf66890_copy__40->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-13.89177,2.25,125.026);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3bf75e60__41 = new TH1D("frame_3bf75e60__41","p_T Balance",25,0,2);
   frame_3bf75e60__41->SetBinContent(1,122.2476);
   frame_3bf75e60__41->SetMaximum(122.2476);
   frame_3bf75e60__41->SetEntries(1);
   frame_3bf75e60__41->SetDirectory(0);
   frame_3bf75e60__41->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf75e60__41->SetLineColor(ci);
   frame_3bf75e60__41->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf75e60__41->GetXaxis()->SetLabelFont(42);
   frame_3bf75e60__41->GetXaxis()->SetTitleOffset(1);
   frame_3bf75e60__41->GetXaxis()->SetTitleFont(42);
   frame_3bf75e60__41->GetYaxis()->SetTitle("1/Events");
   frame_3bf75e60__41->GetYaxis()->SetLabelFont(42);
   frame_3bf75e60__41->GetYaxis()->SetTitleFont(42);
   frame_3bf75e60__41->GetZaxis()->SetLabelFont(42);
   frame_3bf75e60__41->GetZaxis()->SetTitleOffset(1);
   frame_3bf75e60__41->GetZaxis()->SetTitleFont(42);
   frame_3bf75e60__41->Draw("FUNC");
   
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
   4.168003,
   4.93329,
   11.15087,
   18.82351,
   28.31049,
   40.15085,
   65.82582,
   82.90276,
   110.1019,
   91.87426,
   74.59898,
   55.03524,
   31.57237,
   18.15507,
   11.74277,
   4.147677,
   2.175228,
   1.151445,
   0.448652,
   0.5457745,
   0.09242618,
   0,
   0.0704615};
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
   1.139958,
   1.041493,
   1.894319,
   2.493354,
   3.118632,
   3.721819,
   4.876536,
   5.45702,
   6.324361,
   5.690174,
   5.124545,
   4.284857,
   3.048253,
   2.392177,
   1.848,
   1.069705,
   0.6721494,
   0.508825,
   0.2041149,
   0.298008,
   0.05781809,
   0,
   0.05553056};
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
   1.139958,
   1.041493,
   1.894319,
   2.493354,
   3.118632,
   3.721819,
   4.876536,
   5.45702,
   6.324361,
   5.690174,
   5.124545,
   4.284857,
   3.048253,
   2.392177,
   1.848,
   1.069705,
   0.6721494,
   0.508825,
   0.2041149,
   0.298008,
   0.05781809,
   0,
   0.05553056};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3011,h_dh_down2_fy3011,h_dh_down2_felx3011,h_dh_down2_fehx3011,h_dh_down2_fely3011,h_dh_down2_fehy3011);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23011 = new TH1F("Graph_h_dh_down23011","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23011->SetMinimum(0);
   Graph_h_dh_down23011->SetMaximum(128.0689);
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
   
   Double_t down_fx11[58] = {
   0.3117862,
   0.3551755,
   0.3985648,
   0.4202595,
   0.4419541,
   0.4636488,
   0.4853434,
   0.5070381,
   0.5287327,
   0.5504274,
   0.5612747,
   0.572122,
   0.5829694,
   0.5938167,
   0.6155113,
   0.6589006,
   0.7022899,
   0.7239846,
   0.7456792,
   0.7673739,
   0.7782212,
   0.7890685,
   0.7999159,
   0.8107632,
   0.8216105,
   0.8324578,
   0.8433052,
   0.8541525,
   0.8649998,
   0.8758471,
   0.8866945,
   0.8975418,
   0.9083891,
   0.9192365,
   0.9300838,
   0.9409311,
   0.9517784,
   0.9626258,
   0.9843204,
   1.006015,
   1.02771,
   1.049404,
   1.092794,
   1.114488,
   1.136183,
   1.157878,
   1.179572,
   1.201267,
   1.222962,
   1.244656,
   1.266351,
   1.288046,
   1.30974,
   1.331435,
   1.353129,
   1.374824,
   1.396519,
   1.396519};
   Double_t down_fy11[58] = {
   9.179081,
   11.20607,
   13.82486,
   15.42149,
   17.25545,
   19.37034,
   21.81945,
   24.66821,
   27.99749,
   31.90794,
   34.11933,
   36.52568,
   39.14798,
   41.9867,
   47.93634,
   60.41736,
   72.80811,
   78.59306,
   83.89168,
   88.54903,
   90.59206,
   92.42278,
   94.02655,
   95.39036,
   96.50306,
   97.35545,
   97.94042,
   98.2531,
   98.29086,
   98.05338,
   97.54265,
   96.76295,
   95.72078,
   94.42477,
   92.88556,
   91.11566,
   89.12929,
   86.94215,
   82.03478,
   76.54131,
   70.61941,
   64.42917,
   51.85495,
   45.74456,
   39.90423,
   34.42141,
   29.36086,
   24.76504,
   20.65569,
   17.03611,
   13.89414,
   11.20529,
   8.93603,
   7.046875,
   5.49514,
   4.237319,
   3.230977,
   3.230977};
   graph = new TGraph(58,down_fx11,down_fy11);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down11 = new TH1F("Graph_down11","Projection of downf DSCB fit",100,0.203313,1.504992);
   Graph_down11->SetMinimum(2.90788);
   Graph_down11->SetMaximum(107.7968);
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
   
   TH1D *frame_3bf75e60__42 = new TH1D("frame_3bf75e60__42","p_T Balance",25,0,2);
   frame_3bf75e60__42->SetBinContent(1,122.2476);
   frame_3bf75e60__42->SetMaximum(122.2476);
   frame_3bf75e60__42->SetEntries(1);
   frame_3bf75e60__42->SetDirectory(0);
   frame_3bf75e60__42->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf75e60__42->SetLineColor(ci);
   frame_3bf75e60__42->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf75e60__42->GetXaxis()->SetLabelFont(42);
   frame_3bf75e60__42->GetXaxis()->SetTitleOffset(1);
   frame_3bf75e60__42->GetXaxis()->SetTitleFont(42);
   frame_3bf75e60__42->GetYaxis()->SetTitle("1/Events");
   frame_3bf75e60__42->GetYaxis()->SetLabelFont(42);
   frame_3bf75e60__42->GetYaxis()->SetTitleFont(42);
   frame_3bf75e60__42->GetZaxis()->SetLabelFont(42);
   frame_3bf75e60__42->GetZaxis()->SetTitleOffset(1);
   frame_3bf75e60__42->GetZaxis()->SetTitleFont(42);
   frame_3bf75e60__42->Draw("AXISSAME");
   
   TH1D *norm_d__43 = new TH1D("norm_d__43","",25,0,2);
   norm_d__43->SetBinContent(3,4.168003);
   norm_d__43->SetBinContent(4,4.933289);
   norm_d__43->SetBinContent(5,11.15087);
   norm_d__43->SetBinContent(6,18.8235);
   norm_d__43->SetBinContent(7,28.31049);
   norm_d__43->SetBinContent(8,40.15085);
   norm_d__43->SetBinContent(9,65.82582);
   norm_d__43->SetBinContent(10,82.90276);
   norm_d__43->SetBinContent(11,110.1019);
   norm_d__43->SetBinContent(12,91.87426);
   norm_d__43->SetBinContent(13,74.59898);
   norm_d__43->SetBinContent(14,55.03524);
   norm_d__43->SetBinContent(15,31.57237);
   norm_d__43->SetBinContent(16,18.15507);
   norm_d__43->SetBinContent(17,11.74277);
   norm_d__43->SetBinContent(18,4.147677);
   norm_d__43->SetBinContent(19,2.175228);
   norm_d__43->SetBinContent(20,1.151445);
   norm_d__43->SetBinContent(21,0.448652);
   norm_d__43->SetBinContent(22,0.5457745);
   norm_d__43->SetBinContent(23,0.09242618);
   norm_d__43->SetBinContent(25,0.0704615);
   norm_d__43->SetBinContent(26,0.1977193);
   norm_d__43->SetBinError(3,1.139958);
   norm_d__43->SetBinError(4,1.041493);
   norm_d__43->SetBinError(5,1.894319);
   norm_d__43->SetBinError(6,2.493354);
   norm_d__43->SetBinError(7,3.118632);
   norm_d__43->SetBinError(8,3.721819);
   norm_d__43->SetBinError(9,4.876536);
   norm_d__43->SetBinError(10,5.45702);
   norm_d__43->SetBinError(11,6.324361);
   norm_d__43->SetBinError(12,5.690174);
   norm_d__43->SetBinError(13,5.124545);
   norm_d__43->SetBinError(14,4.284857);
   norm_d__43->SetBinError(15,3.048253);
   norm_d__43->SetBinError(16,2.392177);
   norm_d__43->SetBinError(17,1.848);
   norm_d__43->SetBinError(18,1.069705);
   norm_d__43->SetBinError(19,0.6721494);
   norm_d__43->SetBinError(20,0.508825);
   norm_d__43->SetBinError(21,0.2041149);
   norm_d__43->SetBinError(22,0.298008);
   norm_d__43->SetBinError(23,0.05781809);
   norm_d__43->SetBinError(25,0.05553056);
   norm_d__43->SetBinError(26,0.08967208);
   norm_d__43->SetEntries(3194);
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
   entry=leg->AddEntry("frame_x_d2_3bf75e60","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.861076 #pm 0.008981","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.204842 #pm 0.007963","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.985000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3bf75e60_copy__44 = new TH1D("frame_3bf75e60_copy__44","p_T Balance",25,0,2);
   frame_3bf75e60_copy__44->SetBinContent(1,122.2476);
   frame_3bf75e60_copy__44->SetMaximum(122.2476);
   frame_3bf75e60_copy__44->SetEntries(1);
   frame_3bf75e60_copy__44->SetDirectory(0);
   frame_3bf75e60_copy__44->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf75e60_copy__44->SetLineColor(ci);
   frame_3bf75e60_copy__44->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf75e60_copy__44->GetXaxis()->SetLabelFont(42);
   frame_3bf75e60_copy__44->GetXaxis()->SetTitleOffset(1);
   frame_3bf75e60_copy__44->GetXaxis()->SetTitleFont(42);
   frame_3bf75e60_copy__44->GetYaxis()->SetTitle("1/Events");
   frame_3bf75e60_copy__44->GetYaxis()->SetLabelFont(42);
   frame_3bf75e60_copy__44->GetYaxis()->SetTitleFont(42);
   frame_3bf75e60_copy__44->GetZaxis()->SetLabelFont(42);
   frame_3bf75e60_copy__44->GetZaxis()->SetTitleOffset(1);
   frame_3bf75e60_copy__44->GetZaxis()->SetTitleFont(42);
   frame_3bf75e60_copy__44->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-13.81217,2.25,124.3095);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3bf5e8b0__45 = new TH1D("frame_3bf5e8b0__45","p_T Balance",25,0,2);
   frame_3bf5e8b0__45->SetBinContent(1,121.5471);
   frame_3bf5e8b0__45->SetMaximum(121.5471);
   frame_3bf5e8b0__45->SetEntries(1);
   frame_3bf5e8b0__45->SetDirectory(0);
   frame_3bf5e8b0__45->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf5e8b0__45->SetLineColor(ci);
   frame_3bf5e8b0__45->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf5e8b0__45->GetXaxis()->SetLabelFont(42);
   frame_3bf5e8b0__45->GetXaxis()->SetTitleOffset(1);
   frame_3bf5e8b0__45->GetXaxis()->SetTitleFont(42);
   frame_3bf5e8b0__45->GetYaxis()->SetTitle("1/Events");
   frame_3bf5e8b0__45->GetYaxis()->SetLabelFont(42);
   frame_3bf5e8b0__45->GetYaxis()->SetTitleFont(42);
   frame_3bf5e8b0__45->GetZaxis()->SetLabelFont(42);
   frame_3bf5e8b0__45->GetZaxis()->SetTitleOffset(1);
   frame_3bf5e8b0__45->GetZaxis()->SetTitleFont(42);
   frame_3bf5e8b0__45->Draw("FUNC");
   
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
   3,
   7,
   6,
   17,
   33,
   54,
   66,
   96,
   105,
   84,
   87,
   62,
   46,
   27,
   13,
   4,
   5,
   0,
   0,
   3,
   0,
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
   1.632705,
   2.58147,
   2.379931,
   4.082184,
   5.715302,
   7.32564,
   8.103403,
   9.780867,
   9.759142,
   9.146873,
   9.30942,
   7.852713,
   6.757581,
   5.163771,
   3.558662,
   1.914339,
   2.159691,
   0,
   0,
   1.632705,
   0,
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
   2.918186,
   3.770281,
   3.583642,
   5.203719,
   6.802567,
   8.39385,
   9.165094,
   10.83201,
   10.75914,
   10.20155,
   10.36314,
   8.916365,
   7.831489,
   6.260244,
   4.697573,
   3.162753,
   3.382473,
   1.147874,
   1.147874,
   2.918186,
   1.147874,
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
   Graph_h_dh_data23012->SetMaximum(127.3351);
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
   0.2501317,
   0.298326,
   0.3224231,
   0.3344717,
   0.3465202,
   0.3706174,
   0.3947145,
   0.4188116,
   0.4429088,
   0.4670059,
   0.4911031,
   0.5152002,
   0.5392973,
   0.5633945,
   0.5874916,
   0.6356859,
   0.6838802,
   0.7079773,
   0.7320744,
   0.7561716,
   0.7682201,
   0.7802687,
   0.7923173,
   0.8043658,
   0.8164144,
   0.828463,
   0.8405115,
   0.8525601,
   0.8646087,
   0.8766573,
   0.8887058,
   0.9007544,
   0.912803,
   0.9248515,
   0.9369001,
   0.9489487,
   0.9609972,
   0.9730458,
   0.9971429,
   1.02124,
   1.045337,
   1.069434,
   1.117629,
   1.141726,
   1.165823,
   1.18992,
   1.214017,
   1.238114,
   1.262211,
   1.286309,
   1.310406,
   1.334503,
   1.3586,
   1.382697,
   1.406794,
   1.430891,
   1.454989,
   1.454989};
   Double_t observation_fy12[58] = {
   6.193881,
   6.39851,
   6.597391,
   6.780852,
   7.238963,
   9.203263,
   11.56708,
   14.37215,
   17.65373,
   21.43717,
   25.73444,
   30.54066,
   35.83096,
   41.55802,
   47.65052,
   60.52605,
   73.43151,
   79.50182,
   85.09187,
   90.03584,
   92.21684,
   94.1801,
   95.90961,
   97.39109,
   98.61214,
   99.56247,
   100.234,
   100.621,
   100.7201,
   100.5305,
   100.0538,
   99.29406,
   98.25783,
   96.95388,
   95.39317,
   93.58871,
   91.55535,
   89.3096,
   84.25373,
   78.5772,
   72.44698,
   66.03291,
   53.0017,
   46.67443,
   40.63354,
   34.97088,
   29.75397,
   25.02647,
   20.80993,
   17.10638,
   13.90151,
   11.16817,
   8.869898,
   6.964205,
   5.405562,
   4.147883,
   3.146505,
   3.146505};
   graph = new TGraph(58,observation_fx12,observation_fy12);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation12 = new TH1F("Graph_observation12","Projection of obsf DSCB fit",100,0.129646,1.575474);
   Graph_observation12->SetMinimum(2.831855);
   Graph_observation12->SetMaximum(110.4774);
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
   
   TH1D *frame_3bf5e8b0__46 = new TH1D("frame_3bf5e8b0__46","p_T Balance",25,0,2);
   frame_3bf5e8b0__46->SetBinContent(1,121.5471);
   frame_3bf5e8b0__46->SetMaximum(121.5471);
   frame_3bf5e8b0__46->SetEntries(1);
   frame_3bf5e8b0__46->SetDirectory(0);
   frame_3bf5e8b0__46->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf5e8b0__46->SetLineColor(ci);
   frame_3bf5e8b0__46->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf5e8b0__46->GetXaxis()->SetLabelFont(42);
   frame_3bf5e8b0__46->GetXaxis()->SetTitleOffset(1);
   frame_3bf5e8b0__46->GetXaxis()->SetTitleFont(42);
   frame_3bf5e8b0__46->GetYaxis()->SetTitle("1/Events");
   frame_3bf5e8b0__46->GetYaxis()->SetLabelFont(42);
   frame_3bf5e8b0__46->GetYaxis()->SetTitleFont(42);
   frame_3bf5e8b0__46->GetZaxis()->SetLabelFont(42);
   frame_3bf5e8b0__46->GetZaxis()->SetTitleOffset(1);
   frame_3bf5e8b0__46->GetZaxis()->SetTitleFont(42);
   frame_3bf5e8b0__46->Draw("AXISSAME");
   
   TH1D *norm_o__47 = new TH1D("norm_o__47","",25,0,2);
   norm_o__47->SetBinContent(3,3);
   norm_o__47->SetBinContent(4,7);
   norm_o__47->SetBinContent(5,6);
   norm_o__47->SetBinContent(6,17);
   norm_o__47->SetBinContent(7,33);
   norm_o__47->SetBinContent(8,54);
   norm_o__47->SetBinContent(9,66);
   norm_o__47->SetBinContent(10,96);
   norm_o__47->SetBinContent(11,105);
   norm_o__47->SetBinContent(12,84);
   norm_o__47->SetBinContent(13,87);
   norm_o__47->SetBinContent(14,62);
   norm_o__47->SetBinContent(15,46);
   norm_o__47->SetBinContent(16,27);
   norm_o__47->SetBinContent(17,13);
   norm_o__47->SetBinContent(18,4);
   norm_o__47->SetBinContent(19,5);
   norm_o__47->SetBinContent(22,3);
   norm_o__47->SetMinimum(0);
   norm_o__47->SetMaximum(231);
   norm_o__47->SetEntries(718);
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
   entry=leg->AddEntry("frame_x_o2_3bf5e8b0","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.862719 #pm 0.008683","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.224949 #pm 0.006684","");
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
   
   TH1D *frame_3bf5e8b0_copy__48 = new TH1D("frame_3bf5e8b0_copy__48","p_T Balance",25,0,2);
   frame_3bf5e8b0_copy__48->SetBinContent(1,121.5471);
   frame_3bf5e8b0_copy__48->SetMaximum(121.5471);
   frame_3bf5e8b0_copy__48->SetEntries(1);
   frame_3bf5e8b0_copy__48->SetDirectory(0);
   frame_3bf5e8b0_copy__48->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf5e8b0_copy__48->SetLineColor(ci);
   frame_3bf5e8b0_copy__48->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf5e8b0_copy__48->GetXaxis()->SetLabelFont(42);
   frame_3bf5e8b0_copy__48->GetXaxis()->SetTitleOffset(1);
   frame_3bf5e8b0_copy__48->GetXaxis()->SetTitleFont(42);
   frame_3bf5e8b0_copy__48->GetYaxis()->SetTitle("1/Events");
   frame_3bf5e8b0_copy__48->GetYaxis()->SetLabelFont(42);
   frame_3bf5e8b0_copy__48->GetYaxis()->SetTitleFont(42);
   frame_3bf5e8b0_copy__48->GetZaxis()->SetLabelFont(42);
   frame_3bf5e8b0_copy__48->GetZaxis()->SetTitleOffset(1);
   frame_3bf5e8b0_copy__48->GetZaxis()->SetTitleFont(42);
   frame_3bf5e8b0_copy__48->Draw("sameaxis");
   
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
