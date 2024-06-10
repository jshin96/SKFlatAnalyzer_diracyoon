void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_3__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 17:27:35 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-7.384584,2.25,55.58474);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3c7f8c30__33 = new TH1D("frame_3c7f8c30__33","p_T Balance",25,0,2);
   frame_3c7f8c30__33->SetBinContent(1,49.2878);
   frame_3c7f8c30__33->SetMinimum(-2.347038);
   frame_3c7f8c30__33->SetMaximum(49.2878);
   frame_3c7f8c30__33->SetEntries(1);
   frame_3c7f8c30__33->SetDirectory(0);
   frame_3c7f8c30__33->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_3c7f8c30__33->SetLineColor(ci);
   frame_3c7f8c30__33->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3c7f8c30__33->GetXaxis()->SetLabelFont(42);
   frame_3c7f8c30__33->GetXaxis()->SetTitleOffset(1);
   frame_3c7f8c30__33->GetXaxis()->SetTitleFont(42);
   frame_3c7f8c30__33->GetYaxis()->SetTitle("1/Events");
   frame_3c7f8c30__33->GetYaxis()->SetLabelFont(42);
   frame_3c7f8c30__33->GetYaxis()->SetTitleFont(42);
   frame_3c7f8c30__33->GetZaxis()->SetLabelFont(42);
   frame_3c7f8c30__33->GetZaxis()->SetTitleOffset(1);
   frame_3c7f8c30__33->GetZaxis()->SetTitleFont(42);
   frame_3c7f8c30__33->Draw("FUNC");
   
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
   1.69041,
   3.704765,
   6.159921,
   9.786462,
   16.61089,
   22.8684,
   28.3032,
   41.29832,
   39.18758,
   42.6592,
   27.83343,
   21.23477,
   11.92354,
   9.133857,
   3.183776,
   0.5177698,
   1.043188,
   0.5908136,
   0.09686452,
   0.01350629,
   0.1632775,
   0.09211125,
   0.00981989};
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
   0.6619753,
   1.344462,
   1.313118,
   1.999573,
   2.593421,
   2.862499,
   3.476085,
   4.149297,
   3.899107,
   4.281567,
   3.110915,
   2.868473,
   2.105541,
   2.130296,
   1.103333,
   0.305791,
   0.4980659,
   0.3168865,
   0.07081433,
   0.01097209,
   0.1035623,
   0.09211125,
   0.009819891};
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
   0.6619753,
   1.344462,
   1.313118,
   1.999573,
   2.593421,
   2.862499,
   3.476085,
   4.149297,
   3.899107,
   4.281567,
   3.110915,
   2.868473,
   2.105541,
   2.130296,
   1.103333,
   0.305791,
   0.4980659,
   0.3168865,
   0.07081433,
   0.01097209,
   0.1035623,
   0.09211125,
   0.009819891};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3009,h_dh_central2_fy3009,h_dh_central2_felx3009,h_dh_central2_fehx3009,h_dh_central2_fely3009,h_dh_central2_fehy3009);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23009 = new TH1F("Graph_h_dh_central23009","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23009->SetMinimum(-4.694077);
   Graph_h_dh_central23009->SetMaximum(51.63484);
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
   
   Double_t Central_fx9[55] = {
   0.3333222,
   0.3745634,
   0.395184,
   0.4158046,
   0.4364252,
   0.4570458,
   0.4776664,
   0.498287,
   0.5189076,
   0.5395282,
   0.5601488,
   0.5807694,
   0.6220106,
   0.6632518,
   0.6838724,
   0.704493,
   0.7251136,
   0.7457342,
   0.7663548,
   0.7766651,
   0.7869754,
   0.7972857,
   0.807596,
   0.8179063,
   0.8282166,
   0.8385269,
   0.8488372,
   0.8591475,
   0.8694578,
   0.8797681,
   0.8900784,
   0.9003887,
   0.910699,
   0.9313196,
   0.9519402,
   0.9725608,
   0.9931814,
   1.013802,
   1.034423,
   1.075664,
   1.096284,
   1.116905,
   1.137526,
   1.158146,
   1.178767,
   1.199387,
   1.220008,
   1.240629,
   1.261249,
   1.28187,
   1.30249,
   1.323111,
   1.343732,
   1.364352,
   1.364352};
   Double_t Central_fy9[55] = {
   6.740086,
   7.915482,
   8.605128,
   9.376036,
   10.24042,
   11.21275,
   12.31026,
   13.55355,
   14.96743,
   16.58188,
   18.43341,
   20.56677,
   25.24241,
   29.88362,
   32.07827,
   34.12505,
   35.97659,
   37.58817,
   38.91946,
   39.46901,
   39.9362,
   40.31795,
   40.61171,
   40.8155,
   40.92797,
   40.94834,
   40.87648,
   40.71289,
   40.45864,
   40.11547,
   39.68566,
   39.17205,
   38.57805,
   37.16476,
   35.4819,
   33.5712,
   31.4783,
   29.25096,
   26.93726,
   22.23481,
   19.92967,
   17.70317,
   15.58427,
   13.59586,
   11.75468,
   10.07163,
   8.552104,
   7.196655,
   6.00168,
   4.960202,
   4.062659,
   3.29766,
   2.652685,
   2.114706,
   2.114706};
   TGraph *graph = new TGraph(55,Central_fx9,Central_fy9);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central9 = new TH1F("Graph_Central9","Projection of centralf DSCB fit",100,0.2302192,1.467455);
   Graph_Central9->SetMinimum(1.903236);
   Graph_Central9->SetMaximum(44.8317);
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
   
   TH1D *frame_3c7f8c30__34 = new TH1D("frame_3c7f8c30__34","p_T Balance",25,0,2);
   frame_3c7f8c30__34->SetBinContent(1,49.2878);
   frame_3c7f8c30__34->SetMinimum(-2.347038);
   frame_3c7f8c30__34->SetMaximum(49.2878);
   frame_3c7f8c30__34->SetEntries(1);
   frame_3c7f8c30__34->SetDirectory(0);
   frame_3c7f8c30__34->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3c7f8c30__34->SetLineColor(ci);
   frame_3c7f8c30__34->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3c7f8c30__34->GetXaxis()->SetLabelFont(42);
   frame_3c7f8c30__34->GetXaxis()->SetTitleOffset(1);
   frame_3c7f8c30__34->GetXaxis()->SetTitleFont(42);
   frame_3c7f8c30__34->GetYaxis()->SetTitle("1/Events");
   frame_3c7f8c30__34->GetYaxis()->SetLabelFont(42);
   frame_3c7f8c30__34->GetYaxis()->SetTitleFont(42);
   frame_3c7f8c30__34->GetZaxis()->SetLabelFont(42);
   frame_3c7f8c30__34->GetZaxis()->SetTitleOffset(1);
   frame_3c7f8c30__34->GetZaxis()->SetTitleFont(42);
   frame_3c7f8c30__34->Draw("AXISSAME");
   
   TH1D *norm_c__35 = new TH1D("norm_c__35","",25,0,2);
   norm_c__35->SetBinContent(3,1.690411);
   norm_c__35->SetBinContent(4,3.704765);
   norm_c__35->SetBinContent(5,6.159921);
   norm_c__35->SetBinContent(6,9.786462);
   norm_c__35->SetBinContent(7,16.61089);
   norm_c__35->SetBinContent(8,22.8684);
   norm_c__35->SetBinContent(9,28.3032);
   norm_c__35->SetBinContent(10,41.29832);
   norm_c__35->SetBinContent(11,39.18758);
   norm_c__35->SetBinContent(12,42.6592);
   norm_c__35->SetBinContent(13,27.83343);
   norm_c__35->SetBinContent(14,21.23477);
   norm_c__35->SetBinContent(15,11.92354);
   norm_c__35->SetBinContent(16,9.133857);
   norm_c__35->SetBinContent(17,3.183776);
   norm_c__35->SetBinContent(18,0.5177698);
   norm_c__35->SetBinContent(19,1.043188);
   norm_c__35->SetBinContent(20,0.5908136);
   norm_c__35->SetBinContent(21,0.09686452);
   norm_c__35->SetBinContent(22,0.01350629);
   norm_c__35->SetBinContent(23,0.1632775);
   norm_c__35->SetBinContent(24,0.09211125);
   norm_c__35->SetBinContent(25,0.009819891);
   norm_c__35->SetBinContent(26,0.1997706);
   norm_c__35->SetBinError(3,0.6619753);
   norm_c__35->SetBinError(4,1.344462);
   norm_c__35->SetBinError(5,1.313118);
   norm_c__35->SetBinError(6,1.999573);
   norm_c__35->SetBinError(7,2.593421);
   norm_c__35->SetBinError(8,2.862499);
   norm_c__35->SetBinError(9,3.476085);
   norm_c__35->SetBinError(10,4.149297);
   norm_c__35->SetBinError(11,3.899107);
   norm_c__35->SetBinError(12,4.281567);
   norm_c__35->SetBinError(13,3.110915);
   norm_c__35->SetBinError(14,2.868473);
   norm_c__35->SetBinError(15,2.105541);
   norm_c__35->SetBinError(16,2.130296);
   norm_c__35->SetBinError(17,1.103333);
   norm_c__35->SetBinError(18,0.305791);
   norm_c__35->SetBinError(19,0.4980659);
   norm_c__35->SetBinError(20,0.3168865);
   norm_c__35->SetBinError(21,0.07081433);
   norm_c__35->SetBinError(22,0.01097209);
   norm_c__35->SetBinError(23,0.1035623);
   norm_c__35->SetBinError(24,0.09211125);
   norm_c__35->SetBinError(25,0.009819891);
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
   entry=leg->AddEntry("frame_x_c2_3c7f8c30","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.832263 #pm 0.014764","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.219997 #pm 0.014174","");
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
   
   TH1D *frame_3c7f8c30_copy__36 = new TH1D("frame_3c7f8c30_copy__36","p_T Balance",25,0,2);
   frame_3c7f8c30_copy__36->SetBinContent(1,49.2878);
   frame_3c7f8c30_copy__36->SetMinimum(-2.347038);
   frame_3c7f8c30_copy__36->SetMaximum(49.2878);
   frame_3c7f8c30_copy__36->SetEntries(1);
   frame_3c7f8c30_copy__36->SetDirectory(0);
   frame_3c7f8c30_copy__36->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3c7f8c30_copy__36->SetLineColor(ci);
   frame_3c7f8c30_copy__36->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3c7f8c30_copy__36->GetXaxis()->SetLabelFont(42);
   frame_3c7f8c30_copy__36->GetXaxis()->SetTitleOffset(1);
   frame_3c7f8c30_copy__36->GetXaxis()->SetTitleFont(42);
   frame_3c7f8c30_copy__36->GetYaxis()->SetTitle("1/Events");
   frame_3c7f8c30_copy__36->GetYaxis()->SetLabelFont(42);
   frame_3c7f8c30_copy__36->GetYaxis()->SetTitleFont(42);
   frame_3c7f8c30_copy__36->GetZaxis()->SetLabelFont(42);
   frame_3c7f8c30_copy__36->GetZaxis()->SetTitleOffset(1);
   frame_3c7f8c30_copy__36->GetZaxis()->SetTitleFont(42);
   frame_3c7f8c30_copy__36->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-7.426794,2.25,55.90246);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3c8384f0__37 = new TH1D("frame_3c8384f0__37","p_T Balance",25,0,2);
   frame_3c8384f0__37->SetBinContent(1,49.56953);
   frame_3c8384f0__37->SetMinimum(-2.360454);
   frame_3c8384f0__37->SetMaximum(49.56953);
   frame_3c8384f0__37->SetEntries(1);
   frame_3c8384f0__37->SetDirectory(0);
   frame_3c8384f0__37->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3c8384f0__37->SetLineColor(ci);
   frame_3c8384f0__37->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3c8384f0__37->GetXaxis()->SetLabelFont(42);
   frame_3c8384f0__37->GetXaxis()->SetTitleOffset(1);
   frame_3c8384f0__37->GetXaxis()->SetTitleFont(42);
   frame_3c8384f0__37->GetYaxis()->SetTitle("1/Events");
   frame_3c8384f0__37->GetYaxis()->SetLabelFont(42);
   frame_3c8384f0__37->GetYaxis()->SetTitleFont(42);
   frame_3c8384f0__37->GetZaxis()->SetLabelFont(42);
   frame_3c8384f0__37->GetZaxis()->SetTitleOffset(1);
   frame_3c8384f0__37->GetZaxis()->SetTitleFont(42);
   frame_3c8384f0__37->Draw("FUNC");
   
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
   1.796671,
   3.128226,
   3.635137,
   10.74755,
   16.27575,
   23.10205,
   27.76473,
   37.9614,
   43.06709,
   38.55257,
   27.2293,
   23.08937,
   13.26778,
   8.961341,
   3.623938,
   0.4203613,
   1.199019,
   0.5754625,
   0.07216088,
   0.3452137,
   0.1368252,
   0.03727807,
   0.1013811};
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
   0.6915449,
   1.22701,
   0.8280037,
   2.100715,
   2.682708,
   3.020831,
   3.406998,
   3.832652,
   4.141992,
   3.941434,
   3.166644,
   3.046225,
   2.175259,
   2.029664,
   1.098935,
   0.2002619,
   0.5223789,
   0.3152281,
   0.06629913,
   0.3422989,
   0.09754415,
   0.03727808,
   0.09212052};
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
   0.6915449,
   1.22701,
   0.8280037,
   2.100715,
   2.682708,
   3.020831,
   3.406998,
   3.832652,
   4.141992,
   3.941434,
   3.166644,
   3.046225,
   2.175259,
   2.029664,
   1.098935,
   0.2002619,
   0.5223789,
   0.3152281,
   0.06629913,
   0.3422989,
   0.09754415,
   0.03727808,
   0.09212052};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3010,h_dh_up2_fy3010,h_dh_up2_felx3010,h_dh_up2_fehx3010,h_dh_up2_fely3010,h_dh_up2_fehy3010);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23010 = new TH1F("Graph_h_dh_up23010","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23010->SetMinimum(-4.720908);
   Graph_h_dh_up23010->SetMaximum(51.92999);
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
   
   Double_t up_fx10[53] = {
   0.3293217,
   0.3502447,
   0.3711677,
   0.3920907,
   0.4130137,
   0.4339367,
   0.4548597,
   0.4757827,
   0.4967057,
   0.5176287,
   0.5385517,
   0.5803977,
   0.6222437,
   0.6431667,
   0.6640897,
   0.6850127,
   0.7059357,
   0.7268587,
   0.7477817,
   0.7687047,
   0.7791662,
   0.7896277,
   0.8000892,
   0.8105507,
   0.8210122,
   0.8314737,
   0.8419352,
   0.8523967,
   0.8628582,
   0.8733197,
   0.8837812,
   0.8942427,
   0.9151657,
   0.9360887,
   0.9570117,
   0.9779348,
   0.9988578,
   1.040704,
   1.08255,
   1.124396,
   1.145319,
   1.166242,
   1.187165,
   1.208088,
   1.229011,
   1.249934,
   1.270857,
   1.29178,
   1.312703,
   1.333626,
   1.354549,
   1.375472,
   1.375472};
   Double_t up_fy10[53] = {
   3.486337,
   4.253644,
   5.146034,
   6.173106,
   7.342676,
   8.660135,
   10.12779,
   11.74422,
   13.50371,
   15.39578,
   17.40484,
   21.6853,
   26.11795,
   28.30124,
   30.40824,
   32.3964,
   34.2233,
   35.84814,
   37.23324,
   38.34553,
   38.79061,
   39.1578,
   39.44481,
   39.64983,
   39.77157,
   39.80926,
   39.76265,
   39.63203,
   39.41825,
   39.12265,
   38.74709,
   38.29392,
   37.16643,
   35.76775,
   34.13123,
   32.29474,
   30.29921,
   26.00095,
   21.56877,
   17.29578,
   15.29244,
   13.40705,
   11.65491,
   10.04626,
   8.586569,
   7.277034,
   6.115173,
   5.095452,
   4.209943,
   3.448969,
   2.801703,
   2.256703,
   2.256703};
   graph = new TGraph(53,up_fx10,up_fy10);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up10 = new TH1F("Graph_up10","Projection of upf DSCB fit",100,0.2247067,1.480087);
   Graph_up10->SetMinimum(2.031033);
   Graph_up10->SetMaximum(43.56451);
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
   
   TH1D *frame_3c8384f0__38 = new TH1D("frame_3c8384f0__38","p_T Balance",25,0,2);
   frame_3c8384f0__38->SetBinContent(1,49.56953);
   frame_3c8384f0__38->SetMinimum(-2.360454);
   frame_3c8384f0__38->SetMaximum(49.56953);
   frame_3c8384f0__38->SetEntries(1);
   frame_3c8384f0__38->SetDirectory(0);
   frame_3c8384f0__38->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3c8384f0__38->SetLineColor(ci);
   frame_3c8384f0__38->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3c8384f0__38->GetXaxis()->SetLabelFont(42);
   frame_3c8384f0__38->GetXaxis()->SetTitleOffset(1);
   frame_3c8384f0__38->GetXaxis()->SetTitleFont(42);
   frame_3c8384f0__38->GetYaxis()->SetTitle("1/Events");
   frame_3c8384f0__38->GetYaxis()->SetLabelFont(42);
   frame_3c8384f0__38->GetYaxis()->SetTitleFont(42);
   frame_3c8384f0__38->GetZaxis()->SetLabelFont(42);
   frame_3c8384f0__38->GetZaxis()->SetTitleOffset(1);
   frame_3c8384f0__38->GetZaxis()->SetTitleFont(42);
   frame_3c8384f0__38->Draw("AXISSAME");
   
   TH1D *norm_u__39 = new TH1D("norm_u__39","",25,0,2);
   norm_u__39->SetBinContent(3,1.796671);
   norm_u__39->SetBinContent(4,3.128226);
   norm_u__39->SetBinContent(5,3.635137);
   norm_u__39->SetBinContent(6,10.74755);
   norm_u__39->SetBinContent(7,16.27575);
   norm_u__39->SetBinContent(8,23.10205);
   norm_u__39->SetBinContent(9,27.76473);
   norm_u__39->SetBinContent(10,37.9614);
   norm_u__39->SetBinContent(11,43.06709);
   norm_u__39->SetBinContent(12,38.55257);
   norm_u__39->SetBinContent(13,27.2293);
   norm_u__39->SetBinContent(14,23.08937);
   norm_u__39->SetBinContent(15,13.26778);
   norm_u__39->SetBinContent(16,8.961341);
   norm_u__39->SetBinContent(17,3.623938);
   norm_u__39->SetBinContent(18,0.4203613);
   norm_u__39->SetBinContent(19,1.199019);
   norm_u__39->SetBinContent(20,0.5754625);
   norm_u__39->SetBinContent(21,0.07216087);
   norm_u__39->SetBinContent(22,0.3452137);
   norm_u__39->SetBinContent(23,0.1368252);
   norm_u__39->SetBinContent(24,0.03727808);
   norm_u__39->SetBinContent(25,0.1013811);
   norm_u__39->SetBinContent(26,0.1863946);
   norm_u__39->SetBinError(3,0.6915449);
   norm_u__39->SetBinError(4,1.22701);
   norm_u__39->SetBinError(5,0.8280037);
   norm_u__39->SetBinError(6,2.100715);
   norm_u__39->SetBinError(7,2.682708);
   norm_u__39->SetBinError(8,3.020831);
   norm_u__39->SetBinError(9,3.406998);
   norm_u__39->SetBinError(10,3.832652);
   norm_u__39->SetBinError(11,4.141992);
   norm_u__39->SetBinError(12,3.941434);
   norm_u__39->SetBinError(13,3.166644);
   norm_u__39->SetBinError(14,3.046225);
   norm_u__39->SetBinError(15,2.175259);
   norm_u__39->SetBinError(16,2.029664);
   norm_u__39->SetBinError(17,1.098935);
   norm_u__39->SetBinError(18,0.2002619);
   norm_u__39->SetBinError(19,0.5223789);
   norm_u__39->SetBinError(20,0.3152281);
   norm_u__39->SetBinError(21,0.06629913);
   norm_u__39->SetBinError(22,0.3422989);
   norm_u__39->SetBinError(23,0.09754415);
   norm_u__39->SetBinError(24,0.03727808);
   norm_u__39->SetBinError(25,0.09212052);
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
   entry=leg->AddEntry("frame_x_u2_3c8384f0","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.830919 #pm 0.014667","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.227284 #pm 0.013014","");
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
   
   TH1D *frame_3c8384f0_copy__40 = new TH1D("frame_3c8384f0_copy__40","p_T Balance",25,0,2);
   frame_3c8384f0_copy__40->SetBinContent(1,49.56953);
   frame_3c8384f0_copy__40->SetMinimum(-2.360454);
   frame_3c8384f0_copy__40->SetMaximum(49.56953);
   frame_3c8384f0_copy__40->SetEntries(1);
   frame_3c8384f0_copy__40->SetDirectory(0);
   frame_3c8384f0_copy__40->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3c8384f0_copy__40->SetLineColor(ci);
   frame_3c8384f0_copy__40->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3c8384f0_copy__40->GetXaxis()->SetLabelFont(42);
   frame_3c8384f0_copy__40->GetXaxis()->SetTitleOffset(1);
   frame_3c8384f0_copy__40->GetXaxis()->SetTitleFont(42);
   frame_3c8384f0_copy__40->GetYaxis()->SetTitle("1/Events");
   frame_3c8384f0_copy__40->GetYaxis()->SetLabelFont(42);
   frame_3c8384f0_copy__40->GetYaxis()->SetTitleFont(42);
   frame_3c8384f0_copy__40->GetZaxis()->SetLabelFont(42);
   frame_3c8384f0_copy__40->GetZaxis()->SetTitleOffset(1);
   frame_3c8384f0_copy__40->GetZaxis()->SetTitleFont(42);
   frame_3c8384f0_copy__40->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-8.309357,2.25,51.04319);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3c835c30__41 = new TH1D("frame_3c835c30__41","p_T Balance",25,0,2);
   frame_3c835c30__41->SetBinContent(1,49.85614);
   frame_3c835c30__41->SetMinimum(-2.374102);
   frame_3c835c30__41->SetMaximum(49.85614);
   frame_3c835c30__41->SetEntries(1);
   frame_3c835c30__41->SetDirectory(0);
   frame_3c835c30__41->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3c835c30__41->SetLineColor(ci);
   frame_3c835c30__41->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3c835c30__41->GetXaxis()->SetLabelFont(42);
   frame_3c835c30__41->GetXaxis()->SetTitleOffset(1);
   frame_3c835c30__41->GetXaxis()->SetTitleFont(42);
   frame_3c835c30__41->GetYaxis()->SetTitle("1/Events");
   frame_3c835c30__41->GetYaxis()->SetLabelFont(42);
   frame_3c835c30__41->GetYaxis()->SetTitleFont(42);
   frame_3c835c30__41->GetZaxis()->SetLabelFont(42);
   frame_3c835c30__41->GetZaxis()->SetTitleOffset(1);
   frame_3c835c30__41->GetZaxis()->SetTitleFont(42);
   frame_3c835c30__41->Draw("FUNC");
   
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
   2.009538,
   4.240762,
   6.630477,
   11.90349,
   20.59877,
   23.06985,
   28.71197,
   43.23009,
   42.31133,
   41.26044,
   28.82201,
   18.48872,
   12.82281,
   11.87525,
   2.757513,
   0.9831885,
   1.060501,
   0.4717903,
   0.04918943,
   0.2515987,
   0.03666621,
   0.003827993,
   0.0115212};
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
   0.711468,
   1.327202,
   1.450088,
   2.154202,
   2.946658,
   2.77311,
   3.451482,
   4.251949,
   3.91917,
   4.20824,
   3.333554,
   2.651309,
   2.196881,
   2.346496,
   1.058395,
   0.4506148,
   0.4838742,
   0.2558303,
   0.04340714,
   0.1368897,
   0.03666622,
   0.003827993,
   0.01003207};
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
   0.711468,
   1.327202,
   1.450088,
   2.154202,
   2.946658,
   2.77311,
   3.451482,
   4.251949,
   3.91917,
   4.20824,
   3.333554,
   2.651309,
   2.196881,
   2.346496,
   1.058395,
   0.4506148,
   0.4838742,
   0.2558303,
   0.04340714,
   0.1368897,
   0.03666622,
   0.003827993,
   0.01003207};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3011,h_dh_down2_fy3011,h_dh_down2_felx3011,h_dh_down2_fehx3011,h_dh_down2_fely3011,h_dh_down2_fehy3011);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23011 = new TH1F("Graph_h_dh_down23011","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23011->SetMinimum(-4.748204);
   Graph_h_dh_down23011->SetMaximum(52.23024);
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
   
   Double_t down_fx11[54] = {
   0.3023821,
   0.3239221,
   0.3454621,
   0.3670021,
   0.3885422,
   0.4100822,
   0.4316222,
   0.4531622,
   0.4747022,
   0.4962422,
   0.5177822,
   0.5608622,
   0.6039422,
   0.6254822,
   0.6470222,
   0.6685623,
   0.6901023,
   0.7116423,
   0.7331823,
   0.7547223,
   0.7654923,
   0.7762623,
   0.7870323,
   0.7978023,
   0.8085723,
   0.8193423,
   0.8301123,
   0.8408823,
   0.8516523,
   0.8624223,
   0.8731923,
   0.8839623,
   0.9055023,
   0.9270423,
   0.9485824,
   0.9701224,
   0.9916624,
   1.034742,
   1.077822,
   1.099362,
   1.120902,
   1.142442,
   1.163982,
   1.185522,
   1.207062,
   1.228602,
   1.250142,
   1.271682,
   1.293222,
   1.314762,
   1.336302,
   1.357843,
   1.379383,
   1.379383};
   Double_t down_fy11[54] = {
   3.469082,
   4.245724,
   5.153393,
   6.201313,
   7.398144,
   8.750054,
   10.26,
   11.92705,
   13.74572,
   15.70546,
   17.79027,
   22.24297,
   26.86571,
   29.14569,
   31.34723,
   33.4251,
   35.33419,
   37.03107,
   38.47568,
   39.63283,
   40.09432,
   40.47368,
   40.76851,
   40.9769,
   41.09752,
   41.12959,
   41.07289,
   40.9278,
   40.69525,
   40.37673,
   39.9743,
   39.49052,
   38.29158,
   36.80972,
   35.08088,
   33.14571,
   31.04795,
   26.54549,
   21.9252,
   19.6695,
   17.4941,
   15.42549,
   13.48451,
   11.68638,
   10.04092,
   8.552953,
   7.22283,
   6.047104,
   5.019222,
   4.130228,
   3.369462,
   2.725184,
   2.185144,
   2.185144};
   graph = new TGraph(54,down_fx11,down_fy11);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down11 = new TH1F("Graph_down11","Projection of downf DSCB fit",100,0.1946821,1.487083);
   Graph_down11->SetMinimum(1.966629);
   Graph_down11->SetMaximum(45.02403);
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
   
   TH1D *frame_3c835c30__42 = new TH1D("frame_3c835c30__42","p_T Balance",25,0,2);
   frame_3c835c30__42->SetBinContent(1,49.85614);
   frame_3c835c30__42->SetMinimum(-2.374102);
   frame_3c835c30__42->SetMaximum(49.85614);
   frame_3c835c30__42->SetEntries(1);
   frame_3c835c30__42->SetDirectory(0);
   frame_3c835c30__42->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3c835c30__42->SetLineColor(ci);
   frame_3c835c30__42->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3c835c30__42->GetXaxis()->SetLabelFont(42);
   frame_3c835c30__42->GetXaxis()->SetTitleOffset(1);
   frame_3c835c30__42->GetXaxis()->SetTitleFont(42);
   frame_3c835c30__42->GetYaxis()->SetTitle("1/Events");
   frame_3c835c30__42->GetYaxis()->SetLabelFont(42);
   frame_3c835c30__42->GetYaxis()->SetTitleFont(42);
   frame_3c835c30__42->GetZaxis()->SetLabelFont(42);
   frame_3c835c30__42->GetZaxis()->SetTitleOffset(1);
   frame_3c835c30__42->GetZaxis()->SetTitleFont(42);
   frame_3c835c30__42->Draw("AXISSAME");
   
   TH1D *norm_d__43 = new TH1D("norm_d__43","",25,0,2);
   norm_d__43->SetBinContent(3,2.009538);
   norm_d__43->SetBinContent(4,4.240762);
   norm_d__43->SetBinContent(5,6.630477);
   norm_d__43->SetBinContent(6,11.90349);
   norm_d__43->SetBinContent(7,20.59877);
   norm_d__43->SetBinContent(8,23.06985);
   norm_d__43->SetBinContent(9,28.71197);
   norm_d__43->SetBinContent(10,43.23009);
   norm_d__43->SetBinContent(11,42.31133);
   norm_d__43->SetBinContent(12,41.26044);
   norm_d__43->SetBinContent(13,28.82201);
   norm_d__43->SetBinContent(14,18.48872);
   norm_d__43->SetBinContent(15,12.82281);
   norm_d__43->SetBinContent(16,11.87525);
   norm_d__43->SetBinContent(17,2.757513);
   norm_d__43->SetBinContent(18,0.9831884);
   norm_d__43->SetBinContent(19,1.060501);
   norm_d__43->SetBinContent(20,0.4717903);
   norm_d__43->SetBinContent(21,0.04918943);
   norm_d__43->SetBinContent(22,0.2515987);
   norm_d__43->SetBinContent(23,0.03666622);
   norm_d__43->SetBinContent(24,0.003827993);
   norm_d__43->SetBinContent(25,0.0115212);
   norm_d__43->SetBinContent(26,0.080793);
   norm_d__43->SetBinError(3,0.711468);
   norm_d__43->SetBinError(4,1.327202);
   norm_d__43->SetBinError(5,1.450088);
   norm_d__43->SetBinError(6,2.154202);
   norm_d__43->SetBinError(7,2.946658);
   norm_d__43->SetBinError(8,2.77311);
   norm_d__43->SetBinError(9,3.451482);
   norm_d__43->SetBinError(10,4.251949);
   norm_d__43->SetBinError(11,3.91917);
   norm_d__43->SetBinError(12,4.20824);
   norm_d__43->SetBinError(13,3.333554);
   norm_d__43->SetBinError(14,2.651309);
   norm_d__43->SetBinError(15,2.196881);
   norm_d__43->SetBinError(16,2.346496);
   norm_d__43->SetBinError(17,1.058395);
   norm_d__43->SetBinError(18,0.4506148);
   norm_d__43->SetBinError(19,0.4838742);
   norm_d__43->SetBinError(20,0.2558303);
   norm_d__43->SetBinError(21,0.04340714);
   norm_d__43->SetBinError(22,0.1368897);
   norm_d__43->SetBinError(23,0.03666622);
   norm_d__43->SetBinError(24,0.003827993);
   norm_d__43->SetBinError(25,0.01003207);
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
   entry=leg->AddEntry("frame_x_d2_3c835c30","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.817921 #pm 0.014524","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.231839 #pm 0.012800","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.970000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3c835c30_copy__44 = new TH1D("frame_3c835c30_copy__44","p_T Balance",25,0,2);
   frame_3c835c30_copy__44->SetBinContent(1,49.85614);
   frame_3c835c30_copy__44->SetMinimum(-2.374102);
   frame_3c835c30_copy__44->SetMaximum(49.85614);
   frame_3c835c30_copy__44->SetEntries(1);
   frame_3c835c30_copy__44->SetDirectory(0);
   frame_3c835c30_copy__44->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3c835c30_copy__44->SetLineColor(ci);
   frame_3c835c30_copy__44->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3c835c30_copy__44->GetXaxis()->SetLabelFont(42);
   frame_3c835c30_copy__44->GetXaxis()->SetTitleOffset(1);
   frame_3c835c30_copy__44->GetXaxis()->SetTitleFont(42);
   frame_3c835c30_copy__44->GetYaxis()->SetTitle("1/Events");
   frame_3c835c30_copy__44->GetYaxis()->SetLabelFont(42);
   frame_3c835c30_copy__44->GetYaxis()->SetTitleFont(42);
   frame_3c835c30_copy__44->GetZaxis()->SetLabelFont(42);
   frame_3c835c30_copy__44->GetZaxis()->SetTitleOffset(1);
   frame_3c835c30_copy__44->GetZaxis()->SetTitleFont(42);
   frame_3c835c30_copy__44->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-7.953698,2.25,71.58328);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3c845630__45 = new TH1D("frame_3c845630__45","p_T Balance",25,0,2);
   frame_3c845630__45->SetBinContent(1,69.99254);
   frame_3c845630__45->SetMaximum(69.99254);
   frame_3c845630__45->SetEntries(1);
   frame_3c845630__45->SetDirectory(0);
   frame_3c845630__45->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3c845630__45->SetLineColor(ci);
   frame_3c845630__45->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3c845630__45->GetXaxis()->SetLabelFont(42);
   frame_3c845630__45->GetXaxis()->SetTitleOffset(1);
   frame_3c845630__45->GetXaxis()->SetTitleFont(42);
   frame_3c845630__45->GetYaxis()->SetTitle("1/Events");
   frame_3c845630__45->GetYaxis()->SetLabelFont(42);
   frame_3c845630__45->GetYaxis()->SetTitleFont(42);
   frame_3c845630__45->GetZaxis()->SetLabelFont(42);
   frame_3c845630__45->GetZaxis()->SetTitleOffset(1);
   frame_3c845630__45->GetZaxis()->SetTitleFont(42);
   frame_3c845630__45->Draw("FUNC");
   
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
   8,
   9,
   22,
   27,
   42,
   48,
   58,
   49,
   34,
   29,
   10,
   4,
   6,
   2,
   2,
   3,
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
   2.768386,
   2.943461,
   4.654502,
   5.163771,
   6.454831,
   6.903979,
   7.593751,
   6.976026,
   5.802128,
   5.353932,
   3.108694,
   1.914339,
   2.379931,
   1.291815,
   1.291815,
   1.632705,
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
   3.945142,
   4.110204,
   5.761366,
   6.260244,
   7.53218,
   7.97633,
   8.659564,
   8.047634,
   6.888101,
   6.44702,
   4.26695,
   3.162753,
   3.583642,
   2.63786,
   2.63786,
   2.918186,
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
   Graph_h_dh_data23012->SetMaximum(73.32552);
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
   
   Double_t observation_fx12[52] = {
   0.4150859,
   0.4498338,
   0.4672077,
   0.4758947,
   0.4802382,
   0.4845817,
   0.5019557,
   0.5193296,
   0.5367036,
   0.5540775,
   0.5714515,
   0.5888254,
   0.6235733,
   0.6583212,
   0.6756952,
   0.6930691,
   0.7104431,
   0.727817,
   0.745191,
   0.762565,
   0.7799389,
   0.7886259,
   0.7973129,
   0.8059998,
   0.8146868,
   0.8233738,
   0.8320608,
   0.8407477,
   0.8494347,
   0.8668087,
   0.8841826,
   0.9015566,
   0.9189305,
   0.9363045,
   0.9536784,
   0.9710524,
   1.0058,
   1.040548,
   1.075296,
   1.09267,
   1.110044,
   1.127418,
   1.144792,
   1.162166,
   1.17954,
   1.196914,
   1.214288,
   1.231662,
   1.249036,
   1.26641,
   1.283784,
   1.283784};
   Double_t observation_fy12[52] = {
   11.48562,
   11.85506,
   12.20575,
   12.51709,
   12.76784,
   13.18375,
   15.24763,
   17.49771,
   19.92397,
   22.51057,
   25.23556,
   28.07082,
   33.93023,
   39.75409,
   42.53075,
   45.14816,
   47.55464,
   49.70058,
   51.54018,
   53.03299,
   54.14547,
   54.5508,
   54.85219,
   55.04791,
   55.13681,
   55.11837,
   54.9927,
   54.76054,
   54.42323,
   53.44159,
   52.07032,
   50.34043,
   48.29024,
   45.96398,
   43.41019,
   40.68006,
   34.89866,
   29.02012,
   23.39122,
   20.75646,
   18.27552,
   15.96621,
   13.84043,
   11.90456,
   10.15998,
   8.60376,
   7.229353,
   6.02735,
   4.986194,
   4.092868,
   3.333513,
   3.333513};
   graph = new TGraph(52,observation_fx12,observation_fy12);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation12 = new TH1F("Graph_observation12","Projection of obsf DSCB fit",100,0.3282161,1.370653);
   Graph_observation12->SetMinimum(3.000161);
   Graph_observation12->SetMaximum(60.31714);
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
   
   TH1D *frame_3c845630__46 = new TH1D("frame_3c845630__46","p_T Balance",25,0,2);
   frame_3c845630__46->SetBinContent(1,69.99254);
   frame_3c845630__46->SetMaximum(69.99254);
   frame_3c845630__46->SetEntries(1);
   frame_3c845630__46->SetDirectory(0);
   frame_3c845630__46->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3c845630__46->SetLineColor(ci);
   frame_3c845630__46->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3c845630__46->GetXaxis()->SetLabelFont(42);
   frame_3c845630__46->GetXaxis()->SetTitleOffset(1);
   frame_3c845630__46->GetXaxis()->SetTitleFont(42);
   frame_3c845630__46->GetYaxis()->SetTitle("1/Events");
   frame_3c845630__46->GetYaxis()->SetLabelFont(42);
   frame_3c845630__46->GetYaxis()->SetTitleFont(42);
   frame_3c845630__46->GetZaxis()->SetLabelFont(42);
   frame_3c845630__46->GetZaxis()->SetTitleOffset(1);
   frame_3c845630__46->GetZaxis()->SetTitleFont(42);
   frame_3c845630__46->Draw("AXISSAME");
   
   TH1D *norm_o__47 = new TH1D("norm_o__47","",25,0,2);
   norm_o__47->SetBinContent(3,1);
   norm_o__47->SetBinContent(4,1);
   norm_o__47->SetBinContent(5,8);
   norm_o__47->SetBinContent(6,9);
   norm_o__47->SetBinContent(7,22);
   norm_o__47->SetBinContent(8,27);
   norm_o__47->SetBinContent(9,42);
   norm_o__47->SetBinContent(10,48);
   norm_o__47->SetBinContent(11,58);
   norm_o__47->SetBinContent(12,49);
   norm_o__47->SetBinContent(13,34);
   norm_o__47->SetBinContent(14,29);
   norm_o__47->SetBinContent(15,10);
   norm_o__47->SetBinContent(16,4);
   norm_o__47->SetBinContent(17,6);
   norm_o__47->SetBinContent(18,2);
   norm_o__47->SetBinContent(19,2);
   norm_o__47->SetBinContent(20,3);
   norm_o__47->SetMinimum(0);
   norm_o__47->SetMaximum(127.6);
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
   entry=leg->AddEntry("frame_x_o2_3c845630","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.814135 #pm 0.012158","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.200894 #pm 0.011313","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.986000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3c845630_copy__48 = new TH1D("frame_3c845630_copy__48","p_T Balance",25,0,2);
   frame_3c845630_copy__48->SetBinContent(1,69.99254);
   frame_3c845630_copy__48->SetMaximum(69.99254);
   frame_3c845630_copy__48->SetEntries(1);
   frame_3c845630_copy__48->SetDirectory(0);
   frame_3c845630_copy__48->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3c845630_copy__48->SetLineColor(ci);
   frame_3c845630_copy__48->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3c845630_copy__48->GetXaxis()->SetLabelFont(42);
   frame_3c845630_copy__48->GetXaxis()->SetTitleOffset(1);
   frame_3c845630_copy__48->GetXaxis()->SetTitleFont(42);
   frame_3c845630_copy__48->GetYaxis()->SetTitle("1/Events");
   frame_3c845630_copy__48->GetYaxis()->SetLabelFont(42);
   frame_3c845630_copy__48->GetYaxis()->SetTitleFont(42);
   frame_3c845630_copy__48->GetZaxis()->SetLabelFont(42);
   frame_3c845630_copy__48->GetZaxis()->SetTitleOffset(1);
   frame_3c845630_copy__48->GetZaxis()->SetTitleFont(42);
   frame_3c845630_copy__48->Draw("sameaxis");
   
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
