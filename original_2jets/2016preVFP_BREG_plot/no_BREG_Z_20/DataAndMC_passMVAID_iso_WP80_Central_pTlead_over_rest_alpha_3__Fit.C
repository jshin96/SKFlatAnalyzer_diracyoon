void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_3__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 16:37:29 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-8.886243,2.25,66.88793);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3ad8f630__33 = new TH1D("frame_3ad8f630__33","p_T Balance",25,0,2);
   frame_3ad8f630__33->SetBinContent(1,59.31051);
   frame_3ad8f630__33->SetMinimum(-2.82431);
   frame_3ad8f630__33->SetMaximum(59.31051);
   frame_3ad8f630__33->SetEntries(1);
   frame_3ad8f630__33->SetDirectory(0);
   frame_3ad8f630__33->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_3ad8f630__33->SetLineColor(ci);
   frame_3ad8f630__33->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ad8f630__33->GetXaxis()->SetLabelFont(42);
   frame_3ad8f630__33->GetXaxis()->SetTitleOffset(1);
   frame_3ad8f630__33->GetXaxis()->SetTitleFont(42);
   frame_3ad8f630__33->GetYaxis()->SetTitle("1/Events");
   frame_3ad8f630__33->GetYaxis()->SetLabelFont(42);
   frame_3ad8f630__33->GetYaxis()->SetTitleFont(42);
   frame_3ad8f630__33->GetZaxis()->SetLabelFont(42);
   frame_3ad8f630__33->GetZaxis()->SetTitleOffset(1);
   frame_3ad8f630__33->GetZaxis()->SetTitleFont(42);
   frame_3ad8f630__33->Draw("FUNC");
   
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
   2.400888,
   3.652296,
   6.906003,
   10.45637,
   12.73821,
   23.75189,
   36.57808,
   44.82245,
   52.03559,
   46.54906,
   33.33252,
   28.36677,
   16.36718,
   8.543283,
   4.52423,
   3.256536,
   1.080139,
   0.5242944,
   0.6693558,
   0.04134189,
   0,
   0,
   0.1893215};
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
   0.836973,
   1.016954,
   1.723286,
   1.95122,
   2.019468,
   2.984274,
   3.752899,
   4.202856,
   4.450604,
   4.101349,
   3.548794,
   3.258679,
   2.281837,
   1.665598,
   1.138395,
   0.8592376,
   0.479508,
   0.2767166,
   0.3358187,
   0.04134189,
   0,
   0,
   0.1893215};
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
   0.836973,
   1.016954,
   1.723286,
   1.95122,
   2.019468,
   2.984274,
   3.752899,
   4.202856,
   4.450604,
   4.101349,
   3.548794,
   3.258679,
   2.281837,
   1.665598,
   1.138395,
   0.8592376,
   0.479508,
   0.2767166,
   0.3358187,
   0.04134189,
   0,
   0,
   0.1893215};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3009,h_dh_central2_fy3009,h_dh_central2_felx3009,h_dh_central2_fehx3009,h_dh_central2_fely3009,h_dh_central2_fehy3009);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23009 = new TH1F("Graph_h_dh_central23009","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23009->SetMinimum(-5.64862);
   Graph_h_dh_central23009->SetMaximum(62.13482);
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
   
   Double_t Central_fx9[58] = {
   0.3090168,
   0.3517869,
   0.394557,
   0.415942,
   0.437327,
   0.4587121,
   0.4800971,
   0.5014821,
   0.5228672,
   0.5442522,
   0.5549447,
   0.5656372,
   0.5870223,
   0.6084073,
   0.6511774,
   0.6725624,
   0.6939474,
   0.7153325,
   0.7367175,
   0.7581025,
   0.768795,
   0.7794875,
   0.7901801,
   0.8008726,
   0.8115651,
   0.8222576,
   0.8329501,
   0.8436426,
   0.8543352,
   0.8650277,
   0.8757202,
   0.8864127,
   0.8971052,
   0.9077977,
   0.9184903,
   0.9291828,
   0.9398753,
   0.9505678,
   0.9719528,
   0.9933379,
   1.014723,
   1.036108,
   1.078878,
   1.100263,
   1.121648,
   1.143033,
   1.164418,
   1.185803,
   1.207188,
   1.228573,
   1.249958,
   1.271343,
   1.292728,
   1.314113,
   1.335498,
   1.356883,
   1.378268,
   1.378268};
   Double_t Central_fy9[58] = {
   5.013859,
   6.098098,
   7.491919,
   8.338329,
   9.307717,
   10.42216,
   11.70851,
   13.19958,
   14.93575,
   16.967,
   18.11216,
   19.35559,
   22.13568,
   25.09326,
   31.23433,
   34.29597,
   37.25944,
   40.05085,
   42.59605,
   44.82385,
   45.7981,
   46.6693,
   47.43082,
   48.0768,
   48.60222,
   49.00294,
   49.27581,
   49.41866,
   49.43035,
   49.31079,
   49.06093,
   48.68276,
   48.17927,
   47.5544,
   46.81303,
   45.96089,
   45.00447,
   43.95096,
   41.58441,
   38.92916,
   36.058,
   33.04536,
   26.88283,
   23.8633,
   20.95889,
   18.21329,
   15.65996,
   13.32218,
   11.21352,
   9.338797,
   7.69524,
   6.273871,
   5.060941,
   4.039329,
   3.189843,
   2.492365,
   1.926799,
   1.926799};
   TGraph *graph = new TGraph(58,Central_fx9,Central_fy9);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central9 = new TH1F("Graph_Central9","Projection of centralf DSCB fit",100,0.2020917,1.485194);
   Graph_Central9->SetMinimum(1.734119);
   Graph_Central9->SetMaximum(54.1807);
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
   
   TH1D *frame_3ad8f630__34 = new TH1D("frame_3ad8f630__34","p_T Balance",25,0,2);
   frame_3ad8f630__34->SetBinContent(1,59.31051);
   frame_3ad8f630__34->SetMinimum(-2.82431);
   frame_3ad8f630__34->SetMaximum(59.31051);
   frame_3ad8f630__34->SetEntries(1);
   frame_3ad8f630__34->SetDirectory(0);
   frame_3ad8f630__34->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3ad8f630__34->SetLineColor(ci);
   frame_3ad8f630__34->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ad8f630__34->GetXaxis()->SetLabelFont(42);
   frame_3ad8f630__34->GetXaxis()->SetTitleOffset(1);
   frame_3ad8f630__34->GetXaxis()->SetTitleFont(42);
   frame_3ad8f630__34->GetYaxis()->SetTitle("1/Events");
   frame_3ad8f630__34->GetYaxis()->SetLabelFont(42);
   frame_3ad8f630__34->GetYaxis()->SetTitleFont(42);
   frame_3ad8f630__34->GetZaxis()->SetLabelFont(42);
   frame_3ad8f630__34->GetZaxis()->SetTitleOffset(1);
   frame_3ad8f630__34->GetZaxis()->SetTitleFont(42);
   frame_3ad8f630__34->Draw("AXISSAME");
   
   TH1D *norm_c__35 = new TH1D("norm_c__35","",25,0,2);
   norm_c__35->SetBinContent(3,2.400888);
   norm_c__35->SetBinContent(4,3.652296);
   norm_c__35->SetBinContent(5,6.906003);
   norm_c__35->SetBinContent(6,10.45637);
   norm_c__35->SetBinContent(7,12.73821);
   norm_c__35->SetBinContent(8,23.75189);
   norm_c__35->SetBinContent(9,36.57808);
   norm_c__35->SetBinContent(10,44.82245);
   norm_c__35->SetBinContent(11,52.0356);
   norm_c__35->SetBinContent(12,46.54906);
   norm_c__35->SetBinContent(13,33.33252);
   norm_c__35->SetBinContent(14,28.36677);
   norm_c__35->SetBinContent(15,16.36718);
   norm_c__35->SetBinContent(16,8.543282);
   norm_c__35->SetBinContent(17,4.52423);
   norm_c__35->SetBinContent(18,3.256536);
   norm_c__35->SetBinContent(19,1.080139);
   norm_c__35->SetBinContent(20,0.5242944);
   norm_c__35->SetBinContent(21,0.6693558);
   norm_c__35->SetBinContent(22,0.04134189);
   norm_c__35->SetBinContent(25,0.1893215);
   norm_c__35->SetBinContent(26,0.03109237);
   norm_c__35->SetBinError(3,0.836973);
   norm_c__35->SetBinError(4,1.016954);
   norm_c__35->SetBinError(5,1.723286);
   norm_c__35->SetBinError(6,1.95122);
   norm_c__35->SetBinError(7,2.019468);
   norm_c__35->SetBinError(8,2.984274);
   norm_c__35->SetBinError(9,3.752899);
   norm_c__35->SetBinError(10,4.202856);
   norm_c__35->SetBinError(11,4.450604);
   norm_c__35->SetBinError(12,4.101349);
   norm_c__35->SetBinError(13,3.548794);
   norm_c__35->SetBinError(14,3.258679);
   norm_c__35->SetBinError(15,2.281837);
   norm_c__35->SetBinError(16,1.665598);
   norm_c__35->SetBinError(17,1.138395);
   norm_c__35->SetBinError(18,0.8592376);
   norm_c__35->SetBinError(19,0.479508);
   norm_c__35->SetBinError(20,0.2767166);
   norm_c__35->SetBinError(21,0.3358187);
   norm_c__35->SetBinError(22,0.04134189);
   norm_c__35->SetBinError(25,0.1893215);
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
   entry=leg->AddEntry("frame_x_c2_3ad8f630","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.839499 #pm 0.012816","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.219036 #pm 0.010796","");
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
   
   TH1D *frame_3ad8f630_copy__36 = new TH1D("frame_3ad8f630_copy__36","p_T Balance",25,0,2);
   frame_3ad8f630_copy__36->SetBinContent(1,59.31051);
   frame_3ad8f630_copy__36->SetMinimum(-2.82431);
   frame_3ad8f630_copy__36->SetMaximum(59.31051);
   frame_3ad8f630_copy__36->SetEntries(1);
   frame_3ad8f630_copy__36->SetDirectory(0);
   frame_3ad8f630_copy__36->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3ad8f630_copy__36->SetLineColor(ci);
   frame_3ad8f630_copy__36->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ad8f630_copy__36->GetXaxis()->SetLabelFont(42);
   frame_3ad8f630_copy__36->GetXaxis()->SetTitleOffset(1);
   frame_3ad8f630_copy__36->GetXaxis()->SetTitleFont(42);
   frame_3ad8f630_copy__36->GetYaxis()->SetTitle("1/Events");
   frame_3ad8f630_copy__36->GetYaxis()->SetLabelFont(42);
   frame_3ad8f630_copy__36->GetYaxis()->SetTitleFont(42);
   frame_3ad8f630_copy__36->GetZaxis()->SetLabelFont(42);
   frame_3ad8f630_copy__36->GetZaxis()->SetTitleOffset(1);
   frame_3ad8f630_copy__36->GetZaxis()->SetTitleFont(42);
   frame_3ad8f630_copy__36->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-8.831201,2.25,66.47362);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3adb4d90__37 = new TH1D("frame_3adb4d90__37","p_T Balance",25,0,2);
   frame_3adb4d90__37->SetBinContent(1,58.94313);
   frame_3adb4d90__37->SetMinimum(-2.806816);
   frame_3adb4d90__37->SetMaximum(58.94313);
   frame_3adb4d90__37->SetEntries(1);
   frame_3adb4d90__37->SetDirectory(0);
   frame_3adb4d90__37->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3adb4d90__37->SetLineColor(ci);
   frame_3adb4d90__37->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3adb4d90__37->GetXaxis()->SetLabelFont(42);
   frame_3adb4d90__37->GetXaxis()->SetTitleOffset(1);
   frame_3adb4d90__37->GetXaxis()->SetTitleFont(42);
   frame_3adb4d90__37->GetYaxis()->SetTitle("1/Events");
   frame_3adb4d90__37->GetYaxis()->SetLabelFont(42);
   frame_3adb4d90__37->GetYaxis()->SetTitleFont(42);
   frame_3adb4d90__37->GetZaxis()->SetLabelFont(42);
   frame_3adb4d90__37->GetZaxis()->SetTitleOffset(1);
   frame_3adb4d90__37->GetZaxis()->SetTitleFont(42);
   frame_3adb4d90__37->Draw("FUNC");
   
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
   1.388999,
   4.771066,
   5.897974,
   7.300838,
   12.24331,
   21.44012,
   33.66265,
   42.17284,
   51.73978,
   50.72947,
   37.98218,
   30.86644,
   19.18567,
   8.086759,
   5.356148,
   4.16622,
   1.008132,
   0.811682,
   0.3871284,
   0.2226947,
   0.04124406,
   0.03736381,
   0.1883879};
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
   0.5893226,
   1.172728,
   1.632365,
   1.624153,
   2.04901,
   2.79824,
   3.544793,
   4.011094,
   4.396541,
   4.381633,
   3.865978,
   3.442894,
   2.530137,
   1.560549,
   1.311436,
   1.093918,
   0.4517853,
   0.4099134,
   0.2099589,
   0.2226947,
   0.04124406,
   0.03736381,
   0.1883879};
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
   0.5893226,
   1.172728,
   1.632365,
   1.624153,
   2.04901,
   2.79824,
   3.544793,
   4.011094,
   4.396541,
   4.381633,
   3.865978,
   3.442894,
   2.530137,
   1.560549,
   1.311436,
   1.093918,
   0.4517853,
   0.4099134,
   0.2099589,
   0.2226947,
   0.04124406,
   0.03736381,
   0.1883879};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3010,h_dh_up2_fy3010,h_dh_up2_felx3010,h_dh_up2_fehx3010,h_dh_up2_fely3010,h_dh_up2_fehy3010);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23010 = new TH1F("Graph_h_dh_up23010","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23010->SetMinimum(-5.613632);
   Graph_h_dh_up23010->SetMaximum(61.74995);
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
   0.3143444,
   0.3583058,
   0.4022673,
   0.424248,
   0.4462287,
   0.4682094,
   0.4901901,
   0.5121708,
   0.5341515,
   0.5451419,
   0.5561322,
   0.5671226,
   0.5781129,
   0.6000936,
   0.6220743,
   0.6660357,
   0.7099971,
   0.7319779,
   0.7539586,
   0.7649489,
   0.7759393,
   0.7869296,
   0.79792,
   0.8089103,
   0.8199007,
   0.830891,
   0.8418814,
   0.8528717,
   0.8638621,
   0.8748524,
   0.8858428,
   0.8968331,
   0.9078235,
   0.9188139,
   0.9298042,
   0.9407946,
   0.9517849,
   0.9627753,
   0.9737656,
   0.9957463,
   1.017727,
   1.039708,
   1.061688,
   1.10565,
   1.127631,
   1.149611,
   1.171592,
   1.193573,
   1.215553,
   1.237534,
   1.259515,
   1.270505,
   1.276,
   1.281496,
   1.303476,
   1.325457,
   1.369418,
   1.41338,
   1.41338};
   Double_t up_fy10[59] = {
   4.381916,
   5.275715,
   6.450226,
   7.179427,
   8.030659,
   9.031646,
   10.21825,
   11.63744,
   13.35166,
   14.34466,
   15.44521,
   16.66883,
   18.0326,
   20.99696,
   24.15709,
   30.84552,
   37.54056,
   40.6762,
   43.54821,
   44.85715,
   46.06706,
   47.16795,
   48.15052,
   49.00638,
   49.72809,
   50.30932,
   50.74494,
   51.03106,
   51.16512,
   51.14592,
   50.97363,
   50.64979,
   50.17731,
   49.56038,
   48.80445,
   47.91614,
   46.90313,
   45.77405,
   44.53838,
   41.78855,
   38.74096,
   35.48737,
   32.1194,
   25.38199,
   22.16104,
   19.11811,
   16.29633,
   13.7254,
   11.42222,
   9.392182,
   7.630844,
   6.847341,
   6.491412,
   6.294256,
   5.974031,
   5.826647,
   5.660035,
   5.55773,
   5.55773};
   graph = new TGraph(59,up_fx10,up_fy10);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up10 = new TH1F("Graph_up10","Projection of upf DSCB fit",100,0.2044409,1.523283);
   Graph_up10->SetMinimum(3.943724);
   Graph_up10->SetMaximum(55.84344);
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
   
   TH1D *frame_3adb4d90__38 = new TH1D("frame_3adb4d90__38","p_T Balance",25,0,2);
   frame_3adb4d90__38->SetBinContent(1,58.94313);
   frame_3adb4d90__38->SetMinimum(-2.806816);
   frame_3adb4d90__38->SetMaximum(58.94313);
   frame_3adb4d90__38->SetEntries(1);
   frame_3adb4d90__38->SetDirectory(0);
   frame_3adb4d90__38->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3adb4d90__38->SetLineColor(ci);
   frame_3adb4d90__38->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3adb4d90__38->GetXaxis()->SetLabelFont(42);
   frame_3adb4d90__38->GetXaxis()->SetTitleOffset(1);
   frame_3adb4d90__38->GetXaxis()->SetTitleFont(42);
   frame_3adb4d90__38->GetYaxis()->SetTitle("1/Events");
   frame_3adb4d90__38->GetYaxis()->SetLabelFont(42);
   frame_3adb4d90__38->GetYaxis()->SetTitleFont(42);
   frame_3adb4d90__38->GetZaxis()->SetLabelFont(42);
   frame_3adb4d90__38->GetZaxis()->SetTitleOffset(1);
   frame_3adb4d90__38->GetZaxis()->SetTitleFont(42);
   frame_3adb4d90__38->Draw("AXISSAME");
   
   TH1D *norm_u__39 = new TH1D("norm_u__39","",25,0,2);
   norm_u__39->SetBinContent(3,1.388999);
   norm_u__39->SetBinContent(4,4.771066);
   norm_u__39->SetBinContent(5,5.897974);
   norm_u__39->SetBinContent(6,7.300838);
   norm_u__39->SetBinContent(7,12.24331);
   norm_u__39->SetBinContent(8,21.44012);
   norm_u__39->SetBinContent(9,33.66265);
   norm_u__39->SetBinContent(10,42.17285);
   norm_u__39->SetBinContent(11,51.73978);
   norm_u__39->SetBinContent(12,50.72946);
   norm_u__39->SetBinContent(13,37.98218);
   norm_u__39->SetBinContent(14,30.86644);
   norm_u__39->SetBinContent(15,19.18567);
   norm_u__39->SetBinContent(16,8.086759);
   norm_u__39->SetBinContent(17,5.356148);
   norm_u__39->SetBinContent(18,4.16622);
   norm_u__39->SetBinContent(19,1.008132);
   norm_u__39->SetBinContent(20,0.8116821);
   norm_u__39->SetBinContent(21,0.3871283);
   norm_u__39->SetBinContent(22,0.2226947);
   norm_u__39->SetBinContent(23,0.04124406);
   norm_u__39->SetBinContent(24,0.03736381);
   norm_u__39->SetBinContent(25,0.1883879);
   norm_u__39->SetBinContent(26,0.03103104);
   norm_u__39->SetBinError(3,0.5893226);
   norm_u__39->SetBinError(4,1.172728);
   norm_u__39->SetBinError(5,1.632365);
   norm_u__39->SetBinError(6,1.624153);
   norm_u__39->SetBinError(7,2.04901);
   norm_u__39->SetBinError(8,2.79824);
   norm_u__39->SetBinError(9,3.544793);
   norm_u__39->SetBinError(10,4.011094);
   norm_u__39->SetBinError(11,4.396541);
   norm_u__39->SetBinError(12,4.381633);
   norm_u__39->SetBinError(13,3.865978);
   norm_u__39->SetBinError(14,3.442894);
   norm_u__39->SetBinError(15,2.530137);
   norm_u__39->SetBinError(16,1.560549);
   norm_u__39->SetBinError(17,1.311436);
   norm_u__39->SetBinError(18,1.093918);
   norm_u__39->SetBinError(19,0.4517853);
   norm_u__39->SetBinError(20,0.4099134);
   norm_u__39->SetBinError(21,0.2099589);
   norm_u__39->SetBinError(22,0.2226947);
   norm_u__39->SetBinError(23,0.04124406);
   norm_u__39->SetBinError(24,0.03736381);
   norm_u__39->SetBinError(25,0.1883879);
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
   entry=leg->AddEntry("frame_x_u2_3adb4d90","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.870980 #pm 0.012826","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.214927 #pm 0.011283","");
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
   
   TH1D *frame_3adb4d90_copy__40 = new TH1D("frame_3adb4d90_copy__40","p_T Balance",25,0,2);
   frame_3adb4d90_copy__40->SetBinContent(1,58.94313);
   frame_3adb4d90_copy__40->SetMinimum(-2.806816);
   frame_3adb4d90_copy__40->SetMaximum(58.94313);
   frame_3adb4d90_copy__40->SetEntries(1);
   frame_3adb4d90_copy__40->SetDirectory(0);
   frame_3adb4d90_copy__40->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3adb4d90_copy__40->SetLineColor(ci);
   frame_3adb4d90_copy__40->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3adb4d90_copy__40->GetXaxis()->SetLabelFont(42);
   frame_3adb4d90_copy__40->GetXaxis()->SetTitleOffset(1);
   frame_3adb4d90_copy__40->GetXaxis()->SetTitleFont(42);
   frame_3adb4d90_copy__40->GetYaxis()->SetTitle("1/Events");
   frame_3adb4d90_copy__40->GetYaxis()->SetLabelFont(42);
   frame_3adb4d90_copy__40->GetYaxis()->SetTitleFont(42);
   frame_3adb4d90_copy__40->GetZaxis()->SetLabelFont(42);
   frame_3adb4d90_copy__40->GetZaxis()->SetTitleOffset(1);
   frame_3adb4d90_copy__40->GetZaxis()->SetTitleFont(42);
   frame_3adb4d90_copy__40->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-6.939447,2.25,62.45502);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3ada29c0__41 = new TH1D("frame_3ada29c0__41","p_T Balance",25,0,2);
   frame_3ada29c0__41->SetBinContent(1,61.06713);
   frame_3ada29c0__41->SetMaximum(61.06713);
   frame_3ada29c0__41->SetEntries(1);
   frame_3ada29c0__41->SetDirectory(0);
   frame_3ada29c0__41->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3ada29c0__41->SetLineColor(ci);
   frame_3ada29c0__41->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ada29c0__41->GetXaxis()->SetLabelFont(42);
   frame_3ada29c0__41->GetXaxis()->SetTitleOffset(1);
   frame_3ada29c0__41->GetXaxis()->SetTitleFont(42);
   frame_3ada29c0__41->GetYaxis()->SetTitle("1/Events");
   frame_3ada29c0__41->GetYaxis()->SetLabelFont(42);
   frame_3ada29c0__41->GetYaxis()->SetTitleFont(42);
   frame_3ada29c0__41->GetZaxis()->SetLabelFont(42);
   frame_3ada29c0__41->GetZaxis()->SetTitleOffset(1);
   frame_3ada29c0__41->GetZaxis()->SetTitleFont(42);
   frame_3ada29c0__41->Draw("FUNC");
   
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
   2.382584,
   3.412412,
   10.20232,
   11.47058,
   14.80575,
   22.11031,
   36.4079,
   48.10667,
   53.63231,
   43.93976,
   31.01952,
   23.74387,
   13.16101,
   7.329723,
   4.880489,
   2.937299,
   1.268361,
   0.2851279,
   0.4591143,
   0.04155787,
   0,
   0,
   0.190867};
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
   0.7654003,
   0.9825214,
   2.064472,
   1.985383,
   2.249611,
   2.890543,
   3.676626,
   4.352069,
   4.526863,
   4.050642,
   3.405975,
   2.849713,
   2.031577,
   1.546199,
   1.212718,
   0.8266868,
   0.515648,
   0.1527977,
   0.2527232,
   0.04155787,
   0,
   0,
   0.190867};
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
   0.7654003,
   0.9825214,
   2.064472,
   1.985383,
   2.249611,
   2.890543,
   3.676626,
   4.352069,
   4.526863,
   4.050642,
   3.405975,
   2.849713,
   2.031577,
   1.546199,
   1.212718,
   0.8266868,
   0.515648,
   0.1527977,
   0.2527232,
   0.04155787,
   0,
   0,
   0.190867};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3011,h_dh_down2_fy3011,h_dh_down2_felx3011,h_dh_down2_fehx3011,h_dh_down2_fely3011,h_dh_down2_fehy3011);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23011 = new TH1F("Graph_h_dh_down23011","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23011->SetMinimum(0);
   Graph_h_dh_down23011->SetMaximum(63.97509);
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
   0.3151822,
   0.3562101,
   0.397238,
   0.4382659,
   0.4587799,
   0.4792938,
   0.4998078,
   0.5203218,
   0.5408357,
   0.5613497,
   0.5818636,
   0.6023776,
   0.6126346,
   0.6228916,
   0.6331485,
   0.6434055,
   0.6844334,
   0.7049474,
   0.7254613,
   0.7357183,
   0.7459753,
   0.7562323,
   0.7664893,
   0.7767462,
   0.7870032,
   0.7972602,
   0.8075172,
   0.8177742,
   0.8280311,
   0.8382881,
   0.8485451,
   0.8588021,
   0.8690591,
   0.879316,
   0.889573,
   0.89983,
   0.910087,
   0.920344,
   0.9306009,
   0.9408579,
   0.9511149,
   0.9716289,
   0.9921428,
   1.012657,
   1.053685,
   1.074199,
   1.094713,
   1.115227,
   1.135741,
   1.156254,
   1.176768,
   1.197282,
   1.202411,
   1.207539,
   1.217796,
   1.23831,
   1.258824,
   1.299852,
   1.34088,
   1.34088};
   Double_t down_fy11[60] = {
   7.878405,
   8.916079,
   10.1739,
   11.71899,
   12.62745,
   13.64615,
   14.79371,
   16.09286,
   17.57156,
   19.26455,
   21.21542,
   23.47942,
   24.75025,
   26.12745,
   27.62327,
   29.2509,
   35.95453,
   39.14962,
   42.11913,
   43.49075,
   44.77225,
   45.95317,
   47.02365,
   47.97465,
   48.79796,
   49.48641,
   50.03394,
   50.43568,
   50.68805,
   50.78877,
   50.73695,
   50.53303,
   50.17887,
   49.67763,
   49.03377,
   48.25298,
   47.34209,
   46.30898,
   45.16245,
   43.9121,
   42.56821,
   39.64341,
   36.47829,
   33.16468,
   26.44186,
   23.18819,
   20.09183,
   17.20085,
   14.54984,
   12.1603,
   10.04172,
   8.193133,
   7.876958,
   7.706262,
   7.502385,
   7.279061,
   7.144195,
   6.973048,
   6.860591,
   6.860591};
   graph = new TGraph(60,down_fx11,down_fy11);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down11 = new TH1F("Graph_down11","Projection of downf DSCB fit",100,0.2126124,1.44345);
   Graph_down11->SetMinimum(2.467773);
   Graph_down11->SetMaximum(55.18159);
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
   
   TH1D *frame_3ada29c0__42 = new TH1D("frame_3ada29c0__42","p_T Balance",25,0,2);
   frame_3ada29c0__42->SetBinContent(1,61.06713);
   frame_3ada29c0__42->SetMaximum(61.06713);
   frame_3ada29c0__42->SetEntries(1);
   frame_3ada29c0__42->SetDirectory(0);
   frame_3ada29c0__42->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3ada29c0__42->SetLineColor(ci);
   frame_3ada29c0__42->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ada29c0__42->GetXaxis()->SetLabelFont(42);
   frame_3ada29c0__42->GetXaxis()->SetTitleOffset(1);
   frame_3ada29c0__42->GetXaxis()->SetTitleFont(42);
   frame_3ada29c0__42->GetYaxis()->SetTitle("1/Events");
   frame_3ada29c0__42->GetYaxis()->SetLabelFont(42);
   frame_3ada29c0__42->GetYaxis()->SetTitleFont(42);
   frame_3ada29c0__42->GetZaxis()->SetLabelFont(42);
   frame_3ada29c0__42->GetZaxis()->SetTitleOffset(1);
   frame_3ada29c0__42->GetZaxis()->SetTitleFont(42);
   frame_3ada29c0__42->Draw("AXISSAME");
   
   TH1D *norm_d__43 = new TH1D("norm_d__43","",25,0,2);
   norm_d__43->SetBinContent(3,2.382584);
   norm_d__43->SetBinContent(4,3.412412);
   norm_d__43->SetBinContent(5,10.20232);
   norm_d__43->SetBinContent(6,11.47058);
   norm_d__43->SetBinContent(7,14.80575);
   norm_d__43->SetBinContent(8,22.11031);
   norm_d__43->SetBinContent(9,36.4079);
   norm_d__43->SetBinContent(10,48.10667);
   norm_d__43->SetBinContent(11,53.63231);
   norm_d__43->SetBinContent(12,43.93976);
   norm_d__43->SetBinContent(13,31.01952);
   norm_d__43->SetBinContent(14,23.74387);
   norm_d__43->SetBinContent(15,13.16101);
   norm_d__43->SetBinContent(16,7.329723);
   norm_d__43->SetBinContent(17,4.880489);
   norm_d__43->SetBinContent(18,2.9373);
   norm_d__43->SetBinContent(19,1.268361);
   norm_d__43->SetBinContent(20,0.2851279);
   norm_d__43->SetBinContent(21,0.4591142);
   norm_d__43->SetBinContent(22,0.04155787);
   norm_d__43->SetBinContent(25,0.190867);
   norm_d__43->SetBinContent(26,0.08583493);
   norm_d__43->SetBinError(3,0.7654003);
   norm_d__43->SetBinError(4,0.9825214);
   norm_d__43->SetBinError(5,2.064472);
   norm_d__43->SetBinError(6,1.985383);
   norm_d__43->SetBinError(7,2.249611);
   norm_d__43->SetBinError(8,2.890543);
   norm_d__43->SetBinError(9,3.676626);
   norm_d__43->SetBinError(10,4.352069);
   norm_d__43->SetBinError(11,4.526863);
   norm_d__43->SetBinError(12,4.050642);
   norm_d__43->SetBinError(13,3.405975);
   norm_d__43->SetBinError(14,2.849713);
   norm_d__43->SetBinError(15,2.031577);
   norm_d__43->SetBinError(16,1.546199);
   norm_d__43->SetBinError(17,1.212718);
   norm_d__43->SetBinError(18,0.8266868);
   norm_d__43->SetBinError(19,0.515648);
   norm_d__43->SetBinError(20,0.1527977);
   norm_d__43->SetBinError(21,0.2527232);
   norm_d__43->SetBinError(22,0.04155787);
   norm_d__43->SetBinError(25,0.190867);
   norm_d__43->SetBinError(26,0.04489127);
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
   entry=leg->AddEntry("frame_x_d2_3ada29c0","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.836320 #pm 0.013722","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.189847 #pm 0.013542","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.995000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3ada29c0_copy__44 = new TH1D("frame_3ada29c0_copy__44","p_T Balance",25,0,2);
   frame_3ada29c0_copy__44->SetBinContent(1,61.06713);
   frame_3ada29c0_copy__44->SetMaximum(61.06713);
   frame_3ada29c0_copy__44->SetEntries(1);
   frame_3ada29c0_copy__44->SetDirectory(0);
   frame_3ada29c0_copy__44->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3ada29c0_copy__44->SetLineColor(ci);
   frame_3ada29c0_copy__44->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ada29c0_copy__44->GetXaxis()->SetLabelFont(42);
   frame_3ada29c0_copy__44->GetXaxis()->SetTitleOffset(1);
   frame_3ada29c0_copy__44->GetXaxis()->SetTitleFont(42);
   frame_3ada29c0_copy__44->GetYaxis()->SetTitle("1/Events");
   frame_3ada29c0_copy__44->GetYaxis()->SetLabelFont(42);
   frame_3ada29c0_copy__44->GetYaxis()->SetTitleFont(42);
   frame_3ada29c0_copy__44->GetZaxis()->SetLabelFont(42);
   frame_3ada29c0_copy__44->GetZaxis()->SetTitleOffset(1);
   frame_3ada29c0_copy__44->GetZaxis()->SetTitleFont(42);
   frame_3ada29c0_copy__44->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-7.189797,2.25,64.70817);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3ad8f070__45 = new TH1D("frame_3ad8f070__45","p_T Balance",25,0,2);
   frame_3ad8f070__45->SetBinContent(1,63.27021);
   frame_3ad8f070__45->SetMaximum(63.27021);
   frame_3ad8f070__45->SetEntries(1);
   frame_3ad8f070__45->SetDirectory(0);
   frame_3ad8f070__45->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3ad8f070__45->SetLineColor(ci);
   frame_3ad8f070__45->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ad8f070__45->GetXaxis()->SetLabelFont(42);
   frame_3ad8f070__45->GetXaxis()->SetTitleOffset(1);
   frame_3ad8f070__45->GetXaxis()->SetTitleFont(42);
   frame_3ad8f070__45->GetYaxis()->SetTitle("1/Events");
   frame_3ad8f070__45->GetYaxis()->SetLabelFont(42);
   frame_3ad8f070__45->GetYaxis()->SetTitleFont(42);
   frame_3ad8f070__45->GetZaxis()->SetLabelFont(42);
   frame_3ad8f070__45->GetZaxis()->SetTitleOffset(1);
   frame_3ad8f070__45->GetZaxis()->SetTitleFont(42);
   frame_3ad8f070__45->Draw("FUNC");
   
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
   3,
   13,
   12,
   26,
   20,
   40,
   52,
   51,
   48,
   27,
   24,
   16,
   7,
   5,
   6,
   1,
   1,
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
   1.632705,
   3.558662,
   3.415266,
   5.066015,
   4.434448,
   6.298,
   7.187836,
   7.117933,
   6.903979,
   5.163771,
   4.864612,
   3.957801,
   2.58147,
   2.159691,
   2.379931,
   0.8272462,
   0.8272462,
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
   2.918186,
   4.697573,
   4.559819,
   6.164324,
   5.546519,
   7.377261,
   8.257346,
   8.188122,
   7.97633,
   6.260244,
   5.966932,
   5.083066,
   3.770281,
   3.382473,
   3.583642,
   2.299527,
   2.299527,
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
   Graph_h_dh_data23012->SetMaximum(66.28308);
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
   
   Double_t observation_fx12[53] = {
   0.3525335,
   0.3908182,
   0.4291029,
   0.4482452,
   0.4673876,
   0.4769587,
   0.4865299,
   0.4913155,
   0.4961011,
   0.5056723,
   0.5248146,
   0.543957,
   0.5822417,
   0.6205263,
   0.6396687,
   0.658811,
   0.6779534,
   0.6970957,
   0.7162381,
   0.7353804,
   0.7545228,
   0.7736651,
   0.7832363,
   0.7928075,
   0.8023786,
   0.8119498,
   0.821521,
   0.8310922,
   0.8406633,
   0.8502345,
   0.8693768,
   0.8885192,
   0.9076615,
   0.9268039,
   0.9459462,
   0.9650886,
   0.9842309,
   1.003373,
   1.041658,
   1.079943,
   1.099085,
   1.118227,
   1.13737,
   1.156512,
   1.175654,
   1.194797,
   1.213939,
   1.233081,
   1.252224,
   1.271366,
   1.290508,
   1.309651,
   1.309651};
   Double_t observation_fy12[53] = {
   14.66573,
   14.88319,
   15.19829,
   15.42907,
   15.76714,
   16.01865,
   16.39607,
   16.68707,
   17.14466,
   18.27391,
   20.63817,
   23.12549,
   28.35759,
   33.69508,
   36.29817,
   38.79562,
   41.13963,
   43.28304,
   45.18091,
   46.79202,
   48.08043,
   49.01677,
   49.3458,
   49.57934,
   49.71599,
   49.75497,
   49.69604,
   49.53954,
   49.2864,
   48.93811,
   47.96474,
   46.64196,
   44.99986,
   43.075,
   40.90903,
   38.54719,
   36.03678,
   33.42559,
   28.08563,
   22.86696,
   20.39107,
   18.04062,
   15.83589,
   13.79156,
   11.91692,
   10.21631,
   8.689688,
   7.333206,
   6.139929,
   5.100498,
   4.203794,
   3.437559,
   3.437559};
   graph = new TGraph(53,observation_fx12,observation_fy12);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation12 = new TH1F("Graph_observation12","Projection of obsf DSCB fit",100,0.2568218,1.405363);
   Graph_observation12->SetMinimum(3.093803);
   Graph_observation12->SetMaximum(54.38671);
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
   
   TH1D *frame_3ad8f070__46 = new TH1D("frame_3ad8f070__46","p_T Balance",25,0,2);
   frame_3ad8f070__46->SetBinContent(1,63.27021);
   frame_3ad8f070__46->SetMaximum(63.27021);
   frame_3ad8f070__46->SetEntries(1);
   frame_3ad8f070__46->SetDirectory(0);
   frame_3ad8f070__46->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3ad8f070__46->SetLineColor(ci);
   frame_3ad8f070__46->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ad8f070__46->GetXaxis()->SetLabelFont(42);
   frame_3ad8f070__46->GetXaxis()->SetTitleOffset(1);
   frame_3ad8f070__46->GetXaxis()->SetTitleFont(42);
   frame_3ad8f070__46->GetYaxis()->SetTitle("1/Events");
   frame_3ad8f070__46->GetYaxis()->SetLabelFont(42);
   frame_3ad8f070__46->GetYaxis()->SetTitleFont(42);
   frame_3ad8f070__46->GetZaxis()->SetLabelFont(42);
   frame_3ad8f070__46->GetZaxis()->SetTitleOffset(1);
   frame_3ad8f070__46->GetZaxis()->SetTitleFont(42);
   frame_3ad8f070__46->Draw("AXISSAME");
   
   TH1D *norm_o__47 = new TH1D("norm_o__47","",25,0,2);
   norm_o__47->SetBinContent(3,1);
   norm_o__47->SetBinContent(4,3);
   norm_o__47->SetBinContent(5,13);
   norm_o__47->SetBinContent(6,12);
   norm_o__47->SetBinContent(7,26);
   norm_o__47->SetBinContent(8,20);
   norm_o__47->SetBinContent(9,40);
   norm_o__47->SetBinContent(10,52);
   norm_o__47->SetBinContent(11,51);
   norm_o__47->SetBinContent(12,48);
   norm_o__47->SetBinContent(13,27);
   norm_o__47->SetBinContent(14,24);
   norm_o__47->SetBinContent(15,16);
   norm_o__47->SetBinContent(16,7);
   norm_o__47->SetBinContent(17,5);
   norm_o__47->SetBinContent(18,6);
   norm_o__47->SetBinContent(19,1);
   norm_o__47->SetBinContent(20,1);
   norm_o__47->SetBinContent(22,1);
   norm_o__47->SetMinimum(0);
   norm_o__47->SetMaximum(114.4);
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
   entry=leg->AddEntry("frame_x_o2_3ad8f070","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.832473 #pm 0.012486","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.196692 #pm 0.011253","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.970000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3ad8f070_copy__48 = new TH1D("frame_3ad8f070_copy__48","p_T Balance",25,0,2);
   frame_3ad8f070_copy__48->SetBinContent(1,63.27021);
   frame_3ad8f070_copy__48->SetMaximum(63.27021);
   frame_3ad8f070_copy__48->SetEntries(1);
   frame_3ad8f070_copy__48->SetDirectory(0);
   frame_3ad8f070_copy__48->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3ad8f070_copy__48->SetLineColor(ci);
   frame_3ad8f070_copy__48->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3ad8f070_copy__48->GetXaxis()->SetLabelFont(42);
   frame_3ad8f070_copy__48->GetXaxis()->SetTitleOffset(1);
   frame_3ad8f070_copy__48->GetXaxis()->SetTitleFont(42);
   frame_3ad8f070_copy__48->GetYaxis()->SetTitle("1/Events");
   frame_3ad8f070_copy__48->GetYaxis()->SetLabelFont(42);
   frame_3ad8f070_copy__48->GetYaxis()->SetTitleFont(42);
   frame_3ad8f070_copy__48->GetZaxis()->SetLabelFont(42);
   frame_3ad8f070_copy__48->GetZaxis()->SetTitleOffset(1);
   frame_3ad8f070_copy__48->GetZaxis()->SetTitleFont(42);
   frame_3ad8f070_copy__48->Draw("sameaxis");
   
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
