void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_2__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 19:35:19 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-17.6287,2.25,202.73);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_367a5770__17 = new TH1D("frame_367a5770__17","p_T Balance",25,0,2);
   frame_367a5770__17->SetBinContent(1,180.6942);
   frame_367a5770__17->SetMaximum(180.6942);
   frame_367a5770__17->SetEntries(1);
   frame_367a5770__17->SetDirectory(0);
   frame_367a5770__17->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_367a5770__17->SetLineColor(ci);
   frame_367a5770__17->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367a5770__17->GetXaxis()->SetLabelFont(42);
   frame_367a5770__17->GetXaxis()->SetTitleOffset(1);
   frame_367a5770__17->GetXaxis()->SetTitleFont(42);
   frame_367a5770__17->GetYaxis()->SetTitle("1/Events");
   frame_367a5770__17->GetYaxis()->SetLabelFont(42);
   frame_367a5770__17->GetYaxis()->SetTitleFont(42);
   frame_367a5770__17->GetZaxis()->SetLabelFont(42);
   frame_367a5770__17->GetZaxis()->SetTitleOffset(1);
   frame_367a5770__17->GetZaxis()->SetTitleFont(42);
   frame_367a5770__17->Draw("FUNC");
   
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
   0.5734698,
   4.832619,
   7.0463,
   8.757084,
   12.8674,
   31.307,
   49.89226,
   88.13804,
   121.4831,
   156.7434,
   165.0544,
   133.7854,
   95.7618,
   47.49821,
   21.26412,
   11.16074,
   4.228181,
   2.79993,
   0.8451191,
   0.479495,
   0.3734296,
   0.1685788,
   0.1168146,
   0};
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
   0.2774154,
   1.140453,
   1.418395,
   1.70611,
   1.958434,
   3.111817,
   4.024203,
   5.367466,
   6.096285,
   6.952489,
   7.035291,
   6.26619,
   5.154887,
   3.474177,
   2.207529,
   1.590716,
   0.8797809,
   0.7707136,
   0.3686345,
   0.2656936,
   0.2119626,
   0.1449669,
   0.06658183,
   0};
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
   0.2774154,
   1.140453,
   1.418395,
   1.70611,
   1.958434,
   3.111817,
   4.024203,
   5.367466,
   6.096285,
   6.952489,
   7.035291,
   6.26619,
   5.154887,
   3.474177,
   2.207529,
   1.590716,
   0.8797809,
   0.7707136,
   0.3686345,
   0.2656936,
   0.2119626,
   0.1449669,
   0.06658183,
   0};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3005,h_dh_central2_fy3005,h_dh_central2_felx3005,h_dh_central2_fehx3005,h_dh_central2_fely3005,h_dh_central2_fehy3005);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23005 = new TH1F("Graph_h_dh_central23005","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23005->SetMinimum(0);
   Graph_h_dh_central23005->SetMaximum(189.2986);
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
   
   Double_t Central_fx5[57] = {
   0.4324844,
   0.4690724,
   0.5056604,
   0.5239544,
   0.5422484,
   0.5605425,
   0.5788365,
   0.5971305,
   0.6154245,
   0.6337185,
   0.6428655,
   0.6520125,
   0.6703065,
   0.6886005,
   0.7251886,
   0.7434826,
   0.7617766,
   0.7800706,
   0.7983646,
   0.8166586,
   0.8258057,
   0.8349527,
   0.8440997,
   0.8532467,
   0.8623937,
   0.8715407,
   0.8806877,
   0.8898347,
   0.8989817,
   0.9081287,
   0.9172757,
   0.9264227,
   0.9355697,
   0.9447167,
   0.9538638,
   0.9630108,
   0.9813048,
   0.9995988,
   1.017893,
   1.036187,
   1.054481,
   1.091069,
   1.109363,
   1.127657,
   1.145951,
   1.164245,
   1.182539,
   1.200833,
   1.219127,
   1.237421,
   1.255715,
   1.274009,
   1.292303,
   1.310597,
   1.328891,
   1.347185,
   1.347185};
   Double_t Central_fy5[57] = {
   21.67364,
   25.24803,
   29.78732,
   32.53123,
   35.67321,
   39.29419,
   43.49685,
   48.41289,
   54.21358,
   61.12484,
   65.08779,
   69.44967,
   78.88664,
   88.68965,
   108.6936,
   118.4855,
   127.8372,
   136.5149,
   144.2891,
   150.9446,
   153.7919,
   156.2903,
   158.4213,
   160.1686,
   161.5192,
   162.4626,
   162.9917,
   163.1023,
   162.7936,
   162.068,
   160.9311,
   159.3915,
   157.461,
   155.1543,
   152.4885,
   149.4834,
   142.5452,
   134.5375,
   125.6795,
   116.2027,
   106.3405,
   86.3486,
   76.6178,
   67.28754,
   58.48848,
   50.31953,
   42.8483,
   36.1128,
   30.12447,
   24.87186,
   20.32487,
   16.4391,
   13.16009,
   10.42726,
   8.177346,
   6.347243,
   6.347243};
   TGraph *graph = new TGraph(57,Central_fx5,Central_fy5);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central5 = new TH1F("Graph_Central5","Projection of centralf DSCB fit",100,0.3410143,1.438655);
   Graph_Central5->SetMinimum(5.712519);
   Graph_Central5->SetMaximum(178.7778);
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
   
   TH1D *frame_367a5770__18 = new TH1D("frame_367a5770__18","p_T Balance",25,0,2);
   frame_367a5770__18->SetBinContent(1,180.6942);
   frame_367a5770__18->SetMaximum(180.6942);
   frame_367a5770__18->SetEntries(1);
   frame_367a5770__18->SetDirectory(0);
   frame_367a5770__18->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367a5770__18->SetLineColor(ci);
   frame_367a5770__18->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367a5770__18->GetXaxis()->SetLabelFont(42);
   frame_367a5770__18->GetXaxis()->SetTitleOffset(1);
   frame_367a5770__18->GetXaxis()->SetTitleFont(42);
   frame_367a5770__18->GetYaxis()->SetTitle("1/Events");
   frame_367a5770__18->GetYaxis()->SetLabelFont(42);
   frame_367a5770__18->GetYaxis()->SetTitleFont(42);
   frame_367a5770__18->GetZaxis()->SetLabelFont(42);
   frame_367a5770__18->GetZaxis()->SetTitleOffset(1);
   frame_367a5770__18->GetZaxis()->SetTitleFont(42);
   frame_367a5770__18->Draw("AXISSAME");
   
   TH1D *norm_c__19 = new TH1D("norm_c__19","",25,0,2);
   norm_c__19->SetBinContent(2,0.5734698);
   norm_c__19->SetBinContent(3,4.832619);
   norm_c__19->SetBinContent(4,7.046301);
   norm_c__19->SetBinContent(5,8.757084);
   norm_c__19->SetBinContent(6,12.8674);
   norm_c__19->SetBinContent(7,31.307);
   norm_c__19->SetBinContent(8,49.89226);
   norm_c__19->SetBinContent(9,88.13804);
   norm_c__19->SetBinContent(10,121.4831);
   norm_c__19->SetBinContent(11,156.7434);
   norm_c__19->SetBinContent(12,165.0544);
   norm_c__19->SetBinContent(13,133.7853);
   norm_c__19->SetBinContent(14,95.7618);
   norm_c__19->SetBinContent(15,47.49821);
   norm_c__19->SetBinContent(16,21.26412);
   norm_c__19->SetBinContent(17,11.16074);
   norm_c__19->SetBinContent(18,4.228181);
   norm_c__19->SetBinContent(19,2.79993);
   norm_c__19->SetBinContent(20,0.845119);
   norm_c__19->SetBinContent(21,0.479495);
   norm_c__19->SetBinContent(22,0.3734296);
   norm_c__19->SetBinContent(23,0.1685788);
   norm_c__19->SetBinContent(24,0.1168146);
   norm_c__19->SetBinContent(26,0.5980407);
   norm_c__19->SetBinError(2,0.2774154);
   norm_c__19->SetBinError(3,1.140453);
   norm_c__19->SetBinError(4,1.418395);
   norm_c__19->SetBinError(5,1.70611);
   norm_c__19->SetBinError(6,1.958434);
   norm_c__19->SetBinError(7,3.111817);
   norm_c__19->SetBinError(8,4.024203);
   norm_c__19->SetBinError(9,5.367466);
   norm_c__19->SetBinError(10,6.096285);
   norm_c__19->SetBinError(11,6.952489);
   norm_c__19->SetBinError(12,7.035291);
   norm_c__19->SetBinError(13,6.26619);
   norm_c__19->SetBinError(14,5.154887);
   norm_c__19->SetBinError(15,3.474177);
   norm_c__19->SetBinError(16,2.207529);
   norm_c__19->SetBinError(17,1.590716);
   norm_c__19->SetBinError(18,0.8797809);
   norm_c__19->SetBinError(19,0.7707136);
   norm_c__19->SetBinError(20,0.3686345);
   norm_c__19->SetBinError(21,0.2656936);
   norm_c__19->SetBinError(22,0.2119626);
   norm_c__19->SetBinError(23,0.1449669);
   norm_c__19->SetBinError(24,0.06658183);
   norm_c__19->SetBinError(26,0.1740225);
   norm_c__19->SetEntries(5074);
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
   entry=leg->AddEntry("frame_x_c2_367a5770","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.885728 #pm 0.006349","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.181776 #pm 0.005582","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.894000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_367a5770_copy__20 = new TH1D("frame_367a5770_copy__20","p_T Balance",25,0,2);
   frame_367a5770_copy__20->SetBinContent(1,180.6942);
   frame_367a5770_copy__20->SetMaximum(180.6942);
   frame_367a5770_copy__20->SetEntries(1);
   frame_367a5770_copy__20->SetDirectory(0);
   frame_367a5770_copy__20->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367a5770_copy__20->SetLineColor(ci);
   frame_367a5770_copy__20->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367a5770_copy__20->GetXaxis()->SetLabelFont(42);
   frame_367a5770_copy__20->GetXaxis()->SetTitleOffset(1);
   frame_367a5770_copy__20->GetXaxis()->SetTitleFont(42);
   frame_367a5770_copy__20->GetYaxis()->SetTitle("1/Events");
   frame_367a5770_copy__20->GetYaxis()->SetLabelFont(42);
   frame_367a5770_copy__20->GetYaxis()->SetTitleFont(42);
   frame_367a5770_copy__20->GetZaxis()->SetLabelFont(42);
   frame_367a5770_copy__20->GetZaxis()->SetTitleOffset(1);
   frame_367a5770_copy__20->GetZaxis()->SetTitleFont(42);
   frame_367a5770_copy__20->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-18.00129,2.25,207.0148);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_367c22e0__21 = new TH1D("frame_367c22e0__21","p_T Balance",25,0,2);
   frame_367c22e0__21->SetBinContent(1,184.5132);
   frame_367c22e0__21->SetMaximum(184.5132);
   frame_367c22e0__21->SetEntries(1);
   frame_367c22e0__21->SetDirectory(0);
   frame_367c22e0__21->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367c22e0__21->SetLineColor(ci);
   frame_367c22e0__21->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367c22e0__21->GetXaxis()->SetLabelFont(42);
   frame_367c22e0__21->GetXaxis()->SetTitleOffset(1);
   frame_367c22e0__21->GetXaxis()->SetTitleFont(42);
   frame_367c22e0__21->GetYaxis()->SetTitle("1/Events");
   frame_367c22e0__21->GetYaxis()->SetLabelFont(42);
   frame_367c22e0__21->GetYaxis()->SetTitleFont(42);
   frame_367c22e0__21->GetZaxis()->SetLabelFont(42);
   frame_367c22e0__21->GetZaxis()->SetTitleOffset(1);
   frame_367c22e0__21->GetZaxis()->SetTitleFont(42);
   frame_367c22e0__21->Draw("FUNC");
   
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
   0.519075,
   6.25619,
   7.984661,
   6.040277,
   11.90575,
   27.32115,
   48.16496,
   79.63023,
   117.1057,
   163.2093,
   168.6161,
   140.5331,
   103.2686,
   53.52285,
   24.85254,
   13.3842,
   3.124304,
   2.761176,
   1.560083,
   0.5080826,
   0.3190602,
   0.07020345,
   0.1437496,
   0.05599863};
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
   0.2593842,
   1.508038,
   1.48557,
   1.3183,
   1.832087,
   2.942032,
   4.006057,
   5.157779,
   5.968518,
   7.156097,
   7.110822,
   6.472067,
   5.368912,
   3.71919,
   2.443486,
   1.732259,
   0.6803483,
   0.8203341,
   0.622843,
   0.265661,
   0.204133,
   0.05011546,
   0.0764667,
   0.04560497};
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
   0.2593842,
   1.508038,
   1.48557,
   1.3183,
   1.832087,
   2.942032,
   4.006057,
   5.157779,
   5.968518,
   7.156097,
   7.110822,
   6.472067,
   5.368912,
   3.71919,
   2.443486,
   1.732259,
   0.6803483,
   0.8203341,
   0.622843,
   0.265661,
   0.204133,
   0.05011546,
   0.0764667,
   0.04560497};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3006,h_dh_up2_fy3006,h_dh_up2_felx3006,h_dh_up2_fehx3006,h_dh_up2_fely3006,h_dh_up2_fehy3006);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23006 = new TH1F("Graph_h_dh_up23006","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23006->SetMinimum(0);
   Graph_h_dh_up23006->SetMaximum(193.2996);
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
   
   Double_t up_fx6[55] = {
   0.462762,
   0.4803158,
   0.4978697,
   0.5154235,
   0.5329773,
   0.5505311,
   0.5680849,
   0.5856387,
   0.6031925,
   0.6207464,
   0.6383002,
   0.655854,
   0.6734078,
   0.7085154,
   0.7436231,
   0.7611769,
   0.7787307,
   0.7962845,
   0.8138383,
   0.8313921,
   0.840169,
   0.8489459,
   0.8577229,
   0.8664998,
   0.8752767,
   0.8840536,
   0.8928305,
   0.9016074,
   0.9103843,
   0.9191612,
   0.9279381,
   0.936715,
   0.9454919,
   0.9542688,
   0.9718227,
   0.9893765,
   1.00693,
   1.024484,
   1.042038,
   1.059592,
   1.094699,
   1.129807,
   1.147361,
   1.164915,
   1.182468,
   1.200022,
   1.217576,
   1.23513,
   1.252684,
   1.270238,
   1.287791,
   1.305345,
   1.322899,
   1.340453,
   1.340453};
   Double_t up_fy6[55] = {
   11.1675,
   13.83313,
   16.9861,
   20.67302,
   24.93741,
   29.81506,
   35.3311,
   41.4969,
   48.30713,
   55.73704,
   63.74022,
   72.24709,
   81.16413,
   99.73854,
   118.2797,
   127.0981,
   135.3647,
   142.8922,
   149.5027,
   155.0338,
   157.3499,
   159.3459,
   161.0087,
   162.3276,
   163.2937,
   163.9007,
   164.1446,
   164.0236,
   163.5388,
   162.6931,
   161.4923,
   159.9443,
   158.0593,
   155.8496,
   150.5149,
   144.0756,
   136.6905,
   128.5356,
   119.7969,
   110.6636,
   91.94632,
   73.72455,
   65.14132,
   57.0477,
   49.51727,
   42.60027,
   36.32496,
   30.69975,
   25.7159,
   21.35038,
   17.56898,
   14.32929,
   11.5835,
   9.280938,
   9.280938};
   graph = new TGraph(55,up_fx6,up_fy6);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up6 = new TH1F("Graph_up6","Projection of upf DSCB fit",100,0.3749929,1.428222);
   Graph_up6->SetMinimum(8.352844);
   Graph_up6->SetMaximum(179.6309);
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
   
   TH1D *frame_367c22e0__22 = new TH1D("frame_367c22e0__22","p_T Balance",25,0,2);
   frame_367c22e0__22->SetBinContent(1,184.5132);
   frame_367c22e0__22->SetMaximum(184.5132);
   frame_367c22e0__22->SetEntries(1);
   frame_367c22e0__22->SetDirectory(0);
   frame_367c22e0__22->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367c22e0__22->SetLineColor(ci);
   frame_367c22e0__22->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367c22e0__22->GetXaxis()->SetLabelFont(42);
   frame_367c22e0__22->GetXaxis()->SetTitleOffset(1);
   frame_367c22e0__22->GetXaxis()->SetTitleFont(42);
   frame_367c22e0__22->GetYaxis()->SetTitle("1/Events");
   frame_367c22e0__22->GetYaxis()->SetLabelFont(42);
   frame_367c22e0__22->GetYaxis()->SetTitleFont(42);
   frame_367c22e0__22->GetZaxis()->SetLabelFont(42);
   frame_367c22e0__22->GetZaxis()->SetTitleOffset(1);
   frame_367c22e0__22->GetZaxis()->SetTitleFont(42);
   frame_367c22e0__22->Draw("AXISSAME");
   
   TH1D *norm_u__23 = new TH1D("norm_u__23","",25,0,2);
   norm_u__23->SetBinContent(2,0.519075);
   norm_u__23->SetBinContent(3,6.25619);
   norm_u__23->SetBinContent(4,7.98466);
   norm_u__23->SetBinContent(5,6.040276);
   norm_u__23->SetBinContent(6,11.90575);
   norm_u__23->SetBinContent(7,27.32115);
   norm_u__23->SetBinContent(8,48.16496);
   norm_u__23->SetBinContent(9,79.63023);
   norm_u__23->SetBinContent(10,117.1057);
   norm_u__23->SetBinContent(11,163.2093);
   norm_u__23->SetBinContent(12,168.6161);
   norm_u__23->SetBinContent(13,140.5331);
   norm_u__23->SetBinContent(14,103.2686);
   norm_u__23->SetBinContent(15,53.52285);
   norm_u__23->SetBinContent(16,24.85254);
   norm_u__23->SetBinContent(17,13.3842);
   norm_u__23->SetBinContent(18,3.124304);
   norm_u__23->SetBinContent(19,2.761176);
   norm_u__23->SetBinContent(20,1.560083);
   norm_u__23->SetBinContent(21,0.5080825);
   norm_u__23->SetBinContent(22,0.3190602);
   norm_u__23->SetBinContent(23,0.07020345);
   norm_u__23->SetBinContent(24,0.1437496);
   norm_u__23->SetBinContent(25,0.05599863);
   norm_u__23->SetBinContent(26,0.6907804);
   norm_u__23->SetBinError(2,0.2593842);
   norm_u__23->SetBinError(3,1.508038);
   norm_u__23->SetBinError(4,1.48557);
   norm_u__23->SetBinError(5,1.3183);
   norm_u__23->SetBinError(6,1.832087);
   norm_u__23->SetBinError(7,2.942032);
   norm_u__23->SetBinError(8,4.006057);
   norm_u__23->SetBinError(9,5.157779);
   norm_u__23->SetBinError(10,5.968518);
   norm_u__23->SetBinError(11,7.156097);
   norm_u__23->SetBinError(12,7.110822);
   norm_u__23->SetBinError(13,6.472067);
   norm_u__23->SetBinError(14,5.368912);
   norm_u__23->SetBinError(15,3.71919);
   norm_u__23->SetBinError(16,2.443486);
   norm_u__23->SetBinError(17,1.732259);
   norm_u__23->SetBinError(18,0.6803483);
   norm_u__23->SetBinError(19,0.8203341);
   norm_u__23->SetBinError(20,0.622843);
   norm_u__23->SetBinError(21,0.265661);
   norm_u__23->SetBinError(22,0.204133);
   norm_u__23->SetBinError(23,0.05011546);
   norm_u__23->SetBinError(24,0.0764667);
   norm_u__23->SetBinError(25,0.04560497);
   norm_u__23->SetBinError(26,0.2050711);
   norm_u__23->SetEntries(5075);
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
   entry=leg->AddEntry("frame_x_u2_367c22e0","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.894303 #pm 0.006469","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.186105 #pm 0.005550","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.912000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_367c22e0_copy__24 = new TH1D("frame_367c22e0_copy__24","p_T Balance",25,0,2);
   frame_367c22e0_copy__24->SetBinContent(1,184.5132);
   frame_367c22e0_copy__24->SetMaximum(184.5132);
   frame_367c22e0_copy__24->SetEntries(1);
   frame_367c22e0_copy__24->SetDirectory(0);
   frame_367c22e0_copy__24->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367c22e0_copy__24->SetLineColor(ci);
   frame_367c22e0_copy__24->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367c22e0_copy__24->GetXaxis()->SetLabelFont(42);
   frame_367c22e0_copy__24->GetXaxis()->SetTitleOffset(1);
   frame_367c22e0_copy__24->GetXaxis()->SetTitleFont(42);
   frame_367c22e0_copy__24->GetYaxis()->SetTitle("1/Events");
   frame_367c22e0_copy__24->GetYaxis()->SetLabelFont(42);
   frame_367c22e0_copy__24->GetYaxis()->SetTitleFont(42);
   frame_367c22e0_copy__24->GetZaxis()->SetLabelFont(42);
   frame_367c22e0_copy__24->GetZaxis()->SetTitleOffset(1);
   frame_367c22e0_copy__24->GetZaxis()->SetTitleFont(42);
   frame_367c22e0_copy__24->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-20.53838,2.25,184.8454);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_367cfac0__25 = new TH1D("frame_367cfac0__25","p_T Balance",25,0,2);
   frame_367cfac0__25->SetBinContent(1,180.7377);
   frame_367cfac0__25->SetMaximum(180.7377);
   frame_367cfac0__25->SetEntries(1);
   frame_367cfac0__25->SetDirectory(0);
   frame_367cfac0__25->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367cfac0__25->SetLineColor(ci);
   frame_367cfac0__25->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367cfac0__25->GetXaxis()->SetLabelFont(42);
   frame_367cfac0__25->GetXaxis()->SetTitleOffset(1);
   frame_367cfac0__25->GetXaxis()->SetTitleFont(42);
   frame_367cfac0__25->GetYaxis()->SetTitle("1/Events");
   frame_367cfac0__25->GetYaxis()->SetLabelFont(42);
   frame_367cfac0__25->GetYaxis()->SetTitleFont(42);
   frame_367cfac0__25->GetZaxis()->SetLabelFont(42);
   frame_367cfac0__25->GetZaxis()->SetTitleOffset(1);
   frame_367cfac0__25->GetZaxis()->SetTitleFont(42);
   frame_367cfac0__25->Draw("FUNC");
   
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
   0.6729975,
   6.115369,
   8.519448,
   6.610211,
   15.57311,
   30.36632,
   60.56578,
   86.5146,
   136.5741,
   158.7427,
   165.1106,
   126.7831,
   82.18085,
   44.00047,
   15.68387,
   8.591162,
   4.032765,
   1.588777,
   1.086482,
   0.6172845,
   0.5260208,
   0.02345426,
   0.1436943,
   0.1048261};
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
   0.2924274,
   1.304582,
   1.629003,
   1.253854,
   2.059053,
   2.999039,
   4.438629,
   5.22574,
   6.512132,
   6.930801,
   7.020548,
   6.072504,
   4.718245,
   3.304574,
   1.733002,
   1.279551,
   0.8554756,
   0.4649898,
   0.4195463,
   0.3157252,
   0.2580119,
   0.01616888,
   0.06830677,
   0.07445595};
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
   0.2924274,
   1.304582,
   1.629003,
   1.253854,
   2.059053,
   2.999039,
   4.438629,
   5.22574,
   6.512132,
   6.930801,
   7.020548,
   6.072504,
   4.718245,
   3.304574,
   1.733002,
   1.279551,
   0.8554756,
   0.4649898,
   0.4195463,
   0.3157252,
   0.2580119,
   0.01616888,
   0.06830677,
   0.07445595};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3007,h_dh_down2_fy3007,h_dh_down2_felx3007,h_dh_down2_fehx3007,h_dh_down2_fely3007,h_dh_down2_fehy3007);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23007 = new TH1F("Graph_h_dh_down23007","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23007->SetMinimum(0);
   Graph_h_dh_down23007->SetMaximum(189.3443);
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
   
   Double_t down_fx7[56] = {
   0.4470605,
   0.464208,
   0.4813555,
   0.498503,
   0.5156505,
   0.532798,
   0.5499455,
   0.567093,
   0.5842405,
   0.601388,
   0.6185355,
   0.635683,
   0.6528305,
   0.6871254,
   0.7214204,
   0.7385679,
   0.7557154,
   0.7728629,
   0.7900104,
   0.8071579,
   0.8157316,
   0.8243054,
   0.8328791,
   0.8414529,
   0.8500266,
   0.8586004,
   0.8671741,
   0.8757479,
   0.8843216,
   0.8928954,
   0.9014691,
   0.9100428,
   0.9186166,
   0.9271903,
   0.9443378,
   0.9614853,
   0.9786328,
   0.9957803,
   1.012928,
   1.030075,
   1.06437,
   1.081518,
   1.098665,
   1.115813,
   1.13296,
   1.150108,
   1.167255,
   1.184403,
   1.20155,
   1.218698,
   1.235845,
   1.252993,
   1.27014,
   1.287288,
   1.304435,
   1.304435};
   Double_t down_fy7[56] = {
   9.631245,
   12.1089,
   15.07904,
   18.59899,
   22.72227,
   27.49543,
   32.95461,
   39.12175,
   46.00099,
   53.57506,
   61.80233,
   70.61445,
   79.91514,
   99.45803,
   119.1344,
   128.5304,
   137.3476,
   145.3728,
   152.4024,
   158.2512,
   160.682,
   162.7605,
   164.4721,
   165.8049,
   166.7494,
   167.2987,
   167.4491,
   167.1993,
   166.5512,
   165.5095,
   164.0815,
   162.2774,
   160.1099,
   157.594,
   151.5892,
   144.4253,
   136.2903,
   127.3894,
   117.9365,
   108.1459,
   88.36355,
   78.73625,
   69.4901,
   60.74602,
   52.5968,
   45.10737,
   38.31619,
   32.23768,
   26.86531,
   22.17515,
   18.12959,
   14.68101,
   11.77526,
   9.354746,
   7.361054,
   7.361054};
   graph = new TGraph(56,down_fx7,down_fy7);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down7 = new TH1F("Graph_down7","Projection of downf DSCB fit",100,0.3613231,1.390173);
   Graph_down7->SetMinimum(6.624948);
   Graph_down7->SetMaximum(183.4579);
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
   
   TH1D *frame_367cfac0__26 = new TH1D("frame_367cfac0__26","p_T Balance",25,0,2);
   frame_367cfac0__26->SetBinContent(1,180.7377);
   frame_367cfac0__26->SetMaximum(180.7377);
   frame_367cfac0__26->SetEntries(1);
   frame_367cfac0__26->SetDirectory(0);
   frame_367cfac0__26->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367cfac0__26->SetLineColor(ci);
   frame_367cfac0__26->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367cfac0__26->GetXaxis()->SetLabelFont(42);
   frame_367cfac0__26->GetXaxis()->SetTitleOffset(1);
   frame_367cfac0__26->GetXaxis()->SetTitleFont(42);
   frame_367cfac0__26->GetYaxis()->SetTitle("1/Events");
   frame_367cfac0__26->GetYaxis()->SetLabelFont(42);
   frame_367cfac0__26->GetYaxis()->SetTitleFont(42);
   frame_367cfac0__26->GetZaxis()->SetLabelFont(42);
   frame_367cfac0__26->GetZaxis()->SetTitleOffset(1);
   frame_367cfac0__26->GetZaxis()->SetTitleFont(42);
   frame_367cfac0__26->Draw("AXISSAME");
   
   TH1D *norm_d__27 = new TH1D("norm_d__27","",25,0,2);
   norm_d__27->SetBinContent(2,0.6729975);
   norm_d__27->SetBinContent(3,6.115369);
   norm_d__27->SetBinContent(4,8.519448);
   norm_d__27->SetBinContent(5,6.610211);
   norm_d__27->SetBinContent(6,15.57311);
   norm_d__27->SetBinContent(7,30.36632);
   norm_d__27->SetBinContent(8,60.56579);
   norm_d__27->SetBinContent(9,86.5146);
   norm_d__27->SetBinContent(10,136.5741);
   norm_d__27->SetBinContent(11,158.7427);
   norm_d__27->SetBinContent(12,165.1106);
   norm_d__27->SetBinContent(13,126.7831);
   norm_d__27->SetBinContent(14,82.18086);
   norm_d__27->SetBinContent(15,44.00047);
   norm_d__27->SetBinContent(16,15.68387);
   norm_d__27->SetBinContent(17,8.591162);
   norm_d__27->SetBinContent(18,4.032765);
   norm_d__27->SetBinContent(19,1.588777);
   norm_d__27->SetBinContent(20,1.086482);
   norm_d__27->SetBinContent(21,0.6172845);
   norm_d__27->SetBinContent(22,0.5260208);
   norm_d__27->SetBinContent(23,0.02345426);
   norm_d__27->SetBinContent(24,0.1436943);
   norm_d__27->SetBinContent(25,0.1048261);
   norm_d__27->SetBinContent(26,0.4951645);
   norm_d__27->SetBinError(2,0.2924274);
   norm_d__27->SetBinError(3,1.304582);
   norm_d__27->SetBinError(4,1.629003);
   norm_d__27->SetBinError(5,1.253854);
   norm_d__27->SetBinError(6,2.059053);
   norm_d__27->SetBinError(7,2.999039);
   norm_d__27->SetBinError(8,4.438629);
   norm_d__27->SetBinError(9,5.22574);
   norm_d__27->SetBinError(10,6.512132);
   norm_d__27->SetBinError(11,6.930801);
   norm_d__27->SetBinError(12,7.020548);
   norm_d__27->SetBinError(13,6.072504);
   norm_d__27->SetBinError(14,4.718245);
   norm_d__27->SetBinError(15,3.304574);
   norm_d__27->SetBinError(16,1.733002);
   norm_d__27->SetBinError(17,1.279551);
   norm_d__27->SetBinError(18,0.8554756);
   norm_d__27->SetBinError(19,0.4649898);
   norm_d__27->SetBinError(20,0.4195463);
   norm_d__27->SetBinError(21,0.3157252);
   norm_d__27->SetBinError(22,0.2580119);
   norm_d__27->SetBinError(23,0.01616888);
   norm_d__27->SetBinError(24,0.06830677);
   norm_d__27->SetBinError(25,0.07445595);
   norm_d__27->SetBinError(26,0.1282791);
   norm_d__27->SetEntries(5167);
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
   entry=leg->AddEntry("frame_x_d2_367cfac0","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.866108 #pm 0.006138","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.175345 #pm 0.005137","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.340000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_367cfac0_copy__28 = new TH1D("frame_367cfac0_copy__28","p_T Balance",25,0,2);
   frame_367cfac0_copy__28->SetBinContent(1,180.7377);
   frame_367cfac0_copy__28->SetMaximum(180.7377);
   frame_367cfac0_copy__28->SetEntries(1);
   frame_367cfac0_copy__28->SetDirectory(0);
   frame_367cfac0_copy__28->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367cfac0_copy__28->SetLineColor(ci);
   frame_367cfac0_copy__28->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367cfac0_copy__28->GetXaxis()->SetLabelFont(42);
   frame_367cfac0_copy__28->GetXaxis()->SetTitleOffset(1);
   frame_367cfac0_copy__28->GetXaxis()->SetTitleFont(42);
   frame_367cfac0_copy__28->GetYaxis()->SetTitle("1/Events");
   frame_367cfac0_copy__28->GetYaxis()->SetLabelFont(42);
   frame_367cfac0_copy__28->GetYaxis()->SetTitleFont(42);
   frame_367cfac0_copy__28->GetZaxis()->SetLabelFont(42);
   frame_367cfac0_copy__28->GetZaxis()->SetTitleOffset(1);
   frame_367cfac0_copy__28->GetZaxis()->SetTitleFont(42);
   frame_367cfac0_copy__28->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-24.49952,2.25,220.4957);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3679aa10__29 = new TH1D("frame_3679aa10__29","p_T Balance",25,0,2);
   frame_3679aa10__29->SetBinContent(1,215.5958);
   frame_3679aa10__29->SetMaximum(215.5958);
   frame_3679aa10__29->SetEntries(1);
   frame_3679aa10__29->SetDirectory(0);
   frame_3679aa10__29->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3679aa10__29->SetLineColor(ci);
   frame_3679aa10__29->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3679aa10__29->GetXaxis()->SetLabelFont(42);
   frame_3679aa10__29->GetXaxis()->SetTitleOffset(1);
   frame_3679aa10__29->GetXaxis()->SetTitleFont(42);
   frame_3679aa10__29->GetYaxis()->SetTitle("1/Events");
   frame_3679aa10__29->GetYaxis()->SetLabelFont(42);
   frame_3679aa10__29->GetYaxis()->SetTitleFont(42);
   frame_3679aa10__29->GetZaxis()->SetLabelFont(42);
   frame_3679aa10__29->GetZaxis()->SetTitleOffset(1);
   frame_3679aa10__29->GetZaxis()->SetTitleFont(42);
   frame_3679aa10__29->Draw("FUNC");
   
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
   2,
   11,
   9,
   17,
   25,
   34,
   75,
   121,
   180,
   191,
   180,
   181,
   103,
   64,
   25,
   11,
   2,
   4,
   2,
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
   1.291815,
   3.265579,
   2.943461,
   4.082184,
   4.966335,
   5.802128,
   8.640903,
   10.51136,
   12.92572,
   13.32932,
   12.92572,
   12.96291,
   9.661201,
   7.979042,
   4.966335,
   3.265579,
   1.291815,
   1.914339,
   1.291815,
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
   2.63786,
   4.416521,
   4.110204,
   5.203719,
   6.066589,
   6.888101,
   9.698771,
   11.51136,
   13.92572,
   14.32932,
   13.92572,
   13.96291,
   10.6612,
   9.041691,
   6.066589,
   4.416521,
   2.63786,
   3.162753,
   2.63786,
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
   Graph_h_dh_data23008->SetMaximum(225.8622);
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
   
   Double_t observation_fx8[58] = {
   0.3840508,
   0.4225739,
   0.4418354,
   0.461097,
   0.4803585,
   0.4996201,
   0.5188816,
   0.5381431,
   0.5574047,
   0.5766662,
   0.5959277,
   0.6151893,
   0.6344508,
   0.6537123,
   0.6922354,
   0.711497,
   0.7307585,
   0.75002,
   0.7692816,
   0.7885431,
   0.7981739,
   0.8078046,
   0.8174354,
   0.8270662,
   0.8366969,
   0.8463277,
   0.8559585,
   0.8655892,
   0.87522,
   0.8848508,
   0.8944816,
   0.9041123,
   0.9137431,
   0.9233739,
   0.9330046,
   0.9426354,
   0.9522662,
   0.9618969,
   0.9811585,
   1.00042,
   1.019682,
   1.038943,
   1.077466,
   1.096728,
   1.115989,
   1.135251,
   1.154512,
   1.173774,
   1.193035,
   1.212297,
   1.231558,
   1.25082,
   1.270082,
   1.289343,
   1.308605,
   1.327866,
   1.347128,
   1.347128};
   Double_t observation_fy8[58] = {
   14.64096,
   18.70437,
   21.26555,
   24.2805,
   27.84921,
   32.09834,
   37.18967,
   43.33171,
   50.79573,
   59.81316,
   69.85077,
   80.71804,
   92.29855,
   104.4345,
   129.5439,
   142.0171,
   154.0598,
   165.3724,
   175.6554,
   184.6226,
   188.5301,
   192.014,
   195.0479,
   197.6087,
   199.6765,
   201.2352,
   202.2727,
   202.7808,
   202.7555,
   202.1969,
   201.1096,
   199.5019,
   197.3866,
   194.7801,
   191.7024,
   188.1772,
   184.2309,
   179.893,
   170.1713,
   159.2881,
   147.5384,
   135.2234,
   110.0576,
   97.73306,
   85.87915,
   74.6722,
   64.24731,
   54.69856,
   46.08098,
   38.41425,
   31.6875,
   25.86475,
   20.89073,
   16.69644,
   13.20441,
   10.3333,
   8.001728,
   8.001728};
   graph = new TGraph(58,observation_fx8,observation_fy8);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation8 = new TH1F("Graph_observation8","Projection of obsf DSCB fit",100,0.2877432,1.443435);
   Graph_observation8->SetMinimum(7.201555);
   Graph_observation8->SetMaximum(222.2587);
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
   
   TH1D *frame_3679aa10__30 = new TH1D("frame_3679aa10__30","p_T Balance",25,0,2);
   frame_3679aa10__30->SetBinContent(1,215.5958);
   frame_3679aa10__30->SetMaximum(215.5958);
   frame_3679aa10__30->SetEntries(1);
   frame_3679aa10__30->SetDirectory(0);
   frame_3679aa10__30->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3679aa10__30->SetLineColor(ci);
   frame_3679aa10__30->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3679aa10__30->GetXaxis()->SetLabelFont(42);
   frame_3679aa10__30->GetXaxis()->SetTitleOffset(1);
   frame_3679aa10__30->GetXaxis()->SetTitleFont(42);
   frame_3679aa10__30->GetYaxis()->SetTitle("1/Events");
   frame_3679aa10__30->GetYaxis()->SetLabelFont(42);
   frame_3679aa10__30->GetYaxis()->SetTitleFont(42);
   frame_3679aa10__30->GetZaxis()->SetLabelFont(42);
   frame_3679aa10__30->GetZaxis()->SetTitleOffset(1);
   frame_3679aa10__30->GetZaxis()->SetTitleFont(42);
   frame_3679aa10__30->Draw("AXISSAME");
   
   TH1D *norm_o__31 = new TH1D("norm_o__31","",25,0,2);
   norm_o__31->SetBinContent(2,2);
   norm_o__31->SetBinContent(3,11);
   norm_o__31->SetBinContent(4,9);
   norm_o__31->SetBinContent(5,17);
   norm_o__31->SetBinContent(6,25);
   norm_o__31->SetBinContent(7,34);
   norm_o__31->SetBinContent(8,75);
   norm_o__31->SetBinContent(9,121);
   norm_o__31->SetBinContent(10,180);
   norm_o__31->SetBinContent(11,191);
   norm_o__31->SetBinContent(12,180);
   norm_o__31->SetBinContent(13,181);
   norm_o__31->SetBinContent(14,103);
   norm_o__31->SetBinContent(15,64);
   norm_o__31->SetBinContent(16,25);
   norm_o__31->SetBinContent(17,11);
   norm_o__31->SetBinContent(18,2);
   norm_o__31->SetBinContent(19,4);
   norm_o__31->SetBinContent(20,2);
   norm_o__31->SetBinContent(21,1);
   norm_o__31->SetMinimum(0);
   norm_o__31->SetMaximum(420.2);
   norm_o__31->SetEntries(1238);
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
   entry=leg->AddEntry("frame_x_o2_3679aa10","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.869944 #pm 0.005890","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.187660 #pm 0.005129","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.993000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3679aa10_copy__32 = new TH1D("frame_3679aa10_copy__32","p_T Balance",25,0,2);
   frame_3679aa10_copy__32->SetBinContent(1,215.5958);
   frame_3679aa10_copy__32->SetMaximum(215.5958);
   frame_3679aa10_copy__32->SetEntries(1);
   frame_3679aa10_copy__32->SetDirectory(0);
   frame_3679aa10_copy__32->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3679aa10_copy__32->SetLineColor(ci);
   frame_3679aa10_copy__32->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3679aa10_copy__32->GetXaxis()->SetLabelFont(42);
   frame_3679aa10_copy__32->GetXaxis()->SetTitleOffset(1);
   frame_3679aa10_copy__32->GetXaxis()->SetTitleFont(42);
   frame_3679aa10_copy__32->GetYaxis()->SetTitle("1/Events");
   frame_3679aa10_copy__32->GetYaxis()->SetLabelFont(42);
   frame_3679aa10_copy__32->GetYaxis()->SetTitleFont(42);
   frame_3679aa10_copy__32->GetZaxis()->SetLabelFont(42);
   frame_3679aa10_copy__32->GetZaxis()->SetTitleOffset(1);
   frame_3679aa10_copy__32->GetZaxis()->SetTitleFont(42);
   frame_3679aa10_copy__32->Draw("sameaxis");
   
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
