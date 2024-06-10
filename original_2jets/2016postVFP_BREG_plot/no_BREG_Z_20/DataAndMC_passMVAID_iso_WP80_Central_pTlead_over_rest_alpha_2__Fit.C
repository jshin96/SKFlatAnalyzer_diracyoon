void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_2__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 17:25:28 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-5.266764,2.25,60.56779);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_370ebd00__17 = new TH1D("frame_370ebd00__17","p_T Balance",25,0,2);
   frame_370ebd00__17->SetBinContent(1,53.98433);
   frame_370ebd00__17->SetMaximum(53.98433);
   frame_370ebd00__17->SetEntries(1);
   frame_370ebd00__17->SetDirectory(0);
   frame_370ebd00__17->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_370ebd00__17->SetLineColor(ci);
   frame_370ebd00__17->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_370ebd00__17->GetXaxis()->SetLabelFont(42);
   frame_370ebd00__17->GetXaxis()->SetTitleOffset(1);
   frame_370ebd00__17->GetXaxis()->SetTitleFont(42);
   frame_370ebd00__17->GetYaxis()->SetTitle("1/Events");
   frame_370ebd00__17->GetYaxis()->SetLabelFont(42);
   frame_370ebd00__17->GetYaxis()->SetTitleFont(42);
   frame_370ebd00__17->GetZaxis()->SetLabelFont(42);
   frame_370ebd00__17->GetZaxis()->SetTitleOffset(1);
   frame_370ebd00__17->GetZaxis()->SetTitleFont(42);
   frame_370ebd00__17->Draw("FUNC");
   
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
   0.1421781,
   1.134406,
   1.769761,
   2.767426,
   3.433525,
   12.54061,
   19.01403,
   24.55384,
   36.60345,
   47.39775,
   43.91813,
   34.97908,
   22.99142,
   11.09968,
   9.154765,
   2.392262,
   0.5512057,
   0.6633757,
   0.6835102,
   0.08624431,
   0.1872618,
   0.04856938,
   0,
   0.01576736};
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
   0.1049481,
   0.4694544,
   0.4895593,
   0.8132486,
   0.9835392,
   2.304073,
   2.548774,
   2.944973,
   3.329413,
   4.015894,
   3.741943,
   3.394603,
   2.728977,
   1.508927,
   1.579563,
   0.746104,
   0.2206349,
   0.2691387,
   0.274977,
   0.08624431,
   0.1310149,
   0.04060526,
   0,
   0.0117649};
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
   0.1049481,
   0.4694544,
   0.4895593,
   0.8132486,
   0.9835392,
   2.304073,
   2.548774,
   2.944973,
   3.329413,
   4.015894,
   3.741943,
   3.394603,
   2.728977,
   1.508927,
   1.579563,
   0.746104,
   0.2206349,
   0.2691387,
   0.274977,
   0.08624431,
   0.1310149,
   0.04060526,
   0,
   0.0117649};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3005,h_dh_central2_fy3005,h_dh_central2_felx3005,h_dh_central2_fehx3005,h_dh_central2_fely3005,h_dh_central2_fehy3005);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23005 = new TH1F("Graph_h_dh_central23005","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23005->SetMinimum(0);
   Graph_h_dh_central23005->SetMaximum(56.55501);
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
   0.4195832,
   0.4561177,
   0.474385,
   0.4926523,
   0.5109196,
   0.5291869,
   0.5474542,
   0.5657215,
   0.5839888,
   0.6022561,
   0.6205234,
   0.6387906,
   0.6479243,
   0.6570579,
   0.6753252,
   0.7118598,
   0.7301271,
   0.7483944,
   0.7666617,
   0.784929,
   0.7940626,
   0.8031963,
   0.8123299,
   0.8214635,
   0.8305972,
   0.8397308,
   0.8488645,
   0.8579981,
   0.8671318,
   0.8762654,
   0.8853991,
   0.8945327,
   0.9036663,
   0.9128,
   0.9219336,
   0.9310673,
   0.9402009,
   0.9493346,
   0.9676019,
   0.9858692,
   1.004136,
   1.040671,
   1.077206,
   1.095473,
   1.11374,
   1.122874,
   1.132007,
   1.150275,
   1.168542,
   1.186809,
   1.205077,
   1.223344,
   1.241611,
   1.259879,
   1.296413,
   1.332948,
   1.332948};
   Double_t Central_fy5[57] = {
   6.542279,
   7.754938,
   8.466709,
   9.262046,
   10.15301,
   11.15372,
   12.28082,
   13.55396,
   14.99643,
   16.63601,
   18.50591,
   20.64608,
   21.83221,
   23.10476,
   25.89989,
   31.64788,
   34.43159,
   37.06484,
   39.47844,
   41.60547,
   42.542,
   43.3844,
   44.1263,
   44.762,
   45.2866,
   45.69599,
   45.98696,
   46.15719,
   46.20535,
   46.13105,
   45.93488,
   45.6184,
   45.1841,
   44.6354,
   43.97657,
   43.21271,
   42.34965,
   41.39389,
   39.2332,
   36.79289,
   34.14026,
   28.47414,
   22.76173,
   20.02957,
   17.46984,
   16.32738,
   15.27721,
   13.41939,
   11.83672,
   10.48159,
   9.315733,
   8.308221,
   7.433862,
   6.672032,
   5.420934,
   4.450863,
   4.450863};
   TGraph *graph = new TGraph(57,Central_fx5,Central_fy5);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central5 = new TH1F("Graph_Central5","Projection of centralf DSCB fit",100,0.3282467,1.424284);
   Graph_Central5->SetMinimum(0.2754136);
   Graph_Central5->SetMaximum(50.3808);
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
   
   TH1D *frame_370ebd00__18 = new TH1D("frame_370ebd00__18","p_T Balance",25,0,2);
   frame_370ebd00__18->SetBinContent(1,53.98433);
   frame_370ebd00__18->SetMaximum(53.98433);
   frame_370ebd00__18->SetEntries(1);
   frame_370ebd00__18->SetDirectory(0);
   frame_370ebd00__18->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_370ebd00__18->SetLineColor(ci);
   frame_370ebd00__18->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_370ebd00__18->GetXaxis()->SetLabelFont(42);
   frame_370ebd00__18->GetXaxis()->SetTitleOffset(1);
   frame_370ebd00__18->GetXaxis()->SetTitleFont(42);
   frame_370ebd00__18->GetYaxis()->SetTitle("1/Events");
   frame_370ebd00__18->GetYaxis()->SetLabelFont(42);
   frame_370ebd00__18->GetYaxis()->SetTitleFont(42);
   frame_370ebd00__18->GetZaxis()->SetLabelFont(42);
   frame_370ebd00__18->GetZaxis()->SetTitleOffset(1);
   frame_370ebd00__18->GetZaxis()->SetTitleFont(42);
   frame_370ebd00__18->Draw("AXISSAME");
   
   TH1D *norm_c__19 = new TH1D("norm_c__19","",25,0,2);
   norm_c__19->SetBinContent(2,0.1421781);
   norm_c__19->SetBinContent(3,1.134406);
   norm_c__19->SetBinContent(4,1.769761);
   norm_c__19->SetBinContent(5,2.767426);
   norm_c__19->SetBinContent(6,3.433525);
   norm_c__19->SetBinContent(7,12.54061);
   norm_c__19->SetBinContent(8,19.01403);
   norm_c__19->SetBinContent(9,24.55384);
   norm_c__19->SetBinContent(10,36.60346);
   norm_c__19->SetBinContent(11,47.39775);
   norm_c__19->SetBinContent(12,43.91813);
   norm_c__19->SetBinContent(13,34.97907);
   norm_c__19->SetBinContent(14,22.99143);
   norm_c__19->SetBinContent(15,11.09969);
   norm_c__19->SetBinContent(16,9.154765);
   norm_c__19->SetBinContent(17,2.392262);
   norm_c__19->SetBinContent(18,0.5512057);
   norm_c__19->SetBinContent(19,0.6633756);
   norm_c__19->SetBinContent(20,0.6835103);
   norm_c__19->SetBinContent(21,0.08624431);
   norm_c__19->SetBinContent(22,0.1872619);
   norm_c__19->SetBinContent(23,0.04856938);
   norm_c__19->SetBinContent(25,0.01576736);
   norm_c__19->SetBinContent(26,0.08021484);
   norm_c__19->SetBinError(2,0.1049481);
   norm_c__19->SetBinError(3,0.4694544);
   norm_c__19->SetBinError(4,0.4895593);
   norm_c__19->SetBinError(5,0.8132486);
   norm_c__19->SetBinError(6,0.9835392);
   norm_c__19->SetBinError(7,2.304073);
   norm_c__19->SetBinError(8,2.548774);
   norm_c__19->SetBinError(9,2.944973);
   norm_c__19->SetBinError(10,3.329413);
   norm_c__19->SetBinError(11,4.015894);
   norm_c__19->SetBinError(12,3.741943);
   norm_c__19->SetBinError(13,3.394603);
   norm_c__19->SetBinError(14,2.728977);
   norm_c__19->SetBinError(15,1.508927);
   norm_c__19->SetBinError(16,1.579563);
   norm_c__19->SetBinError(17,0.746104);
   norm_c__19->SetBinError(18,0.2206349);
   norm_c__19->SetBinError(19,0.2691387);
   norm_c__19->SetBinError(20,0.274977);
   norm_c__19->SetBinError(21,0.08624431);
   norm_c__19->SetBinError(22,0.1310149);
   norm_c__19->SetBinError(23,0.04060526);
   norm_c__19->SetBinError(25,0.0117649);
   norm_c__19->SetBinError(26,0.05266801);
   norm_c__19->SetEntries(1529);
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
   entry=leg->AddEntry("frame_x_c2_370ebd00","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.860899 #pm 0.013254","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.201073 #pm 0.011829","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.991000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_370ebd00_copy__20 = new TH1D("frame_370ebd00_copy__20","p_T Balance",25,0,2);
   frame_370ebd00_copy__20->SetBinContent(1,53.98433);
   frame_370ebd00_copy__20->SetMaximum(53.98433);
   frame_370ebd00_copy__20->SetEntries(1);
   frame_370ebd00_copy__20->SetDirectory(0);
   frame_370ebd00_copy__20->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_370ebd00_copy__20->SetLineColor(ci);
   frame_370ebd00_copy__20->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_370ebd00_copy__20->GetXaxis()->SetLabelFont(42);
   frame_370ebd00_copy__20->GetXaxis()->SetTitleOffset(1);
   frame_370ebd00_copy__20->GetXaxis()->SetTitleFont(42);
   frame_370ebd00_copy__20->GetYaxis()->SetTitle("1/Events");
   frame_370ebd00_copy__20->GetYaxis()->SetLabelFont(42);
   frame_370ebd00_copy__20->GetYaxis()->SetTitleFont(42);
   frame_370ebd00_copy__20->GetZaxis()->SetLabelFont(42);
   frame_370ebd00_copy__20->GetZaxis()->SetTitleOffset(1);
   frame_370ebd00_copy__20->GetZaxis()->SetTitleFont(42);
   frame_370ebd00_copy__20->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-5.408922,2.25,62.2026);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_37104090__21 = new TH1D("frame_37104090__21","p_T Balance",25,0,2);
   frame_37104090__21->SetBinContent(1,55.44145);
   frame_37104090__21->SetMaximum(55.44145);
   frame_37104090__21->SetEntries(1);
   frame_37104090__21->SetDirectory(0);
   frame_37104090__21->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_37104090__21->SetLineColor(ci);
   frame_37104090__21->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_37104090__21->GetXaxis()->SetLabelFont(42);
   frame_37104090__21->GetXaxis()->SetTitleOffset(1);
   frame_37104090__21->GetXaxis()->SetTitleFont(42);
   frame_37104090__21->GetYaxis()->SetTitle("1/Events");
   frame_37104090__21->GetYaxis()->SetLabelFont(42);
   frame_37104090__21->GetYaxis()->SetTitleFont(42);
   frame_37104090__21->GetZaxis()->SetLabelFont(42);
   frame_37104090__21->GetZaxis()->SetTitleOffset(1);
   frame_37104090__21->GetZaxis()->SetTitleFont(42);
   frame_37104090__21->Draw("FUNC");
   
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
   0.6493994,
   1.703597,
   3.043407,
   2.949169,
   10.54591,
   16.29456,
   24.11168,
   33.27222,
   48.57703,
   42.81146,
   36.76466,
   24.4706,
   13.09496,
   9.214355,
   2.740399,
   0.8382362,
   0.3660477,
   0.7207127,
   0.3463553,
   0.1339687,
   0.1017685,
   0,
   0.01580398};
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
   0.3627284,
   0.481094,
   0.9290226,
   0.8934757,
   2.091249,
   2.417993,
   2.902055,
   3.237155,
   4.224348,
   3.535773,
   3.442952,
   2.857437,
   1.8397,
   1.558181,
   0.8449031,
   0.2999341,
   0.1823626,
   0.2753445,
   0.2288765,
   0.1228213,
   0.0615892,
   0,
   0.01179048};
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
   0.3627284,
   0.481094,
   0.9290226,
   0.8934757,
   2.091249,
   2.417993,
   2.902055,
   3.237155,
   4.224348,
   3.535773,
   3.442952,
   2.857437,
   1.8397,
   1.558181,
   0.8449031,
   0.2999341,
   0.1823626,
   0.2753445,
   0.2288765,
   0.1228213,
   0.0615892,
   0,
   0.01179048};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3006,h_dh_up2_fy3006,h_dh_up2_felx3006,h_dh_up2_fehx3006,h_dh_up2_fely3006,h_dh_up2_fehy3006);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23006 = new TH1F("Graph_h_dh_up23006","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23006->SetMinimum(0);
   Graph_h_dh_up23006->SetMaximum(58.08152);
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
   
   Double_t up_fx6[58] = {
   0.3708687,
   0.390777,
   0.4106852,
   0.4305935,
   0.4505017,
   0.4704099,
   0.4903182,
   0.5102264,
   0.5301346,
   0.5500429,
   0.5699511,
   0.5898593,
   0.6097676,
   0.6296758,
   0.649584,
   0.6894005,
   0.729217,
   0.7491252,
   0.7690335,
   0.7889417,
   0.7988958,
   0.8088499,
   0.818804,
   0.8287582,
   0.8387123,
   0.8486664,
   0.8586205,
   0.8685746,
   0.8785288,
   0.8884829,
   0.898437,
   0.9083911,
   0.9183452,
   0.9282993,
   0.9382535,
   0.9482076,
   0.9581617,
   0.9681158,
   0.9880241,
   1.007932,
   1.027841,
   1.047749,
   1.087565,
   1.107473,
   1.127382,
   1.14729,
   1.167198,
   1.187106,
   1.207015,
   1.226923,
   1.246831,
   1.266739,
   1.286648,
   1.306556,
   1.326464,
   1.346372,
   1.366281,
   1.366281};
   Double_t up_fy6[58] = {
   1.4,
   1.828772,
   2.363338,
   3.021531,
   3.821758,
   4.782271,
   5.92025,
   7.250714,
   8.785296,
   10.53093,
   12.48856,
   14.65185,
   17.00621,
   19.52799,
   22.18413,
   27.7215,
   33.18415,
   35.72645,
   38.05257,
   40.0971,
   40.99473,
   41.80005,
   42.50689,
   43.10975,
   43.60392,
   43.98546,
   44.25135,
   44.39945,
   44.42858,
   44.3385,
   44.12993,
   43.80455,
   43.36496,
   42.81464,
   42.15795,
   41.4,
   40.54664,
   39.60437,
   37.48184,
   35.09405,
   32.5073,
   29.78951,
   24.22326,
   21.49412,
   18.86868,
   16.38695,
   14.07958,
   11.96785,
   10.06416,
   8.372859,
   6.891359,
   5.611395,
   4.520346,
   3.602528,
   2.84039,
   2.21556,
   1.709715,
   1.709715};
   graph = new TGraph(58,up_fx6,up_fy6);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up6 = new TH1F("Graph_up6","Projection of upf DSCB fit",100,0.2713276,1.465822);
   Graph_up6->SetMinimum(1.26);
   Graph_up6->SetMaximum(48.73144);
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
   
   TH1D *frame_37104090__22 = new TH1D("frame_37104090__22","p_T Balance",25,0,2);
   frame_37104090__22->SetBinContent(1,55.44145);
   frame_37104090__22->SetMaximum(55.44145);
   frame_37104090__22->SetEntries(1);
   frame_37104090__22->SetDirectory(0);
   frame_37104090__22->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_37104090__22->SetLineColor(ci);
   frame_37104090__22->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_37104090__22->GetXaxis()->SetLabelFont(42);
   frame_37104090__22->GetXaxis()->SetTitleOffset(1);
   frame_37104090__22->GetXaxis()->SetTitleFont(42);
   frame_37104090__22->GetYaxis()->SetTitle("1/Events");
   frame_37104090__22->GetYaxis()->SetLabelFont(42);
   frame_37104090__22->GetYaxis()->SetTitleFont(42);
   frame_37104090__22->GetZaxis()->SetLabelFont(42);
   frame_37104090__22->GetZaxis()->SetTitleOffset(1);
   frame_37104090__22->GetZaxis()->SetTitleFont(42);
   frame_37104090__22->Draw("AXISSAME");
   
   TH1D *norm_u__23 = new TH1D("norm_u__23","",25,0,2);
   norm_u__23->SetBinContent(2,0.2711817);
   norm_u__23->SetBinContent(3,0.6493994);
   norm_u__23->SetBinContent(4,1.703597);
   norm_u__23->SetBinContent(5,3.043407);
   norm_u__23->SetBinContent(6,2.949169);
   norm_u__23->SetBinContent(7,10.54591);
   norm_u__23->SetBinContent(8,16.29456);
   norm_u__23->SetBinContent(9,24.11168);
   norm_u__23->SetBinContent(10,33.27222);
   norm_u__23->SetBinContent(11,48.57703);
   norm_u__23->SetBinContent(12,42.81146);
   norm_u__23->SetBinContent(13,36.76466);
   norm_u__23->SetBinContent(14,24.4706);
   norm_u__23->SetBinContent(15,13.09496);
   norm_u__23->SetBinContent(16,9.214356);
   norm_u__23->SetBinContent(17,2.740399);
   norm_u__23->SetBinContent(18,0.8382362);
   norm_u__23->SetBinContent(19,0.3660477);
   norm_u__23->SetBinContent(20,0.7207127);
   norm_u__23->SetBinContent(21,0.3463553);
   norm_u__23->SetBinContent(22,0.1339686);
   norm_u__23->SetBinContent(23,0.1017685);
   norm_u__23->SetBinContent(25,0.01580398);
   norm_u__23->SetBinContent(26,0.08357239);
   norm_u__23->SetBinError(2,0.1987896);
   norm_u__23->SetBinError(3,0.3627284);
   norm_u__23->SetBinError(4,0.481094);
   norm_u__23->SetBinError(5,0.9290226);
   norm_u__23->SetBinError(6,0.8934757);
   norm_u__23->SetBinError(7,2.091249);
   norm_u__23->SetBinError(8,2.417993);
   norm_u__23->SetBinError(9,2.902055);
   norm_u__23->SetBinError(10,3.237155);
   norm_u__23->SetBinError(11,4.224348);
   norm_u__23->SetBinError(12,3.535773);
   norm_u__23->SetBinError(13,3.442952);
   norm_u__23->SetBinError(14,2.857437);
   norm_u__23->SetBinError(15,1.8397);
   norm_u__23->SetBinError(16,1.558181);
   norm_u__23->SetBinError(17,0.8449031);
   norm_u__23->SetBinError(18,0.2999341);
   norm_u__23->SetBinError(19,0.1823626);
   norm_u__23->SetBinError(20,0.2753445);
   norm_u__23->SetBinError(21,0.2288765);
   norm_u__23->SetBinError(22,0.1228213);
   norm_u__23->SetBinError(23,0.0615892);
   norm_u__23->SetBinError(25,0.01179048);
   norm_u__23->SetBinError(26,0.05284295);
   norm_u__23->SetEntries(1508);
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
   entry=leg->AddEntry("frame_x_u2_37104090","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.875978 #pm 0.012257","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.192079 #pm 0.009849","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.980000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_37104090_copy__24 = new TH1D("frame_37104090_copy__24","p_T Balance",25,0,2);
   frame_37104090_copy__24->SetBinContent(1,55.44145);
   frame_37104090_copy__24->SetMaximum(55.44145);
   frame_37104090_copy__24->SetEntries(1);
   frame_37104090_copy__24->SetDirectory(0);
   frame_37104090_copy__24->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_37104090_copy__24->SetLineColor(ci);
   frame_37104090_copy__24->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_37104090_copy__24->GetXaxis()->SetLabelFont(42);
   frame_37104090_copy__24->GetXaxis()->SetTitleOffset(1);
   frame_37104090_copy__24->GetXaxis()->SetTitleFont(42);
   frame_37104090_copy__24->GetYaxis()->SetTitle("1/Events");
   frame_37104090_copy__24->GetYaxis()->SetLabelFont(42);
   frame_37104090_copy__24->GetYaxis()->SetTitleFont(42);
   frame_37104090_copy__24->GetZaxis()->SetLabelFont(42);
   frame_37104090_copy__24->GetZaxis()->SetTitleOffset(1);
   frame_37104090_copy__24->GetZaxis()->SetTitleFont(42);
   frame_37104090_copy__24->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-5.64946,2.25,50.84514);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_370dfdd0__25 = new TH1D("frame_370dfdd0__25","p_T Balance",25,0,2);
   frame_370dfdd0__25->SetBinContent(1,49.71525);
   frame_370dfdd0__25->SetMaximum(49.71525);
   frame_370dfdd0__25->SetEntries(1);
   frame_370dfdd0__25->SetDirectory(0);
   frame_370dfdd0__25->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_370dfdd0__25->SetLineColor(ci);
   frame_370dfdd0__25->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_370dfdd0__25->GetXaxis()->SetLabelFont(42);
   frame_370dfdd0__25->GetXaxis()->SetTitleOffset(1);
   frame_370dfdd0__25->GetXaxis()->SetTitleFont(42);
   frame_370dfdd0__25->GetYaxis()->SetTitle("1/Events");
   frame_370dfdd0__25->GetYaxis()->SetLabelFont(42);
   frame_370dfdd0__25->GetYaxis()->SetTitleFont(42);
   frame_370dfdd0__25->GetZaxis()->SetLabelFont(42);
   frame_370dfdd0__25->GetZaxis()->SetTitleOffset(1);
   frame_370dfdd0__25->GetZaxis()->SetTitleFont(42);
   frame_370dfdd0__25->Draw("FUNC");
   
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
   0.7997586,
   1.173435,
   1.69689,
   2.774444,
   3.425532,
   12.39064,
   20.17356,
   24.79045,
   36.44014,
   43.51275,
   41.5604,
   31.39878,
   18.8339,
   12.72177,
   6.239594,
   2.072464,
   0.6075258,
   0.6080943,
   0.7371762,
   0.08698372,
   0.1905579,
   0.04723104,
   0.1170706,
   0.01589001};
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
   0.6709888,
   0.4633788,
   0.4815074,
   0.7745744,
   0.9016264,
   2.228097,
   2.671631,
   2.838392,
   3.350309,
   3.835108,
   3.519714,
   3.06579,
   2.31728,
   1.741555,
   1.126102,
   0.7174971,
   0.2276284,
   0.2679814,
   0.3183991,
   0.08698372,
   0.1321503,
   0.04089921,
   0.09596489,
   0.01185459};
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
   0.6709888,
   0.4633788,
   0.4815074,
   0.7745744,
   0.9016264,
   2.228097,
   2.671631,
   2.838392,
   3.350309,
   3.835108,
   3.519714,
   3.06579,
   2.31728,
   1.741555,
   1.126102,
   0.7174971,
   0.2276284,
   0.2679814,
   0.3183991,
   0.08698372,
   0.1321503,
   0.04089921,
   0.09596489,
   0.01185459};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3007,h_dh_down2_fy3007,h_dh_down2_felx3007,h_dh_down2_fehx3007,h_dh_down2_fely3007,h_dh_down2_fehy3007);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23007 = new TH1F("Graph_h_dh_down23007","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23007->SetMinimum(0);
   Graph_h_dh_down23007->SetMaximum(52.08264);
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
   
   Double_t down_fx7[54] = {
   0.4057912,
   0.4241715,
   0.4425518,
   0.4609321,
   0.4793124,
   0.4976927,
   0.516073,
   0.5344533,
   0.5528336,
   0.5712139,
   0.5895942,
   0.6079746,
   0.6263549,
   0.6631155,
   0.6998761,
   0.7182564,
   0.7366367,
   0.755017,
   0.7733973,
   0.7917776,
   0.8009678,
   0.810158,
   0.8193481,
   0.8285383,
   0.8377284,
   0.8469186,
   0.8561087,
   0.8652989,
   0.874489,
   0.8836792,
   0.8928693,
   0.9020595,
   0.9204398,
   0.9388201,
   0.9572004,
   0.9755807,
   0.993961,
   1.012341,
   1.030722,
   1.067482,
   1.104243,
   1.122623,
   1.141004,
   1.159384,
   1.177764,
   1.196144,
   1.214525,
   1.232905,
   1.251285,
   1.269666,
   1.288046,
   1.306426,
   1.324807,
   1.324807};
   Double_t down_fy7[54] = {
   3.402009,
   4.163807,
   5.053012,
   6.080157,
   7.254106,
   8.581392,
   10.06552,
   11.70629,
   13.49918,
   15.43476,
   17.49835,
   19.66976,
   21.92329,
   26.54807,
   31.0727,
   33.19013,
   35.15149,
   36.91332,
   38.43503,
   39.6804,
   40.18969,
   40.61902,
   40.96571,
   41.22756,
   41.40292,
   41.49067,
   41.49026,
   41.40168,
   41.22551,
   40.96285,
   40.61538,
   40.18529,
   39.08847,
   37.69944,
   36.05171,
   34.18389,
   32.13822,
   29.95897,
   27.69087,
   23.06057,
   18.56189,
   16.44202,
   14.44086,
   12.5758,
   10.85882,
   9.296824,
   7.892074,
   6.642819,
   5.543937,
   4.587635,
   3.764126,
   3.062275,
   2.470181,
   2.470181};
   graph = new TGraph(54,down_fx7,down_fy7);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down7 = new TH1F("Graph_down7","Projection of downf DSCB fit",100,0.3138896,1.416708);
   Graph_down7->SetMinimum(2.223163);
   Graph_down7->SetMaximum(45.39272);
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
   
   TH1D *frame_370dfdd0__26 = new TH1D("frame_370dfdd0__26","p_T Balance",25,0,2);
   frame_370dfdd0__26->SetBinContent(1,49.71525);
   frame_370dfdd0__26->SetMaximum(49.71525);
   frame_370dfdd0__26->SetEntries(1);
   frame_370dfdd0__26->SetDirectory(0);
   frame_370dfdd0__26->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_370dfdd0__26->SetLineColor(ci);
   frame_370dfdd0__26->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_370dfdd0__26->GetXaxis()->SetLabelFont(42);
   frame_370dfdd0__26->GetXaxis()->SetTitleOffset(1);
   frame_370dfdd0__26->GetXaxis()->SetTitleFont(42);
   frame_370dfdd0__26->GetYaxis()->SetTitle("1/Events");
   frame_370dfdd0__26->GetYaxis()->SetLabelFont(42);
   frame_370dfdd0__26->GetYaxis()->SetTitleFont(42);
   frame_370dfdd0__26->GetZaxis()->SetLabelFont(42);
   frame_370dfdd0__26->GetZaxis()->SetTitleOffset(1);
   frame_370dfdd0__26->GetZaxis()->SetTitleFont(42);
   frame_370dfdd0__26->Draw("AXISSAME");
   
   TH1D *norm_d__27 = new TH1D("norm_d__27","",25,0,2);
   norm_d__27->SetBinContent(2,0.7997586);
   norm_d__27->SetBinContent(3,1.173435);
   norm_d__27->SetBinContent(4,1.69689);
   norm_d__27->SetBinContent(5,2.774444);
   norm_d__27->SetBinContent(6,3.425532);
   norm_d__27->SetBinContent(7,12.39064);
   norm_d__27->SetBinContent(8,20.17356);
   norm_d__27->SetBinContent(9,24.79045);
   norm_d__27->SetBinContent(10,36.44014);
   norm_d__27->SetBinContent(11,43.51275);
   norm_d__27->SetBinContent(12,41.5604);
   norm_d__27->SetBinContent(13,31.39878);
   norm_d__27->SetBinContent(14,18.8339);
   norm_d__27->SetBinContent(15,12.72177);
   norm_d__27->SetBinContent(16,6.239593);
   norm_d__27->SetBinContent(17,2.072464);
   norm_d__27->SetBinContent(18,0.6075258);
   norm_d__27->SetBinContent(19,0.6080944);
   norm_d__27->SetBinContent(20,0.7371762);
   norm_d__27->SetBinContent(21,0.08698372);
   norm_d__27->SetBinContent(22,0.1905579);
   norm_d__27->SetBinContent(23,0.04723104);
   norm_d__27->SetBinContent(24,0.1170706);
   norm_d__27->SetBinContent(25,0.01589001);
   norm_d__27->SetBinContent(26,0.2273996);
   norm_d__27->SetBinError(2,0.6709888);
   norm_d__27->SetBinError(3,0.4633788);
   norm_d__27->SetBinError(4,0.4815074);
   norm_d__27->SetBinError(5,0.7745744);
   norm_d__27->SetBinError(6,0.9016264);
   norm_d__27->SetBinError(7,2.228097);
   norm_d__27->SetBinError(8,2.671631);
   norm_d__27->SetBinError(9,2.838392);
   norm_d__27->SetBinError(10,3.350309);
   norm_d__27->SetBinError(11,3.835108);
   norm_d__27->SetBinError(12,3.519714);
   norm_d__27->SetBinError(13,3.06579);
   norm_d__27->SetBinError(14,2.31728);
   norm_d__27->SetBinError(15,1.741555);
   norm_d__27->SetBinError(16,1.126102);
   norm_d__27->SetBinError(17,0.7174971);
   norm_d__27->SetBinError(18,0.2276284);
   norm_d__27->SetBinError(19,0.2679814);
   norm_d__27->SetBinError(20,0.3183991);
   norm_d__27->SetBinError(21,0.08698372);
   norm_d__27->SetBinError(22,0.1321503);
   norm_d__27->SetBinError(23,0.04089921);
   norm_d__27->SetBinError(24,0.09596489);
   norm_d__27->SetBinError(25,0.01185459);
   norm_d__27->SetBinError(26,0.1559079);
   norm_d__27->SetEntries(1495);
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
   entry=leg->AddEntry("frame_x_d2_370dfdd0","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.848620 #pm 0.013849","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.195215 #pm 0.012754","");
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
   
   TH1D *frame_370dfdd0_copy__28 = new TH1D("frame_370dfdd0_copy__28","p_T Balance",25,0,2);
   frame_370dfdd0_copy__28->SetBinContent(1,49.71525);
   frame_370dfdd0_copy__28->SetMaximum(49.71525);
   frame_370dfdd0_copy__28->SetEntries(1);
   frame_370dfdd0_copy__28->SetDirectory(0);
   frame_370dfdd0_copy__28->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_370dfdd0_copy__28->SetLineColor(ci);
   frame_370dfdd0_copy__28->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_370dfdd0_copy__28->GetXaxis()->SetLabelFont(42);
   frame_370dfdd0_copy__28->GetXaxis()->SetTitleOffset(1);
   frame_370dfdd0_copy__28->GetXaxis()->SetTitleFont(42);
   frame_370dfdd0_copy__28->GetYaxis()->SetTitle("1/Events");
   frame_370dfdd0_copy__28->GetYaxis()->SetLabelFont(42);
   frame_370dfdd0_copy__28->GetYaxis()->SetTitleFont(42);
   frame_370dfdd0_copy__28->GetZaxis()->SetLabelFont(42);
   frame_370dfdd0_copy__28->GetZaxis()->SetTitleOffset(1);
   frame_370dfdd0_copy__28->GetZaxis()->SetTitleFont(42);
   frame_370dfdd0_copy__28->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-7.826558,2.25,70.43902);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_370dce70__29 = new TH1D("frame_370dce70__29","p_T Balance",25,0,2);
   frame_370dce70__29->SetBinContent(1,68.87371);
   frame_370dce70__29->SetMaximum(68.87371);
   frame_370dce70__29->SetEntries(1);
   frame_370dce70__29->SetDirectory(0);
   frame_370dce70__29->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_370dce70__29->SetLineColor(ci);
   frame_370dce70__29->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_370dce70__29->GetXaxis()->SetLabelFont(42);
   frame_370dce70__29->GetXaxis()->SetTitleOffset(1);
   frame_370dce70__29->GetXaxis()->SetTitleFont(42);
   frame_370dce70__29->GetYaxis()->SetTitle("1/Events");
   frame_370dce70__29->GetYaxis()->SetLabelFont(42);
   frame_370dce70__29->GetYaxis()->SetTitleFont(42);
   frame_370dce70__29->GetZaxis()->SetLabelFont(42);
   frame_370dce70__29->GetZaxis()->SetTitleOffset(1);
   frame_370dce70__29->GetZaxis()->SetTitleFont(42);
   frame_370dce70__29->Draw("FUNC");
   
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
   0,
   6,
   3,
   6,
   20,
   18,
   22,
   39,
   53,
   57,
   35,
   36,
   23,
   4,
   8,
   2,
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
   0.8272462,
   0,
   2.379931,
   1.632705,
   2.379931,
   4.434448,
   4.202887,
   4.654502,
   6.218102,
   7.257065,
   7.527619,
   5.887675,
   5.971996,
   4.760717,
   1.914339,
   2.768386,
   1.291815,
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
   2.299527,
   1.147874,
   3.583642,
   2.918186,
   3.583642,
   5.546519,
   5.321007,
   5.761366,
   7.298372,
   8.325916,
   8.594007,
   6.97241,
   7.055545,
   5.865235,
   3.162753,
   3.945142,
   2.63786,
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
   Graph_h_dh_data23008->SetMaximum(72.15341);
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
   
   Double_t observation_fx8[56] = {
   0.4140903,
   0.4529272,
   0.491764,
   0.5306009,
   0.5500193,
   0.5694377,
   0.5888562,
   0.6082746,
   0.627693,
   0.6471115,
   0.6665299,
   0.6859483,
   0.7053667,
   0.7247852,
   0.763622,
   0.7830405,
   0.8024589,
   0.8218773,
   0.8315865,
   0.8412958,
   0.851005,
   0.8607142,
   0.8704234,
   0.8801326,
   0.8898418,
   0.899551,
   0.9092603,
   0.9189695,
   0.9286787,
   0.9383879,
   0.9480971,
   0.9578063,
   0.9675155,
   0.9772248,
   0.986934,
   0.9966432,
   1.016062,
   1.03548,
   1.054898,
   1.074317,
   1.113154,
   1.132572,
   1.151991,
   1.171409,
   1.190827,
   1.210246,
   1.229664,
   1.249083,
   1.268501,
   1.28792,
   1.307338,
   1.326756,
   1.346175,
   1.365593,
   1.385012,
   1.385012};
   Double_t observation_fy8[56] = {
   10.23866,
   11.50123,
   13.00107,
   14.79998,
   15.83645,
   16.98088,
   18.24845,
   19.65705,
   21.22789,
   22.98628,
   24.96258,
   27.19344,
   29.72345,
   32.60726,
   39.01944,
   42.01877,
   44.75216,
   47.14036,
   48.18207,
   49.11116,
   49.92027,
   50.60294,
   51.15365,
   51.56792,
   51.84235,
   51.97468,
   51.96382,
   51.80985,
   51.51406,
   51.07886,
   50.50784,
   49.80563,
   48.97789,
   48.03125,
   46.97316,
   45.81184,
   43.21553,
   40.31905,
   37.20395,
   33.95285,
   27.35743,
   24.15391,
   21.09152,
   18.21531,
   15.55871,
   13.14374,
   10.98177,
   9.074747,
   7.416599,
   5.994921,
   4.792591,
   3.789358,
   2.963256,
   2.291823,
   1.753079,
   1.753079};
   graph = new TGraph(56,observation_fx8,observation_fy8);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation8 = new TH1F("Graph_observation8","Projection of obsf DSCB fit",100,0.3169982,1.482104);
   Graph_observation8->SetMinimum(1.577771);
   Graph_observation8->SetMaximum(56.99684);
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
   
   TH1D *frame_370dce70__30 = new TH1D("frame_370dce70__30","p_T Balance",25,0,2);
   frame_370dce70__30->SetBinContent(1,68.87371);
   frame_370dce70__30->SetMaximum(68.87371);
   frame_370dce70__30->SetEntries(1);
   frame_370dce70__30->SetDirectory(0);
   frame_370dce70__30->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_370dce70__30->SetLineColor(ci);
   frame_370dce70__30->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_370dce70__30->GetXaxis()->SetLabelFont(42);
   frame_370dce70__30->GetXaxis()->SetTitleOffset(1);
   frame_370dce70__30->GetXaxis()->SetTitleFont(42);
   frame_370dce70__30->GetYaxis()->SetTitle("1/Events");
   frame_370dce70__30->GetYaxis()->SetLabelFont(42);
   frame_370dce70__30->GetYaxis()->SetTitleFont(42);
   frame_370dce70__30->GetZaxis()->SetLabelFont(42);
   frame_370dce70__30->GetZaxis()->SetTitleOffset(1);
   frame_370dce70__30->GetZaxis()->SetTitleFont(42);
   frame_370dce70__30->Draw("AXISSAME");
   
   TH1D *norm_o__31 = new TH1D("norm_o__31","",25,0,2);
   norm_o__31->SetBinContent(2,1);
   norm_o__31->SetBinContent(4,6);
   norm_o__31->SetBinContent(5,3);
   norm_o__31->SetBinContent(6,6);
   norm_o__31->SetBinContent(7,20);
   norm_o__31->SetBinContent(8,18);
   norm_o__31->SetBinContent(9,22);
   norm_o__31->SetBinContent(10,39);
   norm_o__31->SetBinContent(11,53);
   norm_o__31->SetBinContent(12,57);
   norm_o__31->SetBinContent(13,35);
   norm_o__31->SetBinContent(14,36);
   norm_o__31->SetBinContent(15,23);
   norm_o__31->SetBinContent(16,4);
   norm_o__31->SetBinContent(17,8);
   norm_o__31->SetBinContent(18,2);
   norm_o__31->SetBinContent(19,1);
   norm_o__31->SetBinContent(20,1);
   norm_o__31->SetMinimum(0);
   norm_o__31->SetMaximum(125.4);
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
   entry=leg->AddEntry("frame_x_o2_370dce70","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.903963 #pm 0.014664","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.172137 #pm 0.013675","");
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
   
   TH1D *frame_370dce70_copy__32 = new TH1D("frame_370dce70_copy__32","p_T Balance",25,0,2);
   frame_370dce70_copy__32->SetBinContent(1,68.87371);
   frame_370dce70_copy__32->SetMaximum(68.87371);
   frame_370dce70_copy__32->SetEntries(1);
   frame_370dce70_copy__32->SetDirectory(0);
   frame_370dce70_copy__32->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_370dce70_copy__32->SetLineColor(ci);
   frame_370dce70_copy__32->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_370dce70_copy__32->GetXaxis()->SetLabelFont(42);
   frame_370dce70_copy__32->GetXaxis()->SetTitleOffset(1);
   frame_370dce70_copy__32->GetXaxis()->SetTitleFont(42);
   frame_370dce70_copy__32->GetYaxis()->SetTitle("1/Events");
   frame_370dce70_copy__32->GetYaxis()->SetLabelFont(42);
   frame_370dce70_copy__32->GetYaxis()->SetTitleFont(42);
   frame_370dce70_copy__32->GetZaxis()->SetLabelFont(42);
   frame_370dce70_copy__32->GetZaxis()->SetTitleOffset(1);
   frame_370dce70_copy__32->GetZaxis()->SetTitleFont(42);
   frame_370dce70_copy__32->Draw("sameaxis");
   
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
