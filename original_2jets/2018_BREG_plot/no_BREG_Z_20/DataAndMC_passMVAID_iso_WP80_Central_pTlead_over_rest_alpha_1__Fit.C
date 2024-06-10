void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_1__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 19:07:55 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-4.177589,2.25,48.04228);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_2fd58310__1 = new TH1D("frame_2fd58310__1","p_T Balance",25,0,2);
   frame_2fd58310__1->SetBinContent(1,42.82029);
   frame_2fd58310__1->SetMaximum(42.82029);
   frame_2fd58310__1->SetEntries(1);
   frame_2fd58310__1->SetDirectory(0);
   frame_2fd58310__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_2fd58310__1->SetLineColor(ci);
   frame_2fd58310__1->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fd58310__1->GetXaxis()->SetLabelFont(42);
   frame_2fd58310__1->GetXaxis()->SetTitleOffset(1);
   frame_2fd58310__1->GetXaxis()->SetTitleFont(42);
   frame_2fd58310__1->GetYaxis()->SetTitle("1/Events");
   frame_2fd58310__1->GetYaxis()->SetLabelFont(42);
   frame_2fd58310__1->GetYaxis()->SetTitleFont(42);
   frame_2fd58310__1->GetZaxis()->SetLabelFont(42);
   frame_2fd58310__1->GetZaxis()->SetTitleOffset(1);
   frame_2fd58310__1->GetZaxis()->SetTitleFont(42);
   frame_2fd58310__1->Draw("FUNC");
   
   Double_t h_dh_central2_fx3001[25] = {
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
   Double_t h_dh_central2_fy3001[25] = {
   0.0927769,
   0.6684073,
   1.449917,
   0.6464527,
   0.6692348,
   1.727926,
   2.804781,
   5.680706,
   13.06129,
   21.19138,
   31.40024,
   38.53564,
   33.68261,
   19.8511,
   9.745029,
   3.127685,
   1.180578,
   0.3610024,
   0.3055452,
   0.02259181,
   0.1478563,
   0.05842585,
   0.04782904,
   0.02443214,
   0.00274297};
   Double_t h_dh_central2_felx3001[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_central2_fely3001[25] = {
   0.06204455,
   0.2698762,
   0.4339385,
   0.2713502,
   0.3035533,
   0.4777314,
   0.6388579,
   0.8630318,
   1.375017,
   1.704858,
   2.038814,
   2.245584,
   2.07799,
   1.559352,
   1.127044,
   0.629397,
   0.3711005,
   0.1721939,
   0.1158859,
   0.01523824,
   0.1478562,
   0.02550578,
   0.04075713,
   0.02443214,
   0.001952796};
   Double_t h_dh_central2_fehx3001[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_central2_fehy3001[25] = {
   0.06204455,
   0.2698762,
   0.4339385,
   0.2713502,
   0.3035533,
   0.4777314,
   0.6388579,
   0.8630318,
   1.375017,
   1.704858,
   2.038814,
   2.245584,
   2.07799,
   1.559352,
   1.127044,
   0.629397,
   0.3711005,
   0.1721939,
   0.1158859,
   0.01523824,
   0.1478562,
   0.02550578,
   0.04075713,
   0.02443214,
   0.001952796};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3001,h_dh_central2_fy3001,h_dh_central2_felx3001,h_dh_central2_fehx3001,h_dh_central2_fely3001,h_dh_central2_fehy3001);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23001 = new TH1F("Graph_h_dh_central23001","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23001->SetMinimum(2.93991e-10);
   Graph_h_dh_central23001->SetMaximum(44.85935);
   Graph_h_dh_central23001->SetDirectory(0);
   Graph_h_dh_central23001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_central23001->SetLineColor(ci);
   Graph_h_dh_central23001->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_central23001->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_central23001->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_central23001->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_central23001->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_central23001->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_central23001->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_central23001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_central23001);
   
   grae->Draw("p");
   
   Double_t Central_fx1[58] = {
   0.5356877,
   0.550779,
   0.5658703,
   0.5809615,
   0.5960528,
   0.6111441,
   0.6262354,
   0.6413266,
   0.6564179,
   0.6715092,
   0.6866005,
   0.7016918,
   0.716783,
   0.7318743,
   0.7469656,
   0.7771482,
   0.7922394,
   0.8073307,
   0.822422,
   0.8375133,
   0.8526046,
   0.8601502,
   0.8676958,
   0.8752415,
   0.8827871,
   0.8903328,
   0.8978784,
   0.905424,
   0.9129697,
   0.9205153,
   0.928061,
   0.9356066,
   0.9431522,
   0.9506979,
   0.9582435,
   0.9657892,
   0.9733348,
   0.9884261,
   1.003517,
   1.018609,
   1.0337,
   1.048791,
   1.078974,
   1.094065,
   1.109156,
   1.124248,
   1.139339,
   1.15443,
   1.169521,
   1.184613,
   1.199704,
   1.214795,
   1.229887,
   1.244978,
   1.260069,
   1.27516,
   1.290252,
   1.290252};
   Double_t Central_fy1[58] = {
   1.745194,
   2.224033,
   2.806156,
   3.505541,
   4.335818,
   5.309576,
   6.437562,
   7.7278,
   9.184659,
   10.80794,
   12.59203,
   14.52517,
   16.58898,
   18.75818,
   21.00074,
   25.54705,
   27.75895,
   29.86333,
   31.80871,
   33.54491,
   35.02516,
   35.65612,
   36.20815,
   36.67724,
   37.05999,
   37.35357,
   37.5558,
   37.6652,
   37.68093,
   37.60289,
   37.43165,
   37.1685,
   36.81537,
   36.37488,
   35.85024,
   35.24527,
   34.5643,
   32.9941,
   31.18298,
   29.17909,
   27.03327,
   24.79695,
   20.24958,
   18.02744,
   15.89003,
   13.86719,
   11.98188,
   10.25024,
   8.681923,
   7.280659,
   6.045027,
   4.969338,
   4.044564,
   3.259249,
   2.600377,
   2.054129,
   1.606542,
   1.606542};
   TGraph *graph = new TGraph(58,Central_fx1,Central_fy1);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central1 = new TH1F("Graph_Central1","Projection of centralf DSCB fit",100,0.4602313,1.365708);
   Graph_Central1->SetMinimum(1.445888);
   Graph_Central1->SetMaximum(41.28837);
   Graph_Central1->SetDirectory(0);
   Graph_Central1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Central1->SetLineColor(ci);
   Graph_Central1->GetXaxis()->SetLabelFont(42);
   Graph_Central1->GetXaxis()->SetTitleOffset(1);
   Graph_Central1->GetXaxis()->SetTitleFont(42);
   Graph_Central1->GetYaxis()->SetLabelFont(42);
   Graph_Central1->GetYaxis()->SetTitleFont(42);
   Graph_Central1->GetZaxis()->SetLabelFont(42);
   Graph_Central1->GetZaxis()->SetTitleOffset(1);
   Graph_Central1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Central1);
   
   graph->Draw("l");
   
   TH1D *frame_2fd58310__2 = new TH1D("frame_2fd58310__2","p_T Balance",25,0,2);
   frame_2fd58310__2->SetBinContent(1,42.82029);
   frame_2fd58310__2->SetMaximum(42.82029);
   frame_2fd58310__2->SetEntries(1);
   frame_2fd58310__2->SetDirectory(0);
   frame_2fd58310__2->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fd58310__2->SetLineColor(ci);
   frame_2fd58310__2->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fd58310__2->GetXaxis()->SetLabelFont(42);
   frame_2fd58310__2->GetXaxis()->SetTitleOffset(1);
   frame_2fd58310__2->GetXaxis()->SetTitleFont(42);
   frame_2fd58310__2->GetYaxis()->SetTitle("1/Events");
   frame_2fd58310__2->GetYaxis()->SetLabelFont(42);
   frame_2fd58310__2->GetYaxis()->SetTitleFont(42);
   frame_2fd58310__2->GetZaxis()->SetLabelFont(42);
   frame_2fd58310__2->GetZaxis()->SetTitleOffset(1);
   frame_2fd58310__2->GetZaxis()->SetTitleFont(42);
   frame_2fd58310__2->Draw("AXISSAME");
   
   TH1D *norm_c__3 = new TH1D("norm_c__3","",25,0,2);
   norm_c__3->SetBinContent(1,0.0927769);
   norm_c__3->SetBinContent(2,0.6684073);
   norm_c__3->SetBinContent(3,1.449917);
   norm_c__3->SetBinContent(4,0.6464527);
   norm_c__3->SetBinContent(5,0.6692347);
   norm_c__3->SetBinContent(6,1.727927);
   norm_c__3->SetBinContent(7,2.804781);
   norm_c__3->SetBinContent(8,5.680706);
   norm_c__3->SetBinContent(9,13.06129);
   norm_c__3->SetBinContent(10,21.19137);
   norm_c__3->SetBinContent(11,31.40024);
   norm_c__3->SetBinContent(12,38.53565);
   norm_c__3->SetBinContent(13,33.68261);
   norm_c__3->SetBinContent(14,19.8511);
   norm_c__3->SetBinContent(15,9.74503);
   norm_c__3->SetBinContent(16,3.127685);
   norm_c__3->SetBinContent(17,1.180578);
   norm_c__3->SetBinContent(18,0.3610023);
   norm_c__3->SetBinContent(19,0.3055452);
   norm_c__3->SetBinContent(20,0.02259181);
   norm_c__3->SetBinContent(21,0.1478562);
   norm_c__3->SetBinContent(22,0.05842585);
   norm_c__3->SetBinContent(23,0.04782903);
   norm_c__3->SetBinContent(24,0.02443214);
   norm_c__3->SetBinContent(25,0.00274297);
   norm_c__3->SetBinContent(26,0.1363668);
   norm_c__3->SetBinError(1,0.06204455);
   norm_c__3->SetBinError(2,0.2698762);
   norm_c__3->SetBinError(3,0.4339385);
   norm_c__3->SetBinError(4,0.2713502);
   norm_c__3->SetBinError(5,0.3035533);
   norm_c__3->SetBinError(6,0.4777314);
   norm_c__3->SetBinError(7,0.6388579);
   norm_c__3->SetBinError(8,0.8630318);
   norm_c__3->SetBinError(9,1.375017);
   norm_c__3->SetBinError(10,1.704858);
   norm_c__3->SetBinError(11,2.038814);
   norm_c__3->SetBinError(12,2.245584);
   norm_c__3->SetBinError(13,2.07799);
   norm_c__3->SetBinError(14,1.559352);
   norm_c__3->SetBinError(15,1.127044);
   norm_c__3->SetBinError(16,0.629397);
   norm_c__3->SetBinError(17,0.3711005);
   norm_c__3->SetBinError(18,0.1721939);
   norm_c__3->SetBinError(19,0.1158859);
   norm_c__3->SetBinError(20,0.01523824);
   norm_c__3->SetBinError(21,0.1478562);
   norm_c__3->SetBinError(22,0.02550578);
   norm_c__3->SetBinError(23,0.04075713);
   norm_c__3->SetBinError(24,0.02443214);
   norm_c__3->SetBinError(25,0.001952796);
   norm_c__3->SetBinError(26,0.1170732);
   norm_c__3->SetEntries(2350);
   norm_c__3->SetStats(0);

   ci = 1311;
   color = new TColor(ci, 0.3, 0.3, 0.3, " ", 0.6);
   norm_c__3->SetFillColor(ci);
   norm_c__3->SetFillStyle(3144);
   norm_c__3->SetLineColor(2);
   norm_c__3->SetLineWidth(2);
   norm_c__3->GetXaxis()->SetRange(1,25);
   norm_c__3->GetXaxis()->SetLabelFont(42);
   norm_c__3->GetXaxis()->SetLabelSize(0.04);
   norm_c__3->GetXaxis()->SetTitleOffset(1);
   norm_c__3->GetXaxis()->SetTitleFont(42);
   norm_c__3->GetYaxis()->SetLabelFont(42);
   norm_c__3->GetYaxis()->SetTitleFont(42);
   norm_c__3->GetZaxis()->SetLabelFont(42);
   norm_c__3->GetZaxis()->SetTitleOffset(1);
   norm_c__3->GetZaxis()->SetTitleFont(42);
   norm_c__3->Draw("e1 same");
   
   TLegend *leg = new TLegend(0.65,0.5,0.93,0.87,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.03);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("norm_c","Central","lpf");

   ci = 1311;
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
   entry=leg->AddEntry("frame_x_c2_2fd58310","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.910470 #pm 0.011931","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.151200 #pm 0.009913","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.757000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_2fd58310_copy__4 = new TH1D("frame_2fd58310_copy__4","p_T Balance",25,0,2);
   frame_2fd58310_copy__4->SetBinContent(1,42.82029);
   frame_2fd58310_copy__4->SetMaximum(42.82029);
   frame_2fd58310_copy__4->SetEntries(1);
   frame_2fd58310_copy__4->SetDirectory(0);
   frame_2fd58310_copy__4->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fd58310_copy__4->SetLineColor(ci);
   frame_2fd58310_copy__4->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fd58310_copy__4->GetXaxis()->SetLabelFont(42);
   frame_2fd58310_copy__4->GetXaxis()->SetTitleOffset(1);
   frame_2fd58310_copy__4->GetXaxis()->SetTitleFont(42);
   frame_2fd58310_copy__4->GetYaxis()->SetTitle("1/Events");
   frame_2fd58310_copy__4->GetYaxis()->SetLabelFont(42);
   frame_2fd58310_copy__4->GetYaxis()->SetTitleFont(42);
   frame_2fd58310_copy__4->GetZaxis()->SetLabelFont(42);
   frame_2fd58310_copy__4->GetZaxis()->SetTitleOffset(1);
   frame_2fd58310_copy__4->GetZaxis()->SetTitleFont(42);
   frame_2fd58310_copy__4->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-4.411801,2.25,50.73572);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_2fd58130__5 = new TH1D("frame_2fd58130__5","p_T Balance",25,0,2);
   frame_2fd58130__5->SetBinContent(1,45.22097);
   frame_2fd58130__5->SetMaximum(45.22097);
   frame_2fd58130__5->SetEntries(1);
   frame_2fd58130__5->SetDirectory(0);
   frame_2fd58130__5->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fd58130__5->SetLineColor(ci);
   frame_2fd58130__5->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fd58130__5->GetXaxis()->SetLabelFont(42);
   frame_2fd58130__5->GetXaxis()->SetTitleOffset(1);
   frame_2fd58130__5->GetXaxis()->SetTitleFont(42);
   frame_2fd58130__5->GetYaxis()->SetTitle("1/Events");
   frame_2fd58130__5->GetYaxis()->SetLabelFont(42);
   frame_2fd58130__5->GetYaxis()->SetTitleFont(42);
   frame_2fd58130__5->GetZaxis()->SetLabelFont(42);
   frame_2fd58130__5->GetZaxis()->SetTitleOffset(1);
   frame_2fd58130__5->GetZaxis()->SetTitleFont(42);
   frame_2fd58130__5->Draw("FUNC");
   
   Double_t h_dh_up2_fx3002[25] = {
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
   Double_t h_dh_up2_fy3002[25] = {
   0.09582861,
   0.9887482,
   1.484218,
   0.7582726,
   0.8663825,
   1.434124,
   3.476637,
   5.649606,
   11.41705,
   19.23096,
   29.64759,
   40.76197,
   35.571,
   19.44352,
   10.35367,
   3.321378,
   1.348037,
   0.1137491,
   0.4214298,
   0.02397774,
   0.1521799,
   0.0604745,
   0.01782285,
   0.03037719,
   0.002713891};
   Double_t h_dh_up2_felx3002[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_up2_fely3002[25] = {
   0.06434893,
   0.3478076,
   0.4544519,
   0.3051176,
   0.3491934,
   0.4387993,
   0.7175009,
   0.8672648,
   1.270155,
   1.628142,
   1.965078,
   2.305616,
   2.147749,
   1.542434,
   1.140971,
   0.6598727,
   0.3958511,
   0.05823853,
   0.1939805,
   0.01520398,
   0.1466551,
   0.02654777,
   0.01261367,
   0.02494774,
   0.001931519};
   Double_t h_dh_up2_fehx3002[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_up2_fehy3002[25] = {
   0.06434893,
   0.3478076,
   0.4544519,
   0.3051176,
   0.3491934,
   0.4387993,
   0.7175009,
   0.8672648,
   1.270155,
   1.628142,
   1.965078,
   2.305616,
   2.147749,
   1.542434,
   1.140971,
   0.6598727,
   0.3958511,
   0.05823853,
   0.1939805,
   0.01520398,
   0.1466551,
   0.02654777,
   0.01261367,
   0.02494774,
   0.001931519};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3002,h_dh_up2_fy3002,h_dh_up2_felx3002,h_dh_up2_fehx3002,h_dh_up2_fely3002,h_dh_up2_fehy3002);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23002 = new TH1F("Graph_h_dh_up23002","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23002->SetMinimum(0.0007041354);
   Graph_h_dh_up23002->SetMaximum(47.37427);
   Graph_h_dh_up23002->SetDirectory(0);
   Graph_h_dh_up23002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_up23002->SetLineColor(ci);
   Graph_h_dh_up23002->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_up23002->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_up23002->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_up23002->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_up23002->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_up23002->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_up23002->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_up23002->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_up23002);
   
   grae->Draw("p");
   
   Double_t up_fx2[57] = {
   0.569612,
   0.5982291,
   0.6268463,
   0.6554634,
   0.669772,
   0.6840805,
   0.6983891,
   0.7126977,
   0.7270063,
   0.7413148,
   0.7556234,
   0.769932,
   0.7842405,
   0.7985491,
   0.8057034,
   0.8128577,
   0.8271663,
   0.8414748,
   0.8557834,
   0.870092,
   0.8772462,
   0.8844005,
   0.8915548,
   0.8987091,
   0.9058634,
   0.9130177,
   0.920172,
   0.9273262,
   0.9344805,
   0.9416348,
   0.9487891,
   0.9559434,
   0.9630977,
   0.970252,
   0.9774062,
   0.9845605,
   0.9917148,
   0.9988691,
   1.013178,
   1.027486,
   1.041795,
   1.056103,
   1.084721,
   1.099029,
   1.113338,
   1.127646,
   1.141955,
   1.156263,
   1.170572,
   1.184881,
   1.199189,
   1.213498,
   1.227806,
   1.242115,
   1.256423,
   1.285041,
   1.285041};
   Double_t up_fy2[57] = {
   6.2392,
   7.20075,
   8.354882,
   9.749792,
   10.55648,
   11.44835,
   12.43643,
   13.53345,
   14.75414,
   16.11562,
   17.63782,
   19.34407,
   21.26173,
   23.42301,
   24.60666,
   25.86603,
   28.44682,
   30.91781,
   33.20854,
   35.24982,
   36.15641,
   36.97687,
   37.70436,
   38.33271,
   38.85653,
   39.27127,
   39.57331,
   39.76001,
   39.82969,
   39.78176,
   39.61663,
   39.33577,
   38.94164,
   38.4377,
   37.82832,
   37.11874,
   36.31499,
   35.4238,
   33.40898,
   31.13847,
   28.68121,
   26.1074,
   20.87827,
   18.34252,
   15.92537,
   13.66426,
   11.58641,
   9.709073,
   8.040308,
   6.580226,
   5.385531,
   4.450179,
   3.709435,
   3.116658,
   2.637747,
   1.926735,
   1.926735};
   graph = new TGraph(57,up_fx2,up_fy2);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up2 = new TH1F("Graph_up2","Projection of upf DSCB fit",100,0.4980691,1.356583);
   Graph_up2->SetMinimum(1.734062);
   Graph_up2->SetMaximum(43.61999);
   Graph_up2->SetDirectory(0);
   Graph_up2->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_up2->SetLineColor(ci);
   Graph_up2->GetXaxis()->SetLabelFont(42);
   Graph_up2->GetXaxis()->SetTitleOffset(1);
   Graph_up2->GetXaxis()->SetTitleFont(42);
   Graph_up2->GetYaxis()->SetLabelFont(42);
   Graph_up2->GetYaxis()->SetTitleFont(42);
   Graph_up2->GetZaxis()->SetLabelFont(42);
   Graph_up2->GetZaxis()->SetTitleOffset(1);
   Graph_up2->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_up2);
   
   graph->Draw("l");
   
   TH1D *frame_2fd58130__6 = new TH1D("frame_2fd58130__6","p_T Balance",25,0,2);
   frame_2fd58130__6->SetBinContent(1,45.22097);
   frame_2fd58130__6->SetMaximum(45.22097);
   frame_2fd58130__6->SetEntries(1);
   frame_2fd58130__6->SetDirectory(0);
   frame_2fd58130__6->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fd58130__6->SetLineColor(ci);
   frame_2fd58130__6->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fd58130__6->GetXaxis()->SetLabelFont(42);
   frame_2fd58130__6->GetXaxis()->SetTitleOffset(1);
   frame_2fd58130__6->GetXaxis()->SetTitleFont(42);
   frame_2fd58130__6->GetYaxis()->SetTitle("1/Events");
   frame_2fd58130__6->GetYaxis()->SetLabelFont(42);
   frame_2fd58130__6->GetYaxis()->SetTitleFont(42);
   frame_2fd58130__6->GetZaxis()->SetLabelFont(42);
   frame_2fd58130__6->GetZaxis()->SetTitleOffset(1);
   frame_2fd58130__6->GetZaxis()->SetTitleFont(42);
   frame_2fd58130__6->Draw("AXISSAME");
   
   TH1D *norm_u__7 = new TH1D("norm_u__7","",25,0,2);
   norm_u__7->SetBinContent(1,0.09582861);
   norm_u__7->SetBinContent(2,0.9887482);
   norm_u__7->SetBinContent(3,1.484218);
   norm_u__7->SetBinContent(4,0.7582726);
   norm_u__7->SetBinContent(5,0.8663825);
   norm_u__7->SetBinContent(6,1.434124);
   norm_u__7->SetBinContent(7,3.476637);
   norm_u__7->SetBinContent(8,5.649606);
   norm_u__7->SetBinContent(9,11.41705);
   norm_u__7->SetBinContent(10,19.23095);
   norm_u__7->SetBinContent(11,29.64759);
   norm_u__7->SetBinContent(12,40.76197);
   norm_u__7->SetBinContent(13,35.571);
   norm_u__7->SetBinContent(14,19.44352);
   norm_u__7->SetBinContent(15,10.35367);
   norm_u__7->SetBinContent(16,3.321378);
   norm_u__7->SetBinContent(17,1.348038);
   norm_u__7->SetBinContent(18,0.1137491);
   norm_u__7->SetBinContent(19,0.4214298);
   norm_u__7->SetBinContent(20,0.02397774);
   norm_u__7->SetBinContent(21,0.1521799);
   norm_u__7->SetBinContent(22,0.0604745);
   norm_u__7->SetBinContent(23,0.01782285);
   norm_u__7->SetBinContent(24,0.03037719);
   norm_u__7->SetBinContent(25,0.002713891);
   norm_u__7->SetBinContent(26,0.02086393);
   norm_u__7->SetBinError(1,0.06434893);
   norm_u__7->SetBinError(2,0.3478076);
   norm_u__7->SetBinError(3,0.4544519);
   norm_u__7->SetBinError(4,0.3051176);
   norm_u__7->SetBinError(5,0.3491934);
   norm_u__7->SetBinError(6,0.4387993);
   norm_u__7->SetBinError(7,0.7175009);
   norm_u__7->SetBinError(8,0.8672648);
   norm_u__7->SetBinError(9,1.270155);
   norm_u__7->SetBinError(10,1.628142);
   norm_u__7->SetBinError(11,1.965078);
   norm_u__7->SetBinError(12,2.305616);
   norm_u__7->SetBinError(13,2.147749);
   norm_u__7->SetBinError(14,1.542434);
   norm_u__7->SetBinError(15,1.140971);
   norm_u__7->SetBinError(16,0.6598727);
   norm_u__7->SetBinError(17,0.3958511);
   norm_u__7->SetBinError(18,0.05823853);
   norm_u__7->SetBinError(19,0.1939805);
   norm_u__7->SetBinError(20,0.01520398);
   norm_u__7->SetBinError(21,0.1466551);
   norm_u__7->SetBinError(22,0.02654777);
   norm_u__7->SetBinError(23,0.01261367);
   norm_u__7->SetBinError(24,0.02494774);
   norm_u__7->SetBinError(25,0.001931519);
   norm_u__7->SetBinError(26,0.009839689);
   norm_u__7->SetEntries(2331);
   norm_u__7->SetStats(0);
   norm_u__7->SetLineColor(4);
   norm_u__7->SetLineWidth(2);
   norm_u__7->GetXaxis()->SetLabelFont(42);
   norm_u__7->GetXaxis()->SetTitleOffset(1);
   norm_u__7->GetXaxis()->SetTitleFont(42);
   norm_u__7->GetYaxis()->SetLabelFont(42);
   norm_u__7->GetYaxis()->SetTitleFont(42);
   norm_u__7->GetZaxis()->SetLabelFont(42);
   norm_u__7->GetZaxis()->SetTitleOffset(1);
   norm_u__7->GetZaxis()->SetTitleFont(42);
   norm_u__7->Draw("e1 same");
   
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
   entry=leg->AddEntry("frame_x_u2_2fd58130","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.915780 #pm 0.012295","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.152524 #pm 0.010721","");
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
   
   TH1D *frame_2fd58130_copy__8 = new TH1D("frame_2fd58130_copy__8","p_T Balance",25,0,2);
   frame_2fd58130_copy__8->SetBinContent(1,45.22097);
   frame_2fd58130_copy__8->SetMaximum(45.22097);
   frame_2fd58130_copy__8->SetEntries(1);
   frame_2fd58130_copy__8->SetDirectory(0);
   frame_2fd58130_copy__8->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fd58130_copy__8->SetLineColor(ci);
   frame_2fd58130_copy__8->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fd58130_copy__8->GetXaxis()->SetLabelFont(42);
   frame_2fd58130_copy__8->GetXaxis()->SetTitleOffset(1);
   frame_2fd58130_copy__8->GetXaxis()->SetTitleFont(42);
   frame_2fd58130_copy__8->GetYaxis()->SetTitle("1/Events");
   frame_2fd58130_copy__8->GetYaxis()->SetLabelFont(42);
   frame_2fd58130_copy__8->GetYaxis()->SetTitleFont(42);
   frame_2fd58130_copy__8->GetZaxis()->SetLabelFont(42);
   frame_2fd58130_copy__8->GetZaxis()->SetTitleOffset(1);
   frame_2fd58130_copy__8->GetZaxis()->SetTitleFont(42);
   frame_2fd58130_copy__8->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-6.711164,2.25,41.22572);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_2fd5a2a0__9 = new TH1D("frame_2fd5a2a0__9","p_T Balance",25,0,2);
   frame_2fd5a2a0__9->SetBinContent(1,40.26698);
   frame_2fd5a2a0__9->SetMinimum(-1.917475);
   frame_2fd5a2a0__9->SetMaximum(40.26698);
   frame_2fd5a2a0__9->SetEntries(1);
   frame_2fd5a2a0__9->SetDirectory(0);
   frame_2fd5a2a0__9->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fd5a2a0__9->SetLineColor(ci);
   frame_2fd5a2a0__9->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fd5a2a0__9->GetXaxis()->SetLabelFont(42);
   frame_2fd5a2a0__9->GetXaxis()->SetTitleOffset(1);
   frame_2fd5a2a0__9->GetXaxis()->SetTitleFont(42);
   frame_2fd5a2a0__9->GetYaxis()->SetTitle("1/Events");
   frame_2fd5a2a0__9->GetYaxis()->SetLabelFont(42);
   frame_2fd5a2a0__9->GetYaxis()->SetTitleFont(42);
   frame_2fd5a2a0__9->GetZaxis()->SetLabelFont(42);
   frame_2fd5a2a0__9->GetZaxis()->SetTitleOffset(1);
   frame_2fd5a2a0__9->GetZaxis()->SetTitleFont(42);
   frame_2fd5a2a0__9->Draw("FUNC");
   
   Double_t h_dh_down2_fx3003[25] = {
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
   Double_t h_dh_down2_fy3003[25] = {
   0.09007429,
   0.6204278,
   1.794539,
   0.8586522,
   0.9732918,
   1.717984,
   3.617537,
   6.171016,
   12.74899,
   22.5443,
   31.84844,
   36.19352,
   31.82211,
   16.75277,
   9.829878,
   2.660899,
   0.8009329,
   0.4222552,
   0.1716043,
   0.008616539,
   0.02397107,
   0.1144993,
   0.04666126,
   0.00154781,
   0.01129465};
   Double_t h_dh_down2_felx3003[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_down2_fely3003[25] = {
   0.06004975,
   0.2620506,
   0.4972082,
   0.3334988,
   0.3763377,
   0.4629778,
   0.7168859,
   0.9028853,
   1.346299,
   1.773716,
   2.065099,
   2.15599,
   2.019271,
   1.405348,
   1.133556,
   0.5590815,
   0.2653296,
   0.1812399,
   0.0752685,
   0.006000085,
   0.01505784,
   0.05854708,
   0.029213,
   0.00154781,
   0.00880056};
   Double_t h_dh_down2_fehx3003[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_down2_fehy3003[25] = {
   0.06004975,
   0.2620506,
   0.4972082,
   0.3334988,
   0.3763377,
   0.4629778,
   0.7168859,
   0.9028853,
   1.346299,
   1.773716,
   2.065099,
   2.15599,
   2.019271,
   1.405348,
   1.133556,
   0.5590815,
   0.2653296,
   0.1812399,
   0.0752685,
   0.006000085,
   0.01505784,
   0.05854708,
   0.029213,
   0.00154781,
   0.00880056};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3003,h_dh_down2_fy3003,h_dh_down2_felx3003,h_dh_down2_fehx3003,h_dh_down2_fely3003,h_dh_down2_fehy3003);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23003 = new TH1F("Graph_h_dh_down23003","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23003->SetMinimum(-3.834951);
   Graph_h_dh_down23003->SetMaximum(42.18446);
   Graph_h_dh_down23003->SetDirectory(0);
   Graph_h_dh_down23003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_down23003->SetLineColor(ci);
   Graph_h_dh_down23003->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_down23003->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_down23003->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_down23003->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_down23003->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_down23003->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_down23003->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_down23003->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_down23003);
   
   grae->Draw("p");
   
   Double_t down_fx3[57] = {
   0.5320681,
   0.5470151,
   0.5619621,
   0.5769091,
   0.591856,
   0.606803,
   0.62175,
   0.636697,
   0.651644,
   0.666591,
   0.681538,
   0.696485,
   0.711432,
   0.7413259,
   0.7712199,
   0.7861669,
   0.8011139,
   0.8160609,
   0.8310079,
   0.8459549,
   0.8534284,
   0.8609018,
   0.8683753,
   0.8758488,
   0.8833223,
   0.8907958,
   0.8982693,
   0.9057428,
   0.9132163,
   0.9206898,
   0.9281633,
   0.9356368,
   0.9431103,
   0.9505838,
   0.9580573,
   0.9655308,
   0.9804778,
   0.9954248,
   1.010372,
   1.025319,
   1.040266,
   1.07016,
   1.085107,
   1.100054,
   1.115001,
   1.129948,
   1.144895,
   1.159842,
   1.174789,
   1.189736,
   1.204683,
   1.21963,
   1.234577,
   1.249524,
   1.264471,
   1.279418,
   1.279418};
   Double_t down_fy3[57] = {
   1.864682,
   2.353892,
   2.94587,
   3.651484,
   4.482849,
   5.450894,
   6.564629,
   7.830356,
   9.25085,
   10.82457,
   12.54494,
   14.39976,
   16.37083,
   20.55836,
   24.84401,
   26.9204,
   28.89151,
   30.71056,
   32.33212,
   33.71394,
   34.30306,
   34.81878,
   35.2575,
   35.61612,
   35.8921,
   36.08348,
   36.18888,
   36.20754,
   36.13934,
   35.98476,
   35.74491,
   35.4215,
   35.01685,
   34.53379,
   33.97572,
   33.34651,
   31.89226,
   30.20989,
   28.34274,
   26.33682,
   24.23894,
   19.94807,
   17.83766,
   15.79806,
   13.85793,
   12.03987,
   10.36034,
   8.829893,
   7.45359,
   6.231669,
   5.160267,
   4.232225,
   3.437908,
   2.765977,
   2.204103,
   1.739578,
   1.739578};
   graph = new TGraph(57,down_fx3,down_fy3);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down3 = new TH1F("Graph_down3","Projection of downf DSCB fit",100,0.4573331,1.354152);
   Graph_down3->SetMinimum(1.56562);
   Graph_down3->SetMaximum(39.65434);
   Graph_down3->SetDirectory(0);
   Graph_down3->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_down3->SetLineColor(ci);
   Graph_down3->GetXaxis()->SetLabelFont(42);
   Graph_down3->GetXaxis()->SetTitleOffset(1);
   Graph_down3->GetXaxis()->SetTitleFont(42);
   Graph_down3->GetYaxis()->SetLabelFont(42);
   Graph_down3->GetYaxis()->SetTitleFont(42);
   Graph_down3->GetZaxis()->SetLabelFont(42);
   Graph_down3->GetZaxis()->SetTitleOffset(1);
   Graph_down3->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_down3);
   
   graph->Draw("l");
   
   TH1D *frame_2fd5a2a0__10 = new TH1D("frame_2fd5a2a0__10","p_T Balance",25,0,2);
   frame_2fd5a2a0__10->SetBinContent(1,40.26698);
   frame_2fd5a2a0__10->SetMinimum(-1.917475);
   frame_2fd5a2a0__10->SetMaximum(40.26698);
   frame_2fd5a2a0__10->SetEntries(1);
   frame_2fd5a2a0__10->SetDirectory(0);
   frame_2fd5a2a0__10->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fd5a2a0__10->SetLineColor(ci);
   frame_2fd5a2a0__10->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fd5a2a0__10->GetXaxis()->SetLabelFont(42);
   frame_2fd5a2a0__10->GetXaxis()->SetTitleOffset(1);
   frame_2fd5a2a0__10->GetXaxis()->SetTitleFont(42);
   frame_2fd5a2a0__10->GetYaxis()->SetTitle("1/Events");
   frame_2fd5a2a0__10->GetYaxis()->SetLabelFont(42);
   frame_2fd5a2a0__10->GetYaxis()->SetTitleFont(42);
   frame_2fd5a2a0__10->GetZaxis()->SetLabelFont(42);
   frame_2fd5a2a0__10->GetZaxis()->SetTitleOffset(1);
   frame_2fd5a2a0__10->GetZaxis()->SetTitleFont(42);
   frame_2fd5a2a0__10->Draw("AXISSAME");
   
   TH1D *norm_d__11 = new TH1D("norm_d__11","",25,0,2);
   norm_d__11->SetBinContent(1,0.09007429);
   norm_d__11->SetBinContent(2,0.6204278);
   norm_d__11->SetBinContent(3,1.794539);
   norm_d__11->SetBinContent(4,0.8586522);
   norm_d__11->SetBinContent(5,0.9732917);
   norm_d__11->SetBinContent(6,1.717984);
   norm_d__11->SetBinContent(7,3.617536);
   norm_d__11->SetBinContent(8,6.171016);
   norm_d__11->SetBinContent(9,12.74899);
   norm_d__11->SetBinContent(10,22.5443);
   norm_d__11->SetBinContent(11,31.84844);
   norm_d__11->SetBinContent(12,36.19352);
   norm_d__11->SetBinContent(13,31.82212);
   norm_d__11->SetBinContent(14,16.75277);
   norm_d__11->SetBinContent(15,9.829878);
   norm_d__11->SetBinContent(16,2.660899);
   norm_d__11->SetBinContent(17,0.8009329);
   norm_d__11->SetBinContent(18,0.4222552);
   norm_d__11->SetBinContent(19,0.1716043);
   norm_d__11->SetBinContent(20,0.008616539);
   norm_d__11->SetBinContent(21,0.02397107);
   norm_d__11->SetBinContent(22,0.1144993);
   norm_d__11->SetBinContent(23,0.04666126);
   norm_d__11->SetBinContent(24,0.00154781);
   norm_d__11->SetBinContent(25,0.01129465);
   norm_d__11->SetBinContent(26,0.1355334);
   norm_d__11->SetBinError(1,0.06004975);
   norm_d__11->SetBinError(2,0.2620506);
   norm_d__11->SetBinError(3,0.4972082);
   norm_d__11->SetBinError(4,0.3334988);
   norm_d__11->SetBinError(5,0.3763377);
   norm_d__11->SetBinError(6,0.4629778);
   norm_d__11->SetBinError(7,0.7168859);
   norm_d__11->SetBinError(8,0.9028853);
   norm_d__11->SetBinError(9,1.346299);
   norm_d__11->SetBinError(10,1.773716);
   norm_d__11->SetBinError(11,2.065099);
   norm_d__11->SetBinError(12,2.15599);
   norm_d__11->SetBinError(13,2.019271);
   norm_d__11->SetBinError(14,1.405348);
   norm_d__11->SetBinError(15,1.133556);
   norm_d__11->SetBinError(16,0.5590815);
   norm_d__11->SetBinError(17,0.2653296);
   norm_d__11->SetBinError(18,0.1812399);
   norm_d__11->SetBinError(19,0.0752685);
   norm_d__11->SetBinError(20,0.006000085);
   norm_d__11->SetBinError(21,0.01505784);
   norm_d__11->SetBinError(22,0.05854708);
   norm_d__11->SetBinError(23,0.029213);
   norm_d__11->SetBinError(24,0.00154781);
   norm_d__11->SetBinError(25,0.00880056);
   norm_d__11->SetBinError(26,0.1181754);
   norm_d__11->SetEntries(2358);
   norm_d__11->SetStats(0);
   norm_d__11->SetLineColor(7);
   norm_d__11->SetLineWidth(2);
   norm_d__11->GetXaxis()->SetLabelFont(42);
   norm_d__11->GetXaxis()->SetTitleOffset(1);
   norm_d__11->GetXaxis()->SetTitleFont(42);
   norm_d__11->GetYaxis()->SetLabelFont(42);
   norm_d__11->GetYaxis()->SetTitleFont(42);
   norm_d__11->GetZaxis()->SetLabelFont(42);
   norm_d__11->GetZaxis()->SetTitleOffset(1);
   norm_d__11->GetZaxis()->SetTitleFont(42);
   norm_d__11->Draw("same e1");
   
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
   entry=leg->AddEntry("frame_x_d2_2fd5a2a0","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.903677 #pm 0.012291","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.152487 #pm 0.010340","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.766000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_2fd5a2a0_copy__12 = new TH1D("frame_2fd5a2a0_copy__12","p_T Balance",25,0,2);
   frame_2fd5a2a0_copy__12->SetBinContent(1,40.26698);
   frame_2fd5a2a0_copy__12->SetMinimum(-1.917475);
   frame_2fd5a2a0_copy__12->SetMaximum(40.26698);
   frame_2fd5a2a0_copy__12->SetEntries(1);
   frame_2fd5a2a0_copy__12->SetDirectory(0);
   frame_2fd5a2a0_copy__12->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fd5a2a0_copy__12->SetLineColor(ci);
   frame_2fd5a2a0_copy__12->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fd5a2a0_copy__12->GetXaxis()->SetLabelFont(42);
   frame_2fd5a2a0_copy__12->GetXaxis()->SetTitleOffset(1);
   frame_2fd5a2a0_copy__12->GetXaxis()->SetTitleFont(42);
   frame_2fd5a2a0_copy__12->GetYaxis()->SetTitle("1/Events");
   frame_2fd5a2a0_copy__12->GetYaxis()->SetLabelFont(42);
   frame_2fd5a2a0_copy__12->GetYaxis()->SetTitleFont(42);
   frame_2fd5a2a0_copy__12->GetZaxis()->SetLabelFont(42);
   frame_2fd5a2a0_copy__12->GetZaxis()->SetTitleOffset(1);
   frame_2fd5a2a0_copy__12->GetZaxis()->SetTitleFont(42);
   frame_2fd5a2a0_copy__12->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-8.461612,2.25,76.15451);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_2fd5ac70__13 = new TH1D("frame_2fd5ac70__13","p_T Balance",25,0,2);
   frame_2fd5ac70__13->SetBinContent(1,74.46218);
   frame_2fd5ac70__13->SetMaximum(74.46218);
   frame_2fd5ac70__13->SetEntries(1);
   frame_2fd5ac70__13->SetDirectory(0);
   frame_2fd5ac70__13->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fd5ac70__13->SetLineColor(ci);
   frame_2fd5ac70__13->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fd5ac70__13->GetXaxis()->SetLabelFont(42);
   frame_2fd5ac70__13->GetXaxis()->SetTitleOffset(1);
   frame_2fd5ac70__13->GetXaxis()->SetTitleFont(42);
   frame_2fd5ac70__13->GetYaxis()->SetTitle("1/Events");
   frame_2fd5ac70__13->GetYaxis()->SetLabelFont(42);
   frame_2fd5ac70__13->GetYaxis()->SetTitleFont(42);
   frame_2fd5ac70__13->GetZaxis()->SetLabelFont(42);
   frame_2fd5ac70__13->GetZaxis()->SetTitleOffset(1);
   frame_2fd5ac70__13->GetZaxis()->SetTitleFont(42);
   frame_2fd5ac70__13->Draw("FUNC");
   
   Double_t h_dh_data2_fx3004[25] = {
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
   Double_t h_dh_data2_fy3004[25] = {
   0,
   1,
   1,
   2,
   1,
   3,
   5,
   11,
   16,
   40,
   47,
   62,
   42,
   31,
   11,
   5,
   0,
   4,
   0,
   0,
   0,
   0,
   0,
   1,
   0};
   Double_t h_dh_data2_felx3004[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_data2_fely3004[25] = {
   0,
   0.8272462,
   0.8272462,
   1.291815,
   0.8272462,
   1.632705,
   2.159691,
   3.265579,
   3.957801,
   6.298,
   6.831172,
   7.852713,
   6.454831,
   5.537565,
   3.265579,
   2.159691,
   0,
   1.914339,
   0,
   0,
   0,
   0,
   0,
   0.8272462,
   0};
   Double_t h_dh_data2_fehx3004[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_data2_fehy3004[25] = {
   1.147874,
   2.299527,
   2.299527,
   2.63786,
   2.299527,
   2.918186,
   3.382473,
   4.416521,
   5.083066,
   7.377261,
   7.904289,
   8.916365,
   7.53218,
   6.627601,
   4.416521,
   3.382473,
   1.147874,
   3.162753,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   2.299527,
   1.147874};
   grae = new TGraphAsymmErrors(25,h_dh_data2_fx3004,h_dh_data2_fy3004,h_dh_data2_felx3004,h_dh_data2_fehx3004,h_dh_data2_fely3004,h_dh_data2_fehy3004);
   grae->SetName("h_dh_data2");
   grae->SetTitle("Histogram of dh_data2_plot__x_o2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_data23004 = new TH1F("Graph_h_dh_data23004","Histogram of dh_data2_plot__x_o2",100,0,2.2);
   Graph_h_dh_data23004->SetMinimum(0);
   Graph_h_dh_data23004->SetMaximum(78.008);
   Graph_h_dh_data23004->SetDirectory(0);
   Graph_h_dh_data23004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_data23004->SetLineColor(ci);
   Graph_h_dh_data23004->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_data23004->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_data23004->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_data23004->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_data23004->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_data23004->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_data23004->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_data23004->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_data23004);
   
   grae->Draw("p");
   
   Double_t observation_fx4[60] = {
   0.4908909,
   0.5236782,
   0.5564656,
   0.5728593,
   0.589253,
   0.6056467,
   0.6220404,
   0.6384341,
   0.6548278,
   0.6712215,
   0.6876152,
   0.695812,
   0.7040089,
   0.7122057,
   0.7204026,
   0.7367963,
   0.75319,
   0.7859773,
   0.802371,
   0.8187647,
   0.8269616,
   0.8351584,
   0.8433553,
   0.8515521,
   0.859749,
   0.8679458,
   0.8761426,
   0.8843395,
   0.8925363,
   0.9007332,
   0.90893,
   0.9171269,
   0.9253237,
   0.9335206,
   0.9417174,
   0.9499143,
   0.9581111,
   0.966308,
   0.9745048,
   0.9827017,
   0.9990953,
   1.015489,
   1.031883,
   1.048276,
   1.081064,
   1.097458,
   1.113851,
   1.130245,
   1.146639,
   1.163032,
   1.179426,
   1.19582,
   1.212213,
   1.228607,
   1.245001,
   1.261394,
   1.277788,
   1.294182,
   1.310576,
   1.310576};
   Double_t observation_fy4[60] = {
   5.188271,
   6.288944,
   7.697607,
   8.549997,
   9.523709,
   10.64007,
   11.9249,
   13.40965,
   15.13285,
   17.14195,
   19.49582,
   20.82433,
   22.26795,
   23.83887,
   25.55079,
   29.32687,
   33.25537,
   41.14476,
   44.89224,
   48.35578,
   49.94528,
   51.42161,
   52.7718,
   53.98376,
   55.04648,
   55.95011,
   56.68621,
   57.24782,
   57.6296,
   57.82788,
   57.84076,
   57.66812,
   57.31162,
   56.77466,
   56.06238,
   55.18151,
   54.14031,
   52.94841,
   51.61669,
   50.1571,
   46.90641,
   43.30642,
   39.47231,
   35.51837,
   27.67164,
   23.95831,
   20.47848,
   17.28063,
   14.39599,
   11.83978,
   9.613164,
   7.705647,
   6.097786,
   4.763821,
   3.674168,
   2.797582,
   2.10294,
   1.560598,
   1.143341,
   1.143341};
   graph = new TGraph(60,observation_fx4,observation_fy4);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation4 = new TH1F("Graph_observation4","Projection of obsf DSCB fit",100,0.4089224,1.392544);
   Graph_observation4->SetMinimum(1.029007);
   Graph_observation4->SetMaximum(63.5105);
   Graph_observation4->SetDirectory(0);
   Graph_observation4->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_observation4->SetLineColor(ci);
   Graph_observation4->GetXaxis()->SetLabelFont(42);
   Graph_observation4->GetXaxis()->SetTitleOffset(1);
   Graph_observation4->GetXaxis()->SetTitleFont(42);
   Graph_observation4->GetYaxis()->SetLabelFont(42);
   Graph_observation4->GetYaxis()->SetTitleFont(42);
   Graph_observation4->GetZaxis()->SetLabelFont(42);
   Graph_observation4->GetZaxis()->SetTitleOffset(1);
   Graph_observation4->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_observation4);
   
   graph->Draw("l");
   
   TH1D *frame_2fd5ac70__14 = new TH1D("frame_2fd5ac70__14","p_T Balance",25,0,2);
   frame_2fd5ac70__14->SetBinContent(1,74.46218);
   frame_2fd5ac70__14->SetMaximum(74.46218);
   frame_2fd5ac70__14->SetEntries(1);
   frame_2fd5ac70__14->SetDirectory(0);
   frame_2fd5ac70__14->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fd5ac70__14->SetLineColor(ci);
   frame_2fd5ac70__14->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fd5ac70__14->GetXaxis()->SetLabelFont(42);
   frame_2fd5ac70__14->GetXaxis()->SetTitleOffset(1);
   frame_2fd5ac70__14->GetXaxis()->SetTitleFont(42);
   frame_2fd5ac70__14->GetYaxis()->SetTitle("1/Events");
   frame_2fd5ac70__14->GetYaxis()->SetLabelFont(42);
   frame_2fd5ac70__14->GetYaxis()->SetTitleFont(42);
   frame_2fd5ac70__14->GetZaxis()->SetLabelFont(42);
   frame_2fd5ac70__14->GetZaxis()->SetTitleOffset(1);
   frame_2fd5ac70__14->GetZaxis()->SetTitleFont(42);
   frame_2fd5ac70__14->Draw("AXISSAME");
   
   TH1D *norm_o__15 = new TH1D("norm_o__15","",25,0,2);
   norm_o__15->SetBinContent(2,1);
   norm_o__15->SetBinContent(3,1);
   norm_o__15->SetBinContent(4,2);
   norm_o__15->SetBinContent(5,1);
   norm_o__15->SetBinContent(6,3);
   norm_o__15->SetBinContent(7,5);
   norm_o__15->SetBinContent(8,11);
   norm_o__15->SetBinContent(9,16);
   norm_o__15->SetBinContent(10,40);
   norm_o__15->SetBinContent(11,47);
   norm_o__15->SetBinContent(12,62);
   norm_o__15->SetBinContent(13,42);
   norm_o__15->SetBinContent(14,31);
   norm_o__15->SetBinContent(15,11);
   norm_o__15->SetBinContent(16,5);
   norm_o__15->SetBinContent(18,4);
   norm_o__15->SetBinContent(24,1);
   norm_o__15->SetMinimum(0);
   norm_o__15->SetMaximum(136.4);
   norm_o__15->SetEntries(283);
   norm_o__15->SetStats(0);
   norm_o__15->SetLineWidth(2);
   norm_o__15->SetMarkerStyle(8);
   norm_o__15->SetMarkerSize(0.4);
   norm_o__15->GetXaxis()->SetRange(1,25);
   norm_o__15->GetXaxis()->SetLabelFont(42);
   norm_o__15->GetXaxis()->SetLabelSize(0.04);
   norm_o__15->GetXaxis()->SetTitleOffset(1);
   norm_o__15->GetXaxis()->SetTitleFont(42);
   norm_o__15->GetYaxis()->SetTitle("Events");
   norm_o__15->GetYaxis()->SetLabelFont(42);
   norm_o__15->GetYaxis()->SetTitleOffset(1.4);
   norm_o__15->GetYaxis()->SetTitleFont(42);
   norm_o__15->GetZaxis()->SetLabelFont(42);
   norm_o__15->GetZaxis()->SetTitleOffset(1);
   norm_o__15->GetZaxis()->SetTitleFont(42);
   norm_o__15->Draw("same e1");
   
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
   entry=leg->AddEntry("frame_x_o2_2fd5ac70","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.893736 #pm 0.009921","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.157189 #pm 0.008004","");
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
   
   TH1D *frame_2fd5ac70_copy__16 = new TH1D("frame_2fd5ac70_copy__16","p_T Balance",25,0,2);
   frame_2fd5ac70_copy__16->SetBinContent(1,74.46218);
   frame_2fd5ac70_copy__16->SetMaximum(74.46218);
   frame_2fd5ac70_copy__16->SetEntries(1);
   frame_2fd5ac70_copy__16->SetDirectory(0);
   frame_2fd5ac70_copy__16->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_2fd5ac70_copy__16->SetLineColor(ci);
   frame_2fd5ac70_copy__16->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_2fd5ac70_copy__16->GetXaxis()->SetLabelFont(42);
   frame_2fd5ac70_copy__16->GetXaxis()->SetTitleOffset(1);
   frame_2fd5ac70_copy__16->GetXaxis()->SetTitleFont(42);
   frame_2fd5ac70_copy__16->GetYaxis()->SetTitle("1/Events");
   frame_2fd5ac70_copy__16->GetYaxis()->SetLabelFont(42);
   frame_2fd5ac70_copy__16->GetYaxis()->SetTitleFont(42);
   frame_2fd5ac70_copy__16->GetZaxis()->SetLabelFont(42);
   frame_2fd5ac70_copy__16->GetZaxis()->SetTitleOffset(1);
   frame_2fd5ac70_copy__16->GetZaxis()->SetTitleFont(42);
   frame_2fd5ac70_copy__16->Draw("sameaxis");
   
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
