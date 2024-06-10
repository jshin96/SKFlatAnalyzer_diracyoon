void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_4__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 18:49:27 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-21.65997,2.25,249.0897);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_4184a650__49 = new TH1D("frame_4184a650__49","p_T Balance",25,0,2);
   frame_4184a650__49->SetBinContent(1,222.0147);
   frame_4184a650__49->SetMaximum(222.0147);
   frame_4184a650__49->SetEntries(1);
   frame_4184a650__49->SetDirectory(0);
   frame_4184a650__49->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_4184a650__49->SetLineColor(ci);
   frame_4184a650__49->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4184a650__49->GetXaxis()->SetLabelFont(42);
   frame_4184a650__49->GetXaxis()->SetTitleOffset(1);
   frame_4184a650__49->GetXaxis()->SetTitleFont(42);
   frame_4184a650__49->GetYaxis()->SetTitle("1/Events");
   frame_4184a650__49->GetYaxis()->SetLabelFont(42);
   frame_4184a650__49->GetYaxis()->SetTitleFont(42);
   frame_4184a650__49->GetZaxis()->SetLabelFont(42);
   frame_4184a650__49->GetZaxis()->SetTitleOffset(1);
   frame_4184a650__49->GetZaxis()->SetTitleFont(42);
   frame_4184a650__49->Draw("FUNC");
   
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
   4.506627,
   13.58766,
   30.12563,
   49.70607,
   68.80755,
   103.1204,
   164.4284,
   177.5168,
   202.03,
   175.026,
   150.539,
   111.6493,
   69.43621,
   44.8187,
   24.50914,
   11.69141,
   5.546359,
   3.851514,
   1.019731,
   1.138214,
   0.5756392,
   0.3293076,
   0.3998723};
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
   1.2724,
   1.983936,
   3.553878,
   4.434999,
   5.530713,
   6.627376,
   8.484424,
   8.835431,
   9.412586,
   8.615274,
   7.890483,
   6.663324,
   5.378069,
   4.110154,
   2.863599,
   1.906511,
   1.144785,
   1.053404,
   0.4763946,
   0.3957417,
   0.2889882,
   0.2353835,
   0.1933498};
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
   1.2724,
   1.983936,
   3.553878,
   4.434999,
   5.530713,
   6.627376,
   8.484424,
   8.835431,
   9.412586,
   8.615274,
   7.890483,
   6.663324,
   5.378069,
   4.110154,
   2.863599,
   1.906511,
   1.144785,
   1.053404,
   0.4763946,
   0.3957417,
   0.2889882,
   0.2353835,
   0.1933498};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3013,h_dh_central2_fy3013,h_dh_central2_felx3013,h_dh_central2_fehx3013,h_dh_central2_fely3013,h_dh_central2_fehy3013);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23013 = new TH1F("Graph_h_dh_central23013","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23013->SetMinimum(0);
   Graph_h_dh_central23013->SetMaximum(232.5868);
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
   0.2287659,
   0.2528793,
   0.2769928,
   0.3011063,
   0.3252198,
   0.3493333,
   0.3734467,
   0.3975602,
   0.4216737,
   0.4457872,
   0.4699007,
   0.4940141,
   0.5181276,
   0.5422411,
   0.5663546,
   0.6145815,
   0.638695,
   0.6628085,
   0.686922,
   0.7110355,
   0.7351489,
   0.7472057,
   0.7592624,
   0.7713192,
   0.7833759,
   0.7954326,
   0.8074894,
   0.8195461,
   0.8316029,
   0.8436596,
   0.8557163,
   0.8677731,
   0.8798298,
   0.8918866,
   0.9039433,
   0.916,
   0.9280568,
   0.9521703,
   0.9762837,
   1.000397,
   1.024511,
   1.048624,
   1.096851,
   1.120965,
   1.145078,
   1.169192,
   1.193305,
   1.217419,
   1.241532,
   1.265645,
   1.289759,
   1.313872,
   1.337986,
   1.362099,
   1.374156,
   1.386213,
   1.43444,
   1.43444};
   Double_t Central_fy13[58] = {
   7.055701,
   9.123404,
   11.67464,
   14.78426,
   18.52787,
   22.97847,
   28.20242,
   34.25479,
   41.17427,
   48.97792,
   57.65598,
   67.16734,
   77.43577,
   88.34761,
   99.75109,
   123.2459,
   134.8666,
   146.0515,
   156.5228,
   166.004,
   174.2326,
   177.8017,
   180.9713,
   183.7178,
   186.0201,
   187.8608,
   189.2256,
   190.1038,
   190.4888,
   190.3774,
   189.7705,
   188.6728,
   187.093,
   185.0432,
   182.5392,
   179.6002,
   176.2482,
   168.408,
   159.2467,
   149.0211,
   138.0051,
   126.4771,
   102.9567,
   91.44935,
   80.38524,
   69.92648,
   60.19726,
   51.28395,
   43.23703,
   36.07448,
   29.78612,
   24.3387,
   19.68116,
   15.74975,
   14.80114,
   14.40844,
   13.7196,
   13.7196};
   TGraph *graph = new TGraph(58,Central_fx13,Central_fy13);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central13 = new TH1F("Graph_Central13","Projection of centralf DSCB fit",100,0.1081985,1.555007);
   Graph_Central13->SetMinimum(6.35013);
   Graph_Central13->SetMaximum(208.8321);
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
   
   TH1D *frame_4184a650__50 = new TH1D("frame_4184a650__50","p_T Balance",25,0,2);
   frame_4184a650__50->SetBinContent(1,222.0147);
   frame_4184a650__50->SetMaximum(222.0147);
   frame_4184a650__50->SetEntries(1);
   frame_4184a650__50->SetDirectory(0);
   frame_4184a650__50->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4184a650__50->SetLineColor(ci);
   frame_4184a650__50->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4184a650__50->GetXaxis()->SetLabelFont(42);
   frame_4184a650__50->GetXaxis()->SetTitleOffset(1);
   frame_4184a650__50->GetXaxis()->SetTitleFont(42);
   frame_4184a650__50->GetYaxis()->SetTitle("1/Events");
   frame_4184a650__50->GetYaxis()->SetLabelFont(42);
   frame_4184a650__50->GetYaxis()->SetTitleFont(42);
   frame_4184a650__50->GetZaxis()->SetLabelFont(42);
   frame_4184a650__50->GetZaxis()->SetTitleOffset(1);
   frame_4184a650__50->GetZaxis()->SetTitleFont(42);
   frame_4184a650__50->Draw("AXISSAME");
   
   TH1D *norm_c__51 = new TH1D("norm_c__51","",25,0,2);
   norm_c__51->SetBinContent(3,4.506627);
   norm_c__51->SetBinContent(4,13.58766);
   norm_c__51->SetBinContent(5,30.12563);
   norm_c__51->SetBinContent(6,49.70607);
   norm_c__51->SetBinContent(7,68.80755);
   norm_c__51->SetBinContent(8,103.1204);
   norm_c__51->SetBinContent(9,164.4284);
   norm_c__51->SetBinContent(10,177.5168);
   norm_c__51->SetBinContent(11,202.03);
   norm_c__51->SetBinContent(12,175.026);
   norm_c__51->SetBinContent(13,150.539);
   norm_c__51->SetBinContent(14,111.6493);
   norm_c__51->SetBinContent(15,69.43621);
   norm_c__51->SetBinContent(16,44.8187);
   norm_c__51->SetBinContent(17,24.50914);
   norm_c__51->SetBinContent(18,11.69141);
   norm_c__51->SetBinContent(19,5.546358);
   norm_c__51->SetBinContent(20,3.851514);
   norm_c__51->SetBinContent(21,1.019731);
   norm_c__51->SetBinContent(22,1.138214);
   norm_c__51->SetBinContent(23,0.5756392);
   norm_c__51->SetBinContent(24,0.3293076);
   norm_c__51->SetBinContent(25,0.3998723);
   norm_c__51->SetBinContent(26,1.116523);
   norm_c__51->SetBinError(3,1.2724);
   norm_c__51->SetBinError(4,1.983936);
   norm_c__51->SetBinError(5,3.553878);
   norm_c__51->SetBinError(6,4.434999);
   norm_c__51->SetBinError(7,5.530713);
   norm_c__51->SetBinError(8,6.627376);
   norm_c__51->SetBinError(9,8.484424);
   norm_c__51->SetBinError(10,8.835431);
   norm_c__51->SetBinError(11,9.412586);
   norm_c__51->SetBinError(12,8.615274);
   norm_c__51->SetBinError(13,7.890483);
   norm_c__51->SetBinError(14,6.663324);
   norm_c__51->SetBinError(15,5.378069);
   norm_c__51->SetBinError(16,4.110154);
   norm_c__51->SetBinError(17,2.863599);
   norm_c__51->SetBinError(18,1.906511);
   norm_c__51->SetBinError(19,1.144785);
   norm_c__51->SetBinError(20,1.053404);
   norm_c__51->SetBinError(21,0.4763946);
   norm_c__51->SetBinError(22,0.3957417);
   norm_c__51->SetBinError(23,0.2889882);
   norm_c__51->SetBinError(24,0.2353835);
   norm_c__51->SetBinError(25,0.1933498);
   norm_c__51->SetBinError(26,0.2868048);
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
   entry=leg->AddEntry("frame_x_c2_4184a650","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.836206 #pm 0.006639","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.237738 #pm 0.005414","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.985000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_4184a650_copy__52 = new TH1D("frame_4184a650_copy__52","p_T Balance",25,0,2);
   frame_4184a650_copy__52->SetBinContent(1,222.0147);
   frame_4184a650_copy__52->SetMaximum(222.0147);
   frame_4184a650_copy__52->SetEntries(1);
   frame_4184a650_copy__52->SetDirectory(0);
   frame_4184a650_copy__52->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4184a650_copy__52->SetLineColor(ci);
   frame_4184a650_copy__52->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4184a650_copy__52->GetXaxis()->SetLabelFont(42);
   frame_4184a650_copy__52->GetXaxis()->SetTitleOffset(1);
   frame_4184a650_copy__52->GetXaxis()->SetTitleFont(42);
   frame_4184a650_copy__52->GetYaxis()->SetTitle("1/Events");
   frame_4184a650_copy__52->GetYaxis()->SetLabelFont(42);
   frame_4184a650_copy__52->GetYaxis()->SetTitleFont(42);
   frame_4184a650_copy__52->GetZaxis()->SetLabelFont(42);
   frame_4184a650_copy__52->GetZaxis()->SetTitleOffset(1);
   frame_4184a650_copy__52->GetZaxis()->SetTitleFont(42);
   frame_4184a650_copy__52->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-22.20604,2.25,255.3694);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_41845c70__53 = new TH1D("frame_41845c70__53","p_T Balance",25,0,2);
   frame_41845c70__53->SetBinContent(1,227.6119);
   frame_41845c70__53->SetMaximum(227.6119);
   frame_41845c70__53->SetEntries(1);
   frame_41845c70__53->SetDirectory(0);
   frame_41845c70__53->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_41845c70__53->SetLineColor(ci);
   frame_41845c70__53->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_41845c70__53->GetXaxis()->SetLabelFont(42);
   frame_41845c70__53->GetXaxis()->SetTitleOffset(1);
   frame_41845c70__53->GetXaxis()->SetTitleFont(42);
   frame_41845c70__53->GetYaxis()->SetTitle("1/Events");
   frame_41845c70__53->GetYaxis()->SetLabelFont(42);
   frame_41845c70__53->GetYaxis()->SetTitleFont(42);
   frame_41845c70__53->GetZaxis()->SetLabelFont(42);
   frame_41845c70__53->GetZaxis()->SetTitleOffset(1);
   frame_41845c70__53->GetZaxis()->SetTitleFont(42);
   frame_41845c70__53->Draw("FUNC");
   
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
   3.85743,
   12.59007,
   24.84578,
   46.00484,
   63.09901,
   99.30917,
   147.514,
   175.4615,
   207.1454,
   199.1378,
   169.3613,
   126.9642,
   79.72398,
   46.19827,
   34.1539,
   12.09599,
   7.941697,
   3.046031,
   1.375284,
   1.326436,
   1.022987,
   0.3280159,
   0.41106};
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
   1.267503,
   1.893638,
   3.168612,
   4.324617,
   4.953984,
   6.769145,
   8.15056,
   8.839475,
   9.627761,
   9.350985,
   8.516138,
   7.235757,
   5.816187,
   4.153677,
   3.538649,
   1.871776,
   1.427225,
   0.8983407,
   0.483314,
   0.4443866,
   0.4760649,
   0.2337761,
   0.2129553};
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
   1.267503,
   1.893638,
   3.168612,
   4.324617,
   4.953984,
   6.769145,
   8.15056,
   8.839475,
   9.627761,
   9.350985,
   8.516138,
   7.235757,
   5.816187,
   4.153677,
   3.538649,
   1.871776,
   1.427225,
   0.8983407,
   0.483314,
   0.4443866,
   0.4760649,
   0.2337761,
   0.2129553};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3014,h_dh_up2_fy3014,h_dh_up2_felx3014,h_dh_up2_fehx3014,h_dh_up2_fely3014,h_dh_up2_fehy3014);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23014 = new TH1F("Graph_h_dh_up23014","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23014->SetMinimum(0);
   Graph_h_dh_up23014->SetMaximum(238.4505);
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
   0.2629847,
   0.3104598,
   0.3579348,
   0.3816724,
   0.4054099,
   0.4291475,
   0.452885,
   0.4766225,
   0.4884913,
   0.5003601,
   0.5240976,
   0.5478352,
   0.5715727,
   0.5953102,
   0.6427853,
   0.6665229,
   0.6902604,
   0.7139979,
   0.7377355,
   0.761473,
   0.7733418,
   0.7852106,
   0.7970793,
   0.8089481,
   0.8208169,
   0.8326856,
   0.8445544,
   0.8564232,
   0.8682919,
   0.8801607,
   0.8920295,
   0.9038982,
   0.915767,
   0.9276358,
   0.9395046,
   0.9513733,
   0.9632421,
   0.9751109,
   0.9988484,
   1.022586,
   1.046323,
   1.070061,
   1.117536,
   1.141274,
   1.165011,
   1.188749,
   1.212486,
   1.236224,
   1.259961,
   1.283699,
   1.307436,
   1.331174,
   1.354912,
   1.378649,
   1.402387,
   1.426124,
   1.449862,
   1.449862};
   Double_t up_fy14[58] = {
   17.2797,
   20.97006,
   25.91916,
   29.048,
   32.75408,
   37.18515,
   42.53864,
   49.08296,
   52.91266,
   57.19011,
   67.02402,
   77.78776,
   89.30718,
   101.4275,
   126.6419,
   139.229,
   151.4176,
   162.8985,
   173.3613,
   182.5079,
   186.5012,
   190.0664,
   193.1757,
   195.8048,
   197.9327,
   199.5425,
   200.6213,
   201.1602,
   201.1549,
   200.6055,
   199.5164,
   197.8965,
   195.7586,
   193.1201,
   190.0017,
   186.428,
   182.4267,
   178.0283,
   168.175,
   157.1549,
   145.2743,
   132.8446,
   107.5318,
   95.18645,
   83.35035,
   72.19947,
   61.8664,
   52.44088,
   43.97233,
   36.47398,
   29.92824,
   24.29257,
   19.50563,
   15.49319,
   12.17352,
   9.462058,
   7.275274,
   7.275274};
   graph = new TGraph(58,up_fx14,up_fy14);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up14 = new TH1F("Graph_up14","Projection of upf DSCB fit",100,0.144297,1.568549);
   Graph_up14->SetMinimum(6.547746);
   Graph_up14->SetMaximum(220.5487);
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
   
   TH1D *frame_41845c70__54 = new TH1D("frame_41845c70__54","p_T Balance",25,0,2);
   frame_41845c70__54->SetBinContent(1,227.6119);
   frame_41845c70__54->SetMaximum(227.6119);
   frame_41845c70__54->SetEntries(1);
   frame_41845c70__54->SetDirectory(0);
   frame_41845c70__54->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_41845c70__54->SetLineColor(ci);
   frame_41845c70__54->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_41845c70__54->GetXaxis()->SetLabelFont(42);
   frame_41845c70__54->GetXaxis()->SetTitleOffset(1);
   frame_41845c70__54->GetXaxis()->SetTitleFont(42);
   frame_41845c70__54->GetYaxis()->SetTitle("1/Events");
   frame_41845c70__54->GetYaxis()->SetLabelFont(42);
   frame_41845c70__54->GetYaxis()->SetTitleFont(42);
   frame_41845c70__54->GetZaxis()->SetLabelFont(42);
   frame_41845c70__54->GetZaxis()->SetTitleOffset(1);
   frame_41845c70__54->GetZaxis()->SetTitleFont(42);
   frame_41845c70__54->Draw("AXISSAME");
   
   TH1D *norm_u__55 = new TH1D("norm_u__55","",25,0,2);
   norm_u__55->SetBinContent(3,3.85743);
   norm_u__55->SetBinContent(4,12.59007);
   norm_u__55->SetBinContent(5,24.84578);
   norm_u__55->SetBinContent(6,46.00484);
   norm_u__55->SetBinContent(7,63.09902);
   norm_u__55->SetBinContent(8,99.30917);
   norm_u__55->SetBinContent(9,147.514);
   norm_u__55->SetBinContent(10,175.4615);
   norm_u__55->SetBinContent(11,207.1454);
   norm_u__55->SetBinContent(12,199.1378);
   norm_u__55->SetBinContent(13,169.3613);
   norm_u__55->SetBinContent(14,126.9642);
   norm_u__55->SetBinContent(15,79.72398);
   norm_u__55->SetBinContent(16,46.19827);
   norm_u__55->SetBinContent(17,34.1539);
   norm_u__55->SetBinContent(18,12.09599);
   norm_u__55->SetBinContent(19,7.941697);
   norm_u__55->SetBinContent(20,3.046031);
   norm_u__55->SetBinContent(21,1.375284);
   norm_u__55->SetBinContent(22,1.326436);
   norm_u__55->SetBinContent(23,1.022987);
   norm_u__55->SetBinContent(24,0.3280159);
   norm_u__55->SetBinContent(25,0.41106);
   norm_u__55->SetBinContent(26,0.9785126);
   norm_u__55->SetBinError(3,1.267503);
   norm_u__55->SetBinError(4,1.893638);
   norm_u__55->SetBinError(5,3.168612);
   norm_u__55->SetBinError(6,4.324617);
   norm_u__55->SetBinError(7,4.953984);
   norm_u__55->SetBinError(8,6.769145);
   norm_u__55->SetBinError(9,8.15056);
   norm_u__55->SetBinError(10,8.839475);
   norm_u__55->SetBinError(11,9.627761);
   norm_u__55->SetBinError(12,9.350985);
   norm_u__55->SetBinError(13,8.516138);
   norm_u__55->SetBinError(14,7.235757);
   norm_u__55->SetBinError(15,5.816187);
   norm_u__55->SetBinError(16,4.153677);
   norm_u__55->SetBinError(17,3.538649);
   norm_u__55->SetBinError(18,1.871776);
   norm_u__55->SetBinError(19,1.427225);
   norm_u__55->SetBinError(20,0.8983407);
   norm_u__55->SetBinError(21,0.483314);
   norm_u__55->SetBinError(22,0.4443866);
   norm_u__55->SetBinError(23,0.4760649);
   norm_u__55->SetBinError(24,0.2337761);
   norm_u__55->SetBinError(25,0.2129553);
   norm_u__55->SetBinError(26,0.2774032);
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
   entry=leg->AddEntry("frame_x_u2_41845c70","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.862305 #pm 0.006949","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.228075 #pm 0.006128","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.995000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_41845c70_copy__56 = new TH1D("frame_41845c70_copy__56","p_T Balance",25,0,2);
   frame_41845c70_copy__56->SetBinContent(1,227.6119);
   frame_41845c70_copy__56->SetMaximum(227.6119);
   frame_41845c70_copy__56->SetEntries(1);
   frame_41845c70_copy__56->SetDirectory(0);
   frame_41845c70_copy__56->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_41845c70_copy__56->SetLineColor(ci);
   frame_41845c70_copy__56->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_41845c70_copy__56->GetXaxis()->SetLabelFont(42);
   frame_41845c70_copy__56->GetXaxis()->SetTitleOffset(1);
   frame_41845c70_copy__56->GetXaxis()->SetTitleFont(42);
   frame_41845c70_copy__56->GetYaxis()->SetTitle("1/Events");
   frame_41845c70_copy__56->GetYaxis()->SetLabelFont(42);
   frame_41845c70_copy__56->GetYaxis()->SetTitleFont(42);
   frame_41845c70_copy__56->GetZaxis()->SetLabelFont(42);
   frame_41845c70_copy__56->GetZaxis()->SetTitleOffset(1);
   frame_41845c70_copy__56->GetZaxis()->SetTitleFont(42);
   frame_41845c70_copy__56->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-24.09322,2.25,216.839);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_41830590__57 = new TH1D("frame_41830590__57","p_T Balance",25,0,2);
   frame_41830590__57->SetBinContent(1,212.0204);
   frame_41830590__57->SetMaximum(212.0204);
   frame_41830590__57->SetEntries(1);
   frame_41830590__57->SetDirectory(0);
   frame_41830590__57->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_41830590__57->SetLineColor(ci);
   frame_41830590__57->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_41830590__57->GetXaxis()->SetLabelFont(42);
   frame_41830590__57->GetXaxis()->SetTitleOffset(1);
   frame_41830590__57->GetXaxis()->SetTitleFont(42);
   frame_41830590__57->GetYaxis()->SetTitle("1/Events");
   frame_41830590__57->GetYaxis()->SetLabelFont(42);
   frame_41830590__57->GetYaxis()->SetTitleFont(42);
   frame_41830590__57->GetZaxis()->SetLabelFont(42);
   frame_41830590__57->GetZaxis()->SetTitleOffset(1);
   frame_41830590__57->GetZaxis()->SetTitleFont(42);
   frame_41830590__57->Draw("FUNC");
   
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
   4.12042,
   12.57512,
   30.79591,
   45.62649,
   78.06062,
   101.8413,
   167.3458,
   184.1384,
   192.7417,
   168.8835,
   146.8641,
   103.7171,
   68.10187,
   40.91883,
   23.72805,
   11.62713,
   5.786488,
   3.689862,
   0.9147189,
   1.379761,
   0.6608021,
   0.4754028,
   0.2209544};
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
   1.068798,
   1.771238,
   3.486727,
   4.174132,
   5.805525,
   6.483169,
   8.631445,
   9.036431,
   9.182421,
   8.403275,
   7.876297,
   6.361083,
   5.266882,
   3.877012,
   2.894433,
   1.829934,
   1.135732,
   1.053275,
   0.3647593,
   0.5578022,
   0.2889784,
   0.2837866,
   0.1085964};
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
   1.068798,
   1.771238,
   3.486727,
   4.174132,
   5.805525,
   6.483169,
   8.631445,
   9.036431,
   9.182421,
   8.403275,
   7.876297,
   6.361083,
   5.266882,
   3.877012,
   2.894433,
   1.829934,
   1.135732,
   1.053275,
   0.3647593,
   0.5578022,
   0.2889784,
   0.2837866,
   0.1085964};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3015,h_dh_down2_fy3015,h_dh_down2_felx3015,h_dh_down2_fehx3015,h_dh_down2_fely3015,h_dh_down2_fehy3015);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23015 = new TH1F("Graph_h_dh_down23015","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23015->SetMinimum(0);
   Graph_h_dh_down23015->SetMaximum(222.1166);
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
   0.2526893,
   0.2993408,
   0.3226665,
   0.3459923,
   0.369318,
   0.3926438,
   0.4159695,
   0.4392953,
   0.462621,
   0.4742839,
   0.4859468,
   0.5092725,
   0.5325983,
   0.555924,
   0.5792497,
   0.6259012,
   0.649227,
   0.6725527,
   0.6958785,
   0.7192042,
   0.7308671,
   0.74253,
   0.7541929,
   0.7658557,
   0.7775186,
   0.7891815,
   0.8008444,
   0.8125072,
   0.8241701,
   0.835833,
   0.8474959,
   0.8591587,
   0.8708216,
   0.8824845,
   0.8941474,
   0.9058102,
   0.9174731,
   0.929136,
   0.9524617,
   0.9757875,
   0.9991132,
   1.022439,
   1.045765,
   1.092416,
   1.115742,
   1.139068,
   1.162393,
   1.185719,
   1.197382,
   1.209045,
   1.232371,
   1.255696,
   1.279022,
   1.302348,
   1.325674,
   1.348999,
   1.372325,
   1.418977,
   1.418977};
   Double_t down_fy15[59] = {
   16.17047,
   20.36943,
   22.98072,
   26.0242,
   29.58861,
   33.78472,
   38.75174,
   44.66606,
   51.75299,
   55.82383,
   60.30291,
   70.18383,
   80.82282,
   92.08922,
   103.8153,
   127.7911,
   139.5362,
   150.7479,
   161.1363,
   170.4172,
   174.5581,
   178.3246,
   181.6883,
   184.6235,
   187.1077,
   189.1214,
   190.6489,
   191.678,
   192.2007,
   192.2126,
   191.7138,
   190.7081,
   189.2037,
   187.2124,
   184.7498,
   181.8351,
   178.4909,
   174.7426,
   166.149,
   156.3056,
   145.4887,
   133.9868,
   122.0878,
   98.18092,
   86.65054,
   75.6647,
   65.37223,
   55.89002,
   51.63646,
   47.78209,
   41.09941,
   35.55073,
   30.91208,
   27.00954,
   23.70684,
   20.89632,
   18.49227,
   14.6417,
   14.6417};
   graph = new TGraph(59,down_fx15,down_fy15);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down15 = new TH1F("Graph_down15","Projection of downf DSCB fit",100,0.1360605,1.535605);
   Graph_down15->SetMinimum(13.17753);
   Graph_down15->SetMaximum(209.9697);
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
   
   TH1D *frame_41830590__58 = new TH1D("frame_41830590__58","p_T Balance",25,0,2);
   frame_41830590__58->SetBinContent(1,212.0204);
   frame_41830590__58->SetMaximum(212.0204);
   frame_41830590__58->SetEntries(1);
   frame_41830590__58->SetDirectory(0);
   frame_41830590__58->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_41830590__58->SetLineColor(ci);
   frame_41830590__58->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_41830590__58->GetXaxis()->SetLabelFont(42);
   frame_41830590__58->GetXaxis()->SetTitleOffset(1);
   frame_41830590__58->GetXaxis()->SetTitleFont(42);
   frame_41830590__58->GetYaxis()->SetTitle("1/Events");
   frame_41830590__58->GetYaxis()->SetLabelFont(42);
   frame_41830590__58->GetYaxis()->SetTitleFont(42);
   frame_41830590__58->GetZaxis()->SetLabelFont(42);
   frame_41830590__58->GetZaxis()->SetTitleOffset(1);
   frame_41830590__58->GetZaxis()->SetTitleFont(42);
   frame_41830590__58->Draw("AXISSAME");
   
   TH1D *norm_d__59 = new TH1D("norm_d__59","",25,0,2);
   norm_d__59->SetBinContent(3,4.12042);
   norm_d__59->SetBinContent(4,12.57512);
   norm_d__59->SetBinContent(5,30.79591);
   norm_d__59->SetBinContent(6,45.62649);
   norm_d__59->SetBinContent(7,78.06061);
   norm_d__59->SetBinContent(8,101.8413);
   norm_d__59->SetBinContent(9,167.3458);
   norm_d__59->SetBinContent(10,184.1384);
   norm_d__59->SetBinContent(11,192.7417);
   norm_d__59->SetBinContent(12,168.8835);
   norm_d__59->SetBinContent(13,146.8641);
   norm_d__59->SetBinContent(14,103.7171);
   norm_d__59->SetBinContent(15,68.10187);
   norm_d__59->SetBinContent(16,40.91883);
   norm_d__59->SetBinContent(17,23.72805);
   norm_d__59->SetBinContent(18,11.62713);
   norm_d__59->SetBinContent(19,5.786488);
   norm_d__59->SetBinContent(20,3.689862);
   norm_d__59->SetBinContent(21,0.9147189);
   norm_d__59->SetBinContent(22,1.379761);
   norm_d__59->SetBinContent(23,0.6608021);
   norm_d__59->SetBinContent(24,0.4754028);
   norm_d__59->SetBinContent(25,0.2209544);
   norm_d__59->SetBinContent(26,1.01975);
   norm_d__59->SetBinError(3,1.068798);
   norm_d__59->SetBinError(4,1.771238);
   norm_d__59->SetBinError(5,3.486727);
   norm_d__59->SetBinError(6,4.174132);
   norm_d__59->SetBinError(7,5.805525);
   norm_d__59->SetBinError(8,6.483169);
   norm_d__59->SetBinError(9,8.631445);
   norm_d__59->SetBinError(10,9.036431);
   norm_d__59->SetBinError(11,9.182421);
   norm_d__59->SetBinError(12,8.403275);
   norm_d__59->SetBinError(13,7.876297);
   norm_d__59->SetBinError(14,6.361083);
   norm_d__59->SetBinError(15,5.266882);
   norm_d__59->SetBinError(16,3.877012);
   norm_d__59->SetBinError(17,2.894433);
   norm_d__59->SetBinError(18,1.829934);
   norm_d__59->SetBinError(19,1.135732);
   norm_d__59->SetBinError(20,1.053275);
   norm_d__59->SetBinError(21,0.3647593);
   norm_d__59->SetBinError(22,0.5578022);
   norm_d__59->SetBinError(23,0.2889784);
   norm_d__59->SetBinError(24,0.2837866);
   norm_d__59->SetBinError(25,0.1085964);
   norm_d__59->SetBinError(26,0.266368);
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
   entry=leg->AddEntry("frame_x_d2_41830590","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.829887 #pm 0.006814","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.239628 #pm 0.005717","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.994000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_41830590_copy__60 = new TH1D("frame_41830590_copy__60","p_T Balance",25,0,2);
   frame_41830590_copy__60->SetBinContent(1,212.0204);
   frame_41830590_copy__60->SetMaximum(212.0204);
   frame_41830590_copy__60->SetEntries(1);
   frame_41830590_copy__60->SetDirectory(0);
   frame_41830590_copy__60->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_41830590_copy__60->SetLineColor(ci);
   frame_41830590_copy__60->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_41830590_copy__60->GetXaxis()->SetLabelFont(42);
   frame_41830590_copy__60->GetXaxis()->SetTitleOffset(1);
   frame_41830590_copy__60->GetXaxis()->SetTitleFont(42);
   frame_41830590_copy__60->GetYaxis()->SetTitle("1/Events");
   frame_41830590_copy__60->GetYaxis()->SetLabelFont(42);
   frame_41830590_copy__60->GetYaxis()->SetTitleFont(42);
   frame_41830590_copy__60->GetZaxis()->SetLabelFont(42);
   frame_41830590_copy__60->GetZaxis()->SetTitleOffset(1);
   frame_41830590_copy__60->GetZaxis()->SetTitleFont(42);
   frame_41830590_copy__60->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-23.26262,2.25,209.3636);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_41839150__61 = new TH1D("frame_41839150__61","p_T Balance",25,0,2);
   frame_41839150__61->SetBinContent(1,204.7111);
   frame_41839150__61->SetMaximum(204.7111);
   frame_41839150__61->SetEntries(1);
   frame_41839150__61->SetDirectory(0);
   frame_41839150__61->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_41839150__61->SetLineColor(ci);
   frame_41839150__61->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_41839150__61->GetXaxis()->SetLabelFont(42);
   frame_41839150__61->GetXaxis()->SetTitleOffset(1);
   frame_41839150__61->GetXaxis()->SetTitleFont(42);
   frame_41839150__61->GetYaxis()->SetTitle("1/Events");
   frame_41839150__61->GetYaxis()->SetLabelFont(42);
   frame_41839150__61->GetYaxis()->SetTitleFont(42);
   frame_41839150__61->GetZaxis()->SetLabelFont(42);
   frame_41839150__61->GetZaxis()->SetTitleOffset(1);
   frame_41839150__61->GetZaxis()->SetTitleFont(42);
   frame_41839150__61->Draw("FUNC");
   
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
   28,
   48,
   51,
   77,
   144,
   163,
   174,
   181,
   180,
   133,
   104,
   71,
   41,
   21,
   21,
   8,
   6,
   1,
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
   1.914339,
   5.259711,
   6.903979,
   7.117933,
   8.755868,
   11.51041,
   12.27693,
   12.70038,
   12.96291,
   12.92572,
   11.0434,
   9.710289,
   8.406258,
   6.376898,
   4.545807,
   4.545807,
   2.768386,
   2.379931,
   0.8272462,
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
   3.162753,
   6.354446,
   7.97633,
   8.188122,
   9.812979,
   12.51041,
   13.27693,
   13.70038,
   13.96291,
   13.92572,
   12.0434,
   10.71029,
   9.465736,
   7.455185,
   5.655182,
   5.655182,
   3.945142,
   3.583642,
   2.299527,
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
   Graph_h_dh_data23016->SetMaximum(214.4592);
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
   0.1204698,
   0.1474976,
   0.1745254,
   0.2015532,
   0.228581,
   0.2556087,
   0.2826365,
   0.3096643,
   0.3366921,
   0.3637199,
   0.3907477,
   0.4177755,
   0.4448032,
   0.471831,
   0.4988588,
   0.5529144,
   0.60697,
   0.6339977,
   0.6610255,
   0.6880533,
   0.7015672,
   0.7150811,
   0.728595,
   0.7421089,
   0.7556228,
   0.7691367,
   0.7826506,
   0.7961645,
   0.8096783,
   0.8231922,
   0.8367061,
   0.85022,
   0.8637339,
   0.8772478,
   0.8907617,
   0.9042756,
   0.9177895,
   0.9313034,
   0.9583312,
   0.9853589,
   1.012387,
   1.039415,
   1.09347,
   1.120498,
   1.147526,
   1.174553,
   1.201581,
   1.228609,
   1.255637,
   1.282665,
   1.309692,
   1.33672,
   1.363748,
   1.390776,
   1.417804,
   1.444831,
   1.471859,
   1.471859};
   Double_t observation_fy16[58] = {
   4.136545,
   5.528674,
   7.305269,
   9.542032,
   12.32069,
   15.72601,
   19.84227,
   24.74877,
   30.51443,
   37.19173,
   44.81019,
   53.36994,
   62.83564,
   73.13154,
   84.13812,
   107.5814,
   131.3528,
   142.6509,
   153.1436,
   162.5223,
   166.702,
   170.4968,
   173.8757,
   176.8109,
   179.2777,
   181.2555,
   182.7272,
   183.6803,
   184.1066,
   184.0024,
   183.3687,
   182.2107,
   180.5386,
   178.3667,
   175.7133,
   172.6008,
   169.0552,
   165.1055,
   156.1239,
   145.9375,
   134.8508,
   123.177,
   99.2774,
   87.59812,
   76.4062,
   65.87973,
   56.15189,
   47.31147,
   39.40559,
   32.44432,
   26.40638,
   21.24558,
   16.89731,
   13.28483,
   10.32485,
   7.932336,
   6.024316,
   6.024316};
   graph = new TGraph(58,observation_fx16,observation_fy16);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation16 = new TH1F("Graph_observation16","Projection of obsf DSCB fit",100,0,1.606998);
   Graph_observation16->SetMinimum(3.72289);
   Graph_observation16->SetMaximum(202.1036);
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
   
   TH1D *frame_41839150__62 = new TH1D("frame_41839150__62","p_T Balance",25,0,2);
   frame_41839150__62->SetBinContent(1,204.7111);
   frame_41839150__62->SetMaximum(204.7111);
   frame_41839150__62->SetEntries(1);
   frame_41839150__62->SetDirectory(0);
   frame_41839150__62->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_41839150__62->SetLineColor(ci);
   frame_41839150__62->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_41839150__62->GetXaxis()->SetLabelFont(42);
   frame_41839150__62->GetXaxis()->SetTitleOffset(1);
   frame_41839150__62->GetXaxis()->SetTitleFont(42);
   frame_41839150__62->GetYaxis()->SetTitle("1/Events");
   frame_41839150__62->GetYaxis()->SetLabelFont(42);
   frame_41839150__62->GetYaxis()->SetTitleFont(42);
   frame_41839150__62->GetZaxis()->SetLabelFont(42);
   frame_41839150__62->GetZaxis()->SetTitleOffset(1);
   frame_41839150__62->GetZaxis()->SetTitleFont(42);
   frame_41839150__62->Draw("AXISSAME");
   
   TH1D *norm_o__63 = new TH1D("norm_o__63","",25,0,2);
   norm_o__63->SetBinContent(3,4);
   norm_o__63->SetBinContent(4,28);
   norm_o__63->SetBinContent(5,48);
   norm_o__63->SetBinContent(6,51);
   norm_o__63->SetBinContent(7,77);
   norm_o__63->SetBinContent(8,144);
   norm_o__63->SetBinContent(9,163);
   norm_o__63->SetBinContent(10,174);
   norm_o__63->SetBinContent(11,181);
   norm_o__63->SetBinContent(12,180);
   norm_o__63->SetBinContent(13,133);
   norm_o__63->SetBinContent(14,104);
   norm_o__63->SetBinContent(15,71);
   norm_o__63->SetBinContent(16,41);
   norm_o__63->SetBinContent(17,21);
   norm_o__63->SetBinContent(18,21);
   norm_o__63->SetBinContent(19,8);
   norm_o__63->SetBinContent(20,6);
   norm_o__63->SetBinContent(21,1);
   norm_o__63->SetBinContent(23,1);
   norm_o__63->SetBinContent(26,5);
   norm_o__63->SetMinimum(0);
   norm_o__63->SetMaximum(398.2);
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
   entry=leg->AddEntry("frame_x_o2_41839150","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.813822 #pm 0.006834","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.251674 #pm 0.005384","");
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
   
   TH1D *frame_41839150_copy__64 = new TH1D("frame_41839150_copy__64","p_T Balance",25,0,2);
   frame_41839150_copy__64->SetBinContent(1,204.7111);
   frame_41839150_copy__64->SetMaximum(204.7111);
   frame_41839150_copy__64->SetEntries(1);
   frame_41839150_copy__64->SetDirectory(0);
   frame_41839150_copy__64->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_41839150_copy__64->SetLineColor(ci);
   frame_41839150_copy__64->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_41839150_copy__64->GetXaxis()->SetLabelFont(42);
   frame_41839150_copy__64->GetXaxis()->SetTitleOffset(1);
   frame_41839150_copy__64->GetXaxis()->SetTitleFont(42);
   frame_41839150_copy__64->GetYaxis()->SetTitle("1/Events");
   frame_41839150_copy__64->GetYaxis()->SetLabelFont(42);
   frame_41839150_copy__64->GetYaxis()->SetTitleFont(42);
   frame_41839150_copy__64->GetZaxis()->SetLabelFont(42);
   frame_41839150_copy__64->GetZaxis()->SetTitleOffset(1);
   frame_41839150_copy__64->GetZaxis()->SetTitleFont(42);
   frame_41839150_copy__64->Draw("sameaxis");
   
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
