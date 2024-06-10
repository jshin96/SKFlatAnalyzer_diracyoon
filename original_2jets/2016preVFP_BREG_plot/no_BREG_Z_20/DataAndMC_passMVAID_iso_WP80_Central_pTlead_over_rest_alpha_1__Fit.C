void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_1__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 16:32:34 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-2.418287,2.25,18.20276);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_2fdae5b0__1 = new TH1D("frame_2fdae5b0__1","p_T Balance",25,0,2);
   frame_2fdae5b0__1->SetBinContent(1,16.14066);
   frame_2fdae5b0__1->SetMinimum(-0.7686027);
   frame_2fdae5b0__1->SetMaximum(16.14066);
   frame_2fdae5b0__1->SetEntries(1);
   frame_2fdae5b0__1->SetDirectory(0);
   frame_2fdae5b0__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_2fdae5b0__1->SetLineColor(ci);
   frame_2fdae5b0__1->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fdae5b0__1->GetXaxis()->SetLabelFont(42);
   frame_2fdae5b0__1->GetXaxis()->SetTitleOffset(1);
   frame_2fdae5b0__1->GetXaxis()->SetTitleFont(42);
   frame_2fdae5b0__1->GetYaxis()->SetTitle("1/Events");
   frame_2fdae5b0__1->GetYaxis()->SetLabelFont(42);
   frame_2fdae5b0__1->GetYaxis()->SetTitleFont(42);
   frame_2fdae5b0__1->GetZaxis()->SetLabelFont(42);
   frame_2fdae5b0__1->GetZaxis()->SetTitleOffset(1);
   frame_2fdae5b0__1->GetZaxis()->SetTitleFont(42);
   frame_2fdae5b0__1->Draw("FUNC");
   
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
   0,
   0.2377922,
   0.06022587,
   0.06276494,
   0.2510789,
   0.3487851,
   1.173328,
   2.145849,
   4.451724,
   7.287353,
   10.9594,
   13.87035,
   11.35094,
   7.076927,
   2.79586,
   0.6906589,
   0.3959526,
   0.1426669,
   0.03615576,
   0.007282548,
   0,
   0.005909765,
   0,
   0.01420382,
   0};
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
   0,
   0.1641549,
   0.05457359,
   0.04702597,
   0.2044528,
   0.2050959,
   0.4231513,
   0.6076391,
   0.8637749,
   1.146977,
   1.328893,
   1.501709,
   1.353529,
   1.040095,
   0.6901906,
   0.3217497,
   0.2050575,
   0.07409441,
   0.01966474,
   0.007282548,
   0,
   0.005909765,
   0,
   0.01005488,
   0};
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
   0,
   0.1641549,
   0.05457359,
   0.04702597,
   0.2044528,
   0.2050959,
   0.4231513,
   0.6076391,
   0.8637749,
   1.146977,
   1.328893,
   1.501709,
   1.353529,
   1.040095,
   0.6901906,
   0.3217497,
   0.2050575,
   0.07409441,
   0.01966474,
   0.007282548,
   0,
   0.005909765,
   0,
   0.01005488,
   0};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3001,h_dh_central2_fy3001,h_dh_central2_felx3001,h_dh_central2_fehx3001,h_dh_central2_fely3001,h_dh_central2_fehy3001);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23001 = new TH1F("Graph_h_dh_central23001","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23001->SetMinimum(-1.537205);
   Graph_h_dh_central23001->SetMaximum(16.90926);
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
   
   Double_t Central_fx1[59] = {
   0.5693549,
   0.5969831,
   0.6246113,
   0.6384254,
   0.6522395,
   0.6660537,
   0.6798678,
   0.6936819,
   0.707496,
   0.7144031,
   0.7213101,
   0.7282172,
   0.7351242,
   0.7489384,
   0.7627525,
   0.7903807,
   0.8041948,
   0.8180089,
   0.831823,
   0.8456372,
   0.8594513,
   0.8663583,
   0.8732654,
   0.8801724,
   0.8870795,
   0.8939866,
   0.9008936,
   0.9078007,
   0.9147077,
   0.9216148,
   0.9285218,
   0.9354289,
   0.942336,
   0.949243,
   0.9561501,
   0.9630571,
   0.9699642,
   0.9768713,
   0.9837783,
   0.9975924,
   1.011407,
   1.025221,
   1.039035,
   1.066663,
   1.080477,
   1.094291,
   1.108105,
   1.121919,
   1.135734,
   1.149548,
   1.163362,
   1.177176,
   1.19099,
   1.204804,
   1.211711,
   1.218618,
   1.232432,
   1.260061,
   1.260061};
   Double_t Central_fy1[59] = {
   2.452502,
   2.697442,
   3.0024,
   3.184975,
   3.393448,
   3.633939,
   3.914697,
   4.247125,
   4.647463,
   4.880172,
   5.1397,
   5.431117,
   5.760878,
   6.533295,
   7.350014,
   9.022578,
   9.845035,
   10.63361,
   11.36897,
   12.03202,
   12.60471,
   12.85202,
   13.07086,
   13.25962,
   13.4169,
   13.54153,
   13.63256,
   13.6893,
   13.71132,
   13.69846,
   13.6508,
   13.56873,
   13.45284,
   13.30403,
   13.12341,
   12.91233,
   12.67233,
   12.40517,
   12.11276,
   11.46058,
   10.73364,
   9.950945,
   9.131847,
   7.458954,
   6.639004,
   5.849313,
   5.101334,
   4.403921,
   3.763329,
   3.183331,
   2.665437,
   2.209184,
   1.812476,
   1.471938,
   1.331471,
   1.276585,
   1.228786,
   1.18478,
   1.18478};
   TGraph *graph = new TGraph(59,Central_fx1,Central_fy1);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central1 = new TH1F("Graph_Central1","Projection of centralf DSCB fit",100,0.5002843,1.329131);
   Graph_Central1->SetMinimum(1.066302);
   Graph_Central1->SetMaximum(14.96398);
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
   
   TH1D *frame_2fdae5b0__2 = new TH1D("frame_2fdae5b0__2","p_T Balance",25,0,2);
   frame_2fdae5b0__2->SetBinContent(1,16.14066);
   frame_2fdae5b0__2->SetMinimum(-0.7686027);
   frame_2fdae5b0__2->SetMaximum(16.14066);
   frame_2fdae5b0__2->SetEntries(1);
   frame_2fdae5b0__2->SetDirectory(0);
   frame_2fdae5b0__2->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fdae5b0__2->SetLineColor(ci);
   frame_2fdae5b0__2->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fdae5b0__2->GetXaxis()->SetLabelFont(42);
   frame_2fdae5b0__2->GetXaxis()->SetTitleOffset(1);
   frame_2fdae5b0__2->GetXaxis()->SetTitleFont(42);
   frame_2fdae5b0__2->GetYaxis()->SetTitle("1/Events");
   frame_2fdae5b0__2->GetYaxis()->SetLabelFont(42);
   frame_2fdae5b0__2->GetYaxis()->SetTitleFont(42);
   frame_2fdae5b0__2->GetZaxis()->SetLabelFont(42);
   frame_2fdae5b0__2->GetZaxis()->SetTitleOffset(1);
   frame_2fdae5b0__2->GetZaxis()->SetTitleFont(42);
   frame_2fdae5b0__2->Draw("AXISSAME");
   
   TH1D *norm_c__3 = new TH1D("norm_c__3","",25,0,2);
   norm_c__3->SetBinContent(2,0.2377922);
   norm_c__3->SetBinContent(3,0.06022587);
   norm_c__3->SetBinContent(4,0.06276494);
   norm_c__3->SetBinContent(5,0.2510789);
   norm_c__3->SetBinContent(6,0.3487851);
   norm_c__3->SetBinContent(7,1.173328);
   norm_c__3->SetBinContent(8,2.145848);
   norm_c__3->SetBinContent(9,4.451724);
   norm_c__3->SetBinContent(10,7.287352);
   norm_c__3->SetBinContent(11,10.95941);
   norm_c__3->SetBinContent(12,13.87035);
   norm_c__3->SetBinContent(13,11.35094);
   norm_c__3->SetBinContent(14,7.076927);
   norm_c__3->SetBinContent(15,2.79586);
   norm_c__3->SetBinContent(16,0.6906588);
   norm_c__3->SetBinContent(17,0.3959526);
   norm_c__3->SetBinContent(18,0.1426669);
   norm_c__3->SetBinContent(19,0.03615576);
   norm_c__3->SetBinContent(20,0.007282548);
   norm_c__3->SetBinContent(22,0.005909765);
   norm_c__3->SetBinContent(24,0.01420382);
   norm_c__3->SetBinContent(26,0.002007776);
   norm_c__3->SetBinError(2,0.1641549);
   norm_c__3->SetBinError(3,0.05457359);
   norm_c__3->SetBinError(4,0.04702597);
   norm_c__3->SetBinError(5,0.2044528);
   norm_c__3->SetBinError(6,0.2050959);
   norm_c__3->SetBinError(7,0.4231513);
   norm_c__3->SetBinError(8,0.6076391);
   norm_c__3->SetBinError(9,0.8637749);
   norm_c__3->SetBinError(10,1.146977);
   norm_c__3->SetBinError(11,1.328893);
   norm_c__3->SetBinError(12,1.501709);
   norm_c__3->SetBinError(13,1.353529);
   norm_c__3->SetBinError(14,1.040095);
   norm_c__3->SetBinError(15,0.6901906);
   norm_c__3->SetBinError(16,0.3217497);
   norm_c__3->SetBinError(17,0.2050575);
   norm_c__3->SetBinError(18,0.07409441);
   norm_c__3->SetBinError(19,0.01966474);
   norm_c__3->SetBinError(20,0.007282548);
   norm_c__3->SetBinError(22,0.005909765);
   norm_c__3->SetBinError(24,0.01005488);
   norm_c__3->SetBinError(26,0.002007776);
   norm_c__3->SetEntries(659);
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
   entry=leg->AddEntry("frame_x_c2_2fdae5b0","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.925282 #pm 0.020942","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.132329 #pm 0.018435","");
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
   
   TH1D *frame_2fdae5b0_copy__4 = new TH1D("frame_2fdae5b0_copy__4","p_T Balance",25,0,2);
   frame_2fdae5b0_copy__4->SetBinContent(1,16.14066);
   frame_2fdae5b0_copy__4->SetMinimum(-0.7686027);
   frame_2fdae5b0_copy__4->SetMaximum(16.14066);
   frame_2fdae5b0_copy__4->SetEntries(1);
   frame_2fdae5b0_copy__4->SetDirectory(0);
   frame_2fdae5b0_copy__4->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fdae5b0_copy__4->SetLineColor(ci);
   frame_2fdae5b0_copy__4->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fdae5b0_copy__4->GetXaxis()->SetLabelFont(42);
   frame_2fdae5b0_copy__4->GetXaxis()->SetTitleOffset(1);
   frame_2fdae5b0_copy__4->GetXaxis()->SetTitleFont(42);
   frame_2fdae5b0_copy__4->GetYaxis()->SetTitle("1/Events");
   frame_2fdae5b0_copy__4->GetYaxis()->SetLabelFont(42);
   frame_2fdae5b0_copy__4->GetYaxis()->SetTitleFont(42);
   frame_2fdae5b0_copy__4->GetZaxis()->SetLabelFont(42);
   frame_2fdae5b0_copy__4->GetZaxis()->SetTitleOffset(1);
   frame_2fdae5b0_copy__4->GetZaxis()->SetTitleFont(42);
   frame_2fdae5b0_copy__4->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-2.642887,2.25,19.89336);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_2fd9f800__5 = new TH1D("frame_2fd9f800__5","p_T Balance",25,0,2);
   frame_2fd9f800__5->SetBinContent(1,17.63973);
   frame_2fd9f800__5->SetMinimum(-0.8399872);
   frame_2fd9f800__5->SetMaximum(17.63973);
   frame_2fd9f800__5->SetEntries(1);
   frame_2fd9f800__5->SetDirectory(0);
   frame_2fd9f800__5->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fd9f800__5->SetLineColor(ci);
   frame_2fd9f800__5->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fd9f800__5->GetXaxis()->SetLabelFont(42);
   frame_2fd9f800__5->GetXaxis()->SetTitleOffset(1);
   frame_2fd9f800__5->GetXaxis()->SetTitleFont(42);
   frame_2fd9f800__5->GetYaxis()->SetTitle("1/Events");
   frame_2fd9f800__5->GetYaxis()->SetLabelFont(42);
   frame_2fd9f800__5->GetYaxis()->SetTitleFont(42);
   frame_2fd9f800__5->GetZaxis()->SetLabelFont(42);
   frame_2fd9f800__5->GetZaxis()->SetTitleOffset(1);
   frame_2fd9f800__5->GetZaxis()->SetTitleFont(42);
   frame_2fd9f800__5->Draw("FUNC");
   
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
   0,
   0.08706787,
   0.005966688,
   0.2605147,
   0.2515105,
   0.1026682,
   1.221588,
   1.844828,
   3.483023,
   6.112326,
   11.31278,
   15.18285,
   11.86019,
   6.461939,
   3.372061,
   1.366799,
   0.4556446,
   0.09173502,
   0.1792049,
   0.007265698,
   0,
   0.005908025,
   0,
   0.006757129,
   0};
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
   0,
   0.06462234,
   0.005966688,
   0.2034934,
   0.2048593,
   0.07312223,
   0.4258594,
   0.5402333,
   0.7589396,
   1.035667,
   1.365811,
   1.61689,
   1.387453,
   0.9718306,
   0.7683824,
   0.4638223,
   0.2132822,
   0.04241729,
   0.09746851,
   0.007265698,
   0,
   0.005908025,
   0,
   0.006757129,
   0};
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
   0,
   0.06462234,
   0.005966688,
   0.2034934,
   0.2048593,
   0.07312223,
   0.4258594,
   0.5402333,
   0.7589396,
   1.035667,
   1.365811,
   1.61689,
   1.387453,
   0.9718306,
   0.7683824,
   0.4638223,
   0.2132822,
   0.04241729,
   0.09746851,
   0.007265698,
   0,
   0.005908025,
   0,
   0.006757129,
   0};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3002,h_dh_up2_fy3002,h_dh_up2_felx3002,h_dh_up2_fehx3002,h_dh_up2_fely3002,h_dh_up2_fehy3002);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23002 = new TH1F("Graph_h_dh_up23002","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23002->SetMinimum(-1.679974);
   Graph_h_dh_up23002->SetMaximum(18.47972);
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
   0.5944008,
   0.6210181,
   0.6476354,
   0.6742527,
   0.7008701,
   0.7141787,
   0.720833,
   0.7241602,
   0.7274874,
   0.740796,
   0.7541047,
   0.7674133,
   0.780722,
   0.8073393,
   0.820648,
   0.8339566,
   0.8472653,
   0.8539196,
   0.860574,
   0.8672283,
   0.8738826,
   0.8805369,
   0.8871913,
   0.8938456,
   0.9004999,
   0.9071543,
   0.9138086,
   0.9204629,
   0.9271172,
   0.9337716,
   0.9404259,
   0.9470802,
   0.9537346,
   0.9603889,
   0.9670432,
   0.9736975,
   0.9803519,
   0.9936605,
   1.006969,
   1.020278,
   1.033587,
   1.040241,
   1.046895,
   1.053549,
   1.060204,
   1.073512,
   1.086821,
   1.10013,
   1.113438,
   1.126747,
   1.140056,
   1.153364,
   1.166673,
   1.179982,
   1.206599,
   1.233216,
   1.259834,
   1.259834};
   Double_t up_fy2[58] = {
   3.225975,
   3.261247,
   3.30695,
   3.371567,
   3.481164,
   3.586153,
   3.680732,
   3.758442,
   3.896938,
   4.680833,
   5.547946,
   6.488595,
   7.488219,
   9.582139,
   10.62475,
   11.62476,
   12.55044,
   12.97552,
   13.37036,
   13.73137,
   14.0552,
   14.33878,
   14.57941,
   14.77475,
   14.92288,
   15.02233,
   15.07212,
   15.07176,
   15.02124,
   14.92107,
   14.77224,
   14.57623,
   14.33496,
   14.05077,
   13.72638,
   13.36486,
   12.96955,
   12.09215,
   11.12477,
   10.09923,
   9.047256,
   8.543496,
   8.074356,
   7.637019,
   7.228929,
   6.491434,
   5.845739,
   5.278456,
   4.778423,
   4.336289,
   3.944186,
   3.595467,
   3.284493,
   3.006462,
   2.5334,
   2.149922,
   1.836408,
   1.836408};
   graph = new TGraph(58,up_fx2,up_fy2);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up2 = new TH1F("Graph_up2","Projection of upf DSCB fit",100,0.5278575,1.326377);
   Graph_up2->SetMinimum(0.5128362);
   Graph_up2->SetMaximum(16.39569);
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
   
   TH1D *frame_2fd9f800__6 = new TH1D("frame_2fd9f800__6","p_T Balance",25,0,2);
   frame_2fd9f800__6->SetBinContent(1,17.63973);
   frame_2fd9f800__6->SetMinimum(-0.8399872);
   frame_2fd9f800__6->SetMaximum(17.63973);
   frame_2fd9f800__6->SetEntries(1);
   frame_2fd9f800__6->SetDirectory(0);
   frame_2fd9f800__6->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fd9f800__6->SetLineColor(ci);
   frame_2fd9f800__6->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fd9f800__6->GetXaxis()->SetLabelFont(42);
   frame_2fd9f800__6->GetXaxis()->SetTitleOffset(1);
   frame_2fd9f800__6->GetXaxis()->SetTitleFont(42);
   frame_2fd9f800__6->GetYaxis()->SetTitle("1/Events");
   frame_2fd9f800__6->GetYaxis()->SetLabelFont(42);
   frame_2fd9f800__6->GetYaxis()->SetTitleFont(42);
   frame_2fd9f800__6->GetZaxis()->SetLabelFont(42);
   frame_2fd9f800__6->GetZaxis()->SetTitleOffset(1);
   frame_2fd9f800__6->GetZaxis()->SetTitleFont(42);
   frame_2fd9f800__6->Draw("AXISSAME");
   
   TH1D *norm_u__7 = new TH1D("norm_u__7","",25,0,2);
   norm_u__7->SetBinContent(2,0.08706787);
   norm_u__7->SetBinContent(3,0.005966688);
   norm_u__7->SetBinContent(4,0.2605147);
   norm_u__7->SetBinContent(5,0.2515105);
   norm_u__7->SetBinContent(6,0.1026682);
   norm_u__7->SetBinContent(7,1.221588);
   norm_u__7->SetBinContent(8,1.844828);
   norm_u__7->SetBinContent(9,3.483023);
   norm_u__7->SetBinContent(10,6.112326);
   norm_u__7->SetBinContent(11,11.31278);
   norm_u__7->SetBinContent(12,15.18285);
   norm_u__7->SetBinContent(13,11.86019);
   norm_u__7->SetBinContent(14,6.461939);
   norm_u__7->SetBinContent(15,3.37206);
   norm_u__7->SetBinContent(16,1.366799);
   norm_u__7->SetBinContent(17,0.4556446);
   norm_u__7->SetBinContent(18,0.09173502);
   norm_u__7->SetBinContent(19,0.1792049);
   norm_u__7->SetBinContent(20,0.007265698);
   norm_u__7->SetBinContent(22,0.005908025);
   norm_u__7->SetBinContent(24,0.006757129);
   norm_u__7->SetBinContent(26,0.006617274);
   norm_u__7->SetBinError(2,0.06462234);
   norm_u__7->SetBinError(3,0.005966688);
   norm_u__7->SetBinError(4,0.2034934);
   norm_u__7->SetBinError(5,0.2048593);
   norm_u__7->SetBinError(6,0.07312223);
   norm_u__7->SetBinError(7,0.4258594);
   norm_u__7->SetBinError(8,0.5402333);
   norm_u__7->SetBinError(9,0.7589396);
   norm_u__7->SetBinError(10,1.035667);
   norm_u__7->SetBinError(11,1.365811);
   norm_u__7->SetBinError(12,1.61689);
   norm_u__7->SetBinError(13,1.387453);
   norm_u__7->SetBinError(14,0.9718306);
   norm_u__7->SetBinError(15,0.7683824);
   norm_u__7->SetBinError(16,0.4638223);
   norm_u__7->SetBinError(17,0.2132822);
   norm_u__7->SetBinError(18,0.04241729);
   norm_u__7->SetBinError(19,0.09746851);
   norm_u__7->SetBinError(20,0.007265698);
   norm_u__7->SetBinError(22,0.005908025);
   norm_u__7->SetBinError(24,0.006757129);
   norm_u__7->SetBinError(26,0.006617274);
   norm_u__7->SetEntries(662);
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
   entry=leg->AddEntry("frame_x_u2_2fd9f800","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.931214 #pm 0.019279","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.136298 #pm 0.019763","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.974000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_2fd9f800_copy__8 = new TH1D("frame_2fd9f800_copy__8","p_T Balance",25,0,2);
   frame_2fd9f800_copy__8->SetBinContent(1,17.63973);
   frame_2fd9f800_copy__8->SetMinimum(-0.8399872);
   frame_2fd9f800_copy__8->SetMaximum(17.63973);
   frame_2fd9f800_copy__8->SetEntries(1);
   frame_2fd9f800_copy__8->SetDirectory(0);
   frame_2fd9f800_copy__8->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fd9f800_copy__8->SetLineColor(ci);
   frame_2fd9f800_copy__8->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fd9f800_copy__8->GetXaxis()->SetLabelFont(42);
   frame_2fd9f800_copy__8->GetXaxis()->SetTitleOffset(1);
   frame_2fd9f800_copy__8->GetXaxis()->SetTitleFont(42);
   frame_2fd9f800_copy__8->GetYaxis()->SetTitle("1/Events");
   frame_2fd9f800_copy__8->GetYaxis()->SetLabelFont(42);
   frame_2fd9f800_copy__8->GetYaxis()->SetTitleFont(42);
   frame_2fd9f800_copy__8->GetZaxis()->SetLabelFont(42);
   frame_2fd9f800_copy__8->GetZaxis()->SetTitleOffset(1);
   frame_2fd9f800_copy__8->GetZaxis()->SetTitleFont(42);
   frame_2fd9f800_copy__8->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-2.435847,2.25,14.96306);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_2fda7200__9 = new TH1D("frame_2fda7200__9","p_T Balance",25,0,2);
   frame_2fda7200__9->SetBinContent(1,14.61508);
   frame_2fda7200__9->SetMinimum(-0.6959562);
   frame_2fda7200__9->SetMaximum(14.61508);
   frame_2fda7200__9->SetEntries(1);
   frame_2fda7200__9->SetDirectory(0);
   frame_2fda7200__9->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fda7200__9->SetLineColor(ci);
   frame_2fda7200__9->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fda7200__9->GetXaxis()->SetLabelFont(42);
   frame_2fda7200__9->GetXaxis()->SetTitleOffset(1);
   frame_2fda7200__9->GetXaxis()->SetTitleFont(42);
   frame_2fda7200__9->GetYaxis()->SetTitle("1/Events");
   frame_2fda7200__9->GetYaxis()->SetLabelFont(42);
   frame_2fda7200__9->GetYaxis()->SetTitleFont(42);
   frame_2fda7200__9->GetZaxis()->SetLabelFont(42);
   frame_2fda7200__9->GetZaxis()->SetTitleOffset(1);
   frame_2fda7200__9->GetZaxis()->SetTitleFont(42);
   frame_2fda7200__9->Draw("FUNC");
   
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
   0,
   0.1419003,
   0.0541905,
   0.06329668,
   0.2076381,
   0.5677814,
   0.823185,
   2.943583,
   4.480722,
   6.34282,
   10.48112,
   12.52291,
   9.867994,
   6.377982,
   2.770936,
   0.3770072,
   0.3153286,
   0.1277831,
   0.03471287,
   0.007328762,
   0,
   0.005947959,
   0,
   0.01432347,
   0};
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
   0,
   0.08475995,
   0.0541905,
   0.04741159,
   0.1622938,
   0.2693717,
   0.36272,
   0.7032675,
   0.86451,
   1.039065,
   1.304926,
   1.396213,
   1.240106,
   0.9856768,
   0.6804873,
   0.2494322,
   0.1915559,
   0.07245974,
   0.01974265,
   0.007328762,
   0,
   0.005947959,
   0,
   0.01014077,
   0};
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
   0,
   0.08475995,
   0.0541905,
   0.04741159,
   0.1622938,
   0.2693717,
   0.36272,
   0.7032675,
   0.86451,
   1.039065,
   1.304926,
   1.396213,
   1.240106,
   0.9856768,
   0.6804873,
   0.2494322,
   0.1915559,
   0.07245974,
   0.01974265,
   0.007328762,
   0,
   0.005947959,
   0,
   0.01014077,
   0};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3003,h_dh_down2_fy3003,h_dh_down2_felx3003,h_dh_down2_fehx3003,h_dh_down2_fely3003,h_dh_down2_fehy3003);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23003 = new TH1F("Graph_h_dh_down23003","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23003->SetMinimum(-1.391912);
   Graph_h_dh_down23003->SetMaximum(15.31104);
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
   0.5314532,
   0.5610589,
   0.5906647,
   0.6054676,
   0.6202704,
   0.6350733,
   0.6498762,
   0.664679,
   0.6794819,
   0.6942848,
   0.7090877,
   0.7238905,
   0.7386934,
   0.7460948,
   0.7534963,
   0.7682992,
   0.7979049,
   0.8127078,
   0.8275106,
   0.8423135,
   0.849715,
   0.8571164,
   0.8645178,
   0.8719193,
   0.8793207,
   0.8867221,
   0.8941236,
   0.901525,
   0.9089264,
   0.9163279,
   0.9237293,
   0.9311308,
   0.9385322,
   0.9459336,
   0.9533351,
   0.9607365,
   0.9681379,
   0.9755394,
   0.9903422,
   1.005145,
   1.019948,
   1.034751,
   1.064357,
   1.079159,
   1.093962,
   1.108765,
   1.123568,
   1.138371,
   1.153174,
   1.167977,
   1.18278,
   1.197582,
   1.212385,
   1.227188,
   1.241991,
   1.256794,
   1.271597,
   1.271597};
   Double_t down_fy3[58] = {
   1.556245,
   1.836608,
   2.183049,
   2.386925,
   2.615168,
   2.871357,
   3.159701,
   3.485165,
   3.853636,
   4.272117,
   4.748978,
   5.294272,
   5.920128,
   6.267748,
   6.641262,
   7.426354,
   8.982085,
   9.715084,
   10.3919,
   10.99316,
   11.25974,
   11.50083,
   11.71452,
   11.89912,
   12.05313,
   12.1753,
   12.26462,
   12.32036,
   12.34206,
   12.32952,
   12.28287,
   12.20249,
   12.08903,
   11.94344,
   11.7669,
   11.56084,
   11.32692,
   11.06697,
   10.47724,
   9.809444,
   9.082823,
   8.317185,
   6.745663,
   5.974717,
   5.233463,
   4.533567,
   3.883918,
   3.29063,
   2.757193,
   2.284728,
   1.872323,
   1.517421,
   1.216215,
   0.9640377,
   0.7557125,
   0.5858659,
   0.4491785,
   0.4491785};
   graph = new TGraph(58,down_fx3,down_fy3);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down3 = new TH1F("Graph_down3","Projection of downf DSCB fit",100,0.4574388,1.345611);
   Graph_down3->SetMinimum(0.4042607);
   Graph_down3->SetMaximum(13.53134);
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
   
   TH1D *frame_2fda7200__10 = new TH1D("frame_2fda7200__10","p_T Balance",25,0,2);
   frame_2fda7200__10->SetBinContent(1,14.61508);
   frame_2fda7200__10->SetMinimum(-0.6959562);
   frame_2fda7200__10->SetMaximum(14.61508);
   frame_2fda7200__10->SetEntries(1);
   frame_2fda7200__10->SetDirectory(0);
   frame_2fda7200__10->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fda7200__10->SetLineColor(ci);
   frame_2fda7200__10->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fda7200__10->GetXaxis()->SetLabelFont(42);
   frame_2fda7200__10->GetXaxis()->SetTitleOffset(1);
   frame_2fda7200__10->GetXaxis()->SetTitleFont(42);
   frame_2fda7200__10->GetYaxis()->SetTitle("1/Events");
   frame_2fda7200__10->GetYaxis()->SetLabelFont(42);
   frame_2fda7200__10->GetYaxis()->SetTitleFont(42);
   frame_2fda7200__10->GetZaxis()->SetLabelFont(42);
   frame_2fda7200__10->GetZaxis()->SetTitleOffset(1);
   frame_2fda7200__10->GetZaxis()->SetTitleFont(42);
   frame_2fda7200__10->Draw("AXISSAME");
   
   TH1D *norm_d__11 = new TH1D("norm_d__11","",25,0,2);
   norm_d__11->SetBinContent(2,0.1419003);
   norm_d__11->SetBinContent(3,0.0541905);
   norm_d__11->SetBinContent(4,0.06329668);
   norm_d__11->SetBinContent(5,0.2076381);
   norm_d__11->SetBinContent(6,0.5677814);
   norm_d__11->SetBinContent(7,0.823185);
   norm_d__11->SetBinContent(8,2.943583);
   norm_d__11->SetBinContent(9,4.480722);
   norm_d__11->SetBinContent(10,6.34282);
   norm_d__11->SetBinContent(11,10.48112);
   norm_d__11->SetBinContent(12,12.52291);
   norm_d__11->SetBinContent(13,9.867994);
   norm_d__11->SetBinContent(14,6.377982);
   norm_d__11->SetBinContent(15,2.770936);
   norm_d__11->SetBinContent(16,0.3770072);
   norm_d__11->SetBinContent(17,0.3153286);
   norm_d__11->SetBinContent(18,0.1277831);
   norm_d__11->SetBinContent(19,0.03471287);
   norm_d__11->SetBinContent(20,0.007328762);
   norm_d__11->SetBinContent(22,0.005947959);
   norm_d__11->SetBinContent(24,0.01432347);
   norm_d__11->SetBinContent(26,0.001945317);
   norm_d__11->SetBinError(2,0.08475995);
   norm_d__11->SetBinError(3,0.0541905);
   norm_d__11->SetBinError(4,0.04741159);
   norm_d__11->SetBinError(5,0.1622938);
   norm_d__11->SetBinError(6,0.2693717);
   norm_d__11->SetBinError(7,0.36272);
   norm_d__11->SetBinError(8,0.7032675);
   norm_d__11->SetBinError(9,0.86451);
   norm_d__11->SetBinError(10,1.039065);
   norm_d__11->SetBinError(11,1.304926);
   norm_d__11->SetBinError(12,1.396213);
   norm_d__11->SetBinError(13,1.240106);
   norm_d__11->SetBinError(14,0.9856768);
   norm_d__11->SetBinError(15,0.6804873);
   norm_d__11->SetBinError(16,0.2494322);
   norm_d__11->SetBinError(17,0.1915559);
   norm_d__11->SetBinError(18,0.07245974);
   norm_d__11->SetBinError(19,0.01974265);
   norm_d__11->SetBinError(20,0.007328762);
   norm_d__11->SetBinError(22,0.005947959);
   norm_d__11->SetBinError(24,0.01014077);
   norm_d__11->SetBinError(26,0.001945317);
   norm_d__11->SetEntries(644);
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
   entry=leg->AddEntry("frame_x_d2_2fda7200","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.896787 #pm 0.021714","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.153772 #pm 0.018957","");
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
   
   TH1D *frame_2fda7200_copy__12 = new TH1D("frame_2fda7200_copy__12","p_T Balance",25,0,2);
   frame_2fda7200_copy__12->SetBinContent(1,14.61508);
   frame_2fda7200_copy__12->SetMinimum(-0.6959562);
   frame_2fda7200_copy__12->SetMaximum(14.61508);
   frame_2fda7200_copy__12->SetEntries(1);
   frame_2fda7200_copy__12->SetDirectory(0);
   frame_2fda7200_copy__12->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fda7200_copy__12->SetLineColor(ci);
   frame_2fda7200_copy__12->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fda7200_copy__12->GetXaxis()->SetLabelFont(42);
   frame_2fda7200_copy__12->GetXaxis()->SetTitleOffset(1);
   frame_2fda7200_copy__12->GetXaxis()->SetTitleFont(42);
   frame_2fda7200_copy__12->GetYaxis()->SetTitle("1/Events");
   frame_2fda7200_copy__12->GetYaxis()->SetLabelFont(42);
   frame_2fda7200_copy__12->GetYaxis()->SetTitleFont(42);
   frame_2fda7200_copy__12->GetZaxis()->SetLabelFont(42);
   frame_2fda7200_copy__12->GetZaxis()->SetTitleOffset(1);
   frame_2fda7200_copy__12->GetZaxis()->SetTitleFont(42);
   frame_2fda7200_copy__12->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-3.968552,2.25,35.71697);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_2fdba1b0__13 = new TH1D("frame_2fdba1b0__13","p_T Balance",25,0,2);
   frame_2fdba1b0__13->SetBinContent(1,34.92326);
   frame_2fdba1b0__13->SetMaximum(34.92326);
   frame_2fdba1b0__13->SetEntries(1);
   frame_2fdba1b0__13->SetDirectory(0);
   frame_2fdba1b0__13->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fdba1b0__13->SetLineColor(ci);
   frame_2fdba1b0__13->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fdba1b0__13->GetXaxis()->SetLabelFont(42);
   frame_2fdba1b0__13->GetXaxis()->SetTitleOffset(1);
   frame_2fdba1b0__13->GetXaxis()->SetTitleFont(42);
   frame_2fdba1b0__13->GetYaxis()->SetTitle("1/Events");
   frame_2fdba1b0__13->GetYaxis()->SetLabelFont(42);
   frame_2fdba1b0__13->GetYaxis()->SetTitleFont(42);
   frame_2fdba1b0__13->GetZaxis()->SetLabelFont(42);
   frame_2fdba1b0__13->GetZaxis()->SetTitleOffset(1);
   frame_2fdba1b0__13->GetZaxis()->SetTitleFont(42);
   frame_2fdba1b0__13->Draw("FUNC");
   
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
   2,
   0,
   0,
   0,
   1,
   0,
   2,
   1,
   6,
   12,
   27,
   12,
   10,
   6,
   0,
   0,
   0,
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
   1.291815,
   0,
   0,
   0,
   0.8272462,
   0,
   1.291815,
   0.8272462,
   2.379931,
   3.415266,
   5.163771,
   3.415266,
   3.108694,
   2.379931,
   0,
   0,
   0,
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
   2.63786,
   1.147874,
   1.147874,
   1.147874,
   2.299527,
   1.147874,
   2.63786,
   2.299527,
   3.583642,
   4.559819,
   6.260244,
   4.559819,
   4.26695,
   3.583642,
   1.147874,
   1.147874,
   1.147874,
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
   Graph_h_dh_data23004->SetMaximum(36.58627);
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
   
   Double_t observation_fx4[67] = {
   0.6274925,
   0.6521527,
   0.6768129,
   0.7014731,
   0.7261334,
   0.7384635,
   0.7507936,
   0.7631237,
   0.7754538,
   0.7877839,
   0.800114,
   0.8124441,
   0.8186091,
   0.8247742,
   0.8309393,
   0.8371043,
   0.8432694,
   0.8494344,
   0.8555995,
   0.8617645,
   0.8679296,
   0.8740946,
   0.8802597,
   0.8864247,
   0.8925898,
   0.8956723,
   0.8987548,
   0.9018374,
   0.9049199,
   0.9080024,
   0.9110849,
   0.9141675,
   0.91725,
   0.9203325,
   0.923415,
   0.9264976,
   0.9295801,
   0.9326626,
   0.9357452,
   0.9388277,
   0.9419102,
   0.9449927,
   0.9480753,
   0.9542403,
   0.9604054,
   0.9665704,
   0.9727355,
   0.9789005,
   0.9850656,
   0.9912306,
   0.9973957,
   1.009726,
   1.022056,
   1.034386,
   1.046716,
   1.059046,
   1.071376,
   1.083706,
   1.096037,
   1.108367,
   1.120697,
   1.145357,
   1.170017,
   1.194677,
   1.219338,
   1.243998,
   1.243998};
   Double_t observation_fy4[67] = {
   1.482031,
   1.793822,
   2.192094,
   2.707294,
   3.383144,
   3.800259,
   4.283686,
   4.846486,
   5.504826,
   6.278845,
   7.193814,
   8.281688,
   8.902779,
   9.5832,
   10.32989,
   11.15073,
   12.05476,
   13.05228,
   14.15515,
   15.37701,
   16.7336,
   18.24314,
   19.92681,
   21.7899,
   23.56117,
   24.3608,
   25.09203,
   25.74715,
   26.31916,
   26.80181,
   27.18977,
   27.47871,
   27.66537,
   27.74764,
   27.72457,
   27.59644,
   27.36469,
   27.03195,
   26.60195,
   26.07949,
   25.47029,
   24.78096,
   24.03681,
   22.61722,
   21.30145,
   20.0805,
   18.94625,
   17.8914,
   16.90935,
   15.99412,
   15.14032,
   13.59784,
   12.24787,
   11.06219,
   10.01729,
   9.093526,
   8.274372,
   7.545881,
   6.896236,
   6.315379,
   5.794724,
   4.905612,
   4.18145,
   3.586735,
   3.094583,
   2.684419,
   2.684419};
   graph = new TGraph(67,observation_fx4,observation_fy4);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation4 = new TH1F("Graph_observation4","Projection of obsf DSCB fit",100,0.565842,1.305648);
   Graph_observation4->SetMinimum(1.333828);
   Graph_observation4->SetMaximum(30.3742);
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
   
   TH1D *frame_2fdba1b0__14 = new TH1D("frame_2fdba1b0__14","p_T Balance",25,0,2);
   frame_2fdba1b0__14->SetBinContent(1,34.92326);
   frame_2fdba1b0__14->SetMaximum(34.92326);
   frame_2fdba1b0__14->SetEntries(1);
   frame_2fdba1b0__14->SetDirectory(0);
   frame_2fdba1b0__14->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fdba1b0__14->SetLineColor(ci);
   frame_2fdba1b0__14->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fdba1b0__14->GetXaxis()->SetLabelFont(42);
   frame_2fdba1b0__14->GetXaxis()->SetTitleOffset(1);
   frame_2fdba1b0__14->GetXaxis()->SetTitleFont(42);
   frame_2fdba1b0__14->GetYaxis()->SetTitle("1/Events");
   frame_2fdba1b0__14->GetYaxis()->SetLabelFont(42);
   frame_2fdba1b0__14->GetYaxis()->SetTitleFont(42);
   frame_2fdba1b0__14->GetZaxis()->SetLabelFont(42);
   frame_2fdba1b0__14->GetZaxis()->SetTitleOffset(1);
   frame_2fdba1b0__14->GetZaxis()->SetTitleFont(42);
   frame_2fdba1b0__14->Draw("AXISSAME");
   
   TH1D *norm_o__15 = new TH1D("norm_o__15","",25,0,2);
   norm_o__15->SetBinContent(2,2);
   norm_o__15->SetBinContent(6,1);
   norm_o__15->SetBinContent(8,2);
   norm_o__15->SetBinContent(9,1);
   norm_o__15->SetBinContent(10,6);
   norm_o__15->SetBinContent(11,12);
   norm_o__15->SetBinContent(12,27);
   norm_o__15->SetBinContent(13,12);
   norm_o__15->SetBinContent(14,10);
   norm_o__15->SetBinContent(15,6);
   norm_o__15->SetMinimum(0);
   norm_o__15->SetMaximum(59.4);
   norm_o__15->SetEntries(79);
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
   entry=leg->AddEntry("frame_x_o2_2fdba1b0","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.945474 #pm 0.013797","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.115111 #pm 0.010980","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.992000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_2fdba1b0_copy__16 = new TH1D("frame_2fdba1b0_copy__16","p_T Balance",25,0,2);
   frame_2fdba1b0_copy__16->SetBinContent(1,34.92326);
   frame_2fdba1b0_copy__16->SetMaximum(34.92326);
   frame_2fdba1b0_copy__16->SetEntries(1);
   frame_2fdba1b0_copy__16->SetDirectory(0);
   frame_2fdba1b0_copy__16->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fdba1b0_copy__16->SetLineColor(ci);
   frame_2fdba1b0_copy__16->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fdba1b0_copy__16->GetXaxis()->SetLabelFont(42);
   frame_2fdba1b0_copy__16->GetXaxis()->SetTitleOffset(1);
   frame_2fdba1b0_copy__16->GetXaxis()->SetTitleFont(42);
   frame_2fdba1b0_copy__16->GetYaxis()->SetTitle("1/Events");
   frame_2fdba1b0_copy__16->GetYaxis()->SetLabelFont(42);
   frame_2fdba1b0_copy__16->GetYaxis()->SetTitleFont(42);
   frame_2fdba1b0_copy__16->GetZaxis()->SetLabelFont(42);
   frame_2fdba1b0_copy__16->GetZaxis()->SetTitleOffset(1);
   frame_2fdba1b0_copy__16->GetZaxis()->SetTitleFont(42);
   frame_2fdba1b0_copy__16->Draw("sameaxis");
   
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
