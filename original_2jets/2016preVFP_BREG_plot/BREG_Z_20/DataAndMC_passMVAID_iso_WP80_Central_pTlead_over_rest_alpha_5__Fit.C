void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_5__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 17:06:57 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-20.03703,2.25,230.4259);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_46729ae0__65 = new TH1D("frame_46729ae0__65","p_T Balance",25,0,2);
   frame_46729ae0__65->SetBinContent(1,205.3796);
   frame_46729ae0__65->SetMaximum(205.3796);
   frame_46729ae0__65->SetEntries(2);
   frame_46729ae0__65->SetDirectory(0);
   frame_46729ae0__65->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_46729ae0__65->SetLineColor(ci);
   frame_46729ae0__65->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46729ae0__65->GetXaxis()->SetLabelFont(42);
   frame_46729ae0__65->GetXaxis()->SetTitleOffset(1);
   frame_46729ae0__65->GetXaxis()->SetTitleFont(42);
   frame_46729ae0__65->GetYaxis()->SetTitle("1/Events");
   frame_46729ae0__65->GetYaxis()->SetLabelFont(42);
   frame_46729ae0__65->GetYaxis()->SetTitleFont(42);
   frame_46729ae0__65->GetZaxis()->SetLabelFont(42);
   frame_46729ae0__65->GetZaxis()->SetTitleOffset(1);
   frame_46729ae0__65->GetZaxis()->SetTitleFont(42);
   frame_46729ae0__65->Draw("FUNC");
   
   Double_t h_dh_central2_fx3017[25] = {
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
   Double_t h_dh_central2_fy3017[25] = {
   0,
   0,
   0.9815168,
   10.42643,
   31.53774,
   58.83274,
   107.7442,
   146.0744,
   175.3353,
   185.016,
   165.1146,
   153.99,
   119.6177,
   98.90621,
   78.37672,
   50.29442,
   34.90881,
   19.84493,
   12.96738,
   5.405715,
   2.92148,
   1.110621,
   2.068689,
   0.583033,
   0.6225277};
   Double_t h_dh_central2_felx3017[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_central2_fely3017[25] = {
   0,
   0,
   0.6943068,
   2.311117,
   3.701931,
   5.205994,
   7.338397,
   8.697425,
   9.397729,
   9.85118,
   9.174858,
   8.942608,
   7.811628,
   6.887013,
   6.027073,
   4.846171,
   3.820126,
   2.687979,
   2.093776,
   1.202421,
   1.006895,
   0.5294133,
   0.8315247,
   0.253001,
   0.4487874};
   Double_t h_dh_central2_fehx3017[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_central2_fehy3017[25] = {
   0,
   0,
   0.6943068,
   2.311117,
   3.701931,
   5.205994,
   7.338397,
   8.697425,
   9.397729,
   9.85118,
   9.174858,
   8.942608,
   7.811628,
   6.887013,
   6.027073,
   4.846171,
   3.820126,
   2.687979,
   2.093776,
   1.202421,
   1.006895,
   0.5294133,
   0.8315247,
   0.253001,
   0.4487874};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3017,h_dh_central2_fy3017,h_dh_central2_felx3017,h_dh_central2_fehx3017,h_dh_central2_fely3017,h_dh_central2_fehy3017);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23017 = new TH1F("Graph_h_dh_central23017","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23017->SetMinimum(0);
   Graph_h_dh_central23017->SetMaximum(214.3539);
   Graph_h_dh_central23017->SetDirectory(0);
   Graph_h_dh_central23017->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_central23017->SetLineColor(ci);
   Graph_h_dh_central23017->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_central23017->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_central23017->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_central23017->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_central23017->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_central23017->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_central23017->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_central23017->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_central23017);
   
   grae->Draw("p");
   
   Double_t Central_fx17[58] = {
   0.05471224,
   0.1126966,
   0.1706809,
   0.1996731,
   0.2286652,
   0.2576574,
   0.2866495,
   0.3156417,
   0.3446339,
   0.373626,
   0.4026182,
   0.4316103,
   0.4606025,
   0.4895947,
   0.5185868,
   0.5765712,
   0.6055633,
   0.6345555,
   0.6490516,
   0.6635476,
   0.6780437,
   0.6925398,
   0.7070359,
   0.721532,
   0.736028,
   0.7505241,
   0.7650202,
   0.7795163,
   0.7940124,
   0.8085084,
   0.8230045,
   0.8375006,
   0.8519967,
   0.8664928,
   0.8809889,
   0.8954849,
   0.909981,
   0.9244771,
   0.9534693,
   0.9824614,
   1.011454,
   1.02595,
   1.040446,
   1.054942,
   1.069438,
   1.09843,
   1.127422,
   1.156414,
   1.185407,
   1.214399,
   1.243391,
   1.272383,
   1.301375,
   1.330367,
   1.388352,
   1.446336,
   1.50432,
   1.50432};
   Double_t Central_fy17[58] = {
   0.7252172,
   1.692033,
   3.698917,
   5.32671,
   7.537219,
   10.47927,
   14.31589,
   19.21647,
   25.34524,
   32.84634,
   41.82589,
   52.33245,
   64.33757,
   77.71877,
   92.24755,
   123.2866,
   138.8186,
   153.5845,
   160.4853,
   166.9609,
   172.9364,
   178.3404,
   183.1071,
   187.177,
   190.4986,
   193.0292,
   194.7359,
   195.5965,
   195.5996,
   194.7452,
   193.0445,
   190.5198,
   187.2039,
   183.1392,
   178.3774,
   172.9777,
   167.0061,
   160.5339,
   146.3898,
   131.1664,
   115.5545,
   108.2956,
   101.5979,
   95.41008,
   89.68624,
   79.47021,
   70.66825,
   63.05186,
   56.43446,
   50.66286,
   45.61059,
   41.1727,
   37.26167,
   33.8042,
   28.01277,
   23.41017,
   19.7152,
   19.7152};
   TGraph *graph = new TGraph(58,Central_fx17,Central_fy17);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central17 = new TH1F("Graph_Central17","Projection of centralf DSCB fit",100,0,1.649281);
   Graph_Central17->SetMinimum(0.6526955);
   Graph_Central17->SetMaximum(215.087);
   Graph_Central17->SetDirectory(0);
   Graph_Central17->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Central17->SetLineColor(ci);
   Graph_Central17->GetXaxis()->SetLabelFont(42);
   Graph_Central17->GetXaxis()->SetTitleOffset(1);
   Graph_Central17->GetXaxis()->SetTitleFont(42);
   Graph_Central17->GetYaxis()->SetLabelFont(42);
   Graph_Central17->GetYaxis()->SetTitleFont(42);
   Graph_Central17->GetZaxis()->SetLabelFont(42);
   Graph_Central17->GetZaxis()->SetTitleOffset(1);
   Graph_Central17->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Central17);
   
   graph->Draw("l");
   
   TH1D *frame_46729ae0__66 = new TH1D("frame_46729ae0__66","p_T Balance",25,0,2);
   frame_46729ae0__66->SetBinContent(1,205.3796);
   frame_46729ae0__66->SetMaximum(205.3796);
   frame_46729ae0__66->SetEntries(2);
   frame_46729ae0__66->SetDirectory(0);
   frame_46729ae0__66->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46729ae0__66->SetLineColor(ci);
   frame_46729ae0__66->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46729ae0__66->GetXaxis()->SetLabelFont(42);
   frame_46729ae0__66->GetXaxis()->SetTitleOffset(1);
   frame_46729ae0__66->GetXaxis()->SetTitleFont(42);
   frame_46729ae0__66->GetYaxis()->SetTitle("1/Events");
   frame_46729ae0__66->GetYaxis()->SetLabelFont(42);
   frame_46729ae0__66->GetYaxis()->SetTitleFont(42);
   frame_46729ae0__66->GetZaxis()->SetLabelFont(42);
   frame_46729ae0__66->GetZaxis()->SetTitleOffset(1);
   frame_46729ae0__66->GetZaxis()->SetTitleFont(42);
   frame_46729ae0__66->Draw("AXISSAME");
   
   TH1D *norm_c__67 = new TH1D("norm_c__67","",25,0,2);
   norm_c__67->SetBinContent(3,0.9815168);
   norm_c__67->SetBinContent(4,10.42643);
   norm_c__67->SetBinContent(5,31.53774);
   norm_c__67->SetBinContent(6,58.83274);
   norm_c__67->SetBinContent(7,107.7442);
   norm_c__67->SetBinContent(8,146.0744);
   norm_c__67->SetBinContent(9,175.3353);
   norm_c__67->SetBinContent(10,185.016);
   norm_c__67->SetBinContent(11,165.1146);
   norm_c__67->SetBinContent(12,153.99);
   norm_c__67->SetBinContent(13,119.6177);
   norm_c__67->SetBinContent(14,98.90621);
   norm_c__67->SetBinContent(15,78.37672);
   norm_c__67->SetBinContent(16,50.29442);
   norm_c__67->SetBinContent(17,34.90881);
   norm_c__67->SetBinContent(18,19.84493);
   norm_c__67->SetBinContent(19,12.96738);
   norm_c__67->SetBinContent(20,5.405715);
   norm_c__67->SetBinContent(21,2.92148);
   norm_c__67->SetBinContent(22,1.110621);
   norm_c__67->SetBinContent(23,2.068689);
   norm_c__67->SetBinContent(24,0.583033);
   norm_c__67->SetBinContent(25,0.6225276);
   norm_c__67->SetBinContent(26,0.9699907);
   norm_c__67->SetBinError(3,0.6943068);
   norm_c__67->SetBinError(4,2.311117);
   norm_c__67->SetBinError(5,3.701931);
   norm_c__67->SetBinError(6,5.205994);
   norm_c__67->SetBinError(7,7.338397);
   norm_c__67->SetBinError(8,8.697425);
   norm_c__67->SetBinError(9,9.397729);
   norm_c__67->SetBinError(10,9.85118);
   norm_c__67->SetBinError(11,9.174858);
   norm_c__67->SetBinError(12,8.942608);
   norm_c__67->SetBinError(13,7.811628);
   norm_c__67->SetBinError(14,6.887013);
   norm_c__67->SetBinError(15,6.027073);
   norm_c__67->SetBinError(16,4.846171);
   norm_c__67->SetBinError(17,3.820126);
   norm_c__67->SetBinError(18,2.687979);
   norm_c__67->SetBinError(19,2.093776);
   norm_c__67->SetBinError(20,1.202421);
   norm_c__67->SetBinError(21,1.006895);
   norm_c__67->SetBinError(22,0.5294133);
   norm_c__67->SetBinError(23,0.8315247);
   norm_c__67->SetBinError(24,0.253001);
   norm_c__67->SetBinError(25,0.4487874);
   norm_c__67->SetBinError(26,0.2416227);
   norm_c__67->SetEntries(5477);
   norm_c__67->SetStats(0);

   ci = 1343;
   color = new TColor(ci, 0.3, 0.3, 0.3, " ", 0.6);
   norm_c__67->SetFillColor(ci);
   norm_c__67->SetFillStyle(3144);
   norm_c__67->SetLineColor(2);
   norm_c__67->SetLineWidth(2);
   norm_c__67->GetXaxis()->SetRange(1,25);
   norm_c__67->GetXaxis()->SetLabelFont(42);
   norm_c__67->GetXaxis()->SetLabelSize(0.04);
   norm_c__67->GetXaxis()->SetTitleOffset(1);
   norm_c__67->GetXaxis()->SetTitleFont(42);
   norm_c__67->GetYaxis()->SetLabelFont(42);
   norm_c__67->GetYaxis()->SetTitleFont(42);
   norm_c__67->GetZaxis()->SetLabelFont(42);
   norm_c__67->GetZaxis()->SetTitleOffset(1);
   norm_c__67->GetZaxis()->SetTitleFont(42);
   norm_c__67->Draw("e1 same");
   
   TLegend *leg = new TLegend(0.65,0.5,0.93,0.87,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.03);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("norm_c","Central","lpf");

   ci = 1343;
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
   entry=leg->AddEntry("frame_x_c2_46729ae0","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.773209 #pm 0.011606","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.209049 #pm 0.008482","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.756000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_46729ae0_copy__68 = new TH1D("frame_46729ae0_copy__68","p_T Balance",25,0,2);
   frame_46729ae0_copy__68->SetBinContent(1,205.3796);
   frame_46729ae0_copy__68->SetMaximum(205.3796);
   frame_46729ae0_copy__68->SetEntries(2);
   frame_46729ae0_copy__68->SetDirectory(0);
   frame_46729ae0_copy__68->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46729ae0_copy__68->SetLineColor(ci);
   frame_46729ae0_copy__68->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46729ae0_copy__68->GetXaxis()->SetLabelFont(42);
   frame_46729ae0_copy__68->GetXaxis()->SetTitleOffset(1);
   frame_46729ae0_copy__68->GetXaxis()->SetTitleFont(42);
   frame_46729ae0_copy__68->GetYaxis()->SetTitle("1/Events");
   frame_46729ae0_copy__68->GetYaxis()->SetLabelFont(42);
   frame_46729ae0_copy__68->GetYaxis()->SetTitleFont(42);
   frame_46729ae0_copy__68->GetZaxis()->SetLabelFont(42);
   frame_46729ae0_copy__68->GetZaxis()->SetTitleOffset(1);
   frame_46729ae0_copy__68->GetZaxis()->SetTitleFont(42);
   frame_46729ae0_copy__68->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-19.92027,2.25,229.0831);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_466dcb40__69 = new TH1D("frame_466dcb40__69","p_T Balance",25,0,2);
   frame_466dcb40__69->SetBinContent(1,204.1827);
   frame_466dcb40__69->SetMaximum(204.1827);
   frame_466dcb40__69->SetEntries(2);
   frame_466dcb40__69->SetDirectory(0);
   frame_466dcb40__69->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_466dcb40__69->SetLineColor(ci);
   frame_466dcb40__69->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_466dcb40__69->GetXaxis()->SetLabelFont(42);
   frame_466dcb40__69->GetXaxis()->SetTitleOffset(1);
   frame_466dcb40__69->GetXaxis()->SetTitleFont(42);
   frame_466dcb40__69->GetYaxis()->SetTitle("1/Events");
   frame_466dcb40__69->GetYaxis()->SetLabelFont(42);
   frame_466dcb40__69->GetYaxis()->SetTitleFont(42);
   frame_466dcb40__69->GetZaxis()->SetLabelFont(42);
   frame_466dcb40__69->GetZaxis()->SetTitleOffset(1);
   frame_466dcb40__69->GetZaxis()->SetTitleFont(42);
   frame_466dcb40__69->Draw("FUNC");
   
   Double_t h_dh_up2_fx3018[25] = {
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
   Double_t h_dh_up2_fy3018[25] = {
   0,
   0,
   0,
   10.55182,
   30.72491,
   53.85523,
   96.8673,
   134.8574,
   175.0626,
   182.3125,
   176.0004,
   154.2601,
   136.5275,
   108.5504,
   88.69563,
   52.24513,
   42.44167,
   21.71568,
   13.48857,
   4.691601,
   3.040556,
   1.862257,
   0.7694706,
   0.6777897,
   0.3640619};
   Double_t h_dh_up2_felx3018[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_up2_fely3018[25] = {
   0,
   0,
   0,
   2.637091,
   3.658789,
   5.037073,
   6.974321,
   8.516611,
   9.483324,
   9.670204,
   9.600053,
   8.997975,
   8.349246,
   7.50538,
   6.480965,
   4.925239,
   4.506051,
   2.872793,
   2.13671,
   1.145499,
   0.9690405,
   0.7782666,
   0.3583575,
   0.2616095,
   0.1973486};
   Double_t h_dh_up2_fehx3018[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_up2_fehy3018[25] = {
   0,
   0,
   0,
   2.637091,
   3.658789,
   5.037073,
   6.974321,
   8.516611,
   9.483324,
   9.670204,
   9.600053,
   8.997975,
   8.349246,
   7.50538,
   6.480965,
   4.925239,
   4.506051,
   2.872793,
   2.13671,
   1.145499,
   0.9690405,
   0.7782666,
   0.3583575,
   0.2616095,
   0.1973486};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3018,h_dh_up2_fy3018,h_dh_up2_felx3018,h_dh_up2_fehx3018,h_dh_up2_fely3018,h_dh_up2_fehy3018);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23018 = new TH1F("Graph_h_dh_up23018","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23018->SetMinimum(0);
   Graph_h_dh_up23018->SetMaximum(211.181);
   Graph_h_dh_up23018->SetDirectory(0);
   Graph_h_dh_up23018->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_up23018->SetLineColor(ci);
   Graph_h_dh_up23018->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_up23018->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_up23018->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_up23018->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_up23018->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_up23018->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_up23018->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_up23018->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_up23018);
   
   grae->Draw("p");
   
   Double_t up_fx18[60] = {
   0.0484396,
   0.1084396,
   0.1684396,
   0.1984396,
   0.2284396,
   0.2584396,
   0.2884396,
   0.3184396,
   0.3484396,
   0.3784396,
   0.4084396,
   0.4384396,
   0.4684396,
   0.4984396,
   0.5284396,
   0.5584396,
   0.5884396,
   0.6184396,
   0.6484396,
   0.6784396,
   0.6934396,
   0.7084396,
   0.7234396,
   0.7384396,
   0.7534396,
   0.7684396,
   0.7834396,
   0.7984396,
   0.8134396,
   0.8284396,
   0.8434396,
   0.8584396,
   0.8734396,
   0.8884396,
   0.9034396,
   0.9184396,
   0.9334396,
   0.9484396,
   0.9634396,
   0.9784396,
   1.00844,
   1.06844,
   1.09844,
   1.11344,
   1.12844,
   1.14344,
   1.15844,
   1.17344,
   1.18844,
   1.21844,
   1.24844,
   1.27844,
   1.30844,
   1.33844,
   1.36844,
   1.39844,
   1.42844,
   1.48844,
   1.54844,
   1.54844};
   Double_t up_fy18[60] = {
   0.8073789,
   1.833008,
   3.894371,
   5.536923,
   7.742766,
   10.64928,
   14.40591,
   19.16717,
   25.08253,
   32.28356,
   40.86842,
   50.88512,
   62.31466,
   75.05612,
   88.9157,
   103.6018,
   118.7278,
   133.8241,
   148.3585,
   161.766,
   167.8701,
   173.4836,
   178.5429,
   182.9895,
   186.7706,
   189.8411,
   192.1635,
   193.7094,
   194.4598,
   194.4052,
   193.5464,
   191.894,
   189.4684,
   186.2993,
   182.4253,
   177.8926,
   172.7546,
   167.0709,
   160.9055,
   154.3264,
   140.209,
   110.1126,
   95.18368,
   87.97433,
   81.33251,
   75.30582,
   69.82715,
   64.83778,
   60.28618,
   52.32052,
   45.6281,
   39.97233,
   35.16635,
   31.06143,
   27.53837,
   24.50093,
   21.87096,
   17.58934,
   14.30605,
   14.30605};
   graph = new TGraph(60,up_fx18,up_fy18);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up18 = new TH1F("Graph_up18","Projection of upf DSCB fit",100,0,1.69844);
   Graph_up18->SetMinimum(0.726641);
   Graph_up18->SetMaximum(213.825);
   Graph_up18->SetDirectory(0);
   Graph_up18->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_up18->SetLineColor(ci);
   Graph_up18->GetXaxis()->SetLabelFont(42);
   Graph_up18->GetXaxis()->SetTitleOffset(1);
   Graph_up18->GetXaxis()->SetTitleFont(42);
   Graph_up18->GetYaxis()->SetLabelFont(42);
   Graph_up18->GetYaxis()->SetTitleFont(42);
   Graph_up18->GetZaxis()->SetLabelFont(42);
   Graph_up18->GetZaxis()->SetTitleOffset(1);
   Graph_up18->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_up18);
   
   graph->Draw("l");
   
   TH1D *frame_466dcb40__70 = new TH1D("frame_466dcb40__70","p_T Balance",25,0,2);
   frame_466dcb40__70->SetBinContent(1,204.1827);
   frame_466dcb40__70->SetMaximum(204.1827);
   frame_466dcb40__70->SetEntries(2);
   frame_466dcb40__70->SetDirectory(0);
   frame_466dcb40__70->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_466dcb40__70->SetLineColor(ci);
   frame_466dcb40__70->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_466dcb40__70->GetXaxis()->SetLabelFont(42);
   frame_466dcb40__70->GetXaxis()->SetTitleOffset(1);
   frame_466dcb40__70->GetXaxis()->SetTitleFont(42);
   frame_466dcb40__70->GetYaxis()->SetTitle("1/Events");
   frame_466dcb40__70->GetYaxis()->SetLabelFont(42);
   frame_466dcb40__70->GetYaxis()->SetTitleFont(42);
   frame_466dcb40__70->GetZaxis()->SetLabelFont(42);
   frame_466dcb40__70->GetZaxis()->SetTitleOffset(1);
   frame_466dcb40__70->GetZaxis()->SetTitleFont(42);
   frame_466dcb40__70->Draw("AXISSAME");
   
   TH1D *norm_u__71 = new TH1D("norm_u__71","",25,0,2);
   norm_u__71->SetBinContent(4,10.55182);
   norm_u__71->SetBinContent(5,30.72491);
   norm_u__71->SetBinContent(6,53.85523);
   norm_u__71->SetBinContent(7,96.86731);
   norm_u__71->SetBinContent(8,134.8574);
   norm_u__71->SetBinContent(9,175.0626);
   norm_u__71->SetBinContent(10,182.3125);
   norm_u__71->SetBinContent(11,176.0004);
   norm_u__71->SetBinContent(12,154.2601);
   norm_u__71->SetBinContent(13,136.5275);
   norm_u__71->SetBinContent(14,108.5504);
   norm_u__71->SetBinContent(15,88.69563);
   norm_u__71->SetBinContent(16,52.24513);
   norm_u__71->SetBinContent(17,42.44167);
   norm_u__71->SetBinContent(18,21.71568);
   norm_u__71->SetBinContent(19,13.48857);
   norm_u__71->SetBinContent(20,4.691601);
   norm_u__71->SetBinContent(21,3.040556);
   norm_u__71->SetBinContent(22,1.862257);
   norm_u__71->SetBinContent(23,0.7694706);
   norm_u__71->SetBinContent(24,0.6777897);
   norm_u__71->SetBinContent(25,0.3640619);
   norm_u__71->SetBinContent(26,1.150858);
   norm_u__71->SetBinError(4,2.637091);
   norm_u__71->SetBinError(5,3.658789);
   norm_u__71->SetBinError(6,5.037073);
   norm_u__71->SetBinError(7,6.974321);
   norm_u__71->SetBinError(8,8.516611);
   norm_u__71->SetBinError(9,9.483324);
   norm_u__71->SetBinError(10,9.670204);
   norm_u__71->SetBinError(11,9.600053);
   norm_u__71->SetBinError(12,8.997975);
   norm_u__71->SetBinError(13,8.349246);
   norm_u__71->SetBinError(14,7.50538);
   norm_u__71->SetBinError(15,6.480965);
   norm_u__71->SetBinError(16,4.925239);
   norm_u__71->SetBinError(17,4.506051);
   norm_u__71->SetBinError(18,2.872793);
   norm_u__71->SetBinError(19,2.13671);
   norm_u__71->SetBinError(20,1.145499);
   norm_u__71->SetBinError(21,0.9690405);
   norm_u__71->SetBinError(22,0.7782666);
   norm_u__71->SetBinError(23,0.3583575);
   norm_u__71->SetBinError(24,0.2616095);
   norm_u__71->SetBinError(25,0.1973486);
   norm_u__71->SetBinError(26,0.2997581);
   norm_u__71->SetEntries(5448);
   norm_u__71->SetStats(0);
   norm_u__71->SetLineColor(4);
   norm_u__71->SetLineWidth(2);
   norm_u__71->GetXaxis()->SetLabelFont(42);
   norm_u__71->GetXaxis()->SetTitleOffset(1);
   norm_u__71->GetXaxis()->SetTitleFont(42);
   norm_u__71->GetYaxis()->SetLabelFont(42);
   norm_u__71->GetYaxis()->SetTitleFont(42);
   norm_u__71->GetZaxis()->SetLabelFont(42);
   norm_u__71->GetZaxis()->SetTitleOffset(1);
   norm_u__71->GetZaxis()->SetTitleFont(42);
   norm_u__71->Draw("e1 same");
   
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
   entry=leg->AddEntry("frame_x_u2_466dcb40","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.843119 #pm 0.006737","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.254633 #pm 0.005086","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.532000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_466dcb40_copy__72 = new TH1D("frame_466dcb40_copy__72","p_T Balance",25,0,2);
   frame_466dcb40_copy__72->SetBinContent(1,204.1827);
   frame_466dcb40_copy__72->SetMaximum(204.1827);
   frame_466dcb40_copy__72->SetEntries(2);
   frame_466dcb40_copy__72->SetDirectory(0);
   frame_466dcb40_copy__72->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_466dcb40_copy__72->SetLineColor(ci);
   frame_466dcb40_copy__72->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_466dcb40_copy__72->GetXaxis()->SetLabelFont(42);
   frame_466dcb40_copy__72->GetXaxis()->SetTitleOffset(1);
   frame_466dcb40_copy__72->GetXaxis()->SetTitleFont(42);
   frame_466dcb40_copy__72->GetYaxis()->SetTitle("1/Events");
   frame_466dcb40_copy__72->GetYaxis()->SetLabelFont(42);
   frame_466dcb40_copy__72->GetYaxis()->SetTitleFont(42);
   frame_466dcb40_copy__72->GetZaxis()->SetLabelFont(42);
   frame_466dcb40_copy__72->GetZaxis()->SetTitleOffset(1);
   frame_466dcb40_copy__72->GetZaxis()->SetTitleFont(42);
   frame_466dcb40_copy__72->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-34.18582,2.25,211.1335);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_4673c3b0__73 = new TH1D("frame_4673c3b0__73","p_T Balance",25,0,2);
   frame_4673c3b0__73->SetBinContent(1,206.2271);
   frame_4673c3b0__73->SetMinimum(-9.653883);
   frame_4673c3b0__73->SetMaximum(206.2271);
   frame_4673c3b0__73->SetEntries(2);
   frame_4673c3b0__73->SetDirectory(0);
   frame_4673c3b0__73->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4673c3b0__73->SetLineColor(ci);
   frame_4673c3b0__73->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4673c3b0__73->GetXaxis()->SetLabelFont(42);
   frame_4673c3b0__73->GetXaxis()->SetTitleOffset(1);
   frame_4673c3b0__73->GetXaxis()->SetTitleFont(42);
   frame_4673c3b0__73->GetYaxis()->SetTitle("1/Events");
   frame_4673c3b0__73->GetYaxis()->SetLabelFont(42);
   frame_4673c3b0__73->GetYaxis()->SetTitleFont(42);
   frame_4673c3b0__73->GetZaxis()->SetLabelFont(42);
   frame_4673c3b0__73->GetZaxis()->SetTitleOffset(1);
   frame_4673c3b0__73->GetZaxis()->SetTitleFont(42);
   frame_4673c3b0__73->Draw("FUNC");
   
   Double_t h_dh_down2_fx3019[25] = {
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
   Double_t h_dh_down2_fy3019[25] = {
   0,
   0,
   0.03282912,
   11.90837,
   36.1123,
   68.6638,
   112.5145,
   143.9903,
   180.2392,
   183.4855,
   164.1263,
   138.2108,
   115.9261,
   93.10239,
   65.91018,
   53.9527,
   31.34941,
   15.82674,
   11.88899,
   4.929214,
   1.878242,
   1.921009,
   1.813977,
   1.40017,
   0.3085299};
   Double_t h_dh_down2_felx3019[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_down2_fely3019[25] = {
   0,
   0,
   0.03282912,
   2.424308,
   3.919359,
   5.730011,
   7.433057,
   8.496925,
   9.505186,
   9.592165,
   9.153693,
   8.391834,
   7.588585,
   6.581009,
   5.45057,
   4.948072,
   3.522836,
   2.294861,
   2.011053,
   1.146911,
   0.7485751,
   0.7002772,
   0.7927341,
   0.620636,
   0.1184155};
   Double_t h_dh_down2_fehx3019[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_down2_fehy3019[25] = {
   0,
   0,
   0.03282912,
   2.424308,
   3.919359,
   5.730011,
   7.433057,
   8.496925,
   9.505186,
   9.592165,
   9.153693,
   8.391834,
   7.588585,
   6.581009,
   5.45057,
   4.948072,
   3.522836,
   2.294861,
   2.011053,
   1.146911,
   0.7485751,
   0.7002772,
   0.7927341,
   0.620636,
   0.1184155};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3019,h_dh_down2_fy3019,h_dh_down2_felx3019,h_dh_down2_fehx3019,h_dh_down2_fely3019,h_dh_down2_fehy3019);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23019 = new TH1F("Graph_h_dh_down23019","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23019->SetMinimum(-19.30777);
   Graph_h_dh_down23019->SetMaximum(212.3854);
   Graph_h_dh_down23019->SetDirectory(0);
   Graph_h_dh_down23019->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_down23019->SetLineColor(ci);
   Graph_h_dh_down23019->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_down23019->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_down23019->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_down23019->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_down23019->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_down23019->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_down23019->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_down23019->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_down23019);
   
   grae->Draw("p");
   
   Double_t down_fx19[62] = {
   -0.003757647,
   0.05624235,
   0.1162424,
   0.1462424,
   0.1762424,
   0.2062424,
   0.2362424,
   0.2662424,
   0.2962424,
   0.3262424,
   0.3412424,
   0.3562424,
   0.3712424,
   0.3862424,
   0.4012424,
   0.4162424,
   0.4312424,
   0.4462424,
   0.4612424,
   0.4762424,
   0.5062424,
   0.5362424,
   0.5962424,
   0.6112424,
   0.6262424,
   0.6412424,
   0.6562424,
   0.6712424,
   0.6862424,
   0.7012424,
   0.7162424,
   0.7312424,
   0.7462424,
   0.7612424,
   0.7762424,
   0.7912424,
   0.8062424,
   0.8212424,
   0.8362424,
   0.8512424,
   0.8662424,
   0.8812424,
   0.8962424,
   0.9562424,
   0.9712424,
   0.9862424,
   1.001242,
   1.016242,
   1.046242,
   1.076242,
   1.106242,
   1.136242,
   1.166242,
   1.196242,
   1.226242,
   1.256242,
   1.286242,
   1.316242,
   1.376242,
   1.436242,
   1.496242,
   1.496242};
   Double_t down_fy19[62] = {
   0,
   0.6073816,
   1.564459,
   2.432482,
   3.703035,
   5.519359,
   8.054566,
   11.50849,
   16.09969,
   22.05155,
   25.60404,
   29.57219,
   33.97537,
   38.8285,
   44.14106,
   49.91608,
   56.14924,
   62.82797,
   69.93069,
   77.42627,
   93.42139,
   110.3639,
   144.5628,
   152.6259,
   160.2897,
   167.4513,
   174.0112,
   179.8752,
   184.9573,
   189.1808,
   192.4812,
   194.8074,
   196.1228,
   196.4068,
   195.6548,
   193.8788,
   191.1066,
   187.3816,
   182.7611,
   177.3153,
   171.1253,
   164.2813,
   156.88,
   124.4387,
   117.0662,
   110.2316,
   103.8886,
   97.9954,
   87.41089,
   78.21761,
   70.20178,
   63.18698,
   57.02688,
   51.5995,
   46.8027,
   42.55057,
   38.77056,
   35.40112,
   29.69214,
   25.08898,
   21.34427,
   21.34427};
   graph = new TGraph(62,down_fx19,down_fy19);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down19 = new TH1F("Graph_down19","Projection of downf DSCB fit",100,-0.1537576,1.646242);
   Graph_down19->SetMinimum(0);
   Graph_down19->SetMaximum(216.0475);
   Graph_down19->SetDirectory(0);
   Graph_down19->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_down19->SetLineColor(ci);
   Graph_down19->GetXaxis()->SetLabelFont(42);
   Graph_down19->GetXaxis()->SetTitleOffset(1);
   Graph_down19->GetXaxis()->SetTitleFont(42);
   Graph_down19->GetYaxis()->SetLabelFont(42);
   Graph_down19->GetYaxis()->SetTitleFont(42);
   Graph_down19->GetZaxis()->SetLabelFont(42);
   Graph_down19->GetZaxis()->SetTitleOffset(1);
   Graph_down19->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_down19);
   
   graph->Draw("l");
   
   TH1D *frame_4673c3b0__74 = new TH1D("frame_4673c3b0__74","p_T Balance",25,0,2);
   frame_4673c3b0__74->SetBinContent(1,206.2271);
   frame_4673c3b0__74->SetMinimum(-9.653883);
   frame_4673c3b0__74->SetMaximum(206.2271);
   frame_4673c3b0__74->SetEntries(2);
   frame_4673c3b0__74->SetDirectory(0);
   frame_4673c3b0__74->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4673c3b0__74->SetLineColor(ci);
   frame_4673c3b0__74->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4673c3b0__74->GetXaxis()->SetLabelFont(42);
   frame_4673c3b0__74->GetXaxis()->SetTitleOffset(1);
   frame_4673c3b0__74->GetXaxis()->SetTitleFont(42);
   frame_4673c3b0__74->GetYaxis()->SetTitle("1/Events");
   frame_4673c3b0__74->GetYaxis()->SetLabelFont(42);
   frame_4673c3b0__74->GetYaxis()->SetTitleFont(42);
   frame_4673c3b0__74->GetZaxis()->SetLabelFont(42);
   frame_4673c3b0__74->GetZaxis()->SetTitleOffset(1);
   frame_4673c3b0__74->GetZaxis()->SetTitleFont(42);
   frame_4673c3b0__74->Draw("AXISSAME");
   
   TH1D *norm_d__75 = new TH1D("norm_d__75","",25,0,2);
   norm_d__75->SetBinContent(3,0.03282912);
   norm_d__75->SetBinContent(4,11.90837);
   norm_d__75->SetBinContent(5,36.1123);
   norm_d__75->SetBinContent(6,68.66379);
   norm_d__75->SetBinContent(7,112.5144);
   norm_d__75->SetBinContent(8,143.9903);
   norm_d__75->SetBinContent(9,180.2392);
   norm_d__75->SetBinContent(10,183.4855);
   norm_d__75->SetBinContent(11,164.1263);
   norm_d__75->SetBinContent(12,138.2108);
   norm_d__75->SetBinContent(13,115.9261);
   norm_d__75->SetBinContent(14,93.10239);
   norm_d__75->SetBinContent(15,65.91018);
   norm_d__75->SetBinContent(16,53.9527);
   norm_d__75->SetBinContent(17,31.34941);
   norm_d__75->SetBinContent(18,15.82674);
   norm_d__75->SetBinContent(19,11.88899);
   norm_d__75->SetBinContent(20,4.929215);
   norm_d__75->SetBinContent(21,1.878243);
   norm_d__75->SetBinContent(22,1.921009);
   norm_d__75->SetBinContent(23,1.813977);
   norm_d__75->SetBinContent(24,1.40017);
   norm_d__75->SetBinContent(25,0.3085299);
   norm_d__75->SetBinContent(26,1.167541);
   norm_d__75->SetBinError(3,0.03282912);
   norm_d__75->SetBinError(4,2.424308);
   norm_d__75->SetBinError(5,3.919359);
   norm_d__75->SetBinError(6,5.730011);
   norm_d__75->SetBinError(7,7.433057);
   norm_d__75->SetBinError(8,8.496925);
   norm_d__75->SetBinError(9,9.505186);
   norm_d__75->SetBinError(10,9.592165);
   norm_d__75->SetBinError(11,9.153693);
   norm_d__75->SetBinError(12,8.391834);
   norm_d__75->SetBinError(13,7.588585);
   norm_d__75->SetBinError(14,6.581009);
   norm_d__75->SetBinError(15,5.45057);
   norm_d__75->SetBinError(16,4.948072);
   norm_d__75->SetBinError(17,3.522836);
   norm_d__75->SetBinError(18,2.294861);
   norm_d__75->SetBinError(19,2.011053);
   norm_d__75->SetBinError(20,1.146911);
   norm_d__75->SetBinError(21,0.7485751);
   norm_d__75->SetBinError(22,0.7002772);
   norm_d__75->SetBinError(23,0.7927341);
   norm_d__75->SetBinError(24,0.620636);
   norm_d__75->SetBinError(25,0.1184155);
   norm_d__75->SetBinError(26,0.3017961);
   norm_d__75->SetEntries(5533);
   norm_d__75->SetStats(0);
   norm_d__75->SetLineColor(7);
   norm_d__75->SetLineWidth(2);
   norm_d__75->GetXaxis()->SetLabelFont(42);
   norm_d__75->GetXaxis()->SetTitleOffset(1);
   norm_d__75->GetXaxis()->SetTitleFont(42);
   norm_d__75->GetYaxis()->SetLabelFont(42);
   norm_d__75->GetYaxis()->SetTitleFont(42);
   norm_d__75->GetZaxis()->SetLabelFont(42);
   norm_d__75->GetZaxis()->SetTitleOffset(1);
   norm_d__75->GetZaxis()->SetTitleFont(42);
   norm_d__75->Draw("same e1");
   
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
   entry=leg->AddEntry("frame_x_d2_4673c3b0","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.757842 #pm 0.009071","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.206373 #pm 0.006824","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.628000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_4673c3b0_copy__76 = new TH1D("frame_4673c3b0_copy__76","p_T Balance",25,0,2);
   frame_4673c3b0_copy__76->SetBinContent(1,206.2271);
   frame_4673c3b0_copy__76->SetMinimum(-9.653883);
   frame_4673c3b0_copy__76->SetMaximum(206.2271);
   frame_4673c3b0_copy__76->SetEntries(2);
   frame_4673c3b0_copy__76->SetDirectory(0);
   frame_4673c3b0_copy__76->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4673c3b0_copy__76->SetLineColor(ci);
   frame_4673c3b0_copy__76->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4673c3b0_copy__76->GetXaxis()->SetLabelFont(42);
   frame_4673c3b0_copy__76->GetXaxis()->SetTitleOffset(1);
   frame_4673c3b0_copy__76->GetXaxis()->SetTitleFont(42);
   frame_4673c3b0_copy__76->GetYaxis()->SetTitle("1/Events");
   frame_4673c3b0_copy__76->GetYaxis()->SetLabelFont(42);
   frame_4673c3b0_copy__76->GetYaxis()->SetTitleFont(42);
   frame_4673c3b0_copy__76->GetZaxis()->SetLabelFont(42);
   frame_4673c3b0_copy__76->GetZaxis()->SetTitleOffset(1);
   frame_4673c3b0_copy__76->GetZaxis()->SetTitleFont(42);
   frame_4673c3b0_copy__76->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-22.68465,2.25,204.1619);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_4672afc0__77 = new TH1D("frame_4672afc0__77","p_T Balance",25,0,2);
   frame_4672afc0__77->SetBinContent(1,199.625);
   frame_4672afc0__77->SetMaximum(199.625);
   frame_4672afc0__77->SetEntries(2);
   frame_4672afc0__77->SetDirectory(0);
   frame_4672afc0__77->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4672afc0__77->SetLineColor(ci);
   frame_4672afc0__77->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4672afc0__77->GetXaxis()->SetLabelFont(42);
   frame_4672afc0__77->GetXaxis()->SetTitleOffset(1);
   frame_4672afc0__77->GetXaxis()->SetTitleFont(42);
   frame_4672afc0__77->GetYaxis()->SetTitle("1/Events");
   frame_4672afc0__77->GetYaxis()->SetLabelFont(42);
   frame_4672afc0__77->GetYaxis()->SetTitleFont(42);
   frame_4672afc0__77->GetZaxis()->SetLabelFont(42);
   frame_4672afc0__77->GetZaxis()->SetTitleOffset(1);
   frame_4672afc0__77->GetZaxis()->SetTitleFont(42);
   frame_4672afc0__77->Draw("FUNC");
   
   Double_t h_dh_data2_fx3020[25] = {
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
   Double_t h_dh_data2_fy3020[25] = {
   0,
   0,
   1,
   17,
   54,
   86,
   115,
   155,
   165,
   166,
   162,
   158,
   111,
   78,
   71,
   53,
   30,
   19,
   11,
   8,
   6,
   3,
   3,
   2,
   1};
   Double_t h_dh_data2_felx3020[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_data2_fely3020[25] = {
   0,
   0,
   0.8272462,
   4.082184,
   7.32564,
   9.255555,
   10.23546,
   11.95994,
   12.35496,
   12.3938,
   12.23774,
   12.07975,
   10.04751,
   8.812788,
   8.406258,
   7.257065,
   5.446522,
   4.320219,
   3.265579,
   2.768386,
   2.379931,
   1.632705,
   1.632705,
   1.291815,
   0.8272462};
   Double_t h_dh_data2_fehx3020[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_data2_fehy3020[25] = {
   1.147874,
   1.147874,
   2.299527,
   5.203719,
   8.39385,
   10.30959,
   11.23546,
   12.95994,
   13.35496,
   13.3938,
   13.23774,
   13.07975,
   11.04751,
   9.869531,
   9.465736,
   8.325916,
   6.538046,
   5.435196,
   4.416521,
   3.945142,
   3.583642,
   2.918186,
   2.918186,
   2.63786,
   2.299527};
   grae = new TGraphAsymmErrors(25,h_dh_data2_fx3020,h_dh_data2_fy3020,h_dh_data2_felx3020,h_dh_data2_fehx3020,h_dh_data2_fely3020,h_dh_data2_fehy3020);
   grae->SetName("h_dh_data2");
   grae->SetTitle("Histogram of dh_data2_plot__x_o2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_data23020 = new TH1F("Graph_h_dh_data23020","Histogram of dh_data2_plot__x_o2",100,0,2.2);
   Graph_h_dh_data23020->SetMinimum(0);
   Graph_h_dh_data23020->SetMaximum(197.3332);
   Graph_h_dh_data23020->SetDirectory(0);
   Graph_h_dh_data23020->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_data23020->SetLineColor(ci);
   Graph_h_dh_data23020->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_data23020->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_data23020->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_data23020->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_data23020->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_data23020->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_data23020->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_data23020->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_data23020);
   
   grae->Draw("p");
   
   Double_t observation_fx20[66] = {
   -0.004821822,
   -0.001071822,
   0.0008031779,
   0.002678178,
   0.01017818,
   0.02517818,
   0.05517818,
   0.1151782,
   0.1451782,
   0.1751782,
   0.2051782,
   0.2351782,
   0.2651782,
   0.2951782,
   0.3251782,
   0.3551782,
   0.3701782,
   0.3851782,
   0.4151782,
   0.4451782,
   0.4751782,
   0.5051782,
   0.5351782,
   0.5651782,
   0.5951782,
   0.6101782,
   0.6251782,
   0.6401782,
   0.6551782,
   0.6701782,
   0.6851782,
   0.7001782,
   0.7151782,
   0.7301782,
   0.7451782,
   0.7601782,
   0.7751782,
   0.7901782,
   0.8051782,
   0.8201782,
   0.8351782,
   0.8501782,
   0.8651782,
   0.8801782,
   0.8951782,
   0.9251782,
   0.9551782,
   0.9701782,
   0.9851782,
   1.000178,
   1.015178,
   1.030178,
   1.045178,
   1.075178,
   1.105178,
   1.135178,
   1.165178,
   1.195178,
   1.225178,
   1.255178,
   1.285178,
   1.315178,
   1.375178,
   1.435178,
   1.495178,
   1.495178};
   Double_t observation_fy20[66] = {
   0,
   0,
   0.6151208,
   0.6329185,
   0.7089056,
   0.8863131,
   1.366641,
   3.07658,
   4.49174,
   6.43953,
   9.065395,
   12.53177,
   17.01105,
   22.67477,
   29.67889,
   38.1457,
   42.95161,
   48.14338,
   59.66512,
   72.6102,
   86.76963,
   101.8195,
   117.3241,
   132.7506,
   147.4956,
   154.4134,
   160.9216,
   166.9425,
   172.4022,
   177.232,
   181.3696,
   184.7609,
   187.361,
   189.1347,
   190.0583,
   190.119,
   189.3161,
   187.6605,
   185.1746,
   181.8918,
   177.8559,
   173.1197,
   167.7445,
   161.798,
   155.3535,
   141.2821,
   126.1672,
   118.5288,
   111.4084,
   104.8147,
   98.70177,
   93.02802,
   87.75616,
   78.28662,
   70.06061,
   62.88721,
   56.60886,
   51.09481,
   46.23608,
   41.94141,
   38.13399,
   34.74898,
   29.03432,
   24.44759,
   20.73188,
   20.73188};
   graph = new TGraph(66,observation_fx20,observation_fy20);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation20 = new TH1F("Graph_observation20","Projection of obsf DSCB fit",100,-0.1548218,1.645178);
   Graph_observation20->SetMinimum(0);
   Graph_observation20->SetMaximum(209.1309);
   Graph_observation20->SetDirectory(0);
   Graph_observation20->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_observation20->SetLineColor(ci);
   Graph_observation20->GetXaxis()->SetLabelFont(42);
   Graph_observation20->GetXaxis()->SetTitleOffset(1);
   Graph_observation20->GetXaxis()->SetTitleFont(42);
   Graph_observation20->GetYaxis()->SetLabelFont(42);
   Graph_observation20->GetYaxis()->SetTitleFont(42);
   Graph_observation20->GetZaxis()->SetLabelFont(42);
   Graph_observation20->GetZaxis()->SetTitleOffset(1);
   Graph_observation20->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_observation20);
   
   graph->Draw("l");
   
   TH1D *frame_4672afc0__78 = new TH1D("frame_4672afc0__78","p_T Balance",25,0,2);
   frame_4672afc0__78->SetBinContent(1,199.625);
   frame_4672afc0__78->SetMaximum(199.625);
   frame_4672afc0__78->SetEntries(2);
   frame_4672afc0__78->SetDirectory(0);
   frame_4672afc0__78->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4672afc0__78->SetLineColor(ci);
   frame_4672afc0__78->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4672afc0__78->GetXaxis()->SetLabelFont(42);
   frame_4672afc0__78->GetXaxis()->SetTitleOffset(1);
   frame_4672afc0__78->GetXaxis()->SetTitleFont(42);
   frame_4672afc0__78->GetYaxis()->SetTitle("1/Events");
   frame_4672afc0__78->GetYaxis()->SetLabelFont(42);
   frame_4672afc0__78->GetYaxis()->SetTitleFont(42);
   frame_4672afc0__78->GetZaxis()->SetLabelFont(42);
   frame_4672afc0__78->GetZaxis()->SetTitleOffset(1);
   frame_4672afc0__78->GetZaxis()->SetTitleFont(42);
   frame_4672afc0__78->Draw("AXISSAME");
   
   TH1D *norm_o__79 = new TH1D("norm_o__79","",25,0,2);
   norm_o__79->SetBinContent(3,1);
   norm_o__79->SetBinContent(4,17);
   norm_o__79->SetBinContent(5,54);
   norm_o__79->SetBinContent(6,86);
   norm_o__79->SetBinContent(7,115);
   norm_o__79->SetBinContent(8,155);
   norm_o__79->SetBinContent(9,165);
   norm_o__79->SetBinContent(10,166);
   norm_o__79->SetBinContent(11,162);
   norm_o__79->SetBinContent(12,158);
   norm_o__79->SetBinContent(13,111);
   norm_o__79->SetBinContent(14,78);
   norm_o__79->SetBinContent(15,71);
   norm_o__79->SetBinContent(16,53);
   norm_o__79->SetBinContent(17,30);
   norm_o__79->SetBinContent(18,19);
   norm_o__79->SetBinContent(19,11);
   norm_o__79->SetBinContent(20,8);
   norm_o__79->SetBinContent(21,6);
   norm_o__79->SetBinContent(22,3);
   norm_o__79->SetBinContent(23,3);
   norm_o__79->SetBinContent(24,2);
   norm_o__79->SetBinContent(25,1);
   norm_o__79->SetBinContent(26,2);
   norm_o__79->SetMinimum(0);
   norm_o__79->SetMaximum(365.2);
   norm_o__79->SetEntries(1477);
   norm_o__79->SetStats(0);
   norm_o__79->SetLineWidth(2);
   norm_o__79->SetMarkerStyle(8);
   norm_o__79->SetMarkerSize(0.4);
   norm_o__79->GetXaxis()->SetRange(1,25);
   norm_o__79->GetXaxis()->SetLabelFont(42);
   norm_o__79->GetXaxis()->SetLabelSize(0.04);
   norm_o__79->GetXaxis()->SetTitleOffset(1);
   norm_o__79->GetXaxis()->SetTitleFont(42);
   norm_o__79->GetYaxis()->SetTitle("Events");
   norm_o__79->GetYaxis()->SetLabelFont(42);
   norm_o__79->GetYaxis()->SetTitleOffset(1.4);
   norm_o__79->GetYaxis()->SetTitleFont(42);
   norm_o__79->GetZaxis()->SetLabelFont(42);
   norm_o__79->GetZaxis()->SetTitleOffset(1);
   norm_o__79->GetZaxis()->SetTitleFont(42);
   norm_o__79->Draw("same e1");
   
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
   entry=leg->AddEntry("frame_x_o2_4672afc0","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.753734 #pm 0.011793","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.222337 #pm 0.008644","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.892000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_4672afc0_copy__80 = new TH1D("frame_4672afc0_copy__80","p_T Balance",25,0,2);
   frame_4672afc0_copy__80->SetBinContent(1,199.625);
   frame_4672afc0_copy__80->SetMaximum(199.625);
   frame_4672afc0_copy__80->SetEntries(2);
   frame_4672afc0_copy__80->SetDirectory(0);
   frame_4672afc0_copy__80->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4672afc0_copy__80->SetLineColor(ci);
   frame_4672afc0_copy__80->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4672afc0_copy__80->GetXaxis()->SetLabelFont(42);
   frame_4672afc0_copy__80->GetXaxis()->SetTitleOffset(1);
   frame_4672afc0_copy__80->GetXaxis()->SetTitleFont(42);
   frame_4672afc0_copy__80->GetYaxis()->SetTitle("1/Events");
   frame_4672afc0_copy__80->GetYaxis()->SetLabelFont(42);
   frame_4672afc0_copy__80->GetYaxis()->SetTitleFont(42);
   frame_4672afc0_copy__80->GetZaxis()->SetLabelFont(42);
   frame_4672afc0_copy__80->GetZaxis()->SetTitleOffset(1);
   frame_4672afc0_copy__80->GetZaxis()->SetTitleFont(42);
   frame_4672afc0_copy__80->Draw("sameaxis");
   
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
