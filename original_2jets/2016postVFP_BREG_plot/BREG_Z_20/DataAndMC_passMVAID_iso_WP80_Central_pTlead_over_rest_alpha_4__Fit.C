void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_4__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 17:54:30 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-10.12788,2.25,116.4707);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_41733df0__49 = new TH1D("frame_41733df0__49","p_T Balance",25,0,2);
   frame_41733df0__49->SetBinContent(1,103.8108);
   frame_41733df0__49->SetMaximum(103.8108);
   frame_41733df0__49->SetEntries(1);
   frame_41733df0__49->SetDirectory(0);
   frame_41733df0__49->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_41733df0__49->SetLineColor(ci);
   frame_41733df0__49->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_41733df0__49->GetXaxis()->SetLabelFont(42);
   frame_41733df0__49->GetXaxis()->SetTitleOffset(1);
   frame_41733df0__49->GetXaxis()->SetTitleFont(42);
   frame_41733df0__49->GetYaxis()->SetTitle("1/Events");
   frame_41733df0__49->GetYaxis()->SetLabelFont(42);
   frame_41733df0__49->GetYaxis()->SetTitleFont(42);
   frame_41733df0__49->GetZaxis()->SetLabelFont(42);
   frame_41733df0__49->GetZaxis()->SetTitleOffset(1);
   frame_41733df0__49->GetZaxis()->SetTitleFont(42);
   frame_41733df0__49->Draw("FUNC");
   
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
   0.8568739,
   7.490338,
   14.13469,
   23.34636,
   34.7413,
   57.52729,
   67.72916,
   80.46019,
   83.66324,
   92.10088,
   65.17677,
   41.53904,
   31.24442,
   17.37565,
   11.68574,
   6.969176,
   1.170749,
   0.6096176,
   0.7306948,
   0.7367591,
   0.3779249,
   0.4590342,
   0};
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
   0.4306249,
   1.472905,
   2.391515,
   3.050602,
   3.736725,
   5.279413,
   5.537914,
   6.068572,
   6.218472,
   6.766563,
   5.591463,
   4.468968,
   3.452226,
   2.273879,
   2.361901,
   1.904076,
   0.5038252,
   0.3661863,
   0.5695371,
   0.3607062,
   0.2018343,
   0.3088561,
   0};
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
   0.4306249,
   1.472905,
   2.391515,
   3.050602,
   3.736725,
   5.279413,
   5.537914,
   6.068572,
   6.218472,
   6.766563,
   5.591463,
   4.468968,
   3.452226,
   2.273879,
   2.361901,
   1.904076,
   0.5038252,
   0.3661863,
   0.5695371,
   0.3607062,
   0.2018343,
   0.3088561,
   0};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3013,h_dh_central2_fy3013,h_dh_central2_felx3013,h_dh_central2_fehx3013,h_dh_central2_fely3013,h_dh_central2_fehy3013);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23013 = new TH1F("Graph_h_dh_central23013","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23013->SetMinimum(0);
   Graph_h_dh_central23013->SetMaximum(108.7542);
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
   0.2563746,
   0.3029696,
   0.3262671,
   0.3495646,
   0.372862,
   0.3961595,
   0.419457,
   0.4427545,
   0.466052,
   0.4777008,
   0.4893495,
   0.512647,
   0.5359445,
   0.559242,
   0.5825395,
   0.6291345,
   0.652432,
   0.6757295,
   0.699027,
   0.7223245,
   0.7339733,
   0.745622,
   0.7572708,
   0.7689195,
   0.7805683,
   0.792217,
   0.8038658,
   0.8155145,
   0.8271633,
   0.838812,
   0.8504608,
   0.8621095,
   0.8737583,
   0.885407,
   0.8970558,
   0.9087045,
   0.9203533,
   0.932002,
   0.9552995,
   0.978597,
   1.001895,
   1.04849,
   1.095085,
   1.118382,
   1.14168,
   1.164977,
   1.188275,
   1.211572,
   1.23487,
   1.258167,
   1.269816,
   1.281465,
   1.293113,
   1.304762,
   1.32806,
   1.374655,
   1.42125,
   1.42125};
   Double_t Central_fy13[58] = {
   8.714378,
   10.81037,
   12.09598,
   13.57932,
   15.29815,
   17.29891,
   19.63913,
   22.39053,
   25.64319,
   27.49201,
   29.51114,
   34.07415,
   39.01291,
   44.20295,
   49.56258,
   60.38628,
   65.61755,
   70.56045,
   75.0866,
   79.07208,
   80.82597,
   82.40311,
   83.79174,
   84.98137,
   85.96292,
   86.72884,
   87.27318,
   87.59171,
   87.68194,
   87.54316,
   87.17645,
   86.58468,
   85.77246,
   84.74607,
   83.51341,
   82.08387,
   80.4682,
   78.67844,
   74.62998,
   70.05362,
   65.07401,
   54.41774,
   43.64276,
   38.47579,
   33.56778,
   28.98127,
   24.76121,
   20.93563,
   17.517,
   14.50418,
   13.14642,
   11.9808,
   11.51462,
   11.26583,
   10.96832,
   10.64216,
   10.44511,
   10.44511};
   TGraph *graph = new TGraph(58,Central_fx13,Central_fy13);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central13 = new TH1F("Graph_Central13","Projection of centralf DSCB fit",100,0.1398871,1.537737);
   Graph_Central13->SetMinimum(0.8176217);
   Graph_Central13->SetMaximum(95.5787);
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
   
   TH1D *frame_41733df0__50 = new TH1D("frame_41733df0__50","p_T Balance",25,0,2);
   frame_41733df0__50->SetBinContent(1,103.8108);
   frame_41733df0__50->SetMaximum(103.8108);
   frame_41733df0__50->SetEntries(1);
   frame_41733df0__50->SetDirectory(0);
   frame_41733df0__50->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_41733df0__50->SetLineColor(ci);
   frame_41733df0__50->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_41733df0__50->GetXaxis()->SetLabelFont(42);
   frame_41733df0__50->GetXaxis()->SetTitleOffset(1);
   frame_41733df0__50->GetXaxis()->SetTitleFont(42);
   frame_41733df0__50->GetYaxis()->SetTitle("1/Events");
   frame_41733df0__50->GetYaxis()->SetLabelFont(42);
   frame_41733df0__50->GetYaxis()->SetTitleFont(42);
   frame_41733df0__50->GetZaxis()->SetLabelFont(42);
   frame_41733df0__50->GetZaxis()->SetTitleOffset(1);
   frame_41733df0__50->GetZaxis()->SetTitleFont(42);
   frame_41733df0__50->Draw("AXISSAME");
   
   TH1D *norm_c__51 = new TH1D("norm_c__51","",25,0,2);
   norm_c__51->SetBinContent(3,0.8568738);
   norm_c__51->SetBinContent(4,7.490338);
   norm_c__51->SetBinContent(5,14.13469);
   norm_c__51->SetBinContent(6,23.34636);
   norm_c__51->SetBinContent(7,34.7413);
   norm_c__51->SetBinContent(8,57.52729);
   norm_c__51->SetBinContent(9,67.72916);
   norm_c__51->SetBinContent(10,80.46019);
   norm_c__51->SetBinContent(11,83.66324);
   norm_c__51->SetBinContent(12,92.10088);
   norm_c__51->SetBinContent(13,65.17677);
   norm_c__51->SetBinContent(14,41.53904);
   norm_c__51->SetBinContent(15,31.24442);
   norm_c__51->SetBinContent(16,17.37565);
   norm_c__51->SetBinContent(17,11.68574);
   norm_c__51->SetBinContent(18,6.969176);
   norm_c__51->SetBinContent(19,1.170749);
   norm_c__51->SetBinContent(20,0.6096176);
   norm_c__51->SetBinContent(21,0.7306948);
   norm_c__51->SetBinContent(22,0.7367591);
   norm_c__51->SetBinContent(23,0.3779249);
   norm_c__51->SetBinContent(24,0.4590342);
   norm_c__51->SetBinContent(26,0.4515359);
   norm_c__51->SetBinError(3,0.4306249);
   norm_c__51->SetBinError(4,1.472905);
   norm_c__51->SetBinError(5,2.391515);
   norm_c__51->SetBinError(6,3.050602);
   norm_c__51->SetBinError(7,3.736725);
   norm_c__51->SetBinError(8,5.279413);
   norm_c__51->SetBinError(9,5.537914);
   norm_c__51->SetBinError(10,6.068572);
   norm_c__51->SetBinError(11,6.218472);
   norm_c__51->SetBinError(12,6.766563);
   norm_c__51->SetBinError(13,5.591463);
   norm_c__51->SetBinError(14,4.468968);
   norm_c__51->SetBinError(15,3.452226);
   norm_c__51->SetBinError(16,2.273879);
   norm_c__51->SetBinError(17,2.361901);
   norm_c__51->SetBinError(18,1.904076);
   norm_c__51->SetBinError(19,0.5038252);
   norm_c__51->SetBinError(20,0.3661863);
   norm_c__51->SetBinError(21,0.5695371);
   norm_c__51->SetBinError(22,0.3607062);
   norm_c__51->SetBinError(23,0.2018343);
   norm_c__51->SetBinError(24,0.3088561);
   norm_c__51->SetBinError(26,0.2411717);
   norm_c__51->SetEntries(3046);
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
   entry=leg->AddEntry("frame_x_c2_41733df0","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.825914 #pm 0.010620","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.227870 #pm 0.010000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.999000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_41733df0_copy__52 = new TH1D("frame_41733df0_copy__52","p_T Balance",25,0,2);
   frame_41733df0_copy__52->SetBinContent(1,103.8108);
   frame_41733df0_copy__52->SetMaximum(103.8108);
   frame_41733df0_copy__52->SetEntries(1);
   frame_41733df0_copy__52->SetDirectory(0);
   frame_41733df0_copy__52->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_41733df0_copy__52->SetLineColor(ci);
   frame_41733df0_copy__52->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_41733df0_copy__52->GetXaxis()->SetLabelFont(42);
   frame_41733df0_copy__52->GetXaxis()->SetTitleOffset(1);
   frame_41733df0_copy__52->GetXaxis()->SetTitleFont(42);
   frame_41733df0_copy__52->GetYaxis()->SetTitle("1/Events");
   frame_41733df0_copy__52->GetYaxis()->SetLabelFont(42);
   frame_41733df0_copy__52->GetYaxis()->SetTitleFont(42);
   frame_41733df0_copy__52->GetZaxis()->SetLabelFont(42);
   frame_41733df0_copy__52->GetZaxis()->SetTitleOffset(1);
   frame_41733df0_copy__52->GetZaxis()->SetTitleFont(42);
   frame_41733df0_copy__52->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-10.65329,2.25,122.5128);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_417407e0__53 = new TH1D("frame_417407e0__53","p_T Balance",25,0,2);
   frame_417407e0__53->SetBinContent(1,109.1962);
   frame_417407e0__53->SetMaximum(109.1962);
   frame_417407e0__53->SetEntries(1);
   frame_417407e0__53->SetDirectory(0);
   frame_417407e0__53->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_417407e0__53->SetLineColor(ci);
   frame_417407e0__53->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_417407e0__53->GetXaxis()->SetLabelFont(42);
   frame_417407e0__53->GetXaxis()->SetTitleOffset(1);
   frame_417407e0__53->GetXaxis()->SetTitleFont(42);
   frame_417407e0__53->GetYaxis()->SetTitle("1/Events");
   frame_417407e0__53->GetYaxis()->SetLabelFont(42);
   frame_417407e0__53->GetYaxis()->SetTitleFont(42);
   frame_417407e0__53->GetZaxis()->SetLabelFont(42);
   frame_417407e0__53->GetZaxis()->SetTitleOffset(1);
   frame_417407e0__53->GetZaxis()->SetTitleFont(42);
   frame_417407e0__53->Draw("FUNC");
   
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
   1.038782,
   5.044939,
   11.52326,
   21.26088,
   35.82425,
   52.86074,
   65.82462,
   84.04449,
   86.73408,
   97.20887,
   69.9324,
   48.92212,
   30.76585,
   19.99265,
   15.07162,
   6.584222,
   3.265882,
   0.5943548,
   0.4301119,
   1.286978,
   0.3777467,
   0.5686511,
   0};
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
   0.512052,
   1.063499,
   2.049936,
   2.94768,
   4.071326,
   4.784921,
   5.516101,
   6.293687,
   6.336889,
   6.787515,
   5.681172,
   4.701098,
   3.598953,
   2.675743,
   2.647717,
   1.759696,
   0.9868086,
   0.3570294,
   0.1959749,
   0.6597384,
   0.2019813,
   0.3383772,
   0};
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
   0.512052,
   1.063499,
   2.049936,
   2.94768,
   4.071326,
   4.784921,
   5.516101,
   6.293687,
   6.336889,
   6.787515,
   5.681172,
   4.701098,
   3.598953,
   2.675743,
   2.647717,
   1.759696,
   0.9868086,
   0.3570294,
   0.1959749,
   0.6597384,
   0.2019813,
   0.3383772,
   0};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3014,h_dh_up2_fy3014,h_dh_up2_felx3014,h_dh_up2_fehx3014,h_dh_up2_fely3014,h_dh_up2_fehy3014);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23014 = new TH1F("Graph_h_dh_up23014","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23014->SetMinimum(0);
   Graph_h_dh_up23014->SetMaximum(114.396);
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
   
   Double_t up_fx14[59] = {
   0.2691388,
   0.3158963,
   0.3275857,
   0.3392751,
   0.3626539,
   0.3860327,
   0.4094115,
   0.4327903,
   0.456169,
   0.4795478,
   0.5029266,
   0.5263054,
   0.5496842,
   0.5964417,
   0.6431993,
   0.6665781,
   0.6899569,
   0.7133356,
   0.7367144,
   0.7484038,
   0.7600932,
   0.7717826,
   0.783472,
   0.7951614,
   0.8068508,
   0.8185402,
   0.8302296,
   0.841919,
   0.8536083,
   0.8652977,
   0.8769871,
   0.8886765,
   0.9003659,
   0.9120553,
   0.9237447,
   0.9354341,
   0.9471235,
   0.9705023,
   0.993881,
   1.01726,
   1.040639,
   1.064017,
   1.110775,
   1.134154,
   1.157533,
   1.180911,
   1.20429,
   1.227669,
   1.251048,
   1.274426,
   1.297805,
   1.321184,
   1.344563,
   1.356252,
   1.362097,
   1.367942,
   1.39132,
   1.438078,
   1.438078};
   Double_t up_fy14[59] = {
   7.553079,
   8.039468,
   8.439057,
   9.366693,
   11.50047,
   13.98251,
   16.83427,
   20.06981,
   23.69366,
   27.69879,
   32.06486,
   36.7568,
   41.72401,
   52.20379,
   62.80258,
   67.87736,
   72.6461,
   76.99092,
   80.7991,
   82.46933,
   83.96792,
   85.28434,
   86.40923,
   87.33452,
   88.05352,
   88.56099,
   88.85321,
   88.92806,
   88.78496,
   88.42499,
   87.85076,
   87.06649,
   86.07787,
   84.89203,
   83.51747,
   81.96391,
   80.24223,
   76.34288,
   71.92401,
   67.09947,
   61.98751,
   56.70601,
   46.07851,
   40.93011,
   36.00205,
   31.35822,
   27.04677,
   23.10038,
   19.53723,
   16.36238,
   13.56969,
   11.14379,
   9.062252,
   8.142169,
   7.774144,
   7.5826,
   7.232865,
   6.949784,
   6.949784};
   graph = new TGraph(59,up_fx14,up_fy14);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up14 = new TH1F("Graph_up14","Projection of upf DSCB fit",100,0.1522449,1.554972);
   Graph_up14->SetMinimum(6.254806);
   Graph_up14->SetMaximum(97.12588);
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
   
   TH1D *frame_417407e0__54 = new TH1D("frame_417407e0__54","p_T Balance",25,0,2);
   frame_417407e0__54->SetBinContent(1,109.1962);
   frame_417407e0__54->SetMaximum(109.1962);
   frame_417407e0__54->SetEntries(1);
   frame_417407e0__54->SetDirectory(0);
   frame_417407e0__54->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_417407e0__54->SetLineColor(ci);
   frame_417407e0__54->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_417407e0__54->GetXaxis()->SetLabelFont(42);
   frame_417407e0__54->GetXaxis()->SetTitleOffset(1);
   frame_417407e0__54->GetXaxis()->SetTitleFont(42);
   frame_417407e0__54->GetYaxis()->SetTitle("1/Events");
   frame_417407e0__54->GetYaxis()->SetLabelFont(42);
   frame_417407e0__54->GetYaxis()->SetTitleFont(42);
   frame_417407e0__54->GetZaxis()->SetLabelFont(42);
   frame_417407e0__54->GetZaxis()->SetTitleOffset(1);
   frame_417407e0__54->GetZaxis()->SetTitleFont(42);
   frame_417407e0__54->Draw("AXISSAME");
   
   TH1D *norm_u__55 = new TH1D("norm_u__55","",25,0,2);
   norm_u__55->SetBinContent(3,1.038782);
   norm_u__55->SetBinContent(4,5.044939);
   norm_u__55->SetBinContent(5,11.52326);
   norm_u__55->SetBinContent(6,21.26088);
   norm_u__55->SetBinContent(7,35.82425);
   norm_u__55->SetBinContent(8,52.86074);
   norm_u__55->SetBinContent(9,65.82463);
   norm_u__55->SetBinContent(10,84.04449);
   norm_u__55->SetBinContent(11,86.73407);
   norm_u__55->SetBinContent(12,97.20887);
   norm_u__55->SetBinContent(13,69.9324);
   norm_u__55->SetBinContent(14,48.92212);
   norm_u__55->SetBinContent(15,30.76585);
   norm_u__55->SetBinContent(16,19.99265);
   norm_u__55->SetBinContent(17,15.07162);
   norm_u__55->SetBinContent(18,6.584222);
   norm_u__55->SetBinContent(19,3.265882);
   norm_u__55->SetBinContent(20,0.5943548);
   norm_u__55->SetBinContent(21,0.4301119);
   norm_u__55->SetBinContent(22,1.286978);
   norm_u__55->SetBinContent(23,0.3777467);
   norm_u__55->SetBinContent(24,0.5686512);
   norm_u__55->SetBinContent(26,0.4503215);
   norm_u__55->SetBinError(3,0.512052);
   norm_u__55->SetBinError(4,1.063499);
   norm_u__55->SetBinError(5,2.049936);
   norm_u__55->SetBinError(6,2.94768);
   norm_u__55->SetBinError(7,4.071326);
   norm_u__55->SetBinError(8,4.784921);
   norm_u__55->SetBinError(9,5.516101);
   norm_u__55->SetBinError(10,6.293687);
   norm_u__55->SetBinError(11,6.336889);
   norm_u__55->SetBinError(12,6.787515);
   norm_u__55->SetBinError(13,5.681172);
   norm_u__55->SetBinError(14,4.701098);
   norm_u__55->SetBinError(15,3.598953);
   norm_u__55->SetBinError(16,2.675743);
   norm_u__55->SetBinError(17,2.647717);
   norm_u__55->SetBinError(18,1.759696);
   norm_u__55->SetBinError(19,0.9868086);
   norm_u__55->SetBinError(20,0.3570294);
   norm_u__55->SetBinError(21,0.1959749);
   norm_u__55->SetBinError(22,0.6597384);
   norm_u__55->SetBinError(23,0.2019813);
   norm_u__55->SetBinError(24,0.3383772);
   norm_u__55->SetBinError(26,0.2407948);
   norm_u__55->SetEntries(3076);
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
   entry=leg->AddEntry("frame_x_u2_417407e0","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.834448 #pm 0.009738","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.232504 #pm 0.008810","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.992000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_417407e0_copy__56 = new TH1D("frame_417407e0_copy__56","p_T Balance",25,0,2);
   frame_417407e0_copy__56->SetBinContent(1,109.1962);
   frame_417407e0_copy__56->SetMaximum(109.1962);
   frame_417407e0_copy__56->SetEntries(1);
   frame_417407e0_copy__56->SetDirectory(0);
   frame_417407e0_copy__56->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_417407e0_copy__56->SetLineColor(ci);
   frame_417407e0_copy__56->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_417407e0_copy__56->GetXaxis()->SetLabelFont(42);
   frame_417407e0_copy__56->GetXaxis()->SetTitleOffset(1);
   frame_417407e0_copy__56->GetXaxis()->SetTitleFont(42);
   frame_417407e0_copy__56->GetYaxis()->SetTitle("1/Events");
   frame_417407e0_copy__56->GetYaxis()->SetLabelFont(42);
   frame_417407e0_copy__56->GetYaxis()->SetTitleFont(42);
   frame_417407e0_copy__56->GetZaxis()->SetLabelFont(42);
   frame_417407e0_copy__56->GetZaxis()->SetTitleOffset(1);
   frame_417407e0_copy__56->GetZaxis()->SetTitleFont(42);
   frame_417407e0_copy__56->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-10.50176,2.25,94.51584);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_4171f2b0__57 = new TH1D("frame_4171f2b0__57","p_T Balance",25,0,2);
   frame_4171f2b0__57->SetBinContent(1,92.41549);
   frame_4171f2b0__57->SetMaximum(92.41549);
   frame_4171f2b0__57->SetEntries(1);
   frame_4171f2b0__57->SetDirectory(0);
   frame_4171f2b0__57->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4171f2b0__57->SetLineColor(ci);
   frame_4171f2b0__57->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4171f2b0__57->GetXaxis()->SetLabelFont(42);
   frame_4171f2b0__57->GetXaxis()->SetTitleOffset(1);
   frame_4171f2b0__57->GetXaxis()->SetTitleFont(42);
   frame_4171f2b0__57->GetYaxis()->SetTitle("1/Events");
   frame_4171f2b0__57->GetYaxis()->SetLabelFont(42);
   frame_4171f2b0__57->GetYaxis()->SetTitleFont(42);
   frame_4171f2b0__57->GetZaxis()->SetLabelFont(42);
   frame_4171f2b0__57->GetZaxis()->SetTitleOffset(1);
   frame_4171f2b0__57->GetZaxis()->SetTitleFont(42);
   frame_4171f2b0__57->Draw("FUNC");
   
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
   1.370819,
   6.87296,
   14.98669,
   24.03152,
   33.6124,
   63.47929,
   65.60073,
   72.1817,
   79.85806,
   81.69098,
   65.37182,
   42.66268,
   29.7989,
   14.38613,
   9.397062,
   4.999477,
   1.580726,
   0.3562089,
   1.09934,
   0.4143867,
   0.6204067,
   0.4698009,
   0};
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
   0.7100573,
   1.271625,
   2.542256,
   3.079057,
   3.645169,
   5.707967,
   5.280199,
   5.313945,
   5.79472,
   6.323773,
   5.579031,
   4.681114,
   3.298237,
   2.055218,
   2.077973,
   1.586716,
   0.7091755,
   0.2167175,
   0.6113462,
   0.2218192,
   0.3218957,
   0.3122225,
   0};
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
   0.7100573,
   1.271625,
   2.542256,
   3.079057,
   3.645169,
   5.707967,
   5.280199,
   5.313945,
   5.79472,
   6.323773,
   5.579031,
   4.681114,
   3.298237,
   2.055218,
   2.077973,
   1.586716,
   0.7091755,
   0.2167175,
   0.6113462,
   0.2218192,
   0.3218957,
   0.3122225,
   0};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3015,h_dh_down2_fy3015,h_dh_down2_felx3015,h_dh_down2_fehx3015,h_dh_down2_fely3015,h_dh_down2_fehy3015);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23015 = new TH1F("Graph_h_dh_down23015","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23015->SetMinimum(0);
   Graph_h_dh_down23015->SetMaximum(96.81623);
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
   
   Double_t down_fx15[56] = {
   0.2779318,
   0.3231185,
   0.3683053,
   0.3908987,
   0.396547,
   0.4021954,
   0.4134921,
   0.4360854,
   0.4586788,
   0.4812722,
   0.5038656,
   0.526459,
   0.5490524,
   0.5942391,
   0.6394259,
   0.6620193,
   0.6846127,
   0.707206,
   0.7297994,
   0.7410961,
   0.7523928,
   0.7636895,
   0.7749862,
   0.7862829,
   0.7975796,
   0.8088763,
   0.820173,
   0.8314697,
   0.8427663,
   0.854063,
   0.8653597,
   0.8766564,
   0.8879531,
   0.8992498,
   0.9105465,
   0.9331399,
   0.9557333,
   0.9783266,
   1.00092,
   1.046107,
   1.091294,
   1.113887,
   1.13648,
   1.159074,
   1.181667,
   1.20426,
   1.226854,
   1.249447,
   1.272041,
   1.283337,
   1.288986,
   1.294634,
   1.317227,
   1.362414,
   1.407601,
   1.407601};
   Double_t down_fy15[56] = {
   14.40841,
   14.7185,
   15.28627,
   15.93762,
   16.25505,
   16.79902,
   18.30804,
   21.59064,
   25.22128,
   29.1841,
   33.45054,
   37.97848,
   42.71199,
   52.50581,
   62.14063,
   66.64634,
   70.80349,
   74.50934,
   77.66841,
   79.01607,
   80.19658,
   81.20181,
   82.02476,
   82.65967,
   83.10205,
   83.34879,
   83.39812,
   83.24969,
   82.90456,
   82.36518,
   81.63535,
   80.72022,
   79.62617,
   78.36078,
   76.93272,
   73.62817,
   69.79987,
   65.54551,
   60.96898,
   51.27126,
   41.50972,
   36.82174,
   32.35463,
   28.16088,
   24.27916,
   20.73476,
   17.54049,
   14.69814,
   12.20002,
   11.07551,
   10.66063,
   10.4324,
   9.984484,
   9.605446,
   9.400646,
   9.400646};
   graph = new TGraph(56,down_fx15,down_fy15);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down15 = new TH1F("Graph_down15","Projection of downf DSCB fit",100,0.1649648,1.520568);
   Graph_down15->SetMinimum(2.000898);
   Graph_down15->SetMaximum(90.79786);
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
   
   TH1D *frame_4171f2b0__58 = new TH1D("frame_4171f2b0__58","p_T Balance",25,0,2);
   frame_4171f2b0__58->SetBinContent(1,92.41549);
   frame_4171f2b0__58->SetMaximum(92.41549);
   frame_4171f2b0__58->SetEntries(1);
   frame_4171f2b0__58->SetDirectory(0);
   frame_4171f2b0__58->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4171f2b0__58->SetLineColor(ci);
   frame_4171f2b0__58->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4171f2b0__58->GetXaxis()->SetLabelFont(42);
   frame_4171f2b0__58->GetXaxis()->SetTitleOffset(1);
   frame_4171f2b0__58->GetXaxis()->SetTitleFont(42);
   frame_4171f2b0__58->GetYaxis()->SetTitle("1/Events");
   frame_4171f2b0__58->GetYaxis()->SetLabelFont(42);
   frame_4171f2b0__58->GetYaxis()->SetTitleFont(42);
   frame_4171f2b0__58->GetZaxis()->SetLabelFont(42);
   frame_4171f2b0__58->GetZaxis()->SetTitleOffset(1);
   frame_4171f2b0__58->GetZaxis()->SetTitleFont(42);
   frame_4171f2b0__58->Draw("AXISSAME");
   
   TH1D *norm_d__59 = new TH1D("norm_d__59","",25,0,2);
   norm_d__59->SetBinContent(3,1.370819);
   norm_d__59->SetBinContent(4,6.87296);
   norm_d__59->SetBinContent(5,14.98669);
   norm_d__59->SetBinContent(6,24.03152);
   norm_d__59->SetBinContent(7,33.6124);
   norm_d__59->SetBinContent(8,63.47929);
   norm_d__59->SetBinContent(9,65.60073);
   norm_d__59->SetBinContent(10,72.1817);
   norm_d__59->SetBinContent(11,79.85806);
   norm_d__59->SetBinContent(12,81.69098);
   norm_d__59->SetBinContent(13,65.37182);
   norm_d__59->SetBinContent(14,42.66268);
   norm_d__59->SetBinContent(15,29.7989);
   norm_d__59->SetBinContent(16,14.38613);
   norm_d__59->SetBinContent(17,9.397063);
   norm_d__59->SetBinContent(18,4.999477);
   norm_d__59->SetBinContent(19,1.580726);
   norm_d__59->SetBinContent(20,0.3562089);
   norm_d__59->SetBinContent(21,1.09934);
   norm_d__59->SetBinContent(22,0.4143867);
   norm_d__59->SetBinContent(23,0.6204067);
   norm_d__59->SetBinContent(24,0.4698009);
   norm_d__59->SetBinContent(26,0.2550833);
   norm_d__59->SetBinError(3,0.7100573);
   norm_d__59->SetBinError(4,1.271625);
   norm_d__59->SetBinError(5,2.542256);
   norm_d__59->SetBinError(6,3.079057);
   norm_d__59->SetBinError(7,3.645169);
   norm_d__59->SetBinError(8,5.707967);
   norm_d__59->SetBinError(9,5.280199);
   norm_d__59->SetBinError(10,5.313945);
   norm_d__59->SetBinError(11,5.79472);
   norm_d__59->SetBinError(12,6.323773);
   norm_d__59->SetBinError(13,5.579031);
   norm_d__59->SetBinError(14,4.681114);
   norm_d__59->SetBinError(15,3.298237);
   norm_d__59->SetBinError(16,2.055218);
   norm_d__59->SetBinError(17,2.077973);
   norm_d__59->SetBinError(18,1.586716);
   norm_d__59->SetBinError(19,0.7091755);
   norm_d__59->SetBinError(20,0.2167175);
   norm_d__59->SetBinError(21,0.6113462);
   norm_d__59->SetBinError(22,0.2218192);
   norm_d__59->SetBinError(23,0.3218957);
   norm_d__59->SetBinError(24,0.3122225);
   norm_d__59->SetBinError(26,0.09889863);
   norm_d__59->SetEntries(3048);
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
   entry=leg->AddEntry("frame_x_d2_4171f2b0","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.810908 #pm 0.010570","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.242185 #pm 0.008970","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.982000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_4171f2b0_copy__60 = new TH1D("frame_4171f2b0_copy__60","p_T Balance",25,0,2);
   frame_4171f2b0_copy__60->SetBinContent(1,92.41549);
   frame_4171f2b0_copy__60->SetMaximum(92.41549);
   frame_4171f2b0_copy__60->SetEntries(1);
   frame_4171f2b0_copy__60->SetDirectory(0);
   frame_4171f2b0_copy__60->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4171f2b0_copy__60->SetLineColor(ci);
   frame_4171f2b0_copy__60->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4171f2b0_copy__60->GetXaxis()->SetLabelFont(42);
   frame_4171f2b0_copy__60->GetXaxis()->SetTitleOffset(1);
   frame_4171f2b0_copy__60->GetXaxis()->SetTitleFont(42);
   frame_4171f2b0_copy__60->GetYaxis()->SetTitle("1/Events");
   frame_4171f2b0_copy__60->GetYaxis()->SetLabelFont(42);
   frame_4171f2b0_copy__60->GetYaxis()->SetTitleFont(42);
   frame_4171f2b0_copy__60->GetZaxis()->SetLabelFont(42);
   frame_4171f2b0_copy__60->GetZaxis()->SetTitleOffset(1);
   frame_4171f2b0_copy__60->GetZaxis()->SetTitleFont(42);
   frame_4171f2b0_copy__60->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-12.3707,2.25,111.3363);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_41749f80__61 = new TH1D("frame_41749f80__61","p_T Balance",25,0,2);
   frame_41749f80__61->SetBinContent(1,108.8622);
   frame_41749f80__61->SetMaximum(108.8622);
   frame_41749f80__61->SetEntries(1);
   frame_41749f80__61->SetDirectory(0);
   frame_41749f80__61->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_41749f80__61->SetLineColor(ci);
   frame_41749f80__61->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_41749f80__61->GetXaxis()->SetLabelFont(42);
   frame_41749f80__61->GetXaxis()->SetTitleOffset(1);
   frame_41749f80__61->GetXaxis()->SetTitleFont(42);
   frame_41749f80__61->GetYaxis()->SetTitle("1/Events");
   frame_41749f80__61->GetYaxis()->SetLabelFont(42);
   frame_41749f80__61->GetYaxis()->SetTitleFont(42);
   frame_41749f80__61->GetZaxis()->SetLabelFont(42);
   frame_41749f80__61->GetZaxis()->SetTitleOffset(1);
   frame_41749f80__61->GetZaxis()->SetTitleFont(42);
   frame_41749f80__61->Draw("FUNC");
   
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
   0,
   19,
   12,
   32,
   39,
   55,
   78,
   93,
   81,
   78,
   49,
   45,
   38,
   21,
   11,
   6,
   2,
   1,
   1,
   1,
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
   0,
   4.320219,
   3.415266,
   5.627135,
   6.218102,
   7.39358,
   8.812788,
   9.626284,
   8.981384,
   8.812788,
   6.976026,
   6.683179,
   6.137163,
   4.545807,
   3.265579,
   2.379931,
   1.291815,
   0.8272462,
   0.8272462,
   0.8272462,
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
   1.147874,
   5.435196,
   4.559819,
   6.715753,
   7.298372,
   8.461166,
   9.869531,
   10.67824,
   10.03706,
   9.869531,
   8.047634,
   7.757905,
   7.218484,
   5.655182,
   4.416521,
   3.583642,
   2.63786,
   2.299527,
   2.299527,
   2.299527,
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
   Graph_h_dh_data23016->SetMaximum(114.0461);
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
   0.166751,
   0.1923489,
   0.2179468,
   0.2435447,
   0.2691426,
   0.2947405,
   0.3203384,
   0.3459363,
   0.3715341,
   0.397132,
   0.4227299,
   0.4483278,
   0.4739257,
   0.4995236,
   0.5251215,
   0.5763173,
   0.6019152,
   0.6275131,
   0.653111,
   0.6787089,
   0.7043067,
   0.7171057,
   0.7299046,
   0.7427036,
   0.7555025,
   0.7683015,
   0.7811004,
   0.7938994,
   0.8066983,
   0.8194973,
   0.8322962,
   0.8450952,
   0.8578941,
   0.8706931,
   0.883492,
   0.8962909,
   0.9090899,
   0.9346878,
   0.9602857,
   0.9858836,
   1.011481,
   1.037079,
   1.088275,
   1.113873,
   1.139471,
   1.165069,
   1.190667,
   1.216265,
   1.241862,
   1.26746,
   1.293058,
   1.318656,
   1.344254,
   1.369852,
   1.39545,
   1.421048,
   1.446646,
   1.446646};
   Double_t observation_fy16[58] = {
   3.490384,
   4.469472,
   5.670152,
   7.121148,
   8.853643,
   10.8971,
   13.2775,
   16.01543,
   19.12396,
   22.60652,
   26.45491,
   30.64754,
   35.14809,
   39.90475,
   44.85019,
   54.96596,
   59.93545,
   64.69794,
   69.13754,
   73.13987,
   76.59689,
   78.09009,
   79.41177,
   80.55232,
   81.50334,
   82.25777,
   82.80998,
   83.15581,
   83.29265,
   83.21948,
   82.93684,
   82.44687,
   81.75325,
   80.86118,
   79.7773,
   78.5096,
   77.06735,
   73.70182,
   69.77548,
   65.39495,
   60.67396,
   55.72848,
   45.6118,
   40.64456,
   35.85455,
   31.31144,
   27.06939,
   23.16705,
   19.62816,
   16.46286,
   13.66935,
   11.23588,
   9.142883,
   7.365054,
   5.873344,
   4.63673,
   3.623722,
   3.623722};
   graph = new TGraph(58,observation_fx16,observation_fy16);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation16 = new TH1F("Graph_observation16","Projection of obsf DSCB fit",100,0.03876154,1.574635);
   Graph_observation16->SetMinimum(3.141346);
   Graph_observation16->SetMaximum(91.27288);
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
   
   TH1D *frame_41749f80__62 = new TH1D("frame_41749f80__62","p_T Balance",25,0,2);
   frame_41749f80__62->SetBinContent(1,108.8622);
   frame_41749f80__62->SetMaximum(108.8622);
   frame_41749f80__62->SetEntries(1);
   frame_41749f80__62->SetDirectory(0);
   frame_41749f80__62->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_41749f80__62->SetLineColor(ci);
   frame_41749f80__62->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_41749f80__62->GetXaxis()->SetLabelFont(42);
   frame_41749f80__62->GetXaxis()->SetTitleOffset(1);
   frame_41749f80__62->GetXaxis()->SetTitleFont(42);
   frame_41749f80__62->GetYaxis()->SetTitle("1/Events");
   frame_41749f80__62->GetYaxis()->SetLabelFont(42);
   frame_41749f80__62->GetYaxis()->SetTitleFont(42);
   frame_41749f80__62->GetZaxis()->SetLabelFont(42);
   frame_41749f80__62->GetZaxis()->SetTitleOffset(1);
   frame_41749f80__62->GetZaxis()->SetTitleFont(42);
   frame_41749f80__62->Draw("AXISSAME");
   
   TH1D *norm_o__63 = new TH1D("norm_o__63","",25,0,2);
   norm_o__63->SetBinContent(4,19);
   norm_o__63->SetBinContent(5,12);
   norm_o__63->SetBinContent(6,32);
   norm_o__63->SetBinContent(7,39);
   norm_o__63->SetBinContent(8,55);
   norm_o__63->SetBinContent(9,78);
   norm_o__63->SetBinContent(10,93);
   norm_o__63->SetBinContent(11,81);
   norm_o__63->SetBinContent(12,78);
   norm_o__63->SetBinContent(13,49);
   norm_o__63->SetBinContent(14,45);
   norm_o__63->SetBinContent(15,38);
   norm_o__63->SetBinContent(16,21);
   norm_o__63->SetBinContent(17,11);
   norm_o__63->SetBinContent(18,6);
   norm_o__63->SetBinContent(19,2);
   norm_o__63->SetBinContent(20,1);
   norm_o__63->SetBinContent(21,1);
   norm_o__63->SetBinContent(22,1);
   norm_o__63->SetMinimum(0);
   norm_o__63->SetMaximum(204.6);
   norm_o__63->SetEntries(662);
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
   entry=leg->AddEntry("frame_x_o2_41749f80","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.808643 #pm 0.010399","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.254808 #pm 0.008555","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.999000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_41749f80_copy__64 = new TH1D("frame_41749f80_copy__64","p_T Balance",25,0,2);
   frame_41749f80_copy__64->SetBinContent(1,108.8622);
   frame_41749f80_copy__64->SetMaximum(108.8622);
   frame_41749f80_copy__64->SetEntries(1);
   frame_41749f80_copy__64->SetDirectory(0);
   frame_41749f80_copy__64->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_41749f80_copy__64->SetLineColor(ci);
   frame_41749f80_copy__64->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_41749f80_copy__64->GetXaxis()->SetLabelFont(42);
   frame_41749f80_copy__64->GetXaxis()->SetTitleOffset(1);
   frame_41749f80_copy__64->GetXaxis()->SetTitleFont(42);
   frame_41749f80_copy__64->GetYaxis()->SetTitle("1/Events");
   frame_41749f80_copy__64->GetYaxis()->SetLabelFont(42);
   frame_41749f80_copy__64->GetYaxis()->SetTitleFont(42);
   frame_41749f80_copy__64->GetZaxis()->SetLabelFont(42);
   frame_41749f80_copy__64->GetZaxis()->SetTitleOffset(1);
   frame_41749f80_copy__64->GetZaxis()->SetTitleFont(42);
   frame_41749f80_copy__64->Draw("sameaxis");
   
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
