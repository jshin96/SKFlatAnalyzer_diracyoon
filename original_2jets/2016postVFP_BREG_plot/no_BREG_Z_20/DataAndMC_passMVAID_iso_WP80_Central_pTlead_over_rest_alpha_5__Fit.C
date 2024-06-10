void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_5__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 17:32:14 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-17.01793,2.25,195.7062);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_47934930__65 = new TH1D("frame_47934930__65","p_T Balance",25,0,2);
   frame_47934930__65->SetBinContent(1,174.4338);
   frame_47934930__65->SetMaximum(174.4338);
   frame_47934930__65->SetEntries(2);
   frame_47934930__65->SetDirectory(0);
   frame_47934930__65->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_47934930__65->SetLineColor(ci);
   frame_47934930__65->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_47934930__65->GetXaxis()->SetLabelFont(42);
   frame_47934930__65->GetXaxis()->SetTitleOffset(1);
   frame_47934930__65->GetXaxis()->SetTitleFont(42);
   frame_47934930__65->GetYaxis()->SetTitle("1/Events");
   frame_47934930__65->GetYaxis()->SetLabelFont(42);
   frame_47934930__65->GetYaxis()->SetTitleFont(42);
   frame_47934930__65->GetZaxis()->SetLabelFont(42);
   frame_47934930__65->GetZaxis()->SetTitleOffset(1);
   frame_47934930__65->GetZaxis()->SetTitleFont(42);
   frame_47934930__65->Draw("FUNC");
   
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
   0.2832575,
   18.70346,
   42.63984,
   64.56425,
   108.3921,
   135.0421,
   152.1374,
   149.4562,
   137.0685,
   122.3529,
   110.6236,
   91.1981,
   55.3903,
   41.8131,
   26.27042,
   14.04955,
   11.15476,
   5.332113,
   2.831373,
   2.206024,
   1.134499,
   1.162896,
   0.4138991};
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
   0.2666506,
   2.890993,
   4.382043,
   5.747064,
   7.76171,
   8.443591,
   9.168648,
   9.207505,
   8.843696,
   8.517593,
   7.615444,
   7.219423,
   4.980828,
   4.377916,
   3.428207,
   2.283012,
   2.043332,
   1.600026,
   0.8429637,
   0.7405388,
   0.6382263,
   0.5564919,
   0.176412};
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
   0.2666506,
   2.890993,
   4.382043,
   5.747064,
   7.76171,
   8.443591,
   9.168648,
   9.207505,
   8.843696,
   8.517593,
   7.615444,
   7.219423,
   4.980828,
   4.377916,
   3.428207,
   2.283012,
   2.043332,
   1.600026,
   0.8429637,
   0.7405388,
   0.6382263,
   0.5564919,
   0.176412};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3017,h_dh_central2_fy3017,h_dh_central2_felx3017,h_dh_central2_fehx3017,h_dh_central2_fely3017,h_dh_central2_fehy3017);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23017 = new TH1F("Graph_h_dh_central23017","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23017->SetMinimum(0);
   Graph_h_dh_central23017->SetMaximum(177.4366);
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
   
   Double_t Central_fx17[65] = {
   -0.003621911,
   -0.001746911,
   0.0001280891,
   0.003878089,
   0.01137809,
   0.02637809,
   0.05637809,
   0.1163781,
   0.1463781,
   0.1763781,
   0.2063781,
   0.2363781,
   0.2663781,
   0.2963781,
   0.3263781,
   0.3563781,
   0.3863781,
   0.4163781,
   0.4463781,
   0.4763781,
   0.5063781,
   0.5363781,
   0.5663781,
   0.5963781,
   0.6263781,
   0.6413781,
   0.6563781,
   0.6713781,
   0.6863781,
   0.7013781,
   0.7163781,
   0.7313781,
   0.7463781,
   0.7613781,
   0.7763781,
   0.7913781,
   0.8063781,
   0.8213781,
   0.8363781,
   0.8513781,
   0.8663781,
   0.8813781,
   0.8963781,
   0.9113781,
   0.9263781,
   0.9563781,
   1.016378,
   1.031378,
   1.046378,
   1.061378,
   1.076378,
   1.091378,
   1.106378,
   1.136378,
   1.166378,
   1.196378,
   1.226378,
   1.256378,
   1.286378,
   1.316378,
   1.346378,
   1.376378,
   1.436378,
   1.496378,
   1.496378};
   Double_t Central_fy17[65] = {
   0,
   0,
   0.6695621,
   0.7063355,
   0.7854382,
   0.9681808,
   1.452832,
   3.111812,
   4.441733,
   6.235216,
   8.608166,
   11.68772,
   15.60663,
   20.49501,
   26.46961,
   33.62071,
   41.99777,
   51.59476,
   62.33687,
   74.07037,
   86.55736,
   99.4772,
   112.4354,
   124.9806,
   136.6289,
   141.9637,
   146.8933,
   151.362,
   155.318,
   158.7146,
   161.5108,
   163.6728,
   165.1739,
   165.9955,
   166.1274,
   165.5679,
   164.3241,
   162.4113,
   159.8531,
   156.6809,
   152.933,
   148.6538,
   143.8935,
   138.7063,
   133.15,
   121.1717,
   95.45563,
   89.03816,
   83.07598,
   77.60461,
   72.57634,
   67.9488,
   63.68427,
   56.11327,
   49.63464,
   44.06461,
   39.25445,
   35.0831,
   31.4514,
   28.27771,
   25.49442,
   23.04529,
   18.96904,
   15.7555,
   15.7555};
   TGraph *graph = new TGraph(65,Central_fx17,Central_fy17);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central17 = new TH1F("Graph_Central17","Projection of centralf DSCB fit",100,-0.1536219,1.646378);
   Graph_Central17->SetMinimum(0);
   Graph_Central17->SetMaximum(182.7402);
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
   
   TH1D *frame_47934930__66 = new TH1D("frame_47934930__66","p_T Balance",25,0,2);
   frame_47934930__66->SetBinContent(1,174.4338);
   frame_47934930__66->SetMaximum(174.4338);
   frame_47934930__66->SetEntries(2);
   frame_47934930__66->SetDirectory(0);
   frame_47934930__66->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_47934930__66->SetLineColor(ci);
   frame_47934930__66->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_47934930__66->GetXaxis()->SetLabelFont(42);
   frame_47934930__66->GetXaxis()->SetTitleOffset(1);
   frame_47934930__66->GetXaxis()->SetTitleFont(42);
   frame_47934930__66->GetYaxis()->SetTitle("1/Events");
   frame_47934930__66->GetYaxis()->SetLabelFont(42);
   frame_47934930__66->GetYaxis()->SetTitleFont(42);
   frame_47934930__66->GetZaxis()->SetLabelFont(42);
   frame_47934930__66->GetZaxis()->SetTitleOffset(1);
   frame_47934930__66->GetZaxis()->SetTitleFont(42);
   frame_47934930__66->Draw("AXISSAME");
   
   TH1D *norm_c__67 = new TH1D("norm_c__67","",25,0,2);
   norm_c__67->SetBinContent(3,0.2832575);
   norm_c__67->SetBinContent(4,18.70346);
   norm_c__67->SetBinContent(5,42.63984);
   norm_c__67->SetBinContent(6,64.56425);
   norm_c__67->SetBinContent(7,108.3921);
   norm_c__67->SetBinContent(8,135.0421);
   norm_c__67->SetBinContent(9,152.1374);
   norm_c__67->SetBinContent(10,149.4562);
   norm_c__67->SetBinContent(11,137.0685);
   norm_c__67->SetBinContent(12,122.3529);
   norm_c__67->SetBinContent(13,110.6236);
   norm_c__67->SetBinContent(14,91.1981);
   norm_c__67->SetBinContent(15,55.3903);
   norm_c__67->SetBinContent(16,41.8131);
   norm_c__67->SetBinContent(17,26.27042);
   norm_c__67->SetBinContent(18,14.04955);
   norm_c__67->SetBinContent(19,11.15476);
   norm_c__67->SetBinContent(20,5.332113);
   norm_c__67->SetBinContent(21,2.831373);
   norm_c__67->SetBinContent(22,2.206024);
   norm_c__67->SetBinContent(23,1.134499);
   norm_c__67->SetBinContent(24,1.162896);
   norm_c__67->SetBinContent(25,0.4138991);
   norm_c__67->SetBinContent(26,1.700556);
   norm_c__67->SetBinError(3,0.2666506);
   norm_c__67->SetBinError(4,2.890993);
   norm_c__67->SetBinError(5,4.382043);
   norm_c__67->SetBinError(6,5.747064);
   norm_c__67->SetBinError(7,7.76171);
   norm_c__67->SetBinError(8,8.443591);
   norm_c__67->SetBinError(9,9.168648);
   norm_c__67->SetBinError(10,9.207505);
   norm_c__67->SetBinError(11,8.843696);
   norm_c__67->SetBinError(12,8.517593);
   norm_c__67->SetBinError(13,7.615444);
   norm_c__67->SetBinError(14,7.219423);
   norm_c__67->SetBinError(15,4.980828);
   norm_c__67->SetBinError(16,4.377916);
   norm_c__67->SetBinError(17,3.428207);
   norm_c__67->SetBinError(18,2.283012);
   norm_c__67->SetBinError(19,2.043332);
   norm_c__67->SetBinError(20,1.600026);
   norm_c__67->SetBinError(21,0.8429637);
   norm_c__67->SetBinError(22,0.7405388);
   norm_c__67->SetBinError(23,0.6382263);
   norm_c__67->SetBinError(24,0.5564919);
   norm_c__67->SetBinError(25,0.176412);
   norm_c__67->SetBinError(26,0.5077278);
   norm_c__67->SetEntries(5927);
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
   entry=leg->AddEntry("frame_x_c2_47934930","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.782936 #pm 0.007530","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.241055 #pm 0.005696","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.563000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_47934930_copy__68 = new TH1D("frame_47934930_copy__68","p_T Balance",25,0,2);
   frame_47934930_copy__68->SetBinContent(1,174.4338);
   frame_47934930_copy__68->SetMaximum(174.4338);
   frame_47934930_copy__68->SetEntries(2);
   frame_47934930_copy__68->SetDirectory(0);
   frame_47934930_copy__68->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_47934930_copy__68->SetLineColor(ci);
   frame_47934930_copy__68->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_47934930_copy__68->GetXaxis()->SetLabelFont(42);
   frame_47934930_copy__68->GetXaxis()->SetTitleOffset(1);
   frame_47934930_copy__68->GetXaxis()->SetTitleFont(42);
   frame_47934930_copy__68->GetYaxis()->SetTitle("1/Events");
   frame_47934930_copy__68->GetYaxis()->SetLabelFont(42);
   frame_47934930_copy__68->GetYaxis()->SetTitleFont(42);
   frame_47934930_copy__68->GetZaxis()->SetLabelFont(42);
   frame_47934930_copy__68->GetZaxis()->SetTitleOffset(1);
   frame_47934930_copy__68->GetZaxis()->SetTitleFont(42);
   frame_47934930_copy__68->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-17.01742,2.25,195.7003);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_4792ee80__69 = new TH1D("frame_4792ee80__69","p_T Balance",25,0,2);
   frame_4792ee80__69->SetBinContent(1,174.4285);
   frame_4792ee80__69->SetMaximum(174.4285);
   frame_4792ee80__69->SetEntries(2);
   frame_4792ee80__69->SetDirectory(0);
   frame_4792ee80__69->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4792ee80__69->SetLineColor(ci);
   frame_4792ee80__69->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4792ee80__69->GetXaxis()->SetLabelFont(42);
   frame_4792ee80__69->GetXaxis()->SetTitleOffset(1);
   frame_4792ee80__69->GetXaxis()->SetTitleFont(42);
   frame_4792ee80__69->GetYaxis()->SetTitle("1/Events");
   frame_4792ee80__69->GetYaxis()->SetLabelFont(42);
   frame_4792ee80__69->GetYaxis()->SetTitleFont(42);
   frame_4792ee80__69->GetZaxis()->SetLabelFont(42);
   frame_4792ee80__69->GetZaxis()->SetTitleOffset(1);
   frame_4792ee80__69->GetZaxis()->SetTitleFont(42);
   frame_4792ee80__69->Draw("FUNC");
   
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
   0.004666437,
   18.30711,
   43.3544,
   66.88009,
   102.9182,
   127.4598,
   155.7289,
   151.4409,
   143.0788,
   130.3883,
   123.1197,
   83.91986,
   68.09643,
   42.97446,
   28.47404,
   15.03148,
   10.70234,
   4.593476,
   4.372368,
   3.344553,
   0.9343054,
   1.275144,
   0.4329875};
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
   0.004666437,
   2.837166,
   4.591984,
   6.136655,
   7.4164,
   8.25625,
   9.435761,
   9.370204,
   8.881386,
   9.161831,
   7.983551,
   6.697101,
   6.11097,
   4.44111,
   3.492205,
   2.337946,
   1.968435,
   1.181008,
   1.481942,
   0.9587309,
   0.6306448,
   0.5586414,
   0.1778168};
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
   0.004666437,
   2.837166,
   4.591984,
   6.136655,
   7.4164,
   8.25625,
   9.435761,
   9.370204,
   8.881386,
   9.161831,
   7.983551,
   6.697101,
   6.11097,
   4.44111,
   3.492205,
   2.337946,
   1.968435,
   1.181008,
   1.481942,
   0.9587309,
   0.6306448,
   0.5586414,
   0.1778168};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3018,h_dh_up2_fy3018,h_dh_up2_felx3018,h_dh_up2_fehx3018,h_dh_up2_fely3018,h_dh_up2_fehy3018);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23018 = new TH1F("Graph_h_dh_up23018","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23018->SetMinimum(0);
   Graph_h_dh_up23018->SetMaximum(181.6811);
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
   
   Double_t up_fx18[59] = {
   0.07704497,
   0.1336736,
   0.161988,
   0.1903023,
   0.2186167,
   0.246931,
   0.2752454,
   0.3035597,
   0.331874,
   0.3601884,
   0.3885027,
   0.4168171,
   0.4451314,
   0.4734457,
   0.5017601,
   0.5300744,
   0.5867031,
   0.6150174,
   0.6433318,
   0.6574889,
   0.6716461,
   0.6858033,
   0.6999605,
   0.7141176,
   0.7282748,
   0.742432,
   0.7565891,
   0.7707463,
   0.7849035,
   0.7990606,
   0.8132178,
   0.827375,
   0.8415322,
   0.8556893,
   0.8698465,
   0.8840037,
   0.8981608,
   0.912318,
   0.9264752,
   0.9547895,
   0.9831039,
   1.039733,
   1.068047,
   1.096361,
   1.110518,
   1.124676,
   1.138833,
   1.15299,
   1.181304,
   1.209619,
   1.237933,
   1.266247,
   1.294562,
   1.322876,
   1.35119,
   1.379505,
   1.436133,
   1.492762,
   1.492762};
   Double_t up_fy18[59] = {
   2.327446,
   4.460604,
   6.051966,
   8.101459,
   10.70025,
   13.94404,
   17.92862,
   22.74413,
   28.46792,
   35.15652,
   42.83709,
   51.49891,
   61.08576,
   71.49009,
   82.54972,
   94.04794,
   117.2488,
   128.3021,
   138.5234,
   143.2119,
   147.5626,
   151.5355,
   155.0934,
   158.2025,
   160.8327,
   162.9583,
   164.5581,
   165.6164,
   166.1224,
   166.0711,
   165.463,
   164.3043,
   162.6064,
   160.3864,
   157.6661,
   154.4721,
   150.8352,
   146.79,
   142.3742,
   132.5939,
   121.8371,
   98.80612,
   87.20308,
   75.94363,
   70.74591,
   65.98535,
   61.61857,
   57.60712,
   50.51741,
   44.48558,
   39.32773,
   34.89621,
   31.07166,
   27.757,
   24.87279,
   22.35366,
   18.20344,
   14.97322,
   14.97322};
   graph = new TGraph(59,up_fx18,up_fy18);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up18 = new TH1F("Graph_up18","Projection of upf DSCB fit",100,0,1.634334);
   Graph_up18->SetMinimum(2.094702);
   Graph_up18->SetMaximum(182.5019);
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
   
   TH1D *frame_4792ee80__70 = new TH1D("frame_4792ee80__70","p_T Balance",25,0,2);
   frame_4792ee80__70->SetBinContent(1,174.4285);
   frame_4792ee80__70->SetMaximum(174.4285);
   frame_4792ee80__70->SetEntries(2);
   frame_4792ee80__70->SetDirectory(0);
   frame_4792ee80__70->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4792ee80__70->SetLineColor(ci);
   frame_4792ee80__70->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4792ee80__70->GetXaxis()->SetLabelFont(42);
   frame_4792ee80__70->GetXaxis()->SetTitleOffset(1);
   frame_4792ee80__70->GetXaxis()->SetTitleFont(42);
   frame_4792ee80__70->GetYaxis()->SetTitle("1/Events");
   frame_4792ee80__70->GetYaxis()->SetLabelFont(42);
   frame_4792ee80__70->GetYaxis()->SetTitleFont(42);
   frame_4792ee80__70->GetZaxis()->SetLabelFont(42);
   frame_4792ee80__70->GetZaxis()->SetTitleOffset(1);
   frame_4792ee80__70->GetZaxis()->SetTitleFont(42);
   frame_4792ee80__70->Draw("AXISSAME");
   
   TH1D *norm_u__71 = new TH1D("norm_u__71","",25,0,2);
   norm_u__71->SetBinContent(3,0.004666437);
   norm_u__71->SetBinContent(4,18.30711);
   norm_u__71->SetBinContent(5,43.3544);
   norm_u__71->SetBinContent(6,66.88009);
   norm_u__71->SetBinContent(7,102.9182);
   norm_u__71->SetBinContent(8,127.4598);
   norm_u__71->SetBinContent(9,155.7289);
   norm_u__71->SetBinContent(10,151.4409);
   norm_u__71->SetBinContent(11,143.0788);
   norm_u__71->SetBinContent(12,130.3883);
   norm_u__71->SetBinContent(13,123.1197);
   norm_u__71->SetBinContent(14,83.91986);
   norm_u__71->SetBinContent(15,68.09643);
   norm_u__71->SetBinContent(16,42.97446);
   norm_u__71->SetBinContent(17,28.47404);
   norm_u__71->SetBinContent(18,15.03148);
   norm_u__71->SetBinContent(19,10.70234);
   norm_u__71->SetBinContent(20,4.593476);
   norm_u__71->SetBinContent(21,4.372368);
   norm_u__71->SetBinContent(22,3.344554);
   norm_u__71->SetBinContent(23,0.9343054);
   norm_u__71->SetBinContent(24,1.275144);
   norm_u__71->SetBinContent(25,0.4329875);
   norm_u__71->SetBinContent(26,1.584654);
   norm_u__71->SetBinError(3,0.004666437);
   norm_u__71->SetBinError(4,2.837166);
   norm_u__71->SetBinError(5,4.591984);
   norm_u__71->SetBinError(6,6.136655);
   norm_u__71->SetBinError(7,7.4164);
   norm_u__71->SetBinError(8,8.25625);
   norm_u__71->SetBinError(9,9.435761);
   norm_u__71->SetBinError(10,9.370204);
   norm_u__71->SetBinError(11,8.881386);
   norm_u__71->SetBinError(12,9.161831);
   norm_u__71->SetBinError(13,7.983551);
   norm_u__71->SetBinError(14,6.697101);
   norm_u__71->SetBinError(15,6.11097);
   norm_u__71->SetBinError(16,4.44111);
   norm_u__71->SetBinError(17,3.492205);
   norm_u__71->SetBinError(18,2.337946);
   norm_u__71->SetBinError(19,1.968435);
   norm_u__71->SetBinError(20,1.181008);
   norm_u__71->SetBinError(21,1.481942);
   norm_u__71->SetBinError(22,0.9587309);
   norm_u__71->SetBinError(23,0.6306448);
   norm_u__71->SetBinError(24,0.5586414);
   norm_u__71->SetBinError(25,0.1778168);
   norm_u__71->SetBinError(26,0.4818228);
   norm_u__71->SetEntries(5865);
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
   entry=leg->AddEntry("frame_x_u2_4792ee80","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.790670 #pm 0.007655","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.244269 #pm 0.005997","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.656000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_4792ee80_copy__72 = new TH1D("frame_4792ee80_copy__72","p_T Balance",25,0,2);
   frame_4792ee80_copy__72->SetBinContent(1,174.4285);
   frame_4792ee80_copy__72->SetMaximum(174.4285);
   frame_4792ee80_copy__72->SetEntries(2);
   frame_4792ee80_copy__72->SetDirectory(0);
   frame_4792ee80_copy__72->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4792ee80_copy__72->SetLineColor(ci);
   frame_4792ee80_copy__72->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4792ee80_copy__72->GetXaxis()->SetLabelFont(42);
   frame_4792ee80_copy__72->GetXaxis()->SetTitleOffset(1);
   frame_4792ee80_copy__72->GetXaxis()->SetTitleFont(42);
   frame_4792ee80_copy__72->GetYaxis()->SetTitle("1/Events");
   frame_4792ee80_copy__72->GetYaxis()->SetLabelFont(42);
   frame_4792ee80_copy__72->GetYaxis()->SetTitleFont(42);
   frame_4792ee80_copy__72->GetZaxis()->SetLabelFont(42);
   frame_4792ee80_copy__72->GetZaxis()->SetTitleOffset(1);
   frame_4792ee80_copy__72->GetZaxis()->SetTitleFont(42);
   frame_4792ee80_copy__72->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-19.74193,2.25,177.6773);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_478a3140__73 = new TH1D("frame_478a3140__73","p_T Balance",25,0,2);
   frame_478a3140__73->SetBinContent(1,173.7289);
   frame_478a3140__73->SetMaximum(173.7289);
   frame_478a3140__73->SetEntries(2);
   frame_478a3140__73->SetDirectory(0);
   frame_478a3140__73->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_478a3140__73->SetLineColor(ci);
   frame_478a3140__73->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_478a3140__73->GetXaxis()->SetLabelFont(42);
   frame_478a3140__73->GetXaxis()->SetTitleOffset(1);
   frame_478a3140__73->GetXaxis()->SetTitleFont(42);
   frame_478a3140__73->GetYaxis()->SetTitle("1/Events");
   frame_478a3140__73->GetYaxis()->SetLabelFont(42);
   frame_478a3140__73->GetYaxis()->SetTitleFont(42);
   frame_478a3140__73->GetZaxis()->SetLabelFont(42);
   frame_478a3140__73->GetZaxis()->SetTitleOffset(1);
   frame_478a3140__73->GetZaxis()->SetTitleFont(42);
   frame_478a3140__73->Draw("FUNC");
   
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
   0.01679267,
   18.15302,
   49.35337,
   68.2285,
   113.0223,
   142.3813,
   138.9724,
   148.7283,
   136.042,
   110.0426,
   106.5107,
   76.36502,
   50.55638,
   39.24799,
   27.8835,
   15.66494,
   7.623726,
   5.396941,
   3.618398,
   1.251064,
   1.052522,
   1.12156,
   0.4195179};
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
   0.01679267,
   2.803135,
   4.723709,
   5.782594,
   7.803489,
   8.627602,
   8.768458,
   9.073242,
   8.966395,
   7.998889,
   7.479109,
   6.151049,
   4.736429,
   4.207663,
   3.597752,
   2.428656,
   1.429531,
   1.602509,
   1.053735,
   0.4950226,
   0.5973052,
   0.5151414,
   0.1566929};
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
   0.01679267,
   2.803135,
   4.723709,
   5.782594,
   7.803489,
   8.627602,
   8.768458,
   9.073242,
   8.966395,
   7.998889,
   7.479109,
   6.151049,
   4.736429,
   4.207663,
   3.597752,
   2.428656,
   1.429531,
   1.602509,
   1.053735,
   0.4950226,
   0.5973052,
   0.5151414,
   0.1566929};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3019,h_dh_down2_fy3019,h_dh_down2_felx3019,h_dh_down2_fehx3019,h_dh_down2_fely3019,h_dh_down2_fehy3019);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23019 = new TH1F("Graph_h_dh_down23019","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23019->SetMinimum(0);
   Graph_h_dh_down23019->SetMaximum(173.5817);
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
   
   Double_t down_fx19[62] = {
   -0.02639802,
   0.03360198,
   0.09360198,
   0.123602,
   0.153602,
   0.183602,
   0.213602,
   0.243602,
   0.273602,
   0.303602,
   0.333602,
   0.348602,
   0.363602,
   0.378602,
   0.393602,
   0.423602,
   0.453602,
   0.483602,
   0.5136019,
   0.5436019,
   0.5736019,
   0.6036019,
   0.6186019,
   0.6336019,
   0.6486019,
   0.6636019,
   0.6786019,
   0.6936019,
   0.7086019,
   0.7236019,
   0.7386019,
   0.7536019,
   0.7686019,
   0.7836019,
   0.7986019,
   0.8136019,
   0.8286019,
   0.8436019,
   0.8586019,
   0.8736019,
   0.8886019,
   0.9036019,
   0.9336019,
   0.9486019,
   0.9636019,
   0.9786019,
   0.9936019,
   1.008602,
   1.023602,
   1.053602,
   1.083602,
   1.113602,
   1.143602,
   1.173602,
   1.203602,
   1.233602,
   1.263602,
   1.293602,
   1.353602,
   1.413602,
   1.473602,
   1.473602};
   Double_t down_fy19[62] = {
   0,
   0.8688855,
   2.038369,
   3.034888,
   4.434071,
   6.35715,
   8.943804,
   12.34758,
   16.72791,
   22.23828,
   29.01087,
   32.90149,
   37.13815,
   41.72294,
   46.653,
   57.50941,
   69.56619,
   82.57668,
   96.18703,
   109.945,
   123.3203,
   135.7355,
   141.3995,
   146.6062,
   151.2888,
   155.3857,
   158.8421,
   161.6106,
   163.6531,
   164.941,
   165.4561,
   165.1913,
   164.1502,
   162.3475,
   159.8085,
   156.5684,
   152.6716,
   148.1708,
   143.1254,
   137.6008,
   131.6664,
   125.3947,
   112.134,
   105.3062,
   98.82397,
   92.83292,
   87.28907,
   82.15294,
   77.38908,
   68.85366,
   61.4632,
   55.03824,
   49.43129,
   44.52051,
   40.20469,
   36.39939,
   33.03384,
   30.04842,
   25.02413,
   21.00742,
   17.76525,
   17.76525};
   graph = new TGraph(62,down_fx19,down_fy19);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down19 = new TH1F("Graph_down19","Projection of downf DSCB fit",100,-0.176398,1.623602);
   Graph_down19->SetMinimum(0);
   Graph_down19->SetMaximum(182.0017);
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
   
   TH1D *frame_478a3140__74 = new TH1D("frame_478a3140__74","p_T Balance",25,0,2);
   frame_478a3140__74->SetBinContent(1,173.7289);
   frame_478a3140__74->SetMaximum(173.7289);
   frame_478a3140__74->SetEntries(2);
   frame_478a3140__74->SetDirectory(0);
   frame_478a3140__74->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_478a3140__74->SetLineColor(ci);
   frame_478a3140__74->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_478a3140__74->GetXaxis()->SetLabelFont(42);
   frame_478a3140__74->GetXaxis()->SetTitleOffset(1);
   frame_478a3140__74->GetXaxis()->SetTitleFont(42);
   frame_478a3140__74->GetYaxis()->SetTitle("1/Events");
   frame_478a3140__74->GetYaxis()->SetLabelFont(42);
   frame_478a3140__74->GetYaxis()->SetTitleFont(42);
   frame_478a3140__74->GetZaxis()->SetLabelFont(42);
   frame_478a3140__74->GetZaxis()->SetTitleOffset(1);
   frame_478a3140__74->GetZaxis()->SetTitleFont(42);
   frame_478a3140__74->Draw("AXISSAME");
   
   TH1D *norm_d__75 = new TH1D("norm_d__75","",25,0,2);
   norm_d__75->SetBinContent(3,0.01679267);
   norm_d__75->SetBinContent(4,18.15302);
   norm_d__75->SetBinContent(5,49.35337);
   norm_d__75->SetBinContent(6,68.2285);
   norm_d__75->SetBinContent(7,113.0223);
   norm_d__75->SetBinContent(8,142.3813);
   norm_d__75->SetBinContent(9,138.9724);
   norm_d__75->SetBinContent(10,148.7283);
   norm_d__75->SetBinContent(11,136.042);
   norm_d__75->SetBinContent(12,110.0426);
   norm_d__75->SetBinContent(13,106.5107);
   norm_d__75->SetBinContent(14,76.36502);
   norm_d__75->SetBinContent(15,50.55638);
   norm_d__75->SetBinContent(16,39.24799);
   norm_d__75->SetBinContent(17,27.8835);
   norm_d__75->SetBinContent(18,15.66494);
   norm_d__75->SetBinContent(19,7.623726);
   norm_d__75->SetBinContent(20,5.396941);
   norm_d__75->SetBinContent(21,3.618398);
   norm_d__75->SetBinContent(22,1.251064);
   norm_d__75->SetBinContent(23,1.052522);
   norm_d__75->SetBinContent(24,1.12156);
   norm_d__75->SetBinContent(25,0.4195179);
   norm_d__75->SetBinContent(26,1.641583);
   norm_d__75->SetBinError(3,0.01679267);
   norm_d__75->SetBinError(4,2.803135);
   norm_d__75->SetBinError(5,4.723709);
   norm_d__75->SetBinError(6,5.782594);
   norm_d__75->SetBinError(7,7.803489);
   norm_d__75->SetBinError(8,8.627602);
   norm_d__75->SetBinError(9,8.768458);
   norm_d__75->SetBinError(10,9.073242);
   norm_d__75->SetBinError(11,8.966395);
   norm_d__75->SetBinError(12,7.998889);
   norm_d__75->SetBinError(13,7.479109);
   norm_d__75->SetBinError(14,6.151049);
   norm_d__75->SetBinError(15,4.736429);
   norm_d__75->SetBinError(16,4.207663);
   norm_d__75->SetBinError(17,3.597752);
   norm_d__75->SetBinError(18,2.428656);
   norm_d__75->SetBinError(19,1.429531);
   norm_d__75->SetBinError(20,1.602509);
   norm_d__75->SetBinError(21,1.053735);
   norm_d__75->SetBinError(22,0.4950226);
   norm_d__75->SetBinError(23,0.5973052);
   norm_d__75->SetBinError(24,0.5151414);
   norm_d__75->SetBinError(25,0.1566929);
   norm_d__75->SetBinError(26,0.5095509);
   norm_d__75->SetEntries(5969);
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
   entry=leg->AddEntry("frame_x_d2_478a3140","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.787969 #pm 0.007468","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.257844 #pm 0.005666","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.408000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_478a3140_copy__76 = new TH1D("frame_478a3140_copy__76","p_T Balance",25,0,2);
   frame_478a3140_copy__76->SetBinContent(1,173.7289);
   frame_478a3140_copy__76->SetMaximum(173.7289);
   frame_478a3140_copy__76->SetEntries(2);
   frame_478a3140_copy__76->SetDirectory(0);
   frame_478a3140_copy__76->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_478a3140_copy__76->SetLineColor(ci);
   frame_478a3140_copy__76->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_478a3140_copy__76->GetXaxis()->SetLabelFont(42);
   frame_478a3140_copy__76->GetXaxis()->SetTitleOffset(1);
   frame_478a3140_copy__76->GetXaxis()->SetTitleFont(42);
   frame_478a3140_copy__76->GetYaxis()->SetTitle("1/Events");
   frame_478a3140_copy__76->GetYaxis()->SetLabelFont(42);
   frame_478a3140_copy__76->GetYaxis()->SetTitleFont(42);
   frame_478a3140_copy__76->GetZaxis()->SetLabelFont(42);
   frame_478a3140_copy__76->GetZaxis()->SetTitleOffset(1);
   frame_478a3140_copy__76->GetZaxis()->SetTitleFont(42);
   frame_478a3140_copy__76->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-22.39607,2.25,201.5646);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_47927030__77 = new TH1D("frame_47927030__77","p_T Balance",25,0,2);
   frame_47927030__77->SetBinContent(1,197.0854);
   frame_47927030__77->SetMaximum(197.0854);
   frame_47927030__77->SetEntries(1);
   frame_47927030__77->SetDirectory(0);
   frame_47927030__77->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_47927030__77->SetLineColor(ci);
   frame_47927030__77->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_47927030__77->GetXaxis()->SetLabelFont(42);
   frame_47927030__77->GetXaxis()->SetTitleOffset(1);
   frame_47927030__77->GetXaxis()->SetTitleFont(42);
   frame_47927030__77->GetYaxis()->SetTitle("1/Events");
   frame_47927030__77->GetYaxis()->SetLabelFont(42);
   frame_47927030__77->GetYaxis()->SetTitleFont(42);
   frame_47927030__77->GetZaxis()->SetLabelFont(42);
   frame_47927030__77->GetZaxis()->SetTitleOffset(1);
   frame_47927030__77->GetZaxis()->SetTitleFont(42);
   frame_47927030__77->Draw("FUNC");
   
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
   0,
   27,
   37,
   78,
   97,
   147,
   166,
   165,
   174,
   118,
   95,
   74,
   46,
   42,
   22,
   17,
   12,
   6,
   6,
   4,
   2,
   1,
   1};
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
   0,
   5.163771,
   6.055143,
   8.812788,
   9.831854,
   11.63466,
   12.3938,
   12.35496,
   12.70038,
   10.37428,
   9.729612,
   8.582844,
   6.757581,
   6.454831,
   4.654502,
   4.082184,
   3.415266,
   2.379931,
   2.379931,
   1.914339,
   1.291815,
   0.8272462,
   0.8272462};
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
   1.147874,
   6.260244,
   7.137555,
   9.869531,
   10.88273,
   12.63466,
   13.3938,
   13.35496,
   13.70038,
   11.37428,
   10.78102,
   9.641101,
   7.831489,
   7.53218,
   5.761366,
   5.203719,
   4.559819,
   3.583642,
   3.583642,
   3.162753,
   2.63786,
   2.299527,
   2.299527};
   grae = new TGraphAsymmErrors(25,h_dh_data2_fx3020,h_dh_data2_fy3020,h_dh_data2_felx3020,h_dh_data2_fehx3020,h_dh_data2_fely3020,h_dh_data2_fehy3020);
   grae->SetName("h_dh_data2");
   grae->SetTitle("Histogram of dh_data2_plot__x_o2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_data23020 = new TH1F("Graph_h_dh_data23020","Histogram of dh_data2_plot__x_o2",100,0,2.2);
   Graph_h_dh_data23020->SetMinimum(0);
   Graph_h_dh_data23020->SetMaximum(206.4704);
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
   
   Double_t observation_fx20[57] = {
   0.08888263,
   0.1407563,
   0.1666932,
   0.19263,
   0.2185669,
   0.2445038,
   0.2704406,
   0.2963775,
   0.3223143,
   0.3482512,
   0.374188,
   0.4001249,
   0.4260617,
   0.4519986,
   0.4779354,
   0.5038723,
   0.555746,
   0.5816828,
   0.6076197,
   0.6205881,
   0.6335566,
   0.646525,
   0.6594934,
   0.6724618,
   0.6854303,
   0.6983987,
   0.7113671,
   0.7243355,
   0.737304,
   0.7502724,
   0.7632408,
   0.7762092,
   0.7891777,
   0.8021461,
   0.8151145,
   0.828083,
   0.8410514,
   0.8540198,
   0.8669882,
   0.8929251,
   0.9188619,
   0.9707356,
   0.9837041,
   0.9966725,
   1.022609,
   1.048546,
   1.074483,
   1.10042,
   1.126357,
   1.152294,
   1.17823,
   1.204167,
   1.230104,
   1.281978,
   1.333852,
   1.385725,
   1.385725};
   Double_t observation_fy20[57] = {
   1.694121,
   3.448777,
   4.813513,
   6.62039,
   8.972831,
   11.98395,
   15.77228,
   20.45567,
   26.14312,
   32.92497,
   40.86184,
   49.97293,
   60.2249,
   71.52237,
   83.70127,
   96.52653,
   122.8427,
   135.5617,
   147.4176,
   152.885,
   157.9742,
   162.6349,
   166.8197,
   170.4854,
   173.5933,
   176.1104,
   178.0095,
   179.2699,
   179.8778,
   179.8266,
   179.1169,
   177.7564,
   175.7599,
   173.1493,
   169.9525,
   166.2037,
   161.9421,
   157.2118,
   152.0605,
   140.7011,
   128.293,
   102.325,
   96.43643,
   90.96543,
   81.13937,
   72.60495,
   65.1637,
   58.6518,
   52.93338,
   47.8952,
   43.44242,
   39.49529,
   35.98644,
   30.06359,
   25.31064,
   21.46094,
   21.46094};
   graph = new TGraph(57,observation_fx20,observation_fy20);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation20 = new TH1F("Graph_observation20","Projection of obsf DSCB fit",100,0,1.51541);
   Graph_observation20->SetMinimum(1.524709);
   Graph_observation20->SetMaximum(197.6962);
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
   
   TH1D *frame_47927030__78 = new TH1D("frame_47927030__78","p_T Balance",25,0,2);
   frame_47927030__78->SetBinContent(1,197.0854);
   frame_47927030__78->SetMaximum(197.0854);
   frame_47927030__78->SetEntries(1);
   frame_47927030__78->SetDirectory(0);
   frame_47927030__78->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_47927030__78->SetLineColor(ci);
   frame_47927030__78->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_47927030__78->GetXaxis()->SetLabelFont(42);
   frame_47927030__78->GetXaxis()->SetTitleOffset(1);
   frame_47927030__78->GetXaxis()->SetTitleFont(42);
   frame_47927030__78->GetYaxis()->SetTitle("1/Events");
   frame_47927030__78->GetYaxis()->SetLabelFont(42);
   frame_47927030__78->GetYaxis()->SetTitleFont(42);
   frame_47927030__78->GetZaxis()->SetLabelFont(42);
   frame_47927030__78->GetZaxis()->SetTitleOffset(1);
   frame_47927030__78->GetZaxis()->SetTitleFont(42);
   frame_47927030__78->Draw("AXISSAME");
   
   TH1D *norm_o__79 = new TH1D("norm_o__79","",25,0,2);
   norm_o__79->SetBinContent(4,27);
   norm_o__79->SetBinContent(5,37);
   norm_o__79->SetBinContent(6,78);
   norm_o__79->SetBinContent(7,97);
   norm_o__79->SetBinContent(8,147);
   norm_o__79->SetBinContent(9,166);
   norm_o__79->SetBinContent(10,165);
   norm_o__79->SetBinContent(11,174);
   norm_o__79->SetBinContent(12,118);
   norm_o__79->SetBinContent(13,95);
   norm_o__79->SetBinContent(14,74);
   norm_o__79->SetBinContent(15,46);
   norm_o__79->SetBinContent(16,42);
   norm_o__79->SetBinContent(17,22);
   norm_o__79->SetBinContent(18,17);
   norm_o__79->SetBinContent(19,12);
   norm_o__79->SetBinContent(20,6);
   norm_o__79->SetBinContent(21,6);
   norm_o__79->SetBinContent(22,4);
   norm_o__79->SetBinContent(23,2);
   norm_o__79->SetBinContent(24,1);
   norm_o__79->SetBinContent(25,1);
   norm_o__79->SetBinContent(26,1);
   norm_o__79->SetMinimum(0);
   norm_o__79->SetMaximum(382.8);
   norm_o__79->SetEntries(1338);
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
   entry=leg->AddEntry("frame_x_o2_47927030","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.752741 #pm 0.007032","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.221660 #pm 0.005504","");
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
   
   TH1D *frame_47927030_copy__80 = new TH1D("frame_47927030_copy__80","p_T Balance",25,0,2);
   frame_47927030_copy__80->SetBinContent(1,197.0854);
   frame_47927030_copy__80->SetMaximum(197.0854);
   frame_47927030_copy__80->SetEntries(1);
   frame_47927030_copy__80->SetDirectory(0);
   frame_47927030_copy__80->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_47927030_copy__80->SetLineColor(ci);
   frame_47927030_copy__80->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_47927030_copy__80->GetXaxis()->SetLabelFont(42);
   frame_47927030_copy__80->GetXaxis()->SetTitleOffset(1);
   frame_47927030_copy__80->GetXaxis()->SetTitleFont(42);
   frame_47927030_copy__80->GetYaxis()->SetTitle("1/Events");
   frame_47927030_copy__80->GetYaxis()->SetLabelFont(42);
   frame_47927030_copy__80->GetYaxis()->SetTitleFont(42);
   frame_47927030_copy__80->GetZaxis()->SetLabelFont(42);
   frame_47927030_copy__80->GetZaxis()->SetTitleOffset(1);
   frame_47927030_copy__80->GetZaxis()->SetTitleFont(42);
   frame_47927030_copy__80->Draw("sameaxis");
   
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
