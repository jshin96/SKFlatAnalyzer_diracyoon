void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_3__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 18:17:49 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-18.05233,2.25,135.8822);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3b945220__33 = new TH1D("frame_3b945220__33","p_T Balance",25,0,2);
   frame_3b945220__33->SetBinContent(1,120.4888);
   frame_3b945220__33->SetMinimum(-5.737561);
   frame_3b945220__33->SetMaximum(120.4888);
   frame_3b945220__33->SetEntries(1);
   frame_3b945220__33->SetDirectory(0);
   frame_3b945220__33->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_3b945220__33->SetLineColor(ci);
   frame_3b945220__33->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b945220__33->GetXaxis()->SetLabelFont(42);
   frame_3b945220__33->GetXaxis()->SetTitleOffset(1);
   frame_3b945220__33->GetXaxis()->SetTitleFont(42);
   frame_3b945220__33->GetYaxis()->SetTitle("1/Events");
   frame_3b945220__33->GetYaxis()->SetLabelFont(42);
   frame_3b945220__33->GetYaxis()->SetTitleFont(42);
   frame_3b945220__33->GetZaxis()->SetLabelFont(42);
   frame_3b945220__33->GetZaxis()->SetTitleOffset(1);
   frame_3b945220__33->GetZaxis()->SetTitleFont(42);
   frame_3b945220__33->Draw("FUNC");
   
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
   4.543487,
   4.242867,
   10.83266,
   19.89064,
   28.82527,
   45.27575,
   63.13602,
   82.79086,
   108.3846,
   93.58851,
   75.58114,
   57.46905,
   36.68657,
   18.85416,
   10.20997,
   6.754456,
   2.93304,
   1.208452,
   0.4978426,
   0.1495325,
   0.2605704,
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
   1.179657,
   0.9818377,
   2.044241,
   2.629895,
   3.171213,
   3.992928,
   4.813846,
   5.503783,
   6.366609,
   5.782321,
   5.16617,
   4.441634,
   3.364488,
   2.447071,
   1.722136,
   1.382521,
   0.8438706,
   0.4578799,
   0.2626027,
   0.1495325,
   0.1771325,
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
   1.179657,
   0.9818377,
   2.044241,
   2.629895,
   3.171213,
   3.992928,
   4.813846,
   5.503783,
   6.366609,
   5.782321,
   5.16617,
   4.441634,
   3.364488,
   2.447071,
   1.722136,
   1.382521,
   0.8438706,
   0.4578799,
   0.2626027,
   0.1495325,
   0.1771325,
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
   Graph_h_dh_central23009->SetMinimum(-11.47512);
   Graph_h_dh_central23009->SetMaximum(126.2263);
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
   0.2902845,
   0.3128997,
   0.335515,
   0.3581302,
   0.3807454,
   0.4033606,
   0.4259758,
   0.448591,
   0.4712062,
   0.4938215,
   0.5164367,
   0.5390519,
   0.5616671,
   0.5842823,
   0.6068975,
   0.652128,
   0.6747432,
   0.6973584,
   0.7199736,
   0.7425888,
   0.7652041,
   0.7765117,
   0.7878193,
   0.7991269,
   0.8104345,
   0.8217421,
   0.8330497,
   0.8443573,
   0.8556649,
   0.8669725,
   0.8782801,
   0.8895878,
   0.9008954,
   0.912203,
   0.9235106,
   0.9348182,
   0.9461258,
   0.968741,
   0.9913562,
   1.013971,
   1.036587,
   1.059202,
   1.104432,
   1.127048,
   1.149663,
   1.172278,
   1.194893,
   1.217508,
   1.240124,
   1.262739,
   1.285354,
   1.307969,
   1.330584,
   1.341892,
   1.3532,
   1.375815,
   1.421045,
   1.421045};
   Double_t Central_fy9[58] = {
   3.671037,
   4.74039,
   6.057689,
   7.660682,
   9.587281,
   11.87383,
   14.55305,
   17.65163,
   21.18766,
   25.16801,
   29.58572,
   34.41779,
   39.62338,
   45.14269,
   50.89687,
   62.7048,
   68.51837,
   74.09362,
   79.29068,
   83.97133,
   88.00502,
   89.74205,
   91.27491,
   92.59206,
   93.68347,
   94.54076,
   95.15729,
   95.52828,
   95.65083,
   95.52398,
   95.14872,
   94.52798,
   93.66659,
   92.57121,
   91.25024,
   89.71375,
   87.9733,
   83.9335,
   79.24782,
   74.04689,
   68.46899,
   62.65397,
   50.84644,
   45.0939,
   39.57698,
   34.3744,
   29.54575,
   25.13174,
   21.15523,
   17.62302,
   14.52816,
   11.85245,
   9.569154,
   8.564589,
   8.058546,
   7.711884,
   7.418875,
   7.418875};
   TGraph *graph = new TGraph(58,Central_fx9,Central_fy9);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central9 = new TH1F("Graph_Central9","Projection of centralf DSCB fit",100,0.1772084,1.534121);
   Graph_Central9->SetMinimum(3.303933);
   Graph_Central9->SetMaximum(104.8488);
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
   
   TH1D *frame_3b945220__34 = new TH1D("frame_3b945220__34","p_T Balance",25,0,2);
   frame_3b945220__34->SetBinContent(1,120.4888);
   frame_3b945220__34->SetMinimum(-5.737561);
   frame_3b945220__34->SetMaximum(120.4888);
   frame_3b945220__34->SetEntries(1);
   frame_3b945220__34->SetDirectory(0);
   frame_3b945220__34->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b945220__34->SetLineColor(ci);
   frame_3b945220__34->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b945220__34->GetXaxis()->SetLabelFont(42);
   frame_3b945220__34->GetXaxis()->SetTitleOffset(1);
   frame_3b945220__34->GetXaxis()->SetTitleFont(42);
   frame_3b945220__34->GetYaxis()->SetTitle("1/Events");
   frame_3b945220__34->GetYaxis()->SetLabelFont(42);
   frame_3b945220__34->GetYaxis()->SetTitleFont(42);
   frame_3b945220__34->GetZaxis()->SetLabelFont(42);
   frame_3b945220__34->GetZaxis()->SetTitleOffset(1);
   frame_3b945220__34->GetZaxis()->SetTitleFont(42);
   frame_3b945220__34->Draw("AXISSAME");
   
   TH1D *norm_c__35 = new TH1D("norm_c__35","",25,0,2);
   norm_c__35->SetBinContent(3,4.543487);
   norm_c__35->SetBinContent(4,4.242867);
   norm_c__35->SetBinContent(5,10.83266);
   norm_c__35->SetBinContent(6,19.89064);
   norm_c__35->SetBinContent(7,28.82527);
   norm_c__35->SetBinContent(8,45.27575);
   norm_c__35->SetBinContent(9,63.13603);
   norm_c__35->SetBinContent(10,82.79086);
   norm_c__35->SetBinContent(11,108.3846);
   norm_c__35->SetBinContent(12,93.58851);
   norm_c__35->SetBinContent(13,75.58114);
   norm_c__35->SetBinContent(14,57.46905);
   norm_c__35->SetBinContent(15,36.68657);
   norm_c__35->SetBinContent(16,18.85416);
   norm_c__35->SetBinContent(17,10.20997);
   norm_c__35->SetBinContent(18,6.754455);
   norm_c__35->SetBinContent(19,2.93304);
   norm_c__35->SetBinContent(20,1.208452);
   norm_c__35->SetBinContent(21,0.4978426);
   norm_c__35->SetBinContent(22,0.1495325);
   norm_c__35->SetBinContent(23,0.2605704);
   norm_c__35->SetBinContent(26,0.287201);
   norm_c__35->SetBinError(3,1.179657);
   norm_c__35->SetBinError(4,0.9818377);
   norm_c__35->SetBinError(5,2.044241);
   norm_c__35->SetBinError(6,2.629895);
   norm_c__35->SetBinError(7,3.171213);
   norm_c__35->SetBinError(8,3.992928);
   norm_c__35->SetBinError(9,4.813846);
   norm_c__35->SetBinError(10,5.503783);
   norm_c__35->SetBinError(11,6.366609);
   norm_c__35->SetBinError(12,5.782321);
   norm_c__35->SetBinError(13,5.16617);
   norm_c__35->SetBinError(14,4.441634);
   norm_c__35->SetBinError(15,3.364488);
   norm_c__35->SetBinError(16,2.447071);
   norm_c__35->SetBinError(17,1.722136);
   norm_c__35->SetBinError(18,1.382521);
   norm_c__35->SetBinError(19,0.8438706);
   norm_c__35->SetBinError(20,0.4578799);
   norm_c__35->SetBinError(21,0.2626027);
   norm_c__35->SetBinError(22,0.1495325);
   norm_c__35->SetBinError(23,0.1771325);
   norm_c__35->SetBinError(26,0.1280197);
   norm_c__35->SetEntries(3131);
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
   entry=leg->AddEntry("frame_x_c2_3b945220","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.855567 #pm 0.008900","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.221374 #pm 0.006981","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.940000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3b945220_copy__36 = new TH1D("frame_3b945220_copy__36","p_T Balance",25,0,2);
   frame_3b945220_copy__36->SetBinContent(1,120.4888);
   frame_3b945220_copy__36->SetMinimum(-5.737561);
   frame_3b945220_copy__36->SetMaximum(120.4888);
   frame_3b945220_copy__36->SetEntries(1);
   frame_3b945220_copy__36->SetDirectory(0);
   frame_3b945220_copy__36->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b945220_copy__36->SetLineColor(ci);
   frame_3b945220_copy__36->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b945220_copy__36->GetXaxis()->SetLabelFont(42);
   frame_3b945220_copy__36->GetXaxis()->SetTitleOffset(1);
   frame_3b945220_copy__36->GetXaxis()->SetTitleFont(42);
   frame_3b945220_copy__36->GetYaxis()->SetTitle("1/Events");
   frame_3b945220_copy__36->GetYaxis()->SetLabelFont(42);
   frame_3b945220_copy__36->GetYaxis()->SetTitleFont(42);
   frame_3b945220_copy__36->GetZaxis()->SetLabelFont(42);
   frame_3b945220_copy__36->GetZaxis()->SetTitleOffset(1);
   frame_3b945220_copy__36->GetZaxis()->SetTitleFont(42);
   frame_3b945220_copy__36->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-17.37101,2.25,130.7539);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3b9494e0__37 = new TH1D("frame_3b9494e0__37","p_T Balance",25,0,2);
   frame_3b9494e0__37->SetBinContent(1,115.9414);
   frame_3b9494e0__37->SetMinimum(-5.521019);
   frame_3b9494e0__37->SetMaximum(115.9414);
   frame_3b9494e0__37->SetEntries(1);
   frame_3b9494e0__37->SetDirectory(0);
   frame_3b9494e0__37->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b9494e0__37->SetLineColor(ci);
   frame_3b9494e0__37->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b9494e0__37->GetXaxis()->SetLabelFont(42);
   frame_3b9494e0__37->GetXaxis()->SetTitleOffset(1);
   frame_3b9494e0__37->GetXaxis()->SetTitleFont(42);
   frame_3b9494e0__37->GetYaxis()->SetTitle("1/Events");
   frame_3b9494e0__37->GetYaxis()->SetLabelFont(42);
   frame_3b9494e0__37->GetYaxis()->SetTitleFont(42);
   frame_3b9494e0__37->GetZaxis()->SetLabelFont(42);
   frame_3b9494e0__37->GetZaxis()->SetTitleOffset(1);
   frame_3b9494e0__37->GetZaxis()->SetTitleFont(42);
   frame_3b9494e0__37->Draw("FUNC");
   
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
   3.906345,
   4.552246,
   11.38211,
   16.62249,
   30.55102,
   46.26831,
   64.49599,
   85.5153,
   104.1958,
   97.20419,
   75.13714,
   56.26033,
   42.30241,
   20.94643,
   8.602323,
   5.653944,
   2.548867,
   1.236747,
   0.7058952,
   0.3350402,
   0.1794449,
   0.03146754,
   0.1632003};
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
   1.061348,
   1.213738,
   2.049324,
   2.353002,
   3.29021,
   4.071633,
   4.982172,
   5.646272,
   6.22458,
   5.940899,
   5.160882,
   4.375701,
   3.68518,
   2.623674,
   1.601468,
   1.269037,
   0.7225004,
   0.4610412,
   0.3072389,
   0.2384141,
   0.1665383,
   0.03146754,
   0.1632003};
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
   1.061348,
   1.213738,
   2.049324,
   2.353002,
   3.29021,
   4.071633,
   4.982172,
   5.646272,
   6.22458,
   5.940899,
   5.160882,
   4.375701,
   3.68518,
   2.623674,
   1.601468,
   1.269037,
   0.7225004,
   0.4610412,
   0.3072389,
   0.2384141,
   0.1665383,
   0.03146754,
   0.1632003};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3010,h_dh_up2_fy3010,h_dh_up2_felx3010,h_dh_up2_fehx3010,h_dh_up2_fely3010,h_dh_up2_fehy3010);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23010 = new TH1F("Graph_h_dh_up23010","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23010->SetMinimum(-11.04204);
   Graph_h_dh_up23010->SetMaximum(121.4624);
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
   
   Double_t up_fx10[58] = {
   0.2892549,
   0.3118581,
   0.3344612,
   0.3570644,
   0.3796676,
   0.4022708,
   0.424874,
   0.4474771,
   0.4700803,
   0.4926835,
   0.5152867,
   0.5378899,
   0.560493,
   0.5830962,
   0.6056994,
   0.6509058,
   0.6735089,
   0.6961121,
   0.7187153,
   0.7413185,
   0.7639217,
   0.7752233,
   0.7865248,
   0.7978264,
   0.809128,
   0.8204296,
   0.8317312,
   0.8430328,
   0.8543344,
   0.865636,
   0.8769376,
   0.8882391,
   0.8995407,
   0.9108423,
   0.9221439,
   0.9334455,
   0.9447471,
   0.9673503,
   0.9899535,
   1.012557,
   1.03516,
   1.057763,
   1.102969,
   1.125573,
   1.148176,
   1.170779,
   1.193382,
   1.215985,
   1.238588,
   1.261192,
   1.283795,
   1.306398,
   1.329001,
   1.351604,
   1.374208,
   1.396811,
   1.419414,
   1.419414};
   Double_t up_fy10[58] = {
   3.649137,
   4.707508,
   6.010561,
   7.595598,
   9.500182,
   11.76048,
   14.40924,
   17.47351,
   20.97211,
   24.91308,
   29.29109,
   34.08527,
   39.25735,
   44.75053,
   50.4892,
   62.31148,
   68.16124,
   73.79549,
   79.0761,
   83.86557,
   88.03294,
   89.84565,
   91.45968,
   92.86308,
   94.04533,
   94.99749,
   95.71231,
   96.1843,
   96.40984,
   96.38719,
   96.11651,
   95.5999,
   94.84133,
   93.84661,
   92.62331,
   91.18067,
   89.52947,
   85.65145,
   81.10105,
   76.00484,
   70.49837,
   64.72021,
   52.88478,
   47.07178,
   41.46805,
   36.15676,
   31.20244,
   26.65082,
   22.52971,
   18.85054,
   15.61043,
   12.79467,
   10.37926,
   8.33348,
   6.622312,
   5.208539,
   4.055506,
   4.055506};
   graph = new TGraph(58,up_fx10,up_fy10);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up10 = new TH1F("Graph_up10","Projection of upf DSCB fit",100,0.176239,1.53243);
   Graph_up10->SetMinimum(3.284223);
   Graph_up10->SetMaximum(105.6859);
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
   
   TH1D *frame_3b9494e0__38 = new TH1D("frame_3b9494e0__38","p_T Balance",25,0,2);
   frame_3b9494e0__38->SetBinContent(1,115.9414);
   frame_3b9494e0__38->SetMinimum(-5.521019);
   frame_3b9494e0__38->SetMaximum(115.9414);
   frame_3b9494e0__38->SetEntries(1);
   frame_3b9494e0__38->SetDirectory(0);
   frame_3b9494e0__38->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b9494e0__38->SetLineColor(ci);
   frame_3b9494e0__38->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b9494e0__38->GetXaxis()->SetLabelFont(42);
   frame_3b9494e0__38->GetXaxis()->SetTitleOffset(1);
   frame_3b9494e0__38->GetXaxis()->SetTitleFont(42);
   frame_3b9494e0__38->GetYaxis()->SetTitle("1/Events");
   frame_3b9494e0__38->GetYaxis()->SetLabelFont(42);
   frame_3b9494e0__38->GetYaxis()->SetTitleFont(42);
   frame_3b9494e0__38->GetZaxis()->SetLabelFont(42);
   frame_3b9494e0__38->GetZaxis()->SetTitleOffset(1);
   frame_3b9494e0__38->GetZaxis()->SetTitleFont(42);
   frame_3b9494e0__38->Draw("AXISSAME");
   
   TH1D *norm_u__39 = new TH1D("norm_u__39","",25,0,2);
   norm_u__39->SetBinContent(3,3.906345);
   norm_u__39->SetBinContent(4,4.552246);
   norm_u__39->SetBinContent(5,11.38211);
   norm_u__39->SetBinContent(6,16.62249);
   norm_u__39->SetBinContent(7,30.55102);
   norm_u__39->SetBinContent(8,46.26831);
   norm_u__39->SetBinContent(9,64.49599);
   norm_u__39->SetBinContent(10,85.51529);
   norm_u__39->SetBinContent(11,104.1958);
   norm_u__39->SetBinContent(12,97.2042);
   norm_u__39->SetBinContent(13,75.13714);
   norm_u__39->SetBinContent(14,56.26033);
   norm_u__39->SetBinContent(15,42.30241);
   norm_u__39->SetBinContent(16,20.94643);
   norm_u__39->SetBinContent(17,8.602322);
   norm_u__39->SetBinContent(18,5.653944);
   norm_u__39->SetBinContent(19,2.548867);
   norm_u__39->SetBinContent(20,1.236747);
   norm_u__39->SetBinContent(21,0.7058953);
   norm_u__39->SetBinContent(22,0.3350402);
   norm_u__39->SetBinContent(23,0.1794449);
   norm_u__39->SetBinContent(24,0.03146754);
   norm_u__39->SetBinContent(25,0.1632003);
   norm_u__39->SetBinContent(26,0.2810323);
   norm_u__39->SetBinError(3,1.061348);
   norm_u__39->SetBinError(4,1.213738);
   norm_u__39->SetBinError(5,2.049324);
   norm_u__39->SetBinError(6,2.353002);
   norm_u__39->SetBinError(7,3.29021);
   norm_u__39->SetBinError(8,4.071633);
   norm_u__39->SetBinError(9,4.982172);
   norm_u__39->SetBinError(10,5.646272);
   norm_u__39->SetBinError(11,6.22458);
   norm_u__39->SetBinError(12,5.940899);
   norm_u__39->SetBinError(13,5.160882);
   norm_u__39->SetBinError(14,4.375701);
   norm_u__39->SetBinError(15,3.68518);
   norm_u__39->SetBinError(16,2.623674);
   norm_u__39->SetBinError(17,1.601468);
   norm_u__39->SetBinError(18,1.269037);
   norm_u__39->SetBinError(19,0.7225004);
   norm_u__39->SetBinError(20,0.4610412);
   norm_u__39->SetBinError(21,0.3072389);
   norm_u__39->SetBinError(22,0.2384141);
   norm_u__39->SetBinError(23,0.1665383);
   norm_u__39->SetBinError(24,0.03146754);
   norm_u__39->SetBinError(25,0.1632003);
   norm_u__39->SetBinError(26,0.1283891);
   norm_u__39->SetEntries(3108);
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
   entry=leg->AddEntry("frame_x_u2_3b9494e0","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.858955 #pm 0.009007","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.222619 #pm 0.007351","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.994000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3b9494e0_copy__40 = new TH1D("frame_3b9494e0_copy__40","p_T Balance",25,0,2);
   frame_3b9494e0_copy__40->SetBinContent(1,115.9414);
   frame_3b9494e0_copy__40->SetMinimum(-5.521019);
   frame_3b9494e0_copy__40->SetMaximum(115.9414);
   frame_3b9494e0_copy__40->SetEntries(1);
   frame_3b9494e0_copy__40->SetDirectory(0);
   frame_3b9494e0_copy__40->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b9494e0_copy__40->SetLineColor(ci);
   frame_3b9494e0_copy__40->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b9494e0_copy__40->GetXaxis()->SetLabelFont(42);
   frame_3b9494e0_copy__40->GetXaxis()->SetTitleOffset(1);
   frame_3b9494e0_copy__40->GetXaxis()->SetTitleFont(42);
   frame_3b9494e0_copy__40->GetYaxis()->SetTitle("1/Events");
   frame_3b9494e0_copy__40->GetYaxis()->SetLabelFont(42);
   frame_3b9494e0_copy__40->GetYaxis()->SetTitleFont(42);
   frame_3b9494e0_copy__40->GetZaxis()->SetLabelFont(42);
   frame_3b9494e0_copy__40->GetZaxis()->SetTitleOffset(1);
   frame_3b9494e0_copy__40->GetZaxis()->SetTitleFont(42);
   frame_3b9494e0_copy__40->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-18.98857,2.25,116.6441);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3b961280__41 = new TH1D("frame_3b961280__41","p_T Balance",25,0,2);
   frame_3b961280__41->SetBinContent(1,113.9314);
   frame_3b961280__41->SetMinimum(-5.425305);
   frame_3b961280__41->SetMaximum(113.9314);
   frame_3b961280__41->SetEntries(1);
   frame_3b961280__41->SetDirectory(0);
   frame_3b961280__41->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b961280__41->SetLineColor(ci);
   frame_3b961280__41->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b961280__41->GetXaxis()->SetLabelFont(42);
   frame_3b961280__41->GetXaxis()->SetTitleOffset(1);
   frame_3b961280__41->GetXaxis()->SetTitleFont(42);
   frame_3b961280__41->GetYaxis()->SetTitle("1/Events");
   frame_3b961280__41->GetYaxis()->SetLabelFont(42);
   frame_3b961280__41->GetYaxis()->SetTitleFont(42);
   frame_3b961280__41->GetZaxis()->SetLabelFont(42);
   frame_3b961280__41->GetZaxis()->SetTitleOffset(1);
   frame_3b961280__41->GetZaxis()->SetTitleFont(42);
   frame_3b961280__41->Draw("FUNC");
   
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
   4.688071,
   6.04503,
   13.70775,
   24.25596,
   30.12568,
   50.5349,
   67.01642,
   81.70577,
   102.4247,
   92.49348,
   66.27666,
   50.93597,
   32.98152,
   15.44052,
   11.52519,
   3.734413,
   2.387825,
   1.059281,
   0.3165101,
   0.3770097,
   0.2969997,
   0.01789249,
   0.05256902};
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
   1.15559,
   1.221881,
   2.229247,
   2.873069,
   3.201038,
   4.273843,
   4.923757,
   5.397845,
   6.081407,
   5.719681,
   4.772335,
   4.109266,
   3.172859,
   2.162698,
   1.836723,
   0.9734778,
   0.716158,
   0.4884873,
   0.1674703,
   0.2456161,
   0.1819526,
   0.01789249,
   0.05256902};
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
   1.15559,
   1.221881,
   2.229247,
   2.873069,
   3.201038,
   4.273843,
   4.923757,
   5.397845,
   6.081407,
   5.719681,
   4.772335,
   4.109266,
   3.172859,
   2.162698,
   1.836723,
   0.9734778,
   0.716158,
   0.4884873,
   0.1674703,
   0.2456161,
   0.1819526,
   0.01789249,
   0.05256902};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3011,h_dh_down2_fy3011,h_dh_down2_felx3011,h_dh_down2_fehx3011,h_dh_down2_fely3011,h_dh_down2_fehy3011);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23011 = new TH1F("Graph_h_dh_down23011","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23011->SetMinimum(-10.85061);
   Graph_h_dh_down23011->SetMaximum(119.3567);
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
   
   Double_t down_fx11[57] = {
   0.3011995,
   0.3446309,
   0.3880623,
   0.4097781,
   0.4314938,
   0.4532095,
   0.4749252,
   0.4966409,
   0.5183566,
   0.5400723,
   0.5509302,
   0.561788,
   0.5835037,
   0.6052194,
   0.6486508,
   0.6703666,
   0.6920823,
   0.713798,
   0.7355137,
   0.7572294,
   0.7680872,
   0.7789451,
   0.7898029,
   0.8006608,
   0.8115187,
   0.8223765,
   0.8332344,
   0.8440922,
   0.8549501,
   0.8658079,
   0.8766658,
   0.8875236,
   0.8983815,
   0.9092393,
   0.9200972,
   0.9309551,
   0.9526708,
   0.9743865,
   0.9961022,
   1.017818,
   1.039534,
   1.082965,
   1.104681,
   1.126396,
   1.148112,
   1.169828,
   1.191544,
   1.213259,
   1.234975,
   1.256691,
   1.278406,
   1.300122,
   1.321838,
   1.343554,
   1.365269,
   1.386985,
   1.386985};
   Double_t down_fy11[57] = {
   10.63183,
   12.85993,
   15.70351,
   17.42035,
   19.37835,
   21.61934,
   24.19384,
   27.16324,
   30.6025,
   34.60373,
   36.84966,
   39.2808,
   44.65068,
   50.28824,
   61.8499,
   67.54189,
   73.00277,
   78.09756,
   82.69276,
   86.66215,
   88.37612,
   89.89249,
   91.2,
   92.28886,
   93.15082,
   93.77932,
   94.16955,
   94.31849,
   94.22502,
   93.88983,
   93.31552,
   92.50649,
   91.46891,
   90.21065,
   88.74116,
   87.07136,
   83.18113,
   78.65136,
   73.60709,
   68.18125,
   62.50895,
   50.94394,
   45.28618,
   39.84471,
   34.69826,
   29.90726,
   25.51394,
   21.5432,
   18.00425,
   14.89264,
   12.19271,
   9.880091,
   7.924165,
   6.290396,
   4.94236,
   3.843464,
   3.843464};
   graph = new TGraph(57,down_fx11,down_fy11);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down11 = new TH1F("Graph_down11","Projection of downf DSCB fit",100,0.192621,1.495563);
   Graph_down11->SetMinimum(3.459117);
   Graph_down11->SetMaximum(103.366);
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
   
   TH1D *frame_3b961280__42 = new TH1D("frame_3b961280__42","p_T Balance",25,0,2);
   frame_3b961280__42->SetBinContent(1,113.9314);
   frame_3b961280__42->SetMinimum(-5.425305);
   frame_3b961280__42->SetMaximum(113.9314);
   frame_3b961280__42->SetEntries(1);
   frame_3b961280__42->SetDirectory(0);
   frame_3b961280__42->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b961280__42->SetLineColor(ci);
   frame_3b961280__42->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b961280__42->GetXaxis()->SetLabelFont(42);
   frame_3b961280__42->GetXaxis()->SetTitleOffset(1);
   frame_3b961280__42->GetXaxis()->SetTitleFont(42);
   frame_3b961280__42->GetYaxis()->SetTitle("1/Events");
   frame_3b961280__42->GetYaxis()->SetLabelFont(42);
   frame_3b961280__42->GetYaxis()->SetTitleFont(42);
   frame_3b961280__42->GetZaxis()->SetLabelFont(42);
   frame_3b961280__42->GetZaxis()->SetTitleOffset(1);
   frame_3b961280__42->GetZaxis()->SetTitleFont(42);
   frame_3b961280__42->Draw("AXISSAME");
   
   TH1D *norm_d__43 = new TH1D("norm_d__43","",25,0,2);
   norm_d__43->SetBinContent(3,4.688071);
   norm_d__43->SetBinContent(4,6.04503);
   norm_d__43->SetBinContent(5,13.70775);
   norm_d__43->SetBinContent(6,24.25596);
   norm_d__43->SetBinContent(7,30.12568);
   norm_d__43->SetBinContent(8,50.5349);
   norm_d__43->SetBinContent(9,67.01642);
   norm_d__43->SetBinContent(10,81.70577);
   norm_d__43->SetBinContent(11,102.4247);
   norm_d__43->SetBinContent(12,92.49348);
   norm_d__43->SetBinContent(13,66.27666);
   norm_d__43->SetBinContent(14,50.93597);
   norm_d__43->SetBinContent(15,32.98152);
   norm_d__43->SetBinContent(16,15.44052);
   norm_d__43->SetBinContent(17,11.52519);
   norm_d__43->SetBinContent(18,3.734413);
   norm_d__43->SetBinContent(19,2.387825);
   norm_d__43->SetBinContent(20,1.05928);
   norm_d__43->SetBinContent(21,0.3165101);
   norm_d__43->SetBinContent(22,0.3770097);
   norm_d__43->SetBinContent(23,0.2969997);
   norm_d__43->SetBinContent(24,0.01789249);
   norm_d__43->SetBinContent(25,0.05256902);
   norm_d__43->SetBinContent(26,0.1977193);
   norm_d__43->SetBinError(3,1.15559);
   norm_d__43->SetBinError(4,1.221881);
   norm_d__43->SetBinError(5,2.229247);
   norm_d__43->SetBinError(6,2.873069);
   norm_d__43->SetBinError(7,3.201038);
   norm_d__43->SetBinError(8,4.273843);
   norm_d__43->SetBinError(9,4.923757);
   norm_d__43->SetBinError(10,5.397845);
   norm_d__43->SetBinError(11,6.081407);
   norm_d__43->SetBinError(12,5.719681);
   norm_d__43->SetBinError(13,4.772335);
   norm_d__43->SetBinError(14,4.109266);
   norm_d__43->SetBinError(15,3.172859);
   norm_d__43->SetBinError(16,2.162698);
   norm_d__43->SetBinError(17,1.836723);
   norm_d__43->SetBinError(18,0.9734778);
   norm_d__43->SetBinError(19,0.716158);
   norm_d__43->SetBinError(20,0.4884873);
   norm_d__43->SetBinError(21,0.1674703);
   norm_d__43->SetBinError(22,0.2456161);
   norm_d__43->SetBinError(23,0.1819526);
   norm_d__43->SetBinError(24,0.01789249);
   norm_d__43->SetBinError(25,0.05256902);
   norm_d__43->SetBinError(26,0.08967208);
   norm_d__43->SetEntries(3195);
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
   entry=leg->AddEntry("frame_x_d2_3b961280","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.845365 #pm 0.009599","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.214107 #pm 0.008625","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.993000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3b961280_copy__44 = new TH1D("frame_3b961280_copy__44","p_T Balance",25,0,2);
   frame_3b961280_copy__44->SetBinContent(1,113.9314);
   frame_3b961280_copy__44->SetMinimum(-5.425305);
   frame_3b961280_copy__44->SetMaximum(113.9314);
   frame_3b961280_copy__44->SetEntries(1);
   frame_3b961280_copy__44->SetDirectory(0);
   frame_3b961280_copy__44->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b961280_copy__44->SetLineColor(ci);
   frame_3b961280_copy__44->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b961280_copy__44->GetXaxis()->SetLabelFont(42);
   frame_3b961280_copy__44->GetXaxis()->SetTitleOffset(1);
   frame_3b961280_copy__44->GetXaxis()->SetTitleFont(42);
   frame_3b961280_copy__44->GetYaxis()->SetTitle("1/Events");
   frame_3b961280_copy__44->GetYaxis()->SetLabelFont(42);
   frame_3b961280_copy__44->GetYaxis()->SetTitleFont(42);
   frame_3b961280_copy__44->GetZaxis()->SetLabelFont(42);
   frame_3b961280_copy__44->GetZaxis()->SetTitleOffset(1);
   frame_3b961280_copy__44->GetZaxis()->SetTitleFont(42);
   frame_3b961280_copy__44->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-13.43664,2.25,120.9298);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3b939d80__45 = new TH1D("frame_3b939d80__45","p_T Balance",25,0,2);
   frame_3b939d80__45->SetBinContent(1,118.2425);
   frame_3b939d80__45->SetMaximum(118.2425);
   frame_3b939d80__45->SetEntries(1);
   frame_3b939d80__45->SetDirectory(0);
   frame_3b939d80__45->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b939d80__45->SetLineColor(ci);
   frame_3b939d80__45->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b939d80__45->GetXaxis()->SetLabelFont(42);
   frame_3b939d80__45->GetXaxis()->SetTitleOffset(1);
   frame_3b939d80__45->GetXaxis()->SetTitleFont(42);
   frame_3b939d80__45->GetYaxis()->SetTitle("1/Events");
   frame_3b939d80__45->GetYaxis()->SetLabelFont(42);
   frame_3b939d80__45->GetYaxis()->SetTitleFont(42);
   frame_3b939d80__45->GetZaxis()->SetLabelFont(42);
   frame_3b939d80__45->GetZaxis()->SetTitleOffset(1);
   frame_3b939d80__45->GetZaxis()->SetTitleFont(42);
   frame_3b939d80__45->Draw("FUNC");
   
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
   3,
   10,
   13,
   13,
   42,
   62,
   71,
   94,
   102,
   79,
   71,
   64,
   46,
   25,
   12,
   5,
   2,
   1,
   0,
   3,
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
   1.632705,
   3.108694,
   3.558662,
   3.558662,
   6.454831,
   7.852713,
   8.406258,
   9.678086,
   9.611874,
   8.869343,
   8.406258,
   7.979042,
   6.757581,
   4.966335,
   3.415266,
   2.159691,
   1.291815,
   0.8272462,
   0,
   1.632705,
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
   2.918186,
   4.26695,
   4.697573,
   4.697573,
   7.53218,
   8.916365,
   9.465736,
   10.72977,
   10.61187,
   9.925725,
   9.465736,
   9.041691,
   7.831489,
   6.066589,
   4.559819,
   3.382473,
   2.63786,
   2.299527,
   1.147874,
   2.918186,
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
   Graph_h_dh_data23012->SetMaximum(123.8731);
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
   
   Double_t observation_fx12[57] = {
   0.2806089,
   0.3036951,
   0.3267813,
   0.3498674,
   0.3729536,
   0.3960398,
   0.4191259,
   0.4422121,
   0.4652983,
   0.4883844,
   0.5114706,
   0.5345568,
   0.5576429,
   0.6038153,
   0.6499876,
   0.6730738,
   0.69616,
   0.7192461,
   0.7423323,
   0.7654185,
   0.7769616,
   0.7885046,
   0.8000477,
   0.8115908,
   0.8231339,
   0.834677,
   0.8462201,
   0.8577631,
   0.8693062,
   0.8808493,
   0.8923924,
   0.9039355,
   0.9154786,
   0.9270217,
   0.9385647,
   0.9501078,
   0.973194,
   0.9962802,
   1.019366,
   1.042452,
   1.065539,
   1.111711,
   1.134797,
   1.157883,
   1.18097,
   1.204056,
   1.227142,
   1.250228,
   1.273314,
   1.2964,
   1.319487,
   1.342573,
   1.365659,
   1.388745,
   1.411831,
   1.434917,
   1.434917};
   Double_t observation_fy12[57] = {
   4.850564,
   6.153954,
   7.731093,
   9.617281,
   11.84646,
   14.44938,
   17.45158,
   20.87108,
   24.71609,
   28.98273,
   33.65298,
   38.693,
   44.05204,
   55.43798,
   67.07296,
   72.69501,
   78.01648,
   82.90731,
   87.24167,
   90.90334,
   92.44949,
   93.79083,
   94.91775,
   95.82209,
   96.49727,
   96.93834,
   97.14206,
   97.10692,
   96.83319,
   96.32289,
   95.57976,
   94.60923,
   93.41837,
   92.01576,
   90.41143,
   88.61671,
   84.50719,
   79.79882,
   74.61462,
   69.08378,
   63.33634,
   51.68693,
   46.00782,
   40.55153,
   35.3922,
   30.5867,
   26.17473,
   22.17975,
   18.6104,
   15.46249,
   12.7212,
   10.36337,
   8.35986,
   6.677617,
   5.281639,
   4.136573,
   4.136573};
   graph = new TGraph(57,observation_fx12,observation_fy12);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation12 = new TH1F("Graph_observation12","Projection of obsf DSCB fit",100,0.1651781,1.550348);
   Graph_observation12->SetMinimum(3.722916);
   Graph_observation12->SetMaximum(106.4426);
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
   
   TH1D *frame_3b939d80__46 = new TH1D("frame_3b939d80__46","p_T Balance",25,0,2);
   frame_3b939d80__46->SetBinContent(1,118.2425);
   frame_3b939d80__46->SetMaximum(118.2425);
   frame_3b939d80__46->SetEntries(1);
   frame_3b939d80__46->SetDirectory(0);
   frame_3b939d80__46->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b939d80__46->SetLineColor(ci);
   frame_3b939d80__46->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b939d80__46->GetXaxis()->SetLabelFont(42);
   frame_3b939d80__46->GetXaxis()->SetTitleOffset(1);
   frame_3b939d80__46->GetXaxis()->SetTitleFont(42);
   frame_3b939d80__46->GetYaxis()->SetTitle("1/Events");
   frame_3b939d80__46->GetYaxis()->SetLabelFont(42);
   frame_3b939d80__46->GetYaxis()->SetTitleFont(42);
   frame_3b939d80__46->GetZaxis()->SetLabelFont(42);
   frame_3b939d80__46->GetZaxis()->SetTitleOffset(1);
   frame_3b939d80__46->GetZaxis()->SetTitleFont(42);
   frame_3b939d80__46->Draw("AXISSAME");
   
   TH1D *norm_o__47 = new TH1D("norm_o__47","",25,0,2);
   norm_o__47->SetBinContent(3,3);
   norm_o__47->SetBinContent(4,10);
   norm_o__47->SetBinContent(5,13);
   norm_o__47->SetBinContent(6,13);
   norm_o__47->SetBinContent(7,42);
   norm_o__47->SetBinContent(8,62);
   norm_o__47->SetBinContent(9,71);
   norm_o__47->SetBinContent(10,94);
   norm_o__47->SetBinContent(11,102);
   norm_o__47->SetBinContent(12,79);
   norm_o__47->SetBinContent(13,71);
   norm_o__47->SetBinContent(14,64);
   norm_o__47->SetBinContent(15,46);
   norm_o__47->SetBinContent(16,25);
   norm_o__47->SetBinContent(17,12);
   norm_o__47->SetBinContent(18,5);
   norm_o__47->SetBinContent(19,2);
   norm_o__47->SetBinContent(20,1);
   norm_o__47->SetBinContent(22,3);
   norm_o__47->SetMinimum(0);
   norm_o__47->SetMaximum(224.4);
   norm_o__47->SetEntries(718);
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
   entry=leg->AddEntry("frame_x_o2_3b939d80","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.850265 #pm 0.009238","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.232682 #pm 0.007671","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.958000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_3b939d80_copy__48 = new TH1D("frame_3b939d80_copy__48","p_T Balance",25,0,2);
   frame_3b939d80_copy__48->SetBinContent(1,118.2425);
   frame_3b939d80_copy__48->SetMaximum(118.2425);
   frame_3b939d80_copy__48->SetEntries(1);
   frame_3b939d80_copy__48->SetDirectory(0);
   frame_3b939d80_copy__48->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3b939d80_copy__48->SetLineColor(ci);
   frame_3b939d80_copy__48->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3b939d80_copy__48->GetXaxis()->SetLabelFont(42);
   frame_3b939d80_copy__48->GetXaxis()->SetTitleOffset(1);
   frame_3b939d80_copy__48->GetXaxis()->SetTitleFont(42);
   frame_3b939d80_copy__48->GetYaxis()->SetTitle("1/Events");
   frame_3b939d80_copy__48->GetYaxis()->SetLabelFont(42);
   frame_3b939d80_copy__48->GetYaxis()->SetTitleFont(42);
   frame_3b939d80_copy__48->GetZaxis()->SetLabelFont(42);
   frame_3b939d80_copy__48->GetZaxis()->SetTitleOffset(1);
   frame_3b939d80_copy__48->GetZaxis()->SetTitleFont(42);
   frame_3b939d80_copy__48->Draw("sameaxis");
   
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
