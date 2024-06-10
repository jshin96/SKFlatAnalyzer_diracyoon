void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_3__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 17:02:10 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-9.339289,2.25,70.29806);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3b67ca00__33 = new TH1D("frame_3b67ca00__33","p_T Balance",25,0,2);
   frame_3b67ca00__33->SetBinContent(1,62.33433);
   frame_3b67ca00__33->SetMinimum(-2.968301);
   frame_3b67ca00__33->SetMaximum(62.33433);
   frame_3b67ca00__33->SetEntries(1);
   frame_3b67ca00__33->SetDirectory(0);
   frame_3b67ca00__33->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_3b67ca00__33->SetLineColor(ci);
   frame_3b67ca00__33->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b67ca00__33->GetXaxis()->SetLabelFont(42);
   frame_3b67ca00__33->GetXaxis()->SetTitleOffset(1);
   frame_3b67ca00__33->GetXaxis()->SetTitleFont(42);
   frame_3b67ca00__33->GetYaxis()->SetTitle("1/Events");
   frame_3b67ca00__33->GetYaxis()->SetLabelFont(42);
   frame_3b67ca00__33->GetYaxis()->SetTitleFont(42);
   frame_3b67ca00__33->GetZaxis()->SetLabelFont(42);
   frame_3b67ca00__33->GetZaxis()->SetTitleOffset(1);
   frame_3b67ca00__33->GetZaxis()->SetTitleFont(42);
   frame_3b67ca00__33->Draw("FUNC");
   
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
   2.119205,
   2.433735,
   4.68248,
   7.308963,
   15.53993,
   22.60433,
   37.02242,
   43.78388,
   54.81411,
   44.65845,
   40.34414,
   25.94881,
   14.11148,
   10.41352,
   6.26664,
   2.440598,
   0.6968217,
   0.6595827,
   0.4824352,
   0.04134189,
   0.1893215,
   0,
   0};
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
   0.8273424,
   0.8092143,
   1.252641,
   1.61389,
   2.317652,
   2.95127,
   3.780387,
   4.051212,
   4.551918,
   4.087364,
   3.971163,
   3.048693,
   2.012684,
   1.94288,
   1.310238,
   0.7592242,
   0.3955516,
   0.3129116,
   0.2979374,
   0.04134189,
   0.1893215,
   0,
   0};
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
   0.8273424,
   0.8092143,
   1.252641,
   1.61389,
   2.317652,
   2.95127,
   3.780387,
   4.051212,
   4.551918,
   4.087364,
   3.971163,
   3.048693,
   2.012684,
   1.94288,
   1.310238,
   0.7592242,
   0.3955516,
   0.3129116,
   0.2979374,
   0.04134189,
   0.1893215,
   0,
   0};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3009,h_dh_central2_fy3009,h_dh_central2_felx3009,h_dh_central2_fehx3009,h_dh_central2_fely3009,h_dh_central2_fehy3009);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23009 = new TH1F("Graph_h_dh_central23009","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23009->SetMinimum(-5.936602);
   Graph_h_dh_central23009->SetMaximum(65.30263);
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
   
   Double_t Central_fx9[59] = {
   0.282684,
   0.3050893,
   0.3274946,
   0.3498999,
   0.3723052,
   0.3947105,
   0.4171158,
   0.4395211,
   0.4619264,
   0.4843317,
   0.506737,
   0.5291423,
   0.5515475,
   0.5739528,
   0.5963581,
   0.6411687,
   0.6859793,
   0.7083846,
   0.7307899,
   0.7419925,
   0.7531952,
   0.7643978,
   0.7756005,
   0.7868031,
   0.7980058,
   0.8092084,
   0.8204111,
   0.8316137,
   0.8428164,
   0.854019,
   0.8652216,
   0.8764243,
   0.8876269,
   0.8988296,
   0.9100322,
   0.9212349,
   0.9324375,
   0.9436402,
   0.9548428,
   0.9772481,
   0.9996534,
   1.022059,
   1.044464,
   1.089275,
   1.11168,
   1.134085,
   1.15649,
   1.178896,
   1.190098,
   1.201301,
   1.212504,
   1.223706,
   1.246112,
   1.268517,
   1.290922,
   1.313327,
   1.358138,
   1.402949,
   1.402949};
   Double_t Central_fy9[59] = {
   1.253161,
   1.67265,
   2.206483,
   2.87669,
   3.706661,
   4.720302,
   5.940923,
   7.389843,
   9.084765,
   11.03797,
   13.25446,
   15.73013,
   18.45013,
   21.38768,
   24.50334,
   31.04845,
   37.5356,
   40.54999,
   43.29477,
   44.53938,
   45.68538,
   46.72342,
   47.64488,
   48.44201,
   49.10802,
   49.63716,
   50.02485,
   50.26768,
   50.36355,
   50.31159,
   50.11226,
   49.76733,
   49.2798,
   48.65392,
   47.89509,
   47.00981,
   46.00555,
   44.89069,
   43.67437,
   40.97701,
   37.99716,
   34.82243,
   31.54019,
   24.97849,
   21.84051,
   18.87368,
   16.11936,
   13.6062,
   12.51195,
   11.58135,
   10.7802,
   10.08321,
   8.929697,
   8.014034,
   7.269442,
   6.652017,
   5.687232,
   4.967845,
   4.967845};
   TGraph *graph = new TGraph(59,Central_fx9,Central_fy9);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central9 = new TH1F("Graph_Central9","Projection of centralf DSCB fit",100,0.1706576,1.514975);
   Graph_Central9->SetMinimum(1.127845);
   Graph_Central9->SetMaximum(55.27458);
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
   
   TH1D *frame_3b67ca00__34 = new TH1D("frame_3b67ca00__34","p_T Balance",25,0,2);
   frame_3b67ca00__34->SetBinContent(1,62.33433);
   frame_3b67ca00__34->SetMinimum(-2.968301);
   frame_3b67ca00__34->SetMaximum(62.33433);
   frame_3b67ca00__34->SetEntries(1);
   frame_3b67ca00__34->SetDirectory(0);
   frame_3b67ca00__34->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b67ca00__34->SetLineColor(ci);
   frame_3b67ca00__34->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b67ca00__34->GetXaxis()->SetLabelFont(42);
   frame_3b67ca00__34->GetXaxis()->SetTitleOffset(1);
   frame_3b67ca00__34->GetXaxis()->SetTitleFont(42);
   frame_3b67ca00__34->GetYaxis()->SetTitle("1/Events");
   frame_3b67ca00__34->GetYaxis()->SetLabelFont(42);
   frame_3b67ca00__34->GetYaxis()->SetTitleFont(42);
   frame_3b67ca00__34->GetZaxis()->SetLabelFont(42);
   frame_3b67ca00__34->GetZaxis()->SetTitleOffset(1);
   frame_3b67ca00__34->GetZaxis()->SetTitleFont(42);
   frame_3b67ca00__34->Draw("AXISSAME");
   
   TH1D *norm_c__35 = new TH1D("norm_c__35","",25,0,2);
   norm_c__35->SetBinContent(3,2.119205);
   norm_c__35->SetBinContent(4,2.433735);
   norm_c__35->SetBinContent(5,4.68248);
   norm_c__35->SetBinContent(6,7.308963);
   norm_c__35->SetBinContent(7,15.53993);
   norm_c__35->SetBinContent(8,22.60433);
   norm_c__35->SetBinContent(9,37.02242);
   norm_c__35->SetBinContent(10,43.78388);
   norm_c__35->SetBinContent(11,54.8141);
   norm_c__35->SetBinContent(12,44.65846);
   norm_c__35->SetBinContent(13,40.34414);
   norm_c__35->SetBinContent(14,25.94881);
   norm_c__35->SetBinContent(15,14.11148);
   norm_c__35->SetBinContent(16,10.41352);
   norm_c__35->SetBinContent(17,6.266639);
   norm_c__35->SetBinContent(18,2.440598);
   norm_c__35->SetBinContent(19,0.6968217);
   norm_c__35->SetBinContent(20,0.6595827);
   norm_c__35->SetBinContent(21,0.4824352);
   norm_c__35->SetBinContent(22,0.04134189);
   norm_c__35->SetBinContent(23,0.1893215);
   norm_c__35->SetBinContent(26,0.03109237);
   norm_c__35->SetBinError(3,0.8273424);
   norm_c__35->SetBinError(4,0.8092143);
   norm_c__35->SetBinError(5,1.252641);
   norm_c__35->SetBinError(6,1.61389);
   norm_c__35->SetBinError(7,2.317652);
   norm_c__35->SetBinError(8,2.95127);
   norm_c__35->SetBinError(9,3.780387);
   norm_c__35->SetBinError(10,4.051212);
   norm_c__35->SetBinError(11,4.551918);
   norm_c__35->SetBinError(12,4.087364);
   norm_c__35->SetBinError(13,3.971163);
   norm_c__35->SetBinError(14,3.048693);
   norm_c__35->SetBinError(15,2.012684);
   norm_c__35->SetBinError(16,1.94288);
   norm_c__35->SetBinError(17,1.310238);
   norm_c__35->SetBinError(18,0.7592242);
   norm_c__35->SetBinError(19,0.3955516);
   norm_c__35->SetBinError(20,0.3129116);
   norm_c__35->SetBinError(21,0.2979374);
   norm_c__35->SetBinError(22,0.04134189);
   norm_c__35->SetBinError(23,0.1893215);
   norm_c__35->SetBinError(26,0.01595649);
   norm_c__35->SetEntries(1372);
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
   entry=leg->AddEntry("frame_x_c2_3b67ca00","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.844506 #pm 0.012035","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.206678 #pm 0.010328","");
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
   
   TH1D *frame_3b67ca00_copy__36 = new TH1D("frame_3b67ca00_copy__36","p_T Balance",25,0,2);
   frame_3b67ca00_copy__36->SetBinContent(1,62.33433);
   frame_3b67ca00_copy__36->SetMinimum(-2.968301);
   frame_3b67ca00_copy__36->SetMaximum(62.33433);
   frame_3b67ca00_copy__36->SetEntries(1);
   frame_3b67ca00_copy__36->SetDirectory(0);
   frame_3b67ca00_copy__36->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b67ca00_copy__36->SetLineColor(ci);
   frame_3b67ca00_copy__36->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b67ca00_copy__36->GetXaxis()->SetLabelFont(42);
   frame_3b67ca00_copy__36->GetXaxis()->SetTitleOffset(1);
   frame_3b67ca00_copy__36->GetXaxis()->SetTitleFont(42);
   frame_3b67ca00_copy__36->GetYaxis()->SetTitle("1/Events");
   frame_3b67ca00_copy__36->GetYaxis()->SetLabelFont(42);
   frame_3b67ca00_copy__36->GetYaxis()->SetTitleFont(42);
   frame_3b67ca00_copy__36->GetZaxis()->SetLabelFont(42);
   frame_3b67ca00_copy__36->GetZaxis()->SetTitleOffset(1);
   frame_3b67ca00_copy__36->GetZaxis()->SetTitleFont(42);
   frame_3b67ca00_copy__36->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-9.3125,2.25,70.09641);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3b6811d0__37 = new TH1D("frame_3b6811d0__37","p_T Balance",25,0,2);
   frame_3b6811d0__37->SetBinContent(1,62.15552);
   frame_3b6811d0__37->SetMinimum(-2.959787);
   frame_3b6811d0__37->SetMaximum(62.15552);
   frame_3b6811d0__37->SetEntries(1);
   frame_3b6811d0__37->SetDirectory(0);
   frame_3b6811d0__37->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b6811d0__37->SetLineColor(ci);
   frame_3b6811d0__37->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b6811d0__37->GetXaxis()->SetLabelFont(42);
   frame_3b6811d0__37->GetXaxis()->SetTitleOffset(1);
   frame_3b6811d0__37->GetXaxis()->SetTitleFont(42);
   frame_3b6811d0__37->GetYaxis()->SetTitle("1/Events");
   frame_3b6811d0__37->GetYaxis()->SetLabelFont(42);
   frame_3b6811d0__37->GetYaxis()->SetTitleFont(42);
   frame_3b6811d0__37->GetZaxis()->SetLabelFont(42);
   frame_3b6811d0__37->GetZaxis()->SetTitleOffset(1);
   frame_3b6811d0__37->GetZaxis()->SetTitleFont(42);
   frame_3b6811d0__37->Draw("FUNC");
   
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
   1.279663,
   3.837684,
   5.032252,
   5.7871,
   10.83156,
   20.19689,
   34.38626,
   39.66697,
   54.684,
   50.48232,
   42.45016,
   31.63721,
   15.88168,
   11.21114,
   6.766632,
   2.447939,
   1.685925,
   0.4083579,
   0.3463446,
   0.2639387,
   0.1883879,
   0.03736381,
   0};
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
   0.5843134,
   1.061578,
   1.406484,
   1.463533,
   1.86099,
   2.754174,
   3.62107,
   3.777483,
   4.511733,
   4.41202,
   4.131033,
   3.450846,
   2.212715,
   2.015561,
   1.406175,
   0.8352974,
   0.669275,
   0.2633212,
   0.2059598,
   0.2264818,
   0.1883879,
   0.03736381,
   0};
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
   0.5843134,
   1.061578,
   1.406484,
   1.463533,
   1.86099,
   2.754174,
   3.62107,
   3.777483,
   4.511733,
   4.41202,
   4.131033,
   3.450846,
   2.212715,
   2.015561,
   1.406175,
   0.8352974,
   0.669275,
   0.2633212,
   0.2059598,
   0.2264818,
   0.1883879,
   0.03736381,
   0};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3010,h_dh_up2_fy3010,h_dh_up2_felx3010,h_dh_up2_fehx3010,h_dh_up2_fely3010,h_dh_up2_fehy3010);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23010 = new TH1F("Graph_h_dh_up23010","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23010->SetMinimum(-5.919573);
   Graph_h_dh_up23010->SetMaximum(65.11531);
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
   
   Double_t up_fx10[59] = {
   0.3327893,
   0.3759911,
   0.4191928,
   0.4623945,
   0.4731949,
   0.4785952,
   0.4839954,
   0.5055962,
   0.5271971,
   0.548798,
   0.5703988,
   0.5919997,
   0.6136005,
   0.6352014,
   0.6784031,
   0.700004,
   0.7216049,
   0.7432057,
   0.7648066,
   0.775607,
   0.7864074,
   0.7972079,
   0.8080083,
   0.8188087,
   0.8296092,
   0.8404096,
   0.85121,
   0.8620105,
   0.8728109,
   0.8836113,
   0.8944117,
   0.9052122,
   0.9160126,
   0.926813,
   0.9376135,
   0.9484139,
   0.9592143,
   0.9700148,
   0.9808152,
   1.002416,
   1.024017,
   1.045618,
   1.067219,
   1.11042,
   1.132021,
   1.153622,
   1.175223,
   1.186023,
   1.196824,
   1.207624,
   1.218425,
   1.240026,
   1.261626,
   1.283227,
   1.304828,
   1.326429,
   1.369631,
   1.412832,
   1.412832};
   Double_t up_fy10[59] = {
   5.918109,
   6.018353,
   6.173664,
   6.520243,
   6.747052,
   6.978603,
   7.369044,
   9.110542,
   11.12789,
   13.42819,
   16.00875,
   18.85529,
   21.9404,
   25.2227,
   32.14347,
   35.63254,
   39.02442,
   42.22424,
   45.13599,
   46.45467,
   47.6672,
   48.76339,
   49.73385,
   50.57014,
   51.26491,
   51.81197,
   52.20642,
   52.4447,
   52.52467,
   52.44558,
   52.20816,
   51.81456,
   51.26832,
   50.57436,
   49.73882,
   48.76908,
   47.67356,
   46.46164,
   45.14351,
   42.23269,
   39.03353,
   35.64204,
   32.15311,
   25.23195,
   21.94918,
   18.86346,
   16.01743,
   14.7504,
   13.622,
   12.61311,
   11.70779,
   10.15626,
   8.882866,
   7.826084,
   6.940326,
   6.191267,
   5.004293,
   4.117813,
   4.117813};
   graph = new TGraph(59,up_fx10,up_fy10);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up10 = new TH1F("Graph_up10","Projection of upf DSCB fit",100,0.224785,1.520837);
   Graph_up10->SetMinimum(3.706031);
   Graph_up10->SetMaximum(57.36535);
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
   
   TH1D *frame_3b6811d0__38 = new TH1D("frame_3b6811d0__38","p_T Balance",25,0,2);
   frame_3b6811d0__38->SetBinContent(1,62.15552);
   frame_3b6811d0__38->SetMinimum(-2.959787);
   frame_3b6811d0__38->SetMaximum(62.15552);
   frame_3b6811d0__38->SetEntries(1);
   frame_3b6811d0__38->SetDirectory(0);
   frame_3b6811d0__38->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b6811d0__38->SetLineColor(ci);
   frame_3b6811d0__38->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b6811d0__38->GetXaxis()->SetLabelFont(42);
   frame_3b6811d0__38->GetXaxis()->SetTitleOffset(1);
   frame_3b6811d0__38->GetXaxis()->SetTitleFont(42);
   frame_3b6811d0__38->GetYaxis()->SetTitle("1/Events");
   frame_3b6811d0__38->GetYaxis()->SetLabelFont(42);
   frame_3b6811d0__38->GetYaxis()->SetTitleFont(42);
   frame_3b6811d0__38->GetZaxis()->SetLabelFont(42);
   frame_3b6811d0__38->GetZaxis()->SetTitleOffset(1);
   frame_3b6811d0__38->GetZaxis()->SetTitleFont(42);
   frame_3b6811d0__38->Draw("AXISSAME");
   
   TH1D *norm_u__39 = new TH1D("norm_u__39","",25,0,2);
   norm_u__39->SetBinContent(3,1.279663);
   norm_u__39->SetBinContent(4,3.837684);
   norm_u__39->SetBinContent(5,5.032252);
   norm_u__39->SetBinContent(6,5.7871);
   norm_u__39->SetBinContent(7,10.83156);
   norm_u__39->SetBinContent(8,20.19689);
   norm_u__39->SetBinContent(9,34.38626);
   norm_u__39->SetBinContent(10,39.66697);
   norm_u__39->SetBinContent(11,54.684);
   norm_u__39->SetBinContent(12,50.48231);
   norm_u__39->SetBinContent(13,42.45016);
   norm_u__39->SetBinContent(14,31.63721);
   norm_u__39->SetBinContent(15,15.88168);
   norm_u__39->SetBinContent(16,11.21114);
   norm_u__39->SetBinContent(17,6.766632);
   norm_u__39->SetBinContent(18,2.447939);
   norm_u__39->SetBinContent(19,1.685925);
   norm_u__39->SetBinContent(20,0.4083579);
   norm_u__39->SetBinContent(21,0.3463446);
   norm_u__39->SetBinContent(22,0.2639387);
   norm_u__39->SetBinContent(23,0.1883879);
   norm_u__39->SetBinContent(24,0.03736381);
   norm_u__39->SetBinContent(26,0.03103104);
   norm_u__39->SetBinError(3,0.5843134);
   norm_u__39->SetBinError(4,1.061578);
   norm_u__39->SetBinError(5,1.406484);
   norm_u__39->SetBinError(6,1.463533);
   norm_u__39->SetBinError(7,1.86099);
   norm_u__39->SetBinError(8,2.754174);
   norm_u__39->SetBinError(9,3.62107);
   norm_u__39->SetBinError(10,3.777483);
   norm_u__39->SetBinError(11,4.511733);
   norm_u__39->SetBinError(12,4.41202);
   norm_u__39->SetBinError(13,4.131033);
   norm_u__39->SetBinError(14,3.450846);
   norm_u__39->SetBinError(15,2.212715);
   norm_u__39->SetBinError(16,2.015561);
   norm_u__39->SetBinError(17,1.406175);
   norm_u__39->SetBinError(18,0.8352974);
   norm_u__39->SetBinError(19,0.669275);
   norm_u__39->SetBinError(20,0.2633212);
   norm_u__39->SetBinError(21,0.2059598);
   norm_u__39->SetBinError(22,0.2264818);
   norm_u__39->SetBinError(23,0.1883879);
   norm_u__39->SetBinError(24,0.03736381);
   norm_u__39->SetBinError(26,0.01592578);
   norm_u__39->SetEntries(1386);
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
   entry=leg->AddEntry("frame_x_u2_3b6811d0","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.872785 #pm 0.012648","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.196211 #pm 0.011894","");
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
   
   TH1D *frame_3b6811d0_copy__40 = new TH1D("frame_3b6811d0_copy__40","p_T Balance",25,0,2);
   frame_3b6811d0_copy__40->SetBinContent(1,62.15552);
   frame_3b6811d0_copy__40->SetMinimum(-2.959787);
   frame_3b6811d0_copy__40->SetMaximum(62.15552);
   frame_3b6811d0_copy__40->SetEntries(1);
   frame_3b6811d0_copy__40->SetDirectory(0);
   frame_3b6811d0_copy__40->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b6811d0_copy__40->SetLineColor(ci);
   frame_3b6811d0_copy__40->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b6811d0_copy__40->GetXaxis()->SetLabelFont(42);
   frame_3b6811d0_copy__40->GetXaxis()->SetTitleOffset(1);
   frame_3b6811d0_copy__40->GetXaxis()->SetTitleFont(42);
   frame_3b6811d0_copy__40->GetYaxis()->SetTitle("1/Events");
   frame_3b6811d0_copy__40->GetYaxis()->SetLabelFont(42);
   frame_3b6811d0_copy__40->GetYaxis()->SetTitleFont(42);
   frame_3b6811d0_copy__40->GetZaxis()->SetLabelFont(42);
   frame_3b6811d0_copy__40->GetZaxis()->SetTitleOffset(1);
   frame_3b6811d0_copy__40->GetZaxis()->SetTitleFont(42);
   frame_3b6811d0_copy__40->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-6.960262,2.25,62.64236);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3b691750__41 = new TH1D("frame_3b691750__41","p_T Balance",25,0,2);
   frame_3b691750__41->SetBinContent(1,61.2503);
   frame_3b691750__41->SetMaximum(61.2503);
   frame_3b691750__41->SetEntries(1);
   frame_3b691750__41->SetDirectory(0);
   frame_3b691750__41->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b691750__41->SetLineColor(ci);
   frame_3b691750__41->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b691750__41->GetXaxis()->SetLabelFont(42);
   frame_3b691750__41->GetXaxis()->SetTitleOffset(1);
   frame_3b691750__41->GetXaxis()->SetTitleFont(42);
   frame_3b691750__41->GetYaxis()->SetTitle("1/Events");
   frame_3b691750__41->GetYaxis()->SetLabelFont(42);
   frame_3b691750__41->GetYaxis()->SetTitleFont(42);
   frame_3b691750__41->GetZaxis()->SetLabelFont(42);
   frame_3b691750__41->GetZaxis()->SetTitleOffset(1);
   frame_3b691750__41->GetZaxis()->SetTitleFont(42);
   frame_3b691750__41->Draw("FUNC");
   
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
   1.96722,
   2.4333,
   6.149464,
   10.29632,
   15.40001,
   21.96015,
   36.34763,
   45.52398,
   53.79322,
   47.67149,
   36.96438,
   21.21663,
   13.25058,
   9.182753,
   5.720568,
   1.546862,
   1.170065,
   0.3261373,
   0.2708265,
   0.04155787,
   0.190867,
   0,
   0.03863969};
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
   0.7310864,
   0.8010021,
   1.481233,
   1.899135,
   2.255881,
   2.834315,
   3.776174,
   4.092471,
   4.540402,
   4.248392,
   3.807655,
   2.669785,
   2.001372,
   1.764796,
   1.324553,
   0.5314918,
   0.4842115,
   0.1974142,
   0.1987867,
   0.04155787,
   0.190867,
   0,
   0.03863969};
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
   0.7310864,
   0.8010021,
   1.481233,
   1.899135,
   2.255881,
   2.834315,
   3.776174,
   4.092471,
   4.540402,
   4.248392,
   3.807655,
   2.669785,
   2.001372,
   1.764796,
   1.324553,
   0.5314918,
   0.4842115,
   0.1974142,
   0.1987867,
   0.04155787,
   0.190867,
   0,
   0.03863969};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3011,h_dh_down2_fy3011,h_dh_down2_felx3011,h_dh_down2_fehx3011,h_dh_down2_fely3011,h_dh_down2_fehy3011);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23011 = new TH1F("Graph_h_dh_down23011","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23011->SetMinimum(0);
   Graph_h_dh_down23011->SetMaximum(64.16698);
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
   
   Double_t down_fx11[60] = {
   0.2871013,
   0.331011,
   0.3529659,
   0.3749207,
   0.3968756,
   0.4188305,
   0.4407853,
   0.4627402,
   0.4846951,
   0.4956725,
   0.5066499,
   0.5286048,
   0.5505597,
   0.5725145,
   0.5944694,
   0.6383791,
   0.660334,
   0.6822889,
   0.7042437,
   0.7261986,
   0.737176,
   0.7481535,
   0.7591309,
   0.7701083,
   0.7810858,
   0.7920632,
   0.8030406,
   0.8140181,
   0.8249955,
   0.8359729,
   0.8469504,
   0.8579278,
   0.8689052,
   0.8798827,
   0.8908601,
   0.9018375,
   0.912815,
   0.9237924,
   0.9347698,
   0.9457473,
   0.9677021,
   0.989657,
   1.011612,
   1.033567,
   1.077476,
   1.099431,
   1.121386,
   1.143341,
   1.165296,
   1.176273,
   1.187251,
   1.209206,
   1.231161,
   1.253115,
   1.27507,
   1.297025,
   1.31898,
   1.340935,
   1.384845,
   1.384845};
   Double_t down_fy11[60] = {
   3.265778,
   4.1757,
   4.749691,
   5.425786,
   6.226577,
   7.180706,
   8.324799,
   9.706101,
   11.38616,
   12.36259,
   13.44596,
   15.91689,
   18.63848,
   21.57211,
   24.67769,
   31.18298,
   34.44443,
   37.60539,
   40.57991,
   43.28145,
   44.50367,
   45.62705,
   46.64245,
   47.54149,
   48.31663,
   48.9613,
   49.46998,
   49.83827,
   50.06298,
   50.14213,
   50.07505,
   49.86231,
   49.50578,
   49.00855,
   48.37492,
   47.61033,
   46.72125,
   45.71516,
   44.60037,
   43.38595,
   40.69751,
   37.73257,
   34.57759,
   31.31864,
   24.80896,
   21.69732,
   18.75571,
   16.02473,
   13.53268,
   12.41586,
   11.41212,
   9.691793,
   8.284275,
   7.123658,
   6.159692,
   5.353671,
   4.675501,
   4.101572,
   3.19555,
   3.19555};
   graph = new TGraph(60,down_fx11,down_fy11);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down11 = new TH1F("Graph_down11","Projection of downf DSCB fit",100,0.1773269,1.494619);
   Graph_down11->SetMinimum(2.875995);
   Graph_down11->SetMaximum(54.83679);
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
   
   TH1D *frame_3b691750__42 = new TH1D("frame_3b691750__42","p_T Balance",25,0,2);
   frame_3b691750__42->SetBinContent(1,61.2503);
   frame_3b691750__42->SetMaximum(61.2503);
   frame_3b691750__42->SetEntries(1);
   frame_3b691750__42->SetDirectory(0);
   frame_3b691750__42->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b691750__42->SetLineColor(ci);
   frame_3b691750__42->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b691750__42->GetXaxis()->SetLabelFont(42);
   frame_3b691750__42->GetXaxis()->SetTitleOffset(1);
   frame_3b691750__42->GetXaxis()->SetTitleFont(42);
   frame_3b691750__42->GetYaxis()->SetTitle("1/Events");
   frame_3b691750__42->GetYaxis()->SetLabelFont(42);
   frame_3b691750__42->GetYaxis()->SetTitleFont(42);
   frame_3b691750__42->GetZaxis()->SetLabelFont(42);
   frame_3b691750__42->GetZaxis()->SetTitleOffset(1);
   frame_3b691750__42->GetZaxis()->SetTitleFont(42);
   frame_3b691750__42->Draw("AXISSAME");
   
   TH1D *norm_d__43 = new TH1D("norm_d__43","",25,0,2);
   norm_d__43->SetBinContent(3,1.96722);
   norm_d__43->SetBinContent(4,2.4333);
   norm_d__43->SetBinContent(5,6.149464);
   norm_d__43->SetBinContent(6,10.29632);
   norm_d__43->SetBinContent(7,15.40001);
   norm_d__43->SetBinContent(8,21.96015);
   norm_d__43->SetBinContent(9,36.34763);
   norm_d__43->SetBinContent(10,45.52398);
   norm_d__43->SetBinContent(11,53.79322);
   norm_d__43->SetBinContent(12,47.67149);
   norm_d__43->SetBinContent(13,36.96438);
   norm_d__43->SetBinContent(14,21.21663);
   norm_d__43->SetBinContent(15,13.25058);
   norm_d__43->SetBinContent(16,9.182753);
   norm_d__43->SetBinContent(17,5.720568);
   norm_d__43->SetBinContent(18,1.546862);
   norm_d__43->SetBinContent(19,1.170065);
   norm_d__43->SetBinContent(20,0.3261373);
   norm_d__43->SetBinContent(21,0.2708265);
   norm_d__43->SetBinContent(22,0.04155787);
   norm_d__43->SetBinContent(23,0.190867);
   norm_d__43->SetBinContent(25,0.03863969);
   norm_d__43->SetBinContent(26,0.04719524);
   norm_d__43->SetBinError(3,0.7310864);
   norm_d__43->SetBinError(4,0.8010021);
   norm_d__43->SetBinError(5,1.481233);
   norm_d__43->SetBinError(6,1.899135);
   norm_d__43->SetBinError(7,2.255881);
   norm_d__43->SetBinError(8,2.834315);
   norm_d__43->SetBinError(9,3.776174);
   norm_d__43->SetBinError(10,4.092471);
   norm_d__43->SetBinError(11,4.540402);
   norm_d__43->SetBinError(12,4.248392);
   norm_d__43->SetBinError(13,3.807655);
   norm_d__43->SetBinError(14,2.669785);
   norm_d__43->SetBinError(15,2.001372);
   norm_d__43->SetBinError(16,1.764796);
   norm_d__43->SetBinError(17,1.324553);
   norm_d__43->SetBinError(18,0.5314918);
   norm_d__43->SetBinError(19,0.4842115);
   norm_d__43->SetBinError(20,0.1974142);
   norm_d__43->SetBinError(21,0.1987867);
   norm_d__43->SetBinError(22,0.04155787);
   norm_d__43->SetBinError(23,0.190867);
   norm_d__43->SetBinError(25,0.03863969);
   norm_d__43->SetBinError(26,0.02285169);
   norm_d__43->SetEntries(1400);
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
   entry=leg->AddEntry("frame_x_d2_3b691750","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.836183 #pm 0.012434","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.214700 #pm 0.010141","");
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
   
   TH1D *frame_3b691750_copy__44 = new TH1D("frame_3b691750_copy__44","p_T Balance",25,0,2);
   frame_3b691750_copy__44->SetBinContent(1,61.2503);
   frame_3b691750_copy__44->SetMaximum(61.2503);
   frame_3b691750_copy__44->SetEntries(1);
   frame_3b691750_copy__44->SetDirectory(0);
   frame_3b691750_copy__44->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b691750_copy__44->SetLineColor(ci);
   frame_3b691750_copy__44->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b691750_copy__44->GetXaxis()->SetLabelFont(42);
   frame_3b691750_copy__44->GetXaxis()->SetTitleOffset(1);
   frame_3b691750_copy__44->GetXaxis()->SetTitleFont(42);
   frame_3b691750_copy__44->GetYaxis()->SetTitle("1/Events");
   frame_3b691750_copy__44->GetYaxis()->SetLabelFont(42);
   frame_3b691750_copy__44->GetYaxis()->SetTitleFont(42);
   frame_3b691750_copy__44->GetZaxis()->SetLabelFont(42);
   frame_3b691750_copy__44->GetZaxis()->SetTitleOffset(1);
   frame_3b691750_copy__44->GetZaxis()->SetTitleFont(42);
   frame_3b691750_copy__44->Draw("sameaxis");
   
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
   
   TH1D *frame_3b6a52f0__45 = new TH1D("frame_3b6a52f0__45","p_T Balance",25,0,2);
   frame_3b6a52f0__45->SetBinContent(1,68.87371);
   frame_3b6a52f0__45->SetMaximum(68.87371);
   frame_3b6a52f0__45->SetEntries(1);
   frame_3b6a52f0__45->SetDirectory(0);
   frame_3b6a52f0__45->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b6a52f0__45->SetLineColor(ci);
   frame_3b6a52f0__45->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b6a52f0__45->GetXaxis()->SetLabelFont(42);
   frame_3b6a52f0__45->GetXaxis()->SetTitleOffset(1);
   frame_3b6a52f0__45->GetXaxis()->SetTitleFont(42);
   frame_3b6a52f0__45->GetYaxis()->SetTitle("1/Events");
   frame_3b6a52f0__45->GetYaxis()->SetLabelFont(42);
   frame_3b6a52f0__45->GetYaxis()->SetTitleFont(42);
   frame_3b6a52f0__45->GetZaxis()->SetLabelFont(42);
   frame_3b6a52f0__45->GetZaxis()->SetTitleOffset(1);
   frame_3b6a52f0__45->GetZaxis()->SetTitleFont(42);
   frame_3b6a52f0__45->Draw("FUNC");
   
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
   2,
   9,
   12,
   20,
   27,
   37,
   57,
   52,
   47,
   30,
   25,
   17,
   6,
   3,
   5,
   3,
   0,
   0,
   1,
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
   1.291815,
   2.943461,
   3.415266,
   4.434448,
   5.163771,
   6.055143,
   7.527619,
   7.187836,
   6.831172,
   5.446522,
   4.966335,
   4.082184,
   2.379931,
   1.632705,
   2.159691,
   1.632705,
   0,
   0,
   0.8272462,
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
   2.63786,
   4.110204,
   4.559819,
   5.546519,
   6.260244,
   7.137555,
   8.594007,
   8.257346,
   7.904289,
   6.538046,
   6.066589,
   5.203719,
   3.583642,
   2.918186,
   3.382473,
   2.918186,
   1.147874,
   1.147874,
   2.299527,
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
   Graph_h_dh_data23012->SetMaximum(72.15341);
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
   
   Double_t observation_fx12[59] = {
   0.1948824,
   0.2439406,
   0.2684697,
   0.2929988,
   0.3175279,
   0.342057,
   0.3665861,
   0.3911152,
   0.4156443,
   0.4401734,
   0.4647025,
   0.4892316,
   0.5137607,
   0.5382898,
   0.5628189,
   0.587348,
   0.6364062,
   0.6609353,
   0.6854644,
   0.697729,
   0.7099935,
   0.7222581,
   0.7345226,
   0.7467872,
   0.7590517,
   0.7713163,
   0.7835808,
   0.7958454,
   0.8081099,
   0.8203745,
   0.832639,
   0.8449036,
   0.8571681,
   0.8694327,
   0.8816972,
   0.8939618,
   0.9062263,
   0.9184909,
   0.9307554,
   0.9552845,
   0.9798136,
   1.004343,
   1.028872,
   1.07793,
   1.102459,
   1.126988,
   1.151517,
   1.176046,
   1.200576,
   1.225105,
   1.249634,
   1.274163,
   1.280295,
   1.286427,
   1.298692,
   1.323221,
   1.372279,
   1.421337,
   1.421337};
   Double_t observation_fy12[59] = {
   1.635637,
   1.78796,
   2.318092,
   3.041844,
   3.941881,
   5.044641,
   6.375544,
   7.957277,
   9.807808,
   11.93822,
   14.35052,
   17.03554,
   19.9712,
   23.12134,
   26.43515,
   29.84771,
   36.64798,
   39.8529,
   42.79864,
   44.14435,
   45.39002,
   46.52492,
   47.5391,
   48.42352,
   49.17018,
   49.77225,
   50.22418,
   50.52176,
   50.66221,
   50.64422,
   50.46795,
   50.13506,
   49.64865,
   49.01325,
   48.23469,
   47.32009,
   46.2777,
   45.11677,
   43.84744,
   41.02769,
   37.91142,
   34.59579,
   31.17717,
   24.38621,
   21.16599,
   18.14232,
   15.35704,
   12.83756,
   10.59785,
   8.639985,
   6.956145,
   5.530756,
   5.245695,
   5.101412,
   4.946207,
   4.787249,
   4.628928,
   4.537603,
   4.537603};
   graph = new TGraph(59,observation_fx12,observation_fy12);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation12 = new TH1F("Graph_observation12","Projection of obsf DSCB fit",100,0.07223687,1.543983);
   Graph_observation12->SetMinimum(1.472073);
   Graph_observation12->SetMaximum(55.56487);
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
   
   TH1D *frame_3b6a52f0__46 = new TH1D("frame_3b6a52f0__46","p_T Balance",25,0,2);
   frame_3b6a52f0__46->SetBinContent(1,68.87371);
   frame_3b6a52f0__46->SetMaximum(68.87371);
   frame_3b6a52f0__46->SetEntries(1);
   frame_3b6a52f0__46->SetDirectory(0);
   frame_3b6a52f0__46->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b6a52f0__46->SetLineColor(ci);
   frame_3b6a52f0__46->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b6a52f0__46->GetXaxis()->SetLabelFont(42);
   frame_3b6a52f0__46->GetXaxis()->SetTitleOffset(1);
   frame_3b6a52f0__46->GetXaxis()->SetTitleFont(42);
   frame_3b6a52f0__46->GetYaxis()->SetTitle("1/Events");
   frame_3b6a52f0__46->GetYaxis()->SetLabelFont(42);
   frame_3b6a52f0__46->GetYaxis()->SetTitleFont(42);
   frame_3b6a52f0__46->GetZaxis()->SetLabelFont(42);
   frame_3b6a52f0__46->GetZaxis()->SetTitleOffset(1);
   frame_3b6a52f0__46->GetZaxis()->SetTitleFont(42);
   frame_3b6a52f0__46->Draw("AXISSAME");
   
   TH1D *norm_o__47 = new TH1D("norm_o__47","",25,0,2);
   norm_o__47->SetBinContent(3,1);
   norm_o__47->SetBinContent(4,2);
   norm_o__47->SetBinContent(5,9);
   norm_o__47->SetBinContent(6,12);
   norm_o__47->SetBinContent(7,20);
   norm_o__47->SetBinContent(8,27);
   norm_o__47->SetBinContent(9,37);
   norm_o__47->SetBinContent(10,57);
   norm_o__47->SetBinContent(11,52);
   norm_o__47->SetBinContent(12,47);
   norm_o__47->SetBinContent(13,30);
   norm_o__47->SetBinContent(14,25);
   norm_o__47->SetBinContent(15,17);
   norm_o__47->SetBinContent(16,6);
   norm_o__47->SetBinContent(17,3);
   norm_o__47->SetBinContent(18,5);
   norm_o__47->SetBinContent(19,3);
   norm_o__47->SetBinContent(22,1);
   norm_o__47->SetMinimum(0);
   norm_o__47->SetMaximum(125.4);
   norm_o__47->SetEntries(354);
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
   entry=leg->AddEntry("frame_x_o2_3b6a52f0","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.812433 #pm 0.012124","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.220023 #pm 0.009283","");
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
   
   TH1D *frame_3b6a52f0_copy__48 = new TH1D("frame_3b6a52f0_copy__48","p_T Balance",25,0,2);
   frame_3b6a52f0_copy__48->SetBinContent(1,68.87371);
   frame_3b6a52f0_copy__48->SetMaximum(68.87371);
   frame_3b6a52f0_copy__48->SetEntries(1);
   frame_3b6a52f0_copy__48->SetDirectory(0);
   frame_3b6a52f0_copy__48->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b6a52f0_copy__48->SetLineColor(ci);
   frame_3b6a52f0_copy__48->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b6a52f0_copy__48->GetXaxis()->SetLabelFont(42);
   frame_3b6a52f0_copy__48->GetXaxis()->SetTitleOffset(1);
   frame_3b6a52f0_copy__48->GetXaxis()->SetTitleFont(42);
   frame_3b6a52f0_copy__48->GetYaxis()->SetTitle("1/Events");
   frame_3b6a52f0_copy__48->GetYaxis()->SetLabelFont(42);
   frame_3b6a52f0_copy__48->GetYaxis()->SetTitleFont(42);
   frame_3b6a52f0_copy__48->GetZaxis()->SetLabelFont(42);
   frame_3b6a52f0_copy__48->GetZaxis()->SetTitleOffset(1);
   frame_3b6a52f0_copy__48->GetZaxis()->SetTitleFont(42);
   frame_3b6a52f0_copy__48->Draw("sameaxis");
   
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
