void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_2__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 17:50:12 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-8.483073,2.25,63.85321);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_367168d0__17 = new TH1D("frame_367168d0__17","p_T Balance",25,0,2);
   frame_367168d0__17->SetBinContent(1,56.61958);
   frame_367168d0__17->SetMinimum(-2.69617);
   frame_367168d0__17->SetMaximum(56.61958);
   frame_367168d0__17->SetEntries(1);
   frame_367168d0__17->SetDirectory(0);
   frame_367168d0__17->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_367168d0__17->SetLineColor(ci);
   frame_367168d0__17->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367168d0__17->GetXaxis()->SetLabelFont(42);
   frame_367168d0__17->GetXaxis()->SetTitleOffset(1);
   frame_367168d0__17->GetXaxis()->SetTitleFont(42);
   frame_367168d0__17->GetYaxis()->SetTitle("1/Events");
   frame_367168d0__17->GetYaxis()->SetLabelFont(42);
   frame_367168d0__17->GetYaxis()->SetTitleFont(42);
   frame_367168d0__17->GetZaxis()->SetLabelFont(42);
   frame_367168d0__17->GetZaxis()->SetTitleOffset(1);
   frame_367168d0__17->GetZaxis()->SetTitleFont(42);
   frame_367168d0__17->Draw("FUNC");
   
   Double_t h_dh_central2_fx3005[25] = {
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
   Double_t h_dh_central2_fy3005[25] = {
   0,
   0.1459324,
   0.9616627,
   1.46701,
   1.554107,
   3.529139,
   7.831844,
   15.77155,
   31.5286,
   36.80734,
   49.8982,
   46.85124,
   33.99132,
   21.6657,
   12.93771,
   7.176903,
   1.448478,
   0.597326,
   1.133459,
   0.3541145,
   0.1219482,
   0.06456129,
   0.04932179,
   0.00522773,
   0.01053963};
   Double_t h_dh_central2_felx3005[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_central2_fely3005[25] = {
   0,
   0.1067807,
   0.4574232,
   0.4283155,
   0.5642139,
   0.9346348,
   1.495687,
   2.310786,
   3.462162,
   3.413493,
   4.025202,
   3.984092,
   3.305798,
   2.555437,
   1.875766,
   1.314947,
   0.4728437,
   0.2362811,
   0.3573627,
   0.1753342,
   0.1219482,
   0.04777722,
   0.04073921,
   0.00522773,
   0.01053963};
   Double_t h_dh_central2_fehx3005[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_central2_fehy3005[25] = {
   0,
   0.1067807,
   0.4574232,
   0.4283155,
   0.5642139,
   0.9346348,
   1.495687,
   2.310786,
   3.462162,
   3.413493,
   4.025202,
   3.984092,
   3.305798,
   2.555437,
   1.875766,
   1.314947,
   0.4728437,
   0.2362811,
   0.3573627,
   0.1753342,
   0.1219482,
   0.04777722,
   0.04073921,
   0.00522773,
   0.01053963};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3005,h_dh_central2_fy3005,h_dh_central2_felx3005,h_dh_central2_fehx3005,h_dh_central2_fely3005,h_dh_central2_fehy3005);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23005 = new TH1F("Graph_h_dh_central23005","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23005->SetMinimum(-5.392341);
   Graph_h_dh_central23005->SetMaximum(59.31575);
   Graph_h_dh_central23005->SetDirectory(0);
   Graph_h_dh_central23005->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_central23005->SetLineColor(ci);
   Graph_h_dh_central23005->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_central23005->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_central23005->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_central23005->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_central23005->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_central23005->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_central23005->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_central23005->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_central23005);
   
   grae->Draw("p");
   
   Double_t Central_fx5[59] = {
   0.3967033,
   0.4152196,
   0.4337359,
   0.4522523,
   0.4707686,
   0.4892849,
   0.5078012,
   0.5263175,
   0.5448339,
   0.5633502,
   0.5818665,
   0.6003828,
   0.6188991,
   0.6374155,
   0.6559318,
   0.6929644,
   0.7114807,
   0.7299971,
   0.7485134,
   0.7670297,
   0.785546,
   0.7948042,
   0.8040623,
   0.8133205,
   0.8225787,
   0.8318368,
   0.841095,
   0.8503531,
   0.8596113,
   0.8688695,
   0.8781276,
   0.8873858,
   0.8966439,
   0.9059021,
   0.9151603,
   0.9244184,
   0.9336766,
   0.9429347,
   0.9521929,
   0.9707092,
   0.9892255,
   1.007742,
   1.026258,
   1.063291,
   1.081807,
   1.100323,
   1.11884,
   1.137356,
   1.155872,
   1.174389,
   1.183647,
   1.192905,
   1.211421,
   1.229938,
   1.248454,
   1.26697,
   1.285487,
   1.322519,
   1.322519};
   Double_t Central_fy5[59] = {
   2.31022,
   2.724437,
   3.23604,
   3.873894,
   4.677371,
   5.700965,
   6.993731,
   8.504177,
   10.23287,
   12.18442,
   14.35669,
   16.73962,
   19.31429,
   22.05231,
   24.91559,
   30.81992,
   33.7423,
   36.55609,
   39.19104,
   41.57726,
   43.64825,
   44.54645,
   45.344,
   46.03488,
   46.61383,
   47.07637,
   47.41892,
   47.63881,
   47.7343,
   47.70466,
   47.5501,
   47.27185,
   46.87209,
   46.35392,
   45.72136,
   44.97925,
   44.13325,
   43.18968,
   42.15554,
   39.84606,
   37.26989,
   34.49632,
   31.59581,
   25.68435,
   22.79561,
   20.02054,
   17.39972,
   14.96411,
   12.73507,
   10.72491,
   9.81134,
   9.002882,
   7.660172,
   6.597818,
   5.742761,
   5.044296,
   4.466339,
   3.573725,
   3.573725};
   TGraph *graph = new TGraph(59,Central_fx5,Central_fy5);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central5 = new TH1F("Graph_Central5","Projection of centralf DSCB fit",100,0.3041217,1.415101);
   Graph_Central5->SetMinimum(2.079198);
   Graph_Central5->SetMaximum(52.27671);
   Graph_Central5->SetDirectory(0);
   Graph_Central5->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Central5->SetLineColor(ci);
   Graph_Central5->GetXaxis()->SetLabelFont(42);
   Graph_Central5->GetXaxis()->SetTitleOffset(1);
   Graph_Central5->GetXaxis()->SetTitleFont(42);
   Graph_Central5->GetYaxis()->SetLabelFont(42);
   Graph_Central5->GetYaxis()->SetTitleFont(42);
   Graph_Central5->GetZaxis()->SetLabelFont(42);
   Graph_Central5->GetZaxis()->SetTitleOffset(1);
   Graph_Central5->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Central5);
   
   graph->Draw("l");
   
   TH1D *frame_367168d0__18 = new TH1D("frame_367168d0__18","p_T Balance",25,0,2);
   frame_367168d0__18->SetBinContent(1,56.61958);
   frame_367168d0__18->SetMinimum(-2.69617);
   frame_367168d0__18->SetMaximum(56.61958);
   frame_367168d0__18->SetEntries(1);
   frame_367168d0__18->SetDirectory(0);
   frame_367168d0__18->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367168d0__18->SetLineColor(ci);
   frame_367168d0__18->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367168d0__18->GetXaxis()->SetLabelFont(42);
   frame_367168d0__18->GetXaxis()->SetTitleOffset(1);
   frame_367168d0__18->GetXaxis()->SetTitleFont(42);
   frame_367168d0__18->GetYaxis()->SetTitle("1/Events");
   frame_367168d0__18->GetYaxis()->SetLabelFont(42);
   frame_367168d0__18->GetYaxis()->SetTitleFont(42);
   frame_367168d0__18->GetZaxis()->SetLabelFont(42);
   frame_367168d0__18->GetZaxis()->SetTitleOffset(1);
   frame_367168d0__18->GetZaxis()->SetTitleFont(42);
   frame_367168d0__18->Draw("AXISSAME");
   
   TH1D *norm_c__19 = new TH1D("norm_c__19","",25,0,2);
   norm_c__19->SetBinContent(2,0.1459324);
   norm_c__19->SetBinContent(3,0.9616627);
   norm_c__19->SetBinContent(4,1.46701);
   norm_c__19->SetBinContent(5,1.554107);
   norm_c__19->SetBinContent(6,3.529139);
   norm_c__19->SetBinContent(7,7.831844);
   norm_c__19->SetBinContent(8,15.77155);
   norm_c__19->SetBinContent(9,31.5286);
   norm_c__19->SetBinContent(10,36.80734);
   norm_c__19->SetBinContent(11,49.89821);
   norm_c__19->SetBinContent(12,46.85124);
   norm_c__19->SetBinContent(13,33.99132);
   norm_c__19->SetBinContent(14,21.66571);
   norm_c__19->SetBinContent(15,12.93771);
   norm_c__19->SetBinContent(16,7.176903);
   norm_c__19->SetBinContent(17,1.448478);
   norm_c__19->SetBinContent(18,0.597326);
   norm_c__19->SetBinContent(19,1.133459);
   norm_c__19->SetBinContent(20,0.3541145);
   norm_c__19->SetBinContent(21,0.1219482);
   norm_c__19->SetBinContent(22,0.06456128);
   norm_c__19->SetBinContent(23,0.04932179);
   norm_c__19->SetBinContent(24,0.00522773);
   norm_c__19->SetBinContent(25,0.01053963);
   norm_c__19->SetBinContent(26,0.08021484);
   norm_c__19->SetBinError(2,0.1067807);
   norm_c__19->SetBinError(3,0.4574232);
   norm_c__19->SetBinError(4,0.4283155);
   norm_c__19->SetBinError(5,0.5642139);
   norm_c__19->SetBinError(6,0.9346348);
   norm_c__19->SetBinError(7,1.495687);
   norm_c__19->SetBinError(8,2.310786);
   norm_c__19->SetBinError(9,3.462162);
   norm_c__19->SetBinError(10,3.413493);
   norm_c__19->SetBinError(11,4.025202);
   norm_c__19->SetBinError(12,3.984092);
   norm_c__19->SetBinError(13,3.305798);
   norm_c__19->SetBinError(14,2.555437);
   norm_c__19->SetBinError(15,1.875766);
   norm_c__19->SetBinError(16,1.314947);
   norm_c__19->SetBinError(17,0.4728437);
   norm_c__19->SetBinError(18,0.2362811);
   norm_c__19->SetBinError(19,0.3573627);
   norm_c__19->SetBinError(20,0.1753342);
   norm_c__19->SetBinError(21,0.1219482);
   norm_c__19->SetBinError(22,0.04777722);
   norm_c__19->SetBinError(23,0.04073921);
   norm_c__19->SetBinError(24,0.00522773);
   norm_c__19->SetBinError(25,0.01053963);
   norm_c__19->SetBinError(26,0.05266801);
   norm_c__19->SetEntries(1528);
   norm_c__19->SetStats(0);

   ci = 1319;
   color = new TColor(ci, 0.3, 0.3, 0.3, " ", 0.6);
   norm_c__19->SetFillColor(ci);
   norm_c__19->SetFillStyle(3144);
   norm_c__19->SetLineColor(2);
   norm_c__19->SetLineWidth(2);
   norm_c__19->GetXaxis()->SetRange(1,25);
   norm_c__19->GetXaxis()->SetLabelFont(42);
   norm_c__19->GetXaxis()->SetLabelSize(0.04);
   norm_c__19->GetXaxis()->SetTitleOffset(1);
   norm_c__19->GetXaxis()->SetTitleFont(42);
   norm_c__19->GetYaxis()->SetLabelFont(42);
   norm_c__19->GetYaxis()->SetTitleFont(42);
   norm_c__19->GetZaxis()->SetLabelFont(42);
   norm_c__19->GetZaxis()->SetTitleOffset(1);
   norm_c__19->GetZaxis()->SetTitleFont(42);
   norm_c__19->Draw("e1 same");
   
   TLegend *leg = new TLegend(0.65,0.5,0.93,0.87,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.03);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("norm_c","Central","lpf");

   ci = 1319;
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
   entry=leg->AddEntry("frame_x_c2_367168d0","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.864153 #pm 0.011784","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.184769 #pm 0.009722","");
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
   
   TH1D *frame_367168d0_copy__20 = new TH1D("frame_367168d0_copy__20","p_T Balance",25,0,2);
   frame_367168d0_copy__20->SetBinContent(1,56.61958);
   frame_367168d0_copy__20->SetMinimum(-2.69617);
   frame_367168d0_copy__20->SetMaximum(56.61958);
   frame_367168d0_copy__20->SetEntries(1);
   frame_367168d0_copy__20->SetDirectory(0);
   frame_367168d0_copy__20->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367168d0_copy__20->SetLineColor(ci);
   frame_367168d0_copy__20->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367168d0_copy__20->GetXaxis()->SetLabelFont(42);
   frame_367168d0_copy__20->GetXaxis()->SetTitleOffset(1);
   frame_367168d0_copy__20->GetXaxis()->SetTitleFont(42);
   frame_367168d0_copy__20->GetYaxis()->SetTitle("1/Events");
   frame_367168d0_copy__20->GetYaxis()->SetLabelFont(42);
   frame_367168d0_copy__20->GetYaxis()->SetTitleFont(42);
   frame_367168d0_copy__20->GetZaxis()->SetLabelFont(42);
   frame_367168d0_copy__20->GetZaxis()->SetTitleOffset(1);
   frame_367168d0_copy__20->GetZaxis()->SetTitleFont(42);
   frame_367168d0_copy__20->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-8.302388,2.25,62.49317);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_36759bc0__21 = new TH1D("frame_36759bc0__21","p_T Balance",25,0,2);
   frame_36759bc0__21->SetBinContent(1,55.41361);
   frame_36759bc0__21->SetMinimum(-2.638744);
   frame_36759bc0__21->SetMaximum(55.41361);
   frame_36759bc0__21->SetEntries(1);
   frame_36759bc0__21->SetDirectory(0);
   frame_36759bc0__21->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_36759bc0__21->SetLineColor(ci);
   frame_36759bc0__21->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_36759bc0__21->GetXaxis()->SetLabelFont(42);
   frame_36759bc0__21->GetXaxis()->SetTitleOffset(1);
   frame_36759bc0__21->GetXaxis()->SetTitleFont(42);
   frame_36759bc0__21->GetYaxis()->SetTitle("1/Events");
   frame_36759bc0__21->GetYaxis()->SetLabelFont(42);
   frame_36759bc0__21->GetYaxis()->SetTitleFont(42);
   frame_36759bc0__21->GetZaxis()->SetLabelFont(42);
   frame_36759bc0__21->GetZaxis()->SetTitleOffset(1);
   frame_36759bc0__21->GetZaxis()->SetTitleFont(42);
   frame_36759bc0__21->Draw("FUNC");
   
   Double_t h_dh_up2_fx3006[25] = {
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
   Double_t h_dh_up2_fy3006[25] = {
   0,
   0.2711817,
   0.5501163,
   1.372591,
   1.598791,
   2.860021,
   5.107444,
   15.08114,
   28.52487,
   36.34779,
   47.56979,
   48.72885,
   36.47103,
   22.68889,
   14.1071,
   7.423958,
   1.738661,
   0.8993925,
   0.8660935,
   0.4514749,
   0,
   0.1339687,
   0.1017685,
   0.005243741,
   0.01056024};
   Double_t h_dh_up2_felx3006[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_up2_fely3006[25] = {
   0,
   0.1987896,
   0.3491528,
   0.4181937,
   0.646715,
   0.8257474,
   1.132122,
   2.315883,
   3.228055,
   3.520506,
   3.957022,
   4.046023,
   3.409365,
   2.705155,
   1.974988,
   1.362079,
   0.5172516,
   0.2990504,
   0.336829,
   0.1861458,
   0,
   0.1228213,
   0.0615892,
   0.005243742,
   0.01056024};
   Double_t h_dh_up2_fehx3006[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_up2_fehy3006[25] = {
   0,
   0.1987896,
   0.3491528,
   0.4181937,
   0.646715,
   0.8257474,
   1.132122,
   2.315883,
   3.228055,
   3.520506,
   3.957022,
   4.046023,
   3.409365,
   2.705155,
   1.974988,
   1.362079,
   0.5172516,
   0.2990504,
   0.336829,
   0.1861458,
   0,
   0.1228213,
   0.0615892,
   0.005243742,
   0.01056024};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3006,h_dh_up2_fy3006,h_dh_up2_felx3006,h_dh_up2_fehx3006,h_dh_up2_fely3006,h_dh_up2_fehy3006);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23006 = new TH1F("Graph_h_dh_up23006","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23006->SetMinimum(-5.277487);
   Graph_h_dh_up23006->SetMaximum(58.05236);
   Graph_h_dh_up23006->SetDirectory(0);
   Graph_h_dh_up23006->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_up23006->SetLineColor(ci);
   Graph_h_dh_up23006->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_up23006->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_up23006->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_up23006->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_up23006->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_up23006->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_up23006->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_up23006->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_up23006);
   
   grae->Draw("p");
   
   Double_t up_fx6[59] = {
   0.4303039,
   0.4659685,
   0.4838008,
   0.492717,
   0.5016332,
   0.5194655,
   0.5372978,
   0.5551301,
   0.5729625,
   0.5907948,
   0.6086271,
   0.6264594,
   0.6442918,
   0.6621241,
   0.6799564,
   0.715621,
   0.7334534,
   0.7512857,
   0.769118,
   0.7869503,
   0.7958665,
   0.8047827,
   0.8136988,
   0.822615,
   0.8315311,
   0.8404473,
   0.8493635,
   0.8582796,
   0.8671958,
   0.876112,
   0.8850281,
   0.8939443,
   0.9028604,
   0.9117766,
   0.9206928,
   0.9296089,
   0.9385251,
   0.9474412,
   0.9652736,
   0.9831059,
   1.000938,
   1.018771,
   1.036603,
   1.072268,
   1.0901,
   1.107932,
   1.125764,
   1.143597,
   1.161429,
   1.179261,
   1.188178,
   1.197094,
   1.214926,
   1.232758,
   1.250591,
   1.268423,
   1.286255,
   1.32192,
   1.32192};
   Double_t up_fy6[59] = {
   4.04954,
   4.209737,
   4.399682,
   4.678164,
   5.210273,
   6.413762,
   7.815232,
   9.426435,
   11.25459,
   13.30113,
   15.56051,
   18.01922,
   20.65496,
   23.43633,
   26.32276,
   32.20659,
   35.08458,
   37.83244,
   40.38212,
   42.66684,
   43.69003,
   44.62398,
   45.462,
   46.19797,
   46.82646,
   47.3428,
   47.74311,
   48.02437,
   48.18443,
   48.22208,
   48.13703,
   47.92993,
   47.60236,
   47.1568,
   46.5966,
   45.92597,
   45.14988,
   44.27403,
   42.24898,
   39.90801,
   37.31475,
   34.53644,
   31.64107,
   25.75896,
   22.88925,
   20.13315,
   17.52945,
   15.10781,
   12.88876,
   10.88423,
   9.975876,
   9.189398,
   7.917834,
   6.936603,
   6.158242,
   5.526911,
   5.005356,
   4.195911,
   4.195911};
   graph = new TGraph(59,up_fx6,up_fy6);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up6 = new TH1F("Graph_up6","Projection of upf DSCB fit",100,0.3411423,1.411082);
   Graph_up6->SetMinimum(3.644586);
   Graph_up6->SetMaximum(52.63933);
   Graph_up6->SetDirectory(0);
   Graph_up6->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_up6->SetLineColor(ci);
   Graph_up6->GetXaxis()->SetLabelFont(42);
   Graph_up6->GetXaxis()->SetTitleOffset(1);
   Graph_up6->GetXaxis()->SetTitleFont(42);
   Graph_up6->GetYaxis()->SetLabelFont(42);
   Graph_up6->GetYaxis()->SetTitleFont(42);
   Graph_up6->GetZaxis()->SetLabelFont(42);
   Graph_up6->GetZaxis()->SetTitleOffset(1);
   Graph_up6->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_up6);
   
   graph->Draw("l");
   
   TH1D *frame_36759bc0__22 = new TH1D("frame_36759bc0__22","p_T Balance",25,0,2);
   frame_36759bc0__22->SetBinContent(1,55.41361);
   frame_36759bc0__22->SetMinimum(-2.638744);
   frame_36759bc0__22->SetMaximum(55.41361);
   frame_36759bc0__22->SetEntries(1);
   frame_36759bc0__22->SetDirectory(0);
   frame_36759bc0__22->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_36759bc0__22->SetLineColor(ci);
   frame_36759bc0__22->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_36759bc0__22->GetXaxis()->SetLabelFont(42);
   frame_36759bc0__22->GetXaxis()->SetTitleOffset(1);
   frame_36759bc0__22->GetXaxis()->SetTitleFont(42);
   frame_36759bc0__22->GetYaxis()->SetTitle("1/Events");
   frame_36759bc0__22->GetYaxis()->SetLabelFont(42);
   frame_36759bc0__22->GetYaxis()->SetTitleFont(42);
   frame_36759bc0__22->GetZaxis()->SetLabelFont(42);
   frame_36759bc0__22->GetZaxis()->SetTitleOffset(1);
   frame_36759bc0__22->GetZaxis()->SetTitleFont(42);
   frame_36759bc0__22->Draw("AXISSAME");
   
   TH1D *norm_u__23 = new TH1D("norm_u__23","",25,0,2);
   norm_u__23->SetBinContent(2,0.2711817);
   norm_u__23->SetBinContent(3,0.5501163);
   norm_u__23->SetBinContent(4,1.372591);
   norm_u__23->SetBinContent(5,1.598791);
   norm_u__23->SetBinContent(6,2.860021);
   norm_u__23->SetBinContent(7,5.107444);
   norm_u__23->SetBinContent(8,15.08114);
   norm_u__23->SetBinContent(9,28.52487);
   norm_u__23->SetBinContent(10,36.3478);
   norm_u__23->SetBinContent(11,47.56979);
   norm_u__23->SetBinContent(12,48.72885);
   norm_u__23->SetBinContent(13,36.47103);
   norm_u__23->SetBinContent(14,22.68889);
   norm_u__23->SetBinContent(15,14.1071);
   norm_u__23->SetBinContent(16,7.423958);
   norm_u__23->SetBinContent(17,1.738661);
   norm_u__23->SetBinContent(18,0.8993925);
   norm_u__23->SetBinContent(19,0.8660935);
   norm_u__23->SetBinContent(20,0.4514749);
   norm_u__23->SetBinContent(22,0.1339686);
   norm_u__23->SetBinContent(23,0.1017685);
   norm_u__23->SetBinContent(24,0.005243742);
   norm_u__23->SetBinContent(25,0.01056024);
   norm_u__23->SetBinContent(26,0.08357239);
   norm_u__23->SetBinError(2,0.1987896);
   norm_u__23->SetBinError(3,0.3491528);
   norm_u__23->SetBinError(4,0.4181937);
   norm_u__23->SetBinError(5,0.646715);
   norm_u__23->SetBinError(6,0.8257474);
   norm_u__23->SetBinError(7,1.132122);
   norm_u__23->SetBinError(8,2.315883);
   norm_u__23->SetBinError(9,3.228055);
   norm_u__23->SetBinError(10,3.520506);
   norm_u__23->SetBinError(11,3.957022);
   norm_u__23->SetBinError(12,4.046023);
   norm_u__23->SetBinError(13,3.409365);
   norm_u__23->SetBinError(14,2.705155);
   norm_u__23->SetBinError(15,1.974988);
   norm_u__23->SetBinError(16,1.362079);
   norm_u__23->SetBinError(17,0.5172516);
   norm_u__23->SetBinError(18,0.2990504);
   norm_u__23->SetBinError(19,0.336829);
   norm_u__23->SetBinError(20,0.1861458);
   norm_u__23->SetBinError(22,0.1228213);
   norm_u__23->SetBinError(23,0.0615892);
   norm_u__23->SetBinError(24,0.005243742);
   norm_u__23->SetBinError(25,0.01056024);
   norm_u__23->SetBinError(26,0.05284295);
   norm_u__23->SetEntries(1507);
   norm_u__23->SetStats(0);
   norm_u__23->SetLineColor(4);
   norm_u__23->SetLineWidth(2);
   norm_u__23->GetXaxis()->SetLabelFont(42);
   norm_u__23->GetXaxis()->SetTitleOffset(1);
   norm_u__23->GetXaxis()->SetTitleFont(42);
   norm_u__23->GetYaxis()->SetLabelFont(42);
   norm_u__23->GetYaxis()->SetTitleFont(42);
   norm_u__23->GetZaxis()->SetLabelFont(42);
   norm_u__23->GetZaxis()->SetTitleOffset(1);
   norm_u__23->GetZaxis()->SetTitleFont(42);
   norm_u__23->Draw("e1 same");
   
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
   entry=leg->AddEntry("frame_x_u2_36759bc0","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.876878 #pm 0.011633","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.179680 #pm 0.009671","");
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
   
   TH1D *frame_36759bc0_copy__24 = new TH1D("frame_36759bc0_copy__24","p_T Balance",25,0,2);
   frame_36759bc0_copy__24->SetBinContent(1,55.41361);
   frame_36759bc0_copy__24->SetMinimum(-2.638744);
   frame_36759bc0_copy__24->SetMaximum(55.41361);
   frame_36759bc0_copy__24->SetEntries(1);
   frame_36759bc0_copy__24->SetDirectory(0);
   frame_36759bc0_copy__24->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_36759bc0_copy__24->SetLineColor(ci);
   frame_36759bc0_copy__24->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_36759bc0_copy__24->GetXaxis()->SetLabelFont(42);
   frame_36759bc0_copy__24->GetXaxis()->SetTitleOffset(1);
   frame_36759bc0_copy__24->GetXaxis()->SetTitleFont(42);
   frame_36759bc0_copy__24->GetYaxis()->SetTitle("1/Events");
   frame_36759bc0_copy__24->GetYaxis()->SetLabelFont(42);
   frame_36759bc0_copy__24->GetYaxis()->SetTitleFont(42);
   frame_36759bc0_copy__24->GetZaxis()->SetLabelFont(42);
   frame_36759bc0_copy__24->GetZaxis()->SetTitleOffset(1);
   frame_36759bc0_copy__24->GetZaxis()->SetTitleFont(42);
   frame_36759bc0_copy__24->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-8.999497,2.25,55.28262);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3673ccf0__25 = new TH1D("frame_3673ccf0__25","p_T Balance",25,0,2);
   frame_3673ccf0__25->SetBinContent(1,53.99698);
   frame_3673ccf0__25->SetMinimum(-2.571285);
   frame_3673ccf0__25->SetMaximum(53.99698);
   frame_3673ccf0__25->SetEntries(1);
   frame_3673ccf0__25->SetDirectory(0);
   frame_3673ccf0__25->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3673ccf0__25->SetLineColor(ci);
   frame_3673ccf0__25->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3673ccf0__25->GetXaxis()->SetLabelFont(42);
   frame_3673ccf0__25->GetXaxis()->SetTitleOffset(1);
   frame_3673ccf0__25->GetXaxis()->SetTitleFont(42);
   frame_3673ccf0__25->GetYaxis()->SetTitle("1/Events");
   frame_3673ccf0__25->GetYaxis()->SetLabelFont(42);
   frame_3673ccf0__25->GetYaxis()->SetTitleFont(42);
   frame_3673ccf0__25->GetZaxis()->SetLabelFont(42);
   frame_3673ccf0__25->GetZaxis()->SetTitleOffset(1);
   frame_3673ccf0__25->GetZaxis()->SetTitleFont(42);
   frame_3673ccf0__25->Draw("FUNC");
   
   Double_t h_dh_down2_fx3007[25] = {
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
   Double_t h_dh_down2_fy3007[25] = {
   0,
   0.8048773,
   1.005205,
   1.553881,
   1.896798,
   3.275528,
   9.06706,
   16.58924,
   30.61241,
   36.23939,
   47.40276,
   44.4636,
   28.90212,
   19.23357,
   11.654,
   5.584334,
   1.500962,
   0.4709056,
   1.032448,
   0.5068593,
   0.1230039,
   0.07447577,
   0.04030923,
   0.02948215,
   0.1034785};
   Double_t h_dh_down2_felx3007[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_down2_fely3007[25] = {
   0,
   0.6713721,
   0.4516014,
   0.4423499,
   0.6599692,
   0.8248793,
   1.620046,
   2.378651,
   3.320374,
   3.368356,
   4.022937,
   3.620246,
   2.919835,
   2.319172,
   1.643061,
   1.159679,
   0.4737928,
   0.1986724,
   0.3442336,
   0.2602602,
   0.1230039,
   0.04880216,
   0.04030923,
   0.02477717,
   0.09346595};
   Double_t h_dh_down2_fehx3007[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_down2_fehy3007[25] = {
   0,
   0.6713721,
   0.4516014,
   0.4423499,
   0.6599692,
   0.8248793,
   1.620046,
   2.378651,
   3.320374,
   3.368356,
   4.022937,
   3.620246,
   2.919835,
   2.319172,
   1.643061,
   1.159679,
   0.4737928,
   0.1986724,
   0.3442336,
   0.2602602,
   0.1230039,
   0.04880216,
   0.04030923,
   0.02477717,
   0.09346595};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3007,h_dh_down2_fy3007,h_dh_down2_felx3007,h_dh_down2_fehx3007,h_dh_down2_fely3007,h_dh_down2_fehy3007);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23007 = new TH1F("Graph_h_dh_down23007","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23007->SetMinimum(-5.14257);
   Graph_h_dh_down23007->SetMaximum(56.56827);
   Graph_h_dh_down23007->SetDirectory(0);
   Graph_h_dh_down23007->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_down23007->SetLineColor(ci);
   Graph_h_dh_down23007->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_down23007->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_down23007->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_down23007->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_down23007->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_down23007->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_down23007->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_down23007->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_down23007);
   
   grae->Draw("p");
   
   Double_t down_fx7[59] = {
   0.3771245,
   0.3959043,
   0.4146842,
   0.433464,
   0.4522438,
   0.4710237,
   0.4898035,
   0.5085834,
   0.5273632,
   0.546143,
   0.5649229,
   0.5837027,
   0.6024825,
   0.6212624,
   0.6400422,
   0.6776019,
   0.6963817,
   0.7151616,
   0.7339414,
   0.7527213,
   0.7715011,
   0.780891,
   0.7902809,
   0.7996708,
   0.8090608,
   0.8184507,
   0.8278406,
   0.8372305,
   0.8466204,
   0.8560104,
   0.8654003,
   0.8747902,
   0.8841801,
   0.89357,
   0.90296,
   0.9123499,
   0.9217398,
   0.9311297,
   0.9405196,
   0.9592995,
   0.9780793,
   0.9968591,
   1.015639,
   1.053199,
   1.071978,
   1.090758,
   1.109538,
   1.128318,
   1.147098,
   1.165878,
   1.184658,
   1.203437,
   1.222217,
   1.240997,
   1.259777,
   1.278557,
   1.297337,
   1.316116,
   1.316116};
   Double_t down_fy7[59] = {
   1.405633,
   1.833572,
   2.375947,
   3.045345,
   3.860975,
   4.841929,
   6.006212,
   7.369597,
   8.944328,
   10.73773,
   12.75082,
   14.977,
   17.40092,
   19.99771,
   22.73262,
   28.42956,
   31.27676,
   34.03567,
   36.63596,
   39.00693,
   41.08061,
   41.98626,
   42.79498,
   43.50043,
   44.09705,
   44.58007,
   44.9456,
   45.19067,
   45.31329,
   45.31246,
   45.18819,
   44.94148,
   44.57436,
   44.08979,
   43.49167,
   42.7848,
   41.97474,
   41.06783,
   40.07105,
   37.83854,
   35.34262,
   32.65307,
   29.84078,
   24.11932,
   21.33211,
   18.66222,
   16.1493,
   13.82308,
   11.70354,
   9.801443,
   8.119399,
   6.653015,
   5.3923,
   4.323052,
   3.428212,
   2.689093,
   2.086434,
   1.60127,
   1.60127};
   graph = new TGraph(59,down_fx7,down_fy7);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down7 = new TH1F("Graph_down7","Projection of downf DSCB fit",100,0.2832253,1.410016);
   Graph_down7->SetMinimum(1.265069);
   Graph_down7->SetMaximum(49.70406);
   Graph_down7->SetDirectory(0);
   Graph_down7->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_down7->SetLineColor(ci);
   Graph_down7->GetXaxis()->SetLabelFont(42);
   Graph_down7->GetXaxis()->SetTitleOffset(1);
   Graph_down7->GetXaxis()->SetTitleFont(42);
   Graph_down7->GetYaxis()->SetLabelFont(42);
   Graph_down7->GetYaxis()->SetTitleFont(42);
   Graph_down7->GetZaxis()->SetLabelFont(42);
   Graph_down7->GetZaxis()->SetTitleOffset(1);
   Graph_down7->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_down7);
   
   graph->Draw("l");
   
   TH1D *frame_3673ccf0__26 = new TH1D("frame_3673ccf0__26","p_T Balance",25,0,2);
   frame_3673ccf0__26->SetBinContent(1,53.99698);
   frame_3673ccf0__26->SetMinimum(-2.571285);
   frame_3673ccf0__26->SetMaximum(53.99698);
   frame_3673ccf0__26->SetEntries(1);
   frame_3673ccf0__26->SetDirectory(0);
   frame_3673ccf0__26->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3673ccf0__26->SetLineColor(ci);
   frame_3673ccf0__26->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3673ccf0__26->GetXaxis()->SetLabelFont(42);
   frame_3673ccf0__26->GetXaxis()->SetTitleOffset(1);
   frame_3673ccf0__26->GetXaxis()->SetTitleFont(42);
   frame_3673ccf0__26->GetYaxis()->SetTitle("1/Events");
   frame_3673ccf0__26->GetYaxis()->SetLabelFont(42);
   frame_3673ccf0__26->GetYaxis()->SetTitleFont(42);
   frame_3673ccf0__26->GetZaxis()->SetLabelFont(42);
   frame_3673ccf0__26->GetZaxis()->SetTitleOffset(1);
   frame_3673ccf0__26->GetZaxis()->SetTitleFont(42);
   frame_3673ccf0__26->Draw("AXISSAME");
   
   TH1D *norm_d__27 = new TH1D("norm_d__27","",25,0,2);
   norm_d__27->SetBinContent(2,0.8048773);
   norm_d__27->SetBinContent(3,1.005205);
   norm_d__27->SetBinContent(4,1.553881);
   norm_d__27->SetBinContent(5,1.896798);
   norm_d__27->SetBinContent(6,3.275528);
   norm_d__27->SetBinContent(7,9.067059);
   norm_d__27->SetBinContent(8,16.58924);
   norm_d__27->SetBinContent(9,30.61241);
   norm_d__27->SetBinContent(10,36.23939);
   norm_d__27->SetBinContent(11,47.40276);
   norm_d__27->SetBinContent(12,44.4636);
   norm_d__27->SetBinContent(13,28.90212);
   norm_d__27->SetBinContent(14,19.23357);
   norm_d__27->SetBinContent(15,11.654);
   norm_d__27->SetBinContent(16,5.584334);
   norm_d__27->SetBinContent(17,1.500962);
   norm_d__27->SetBinContent(18,0.4709056);
   norm_d__27->SetBinContent(19,1.032448);
   norm_d__27->SetBinContent(20,0.5068593);
   norm_d__27->SetBinContent(21,0.1230039);
   norm_d__27->SetBinContent(22,0.07447576);
   norm_d__27->SetBinContent(23,0.04030923);
   norm_d__27->SetBinContent(24,0.02948215);
   norm_d__27->SetBinContent(25,0.1034785);
   norm_d__27->SetBinContent(26,0.2273996);
   norm_d__27->SetBinError(2,0.6713721);
   norm_d__27->SetBinError(3,0.4516014);
   norm_d__27->SetBinError(4,0.4423499);
   norm_d__27->SetBinError(5,0.6599692);
   norm_d__27->SetBinError(6,0.8248793);
   norm_d__27->SetBinError(7,1.620046);
   norm_d__27->SetBinError(8,2.378651);
   norm_d__27->SetBinError(9,3.320374);
   norm_d__27->SetBinError(10,3.368356);
   norm_d__27->SetBinError(11,4.022937);
   norm_d__27->SetBinError(12,3.620246);
   norm_d__27->SetBinError(13,2.919835);
   norm_d__27->SetBinError(14,2.319172);
   norm_d__27->SetBinError(15,1.643061);
   norm_d__27->SetBinError(16,1.159679);
   norm_d__27->SetBinError(17,0.4737928);
   norm_d__27->SetBinError(18,0.1986724);
   norm_d__27->SetBinError(19,0.3442336);
   norm_d__27->SetBinError(20,0.2602602);
   norm_d__27->SetBinError(21,0.1230039);
   norm_d__27->SetBinError(22,0.04880216);
   norm_d__27->SetBinError(23,0.04030923);
   norm_d__27->SetBinError(24,0.02477717);
   norm_d__27->SetBinError(25,0.09346595);
   norm_d__27->SetBinError(26,0.1559079);
   norm_d__27->SetEntries(1494);
   norm_d__27->SetStats(0);
   norm_d__27->SetLineColor(7);
   norm_d__27->SetLineWidth(2);
   norm_d__27->GetXaxis()->SetLabelFont(42);
   norm_d__27->GetXaxis()->SetTitleOffset(1);
   norm_d__27->GetXaxis()->SetTitleFont(42);
   norm_d__27->GetYaxis()->SetLabelFont(42);
   norm_d__27->GetYaxis()->SetTitleFont(42);
   norm_d__27->GetZaxis()->SetLabelFont(42);
   norm_d__27->GetZaxis()->SetTitleOffset(1);
   norm_d__27->GetZaxis()->SetTitleFont(42);
   norm_d__27->Draw("same e1");
   
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
   entry=leg->AddEntry("frame_x_d2_3673ccf0","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.851279 #pm 0.011720","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.179845 #pm 0.009427","");
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
   
   TH1D *frame_3673ccf0_copy__28 = new TH1D("frame_3673ccf0_copy__28","p_T Balance",25,0,2);
   frame_3673ccf0_copy__28->SetBinContent(1,53.99698);
   frame_3673ccf0_copy__28->SetMinimum(-2.571285);
   frame_3673ccf0_copy__28->SetMaximum(53.99698);
   frame_3673ccf0_copy__28->SetEntries(1);
   frame_3673ccf0_copy__28->SetDirectory(0);
   frame_3673ccf0_copy__28->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3673ccf0_copy__28->SetLineColor(ci);
   frame_3673ccf0_copy__28->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3673ccf0_copy__28->GetXaxis()->SetLabelFont(42);
   frame_3673ccf0_copy__28->GetXaxis()->SetTitleOffset(1);
   frame_3673ccf0_copy__28->GetXaxis()->SetTitleFont(42);
   frame_3673ccf0_copy__28->GetYaxis()->SetTitle("1/Events");
   frame_3673ccf0_copy__28->GetYaxis()->SetLabelFont(42);
   frame_3673ccf0_copy__28->GetYaxis()->SetTitleFont(42);
   frame_3673ccf0_copy__28->GetZaxis()->SetLabelFont(42);
   frame_3673ccf0_copy__28->GetZaxis()->SetTitleOffset(1);
   frame_3673ccf0_copy__28->GetZaxis()->SetTitleFont(42);
   frame_3673ccf0_copy__28->Draw("sameaxis");
   
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
   
   TH1D *frame_36743500__29 = new TH1D("frame_36743500__29","p_T Balance",25,0,2);
   frame_36743500__29->SetBinContent(1,71.11079);
   frame_36743500__29->SetMaximum(71.11079);
   frame_36743500__29->SetEntries(1);
   frame_36743500__29->SetDirectory(0);
   frame_36743500__29->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_36743500__29->SetLineColor(ci);
   frame_36743500__29->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_36743500__29->GetXaxis()->SetLabelFont(42);
   frame_36743500__29->GetXaxis()->SetTitleOffset(1);
   frame_36743500__29->GetXaxis()->SetTitleFont(42);
   frame_36743500__29->GetYaxis()->SetTitle("1/Events");
   frame_36743500__29->GetYaxis()->SetLabelFont(42);
   frame_36743500__29->GetYaxis()->SetTitleFont(42);
   frame_36743500__29->GetZaxis()->SetLabelFont(42);
   frame_36743500__29->GetZaxis()->SetTitleOffset(1);
   frame_36743500__29->GetZaxis()->SetTitleFont(42);
   frame_36743500__29->Draw("FUNC");
   
   Double_t h_dh_data2_fx3008[25] = {
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
   Double_t h_dh_data2_fy3008[25] = {
   0,
   0,
   1,
   4,
   6,
   3,
   20,
   18,
   20,
   38,
   59,
   56,
   34,
   39,
   21,
   7,
   3,
   4,
   1,
   1,
   0,
   0,
   0,
   0,
   0};
   Double_t h_dh_data2_felx3008[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_data2_fely3008[25] = {
   0,
   0,
   0.8272462,
   1.914339,
   2.379931,
   1.632705,
   4.434448,
   4.202887,
   4.434448,
   6.137163,
   7.659312,
   7.4609,
   5.802128,
   6.218102,
   4.545807,
   2.58147,
   1.632705,
   1.914339,
   0.8272462,
   0.8272462,
   0,
   0,
   0,
   0,
   0};
   Double_t h_dh_data2_fehx3008[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_data2_fehy3008[25] = {
   1.147874,
   1.147874,
   2.299527,
   3.162753,
   3.583642,
   2.918186,
   5.546519,
   5.321007,
   5.546519,
   7.218484,
   8.724565,
   8.527879,
   6.888101,
   7.298372,
   5.655182,
   3.770281,
   2.918186,
   3.162753,
   2.299527,
   2.299527,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874};
   grae = new TGraphAsymmErrors(25,h_dh_data2_fx3008,h_dh_data2_fy3008,h_dh_data2_felx3008,h_dh_data2_fehx3008,h_dh_data2_fely3008,h_dh_data2_fehy3008);
   grae->SetName("h_dh_data2");
   grae->SetTitle("Histogram of dh_data2_plot__x_o2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_data23008 = new TH1F("Graph_h_dh_data23008","Histogram of dh_data2_plot__x_o2",100,0,2.2);
   Graph_h_dh_data23008->SetMinimum(0);
   Graph_h_dh_data23008->SetMaximum(74.49702);
   Graph_h_dh_data23008->SetDirectory(0);
   Graph_h_dh_data23008->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_data23008->SetLineColor(ci);
   Graph_h_dh_data23008->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_data23008->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_data23008->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_data23008->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_data23008->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_data23008->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_data23008->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_data23008->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_data23008);
   
   grae->Draw("p");
   
   Double_t observation_fx8[54] = {
   0.5032387,
   0.536108,
   0.5689773,
   0.6018466,
   0.6182812,
   0.6347159,
   0.6511506,
   0.6593679,
   0.6634765,
   0.6675852,
   0.6840199,
   0.7004545,
   0.7333238,
   0.7661931,
   0.7826278,
   0.7990625,
   0.8154971,
   0.8319318,
   0.8483664,
   0.8565838,
   0.8648011,
   0.8730184,
   0.8812357,
   0.8894531,
   0.8976704,
   0.9058877,
   0.914105,
   0.9223224,
   0.9305397,
   0.938757,
   0.9469744,
   0.9551917,
   0.963409,
   0.9798437,
   0.9962783,
   1.012713,
   1.029148,
   1.045582,
   1.062017,
   1.094886,
   1.127756,
   1.14419,
   1.160625,
   1.17706,
   1.193494,
   1.209929,
   1.226363,
   1.242798,
   1.259233,
   1.275667,
   1.283885,
   1.292102,
   1.324971,
   1.324971};
   Double_t observation_fy8[54] = {
   19.43101,
   19.64231,
   19.91566,
   20.30101,
   20.5728,
   20.95006,
   21.56296,
   22.10268,
   22.53268,
   23.18663,
   26.06136,
   29.04274,
   35.15296,
   41.11598,
   43.89921,
   46.47119,
   48.7744,
   50.75528,
   52.36627,
   53.0203,
   53.56771,
   54.00503,
   54.32949,
   54.53902,
   54.63228,
   54.60866,
   54.46833,
   54.21218,
   53.84184,
   53.35968,
   52.76876,
   52.07278,
   51.27609,
   49.40081,
   47.18829,
   44.69054,
   41.96411,
   39.06803,
   36.06169,
   29.94598,
   24.03009,
   21.2513,
   18.6336,
   16.19903,
   13.96247,
   11.9321,
   10.11003,
   8.493154,
   7.074027,
   5.866488,
   5.623707,
   5.498186,
   5.256928,
   5.256928};
   graph = new TGraph(54,observation_fx8,observation_fy8);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation8 = new TH1F("Graph_observation8","Projection of obsf DSCB fit",100,0.4210654,1.407145);
   Graph_observation8->SetMinimum(0.3193927);
   Graph_observation8->SetMaximum(59.56981);
   Graph_observation8->SetDirectory(0);
   Graph_observation8->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_observation8->SetLineColor(ci);
   Graph_observation8->GetXaxis()->SetLabelFont(42);
   Graph_observation8->GetXaxis()->SetTitleOffset(1);
   Graph_observation8->GetXaxis()->SetTitleFont(42);
   Graph_observation8->GetYaxis()->SetLabelFont(42);
   Graph_observation8->GetYaxis()->SetTitleFont(42);
   Graph_observation8->GetZaxis()->SetLabelFont(42);
   Graph_observation8->GetZaxis()->SetTitleOffset(1);
   Graph_observation8->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_observation8);
   
   graph->Draw("l");
   
   TH1D *frame_36743500__30 = new TH1D("frame_36743500__30","p_T Balance",25,0,2);
   frame_36743500__30->SetBinContent(1,71.11079);
   frame_36743500__30->SetMaximum(71.11079);
   frame_36743500__30->SetEntries(1);
   frame_36743500__30->SetDirectory(0);
   frame_36743500__30->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_36743500__30->SetLineColor(ci);
   frame_36743500__30->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_36743500__30->GetXaxis()->SetLabelFont(42);
   frame_36743500__30->GetXaxis()->SetTitleOffset(1);
   frame_36743500__30->GetXaxis()->SetTitleFont(42);
   frame_36743500__30->GetYaxis()->SetTitle("1/Events");
   frame_36743500__30->GetYaxis()->SetLabelFont(42);
   frame_36743500__30->GetYaxis()->SetTitleFont(42);
   frame_36743500__30->GetZaxis()->SetLabelFont(42);
   frame_36743500__30->GetZaxis()->SetTitleOffset(1);
   frame_36743500__30->GetZaxis()->SetTitleFont(42);
   frame_36743500__30->Draw("AXISSAME");
   
   TH1D *norm_o__31 = new TH1D("norm_o__31","",25,0,2);
   norm_o__31->SetBinContent(3,1);
   norm_o__31->SetBinContent(4,4);
   norm_o__31->SetBinContent(5,6);
   norm_o__31->SetBinContent(6,3);
   norm_o__31->SetBinContent(7,20);
   norm_o__31->SetBinContent(8,18);
   norm_o__31->SetBinContent(9,20);
   norm_o__31->SetBinContent(10,38);
   norm_o__31->SetBinContent(11,59);
   norm_o__31->SetBinContent(12,56);
   norm_o__31->SetBinContent(13,34);
   norm_o__31->SetBinContent(14,39);
   norm_o__31->SetBinContent(15,21);
   norm_o__31->SetBinContent(16,7);
   norm_o__31->SetBinContent(17,3);
   norm_o__31->SetBinContent(18,4);
   norm_o__31->SetBinContent(19,1);
   norm_o__31->SetBinContent(20,1);
   norm_o__31->SetMinimum(0);
   norm_o__31->SetMaximum(129.8);
   norm_o__31->SetEntries(335);
   norm_o__31->SetStats(0);
   norm_o__31->SetLineWidth(2);
   norm_o__31->SetMarkerStyle(8);
   norm_o__31->SetMarkerSize(0.4);
   norm_o__31->GetXaxis()->SetRange(1,25);
   norm_o__31->GetXaxis()->SetLabelFont(42);
   norm_o__31->GetXaxis()->SetLabelSize(0.04);
   norm_o__31->GetXaxis()->SetTitleOffset(1);
   norm_o__31->GetXaxis()->SetTitleFont(42);
   norm_o__31->GetYaxis()->SetTitle("Events");
   norm_o__31->GetYaxis()->SetLabelFont(42);
   norm_o__31->GetYaxis()->SetTitleOffset(1.4);
   norm_o__31->GetYaxis()->SetTitleFont(42);
   norm_o__31->GetZaxis()->SetLabelFont(42);
   norm_o__31->GetZaxis()->SetTitleOffset(1);
   norm_o__31->GetZaxis()->SetTitleFont(42);
   norm_o__31->Draw("same e1");
   
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
   entry=leg->AddEntry("frame_x_o2_36743500","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.914092 #pm 0.012208","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.166300 #pm 0.011430","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.994000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_36743500_copy__32 = new TH1D("frame_36743500_copy__32","p_T Balance",25,0,2);
   frame_36743500_copy__32->SetBinContent(1,71.11079);
   frame_36743500_copy__32->SetMaximum(71.11079);
   frame_36743500_copy__32->SetEntries(1);
   frame_36743500_copy__32->SetDirectory(0);
   frame_36743500_copy__32->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_36743500_copy__32->SetLineColor(ci);
   frame_36743500_copy__32->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_36743500_copy__32->GetXaxis()->SetLabelFont(42);
   frame_36743500_copy__32->GetXaxis()->SetTitleOffset(1);
   frame_36743500_copy__32->GetXaxis()->SetTitleFont(42);
   frame_36743500_copy__32->GetYaxis()->SetTitle("1/Events");
   frame_36743500_copy__32->GetYaxis()->SetLabelFont(42);
   frame_36743500_copy__32->GetYaxis()->SetTitleFont(42);
   frame_36743500_copy__32->GetZaxis()->SetLabelFont(42);
   frame_36743500_copy__32->GetZaxis()->SetTitleOffset(1);
   frame_36743500_copy__32->GetZaxis()->SetTitleFont(42);
   frame_36743500_copy__32->Draw("sameaxis");
   
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
