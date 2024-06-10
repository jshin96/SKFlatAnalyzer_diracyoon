void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_3__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 19:37:31 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-17.54642,2.25,201.7838);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3bf08670__33 = new TH1D("frame_3bf08670__33","p_T Balance",25,0,2);
   frame_3bf08670__33->SetBinContent(1,179.8508);
   frame_3bf08670__33->SetMaximum(179.8508);
   frame_3bf08670__33->SetEntries(1);
   frame_3bf08670__33->SetDirectory(0);
   frame_3bf08670__33->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_3bf08670__33->SetLineColor(ci);
   frame_3bf08670__33->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf08670__33->GetXaxis()->SetLabelFont(42);
   frame_3bf08670__33->GetXaxis()->SetTitleOffset(1);
   frame_3bf08670__33->GetXaxis()->SetTitleFont(42);
   frame_3bf08670__33->GetYaxis()->SetTitle("1/Events");
   frame_3bf08670__33->GetYaxis()->SetLabelFont(42);
   frame_3bf08670__33->GetYaxis()->SetTitleFont(42);
   frame_3bf08670__33->GetZaxis()->SetLabelFont(42);
   frame_3bf08670__33->GetZaxis()->SetTitleOffset(1);
   frame_3bf08670__33->GetZaxis()->SetTitleFont(42);
   frame_3bf08670__33->Draw("FUNC");
   
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
   4.881868,
   11.48975,
   17.30073,
   23.65908,
   41.77968,
   71.4239,
   107.8163,
   142.9067,
   163.3515,
   162.8289,
   124.6807,
   92.80799,
   59.23191,
   28.3719,
   12.00271,
   8.499079,
   2.672119,
   1.185983,
   0.6921012,
   0.2624495,
   0.2116109,
   0.1478931,
   0.3372572};
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
   1.136282,
   2.025788,
   2.450536,
   2.867215,
   3.887443,
   5.201191,
   6.474736,
   7.424365,
   7.934992,
   7.958007,
   6.93586,
   5.888399,
   4.57687,
   3.088775,
   1.988585,
   1.551645,
   0.8062014,
   0.4357572,
   0.3283745,
   0.1897451,
   0.1001507,
   0.08769452,
   0.1832678};
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
   1.136282,
   2.025788,
   2.450536,
   2.867215,
   3.887443,
   5.201191,
   6.474736,
   7.424365,
   7.934992,
   7.958007,
   6.93586,
   5.888399,
   4.57687,
   3.088775,
   1.988585,
   1.551645,
   0.8062014,
   0.4357572,
   0.3283745,
   0.1897451,
   0.1001507,
   0.08769452,
   0.1832678};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3009,h_dh_central2_fy3009,h_dh_central2_felx3009,h_dh_central2_fehx3009,h_dh_central2_fely3009,h_dh_central2_fehy3009);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23009 = new TH1F("Graph_h_dh_central23009","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23009->SetMinimum(0);
   Graph_h_dh_central23009->SetMaximum(188.4151);
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
   0.3327434,
   0.3745893,
   0.4164352,
   0.458281,
   0.4687425,
   0.4739733,
   0.479204,
   0.5001269,
   0.5210499,
   0.5419728,
   0.5628958,
   0.5838187,
   0.6047417,
   0.6256646,
   0.6675105,
   0.7093564,
   0.7302793,
   0.7512023,
   0.7721252,
   0.7825867,
   0.7930482,
   0.8035096,
   0.8139711,
   0.8244326,
   0.834894,
   0.8453555,
   0.855817,
   0.8662785,
   0.8767399,
   0.8872014,
   0.8976629,
   0.9081243,
   0.9185858,
   0.9290473,
   0.9395088,
   0.9499702,
   0.9604317,
   0.9813546,
   1.002278,
   1.023201,
   1.044123,
   1.085969,
   1.106892,
   1.127815,
   1.148738,
   1.169661,
   1.190584,
   1.211507,
   1.23243,
   1.253353,
   1.274276,
   1.295199,
   1.316122,
   1.337045,
   1.357968,
   1.378891,
   1.378891};
   Double_t Central_fy9[57] = {
   22.34468,
   22.74426,
   23.35027,
   24.60004,
   25.28879,
   25.84323,
   26.79746,
   32.51251,
   39.02048,
   46.32546,
   54.40416,
   63.20182,
   72.62936,
   82.56196,
   103.2693,
   123.6809,
   133.1669,
   141.8322,
   149.4304,
   152.7575,
   155.7356,
   158.3413,
   160.5543,
   162.357,
   163.7349,
   164.677,
   165.1756,
   165.2266,
   164.8297,
   163.988,
   162.7085,
   161.0013,
   158.8803,
   156.3623,
   153.4671,
   150.2172,
   146.6376,
   138.5992,
   129.587,
   119.8525,
   109.6523,
   88.84133,
   78.67584,
   68.9212,
   59.72408,
   51.19543,
   43.41083,
   36.41247,
   30.21255,
   24.79761,
   20.13341,
   16.17,
   12.84659,
   10.09603,
   7.848722,
   6.035764,
   6.035764};
   TGraph *graph = new TGraph(57,Central_fx9,Central_fy9);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central9 = new TH1F("Graph_Central9","Projection of centralf DSCB fit",100,0.2281287,1.483505);
   Graph_Central9->SetMinimum(5.432188);
   Graph_Central9->SetMaximum(181.1457);
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
   
   TH1D *frame_3bf08670__34 = new TH1D("frame_3bf08670__34","p_T Balance",25,0,2);
   frame_3bf08670__34->SetBinContent(1,179.8508);
   frame_3bf08670__34->SetMaximum(179.8508);
   frame_3bf08670__34->SetEntries(1);
   frame_3bf08670__34->SetDirectory(0);
   frame_3bf08670__34->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf08670__34->SetLineColor(ci);
   frame_3bf08670__34->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf08670__34->GetXaxis()->SetLabelFont(42);
   frame_3bf08670__34->GetXaxis()->SetTitleOffset(1);
   frame_3bf08670__34->GetXaxis()->SetTitleFont(42);
   frame_3bf08670__34->GetYaxis()->SetTitle("1/Events");
   frame_3bf08670__34->GetYaxis()->SetLabelFont(42);
   frame_3bf08670__34->GetYaxis()->SetTitleFont(42);
   frame_3bf08670__34->GetZaxis()->SetLabelFont(42);
   frame_3bf08670__34->GetZaxis()->SetTitleOffset(1);
   frame_3bf08670__34->GetZaxis()->SetTitleFont(42);
   frame_3bf08670__34->Draw("AXISSAME");
   
   TH1D *norm_c__35 = new TH1D("norm_c__35","",25,0,2);
   norm_c__35->SetBinContent(3,4.881868);
   norm_c__35->SetBinContent(4,11.48975);
   norm_c__35->SetBinContent(5,17.30073);
   norm_c__35->SetBinContent(6,23.65908);
   norm_c__35->SetBinContent(7,41.77968);
   norm_c__35->SetBinContent(8,71.4239);
   norm_c__35->SetBinContent(9,107.8163);
   norm_c__35->SetBinContent(10,142.9067);
   norm_c__35->SetBinContent(11,163.3515);
   norm_c__35->SetBinContent(12,162.8289);
   norm_c__35->SetBinContent(13,124.6807);
   norm_c__35->SetBinContent(14,92.80799);
   norm_c__35->SetBinContent(15,59.23191);
   norm_c__35->SetBinContent(16,28.3719);
   norm_c__35->SetBinContent(17,12.00271);
   norm_c__35->SetBinContent(18,8.499079);
   norm_c__35->SetBinContent(19,2.672119);
   norm_c__35->SetBinContent(20,1.185983);
   norm_c__35->SetBinContent(21,0.6921012);
   norm_c__35->SetBinContent(22,0.2624495);
   norm_c__35->SetBinContent(23,0.2116109);
   norm_c__35->SetBinContent(24,0.1478931);
   norm_c__35->SetBinContent(25,0.3372572);
   norm_c__35->SetBinContent(26,0.6068858);
   norm_c__35->SetBinError(3,1.136282);
   norm_c__35->SetBinError(4,2.025788);
   norm_c__35->SetBinError(5,2.450536);
   norm_c__35->SetBinError(6,2.867215);
   norm_c__35->SetBinError(7,3.887443);
   norm_c__35->SetBinError(8,5.201191);
   norm_c__35->SetBinError(9,6.474736);
   norm_c__35->SetBinError(10,7.424365);
   norm_c__35->SetBinError(11,7.934992);
   norm_c__35->SetBinError(12,7.958007);
   norm_c__35->SetBinError(13,6.93586);
   norm_c__35->SetBinError(14,5.888399);
   norm_c__35->SetBinError(15,4.57687);
   norm_c__35->SetBinError(16,3.088775);
   norm_c__35->SetBinError(17,1.988585);
   norm_c__35->SetBinError(18,1.551645);
   norm_c__35->SetBinError(19,0.8062014);
   norm_c__35->SetBinError(20,0.4357572);
   norm_c__35->SetBinError(21,0.3283745);
   norm_c__35->SetBinError(22,0.1897451);
   norm_c__35->SetBinError(23,0.1001507);
   norm_c__35->SetBinError(24,0.08769452);
   norm_c__35->SetBinError(25,0.1832678);
   norm_c__35->SetBinError(26,0.172597);
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
   entry=leg->AddEntry("frame_x_c2_3bf08670","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.862307 #pm 0.006564","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.200776 #pm 0.005579","");
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
   
   TH1D *frame_3bf08670_copy__36 = new TH1D("frame_3bf08670_copy__36","p_T Balance",25,0,2);
   frame_3bf08670_copy__36->SetBinContent(1,179.8508);
   frame_3bf08670_copy__36->SetMaximum(179.8508);
   frame_3bf08670_copy__36->SetEntries(1);
   frame_3bf08670_copy__36->SetDirectory(0);
   frame_3bf08670_copy__36->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf08670_copy__36->SetLineColor(ci);
   frame_3bf08670_copy__36->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf08670_copy__36->GetXaxis()->SetLabelFont(42);
   frame_3bf08670_copy__36->GetXaxis()->SetTitleOffset(1);
   frame_3bf08670_copy__36->GetXaxis()->SetTitleFont(42);
   frame_3bf08670_copy__36->GetYaxis()->SetTitle("1/Events");
   frame_3bf08670_copy__36->GetYaxis()->SetLabelFont(42);
   frame_3bf08670_copy__36->GetYaxis()->SetTitleFont(42);
   frame_3bf08670_copy__36->GetZaxis()->SetLabelFont(42);
   frame_3bf08670_copy__36->GetZaxis()->SetTitleOffset(1);
   frame_3bf08670_copy__36->GetZaxis()->SetTitleFont(42);
   frame_3bf08670_copy__36->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-17.91509,2.25,206.0235);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3bf09a10__37 = new TH1D("frame_3bf09a10__37","p_T Balance",25,0,2);
   frame_3bf09a10__37->SetBinContent(1,183.6297);
   frame_3bf09a10__37->SetMaximum(183.6297);
   frame_3bf09a10__37->SetEntries(1);
   frame_3bf09a10__37->SetDirectory(0);
   frame_3bf09a10__37->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf09a10__37->SetLineColor(ci);
   frame_3bf09a10__37->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf09a10__37->GetXaxis()->SetLabelFont(42);
   frame_3bf09a10__37->GetXaxis()->SetTitleOffset(1);
   frame_3bf09a10__37->GetXaxis()->SetTitleFont(42);
   frame_3bf09a10__37->GetYaxis()->SetTitle("1/Events");
   frame_3bf09a10__37->GetYaxis()->SetLabelFont(42);
   frame_3bf09a10__37->GetYaxis()->SetTitleFont(42);
   frame_3bf09a10__37->GetZaxis()->SetLabelFont(42);
   frame_3bf09a10__37->GetZaxis()->SetTitleOffset(1);
   frame_3bf09a10__37->GetZaxis()->SetTitleFont(42);
   frame_3bf09a10__37->Draw("FUNC");
   
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
   5.041697,
   11.98302,
   17.09302,
   17.06996,
   43.70009,
   67.80139,
   101.0961,
   143.6915,
   164.4324,
   166.7571,
   134.3511,
   99.89884,
   62.28532,
   30.66979,
   13.01375,
   8.73224,
   3.570907,
   1.015954,
   0.8993688,
   0.4855047,
   0.251396,
   0.091105,
   0.1344279};
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
   1.318704,
   2.199215,
   2.584147,
   2.377169,
   4.069566,
   5.110607,
   6.231619,
   7.576758,
   8.01975,
   8.128243,
   7.166517,
   6.187704,
   4.766097,
   3.211955,
   2.017922,
   1.623766,
   0.8110916,
   0.4418675,
   0.3828803,
   0.2965475,
   0.1581734,
   0.06692415,
   0.07969134};
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
   1.318704,
   2.199215,
   2.584147,
   2.377169,
   4.069566,
   5.110607,
   6.231619,
   7.576758,
   8.01975,
   8.128243,
   7.166517,
   6.187704,
   4.766097,
   3.211955,
   2.017922,
   1.623766,
   0.8110916,
   0.4418675,
   0.3828803,
   0.2965475,
   0.1581734,
   0.06692415,
   0.07969134};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3010,h_dh_up2_fy3010,h_dh_up2_felx3010,h_dh_up2_fehx3010,h_dh_up2_fely3010,h_dh_up2_fehy3010);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23010 = new TH1F("Graph_h_dh_up23010","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23010->SetMinimum(0);
   Graph_h_dh_up23010->SetMaximum(192.3739);
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
   
   Double_t up_fx10[57] = {
   0.3299756,
   0.3727723,
   0.415569,
   0.4369673,
   0.4583656,
   0.4690648,
   0.479764,
   0.5011623,
   0.5225606,
   0.543959,
   0.5653573,
   0.5867556,
   0.608154,
   0.6295523,
   0.672349,
   0.7151457,
   0.736544,
   0.7579423,
   0.7793407,
   0.7900398,
   0.800739,
   0.8114382,
   0.8221373,
   0.8328365,
   0.8435357,
   0.8542348,
   0.864934,
   0.8756332,
   0.8863323,
   0.8970315,
   0.9077307,
   0.9184298,
   0.929129,
   0.9398282,
   0.9505274,
   0.9612265,
   0.9719257,
   0.993324,
   1.014722,
   1.036121,
   1.057519,
   1.100316,
   1.121714,
   1.143112,
   1.164511,
   1.185909,
   1.207307,
   1.228706,
   1.250104,
   1.271502,
   1.292901,
   1.314299,
   1.335697,
   1.357096,
   1.378494,
   1.399892,
   1.399892};
   Double_t up_fy10[57] = {
   19.14472,
   19.47725,
   19.99987,
   20.43391,
   21.23448,
   22.17153,
   24.53256,
   30.14288,
   36.60892,
   43.94906,
   52.1522,
   61.17247,
   70.92508,
   81.28382,
   103.1083,
   124.8605,
   135.0303,
   144.3437,
   152.5193,
   156.0985,
   159.2988,
   162.0937,
   164.46,
   166.3774,
   167.8296,
   168.804,
   169.2923,
   169.2901,
   168.7976,
   167.8189,
   166.3626,
   164.4412,
   162.0711,
   159.2724,
   156.0687,
   152.4864,
   148.5547,
   139.7711,
   129.9897,
   119.4981,
   108.5858,
   86.59222,
   75.99279,
   65.92138,
   56.525,
   47.90879,
   40.1375,
   33.23884,
   27.20832,
   22.01497,
   17.60738,
   13.91976,
   10.87751,
   8.402088,
   6.415131,
   4.841548,
   4.841548};
   graph = new TGraph(57,up_fx10,up_fy10);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up10 = new TH1F("Graph_up10","Projection of upf DSCB fit",100,0.2229839,1.506884);
   Graph_up10->SetMinimum(4.357393);
   Graph_up10->SetMaximum(185.7373);
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
   
   TH1D *frame_3bf09a10__38 = new TH1D("frame_3bf09a10__38","p_T Balance",25,0,2);
   frame_3bf09a10__38->SetBinContent(1,183.6297);
   frame_3bf09a10__38->SetMaximum(183.6297);
   frame_3bf09a10__38->SetEntries(1);
   frame_3bf09a10__38->SetDirectory(0);
   frame_3bf09a10__38->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf09a10__38->SetLineColor(ci);
   frame_3bf09a10__38->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf09a10__38->GetXaxis()->SetLabelFont(42);
   frame_3bf09a10__38->GetXaxis()->SetTitleOffset(1);
   frame_3bf09a10__38->GetXaxis()->SetTitleFont(42);
   frame_3bf09a10__38->GetYaxis()->SetTitle("1/Events");
   frame_3bf09a10__38->GetYaxis()->SetLabelFont(42);
   frame_3bf09a10__38->GetYaxis()->SetTitleFont(42);
   frame_3bf09a10__38->GetZaxis()->SetLabelFont(42);
   frame_3bf09a10__38->GetZaxis()->SetTitleOffset(1);
   frame_3bf09a10__38->GetZaxis()->SetTitleFont(42);
   frame_3bf09a10__38->Draw("AXISSAME");
   
   TH1D *norm_u__39 = new TH1D("norm_u__39","",25,0,2);
   norm_u__39->SetBinContent(2,0.150699);
   norm_u__39->SetBinContent(3,5.041697);
   norm_u__39->SetBinContent(4,11.98302);
   norm_u__39->SetBinContent(5,17.09302);
   norm_u__39->SetBinContent(6,17.06996);
   norm_u__39->SetBinContent(7,43.70009);
   norm_u__39->SetBinContent(8,67.80139);
   norm_u__39->SetBinContent(9,101.0961);
   norm_u__39->SetBinContent(10,143.6914);
   norm_u__39->SetBinContent(11,164.4324);
   norm_u__39->SetBinContent(12,166.7571);
   norm_u__39->SetBinContent(13,134.3511);
   norm_u__39->SetBinContent(14,99.89884);
   norm_u__39->SetBinContent(15,62.28532);
   norm_u__39->SetBinContent(16,30.66979);
   norm_u__39->SetBinContent(17,13.01375);
   norm_u__39->SetBinContent(18,8.73224);
   norm_u__39->SetBinContent(19,3.570907);
   norm_u__39->SetBinContent(20,1.015954);
   norm_u__39->SetBinContent(21,0.8993688);
   norm_u__39->SetBinContent(22,0.4855047);
   norm_u__39->SetBinContent(23,0.251396);
   norm_u__39->SetBinContent(24,0.091105);
   norm_u__39->SetBinContent(25,0.1344279);
   norm_u__39->SetBinContent(26,0.7686852);
   norm_u__39->SetBinError(2,0.150699);
   norm_u__39->SetBinError(3,1.318704);
   norm_u__39->SetBinError(4,2.199215);
   norm_u__39->SetBinError(5,2.584147);
   norm_u__39->SetBinError(6,2.377169);
   norm_u__39->SetBinError(7,4.069566);
   norm_u__39->SetBinError(8,5.110607);
   norm_u__39->SetBinError(9,6.231619);
   norm_u__39->SetBinError(10,7.576758);
   norm_u__39->SetBinError(11,8.01975);
   norm_u__39->SetBinError(12,8.128243);
   norm_u__39->SetBinError(13,7.166517);
   norm_u__39->SetBinError(14,6.187704);
   norm_u__39->SetBinError(15,4.766097);
   norm_u__39->SetBinError(16,3.211955);
   norm_u__39->SetBinError(17,2.017922);
   norm_u__39->SetBinError(18,1.623766);
   norm_u__39->SetBinError(19,0.8110916);
   norm_u__39->SetBinError(20,0.4418675);
   norm_u__39->SetBinError(21,0.3828803);
   norm_u__39->SetBinError(22,0.2965475);
   norm_u__39->SetBinError(23,0.1581734);
   norm_u__39->SetBinError(24,0.06692415);
   norm_u__39->SetBinError(25,0.07969134);
   norm_u__39->SetBinError(26,0.198391);
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
   entry=leg->AddEntry("frame_x_u2_3bf09a10","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.870236 #pm 0.006398","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.198644 #pm 0.005132","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.989000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3bf09a10_copy__40 = new TH1D("frame_3bf09a10_copy__40","p_T Balance",25,0,2);
   frame_3bf09a10_copy__40->SetBinContent(1,183.6297);
   frame_3bf09a10_copy__40->SetMaximum(183.6297);
   frame_3bf09a10_copy__40->SetEntries(1);
   frame_3bf09a10_copy__40->SetDirectory(0);
   frame_3bf09a10_copy__40->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf09a10_copy__40->SetLineColor(ci);
   frame_3bf09a10_copy__40->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf09a10_copy__40->GetXaxis()->SetLabelFont(42);
   frame_3bf09a10_copy__40->GetXaxis()->SetTitleOffset(1);
   frame_3bf09a10_copy__40->GetXaxis()->SetTitleFont(42);
   frame_3bf09a10_copy__40->GetYaxis()->SetTitle("1/Events");
   frame_3bf09a10_copy__40->GetYaxis()->SetLabelFont(42);
   frame_3bf09a10_copy__40->GetYaxis()->SetTitleFont(42);
   frame_3bf09a10_copy__40->GetZaxis()->SetLabelFont(42);
   frame_3bf09a10_copy__40->GetZaxis()->SetTitleOffset(1);
   frame_3bf09a10_copy__40->GetZaxis()->SetTitleFont(42);
   frame_3bf09a10_copy__40->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-20.16296,2.25,181.4666);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3bf087b0__41 = new TH1D("frame_3bf087b0__41","p_T Balance",25,0,2);
   frame_3bf087b0__41->SetBinContent(1,177.434);
   frame_3bf087b0__41->SetMaximum(177.434);
   frame_3bf087b0__41->SetEntries(1);
   frame_3bf087b0__41->SetDirectory(0);
   frame_3bf087b0__41->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf087b0__41->SetLineColor(ci);
   frame_3bf087b0__41->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf087b0__41->GetXaxis()->SetLabelFont(42);
   frame_3bf087b0__41->GetXaxis()->SetTitleOffset(1);
   frame_3bf087b0__41->GetXaxis()->SetTitleFont(42);
   frame_3bf087b0__41->GetYaxis()->SetTitle("1/Events");
   frame_3bf087b0__41->GetYaxis()->SetLabelFont(42);
   frame_3bf087b0__41->GetYaxis()->SetTitleFont(42);
   frame_3bf087b0__41->GetZaxis()->SetLabelFont(42);
   frame_3bf087b0__41->GetZaxis()->SetTitleOffset(1);
   frame_3bf087b0__41->GetZaxis()->SetTitleFont(42);
   frame_3bf087b0__41->Draw("FUNC");
   
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
   5.534764,
   10.75762,
   15.61995,
   24.82373,
   53.31346,
   79.92404,
   107.0154,
   144.8836,
   161.0688,
   157.9659,
   115.6157,
   85.41077,
   56.59045,
   25.53456,
   11.15199,
   6.063254,
   2.526167,
   0.5086779,
   0.2673933,
   0.8646559,
   0.1825309,
   0.2552069,
   0.03985614};
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
   1.323367,
   1.920307,
   2.260802,
   2.914775,
   4.45161,
   5.495383,
   6.30124,
   7.401699,
   7.915948,
   7.863079,
   6.619528,
   5.592792,
   4.496775,
   3.006435,
   1.84126,
   1.189511,
   0.7968588,
   0.2482009,
   0.1981501,
   0.3245093,
   0.09330454,
   0.1119726,
   0.02941084};
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
   1.323367,
   1.920307,
   2.260802,
   2.914775,
   4.45161,
   5.495383,
   6.30124,
   7.401699,
   7.915948,
   7.863079,
   6.619528,
   5.592792,
   4.496775,
   3.006435,
   1.84126,
   1.189511,
   0.7968588,
   0.2482009,
   0.1981501,
   0.3245093,
   0.09330454,
   0.1119726,
   0.02941084};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3011,h_dh_down2_fy3011,h_dh_down2_felx3011,h_dh_down2_fehx3011,h_dh_down2_fely3011,h_dh_down2_fehy3011);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23011 = new TH1F("Graph_h_dh_down23011","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23011->SetMinimum(0);
   Graph_h_dh_down23011->SetMaximum(185.8832);
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
   
   Double_t down_fx11[56] = {
   0.3676916,
   0.3874655,
   0.4072394,
   0.4270132,
   0.4467871,
   0.466561,
   0.4863348,
   0.5061087,
   0.5258826,
   0.5456564,
   0.5654303,
   0.5852042,
   0.6049781,
   0.6445258,
   0.6840735,
   0.7038474,
   0.7236213,
   0.7433951,
   0.763169,
   0.7829429,
   0.7928298,
   0.8027168,
   0.8126037,
   0.8224906,
   0.8323776,
   0.8422645,
   0.8521514,
   0.8620384,
   0.8719253,
   0.8818122,
   0.8916992,
   0.9015861,
   0.911473,
   0.92136,
   0.9411338,
   0.9609077,
   0.9806816,
   1.000455,
   1.020229,
   1.040003,
   1.079551,
   1.099325,
   1.119099,
   1.138873,
   1.158646,
   1.17842,
   1.198194,
   1.217968,
   1.237742,
   1.257516,
   1.27729,
   1.297063,
   1.316837,
   1.336611,
   1.356385,
   1.356385};
   Double_t down_fy11[56] = {
   10.81656,
   13.44039,
   16.54915,
   20.19205,
   24.41329,
   29.24913,
   34.72487,
   40.85163,
   47.62325,
   55.01355,
   62.974,
   71.43217,
   80.29111,
   98.70463,
   116.9961,
   125.6464,
   133.7117,
   141.0035,
   147.3436,
   152.5716,
   154.7249,
   156.5514,
   158.0389,
   159.1774,
   159.9591,
   160.3787,
   160.4334,
   160.1227,
   159.4489,
   158.4165,
   157.0324,
   155.3061,
   153.2492,
   150.8752,
   145.2406,
   138.5477,
   130.9638,
   122.6718,
   113.862,
   104.7258,
   86.20391,
   77.14806,
   68.41701,
   60.12347,
   52.35583,
   45.178,
   38.63047,
   32.7321,
   27.48266,
   22.86571,
   18.85174,
   15.40137,
   12.46833,
   10.00226,
   7.951128,
   7.951128};
   graph = new TGraph(56,down_fx11,down_fy11);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down11 = new TH1F("Graph_down11","Projection of downf DSCB fit",100,0.2688223,1.455254);
   Graph_down11->SetMinimum(7.156016);
   Graph_down11->SetMaximum(175.6816);
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
   
   TH1D *frame_3bf087b0__42 = new TH1D("frame_3bf087b0__42","p_T Balance",25,0,2);
   frame_3bf087b0__42->SetBinContent(1,177.434);
   frame_3bf087b0__42->SetMaximum(177.434);
   frame_3bf087b0__42->SetEntries(1);
   frame_3bf087b0__42->SetDirectory(0);
   frame_3bf087b0__42->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf087b0__42->SetLineColor(ci);
   frame_3bf087b0__42->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf087b0__42->GetXaxis()->SetLabelFont(42);
   frame_3bf087b0__42->GetXaxis()->SetTitleOffset(1);
   frame_3bf087b0__42->GetXaxis()->SetTitleFont(42);
   frame_3bf087b0__42->GetYaxis()->SetTitle("1/Events");
   frame_3bf087b0__42->GetYaxis()->SetLabelFont(42);
   frame_3bf087b0__42->GetYaxis()->SetTitleFont(42);
   frame_3bf087b0__42->GetZaxis()->SetLabelFont(42);
   frame_3bf087b0__42->GetZaxis()->SetTitleOffset(1);
   frame_3bf087b0__42->GetZaxis()->SetTitleFont(42);
   frame_3bf087b0__42->Draw("AXISSAME");
   
   TH1D *norm_d__43 = new TH1D("norm_d__43","",25,0,2);
   norm_d__43->SetBinContent(3,5.534764);
   norm_d__43->SetBinContent(4,10.75762);
   norm_d__43->SetBinContent(5,15.61995);
   norm_d__43->SetBinContent(6,24.82373);
   norm_d__43->SetBinContent(7,53.31346);
   norm_d__43->SetBinContent(8,79.92404);
   norm_d__43->SetBinContent(9,107.0154);
   norm_d__43->SetBinContent(10,144.8836);
   norm_d__43->SetBinContent(11,161.0688);
   norm_d__43->SetBinContent(12,157.9659);
   norm_d__43->SetBinContent(13,115.6157);
   norm_d__43->SetBinContent(14,85.41077);
   norm_d__43->SetBinContent(15,56.59045);
   norm_d__43->SetBinContent(16,25.53457);
   norm_d__43->SetBinContent(17,11.15199);
   norm_d__43->SetBinContent(18,6.063254);
   norm_d__43->SetBinContent(19,2.526167);
   norm_d__43->SetBinContent(20,0.5086779);
   norm_d__43->SetBinContent(21,0.2673933);
   norm_d__43->SetBinContent(22,0.8646559);
   norm_d__43->SetBinContent(23,0.1825309);
   norm_d__43->SetBinContent(24,0.2552069);
   norm_d__43->SetBinContent(25,0.03985614);
   norm_d__43->SetBinContent(26,0.4065728);
   norm_d__43->SetBinError(3,1.323367);
   norm_d__43->SetBinError(4,1.920307);
   norm_d__43->SetBinError(5,2.260802);
   norm_d__43->SetBinError(6,2.914775);
   norm_d__43->SetBinError(7,4.45161);
   norm_d__43->SetBinError(8,5.495383);
   norm_d__43->SetBinError(9,6.30124);
   norm_d__43->SetBinError(10,7.401699);
   norm_d__43->SetBinError(11,7.915948);
   norm_d__43->SetBinError(12,7.863079);
   norm_d__43->SetBinError(13,6.619528);
   norm_d__43->SetBinError(14,5.592792);
   norm_d__43->SetBinError(15,4.496775);
   norm_d__43->SetBinError(16,3.006435);
   norm_d__43->SetBinError(17,1.84126);
   norm_d__43->SetBinError(18,1.189511);
   norm_d__43->SetBinError(19,0.7968588);
   norm_d__43->SetBinError(20,0.2482009);
   norm_d__43->SetBinError(21,0.1981501);
   norm_d__43->SetBinError(22,0.3245093);
   norm_d__43->SetBinError(23,0.09330454);
   norm_d__43->SetBinError(24,0.1119726);
   norm_d__43->SetBinError(25,0.02941084);
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
   entry=leg->AddEntry("frame_x_d2_3bf087b0","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.848720 #pm 0.006873","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.207105 #pm 0.005853","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.781000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3bf087b0_copy__44 = new TH1D("frame_3bf087b0_copy__44","p_T Balance",25,0,2);
   frame_3bf087b0_copy__44->SetBinContent(1,177.434);
   frame_3bf087b0_copy__44->SetMaximum(177.434);
   frame_3bf087b0_copy__44->SetEntries(1);
   frame_3bf087b0_copy__44->SetDirectory(0);
   frame_3bf087b0_copy__44->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf087b0_copy__44->SetLineColor(ci);
   frame_3bf087b0_copy__44->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf087b0_copy__44->GetXaxis()->SetLabelFont(42);
   frame_3bf087b0_copy__44->GetXaxis()->SetTitleOffset(1);
   frame_3bf087b0_copy__44->GetXaxis()->SetTitleFont(42);
   frame_3bf087b0_copy__44->GetYaxis()->SetTitle("1/Events");
   frame_3bf087b0_copy__44->GetYaxis()->SetLabelFont(42);
   frame_3bf087b0_copy__44->GetYaxis()->SetTitleFont(42);
   frame_3bf087b0_copy__44->GetZaxis()->SetLabelFont(42);
   frame_3bf087b0_copy__44->GetZaxis()->SetTitleOffset(1);
   frame_3bf087b0_copy__44->GetZaxis()->SetTitleFont(42);
   frame_3bf087b0_copy__44->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-24.25223,2.25,218.2701);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3bf1c660__45 = new TH1D("frame_3bf1c660__45","p_T Balance",25,0,2);
   frame_3bf1c660__45->SetBinContent(1,213.4197);
   frame_3bf1c660__45->SetMaximum(213.4197);
   frame_3bf1c660__45->SetEntries(1);
   frame_3bf1c660__45->SetDirectory(0);
   frame_3bf1c660__45->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf1c660__45->SetLineColor(ci);
   frame_3bf1c660__45->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf1c660__45->GetXaxis()->SetLabelFont(42);
   frame_3bf1c660__45->GetXaxis()->SetTitleOffset(1);
   frame_3bf1c660__45->GetXaxis()->SetTitleFont(42);
   frame_3bf1c660__45->GetYaxis()->SetTitle("1/Events");
   frame_3bf1c660__45->GetYaxis()->SetLabelFont(42);
   frame_3bf1c660__45->GetYaxis()->SetTitleFont(42);
   frame_3bf1c660__45->GetZaxis()->SetLabelFont(42);
   frame_3bf1c660__45->GetZaxis()->SetTitleOffset(1);
   frame_3bf1c660__45->GetZaxis()->SetTitleFont(42);
   frame_3bf1c660__45->Draw("FUNC");
   
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
   4,
   17,
   16,
   29,
   58,
   99,
   142,
   189,
   165,
   150,
   155,
   110,
   54,
   31,
   15,
   7,
   4,
   4,
   2,
   2,
   1,
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
   1.914339,
   4.082184,
   3.957801,
   5.353932,
   7.593751,
   9.933044,
   11.42686,
   13.25682,
   12.35496,
   11.75765,
   11.95994,
   10,
   7.32564,
   5.537565,
   3.82938,
   2.58147,
   1.914339,
   1.914339,
   1.291815,
   1.291815,
   0.8272462,
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
   3.162753,
   5.203719,
   5.083066,
   6.44702,
   8.659564,
   10.9834,
   12.42686,
   14.25682,
   13.35496,
   12.75765,
   12.95994,
   11,
   8.39385,
   6.627601,
   4.958738,
   3.770281,
   3.162753,
   3.162753,
   2.63786,
   2.63786,
   2.299527,
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
   Graph_h_dh_data23012->SetMaximum(223.5825);
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
   0.2659309,
   0.2885044,
   0.311078,
   0.3336515,
   0.3562251,
   0.3787986,
   0.4013721,
   0.4239457,
   0.4465192,
   0.4690928,
   0.4916663,
   0.5142398,
   0.5368134,
   0.5593869,
   0.5819605,
   0.6271076,
   0.6496811,
   0.6722546,
   0.6948282,
   0.7174017,
   0.7399753,
   0.751262,
   0.7625488,
   0.7738356,
   0.7851224,
   0.7964091,
   0.8076959,
   0.8189827,
   0.8302694,
   0.8415562,
   0.852843,
   0.8641298,
   0.8754165,
   0.8867033,
   0.8979901,
   0.9092768,
   0.9205636,
   0.9431371,
   0.9657107,
   0.9882842,
   1.010858,
   1.033431,
   1.078578,
   1.101152,
   1.123725,
   1.146299,
   1.168873,
   1.191446,
   1.21402,
   1.236593,
   1.259167,
   1.28174,
   1.304314,
   1.326887,
   1.349461,
   1.372034,
   1.394608,
   1.394608};
   Double_t observation_fy12[58] = {
   6.655757,
   8.607171,
   11.0151,
   13.95024,
   17.48397,
   21.68521,
   26.61657,
   32.33,
   38.86195,
   46.22835,
   54.41986,
   63.39742,
   73.08879,
   83.38638,
   94.14659,
   116.3105,
   127.2693,
   137.8141,
   147.6823,
   156.6133,
   164.3592,
   167.7166,
   170.6964,
   173.2762,
   175.4364,
   177.1605,
   178.4351,
   179.2503,
   179.5999,
   179.4809,
   178.8944,
   177.845,
   176.3407,
   174.3934,
   172.0179,
   169.2324,
   166.058,
   158.6394,
   149.978,
   140.3166,
   129.9139,
   119.0329,
   96.84694,
   85.99891,
   75.57273,
   65.72073,
   56.55939,
   48.16951,
   40.59801,
   33.86121,
   27.94894,
   22.82933,
   18.45382,
   14.76197,
   11.68605,
   9.154952,
   7.097568,
   7.097568};
   graph = new TGraph(58,observation_fx12,observation_fy12);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation12 = new TH1F("Graph_observation12","Projection of obsf DSCB fit",100,0.1530632,1.507476);
   Graph_observation12->SetMinimum(5.990181);
   Graph_observation12->SetMaximum(196.8943);
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
   
   TH1D *frame_3bf1c660__46 = new TH1D("frame_3bf1c660__46","p_T Balance",25,0,2);
   frame_3bf1c660__46->SetBinContent(1,213.4197);
   frame_3bf1c660__46->SetMaximum(213.4197);
   frame_3bf1c660__46->SetEntries(1);
   frame_3bf1c660__46->SetDirectory(0);
   frame_3bf1c660__46->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf1c660__46->SetLineColor(ci);
   frame_3bf1c660__46->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf1c660__46->GetXaxis()->SetLabelFont(42);
   frame_3bf1c660__46->GetXaxis()->SetTitleOffset(1);
   frame_3bf1c660__46->GetXaxis()->SetTitleFont(42);
   frame_3bf1c660__46->GetYaxis()->SetTitle("1/Events");
   frame_3bf1c660__46->GetYaxis()->SetLabelFont(42);
   frame_3bf1c660__46->GetYaxis()->SetTitleFont(42);
   frame_3bf1c660__46->GetZaxis()->SetLabelFont(42);
   frame_3bf1c660__46->GetZaxis()->SetTitleOffset(1);
   frame_3bf1c660__46->GetZaxis()->SetTitleFont(42);
   frame_3bf1c660__46->Draw("AXISSAME");
   
   TH1D *norm_o__47 = new TH1D("norm_o__47","",25,0,2);
   norm_o__47->SetBinContent(3,4);
   norm_o__47->SetBinContent(4,17);
   norm_o__47->SetBinContent(5,16);
   norm_o__47->SetBinContent(6,29);
   norm_o__47->SetBinContent(7,58);
   norm_o__47->SetBinContent(8,99);
   norm_o__47->SetBinContent(9,142);
   norm_o__47->SetBinContent(10,189);
   norm_o__47->SetBinContent(11,165);
   norm_o__47->SetBinContent(12,150);
   norm_o__47->SetBinContent(13,155);
   norm_o__47->SetBinContent(14,110);
   norm_o__47->SetBinContent(15,54);
   norm_o__47->SetBinContent(16,31);
   norm_o__47->SetBinContent(17,15);
   norm_o__47->SetBinContent(18,7);
   norm_o__47->SetBinContent(19,4);
   norm_o__47->SetBinContent(20,4);
   norm_o__47->SetBinContent(21,2);
   norm_o__47->SetBinContent(22,2);
   norm_o__47->SetBinContent(23,1);
   norm_o__47->SetMinimum(0);
   norm_o__47->SetMaximum(415.8);
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
   entry=leg->AddEntry("frame_x_o2_3bf1c660","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.839965 #pm 0.006255","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.210925 #pm 0.004913","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.849000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3bf1c660_copy__48 = new TH1D("frame_3bf1c660_copy__48","p_T Balance",25,0,2);
   frame_3bf1c660_copy__48->SetBinContent(1,213.4197);
   frame_3bf1c660_copy__48->SetMaximum(213.4197);
   frame_3bf1c660_copy__48->SetEntries(1);
   frame_3bf1c660_copy__48->SetDirectory(0);
   frame_3bf1c660_copy__48->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3bf1c660_copy__48->SetLineColor(ci);
   frame_3bf1c660_copy__48->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3bf1c660_copy__48->GetXaxis()->SetLabelFont(42);
   frame_3bf1c660_copy__48->GetXaxis()->SetTitleOffset(1);
   frame_3bf1c660_copy__48->GetXaxis()->SetTitleFont(42);
   frame_3bf1c660_copy__48->GetYaxis()->SetTitle("1/Events");
   frame_3bf1c660_copy__48->GetYaxis()->SetLabelFont(42);
   frame_3bf1c660_copy__48->GetYaxis()->SetTitleFont(42);
   frame_3bf1c660_copy__48->GetZaxis()->SetLabelFont(42);
   frame_3bf1c660_copy__48->GetZaxis()->SetTitleOffset(1);
   frame_3bf1c660_copy__48->GetZaxis()->SetTitleFont(42);
   frame_3bf1c660_copy__48->Draw("sameaxis");
   
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
