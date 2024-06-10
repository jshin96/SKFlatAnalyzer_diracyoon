void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_5__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 19:42:23 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-60.2343,2.25,692.6944);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_46f78490__65 = new TH1D("frame_46f78490__65","p_T Balance",25,0,2);
   frame_46f78490__65->SetBinContent(1,617.4015);
   frame_46f78490__65->SetMaximum(617.4015);
   frame_46f78490__65->SetEntries(2);
   frame_46f78490__65->SetDirectory(0);
   frame_46f78490__65->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_46f78490__65->SetLineColor(ci);
   frame_46f78490__65->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46f78490__65->GetXaxis()->SetLabelFont(42);
   frame_46f78490__65->GetXaxis()->SetTitleOffset(1);
   frame_46f78490__65->GetXaxis()->SetTitleFont(42);
   frame_46f78490__65->GetYaxis()->SetTitle("1/Events");
   frame_46f78490__65->GetYaxis()->SetLabelFont(42);
   frame_46f78490__65->GetYaxis()->SetTitleFont(42);
   frame_46f78490__65->GetZaxis()->SetLabelFont(42);
   frame_46f78490__65->GetZaxis()->SetTitleOffset(1);
   frame_46f78490__65->GetZaxis()->SetTitleFont(42);
   frame_46f78490__65->Draw("FUNC");
   
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
   0.07276672,
   38.17386,
   101.7302,
   180.2419,
   278.1436,
   383.5454,
   536.0079,
   532.2511,
   549.7089,
   516.4988,
   411.7859,
   328.2266,
   235.0376,
   146.7462,
   103.7687,
   54.01783,
   40.01967,
   22.32108,
   13.38343,
   7.129449,
   4.519695,
   3.296702,
   1.203592};
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
   0.05151232,
   4.214999,
   6.948352,
   9.41892,
   12.14395,
   14.29779,
   17.38671,
   17.41207,
   17.80235,
   17.4088,
   15.28125,
   13.57943,
   11.31086,
   8.608558,
   6.650472,
   4.849223,
   4.019948,
   2.872502,
   2.023442,
   1.446457,
   0.9706028,
   0.8793145,
   0.3790333};
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
   0.05151232,
   4.214999,
   6.948352,
   9.41892,
   12.14395,
   14.29779,
   17.38671,
   17.41207,
   17.80235,
   17.4088,
   15.28125,
   13.57943,
   11.31086,
   8.608558,
   6.650472,
   4.849223,
   4.019948,
   2.872502,
   2.023442,
   1.446457,
   0.9706028,
   0.8793145,
   0.3790333};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3017,h_dh_central2_fy3017,h_dh_central2_felx3017,h_dh_central2_fehx3017,h_dh_central2_fely3017,h_dh_central2_fehy3017);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23017 = new TH1F("Graph_h_dh_central23017","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23017->SetMinimum(0);
   Graph_h_dh_central23017->SetMaximum(624.2624);
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
   
   Double_t Central_fx17[59] = {
   0.1031782,
   0.1594428,
   0.1875751,
   0.2157075,
   0.2438398,
   0.2719721,
   0.3001044,
   0.3282367,
   0.356369,
   0.3845014,
   0.4126337,
   0.440766,
   0.4688983,
   0.4970306,
   0.5251629,
   0.5532953,
   0.6095599,
   0.6376922,
   0.6658245,
   0.6798907,
   0.6939569,
   0.708023,
   0.7220892,
   0.7361553,
   0.7502215,
   0.7642876,
   0.7783538,
   0.79242,
   0.8064861,
   0.8205523,
   0.8346184,
   0.8486846,
   0.8627508,
   0.8768169,
   0.8908831,
   0.9049492,
   0.9190154,
   0.9330815,
   0.9471477,
   0.97528,
   1.003412,
   1.059677,
   1.087809,
   1.115942,
   1.130008,
   1.144074,
   1.15814,
   1.172206,
   1.200339,
   1.228471,
   1.256603,
   1.284736,
   1.312868,
   1.341,
   1.369132,
   1.397265,
   1.453529,
   1.509794,
   1.509794};
   Double_t Central_fy17[59] = {
   5.504373,
   11.1723,
   15.57373,
   21.39592,
   28.97061,
   38.66097,
   50.84827,
   65.91252,
   84.20698,
   106.027,
   131.575,
   160.9232,
   193.9779,
   230.4487,
   269.8266,
   311.3748,
   396.9593,
   438.5405,
   477.4874,
   495.5314,
   512.3921,
   527.9051,
   541.9152,
   554.2797,
   564.8702,
   573.5753,
   580.3023,
   584.9789,
   587.5547,
   588.0015,
   586.3145,
   582.5121,
   576.6355,
   568.748,
   558.9339,
   547.2971,
   533.959,
   519.0567,
   502.7404,
   466.5175,
   426.6586,
   341.6416,
   299.122,
   258.1164,
   239.1171,
   221.8342,
   206.0849,
   191.7088,
   166.528,
   145.3491,
   127.4326,
   112.1936,
   99.16591,
   87.97546,
   78.31991,
   69.9534,
   56.31879,
   45.85004,
   45.85004};
   TGraph *graph = new TGraph(59,Central_fx17,Central_fy17);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central17 = new TH1F("Graph_Central17","Projection of centralf DSCB fit",100,0,1.650456);
   Graph_Central17->SetMinimum(4.953936);
   Graph_Central17->SetMaximum(646.2512);
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
   
   TH1D *frame_46f78490__66 = new TH1D("frame_46f78490__66","p_T Balance",25,0,2);
   frame_46f78490__66->SetBinContent(1,617.4015);
   frame_46f78490__66->SetMaximum(617.4015);
   frame_46f78490__66->SetEntries(2);
   frame_46f78490__66->SetDirectory(0);
   frame_46f78490__66->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46f78490__66->SetLineColor(ci);
   frame_46f78490__66->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46f78490__66->GetXaxis()->SetLabelFont(42);
   frame_46f78490__66->GetXaxis()->SetTitleOffset(1);
   frame_46f78490__66->GetXaxis()->SetTitleFont(42);
   frame_46f78490__66->GetYaxis()->SetTitle("1/Events");
   frame_46f78490__66->GetYaxis()->SetLabelFont(42);
   frame_46f78490__66->GetYaxis()->SetTitleFont(42);
   frame_46f78490__66->GetZaxis()->SetLabelFont(42);
   frame_46f78490__66->GetZaxis()->SetTitleOffset(1);
   frame_46f78490__66->GetZaxis()->SetTitleFont(42);
   frame_46f78490__66->Draw("AXISSAME");
   
   TH1D *norm_c__67 = new TH1D("norm_c__67","",25,0,2);
   norm_c__67->SetBinContent(3,0.07276672);
   norm_c__67->SetBinContent(4,38.17386);
   norm_c__67->SetBinContent(5,101.7302);
   norm_c__67->SetBinContent(6,180.2419);
   norm_c__67->SetBinContent(7,278.1436);
   norm_c__67->SetBinContent(8,383.5454);
   norm_c__67->SetBinContent(9,536.0079);
   norm_c__67->SetBinContent(10,532.2511);
   norm_c__67->SetBinContent(11,549.709);
   norm_c__67->SetBinContent(12,516.4988);
   norm_c__67->SetBinContent(13,411.7859);
   norm_c__67->SetBinContent(14,328.2266);
   norm_c__67->SetBinContent(15,235.0376);
   norm_c__67->SetBinContent(16,146.7462);
   norm_c__67->SetBinContent(17,103.7687);
   norm_c__67->SetBinContent(18,54.01783);
   norm_c__67->SetBinContent(19,40.01967);
   norm_c__67->SetBinContent(20,22.32108);
   norm_c__67->SetBinContent(21,13.38343);
   norm_c__67->SetBinContent(22,7.129449);
   norm_c__67->SetBinContent(23,4.519695);
   norm_c__67->SetBinContent(24,3.296702);
   norm_c__67->SetBinContent(25,1.203592);
   norm_c__67->SetBinContent(26,6.606351);
   norm_c__67->SetBinError(3,0.05151232);
   norm_c__67->SetBinError(4,4.214999);
   norm_c__67->SetBinError(5,6.948352);
   norm_c__67->SetBinError(6,9.41892);
   norm_c__67->SetBinError(7,12.14395);
   norm_c__67->SetBinError(8,14.29779);
   norm_c__67->SetBinError(9,17.38671);
   norm_c__67->SetBinError(10,17.41207);
   norm_c__67->SetBinError(11,17.80235);
   norm_c__67->SetBinError(12,17.4088);
   norm_c__67->SetBinError(13,15.28125);
   norm_c__67->SetBinError(14,13.57943);
   norm_c__67->SetBinError(15,11.31086);
   norm_c__67->SetBinError(16,8.608558);
   norm_c__67->SetBinError(17,6.650472);
   norm_c__67->SetBinError(18,4.849223);
   norm_c__67->SetBinError(19,4.019948);
   norm_c__67->SetBinError(20,2.872502);
   norm_c__67->SetBinError(21,2.023442);
   norm_c__67->SetBinError(22,1.446457);
   norm_c__67->SetBinError(23,0.9706028);
   norm_c__67->SetBinError(24,0.8793145);
   norm_c__67->SetBinError(25,0.3790333);
   norm_c__67->SetBinError(26,0.9104788);
   norm_c__67->SetEntries(18860);
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
   entry=leg->AddEntry("frame_x_c2_46f78490","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.822691 #pm 0.003896","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.238687 #pm 0.003152","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.361000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_46f78490_copy__68 = new TH1D("frame_46f78490_copy__68","p_T Balance",25,0,2);
   frame_46f78490_copy__68->SetBinContent(1,617.4015);
   frame_46f78490_copy__68->SetMaximum(617.4015);
   frame_46f78490_copy__68->SetEntries(2);
   frame_46f78490_copy__68->SetDirectory(0);
   frame_46f78490_copy__68->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46f78490_copy__68->SetLineColor(ci);
   frame_46f78490_copy__68->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46f78490_copy__68->GetXaxis()->SetLabelFont(42);
   frame_46f78490_copy__68->GetXaxis()->SetTitleOffset(1);
   frame_46f78490_copy__68->GetXaxis()->SetTitleFont(42);
   frame_46f78490_copy__68->GetYaxis()->SetTitle("1/Events");
   frame_46f78490_copy__68->GetYaxis()->SetLabelFont(42);
   frame_46f78490_copy__68->GetYaxis()->SetTitleFont(42);
   frame_46f78490_copy__68->GetZaxis()->SetLabelFont(42);
   frame_46f78490_copy__68->GetZaxis()->SetTitleOffset(1);
   frame_46f78490_copy__68->GetZaxis()->SetTitleFont(42);
   frame_46f78490_copy__68->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-58.7938,2.25,676.1287);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_46f6d060__69 = new TH1D("frame_46f6d060__69","p_T Balance",25,0,2);
   frame_46f6d060__69->SetBinContent(1,602.6365);
   frame_46f6d060__69->SetMaximum(602.6365);
   frame_46f6d060__69->SetEntries(2);
   frame_46f6d060__69->SetDirectory(0);
   frame_46f6d060__69->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46f6d060__69->SetLineColor(ci);
   frame_46f6d060__69->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46f6d060__69->GetXaxis()->SetLabelFont(42);
   frame_46f6d060__69->GetXaxis()->SetTitleOffset(1);
   frame_46f6d060__69->GetXaxis()->SetTitleFont(42);
   frame_46f6d060__69->GetYaxis()->SetTitle("1/Events");
   frame_46f6d060__69->GetYaxis()->SetLabelFont(42);
   frame_46f6d060__69->GetYaxis()->SetTitleFont(42);
   frame_46f6d060__69->GetZaxis()->SetLabelFont(42);
   frame_46f6d060__69->GetZaxis()->SetTitleOffset(1);
   frame_46f6d060__69->GetZaxis()->SetTitleFont(42);
   frame_46f6d060__69->Draw("FUNC");
   
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
   0.8566325,
   36.18372,
   99.98035,
   172.3771,
   263.8096,
   360.6021,
   512.2383,
   524.4086,
   531.4199,
   545.9479,
   448.0571,
   356.221,
   263.8782,
   189.6224,
   123.3568,
   62.52827,
   43.25111,
   29.5703,
   17.012,
   7.766577,
   5.511371,
   3.400424,
   1.44331};
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
   0.8243093,
   4.208603,
   7.231867,
   9.445736,
   11.96925,
   14.06733,
   17.1354,
   17.22817,
   17.5112,
   18.08901,
   16.13477,
   14.31125,
   12.05551,
   10.23298,
   7.688841,
   5.234336,
   4.299184,
   3.525835,
   2.290236,
   1.444557,
   1.255546,
   0.9146194,
   0.3993726};
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
   0.8243093,
   4.208603,
   7.231867,
   9.445736,
   11.96925,
   14.06733,
   17.1354,
   17.22817,
   17.5112,
   18.08901,
   16.13477,
   14.31125,
   12.05551,
   10.23298,
   7.688841,
   5.234336,
   4.299184,
   3.525835,
   2.290236,
   1.444557,
   1.255546,
   0.9146194,
   0.3993726};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3018,h_dh_up2_fy3018,h_dh_up2_felx3018,h_dh_up2_fehx3018,h_dh_up2_fely3018,h_dh_up2_fehy3018);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23018 = new TH1F("Graph_h_dh_up23018","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23018->SetMinimum(0);
   Graph_h_dh_up23018->SetMaximum(620.4406);
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
   
   Double_t up_fx18[58] = {
   0.1801878,
   0.2067163,
   0.2332449,
   0.2597734,
   0.2863019,
   0.3128305,
   0.339359,
   0.3658876,
   0.3924161,
   0.4189446,
   0.4454732,
   0.4720017,
   0.4985303,
   0.5250588,
   0.5515873,
   0.6046444,
   0.6311729,
   0.6577015,
   0.68423,
   0.7107586,
   0.7240228,
   0.7372871,
   0.7505514,
   0.7638156,
   0.7770799,
   0.7903442,
   0.8036085,
   0.8168727,
   0.830137,
   0.8434013,
   0.8566655,
   0.8699298,
   0.8831941,
   0.8964583,
   0.9097226,
   0.9229869,
   0.9362511,
   0.9495154,
   0.976044,
   1.002572,
   1.029101,
   1.05563,
   1.082158,
   1.135215,
   1.161744,
   1.188272,
   1.201537,
   1.214801,
   1.241329,
   1.267858,
   1.294386,
   1.320915,
   1.347444,
   1.373972,
   1.400501,
   1.453558,
   1.506615,
   1.506615};
   Double_t up_fy18[58] = {
   17.22148,
   22.69141,
   29.56711,
   38.09291,
   48.5252,
   61.11932,
   76.11628,
   93.72695,
   114.1141,
   137.3733,
   163.5133,
   192.4384,
   223.9331,
   257.6516,
   293.1132,
   366.6943,
   403.2463,
   438.4546,
   471.3752,
   501.0682,
   514.4224,
   526.6412,
   537.6279,
   547.2941,
   555.5609,
   562.3602,
   567.6354,
   571.3423,
   573.4496,
   573.9395,
   572.8078,
   570.0642,
   565.7317,
   559.847,
   552.459,
   543.6293,
   533.4301,
   521.9444,
   495.4885,
   465.0835,
   431.6345,
   396.0858,
   359.3771,
   285.9804,
   250.8194,
   217.5074,
   202.1176,
   188.0651,
   163.4402,
   142.717,
   125.1766,
   110.25,
   97.48347,
   86.51247,
   77.04232,
   61.68902,
   49.97678,
   49.97678};
   graph = new TGraph(58,up_fx18,up_fy18);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up18 = new TH1F("Graph_up18","Projection of upf DSCB fit",100,0.04754509,1.639257);
   Graph_up18->SetMinimum(15.49933);
   Graph_up18->SetMaximum(629.6113);
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
   
   TH1D *frame_46f6d060__70 = new TH1D("frame_46f6d060__70","p_T Balance",25,0,2);
   frame_46f6d060__70->SetBinContent(1,602.6365);
   frame_46f6d060__70->SetMaximum(602.6365);
   frame_46f6d060__70->SetEntries(2);
   frame_46f6d060__70->SetDirectory(0);
   frame_46f6d060__70->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46f6d060__70->SetLineColor(ci);
   frame_46f6d060__70->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46f6d060__70->GetXaxis()->SetLabelFont(42);
   frame_46f6d060__70->GetXaxis()->SetTitleOffset(1);
   frame_46f6d060__70->GetXaxis()->SetTitleFont(42);
   frame_46f6d060__70->GetYaxis()->SetTitle("1/Events");
   frame_46f6d060__70->GetYaxis()->SetLabelFont(42);
   frame_46f6d060__70->GetYaxis()->SetTitleFont(42);
   frame_46f6d060__70->GetZaxis()->SetLabelFont(42);
   frame_46f6d060__70->GetZaxis()->SetTitleOffset(1);
   frame_46f6d060__70->GetZaxis()->SetTitleFont(42);
   frame_46f6d060__70->Draw("AXISSAME");
   
   TH1D *norm_u__71 = new TH1D("norm_u__71","",25,0,2);
   norm_u__71->SetBinContent(3,0.8566325);
   norm_u__71->SetBinContent(4,36.18372);
   norm_u__71->SetBinContent(5,99.98035);
   norm_u__71->SetBinContent(6,172.3771);
   norm_u__71->SetBinContent(7,263.8096);
   norm_u__71->SetBinContent(8,360.6021);
   norm_u__71->SetBinContent(9,512.2383);
   norm_u__71->SetBinContent(10,524.4085);
   norm_u__71->SetBinContent(11,531.4199);
   norm_u__71->SetBinContent(12,545.9479);
   norm_u__71->SetBinContent(13,448.0571);
   norm_u__71->SetBinContent(14,356.221);
   norm_u__71->SetBinContent(15,263.8782);
   norm_u__71->SetBinContent(16,189.6224);
   norm_u__71->SetBinContent(17,123.3568);
   norm_u__71->SetBinContent(18,62.52827);
   norm_u__71->SetBinContent(19,43.25111);
   norm_u__71->SetBinContent(20,29.5703);
   norm_u__71->SetBinContent(21,17.012);
   norm_u__71->SetBinContent(22,7.766577);
   norm_u__71->SetBinContent(23,5.511371);
   norm_u__71->SetBinContent(24,3.400424);
   norm_u__71->SetBinContent(25,1.44331);
   norm_u__71->SetBinContent(26,6.335289);
   norm_u__71->SetBinError(3,0.8243093);
   norm_u__71->SetBinError(4,4.208603);
   norm_u__71->SetBinError(5,7.231867);
   norm_u__71->SetBinError(6,9.445736);
   norm_u__71->SetBinError(7,11.96925);
   norm_u__71->SetBinError(8,14.06733);
   norm_u__71->SetBinError(9,17.1354);
   norm_u__71->SetBinError(10,17.22817);
   norm_u__71->SetBinError(11,17.5112);
   norm_u__71->SetBinError(12,18.08901);
   norm_u__71->SetBinError(13,16.13477);
   norm_u__71->SetBinError(14,14.31125);
   norm_u__71->SetBinError(15,12.05551);
   norm_u__71->SetBinError(16,10.23298);
   norm_u__71->SetBinError(17,7.688841);
   norm_u__71->SetBinError(18,5.234336);
   norm_u__71->SetBinError(19,4.299184);
   norm_u__71->SetBinError(20,3.525835);
   norm_u__71->SetBinError(21,2.290236);
   norm_u__71->SetBinError(22,1.444557);
   norm_u__71->SetBinError(23,1.255546);
   norm_u__71->SetBinError(24,0.9146194);
   norm_u__71->SetBinError(25,0.3993726);
   norm_u__71->SetBinError(26,0.9184662);
   norm_u__71->SetEntries(18374);
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
   entry=leg->AddEntry("frame_x_u2_46f6d060","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.851808 #pm 0.004053","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.261501 #pm 0.003302","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.707000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_46f6d060_copy__72 = new TH1D("frame_46f6d060_copy__72","p_T Balance",25,0,2);
   frame_46f6d060_copy__72->SetBinContent(1,602.6365);
   frame_46f6d060_copy__72->SetMaximum(602.6365);
   frame_46f6d060_copy__72->SetEntries(2);
   frame_46f6d060_copy__72->SetDirectory(0);
   frame_46f6d060_copy__72->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46f6d060_copy__72->SetLineColor(ci);
   frame_46f6d060_copy__72->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46f6d060_copy__72->GetXaxis()->SetLabelFont(42);
   frame_46f6d060_copy__72->GetXaxis()->SetTitleOffset(1);
   frame_46f6d060_copy__72->GetXaxis()->SetTitleFont(42);
   frame_46f6d060_copy__72->GetYaxis()->SetTitle("1/Events");
   frame_46f6d060_copy__72->GetYaxis()->SetLabelFont(42);
   frame_46f6d060_copy__72->GetYaxis()->SetTitleFont(42);
   frame_46f6d060_copy__72->GetZaxis()->SetLabelFont(42);
   frame_46f6d060_copy__72->GetZaxis()->SetTitleOffset(1);
   frame_46f6d060_copy__72->GetZaxis()->SetTitleFont(42);
   frame_46f6d060_copy__72->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-68.73839,2.25,618.6455);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_46f74d20__73 = new TH1D("frame_46f74d20__73","p_T Balance",25,0,2);
   frame_46f74d20__73->SetBinContent(1,604.8978);
   frame_46f74d20__73->SetMaximum(604.8978);
   frame_46f74d20__73->SetEntries(2);
   frame_46f74d20__73->SetDirectory(0);
   frame_46f74d20__73->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46f74d20__73->SetLineColor(ci);
   frame_46f74d20__73->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46f74d20__73->GetXaxis()->SetLabelFont(42);
   frame_46f74d20__73->GetXaxis()->SetTitleOffset(1);
   frame_46f74d20__73->GetXaxis()->SetTitleFont(42);
   frame_46f74d20__73->GetYaxis()->SetTitle("1/Events");
   frame_46f74d20__73->GetYaxis()->SetLabelFont(42);
   frame_46f74d20__73->GetYaxis()->SetTitleFont(42);
   frame_46f74d20__73->GetZaxis()->SetLabelFont(42);
   frame_46f74d20__73->GetZaxis()->SetTitleOffset(1);
   frame_46f74d20__73->GetZaxis()->SetTitleFont(42);
   frame_46f74d20__73->Draw("FUNC");
   
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
   0.1060651,
   37.92975,
   117.0775,
   197.6581,
   295.5713,
   400.7331,
   549.9729,
   513.0214,
   526.6713,
   492.6597,
   379.6855,
   280.553,
   193.6541,
   137.6311,
   93.61723,
   53.33382,
   33.74738,
   17.79937,
   12.31493,
   6.45716,
   4.166132,
   2.932232,
   1.72696};
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
   0.06133088,
   3.957219,
   7.258528,
   9.906605,
   12.31115,
   14.61646,
   17.3341,
   16.87376,
   17.29303,
   16.81642,
   14.48272,
   12.22229,
   9.908124,
   8.089671,
   6.268431,
   4.814693,
   3.57205,
   2.278294,
   1.960092,
   1.334978,
   0.8866931,
   0.6849675,
   0.5007837};
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
   0.06133088,
   3.957219,
   7.258528,
   9.906605,
   12.31115,
   14.61646,
   17.3341,
   16.87376,
   17.29303,
   16.81642,
   14.48272,
   12.22229,
   9.908124,
   8.089671,
   6.268431,
   4.814693,
   3.57205,
   2.278294,
   1.960092,
   1.334978,
   0.8866931,
   0.6849675,
   0.5007837};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3019,h_dh_down2_fy3019,h_dh_down2_felx3019,h_dh_down2_fehx3019,h_dh_down2_fely3019,h_dh_down2_fehy3019);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23019 = new TH1F("Graph_h_dh_down23019","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23019->SetMinimum(0);
   Graph_h_dh_down23019->SetMaximum(624.0377);
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
   
   Double_t down_fx19[57] = {
   0.1577435,
   0.1832929,
   0.2088422,
   0.2343915,
   0.2599409,
   0.2854902,
   0.3110395,
   0.3365889,
   0.3621382,
   0.3876875,
   0.4132368,
   0.4387862,
   0.4643355,
   0.4898848,
   0.5154342,
   0.5665328,
   0.5920822,
   0.6176315,
   0.6431808,
   0.6687302,
   0.6815048,
   0.6942795,
   0.7070541,
   0.7198288,
   0.7326035,
   0.7453781,
   0.7581528,
   0.7709275,
   0.7837021,
   0.7964768,
   0.8092515,
   0.8220261,
   0.8348008,
   0.8475755,
   0.8603501,
   0.8731248,
   0.8858995,
   0.8986741,
   0.9242235,
   0.9497728,
   0.9753221,
   1.026421,
   1.05197,
   1.064745,
   1.077519,
   1.103069,
   1.128618,
   1.154167,
   1.179717,
   1.205266,
   1.230815,
   1.256365,
   1.281914,
   1.333013,
   1.384111,
   1.43521,
   1.43521};
   Double_t down_fy19[57] = {
   11.84558,
   16.11489,
   21.65218,
   28.72427,
   37.62439,
   48.65897,
   62.13403,
   78.33741,
   97.51737,
   119.8582,
   145.4543,
   174.2845,
   206.1882,
   240.8473,
   277.7749,
   355.6434,
   394.8073,
   432.7416,
   468.3227,
   500.4203,
   514.822,
   527.9559,
   539.705,
   549.963,
   558.6358,
   565.6429,
   570.9186,
   574.4131,
   576.0932,
   575.9428,
   573.9635,
   570.1741,
   564.6105,
   557.3252,
   548.3864,
   537.877,
   525.8932,
   512.543,
   482.2262,
   447.9652,
   410.8761,
   332.708,
   294.3562,
   276.9856,
   260.8775,
   232.026,
   207.055,
   185.3547,
   166.4242,
   149.8499,
   135.2885,
   122.4537,
   111.1054,
   92.09228,
   76.97774,
   64.84065,
   64.84065};
   graph = new TGraph(57,down_fx19,down_fy19);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down19 = new TH1F("Graph_down19","Projection of downf DSCB fit",100,0.0299969,1.562957);
   Graph_down19->SetMinimum(10.66102);
   Graph_down19->SetMaximum(632.5179);
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
   
   TH1D *frame_46f74d20__74 = new TH1D("frame_46f74d20__74","p_T Balance",25,0,2);
   frame_46f74d20__74->SetBinContent(1,604.8978);
   frame_46f74d20__74->SetMaximum(604.8978);
   frame_46f74d20__74->SetEntries(2);
   frame_46f74d20__74->SetDirectory(0);
   frame_46f74d20__74->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46f74d20__74->SetLineColor(ci);
   frame_46f74d20__74->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46f74d20__74->GetXaxis()->SetLabelFont(42);
   frame_46f74d20__74->GetXaxis()->SetTitleOffset(1);
   frame_46f74d20__74->GetXaxis()->SetTitleFont(42);
   frame_46f74d20__74->GetYaxis()->SetTitle("1/Events");
   frame_46f74d20__74->GetYaxis()->SetLabelFont(42);
   frame_46f74d20__74->GetYaxis()->SetTitleFont(42);
   frame_46f74d20__74->GetZaxis()->SetLabelFont(42);
   frame_46f74d20__74->GetZaxis()->SetTitleOffset(1);
   frame_46f74d20__74->GetZaxis()->SetTitleFont(42);
   frame_46f74d20__74->Draw("AXISSAME");
   
   TH1D *norm_d__75 = new TH1D("norm_d__75","",25,0,2);
   norm_d__75->SetBinContent(3,0.1060651);
   norm_d__75->SetBinContent(4,37.92975);
   norm_d__75->SetBinContent(5,117.0775);
   norm_d__75->SetBinContent(6,197.6581);
   norm_d__75->SetBinContent(7,295.5713);
   norm_d__75->SetBinContent(8,400.7331);
   norm_d__75->SetBinContent(9,549.9729);
   norm_d__75->SetBinContent(10,513.0214);
   norm_d__75->SetBinContent(11,526.6713);
   norm_d__75->SetBinContent(12,492.6597);
   norm_d__75->SetBinContent(13,379.6855);
   norm_d__75->SetBinContent(14,280.553);
   norm_d__75->SetBinContent(15,193.6541);
   norm_d__75->SetBinContent(16,137.6311);
   norm_d__75->SetBinContent(17,93.61724);
   norm_d__75->SetBinContent(18,53.33382);
   norm_d__75->SetBinContent(19,33.74738);
   norm_d__75->SetBinContent(20,17.79937);
   norm_d__75->SetBinContent(21,12.31493);
   norm_d__75->SetBinContent(22,6.45716);
   norm_d__75->SetBinContent(23,4.166132);
   norm_d__75->SetBinContent(24,2.932232);
   norm_d__75->SetBinContent(25,1.72696);
   norm_d__75->SetBinContent(26,6.10514);
   norm_d__75->SetBinError(3,0.06133088);
   norm_d__75->SetBinError(4,3.957219);
   norm_d__75->SetBinError(5,7.258528);
   norm_d__75->SetBinError(6,9.906605);
   norm_d__75->SetBinError(7,12.31115);
   norm_d__75->SetBinError(8,14.61646);
   norm_d__75->SetBinError(9,17.3341);
   norm_d__75->SetBinError(10,16.87376);
   norm_d__75->SetBinError(11,17.29303);
   norm_d__75->SetBinError(12,16.81642);
   norm_d__75->SetBinError(13,14.48272);
   norm_d__75->SetBinError(14,12.22229);
   norm_d__75->SetBinError(15,9.908124);
   norm_d__75->SetBinError(16,8.089671);
   norm_d__75->SetBinError(17,6.268431);
   norm_d__75->SetBinError(18,4.814693);
   norm_d__75->SetBinError(19,3.57205);
   norm_d__75->SetBinError(20,2.278294);
   norm_d__75->SetBinError(21,1.960092);
   norm_d__75->SetBinError(22,1.334978);
   norm_d__75->SetBinError(23,0.8866931);
   norm_d__75->SetBinError(24,0.6849675);
   norm_d__75->SetBinError(25,0.5007837);
   norm_d__75->SetBinError(26,1.013408);
   norm_d__75->SetEntries(19192);
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
   entry=leg->AddEntry("frame_x_d2_46f74d20","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.796797 #pm 0.004004","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.232909 #pm 0.003282","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.473000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_46f74d20_copy__76 = new TH1D("frame_46f74d20_copy__76","p_T Balance",25,0,2);
   frame_46f74d20_copy__76->SetBinContent(1,604.8978);
   frame_46f74d20_copy__76->SetMaximum(604.8978);
   frame_46f74d20_copy__76->SetEntries(2);
   frame_46f74d20_copy__76->SetDirectory(0);
   frame_46f74d20_copy__76->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46f74d20_copy__76->SetLineColor(ci);
   frame_46f74d20_copy__76->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46f74d20_copy__76->GetXaxis()->SetLabelFont(42);
   frame_46f74d20_copy__76->GetXaxis()->SetTitleOffset(1);
   frame_46f74d20_copy__76->GetXaxis()->SetTitleFont(42);
   frame_46f74d20_copy__76->GetYaxis()->SetTitle("1/Events");
   frame_46f74d20_copy__76->GetYaxis()->SetLabelFont(42);
   frame_46f74d20_copy__76->GetYaxis()->SetTitleFont(42);
   frame_46f74d20_copy__76->GetZaxis()->SetLabelFont(42);
   frame_46f74d20_copy__76->GetZaxis()->SetTitleOffset(1);
   frame_46f74d20_copy__76->GetZaxis()->SetTitleFont(42);
   frame_46f74d20_copy__76->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-73.85484,2.25,664.6936);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_46f62690__77 = new TH1D("frame_46f62690__77","p_T Balance",25,0,2);
   frame_46f62690__77->SetBinContent(1,649.9226);
   frame_46f62690__77->SetMaximum(649.9226);
   frame_46f62690__77->SetEntries(2);
   frame_46f62690__77->SetDirectory(0);
   frame_46f62690__77->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46f62690__77->SetLineColor(ci);
   frame_46f62690__77->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46f62690__77->GetXaxis()->SetLabelFont(42);
   frame_46f62690__77->GetXaxis()->SetTitleOffset(1);
   frame_46f62690__77->GetXaxis()->SetTitleFont(42);
   frame_46f62690__77->GetYaxis()->SetTitle("1/Events");
   frame_46f62690__77->GetYaxis()->SetLabelFont(42);
   frame_46f62690__77->GetYaxis()->SetTitleFont(42);
   frame_46f62690__77->GetZaxis()->SetLabelFont(42);
   frame_46f62690__77->GetZaxis()->SetTitleOffset(1);
   frame_46f62690__77->GetZaxis()->SetTitleFont(42);
   frame_46f62690__77->Draw("FUNC");
   
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
   0,
   53,
   144,
   271,
   341,
   514,
   575,
   555,
   508,
   429,
   362,
   311,
   208,
   150,
   81,
   71,
   43,
   13,
   14,
   9,
   6,
   2,
   2};
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
   0,
   7.257065,
   11.51041,
   15.96967,
   17.97295,
   22.17708,
   23.48437,
   23.06374,
   22.0444,
   20.21835,
   18.53287,
   17.14228,
   13.93087,
   11.75765,
   8.981384,
   8.406258,
   6.531834,
   3.558662,
   3.6965,
   2.943461,
   2.379931,
   1.291815,
   1.291815};
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
   1.147874,
   8.325916,
   12.51041,
   16.96967,
   18.97295,
   23.17708,
   24.48437,
   24.06374,
   23.0444,
   21.21835,
   19.53287,
   18.14228,
   14.93087,
   12.75765,
   10.03706,
   9.465736,
   7.608278,
   4.697573,
   4.830381,
   4.110204,
   3.583642,
   2.63786,
   2.63786};
   grae = new TGraphAsymmErrors(25,h_dh_data2_fx3020,h_dh_data2_fy3020,h_dh_data2_felx3020,h_dh_data2_fehx3020,h_dh_data2_fely3020,h_dh_data2_fehy3020);
   grae->SetName("h_dh_data2");
   grae->SetTitle("Histogram of dh_data2_plot__x_o2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_data23020 = new TH1F("Graph_h_dh_data23020","Histogram of dh_data2_plot__x_o2",100,0,2.2);
   Graph_h_dh_data23020->SetMinimum(0);
   Graph_h_dh_data23020->SetMaximum(659.4328);
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
   
   Double_t observation_fx20[62] = {
   -0.0128505,
   0.0471495,
   0.1071495,
   0.1371495,
   0.1671495,
   0.1971495,
   0.2271495,
   0.2571495,
   0.2871495,
   0.3171495,
   0.3321495,
   0.3471495,
   0.3621495,
   0.3771495,
   0.3921495,
   0.4071495,
   0.4221495,
   0.4371495,
   0.4671495,
   0.4971495,
   0.5271495,
   0.5571495,
   0.5871495,
   0.6021495,
   0.6171495,
   0.6321495,
   0.6471495,
   0.6621495,
   0.6771495,
   0.6921495,
   0.7071495,
   0.7221495,
   0.7371495,
   0.7521495,
   0.7671495,
   0.7821495,
   0.7971495,
   0.8121495,
   0.8271495,
   0.8421495,
   0.8571495,
   0.8721495,
   0.8871495,
   0.9471495,
   0.9621495,
   0.9771495,
   0.9921495,
   1.007149,
   1.037149,
   1.067149,
   1.097149,
   1.127149,
   1.157149,
   1.187149,
   1.217149,
   1.247149,
   1.277149,
   1.307149,
   1.367149,
   1.427149,
   1.487149,
   1.487149};
   Double_t observation_fy20[62] = {
   0,
   2.668648,
   6.527654,
   9.906781,
   14.73679,
   21.48664,
   30.70641,
   43.01151,
   59.0521,
   79.46593,
   91.49333,
   104.8146,
   119.4752,
   135.5056,
   152.9188,
   171.7071,
   191.84,
   213.2622,
   259.618,
   309.778,
   362.2943,
   415.3052,
   466.6254,
   490.9129,
   513.8831,
   535.2393,
   554.6964,
   571.9875,
   586.8694,
   599.1287,
   608.5868,
   615.1042,
   618.584,
   618.9739,
   616.2683,
   610.5075,
   601.7776,
   590.2075,
   575.9665,
   559.2596,
   540.323,
   519.4183,
   496.8265,
   397.5691,
   374.8598,
   353.7491,
   334.1037,
   315.8034,
   282.8119,
   254.0183,
   228.7976,
   206.6308,
   187.0846,
   169.7959,
   154.459,
   140.8153,
   128.6453,
   117.7621,
   99.23934,
   84.21933,
   71.93644,
   71.93644};
   graph = new TGraph(62,observation_fx20,observation_fy20);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation20 = new TH1F("Graph_observation20","Projection of obsf DSCB fit",100,-0.1628505,1.637149);
   Graph_observation20->SetMinimum(0);
   Graph_observation20->SetMaximum(680.8713);
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
   
   TH1D *frame_46f62690__78 = new TH1D("frame_46f62690__78","p_T Balance",25,0,2);
   frame_46f62690__78->SetBinContent(1,649.9226);
   frame_46f62690__78->SetMaximum(649.9226);
   frame_46f62690__78->SetEntries(2);
   frame_46f62690__78->SetDirectory(0);
   frame_46f62690__78->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46f62690__78->SetLineColor(ci);
   frame_46f62690__78->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46f62690__78->GetXaxis()->SetLabelFont(42);
   frame_46f62690__78->GetXaxis()->SetTitleOffset(1);
   frame_46f62690__78->GetXaxis()->SetTitleFont(42);
   frame_46f62690__78->GetYaxis()->SetTitle("1/Events");
   frame_46f62690__78->GetYaxis()->SetLabelFont(42);
   frame_46f62690__78->GetYaxis()->SetTitleFont(42);
   frame_46f62690__78->GetZaxis()->SetLabelFont(42);
   frame_46f62690__78->GetZaxis()->SetTitleOffset(1);
   frame_46f62690__78->GetZaxis()->SetTitleFont(42);
   frame_46f62690__78->Draw("AXISSAME");
   
   TH1D *norm_o__79 = new TH1D("norm_o__79","",25,0,2);
   norm_o__79->SetBinContent(4,53);
   norm_o__79->SetBinContent(5,144);
   norm_o__79->SetBinContent(6,271);
   norm_o__79->SetBinContent(7,341);
   norm_o__79->SetBinContent(8,514);
   norm_o__79->SetBinContent(9,575);
   norm_o__79->SetBinContent(10,555);
   norm_o__79->SetBinContent(11,508);
   norm_o__79->SetBinContent(12,429);
   norm_o__79->SetBinContent(13,362);
   norm_o__79->SetBinContent(14,311);
   norm_o__79->SetBinContent(15,208);
   norm_o__79->SetBinContent(16,150);
   norm_o__79->SetBinContent(17,81);
   norm_o__79->SetBinContent(18,71);
   norm_o__79->SetBinContent(19,43);
   norm_o__79->SetBinContent(20,13);
   norm_o__79->SetBinContent(21,14);
   norm_o__79->SetBinContent(22,9);
   norm_o__79->SetBinContent(23,6);
   norm_o__79->SetBinContent(24,2);
   norm_o__79->SetBinContent(25,2);
   norm_o__79->SetBinContent(26,5);
   norm_o__79->SetMinimum(0);
   norm_o__79->SetMaximum(1265);
   norm_o__79->SetEntries(4667);
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
   entry=leg->AddEntry("frame_x_o2_46f62690","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.746544 #pm 0.003803","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.211900 #pm 0.003030","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.429000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_46f62690_copy__80 = new TH1D("frame_46f62690_copy__80","p_T Balance",25,0,2);
   frame_46f62690_copy__80->SetBinContent(1,649.9226);
   frame_46f62690_copy__80->SetMaximum(649.9226);
   frame_46f62690_copy__80->SetEntries(2);
   frame_46f62690_copy__80->SetDirectory(0);
   frame_46f62690_copy__80->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_46f62690_copy__80->SetLineColor(ci);
   frame_46f62690_copy__80->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_46f62690_copy__80->GetXaxis()->SetLabelFont(42);
   frame_46f62690_copy__80->GetXaxis()->SetTitleOffset(1);
   frame_46f62690_copy__80->GetXaxis()->SetTitleFont(42);
   frame_46f62690_copy__80->GetYaxis()->SetTitle("1/Events");
   frame_46f62690_copy__80->GetYaxis()->SetLabelFont(42);
   frame_46f62690_copy__80->GetYaxis()->SetTitleFont(42);
   frame_46f62690_copy__80->GetZaxis()->SetLabelFont(42);
   frame_46f62690_copy__80->GetZaxis()->SetTitleOffset(1);
   frame_46f62690_copy__80->GetZaxis()->SetTitleFont(42);
   frame_46f62690_copy__80->Draw("sameaxis");
   
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
