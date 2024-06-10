void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_2__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 18:44:20 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-17.03899,2.25,128.2547);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_367d4eb0__17 = new TH1D("frame_367d4eb0__17","p_T Balance",25,0,2);
   frame_367d4eb0__17->SetBinContent(1,113.7254);
   frame_367d4eb0__17->SetMinimum(-5.415493);
   frame_367d4eb0__17->SetMaximum(113.7254);
   frame_367d4eb0__17->SetEntries(1);
   frame_367d4eb0__17->SetDirectory(0);
   frame_367d4eb0__17->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_367d4eb0__17->SetLineColor(ci);
   frame_367d4eb0__17->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367d4eb0__17->GetXaxis()->SetLabelFont(42);
   frame_367d4eb0__17->GetXaxis()->SetTitleOffset(1);
   frame_367d4eb0__17->GetXaxis()->SetTitleFont(42);
   frame_367d4eb0__17->GetYaxis()->SetTitle("1/Events");
   frame_367d4eb0__17->GetYaxis()->SetLabelFont(42);
   frame_367d4eb0__17->GetYaxis()->SetTitleFont(42);
   frame_367d4eb0__17->GetZaxis()->SetLabelFont(42);
   frame_367d4eb0__17->GetZaxis()->SetTitleOffset(1);
   frame_367d4eb0__17->GetZaxis()->SetTitleFont(42);
   frame_367d4eb0__17->Draw("FUNC");
   
   Double_t h_dh_central2_fx3005[25] = {
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
   Double_t h_dh_central2_fy3005[25] = {
   0,
   0.924029,
   3.783663,
   3.208176,
   7.504762,
   7.020941,
   17.68541,
   27.16296,
   50.00075,
   78.97643,
   102.9165,
   96.50546,
   88.30505,
   52.40722,
   30.8063,
   13.29477,
   7.367297,
   1.467659,
   0.6152467,
   0.5466706,
   0.6945238,
   0.1605668,
   0.1406238,
   0.03166948,
   0.03311113};
   Double_t h_dh_central2_felx3005[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_central2_fely3005[25] = {
   0,
   0.4756518,
   0.9994016,
   0.8600602,
   1.395455,
   1.351024,
   2.230604,
   2.722868,
   3.900936,
   4.793726,
   5.393394,
   5.128958,
   4.874831,
   3.571139,
   2.736858,
   1.679153,
   1.219985,
   0.4582876,
   0.261603,
   0.1853322,
   0.2972081,
   0.09048253,
   0.08429342,
   0.03166948,
   0.0258221};
   Double_t h_dh_central2_fehx3005[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_central2_fehy3005[25] = {
   0,
   0.4756518,
   0.9994016,
   0.8600602,
   1.395455,
   1.351024,
   2.230604,
   2.722868,
   3.900936,
   4.793726,
   5.393394,
   5.128958,
   4.874831,
   3.571139,
   2.736858,
   1.679153,
   1.219985,
   0.4582876,
   0.261603,
   0.1853322,
   0.2972081,
   0.09048253,
   0.08429342,
   0.03166948,
   0.0258221};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3005,h_dh_central2_fy3005,h_dh_central2_felx3005,h_dh_central2_fehx3005,h_dh_central2_fely3005,h_dh_central2_fehy3005);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23005 = new TH1F("Graph_h_dh_central23005","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23005->SetMinimum(-10.83099);
   Graph_h_dh_central23005->SetMaximum(119.1408);
   Graph_h_dh_central23005->SetDirectory(0);
   Graph_h_dh_central23005->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_central23005->SetLineColor(ci);
   Graph_h_dh_central23005->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_central23005->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_central23005->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_central23005->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_central23005->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_central23005->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_central23005->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_central23005->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_central23005);
   
   grae->Draw("p");
   
   Double_t Central_fx5[57] = {
   0.4556179,
   0.4730761,
   0.4905343,
   0.5079925,
   0.5254507,
   0.5429089,
   0.5603671,
   0.5778253,
   0.5952835,
   0.6127417,
   0.6301999,
   0.6476581,
   0.6651163,
   0.7000327,
   0.7349491,
   0.7524073,
   0.7698655,
   0.7873237,
   0.8047819,
   0.8222401,
   0.8309692,
   0.8396983,
   0.8484274,
   0.8571565,
   0.8658856,
   0.8746147,
   0.8833438,
   0.8920729,
   0.900802,
   0.9095311,
   0.9182602,
   0.9269893,
   0.9357184,
   0.9444475,
   0.9619057,
   0.9793638,
   0.996822,
   1.01428,
   1.031738,
   1.049197,
   1.084113,
   1.101571,
   1.119029,
   1.136488,
   1.153946,
   1.171404,
   1.188862,
   1.20632,
   1.223779,
   1.241237,
   1.258695,
   1.26306,
   1.267424,
   1.276153,
   1.293611,
   1.328528,
   1.328528};
   Double_t Central_fy5[57] = {
   5.8471,
   7.343173,
   9.135146,
   11.25734,
   13.74183,
   16.6166,
   19.90344,
   23.6158,
   27.75657,
   32.31599,
   37.26985,
   42.57811,
   48.18409,
   59.97965,
   71.88834,
   77.59228,
   82.95969,
   87.86265,
   92.17859,
   95.79533,
   97.31049,
   98.61595,
   99.70267,
   100.5631,
   101.1911,
   101.5824,
   101.7341,
   101.6452,
   101.3163,
   100.7498,
   99.94954,
   98.92126,
   97.67213,
   96.2108,
   92.69291,
   88.46221,
   83.62914,
   78.31519,
   72.64787,
   66.7557,
   54.78794,
   48.93461,
   43.29481,
   37.94408,
   32.94131,
   28.32867,
   24.13238,
   20.36398,
   17.02212,
   14.09461,
   11.56062,
   11.00669,
   10.69209,
   10.35982,
   10.02314,
   9.689737,
   9.689737};
   TGraph *graph = new TGraph(57,Central_fx5,Central_fy5);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central5 = new TH1F("Graph_Central5","Projection of centralf DSCB fit",100,0.368327,1.415819);
   Graph_Central5->SetMinimum(5.26239);
   Graph_Central5->SetMaximum(111.3228);
   Graph_Central5->SetDirectory(0);
   Graph_Central5->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Central5->SetLineColor(ci);
   Graph_Central5->GetXaxis()->SetLabelFont(42);
   Graph_Central5->GetXaxis()->SetTitleOffset(1);
   Graph_Central5->GetXaxis()->SetTitleFont(42);
   Graph_Central5->GetYaxis()->SetLabelFont(42);
   Graph_Central5->GetYaxis()->SetTitleFont(42);
   Graph_Central5->GetZaxis()->SetLabelFont(42);
   Graph_Central5->GetZaxis()->SetTitleOffset(1);
   Graph_Central5->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Central5);
   
   graph->Draw("l");
   
   TH1D *frame_367d4eb0__18 = new TH1D("frame_367d4eb0__18","p_T Balance",25,0,2);
   frame_367d4eb0__18->SetBinContent(1,113.7254);
   frame_367d4eb0__18->SetMinimum(-5.415493);
   frame_367d4eb0__18->SetMaximum(113.7254);
   frame_367d4eb0__18->SetEntries(1);
   frame_367d4eb0__18->SetDirectory(0);
   frame_367d4eb0__18->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367d4eb0__18->SetLineColor(ci);
   frame_367d4eb0__18->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367d4eb0__18->GetXaxis()->SetLabelFont(42);
   frame_367d4eb0__18->GetXaxis()->SetTitleOffset(1);
   frame_367d4eb0__18->GetXaxis()->SetTitleFont(42);
   frame_367d4eb0__18->GetYaxis()->SetTitle("1/Events");
   frame_367d4eb0__18->GetYaxis()->SetLabelFont(42);
   frame_367d4eb0__18->GetYaxis()->SetTitleFont(42);
   frame_367d4eb0__18->GetZaxis()->SetLabelFont(42);
   frame_367d4eb0__18->GetZaxis()->SetTitleOffset(1);
   frame_367d4eb0__18->GetZaxis()->SetTitleFont(42);
   frame_367d4eb0__18->Draw("AXISSAME");
   
   TH1D *norm_c__19 = new TH1D("norm_c__19","",25,0,2);
   norm_c__19->SetBinContent(2,0.924029);
   norm_c__19->SetBinContent(3,3.783663);
   norm_c__19->SetBinContent(4,3.208176);
   norm_c__19->SetBinContent(5,7.504762);
   norm_c__19->SetBinContent(6,7.020941);
   norm_c__19->SetBinContent(7,17.68541);
   norm_c__19->SetBinContent(8,27.16296);
   norm_c__19->SetBinContent(9,50.00075);
   norm_c__19->SetBinContent(10,78.97644);
   norm_c__19->SetBinContent(11,102.9165);
   norm_c__19->SetBinContent(12,96.50546);
   norm_c__19->SetBinContent(13,88.30505);
   norm_c__19->SetBinContent(14,52.40722);
   norm_c__19->SetBinContent(15,30.8063);
   norm_c__19->SetBinContent(16,13.29477);
   norm_c__19->SetBinContent(17,7.367297);
   norm_c__19->SetBinContent(18,1.467659);
   norm_c__19->SetBinContent(19,0.6152467);
   norm_c__19->SetBinContent(20,0.5466706);
   norm_c__19->SetBinContent(21,0.6945238);
   norm_c__19->SetBinContent(22,0.1605668);
   norm_c__19->SetBinContent(23,0.1406238);
   norm_c__19->SetBinContent(24,0.03166948);
   norm_c__19->SetBinContent(25,0.03311113);
   norm_c__19->SetBinContent(26,0.135223);
   norm_c__19->SetBinError(2,0.4756518);
   norm_c__19->SetBinError(3,0.9994016);
   norm_c__19->SetBinError(4,0.8600602);
   norm_c__19->SetBinError(5,1.395455);
   norm_c__19->SetBinError(6,1.351024);
   norm_c__19->SetBinError(7,2.230604);
   norm_c__19->SetBinError(8,2.722868);
   norm_c__19->SetBinError(9,3.900936);
   norm_c__19->SetBinError(10,4.793726);
   norm_c__19->SetBinError(11,5.393394);
   norm_c__19->SetBinError(12,5.128958);
   norm_c__19->SetBinError(13,4.874831);
   norm_c__19->SetBinError(14,3.571139);
   norm_c__19->SetBinError(15,2.736858);
   norm_c__19->SetBinError(16,1.679153);
   norm_c__19->SetBinError(17,1.219985);
   norm_c__19->SetBinError(18,0.4582876);
   norm_c__19->SetBinError(19,0.261603);
   norm_c__19->SetBinError(20,0.1853322);
   norm_c__19->SetBinError(21,0.2972081);
   norm_c__19->SetBinError(22,0.09048253);
   norm_c__19->SetBinError(23,0.08429342);
   norm_c__19->SetBinError(24,0.03166948);
   norm_c__19->SetBinError(25,0.0258221);
   norm_c__19->SetBinError(26,0.05548656);
   norm_c__19->SetEntries(3289);
   norm_c__19->SetStats(0);

   ci = 1319;
   color = new TColor(ci, 0.3, 0.3, 0.3, " ", 0.6);
   norm_c__19->SetFillColor(ci);
   norm_c__19->SetFillStyle(3144);
   norm_c__19->SetLineColor(2);
   norm_c__19->SetLineWidth(2);
   norm_c__19->GetXaxis()->SetRange(1,25);
   norm_c__19->GetXaxis()->SetLabelFont(42);
   norm_c__19->GetXaxis()->SetLabelSize(0.04);
   norm_c__19->GetXaxis()->SetTitleOffset(1);
   norm_c__19->GetXaxis()->SetTitleFont(42);
   norm_c__19->GetYaxis()->SetLabelFont(42);
   norm_c__19->GetYaxis()->SetTitleFont(42);
   norm_c__19->GetZaxis()->SetLabelFont(42);
   norm_c__19->GetZaxis()->SetTitleOffset(1);
   norm_c__19->GetZaxis()->SetTitleFont(42);
   norm_c__19->Draw("e1 same");
   
   TLegend *leg = new TLegend(0.65,0.5,0.93,0.87,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.03);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("norm_c","Central","lpf");

   ci = 1319;
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
   entry=leg->AddEntry("frame_x_c2_367d4eb0","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.886504 #pm 0.008162","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.182819 #pm 0.006952","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.910000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_367d4eb0_copy__20 = new TH1D("frame_367d4eb0_copy__20","p_T Balance",25,0,2);
   frame_367d4eb0_copy__20->SetBinContent(1,113.7254);
   frame_367d4eb0_copy__20->SetMinimum(-5.415493);
   frame_367d4eb0_copy__20->SetMaximum(113.7254);
   frame_367d4eb0_copy__20->SetEntries(1);
   frame_367d4eb0_copy__20->SetDirectory(0);
   frame_367d4eb0_copy__20->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367d4eb0_copy__20->SetLineColor(ci);
   frame_367d4eb0_copy__20->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367d4eb0_copy__20->GetXaxis()->SetLabelFont(42);
   frame_367d4eb0_copy__20->GetXaxis()->SetTitleOffset(1);
   frame_367d4eb0_copy__20->GetXaxis()->SetTitleFont(42);
   frame_367d4eb0_copy__20->GetYaxis()->SetTitle("1/Events");
   frame_367d4eb0_copy__20->GetYaxis()->SetLabelFont(42);
   frame_367d4eb0_copy__20->GetYaxis()->SetTitleFont(42);
   frame_367d4eb0_copy__20->GetZaxis()->SetLabelFont(42);
   frame_367d4eb0_copy__20->GetZaxis()->SetTitleOffset(1);
   frame_367d4eb0_copy__20->GetZaxis()->SetTitleFont(42);
   frame_367d4eb0_copy__20->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-11.43985,2.25,131.5582);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_367f8ce0__21 = new TH1D("frame_367f8ce0__21","p_T Balance",25,0,2);
   frame_367f8ce0__21->SetBinContent(1,117.2584);
   frame_367f8ce0__21->SetMaximum(117.2584);
   frame_367f8ce0__21->SetEntries(1);
   frame_367f8ce0__21->SetDirectory(0);
   frame_367f8ce0__21->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367f8ce0__21->SetLineColor(ci);
   frame_367f8ce0__21->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367f8ce0__21->GetXaxis()->SetLabelFont(42);
   frame_367f8ce0__21->GetXaxis()->SetTitleOffset(1);
   frame_367f8ce0__21->GetXaxis()->SetTitleFont(42);
   frame_367f8ce0__21->GetYaxis()->SetTitle("1/Events");
   frame_367f8ce0__21->GetYaxis()->SetLabelFont(42);
   frame_367f8ce0__21->GetYaxis()->SetTitleFont(42);
   frame_367f8ce0__21->GetZaxis()->SetLabelFont(42);
   frame_367f8ce0__21->GetZaxis()->SetTitleOffset(1);
   frame_367f8ce0__21->GetZaxis()->SetTitleFont(42);
   frame_367f8ce0__21->Draw("FUNC");
   
   Double_t h_dh_up2_fx3006[25] = {
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
   Double_t h_dh_up2_fy3006[25] = {
   0,
   0.3260803,
   3.207956,
   3.098072,
   6.226417,
   8.006186,
   17.60152,
   26.25858,
   47.05089,
   74.01257,
   106.1362,
   99.19286,
   92.29758,
   57.05866,
   36.86866,
   15.03484,
   9.578632,
   1.437043,
   0.7693384,
   0.6935597,
   0.7393571,
   0.09292854,
   0.3094946,
   0,
   0.008042533};
   Double_t h_dh_up2_felx3006[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_up2_fely3006[25] = {
   0,
   0.2033721,
   0.9567721,
   0.9108118,
   1.196853,
   1.530651,
   2.309854,
   2.642728,
   3.757383,
   4.702137,
   5.538522,
   5.206473,
   5.052919,
   3.762108,
   3.070506,
   1.80287,
   1.464383,
   0.4410091,
   0.3058744,
   0.2539429,
   0.3007007,
   0.06571095,
   0.1269166,
   0,
   0.006351968};
   Double_t h_dh_up2_fehx3006[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_up2_fehy3006[25] = {
   0,
   0.2033721,
   0.9567721,
   0.9108118,
   1.196853,
   1.530651,
   2.309854,
   2.642728,
   3.757383,
   4.702137,
   5.538522,
   5.206473,
   5.052919,
   3.762108,
   3.070506,
   1.80287,
   1.464383,
   0.4410091,
   0.3058744,
   0.2539429,
   0.3007007,
   0.06571095,
   0.1269166,
   0,
   0.006351968};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3006,h_dh_up2_fy3006,h_dh_up2_felx3006,h_dh_up2_fehx3006,h_dh_up2_fely3006,h_dh_up2_fehy3006);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23006 = new TH1F("Graph_h_dh_up23006","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23006->SetMinimum(0);
   Graph_h_dh_up23006->SetMaximum(122.8422);
   Graph_h_dh_up23006->SetDirectory(0);
   Graph_h_dh_up23006->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_up23006->SetLineColor(ci);
   Graph_h_dh_up23006->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_up23006->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_up23006->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_up23006->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_up23006->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_up23006->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_up23006->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_up23006->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_up23006);
   
   grae->Draw("p");
   
   Double_t up_fx6[58] = {
   0.4659495,
   0.501018,
   0.5185523,
   0.5360866,
   0.5536208,
   0.5711551,
   0.5886893,
   0.6062236,
   0.6237579,
   0.6412921,
   0.6500593,
   0.6588264,
   0.6763606,
   0.6938949,
   0.7114292,
   0.7464977,
   0.7640319,
   0.7815662,
   0.7991005,
   0.8166347,
   0.8254019,
   0.834169,
   0.8429361,
   0.8517032,
   0.8604704,
   0.8692375,
   0.8780046,
   0.8867718,
   0.8955389,
   0.904306,
   0.9130731,
   0.9218403,
   0.9306074,
   0.9393745,
   0.9481417,
   0.9569088,
   0.9656759,
   0.9744431,
   0.9919773,
   1.009512,
   1.027046,
   1.04458,
   1.062114,
   1.097183,
   1.114717,
   1.132251,
   1.149786,
   1.16732,
   1.184854,
   1.202388,
   1.211156,
   1.219923,
   1.237457,
   1.254991,
   1.272525,
   1.307594,
   1.342663,
   1.342663};
   Double_t up_fy6[58] = {
   10.98184,
   13.51037,
   15.04784,
   16.81037,
   18.83869,
   21.18237,
   23.90212,
   27.07274,
   30.78697,
   35.16059,
   37.63878,
   40.3392,
   46.25581,
   52.49901,
   58.96474,
   72.08491,
   78.46122,
   84.51274,
   90.08361,
   95.02236,
   97.21024,
   99.18873,
   100.9431,
   102.4602,
   103.7285,
   104.7381,
   105.4813,
   105.9524,
   106.1475,
   106.0652,
   105.7062,
   105.0731,
   104.1711,
   103.0071,
   101.59,
   99.93066,
   98.04169,
   95.93717,
   91.14473,
   85.6905,
   79.72421,
   73.40138,
   66.87668,
   53.80034,
   47.50342,
   41.50699,
   35.89005,
   30.71024,
   26.00453,
   21.81061,
   20.18188,
   18.8962,
   16.96771,
   15.56637,
   14.48651,
   12.90426,
   11.77886,
   11.77886};
   graph = new TGraph(58,up_fx6,up_fy6);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up6 = new TH1F("Graph_up6","Projection of upf DSCB fit",100,0.3782782,1.430334);
   Graph_up6->SetMinimum(1.465276);
   Graph_up6->SetMaximum(115.6641);
   Graph_up6->SetDirectory(0);
   Graph_up6->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_up6->SetLineColor(ci);
   Graph_up6->GetXaxis()->SetLabelFont(42);
   Graph_up6->GetXaxis()->SetTitleOffset(1);
   Graph_up6->GetXaxis()->SetTitleFont(42);
   Graph_up6->GetYaxis()->SetLabelFont(42);
   Graph_up6->GetYaxis()->SetTitleFont(42);
   Graph_up6->GetZaxis()->SetLabelFont(42);
   Graph_up6->GetZaxis()->SetTitleOffset(1);
   Graph_up6->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_up6);
   
   graph->Draw("l");
   
   TH1D *frame_367f8ce0__22 = new TH1D("frame_367f8ce0__22","p_T Balance",25,0,2);
   frame_367f8ce0__22->SetBinContent(1,117.2584);
   frame_367f8ce0__22->SetMaximum(117.2584);
   frame_367f8ce0__22->SetEntries(1);
   frame_367f8ce0__22->SetDirectory(0);
   frame_367f8ce0__22->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367f8ce0__22->SetLineColor(ci);
   frame_367f8ce0__22->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367f8ce0__22->GetXaxis()->SetLabelFont(42);
   frame_367f8ce0__22->GetXaxis()->SetTitleOffset(1);
   frame_367f8ce0__22->GetXaxis()->SetTitleFont(42);
   frame_367f8ce0__22->GetYaxis()->SetTitle("1/Events");
   frame_367f8ce0__22->GetYaxis()->SetLabelFont(42);
   frame_367f8ce0__22->GetYaxis()->SetTitleFont(42);
   frame_367f8ce0__22->GetZaxis()->SetLabelFont(42);
   frame_367f8ce0__22->GetZaxis()->SetTitleOffset(1);
   frame_367f8ce0__22->GetZaxis()->SetTitleFont(42);
   frame_367f8ce0__22->Draw("AXISSAME");
   
   TH1D *norm_u__23 = new TH1D("norm_u__23","",25,0,2);
   norm_u__23->SetBinContent(2,0.3260803);
   norm_u__23->SetBinContent(3,3.207956);
   norm_u__23->SetBinContent(4,3.098072);
   norm_u__23->SetBinContent(5,6.226417);
   norm_u__23->SetBinContent(6,8.006186);
   norm_u__23->SetBinContent(7,17.60152);
   norm_u__23->SetBinContent(8,26.25858);
   norm_u__23->SetBinContent(9,47.05089);
   norm_u__23->SetBinContent(10,74.01256);
   norm_u__23->SetBinContent(11,106.1362);
   norm_u__23->SetBinContent(12,99.19286);
   norm_u__23->SetBinContent(13,92.29758);
   norm_u__23->SetBinContent(14,57.05866);
   norm_u__23->SetBinContent(15,36.86866);
   norm_u__23->SetBinContent(16,15.03484);
   norm_u__23->SetBinContent(17,9.578633);
   norm_u__23->SetBinContent(18,1.437043);
   norm_u__23->SetBinContent(19,0.7693384);
   norm_u__23->SetBinContent(20,0.6935597);
   norm_u__23->SetBinContent(21,0.739357);
   norm_u__23->SetBinContent(22,0.09292855);
   norm_u__23->SetBinContent(23,0.3094946);
   norm_u__23->SetBinContent(25,0.008042533);
   norm_u__23->SetBinContent(26,0.1696389);
   norm_u__23->SetBinError(2,0.2033721);
   norm_u__23->SetBinError(3,0.9567721);
   norm_u__23->SetBinError(4,0.9108118);
   norm_u__23->SetBinError(5,1.196853);
   norm_u__23->SetBinError(6,1.530651);
   norm_u__23->SetBinError(7,2.309854);
   norm_u__23->SetBinError(8,2.642728);
   norm_u__23->SetBinError(9,3.757383);
   norm_u__23->SetBinError(10,4.702137);
   norm_u__23->SetBinError(11,5.538522);
   norm_u__23->SetBinError(12,5.206473);
   norm_u__23->SetBinError(13,5.052919);
   norm_u__23->SetBinError(14,3.762108);
   norm_u__23->SetBinError(15,3.070506);
   norm_u__23->SetBinError(16,1.80287);
   norm_u__23->SetBinError(17,1.464383);
   norm_u__23->SetBinError(18,0.4410091);
   norm_u__23->SetBinError(19,0.3058744);
   norm_u__23->SetBinError(20,0.2539429);
   norm_u__23->SetBinError(21,0.3007007);
   norm_u__23->SetBinError(22,0.06571095);
   norm_u__23->SetBinError(23,0.1269166);
   norm_u__23->SetBinError(25,0.006351968);
   norm_u__23->SetBinError(26,0.06036589);
   norm_u__23->SetEntries(3291);
   norm_u__23->SetStats(0);
   norm_u__23->SetLineColor(4);
   norm_u__23->SetLineWidth(2);
   norm_u__23->GetXaxis()->SetLabelFont(42);
   norm_u__23->GetXaxis()->SetTitleOffset(1);
   norm_u__23->GetXaxis()->SetTitleFont(42);
   norm_u__23->GetYaxis()->SetLabelFont(42);
   norm_u__23->GetYaxis()->SetTitleFont(42);
   norm_u__23->GetZaxis()->SetLabelFont(42);
   norm_u__23->GetZaxis()->SetTitleOffset(1);
   norm_u__23->GetZaxis()->SetTitleFont(42);
   norm_u__23->Draw("e1 same");
   
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
   entry=leg->AddEntry("frame_x_u2_367f8ce0","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.894137 #pm 0.007936","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.182449 #pm 0.006457","");
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
   
   TH1D *frame_367f8ce0_copy__24 = new TH1D("frame_367f8ce0_copy__24","p_T Balance",25,0,2);
   frame_367f8ce0_copy__24->SetBinContent(1,117.2584);
   frame_367f8ce0_copy__24->SetMaximum(117.2584);
   frame_367f8ce0_copy__24->SetEntries(1);
   frame_367f8ce0_copy__24->SetDirectory(0);
   frame_367f8ce0_copy__24->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367f8ce0_copy__24->SetLineColor(ci);
   frame_367f8ce0_copy__24->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367f8ce0_copy__24->GetXaxis()->SetLabelFont(42);
   frame_367f8ce0_copy__24->GetXaxis()->SetTitleOffset(1);
   frame_367f8ce0_copy__24->GetXaxis()->SetTitleFont(42);
   frame_367f8ce0_copy__24->GetYaxis()->SetTitle("1/Events");
   frame_367f8ce0_copy__24->GetYaxis()->SetLabelFont(42);
   frame_367f8ce0_copy__24->GetYaxis()->SetTitleFont(42);
   frame_367f8ce0_copy__24->GetZaxis()->SetLabelFont(42);
   frame_367f8ce0_copy__24->GetZaxis()->SetTitleOffset(1);
   frame_367f8ce0_copy__24->GetZaxis()->SetTitleFont(42);
   frame_367f8ce0_copy__24->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-12.56165,2.25,113.0549);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_367f8df0__25 = new TH1D("frame_367f8df0__25","p_T Balance",25,0,2);
   frame_367f8df0__25->SetBinContent(1,110.5426);
   frame_367f8df0__25->SetMaximum(110.5426);
   frame_367f8df0__25->SetEntries(1);
   frame_367f8df0__25->SetDirectory(0);
   frame_367f8df0__25->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367f8df0__25->SetLineColor(ci);
   frame_367f8df0__25->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367f8df0__25->GetXaxis()->SetLabelFont(42);
   frame_367f8df0__25->GetXaxis()->SetTitleOffset(1);
   frame_367f8df0__25->GetXaxis()->SetTitleFont(42);
   frame_367f8df0__25->GetYaxis()->SetTitle("1/Events");
   frame_367f8df0__25->GetYaxis()->SetLabelFont(42);
   frame_367f8df0__25->GetYaxis()->SetTitleFont(42);
   frame_367f8df0__25->GetZaxis()->SetLabelFont(42);
   frame_367f8df0__25->GetZaxis()->SetTitleOffset(1);
   frame_367f8df0__25->GetZaxis()->SetTitleFont(42);
   frame_367f8df0__25->Draw("FUNC");
   
   Double_t h_dh_down2_fx3007[25] = {
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
   Double_t h_dh_down2_fy3007[25] = {
   0,
   0.9521535,
   3.457015,
   2.815009,
   7.200608,
   7.480625,
   19.39684,
   29.99542,
   49.90699,
   80.3894,
   100.0608,
   98.27029,
   82.46071,
   47.34351,
   29.19462,
   14.187,
   8.135212,
   2.231636,
   0.820318,
   0.7975534,
   0.6513285,
   0.1179984,
   0.1418206,
   0,
   0.03335295};
   Double_t h_dh_down2_felx3007[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_down2_fely3007[25] = {
   0,
   0.443399,
   0.9592296,
   0.7637424,
   1.339056,
   1.407582,
   2.365174,
   2.877875,
   3.863719,
   4.81331,
   5.21778,
   5.187279,
   4.669626,
   3.353085,
   2.631818,
   1.765007,
   1.275831,
   0.6883499,
   0.3165351,
   0.2770718,
   0.2968216,
   0.07832298,
   0.08502461,
   0,
   0.02600737};
   Double_t h_dh_down2_fehx3007[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_down2_fehy3007[25] = {
   0,
   0.443399,
   0.9592296,
   0.7637424,
   1.339056,
   1.407582,
   2.365174,
   2.877875,
   3.863719,
   4.81331,
   5.21778,
   5.187279,
   4.669626,
   3.353085,
   2.631818,
   1.765007,
   1.275831,
   0.6883499,
   0.3165351,
   0.2770718,
   0.2968216,
   0.07832298,
   0.08502461,
   0,
   0.02600737};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3007,h_dh_down2_fy3007,h_dh_down2_felx3007,h_dh_down2_fehx3007,h_dh_down2_fely3007,h_dh_down2_fehy3007);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23007 = new TH1F("Graph_h_dh_down23007","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23007->SetMinimum(0);
   Graph_h_dh_down23007->SetMaximum(115.8065);
   Graph_h_dh_down23007->SetDirectory(0);
   Graph_h_dh_down23007->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_down23007->SetLineColor(ci);
   Graph_h_dh_down23007->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_down23007->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_down23007->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_down23007->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_down23007->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_down23007->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_down23007->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_down23007->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_down23007);
   
   grae->Draw("p");
   
   Double_t down_fx7[60] = {
   0.3966886,
   0.4348136,
   0.4729385,
   0.4920009,
   0.5110634,
   0.5301259,
   0.5491883,
   0.5682508,
   0.5873132,
   0.6063757,
   0.6159069,
   0.6254382,
   0.6349694,
   0.6445006,
   0.6635631,
   0.6826255,
   0.701688,
   0.7398129,
   0.7588754,
   0.7779378,
   0.7874691,
   0.7970003,
   0.8065315,
   0.8160628,
   0.825594,
   0.8351252,
   0.8446564,
   0.8541877,
   0.8637189,
   0.8732501,
   0.8827814,
   0.8923126,
   0.9018438,
   0.9113751,
   0.9209063,
   0.9304375,
   0.9399687,
   0.9495,
   0.9590312,
   0.9685624,
   0.9876249,
   1.006687,
   1.02575,
   1.044812,
   1.082937,
   1.102,
   1.121062,
   1.140125,
   1.159187,
   1.178249,
   1.187781,
   1.197312,
   1.206843,
   1.216374,
   1.235437,
   1.254499,
   1.273562,
   1.311687,
   1.349812,
   1.349812};
   Double_t down_fy7[60] = {
   8.11699,
   9.980104,
   12.4098,
   13.90226,
   15.62599,
   17.62535,
   19.95496,
   22.6825,
   25.89239,
   29.69072,
   31.8512,
   34.21181,
   36.79522,
   39.62715,
   45.9008,
   52.53345,
   59.3818,
   73.09605,
   79.60073,
   85.61345,
   88.37515,
   90.94291,
   93.29491,
   95.4108,
   97.27195,
   98.86172,
   100.1657,
   101.1721,
   101.8715,
   102.2574,
   102.3264,
   102.0778,
   101.5138,
   100.6397,
   99.46355,
   97.99619,
   96.25091,
   94.24341,
   91.99148,
   89.51477,
   83.97312,
   77.80146,
   71.19296,
   64.34106,
   50.62864,
   44.08116,
   37.90633,
   32.1938,
   27.00441,
   22.3717,
   20.26781,
   18.45132,
   17.02545,
   15.8699,
   14.09572,
   12.78328,
   11.76339,
   10.26355,
   9.198786,
   9.198786};
   graph = new TGraph(60,down_fx7,down_fy7);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down7 = new TH1F("Graph_down7","Projection of downf DSCB fit",100,0.3013763,1.445124);
   Graph_down7->SetMinimum(7.305291);
   Graph_down7->SetMaximum(111.7474);
   Graph_down7->SetDirectory(0);
   Graph_down7->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_down7->SetLineColor(ci);
   Graph_down7->GetXaxis()->SetLabelFont(42);
   Graph_down7->GetXaxis()->SetTitleOffset(1);
   Graph_down7->GetXaxis()->SetTitleFont(42);
   Graph_down7->GetYaxis()->SetLabelFont(42);
   Graph_down7->GetYaxis()->SetTitleFont(42);
   Graph_down7->GetZaxis()->SetLabelFont(42);
   Graph_down7->GetZaxis()->SetTitleOffset(1);
   Graph_down7->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_down7);
   
   graph->Draw("l");
   
   TH1D *frame_367f8df0__26 = new TH1D("frame_367f8df0__26","p_T Balance",25,0,2);
   frame_367f8df0__26->SetBinContent(1,110.5426);
   frame_367f8df0__26->SetMaximum(110.5426);
   frame_367f8df0__26->SetEntries(1);
   frame_367f8df0__26->SetDirectory(0);
   frame_367f8df0__26->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367f8df0__26->SetLineColor(ci);
   frame_367f8df0__26->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367f8df0__26->GetXaxis()->SetLabelFont(42);
   frame_367f8df0__26->GetXaxis()->SetTitleOffset(1);
   frame_367f8df0__26->GetXaxis()->SetTitleFont(42);
   frame_367f8df0__26->GetYaxis()->SetTitle("1/Events");
   frame_367f8df0__26->GetYaxis()->SetLabelFont(42);
   frame_367f8df0__26->GetYaxis()->SetTitleFont(42);
   frame_367f8df0__26->GetZaxis()->SetLabelFont(42);
   frame_367f8df0__26->GetZaxis()->SetTitleOffset(1);
   frame_367f8df0__26->GetZaxis()->SetTitleFont(42);
   frame_367f8df0__26->Draw("AXISSAME");
   
   TH1D *norm_d__27 = new TH1D("norm_d__27","",25,0,2);
   norm_d__27->SetBinContent(2,0.9521535);
   norm_d__27->SetBinContent(3,3.457015);
   norm_d__27->SetBinContent(4,2.815009);
   norm_d__27->SetBinContent(5,7.200608);
   norm_d__27->SetBinContent(6,7.480625);
   norm_d__27->SetBinContent(7,19.39684);
   norm_d__27->SetBinContent(8,29.99542);
   norm_d__27->SetBinContent(9,49.90699);
   norm_d__27->SetBinContent(10,80.3894);
   norm_d__27->SetBinContent(11,100.0608);
   norm_d__27->SetBinContent(12,98.27029);
   norm_d__27->SetBinContent(13,82.46071);
   norm_d__27->SetBinContent(14,47.3435);
   norm_d__27->SetBinContent(15,29.19462);
   norm_d__27->SetBinContent(16,14.187);
   norm_d__27->SetBinContent(17,8.135212);
   norm_d__27->SetBinContent(18,2.231636);
   norm_d__27->SetBinContent(19,0.820318);
   norm_d__27->SetBinContent(20,0.7975534);
   norm_d__27->SetBinContent(21,0.6513285);
   norm_d__27->SetBinContent(22,0.1179984);
   norm_d__27->SetBinContent(23,0.1418206);
   norm_d__27->SetBinContent(25,0.03335295);
   norm_d__27->SetBinContent(26,0.2312986);
   norm_d__27->SetBinError(2,0.443399);
   norm_d__27->SetBinError(3,0.9592296);
   norm_d__27->SetBinError(4,0.7637424);
   norm_d__27->SetBinError(5,1.339056);
   norm_d__27->SetBinError(6,1.407582);
   norm_d__27->SetBinError(7,2.365174);
   norm_d__27->SetBinError(8,2.877875);
   norm_d__27->SetBinError(9,3.863719);
   norm_d__27->SetBinError(10,4.81331);
   norm_d__27->SetBinError(11,5.21778);
   norm_d__27->SetBinError(12,5.187279);
   norm_d__27->SetBinError(13,4.669626);
   norm_d__27->SetBinError(14,3.353085);
   norm_d__27->SetBinError(15,2.631818);
   norm_d__27->SetBinError(16,1.765007);
   norm_d__27->SetBinError(17,1.275831);
   norm_d__27->SetBinError(18,0.6883499);
   norm_d__27->SetBinError(19,0.3165351);
   norm_d__27->SetBinError(20,0.2770718);
   norm_d__27->SetBinError(21,0.2968216);
   norm_d__27->SetBinError(22,0.07832298);
   norm_d__27->SetBinError(23,0.08502461);
   norm_d__27->SetBinError(25,0.02600737);
   norm_d__27->SetBinError(26,0.1086367);
   norm_d__27->SetEntries(3310);
   norm_d__27->SetStats(0);
   norm_d__27->SetLineColor(7);
   norm_d__27->SetLineWidth(2);
   norm_d__27->GetXaxis()->SetLabelFont(42);
   norm_d__27->GetXaxis()->SetTitleOffset(1);
   norm_d__27->GetXaxis()->SetTitleFont(42);
   norm_d__27->GetYaxis()->SetLabelFont(42);
   norm_d__27->GetYaxis()->SetTitleFont(42);
   norm_d__27->GetZaxis()->SetLabelFont(42);
   norm_d__27->GetZaxis()->SetTitleOffset(1);
   norm_d__27->GetZaxis()->SetTitleFont(42);
   norm_d__27->Draw("same e1");
   
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
   entry=leg->AddEntry("frame_x_d2_367f8df0","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.874142 #pm 0.008229","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.185940 #pm 0.006824","");
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
   
   TH1D *frame_367f8df0_copy__28 = new TH1D("frame_367f8df0_copy__28","p_T Balance",25,0,2);
   frame_367f8df0_copy__28->SetBinContent(1,110.5426);
   frame_367f8df0_copy__28->SetMaximum(110.5426);
   frame_367f8df0_copy__28->SetEntries(1);
   frame_367f8df0_copy__28->SetDirectory(0);
   frame_367f8df0_copy__28->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367f8df0_copy__28->SetLineColor(ci);
   frame_367f8df0_copy__28->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367f8df0_copy__28->GetXaxis()->SetLabelFont(42);
   frame_367f8df0_copy__28->GetXaxis()->SetTitleOffset(1);
   frame_367f8df0_copy__28->GetXaxis()->SetTitleFont(42);
   frame_367f8df0_copy__28->GetYaxis()->SetTitle("1/Events");
   frame_367f8df0_copy__28->GetYaxis()->SetLabelFont(42);
   frame_367f8df0_copy__28->GetYaxis()->SetTitleFont(42);
   frame_367f8df0_copy__28->GetZaxis()->SetLabelFont(42);
   frame_367f8df0_copy__28->GetZaxis()->SetTitleOffset(1);
   frame_367f8df0_copy__28->GetZaxis()->SetTitleFont(42);
   frame_367f8df0_copy__28->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-18.92307,2.25,170.3077);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_367effc0__29 = new TH1D("frame_367effc0__29","p_T Balance",25,0,2);
   frame_367effc0__29->SetBinContent(1,166.5231);
   frame_367effc0__29->SetMaximum(166.5231);
   frame_367effc0__29->SetEntries(1);
   frame_367effc0__29->SetDirectory(0);
   frame_367effc0__29->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367effc0__29->SetLineColor(ci);
   frame_367effc0__29->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367effc0__29->GetXaxis()->SetLabelFont(42);
   frame_367effc0__29->GetXaxis()->SetTitleOffset(1);
   frame_367effc0__29->GetXaxis()->SetTitleFont(42);
   frame_367effc0__29->GetYaxis()->SetTitle("1/Events");
   frame_367effc0__29->GetYaxis()->SetLabelFont(42);
   frame_367effc0__29->GetYaxis()->SetTitleFont(42);
   frame_367effc0__29->GetZaxis()->SetLabelFont(42);
   frame_367effc0__29->GetZaxis()->SetTitleOffset(1);
   frame_367effc0__29->GetZaxis()->SetTitleFont(42);
   frame_367effc0__29->Draw("FUNC");
   
   Double_t h_dh_data2_fx3008[25] = {
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
   Double_t h_dh_data2_fy3008[25] = {
   0,
   0,
   3,
   10,
   11,
   17,
   26,
   36,
   80,
   104,
   146,
   140,
   91,
   83,
   29,
   15,
   8,
   4,
   2,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t h_dh_data2_felx3008[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_data2_fely3008[25] = {
   0,
   0,
   1.632705,
   3.108694,
   3.265579,
   4.082184,
   5.066015,
   5.971996,
   8.925539,
   9.710289,
   11.59339,
   11.34272,
   9.521834,
   9.092044,
   5.353932,
   3.82938,
   2.768386,
   1.914339,
   1.291815,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t h_dh_data2_fehx3008[25] = {
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
   0.04,
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
   Double_t h_dh_data2_fehy3008[25] = {
   1.147874,
   1.147874,
   2.918186,
   4.26695,
   4.416521,
   5.203719,
   6.164324,
   7.055545,
   9.981567,
   10.71029,
   12.59339,
   12.34272,
   10.57436,
   10.14705,
   6.44702,
   4.958738,
   3.945142,
   3.162753,
   2.63786,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874};
   grae = new TGraphAsymmErrors(25,h_dh_data2_fx3008,h_dh_data2_fy3008,h_dh_data2_felx3008,h_dh_data2_fehx3008,h_dh_data2_fely3008,h_dh_data2_fehy3008);
   grae->SetName("h_dh_data2");
   grae->SetTitle("Histogram of dh_data2_plot__x_o2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_data23008 = new TH1F("Graph_h_dh_data23008","Histogram of dh_data2_plot__x_o2",100,0,2.2);
   Graph_h_dh_data23008->SetMinimum(0);
   Graph_h_dh_data23008->SetMaximum(174.4527);
   Graph_h_dh_data23008->SetDirectory(0);
   Graph_h_dh_data23008->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_dh_data23008->SetLineColor(ci);
   Graph_h_dh_data23008->GetXaxis()->SetLabelFont(42);
   Graph_h_dh_data23008->GetXaxis()->SetTitleOffset(1);
   Graph_h_dh_data23008->GetXaxis()->SetTitleFont(42);
   Graph_h_dh_data23008->GetYaxis()->SetLabelFont(42);
   Graph_h_dh_data23008->GetYaxis()->SetTitleFont(42);
   Graph_h_dh_data23008->GetZaxis()->SetLabelFont(42);
   Graph_h_dh_data23008->GetZaxis()->SetTitleOffset(1);
   Graph_h_dh_data23008->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_dh_data23008);
   
   grae->Draw("p");
   
   Double_t observation_fx8[55] = {
   0.4651383,
   0.4816479,
   0.4981575,
   0.5146671,
   0.5311767,
   0.5476863,
   0.5641959,
   0.5807055,
   0.5972151,
   0.6137247,
   0.6302343,
   0.6467439,
   0.6632535,
   0.6962727,
   0.7292919,
   0.7458015,
   0.7623111,
   0.7788207,
   0.7953303,
   0.8118399,
   0.8200948,
   0.8283496,
   0.8366044,
   0.8448592,
   0.853114,
   0.8613688,
   0.8696236,
   0.8778784,
   0.8861332,
   0.894388,
   0.9026428,
   0.9108976,
   0.9191524,
   0.9274072,
   0.9439168,
   0.9604264,
   0.976936,
   0.9934456,
   1.009955,
   1.026465,
   1.059484,
   1.092503,
   1.109013,
   1.125522,
   1.142032,
   1.158542,
   1.175051,
   1.191561,
   1.20807,
   1.22458,
   1.24109,
   1.257599,
   1.274109,
   1.290618,
   1.290618};
   Double_t observation_fy8[55] = {
   13.15492,
   14.8657,
   16.86386,
   19.20933,
   21.97711,
   25.26186,
   29.18387,
   33.89746,
   39.55971,
   45.88136,
   52.72578,
   60.03621,
   67.73404,
   83.86966,
   100.096,
   107.8519,
   115.1444,
   121.8038,
   127.6681,
   132.5891,
   134.6547,
   136.4383,
   137.9279,
   139.1133,
   139.9865,
   140.5414,
   140.7743,
   140.6836,
   140.2699,
   139.536,
   138.4869,
   137.13,
   135.4743,
   133.531,
   128.8354,
   123.1663,
   116.6681,
   109.5004,
   101.8317,
   93.83256,
   77.50066,
   61.69802,
   54.29494,
   47.34248,
   40.90215,
   35.01425,
   29.69935,
   24.96046,
   20.78556,
   17.15041,
   14.02137,
   11.35822,
   9.116608,
   7.250366,
   7.250366};
   graph = new TGraph(55,observation_fx8,observation_fy8);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation8 = new TH1F("Graph_observation8","Projection of obsf DSCB fit",100,0.3825902,1.373166);
   Graph_observation8->SetMinimum(6.525329);
   Graph_observation8->SetMaximum(154.1267);
   Graph_observation8->SetDirectory(0);
   Graph_observation8->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_observation8->SetLineColor(ci);
   Graph_observation8->GetXaxis()->SetLabelFont(42);
   Graph_observation8->GetXaxis()->SetTitleOffset(1);
   Graph_observation8->GetXaxis()->SetTitleFont(42);
   Graph_observation8->GetYaxis()->SetLabelFont(42);
   Graph_observation8->GetYaxis()->SetTitleFont(42);
   Graph_observation8->GetZaxis()->SetLabelFont(42);
   Graph_observation8->GetZaxis()->SetTitleOffset(1);
   Graph_observation8->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_observation8);
   
   graph->Draw("l");
   
   TH1D *frame_367effc0__30 = new TH1D("frame_367effc0__30","p_T Balance",25,0,2);
   frame_367effc0__30->SetBinContent(1,166.5231);
   frame_367effc0__30->SetMaximum(166.5231);
   frame_367effc0__30->SetEntries(1);
   frame_367effc0__30->SetDirectory(0);
   frame_367effc0__30->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367effc0__30->SetLineColor(ci);
   frame_367effc0__30->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367effc0__30->GetXaxis()->SetLabelFont(42);
   frame_367effc0__30->GetXaxis()->SetTitleOffset(1);
   frame_367effc0__30->GetXaxis()->SetTitleFont(42);
   frame_367effc0__30->GetYaxis()->SetTitle("1/Events");
   frame_367effc0__30->GetYaxis()->SetLabelFont(42);
   frame_367effc0__30->GetYaxis()->SetTitleFont(42);
   frame_367effc0__30->GetZaxis()->SetLabelFont(42);
   frame_367effc0__30->GetZaxis()->SetTitleOffset(1);
   frame_367effc0__30->GetZaxis()->SetTitleFont(42);
   frame_367effc0__30->Draw("AXISSAME");
   
   TH1D *norm_o__31 = new TH1D("norm_o__31","",25,0,2);
   norm_o__31->SetBinContent(3,3);
   norm_o__31->SetBinContent(4,10);
   norm_o__31->SetBinContent(5,11);
   norm_o__31->SetBinContent(6,17);
   norm_o__31->SetBinContent(7,26);
   norm_o__31->SetBinContent(8,36);
   norm_o__31->SetBinContent(9,80);
   norm_o__31->SetBinContent(10,104);
   norm_o__31->SetBinContent(11,146);
   norm_o__31->SetBinContent(12,140);
   norm_o__31->SetBinContent(13,91);
   norm_o__31->SetBinContent(14,83);
   norm_o__31->SetBinContent(15,29);
   norm_o__31->SetBinContent(16,15);
   norm_o__31->SetBinContent(17,8);
   norm_o__31->SetBinContent(18,4);
   norm_o__31->SetBinContent(19,2);
   norm_o__31->SetBinContent(26,1);
   norm_o__31->SetMinimum(0);
   norm_o__31->SetMaximum(321.2);
   norm_o__31->SetEntries(806);
   norm_o__31->SetStats(0);
   norm_o__31->SetLineWidth(2);
   norm_o__31->SetMarkerStyle(8);
   norm_o__31->SetMarkerSize(0.4);
   norm_o__31->GetXaxis()->SetRange(1,25);
   norm_o__31->GetXaxis()->SetLabelFont(42);
   norm_o__31->GetXaxis()->SetLabelSize(0.04);
   norm_o__31->GetXaxis()->SetTitleOffset(1);
   norm_o__31->GetXaxis()->SetTitleFont(42);
   norm_o__31->GetYaxis()->SetTitle("Events");
   norm_o__31->GetYaxis()->SetLabelFont(42);
   norm_o__31->GetYaxis()->SetTitleOffset(1.4);
   norm_o__31->GetYaxis()->SetTitleFont(42);
   norm_o__31->GetZaxis()->SetLabelFont(42);
   norm_o__31->GetZaxis()->SetTitleOffset(1);
   norm_o__31->GetZaxis()->SetTitleFont(42);
   norm_o__31->Draw("same e1");
   
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
   entry=leg->AddEntry("frame_x_o2_367effc0","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.874971 #pm 0.006899","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.168408 #pm 0.005993","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.981000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_367effc0_copy__32 = new TH1D("frame_367effc0_copy__32","p_T Balance",25,0,2);
   frame_367effc0_copy__32->SetBinContent(1,166.5231);
   frame_367effc0_copy__32->SetMaximum(166.5231);
   frame_367effc0_copy__32->SetEntries(1);
   frame_367effc0_copy__32->SetDirectory(0);
   frame_367effc0_copy__32->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_367effc0_copy__32->SetLineColor(ci);
   frame_367effc0_copy__32->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_367effc0_copy__32->GetXaxis()->SetLabelFont(42);
   frame_367effc0_copy__32->GetXaxis()->SetTitleOffset(1);
   frame_367effc0_copy__32->GetXaxis()->SetTitleFont(42);
   frame_367effc0_copy__32->GetYaxis()->SetTitle("1/Events");
   frame_367effc0_copy__32->GetYaxis()->SetLabelFont(42);
   frame_367effc0_copy__32->GetYaxis()->SetTitleFont(42);
   frame_367effc0_copy__32->GetZaxis()->SetLabelFont(42);
   frame_367effc0_copy__32->GetZaxis()->SetTitleOffset(1);
   frame_367effc0_copy__32->GetZaxis()->SetTitleFont(42);
   frame_367effc0_copy__32->Draw("sameaxis");
   
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
