void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_2__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 16:35:06 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-9.504283,2.25,71.53999);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_35661930__17 = new TH1D("frame_35661930__17","p_T Balance",25,0,2);
   frame_35661930__17->SetBinContent(1,63.43556);
   frame_35661930__17->SetMinimum(-3.020741);
   frame_35661930__17->SetMaximum(63.43556);
   frame_35661930__17->SetEntries(1);
   frame_35661930__17->SetDirectory(0);
   frame_35661930__17->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_35661930__17->SetLineColor(ci);
   frame_35661930__17->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35661930__17->GetXaxis()->SetLabelFont(42);
   frame_35661930__17->GetXaxis()->SetTitleOffset(1);
   frame_35661930__17->GetXaxis()->SetTitleFont(42);
   frame_35661930__17->GetYaxis()->SetTitle("1/Events");
   frame_35661930__17->GetYaxis()->SetLabelFont(42);
   frame_35661930__17->GetYaxis()->SetTitleFont(42);
   frame_35661930__17->GetZaxis()->SetLabelFont(42);
   frame_35661930__17->GetZaxis()->SetTitleOffset(1);
   frame_35661930__17->GetZaxis()->SetTitleFont(42);
   frame_35661930__17->Draw("FUNC");
   
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
   0.4120044,
   0.9949209,
   5.617338,
   4.682508,
   7.439994,
   14.35528,
   20.50483,
   28.07603,
   44.54933,
   56.17514,
   48.39576,
   44.20448,
   26.08685,
   17.40631,
   8.510565,
   3.826096,
   1.997842,
   0.4275483,
   0.4354011,
   0.2124625,
   0.001069055,
   0,
   0.05887979,
   0.001912846};
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
   0.2310714,
   0.3889789,
   1.428684,
   1.248622,
   1.659706,
   2.257688,
   2.65115,
   2.834837,
   3.625085,
   4.239677,
   3.637492,
   3.706144,
   2.793366,
   2.060437,
   1.366174,
   0.939475,
   0.7694051,
   0.2366338,
   0.2223,
   0.1235313,
   0.001069055,
   0,
   0.05887979,
   0.001912846};
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
   0.2310714,
   0.3889789,
   1.428684,
   1.248622,
   1.659706,
   2.257688,
   2.65115,
   2.834837,
   3.625085,
   4.239677,
   3.637492,
   3.706144,
   2.793366,
   2.060437,
   1.366174,
   0.939475,
   0.7694051,
   0.2366338,
   0.2223,
   0.1235313,
   0.001069055,
   0,
   0.05887979,
   0.001912846};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3005,h_dh_central2_fy3005,h_dh_central2_felx3005,h_dh_central2_fehx3005,h_dh_central2_fely3005,h_dh_central2_fehy3005);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23005 = new TH1F("Graph_h_dh_central23005","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23005->SetMinimum(-6.041482);
   Graph_h_dh_central23005->SetMaximum(66.4563);
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
   
   Double_t Central_fx5[58] = {
   0.4097556,
   0.4474705,
   0.4851853,
   0.5040428,
   0.5229002,
   0.5417576,
   0.5606151,
   0.5794725,
   0.5983299,
   0.6171874,
   0.6360448,
   0.6549022,
   0.6737596,
   0.7114745,
   0.7303319,
   0.7491894,
   0.7680468,
   0.7869042,
   0.7963329,
   0.8057617,
   0.8151904,
   0.8246191,
   0.8340478,
   0.8434765,
   0.8529052,
   0.8623339,
   0.8717627,
   0.8811914,
   0.8906201,
   0.9000488,
   0.9094775,
   0.9189062,
   0.928335,
   0.9377637,
   0.9471924,
   0.9566211,
   0.9754785,
   0.994336,
   1.013193,
   1.032051,
   1.050908,
   1.088623,
   1.107481,
   1.126338,
   1.145195,
   1.164053,
   1.18291,
   1.201768,
   1.220625,
   1.239483,
   1.25834,
   1.277197,
   1.281912,
   1.286626,
   1.296055,
   1.314912,
   1.352627,
   1.352627};
   Double_t Central_fy5[58] = {
   8.214599,
   9.601703,
   11.3114,
   12.31654,
   13.44163,
   14.70487,
   16.12781,
   17.73615,
   19.56065,
   21.63833,
   24.01403,
   26.74236,
   29.86398,
   36.33411,
   39.47009,
   42.44258,
   45.17682,
   47.6003,
   48.67425,
   49.64595,
   50.50838,
   51.25522,
   51.88093,
   52.38084,
   52.75118,
   52.98915,
   53.09294,
   53.06176,
   52.89584,
   52.59645,
   52.16586,
   51.60732,
   50.92503,
   50.12407,
   49.21034,
   48.19051,
   45.8624,
   43.20482,
   40.28912,
   37.18977,
   33.98124,
   27.51764,
   24.38751,
   21.39458,
   18.57891,
   15.97044,
   13.58919,
   11.44591,
   9.543054,
   7.875978,
   6.434306,
   5.203302,
   4.957778,
   4.829545,
   4.687621,
   4.539741,
   4.39104,
   4.39104};
   TGraph *graph = new TGraph(58,Central_fx5,Central_fy5);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central5 = new TH1F("Graph_Central5","Projection of centralf DSCB fit",100,0.3154685,1.446914);
   Graph_Central5->SetMinimum(3.951936);
   Graph_Central5->SetMaximum(57.96313);
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
   
   TH1D *frame_35661930__18 = new TH1D("frame_35661930__18","p_T Balance",25,0,2);
   frame_35661930__18->SetBinContent(1,63.43556);
   frame_35661930__18->SetMinimum(-3.020741);
   frame_35661930__18->SetMaximum(63.43556);
   frame_35661930__18->SetEntries(1);
   frame_35661930__18->SetDirectory(0);
   frame_35661930__18->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35661930__18->SetLineColor(ci);
   frame_35661930__18->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35661930__18->GetXaxis()->SetLabelFont(42);
   frame_35661930__18->GetXaxis()->SetTitleOffset(1);
   frame_35661930__18->GetXaxis()->SetTitleFont(42);
   frame_35661930__18->GetYaxis()->SetTitle("1/Events");
   frame_35661930__18->GetYaxis()->SetLabelFont(42);
   frame_35661930__18->GetYaxis()->SetTitleFont(42);
   frame_35661930__18->GetZaxis()->SetLabelFont(42);
   frame_35661930__18->GetZaxis()->SetTitleOffset(1);
   frame_35661930__18->GetZaxis()->SetTitleFont(42);
   frame_35661930__18->Draw("AXISSAME");
   
   TH1D *norm_c__19 = new TH1D("norm_c__19","",25,0,2);
   norm_c__19->SetBinContent(2,0.4120044);
   norm_c__19->SetBinContent(3,0.9949209);
   norm_c__19->SetBinContent(4,5.617338);
   norm_c__19->SetBinContent(5,4.682508);
   norm_c__19->SetBinContent(6,7.439994);
   norm_c__19->SetBinContent(7,14.35527);
   norm_c__19->SetBinContent(8,20.50483);
   norm_c__19->SetBinContent(9,28.07603);
   norm_c__19->SetBinContent(10,44.54933);
   norm_c__19->SetBinContent(11,56.17514);
   norm_c__19->SetBinContent(12,48.39576);
   norm_c__19->SetBinContent(13,44.20448);
   norm_c__19->SetBinContent(14,26.08686);
   norm_c__19->SetBinContent(15,17.4063);
   norm_c__19->SetBinContent(16,8.510565);
   norm_c__19->SetBinContent(17,3.826096);
   norm_c__19->SetBinContent(18,1.997842);
   norm_c__19->SetBinContent(19,0.4275483);
   norm_c__19->SetBinContent(20,0.4354011);
   norm_c__19->SetBinContent(21,0.2124625);
   norm_c__19->SetBinContent(22,0.001069055);
   norm_c__19->SetBinContent(24,0.05887979);
   norm_c__19->SetBinContent(25,0.001912846);
   norm_c__19->SetBinContent(26,0.1456502);
   norm_c__19->SetBinError(2,0.2310714);
   norm_c__19->SetBinError(3,0.3889789);
   norm_c__19->SetBinError(4,1.428684);
   norm_c__19->SetBinError(5,1.248622);
   norm_c__19->SetBinError(6,1.659706);
   norm_c__19->SetBinError(7,2.257688);
   norm_c__19->SetBinError(8,2.65115);
   norm_c__19->SetBinError(9,2.834837);
   norm_c__19->SetBinError(10,3.625085);
   norm_c__19->SetBinError(11,4.239677);
   norm_c__19->SetBinError(12,3.637492);
   norm_c__19->SetBinError(13,3.706144);
   norm_c__19->SetBinError(14,2.793366);
   norm_c__19->SetBinError(15,2.060437);
   norm_c__19->SetBinError(16,1.366174);
   norm_c__19->SetBinError(17,0.939475);
   norm_c__19->SetBinError(18,0.7694051);
   norm_c__19->SetBinError(19,0.2366338);
   norm_c__19->SetBinError(20,0.2223);
   norm_c__19->SetBinError(21,0.1235313);
   norm_c__19->SetBinError(22,0.001069055);
   norm_c__19->SetBinError(24,0.05887979);
   norm_c__19->SetBinError(25,0.001912846);
   norm_c__19->SetBinError(26,0.09277241);
   norm_c__19->SetEntries(1609);
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
   entry=leg->AddEntry("frame_x_c2_35661930","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.874855 #pm 0.012363","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.190704 #pm 0.011289","");
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
   
   TH1D *frame_35661930_copy__20 = new TH1D("frame_35661930_copy__20","p_T Balance",25,0,2);
   frame_35661930_copy__20->SetBinContent(1,63.43556);
   frame_35661930_copy__20->SetMinimum(-3.020741);
   frame_35661930_copy__20->SetMaximum(63.43556);
   frame_35661930_copy__20->SetEntries(1);
   frame_35661930_copy__20->SetDirectory(0);
   frame_35661930_copy__20->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35661930_copy__20->SetLineColor(ci);
   frame_35661930_copy__20->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35661930_copy__20->GetXaxis()->SetLabelFont(42);
   frame_35661930_copy__20->GetXaxis()->SetTitleOffset(1);
   frame_35661930_copy__20->GetXaxis()->SetTitleFont(42);
   frame_35661930_copy__20->GetYaxis()->SetTitle("1/Events");
   frame_35661930_copy__20->GetYaxis()->SetLabelFont(42);
   frame_35661930_copy__20->GetYaxis()->SetTitleFont(42);
   frame_35661930_copy__20->GetZaxis()->SetLabelFont(42);
   frame_35661930_copy__20->GetZaxis()->SetTitleOffset(1);
   frame_35661930_copy__20->GetZaxis()->SetTitleFont(42);
   frame_35661930_copy__20->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-8.819467,2.25,66.38529);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_35677ae0__21 = new TH1D("frame_35677ae0__21","p_T Balance",25,0,2);
   frame_35677ae0__21->SetBinContent(1,58.86482);
   frame_35677ae0__21->SetMinimum(-2.803087);
   frame_35677ae0__21->SetMaximum(58.86482);
   frame_35677ae0__21->SetEntries(1);
   frame_35677ae0__21->SetDirectory(0);
   frame_35677ae0__21->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35677ae0__21->SetLineColor(ci);
   frame_35677ae0__21->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35677ae0__21->GetXaxis()->SetLabelFont(42);
   frame_35677ae0__21->GetXaxis()->SetTitleOffset(1);
   frame_35677ae0__21->GetXaxis()->SetTitleFont(42);
   frame_35677ae0__21->GetYaxis()->SetTitle("1/Events");
   frame_35677ae0__21->GetYaxis()->SetLabelFont(42);
   frame_35677ae0__21->GetYaxis()->SetTitleFont(42);
   frame_35677ae0__21->GetZaxis()->SetLabelFont(42);
   frame_35677ae0__21->GetZaxis()->SetTitleOffset(1);
   frame_35677ae0__21->GetZaxis()->SetTitleFont(42);
   frame_35677ae0__21->Draw("FUNC");
   
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
   0.4249927,
   1.043682,
   4.070527,
   4.518486,
   6.397967,
   11.02882,
   20.21531,
   26.68258,
   42.90013,
   51.04885,
   52.19499,
   48.89794,
   29.99814,
   18.42612,
   10.01265,
   3.222472,
   1.607849,
   0.4493559,
   0.2503242,
   0.4787828,
   0.05592047,
   0,
   0.04599212,
   0};
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
   0.2390896,
   0.3921056,
   1.172753,
   1.278442,
   1.511408,
   1.989543,
   2.637616,
   2.851893,
   3.540022,
   4.028784,
   3.866739,
   3.991977,
   2.955544,
   2.147914,
   1.512223,
   0.9002363,
   0.5347054,
   0.2409008,
   0.1138065,
   0.2553608,
   0.05486531,
   0,
   0.04599212,
   0};
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
   0.2390896,
   0.3921056,
   1.172753,
   1.278442,
   1.511408,
   1.989543,
   2.637616,
   2.851893,
   3.540022,
   4.028784,
   3.866739,
   3.991977,
   2.955544,
   2.147914,
   1.512223,
   0.9002363,
   0.5347054,
   0.2409008,
   0.1138065,
   0.2553608,
   0.05486531,
   0,
   0.04599212,
   0};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3006,h_dh_up2_fy3006,h_dh_up2_felx3006,h_dh_up2_fehx3006,h_dh_up2_fely3006,h_dh_up2_fehy3006);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23006 = new TH1F("Graph_h_dh_up23006","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23006->SetMinimum(-5.606173);
   Graph_h_dh_up23006->SetMaximum(61.6679);
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
   
   Double_t up_fx6[56] = {
   0.4344102,
   0.4712429,
   0.5080755,
   0.5264919,
   0.5449082,
   0.5541164,
   0.5587205,
   0.5633246,
   0.5817409,
   0.6001573,
   0.6185736,
   0.63699,
   0.6554063,
   0.692239,
   0.7290717,
   0.747488,
   0.7659044,
   0.7843207,
   0.8027371,
   0.8211534,
   0.8303616,
   0.8395698,
   0.848778,
   0.8579861,
   0.8671943,
   0.8764025,
   0.8856106,
   0.8948188,
   0.904027,
   0.9132352,
   0.9224433,
   0.9316515,
   0.9408597,
   0.9500679,
   0.9684842,
   0.9869006,
   1.005317,
   1.023733,
   1.04215,
   1.060566,
   1.097399,
   1.115815,
   1.134231,
   1.152648,
   1.171064,
   1.18948,
   1.207897,
   1.226313,
   1.244729,
   1.263146,
   1.281562,
   1.299978,
   1.318395,
   1.336811,
   1.355227,
   1.355227};
   Double_t up_fy6[56] = {
   10.97112,
   11.14673,
   11.4107,
   11.61476,
   11.94111,
   12.22044,
   12.435,
   12.77437,
   14.97288,
   17.39461,
   20.01943,
   22.82527,
   25.78146,
   31.97959,
   38.20744,
   41.17906,
   43.96757,
   46.50672,
   48.73337,
   50.58999,
   51.36371,
   52.02716,
   52.57577,
   53.00575,
   53.31412,
   53.49871,
   53.55823,
   53.49226,
   53.30127,
   52.98659,
   52.55043,
   51.99582,
   51.32659,
   50.54734,
   48.68055,
   46.44512,
   43.89874,
   41.1047,
   38.12925,
   35.03906,
   28.76887,
   25.70391,
   22.75113,
   19.94959,
   17.32976,
   14.91346,
   12.71428,
   10.73822,
   8.984632,
   7.447246,
   6.115311,
   4.974721,
   4.009095,
   3.200747,
   2.534565,
   2.534565};
   graph = new TGraph(56,up_fx6,up_fy6);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up6 = new TH1F("Graph_up6","Projection of upf DSCB fit",100,0.3423284,1.447309);
   Graph_up6->SetMinimum(2.281109);
   Graph_up6->SetMaximum(58.66059);
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
   
   TH1D *frame_35677ae0__22 = new TH1D("frame_35677ae0__22","p_T Balance",25,0,2);
   frame_35677ae0__22->SetBinContent(1,58.86482);
   frame_35677ae0__22->SetMinimum(-2.803087);
   frame_35677ae0__22->SetMaximum(58.86482);
   frame_35677ae0__22->SetEntries(1);
   frame_35677ae0__22->SetDirectory(0);
   frame_35677ae0__22->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35677ae0__22->SetLineColor(ci);
   frame_35677ae0__22->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35677ae0__22->GetXaxis()->SetLabelFont(42);
   frame_35677ae0__22->GetXaxis()->SetTitleOffset(1);
   frame_35677ae0__22->GetXaxis()->SetTitleFont(42);
   frame_35677ae0__22->GetYaxis()->SetTitle("1/Events");
   frame_35677ae0__22->GetYaxis()->SetLabelFont(42);
   frame_35677ae0__22->GetYaxis()->SetTitleFont(42);
   frame_35677ae0__22->GetZaxis()->SetLabelFont(42);
   frame_35677ae0__22->GetZaxis()->SetTitleOffset(1);
   frame_35677ae0__22->GetZaxis()->SetTitleFont(42);
   frame_35677ae0__22->Draw("AXISSAME");
   
   TH1D *norm_u__23 = new TH1D("norm_u__23","",25,0,2);
   norm_u__23->SetBinContent(2,0.4249927);
   norm_u__23->SetBinContent(3,1.043682);
   norm_u__23->SetBinContent(4,4.070527);
   norm_u__23->SetBinContent(5,4.518486);
   norm_u__23->SetBinContent(6,6.397967);
   norm_u__23->SetBinContent(7,11.02882);
   norm_u__23->SetBinContent(8,20.21531);
   norm_u__23->SetBinContent(9,26.68258);
   norm_u__23->SetBinContent(10,42.90013);
   norm_u__23->SetBinContent(11,51.04885);
   norm_u__23->SetBinContent(12,52.19499);
   norm_u__23->SetBinContent(13,48.89794);
   norm_u__23->SetBinContent(14,29.99814);
   norm_u__23->SetBinContent(15,18.42613);
   norm_u__23->SetBinContent(16,10.01265);
   norm_u__23->SetBinContent(17,3.222472);
   norm_u__23->SetBinContent(18,1.607849);
   norm_u__23->SetBinContent(19,0.4493559);
   norm_u__23->SetBinContent(20,0.2503242);
   norm_u__23->SetBinContent(21,0.4787828);
   norm_u__23->SetBinContent(22,0.05592047);
   norm_u__23->SetBinContent(24,0.04599212);
   norm_u__23->SetBinContent(26,0.1483424);
   norm_u__23->SetBinError(2,0.2390896);
   norm_u__23->SetBinError(3,0.3921056);
   norm_u__23->SetBinError(4,1.172753);
   norm_u__23->SetBinError(5,1.278442);
   norm_u__23->SetBinError(6,1.511408);
   norm_u__23->SetBinError(7,1.989543);
   norm_u__23->SetBinError(8,2.637616);
   norm_u__23->SetBinError(9,2.851893);
   norm_u__23->SetBinError(10,3.540022);
   norm_u__23->SetBinError(11,4.028784);
   norm_u__23->SetBinError(12,3.866739);
   norm_u__23->SetBinError(13,3.991977);
   norm_u__23->SetBinError(14,2.955544);
   norm_u__23->SetBinError(15,2.147914);
   norm_u__23->SetBinError(16,1.512223);
   norm_u__23->SetBinError(17,0.9002363);
   norm_u__23->SetBinError(18,0.5347054);
   norm_u__23->SetBinError(19,0.2409008);
   norm_u__23->SetBinError(20,0.1138065);
   norm_u__23->SetBinError(21,0.2553608);
   norm_u__23->SetBinError(22,0.05486531);
   norm_u__23->SetBinError(24,0.04599212);
   norm_u__23->SetBinError(26,0.09252812);
   norm_u__23->SetEntries(1587);
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
   entry=leg->AddEntry("frame_x_u2_35677ae0","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.885444 #pm 0.011425","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.190143 #pm 0.009683","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.977000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_35677ae0_copy__24 = new TH1D("frame_35677ae0_copy__24","p_T Balance",25,0,2);
   frame_35677ae0_copy__24->SetBinContent(1,58.86482);
   frame_35677ae0_copy__24->SetMinimum(-2.803087);
   frame_35677ae0_copy__24->SetMaximum(58.86482);
   frame_35677ae0_copy__24->SetEntries(1);
   frame_35677ae0_copy__24->SetDirectory(0);
   frame_35677ae0_copy__24->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35677ae0_copy__24->SetLineColor(ci);
   frame_35677ae0_copy__24->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35677ae0_copy__24->GetXaxis()->SetLabelFont(42);
   frame_35677ae0_copy__24->GetXaxis()->SetTitleOffset(1);
   frame_35677ae0_copy__24->GetXaxis()->SetTitleFont(42);
   frame_35677ae0_copy__24->GetYaxis()->SetTitle("1/Events");
   frame_35677ae0_copy__24->GetYaxis()->SetLabelFont(42);
   frame_35677ae0_copy__24->GetYaxis()->SetTitleFont(42);
   frame_35677ae0_copy__24->GetZaxis()->SetLabelFont(42);
   frame_35677ae0_copy__24->GetZaxis()->SetTitleOffset(1);
   frame_35677ae0_copy__24->GetZaxis()->SetTitleFont(42);
   frame_35677ae0_copy__24->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-9.748923,2.25,59.88624);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_35673630__25 = new TH1D("frame_35673630__25","p_T Balance",25,0,2);
   frame_35673630__25->SetBinContent(1,58.49354);
   frame_35673630__25->SetMinimum(-2.785407);
   frame_35673630__25->SetMaximum(58.49354);
   frame_35673630__25->SetEntries(1);
   frame_35673630__25->SetDirectory(0);
   frame_35673630__25->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35673630__25->SetLineColor(ci);
   frame_35673630__25->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35673630__25->GetXaxis()->SetLabelFont(42);
   frame_35673630__25->GetXaxis()->SetTitleOffset(1);
   frame_35673630__25->GetXaxis()->SetTitleFont(42);
   frame_35673630__25->GetYaxis()->SetTitle("1/Events");
   frame_35673630__25->GetYaxis()->SetLabelFont(42);
   frame_35673630__25->GetYaxis()->SetTitleFont(42);
   frame_35673630__25->GetZaxis()->SetLabelFont(42);
   frame_35673630__25->GetZaxis()->SetTitleOffset(1);
   frame_35673630__25->GetZaxis()->SetTitleFont(42);
   frame_35673630__25->Draw("FUNC");
   
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
   0.3468021,
   0.7648124,
   5.133192,
   4.310662,
   8.331337,
   13.97263,
   19.27673,
   32.52365,
   41.6388,
   51.74154,
   50.28832,
   39.14359,
   22.7241,
   17.69378,
   6.945229,
   3.97021,
   1.515192,
   0.6331858,
   0.1869424,
   0.1430819,
   0.001075204,
   0.05935261,
   0,
   0.001924301};
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
   0.2182933,
   0.3271992,
   1.367015,
   1.114375,
   1.755953,
   2.226632,
   2.50879,
   3.126588,
   3.460169,
   3.966592,
   3.78924,
   3.437139,
   2.483773,
   2.121089,
   1.19895,
   1.021596,
   0.6275981,
   0.3075641,
   0.09482435,
   0.1022386,
   0.001075204,
   0.05935261,
   0,
   0.001924301};
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
   0.2182933,
   0.3271992,
   1.367015,
   1.114375,
   1.755953,
   2.226632,
   2.50879,
   3.126588,
   3.460169,
   3.966592,
   3.78924,
   3.437139,
   2.483773,
   2.121089,
   1.19895,
   1.021596,
   0.6275981,
   0.3075641,
   0.09482435,
   0.1022386,
   0.001075204,
   0.05935261,
   0,
   0.001924301};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3007,h_dh_down2_fy3007,h_dh_down2_felx3007,h_dh_down2_fehx3007,h_dh_down2_fely3007,h_dh_down2_fehy3007);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23007 = new TH1F("Graph_h_dh_down23007","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23007->SetMinimum(-5.570813);
   Graph_h_dh_down23007->SetMaximum(61.27894);
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
   
   Double_t down_fx7[58] = {
   0.4070135,
   0.4441959,
   0.4813784,
   0.4999696,
   0.5185608,
   0.537152,
   0.5557432,
   0.5743344,
   0.5929256,
   0.6115168,
   0.630108,
   0.6486992,
   0.6672905,
   0.7044729,
   0.7230641,
   0.7416553,
   0.7602465,
   0.7788377,
   0.7881333,
   0.7974289,
   0.8067245,
   0.8160201,
   0.8253157,
   0.8346113,
   0.8439069,
   0.8532025,
   0.8624981,
   0.8717938,
   0.8810894,
   0.890385,
   0.8996806,
   0.9089762,
   0.9182718,
   0.9275674,
   0.936863,
   0.9461586,
   0.9647498,
   0.983341,
   1.001932,
   1.020523,
   1.039115,
   1.076297,
   1.094888,
   1.113479,
   1.132071,
   1.150662,
   1.169253,
   1.187844,
   1.206436,
   1.225027,
   1.243618,
   1.262209,
   1.266857,
   1.271505,
   1.2808,
   1.299392,
   1.336574,
   1.336574};
   Double_t down_fy7[58] = {
   8.135368,
   9.543697,
   11.27334,
   12.28648,
   13.41701,
   14.68173,
   16.10034,
   17.69599,
   19.49602,
   21.53286,
   23.84512,
   26.47898,
   29.41731,
   35.35002,
   38.20324,
   40.89675,
   43.36661,
   45.55124,
   46.51863,
   47.39397,
   48.17135,
   48.84544,
   49.41158,
   49.86583,
   50.20499,
   50.42666,
   50.52927,
   50.5121,
   50.37526,
   50.11973,
   49.74731,
   49.26065,
   48.66313,
   47.95894,
   47.15292,
   46.25058,
   44.18174,
   41.80677,
   39.18578,
   36.38215,
   33.46004,
   27.50659,
   24.5872,
   21.77005,
   19.09361,
   16.58802,
   14.2751,
   12.16864,
   10.27502,
   8.594128,
   7.120309,
   5.843513,
   5.559525,
   5.39299,
   5.2211,
   5.049167,
   4.880085,
   4.880085};
   graph = new TGraph(58,down_fx7,down_fy7);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down7 = new TH1F("Graph_down7","Projection of downf DSCB fit",100,0.3140575,1.42953);
   Graph_down7->SetMinimum(0.3151662);
   Graph_down7->SetMaximum(55.09419);
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
   
   TH1D *frame_35673630__26 = new TH1D("frame_35673630__26","p_T Balance",25,0,2);
   frame_35673630__26->SetBinContent(1,58.49354);
   frame_35673630__26->SetMinimum(-2.785407);
   frame_35673630__26->SetMaximum(58.49354);
   frame_35673630__26->SetEntries(1);
   frame_35673630__26->SetDirectory(0);
   frame_35673630__26->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35673630__26->SetLineColor(ci);
   frame_35673630__26->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35673630__26->GetXaxis()->SetLabelFont(42);
   frame_35673630__26->GetXaxis()->SetTitleOffset(1);
   frame_35673630__26->GetXaxis()->SetTitleFont(42);
   frame_35673630__26->GetYaxis()->SetTitle("1/Events");
   frame_35673630__26->GetYaxis()->SetLabelFont(42);
   frame_35673630__26->GetYaxis()->SetTitleFont(42);
   frame_35673630__26->GetZaxis()->SetLabelFont(42);
   frame_35673630__26->GetZaxis()->SetTitleOffset(1);
   frame_35673630__26->GetZaxis()->SetTitleFont(42);
   frame_35673630__26->Draw("AXISSAME");
   
   TH1D *norm_d__27 = new TH1D("norm_d__27","",25,0,2);
   norm_d__27->SetBinContent(2,0.3468021);
   norm_d__27->SetBinContent(3,0.7648124);
   norm_d__27->SetBinContent(4,5.133192);
   norm_d__27->SetBinContent(5,4.310662);
   norm_d__27->SetBinContent(6,8.331337);
   norm_d__27->SetBinContent(7,13.97263);
   norm_d__27->SetBinContent(8,19.27673);
   norm_d__27->SetBinContent(9,32.52365);
   norm_d__27->SetBinContent(10,41.6388);
   norm_d__27->SetBinContent(11,51.74154);
   norm_d__27->SetBinContent(12,50.28832);
   norm_d__27->SetBinContent(13,39.14358);
   norm_d__27->SetBinContent(14,22.7241);
   norm_d__27->SetBinContent(15,17.69378);
   norm_d__27->SetBinContent(16,6.945229);
   norm_d__27->SetBinContent(17,3.97021);
   norm_d__27->SetBinContent(18,1.515192);
   norm_d__27->SetBinContent(19,0.6331858);
   norm_d__27->SetBinContent(20,0.1869424);
   norm_d__27->SetBinContent(21,0.1430819);
   norm_d__27->SetBinContent(22,0.001075204);
   norm_d__27->SetBinContent(23,0.05935261);
   norm_d__27->SetBinContent(25,0.001924301);
   norm_d__27->SetBinContent(26,0.1976574);
   norm_d__27->SetBinError(2,0.2182933);
   norm_d__27->SetBinError(3,0.3271992);
   norm_d__27->SetBinError(4,1.367015);
   norm_d__27->SetBinError(5,1.114375);
   norm_d__27->SetBinError(6,1.755953);
   norm_d__27->SetBinError(7,2.226632);
   norm_d__27->SetBinError(8,2.50879);
   norm_d__27->SetBinError(9,3.126588);
   norm_d__27->SetBinError(10,3.460169);
   norm_d__27->SetBinError(11,3.966592);
   norm_d__27->SetBinError(12,3.78924);
   norm_d__27->SetBinError(13,3.437139);
   norm_d__27->SetBinError(14,2.483773);
   norm_d__27->SetBinError(15,2.121089);
   norm_d__27->SetBinError(16,1.19895);
   norm_d__27->SetBinError(17,1.021596);
   norm_d__27->SetBinError(18,0.6275981);
   norm_d__27->SetBinError(19,0.3075641);
   norm_d__27->SetBinError(20,0.09482435);
   norm_d__27->SetBinError(21,0.1022386);
   norm_d__27->SetBinError(22,0.001075204);
   norm_d__27->SetBinError(23,0.05935261);
   norm_d__27->SetBinError(25,0.001924301);
   norm_d__27->SetBinError(26,0.1093332);
   norm_d__27->SetEntries(1559);
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
   entry=leg->AddEntry("frame_x_d2_35673630","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.865814 #pm 0.013921","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.190832 #pm 0.012857","");
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
   
   TH1D *frame_35673630_copy__28 = new TH1D("frame_35673630_copy__28","p_T Balance",25,0,2);
   frame_35673630_copy__28->SetBinContent(1,58.49354);
   frame_35673630_copy__28->SetMinimum(-2.785407);
   frame_35673630_copy__28->SetMaximum(58.49354);
   frame_35673630_copy__28->SetEntries(1);
   frame_35673630_copy__28->SetDirectory(0);
   frame_35673630_copy__28->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_35673630_copy__28->SetLineColor(ci);
   frame_35673630_copy__28->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_35673630_copy__28->GetXaxis()->SetLabelFont(42);
   frame_35673630_copy__28->GetXaxis()->SetTitleOffset(1);
   frame_35673630_copy__28->GetXaxis()->SetTitleFont(42);
   frame_35673630_copy__28->GetYaxis()->SetTitle("1/Events");
   frame_35673630_copy__28->GetYaxis()->SetLabelFont(42);
   frame_35673630_copy__28->GetYaxis()->SetTitleFont(42);
   frame_35673630_copy__28->GetZaxis()->SetLabelFont(42);
   frame_35673630_copy__28->GetZaxis()->SetTitleOffset(1);
   frame_35673630_copy__28->GetZaxis()->SetTitleFont(42);
   frame_35673630_copy__28->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-9.221704,2.25,82.99533);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3568e540__29 = new TH1D("frame_3568e540__29","p_T Balance",25,0,2);
   frame_3568e540__29->SetBinContent(1,81.15099);
   frame_3568e540__29->SetMaximum(81.15099);
   frame_3568e540__29->SetEntries(1);
   frame_3568e540__29->SetDirectory(0);
   frame_3568e540__29->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3568e540__29->SetLineColor(ci);
   frame_3568e540__29->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3568e540__29->GetXaxis()->SetLabelFont(42);
   frame_3568e540__29->GetXaxis()->SetTitleOffset(1);
   frame_3568e540__29->GetXaxis()->SetTitleFont(42);
   frame_3568e540__29->GetYaxis()->SetTitle("1/Events");
   frame_3568e540__29->GetYaxis()->SetLabelFont(42);
   frame_3568e540__29->GetYaxis()->SetTitleFont(42);
   frame_3568e540__29->GetZaxis()->SetLabelFont(42);
   frame_3568e540__29->GetZaxis()->SetTitleOffset(1);
   frame_3568e540__29->GetZaxis()->SetTitleFont(42);
   frame_3568e540__29->Draw("FUNC");
   
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
   1,
   1,
   4,
   5,
   8,
   15,
   19,
   37,
   54,
   68,
   64,
   34,
   37,
   21,
   12,
   8,
   1,
   0,
   0,
   1,
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
   0.8272462,
   0.8272462,
   1.914339,
   2.159691,
   2.768386,
   3.82938,
   4.320219,
   6.055143,
   7.32564,
   8.225883,
   7.979042,
   5.802128,
   6.055143,
   4.545807,
   3.415266,
   2.768386,
   0.8272462,
   0,
   0,
   0.8272462,
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
   2.299527,
   2.299527,
   3.162753,
   3.382473,
   3.945142,
   4.958738,
   5.435196,
   7.137555,
   8.39385,
   9.28666,
   9.041691,
   6.888101,
   7.137555,
   5.655182,
   4.559819,
   3.945142,
   2.299527,
   1.147874,
   1.147874,
   2.299527,
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
   Graph_h_dh_data23008->SetMaximum(85.01533);
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
   
   Double_t observation_fx8[63] = {
   0.3553424,
   0.3962163,
   0.4370902,
   0.4779641,
   0.498401,
   0.5188379,
   0.5392749,
   0.5597118,
   0.5801487,
   0.5903672,
   0.6005857,
   0.6108041,
   0.6210226,
   0.6312411,
   0.6414596,
   0.651678,
   0.6618965,
   0.6823334,
   0.7232073,
   0.7436442,
   0.7538627,
   0.7640812,
   0.7742997,
   0.7845181,
   0.7947366,
   0.8049551,
   0.8151735,
   0.825392,
   0.8356105,
   0.8458289,
   0.8560474,
   0.8662659,
   0.8764843,
   0.8867028,
   0.8969213,
   0.9071398,
   0.9173582,
   0.9275767,
   0.9377952,
   0.9480136,
   0.9582321,
   0.9684506,
   0.9888875,
   1.009324,
   1.019543,
   1.029761,
   1.03998,
   1.050198,
   1.060417,
   1.070635,
   1.091072,
   1.111509,
   1.131946,
   1.152383,
   1.17282,
   1.193257,
   1.213694,
   1.234131,
   1.254568,
   1.295442,
   1.336315,
   1.377189,
   1.377189};
   Double_t observation_fy8[63] = {
   7.732148,
   8.659299,
   9.818323,
   11.30533,
   12.21718,
   13.27681,
   14.52218,
   16.00518,
   17.79871,
   18.84315,
   20.00828,
   21.31566,
   22.79229,
   24.47231,
   26.39957,
   28.63126,
   31.09215,
   36.20856,
   46.69307,
   51.70507,
   54.06777,
   56.30156,
   58.38202,
   60.28572,
   61.9907,
   63.47683,
   64.72627,
   65.7238,
   66.4571,
   66.91705,
   67.09789,
   66.99735,
   66.61669,
   65.96068,
   65.03751,
   63.8586,
   62.43836,
   60.79394,
   58.94484,
   56.91254,
   54.72009,
   52.39167,
   47.42674,
   42.21932,
   39.7125,
   37.38901,
   35.23298,
   33.23014,
   31.36762,
   29.63378,
   26.51105,
   23.78902,
   21.40756,
   19.31678,
   17.47512,
   15.84781,
   14.40558,
   13.12375,
   11.98138,
   10.04632,
   8.486617,
   7.218186,
   7.218186};
   graph = new TGraph(63,observation_fx8,observation_fy8);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation8 = new TH1F("Graph_observation8","Projection of obsf DSCB fit",100,0.2531577,1.479374);
   Graph_observation8->SetMinimum(1.230216);
   Graph_observation8->SetMaximum(73.08586);
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
   
   TH1D *frame_3568e540__30 = new TH1D("frame_3568e540__30","p_T Balance",25,0,2);
   frame_3568e540__30->SetBinContent(1,81.15099);
   frame_3568e540__30->SetMaximum(81.15099);
   frame_3568e540__30->SetEntries(1);
   frame_3568e540__30->SetDirectory(0);
   frame_3568e540__30->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3568e540__30->SetLineColor(ci);
   frame_3568e540__30->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3568e540__30->GetXaxis()->SetLabelFont(42);
   frame_3568e540__30->GetXaxis()->SetTitleOffset(1);
   frame_3568e540__30->GetXaxis()->SetTitleFont(42);
   frame_3568e540__30->GetYaxis()->SetTitle("1/Events");
   frame_3568e540__30->GetYaxis()->SetLabelFont(42);
   frame_3568e540__30->GetYaxis()->SetTitleFont(42);
   frame_3568e540__30->GetZaxis()->SetLabelFont(42);
   frame_3568e540__30->GetZaxis()->SetTitleOffset(1);
   frame_3568e540__30->GetZaxis()->SetTitleFont(42);
   frame_3568e540__30->Draw("AXISSAME");
   
   TH1D *norm_o__31 = new TH1D("norm_o__31","",25,0,2);
   norm_o__31->SetBinContent(2,1);
   norm_o__31->SetBinContent(3,1);
   norm_o__31->SetBinContent(4,4);
   norm_o__31->SetBinContent(5,5);
   norm_o__31->SetBinContent(6,8);
   norm_o__31->SetBinContent(7,15);
   norm_o__31->SetBinContent(8,19);
   norm_o__31->SetBinContent(9,37);
   norm_o__31->SetBinContent(10,54);
   norm_o__31->SetBinContent(11,68);
   norm_o__31->SetBinContent(12,64);
   norm_o__31->SetBinContent(13,34);
   norm_o__31->SetBinContent(14,37);
   norm_o__31->SetBinContent(15,21);
   norm_o__31->SetBinContent(16,12);
   norm_o__31->SetBinContent(17,8);
   norm_o__31->SetBinContent(18,1);
   norm_o__31->SetBinContent(21,1);
   norm_o__31->SetMinimum(0);
   norm_o__31->SetMaximum(149.6);
   norm_o__31->SetEntries(390);
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
   entry=leg->AddEntry("frame_x_o2_3568e540","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.867829 #pm 0.011350","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.196387 #pm 0.010347","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.996000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3568e540_copy__32 = new TH1D("frame_3568e540_copy__32","p_T Balance",25,0,2);
   frame_3568e540_copy__32->SetBinContent(1,81.15099);
   frame_3568e540_copy__32->SetMaximum(81.15099);
   frame_3568e540_copy__32->SetEntries(1);
   frame_3568e540_copy__32->SetDirectory(0);
   frame_3568e540_copy__32->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3568e540_copy__32->SetLineColor(ci);
   frame_3568e540_copy__32->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3568e540_copy__32->GetXaxis()->SetLabelFont(42);
   frame_3568e540_copy__32->GetXaxis()->SetTitleOffset(1);
   frame_3568e540_copy__32->GetXaxis()->SetTitleFont(42);
   frame_3568e540_copy__32->GetYaxis()->SetTitle("1/Events");
   frame_3568e540_copy__32->GetYaxis()->SetLabelFont(42);
   frame_3568e540_copy__32->GetYaxis()->SetTitleFont(42);
   frame_3568e540_copy__32->GetZaxis()->SetLabelFont(42);
   frame_3568e540_copy__32->GetZaxis()->SetTitleOffset(1);
   frame_3568e540_copy__32->GetZaxis()->SetTitleFont(42);
   frame_3568e540_copy__32->Draw("sameaxis");
   
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
