void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_5__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 16:42:18 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-19.64407,2.25,225.9068);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_45dcb410__65 = new TH1D("frame_45dcb410__65","p_T Balance",25,0,2);
   frame_45dcb410__65->SetBinContent(1,201.3517);
   frame_45dcb410__65->SetMaximum(201.3517);
   frame_45dcb410__65->SetEntries(2);
   frame_45dcb410__65->SetDirectory(0);
   frame_45dcb410__65->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_45dcb410__65->SetLineColor(ci);
   frame_45dcb410__65->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45dcb410__65->GetXaxis()->SetLabelFont(42);
   frame_45dcb410__65->GetXaxis()->SetTitleOffset(1);
   frame_45dcb410__65->GetXaxis()->SetTitleFont(42);
   frame_45dcb410__65->GetYaxis()->SetTitle("1/Events");
   frame_45dcb410__65->GetYaxis()->SetLabelFont(42);
   frame_45dcb410__65->GetYaxis()->SetTitleFont(42);
   frame_45dcb410__65->GetZaxis()->SetLabelFont(42);
   frame_45dcb410__65->GetZaxis()->SetTitleOffset(1);
   frame_45dcb410__65->GetZaxis()->SetTitleFont(42);
   frame_45dcb410__65->Draw("FUNC");
   
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
   22.40016,
   47.3081,
   75.37981,
   128.2328,
   154.7496,
   178.1045,
   166.6096,
   154.8174,
   150.2525,
   105.8053,
   84.3465,
   79.41038,
   40.39667,
   30.1983,
   17.01013,
   13.11392,
   5.355552,
   3.539061,
   2.062839,
   1.767704,
   1.037309,
   0.5651427};
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
   3.292542,
   4.650616,
   6.181138,
   8.151503,
   8.995869,
   9.537066,
   9.194966,
   8.89709,
   8.775205,
   7.384219,
   6.174583,
   6.140245,
   4.085983,
   3.597063,
   2.410566,
   2.121516,
   1.214511,
   1.084155,
   0.7808945,
   0.8426645,
   0.4531738,
   0.445066};
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
   3.292542,
   4.650616,
   6.181138,
   8.151503,
   8.995869,
   9.537066,
   9.194966,
   8.89709,
   8.775205,
   7.384219,
   6.174583,
   6.140245,
   4.085983,
   3.597063,
   2.410566,
   2.121516,
   1.214511,
   1.084155,
   0.7808945,
   0.8426645,
   0.4531738,
   0.445066};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3017,h_dh_central2_fy3017,h_dh_central2_felx3017,h_dh_central2_fehx3017,h_dh_central2_fely3017,h_dh_central2_fehy3017);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23017 = new TH1F("Graph_h_dh_central23017","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23017->SetMinimum(0);
   Graph_h_dh_central23017->SetMaximum(206.4057);
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
   
   Double_t Central_fx17[62] = {
   -0.01684244,
   0.04315756,
   0.1031576,
   0.1331576,
   0.1631576,
   0.1931576,
   0.2231576,
   0.2531576,
   0.2831576,
   0.3131576,
   0.3281576,
   0.3431576,
   0.3581576,
   0.3731576,
   0.3881576,
   0.4031576,
   0.4331576,
   0.4631576,
   0.4931576,
   0.5231576,
   0.5531576,
   0.5831576,
   0.5981576,
   0.6131576,
   0.6281576,
   0.6431576,
   0.6581576,
   0.6731576,
   0.6881576,
   0.7031576,
   0.7181576,
   0.7331576,
   0.7481576,
   0.7631576,
   0.7781576,
   0.7931576,
   0.8081576,
   0.8231576,
   0.8381576,
   0.8531576,
   0.8681576,
   0.8831576,
   0.9131576,
   0.9431576,
   0.9581576,
   0.9731576,
   0.9881576,
   1.003158,
   1.033158,
   1.063158,
   1.093158,
   1.123158,
   1.153158,
   1.183158,
   1.213158,
   1.243158,
   1.273158,
   1.303158,
   1.363158,
   1.423158,
   1.483158,
   1.483158};
   Double_t Central_fy17[62] = {
   0,
   1.02418,
   2.408872,
   3.590134,
   5.249606,
   7.531156,
   10.60024,
   14.63823,
   19.83263,
   26.36277,
   30.17804,
   34.38118,
   38.98345,
   43.99158,
   49.407,
   55.22519,
   68.018,
   82.19199,
   97.44377,
   113.3438,
   129.3481,
   144.8243,
   152.1517,
   159.0897,
   165.5529,
   171.4594,
   176.7322,
   181.3008,
   185.103,
   188.0862,
   190.2087,
   191.4403,
   191.7635,
   191.1739,
   189.6796,
   187.3021,
   184.0748,
   180.0428,
   175.2617,
   169.7962,
   163.7188,
   157.1083,
   142.6228,
   127.0685,
   119.6332,
   112.7338,
   106.3247,
   100.3647,
   89.64645,
   80.32155,
   72.17817,
   65.04115,
   58.76487,
   53.2277,
   48.32762,
   43.97866,
   40.10807,
   36.65408,
   30.79285,
   26.05773,
   22.19878,
   22.19878};
   TGraph *graph = new TGraph(62,Central_fx17,Central_fy17);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central17 = new TH1F("Graph_Central17","Projection of centralf DSCB fit",100,-0.1668424,1.633158);
   Graph_Central17->SetMinimum(0);
   Graph_Central17->SetMaximum(210.9399);
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
   
   TH1D *frame_45dcb410__66 = new TH1D("frame_45dcb410__66","p_T Balance",25,0,2);
   frame_45dcb410__66->SetBinContent(1,201.3517);
   frame_45dcb410__66->SetMaximum(201.3517);
   frame_45dcb410__66->SetEntries(2);
   frame_45dcb410__66->SetDirectory(0);
   frame_45dcb410__66->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45dcb410__66->SetLineColor(ci);
   frame_45dcb410__66->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45dcb410__66->GetXaxis()->SetLabelFont(42);
   frame_45dcb410__66->GetXaxis()->SetTitleOffset(1);
   frame_45dcb410__66->GetXaxis()->SetTitleFont(42);
   frame_45dcb410__66->GetYaxis()->SetTitle("1/Events");
   frame_45dcb410__66->GetYaxis()->SetLabelFont(42);
   frame_45dcb410__66->GetYaxis()->SetTitleFont(42);
   frame_45dcb410__66->GetZaxis()->SetLabelFont(42);
   frame_45dcb410__66->GetZaxis()->SetTitleOffset(1);
   frame_45dcb410__66->GetZaxis()->SetTitleFont(42);
   frame_45dcb410__66->Draw("AXISSAME");
   
   TH1D *norm_c__67 = new TH1D("norm_c__67","",25,0,2);
   norm_c__67->SetBinContent(3,0.9815168);
   norm_c__67->SetBinContent(4,22.40016);
   norm_c__67->SetBinContent(5,47.3081);
   norm_c__67->SetBinContent(6,75.37981);
   norm_c__67->SetBinContent(7,128.2328);
   norm_c__67->SetBinContent(8,154.7496);
   norm_c__67->SetBinContent(9,178.1045);
   norm_c__67->SetBinContent(10,166.6097);
   norm_c__67->SetBinContent(11,154.8174);
   norm_c__67->SetBinContent(12,150.2525);
   norm_c__67->SetBinContent(13,105.8053);
   norm_c__67->SetBinContent(14,84.34649);
   norm_c__67->SetBinContent(15,79.41038);
   norm_c__67->SetBinContent(16,40.39667);
   norm_c__67->SetBinContent(17,30.1983);
   norm_c__67->SetBinContent(18,17.01013);
   norm_c__67->SetBinContent(19,13.11392);
   norm_c__67->SetBinContent(20,5.355552);
   norm_c__67->SetBinContent(21,3.539061);
   norm_c__67->SetBinContent(22,2.062839);
   norm_c__67->SetBinContent(23,1.767704);
   norm_c__67->SetBinContent(24,1.037309);
   norm_c__67->SetBinContent(25,0.5651427);
   norm_c__67->SetBinContent(26,0.9794864);
   norm_c__67->SetBinError(3,0.6943068);
   norm_c__67->SetBinError(4,3.292542);
   norm_c__67->SetBinError(5,4.650616);
   norm_c__67->SetBinError(6,6.181138);
   norm_c__67->SetBinError(7,8.151503);
   norm_c__67->SetBinError(8,8.995869);
   norm_c__67->SetBinError(9,9.537066);
   norm_c__67->SetBinError(10,9.194966);
   norm_c__67->SetBinError(11,8.89709);
   norm_c__67->SetBinError(12,8.775205);
   norm_c__67->SetBinError(13,7.384219);
   norm_c__67->SetBinError(14,6.174583);
   norm_c__67->SetBinError(15,6.140245);
   norm_c__67->SetBinError(16,4.085983);
   norm_c__67->SetBinError(17,3.597063);
   norm_c__67->SetBinError(18,2.410566);
   norm_c__67->SetBinError(19,2.121516);
   norm_c__67->SetBinError(20,1.214511);
   norm_c__67->SetBinError(21,1.084155);
   norm_c__67->SetBinError(22,0.7808945);
   norm_c__67->SetBinError(23,0.8426645);
   norm_c__67->SetBinError(24,0.4531738);
   norm_c__67->SetBinError(25,0.445066);
   norm_c__67->SetBinError(26,0.2437599);
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
   entry=leg->AddEntry("frame_x_c2_45dcb410","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.745971 #pm 0.009076","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.217245 #pm 0.006904","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.562000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_45dcb410_copy__68 = new TH1D("frame_45dcb410_copy__68","p_T Balance",25,0,2);
   frame_45dcb410_copy__68->SetBinContent(1,201.3517);
   frame_45dcb410_copy__68->SetMaximum(201.3517);
   frame_45dcb410_copy__68->SetEntries(2);
   frame_45dcb410_copy__68->SetDirectory(0);
   frame_45dcb410_copy__68->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45dcb410_copy__68->SetLineColor(ci);
   frame_45dcb410_copy__68->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45dcb410_copy__68->GetXaxis()->SetLabelFont(42);
   frame_45dcb410_copy__68->GetXaxis()->SetTitleOffset(1);
   frame_45dcb410_copy__68->GetXaxis()->SetTitleFont(42);
   frame_45dcb410_copy__68->GetYaxis()->SetTitle("1/Events");
   frame_45dcb410_copy__68->GetYaxis()->SetLabelFont(42);
   frame_45dcb410_copy__68->GetYaxis()->SetTitleFont(42);
   frame_45dcb410_copy__68->GetZaxis()->SetLabelFont(42);
   frame_45dcb410_copy__68->GetZaxis()->SetTitleOffset(1);
   frame_45dcb410_copy__68->GetZaxis()->SetTitleFont(42);
   frame_45dcb410_copy__68->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-19.57351,2.25,225.0954);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_45d71b00__69 = new TH1D("frame_45d71b00__69","p_T Balance",25,0,2);
   frame_45d71b00__69->SetBinContent(1,200.6285);
   frame_45d71b00__69->SetMaximum(200.6285);
   frame_45d71b00__69->SetEntries(2);
   frame_45d71b00__69->SetDirectory(0);
   frame_45d71b00__69->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45d71b00__69->SetLineColor(ci);
   frame_45d71b00__69->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45d71b00__69->GetXaxis()->SetLabelFont(42);
   frame_45d71b00__69->GetXaxis()->SetTitleOffset(1);
   frame_45d71b00__69->GetXaxis()->SetTitleFont(42);
   frame_45d71b00__69->GetYaxis()->SetTitle("1/Events");
   frame_45d71b00__69->GetYaxis()->SetLabelFont(42);
   frame_45d71b00__69->GetYaxis()->SetTitleFont(42);
   frame_45d71b00__69->GetZaxis()->SetLabelFont(42);
   frame_45d71b00__69->GetZaxis()->SetTitleOffset(1);
   frame_45d71b00__69->GetZaxis()->SetTitleFont(42);
   frame_45d71b00__69->Draw("FUNC");
   
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
   19.30204,
   46.35928,
   72.76424,
   113.9898,
   150.1912,
   174.6788,
   173.1006,
   160.1855,
   152.2454,
   123.0861,
   93.67516,
   83.52069,
   48.26702,
   33.58743,
   21.39619,
   11.02336,
   6.579157,
   3.910053,
   1.985819,
   0.9108786,
   0.589776,
   0.2035386};
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
   3.31233,
   4.712423,
   6.086225,
   7.737525,
   9.022689,
   9.539365,
   9.354107,
   9.08911,
   8.875386,
   7.977655,
   6.74183,
   6.367811,
   4.669226,
   3.926715,
   2.856433,
   1.899519,
   1.526915,
   1.166178,
   0.7464117,
   0.5323557,
   0.2532082,
   0.1737785};
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
   3.31233,
   4.712423,
   6.086225,
   7.737525,
   9.022689,
   9.539365,
   9.354107,
   9.08911,
   8.875386,
   7.977655,
   6.74183,
   6.367811,
   4.669226,
   3.926715,
   2.856433,
   1.899519,
   1.526915,
   1.166178,
   0.7464117,
   0.5323557,
   0.2532082,
   0.1737785};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3018,h_dh_up2_fy3018,h_dh_up2_felx3018,h_dh_up2_fehx3018,h_dh_up2_fely3018,h_dh_up2_fehy3018);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23018 = new TH1F("Graph_h_dh_up23018","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23018->SetMinimum(0);
   Graph_h_dh_up23018->SetMaximum(202.6399);
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
   
   Double_t up_fx18[57] = {
   0.02175741,
   0.08175741,
   0.1417574,
   0.1717574,
   0.2017574,
   0.2317574,
   0.2617574,
   0.2917574,
   0.3217574,
   0.3517574,
   0.3817574,
   0.4117574,
   0.4417574,
   0.4717574,
   0.5017574,
   0.5617573,
   0.5917573,
   0.6217573,
   0.6367573,
   0.6517573,
   0.6667573,
   0.6817573,
   0.6967573,
   0.7117573,
   0.7267573,
   0.7417573,
   0.7567573,
   0.7717573,
   0.7867573,
   0.8017573,
   0.8167573,
   0.8317573,
   0.8467573,
   0.8617573,
   0.8767573,
   0.8917573,
   0.9067573,
   0.9217573,
   0.9517573,
   0.9817573,
   1.041757,
   1.056757,
   1.071757,
   1.086757,
   1.101757,
   1.131757,
   1.161757,
   1.191757,
   1.221757,
   1.251757,
   1.281757,
   1.311757,
   1.341757,
   1.401757,
   1.461757,
   1.521757,
   1.521757};
   Double_t up_fy18[57] = {
   0.908278,
   2.050006,
   4.326398,
   6.1288,
   8.537549,
   11.69499,
   15.75343,
   20.86696,
   27.18017,
   34.81401,
   43.84949,
   54.31052,
   66.1473,
   79.22261,
   93.30285,
   123.0589,
   137.8114,
   151.7631,
   158.2605,
   164.3448,
   169.9482,
   175.0067,
   179.4608,
   183.2576,
   186.3509,
   188.7028,
   190.284,
   191.0748,
   191.0652,
   190.2555,
   188.6557,
   186.2858,
   183.1753,
   179.3623,
   174.8931,
   169.821,
   164.2054,
   158.1104,
   144.7566,
   130.3242,
   100.7062,
   94.12025,
   88.06399,
   82.48712,
   77.3448,
   68.20803,
   60.38145,
   53.64593,
   47.82395,
   42.77077,
   38.36772,
   34.51695,
   31.13739,
   25.5328,
   21.13436,
   17.64356,
   17.64356};
   graph = new TGraph(57,up_fx18,up_fy18);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up18 = new TH1F("Graph_up18","Projection of upf DSCB fit",100,0,1.671757);
   Graph_up18->SetMinimum(0.8174502);
   Graph_up18->SetMaximum(210.0914);
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
   
   TH1D *frame_45d71b00__70 = new TH1D("frame_45d71b00__70","p_T Balance",25,0,2);
   frame_45d71b00__70->SetBinContent(1,200.6285);
   frame_45d71b00__70->SetMaximum(200.6285);
   frame_45d71b00__70->SetEntries(2);
   frame_45d71b00__70->SetDirectory(0);
   frame_45d71b00__70->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45d71b00__70->SetLineColor(ci);
   frame_45d71b00__70->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45d71b00__70->GetXaxis()->SetLabelFont(42);
   frame_45d71b00__70->GetXaxis()->SetTitleOffset(1);
   frame_45d71b00__70->GetXaxis()->SetTitleFont(42);
   frame_45d71b00__70->GetYaxis()->SetTitle("1/Events");
   frame_45d71b00__70->GetYaxis()->SetLabelFont(42);
   frame_45d71b00__70->GetYaxis()->SetTitleFont(42);
   frame_45d71b00__70->GetZaxis()->SetLabelFont(42);
   frame_45d71b00__70->GetZaxis()->SetTitleOffset(1);
   frame_45d71b00__70->GetZaxis()->SetTitleFont(42);
   frame_45d71b00__70->Draw("AXISSAME");
   
   TH1D *norm_u__71 = new TH1D("norm_u__71","",25,0,2);
   norm_u__71->SetBinContent(4,19.30204);
   norm_u__71->SetBinContent(5,46.35928);
   norm_u__71->SetBinContent(6,72.76425);
   norm_u__71->SetBinContent(7,113.9898);
   norm_u__71->SetBinContent(8,150.1912);
   norm_u__71->SetBinContent(9,174.6788);
   norm_u__71->SetBinContent(10,173.1006);
   norm_u__71->SetBinContent(11,160.1855);
   norm_u__71->SetBinContent(12,152.2454);
   norm_u__71->SetBinContent(13,123.0861);
   norm_u__71->SetBinContent(14,93.67516);
   norm_u__71->SetBinContent(15,83.52069);
   norm_u__71->SetBinContent(16,48.26702);
   norm_u__71->SetBinContent(17,33.58743);
   norm_u__71->SetBinContent(18,21.39619);
   norm_u__71->SetBinContent(19,11.02336);
   norm_u__71->SetBinContent(20,6.579157);
   norm_u__71->SetBinContent(21,3.910052);
   norm_u__71->SetBinContent(22,1.985819);
   norm_u__71->SetBinContent(23,0.9108786);
   norm_u__71->SetBinContent(24,0.589776);
   norm_u__71->SetBinContent(25,0.2035386);
   norm_u__71->SetBinContent(26,1.318855);
   norm_u__71->SetBinError(4,3.31233);
   norm_u__71->SetBinError(5,4.712423);
   norm_u__71->SetBinError(6,6.086225);
   norm_u__71->SetBinError(7,7.737525);
   norm_u__71->SetBinError(8,9.022689);
   norm_u__71->SetBinError(9,9.539365);
   norm_u__71->SetBinError(10,9.354107);
   norm_u__71->SetBinError(11,9.08911);
   norm_u__71->SetBinError(12,8.875386);
   norm_u__71->SetBinError(13,7.977655);
   norm_u__71->SetBinError(14,6.74183);
   norm_u__71->SetBinError(15,6.367811);
   norm_u__71->SetBinError(16,4.669226);
   norm_u__71->SetBinError(17,3.926715);
   norm_u__71->SetBinError(18,2.856433);
   norm_u__71->SetBinError(19,1.899519);
   norm_u__71->SetBinError(20,1.526915);
   norm_u__71->SetBinError(21,1.166178);
   norm_u__71->SetBinError(22,0.7464117);
   norm_u__71->SetBinError(23,0.5323557);
   norm_u__71->SetBinError(24,0.2532082);
   norm_u__71->SetBinError(25,0.1737785);
   norm_u__71->SetBinError(26,0.3151267);
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
   entry=leg->AddEntry("frame_x_u2_45d71b00","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.813995 #pm 0.006989","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.262987 #pm 0.005344","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.609000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_45d71b00_copy__72 = new TH1D("frame_45d71b00_copy__72","p_T Balance",25,0,2);
   frame_45d71b00_copy__72->SetBinContent(1,200.6285);
   frame_45d71b00_copy__72->SetMaximum(200.6285);
   frame_45d71b00_copy__72->SetEntries(2);
   frame_45d71b00_copy__72->SetDirectory(0);
   frame_45d71b00_copy__72->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45d71b00_copy__72->SetLineColor(ci);
   frame_45d71b00_copy__72->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45d71b00_copy__72->GetXaxis()->SetLabelFont(42);
   frame_45d71b00_copy__72->GetXaxis()->SetTitleOffset(1);
   frame_45d71b00_copy__72->GetXaxis()->SetTitleFont(42);
   frame_45d71b00_copy__72->GetYaxis()->SetTitle("1/Events");
   frame_45d71b00_copy__72->GetYaxis()->SetLabelFont(42);
   frame_45d71b00_copy__72->GetYaxis()->SetTitleFont(42);
   frame_45d71b00_copy__72->GetZaxis()->SetLabelFont(42);
   frame_45d71b00_copy__72->GetZaxis()->SetTitleOffset(1);
   frame_45d71b00_copy__72->GetZaxis()->SetTitleFont(42);
   frame_45d71b00_copy__72->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-32.62643,2.25,203.6974);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_45d1ec60__73 = new TH1D("frame_45d1ec60__73","p_T Balance",25,0,2);
   frame_45d1ec60__73->SetBinContent(1,198.9709);
   frame_45d1ec60__73->SetMinimum(-8.994046);
   frame_45d1ec60__73->SetMaximum(198.9709);
   frame_45d1ec60__73->SetEntries(2);
   frame_45d1ec60__73->SetDirectory(0);
   frame_45d1ec60__73->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45d1ec60__73->SetLineColor(ci);
   frame_45d1ec60__73->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45d1ec60__73->GetXaxis()->SetLabelFont(42);
   frame_45d1ec60__73->GetXaxis()->SetTitleOffset(1);
   frame_45d1ec60__73->GetXaxis()->SetTitleFont(42);
   frame_45d1ec60__73->GetYaxis()->SetTitle("1/Events");
   frame_45d1ec60__73->GetYaxis()->SetLabelFont(42);
   frame_45d1ec60__73->GetYaxis()->SetTitleFont(42);
   frame_45d1ec60__73->GetZaxis()->SetLabelFont(42);
   frame_45d1ec60__73->GetZaxis()->SetTitleOffset(1);
   frame_45d1ec60__73->GetZaxis()->SetTitleFont(42);
   frame_45d1ec60__73->Draw("FUNC");
   
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
   24.54998,
   58.48387,
   77.54068,
   131.7779,
   157.2308,
   169.8704,
   170.7,
   149.8548,
   140.9962,
   94.71166,
   83.50937,
   65.08598,
   45.19743,
   29.54876,
   15.27129,
   10.96661,
   5.511,
   4.033548,
   0.999939,
   1.89122,
   1.430213,
   0.6355716};
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
   3.381943,
   5.190479,
   6.32307,
   8.166202,
   8.939735,
   9.152056,
   9.180947,
   8.721544,
   8.458009,
   6.856035,
   6.117478,
   5.480123,
   4.30409,
   3.487607,
   2.322674,
   1.85087,
   1.262639,
   1.094674,
   0.5576524,
   0.7580955,
   0.6240083,
   0.3978157};
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
   3.381943,
   5.190479,
   6.32307,
   8.166202,
   8.939735,
   9.152056,
   9.180947,
   8.721544,
   8.458009,
   6.856035,
   6.117478,
   5.480123,
   4.30409,
   3.487607,
   2.322674,
   1.85087,
   1.262639,
   1.094674,
   0.5576524,
   0.7580955,
   0.6240083,
   0.3978157};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3019,h_dh_down2_fy3019,h_dh_down2_felx3019,h_dh_down2_fehx3019,h_dh_down2_fely3019,h_dh_down2_fehy3019);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23019 = new TH1F("Graph_h_dh_down23019","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23019->SetMinimum(-17.98809);
   Graph_h_dh_down23019->SetMaximum(197.869);
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
   
   Double_t down_fx19[63] = {
   -0.0263478,
   0.0336522,
   0.0936522,
   0.1236522,
   0.1536522,
   0.1836522,
   0.2136522,
   0.2436522,
   0.2736522,
   0.3036522,
   0.3186522,
   0.3336522,
   0.3486522,
   0.3636522,
   0.3786522,
   0.3936522,
   0.4236522,
   0.4536522,
   0.4836522,
   0.5136522,
   0.5436522,
   0.5736522,
   0.5886522,
   0.6036522,
   0.6186522,
   0.6336522,
   0.6486522,
   0.6636522,
   0.6786522,
   0.6936522,
   0.7086522,
   0.7236522,
   0.7386522,
   0.7536522,
   0.7686522,
   0.7836522,
   0.7986522,
   0.8136522,
   0.8286522,
   0.8436522,
   0.8586522,
   0.8736522,
   0.9036522,
   0.9336522,
   0.9486522,
   0.9636522,
   0.9786522,
   0.9936522,
   1.008652,
   1.023652,
   1.053652,
   1.083652,
   1.113652,
   1.143652,
   1.173652,
   1.203652,
   1.233652,
   1.263652,
   1.293652,
   1.353652,
   1.413652,
   1.473652,
   1.473652};
   Double_t down_fy19[63] = {
   0,
   1.040102,
   2.440071,
   3.632044,
   5.304245,
   7.600105,
   10.68413,
   14.7361,
   19.94113,
   26.47527,
   30.2888,
   34.48694,
   39.08032,
   44.07503,
   49.47183,
   55.26551,
   67.98913,
   82.06319,
   97.18092,
   112.9113,
   128.7114,
   143.953,
   151.1537,
   157.9603,
   164.2887,
   170.0586,
   175.1945,
   179.6276,
   183.2976,
   186.1535,
   188.1554,
   189.2749,
   189.4961,
   188.8159,
   187.2439,
   184.8024,
   181.5259,
   177.46,
   172.6606,
   167.1925,
   161.1281,
   154.5457,
   140.1589,
   124.7119,
   116.9018,
   109.629,
   102.9131,
   96.70369,
   90.9556,
   85.62832,
   76.09408,
   67.85065,
   60.69389,
   54.45633,
   48.99988,
   44.21004,
   39.99143,
   36.26422,
   32.96128,
   27.41025,
   22.98012,
   19.40993,
   19.40993};
   graph = new TGraph(63,down_fx19,down_fy19);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down19 = new TH1F("Graph_down19","Projection of downf DSCB fit",100,-0.1763478,1.623652);
   Graph_down19->SetMinimum(0);
   Graph_down19->SetMaximum(208.4457);
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
   
   TH1D *frame_45d1ec60__74 = new TH1D("frame_45d1ec60__74","p_T Balance",25,0,2);
   frame_45d1ec60__74->SetBinContent(1,198.9709);
   frame_45d1ec60__74->SetMinimum(-8.994046);
   frame_45d1ec60__74->SetMaximum(198.9709);
   frame_45d1ec60__74->SetEntries(2);
   frame_45d1ec60__74->SetDirectory(0);
   frame_45d1ec60__74->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45d1ec60__74->SetLineColor(ci);
   frame_45d1ec60__74->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45d1ec60__74->GetXaxis()->SetLabelFont(42);
   frame_45d1ec60__74->GetXaxis()->SetTitleOffset(1);
   frame_45d1ec60__74->GetXaxis()->SetTitleFont(42);
   frame_45d1ec60__74->GetYaxis()->SetTitle("1/Events");
   frame_45d1ec60__74->GetYaxis()->SetLabelFont(42);
   frame_45d1ec60__74->GetYaxis()->SetTitleFont(42);
   frame_45d1ec60__74->GetZaxis()->SetLabelFont(42);
   frame_45d1ec60__74->GetZaxis()->SetTitleOffset(1);
   frame_45d1ec60__74->GetZaxis()->SetTitleFont(42);
   frame_45d1ec60__74->Draw("AXISSAME");
   
   TH1D *norm_d__75 = new TH1D("norm_d__75","",25,0,2);
   norm_d__75->SetBinContent(3,0.03282912);
   norm_d__75->SetBinContent(4,24.54998);
   norm_d__75->SetBinContent(5,58.48387);
   norm_d__75->SetBinContent(6,77.54068);
   norm_d__75->SetBinContent(7,131.7779);
   norm_d__75->SetBinContent(8,157.2308);
   norm_d__75->SetBinContent(9,169.8704);
   norm_d__75->SetBinContent(10,170.7);
   norm_d__75->SetBinContent(11,149.8548);
   norm_d__75->SetBinContent(12,140.9962);
   norm_d__75->SetBinContent(13,94.71167);
   norm_d__75->SetBinContent(14,83.50937);
   norm_d__75->SetBinContent(15,65.08598);
   norm_d__75->SetBinContent(16,45.19743);
   norm_d__75->SetBinContent(17,29.54876);
   norm_d__75->SetBinContent(18,15.27129);
   norm_d__75->SetBinContent(19,10.96661);
   norm_d__75->SetBinContent(20,5.511);
   norm_d__75->SetBinContent(21,4.033548);
   norm_d__75->SetBinContent(22,0.999939);
   norm_d__75->SetBinContent(23,1.89122);
   norm_d__75->SetBinContent(24,1.430213);
   norm_d__75->SetBinContent(25,0.6355716);
   norm_d__75->SetBinContent(26,1.001522);
   norm_d__75->SetBinError(3,0.03282912);
   norm_d__75->SetBinError(4,3.381943);
   norm_d__75->SetBinError(5,5.190479);
   norm_d__75->SetBinError(6,6.32307);
   norm_d__75->SetBinError(7,8.166202);
   norm_d__75->SetBinError(8,8.939735);
   norm_d__75->SetBinError(9,9.152056);
   norm_d__75->SetBinError(10,9.180947);
   norm_d__75->SetBinError(11,8.721544);
   norm_d__75->SetBinError(12,8.458009);
   norm_d__75->SetBinError(13,6.856035);
   norm_d__75->SetBinError(14,6.117478);
   norm_d__75->SetBinError(15,5.480123);
   norm_d__75->SetBinError(16,4.30409);
   norm_d__75->SetBinError(17,3.487607);
   norm_d__75->SetBinError(18,2.322674);
   norm_d__75->SetBinError(19,1.85087);
   norm_d__75->SetBinError(20,1.262639);
   norm_d__75->SetBinError(21,1.094674);
   norm_d__75->SetBinError(22,0.5576524);
   norm_d__75->SetBinError(23,0.7580955);
   norm_d__75->SetBinError(24,0.6240083);
   norm_d__75->SetBinError(25,0.3978157);
   norm_d__75->SetBinError(26,0.2466116);
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
   entry=leg->AddEntry("frame_x_d2_45d1ec60","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.781589 #pm 0.006975","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.257265 #pm 0.005288","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.633000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_45d1ec60_copy__76 = new TH1D("frame_45d1ec60_copy__76","p_T Balance",25,0,2);
   frame_45d1ec60_copy__76->SetBinContent(1,198.9709);
   frame_45d1ec60_copy__76->SetMinimum(-8.994046);
   frame_45d1ec60_copy__76->SetMaximum(198.9709);
   frame_45d1ec60_copy__76->SetEntries(2);
   frame_45d1ec60_copy__76->SetDirectory(0);
   frame_45d1ec60_copy__76->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45d1ec60_copy__76->SetLineColor(ci);
   frame_45d1ec60_copy__76->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45d1ec60_copy__76->GetXaxis()->SetLabelFont(42);
   frame_45d1ec60_copy__76->GetXaxis()->SetTitleOffset(1);
   frame_45d1ec60_copy__76->GetXaxis()->SetTitleFont(42);
   frame_45d1ec60_copy__76->GetYaxis()->SetTitle("1/Events");
   frame_45d1ec60_copy__76->GetYaxis()->SetLabelFont(42);
   frame_45d1ec60_copy__76->GetYaxis()->SetTitleFont(42);
   frame_45d1ec60_copy__76->GetZaxis()->SetLabelFont(42);
   frame_45d1ec60_copy__76->GetZaxis()->SetTitleOffset(1);
   frame_45d1ec60_copy__76->GetZaxis()->SetTitleFont(42);
   frame_45d1ec60_copy__76->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-23.5101,2.25,211.5909);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_45dd94c0__77 = new TH1D("frame_45dd94c0__77","p_T Balance",25,0,2);
   frame_45dd94c0__77->SetBinContent(1,206.8888);
   frame_45dd94c0__77->SetMaximum(206.8888);
   frame_45dd94c0__77->SetEntries(1);
   frame_45dd94c0__77->SetDirectory(0);
   frame_45dd94c0__77->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45dd94c0__77->SetLineColor(ci);
   frame_45dd94c0__77->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45dd94c0__77->GetXaxis()->SetLabelFont(42);
   frame_45dd94c0__77->GetXaxis()->SetTitleOffset(1);
   frame_45dd94c0__77->GetXaxis()->SetTitleFont(42);
   frame_45dd94c0__77->GetYaxis()->SetTitle("1/Events");
   frame_45dd94c0__77->GetYaxis()->SetLabelFont(42);
   frame_45dd94c0__77->GetYaxis()->SetTitleFont(42);
   frame_45dd94c0__77->GetZaxis()->SetLabelFont(42);
   frame_45dd94c0__77->GetZaxis()->SetTitleOffset(1);
   frame_45dd94c0__77->GetZaxis()->SetTitleFont(42);
   frame_45dd94c0__77->Draw("FUNC");
   
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
   36,
   72,
   99,
   123,
   147,
   166,
   183,
   154,
   129,
   99,
   77,
   60,
   49,
   24,
   25,
   10,
   5,
   8,
   2,
   3,
   1,
   3};
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
   5.971996,
   8.465529,
   9.933044,
   10.6018,
   11.63466,
   12.3938,
   13.03699,
   11.91974,
   10.86882,
   9.933044,
   8.755868,
   7.724317,
   6.976026,
   4.864612,
   4.966335,
   3.108694,
   2.159691,
   2.768386,
   1.291815,
   1.632705,
   0.8272462,
   1.632705};
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
   7.055545,
   9.524592,
   10.9834,
   11.6018,
   12.63466,
   13.3938,
   14.03699,
   12.91974,
   11.86882,
   10.9834,
   9.812979,
   8.789023,
   8.047634,
   5.966932,
   6.066589,
   4.26695,
   3.382473,
   3.945142,
   2.63786,
   2.918186,
   2.299527,
   2.918186};
   grae = new TGraphAsymmErrors(25,h_dh_data2_fx3020,h_dh_data2_fy3020,h_dh_data2_felx3020,h_dh_data2_fehx3020,h_dh_data2_fely3020,h_dh_data2_fehy3020);
   grae->SetName("h_dh_data2");
   grae->SetTitle("Histogram of dh_data2_plot__x_o2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_data23020 = new TH1F("Graph_h_dh_data23020","Histogram of dh_data2_plot__x_o2",100,0,2.2);
   Graph_h_dh_data23020->SetMinimum(0);
   Graph_h_dh_data23020->SetMaximum(216.7407);
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
   
   Double_t observation_fx20[59] = {
   0.004648805,
   0.06190123,
   0.09052744,
   0.1191537,
   0.1477799,
   0.1764061,
   0.2050323,
   0.2336585,
   0.2622847,
   0.2909109,
   0.3195371,
   0.3481633,
   0.3767896,
   0.4054158,
   0.434042,
   0.4626682,
   0.5199206,
   0.5485468,
   0.577173,
   0.5914861,
   0.6057993,
   0.6201124,
   0.6344255,
   0.6487386,
   0.6630517,
   0.6773648,
   0.6916779,
   0.705991,
   0.7203041,
   0.7346172,
   0.7489303,
   0.7632434,
   0.7775565,
   0.7918696,
   0.8061827,
   0.8204958,
   0.8348089,
   0.8491221,
   0.8634352,
   0.8920614,
   0.9206876,
   0.9350007,
   0.9493138,
   0.9636269,
   0.97794,
   1.006566,
   1.035192,
   1.063819,
   1.092445,
   1.121071,
   1.149697,
   1.178323,
   1.20695,
   1.235576,
   1.264202,
   1.321455,
   1.378707,
   1.435959,
   1.435959};
   Double_t observation_fy20[59] = {
   1.202754,
   2.599423,
   3.730912,
   5.270016,
   7.32601,
   10.02263,
   13.49444,
   17.88079,
   23.31725,
   29.92448,
   37.79503,
   46.97876,
   57.46814,
   69.18492,
   81.96991,
   95.57764,
   123.8614,
   137.662,
   150.5743,
   156.5368,
   162.0864,
   167.1634,
   171.712,
   175.6811,
   179.025,
   181.7052,
   183.69,
   184.956,
   185.4881,
   185.2799,
   184.334,
   182.6615,
   180.2824,
   177.2248,
   173.5242,
   169.2234,
   164.3711,
   159.0213,
   153.2321,
   140.583,
   126.933,
   120.0668,
   113.6458,
   107.6484,
   102.0415,
   91.88115,
   82.95453,
   75.08612,
   68.1289,
   61.95913,
   56.47223,
   51.57949,
   47.20533,
   43.28519,
   39.76365,
   33.7323,
   28.80234,
   24.74101,
   24.74101};
   graph = new TGraph(59,observation_fx20,observation_fy20);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation20 = new TH1F("Graph_observation20","Projection of obsf DSCB fit",100,0,1.57909);
   Graph_observation20->SetMinimum(1.082479);
   Graph_observation20->SetMaximum(203.9166);
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
   
   TH1D *frame_45dd94c0__78 = new TH1D("frame_45dd94c0__78","p_T Balance",25,0,2);
   frame_45dd94c0__78->SetBinContent(1,206.8888);
   frame_45dd94c0__78->SetMaximum(206.8888);
   frame_45dd94c0__78->SetEntries(1);
   frame_45dd94c0__78->SetDirectory(0);
   frame_45dd94c0__78->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45dd94c0__78->SetLineColor(ci);
   frame_45dd94c0__78->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45dd94c0__78->GetXaxis()->SetLabelFont(42);
   frame_45dd94c0__78->GetXaxis()->SetTitleOffset(1);
   frame_45dd94c0__78->GetXaxis()->SetTitleFont(42);
   frame_45dd94c0__78->GetYaxis()->SetTitle("1/Events");
   frame_45dd94c0__78->GetYaxis()->SetLabelFont(42);
   frame_45dd94c0__78->GetYaxis()->SetTitleFont(42);
   frame_45dd94c0__78->GetZaxis()->SetLabelFont(42);
   frame_45dd94c0__78->GetZaxis()->SetTitleOffset(1);
   frame_45dd94c0__78->GetZaxis()->SetTitleFont(42);
   frame_45dd94c0__78->Draw("AXISSAME");
   
   TH1D *norm_o__79 = new TH1D("norm_o__79","",25,0,2);
   norm_o__79->SetBinContent(3,1);
   norm_o__79->SetBinContent(4,36);
   norm_o__79->SetBinContent(5,72);
   norm_o__79->SetBinContent(6,99);
   norm_o__79->SetBinContent(7,123);
   norm_o__79->SetBinContent(8,147);
   norm_o__79->SetBinContent(9,166);
   norm_o__79->SetBinContent(10,183);
   norm_o__79->SetBinContent(11,154);
   norm_o__79->SetBinContent(12,129);
   norm_o__79->SetBinContent(13,99);
   norm_o__79->SetBinContent(14,77);
   norm_o__79->SetBinContent(15,60);
   norm_o__79->SetBinContent(16,49);
   norm_o__79->SetBinContent(17,24);
   norm_o__79->SetBinContent(18,25);
   norm_o__79->SetBinContent(19,10);
   norm_o__79->SetBinContent(20,5);
   norm_o__79->SetBinContent(21,8);
   norm_o__79->SetBinContent(22,2);
   norm_o__79->SetBinContent(23,3);
   norm_o__79->SetBinContent(24,1);
   norm_o__79->SetBinContent(25,3);
   norm_o__79->SetBinContent(26,1);
   norm_o__79->SetMinimum(0);
   norm_o__79->SetMaximum(402.6);
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
   entry=leg->AddEntry("frame_x_o2_45dd94c0","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.710505 #pm 0.014579","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.217609 #pm 0.010403","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.915000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_45dd94c0_copy__80 = new TH1D("frame_45dd94c0_copy__80","p_T Balance",25,0,2);
   frame_45dd94c0_copy__80->SetBinContent(1,206.8888);
   frame_45dd94c0_copy__80->SetMaximum(206.8888);
   frame_45dd94c0_copy__80->SetEntries(1);
   frame_45dd94c0_copy__80->SetDirectory(0);
   frame_45dd94c0_copy__80->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45dd94c0_copy__80->SetLineColor(ci);
   frame_45dd94c0_copy__80->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45dd94c0_copy__80->GetXaxis()->SetLabelFont(42);
   frame_45dd94c0_copy__80->GetXaxis()->SetTitleOffset(1);
   frame_45dd94c0_copy__80->GetXaxis()->SetTitleFont(42);
   frame_45dd94c0_copy__80->GetYaxis()->SetTitle("1/Events");
   frame_45dd94c0_copy__80->GetYaxis()->SetLabelFont(42);
   frame_45dd94c0_copy__80->GetYaxis()->SetTitleFont(42);
   frame_45dd94c0_copy__80->GetZaxis()->SetLabelFont(42);
   frame_45dd94c0_copy__80->GetZaxis()->SetTitleOffset(1);
   frame_45dd94c0_copy__80->GetZaxis()->SetTitleFont(42);
   frame_45dd94c0_copy__80->Draw("sameaxis");
   
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
