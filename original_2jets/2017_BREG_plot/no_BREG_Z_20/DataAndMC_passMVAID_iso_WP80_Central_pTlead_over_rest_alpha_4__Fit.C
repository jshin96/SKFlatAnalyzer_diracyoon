void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_4__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 18:20:13 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-19.02745,2.25,218.8157);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_411d5e60__49 = new TH1D("frame_411d5e60__49","p_T Balance",25,0,2);
   frame_411d5e60__49->SetBinContent(1,195.0314);
   frame_411d5e60__49->SetMaximum(195.0314);
   frame_411d5e60__49->SetEntries(1);
   frame_411d5e60__49->SetDirectory(0);
   frame_411d5e60__49->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_411d5e60__49->SetLineColor(ci);
   frame_411d5e60__49->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_411d5e60__49->GetXaxis()->SetLabelFont(42);
   frame_411d5e60__49->GetXaxis()->SetTitleOffset(1);
   frame_411d5e60__49->GetXaxis()->SetTitleFont(42);
   frame_411d5e60__49->GetYaxis()->SetTitle("1/Events");
   frame_411d5e60__49->GetYaxis()->SetLabelFont(42);
   frame_411d5e60__49->GetYaxis()->SetTitleFont(42);
   frame_411d5e60__49->GetZaxis()->SetLabelFont(42);
   frame_411d5e60__49->GetZaxis()->SetTitleOffset(1);
   frame_411d5e60__49->GetZaxis()->SetTitleFont(42);
   frame_411d5e60__49->Draw("FUNC");
   
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
   6.49718,
   20.11113,
   36.94779,
   63.98325,
   76.22427,
   127.2512,
   172.292,
   176.865,
   177.1293,
   172.1652,
   134.194,
   98.30726,
   60.79641,
   42.11678,
   24.09825,
   11.52125,
   6.610921,
   3.850653,
   0.6501415,
   0.760255,
   0.5726151,
   0.4631577,
   0.4436391};
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
   1.514437,
   2.56854,
   3.943556,
   5.521967,
   5.449806,
   7.605519,
   8.768813,
   8.729582,
   8.6149,
   8.606036,
   7.435396,
   6.226101,
   4.828093,
   3.918633,
   2.874788,
   1.988162,
   1.241652,
   1.090605,
   0.2702578,
   0.2971543,
   0.2885471,
   0.2869868,
   0.199178};
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
   1.514437,
   2.56854,
   3.943556,
   5.521967,
   5.449806,
   7.605519,
   8.768813,
   8.729582,
   8.6149,
   8.606036,
   7.435396,
   6.226101,
   4.828093,
   3.918633,
   2.874788,
   1.988162,
   1.241652,
   1.090605,
   0.2702578,
   0.2971543,
   0.2885471,
   0.2869868,
   0.199178};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3013,h_dh_central2_fy3013,h_dh_central2_felx3013,h_dh_central2_fehx3013,h_dh_central2_fely3013,h_dh_central2_fehy3013);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23013 = new TH1F("Graph_h_dh_central23013","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23013->SetMinimum(0);
   Graph_h_dh_central23013->SetMaximum(204.3186);
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
   0.1605999,
   0.1861565,
   0.2117132,
   0.2372699,
   0.2628265,
   0.2883832,
   0.3139398,
   0.3394965,
   0.3650532,
   0.3906098,
   0.4161665,
   0.4417232,
   0.4672798,
   0.4928365,
   0.5183931,
   0.5695065,
   0.6206198,
   0.6461765,
   0.6717331,
   0.6972898,
   0.7100681,
   0.7228464,
   0.7356248,
   0.7484031,
   0.7611814,
   0.7739598,
   0.7867381,
   0.7995164,
   0.8122948,
   0.8250731,
   0.8378514,
   0.8506297,
   0.8634081,
   0.8761864,
   0.8889647,
   0.9017431,
   0.9145214,
   0.9272997,
   0.9528564,
   0.9784131,
   1.00397,
   1.029526,
   1.08064,
   1.106196,
   1.131753,
   1.15731,
   1.182866,
   1.208423,
   1.23398,
   1.259536,
   1.285093,
   1.31065,
   1.336206,
   1.361763,
   1.374541,
   1.38732,
   1.438433,
   1.438433};
   Double_t Central_fy13[58] = {
   5.652125,
   7.393685,
   9.56804,
   12.24892,
   15.51262,
   19.43505,
   24.08789,
   29.53415,
   35.8231,
   42.98476,
   51.02449,
   59.91776,
   69.60578,
   79.99222,
   90.94168,
   113.7972,
   136.3803,
   146.903,
   156.539,
   165.0164,
   168.7414,
   172.0856,
   175.0231,
   177.5312,
   179.5899,
   181.183,
   182.2978,
   182.9251,
   183.06,
   182.7013,
   181.8521,
   180.519,
   178.7129,
   176.4481,
   173.7426,
   170.6175,
   167.0973,
   163.2087,
   154.4456,
   144.5841,
   133.8993,
   122.673,
   99.68471,
   88.41734,
   77.58167,
   67.34317,
   57.82835,
   49.1248,
   41.28322,
   34.32093,
   28.22652,
   22.9651,
   18.48384,
   14.71732,
   13.77168,
   13.39558,
   12.74635,
   12.74635};
   TGraph *graph = new TGraph(58,Central_fx13,Central_fy13);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central13 = new TH1F("Graph_Central13","Projection of centralf DSCB fit",100,0.03281656,1.566216);
   Graph_Central13->SetMinimum(5.086912);
   Graph_Central13->SetMaximum(200.8008);
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
   
   TH1D *frame_411d5e60__50 = new TH1D("frame_411d5e60__50","p_T Balance",25,0,2);
   frame_411d5e60__50->SetBinContent(1,195.0314);
   frame_411d5e60__50->SetMaximum(195.0314);
   frame_411d5e60__50->SetEntries(1);
   frame_411d5e60__50->SetDirectory(0);
   frame_411d5e60__50->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_411d5e60__50->SetLineColor(ci);
   frame_411d5e60__50->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_411d5e60__50->GetXaxis()->SetLabelFont(42);
   frame_411d5e60__50->GetXaxis()->SetTitleOffset(1);
   frame_411d5e60__50->GetXaxis()->SetTitleFont(42);
   frame_411d5e60__50->GetYaxis()->SetTitle("1/Events");
   frame_411d5e60__50->GetYaxis()->SetLabelFont(42);
   frame_411d5e60__50->GetYaxis()->SetTitleFont(42);
   frame_411d5e60__50->GetZaxis()->SetLabelFont(42);
   frame_411d5e60__50->GetZaxis()->SetTitleOffset(1);
   frame_411d5e60__50->GetZaxis()->SetTitleFont(42);
   frame_411d5e60__50->Draw("AXISSAME");
   
   TH1D *norm_c__51 = new TH1D("norm_c__51","",25,0,2);
   norm_c__51->SetBinContent(3,6.49718);
   norm_c__51->SetBinContent(4,20.11113);
   norm_c__51->SetBinContent(5,36.94779);
   norm_c__51->SetBinContent(6,63.98325);
   norm_c__51->SetBinContent(7,76.22427);
   norm_c__51->SetBinContent(8,127.2511);
   norm_c__51->SetBinContent(9,172.292);
   norm_c__51->SetBinContent(10,176.865);
   norm_c__51->SetBinContent(11,177.1293);
   norm_c__51->SetBinContent(12,172.1652);
   norm_c__51->SetBinContent(13,134.194);
   norm_c__51->SetBinContent(14,98.30726);
   norm_c__51->SetBinContent(15,60.79641);
   norm_c__51->SetBinContent(16,42.11678);
   norm_c__51->SetBinContent(17,24.09825);
   norm_c__51->SetBinContent(18,11.52125);
   norm_c__51->SetBinContent(19,6.610921);
   norm_c__51->SetBinContent(20,3.850653);
   norm_c__51->SetBinContent(21,0.6501415);
   norm_c__51->SetBinContent(22,0.760255);
   norm_c__51->SetBinContent(23,0.5726151);
   norm_c__51->SetBinContent(24,0.4631577);
   norm_c__51->SetBinContent(25,0.4436391);
   norm_c__51->SetBinContent(26,1.066913);
   norm_c__51->SetBinError(3,1.514437);
   norm_c__51->SetBinError(4,2.56854);
   norm_c__51->SetBinError(5,3.943556);
   norm_c__51->SetBinError(6,5.521967);
   norm_c__51->SetBinError(7,5.449806);
   norm_c__51->SetBinError(8,7.605519);
   norm_c__51->SetBinError(9,8.768813);
   norm_c__51->SetBinError(10,8.729582);
   norm_c__51->SetBinError(11,8.6149);
   norm_c__51->SetBinError(12,8.606036);
   norm_c__51->SetBinError(13,7.435396);
   norm_c__51->SetBinError(14,6.226101);
   norm_c__51->SetBinError(15,4.828093);
   norm_c__51->SetBinError(16,3.918633);
   norm_c__51->SetBinError(17,2.874788);
   norm_c__51->SetBinError(18,1.988162);
   norm_c__51->SetBinError(19,1.241652);
   norm_c__51->SetBinError(20,1.090605);
   norm_c__51->SetBinError(21,0.2702578);
   norm_c__51->SetBinError(22,0.2971543);
   norm_c__51->SetBinError(23,0.2885471);
   norm_c__51->SetBinError(24,0.2869868);
   norm_c__51->SetBinError(25,0.199178);
   norm_c__51->SetBinError(26,0.2824815);
   norm_c__51->SetEntries(6628);
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
   entry=leg->AddEntry("frame_x_c2_411d5e60","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.810646 #pm 0.006879","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.247643 #pm 0.005546","");
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
   
   TH1D *frame_411d5e60_copy__52 = new TH1D("frame_411d5e60_copy__52","p_T Balance",25,0,2);
   frame_411d5e60_copy__52->SetBinContent(1,195.0314);
   frame_411d5e60_copy__52->SetMaximum(195.0314);
   frame_411d5e60_copy__52->SetEntries(1);
   frame_411d5e60_copy__52->SetDirectory(0);
   frame_411d5e60_copy__52->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_411d5e60_copy__52->SetLineColor(ci);
   frame_411d5e60_copy__52->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_411d5e60_copy__52->GetXaxis()->SetLabelFont(42);
   frame_411d5e60_copy__52->GetXaxis()->SetTitleOffset(1);
   frame_411d5e60_copy__52->GetXaxis()->SetTitleFont(42);
   frame_411d5e60_copy__52->GetYaxis()->SetTitle("1/Events");
   frame_411d5e60_copy__52->GetYaxis()->SetLabelFont(42);
   frame_411d5e60_copy__52->GetYaxis()->SetTitleFont(42);
   frame_411d5e60_copy__52->GetZaxis()->SetLabelFont(42);
   frame_411d5e60_copy__52->GetZaxis()->SetTitleOffset(1);
   frame_411d5e60_copy__52->GetZaxis()->SetTitleFont(42);
   frame_411d5e60_copy__52->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-20.67434,2.25,237.7549);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_411c7c00__53 = new TH1D("frame_411c7c00__53","p_T Balance",25,0,2);
   frame_411c7c00__53->SetBinContent(1,211.912);
   frame_411c7c00__53->SetMaximum(211.912);
   frame_411c7c00__53->SetEntries(1);
   frame_411c7c00__53->SetDirectory(0);
   frame_411c7c00__53->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_411c7c00__53->SetLineColor(ci);
   frame_411c7c00__53->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_411c7c00__53->GetXaxis()->SetLabelFont(42);
   frame_411c7c00__53->GetXaxis()->SetTitleOffset(1);
   frame_411c7c00__53->GetXaxis()->SetTitleFont(42);
   frame_411c7c00__53->GetYaxis()->SetTitle("1/Events");
   frame_411c7c00__53->GetYaxis()->SetLabelFont(42);
   frame_411c7c00__53->GetYaxis()->SetTitleFont(42);
   frame_411c7c00__53->GetZaxis()->SetLabelFont(42);
   frame_411c7c00__53->GetZaxis()->SetTitleOffset(1);
   frame_411c7c00__53->GetZaxis()->SetTitleFont(42);
   frame_411c7c00__53->Draw("FUNC");
   
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
   5.51111,
   19.38025,
   34.05765,
   55.11837,
   77.80201,
   114.7989,
   161.7083,
   174.455,
   190.8498,
   192.5552,
   154.3428,
   113.8665,
   68.72294,
   45.00859,
   27.51408,
   13.36138,
   7.796879,
   3.226542,
   1.117471,
   0.6041912,
   1.250903,
   0.4945862,
   0.366693};
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
   1.472377,
   2.616463,
   3.896473,
   4.823995,
   5.582414,
   7.337043,
   8.634135,
   8.77998,
   9.03037,
   9.265732,
   8.10487,
   6.844187,
   5.267025,
   4.014587,
   3.203669,
   1.964028,
   1.379455,
   0.9919554,
   0.4084204,
   0.2590912,
   0.5131856,
   0.2876313,
   0.2080681};
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
   1.472377,
   2.616463,
   3.896473,
   4.823995,
   5.582414,
   7.337043,
   8.634135,
   8.77998,
   9.03037,
   9.265732,
   8.10487,
   6.844187,
   5.267025,
   4.014587,
   3.203669,
   1.964028,
   1.379455,
   0.9919554,
   0.4084204,
   0.2590912,
   0.5131856,
   0.2876313,
   0.2080681};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3014,h_dh_up2_fy3014,h_dh_up2_felx3014,h_dh_up2_fehx3014,h_dh_up2_fely3014,h_dh_up2_fehy3014);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23014 = new TH1F("Graph_h_dh_up23014","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23014->SetMinimum(0);
   Graph_h_dh_up23014->SetMaximum(222.003);
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
   0.2413114,
   0.288773,
   0.3125037,
   0.3362345,
   0.3599653,
   0.3836961,
   0.4074269,
   0.4311576,
   0.4548884,
   0.4786192,
   0.4904846,
   0.50235,
   0.5260808,
   0.5498115,
   0.5735423,
   0.6210039,
   0.6447346,
   0.6684654,
   0.6921962,
   0.715927,
   0.7396578,
   0.7515231,
   0.7633885,
   0.7752539,
   0.7871193,
   0.7989847,
   0.8108501,
   0.8227155,
   0.8345809,
   0.8464463,
   0.8583117,
   0.870177,
   0.8820424,
   0.8939078,
   0.9057732,
   0.9176386,
   0.929504,
   0.9532348,
   0.9769655,
   1.000696,
   1.024427,
   1.048158,
   1.095619,
   1.11935,
   1.143081,
   1.166812,
   1.190543,
   1.214273,
   1.238004,
   1.261735,
   1.285466,
   1.309196,
   1.332927,
   1.356658,
   1.368523,
   1.380389,
   1.42785,
   1.42785};
   Double_t up_fy14[58] = {
   18.98113,
   23.45899,
   26.19367,
   29.33872,
   32.97028,
   37.18153,
   42.08714,
   47.82914,
   54.58465,
   62.57611,
   67.12052,
   72.0535,
   82.49804,
   93.51883,
   104.9594,
   128.312,
   139.7624,
   150.7234,
   160.9303,
   170.1225,
   178.0545,
   181.4778,
   184.5062,
   187.1177,
   189.2936,
   191.0176,
   192.2772,
   193.0629,
   193.3689,
   193.1929,
   192.5362,
   191.4037,
   189.8039,
   187.7485,
   185.2528,
   182.3349,
   179.0158,
   171.2715,
   162.2354,
   152.1504,
   141.2757,
   129.876,
   106.5252,
   95.04181,
   83.95448,
   73.42433,
   63.57745,
   54.50459,
   46.26261,
   38.87711,
   32.34632,
   26.64543,
   21.73139,
   17.60725,
   16.80432,
   16.41053,
   15.67233,
   15.67233};
   graph = new TGraph(58,up_fx14,up_fy14);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up14 = new TH1F("Graph_up14","Projection of upf DSCB fit",100,0.1226575,1.546504);
   Graph_up14->SetMinimum(14.1051);
   Graph_up14->SetMaximum(211.1385);
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
   
   TH1D *frame_411c7c00__54 = new TH1D("frame_411c7c00__54","p_T Balance",25,0,2);
   frame_411c7c00__54->SetBinContent(1,211.912);
   frame_411c7c00__54->SetMaximum(211.912);
   frame_411c7c00__54->SetEntries(1);
   frame_411c7c00__54->SetDirectory(0);
   frame_411c7c00__54->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_411c7c00__54->SetLineColor(ci);
   frame_411c7c00__54->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_411c7c00__54->GetXaxis()->SetLabelFont(42);
   frame_411c7c00__54->GetXaxis()->SetTitleOffset(1);
   frame_411c7c00__54->GetXaxis()->SetTitleFont(42);
   frame_411c7c00__54->GetYaxis()->SetTitle("1/Events");
   frame_411c7c00__54->GetYaxis()->SetLabelFont(42);
   frame_411c7c00__54->GetYaxis()->SetTitleFont(42);
   frame_411c7c00__54->GetZaxis()->SetLabelFont(42);
   frame_411c7c00__54->GetZaxis()->SetTitleOffset(1);
   frame_411c7c00__54->GetZaxis()->SetTitleFont(42);
   frame_411c7c00__54->Draw("AXISSAME");
   
   TH1D *norm_u__55 = new TH1D("norm_u__55","",25,0,2);
   norm_u__55->SetBinContent(3,5.51111);
   norm_u__55->SetBinContent(4,19.38025);
   norm_u__55->SetBinContent(5,34.05765);
   norm_u__55->SetBinContent(6,55.11837);
   norm_u__55->SetBinContent(7,77.80201);
   norm_u__55->SetBinContent(8,114.7989);
   norm_u__55->SetBinContent(9,161.7083);
   norm_u__55->SetBinContent(10,174.455);
   norm_u__55->SetBinContent(11,190.8498);
   norm_u__55->SetBinContent(12,192.5552);
   norm_u__55->SetBinContent(13,154.3428);
   norm_u__55->SetBinContent(14,113.8665);
   norm_u__55->SetBinContent(15,68.72294);
   norm_u__55->SetBinContent(16,45.00859);
   norm_u__55->SetBinContent(17,27.51408);
   norm_u__55->SetBinContent(18,13.36138);
   norm_u__55->SetBinContent(19,7.796879);
   norm_u__55->SetBinContent(20,3.226542);
   norm_u__55->SetBinContent(21,1.117471);
   norm_u__55->SetBinContent(22,0.6041913);
   norm_u__55->SetBinContent(23,1.250903);
   norm_u__55->SetBinContent(24,0.4945862);
   norm_u__55->SetBinContent(25,0.366693);
   norm_u__55->SetBinContent(26,1.023885);
   norm_u__55->SetBinError(3,1.472377);
   norm_u__55->SetBinError(4,2.616463);
   norm_u__55->SetBinError(5,3.896473);
   norm_u__55->SetBinError(6,4.823995);
   norm_u__55->SetBinError(7,5.582414);
   norm_u__55->SetBinError(8,7.337043);
   norm_u__55->SetBinError(9,8.634135);
   norm_u__55->SetBinError(10,8.77998);
   norm_u__55->SetBinError(11,9.03037);
   norm_u__55->SetBinError(12,9.265732);
   norm_u__55->SetBinError(13,8.10487);
   norm_u__55->SetBinError(14,6.844187);
   norm_u__55->SetBinError(15,5.267025);
   norm_u__55->SetBinError(16,4.014587);
   norm_u__55->SetBinError(17,3.203669);
   norm_u__55->SetBinError(18,1.964028);
   norm_u__55->SetBinError(19,1.379455);
   norm_u__55->SetBinError(20,0.9919554);
   norm_u__55->SetBinError(21,0.4084204);
   norm_u__55->SetBinError(22,0.2590912);
   norm_u__55->SetBinError(23,0.5131856);
   norm_u__55->SetBinError(24,0.2876313);
   norm_u__55->SetBinError(25,0.2080681);
   norm_u__55->SetBinError(26,0.2810893);
   norm_u__55->SetEntries(6578);
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
   entry=leg->AddEntry("frame_x_u2_411c7c00","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.836182 #pm 0.007363","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.237579 #pm 0.006676","");
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
   
   TH1D *frame_411c7c00_copy__56 = new TH1D("frame_411c7c00_copy__56","p_T Balance",25,0,2);
   frame_411c7c00_copy__56->SetBinContent(1,211.912);
   frame_411c7c00_copy__56->SetMaximum(211.912);
   frame_411c7c00_copy__56->SetEntries(1);
   frame_411c7c00_copy__56->SetDirectory(0);
   frame_411c7c00_copy__56->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_411c7c00_copy__56->SetLineColor(ci);
   frame_411c7c00_copy__56->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_411c7c00_copy__56->GetXaxis()->SetLabelFont(42);
   frame_411c7c00_copy__56->GetXaxis()->SetTitleOffset(1);
   frame_411c7c00_copy__56->GetXaxis()->SetTitleFont(42);
   frame_411c7c00_copy__56->GetYaxis()->SetTitle("1/Events");
   frame_411c7c00_copy__56->GetYaxis()->SetLabelFont(42);
   frame_411c7c00_copy__56->GetYaxis()->SetTitleFont(42);
   frame_411c7c00_copy__56->GetZaxis()->SetLabelFont(42);
   frame_411c7c00_copy__56->GetZaxis()->SetTitleOffset(1);
   frame_411c7c00_copy__56->GetZaxis()->SetTitleFont(42);
   frame_411c7c00_copy__56->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-22.31156,2.25,200.804);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_4115be50__57 = new TH1D("frame_4115be50__57","p_T Balance",25,0,2);
   frame_4115be50__57->SetBinContent(1,196.3417);
   frame_4115be50__57->SetMaximum(196.3417);
   frame_4115be50__57->SetEntries(1);
   frame_4115be50__57->SetDirectory(0);
   frame_4115be50__57->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4115be50__57->SetLineColor(ci);
   frame_4115be50__57->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4115be50__57->GetXaxis()->SetLabelFont(42);
   frame_4115be50__57->GetXaxis()->SetTitleOffset(1);
   frame_4115be50__57->GetXaxis()->SetTitleFont(42);
   frame_4115be50__57->GetYaxis()->SetTitle("1/Events");
   frame_4115be50__57->GetYaxis()->SetLabelFont(42);
   frame_4115be50__57->GetYaxis()->SetTitleFont(42);
   frame_4115be50__57->GetZaxis()->SetLabelFont(42);
   frame_4115be50__57->GetZaxis()->SetTitleOffset(1);
   frame_4115be50__57->GetZaxis()->SetTitleFont(42);
   frame_4115be50__57->Draw("FUNC");
   
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
   5.503276,
   20.05727,
   36.15108,
   59.16957,
   85.03493,
   124.0623,
   170.6387,
   177.3275,
   178.2712,
   162.523,
   133.2121,
   92.88693,
   64.18688,
   37.02882,
   22.22657,
   11.00969,
   6.528823,
   3.472511,
   0.7876202,
   1.101521,
   0.7811043,
   0.5923142,
   0.3730121};
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
   1.17253,
   2.517173,
   3.748179,
   5.241822,
   5.843052,
   7.342111,
   8.742002,
   8.736566,
   8.720948,
   8.24217,
   7.519126,
   6.037056,
   4.94332,
   3.732312,
   2.703576,
   1.869605,
   1.241296,
   1.034004,
   0.3195471,
   0.5015367,
   0.3406474,
   0.3279573,
   0.1360189};
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
   1.17253,
   2.517173,
   3.748179,
   5.241822,
   5.843052,
   7.342111,
   8.742002,
   8.736566,
   8.720948,
   8.24217,
   7.519126,
   6.037056,
   4.94332,
   3.732312,
   2.703576,
   1.869605,
   1.241296,
   1.034004,
   0.3195471,
   0.5015367,
   0.3406474,
   0.3279573,
   0.1360189};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3015,h_dh_down2_fy3015,h_dh_down2_felx3015,h_dh_down2_fehx3015,h_dh_down2_fely3015,h_dh_down2_fehy3015);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23015 = new TH1F("Graph_h_dh_down23015","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23015->SetMinimum(0);
   Graph_h_dh_down23015->SetMaximum(205.6913);
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
   
   Double_t down_fx15[59] = {
   0.1721884,
   0.1972987,
   0.2224089,
   0.2475191,
   0.2726293,
   0.2977395,
   0.3228497,
   0.34796,
   0.3730702,
   0.3981804,
   0.4232906,
   0.4484008,
   0.4735111,
   0.4986213,
   0.5237315,
   0.5739519,
   0.5990622,
   0.6241724,
   0.6492826,
   0.6743928,
   0.699503,
   0.7120581,
   0.7246132,
   0.7371684,
   0.7497235,
   0.7622786,
   0.7748337,
   0.7873888,
   0.7999439,
   0.812499,
   0.8250541,
   0.8376092,
   0.8501643,
   0.8627194,
   0.8752746,
   0.8878297,
   0.9003848,
   0.9129399,
   0.925495,
   0.9506052,
   0.9757154,
   1.000826,
   1.025936,
   1.076156,
   1.101267,
   1.126377,
   1.151487,
   1.176597,
   1.201707,
   1.226818,
   1.251928,
   1.264483,
   1.277038,
   1.302148,
   1.327258,
   1.352369,
   1.377479,
   1.427699,
   1.427699};
   Double_t down_fy15[59] = {
   6.177005,
   8.036006,
   10.34375,
   13.17318,
   16.59889,
   20.69391,
   25.52592,
   31.1527,
   37.61709,
   44.94176,
   53.12394,
   62.13064,
   71.89467,
   82.31196,
   93.24047,
   115.8813,
   127.1397,
   138.0142,
   148.232,
   157.52,
   165.6168,
   169.1432,
   172.2855,
   175.0195,
   177.3242,
   179.1817,
   180.5772,
   181.4998,
   181.9421,
   181.9005,
   181.3755,
   180.3712,
   178.8955,
   176.9602,
   174.5804,
   171.7748,
   168.5649,
   164.9752,
   161.0326,
   152.2075,
   142.3421,
   131.7062,
   120.5742,
   97.8761,
   86.78622,
   76.13779,
   66.08837,
   56.75774,
   48.22815,
   40.54631,
   33.72698,
   30.6402,
   27.91221,
   23.53029,
   20.18472,
   17.56226,
   15.46165,
   12.32923,
   12.32923};
   graph = new TGraph(59,down_fx15,down_fy15);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down15 = new TH1F("Graph_down15","Projection of downf DSCB fit",100,0.04663734,1.55325);
   Graph_down15->SetMinimum(5.559305);
   Graph_down15->SetMaximum(199.5186);
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
   
   TH1D *frame_4115be50__58 = new TH1D("frame_4115be50__58","p_T Balance",25,0,2);
   frame_4115be50__58->SetBinContent(1,196.3417);
   frame_4115be50__58->SetMaximum(196.3417);
   frame_4115be50__58->SetEntries(1);
   frame_4115be50__58->SetDirectory(0);
   frame_4115be50__58->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4115be50__58->SetLineColor(ci);
   frame_4115be50__58->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4115be50__58->GetXaxis()->SetLabelFont(42);
   frame_4115be50__58->GetXaxis()->SetTitleOffset(1);
   frame_4115be50__58->GetXaxis()->SetTitleFont(42);
   frame_4115be50__58->GetYaxis()->SetTitle("1/Events");
   frame_4115be50__58->GetYaxis()->SetLabelFont(42);
   frame_4115be50__58->GetYaxis()->SetTitleFont(42);
   frame_4115be50__58->GetZaxis()->SetLabelFont(42);
   frame_4115be50__58->GetZaxis()->SetTitleOffset(1);
   frame_4115be50__58->GetZaxis()->SetTitleFont(42);
   frame_4115be50__58->Draw("AXISSAME");
   
   TH1D *norm_d__59 = new TH1D("norm_d__59","",25,0,2);
   norm_d__59->SetBinContent(3,5.503276);
   norm_d__59->SetBinContent(4,20.05727);
   norm_d__59->SetBinContent(5,36.15108);
   norm_d__59->SetBinContent(6,59.16957);
   norm_d__59->SetBinContent(7,85.03493);
   norm_d__59->SetBinContent(8,124.0623);
   norm_d__59->SetBinContent(9,170.6387);
   norm_d__59->SetBinContent(10,177.3275);
   norm_d__59->SetBinContent(11,178.2712);
   norm_d__59->SetBinContent(12,162.523);
   norm_d__59->SetBinContent(13,133.2121);
   norm_d__59->SetBinContent(14,92.88693);
   norm_d__59->SetBinContent(15,64.18689);
   norm_d__59->SetBinContent(16,37.02882);
   norm_d__59->SetBinContent(17,22.22657);
   norm_d__59->SetBinContent(18,11.00969);
   norm_d__59->SetBinContent(19,6.528823);
   norm_d__59->SetBinContent(20,3.472511);
   norm_d__59->SetBinContent(21,0.7876202);
   norm_d__59->SetBinContent(22,1.101521);
   norm_d__59->SetBinContent(23,0.7811043);
   norm_d__59->SetBinContent(24,0.5923142);
   norm_d__59->SetBinContent(25,0.3730121);
   norm_d__59->SetBinContent(26,0.8796988);
   norm_d__59->SetBinError(3,1.17253);
   norm_d__59->SetBinError(4,2.517173);
   norm_d__59->SetBinError(5,3.748179);
   norm_d__59->SetBinError(6,5.241822);
   norm_d__59->SetBinError(7,5.843052);
   norm_d__59->SetBinError(8,7.342111);
   norm_d__59->SetBinError(9,8.742002);
   norm_d__59->SetBinError(10,8.736566);
   norm_d__59->SetBinError(11,8.720948);
   norm_d__59->SetBinError(12,8.24217);
   norm_d__59->SetBinError(13,7.519126);
   norm_d__59->SetBinError(14,6.037056);
   norm_d__59->SetBinError(15,4.94332);
   norm_d__59->SetBinError(16,3.732312);
   norm_d__59->SetBinError(17,2.703576);
   norm_d__59->SetBinError(18,1.869605);
   norm_d__59->SetBinError(19,1.241296);
   norm_d__59->SetBinError(20,1.034004);
   norm_d__59->SetBinError(21,0.3195471);
   norm_d__59->SetBinError(22,0.5015367);
   norm_d__59->SetBinError(23,0.3406474);
   norm_d__59->SetBinError(24,0.3279573);
   norm_d__59->SetBinError(25,0.1360189);
   norm_d__59->SetBinError(26,0.2537481);
   norm_d__59->SetEntries(6630);
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
   entry=leg->AddEntry("frame_x_d2_4115be50","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.805145 #pm 0.006921","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.243334 #pm 0.005826","");
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
   
   TH1D *frame_4115be50_copy__60 = new TH1D("frame_4115be50_copy__60","p_T Balance",25,0,2);
   frame_4115be50_copy__60->SetBinContent(1,196.3417);
   frame_4115be50_copy__60->SetMaximum(196.3417);
   frame_4115be50_copy__60->SetEntries(1);
   frame_4115be50_copy__60->SetDirectory(0);
   frame_4115be50_copy__60->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4115be50_copy__60->SetLineColor(ci);
   frame_4115be50_copy__60->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4115be50_copy__60->GetXaxis()->SetLabelFont(42);
   frame_4115be50_copy__60->GetXaxis()->SetTitleOffset(1);
   frame_4115be50_copy__60->GetXaxis()->SetTitleFont(42);
   frame_4115be50_copy__60->GetYaxis()->SetTitle("1/Events");
   frame_4115be50_copy__60->GetYaxis()->SetLabelFont(42);
   frame_4115be50_copy__60->GetYaxis()->SetTitleFont(42);
   frame_4115be50_copy__60->GetZaxis()->SetLabelFont(42);
   frame_4115be50_copy__60->GetZaxis()->SetTitleOffset(1);
   frame_4115be50_copy__60->GetZaxis()->SetTitleFont(42);
   frame_4115be50_copy__60->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-23.38636,2.25,210.4773);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_4119a520__61 = new TH1D("frame_4119a520__61","p_T Balance",25,0,2);
   frame_4119a520__61->SetBinContent(1,205.8);
   frame_4119a520__61->SetMaximum(205.8);
   frame_4119a520__61->SetEntries(1);
   frame_4119a520__61->SetDirectory(0);
   frame_4119a520__61->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4119a520__61->SetLineColor(ci);
   frame_4119a520__61->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4119a520__61->GetXaxis()->SetLabelFont(42);
   frame_4119a520__61->GetXaxis()->SetTitleOffset(1);
   frame_4119a520__61->GetXaxis()->SetTitleFont(42);
   frame_4119a520__61->GetYaxis()->SetTitle("1/Events");
   frame_4119a520__61->GetYaxis()->SetLabelFont(42);
   frame_4119a520__61->GetYaxis()->SetTitleFont(42);
   frame_4119a520__61->GetZaxis()->SetLabelFont(42);
   frame_4119a520__61->GetZaxis()->SetTitleOffset(1);
   frame_4119a520__61->GetZaxis()->SetTitleFont(42);
   frame_4119a520__61->Draw("FUNC");
   
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
   8,
   35,
   57,
   65,
   102,
   129,
   177,
   182,
   172,
   158,
   134,
   88,
   61,
   34,
   28,
   12,
   8,
   6,
   0,
   0,
   1,
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
   2.768386,
   5.887675,
   7.527619,
   8.041463,
   9.611874,
   10.86882,
   12.81353,
   13,
   12.6244,
   12.07975,
   11.08663,
   9.362975,
   7.788779,
   5.802128,
   5.259711,
   3.415266,
   2.768386,
   2.379931,
   0,
   0,
   0.8272462,
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
   3.945142,
   6.97241,
   8.594007,
   9.103628,
   10.61187,
   11.86882,
   13.81353,
   14,
   13.6244,
   13.07975,
   12.08663,
   10.41639,
   8.852952,
   6.888101,
   6.354446,
   4.559819,
   3.945142,
   3.583642,
   1.147874,
   1.147874,
   2.299527,
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
   Graph_h_dh_data23016->SetMaximum(215.6);
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
   
   Double_t observation_fx16[54] = {
   0.1995716,
   0.2475588,
   0.2715524,
   0.2955461,
   0.3195397,
   0.3435333,
   0.3675269,
   0.3915205,
   0.4155141,
   0.4395077,
   0.4635013,
   0.487495,
   0.5354822,
   0.5834694,
   0.607463,
   0.6314566,
   0.6554502,
   0.6794438,
   0.7034375,
   0.7154343,
   0.7274311,
   0.7394279,
   0.7514247,
   0.7634215,
   0.7754183,
   0.7874151,
   0.7994119,
   0.8114087,
   0.8234055,
   0.8354023,
   0.8473991,
   0.8593959,
   0.8713927,
   0.8953864,
   0.91938,
   0.9433736,
   0.9673672,
   0.9913608,
   1.015354,
   1.063342,
   1.111329,
   1.135322,
   1.159316,
   1.18331,
   1.207303,
   1.231297,
   1.255291,
   1.279284,
   1.303278,
   1.327271,
   1.351265,
   1.375259,
   1.399252,
   1.399252};
   Double_t observation_fy16[54] = {
   22.86101,
   27.9939,
   31.1013,
   34.65221,
   38.7248,
   43.41383,
   48.83478,
   55.12912,
   62.47134,
   71.07246,
   80.55619,
   90.48938,
   111.1471,
   131.7052,
   141.4513,
   150.5608,
   158.8246,
   166.0447,
   172.0415,
   174.5321,
   176.6617,
   178.4165,
   179.7847,
   180.7573,
   181.3277,
   181.4921,
   181.2494,
   180.6013,
   179.552,
   178.1086,
   176.2807,
   174.0804,
   171.5222,
   165.4006,
   158.072,
   149.7179,
   140.5379,
   130.7418,
   120.5415,
   99.74328,
   79.62237,
   70.18792,
   61.31839,
   53.09091,
   45.55653,
   38.74201,
   32.65238,
   27.27398,
   22.57788,
   18.52333,
   15.06107,
   12.13651,
   9.692431,
   9.692431};
   graph = new TGraph(54,observation_fx16,observation_fy16);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation16 = new TH1F("Graph_observation16","Projection of obsf DSCB fit",100,0.07960356,1.51922);
   Graph_observation16->SetMinimum(8.723188);
   Graph_observation16->SetMaximum(198.6721);
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
   
   TH1D *frame_4119a520__62 = new TH1D("frame_4119a520__62","p_T Balance",25,0,2);
   frame_4119a520__62->SetBinContent(1,205.8);
   frame_4119a520__62->SetMaximum(205.8);
   frame_4119a520__62->SetEntries(1);
   frame_4119a520__62->SetDirectory(0);
   frame_4119a520__62->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4119a520__62->SetLineColor(ci);
   frame_4119a520__62->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4119a520__62->GetXaxis()->SetLabelFont(42);
   frame_4119a520__62->GetXaxis()->SetTitleOffset(1);
   frame_4119a520__62->GetXaxis()->SetTitleFont(42);
   frame_4119a520__62->GetYaxis()->SetTitle("1/Events");
   frame_4119a520__62->GetYaxis()->SetLabelFont(42);
   frame_4119a520__62->GetYaxis()->SetTitleFont(42);
   frame_4119a520__62->GetZaxis()->SetLabelFont(42);
   frame_4119a520__62->GetZaxis()->SetTitleOffset(1);
   frame_4119a520__62->GetZaxis()->SetTitleFont(42);
   frame_4119a520__62->Draw("AXISSAME");
   
   TH1D *norm_o__63 = new TH1D("norm_o__63","",25,0,2);
   norm_o__63->SetBinContent(3,8);
   norm_o__63->SetBinContent(4,35);
   norm_o__63->SetBinContent(5,57);
   norm_o__63->SetBinContent(6,65);
   norm_o__63->SetBinContent(7,102);
   norm_o__63->SetBinContent(8,129);
   norm_o__63->SetBinContent(9,177);
   norm_o__63->SetBinContent(10,182);
   norm_o__63->SetBinContent(11,172);
   norm_o__63->SetBinContent(12,158);
   norm_o__63->SetBinContent(13,134);
   norm_o__63->SetBinContent(14,88);
   norm_o__63->SetBinContent(15,61);
   norm_o__63->SetBinContent(16,34);
   norm_o__63->SetBinContent(17,28);
   norm_o__63->SetBinContent(18,12);
   norm_o__63->SetBinContent(19,8);
   norm_o__63->SetBinContent(20,6);
   norm_o__63->SetBinContent(23,1);
   norm_o__63->SetBinContent(26,5);
   norm_o__63->SetMinimum(0);
   norm_o__63->SetMaximum(400.4);
   norm_o__63->SetEntries(1462);
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
   entry=leg->AddEntry("frame_x_o2_4119a520","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.791484 #pm 0.007574","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.248252 #pm 0.007154","");
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
   
   TH1D *frame_4119a520_copy__64 = new TH1D("frame_4119a520_copy__64","p_T Balance",25,0,2);
   frame_4119a520_copy__64->SetBinContent(1,205.8);
   frame_4119a520_copy__64->SetMaximum(205.8);
   frame_4119a520_copy__64->SetEntries(1);
   frame_4119a520_copy__64->SetDirectory(0);
   frame_4119a520_copy__64->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4119a520_copy__64->SetLineColor(ci);
   frame_4119a520_copy__64->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4119a520_copy__64->GetXaxis()->SetLabelFont(42);
   frame_4119a520_copy__64->GetXaxis()->SetTitleOffset(1);
   frame_4119a520_copy__64->GetXaxis()->SetTitleFont(42);
   frame_4119a520_copy__64->GetYaxis()->SetTitle("1/Events");
   frame_4119a520_copy__64->GetYaxis()->SetLabelFont(42);
   frame_4119a520_copy__64->GetYaxis()->SetTitleFont(42);
   frame_4119a520_copy__64->GetZaxis()->SetLabelFont(42);
   frame_4119a520_copy__64->GetZaxis()->SetTitleOffset(1);
   frame_4119a520_copy__64->GetZaxis()->SetTitleFont(42);
   frame_4119a520_copy__64->Draw("sameaxis");
   
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
