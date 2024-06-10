void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_4__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 17:04:24 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-10.3587,2.25,119.125);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_40f49400__49 = new TH1D("frame_40f49400__49","p_T Balance",25,0,2);
   frame_40f49400__49->SetBinContent(1,106.1767);
   frame_40f49400__49->SetMaximum(106.1767);
   frame_40f49400__49->SetEntries(1);
   frame_40f49400__49->SetDirectory(0);
   frame_40f49400__49->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_40f49400__49->SetLineColor(ci);
   frame_40f49400__49->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40f49400__49->GetXaxis()->SetLabelFont(42);
   frame_40f49400__49->GetXaxis()->SetTitleOffset(1);
   frame_40f49400__49->GetXaxis()->SetTitleFont(42);
   frame_40f49400__49->GetYaxis()->SetTitle("1/Events");
   frame_40f49400__49->GetYaxis()->SetLabelFont(42);
   frame_40f49400__49->GetYaxis()->SetTitleFont(42);
   frame_40f49400__49->GetZaxis()->SetLabelFont(42);
   frame_40f49400__49->GetZaxis()->SetTitleOffset(1);
   frame_40f49400__49->GetZaxis()->SetTitleFont(42);
   frame_40f49400__49->Draw("FUNC");
   
   Double_t h_dh_central2_fx3013[25] = {
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
   Double_t h_dh_central2_fy3013[25] = {
   0,
   0,
   1.780791,
   7.839806,
   11.61498,
   26.26518,
   33.89717,
   58.90495,
   86.21215,
   84.87202,
   89.74294,
   94.793,
   75.2267,
   51.85978,
   35.40889,
   23.39447,
   16.93397,
   4.984736,
   3.989507,
   0.7034671,
   0.6430458,
   0.04937236,
   0.1885668,
   0.5000792,
   0.457457};
   Double_t h_dh_central2_felx3013[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_central2_fely3013[25] = {
   0,
   0,
   0.68383,
   1.655937,
   2.17287,
   3.339512,
   3.593178,
   5.072376,
   6.16938,
   5.971375,
   6.356332,
   6.327622,
   5.772238,
   4.55779,
   3.756142,
   3.02819,
   2.436885,
   1.301569,
   1.068994,
   0.2940292,
   0.4052686,
   0.04937236,
   0.1885668,
   0.3515926,
   0.2819693};
   Double_t h_dh_central2_fehx3013[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_central2_fehy3013[25] = {
   0,
   0,
   0.68383,
   1.655937,
   2.17287,
   3.339512,
   3.593178,
   5.072376,
   6.16938,
   5.971375,
   6.356332,
   6.327622,
   5.772238,
   4.55779,
   3.756142,
   3.02819,
   2.436885,
   1.301569,
   1.068994,
   0.2940292,
   0.4052686,
   0.04937236,
   0.1885668,
   0.3515926,
   0.2819693};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3013,h_dh_central2_fy3013,h_dh_central2_felx3013,h_dh_central2_fehx3013,h_dh_central2_fely3013,h_dh_central2_fehy3013);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23013 = new TH1F("Graph_h_dh_central23013","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23013->SetMinimum(0);
   Graph_h_dh_central23013->SetMaximum(111.2327);
   Graph_h_dh_central23013->SetDirectory(0);
   Graph_h_dh_central23013->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_central23013->SetLineColor(ci);
   Graph_h_dh_central23013->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_central23013->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_central23013->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_central23013->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_central23013->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_central23013->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_central23013->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_central23013->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_central23013);
   
   grae->Draw("p");
   
   Double_t Central_fx13[58] = {
   0.1899822,
   0.2153738,
   0.2407653,
   0.2661569,
   0.2915484,
   0.31694,
   0.3423315,
   0.3677231,
   0.3931146,
   0.4185062,
   0.4438977,
   0.4692893,
   0.4946808,
   0.5200723,
   0.5454639,
   0.596247,
   0.6470301,
   0.6724216,
   0.6978132,
   0.7232047,
   0.7359005,
   0.7485963,
   0.761292,
   0.7739878,
   0.7866836,
   0.7993794,
   0.8120751,
   0.8247709,
   0.8374667,
   0.8501624,
   0.8628582,
   0.875554,
   0.8882498,
   0.9009455,
   0.9136413,
   0.9263371,
   0.9390329,
   0.9517286,
   0.9771202,
   1.002512,
   1.027903,
   1.053295,
   1.104078,
   1.129469,
   1.154861,
   1.180253,
   1.205644,
   1.231036,
   1.256427,
   1.281819,
   1.30721,
   1.332602,
   1.357993,
   1.383385,
   1.408776,
   1.434168,
   1.45956,
   1.45956};
   Double_t Central_fy13[58] = {
   2.558633,
   3.378614,
   4.411911,
   5.697345,
   7.275719,
   9.188336,
   11.47507,
   14.17201,
   17.30873,
   20.90531,
   24.96925,
   29.49254,
   34.44897,
   39.7922,
   45.45454,
   57.35994,
   69.22621,
   74.78902,
   79.90294,
   84.41998,
   86.41131,
   88.2034,
   89.78204,
   91.13454,
   92.24991,
   93.119,
   93.73462,
   94.09167,
   94.18716,
   94.0203,
   93.59249,
   92.90728,
   91.97035,
   90.78945,
   89.37423,
   87.73617,
   85.88838,
   83.84545,
   79.23882,
   74.05494,
   68.44279,
   62.55455,
   50.53522,
   44.66818,
   39.0445,
   33.75041,
   28.85067,
   24.38879,
   20.38836,
   16.85512,
   13.77968,
   11.14048,
   8.906895,
   7.042167,
   5.506098,
   4.257348,
   3.258372,
   3.258372};
   TGraph *graph = new TGraph(58,Central_fx13,Central_fy13);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central13 = new TH1F("Graph_Central13","Projection of centralf DSCB fit",100,0.06302451,1.586517);
   Graph_Central13->SetMinimum(2.30277);
   Graph_Central13->SetMaximum(103.35);
   Graph_Central13->SetDirectory(0);
   Graph_Central13->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Central13->SetLineColor(ci);
   Graph_Central13->GetXaxis()->SetLabelFont(42);
   Graph_Central13->GetXaxis()->SetTitleOffset(1);
   Graph_Central13->GetXaxis()->SetTitleFont(42);
   Graph_Central13->GetYaxis()->SetLabelFont(42);
   Graph_Central13->GetYaxis()->SetTitleFont(42);
   Graph_Central13->GetZaxis()->SetLabelFont(42);
   Graph_Central13->GetZaxis()->SetTitleOffset(1);
   Graph_Central13->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Central13);
   
   graph->Draw("l");
   
   TH1D *frame_40f49400__50 = new TH1D("frame_40f49400__50","p_T Balance",25,0,2);
   frame_40f49400__50->SetBinContent(1,106.1767);
   frame_40f49400__50->SetMaximum(106.1767);
   frame_40f49400__50->SetEntries(1);
   frame_40f49400__50->SetDirectory(0);
   frame_40f49400__50->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40f49400__50->SetLineColor(ci);
   frame_40f49400__50->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40f49400__50->GetXaxis()->SetLabelFont(42);
   frame_40f49400__50->GetXaxis()->SetTitleOffset(1);
   frame_40f49400__50->GetXaxis()->SetTitleFont(42);
   frame_40f49400__50->GetYaxis()->SetTitle("1/Events");
   frame_40f49400__50->GetYaxis()->SetLabelFont(42);
   frame_40f49400__50->GetYaxis()->SetTitleFont(42);
   frame_40f49400__50->GetZaxis()->SetLabelFont(42);
   frame_40f49400__50->GetZaxis()->SetTitleOffset(1);
   frame_40f49400__50->GetZaxis()->SetTitleFont(42);
   frame_40f49400__50->Draw("AXISSAME");
   
   TH1D *norm_c__51 = new TH1D("norm_c__51","",25,0,2);
   norm_c__51->SetBinContent(3,1.780791);
   norm_c__51->SetBinContent(4,7.839806);
   norm_c__51->SetBinContent(5,11.61498);
   norm_c__51->SetBinContent(6,26.26518);
   norm_c__51->SetBinContent(7,33.89717);
   norm_c__51->SetBinContent(8,58.90495);
   norm_c__51->SetBinContent(9,86.21215);
   norm_c__51->SetBinContent(10,84.87203);
   norm_c__51->SetBinContent(11,89.74294);
   norm_c__51->SetBinContent(12,94.793);
   norm_c__51->SetBinContent(13,75.2267);
   norm_c__51->SetBinContent(14,51.85978);
   norm_c__51->SetBinContent(15,35.40889);
   norm_c__51->SetBinContent(16,23.39447);
   norm_c__51->SetBinContent(17,16.93397);
   norm_c__51->SetBinContent(18,4.984736);
   norm_c__51->SetBinContent(19,3.989507);
   norm_c__51->SetBinContent(20,0.7034671);
   norm_c__51->SetBinContent(21,0.6430458);
   norm_c__51->SetBinContent(22,0.04937236);
   norm_c__51->SetBinContent(23,0.1885668);
   norm_c__51->SetBinContent(24,0.5000792);
   norm_c__51->SetBinContent(25,0.457457);
   norm_c__51->SetBinContent(26,0.4331271);
   norm_c__51->SetBinError(3,0.68383);
   norm_c__51->SetBinError(4,1.655937);
   norm_c__51->SetBinError(5,2.17287);
   norm_c__51->SetBinError(6,3.339512);
   norm_c__51->SetBinError(7,3.593178);
   norm_c__51->SetBinError(8,5.072376);
   norm_c__51->SetBinError(9,6.16938);
   norm_c__51->SetBinError(10,5.971375);
   norm_c__51->SetBinError(11,6.356332);
   norm_c__51->SetBinError(12,6.327622);
   norm_c__51->SetBinError(13,5.772238);
   norm_c__51->SetBinError(14,4.55779);
   norm_c__51->SetBinError(15,3.756142);
   norm_c__51->SetBinError(16,3.02819);
   norm_c__51->SetBinError(17,2.436885);
   norm_c__51->SetBinError(18,1.301569);
   norm_c__51->SetBinError(19,1.068994);
   norm_c__51->SetBinError(20,0.2940292);
   norm_c__51->SetBinError(21,0.4052686);
   norm_c__51->SetBinError(22,0.04937236);
   norm_c__51->SetBinError(23,0.1885668);
   norm_c__51->SetBinError(24,0.3515926);
   norm_c__51->SetBinError(25,0.2819693);
   norm_c__51->SetBinError(26,0.2114223);
   norm_c__51->SetEntries(2908);
   norm_c__51->SetStats(0);

   ci = 1335;
   color = new TColor(ci, 0.3, 0.3, 0.3, " ", 0.6);
   norm_c__51->SetFillColor(ci);
   norm_c__51->SetFillStyle(3144);
   norm_c__51->SetLineColor(2);
   norm_c__51->SetLineWidth(2);
   norm_c__51->GetXaxis()->SetRange(1,25);
   norm_c__51->GetXaxis()->SetLabelFont(42);
   norm_c__51->GetXaxis()->SetLabelSize(0.04);
   norm_c__51->GetXaxis()->SetTitleOffset(1);
   norm_c__51->GetXaxis()->SetTitleFont(42);
   norm_c__51->GetYaxis()->SetLabelFont(42);
   norm_c__51->GetYaxis()->SetTitleFont(42);
   norm_c__51->GetZaxis()->SetLabelFont(42);
   norm_c__51->GetZaxis()->SetTitleOffset(1);
   norm_c__51->GetZaxis()->SetTitleFont(42);
   norm_c__51->Draw("e1 same");
   
   TLegend *leg = new TLegend(0.65,0.5,0.93,0.87,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.03);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("norm_c","Central","lpf");

   ci = 1335;
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
   entry=leg->AddEntry("frame_x_c2_40f49400","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.835735 #pm 0.009373","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.240419 #pm 0.007466","");
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
   
   TH1D *frame_40f49400_copy__52 = new TH1D("frame_40f49400_copy__52","p_T Balance",25,0,2);
   frame_40f49400_copy__52->SetBinContent(1,106.1767);
   frame_40f49400_copy__52->SetMaximum(106.1767);
   frame_40f49400_copy__52->SetEntries(1);
   frame_40f49400_copy__52->SetDirectory(0);
   frame_40f49400_copy__52->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40f49400_copy__52->SetLineColor(ci);
   frame_40f49400_copy__52->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40f49400_copy__52->GetXaxis()->SetLabelFont(42);
   frame_40f49400_copy__52->GetXaxis()->SetTitleOffset(1);
   frame_40f49400_copy__52->GetXaxis()->SetTitleFont(42);
   frame_40f49400_copy__52->GetYaxis()->SetTitle("1/Events");
   frame_40f49400_copy__52->GetYaxis()->SetLabelFont(42);
   frame_40f49400_copy__52->GetYaxis()->SetTitleFont(42);
   frame_40f49400_copy__52->GetZaxis()->SetLabelFont(42);
   frame_40f49400_copy__52->GetZaxis()->SetTitleOffset(1);
   frame_40f49400_copy__52->GetZaxis()->SetTitleFont(42);
   frame_40f49400_copy__52->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-10.76807,2.25,123.8328);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_40f3c350__53 = new TH1D("frame_40f3c350__53","p_T Balance",25,0,2);
   frame_40f3c350__53->SetBinContent(1,110.3727);
   frame_40f3c350__53->SetMaximum(110.3727);
   frame_40f3c350__53->SetEntries(1);
   frame_40f3c350__53->SetDirectory(0);
   frame_40f3c350__53->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40f3c350__53->SetLineColor(ci);
   frame_40f3c350__53->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40f3c350__53->GetXaxis()->SetLabelFont(42);
   frame_40f3c350__53->GetXaxis()->SetTitleOffset(1);
   frame_40f3c350__53->GetXaxis()->SetTitleFont(42);
   frame_40f3c350__53->GetYaxis()->SetTitle("1/Events");
   frame_40f3c350__53->GetYaxis()->SetLabelFont(42);
   frame_40f3c350__53->GetYaxis()->SetTitleFont(42);
   frame_40f3c350__53->GetZaxis()->SetLabelFont(42);
   frame_40f3c350__53->GetZaxis()->SetTitleOffset(1);
   frame_40f3c350__53->GetZaxis()->SetTitleFont(42);
   frame_40f3c350__53->Draw("FUNC");
   
   Double_t h_dh_up2_fx3014[25] = {
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
   Double_t h_dh_up2_fy3014[25] = {
   0,
   0,
   2.484007,
   6.788943,
   9.058186,
   22.19921,
   35.66557,
   59.47335,
   77.73699,
   96.20699,
   91.14435,
   98.4855,
   80.24472,
   55.60592,
   39.44804,
   24.9042,
   18.7876,
   5.769896,
   3.549036,
   1.243181,
   0.7561128,
   0.1048736,
   0.1876369,
   0.4445569,
   0.406571};
   Double_t h_dh_up2_felx3014[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_up2_fely3014[25] = {
   0,
   0,
   0.8554076,
   1.498814,
   1.871154,
   2.934393,
   4.000523,
   5.12514,
   5.834638,
   6.5696,
   6.441838,
   6.631348,
   5.89581,
   4.843094,
   3.9041,
   3.15891,
   2.659993,
   1.47173,
   1.02762,
   0.4181388,
   0.4242215,
   0.06496281,
   0.1876369,
   0.3459214,
   0.2485361};
   Double_t h_dh_up2_fehx3014[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_up2_fehy3014[25] = {
   0,
   0,
   0.8554076,
   1.498814,
   1.871154,
   2.934393,
   4.000523,
   5.12514,
   5.834638,
   6.5696,
   6.441838,
   6.631348,
   5.89581,
   4.843094,
   3.9041,
   3.15891,
   2.659993,
   1.47173,
   1.02762,
   0.4181388,
   0.4242215,
   0.06496281,
   0.1876369,
   0.3459214,
   0.2485361};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3014,h_dh_up2_fy3014,h_dh_up2_felx3014,h_dh_up2_fehx3014,h_dh_up2_fely3014,h_dh_up2_fehy3014);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23014 = new TH1F("Graph_h_dh_up23014","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23014->SetMinimum(0);
   Graph_h_dh_up23014->SetMaximum(115.6285);
   Graph_h_dh_up23014->SetDirectory(0);
   Graph_h_dh_up23014->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_up23014->SetLineColor(ci);
   Graph_h_dh_up23014->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_up23014->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_up23014->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_up23014->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_up23014->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_up23014->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_up23014->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_up23014->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_up23014);
   
   grae->Draw("p");
   
   Double_t up_fx14[58] = {
   0.2031162,
   0.2283461,
   0.2535761,
   0.278806,
   0.3040359,
   0.3292658,
   0.3544957,
   0.3797256,
   0.4049556,
   0.4301855,
   0.4554154,
   0.4806453,
   0.5058752,
   0.5311051,
   0.5563351,
   0.6067949,
   0.6572547,
   0.6824846,
   0.7077146,
   0.7329445,
   0.7455594,
   0.7581744,
   0.7707893,
   0.7834043,
   0.7960193,
   0.8086342,
   0.8212492,
   0.8338641,
   0.8464791,
   0.8590941,
   0.871709,
   0.884324,
   0.8969389,
   0.9095539,
   0.9221688,
   0.9347838,
   0.9473988,
   0.9600137,
   0.9852436,
   1.010474,
   1.035703,
   1.060933,
   1.111393,
   1.136623,
   1.161853,
   1.187083,
   1.212313,
   1.237543,
   1.262773,
   1.288003,
   1.313233,
   1.338462,
   1.363692,
   1.388922,
   1.414152,
   1.439382,
   1.464612,
   1.464612};
   Double_t up_fy14[58] = {
   2.247533,
   3.000821,
   3.963288,
   5.174399,
   6.678099,
   8.519901,
   10.74496,
   13.39566,
   16.50866,
   20.11168,
   24.21997,
   28.83285,
   33.9305,
   39.47132,
   45.39017,
   57.98132,
   70.7244,
   76.77024,
   82.37687,
   87.37886,
   89.60406,
   91.62124,
   93.41397,
   94.96743,
   96.26861,
   97.30651,
   98.07228,
   98.55934,
   98.76351,
   98.68302,
   98.31857,
   97.67329,
   96.75273,
   95.56478,
   94.11951,
   92.42908,
   90.50755,
   88.37066,
   83.52112,
   78.03209,
   72.0674,
   65.79504,
   52.97464,
   46.71845,
   40.72843,
   35.09906,
   29.90075,
   25.1801,
   20.96146,
   17.24941,
   14.03187,
   11.28355,
   8.969427,
   7.048104,
   5.474804,
   4.203912,
   3.191004,
   3.191004};
   graph = new TGraph(58,up_fx14,up_fy14);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up14 = new TH1F("Graph_up14","Projection of upf DSCB fit",100,0.07696665,1.590762);
   Graph_up14->SetMinimum(2.022779);
   Graph_up14->SetMaximum(108.4151);
   Graph_up14->SetDirectory(0);
   Graph_up14->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_up14->SetLineColor(ci);
   Graph_up14->GetXaxis()->SetLabelFont(42);
   Graph_up14->GetXaxis()->SetTitleOffset(1);
   Graph_up14->GetXaxis()->SetTitleFont(42);
   Graph_up14->GetYaxis()->SetLabelFont(42);
   Graph_up14->GetYaxis()->SetTitleFont(42);
   Graph_up14->GetZaxis()->SetLabelFont(42);
   Graph_up14->GetZaxis()->SetTitleOffset(1);
   Graph_up14->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_up14);
   
   graph->Draw("l");
   
   TH1D *frame_40f3c350__54 = new TH1D("frame_40f3c350__54","p_T Balance",25,0,2);
   frame_40f3c350__54->SetBinContent(1,110.3727);
   frame_40f3c350__54->SetMaximum(110.3727);
   frame_40f3c350__54->SetEntries(1);
   frame_40f3c350__54->SetDirectory(0);
   frame_40f3c350__54->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40f3c350__54->SetLineColor(ci);
   frame_40f3c350__54->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40f3c350__54->GetXaxis()->SetLabelFont(42);
   frame_40f3c350__54->GetXaxis()->SetTitleOffset(1);
   frame_40f3c350__54->GetXaxis()->SetTitleFont(42);
   frame_40f3c350__54->GetYaxis()->SetTitle("1/Events");
   frame_40f3c350__54->GetYaxis()->SetLabelFont(42);
   frame_40f3c350__54->GetYaxis()->SetTitleFont(42);
   frame_40f3c350__54->GetZaxis()->SetLabelFont(42);
   frame_40f3c350__54->GetZaxis()->SetTitleOffset(1);
   frame_40f3c350__54->GetZaxis()->SetTitleFont(42);
   frame_40f3c350__54->Draw("AXISSAME");
   
   TH1D *norm_u__55 = new TH1D("norm_u__55","",25,0,2);
   norm_u__55->SetBinContent(3,2.484007);
   norm_u__55->SetBinContent(4,6.788943);
   norm_u__55->SetBinContent(5,9.058186);
   norm_u__55->SetBinContent(6,22.19921);
   norm_u__55->SetBinContent(7,35.66557);
   norm_u__55->SetBinContent(8,59.47335);
   norm_u__55->SetBinContent(9,77.737);
   norm_u__55->SetBinContent(10,96.20699);
   norm_u__55->SetBinContent(11,91.14435);
   norm_u__55->SetBinContent(12,98.4855);
   norm_u__55->SetBinContent(13,80.24472);
   norm_u__55->SetBinContent(14,55.60592);
   norm_u__55->SetBinContent(15,39.44804);
   norm_u__55->SetBinContent(16,24.9042);
   norm_u__55->SetBinContent(17,18.7876);
   norm_u__55->SetBinContent(18,5.769896);
   norm_u__55->SetBinContent(19,3.549036);
   norm_u__55->SetBinContent(20,1.24318);
   norm_u__55->SetBinContent(21,0.7561128);
   norm_u__55->SetBinContent(22,0.1048736);
   norm_u__55->SetBinContent(23,0.1876369);
   norm_u__55->SetBinContent(24,0.4445569);
   norm_u__55->SetBinContent(25,0.406571);
   norm_u__55->SetBinContent(26,0.211128);
   norm_u__55->SetBinError(3,0.8554076);
   norm_u__55->SetBinError(4,1.498814);
   norm_u__55->SetBinError(5,1.871154);
   norm_u__55->SetBinError(6,2.934393);
   norm_u__55->SetBinError(7,4.000523);
   norm_u__55->SetBinError(8,5.12514);
   norm_u__55->SetBinError(9,5.834638);
   norm_u__55->SetBinError(10,6.5696);
   norm_u__55->SetBinError(11,6.441838);
   norm_u__55->SetBinError(12,6.631348);
   norm_u__55->SetBinError(13,5.89581);
   norm_u__55->SetBinError(14,4.843094);
   norm_u__55->SetBinError(15,3.9041);
   norm_u__55->SetBinError(16,3.15891);
   norm_u__55->SetBinError(17,2.659993);
   norm_u__55->SetBinError(18,1.47173);
   norm_u__55->SetBinError(19,1.02762);
   norm_u__55->SetBinError(20,0.4181388);
   norm_u__55->SetBinError(21,0.4242215);
   norm_u__55->SetBinError(22,0.06496281);
   norm_u__55->SetBinError(23,0.1876369);
   norm_u__55->SetBinError(24,0.3459214);
   norm_u__55->SetBinError(25,0.2485361);
   norm_u__55->SetBinError(26,0.1044794);
   norm_u__55->SetEntries(2866);
   norm_u__55->SetStats(0);
   norm_u__55->SetLineColor(4);
   norm_u__55->SetLineWidth(2);
   norm_u__55->GetXaxis()->SetLabelFont(42);
   norm_u__55->GetXaxis()->SetTitleOffset(1);
   norm_u__55->GetXaxis()->SetTitleFont(42);
   norm_u__55->GetYaxis()->SetLabelFont(42);
   norm_u__55->GetYaxis()->SetTitleFont(42);
   norm_u__55->GetZaxis()->SetLabelFont(42);
   norm_u__55->GetZaxis()->SetTitleOffset(1);
   norm_u__55->GetZaxis()->SetTitleFont(42);
   norm_u__55->Draw("e1 same");
   
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
   entry=leg->AddEntry("frame_x_u2_40f3c350","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.849289 #pm 0.009015","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.234886 #pm 0.007110","");
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
   
   TH1D *frame_40f3c350_copy__56 = new TH1D("frame_40f3c350_copy__56","p_T Balance",25,0,2);
   frame_40f3c350_copy__56->SetBinContent(1,110.3727);
   frame_40f3c350_copy__56->SetMaximum(110.3727);
   frame_40f3c350_copy__56->SetEntries(1);
   frame_40f3c350_copy__56->SetDirectory(0);
   frame_40f3c350_copy__56->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40f3c350_copy__56->SetLineColor(ci);
   frame_40f3c350_copy__56->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40f3c350_copy__56->GetXaxis()->SetLabelFont(42);
   frame_40f3c350_copy__56->GetXaxis()->SetTitleOffset(1);
   frame_40f3c350_copy__56->GetXaxis()->SetTitleFont(42);
   frame_40f3c350_copy__56->GetYaxis()->SetTitle("1/Events");
   frame_40f3c350_copy__56->GetYaxis()->SetLabelFont(42);
   frame_40f3c350_copy__56->GetYaxis()->SetTitleFont(42);
   frame_40f3c350_copy__56->GetZaxis()->SetLabelFont(42);
   frame_40f3c350_copy__56->GetZaxis()->SetTitleOffset(1);
   frame_40f3c350_copy__56->GetZaxis()->SetTitleFont(42);
   frame_40f3c350_copy__56->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-17.32981,2.25,106.4546);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_40f1e390__57 = new TH1D("frame_40f1e390__57","p_T Balance",25,0,2);
   frame_40f1e390__57->SetBinContent(1,103.9789);
   frame_40f1e390__57->SetMinimum(-4.951375);
   frame_40f1e390__57->SetMaximum(103.9789);
   frame_40f1e390__57->SetEntries(1);
   frame_40f1e390__57->SetDirectory(0);
   frame_40f1e390__57->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40f1e390__57->SetLineColor(ci);
   frame_40f1e390__57->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40f1e390__57->GetXaxis()->SetLabelFont(42);
   frame_40f1e390__57->GetXaxis()->SetTitleOffset(1);
   frame_40f1e390__57->GetXaxis()->SetTitleFont(42);
   frame_40f1e390__57->GetYaxis()->SetTitle("1/Events");
   frame_40f1e390__57->GetYaxis()->SetLabelFont(42);
   frame_40f1e390__57->GetYaxis()->SetTitleFont(42);
   frame_40f1e390__57->GetZaxis()->SetLabelFont(42);
   frame_40f1e390__57->GetZaxis()->SetTitleOffset(1);
   frame_40f1e390__57->GetZaxis()->SetTitleFont(42);
   frame_40f1e390__57->Draw("FUNC");
   
   Double_t h_dh_down2_fx3015[25] = {
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
   Double_t h_dh_down2_fy3015[25] = {
   0,
   0,
   3.417587,
   7.498263,
   12.9667,
   25.24725,
   34.76823,
   60.36826,
   91.52272,
   83.72319,
   92.65042,
   88.73484,
   67.73856,
   44.60748,
   35.43151,
   19.45061,
   13.25318,
   4.569283,
   3.760594,
   0.9674866,
   0.0790294,
   0.04991241,
   0.5315964,
   0.335228,
   0.2498041};
   Double_t h_dh_down2_felx3015[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_down2_fely3015[25] = {
   0,
   0,
   1.239282,
   1.445169,
   2.334217,
   3.201698,
   3.657188,
   5.066895,
   6.415766,
   5.993772,
   6.377084,
   6.075404,
   5.396223,
   4.123814,
   3.777016,
   2.721731,
   2.03629,
   1.255932,
   1.013742,
   0.3994082,
   0.0577782,
   0.04991241,
   0.3908401,
   0.1969875,
   0.2224305};
   Double_t h_dh_down2_fehx3015[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_down2_fehy3015[25] = {
   0,
   0,
   1.239282,
   1.445169,
   2.334217,
   3.201698,
   3.657188,
   5.066895,
   6.415766,
   5.993772,
   6.377084,
   6.075404,
   5.396223,
   4.123814,
   3.777016,
   2.721731,
   2.03629,
   1.255932,
   1.013742,
   0.3994082,
   0.0577782,
   0.04991241,
   0.3908401,
   0.1969875,
   0.2224305};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3015,h_dh_down2_fy3015,h_dh_down2_felx3015,h_dh_down2_fehx3015,h_dh_down2_fely3015,h_dh_down2_fehy3015);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23015 = new TH1F("Graph_h_dh_down23015","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23015->SetMinimum(-9.902751);
   Graph_h_dh_down23015->SetMaximum(108.9303);
   Graph_h_dh_down23015->SetDirectory(0);
   Graph_h_dh_down23015->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_down23015->SetLineColor(ci);
   Graph_h_dh_down23015->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_down23015->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_down23015->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_down23015->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_down23015->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_down23015->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_down23015->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_down23015->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_down23015);
   
   grae->Draw("p");
   
   Double_t down_fx15[58] = {
   0.1750074,
   0.2255713,
   0.2382123,
   0.2508533,
   0.2761353,
   0.3014173,
   0.3266992,
   0.3519812,
   0.3772632,
   0.4025452,
   0.4278272,
   0.4531091,
   0.4783911,
   0.5036731,
   0.5289551,
   0.579519,
   0.630083,
   0.655365,
   0.680647,
   0.7059289,
   0.7185699,
   0.7312109,
   0.7438519,
   0.7564929,
   0.7691339,
   0.7817749,
   0.7944159,
   0.8070568,
   0.8196978,
   0.8323388,
   0.8449798,
   0.8576208,
   0.8702618,
   0.8829028,
   0.8955438,
   0.9081848,
   0.9208258,
   0.9334667,
   0.9587487,
   0.9840307,
   1.009313,
   1.034595,
   1.085159,
   1.110441,
   1.135723,
   1.161005,
   1.186287,
   1.211569,
   1.236851,
   1.262132,
   1.287414,
   1.312696,
   1.337978,
   1.36326,
   1.388542,
   1.413824,
   1.439106,
   1.439106};
   Double_t down_fy15[58] = {
   4.190205,
   4.431153,
   4.594333,
   5.086955,
   6.538719,
   8.30997,
   10.44187,
   12.97266,
   15.93498,
   19.35291,
   23.23876,
   27.58999,
   32.38636,
   37.58761,
   43.13196,
   54.89392,
   66.7632,
   72.38549,
   77.59575,
   82.2425,
   84.30969,
   86.184,
   87.85041,
   89.29537,
   90.50699,
   91.47518,
   92.19182,
   92.65087,
   92.84845,
   92.78286,
   92.45467,
   91.86667,
   91.02382,
   89.93323,
   88.60399,
   87.04711,
   85.27533,
   83.30297,
   78.82039,
   73.73755,
   68.20414,
   62.37417,
   50.42069,
   44.56755,
   38.9494,
   33.65539,
   28.75283,
   24.28725,
   20.28375,
   16.74905,
   13.67426,
   11.03798,
   8.809421,
   6.951477,
   5.42349,
   4.183622,
   3.190789,
   3.190789};
   graph = new TGraph(58,down_fx15,down_fy15);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down15 = new TH1F("Graph_down15","Projection of downf DSCB fit",100,0.04859746,1.565516);
   Graph_down15->SetMinimum(2.87171);
   Graph_down15->SetMaximum(101.8142);
   Graph_down15->SetDirectory(0);
   Graph_down15->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_down15->SetLineColor(ci);
   Graph_down15->GetXaxis()->SetLabelFont(42);
   Graph_down15->GetXaxis()->SetTitleOffset(1);
   Graph_down15->GetXaxis()->SetTitleFont(42);
   Graph_down15->GetYaxis()->SetLabelFont(42);
   Graph_down15->GetYaxis()->SetTitleFont(42);
   Graph_down15->GetZaxis()->SetLabelFont(42);
   Graph_down15->GetZaxis()->SetTitleOffset(1);
   Graph_down15->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_down15);
   
   graph->Draw("l");
   
   TH1D *frame_40f1e390__58 = new TH1D("frame_40f1e390__58","p_T Balance",25,0,2);
   frame_40f1e390__58->SetBinContent(1,103.9789);
   frame_40f1e390__58->SetMinimum(-4.951375);
   frame_40f1e390__58->SetMaximum(103.9789);
   frame_40f1e390__58->SetEntries(1);
   frame_40f1e390__58->SetDirectory(0);
   frame_40f1e390__58->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40f1e390__58->SetLineColor(ci);
   frame_40f1e390__58->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40f1e390__58->GetXaxis()->SetLabelFont(42);
   frame_40f1e390__58->GetXaxis()->SetTitleOffset(1);
   frame_40f1e390__58->GetXaxis()->SetTitleFont(42);
   frame_40f1e390__58->GetYaxis()->SetTitle("1/Events");
   frame_40f1e390__58->GetYaxis()->SetLabelFont(42);
   frame_40f1e390__58->GetYaxis()->SetTitleFont(42);
   frame_40f1e390__58->GetZaxis()->SetLabelFont(42);
   frame_40f1e390__58->GetZaxis()->SetTitleOffset(1);
   frame_40f1e390__58->GetZaxis()->SetTitleFont(42);
   frame_40f1e390__58->Draw("AXISSAME");
   
   TH1D *norm_d__59 = new TH1D("norm_d__59","",25,0,2);
   norm_d__59->SetBinContent(3,3.417587);
   norm_d__59->SetBinContent(4,7.498264);
   norm_d__59->SetBinContent(5,12.9667);
   norm_d__59->SetBinContent(6,25.24725);
   norm_d__59->SetBinContent(7,34.76823);
   norm_d__59->SetBinContent(8,60.36826);
   norm_d__59->SetBinContent(9,91.52272);
   norm_d__59->SetBinContent(10,83.72319);
   norm_d__59->SetBinContent(11,92.65042);
   norm_d__59->SetBinContent(12,88.73484);
   norm_d__59->SetBinContent(13,67.73855);
   norm_d__59->SetBinContent(14,44.60748);
   norm_d__59->SetBinContent(15,35.43151);
   norm_d__59->SetBinContent(16,19.45061);
   norm_d__59->SetBinContent(17,13.25318);
   norm_d__59->SetBinContent(18,4.569282);
   norm_d__59->SetBinContent(19,3.760594);
   norm_d__59->SetBinContent(20,0.9674866);
   norm_d__59->SetBinContent(21,0.0790294);
   norm_d__59->SetBinContent(22,0.04991241);
   norm_d__59->SetBinContent(23,0.5315964);
   norm_d__59->SetBinContent(24,0.335228);
   norm_d__59->SetBinContent(25,0.2498041);
   norm_d__59->SetBinContent(26,0.1975077);
   norm_d__59->SetBinError(3,1.239282);
   norm_d__59->SetBinError(4,1.445169);
   norm_d__59->SetBinError(5,2.334217);
   norm_d__59->SetBinError(6,3.201698);
   norm_d__59->SetBinError(7,3.657188);
   norm_d__59->SetBinError(8,5.066895);
   norm_d__59->SetBinError(9,6.415766);
   norm_d__59->SetBinError(10,5.993772);
   norm_d__59->SetBinError(11,6.377084);
   norm_d__59->SetBinError(12,6.075404);
   norm_d__59->SetBinError(13,5.396223);
   norm_d__59->SetBinError(14,4.123814);
   norm_d__59->SetBinError(15,3.777016);
   norm_d__59->SetBinError(16,2.721731);
   norm_d__59->SetBinError(17,2.03629);
   norm_d__59->SetBinError(18,1.255932);
   norm_d__59->SetBinError(19,1.013742);
   norm_d__59->SetBinError(20,0.3994082);
   norm_d__59->SetBinError(21,0.0577782);
   norm_d__59->SetBinError(22,0.04991241);
   norm_d__59->SetBinError(23,0.3908401);
   norm_d__59->SetBinError(24,0.1969875);
   norm_d__59->SetBinError(25,0.2224305);
   norm_d__59->SetBinError(26,0.1051775);
   norm_d__59->SetEntries(2904);
   norm_d__59->SetStats(0);
   norm_d__59->SetLineColor(7);
   norm_d__59->SetLineWidth(2);
   norm_d__59->GetXaxis()->SetLabelFont(42);
   norm_d__59->GetXaxis()->SetTitleOffset(1);
   norm_d__59->GetXaxis()->SetTitleFont(42);
   norm_d__59->GetYaxis()->SetLabelFont(42);
   norm_d__59->GetYaxis()->SetTitleFont(42);
   norm_d__59->GetZaxis()->SetLabelFont(42);
   norm_d__59->GetZaxis()->SetTitleOffset(1);
   norm_d__59->GetZaxis()->SetTitleFont(42);
   norm_d__59->Draw("same e1");
   
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
   entry=leg->AddEntry("frame_x_d2_40f1e390","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.822030 #pm 0.009419","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.238634 #pm 0.007486","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.989000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_40f1e390_copy__60 = new TH1D("frame_40f1e390_copy__60","p_T Balance",25,0,2);
   frame_40f1e390_copy__60->SetBinContent(1,103.9789);
   frame_40f1e390_copy__60->SetMinimum(-4.951375);
   frame_40f1e390_copy__60->SetMaximum(103.9789);
   frame_40f1e390_copy__60->SetEntries(1);
   frame_40f1e390_copy__60->SetDirectory(0);
   frame_40f1e390_copy__60->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40f1e390_copy__60->SetLineColor(ci);
   frame_40f1e390_copy__60->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40f1e390_copy__60->GetXaxis()->SetLabelFont(42);
   frame_40f1e390_copy__60->GetXaxis()->SetTitleOffset(1);
   frame_40f1e390_copy__60->GetXaxis()->SetTitleFont(42);
   frame_40f1e390_copy__60->GetYaxis()->SetTitle("1/Events");
   frame_40f1e390_copy__60->GetYaxis()->SetLabelFont(42);
   frame_40f1e390_copy__60->GetYaxis()->SetTitleFont(42);
   frame_40f1e390_copy__60->GetZaxis()->SetLabelFont(42);
   frame_40f1e390_copy__60->GetZaxis()->SetTitleOffset(1);
   frame_40f1e390_copy__60->GetZaxis()->SetTitleFont(42);
   frame_40f1e390_copy__60->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-14.18745,2.25,127.687);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_40f4f9b0__61 = new TH1D("frame_40f4f9b0__61","p_T Balance",25,0,2);
   frame_40f4f9b0__61->SetBinContent(1,124.8495);
   frame_40f4f9b0__61->SetMaximum(124.8495);
   frame_40f4f9b0__61->SetEntries(1);
   frame_40f4f9b0__61->SetDirectory(0);
   frame_40f4f9b0__61->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40f4f9b0__61->SetLineColor(ci);
   frame_40f4f9b0__61->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40f4f9b0__61->GetXaxis()->SetLabelFont(42);
   frame_40f4f9b0__61->GetXaxis()->SetTitleOffset(1);
   frame_40f4f9b0__61->GetXaxis()->SetTitleFont(42);
   frame_40f4f9b0__61->GetYaxis()->SetTitle("1/Events");
   frame_40f4f9b0__61->GetYaxis()->SetLabelFont(42);
   frame_40f4f9b0__61->GetYaxis()->SetTitleFont(42);
   frame_40f4f9b0__61->GetZaxis()->SetLabelFont(42);
   frame_40f4f9b0__61->GetZaxis()->SetTitleOffset(1);
   frame_40f4f9b0__61->GetZaxis()->SetTitleFont(42);
   frame_40f4f9b0__61->Draw("FUNC");
   
   Double_t h_dh_data2_fx3016[25] = {
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
   Double_t h_dh_data2_fy3016[25] = {
   0,
   0,
   3,
   5,
   19,
   36,
   39,
   55,
   97,
   108,
   104,
   78,
   72,
   64,
   32,
   23,
   7,
   7,
   4,
   1,
   3,
   0,
   0,
   0,
   0};
   Double_t h_dh_data2_felx3016[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_data2_fely3016[25] = {
   0,
   0,
   1.632705,
   2.159691,
   4.320219,
   5.971996,
   6.218102,
   7.39358,
   9.831854,
   9.904326,
   9.710289,
   8.812788,
   8.465529,
   7.979042,
   5.627135,
   4.760717,
   2.58147,
   2.58147,
   1.914339,
   0.8272462,
   1.632705,
   0,
   0,
   0,
   0};
   Double_t h_dh_data2_fehx3016[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_data2_fehy3016[25] = {
   1.147874,
   1.147874,
   2.918186,
   3.382473,
   5.435196,
   7.055545,
   7.298372,
   8.461166,
   10.88273,
   10.90433,
   10.71029,
   9.869531,
   9.524592,
   9.041691,
   6.715753,
   5.865235,
   3.770281,
   3.770281,
   3.162753,
   2.299527,
   2.918186,
   1.147874,
   1.147874,
   1.147874,
   1.147874};
   grae = new TGraphAsymmErrors(25,h_dh_data2_fx3016,h_dh_data2_fy3016,h_dh_data2_felx3016,h_dh_data2_fehx3016,h_dh_data2_fely3016,h_dh_data2_fehy3016);
   grae->SetName("h_dh_data2");
   grae->SetTitle("Histogram of dh_data2_plot__x_o2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_data23016 = new TH1F("Graph_h_dh_data23016","Histogram of dh_data2_plot__x_o2",100,0,2.2);
   Graph_h_dh_data23016->SetMinimum(0);
   Graph_h_dh_data23016->SetMaximum(130.7948);
   Graph_h_dh_data23016->SetDirectory(0);
   Graph_h_dh_data23016->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_data23016->SetLineColor(ci);
   Graph_h_dh_data23016->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_data23016->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_data23016->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_data23016->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_data23016->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_data23016->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_data23016->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_data23016->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_data23016);
   
   grae->Draw("p");
   
   Double_t observation_fx16[58] = {
   0.2263352,
   0.2498022,
   0.2732691,
   0.296736,
   0.320203,
   0.3436699,
   0.3671369,
   0.3906038,
   0.4140707,
   0.4375377,
   0.4610046,
   0.4844716,
   0.5079385,
   0.5314054,
   0.5548724,
   0.6018062,
   0.6252732,
   0.6487401,
   0.6722071,
   0.695674,
   0.7191409,
   0.7308744,
   0.7426079,
   0.7543413,
   0.7660748,
   0.7778083,
   0.7895418,
   0.8012752,
   0.8130087,
   0.8247422,
   0.8364756,
   0.8482091,
   0.8599426,
   0.871676,
   0.8834095,
   0.895143,
   0.9068765,
   0.9303434,
   0.9538103,
   0.9772773,
   1.000744,
   1.024211,
   1.071145,
   1.094612,
   1.118079,
   1.141546,
   1.165013,
   1.18848,
   1.211947,
   1.235414,
   1.258881,
   1.282347,
   1.305814,
   1.329281,
   1.352748,
   1.376215,
   1.399682,
   1.399682};
   Double_t observation_fy16[58] = {
   4.067025,
   5.242542,
   6.688318,
   8.444761,
   10.55245,
   13.05012,
   15.97244,
   19.34743,
   23.19375,
   27.51781,
   32.31114,
   37.54794,
   43.18325,
   49.15187,
   55.36817,
   68.10619,
   74.36918,
   80.37015,
   85.95912,
   90.9881,
   95.31751,
   97.18013,
   98.82257,
   100.2325,
   101.3993,
   102.3141,
   102.9697,
   103.3612,
   103.4854,
   103.3415,
   102.9306,
   102.2557,
   101.3223,
   100.1373,
   98.70995,
   97.05094,
   95.1727,
   90.81535,
   85.76331,
   80.1566,
   74.14338,
   67.87361,
   55.13716,
   48.9282,
   42.97041,
   37.34867,
   32.12745,
   27.35097,
   23.04436,
   19.21552,
   15.85751,
   12.95129,
   10.46855,
   8.37444,
   6.630103,
   5.194936,
   4.028427,
   4.028427};
   graph = new TGraph(58,observation_fx16,observation_fy16);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation16 = new TH1F("Graph_observation16","Projection of obsf DSCB fit",100,0.1090005,1.517017);
   Graph_observation16->SetMinimum(3.625585);
   Graph_observation16->SetMaximum(113.4311);
   Graph_observation16->SetDirectory(0);
   Graph_observation16->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_observation16->SetLineColor(ci);
   Graph_observation16->GetXaxis()->SetLabelFont(42);
   Graph_observation16->GetXaxis()->SetTitleOffset(1);
   Graph_observation16->GetXaxis()->SetTitleFont(42);
   Graph_observation16->GetYaxis()->SetLabelFont(42);
   Graph_observation16->GetYaxis()->SetTitleFont(42);
   Graph_observation16->GetZaxis()->SetLabelFont(42);
   Graph_observation16->GetZaxis()->SetTitleOffset(1);
   Graph_observation16->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_observation16);
   
   graph->Draw("l");
   
   TH1D *frame_40f4f9b0__62 = new TH1D("frame_40f4f9b0__62","p_T Balance",25,0,2);
   frame_40f4f9b0__62->SetBinContent(1,124.8495);
   frame_40f4f9b0__62->SetMaximum(124.8495);
   frame_40f4f9b0__62->SetEntries(1);
   frame_40f4f9b0__62->SetDirectory(0);
   frame_40f4f9b0__62->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40f4f9b0__62->SetLineColor(ci);
   frame_40f4f9b0__62->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40f4f9b0__62->GetXaxis()->SetLabelFont(42);
   frame_40f4f9b0__62->GetXaxis()->SetTitleOffset(1);
   frame_40f4f9b0__62->GetXaxis()->SetTitleFont(42);
   frame_40f4f9b0__62->GetYaxis()->SetTitle("1/Events");
   frame_40f4f9b0__62->GetYaxis()->SetLabelFont(42);
   frame_40f4f9b0__62->GetYaxis()->SetTitleFont(42);
   frame_40f4f9b0__62->GetZaxis()->SetLabelFont(42);
   frame_40f4f9b0__62->GetZaxis()->SetTitleOffset(1);
   frame_40f4f9b0__62->GetZaxis()->SetTitleFont(42);
   frame_40f4f9b0__62->Draw("AXISSAME");
   
   TH1D *norm_o__63 = new TH1D("norm_o__63","",25,0,2);
   norm_o__63->SetBinContent(3,3);
   norm_o__63->SetBinContent(4,5);
   norm_o__63->SetBinContent(5,19);
   norm_o__63->SetBinContent(6,36);
   norm_o__63->SetBinContent(7,39);
   norm_o__63->SetBinContent(8,55);
   norm_o__63->SetBinContent(9,97);
   norm_o__63->SetBinContent(10,108);
   norm_o__63->SetBinContent(11,104);
   norm_o__63->SetBinContent(12,78);
   norm_o__63->SetBinContent(13,72);
   norm_o__63->SetBinContent(14,64);
   norm_o__63->SetBinContent(15,32);
   norm_o__63->SetBinContent(16,23);
   norm_o__63->SetBinContent(17,7);
   norm_o__63->SetBinContent(18,7);
   norm_o__63->SetBinContent(19,4);
   norm_o__63->SetBinContent(20,1);
   norm_o__63->SetBinContent(21,3);
   norm_o__63->SetBinContent(26,1);
   norm_o__63->SetMinimum(0);
   norm_o__63->SetMaximum(237.6);
   norm_o__63->SetEntries(758);
   norm_o__63->SetStats(0);
   norm_o__63->SetLineWidth(2);
   norm_o__63->SetMarkerStyle(8);
   norm_o__63->SetMarkerSize(0.4);
   norm_o__63->GetXaxis()->SetRange(1,25);
   norm_o__63->GetXaxis()->SetLabelFont(42);
   norm_o__63->GetXaxis()->SetLabelSize(0.04);
   norm_o__63->GetXaxis()->SetTitleOffset(1);
   norm_o__63->GetXaxis()->SetTitleFont(42);
   norm_o__63->GetYaxis()->SetTitle("Events");
   norm_o__63->GetYaxis()->SetLabelFont(42);
   norm_o__63->GetYaxis()->SetTitleOffset(1.4);
   norm_o__63->GetYaxis()->SetTitleFont(42);
   norm_o__63->GetZaxis()->SetLabelFont(42);
   norm_o__63->GetZaxis()->SetTitleOffset(1);
   norm_o__63->GetZaxis()->SetTitleFont(42);
   norm_o__63->Draw("same e1");
   
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
   entry=leg->AddEntry("frame_x_o2_40f4f9b0","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.812580 #pm 0.008832","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.230439 #pm 0.007156","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.965000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_40f4f9b0_copy__64 = new TH1D("frame_40f4f9b0_copy__64","p_T Balance",25,0,2);
   frame_40f4f9b0_copy__64->SetBinContent(1,124.8495);
   frame_40f4f9b0_copy__64->SetMaximum(124.8495);
   frame_40f4f9b0_copy__64->SetEntries(1);
   frame_40f4f9b0_copy__64->SetDirectory(0);
   frame_40f4f9b0_copy__64->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40f4f9b0_copy__64->SetLineColor(ci);
   frame_40f4f9b0_copy__64->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40f4f9b0_copy__64->GetXaxis()->SetLabelFont(42);
   frame_40f4f9b0_copy__64->GetXaxis()->SetTitleOffset(1);
   frame_40f4f9b0_copy__64->GetXaxis()->SetTitleFont(42);
   frame_40f4f9b0_copy__64->GetYaxis()->SetTitle("1/Events");
   frame_40f4f9b0_copy__64->GetYaxis()->SetLabelFont(42);
   frame_40f4f9b0_copy__64->GetYaxis()->SetTitleFont(42);
   frame_40f4f9b0_copy__64->GetZaxis()->SetLabelFont(42);
   frame_40f4f9b0_copy__64->GetZaxis()->SetTitleOffset(1);
   frame_40f4f9b0_copy__64->GetZaxis()->SetTitleFont(42);
   frame_40f4f9b0_copy__64->Draw("sameaxis");
   
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
