void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_4__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 17:29:46 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-14.01513,2.25,105.4937);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_420e5b30__49 = new TH1D("frame_420e5b30__49","p_T Balance",25,0,2);
   frame_420e5b30__49->SetBinContent(1,93.54286);
   frame_420e5b30__49->SetMinimum(-4.454422);
   frame_420e5b30__49->SetMaximum(93.54286);
   frame_420e5b30__49->SetEntries(1);
   frame_420e5b30__49->SetDirectory(0);
   frame_420e5b30__49->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_420e5b30__49->SetLineColor(ci);
   frame_420e5b30__49->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_420e5b30__49->GetXaxis()->SetLabelFont(42);
   frame_420e5b30__49->GetXaxis()->SetTitleOffset(1);
   frame_420e5b30__49->GetXaxis()->SetTitleFont(42);
   frame_420e5b30__49->GetYaxis()->SetTitle("1/Events");
   frame_420e5b30__49->GetYaxis()->SetLabelFont(42);
   frame_420e5b30__49->GetYaxis()->SetTitleFont(42);
   frame_420e5b30__49->GetZaxis()->SetLabelFont(42);
   frame_420e5b30__49->GetZaxis()->SetTitleOffset(1);
   frame_420e5b30__49->GetZaxis()->SetTitleFont(42);
   frame_420e5b30__49->Draw("FUNC");
   
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
   1.787619,
   10.58155,
   16.72032,
   29.09785,
   47.86734,
   57.30186,
   67.22771,
   77.51412,
   79.61688,
   82.65016,
   60.95337,
   39.13998,
   28.41368,
   20.21252,
   10.47934,
   5.528334,
   3.056579,
   0.530799,
   0.4929789,
   0.699951,
   0.414733,
   0.42507,
   0.03396421};
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
   0.6489312,
   1.888714,
   2.648714,
   3.428756,
   4.856171,
   5.155728,
   5.732044,
   5.75703,
   5.984831,
   6.438275,
   5.384453,
   4.326407,
   3.108125,
   2.680924,
   2.28649,
   1.453031,
   1.231718,
   0.327324,
   0.340835,
   0.3588232,
   0.2051632,
   0.3069829,
   0.03396421};
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
   0.6489312,
   1.888714,
   2.648714,
   3.428756,
   4.856171,
   5.155728,
   5.732044,
   5.75703,
   5.984831,
   6.438275,
   5.384453,
   4.326407,
   3.108125,
   2.680924,
   2.28649,
   1.453031,
   1.231718,
   0.327324,
   0.340835,
   0.3588232,
   0.2051632,
   0.3069829,
   0.03396421};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3013,h_dh_central2_fy3013,h_dh_central2_felx3013,h_dh_central2_fehx3013,h_dh_central2_fely3013,h_dh_central2_fehy3013);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23013 = new TH1F("Graph_h_dh_central23013","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23013->SetMinimum(-8.908844);
   Graph_h_dh_central23013->SetMaximum(97.99728);
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
   0.1985387,
   0.2232734,
   0.2356408,
   0.2480082,
   0.272743,
   0.2974778,
   0.3222126,
   0.3469473,
   0.3716821,
   0.3964169,
   0.4211517,
   0.4458864,
   0.4706212,
   0.495356,
   0.5448255,
   0.5942951,
   0.6190299,
   0.6437646,
   0.6684994,
   0.6932342,
   0.717969,
   0.7303364,
   0.7427038,
   0.7550711,
   0.7674385,
   0.7798059,
   0.7921733,
   0.8045407,
   0.8169081,
   0.8292755,
   0.8416429,
   0.8540102,
   0.8663776,
   0.878745,
   0.8911124,
   0.9158472,
   0.940582,
   0.9653167,
   0.9900515,
   1.014786,
   1.039521,
   1.088991,
   1.113725,
   1.13846,
   1.163195,
   1.18793,
   1.212665,
   1.237399,
   1.262134,
   1.286869,
   1.311604,
   1.336338,
   1.361073,
   1.385808,
   1.410543,
   1.435277,
   1.435277};
   Double_t Central_fy13[57] = {
   5.686884,
   6.013867,
   6.586404,
   7.336564,
   9.038453,
   11.03009,
   13.3336,
   15.96613,
   18.93806,
   22.25126,
   25.89748,
   29.85685,
   34.09684,
   38.57161,
   47.9762,
   57.45373,
   61.98545,
   66.24376,
   70.12675,
   73.53702,
   76.38568,
   77.57491,
   78.59619,
   79.44244,
   80.10776,
   80.58746,
   80.87816,
   80.9778,
   80.88566,
   80.60241,
   80.13005,
   79.47192,
   78.63264,
   77.61808,
   76.43528,
   73.59842,
   70.19832,
   66.32366,
   62.07174,
   57.54437,
   52.84397,
   43.3143,
   38.66114,
   34.18232,
   29.93726,
   25.97204,
   22.31946,
   18.99962,
   16.02101,
   13.38192,
   11.07211,
   9.074567,
   7.367245,
   5.92472,
   4.719698,
   3.724296,
   3.724296};
   TGraph *graph = new TGraph(57,Central_fx13,Central_fy13);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central13 = new TH1F("Graph_Central13","Projection of centralf DSCB fit",100,0.07486479,1.558951);
   Graph_Central13->SetMinimum(3.351866);
   Graph_Central13->SetMaximum(88.70315);
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
   
   TH1D *frame_420e5b30__50 = new TH1D("frame_420e5b30__50","p_T Balance",25,0,2);
   frame_420e5b30__50->SetBinContent(1,93.54286);
   frame_420e5b30__50->SetMinimum(-4.454422);
   frame_420e5b30__50->SetMaximum(93.54286);
   frame_420e5b30__50->SetEntries(1);
   frame_420e5b30__50->SetDirectory(0);
   frame_420e5b30__50->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_420e5b30__50->SetLineColor(ci);
   frame_420e5b30__50->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_420e5b30__50->GetXaxis()->SetLabelFont(42);
   frame_420e5b30__50->GetXaxis()->SetTitleOffset(1);
   frame_420e5b30__50->GetXaxis()->SetTitleFont(42);
   frame_420e5b30__50->GetYaxis()->SetTitle("1/Events");
   frame_420e5b30__50->GetYaxis()->SetLabelFont(42);
   frame_420e5b30__50->GetYaxis()->SetTitleFont(42);
   frame_420e5b30__50->GetZaxis()->SetLabelFont(42);
   frame_420e5b30__50->GetZaxis()->SetTitleOffset(1);
   frame_420e5b30__50->GetZaxis()->SetTitleFont(42);
   frame_420e5b30__50->Draw("AXISSAME");
   
   TH1D *norm_c__51 = new TH1D("norm_c__51","",25,0,2);
   norm_c__51->SetBinContent(3,1.787619);
   norm_c__51->SetBinContent(4,10.58155);
   norm_c__51->SetBinContent(5,16.72031);
   norm_c__51->SetBinContent(6,29.09785);
   norm_c__51->SetBinContent(7,47.86734);
   norm_c__51->SetBinContent(8,57.30186);
   norm_c__51->SetBinContent(9,67.22772);
   norm_c__51->SetBinContent(10,77.51412);
   norm_c__51->SetBinContent(11,79.61688);
   norm_c__51->SetBinContent(12,82.65016);
   norm_c__51->SetBinContent(13,60.95337);
   norm_c__51->SetBinContent(14,39.13999);
   norm_c__51->SetBinContent(15,28.41368);
   norm_c__51->SetBinContent(16,20.21252);
   norm_c__51->SetBinContent(17,10.47934);
   norm_c__51->SetBinContent(18,5.528333);
   norm_c__51->SetBinContent(19,3.056579);
   norm_c__51->SetBinContent(20,0.530799);
   norm_c__51->SetBinContent(21,0.4929789);
   norm_c__51->SetBinContent(22,0.699951);
   norm_c__51->SetBinContent(23,0.414733);
   norm_c__51->SetBinContent(24,0.42507);
   norm_c__51->SetBinContent(25,0.03396421);
   norm_c__51->SetBinContent(26,0.4515359);
   norm_c__51->SetBinError(3,0.6489312);
   norm_c__51->SetBinError(4,1.888714);
   norm_c__51->SetBinError(5,2.648714);
   norm_c__51->SetBinError(6,3.428756);
   norm_c__51->SetBinError(7,4.856171);
   norm_c__51->SetBinError(8,5.155728);
   norm_c__51->SetBinError(9,5.732044);
   norm_c__51->SetBinError(10,5.75703);
   norm_c__51->SetBinError(11,5.984831);
   norm_c__51->SetBinError(12,6.438275);
   norm_c__51->SetBinError(13,5.384453);
   norm_c__51->SetBinError(14,4.326407);
   norm_c__51->SetBinError(15,3.108125);
   norm_c__51->SetBinError(16,2.680924);
   norm_c__51->SetBinError(17,2.28649);
   norm_c__51->SetBinError(18,1.453031);
   norm_c__51->SetBinError(19,1.231718);
   norm_c__51->SetBinError(20,0.327324);
   norm_c__51->SetBinError(21,0.340835);
   norm_c__51->SetBinError(22,0.3588232);
   norm_c__51->SetBinError(23,0.2051632);
   norm_c__51->SetBinError(24,0.3069829);
   norm_c__51->SetBinError(25,0.03396421);
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
   entry=leg->AddEntry("frame_x_c2_420e5b30","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.804782 #pm 0.010432","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.254064 #pm 0.008320","");
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
   
   TH1D *frame_420e5b30_copy__52 = new TH1D("frame_420e5b30_copy__52","p_T Balance",25,0,2);
   frame_420e5b30_copy__52->SetBinContent(1,93.54286);
   frame_420e5b30_copy__52->SetMinimum(-4.454422);
   frame_420e5b30_copy__52->SetMaximum(93.54286);
   frame_420e5b30_copy__52->SetEntries(1);
   frame_420e5b30_copy__52->SetDirectory(0);
   frame_420e5b30_copy__52->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_420e5b30_copy__52->SetLineColor(ci);
   frame_420e5b30_copy__52->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_420e5b30_copy__52->GetXaxis()->SetLabelFont(42);
   frame_420e5b30_copy__52->GetXaxis()->SetTitleOffset(1);
   frame_420e5b30_copy__52->GetXaxis()->SetTitleFont(42);
   frame_420e5b30_copy__52->GetYaxis()->SetTitle("1/Events");
   frame_420e5b30_copy__52->GetYaxis()->SetLabelFont(42);
   frame_420e5b30_copy__52->GetYaxis()->SetTitleFont(42);
   frame_420e5b30_copy__52->GetZaxis()->SetLabelFont(42);
   frame_420e5b30_copy__52->GetZaxis()->SetTitleOffset(1);
   frame_420e5b30_copy__52->GetZaxis()->SetTitleFont(42);
   frame_420e5b30_copy__52->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-15.3045,2.25,115.199);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_420c1d30__53 = new TH1D("frame_420c1d30__53","p_T Balance",25,0,2);
   frame_420c1d30__53->SetBinContent(1,102.1486);
   frame_420c1d30__53->SetMinimum(-4.86422);
   frame_420c1d30__53->SetMaximum(102.1486);
   frame_420c1d30__53->SetEntries(1);
   frame_420c1d30__53->SetDirectory(0);
   frame_420c1d30__53->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_420c1d30__53->SetLineColor(ci);
   frame_420c1d30__53->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_420c1d30__53->GetXaxis()->SetLabelFont(42);
   frame_420c1d30__53->GetXaxis()->SetTitleOffset(1);
   frame_420c1d30__53->GetXaxis()->SetTitleFont(42);
   frame_420c1d30__53->GetYaxis()->SetTitle("1/Events");
   frame_420c1d30__53->GetYaxis()->SetLabelFont(42);
   frame_420c1d30__53->GetYaxis()->SetTitleFont(42);
   frame_420c1d30__53->GetZaxis()->SetLabelFont(42);
   frame_420c1d30__53->GetZaxis()->SetTitleOffset(1);
   frame_420c1d30__53->GetZaxis()->SetTitleFont(42);
   frame_420c1d30__53->Draw("FUNC");
   
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
   1.971656,
   6.414702,
   16.95193,
   27.21385,
   45.57936,
   56.08862,
   58.79611,
   90.79326,
   80.11246,
   83.79919,
   69.47886,
   43.75602,
   33.71272,
   20.67869,
   12.29446,
   6.516231,
   3.41263,
   1.549866,
   0.585704,
   0.6967253,
   0.5602151,
   0.1675864,
   0.2552472};
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
   0.7169419,
   1.164221,
   2.65689,
   3.392078,
   5.087313,
   5.047617,
   5.129558,
   6.491145,
   5.967574,
   6.310872,
   5.723335,
   4.4201,
   3.728683,
   2.77347,
   2.408509,
   1.546388,
   1.265316,
   0.7124201,
   0.3471564,
   0.3569826,
   0.2517985,
   0.1675864,
   0.2552472};
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
   0.7169419,
   1.164221,
   2.65689,
   3.392078,
   5.087313,
   5.047617,
   5.129558,
   6.491145,
   5.967574,
   6.310872,
   5.723335,
   4.4201,
   3.728683,
   2.77347,
   2.408509,
   1.546388,
   1.265316,
   0.7124201,
   0.3471564,
   0.3569826,
   0.2517985,
   0.1675864,
   0.2552472};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3014,h_dh_up2_fy3014,h_dh_up2_felx3014,h_dh_up2_fehx3014,h_dh_up2_fely3014,h_dh_up2_fehy3014);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23014 = new TH1F("Graph_h_dh_up23014","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23014->SetMinimum(-9.72844);
   Graph_h_dh_up23014->SetMaximum(107.0128);
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
   
   Double_t up_fx14[56] = {
   0.2251906,
   0.2496808,
   0.2741709,
   0.2986611,
   0.3231513,
   0.3476414,
   0.3721316,
   0.3966217,
   0.4211119,
   0.4456021,
   0.4700922,
   0.4945824,
   0.5190725,
   0.5680529,
   0.6170332,
   0.6415233,
   0.6660135,
   0.6905037,
   0.7149938,
   0.739484,
   0.7517291,
   0.7639741,
   0.7762192,
   0.7884643,
   0.8007094,
   0.8129545,
   0.8251995,
   0.8374446,
   0.8496897,
   0.8619348,
   0.8741799,
   0.8864249,
   0.89867,
   0.9109151,
   0.9354053,
   0.9598954,
   0.9843856,
   1.008876,
   1.033366,
   1.057856,
   1.106836,
   1.131327,
   1.155817,
   1.180307,
   1.204797,
   1.229287,
   1.253777,
   1.278267,
   1.302758,
   1.327248,
   1.351738,
   1.376228,
   1.400718,
   1.425208,
   1.449699,
   1.449699};
   Double_t up_fy14[56] = {
   4.804434,
   6.043579,
   7.537155,
   9.309613,
   11.3885,
   13.79789,
   16.55653,
   19.67601,
   23.15878,
   26.99635,
   31.16775,
   35.63827,
   40.35884,
   50.28234,
   60.27481,
   65.04476,
   69.51838,
   73.58646,
   77.14487,
   80.09899,
   81.32351,
   82.36788,
   83.22474,
   83.88797,
   84.35282,
   84.61596,
   84.67549,
   84.53096,
   84.18344,
   83.63541,
   82.89083,
   81.95501,
   80.83458,
   79.53745,
   76.45021,
   72.77741,
   68.616,
   64.07152,
   59.25372,
   54.27215,
   44.23159,
   39.35742,
   34.68419,
   30.27244,
   26.16821,
   22.40328,
   18.99591,
   15.95216,
   13.26752,
   10.92876,
   8.915851,
   7.203867,
   5.764736,
   4.56882,
   3.586242,
   3.586242};
   graph = new TGraph(56,up_fx14,up_fy14);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up14 = new TH1F("Graph_up14","Projection of upf DSCB fit",100,0.1027398,1.572149);
   Graph_up14->SetMinimum(3.227618);
   Graph_up14->SetMaximum(92.78441);
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
   
   TH1D *frame_420c1d30__54 = new TH1D("frame_420c1d30__54","p_T Balance",25,0,2);
   frame_420c1d30__54->SetBinContent(1,102.1486);
   frame_420c1d30__54->SetMinimum(-4.86422);
   frame_420c1d30__54->SetMaximum(102.1486);
   frame_420c1d30__54->SetEntries(1);
   frame_420c1d30__54->SetDirectory(0);
   frame_420c1d30__54->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_420c1d30__54->SetLineColor(ci);
   frame_420c1d30__54->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_420c1d30__54->GetXaxis()->SetLabelFont(42);
   frame_420c1d30__54->GetXaxis()->SetTitleOffset(1);
   frame_420c1d30__54->GetXaxis()->SetTitleFont(42);
   frame_420c1d30__54->GetYaxis()->SetTitle("1/Events");
   frame_420c1d30__54->GetYaxis()->SetLabelFont(42);
   frame_420c1d30__54->GetYaxis()->SetTitleFont(42);
   frame_420c1d30__54->GetZaxis()->SetLabelFont(42);
   frame_420c1d30__54->GetZaxis()->SetTitleOffset(1);
   frame_420c1d30__54->GetZaxis()->SetTitleFont(42);
   frame_420c1d30__54->Draw("AXISSAME");
   
   TH1D *norm_u__55 = new TH1D("norm_u__55","",25,0,2);
   norm_u__55->SetBinContent(3,1.971656);
   norm_u__55->SetBinContent(4,6.414703);
   norm_u__55->SetBinContent(5,16.95192);
   norm_u__55->SetBinContent(6,27.21385);
   norm_u__55->SetBinContent(7,45.57937);
   norm_u__55->SetBinContent(8,56.08861);
   norm_u__55->SetBinContent(9,58.79611);
   norm_u__55->SetBinContent(10,90.79326);
   norm_u__55->SetBinContent(11,80.11246);
   norm_u__55->SetBinContent(12,83.7992);
   norm_u__55->SetBinContent(13,69.47886);
   norm_u__55->SetBinContent(14,43.75602);
   norm_u__55->SetBinContent(15,33.71272);
   norm_u__55->SetBinContent(16,20.67869);
   norm_u__55->SetBinContent(17,12.29446);
   norm_u__55->SetBinContent(18,6.516231);
   norm_u__55->SetBinContent(19,3.41263);
   norm_u__55->SetBinContent(20,1.549866);
   norm_u__55->SetBinContent(21,0.585704);
   norm_u__55->SetBinContent(22,0.6967253);
   norm_u__55->SetBinContent(23,0.5602151);
   norm_u__55->SetBinContent(24,0.1675864);
   norm_u__55->SetBinContent(25,0.2552472);
   norm_u__55->SetBinContent(26,0.4503215);
   norm_u__55->SetBinError(3,0.7169419);
   norm_u__55->SetBinError(4,1.164221);
   norm_u__55->SetBinError(5,2.65689);
   norm_u__55->SetBinError(6,3.392078);
   norm_u__55->SetBinError(7,5.087313);
   norm_u__55->SetBinError(8,5.047617);
   norm_u__55->SetBinError(9,5.129558);
   norm_u__55->SetBinError(10,6.491145);
   norm_u__55->SetBinError(11,5.967574);
   norm_u__55->SetBinError(12,6.310872);
   norm_u__55->SetBinError(13,5.723335);
   norm_u__55->SetBinError(14,4.4201);
   norm_u__55->SetBinError(15,3.728683);
   norm_u__55->SetBinError(16,2.77347);
   norm_u__55->SetBinError(17,2.408509);
   norm_u__55->SetBinError(18,1.546388);
   norm_u__55->SetBinError(19,1.265316);
   norm_u__55->SetBinError(20,0.7124201);
   norm_u__55->SetBinError(21,0.3471564);
   norm_u__55->SetBinError(22,0.3569826);
   norm_u__55->SetBinError(23,0.2517985);
   norm_u__55->SetBinError(24,0.1675864);
   norm_u__55->SetBinError(25,0.2552472);
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
   entry=leg->AddEntry("frame_x_u2_420c1d30","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.822605 #pm 0.010277","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.249300 #pm 0.008619","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.986000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_420c1d30_copy__56 = new TH1D("frame_420c1d30_copy__56","p_T Balance",25,0,2);
   frame_420c1d30_copy__56->SetBinContent(1,102.1486);
   frame_420c1d30_copy__56->SetMinimum(-4.86422);
   frame_420c1d30_copy__56->SetMaximum(102.1486);
   frame_420c1d30_copy__56->SetEntries(1);
   frame_420c1d30_copy__56->SetDirectory(0);
   frame_420c1d30_copy__56->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_420c1d30_copy__56->SetLineColor(ci);
   frame_420c1d30_copy__56->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_420c1d30_copy__56->GetXaxis()->SetLabelFont(42);
   frame_420c1d30_copy__56->GetXaxis()->SetTitleOffset(1);
   frame_420c1d30_copy__56->GetXaxis()->SetTitleFont(42);
   frame_420c1d30_copy__56->GetYaxis()->SetTitle("1/Events");
   frame_420c1d30_copy__56->GetYaxis()->SetLabelFont(42);
   frame_420c1d30_copy__56->GetYaxis()->SetTitleFont(42);
   frame_420c1d30_copy__56->GetZaxis()->SetLabelFont(42);
   frame_420c1d30_copy__56->GetZaxis()->SetTitleOffset(1);
   frame_420c1d30_copy__56->GetZaxis()->SetTitleFont(42);
   frame_420c1d30_copy__56->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-10.15429,2.25,91.38857);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_420e38d0__57 = new TH1D("frame_420e38d0__57","p_T Balance",25,0,2);
   frame_420e38d0__57->SetBinContent(1,89.35771);
   frame_420e38d0__57->SetMaximum(89.35771);
   frame_420e38d0__57->SetEntries(1);
   frame_420e38d0__57->SetDirectory(0);
   frame_420e38d0__57->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_420e38d0__57->SetLineColor(ci);
   frame_420e38d0__57->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_420e38d0__57->GetXaxis()->SetLabelFont(42);
   frame_420e38d0__57->GetXaxis()->SetTitleOffset(1);
   frame_420e38d0__57->GetXaxis()->SetTitleFont(42);
   frame_420e38d0__57->GetYaxis()->SetTitle("1/Events");
   frame_420e38d0__57->GetYaxis()->SetLabelFont(42);
   frame_420e38d0__57->GetYaxis()->SetTitleFont(42);
   frame_420e38d0__57->GetZaxis()->SetLabelFont(42);
   frame_420e38d0__57->GetZaxis()->SetTitleOffset(1);
   frame_420e38d0__57->GetZaxis()->SetTitleFont(42);
   frame_420e38d0__57->Draw("FUNC");
   
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
   2.030753,
   10.4333,
   18.12942,
   29.65136,
   46.45765,
   56.80877,
   64.10852,
   75.7997,
   79.24531,
   71.99722,
   55.90082,
   43.54065,
   26.28828,
   15.50419,
   9.612055,
   4.646348,
   3.130926,
   0.3412532,
   0.5414103,
   0.4143867,
   0.3254314,
   0.6892846,
   0.07549154};
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
   0.6790119,
   1.880156,
   2.736471,
   3.565191,
   4.651492,
   5.118314,
   5.310568,
   5.610643,
   5.857277,
   5.837269,
   5.150016,
   4.691071,
   2.985131,
   2.285474,
   2.092435,
   1.328641,
   1.260009,
   0.2142198,
   0.2499178,
   0.2218192,
   0.1856182,
   0.4046867,
   0.05361249};
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
   0.6790119,
   1.880156,
   2.736471,
   3.565191,
   4.651492,
   5.118314,
   5.310568,
   5.610643,
   5.857277,
   5.837269,
   5.150016,
   4.691071,
   2.985131,
   2.285474,
   2.092435,
   1.328641,
   1.260009,
   0.2142198,
   0.2499178,
   0.2218192,
   0.1856182,
   0.4046867,
   0.05361249};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3015,h_dh_down2_fy3015,h_dh_down2_felx3015,h_dh_down2_fehx3015,h_dh_down2_fely3015,h_dh_down2_fehy3015);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23015 = new TH1F("Graph_h_dh_down23015","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23015->SetMinimum(0);
   Graph_h_dh_down23015->SetMaximum(93.61284);
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
   0.1843887,
   0.2093802,
   0.2343718,
   0.2593633,
   0.2843548,
   0.3093464,
   0.3343379,
   0.3593294,
   0.384321,
   0.4093125,
   0.4343041,
   0.4592956,
   0.4842871,
   0.5342702,
   0.5842533,
   0.6092448,
   0.6342364,
   0.6592279,
   0.6842194,
   0.709211,
   0.7217067,
   0.7342025,
   0.7466983,
   0.7591941,
   0.7716898,
   0.7841856,
   0.7966814,
   0.8091771,
   0.8216729,
   0.8341687,
   0.8466644,
   0.8591602,
   0.871656,
   0.8841517,
   0.9091433,
   0.9341348,
   0.9591264,
   0.9841179,
   1.009109,
   1.034101,
   1.084084,
   1.109076,
   1.134067,
   1.159059,
   1.18405,
   1.209042,
   1.234033,
   1.259025,
   1.284016,
   1.309008,
   1.333999,
   1.358991,
   1.383983,
   1.408974,
   1.433966,
   1.433966};
   Double_t down_fy15[56] = {
   4.327924,
   5.298496,
   6.583689,
   8.16115,
   10.01833,
   12.17872,
   14.66121,
   17.47834,
   20.63444,
   24.12388,
   27.92954,
   32.02157,
   36.35661,
   45.51465,
   54.79833,
   59.25412,
   63.45003,
   67.28329,
   70.65529,
   73.47578,
   74.65429,
   75.66689,
   76.50635,
   77.16664,
   77.64298,
   77.93192,
   78.03134,
   77.94052,
   77.66011,
   77.19217,
   76.5401,
   75.70862,
   74.7037,
   73.53252,
   70.72545,
   67.36495,
   63.54105,
   59.35221,
   54.90115,
   50.29075,
   40.98149,
   36.45697,
   32.11705,
   28.019,
   24.20649,
   20.70967,
   17.54593,
   14.72115,
   12.23121,
   10.06373,
   8.19994,
   6.616441,
   5.28689,
   4.183485,
   3.278221,
   3.278221};
   graph = new TGraph(56,down_fx15,down_fy15);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down15 = new TH1F("Graph_down15","Projection of downf DSCB fit",100,0.05943099,1.558923);
   Graph_down15->SetMinimum(2.950399);
   Graph_down15->SetMaximum(85.50665);
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
   
   TH1D *frame_420e38d0__58 = new TH1D("frame_420e38d0__58","p_T Balance",25,0,2);
   frame_420e38d0__58->SetBinContent(1,89.35771);
   frame_420e38d0__58->SetMaximum(89.35771);
   frame_420e38d0__58->SetEntries(1);
   frame_420e38d0__58->SetDirectory(0);
   frame_420e38d0__58->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_420e38d0__58->SetLineColor(ci);
   frame_420e38d0__58->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_420e38d0__58->GetXaxis()->SetLabelFont(42);
   frame_420e38d0__58->GetXaxis()->SetTitleOffset(1);
   frame_420e38d0__58->GetXaxis()->SetTitleFont(42);
   frame_420e38d0__58->GetYaxis()->SetTitle("1/Events");
   frame_420e38d0__58->GetYaxis()->SetLabelFont(42);
   frame_420e38d0__58->GetYaxis()->SetTitleFont(42);
   frame_420e38d0__58->GetZaxis()->SetLabelFont(42);
   frame_420e38d0__58->GetZaxis()->SetTitleOffset(1);
   frame_420e38d0__58->GetZaxis()->SetTitleFont(42);
   frame_420e38d0__58->Draw("AXISSAME");
   
   TH1D *norm_d__59 = new TH1D("norm_d__59","",25,0,2);
   norm_d__59->SetBinContent(3,2.030753);
   norm_d__59->SetBinContent(4,10.4333);
   norm_d__59->SetBinContent(5,18.12942);
   norm_d__59->SetBinContent(6,29.65136);
   norm_d__59->SetBinContent(7,46.45765);
   norm_d__59->SetBinContent(8,56.80877);
   norm_d__59->SetBinContent(9,64.10852);
   norm_d__59->SetBinContent(10,75.7997);
   norm_d__59->SetBinContent(11,79.24531);
   norm_d__59->SetBinContent(12,71.99723);
   norm_d__59->SetBinContent(13,55.90082);
   norm_d__59->SetBinContent(14,43.54065);
   norm_d__59->SetBinContent(15,26.28828);
   norm_d__59->SetBinContent(16,15.50419);
   norm_d__59->SetBinContent(17,9.612055);
   norm_d__59->SetBinContent(18,4.646348);
   norm_d__59->SetBinContent(19,3.130926);
   norm_d__59->SetBinContent(20,0.3412532);
   norm_d__59->SetBinContent(21,0.5414102);
   norm_d__59->SetBinContent(22,0.4143867);
   norm_d__59->SetBinContent(23,0.3254314);
   norm_d__59->SetBinContent(24,0.6892846);
   norm_d__59->SetBinContent(25,0.07549154);
   norm_d__59->SetBinContent(26,0.2550833);
   norm_d__59->SetBinError(3,0.6790119);
   norm_d__59->SetBinError(4,1.880156);
   norm_d__59->SetBinError(5,2.736471);
   norm_d__59->SetBinError(6,3.565191);
   norm_d__59->SetBinError(7,4.651492);
   norm_d__59->SetBinError(8,5.118314);
   norm_d__59->SetBinError(9,5.310568);
   norm_d__59->SetBinError(10,5.610643);
   norm_d__59->SetBinError(11,5.857277);
   norm_d__59->SetBinError(12,5.837269);
   norm_d__59->SetBinError(13,5.150016);
   norm_d__59->SetBinError(14,4.691071);
   norm_d__59->SetBinError(15,2.985131);
   norm_d__59->SetBinError(16,2.285474);
   norm_d__59->SetBinError(17,2.092435);
   norm_d__59->SetBinError(18,1.328641);
   norm_d__59->SetBinError(19,1.260009);
   norm_d__59->SetBinError(20,0.2142198);
   norm_d__59->SetBinError(21,0.2499178);
   norm_d__59->SetBinError(22,0.2218192);
   norm_d__59->SetBinError(23,0.1856182);
   norm_d__59->SetBinError(24,0.4046867);
   norm_d__59->SetBinError(25,0.05361249);
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
   entry=leg->AddEntry("frame_x_d2_420e38d0","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.795556 #pm 0.010768","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.251197 #pm 0.009304","");
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
   
   TH1D *frame_420e38d0_copy__60 = new TH1D("frame_420e38d0_copy__60","p_T Balance",25,0,2);
   frame_420e38d0_copy__60->SetBinContent(1,89.35771);
   frame_420e38d0_copy__60->SetMaximum(89.35771);
   frame_420e38d0_copy__60->SetEntries(1);
   frame_420e38d0_copy__60->SetDirectory(0);
   frame_420e38d0_copy__60->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_420e38d0_copy__60->SetLineColor(ci);
   frame_420e38d0_copy__60->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_420e38d0_copy__60->GetXaxis()->SetLabelFont(42);
   frame_420e38d0_copy__60->GetXaxis()->SetTitleOffset(1);
   frame_420e38d0_copy__60->GetXaxis()->SetTitleFont(42);
   frame_420e38d0_copy__60->GetYaxis()->SetTitle("1/Events");
   frame_420e38d0_copy__60->GetYaxis()->SetLabelFont(42);
   frame_420e38d0_copy__60->GetYaxis()->SetTitleFont(42);
   frame_420e38d0_copy__60->GetZaxis()->SetLabelFont(42);
   frame_420e38d0_copy__60->GetZaxis()->SetTitleOffset(1);
   frame_420e38d0_copy__60->GetZaxis()->SetTitleFont(42);
   frame_420e38d0_copy__60->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-11.8685,2.25,106.8165);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_420d0b80__61 = new TH1D("frame_420d0b80__61","p_T Balance",25,0,2);
   frame_420d0b80__61->SetBinContent(1,104.4428);
   frame_420d0b80__61->SetMaximum(104.4428);
   frame_420d0b80__61->SetEntries(1);
   frame_420d0b80__61->SetDirectory(0);
   frame_420d0b80__61->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_420d0b80__61->SetLineColor(ci);
   frame_420d0b80__61->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_420d0b80__61->GetXaxis()->SetLabelFont(42);
   frame_420d0b80__61->GetXaxis()->SetTitleOffset(1);
   frame_420d0b80__61->GetXaxis()->SetTitleFont(42);
   frame_420d0b80__61->GetYaxis()->SetTitle("1/Events");
   frame_420d0b80__61->GetYaxis()->SetLabelFont(42);
   frame_420d0b80__61->GetYaxis()->SetTitleFont(42);
   frame_420d0b80__61->GetZaxis()->SetLabelFont(42);
   frame_420d0b80__61->GetZaxis()->SetTitleOffset(1);
   frame_420d0b80__61->GetZaxis()->SetTitleFont(42);
   frame_420d0b80__61->Draw("FUNC");
   
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
   4,
   18,
   18,
   41,
   39,
   59,
   75,
   89,
   89,
   66,
   48,
   44,
   30,
   20,
   12,
   5,
   3,
   0,
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
   1.914339,
   4.202887,
   4.202887,
   6.376898,
   6.218102,
   7.659312,
   8.640903,
   9.416226,
   9.416226,
   8.103403,
   6.903979,
   6.60794,
   5.446522,
   4.434448,
   3.415266,
   2.159691,
   1.632705,
   0,
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
   3.162753,
   5.321007,
   5.321007,
   7.455185,
   7.298372,
   8.724565,
   9.698771,
   10.46934,
   10.46934,
   9.165094,
   7.97633,
   7.68351,
   6.538046,
   5.546519,
   4.559819,
   3.382473,
   2.918186,
   1.147874,
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
   Graph_h_dh_data23016->SetMaximum(109.4163);
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
   0.1227519,
   0.1493032,
   0.1758544,
   0.2024057,
   0.2289569,
   0.2555082,
   0.2820595,
   0.3086107,
   0.335162,
   0.3617132,
   0.3882645,
   0.4148157,
   0.441367,
   0.4679183,
   0.4944695,
   0.547572,
   0.5741233,
   0.6006746,
   0.6272258,
   0.6537771,
   0.6803283,
   0.693604,
   0.7068796,
   0.7201552,
   0.7334309,
   0.7467065,
   0.7599821,
   0.7732578,
   0.7865334,
   0.799809,
   0.8130846,
   0.8263603,
   0.8396359,
   0.8529115,
   0.8661872,
   0.8794628,
   0.8927384,
   0.9192897,
   0.9458409,
   0.9723922,
   0.9989435,
   1.025495,
   1.078597,
   1.105148,
   1.1317,
   1.158251,
   1.184802,
   1.211354,
   1.237905,
   1.264456,
   1.291007,
   1.317559,
   1.34411,
   1.370661,
   1.397212,
   1.423764,
   1.450315,
   1.450315};
   Double_t observation_fy16[58] = {
   3.071782,
   3.968588,
   5.074072,
   6.420256,
   8.039391,
   9.962516,
   12.21772,
   14.82812,
   17.80973,
   21.16916,
   24.90147,
   28.98821,
   33.39589,
   38.07498,
   42.95972,
   53.00663,
   57.96652,
   62.73347,
   67.18875,
   71.21457,
   74.69925,
   76.20669,
   77.54231,
   78.69609,
   79.65927,
   80.42448,
   80.98582,
   81.33893,
   81.48108,
   81.41113,
   81.12965,
   80.63883,
   79.94247,
   79.04596,
   77.95619,
   76.68145,
   75.23133,
   71.84921,
   67.9079,
   63.51755,
   58.79525,
   53.85994,
   43.80648,
   38.89441,
   34.17521,
   29.71736,
   25.57316,
   21.77879,
   18.35515,
   15.30938,
   12.63665,
   10.32242,
   8.344616,
   6.675844,
   5.285439,
   4.141247,
   3.211117,
   3.211117};
   graph = new TGraph(58,observation_fx16,observation_fy16);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation16 = new TH1F("Graph_observation16","Projection of obsf DSCB fit",100,0,1.583071);
   Graph_observation16->SetMinimum(2.764604);
   Graph_observation16->SetMaximum(89.322);
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
   
   TH1D *frame_420d0b80__62 = new TH1D("frame_420d0b80__62","p_T Balance",25,0,2);
   frame_420d0b80__62->SetBinContent(1,104.4428);
   frame_420d0b80__62->SetMaximum(104.4428);
   frame_420d0b80__62->SetEntries(1);
   frame_420d0b80__62->SetDirectory(0);
   frame_420d0b80__62->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_420d0b80__62->SetLineColor(ci);
   frame_420d0b80__62->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_420d0b80__62->GetXaxis()->SetLabelFont(42);
   frame_420d0b80__62->GetXaxis()->SetTitleOffset(1);
   frame_420d0b80__62->GetXaxis()->SetTitleFont(42);
   frame_420d0b80__62->GetYaxis()->SetTitle("1/Events");
   frame_420d0b80__62->GetYaxis()->SetLabelFont(42);
   frame_420d0b80__62->GetYaxis()->SetTitleFont(42);
   frame_420d0b80__62->GetZaxis()->SetLabelFont(42);
   frame_420d0b80__62->GetZaxis()->SetTitleOffset(1);
   frame_420d0b80__62->GetZaxis()->SetTitleFont(42);
   frame_420d0b80__62->Draw("AXISSAME");
   
   TH1D *norm_o__63 = new TH1D("norm_o__63","",25,0,2);
   norm_o__63->SetBinContent(3,4);
   norm_o__63->SetBinContent(4,18);
   norm_o__63->SetBinContent(5,18);
   norm_o__63->SetBinContent(6,41);
   norm_o__63->SetBinContent(7,39);
   norm_o__63->SetBinContent(8,59);
   norm_o__63->SetBinContent(9,75);
   norm_o__63->SetBinContent(10,89);
   norm_o__63->SetBinContent(11,89);
   norm_o__63->SetBinContent(12,66);
   norm_o__63->SetBinContent(13,48);
   norm_o__63->SetBinContent(14,44);
   norm_o__63->SetBinContent(15,30);
   norm_o__63->SetBinContent(16,20);
   norm_o__63->SetBinContent(17,12);
   norm_o__63->SetBinContent(18,5);
   norm_o__63->SetBinContent(19,3);
   norm_o__63->SetBinContent(21,1);
   norm_o__63->SetBinContent(22,1);
   norm_o__63->SetMinimum(0);
   norm_o__63->SetMaximum(195.8);
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
   entry=leg->AddEntry("frame_x_o2_420d0b80","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.788742 #pm 0.010575","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.260112 #pm 0.008622","");
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
   
   TH1D *frame_420d0b80_copy__64 = new TH1D("frame_420d0b80_copy__64","p_T Balance",25,0,2);
   frame_420d0b80_copy__64->SetBinContent(1,104.4428);
   frame_420d0b80_copy__64->SetMaximum(104.4428);
   frame_420d0b80_copy__64->SetEntries(1);
   frame_420d0b80_copy__64->SetDirectory(0);
   frame_420d0b80_copy__64->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_420d0b80_copy__64->SetLineColor(ci);
   frame_420d0b80_copy__64->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_420d0b80_copy__64->GetXaxis()->SetLabelFont(42);
   frame_420d0b80_copy__64->GetXaxis()->SetTitleOffset(1);
   frame_420d0b80_copy__64->GetXaxis()->SetTitleFont(42);
   frame_420d0b80_copy__64->GetYaxis()->SetTitle("1/Events");
   frame_420d0b80_copy__64->GetYaxis()->SetLabelFont(42);
   frame_420d0b80_copy__64->GetYaxis()->SetTitleFont(42);
   frame_420d0b80_copy__64->GetZaxis()->SetLabelFont(42);
   frame_420d0b80_copy__64->GetZaxis()->SetTitleOffset(1);
   frame_420d0b80_copy__64->GetZaxis()->SetTitleFont(42);
   frame_420d0b80_copy__64->Draw("sameaxis");
   
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
