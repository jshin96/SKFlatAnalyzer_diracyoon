void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_1__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 16:58:00 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-2.582834,2.25,19.44133);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_306b83d0__1 = new TH1D("frame_306b83d0__1","p_T Balance",25,0,2);
   frame_306b83d0__1->SetBinContent(1,17.23891);
   frame_306b83d0__1->SetMinimum(-0.8209007);
   frame_306b83d0__1->SetMaximum(17.23891);
   frame_306b83d0__1->SetEntries(1);
   frame_306b83d0__1->SetDirectory(0);
   frame_306b83d0__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_306b83d0__1->SetLineColor(ci);
   frame_306b83d0__1->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_306b83d0__1->GetXaxis()->SetLabelFont(42);
   frame_306b83d0__1->GetXaxis()->SetTitleOffset(1);
   frame_306b83d0__1->GetXaxis()->SetTitleFont(42);
   frame_306b83d0__1->GetYaxis()->SetTitle("1/Events");
   frame_306b83d0__1->GetYaxis()->SetLabelFont(42);
   frame_306b83d0__1->GetYaxis()->SetTitleFont(42);
   frame_306b83d0__1->GetZaxis()->SetLabelFont(42);
   frame_306b83d0__1->GetZaxis()->SetTitleOffset(1);
   frame_306b83d0__1->GetZaxis()->SetTitleFont(42);
   frame_306b83d0__1->Draw("FUNC");
   
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
   0,
   0.2650859,
   0.05424485,
   0.06874596,
   0.2510789,
   0.1586845,
   1.436286,
   1.788286,
   4.400204,
   7.56887,
   10.90341,
   14.86503,
   11.12656,
   7.124347,
   2.356896,
   0.4741437,
   0.3480052,
   0.1315298,
   0.03445249,
   0.007282548,
   0,
   0.005909765,
   0,
   0.01420382,
   0};
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
   0,
   0.1895588,
   0.05424485,
   0.04740479,
   0.2044528,
   0.08644941,
   0.4883713,
   0.553094,
   0.853857,
   1.166644,
   1.316642,
   1.552988,
   1.342045,
   1.065432,
   0.614331,
   0.2600161,
   0.1962608,
   0.0729932,
   0.01959084,
   0.007282548,
   0,
   0.005909765,
   0,
   0.01005488,
   0};
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
   0,
   0.1895588,
   0.05424485,
   0.04740479,
   0.2044528,
   0.08644941,
   0.4883713,
   0.553094,
   0.853857,
   1.166644,
   1.316642,
   1.552988,
   1.342045,
   1.065432,
   0.614331,
   0.2600161,
   0.1962608,
   0.0729932,
   0.01959084,
   0.007282548,
   0,
   0.005909765,
   0,
   0.01005488,
   0};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3001,h_dh_central2_fy3001,h_dh_central2_felx3001,h_dh_central2_fehx3001,h_dh_central2_fely3001,h_dh_central2_fehy3001);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23001 = new TH1F("Graph_h_dh_central23001","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23001->SetMinimum(-1.641801);
   Graph_h_dh_central23001->SetMaximum(18.05982);
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
   0.5607758,
   0.5884639,
   0.6161519,
   0.6299959,
   0.6438399,
   0.6576839,
   0.6715279,
   0.6853719,
   0.6992159,
   0.71306,
   0.726904,
   0.733826,
   0.740748,
   0.754592,
   0.78228,
   0.796124,
   0.809968,
   0.823812,
   0.837656,
   0.8515001,
   0.8584221,
   0.8653441,
   0.8722661,
   0.8791881,
   0.8861101,
   0.8930321,
   0.8999541,
   0.9068761,
   0.9137981,
   0.9207201,
   0.9276421,
   0.9345641,
   0.9414861,
   0.9484081,
   0.9553301,
   0.9622521,
   0.9691741,
   0.9760961,
   0.9899402,
   1.003784,
   1.017628,
   1.031472,
   1.05916,
   1.073004,
   1.086848,
   1.100692,
   1.114536,
   1.12838,
   1.142224,
   1.156068,
   1.169912,
   1.183756,
   1.1976,
   1.211444,
   1.225288,
   1.239132,
   1.252976,
   1.252976};
   Double_t Central_fy1[58] = {
   1.601675,
   1.923381,
   2.33008,
   2.573783,
   2.8502,
   3.164746,
   3.52391,
   3.935509,
   4.409001,
   4.955902,
   5.590302,
   5.945586,
   6.329552,
   7.163121,
   8.896693,
   9.760617,
   10.597,
   11.38533,
   12.10501,
   12.73625,
   13.01296,
   13.26096,
   13.47839,
   13.66361,
   13.8152,
   13.93198,
   14.01306,
   14.0578,
   14.06585,
   14.03715,
   13.97191,
   13.87066,
   13.73418,
   13.56353,
   13.36001,
   13.12517,
   12.86078,
   12.56881,
   11.91079,
   11.16976,
   10.36583,
   9.519656,
   7.780842,
   6.92492,
   6.099017,
   5.315718,
   4.584807,
   3.913245,
   3.305294,
   2.762741,
   2.285215,
   1.870557,
   1.515207,
   1.21459,
   0.9634845,
   0.7563392,
   0.5875508,
   0.5875508};
   TGraph *graph = new TGraph(58,Central_fx1,Central_fy1);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central1 = new TH1F("Graph_Central1","Projection of centralf DSCB fit",100,0.4915558,1.322196);
   Graph_Central1->SetMinimum(0.5287957);
   Graph_Central1->SetMaximum(15.41368);
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
   
   TH1D *frame_306b83d0__2 = new TH1D("frame_306b83d0__2","p_T Balance",25,0,2);
   frame_306b83d0__2->SetBinContent(1,17.23891);
   frame_306b83d0__2->SetMinimum(-0.8209007);
   frame_306b83d0__2->SetMaximum(17.23891);
   frame_306b83d0__2->SetEntries(1);
   frame_306b83d0__2->SetDirectory(0);
   frame_306b83d0__2->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_306b83d0__2->SetLineColor(ci);
   frame_306b83d0__2->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_306b83d0__2->GetXaxis()->SetLabelFont(42);
   frame_306b83d0__2->GetXaxis()->SetTitleOffset(1);
   frame_306b83d0__2->GetXaxis()->SetTitleFont(42);
   frame_306b83d0__2->GetYaxis()->SetTitle("1/Events");
   frame_306b83d0__2->GetYaxis()->SetLabelFont(42);
   frame_306b83d0__2->GetYaxis()->SetTitleFont(42);
   frame_306b83d0__2->GetZaxis()->SetLabelFont(42);
   frame_306b83d0__2->GetZaxis()->SetTitleOffset(1);
   frame_306b83d0__2->GetZaxis()->SetTitleFont(42);
   frame_306b83d0__2->Draw("AXISSAME");
   
   TH1D *norm_c__3 = new TH1D("norm_c__3","",25,0,2);
   norm_c__3->SetBinContent(2,0.2650859);
   norm_c__3->SetBinContent(3,0.05424485);
   norm_c__3->SetBinContent(4,0.06874596);
   norm_c__3->SetBinContent(5,0.2510789);
   norm_c__3->SetBinContent(6,0.1586845);
   norm_c__3->SetBinContent(7,1.436286);
   norm_c__3->SetBinContent(8,1.788286);
   norm_c__3->SetBinContent(9,4.400204);
   norm_c__3->SetBinContent(10,7.568869);
   norm_c__3->SetBinContent(11,10.90341);
   norm_c__3->SetBinContent(12,14.86503);
   norm_c__3->SetBinContent(13,11.12656);
   norm_c__3->SetBinContent(14,7.124347);
   norm_c__3->SetBinContent(15,2.356896);
   norm_c__3->SetBinContent(16,0.4741437);
   norm_c__3->SetBinContent(17,0.3480052);
   norm_c__3->SetBinContent(18,0.1315298);
   norm_c__3->SetBinContent(19,0.03445249);
   norm_c__3->SetBinContent(20,0.007282548);
   norm_c__3->SetBinContent(22,0.005909765);
   norm_c__3->SetBinContent(24,0.01420382);
   norm_c__3->SetBinContent(26,0.002007776);
   norm_c__3->SetBinError(2,0.1895588);
   norm_c__3->SetBinError(3,0.05424485);
   norm_c__3->SetBinError(4,0.04740479);
   norm_c__3->SetBinError(5,0.2044528);
   norm_c__3->SetBinError(6,0.08644941);
   norm_c__3->SetBinError(7,0.4883713);
   norm_c__3->SetBinError(8,0.553094);
   norm_c__3->SetBinError(9,0.853857);
   norm_c__3->SetBinError(10,1.166644);
   norm_c__3->SetBinError(11,1.316642);
   norm_c__3->SetBinError(12,1.552988);
   norm_c__3->SetBinError(13,1.342045);
   norm_c__3->SetBinError(14,1.065432);
   norm_c__3->SetBinError(15,0.614331);
   norm_c__3->SetBinError(16,0.2600161);
   norm_c__3->SetBinError(17,0.1962608);
   norm_c__3->SetBinError(18,0.0729932);
   norm_c__3->SetBinError(19,0.01959084);
   norm_c__3->SetBinError(20,0.007282548);
   norm_c__3->SetBinError(22,0.005909765);
   norm_c__3->SetBinError(24,0.01005488);
   norm_c__3->SetBinError(26,0.002007776);
   norm_c__3->SetEntries(659);
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
   entry=leg->AddEntry("frame_x_c2_306b83d0","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.903141 #pm 0.019184","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.143301 #pm 0.015887","");
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
   
   TH1D *frame_306b83d0_copy__4 = new TH1D("frame_306b83d0_copy__4","p_T Balance",25,0,2);
   frame_306b83d0_copy__4->SetBinContent(1,17.23891);
   frame_306b83d0_copy__4->SetMinimum(-0.8209007);
   frame_306b83d0_copy__4->SetMaximum(17.23891);
   frame_306b83d0_copy__4->SetEntries(1);
   frame_306b83d0_copy__4->SetDirectory(0);
   frame_306b83d0_copy__4->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_306b83d0_copy__4->SetLineColor(ci);
   frame_306b83d0_copy__4->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_306b83d0_copy__4->GetXaxis()->SetLabelFont(42);
   frame_306b83d0_copy__4->GetXaxis()->SetTitleOffset(1);
   frame_306b83d0_copy__4->GetXaxis()->SetTitleFont(42);
   frame_306b83d0_copy__4->GetYaxis()->SetTitle("1/Events");
   frame_306b83d0_copy__4->GetYaxis()->SetLabelFont(42);
   frame_306b83d0_copy__4->GetYaxis()->SetTitleFont(42);
   frame_306b83d0_copy__4->GetZaxis()->SetLabelFont(42);
   frame_306b83d0_copy__4->GetZaxis()->SetTitleOffset(1);
   frame_306b83d0_copy__4->GetZaxis()->SetTitleFont(42);
   frame_306b83d0_copy__4->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-2.701767,2.25,20.33655);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3068dc60__5 = new TH1D("frame_3068dc60__5","p_T Balance",25,0,2);
   frame_3068dc60__5->SetBinContent(1,18.03272);
   frame_3068dc60__5->SetMinimum(-0.858701);
   frame_3068dc60__5->SetMaximum(18.03272);
   frame_3068dc60__5->SetEntries(1);
   frame_3068dc60__5->SetDirectory(0);
   frame_3068dc60__5->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3068dc60__5->SetLineColor(ci);
   frame_3068dc60__5->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3068dc60__5->GetXaxis()->SetLabelFont(42);
   frame_3068dc60__5->GetXaxis()->SetTitleOffset(1);
   frame_3068dc60__5->GetXaxis()->SetTitleFont(42);
   frame_3068dc60__5->GetYaxis()->SetTitle("1/Events");
   frame_3068dc60__5->GetYaxis()->SetLabelFont(42);
   frame_3068dc60__5->GetYaxis()->SetTitleFont(42);
   frame_3068dc60__5->GetZaxis()->SetLabelFont(42);
   frame_3068dc60__5->GetZaxis()->SetTitleOffset(1);
   frame_3068dc60__5->GetZaxis()->SetTitleFont(42);
   frame_3068dc60__5->Draw("FUNC");
   
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
   0,
   0.08706787,
   0,
   0.2664814,
   0.2515105,
   0.1129283,
   1.284213,
   1.048265,
   3.594114,
   7.026258,
   10.97987,
   15.56229,
   11.9577,
   6.739254,
   3.032425,
   0.8461772,
   0.5974368,
   0.08978096,
   0.1683818,
   0.007265698,
   0,
   0.005908025,
   0,
   0.006757129,
   0};
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
   0,
   0.06462234,
   0,
   0.2035808,
   0.2048593,
   0.07331984,
   0.4540523,
   0.3850067,
   0.7649561,
   1.128348,
   1.316205,
   1.611729,
   1.433084,
   1.007471,
   0.7025258,
   0.3693462,
   0.2806676,
   0.04149868,
   0.09702548,
   0.007265698,
   0,
   0.005908025,
   0,
   0.006757129,
   0};
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
   0,
   0.06462234,
   0,
   0.2035808,
   0.2048593,
   0.07331984,
   0.4540523,
   0.3850067,
   0.7649561,
   1.128348,
   1.316205,
   1.611729,
   1.433084,
   1.007471,
   0.7025258,
   0.3693462,
   0.2806676,
   0.04149868,
   0.09702548,
   0.007265698,
   0,
   0.005908025,
   0,
   0.006757129,
   0};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3002,h_dh_up2_fy3002,h_dh_up2_felx3002,h_dh_up2_fehx3002,h_dh_up2_fely3002,h_dh_up2_fehy3002);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23002 = new TH1F("Graph_h_dh_up23002","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23002->SetMinimum(-1.717402);
   Graph_h_dh_up23002->SetMaximum(18.89142);
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
   
   Double_t up_fx2[60] = {
   0.5799738,
   0.6070172,
   0.6205389,
   0.6340606,
   0.6475823,
   0.661104,
   0.6746257,
   0.6881475,
   0.7016692,
   0.7151909,
   0.7219517,
   0.7287126,
   0.7354735,
   0.7422343,
   0.755756,
   0.7692777,
   0.7963212,
   0.8098429,
   0.8233646,
   0.8368863,
   0.850408,
   0.8639297,
   0.8706906,
   0.8774515,
   0.8842123,
   0.8909732,
   0.897734,
   0.9044949,
   0.9112557,
   0.9180166,
   0.9247775,
   0.9315383,
   0.9382992,
   0.94506,
   0.9518209,
   0.9585817,
   0.9653426,
   0.9721035,
   0.9788643,
   0.9856252,
   0.9991469,
   1.012669,
   1.02619,
   1.039712,
   1.066755,
   1.080277,
   1.093799,
   1.107321,
   1.120842,
   1.134364,
   1.147886,
   1.161407,
   1.174929,
   1.188451,
   1.201973,
   1.208733,
   1.215494,
   1.229016,
   1.256059,
   1.256059};
   Double_t up_fy2[60] = {
   1.408871,
   1.727763,
   1.92108,
   2.142206,
   2.396084,
   2.688712,
   3.027407,
   3.421153,
   3.881045,
   4.420877,
   4.726006,
   5.05792,
   5.41949,
   5.812021,
   6.640836,
   7.508726,
   9.302448,
   10.19259,
   11.05147,
   11.85778,
   12.59026,
   13.2286,
   13.50662,
   13.75438,
   13.97004,
   14.15195,
   14.29871,
   14.40919,
   14.48252,
   14.51813,
   14.51574,
   14.47537,
   14.39734,
   14.28225,
   14.13101,
   13.94478,
   13.72499,
   13.47332,
   13.19165,
   12.88207,
   12.18834,
   11.41172,
   10.57319,
   9.69413,
   7.896929,
   7.016247,
   6.168782,
   5.367129,
   4.620963,
   3.937051,
   3.319384,
   2.769439,
   2.286516,
   1.868119,
   1.512411,
   1.438106,
   1.40319,
   1.36344,
   1.321278,
   1.321278};
   graph = new TGraph(60,up_fx2,up_fy2);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up2 = new TH1F("Graph_up2","Projection of upf DSCB fit",100,0.5123652,1.323668);
   Graph_up2->SetMinimum(0.001592489);
   Graph_up2->SetMaximum(15.83781);
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
   
   TH1D *frame_3068dc60__6 = new TH1D("frame_3068dc60__6","p_T Balance",25,0,2);
   frame_3068dc60__6->SetBinContent(1,18.03272);
   frame_3068dc60__6->SetMinimum(-0.858701);
   frame_3068dc60__6->SetMaximum(18.03272);
   frame_3068dc60__6->SetEntries(1);
   frame_3068dc60__6->SetDirectory(0);
   frame_3068dc60__6->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3068dc60__6->SetLineColor(ci);
   frame_3068dc60__6->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3068dc60__6->GetXaxis()->SetLabelFont(42);
   frame_3068dc60__6->GetXaxis()->SetTitleOffset(1);
   frame_3068dc60__6->GetXaxis()->SetTitleFont(42);
   frame_3068dc60__6->GetYaxis()->SetTitle("1/Events");
   frame_3068dc60__6->GetYaxis()->SetLabelFont(42);
   frame_3068dc60__6->GetYaxis()->SetTitleFont(42);
   frame_3068dc60__6->GetZaxis()->SetLabelFont(42);
   frame_3068dc60__6->GetZaxis()->SetTitleOffset(1);
   frame_3068dc60__6->GetZaxis()->SetTitleFont(42);
   frame_3068dc60__6->Draw("AXISSAME");
   
   TH1D *norm_u__7 = new TH1D("norm_u__7","",25,0,2);
   norm_u__7->SetBinContent(2,0.08706787);
   norm_u__7->SetBinContent(4,0.2664814);
   norm_u__7->SetBinContent(5,0.2515105);
   norm_u__7->SetBinContent(6,0.1129283);
   norm_u__7->SetBinContent(7,1.284213);
   norm_u__7->SetBinContent(8,1.048265);
   norm_u__7->SetBinContent(9,3.594113);
   norm_u__7->SetBinContent(10,7.026258);
   norm_u__7->SetBinContent(11,10.97987);
   norm_u__7->SetBinContent(12,15.56229);
   norm_u__7->SetBinContent(13,11.9577);
   norm_u__7->SetBinContent(14,6.739255);
   norm_u__7->SetBinContent(15,3.032425);
   norm_u__7->SetBinContent(16,0.8461772);
   norm_u__7->SetBinContent(17,0.5974368);
   norm_u__7->SetBinContent(18,0.08978096);
   norm_u__7->SetBinContent(19,0.1683818);
   norm_u__7->SetBinContent(20,0.007265698);
   norm_u__7->SetBinContent(22,0.005908025);
   norm_u__7->SetBinContent(24,0.006757129);
   norm_u__7->SetBinContent(26,0.006617274);
   norm_u__7->SetBinError(2,0.06462234);
   norm_u__7->SetBinError(4,0.2035808);
   norm_u__7->SetBinError(5,0.2048593);
   norm_u__7->SetBinError(6,0.07331984);
   norm_u__7->SetBinError(7,0.4540523);
   norm_u__7->SetBinError(8,0.3850067);
   norm_u__7->SetBinError(9,0.7649561);
   norm_u__7->SetBinError(10,1.128348);
   norm_u__7->SetBinError(11,1.316205);
   norm_u__7->SetBinError(12,1.611729);
   norm_u__7->SetBinError(13,1.433084);
   norm_u__7->SetBinError(14,1.007471);
   norm_u__7->SetBinError(15,0.7025258);
   norm_u__7->SetBinError(16,0.3693462);
   norm_u__7->SetBinError(17,0.2806676);
   norm_u__7->SetBinError(18,0.04149868);
   norm_u__7->SetBinError(19,0.09702548);
   norm_u__7->SetBinError(20,0.007265698);
   norm_u__7->SetBinError(22,0.005908025);
   norm_u__7->SetBinError(24,0.006757129);
   norm_u__7->SetBinError(26,0.006617274);
   norm_u__7->SetEntries(662);
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
   entry=leg->AddEntry("frame_x_u2_3068dc60","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.917172 #pm 0.019138","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.140903 #pm 0.016626","");
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
   
   TH1D *frame_3068dc60_copy__8 = new TH1D("frame_3068dc60_copy__8","p_T Balance",25,0,2);
   frame_3068dc60_copy__8->SetBinContent(1,18.03272);
   frame_3068dc60_copy__8->SetMinimum(-0.858701);
   frame_3068dc60_copy__8->SetMaximum(18.03272);
   frame_3068dc60_copy__8->SetEntries(1);
   frame_3068dc60_copy__8->SetDirectory(0);
   frame_3068dc60_copy__8->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3068dc60_copy__8->SetLineColor(ci);
   frame_3068dc60_copy__8->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3068dc60_copy__8->GetXaxis()->SetLabelFont(42);
   frame_3068dc60_copy__8->GetXaxis()->SetTitleOffset(1);
   frame_3068dc60_copy__8->GetXaxis()->SetTitleFont(42);
   frame_3068dc60_copy__8->GetYaxis()->SetTitle("1/Events");
   frame_3068dc60_copy__8->GetYaxis()->SetLabelFont(42);
   frame_3068dc60_copy__8->GetYaxis()->SetTitleFont(42);
   frame_3068dc60_copy__8->GetZaxis()->SetLabelFont(42);
   frame_3068dc60_copy__8->GetZaxis()->SetTitleOffset(1);
   frame_3068dc60_copy__8->GetZaxis()->SetTitleFont(42);
   frame_3068dc60_copy__8->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-2.3758,2.25,14.5942);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_306b3820__9 = new TH1D("frame_306b3820__9","p_T Balance",25,0,2);
   frame_306b3820__9->SetBinContent(1,14.2548);
   frame_306b3820__9->SetMinimum(-0.6788001);
   frame_306b3820__9->SetMaximum(14.2548);
   frame_306b3820__9->SetEntries(1);
   frame_306b3820__9->SetDirectory(0);
   frame_306b3820__9->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_306b3820__9->SetLineColor(ci);
   frame_306b3820__9->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_306b3820__9->GetXaxis()->SetLabelFont(42);
   frame_306b3820__9->GetXaxis()->SetTitleOffset(1);
   frame_306b3820__9->GetXaxis()->SetTitleFont(42);
   frame_306b3820__9->GetYaxis()->SetTitle("1/Events");
   frame_306b3820__9->GetYaxis()->SetLabelFont(42);
   frame_306b3820__9->GetYaxis()->SetTitleFont(42);
   frame_306b3820__9->GetZaxis()->SetLabelFont(42);
   frame_306b3820__9->GetZaxis()->SetTitleOffset(1);
   frame_306b3820__9->GetZaxis()->SetTitleFont(42);
   frame_306b3820__9->Draw("FUNC");
   
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
   0,
   0.1415716,
   0.0541905,
   0.06329668,
   0.2076381,
   0.1597049,
   1.308365,
   2.742878,
   4.595201,
   6.797191,
   10.88614,
   12.20278,
   10.09952,
   6.834551,
   1.519938,
   0.423936,
   0.266765,
   0.129193,
   0.02035778,
   0.007328762,
   0,
   0.005947959,
   0,
   0.01432347,
   0};
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
   0,
   0.08454841,
   0.0541905,
   0.04741159,
   0.1622938,
   0.08701219,
   0.454917,
   0.6866453,
   0.8690441,
   1.080115,
   1.318826,
   1.373222,
   1.258281,
   1.054605,
   0.4517268,
   0.2564901,
   0.1818733,
   0.07272486,
   0.01355373,
   0.007328762,
   0,
   0.005947959,
   0,
   0.01014077,
   0};
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
   0,
   0.08454841,
   0.0541905,
   0.04741159,
   0.1622938,
   0.08701219,
   0.454917,
   0.6866453,
   0.8690441,
   1.080115,
   1.318826,
   1.373222,
   1.258281,
   1.054605,
   0.4517268,
   0.2564901,
   0.1818733,
   0.07272486,
   0.01355373,
   0.007328762,
   0,
   0.005947959,
   0,
   0.01014077,
   0};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3003,h_dh_down2_fy3003,h_dh_down2_felx3003,h_dh_down2_fehx3003,h_dh_down2_fely3003,h_dh_down2_fehy3003);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23003 = new TH1F("Graph_h_dh_down23003","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23003->SetMinimum(-1.3576);
   Graph_h_dh_down23003->SetMaximum(14.9336);
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
   
   Double_t down_fx3[54] = {
   0.6075992,
   0.6200245,
   0.6324498,
   0.6448751,
   0.6573004,
   0.6697258,
   0.6821511,
   0.6945764,
   0.7070017,
   0.719427,
   0.7318523,
   0.756703,
   0.7815536,
   0.7939789,
   0.8064042,
   0.8188295,
   0.8312549,
   0.8436802,
   0.8561055,
   0.8685308,
   0.8747435,
   0.8809561,
   0.8871688,
   0.8933814,
   0.8995941,
   0.9058067,
   0.9120194,
   0.9182321,
   0.9244447,
   0.9306574,
   0.93687,
   0.9430827,
   0.955508,
   0.9679333,
   0.9803586,
   0.992784,
   1.005209,
   1.03006,
   1.054911,
   1.067336,
   1.079761,
   1.092186,
   1.104612,
   1.117037,
   1.129462,
   1.141888,
   1.154313,
   1.166738,
   1.179164,
   1.191589,
   1.204014,
   1.21644,
   1.228865,
   1.228865};
   Double_t down_fy3[54] = {
   1.122883,
   1.372968,
   1.664313,
   2.000129,
   2.38303,
   2.814813,
   3.296235,
   3.826797,
   4.404545,
   5.025917,
   5.685623,
   7.090048,
   8.541111,
   9.253793,
   9.93971,
   10.58464,
   11.17448,
   11.69571,
   12.13598,
   12.48451,
   12.62156,
   12.73258,
   12.81688,
   12.8739,
   12.90328,
   12.90483,
   12.87854,
   12.82458,
   12.74329,
   12.63521,
   12.50101,
   12.34156,
   11.95106,
   11.47338,
   10.92005,
   10.30402,
   9.63911,
   8.219462,
   6.770862,
   6.066205,
   5.388138,
   4.744701,
   4.142166,
   3.585046,
   3.076171,
   2.616825,
   2.206925,
   1.845223,
   1.529533,
   1.256948,
   1.024057,
   0.827141,
   0.6623439,
   0.6623439};
   graph = new TGraph(54,down_fx3,down_fy3);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down3 = new TH1F("Graph_down3","Projection of downf DSCB fit",100,0.5454726,1.290992);
   Graph_down3->SetMinimum(0.5961095);
   Graph_down3->SetMaximum(14.12908);
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
   
   TH1D *frame_306b3820__10 = new TH1D("frame_306b3820__10","p_T Balance",25,0,2);
   frame_306b3820__10->SetBinContent(1,14.2548);
   frame_306b3820__10->SetMinimum(-0.6788001);
   frame_306b3820__10->SetMaximum(14.2548);
   frame_306b3820__10->SetEntries(1);
   frame_306b3820__10->SetDirectory(0);
   frame_306b3820__10->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_306b3820__10->SetLineColor(ci);
   frame_306b3820__10->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_306b3820__10->GetXaxis()->SetLabelFont(42);
   frame_306b3820__10->GetXaxis()->SetTitleOffset(1);
   frame_306b3820__10->GetXaxis()->SetTitleFont(42);
   frame_306b3820__10->GetYaxis()->SetTitle("1/Events");
   frame_306b3820__10->GetYaxis()->SetLabelFont(42);
   frame_306b3820__10->GetYaxis()->SetTitleFont(42);
   frame_306b3820__10->GetZaxis()->SetLabelFont(42);
   frame_306b3820__10->GetZaxis()->SetTitleOffset(1);
   frame_306b3820__10->GetZaxis()->SetTitleFont(42);
   frame_306b3820__10->Draw("AXISSAME");
   
   TH1D *norm_d__11 = new TH1D("norm_d__11","",25,0,2);
   norm_d__11->SetBinContent(2,0.1415716);
   norm_d__11->SetBinContent(3,0.0541905);
   norm_d__11->SetBinContent(4,0.06329668);
   norm_d__11->SetBinContent(5,0.2076381);
   norm_d__11->SetBinContent(6,0.1597049);
   norm_d__11->SetBinContent(7,1.308365);
   norm_d__11->SetBinContent(8,2.742878);
   norm_d__11->SetBinContent(9,4.595201);
   norm_d__11->SetBinContent(10,6.797191);
   norm_d__11->SetBinContent(11,10.88614);
   norm_d__11->SetBinContent(12,12.20278);
   norm_d__11->SetBinContent(13,10.09952);
   norm_d__11->SetBinContent(14,6.834551);
   norm_d__11->SetBinContent(15,1.519938);
   norm_d__11->SetBinContent(16,0.423936);
   norm_d__11->SetBinContent(17,0.266765);
   norm_d__11->SetBinContent(18,0.129193);
   norm_d__11->SetBinContent(19,0.02035778);
   norm_d__11->SetBinContent(20,0.007328762);
   norm_d__11->SetBinContent(22,0.005947959);
   norm_d__11->SetBinContent(24,0.01432347);
   norm_d__11->SetBinContent(26,0.001945317);
   norm_d__11->SetBinError(2,0.08454841);
   norm_d__11->SetBinError(3,0.0541905);
   norm_d__11->SetBinError(4,0.04741159);
   norm_d__11->SetBinError(5,0.1622938);
   norm_d__11->SetBinError(6,0.08701219);
   norm_d__11->SetBinError(7,0.454917);
   norm_d__11->SetBinError(8,0.6866453);
   norm_d__11->SetBinError(9,0.8690441);
   norm_d__11->SetBinError(10,1.080115);
   norm_d__11->SetBinError(11,1.318826);
   norm_d__11->SetBinError(12,1.373222);
   norm_d__11->SetBinError(13,1.258281);
   norm_d__11->SetBinError(14,1.054605);
   norm_d__11->SetBinError(15,0.4517268);
   norm_d__11->SetBinError(16,0.2564901);
   norm_d__11->SetBinError(17,0.1818733);
   norm_d__11->SetBinError(18,0.07272486);
   norm_d__11->SetBinError(19,0.01355373);
   norm_d__11->SetBinError(20,0.007328762);
   norm_d__11->SetBinError(22,0.005947959);
   norm_d__11->SetBinError(24,0.01014077);
   norm_d__11->SetBinError(26,0.001945317);
   norm_d__11->SetEntries(644);
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
   entry=leg->AddEntry("frame_x_d2_306b3820","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.903037 #pm 0.019686","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.133689 #pm 0.017840","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.439000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_306b3820_copy__12 = new TH1D("frame_306b3820_copy__12","p_T Balance",25,0,2);
   frame_306b3820_copy__12->SetBinContent(1,14.2548);
   frame_306b3820_copy__12->SetMinimum(-0.6788001);
   frame_306b3820_copy__12->SetMaximum(14.2548);
   frame_306b3820_copy__12->SetEntries(1);
   frame_306b3820_copy__12->SetDirectory(0);
   frame_306b3820_copy__12->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_306b3820_copy__12->SetLineColor(ci);
   frame_306b3820_copy__12->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_306b3820_copy__12->GetXaxis()->SetLabelFont(42);
   frame_306b3820_copy__12->GetXaxis()->SetTitleOffset(1);
   frame_306b3820_copy__12->GetXaxis()->SetTitleFont(42);
   frame_306b3820_copy__12->GetYaxis()->SetTitle("1/Events");
   frame_306b3820_copy__12->GetYaxis()->SetLabelFont(42);
   frame_306b3820_copy__12->GetYaxis()->SetTitleFont(42);
   frame_306b3820_copy__12->GetZaxis()->SetLabelFont(42);
   frame_306b3820_copy__12->GetZaxis()->SetTitleOffset(1);
   frame_306b3820_copy__12->GetZaxis()->SetTitleFont(42);
   frame_306b3820_copy__12->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-3.444147,2.25,30.99733);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_30681210__13 = new TH1D("frame_30681210__13","p_T Balance",25,0,2);
   frame_30681210__13->SetBinContent(1,30.3085);
   frame_30681210__13->SetMaximum(30.3085);
   frame_30681210__13->SetEntries(1);
   frame_30681210__13->SetDirectory(0);
   frame_30681210__13->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30681210__13->SetLineColor(ci);
   frame_30681210__13->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30681210__13->GetXaxis()->SetLabelFont(42);
   frame_30681210__13->GetXaxis()->SetTitleOffset(1);
   frame_30681210__13->GetXaxis()->SetTitleFont(42);
   frame_30681210__13->GetYaxis()->SetTitle("1/Events");
   frame_30681210__13->GetYaxis()->SetLabelFont(42);
   frame_30681210__13->GetYaxis()->SetTitleFont(42);
   frame_30681210__13->GetZaxis()->SetLabelFont(42);
   frame_30681210__13->GetZaxis()->SetTitleOffset(1);
   frame_30681210__13->GetZaxis()->SetTitleFont(42);
   frame_30681210__13->Draw("FUNC");
   
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
   2,
   0,
   0,
   0,
   1,
   0,
   2,
   1,
   7,
   13,
   23,
   15,
   9,
   6,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   1.291815,
   0,
   0,
   0,
   0.8272462,
   0,
   1.291815,
   0.8272462,
   2.58147,
   3.558662,
   4.760717,
   3.82938,
   2.943461,
   2.379931,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   2.63786,
   1.147874,
   1.147874,
   1.147874,
   2.299527,
   1.147874,
   2.63786,
   2.299527,
   3.770281,
   4.697573,
   5.865235,
   4.958738,
   4.110204,
   3.583642,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
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
   Graph_h_dh_data23004->SetMaximum(31.75176);
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
   
   Double_t observation_fx4[58] = {
   0.6213445,
   0.6338397,
   0.6463349,
   0.6588301,
   0.6713253,
   0.6838205,
   0.6963157,
   0.7088109,
   0.7213061,
   0.7338013,
   0.7462965,
   0.7587917,
   0.7712869,
   0.7837821,
   0.7962773,
   0.8212677,
   0.8462581,
   0.8587533,
   0.8712485,
   0.8837437,
   0.8899913,
   0.8962389,
   0.9024865,
   0.9087341,
   0.9149817,
   0.9212293,
   0.9274769,
   0.9337245,
   0.9399721,
   0.9462197,
   0.9524673,
   0.9587149,
   0.9649625,
   0.9712101,
   0.9774577,
   0.9837053,
   0.9899529,
   0.9962005,
   1.008696,
   1.021191,
   1.033686,
   1.046181,
   1.071172,
   1.083667,
   1.096162,
   1.108657,
   1.121152,
   1.133648,
   1.146143,
   1.158638,
   1.171133,
   1.183628,
   1.196124,
   1.208619,
   1.221114,
   1.233609,
   1.246104,
   1.246104};
   Double_t observation_fy4[58] = {
   0.468033,
   0.6235923,
   0.8214714,
   1.069921,
   1.377775,
   1.754174,
   2.20818,
   2.748297,
   3.381898,
   4.114574,
   4.949447,
   5.886484,
   6.92186,
   8.047429,
   9.250369,
   11.81314,
   14.4159,
   15.65601,
   16.81078,
   17.84689,
   18.31049,
   18.73287,
   19.11066,
   19.44079,
   19.72055,
   19.94761,
   20.12008,
   20.2365,
   20.29588,
   20.29772,
   20.24201,
   20.12922,
   19.96029,
   19.73667,
   19.46022,
   19.13324,
   18.75841,
   18.33878,
   17.37881,
   16.2831,
   15.08418,
   13.81573,
   11.20161,
   9.915971,
   8.678754,
   7.510123,
   6.42546,
   5.435368,
   4.545913,
   3.759074,
   3.073322,
   2.484293,
   1.985478,
   1.568898,
   1.225722,
   0.946797,
   0.7230847,
   0.7230847};
   graph = new TGraph(58,observation_fx4,observation_fy4);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation4 = new TH1F("Graph_observation4","Projection of obsf DSCB fit",100,0.5588685,1.30858);
   Graph_observation4->SetMinimum(0.4212297);
   Graph_observation4->SetMaximum(22.28069);
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
   
   TH1D *frame_30681210__14 = new TH1D("frame_30681210__14","p_T Balance",25,0,2);
   frame_30681210__14->SetBinContent(1,30.3085);
   frame_30681210__14->SetMaximum(30.3085);
   frame_30681210__14->SetEntries(1);
   frame_30681210__14->SetDirectory(0);
   frame_30681210__14->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30681210__14->SetLineColor(ci);
   frame_30681210__14->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30681210__14->GetXaxis()->SetLabelFont(42);
   frame_30681210__14->GetXaxis()->SetTitleOffset(1);
   frame_30681210__14->GetXaxis()->SetTitleFont(42);
   frame_30681210__14->GetYaxis()->SetTitle("1/Events");
   frame_30681210__14->GetYaxis()->SetLabelFont(42);
   frame_30681210__14->GetYaxis()->SetTitleFont(42);
   frame_30681210__14->GetZaxis()->SetLabelFont(42);
   frame_30681210__14->GetZaxis()->SetTitleOffset(1);
   frame_30681210__14->GetZaxis()->SetTitleFont(42);
   frame_30681210__14->Draw("AXISSAME");
   
   TH1D *norm_o__15 = new TH1D("norm_o__15","",25,0,2);
   norm_o__15->SetBinContent(2,2);
   norm_o__15->SetBinContent(6,1);
   norm_o__15->SetBinContent(8,2);
   norm_o__15->SetBinContent(9,1);
   norm_o__15->SetBinContent(10,7);
   norm_o__15->SetBinContent(11,13);
   norm_o__15->SetBinContent(12,23);
   norm_o__15->SetBinContent(13,15);
   norm_o__15->SetBinContent(14,9);
   norm_o__15->SetBinContent(15,6);
   norm_o__15->SetMinimum(0);
   norm_o__15->SetMaximum(50.6);
   norm_o__15->SetEntries(79);
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
   entry=leg->AddEntry("frame_x_o2_30681210","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.943295 #pm 0.014075","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.117257 #pm 0.011236","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.951000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_30681210_copy__16 = new TH1D("frame_30681210_copy__16","p_T Balance",25,0,2);
   frame_30681210_copy__16->SetBinContent(1,30.3085);
   frame_30681210_copy__16->SetMaximum(30.3085);
   frame_30681210_copy__16->SetEntries(1);
   frame_30681210_copy__16->SetDirectory(0);
   frame_30681210_copy__16->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_30681210_copy__16->SetLineColor(ci);
   frame_30681210_copy__16->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_30681210_copy__16->GetXaxis()->SetLabelFont(42);
   frame_30681210_copy__16->GetXaxis()->SetTitleOffset(1);
   frame_30681210_copy__16->GetXaxis()->SetTitleFont(42);
   frame_30681210_copy__16->GetYaxis()->SetTitle("1/Events");
   frame_30681210_copy__16->GetYaxis()->SetLabelFont(42);
   frame_30681210_copy__16->GetYaxis()->SetTitleFont(42);
   frame_30681210_copy__16->GetZaxis()->SetLabelFont(42);
   frame_30681210_copy__16->GetZaxis()->SetTitleOffset(1);
   frame_30681210_copy__16->GetZaxis()->SetTitleFont(42);
   frame_30681210_copy__16->Draw("sameaxis");
   
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
