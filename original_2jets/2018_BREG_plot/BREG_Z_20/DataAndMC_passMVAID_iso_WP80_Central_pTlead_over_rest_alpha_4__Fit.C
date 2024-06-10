void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_4__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 19:39:51 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-31.90486,2.25,366.9059);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_417d0bf0__49 = new TH1D("frame_417d0bf0__49","p_T Balance",25,0,2);
   frame_417d0bf0__49->SetBinContent(1,327.0249);
   frame_417d0bf0__49->SetMaximum(327.0249);
   frame_417d0bf0__49->SetEntries(1);
   frame_417d0bf0__49->SetDirectory(0);
   frame_417d0bf0__49->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_417d0bf0__49->SetLineColor(ci);
   frame_417d0bf0__49->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_417d0bf0__49->GetXaxis()->SetLabelFont(42);
   frame_417d0bf0__49->GetXaxis()->SetTitleOffset(1);
   frame_417d0bf0__49->GetXaxis()->SetTitleFont(42);
   frame_417d0bf0__49->GetYaxis()->SetTitle("1/Events");
   frame_417d0bf0__49->GetYaxis()->SetLabelFont(42);
   frame_417d0bf0__49->GetYaxis()->SetTitleFont(42);
   frame_417d0bf0__49->GetZaxis()->SetLabelFont(42);
   frame_417d0bf0__49->GetZaxis()->SetTitleOffset(1);
   frame_417d0bf0__49->GetZaxis()->SetTitleFont(42);
   frame_417d0bf0__49->Draw("FUNC");
   
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
   4.32978,
   28.23114,
   46.3025,
   73.43679,
   125.2605,
   182.0355,
   259.5834,
   292.8219,
   299.5335,
   288.2154,
   247.477,
   169.3754,
   121.161,
   76.42633,
   41.42902,
   24.22076,
   9.342108,
   6.519591,
   3.098739,
   1.796563,
   0.9291521,
   0.6338664,
   0.1943106};
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
   1.402904,
   3.410024,
   4.433966,
   5.640972,
   7.428572,
   9.10988,
   10.94447,
   11.43517,
   11.91874,
   11.53391,
   10.71162,
   8.529471,
   7.102238,
   5.546234,
   3.916338,
   2.83326,
   1.68136,
   1.377711,
   0.7892493,
   0.5242786,
   0.3370524,
   0.2188173,
   0.08711414};
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
   1.402904,
   3.410024,
   4.433966,
   5.640972,
   7.428572,
   9.10988,
   10.94447,
   11.43517,
   11.91874,
   11.53391,
   10.71162,
   8.529471,
   7.102238,
   5.546234,
   3.916338,
   2.83326,
   1.68136,
   1.377711,
   0.7892493,
   0.5242786,
   0.3370524,
   0.2188173,
   0.08711414};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3013,h_dh_central2_fy3013,h_dh_central2_felx3013,h_dh_central2_fehx3013,h_dh_central2_fely3013,h_dh_central2_fehy3013);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23013 = new TH1F("Graph_h_dh_central23013","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23013->SetMinimum(0);
   Graph_h_dh_central23013->SetMaximum(342.5975);
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
   
   Double_t Central_fx13[57] = {
   0.2404877,
   0.2885027,
   0.3125102,
   0.3245139,
   0.3365177,
   0.3605252,
   0.3845327,
   0.4085401,
   0.4325476,
   0.4565551,
   0.4805626,
   0.5045701,
   0.5285776,
   0.5765926,
   0.6246076,
   0.6486151,
   0.6726225,
   0.69663,
   0.7206375,
   0.744645,
   0.7566488,
   0.7686525,
   0.7806563,
   0.79266,
   0.8046637,
   0.8166675,
   0.8286712,
   0.840675,
   0.8526787,
   0.8646825,
   0.8766862,
   0.88869,
   0.9006937,
   0.9126975,
   0.9247012,
   0.9367049,
   0.9607124,
   0.9847199,
   1.008727,
   1.032735,
   1.056742,
   1.104757,
   1.128765,
   1.152772,
   1.17678,
   1.200787,
   1.224795,
   1.248802,
   1.27281,
   1.296817,
   1.320825,
   1.344832,
   1.36884,
   1.392847,
   1.416855,
   1.440862,
   1.440862};
   Double_t Central_fy13[57] = {
   28.12099,
   29.20764,
   30.45701,
   32.12406,
   35.63341,
   43.54362,
   52.68818,
   63.12818,
   74.89535,
   87.98484,
   102.3487,
   117.8904,
   134.4608,
   169.8224,
   206.1959,
   223.8745,
   240.686,
   256.2232,
   270.0894,
   281.915,
   286.9584,
   291.3736,
   295.1289,
   298.1972,
   300.5563,
   302.1889,
   303.083,
   303.2319,
   302.6347,
   301.2956,
   299.2246,
   296.4368,
   292.9526,
   288.7972,
   284.0003,
   278.5962,
   266.1208,
   251.7121,
   235.7494,
   218.6345,
   200.7744,
   164.3811,
   146.5567,
   129.3842,
   113.104,
   97.90307,
   83.91432,
   71.21924,
   59.85219,
   49.80629,
   41.04023,
   33.48551,
   27.05362,
   21.6429,
   17.14458,
   13.44807,
   13.44807};
   TGraph *graph = new TGraph(57,Central_fx13,Central_fy13);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central13 = new TH1F("Graph_Central13","Projection of centralf DSCB fit",100,0.1204503,1.5609);
   Graph_Central13->SetMinimum(12.10326);
   Graph_Central13->SetMaximum(332.2103);
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
   
   TH1D *frame_417d0bf0__50 = new TH1D("frame_417d0bf0__50","p_T Balance",25,0,2);
   frame_417d0bf0__50->SetBinContent(1,327.0249);
   frame_417d0bf0__50->SetMaximum(327.0249);
   frame_417d0bf0__50->SetEntries(1);
   frame_417d0bf0__50->SetDirectory(0);
   frame_417d0bf0__50->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_417d0bf0__50->SetLineColor(ci);
   frame_417d0bf0__50->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_417d0bf0__50->GetXaxis()->SetLabelFont(42);
   frame_417d0bf0__50->GetXaxis()->SetTitleOffset(1);
   frame_417d0bf0__50->GetXaxis()->SetTitleFont(42);
   frame_417d0bf0__50->GetYaxis()->SetTitle("1/Events");
   frame_417d0bf0__50->GetYaxis()->SetLabelFont(42);
   frame_417d0bf0__50->GetYaxis()->SetTitleFont(42);
   frame_417d0bf0__50->GetZaxis()->SetLabelFont(42);
   frame_417d0bf0__50->GetZaxis()->SetTitleOffset(1);
   frame_417d0bf0__50->GetZaxis()->SetTitleFont(42);
   frame_417d0bf0__50->Draw("AXISSAME");
   
   TH1D *norm_c__51 = new TH1D("norm_c__51","",25,0,2);
   norm_c__51->SetBinContent(3,4.32978);
   norm_c__51->SetBinContent(4,28.23114);
   norm_c__51->SetBinContent(5,46.3025);
   norm_c__51->SetBinContent(6,73.43679);
   norm_c__51->SetBinContent(7,125.2605);
   norm_c__51->SetBinContent(8,182.0355);
   norm_c__51->SetBinContent(9,259.5834);
   norm_c__51->SetBinContent(10,292.8219);
   norm_c__51->SetBinContent(11,299.5335);
   norm_c__51->SetBinContent(12,288.2154);
   norm_c__51->SetBinContent(13,247.477);
   norm_c__51->SetBinContent(14,169.3754);
   norm_c__51->SetBinContent(15,121.161);
   norm_c__51->SetBinContent(16,76.42633);
   norm_c__51->SetBinContent(17,41.42902);
   norm_c__51->SetBinContent(18,24.22076);
   norm_c__51->SetBinContent(19,9.342108);
   norm_c__51->SetBinContent(20,6.519591);
   norm_c__51->SetBinContent(21,3.098739);
   norm_c__51->SetBinContent(22,1.796563);
   norm_c__51->SetBinContent(23,0.9291521);
   norm_c__51->SetBinContent(24,0.6338664);
   norm_c__51->SetBinContent(25,0.1943106);
   norm_c__51->SetBinContent(26,1.491363);
   norm_c__51->SetBinError(3,1.402904);
   norm_c__51->SetBinError(4,3.410024);
   norm_c__51->SetBinError(5,4.433966);
   norm_c__51->SetBinError(6,5.640972);
   norm_c__51->SetBinError(7,7.428572);
   norm_c__51->SetBinError(8,9.10988);
   norm_c__51->SetBinError(9,10.94447);
   norm_c__51->SetBinError(10,11.43517);
   norm_c__51->SetBinError(11,11.91874);
   norm_c__51->SetBinError(12,11.53391);
   norm_c__51->SetBinError(13,10.71162);
   norm_c__51->SetBinError(14,8.529471);
   norm_c__51->SetBinError(15,7.102238);
   norm_c__51->SetBinError(16,5.546234);
   norm_c__51->SetBinError(17,3.916338);
   norm_c__51->SetBinError(18,2.83326);
   norm_c__51->SetBinError(19,1.68136);
   norm_c__51->SetBinError(20,1.377711);
   norm_c__51->SetBinError(21,0.7892493);
   norm_c__51->SetBinError(22,0.5242786);
   norm_c__51->SetBinError(23,0.3370524);
   norm_c__51->SetBinError(24,0.2188173);
   norm_c__51->SetBinError(25,0.08711414);
   norm_c__51->SetBinError(26,0.3432336);
   norm_c__51->SetEntries(10045);
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
   entry=leg->AddEntry("frame_x_c2_417d0bf0","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.833393 #pm 0.005296","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.242332 #pm 0.004241","");
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
   
   TH1D *frame_417d0bf0_copy__52 = new TH1D("frame_417d0bf0_copy__52","p_T Balance",25,0,2);
   frame_417d0bf0_copy__52->SetBinContent(1,327.0249);
   frame_417d0bf0_copy__52->SetMaximum(327.0249);
   frame_417d0bf0_copy__52->SetEntries(1);
   frame_417d0bf0_copy__52->SetDirectory(0);
   frame_417d0bf0_copy__52->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_417d0bf0_copy__52->SetLineColor(ci);
   frame_417d0bf0_copy__52->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_417d0bf0_copy__52->GetXaxis()->SetLabelFont(42);
   frame_417d0bf0_copy__52->GetXaxis()->SetTitleOffset(1);
   frame_417d0bf0_copy__52->GetXaxis()->SetTitleFont(42);
   frame_417d0bf0_copy__52->GetYaxis()->SetTitle("1/Events");
   frame_417d0bf0_copy__52->GetYaxis()->SetLabelFont(42);
   frame_417d0bf0_copy__52->GetYaxis()->SetTitleFont(42);
   frame_417d0bf0_copy__52->GetZaxis()->SetLabelFont(42);
   frame_417d0bf0_copy__52->GetZaxis()->SetTitleOffset(1);
   frame_417d0bf0_copy__52->GetZaxis()->SetTitleFont(42);
   frame_417d0bf0_copy__52->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-33.3594,2.25,383.6331);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_417d6cf0__53 = new TH1D("frame_417d6cf0__53","p_T Balance",25,0,2);
   frame_417d6cf0__53->SetBinContent(1,341.9338);
   frame_417d6cf0__53->SetMaximum(341.9338);
   frame_417d6cf0__53->SetEntries(1);
   frame_417d6cf0__53->SetDirectory(0);
   frame_417d6cf0__53->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_417d6cf0__53->SetLineColor(ci);
   frame_417d6cf0__53->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_417d6cf0__53->GetXaxis()->SetLabelFont(42);
   frame_417d6cf0__53->GetXaxis()->SetTitleOffset(1);
   frame_417d6cf0__53->GetXaxis()->SetTitleFont(42);
   frame_417d6cf0__53->GetYaxis()->SetTitle("1/Events");
   frame_417d6cf0__53->GetYaxis()->SetLabelFont(42);
   frame_417d6cf0__53->GetYaxis()->SetTitleFont(42);
   frame_417d6cf0__53->GetZaxis()->SetLabelFont(42);
   frame_417d6cf0__53->GetZaxis()->SetTitleOffset(1);
   frame_417d6cf0__53->GetZaxis()->SetTitleFont(42);
   frame_417d6cf0__53->Draw("FUNC");
   
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
   2.373192,
   23.40988,
   42.78963,
   66.72723,
   103.5674,
   166.5666,
   242.8811,
   293.7557,
   313.4442,
   310.5315,
   273.2942,
   206.4211,
   145.2496,
   81.08298,
   45.0039,
   28.31038,
   11.59107,
   6.207559,
   2.14835,
   2.021455,
   1.19141,
   0.4250821,
   0.2263639};
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
   0.7183079,
   3.16765,
   4.259477,
   5.336985,
   6.85953,
   8.67764,
   10.62086,
   11.69246,
   12.207,
   12.18029,
   11.31462,
   9.734237,
   8.028883,
   5.784208,
   4.145583,
   3.100842,
   1.877463,
   1.335202,
   0.6317222,
   0.6262043,
   0.4378875,
   0.1470468,
   0.08558781};
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
   0.7183079,
   3.16765,
   4.259477,
   5.336985,
   6.85953,
   8.67764,
   10.62086,
   11.69246,
   12.207,
   12.18029,
   11.31462,
   9.734237,
   8.028883,
   5.784208,
   4.145583,
   3.100842,
   1.877463,
   1.335202,
   0.6317222,
   0.6262043,
   0.4378875,
   0.1470468,
   0.08558781};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3014,h_dh_up2_fy3014,h_dh_up2_felx3014,h_dh_up2_fehx3014,h_dh_up2_fely3014,h_dh_up2_fehy3014);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23014 = new TH1F("Graph_h_dh_up23014","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23014->SetMinimum(0);
   Graph_h_dh_up23014->SetMaximum(358.2164);
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
   0.2519714,
   0.3002007,
   0.3243153,
   0.3484299,
   0.3725445,
   0.3966591,
   0.4207737,
   0.4448884,
   0.469003,
   0.4810603,
   0.4931176,
   0.5172322,
   0.5413468,
   0.5654614,
   0.589576,
   0.6378053,
   0.6860345,
   0.7101491,
   0.7342637,
   0.7583784,
   0.7704357,
   0.782493,
   0.7945503,
   0.8066076,
   0.8186649,
   0.8307222,
   0.8427795,
   0.8548368,
   0.8668941,
   0.8789514,
   0.8910088,
   0.9030661,
   0.9151234,
   0.9271807,
   0.939238,
   0.9512953,
   0.9633526,
   0.9754099,
   0.9995245,
   1.023639,
   1.047754,
   1.071868,
   1.120098,
   1.144212,
   1.168327,
   1.192441,
   1.216556,
   1.240671,
   1.264785,
   1.2889,
   1.313015,
   1.337129,
   1.361244,
   1.385358,
   1.409473,
   1.433588,
   1.457702,
   1.457702};
   Double_t up_fy14[58] = {
   25.57078,
   31.55281,
   35.27089,
   39.61124,
   44.71162,
   50.74853,
   57.95051,
   66.61716,
   77.14653,
   83.27056,
   90.07529,
   105.6384,
   122.688,
   140.9589,
   160.2112,
   200.3665,
   239.9928,
   258.4343,
   275.3039,
   290.1248,
   296.6283,
   302.4598,
   307.5746,
   311.9326,
   315.4994,
   318.2468,
   320.1526,
   321.2015,
   321.3851,
   320.7018,
   319.1572,
   316.7638,
   313.5407,
   309.5137,
   304.7147,
   299.1813,
   292.9565,
   286.0878,
   270.6291,
   253.2561,
   234.4529,
   214.7146,
   174.3429,
   154.5756,
   135.5776,
   117.6374,
   100.9748,
   85.74142,
   72.02425,
   59.85178,
   49.20233,
   40.01332,
   32.19094,
   25.61964,
   20.17078,
   15.71023,
   12.10467,
   12.10467};
   graph = new TGraph(58,up_fx14,up_fy14);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up14 = new TH1F("Graph_up14","Projection of upf DSCB fit",100,0.1313983,1.578275);
   Graph_up14->SetMinimum(10.8942);
   Graph_up14->SetMaximum(352.3131);
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
   
   TH1D *frame_417d6cf0__54 = new TH1D("frame_417d6cf0__54","p_T Balance",25,0,2);
   frame_417d6cf0__54->SetBinContent(1,341.9338);
   frame_417d6cf0__54->SetMaximum(341.9338);
   frame_417d6cf0__54->SetEntries(1);
   frame_417d6cf0__54->SetDirectory(0);
   frame_417d6cf0__54->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_417d6cf0__54->SetLineColor(ci);
   frame_417d6cf0__54->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_417d6cf0__54->GetXaxis()->SetLabelFont(42);
   frame_417d6cf0__54->GetXaxis()->SetTitleOffset(1);
   frame_417d6cf0__54->GetXaxis()->SetTitleFont(42);
   frame_417d6cf0__54->GetYaxis()->SetTitle("1/Events");
   frame_417d6cf0__54->GetYaxis()->SetLabelFont(42);
   frame_417d6cf0__54->GetYaxis()->SetTitleFont(42);
   frame_417d6cf0__54->GetZaxis()->SetLabelFont(42);
   frame_417d6cf0__54->GetZaxis()->SetTitleOffset(1);
   frame_417d6cf0__54->GetZaxis()->SetTitleFont(42);
   frame_417d6cf0__54->Draw("AXISSAME");
   
   TH1D *norm_u__55 = new TH1D("norm_u__55","",25,0,2);
   norm_u__55->SetBinContent(3,2.373192);
   norm_u__55->SetBinContent(4,23.40988);
   norm_u__55->SetBinContent(5,42.78963);
   norm_u__55->SetBinContent(6,66.72723);
   norm_u__55->SetBinContent(7,103.5674);
   norm_u__55->SetBinContent(8,166.5666);
   norm_u__55->SetBinContent(9,242.8811);
   norm_u__55->SetBinContent(10,293.7557);
   norm_u__55->SetBinContent(11,313.4442);
   norm_u__55->SetBinContent(12,310.5315);
   norm_u__55->SetBinContent(13,273.2942);
   norm_u__55->SetBinContent(14,206.4211);
   norm_u__55->SetBinContent(15,145.2497);
   norm_u__55->SetBinContent(16,81.08298);
   norm_u__55->SetBinContent(17,45.0039);
   norm_u__55->SetBinContent(18,28.31038);
   norm_u__55->SetBinContent(19,11.59107);
   norm_u__55->SetBinContent(20,6.207559);
   norm_u__55->SetBinContent(21,2.14835);
   norm_u__55->SetBinContent(22,2.021455);
   norm_u__55->SetBinContent(23,1.19141);
   norm_u__55->SetBinContent(24,0.4250821);
   norm_u__55->SetBinContent(25,0.2263639);
   norm_u__55->SetBinContent(26,1.649469);
   norm_u__55->SetBinError(3,0.7183079);
   norm_u__55->SetBinError(4,3.16765);
   norm_u__55->SetBinError(5,4.259477);
   norm_u__55->SetBinError(6,5.336985);
   norm_u__55->SetBinError(7,6.85953);
   norm_u__55->SetBinError(8,8.67764);
   norm_u__55->SetBinError(9,10.62086);
   norm_u__55->SetBinError(10,11.69246);
   norm_u__55->SetBinError(11,12.207);
   norm_u__55->SetBinError(12,12.18029);
   norm_u__55->SetBinError(13,11.31462);
   norm_u__55->SetBinError(14,9.734237);
   norm_u__55->SetBinError(15,8.028883);
   norm_u__55->SetBinError(16,5.784208);
   norm_u__55->SetBinError(17,4.145583);
   norm_u__55->SetBinError(18,3.100842);
   norm_u__55->SetBinError(19,1.877463);
   norm_u__55->SetBinError(20,1.335202);
   norm_u__55->SetBinError(21,0.6317222);
   norm_u__55->SetBinError(22,0.6262043);
   norm_u__55->SetBinError(23,0.4378875);
   norm_u__55->SetBinError(24,0.1470468);
   norm_u__55->SetBinError(25,0.08558781);
   norm_u__55->SetBinError(26,0.3679635);
   norm_u__55->SetEntries(9947);
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
   entry=leg->AddEntry("frame_x_u2_417d6cf0","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.856692 #pm 0.005195","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.240312 #pm 0.004264","");
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
   
   TH1D *frame_417d6cf0_copy__56 = new TH1D("frame_417d6cf0_copy__56","p_T Balance",25,0,2);
   frame_417d6cf0_copy__56->SetBinContent(1,341.9338);
   frame_417d6cf0_copy__56->SetMaximum(341.9338);
   frame_417d6cf0_copy__56->SetEntries(1);
   frame_417d6cf0_copy__56->SetDirectory(0);
   frame_417d6cf0_copy__56->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_417d6cf0_copy__56->SetLineColor(ci);
   frame_417d6cf0_copy__56->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_417d6cf0_copy__56->GetXaxis()->SetLabelFont(42);
   frame_417d6cf0_copy__56->GetXaxis()->SetTitleOffset(1);
   frame_417d6cf0_copy__56->GetXaxis()->SetTitleFont(42);
   frame_417d6cf0_copy__56->GetYaxis()->SetTitle("1/Events");
   frame_417d6cf0_copy__56->GetYaxis()->SetLabelFont(42);
   frame_417d6cf0_copy__56->GetYaxis()->SetTitleFont(42);
   frame_417d6cf0_copy__56->GetZaxis()->SetLabelFont(42);
   frame_417d6cf0_copy__56->GetZaxis()->SetTitleOffset(1);
   frame_417d6cf0_copy__56->GetZaxis()->SetTitleFont(42);
   frame_417d6cf0_copy__56->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-36.77601,2.25,330.9841);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_417adc50__57 = new TH1D("frame_417adc50__57","p_T Balance",25,0,2);
   frame_417adc50__57->SetBinContent(1,323.6289);
   frame_417adc50__57->SetMaximum(323.6289);
   frame_417adc50__57->SetEntries(1);
   frame_417adc50__57->SetDirectory(0);
   frame_417adc50__57->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_417adc50__57->SetLineColor(ci);
   frame_417adc50__57->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_417adc50__57->GetXaxis()->SetLabelFont(42);
   frame_417adc50__57->GetXaxis()->SetTitleOffset(1);
   frame_417adc50__57->GetXaxis()->SetTitleFont(42);
   frame_417adc50__57->GetYaxis()->SetTitle("1/Events");
   frame_417adc50__57->GetYaxis()->SetLabelFont(42);
   frame_417adc50__57->GetYaxis()->SetTitleFont(42);
   frame_417adc50__57->GetZaxis()->SetLabelFont(42);
   frame_417adc50__57->GetZaxis()->SetTitleOffset(1);
   frame_417adc50__57->GetZaxis()->SetTitleFont(42);
   frame_417adc50__57->Draw("FUNC");
   
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
   2.322174,
   29.69407,
   53.28325,
   84.94643,
   137.1925,
   208.9921,
   269.8676,
   296.6661,
   291.0599,
   274.3952,
   216.6916,
   146.9152,
   103.371,
   61.08587,
   38.64802,
   19.81284,
   10.09308,
   5.738558,
   2.994958,
   1.472417,
   0.5843153,
   0.3768772,
   0.2093615};
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
   0.7854781,
   3.314107,
   4.746879,
   5.997994,
   7.827018,
   9.757364,
   11.11544,
   11.55187,
   11.55436,
   11.26634,
   9.894651,
   7.934843,
   6.510731,
   4.864739,
   3.706114,
   2.500999,
   1.770571,
   1.216579,
   0.7313962,
   0.4648786,
   0.20895,
   0.1322189,
   0.09268121};
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
   0.7854781,
   3.314107,
   4.746879,
   5.997994,
   7.827018,
   9.757364,
   11.11544,
   11.55187,
   11.55436,
   11.26634,
   9.894651,
   7.934843,
   6.510731,
   4.864739,
   3.706114,
   2.500999,
   1.770571,
   1.216579,
   0.7313962,
   0.4648786,
   0.20895,
   0.1322189,
   0.09268121};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3015,h_dh_down2_fy3015,h_dh_down2_felx3015,h_dh_down2_fehx3015,h_dh_down2_fely3015,h_dh_down2_fehy3015);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23015 = new TH1F("Graph_h_dh_down23015","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23015->SetMinimum(0);
   Graph_h_dh_down23015->SetMaximum(339.0398);
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
   0.2202888,
   0.24402,
   0.2677512,
   0.2914824,
   0.3152136,
   0.3389448,
   0.3626759,
   0.3864071,
   0.4101383,
   0.4338695,
   0.4576007,
   0.4813318,
   0.505063,
   0.5287942,
   0.5525254,
   0.5999878,
   0.6237189,
   0.6474501,
   0.6711813,
   0.6949125,
   0.7067781,
   0.7186437,
   0.7305092,
   0.7423748,
   0.7542404,
   0.766106,
   0.7779716,
   0.7898372,
   0.8017028,
   0.8135684,
   0.825434,
   0.8372996,
   0.8491652,
   0.8610307,
   0.8728963,
   0.8847619,
   0.8966275,
   0.9084931,
   0.9322243,
   0.9559555,
   0.9796867,
   1.003418,
   1.027149,
   1.074611,
   1.098343,
   1.122074,
   1.145805,
   1.169536,
   1.193267,
   1.205133,
   1.216998,
   1.24073,
   1.264461,
   1.288192,
   1.311923,
   1.359386,
   1.406848,
   1.406848};
   Double_t down_fy15[58] = {
   13.51424,
   17.29611,
   21.91168,
   27.47724,
   34.10678,
   41.90622,
   50.96671,
   61.35711,
   73.11616,
   86.24464,
   100.698,
   116.3805,
   133.1403,
   150.768,
   168.997,
   205.9346,
   223.8771,
   240.9131,
   256.6146,
   270.5655,
   276.7622,
   282.3799,
   287.3779,
   291.7194,
   295.3724,
   298.3095,
   300.5086,
   301.9529,
   302.6314,
   302.539,
   301.6764,
   300.0501,
   297.6726,
   294.5618,
   290.7412,
   286.2394,
   281.0895,
   275.3293,
   262.1475,
   247.0639,
   230.4852,
   212.8369,
   194.5455,
   157.645,
   139.7543,
   122.6366,
   106.5235,
   91.58849,
   77.9774,
   72.17174,
   67.18129,
   59.04159,
   52.68229,
   47.57497,
   43.38179,
   36.90236,
   32.12605,
   32.12605};
   graph = new TGraph(58,down_fx15,down_fy15);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down15 = new TH1F("Graph_down15","Projection of downf DSCB fit",100,0.1016329,1.525504);
   Graph_down15->SetMinimum(12.16281);
   Graph_down15->SetMaximum(331.5431);
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
   
   TH1D *frame_417adc50__58 = new TH1D("frame_417adc50__58","p_T Balance",25,0,2);
   frame_417adc50__58->SetBinContent(1,323.6289);
   frame_417adc50__58->SetMaximum(323.6289);
   frame_417adc50__58->SetEntries(1);
   frame_417adc50__58->SetDirectory(0);
   frame_417adc50__58->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_417adc50__58->SetLineColor(ci);
   frame_417adc50__58->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_417adc50__58->GetXaxis()->SetLabelFont(42);
   frame_417adc50__58->GetXaxis()->SetTitleOffset(1);
   frame_417adc50__58->GetXaxis()->SetTitleFont(42);
   frame_417adc50__58->GetYaxis()->SetTitle("1/Events");
   frame_417adc50__58->GetYaxis()->SetLabelFont(42);
   frame_417adc50__58->GetYaxis()->SetTitleFont(42);
   frame_417adc50__58->GetZaxis()->SetLabelFont(42);
   frame_417adc50__58->GetZaxis()->SetTitleOffset(1);
   frame_417adc50__58->GetZaxis()->SetTitleFont(42);
   frame_417adc50__58->Draw("AXISSAME");
   
   TH1D *norm_d__59 = new TH1D("norm_d__59","",25,0,2);
   norm_d__59->SetBinContent(3,2.322174);
   norm_d__59->SetBinContent(4,29.69407);
   norm_d__59->SetBinContent(5,53.28325);
   norm_d__59->SetBinContent(6,84.94642);
   norm_d__59->SetBinContent(7,137.1925);
   norm_d__59->SetBinContent(8,208.9921);
   norm_d__59->SetBinContent(9,269.8676);
   norm_d__59->SetBinContent(10,296.6661);
   norm_d__59->SetBinContent(11,291.0599);
   norm_d__59->SetBinContent(12,274.3952);
   norm_d__59->SetBinContent(13,216.6916);
   norm_d__59->SetBinContent(14,146.9152);
   norm_d__59->SetBinContent(15,103.371);
   norm_d__59->SetBinContent(16,61.08587);
   norm_d__59->SetBinContent(17,38.64802);
   norm_d__59->SetBinContent(18,19.81284);
   norm_d__59->SetBinContent(19,10.09308);
   norm_d__59->SetBinContent(20,5.738558);
   norm_d__59->SetBinContent(21,2.994958);
   norm_d__59->SetBinContent(22,1.472417);
   norm_d__59->SetBinContent(23,0.5843153);
   norm_d__59->SetBinContent(24,0.3768772);
   norm_d__59->SetBinContent(25,0.2093615);
   norm_d__59->SetBinContent(26,2.026637);
   norm_d__59->SetBinError(3,0.7854781);
   norm_d__59->SetBinError(4,3.314107);
   norm_d__59->SetBinError(5,4.746879);
   norm_d__59->SetBinError(6,5.997994);
   norm_d__59->SetBinError(7,7.827018);
   norm_d__59->SetBinError(8,9.757364);
   norm_d__59->SetBinError(9,11.11544);
   norm_d__59->SetBinError(10,11.55187);
   norm_d__59->SetBinError(11,11.55436);
   norm_d__59->SetBinError(12,11.26634);
   norm_d__59->SetBinError(13,9.894651);
   norm_d__59->SetBinError(14,7.934843);
   norm_d__59->SetBinError(15,6.510731);
   norm_d__59->SetBinError(16,4.864739);
   norm_d__59->SetBinError(17,3.706114);
   norm_d__59->SetBinError(18,2.500999);
   norm_d__59->SetBinError(19,1.770571);
   norm_d__59->SetBinError(20,1.216579);
   norm_d__59->SetBinError(21,0.7313962);
   norm_d__59->SetBinError(22,0.4648786);
   norm_d__59->SetBinError(23,0.20895);
   norm_d__59->SetBinError(24,0.1322189);
   norm_d__59->SetBinError(25,0.09268121);
   norm_d__59->SetBinError(26,0.4408997);
   norm_d__59->SetEntries(10151);
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
   entry=leg->AddEntry("frame_x_d2_417adc50","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.806229 #pm 0.005608","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.234973 #pm 0.004828","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.973000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_417adc50_copy__60 = new TH1D("frame_417adc50_copy__60","p_T Balance",25,0,2);
   frame_417adc50_copy__60->SetBinContent(1,323.6289);
   frame_417adc50_copy__60->SetMaximum(323.6289);
   frame_417adc50_copy__60->SetEntries(1);
   frame_417adc50_copy__60->SetDirectory(0);
   frame_417adc50_copy__60->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_417adc50_copy__60->SetLineColor(ci);
   frame_417adc50_copy__60->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_417adc50_copy__60->GetXaxis()->SetLabelFont(42);
   frame_417adc50_copy__60->GetXaxis()->SetTitleOffset(1);
   frame_417adc50_copy__60->GetXaxis()->SetTitleFont(42);
   frame_417adc50_copy__60->GetYaxis()->SetTitle("1/Events");
   frame_417adc50_copy__60->GetYaxis()->SetLabelFont(42);
   frame_417adc50_copy__60->GetYaxis()->SetTitleFont(42);
   frame_417adc50_copy__60->GetZaxis()->SetLabelFont(42);
   frame_417adc50_copy__60->GetZaxis()->SetTitleOffset(1);
   frame_417adc50_copy__60->GetZaxis()->SetTitleFont(42);
   frame_417adc50_copy__60->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-42.70621,2.25,384.3559);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_417c9db0__61 = new TH1D("frame_417c9db0__61","p_T Balance",25,0,2);
   frame_417c9db0__61->SetBinContent(1,375.8147);
   frame_417c9db0__61->SetMaximum(375.8147);
   frame_417c9db0__61->SetEntries(1);
   frame_417c9db0__61->SetDirectory(0);
   frame_417c9db0__61->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_417c9db0__61->SetLineColor(ci);
   frame_417c9db0__61->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_417c9db0__61->GetXaxis()->SetLabelFont(42);
   frame_417c9db0__61->GetXaxis()->SetTitleOffset(1);
   frame_417c9db0__61->GetXaxis()->SetTitleFont(42);
   frame_417c9db0__61->GetYaxis()->SetTitle("1/Events");
   frame_417c9db0__61->GetYaxis()->SetLabelFont(42);
   frame_417c9db0__61->GetYaxis()->SetTitleFont(42);
   frame_417c9db0__61->GetZaxis()->SetLabelFont(42);
   frame_417c9db0__61->GetZaxis()->SetTitleOffset(1);
   frame_417c9db0__61->GetZaxis()->SetTitleFont(42);
   frame_417c9db0__61->Draw("FUNC");
   
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
   5,
   36,
   70,
   97,
   141,
   203,
   283,
   339,
   300,
   309,
   209,
   161,
   148,
   67,
   52,
   27,
   18,
   7,
   2,
   3,
   0,
   2,
   2};
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
   2.159691,
   5.971996,
   8.346566,
   9.831854,
   11.38486,
   13.75658,
   16.33003,
   17.91874,
   16.82772,
   17.08551,
   13.96548,
   12.19843,
   11.6758,
   8.164873,
   7.187836,
   5.163771,
   4.202887,
   2.58147,
   1.291815,
   1.632705,
   0,
   1.291815,
   1.291815};
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
   3.382473,
   7.055545,
   9.406468,
   10.88273,
   12.38486,
   14.75658,
   17.33003,
   18.91874,
   17.82772,
   18.08551,
   14.96548,
   13.19843,
   12.6758,
   9.226102,
   8.257346,
   6.260244,
   5.321007,
   3.770281,
   2.63786,
   2.918186,
   1.147874,
   2.63786,
   2.63786};
   grae = new TGraphAsymmErrors(25,h_dh_data2_fx3016,h_dh_data2_fy3016,h_dh_data2_felx3016,h_dh_data2_fehx3016,h_dh_data2_fely3016,h_dh_data2_fehy3016);
   grae->SetName("h_dh_data2");
   grae->SetTitle("Histogram of dh_data2_plot__x_o2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_data23016 = new TH1F("Graph_h_dh_data23016","Histogram of dh_data2_plot__x_o2",100,0,2.2);
   Graph_h_dh_data23016->SetMinimum(0);
   Graph_h_dh_data23016->SetMaximum(393.7106);
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
   
   Double_t observation_fx16[57] = {
   0.1788673,
   0.204225,
   0.2295828,
   0.2549406,
   0.2802983,
   0.3056561,
   0.3310139,
   0.3563716,
   0.3817294,
   0.4070872,
   0.4324449,
   0.4578027,
   0.4831604,
   0.5085182,
   0.533876,
   0.5845915,
   0.6099493,
   0.635307,
   0.6606648,
   0.6860226,
   0.7113803,
   0.7240592,
   0.7367381,
   0.749417,
   0.7620958,
   0.7747747,
   0.7874536,
   0.8001325,
   0.8128114,
   0.8254903,
   0.8381691,
   0.850848,
   0.8635269,
   0.8762058,
   0.8888847,
   0.9015635,
   0.9142424,
   0.9396002,
   0.964958,
   0.9903157,
   1.015673,
   1.041031,
   1.091747,
   1.117105,
   1.142462,
   1.16782,
   1.193178,
   1.218536,
   1.243893,
   1.269251,
   1.294609,
   1.319967,
   1.345324,
   1.370682,
   1.39604,
   1.446755,
   1.446755};
   Double_t observation_fy16[57] = {
   11.87014,
   15.32539,
   19.58255,
   24.76446,
   30.99494,
   38.39324,
   47.06748,
   57.10697,
   68.574,
   81.49519,
   95.8532,
   111.5792,
   128.5471,
   146.5693,
   165.3965,
   204.1732,
   223.3512,
   241.8131,
   259.1036,
   274.77,
   288.3814,
   294.2927,
   299.5486,
   304.1099,
   307.9424,
   311.0168,
   313.3097,
   314.8033,
   315.4861,
   315.3528,
   314.4045,
   312.6485,
   310.0983,
   306.7736,
   302.6998,
   297.9078,
   292.4335,
   279.6045,
   264.5838,
   247.7904,
   229.6719,
   210.6849,
   171.8663,
   152.835,
   134.5107,
   117.1636,
   101.0023,
   86.17304,
   72.76356,
   61.10483,
   51.6601,
   43.97168,
   37.66182,
   32.44427,
   28.09976,
   21.38877,
   21.38877};
   graph = new TGraph(57,observation_fx16,observation_fy16);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation16 = new TH1F("Graph_observation16","Projection of obsf DSCB fit",100,0.05207847,1.573544);
   Graph_observation16->SetMinimum(10.68313);
   Graph_observation16->SetMaximum(345.8477);
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
   
   TH1D *frame_417c9db0__62 = new TH1D("frame_417c9db0__62","p_T Balance",25,0,2);
   frame_417c9db0__62->SetBinContent(1,375.8147);
   frame_417c9db0__62->SetMaximum(375.8147);
   frame_417c9db0__62->SetEntries(1);
   frame_417c9db0__62->SetDirectory(0);
   frame_417c9db0__62->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_417c9db0__62->SetLineColor(ci);
   frame_417c9db0__62->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_417c9db0__62->GetXaxis()->SetLabelFont(42);
   frame_417c9db0__62->GetXaxis()->SetTitleOffset(1);
   frame_417c9db0__62->GetXaxis()->SetTitleFont(42);
   frame_417c9db0__62->GetYaxis()->SetTitle("1/Events");
   frame_417c9db0__62->GetYaxis()->SetLabelFont(42);
   frame_417c9db0__62->GetYaxis()->SetTitleFont(42);
   frame_417c9db0__62->GetZaxis()->SetLabelFont(42);
   frame_417c9db0__62->GetZaxis()->SetTitleOffset(1);
   frame_417c9db0__62->GetZaxis()->SetTitleFont(42);
   frame_417c9db0__62->Draw("AXISSAME");
   
   TH1D *norm_o__63 = new TH1D("norm_o__63","",25,0,2);
   norm_o__63->SetBinContent(3,5);
   norm_o__63->SetBinContent(4,36);
   norm_o__63->SetBinContent(5,70);
   norm_o__63->SetBinContent(6,97);
   norm_o__63->SetBinContent(7,141);
   norm_o__63->SetBinContent(8,203);
   norm_o__63->SetBinContent(9,283);
   norm_o__63->SetBinContent(10,339);
   norm_o__63->SetBinContent(11,300);
   norm_o__63->SetBinContent(12,309);
   norm_o__63->SetBinContent(13,209);
   norm_o__63->SetBinContent(14,161);
   norm_o__63->SetBinContent(15,148);
   norm_o__63->SetBinContent(16,67);
   norm_o__63->SetBinContent(17,52);
   norm_o__63->SetBinContent(18,27);
   norm_o__63->SetBinContent(19,18);
   norm_o__63->SetBinContent(20,7);
   norm_o__63->SetBinContent(21,2);
   norm_o__63->SetBinContent(22,3);
   norm_o__63->SetBinContent(24,2);
   norm_o__63->SetBinContent(25,2);
   norm_o__63->SetBinContent(26,1);
   norm_o__63->SetMinimum(0);
   norm_o__63->SetMaximum(745.8);
   norm_o__63->SetEntries(2482);
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
   entry=leg->AddEntry("frame_x_o2_417c9db0","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.819778 #pm 0.005339","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.252422 #pm 0.004378","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.964000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_417c9db0_copy__64 = new TH1D("frame_417c9db0_copy__64","p_T Balance",25,0,2);
   frame_417c9db0_copy__64->SetBinContent(1,375.8147);
   frame_417c9db0_copy__64->SetMaximum(375.8147);
   frame_417c9db0_copy__64->SetEntries(1);
   frame_417c9db0_copy__64->SetDirectory(0);
   frame_417c9db0_copy__64->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_417c9db0_copy__64->SetLineColor(ci);
   frame_417c9db0_copy__64->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_417c9db0_copy__64->GetXaxis()->SetLabelFont(42);
   frame_417c9db0_copy__64->GetXaxis()->SetTitleOffset(1);
   frame_417c9db0_copy__64->GetXaxis()->SetTitleFont(42);
   frame_417c9db0_copy__64->GetYaxis()->SetTitle("1/Events");
   frame_417c9db0_copy__64->GetYaxis()->SetLabelFont(42);
   frame_417c9db0_copy__64->GetYaxis()->SetTitleFont(42);
   frame_417c9db0_copy__64->GetZaxis()->SetLabelFont(42);
   frame_417c9db0_copy__64->GetZaxis()->SetTitleOffset(1);
   frame_417c9db0_copy__64->GetZaxis()->SetTitleFont(42);
   frame_417c9db0_copy__64->Draw("sameaxis");
   
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
