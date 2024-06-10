void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_3__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 17:52:15 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-8.377808,2.25,63.06086);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3bea2710__33 = new TH1D("frame_3bea2710__33","p_T Balance",25,0,2);
   frame_3bea2710__33->SetBinContent(1,55.917);
   frame_3bea2710__33->SetMinimum(-2.662714);
   frame_3bea2710__33->SetMaximum(55.917);
   frame_3bea2710__33->SetEntries(1);
   frame_3bea2710__33->SetDirectory(0);
   frame_3bea2710__33->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_3bea2710__33->SetLineColor(ci);
   frame_3bea2710__33->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bea2710__33->GetXaxis()->SetLabelFont(42);
   frame_3bea2710__33->GetXaxis()->SetTitleOffset(1);
   frame_3bea2710__33->GetXaxis()->SetTitleFont(42);
   frame_3bea2710__33->GetYaxis()->SetTitle("1/Events");
   frame_3bea2710__33->GetYaxis()->SetLabelFont(42);
   frame_3bea2710__33->GetYaxis()->SetTitleFont(42);
   frame_3bea2710__33->GetZaxis()->SetLabelFont(42);
   frame_3bea2710__33->GetZaxis()->SetTitleOffset(1);
   frame_3bea2710__33->GetZaxis()->SetTitleFont(42);
   frame_3bea2710__33->Draw("FUNC");
   
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
   1.771806,
   3.419397,
   3.90882,
   8.333464,
   15.39752,
   22.37024,
   27.28138,
   37.48637,
   48.75305,
   40.51983,
   28.5589,
   24.72455,
   11.6647,
   8.370609,
   3.166236,
   0.3557563,
   1.032836,
   0.3978263,
   0.09068283,
   0.1029369,
   0.07384692,
   0.00981989,
   0.09211125};
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
   0.7040314,
   1.316759,
   1.006606,
   1.845527,
   2.405211,
   2.917478,
   3.392253,
   3.718791,
   4.50123,
   4.210875,
   3.156841,
   3.197198,
   2.155338,
   1.935928,
   0.9447178,
   0.2364105,
   0.4938005,
   0.2465501,
   0.070544,
   0.09010114,
   0.05222372,
   0.009819891,
   0.09211125};
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
   0.7040314,
   1.316759,
   1.006606,
   1.845527,
   2.405211,
   2.917478,
   3.392253,
   3.718791,
   4.50123,
   4.210875,
   3.156841,
   3.197198,
   2.155338,
   1.935928,
   0.9447178,
   0.2364105,
   0.4938005,
   0.2465501,
   0.070544,
   0.09010114,
   0.05222372,
   0.009819891,
   0.09211125};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3009,h_dh_central2_fy3009,h_dh_central2_felx3009,h_dh_central2_fehx3009,h_dh_central2_fely3009,h_dh_central2_fehy3009);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23009 = new TH1F("Graph_h_dh_central23009","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23009->SetMinimum(-5.325428);
   Graph_h_dh_central23009->SetMaximum(58.57971);
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
   0.3702515,
   0.3898223,
   0.4093931,
   0.4289638,
   0.4485346,
   0.4681053,
   0.4876761,
   0.5072469,
   0.5268176,
   0.5463884,
   0.5659591,
   0.5855299,
   0.6051007,
   0.6442422,
   0.6833837,
   0.7029545,
   0.7225252,
   0.742096,
   0.7616668,
   0.7812375,
   0.7910229,
   0.8008083,
   0.8105937,
   0.8203791,
   0.8301644,
   0.8399498,
   0.8497352,
   0.8595206,
   0.869306,
   0.8790913,
   0.8888767,
   0.8986621,
   0.9084475,
   0.9182329,
   0.9378036,
   0.9573744,
   0.9769451,
   0.9965159,
   1.016087,
   1.035657,
   1.074799,
   1.09437,
   1.11394,
   1.133511,
   1.153082,
   1.172653,
   1.192224,
   1.211794,
   1.231365,
   1.250936,
   1.270507,
   1.280292,
   1.285185,
   1.290077,
   1.309648,
   1.34879,
   1.34879};
   Double_t Central_fy9[57] = {
   3.472068,
   4.259126,
   5.179501,
   6.244397,
   7.463254,
   8.843029,
   10.38745,
   12.09629,
   13.96467,
   15.98247,
   18.13396,
   20.39747,
   22.74549,
   27.55742,
   32.24945,
   34.43634,
   36.45414,
   38.25707,
   39.80264,
   41.05321,
   41.55783,
   41.97759,
   42.30979,
   42.5523,
   42.70355,
   42.76256,
   42.72895,
   42.60293,
   42.38533,
   42.07755,
   41.68158,
   41.19994,
   40.63571,
   39.99244,
   38.48525,
   36.7152,
   34.72423,
   32.55776,
   30.26297,
   27.88712,
   23.07244,
   20.71529,
   18.43843,
   16.27016,
   14.23295,
   12.34335,
   10.61222,
   9.045132,
   7.642907,
   6.40232,
   5.316812,
   4.829437,
   4.614921,
   4.495245,
   4.282672,
   4.113325,
   4.113325};
   TGraph *graph = new TGraph(57,Central_fx9,Central_fy9);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central9 = new TH1F("Graph_Central9","Projection of centralf DSCB fit",100,0.2723977,1.446643);
   Graph_Central9->SetMinimum(3.124861);
   Graph_Central9->SetMaximum(46.69161);
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
   
   TH1D *frame_3bea2710__34 = new TH1D("frame_3bea2710__34","p_T Balance",25,0,2);
   frame_3bea2710__34->SetBinContent(1,55.917);
   frame_3bea2710__34->SetMinimum(-2.662714);
   frame_3bea2710__34->SetMaximum(55.917);
   frame_3bea2710__34->SetEntries(1);
   frame_3bea2710__34->SetDirectory(0);
   frame_3bea2710__34->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bea2710__34->SetLineColor(ci);
   frame_3bea2710__34->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bea2710__34->GetXaxis()->SetLabelFont(42);
   frame_3bea2710__34->GetXaxis()->SetTitleOffset(1);
   frame_3bea2710__34->GetXaxis()->SetTitleFont(42);
   frame_3bea2710__34->GetYaxis()->SetTitle("1/Events");
   frame_3bea2710__34->GetYaxis()->SetLabelFont(42);
   frame_3bea2710__34->GetYaxis()->SetTitleFont(42);
   frame_3bea2710__34->GetZaxis()->SetLabelFont(42);
   frame_3bea2710__34->GetZaxis()->SetTitleOffset(1);
   frame_3bea2710__34->GetZaxis()->SetTitleFont(42);
   frame_3bea2710__34->Draw("AXISSAME");
   
   TH1D *norm_c__35 = new TH1D("norm_c__35","",25,0,2);
   norm_c__35->SetBinContent(3,1.771806);
   norm_c__35->SetBinContent(4,3.419397);
   norm_c__35->SetBinContent(5,3.90882);
   norm_c__35->SetBinContent(6,8.333464);
   norm_c__35->SetBinContent(7,15.39752);
   norm_c__35->SetBinContent(8,22.37024);
   norm_c__35->SetBinContent(9,27.28138);
   norm_c__35->SetBinContent(10,37.48637);
   norm_c__35->SetBinContent(11,48.75305);
   norm_c__35->SetBinContent(12,40.51983);
   norm_c__35->SetBinContent(13,28.5589);
   norm_c__35->SetBinContent(14,24.72455);
   norm_c__35->SetBinContent(15,11.6647);
   norm_c__35->SetBinContent(16,8.370609);
   norm_c__35->SetBinContent(17,3.166236);
   norm_c__35->SetBinContent(18,0.3557563);
   norm_c__35->SetBinContent(19,1.032836);
   norm_c__35->SetBinContent(20,0.3978263);
   norm_c__35->SetBinContent(21,0.09068284);
   norm_c__35->SetBinContent(22,0.1029369);
   norm_c__35->SetBinContent(23,0.07384692);
   norm_c__35->SetBinContent(24,0.009819891);
   norm_c__35->SetBinContent(25,0.09211125);
   norm_c__35->SetBinContent(26,0.1997706);
   norm_c__35->SetBinError(3,0.7040314);
   norm_c__35->SetBinError(4,1.316759);
   norm_c__35->SetBinError(5,1.006606);
   norm_c__35->SetBinError(6,1.845527);
   norm_c__35->SetBinError(7,2.405211);
   norm_c__35->SetBinError(8,2.917478);
   norm_c__35->SetBinError(9,3.392253);
   norm_c__35->SetBinError(10,3.718791);
   norm_c__35->SetBinError(11,4.50123);
   norm_c__35->SetBinError(12,4.210875);
   norm_c__35->SetBinError(13,3.156841);
   norm_c__35->SetBinError(14,3.197198);
   norm_c__35->SetBinError(15,2.155338);
   norm_c__35->SetBinError(16,1.935928);
   norm_c__35->SetBinError(17,0.9447178);
   norm_c__35->SetBinError(18,0.2364105);
   norm_c__35->SetBinError(19,0.4938005);
   norm_c__35->SetBinError(20,0.2465501);
   norm_c__35->SetBinError(21,0.070544);
   norm_c__35->SetBinError(22,0.09010114);
   norm_c__35->SetBinError(23,0.05222372);
   norm_c__35->SetBinError(24,0.009819891);
   norm_c__35->SetBinError(25,0.09211125);
   norm_c__35->SetBinError(26,0.1475179);
   norm_c__35->SetEntries(1424);
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
   entry=leg->AddEntry("frame_x_c2_3bea2710","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.841293 #pm 0.013361","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.210197 #pm 0.011176","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.995000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3bea2710_copy__36 = new TH1D("frame_3bea2710_copy__36","p_T Balance",25,0,2);
   frame_3bea2710_copy__36->SetBinContent(1,55.917);
   frame_3bea2710_copy__36->SetMinimum(-2.662714);
   frame_3bea2710_copy__36->SetMaximum(55.917);
   frame_3bea2710_copy__36->SetEntries(1);
   frame_3bea2710_copy__36->SetDirectory(0);
   frame_3bea2710_copy__36->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bea2710_copy__36->SetLineColor(ci);
   frame_3bea2710_copy__36->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bea2710_copy__36->GetXaxis()->SetLabelFont(42);
   frame_3bea2710_copy__36->GetXaxis()->SetTitleOffset(1);
   frame_3bea2710_copy__36->GetXaxis()->SetTitleFont(42);
   frame_3bea2710_copy__36->GetYaxis()->SetTitle("1/Events");
   frame_3bea2710_copy__36->GetYaxis()->SetLabelFont(42);
   frame_3bea2710_copy__36->GetYaxis()->SetTitleFont(42);
   frame_3bea2710_copy__36->GetZaxis()->SetLabelFont(42);
   frame_3bea2710_copy__36->GetZaxis()->SetTitleOffset(1);
   frame_3bea2710_copy__36->GetZaxis()->SetTitleFont(42);
   frame_3bea2710_copy__36->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-5.141899,2.25,59.13184);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3be4e930__37 = new TH1D("frame_3be4e930__37","p_T Balance",25,0,2);
   frame_3be4e930__37->SetBinContent(1,52.70447);
   frame_3be4e930__37->SetMaximum(52.70447);
   frame_3be4e930__37->SetEntries(1);
   frame_3be4e930__37->SetDirectory(0);
   frame_3be4e930__37->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3be4e930__37->SetLineColor(ci);
   frame_3be4e930__37->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3be4e930__37->GetXaxis()->SetLabelFont(42);
   frame_3be4e930__37->GetXaxis()->SetTitleOffset(1);
   frame_3be4e930__37->GetXaxis()->SetTitleFont(42);
   frame_3be4e930__37->GetYaxis()->SetTitle("1/Events");
   frame_3be4e930__37->GetYaxis()->SetLabelFont(42);
   frame_3be4e930__37->GetYaxis()->SetTitleFont(42);
   frame_3be4e930__37->GetZaxis()->SetLabelFont(42);
   frame_3be4e930__37->GetZaxis()->SetTitleOffset(1);
   frame_3be4e930__37->GetZaxis()->SetTitleFont(42);
   frame_3be4e930__37->Draw("FUNC");
   
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
   1.926763,
   2.512199,
   3.040782,
   8.433927,
   14.30878,
   18.93321,
   31.80526,
   38.34765,
   45.90664,
   36.45224,
   26.90839,
   26.98614,
   14.92302,
   9.247123,
   2.294397,
   0.3966329,
   1.170052,
   0.3960724,
   0.07216088,
   0.01344121,
   0.4685977,
   0.04705941,
   0.09159976};
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
   0.7387705,
   1.189231,
   0.7114503,
   1.855517,
   2.364938,
   2.664877,
   3.790566,
   3.762486,
   4.288092,
   3.844922,
   3.158179,
   3.417053,
   2.311346,
   1.870068,
   0.8292743,
   0.2370449,
   0.5186247,
   0.2446715,
   0.06629913,
   0.01091382,
   0.3557588,
   0.03853997,
   0.09159976};
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
   0.7387705,
   1.189231,
   0.7114503,
   1.855517,
   2.364938,
   2.664877,
   3.790566,
   3.762486,
   4.288092,
   3.844922,
   3.158179,
   3.417053,
   2.311346,
   1.870068,
   0.8292743,
   0.2370449,
   0.5186247,
   0.2446715,
   0.06629913,
   0.01091382,
   0.3557588,
   0.03853997,
   0.09159976};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3010,h_dh_up2_fy3010,h_dh_up2_felx3010,h_dh_up2_fehx3010,h_dh_up2_fely3010,h_dh_up2_fehy3010);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23010 = new TH1F("Graph_h_dh_up23010","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23010->SetMinimum(0);
   Graph_h_dh_up23010->SetMaximum(55.2142);
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
   
   Double_t up_fx10[54] = {
   0.347995,
   0.3683947,
   0.3887944,
   0.4091941,
   0.4295938,
   0.4499935,
   0.4703932,
   0.4907929,
   0.5111926,
   0.5315923,
   0.551992,
   0.5723917,
   0.5927914,
   0.6335908,
   0.6743902,
   0.6947899,
   0.7151896,
   0.7355893,
   0.755989,
   0.7763887,
   0.7865886,
   0.7967884,
   0.8069883,
   0.8171881,
   0.827388,
   0.8375878,
   0.8477877,
   0.8579875,
   0.8681874,
   0.8783872,
   0.8885871,
   0.8987869,
   0.9191866,
   0.9395863,
   0.959986,
   0.9803857,
   1.000785,
   1.021185,
   1.041585,
   1.082384,
   1.123184,
   1.143583,
   1.163983,
   1.184383,
   1.204782,
   1.225182,
   1.245582,
   1.265982,
   1.286381,
   1.306781,
   1.327181,
   1.34758,
   1.36798,
   1.36798};
   Double_t up_fy10[54] = {
   3.282028,
   4.026879,
   4.898359,
   5.907289,
   7.062873,
   8.372018,
   9.838627,
   11.4629,
   13.24067,
   15.16286,
   17.21504,
   19.37717,
   21.62361,
   26.24043,
   30.76353,
   32.88153,
   34.84365,
   36.60587,
   38.12707,
   39.37058,
   39.87832,
   40.30563,
   40.64981,
   40.90866,
   41.08051,
   41.16427,
   41.15938,
   41.06588,
   40.88437,
   40.61603,
   40.26256,
   39.82624,
   38.71657,
   37.3147,
   35.65486,
   33.77637,
   31.72217,
   29.53714,
   27.26651,
   22.64219,
   18.16477,
   16.06087,
   14.07874,
   12.23528,
   10.54192,
   9.00495,
   7.626028,
   6.402816,
   5.329658,
   4.398283,
   3.598509,
   2.91889,
   2.347299,
   2.347299};
   graph = new TGraph(54,up_fx10,up_fy10);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up10 = new TH1F("Graph_up10","Projection of upf DSCB fit",100,0.2459965,1.469979);
   Graph_up10->SetMinimum(2.112569);
   Graph_up10->SetMaximum(45.04596);
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
   
   TH1D *frame_3be4e930__38 = new TH1D("frame_3be4e930__38","p_T Balance",25,0,2);
   frame_3be4e930__38->SetBinContent(1,52.70447);
   frame_3be4e930__38->SetMaximum(52.70447);
   frame_3be4e930__38->SetEntries(1);
   frame_3be4e930__38->SetDirectory(0);
   frame_3be4e930__38->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3be4e930__38->SetLineColor(ci);
   frame_3be4e930__38->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3be4e930__38->GetXaxis()->SetLabelFont(42);
   frame_3be4e930__38->GetXaxis()->SetTitleOffset(1);
   frame_3be4e930__38->GetXaxis()->SetTitleFont(42);
   frame_3be4e930__38->GetYaxis()->SetTitle("1/Events");
   frame_3be4e930__38->GetYaxis()->SetLabelFont(42);
   frame_3be4e930__38->GetYaxis()->SetTitleFont(42);
   frame_3be4e930__38->GetZaxis()->SetLabelFont(42);
   frame_3be4e930__38->GetZaxis()->SetTitleOffset(1);
   frame_3be4e930__38->GetZaxis()->SetTitleFont(42);
   frame_3be4e930__38->Draw("AXISSAME");
   
   TH1D *norm_u__39 = new TH1D("norm_u__39","",25,0,2);
   norm_u__39->SetBinContent(3,1.926763);
   norm_u__39->SetBinContent(4,2.512199);
   norm_u__39->SetBinContent(5,3.040782);
   norm_u__39->SetBinContent(6,8.433927);
   norm_u__39->SetBinContent(7,14.30878);
   norm_u__39->SetBinContent(8,18.93321);
   norm_u__39->SetBinContent(9,31.80526);
   norm_u__39->SetBinContent(10,38.34765);
   norm_u__39->SetBinContent(11,45.90664);
   norm_u__39->SetBinContent(12,36.45224);
   norm_u__39->SetBinContent(13,26.90839);
   norm_u__39->SetBinContent(14,26.98614);
   norm_u__39->SetBinContent(15,14.92302);
   norm_u__39->SetBinContent(16,9.247123);
   norm_u__39->SetBinContent(17,2.294397);
   norm_u__39->SetBinContent(18,0.3966329);
   norm_u__39->SetBinContent(19,1.170052);
   norm_u__39->SetBinContent(20,0.3960724);
   norm_u__39->SetBinContent(21,0.07216087);
   norm_u__39->SetBinContent(22,0.01344121);
   norm_u__39->SetBinContent(23,0.4685977);
   norm_u__39->SetBinContent(24,0.04705941);
   norm_u__39->SetBinContent(25,0.09159976);
   norm_u__39->SetBinContent(26,0.1863946);
   norm_u__39->SetBinError(3,0.7387705);
   norm_u__39->SetBinError(4,1.189231);
   norm_u__39->SetBinError(5,0.7114503);
   norm_u__39->SetBinError(6,1.855517);
   norm_u__39->SetBinError(7,2.364938);
   norm_u__39->SetBinError(8,2.664877);
   norm_u__39->SetBinError(9,3.790566);
   norm_u__39->SetBinError(10,3.762486);
   norm_u__39->SetBinError(11,4.288092);
   norm_u__39->SetBinError(12,3.844922);
   norm_u__39->SetBinError(13,3.158179);
   norm_u__39->SetBinError(14,3.417053);
   norm_u__39->SetBinError(15,2.311346);
   norm_u__39->SetBinError(16,1.870068);
   norm_u__39->SetBinError(17,0.8292743);
   norm_u__39->SetBinError(18,0.2370449);
   norm_u__39->SetBinError(19,0.5186247);
   norm_u__39->SetBinError(20,0.2446715);
   norm_u__39->SetBinError(21,0.06629913);
   norm_u__39->SetBinError(22,0.01091382);
   norm_u__39->SetBinError(23,0.3557588);
   norm_u__39->SetBinError(24,0.03853997);
   norm_u__39->SetBinError(25,0.09159976);
   norm_u__39->SetBinError(26,0.1466006);
   norm_u__39->SetEntries(1391);
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
   entry=leg->AddEntry("frame_x_u2_3be4e930","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.843553 #pm 0.013644","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.217639 #pm 0.011170","");
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
   
   TH1D *frame_3be4e930_copy__40 = new TH1D("frame_3be4e930_copy__40","p_T Balance",25,0,2);
   frame_3be4e930_copy__40->SetBinContent(1,52.70447);
   frame_3be4e930_copy__40->SetMaximum(52.70447);
   frame_3be4e930_copy__40->SetEntries(1);
   frame_3be4e930_copy__40->SetDirectory(0);
   frame_3be4e930_copy__40->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3be4e930_copy__40->SetLineColor(ci);
   frame_3be4e930_copy__40->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3be4e930_copy__40->GetXaxis()->SetLabelFont(42);
   frame_3be4e930_copy__40->GetXaxis()->SetTitleOffset(1);
   frame_3be4e930_copy__40->GetXaxis()->SetTitleFont(42);
   frame_3be4e930_copy__40->GetYaxis()->SetTitle("1/Events");
   frame_3be4e930_copy__40->GetYaxis()->SetLabelFont(42);
   frame_3be4e930_copy__40->GetYaxis()->SetTitleFont(42);
   frame_3be4e930_copy__40->GetZaxis()->SetLabelFont(42);
   frame_3be4e930_copy__40->GetZaxis()->SetTitleOffset(1);
   frame_3be4e930_copy__40->GetZaxis()->SetTitleFont(42);
   frame_3be4e930_copy__40->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-9.059443,2.25,55.65086);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3be8e860__41 = new TH1D("frame_3be8e860__41","p_T Balance",25,0,2);
   frame_3be8e860__41->SetBinContent(1,54.35666);
   frame_3be8e860__41->SetMinimum(-2.588412);
   frame_3be8e860__41->SetMaximum(54.35666);
   frame_3be8e860__41->SetEntries(1);
   frame_3be8e860__41->SetDirectory(0);
   frame_3be8e860__41->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3be8e860__41->SetLineColor(ci);
   frame_3be8e860__41->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3be8e860__41->GetXaxis()->SetLabelFont(42);
   frame_3be8e860__41->GetXaxis()->SetTitleOffset(1);
   frame_3be8e860__41->GetXaxis()->SetTitleFont(42);
   frame_3be8e860__41->GetYaxis()->SetTitle("1/Events");
   frame_3be8e860__41->GetYaxis()->SetLabelFont(42);
   frame_3be8e860__41->GetYaxis()->SetTitleFont(42);
   frame_3be8e860__41->GetZaxis()->SetLabelFont(42);
   frame_3be8e860__41->GetZaxis()->SetTitleOffset(1);
   frame_3be8e860__41->GetZaxis()->SetTitleFont(42);
   frame_3be8e860__41->Draw("FUNC");
   
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
   1.835322,
   3.083042,
   4.962782,
   10.26472,
   19.13689,
   20.60723,
   28.90347,
   41.728,
   47.45663,
   41.63292,
   30.60369,
   21.88313,
   13.26687,
   10.57687,
   3.176118,
   0.5989632,
   0.8974869,
   0.2771445,
   0.05091007,
   0.243646,
   0.03666621,
   0.01372824,
   0.00162095};
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
   0.6991695,
   1.129126,
   1.262148,
   2.018371,
   2.740815,
   2.640024,
   3.450395,
   4.03446,
   4.311613,
   4.189095,
   3.414902,
   3.017235,
   2.321701,
   2.172504,
   0.9476216,
   0.3157085,
   0.4506676,
   0.1585437,
   0.04368737,
   0.1366585,
   0.03666622,
   0.01061454,
   0.00162095};
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
   0.6991695,
   1.129126,
   1.262148,
   2.018371,
   2.740815,
   2.640024,
   3.450395,
   4.03446,
   4.311613,
   4.189095,
   3.414902,
   3.017235,
   2.321701,
   2.172504,
   0.9476216,
   0.3157085,
   0.4506676,
   0.1585437,
   0.04368737,
   0.1366585,
   0.03666622,
   0.01061454,
   0.00162095};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3011,h_dh_down2_fy3011,h_dh_down2_felx3011,h_dh_down2_fehx3011,h_dh_down2_fely3011,h_dh_down2_fehy3011);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23011 = new TH1F("Graph_h_dh_down23011","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23011->SetMinimum(-5.176824);
   Graph_h_dh_down23011->SetMaximum(56.94507);
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
   
   Double_t down_fx11[57] = {
   0.3459452,
   0.3866599,
   0.4273746,
   0.447732,
   0.4680893,
   0.4884467,
   0.5088041,
   0.5291614,
   0.5495188,
   0.5698761,
   0.5902335,
   0.6105909,
   0.6309482,
   0.6513056,
   0.6716629,
   0.6920203,
   0.7123777,
   0.732735,
   0.7530924,
   0.7734497,
   0.7836284,
   0.7938071,
   0.8039858,
   0.8141644,
   0.8243431,
   0.8345218,
   0.8447005,
   0.8548792,
   0.8650578,
   0.8752365,
   0.8854152,
   0.8955939,
   0.9057726,
   0.9159512,
   0.9261299,
   0.9363086,
   0.956666,
   0.9770233,
   0.9973807,
   1.017738,
   1.038095,
   1.07881,
   1.099167,
   1.119525,
   1.139882,
   1.16024,
   1.180597,
   1.200954,
   1.221312,
   1.241669,
   1.262026,
   1.282384,
   1.302741,
   1.323098,
   1.343456,
   1.363813,
   1.363813};
   Double_t down_fy11[57] = {
   8.190505,
   9.44527,
   10.94979,
   11.81445,
   12.76617,
   13.81568,
   14.97529,
   16.25917,
   17.68362,
   19.26755,
   21.03286,
   23.00505,
   25.21392,
   27.69101,
   30.25281,
   32.73792,
   35.09093,
   37.25606,
   39.17937,
   40.81091,
   41.5033,
   42.10692,
   42.6176,
   43.03176,
   43.34648,
   43.55952,
   43.66938,
   43.67526,
   43.57712,
   43.37567,
   43.07234,
   42.66928,
   42.16934,
   41.57602,
   40.89343,
   40.12627,
   38.35951,
   36.32249,
   34.06722,
   31.64871,
   29.12284,
   23.96428,
   21.42976,
   18.98142,
   16.65322,
   14.47192,
   12.45698,
   10.62081,
   8.969343,
   7.502779,
   6.216445,
   5.101764,
   4.14722,
   3.339274,
   2.663211,
   2.103862,
   2.103862};
   graph = new TGraph(57,down_fx11,down_fy11);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down11 = new TH1F("Graph_down11","Projection of downf DSCB fit",100,0.2441584,1.4656);
   Graph_down11->SetMinimum(1.893476);
   Graph_down11->SetMaximum(47.8324);
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
   
   TH1D *frame_3be8e860__42 = new TH1D("frame_3be8e860__42","p_T Balance",25,0,2);
   frame_3be8e860__42->SetBinContent(1,54.35666);
   frame_3be8e860__42->SetMinimum(-2.588412);
   frame_3be8e860__42->SetMaximum(54.35666);
   frame_3be8e860__42->SetEntries(1);
   frame_3be8e860__42->SetDirectory(0);
   frame_3be8e860__42->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3be8e860__42->SetLineColor(ci);
   frame_3be8e860__42->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3be8e860__42->GetXaxis()->SetLabelFont(42);
   frame_3be8e860__42->GetXaxis()->SetTitleOffset(1);
   frame_3be8e860__42->GetXaxis()->SetTitleFont(42);
   frame_3be8e860__42->GetYaxis()->SetTitle("1/Events");
   frame_3be8e860__42->GetYaxis()->SetLabelFont(42);
   frame_3be8e860__42->GetYaxis()->SetTitleFont(42);
   frame_3be8e860__42->GetZaxis()->SetLabelFont(42);
   frame_3be8e860__42->GetZaxis()->SetTitleOffset(1);
   frame_3be8e860__42->GetZaxis()->SetTitleFont(42);
   frame_3be8e860__42->Draw("AXISSAME");
   
   TH1D *norm_d__43 = new TH1D("norm_d__43","",25,0,2);
   norm_d__43->SetBinContent(3,1.835322);
   norm_d__43->SetBinContent(4,3.083042);
   norm_d__43->SetBinContent(5,4.962783);
   norm_d__43->SetBinContent(6,10.26472);
   norm_d__43->SetBinContent(7,19.13689);
   norm_d__43->SetBinContent(8,20.60723);
   norm_d__43->SetBinContent(9,28.90348);
   norm_d__43->SetBinContent(10,41.72801);
   norm_d__43->SetBinContent(11,47.45663);
   norm_d__43->SetBinContent(12,41.63292);
   norm_d__43->SetBinContent(13,30.60369);
   norm_d__43->SetBinContent(14,21.88313);
   norm_d__43->SetBinContent(15,13.26687);
   norm_d__43->SetBinContent(16,10.57687);
   norm_d__43->SetBinContent(17,3.176118);
   norm_d__43->SetBinContent(18,0.5989632);
   norm_d__43->SetBinContent(19,0.8974869);
   norm_d__43->SetBinContent(20,0.2771445);
   norm_d__43->SetBinContent(21,0.05091007);
   norm_d__43->SetBinContent(22,0.243646);
   norm_d__43->SetBinContent(23,0.03666622);
   norm_d__43->SetBinContent(24,0.01372824);
   norm_d__43->SetBinContent(25,0.00162095);
   norm_d__43->SetBinContent(26,0.080793);
   norm_d__43->SetBinError(3,0.6991695);
   norm_d__43->SetBinError(4,1.129126);
   norm_d__43->SetBinError(5,1.262148);
   norm_d__43->SetBinError(6,2.018371);
   norm_d__43->SetBinError(7,2.740815);
   norm_d__43->SetBinError(8,2.640024);
   norm_d__43->SetBinError(9,3.450395);
   norm_d__43->SetBinError(10,4.03446);
   norm_d__43->SetBinError(11,4.311613);
   norm_d__43->SetBinError(12,4.189095);
   norm_d__43->SetBinError(13,3.414902);
   norm_d__43->SetBinError(14,3.017235);
   norm_d__43->SetBinError(15,2.321701);
   norm_d__43->SetBinError(16,2.172504);
   norm_d__43->SetBinError(17,0.9476216);
   norm_d__43->SetBinError(18,0.3157085);
   norm_d__43->SetBinError(19,0.4506676);
   norm_d__43->SetBinError(20,0.1585437);
   norm_d__43->SetBinError(21,0.04368737);
   norm_d__43->SetBinError(22,0.1366585);
   norm_d__43->SetBinError(23,0.03666622);
   norm_d__43->SetBinError(24,0.01061454);
   norm_d__43->SetBinError(25,0.00162095);
   norm_d__43->SetBinError(26,0.03950089);
   norm_d__43->SetEntries(1480);
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
   entry=leg->AddEntry("frame_x_d2_3be8e860","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.850402 #pm 0.014752","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.208468 #pm 0.014028","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.987000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3be8e860_copy__44 = new TH1D("frame_3be8e860_copy__44","p_T Balance",25,0,2);
   frame_3be8e860_copy__44->SetBinContent(1,54.35666);
   frame_3be8e860_copy__44->SetMinimum(-2.588412);
   frame_3be8e860_copy__44->SetMaximum(54.35666);
   frame_3be8e860_copy__44->SetEntries(1);
   frame_3be8e860_copy__44->SetDirectory(0);
   frame_3be8e860_copy__44->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3be8e860_copy__44->SetLineColor(ci);
   frame_3be8e860_copy__44->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3be8e860_copy__44->GetXaxis()->SetLabelFont(42);
   frame_3be8e860_copy__44->GetXaxis()->SetTitleOffset(1);
   frame_3be8e860_copy__44->GetXaxis()->SetTitleFont(42);
   frame_3be8e860_copy__44->GetYaxis()->SetTitle("1/Events");
   frame_3be8e860_copy__44->GetYaxis()->SetLabelFont(42);
   frame_3be8e860_copy__44->GetYaxis()->SetTitleFont(42);
   frame_3be8e860_copy__44->GetZaxis()->SetLabelFont(42);
   frame_3be8e860_copy__44->GetZaxis()->SetTitleOffset(1);
   frame_3be8e860_copy__44->GetZaxis()->SetTitleFont(42);
   frame_3be8e860_copy__44->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-7.572071,2.25,68.14864);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3be9d650__45 = new TH1D("frame_3be9d650__45","p_T Balance",25,0,2);
   frame_3be9d650__45->SetBinContent(1,66.63422);
   frame_3be9d650__45->SetMaximum(66.63422);
   frame_3be9d650__45->SetEntries(1);
   frame_3be9d650__45->SetDirectory(0);
   frame_3be9d650__45->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3be9d650__45->SetLineColor(ci);
   frame_3be9d650__45->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3be9d650__45->GetXaxis()->SetLabelFont(42);
   frame_3be9d650__45->GetXaxis()->SetTitleOffset(1);
   frame_3be9d650__45->GetXaxis()->SetTitleFont(42);
   frame_3be9d650__45->GetYaxis()->SetTitle("1/Events");
   frame_3be9d650__45->GetYaxis()->SetLabelFont(42);
   frame_3be9d650__45->GetYaxis()->SetTitleFont(42);
   frame_3be9d650__45->GetZaxis()->SetLabelFont(42);
   frame_3be9d650__45->GetZaxis()->SetTitleOffset(1);
   frame_3be9d650__45->GetZaxis()->SetTitleFont(42);
   frame_3be9d650__45->Draw("FUNC");
   
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
   1,
   1,
   3,
   11,
   15,
   29,
   41,
   55,
   48,
   53,
   40,
   28,
   11,
   8,
   5,
   2,
   2,
   2,
   0,
   0,
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
   0.8272462,
   0.8272462,
   1.632705,
   3.265579,
   3.82938,
   5.353932,
   6.376898,
   7.39358,
   6.903979,
   7.257065,
   6.298,
   5.259711,
   3.265579,
   2.768386,
   2.159691,
   1.291815,
   1.291815,
   1.291815,
   0,
   0,
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
   2.299527,
   2.299527,
   2.918186,
   4.416521,
   4.958738,
   6.44702,
   7.455185,
   8.461166,
   7.97633,
   8.325916,
   7.377261,
   6.354446,
   4.416521,
   3.945142,
   3.382473,
   2.63786,
   2.63786,
   2.63786,
   1.147874,
   1.147874,
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
   Graph_h_dh_data23012->SetMaximum(69.80728);
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
   
   Double_t observation_fx12[57] = {
   0.3136417,
   0.3341415,
   0.3546413,
   0.375141,
   0.3956408,
   0.4161405,
   0.4366403,
   0.4571401,
   0.4776398,
   0.4981396,
   0.5186394,
   0.5391391,
   0.5596389,
   0.5801386,
   0.6006384,
   0.6416379,
   0.6621377,
   0.6826375,
   0.7031372,
   0.723637,
   0.7441367,
   0.7543866,
   0.7646365,
   0.7748864,
   0.7851363,
   0.7953861,
   0.805636,
   0.8158859,
   0.8261358,
   0.8363857,
   0.8466356,
   0.8568854,
   0.8671353,
   0.8773852,
   0.8876351,
   0.897885,
   0.9081348,
   0.9286346,
   0.9491344,
   0.9696341,
   0.9901339,
   1.010634,
   1.051633,
   1.092633,
   1.113132,
   1.133632,
   1.154132,
   1.174632,
   1.195132,
   1.215631,
   1.236131,
   1.256631,
   1.277131,
   1.29763,
   1.31813,
   1.33863,
   1.33863};
   Double_t observation_fy12[57] = {
   2.345229,
   2.986815,
   3.767193,
   4.705587,
   5.820982,
   7.131242,
   8.652081,
   10.39591,
   12.3706,
   14.57825,
   17.01401,
   19.66503,
   22.50965,
   25.51698,
   28.64682,
   35.06955,
   38.24165,
   41.29806,
   44.16814,
   46.7816,
   49.07129,
   50.0753,
   50.97607,
   51.76732,
   52.4435,
   52.9998,
   53.43225,
   53.73773,
   53.91402,
   53.95986,
   53.8749,
   53.65977,
   53.31602,
   52.84613,
   52.2535,
   51.54234,
   50.7177,
   48.75174,
   46.40953,
   43.75329,
   40.85082,
   37.77263,
   31.3682,
   25.05808,
   22.07276,
   19.25537,
   16.63542,
   14.23318,
   12.06026,
   10.1204,
   8.410569,
   6.922126,
   5.64209,
   4.554357,
   3.640831,
   2.882442,
   2.882442};
   graph = new TGraph(57,observation_fx12,observation_fy12);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation12 = new TH1F("Graph_observation12","Projection of obsf DSCB fit",100,0.2111429,1.441129);
   Graph_observation12->SetMinimum(2.110706);
   Graph_observation12->SetMaximum(59.12132);
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
   
   TH1D *frame_3be9d650__46 = new TH1D("frame_3be9d650__46","p_T Balance",25,0,2);
   frame_3be9d650__46->SetBinContent(1,66.63422);
   frame_3be9d650__46->SetMaximum(66.63422);
   frame_3be9d650__46->SetEntries(1);
   frame_3be9d650__46->SetDirectory(0);
   frame_3be9d650__46->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3be9d650__46->SetLineColor(ci);
   frame_3be9d650__46->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3be9d650__46->GetXaxis()->SetLabelFont(42);
   frame_3be9d650__46->GetXaxis()->SetTitleOffset(1);
   frame_3be9d650__46->GetXaxis()->SetTitleFont(42);
   frame_3be9d650__46->GetYaxis()->SetTitle("1/Events");
   frame_3be9d650__46->GetYaxis()->SetLabelFont(42);
   frame_3be9d650__46->GetYaxis()->SetTitleFont(42);
   frame_3be9d650__46->GetZaxis()->SetLabelFont(42);
   frame_3be9d650__46->GetZaxis()->SetTitleOffset(1);
   frame_3be9d650__46->GetZaxis()->SetTitleFont(42);
   frame_3be9d650__46->Draw("AXISSAME");
   
   TH1D *norm_o__47 = new TH1D("norm_o__47","",25,0,2);
   norm_o__47->SetBinContent(3,1);
   norm_o__47->SetBinContent(4,1);
   norm_o__47->SetBinContent(5,3);
   norm_o__47->SetBinContent(6,11);
   norm_o__47->SetBinContent(7,15);
   norm_o__47->SetBinContent(8,29);
   norm_o__47->SetBinContent(9,41);
   norm_o__47->SetBinContent(10,55);
   norm_o__47->SetBinContent(11,48);
   norm_o__47->SetBinContent(12,53);
   norm_o__47->SetBinContent(13,40);
   norm_o__47->SetBinContent(14,28);
   norm_o__47->SetBinContent(15,11);
   norm_o__47->SetBinContent(16,8);
   norm_o__47->SetBinContent(17,5);
   norm_o__47->SetBinContent(18,2);
   norm_o__47->SetBinContent(19,2);
   norm_o__47->SetBinContent(20,2);
   norm_o__47->SetMinimum(0);
   norm_o__47->SetMaximum(121);
   norm_o__47->SetEntries(355);
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
   entry=leg->AddEntry("frame_x_o2_3be9d650","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.834843 #pm 0.011751","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.208114 #pm 0.009787","");
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
   
   TH1D *frame_3be9d650_copy__48 = new TH1D("frame_3be9d650_copy__48","p_T Balance",25,0,2);
   frame_3be9d650_copy__48->SetBinContent(1,66.63422);
   frame_3be9d650_copy__48->SetMaximum(66.63422);
   frame_3be9d650_copy__48->SetEntries(1);
   frame_3be9d650_copy__48->SetDirectory(0);
   frame_3be9d650_copy__48->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3be9d650_copy__48->SetLineColor(ci);
   frame_3be9d650_copy__48->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3be9d650_copy__48->GetXaxis()->SetLabelFont(42);
   frame_3be9d650_copy__48->GetXaxis()->SetTitleOffset(1);
   frame_3be9d650_copy__48->GetXaxis()->SetTitleFont(42);
   frame_3be9d650_copy__48->GetYaxis()->SetTitle("1/Events");
   frame_3be9d650_copy__48->GetYaxis()->SetLabelFont(42);
   frame_3be9d650_copy__48->GetYaxis()->SetTitleFont(42);
   frame_3be9d650_copy__48->GetZaxis()->SetLabelFont(42);
   frame_3be9d650_copy__48->GetZaxis()->SetTitleOffset(1);
   frame_3be9d650_copy__48->GetZaxis()->SetTitleFont(42);
   frame_3be9d650_copy__48->Draw("sameaxis");
   
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
