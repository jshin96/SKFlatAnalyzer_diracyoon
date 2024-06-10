void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_1__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 17:23:01 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-2.140789,2.25,16.114);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_3183a5b0__1 = new TH1D("frame_3183a5b0__1","p_T Balance",25,0,2);
   frame_3183a5b0__1->SetBinContent(1,14.28852);
   frame_3183a5b0__1->SetMinimum(-0.6804057);
   frame_3183a5b0__1->SetMaximum(14.28852);
   frame_3183a5b0__1->SetEntries(1);
   frame_3183a5b0__1->SetDirectory(0);
   frame_3183a5b0__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_3183a5b0__1->SetLineColor(ci);
   frame_3183a5b0__1->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3183a5b0__1->GetXaxis()->SetLabelFont(42);
   frame_3183a5b0__1->GetXaxis()->SetTitleOffset(1);
   frame_3183a5b0__1->GetXaxis()->SetTitleFont(42);
   frame_3183a5b0__1->GetYaxis()->SetTitle("1/Events");
   frame_3183a5b0__1->GetYaxis()->SetLabelFont(42);
   frame_3183a5b0__1->GetYaxis()->SetTitleFont(42);
   frame_3183a5b0__1->GetZaxis()->SetLabelFont(42);
   frame_3183a5b0__1->GetZaxis()->SetTitleOffset(1);
   frame_3183a5b0__1->GetZaxis()->SetTitleFont(42);
   frame_3183a5b0__1->Draw("FUNC");
   
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
   0.1823441,
   0.343869,
   0.1450247,
   0.5241734,
   1.01544,
   0.9363821,
   1.471973,
   2.611842,
   5.040517,
   8.208928,
   12.19129,
   10.08516,
   6.197882,
   2.110007,
   0.6291578,
   0.5883027,
   0.06591415,
   0.05393529,
   0.008168306,
   0,
   0.004956421,
   0,
   0,
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
   0.1440736,
   0.2483733,
   0.09050625,
   0.3588476,
   0.3923006,
   0.4962006,
   0.47687,
   0.6722912,
   0.8230099,
   1.14986,
   1.41682,
   1.25206,
   0.9767964,
   0.5678107,
   0.2709662,
   0.2947485,
   0.06591414,
   0.03775836,
   0.008168306,
   0,
   0.004956421,
   0,
   0,
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
   0.1440736,
   0.2483733,
   0.09050625,
   0.3588476,
   0.3923006,
   0.4962006,
   0.47687,
   0.6722912,
   0.8230099,
   1.14986,
   1.41682,
   1.25206,
   0.9767964,
   0.5678107,
   0.2709662,
   0.2947485,
   0.06591414,
   0.03775836,
   0.008168306,
   0,
   0.004956421,
   0,
   0,
   0};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3001,h_dh_central2_fy3001,h_dh_central2_felx3001,h_dh_central2_fehx3001,h_dh_central2_fely3001,h_dh_central2_fehy3001);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23001 = new TH1F("Graph_h_dh_central23001","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23001->SetMinimum(-1.360811);
   Graph_h_dh_central23001->SetMaximum(14.96892);
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
   
   Double_t Central_fx1[55] = {
   0.6344133,
   0.6587234,
   0.6830335,
   0.6951886,
   0.7073436,
   0.7194987,
   0.7316537,
   0.7438088,
   0.7559638,
   0.7681189,
   0.7802739,
   0.792429,
   0.804584,
   0.8288941,
   0.8410492,
   0.8532042,
   0.8653593,
   0.8775143,
   0.8896694,
   0.8957469,
   0.9018244,
   0.907902,
   0.9139795,
   0.920057,
   0.9261346,
   0.9322121,
   0.9382896,
   0.9443671,
   0.9504447,
   0.9565222,
   0.9625997,
   0.9686772,
   0.9747548,
   0.9808323,
   0.9869098,
   0.9990649,
   1.01122,
   1.023375,
   1.03553,
   1.047685,
   1.071995,
   1.096305,
   1.10846,
   1.120615,
   1.13277,
   1.144926,
   1.157081,
   1.169236,
   1.181391,
   1.193546,
   1.205701,
   1.217856,
   1.230011,
   1.242166,
   1.242166};
   Double_t Central_fy1[55] = {
   2.053547,
   2.380069,
   2.774157,
   3.001812,
   3.25331,
   3.531711,
   3.840545,
   4.183892,
   4.566488,
   4.99384,
   5.472384,
   6.009657,
   6.614525,
   7.974976,
   8.642421,
   9.277761,
   9.86626,
   10.39354,
   10.84617,
   11.04068,
   11.21219,
   11.35954,
   11.48171,
   11.57785,
   11.64727,
   11.68951,
   11.70425,
   11.6914,
   11.65104,
   11.58346,
   11.48913,
   11.36872,
   11.22307,
   11.05317,
   10.86019,
   10.41034,
   9.885403,
   9.298766,
   8.664788,
   7.998198,
   6.624691,
   5.283792,
   4.65252,
   4.058191,
   3.506536,
   3.001414,
   2.544925,
   2.137597,
   1.7786,
   1.465995,
   1.196984,
   0.968157,
   0.7757199,
   0.6156951,
   0.6156951};
   TGraph *graph = new TGraph(55,Central_fx1,Central_fy1);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central1 = new TH1F("Graph_Central1","Projection of centralf DSCB fit",100,0.573638,1.302941);
   Graph_Central1->SetMinimum(0.5541256);
   Graph_Central1->SetMaximum(12.81311);
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
   
   TH1D *frame_3183a5b0__2 = new TH1D("frame_3183a5b0__2","p_T Balance",25,0,2);
   frame_3183a5b0__2->SetBinContent(1,14.28852);
   frame_3183a5b0__2->SetMinimum(-0.6804057);
   frame_3183a5b0__2->SetMaximum(14.28852);
   frame_3183a5b0__2->SetEntries(1);
   frame_3183a5b0__2->SetDirectory(0);
   frame_3183a5b0__2->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3183a5b0__2->SetLineColor(ci);
   frame_3183a5b0__2->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3183a5b0__2->GetXaxis()->SetLabelFont(42);
   frame_3183a5b0__2->GetXaxis()->SetTitleOffset(1);
   frame_3183a5b0__2->GetXaxis()->SetTitleFont(42);
   frame_3183a5b0__2->GetYaxis()->SetTitle("1/Events");
   frame_3183a5b0__2->GetYaxis()->SetLabelFont(42);
   frame_3183a5b0__2->GetYaxis()->SetTitleFont(42);
   frame_3183a5b0__2->GetZaxis()->SetLabelFont(42);
   frame_3183a5b0__2->GetZaxis()->SetTitleOffset(1);
   frame_3183a5b0__2->GetZaxis()->SetTitleFont(42);
   frame_3183a5b0__2->Draw("AXISSAME");
   
   TH1D *norm_c__3 = new TH1D("norm_c__3","",25,0,2);
   norm_c__3->SetBinContent(2,0.1823441);
   norm_c__3->SetBinContent(3,0.343869);
   norm_c__3->SetBinContent(4,0.1450247);
   norm_c__3->SetBinContent(5,0.5241734);
   norm_c__3->SetBinContent(6,1.01544);
   norm_c__3->SetBinContent(7,0.9363821);
   norm_c__3->SetBinContent(8,1.471973);
   norm_c__3->SetBinContent(9,2.611842);
   norm_c__3->SetBinContent(10,5.040517);
   norm_c__3->SetBinContent(11,8.208928);
   norm_c__3->SetBinContent(12,12.19129);
   norm_c__3->SetBinContent(13,10.08516);
   norm_c__3->SetBinContent(14,6.197882);
   norm_c__3->SetBinContent(15,2.110007);
   norm_c__3->SetBinContent(16,0.6291578);
   norm_c__3->SetBinContent(17,0.5883027);
   norm_c__3->SetBinContent(18,0.06591414);
   norm_c__3->SetBinContent(19,0.05393529);
   norm_c__3->SetBinContent(20,0.008168306);
   norm_c__3->SetBinContent(22,0.004956421);
   norm_c__3->SetBinContent(26,0.01076375);
   norm_c__3->SetBinError(2,0.1440736);
   norm_c__3->SetBinError(3,0.2483733);
   norm_c__3->SetBinError(4,0.09050625);
   norm_c__3->SetBinError(5,0.3588476);
   norm_c__3->SetBinError(6,0.3923006);
   norm_c__3->SetBinError(7,0.4962006);
   norm_c__3->SetBinError(8,0.47687);
   norm_c__3->SetBinError(9,0.6722912);
   norm_c__3->SetBinError(10,0.8230099);
   norm_c__3->SetBinError(11,1.14986);
   norm_c__3->SetBinError(12,1.41682);
   norm_c__3->SetBinError(13,1.25206);
   norm_c__3->SetBinError(14,0.9767964);
   norm_c__3->SetBinError(15,0.5678107);
   norm_c__3->SetBinError(16,0.2709662);
   norm_c__3->SetBinError(17,0.2947485);
   norm_c__3->SetBinError(18,0.06591414);
   norm_c__3->SetBinError(19,0.03775836);
   norm_c__3->SetBinError(20,0.008168306);
   norm_c__3->SetBinError(22,0.004956421);
   norm_c__3->SetBinError(26,0.008575999);
   norm_c__3->SetEntries(617);
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
   entry=leg->AddEntry("frame_x_c2_3183a5b0","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.938485 #pm 0.021716","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.125071 #pm 0.019442","");
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
   
   TH1D *frame_3183a5b0_copy__4 = new TH1D("frame_3183a5b0_copy__4","p_T Balance",25,0,2);
   frame_3183a5b0_copy__4->SetBinContent(1,14.28852);
   frame_3183a5b0_copy__4->SetMinimum(-0.6804057);
   frame_3183a5b0_copy__4->SetMaximum(14.28852);
   frame_3183a5b0_copy__4->SetEntries(1);
   frame_3183a5b0_copy__4->SetDirectory(0);
   frame_3183a5b0_copy__4->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_3183a5b0_copy__4->SetLineColor(ci);
   frame_3183a5b0_copy__4->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_3183a5b0_copy__4->GetXaxis()->SetLabelFont(42);
   frame_3183a5b0_copy__4->GetXaxis()->SetTitleOffset(1);
   frame_3183a5b0_copy__4->GetXaxis()->SetTitleFont(42);
   frame_3183a5b0_copy__4->GetYaxis()->SetTitle("1/Events");
   frame_3183a5b0_copy__4->GetYaxis()->SetLabelFont(42);
   frame_3183a5b0_copy__4->GetYaxis()->SetTitleFont(42);
   frame_3183a5b0_copy__4->GetZaxis()->SetLabelFont(42);
   frame_3183a5b0_copy__4->GetZaxis()->SetTitleOffset(1);
   frame_3183a5b0_copy__4->GetZaxis()->SetTitleFont(42);
   frame_3183a5b0_copy__4->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-1.867107,2.25,14.05396);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_31835220__5 = new TH1D("frame_31835220__5","p_T Balance",25,0,2);
   frame_31835220__5->SetBinContent(1,12.46185);
   frame_31835220__5->SetMinimum(-0.5934216);
   frame_31835220__5->SetMaximum(12.46185);
   frame_31835220__5->SetEntries(1);
   frame_31835220__5->SetDirectory(0);
   frame_31835220__5->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_31835220__5->SetLineColor(ci);
   frame_31835220__5->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_31835220__5->GetXaxis()->SetLabelFont(42);
   frame_31835220__5->GetXaxis()->SetTitleOffset(1);
   frame_31835220__5->GetXaxis()->SetTitleFont(42);
   frame_31835220__5->GetYaxis()->SetTitle("1/Events");
   frame_31835220__5->GetYaxis()->SetLabelFont(42);
   frame_31835220__5->GetYaxis()->SetTitleFont(42);
   frame_31835220__5->GetZaxis()->SetLabelFont(42);
   frame_31835220__5->GetZaxis()->SetTitleOffset(1);
   frame_31835220__5->GetZaxis()->SetTitleFont(42);
   frame_31835220__5->Draw("FUNC");
   
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
   0.1842998,
   0.3452933,
   0.1446164,
   0.2029337,
   1.015625,
   1.333769,
   1.446082,
   2.82394,
   3.99892,
   8.996257,
   10.56203,
   10.43378,
   6.631037,
   2.609751,
   0.6545229,
   0.5483358,
   0,
   0.01626766,
   0.0176309,
   0,
   0.004928898,
   0,
   0,
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
   0.1456743,
   0.2493577,
   0.08999945,
   0.1594054,
   0.3925755,
   0.6364969,
   0.5181153,
   0.6830635,
   0.714839,
   1.19005,
   1.3064,
   1.251769,
   1.048986,
   0.6353488,
   0.2726992,
   0.2919466,
   0,
   0.01156496,
   0.01250534,
   0,
   0.004928898,
   0,
   0,
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
   0.1456743,
   0.2493577,
   0.08999945,
   0.1594054,
   0.3925755,
   0.6364969,
   0.5181153,
   0.6830635,
   0.714839,
   1.19005,
   1.3064,
   1.251769,
   1.048986,
   0.6353488,
   0.2726992,
   0.2919466,
   0,
   0.01156496,
   0.01250534,
   0,
   0.004928898,
   0,
   0,
   0};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3002,h_dh_up2_fy3002,h_dh_up2_felx3002,h_dh_up2_fehx3002,h_dh_up2_fely3002,h_dh_up2_fehy3002);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23002 = new TH1F("Graph_h_dh_up23002","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23002->SetMinimum(-1.186843);
   Graph_h_dh_up23002->SetMaximum(13.05528);
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
   
   Double_t up_fx2[56] = {
   0.6160155,
   0.6291855,
   0.6423556,
   0.6555256,
   0.6686956,
   0.6818657,
   0.6950357,
   0.7082057,
   0.7213758,
   0.7345458,
   0.7477158,
   0.7608858,
   0.7740559,
   0.8003959,
   0.826736,
   0.839906,
   0.8530761,
   0.8662461,
   0.8794161,
   0.8860011,
   0.8925861,
   0.8991712,
   0.9057562,
   0.9123412,
   0.9189262,
   0.9255112,
   0.9320962,
   0.9386813,
   0.9452663,
   0.9518513,
   0.9584363,
   0.9650213,
   0.9716063,
   0.9781913,
   0.9847764,
   0.9979464,
   1.011116,
   1.024286,
   1.037456,
   1.063797,
   1.090137,
   1.103307,
   1.116477,
   1.129647,
   1.142817,
   1.155987,
   1.169157,
   1.182327,
   1.195497,
   1.208667,
   1.221837,
   1.235007,
   1.248177,
   1.261347,
   1.274517,
   1.274517};
   Double_t up_fy2[56] = {
   0.7090823,
   0.887162,
   1.099486,
   1.34976,
   1.64136,
   1.977112,
   2.359061,
   2.788223,
   3.264344,
   3.785688,
   4.348846,
   4.948613,
   5.577933,
   6.888012,
   8.189093,
   8.802929,
   9.373439,
   9.886692,
   10.3296,
   10.52094,
   10.69045,
   10.83696,
   10.95946,
   11.05709,
   11.12916,
   11.17517,
   11.19479,
   11.18789,
   11.1545,
   11.09487,
   11.00942,
   10.89875,
   10.76364,
   10.60502,
   10.42399,
   9.999751,
   9.502213,
   8.944182,
   8.339439,
   7.046448,
   5.732247,
   5.097095,
   4.48953,
   3.917052,
   3.385307,
   2.898126,
   2.457631,
   2.064412,
   1.717736,
   1.415783,
   1.155893,
   0.9347996,
   0.7488587,
   0.5942395,
   0.4670931,
   0.4670931};
   graph = new TGraph(56,up_fx2,up_fy2);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up2 = new TH1F("Graph_up2","Projection of upf DSCB fit",100,0.5501654,1.340367);
   Graph_up2->SetMinimum(0.4203838);
   Graph_up2->SetMaximum(12.26756);
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
   
   TH1D *frame_31835220__6 = new TH1D("frame_31835220__6","p_T Balance",25,0,2);
   frame_31835220__6->SetBinContent(1,12.46185);
   frame_31835220__6->SetMinimum(-0.5934216);
   frame_31835220__6->SetMaximum(12.46185);
   frame_31835220__6->SetEntries(1);
   frame_31835220__6->SetDirectory(0);
   frame_31835220__6->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_31835220__6->SetLineColor(ci);
   frame_31835220__6->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_31835220__6->GetXaxis()->SetLabelFont(42);
   frame_31835220__6->GetXaxis()->SetTitleOffset(1);
   frame_31835220__6->GetXaxis()->SetTitleFont(42);
   frame_31835220__6->GetYaxis()->SetTitle("1/Events");
   frame_31835220__6->GetYaxis()->SetLabelFont(42);
   frame_31835220__6->GetYaxis()->SetTitleFont(42);
   frame_31835220__6->GetZaxis()->SetLabelFont(42);
   frame_31835220__6->GetZaxis()->SetTitleOffset(1);
   frame_31835220__6->GetZaxis()->SetTitleFont(42);
   frame_31835220__6->Draw("AXISSAME");
   
   TH1D *norm_u__7 = new TH1D("norm_u__7","",25,0,2);
   norm_u__7->SetBinContent(2,0.1842998);
   norm_u__7->SetBinContent(3,0.3452932);
   norm_u__7->SetBinContent(4,0.1446164);
   norm_u__7->SetBinContent(5,0.2029337);
   norm_u__7->SetBinContent(6,1.015624);
   norm_u__7->SetBinContent(7,1.333769);
   norm_u__7->SetBinContent(8,1.446082);
   norm_u__7->SetBinContent(9,2.82394);
   norm_u__7->SetBinContent(10,3.99892);
   norm_u__7->SetBinContent(11,8.996257);
   norm_u__7->SetBinContent(12,10.56203);
   norm_u__7->SetBinContent(13,10.43378);
   norm_u__7->SetBinContent(14,6.631037);
   norm_u__7->SetBinContent(15,2.609751);
   norm_u__7->SetBinContent(16,0.6545229);
   norm_u__7->SetBinContent(17,0.5483358);
   norm_u__7->SetBinContent(19,0.01626766);
   norm_u__7->SetBinContent(20,0.01763091);
   norm_u__7->SetBinContent(22,0.004928898);
   norm_u__7->SetBinContent(26,0.002346652);
   norm_u__7->SetBinError(2,0.1456743);
   norm_u__7->SetBinError(3,0.2493577);
   norm_u__7->SetBinError(4,0.08999945);
   norm_u__7->SetBinError(5,0.1594054);
   norm_u__7->SetBinError(6,0.3925755);
   norm_u__7->SetBinError(7,0.6364969);
   norm_u__7->SetBinError(8,0.5181153);
   norm_u__7->SetBinError(9,0.6830635);
   norm_u__7->SetBinError(10,0.714839);
   norm_u__7->SetBinError(11,1.19005);
   norm_u__7->SetBinError(12,1.3064);
   norm_u__7->SetBinError(13,1.251769);
   norm_u__7->SetBinError(14,1.048986);
   norm_u__7->SetBinError(15,0.6353488);
   norm_u__7->SetBinError(16,0.2726992);
   norm_u__7->SetBinError(17,0.2919466);
   norm_u__7->SetBinError(19,0.01156496);
   norm_u__7->SetBinError(20,0.01250534);
   norm_u__7->SetBinError(22,0.004928898);
   norm_u__7->SetBinError(26,0.001662675);
   norm_u__7->SetEntries(608);
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
   entry=leg->AddEntry("frame_x_u2_31835220","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.933721 #pm 0.020878","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.135173 #pm 0.018238","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.798000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_31835220_copy__8 = new TH1D("frame_31835220_copy__8","p_T Balance",25,0,2);
   frame_31835220_copy__8->SetBinContent(1,12.46185);
   frame_31835220_copy__8->SetMinimum(-0.5934216);
   frame_31835220_copy__8->SetMaximum(12.46185);
   frame_31835220_copy__8->SetEntries(1);
   frame_31835220_copy__8->SetDirectory(0);
   frame_31835220_copy__8->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_31835220_copy__8->SetLineColor(ci);
   frame_31835220_copy__8->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_31835220_copy__8->GetXaxis()->SetLabelFont(42);
   frame_31835220_copy__8->GetXaxis()->SetTitleOffset(1);
   frame_31835220_copy__8->GetXaxis()->SetTitleFont(42);
   frame_31835220_copy__8->GetYaxis()->SetTitle("1/Events");
   frame_31835220_copy__8->GetYaxis()->SetLabelFont(42);
   frame_31835220_copy__8->GetYaxis()->SetTitleFont(42);
   frame_31835220_copy__8->GetZaxis()->SetLabelFont(42);
   frame_31835220_copy__8->GetZaxis()->SetTitleOffset(1);
   frame_31835220_copy__8->GetZaxis()->SetTitleFont(42);
   frame_31835220_copy__8->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-2.311184,2.25,14.19727);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_31835330__9 = new TH1D("frame_31835330__9","p_T Balance",25,0,2);
   frame_31835330__9->SetBinContent(1,13.8671);
   frame_31835330__9->SetMinimum(-0.6603383);
   frame_31835330__9->SetMaximum(13.8671);
   frame_31835330__9->SetEntries(1);
   frame_31835330__9->SetDirectory(0);
   frame_31835330__9->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_31835330__9->SetLineColor(ci);
   frame_31835330__9->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_31835330__9->GetXaxis()->SetLabelFont(42);
   frame_31835330__9->GetXaxis()->SetTitleOffset(1);
   frame_31835330__9->GetXaxis()->SetTitleFont(42);
   frame_31835330__9->GetYaxis()->SetTitle("1/Events");
   frame_31835330__9->GetYaxis()->SetLabelFont(42);
   frame_31835330__9->GetYaxis()->SetTitleFont(42);
   frame_31835330__9->GetZaxis()->SetLabelFont(42);
   frame_31835330__9->GetZaxis()->SetTitleOffset(1);
   frame_31835330__9->GetZaxis()->SetTitleFont(42);
   frame_31835330__9->Draw("FUNC");
   
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
   0.1828583,
   0.3460914,
   0.3012702,
   0.5068911,
   0.6171447,
   0.5922923,
   1.806635,
   2.926534,
   5.125798,
   10.9684,
   11.82393,
   8.306017,
   5.978071,
   1.505036,
   0.5672557,
   0.6258568,
   0.06645061,
   0.04533224,
   0.009771712,
   0.00499676,
   0.004622551,
   0,
   0,
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
   0.1446367,
   0.2501036,
   0.1474292,
   0.3569395,
   0.2718138,
   0.4256139,
   0.5265181,
   0.7348848,
   0.7913113,
   1.401536,
   1.382833,
   1.134273,
   0.9912707,
   0.4057696,
   0.2648114,
   0.2989805,
   0.06645061,
   0.03697728,
   0.008376983,
   0.004996761,
   0.00462255,
   0,
   0,
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
   0.1446367,
   0.2501036,
   0.1474292,
   0.3569395,
   0.2718138,
   0.4256139,
   0.5265181,
   0.7348848,
   0.7913113,
   1.401536,
   1.382833,
   1.134273,
   0.9912707,
   0.4057696,
   0.2648114,
   0.2989805,
   0.06645061,
   0.03697728,
   0.008376983,
   0.004996761,
   0.00462255,
   0,
   0,
   0};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3003,h_dh_down2_fy3003,h_dh_down2_felx3003,h_dh_down2_fehx3003,h_dh_down2_fely3003,h_dh_down2_fehy3003);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23003 = new TH1F("Graph_h_dh_down23003","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23003->SetMinimum(-1.320677);
   Graph_h_dh_down23003->SetMaximum(14.52744);
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
   0.5918916,
   0.6175652,
   0.6432388,
   0.6689124,
   0.694586,
   0.7074227,
   0.7138411,
   0.7202595,
   0.7234687,
   0.7266779,
   0.7330963,
   0.7459331,
   0.7587699,
   0.7716067,
   0.7972803,
   0.8229538,
   0.8357906,
   0.8486274,
   0.8614642,
   0.8678826,
   0.874301,
   0.8807194,
   0.8871378,
   0.8935562,
   0.8999746,
   0.906393,
   0.9128114,
   0.9192297,
   0.9256481,
   0.9320665,
   0.9384849,
   0.9449033,
   0.9513217,
   0.9577401,
   0.9641585,
   0.9705769,
   0.9769953,
   0.9898321,
   1.002669,
   1.015506,
   1.028342,
   1.054016,
   1.066853,
   1.07969,
   1.092526,
   1.105363,
   1.1182,
   1.131037,
   1.143874,
   1.15671,
   1.169547,
   1.182384,
   1.195221,
   1.208057,
   1.220894,
   1.233731,
   1.233731};
   Double_t down_fy3[57] = {
   2.898835,
   2.929531,
   2.968937,
   3.023735,
   3.113133,
   3.192469,
   3.256331,
   3.366536,
   3.47577,
   3.624511,
   3.932985,
   4.591695,
   5.300255,
   6.04914,
   7.615644,
   9.162458,
   9.880395,
   10.5344,
   11.10499,
   11.35337,
   11.57443,
   11.76638,
   11.92764,
   12.05686,
   12.15296,
   12.21514,
   12.24286,
   12.2359,
   12.1943,
   12.11843,
   12.00892,
   11.8667,
   11.69295,
   11.48911,
   11.25686,
   10.99806,
   10.71478,
   10.08377,
   9.382861,
   8.632186,
   7.851984,
   6.279368,
   5.520696,
   4.798934,
   4.124477,
   3.504822,
   2.944667,
   2.44613,
   2.009074,
   1.631494,
   1.30993,
   1.039881,
   0.8161923,
   0.6333946,
   0.4859922,
   0.3686866,
   0.3686866};
   graph = new TGraph(57,down_fx3,down_fy3);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down3 = new TH1F("Graph_down3","Projection of downf DSCB fit",100,0.5277077,1.297915);
   Graph_down3->SetMinimum(0.3318179);
   Graph_down3->SetMaximum(13.43028);
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
   
   TH1D *frame_31835330__10 = new TH1D("frame_31835330__10","p_T Balance",25,0,2);
   frame_31835330__10->SetBinContent(1,13.8671);
   frame_31835330__10->SetMinimum(-0.6603383);
   frame_31835330__10->SetMaximum(13.8671);
   frame_31835330__10->SetEntries(1);
   frame_31835330__10->SetDirectory(0);
   frame_31835330__10->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_31835330__10->SetLineColor(ci);
   frame_31835330__10->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_31835330__10->GetXaxis()->SetLabelFont(42);
   frame_31835330__10->GetXaxis()->SetTitleOffset(1);
   frame_31835330__10->GetXaxis()->SetTitleFont(42);
   frame_31835330__10->GetYaxis()->SetTitle("1/Events");
   frame_31835330__10->GetYaxis()->SetLabelFont(42);
   frame_31835330__10->GetYaxis()->SetTitleFont(42);
   frame_31835330__10->GetZaxis()->SetLabelFont(42);
   frame_31835330__10->GetZaxis()->SetTitleOffset(1);
   frame_31835330__10->GetZaxis()->SetTitleFont(42);
   frame_31835330__10->Draw("AXISSAME");
   
   TH1D *norm_d__11 = new TH1D("norm_d__11","",25,0,2);
   norm_d__11->SetBinContent(2,0.1828583);
   norm_d__11->SetBinContent(3,0.3460914);
   norm_d__11->SetBinContent(4,0.3012702);
   norm_d__11->SetBinContent(5,0.5068912);
   norm_d__11->SetBinContent(6,0.6171447);
   norm_d__11->SetBinContent(7,0.5922923);
   norm_d__11->SetBinContent(8,1.806635);
   norm_d__11->SetBinContent(9,2.926534);
   norm_d__11->SetBinContent(10,5.125798);
   norm_d__11->SetBinContent(11,10.9684);
   norm_d__11->SetBinContent(12,11.82393);
   norm_d__11->SetBinContent(13,8.306017);
   norm_d__11->SetBinContent(14,5.978071);
   norm_d__11->SetBinContent(15,1.505036);
   norm_d__11->SetBinContent(16,0.5672558);
   norm_d__11->SetBinContent(17,0.6258568);
   norm_d__11->SetBinContent(18,0.06645061);
   norm_d__11->SetBinContent(19,0.04533224);
   norm_d__11->SetBinContent(20,0.009771712);
   norm_d__11->SetBinContent(21,0.004996761);
   norm_d__11->SetBinContent(22,0.00462255);
   norm_d__11->SetBinContent(26,0.01084467);
   norm_d__11->SetBinError(2,0.1446367);
   norm_d__11->SetBinError(3,0.2501036);
   norm_d__11->SetBinError(4,0.1474292);
   norm_d__11->SetBinError(5,0.3569395);
   norm_d__11->SetBinError(6,0.2718138);
   norm_d__11->SetBinError(7,0.4256139);
   norm_d__11->SetBinError(8,0.5265181);
   norm_d__11->SetBinError(9,0.7348848);
   norm_d__11->SetBinError(10,0.7913113);
   norm_d__11->SetBinError(11,1.401536);
   norm_d__11->SetBinError(12,1.382833);
   norm_d__11->SetBinError(13,1.134273);
   norm_d__11->SetBinError(14,0.9912707);
   norm_d__11->SetBinError(15,0.4057696);
   norm_d__11->SetBinError(16,0.2648114);
   norm_d__11->SetBinError(17,0.2989805);
   norm_d__11->SetBinError(18,0.06645061);
   norm_d__11->SetBinError(19,0.03697728);
   norm_d__11->SetBinError(20,0.008376983);
   norm_d__11->SetBinError(21,0.004996761);
   norm_d__11->SetBinError(22,0.00462255);
   norm_d__11->SetBinError(26,0.008644936);
   norm_d__11->SetEntries(617);
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
   entry=leg->AddEntry("frame_x_d2_31835330","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.914738 #pm 0.018884","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.120513 #pm 0.017242","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.915000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_31835330_copy__12 = new TH1D("frame_31835330_copy__12","p_T Balance",25,0,2);
   frame_31835330_copy__12->SetBinContent(1,13.8671);
   frame_31835330_copy__12->SetMinimum(-0.6603383);
   frame_31835330_copy__12->SetMaximum(13.8671);
   frame_31835330_copy__12->SetEntries(1);
   frame_31835330_copy__12->SetDirectory(0);
   frame_31835330_copy__12->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_31835330_copy__12->SetLineColor(ci);
   frame_31835330_copy__12->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_31835330_copy__12->GetXaxis()->SetLabelFont(42);
   frame_31835330_copy__12->GetXaxis()->SetTitleOffset(1);
   frame_31835330_copy__12->GetXaxis()->SetTitleFont(42);
   frame_31835330_copy__12->GetYaxis()->SetTitle("1/Events");
   frame_31835330_copy__12->GetYaxis()->SetLabelFont(42);
   frame_31835330_copy__12->GetYaxis()->SetTitleFont(42);
   frame_31835330_copy__12->GetZaxis()->SetLabelFont(42);
   frame_31835330_copy__12->GetZaxis()->SetTitleOffset(1);
   frame_31835330_copy__12->GetZaxis()->SetTitleFont(42);
   frame_31835330_copy__12->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-2.515593,2.25,22.64034);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_31833dd0__13 = new TH1D("frame_31833dd0__13","p_T Balance",25,0,2);
   frame_31833dd0__13->SetBinContent(1,22.13722);
   frame_31833dd0__13->SetMaximum(22.13722);
   frame_31833dd0__13->SetEntries(1);
   frame_31833dd0__13->SetDirectory(0);
   frame_31833dd0__13->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_31833dd0__13->SetLineColor(ci);
   frame_31833dd0__13->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_31833dd0__13->GetXaxis()->SetLabelFont(42);
   frame_31833dd0__13->GetXaxis()->SetTitleOffset(1);
   frame_31833dd0__13->GetXaxis()->SetTitleFont(42);
   frame_31833dd0__13->GetYaxis()->SetTitle("1/Events");
   frame_31833dd0__13->GetYaxis()->SetLabelFont(42);
   frame_31833dd0__13->GetYaxis()->SetTitleFont(42);
   frame_31833dd0__13->GetZaxis()->SetLabelFont(42);
   frame_31833dd0__13->GetZaxis()->SetTitleOffset(1);
   frame_31833dd0__13->GetZaxis()->SetTitleFont(42);
   frame_31833dd0__13->Draw("FUNC");
   
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
   0,
   0,
   0,
   0,
   2,
   2,
   1,
   0,
   6,
   10,
   14,
   16,
   14,
   4,
   2,
   0,
   1,
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
   0,
   0,
   0,
   0,
   1.291815,
   1.291815,
   0.8272462,
   0,
   2.379931,
   3.108694,
   3.6965,
   3.957801,
   3.6965,
   1.914339,
   1.291815,
   0,
   0.8272462,
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
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   2.63786,
   2.63786,
   2.299527,
   1.147874,
   3.583642,
   4.26695,
   4.830381,
   5.083066,
   4.830381,
   3.162753,
   2.63786,
   1.147874,
   2.299527,
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
   Graph_h_dh_data23004->SetMaximum(23.19137);
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
   0.6531088,
   0.6657129,
   0.678317,
   0.6909211,
   0.7035252,
   0.7161294,
   0.7287335,
   0.7413376,
   0.7539417,
   0.7665458,
   0.7791499,
   0.791754,
   0.8043581,
   0.8169622,
   0.8295664,
   0.8547746,
   0.8673787,
   0.8799828,
   0.8925869,
   0.905191,
   0.9177951,
   0.9240972,
   0.9303993,
   0.9367013,
   0.9430034,
   0.9493054,
   0.9556075,
   0.9619095,
   0.9682116,
   0.9745136,
   0.9808157,
   0.9871178,
   0.9934198,
   0.9997219,
   1.006024,
   1.012326,
   1.018628,
   1.031232,
   1.043836,
   1.05644,
   1.069044,
   1.081649,
   1.106857,
   1.119461,
   1.132065,
   1.144669,
   1.157273,
   1.169877,
   1.182481,
   1.195086,
   1.20769,
   1.220294,
   1.232898,
   1.245502,
   1.258106,
   1.27071,
   1.283314,
   1.283314};
   Double_t observation_fy4[58] = {
   0.6699154,
   0.8604843,
   1.095491,
   1.38056,
   1.722197,
   2.126624,
   2.599439,
   3.145206,
   3.767033,
   4.466121,
   5.241339,
   6.088843,
   7.001772,
   7.970067,
   8.980421,
   11.05881,
   12.08608,
   13.07504,
   14.00172,
   14.84228,
   15.57401,
   15.89254,
   16.17637,
   16.42344,
   16.63192,
   16.80026,
   16.92718,
   17.01173,
   17.05326,
   17.05146,
   17.00635,
   16.91826,
   16.78786,
   16.61615,
   16.4044,
   16.15421,
   15.86742,
   15.19263,
   14.39926,
   13.50915,
   12.54576,
   11.53311,
   9.453392,
   8.429065,
   7.439639,
   6.499876,
   5.621329,
   4.812311,
   4.078018,
   3.420781,
   2.840417,
   2.334639,
   1.899495,
   1.529809,
   1.219599,
   0.9624491,
   0.7518291,
   0.7518291};
   graph = new TGraph(58,observation_fx4,observation_fy4);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation4 = new TH1F("Graph_observation4","Projection of obsf DSCB fit",100,0.5900882,1.346335);
   Graph_observation4->SetMinimum(0.6029239);
   Graph_observation4->SetMaximum(18.6916);
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
   
   TH1D *frame_31833dd0__14 = new TH1D("frame_31833dd0__14","p_T Balance",25,0,2);
   frame_31833dd0__14->SetBinContent(1,22.13722);
   frame_31833dd0__14->SetMaximum(22.13722);
   frame_31833dd0__14->SetEntries(1);
   frame_31833dd0__14->SetDirectory(0);
   frame_31833dd0__14->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_31833dd0__14->SetLineColor(ci);
   frame_31833dd0__14->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_31833dd0__14->GetXaxis()->SetLabelFont(42);
   frame_31833dd0__14->GetXaxis()->SetTitleOffset(1);
   frame_31833dd0__14->GetXaxis()->SetTitleFont(42);
   frame_31833dd0__14->GetYaxis()->SetTitle("1/Events");
   frame_31833dd0__14->GetYaxis()->SetLabelFont(42);
   frame_31833dd0__14->GetYaxis()->SetTitleFont(42);
   frame_31833dd0__14->GetZaxis()->SetLabelFont(42);
   frame_31833dd0__14->GetZaxis()->SetTitleOffset(1);
   frame_31833dd0__14->GetZaxis()->SetTitleFont(42);
   frame_31833dd0__14->Draw("AXISSAME");
   
   TH1D *norm_o__15 = new TH1D("norm_o__15","",25,0,2);
   norm_o__15->SetBinContent(6,2);
   norm_o__15->SetBinContent(7,2);
   norm_o__15->SetBinContent(8,1);
   norm_o__15->SetBinContent(10,6);
   norm_o__15->SetBinContent(11,10);
   norm_o__15->SetBinContent(12,14);
   norm_o__15->SetBinContent(13,16);
   norm_o__15->SetBinContent(14,14);
   norm_o__15->SetBinContent(15,4);
   norm_o__15->SetBinContent(16,2);
   norm_o__15->SetBinContent(18,1);
   norm_o__15->SetMinimum(0);
   norm_o__15->SetMaximum(35.2);
   norm_o__15->SetEntries(72);
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
   entry=leg->AddEntry("frame_x_o2_31833dd0","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.971136 #pm 0.016064","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.124883 #pm 0.013359","");
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
   
   TH1D *frame_31833dd0_copy__16 = new TH1D("frame_31833dd0_copy__16","p_T Balance",25,0,2);
   frame_31833dd0_copy__16->SetBinContent(1,22.13722);
   frame_31833dd0_copy__16->SetMaximum(22.13722);
   frame_31833dd0_copy__16->SetEntries(1);
   frame_31833dd0_copy__16->SetDirectory(0);
   frame_31833dd0_copy__16->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_31833dd0_copy__16->SetLineColor(ci);
   frame_31833dd0_copy__16->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_31833dd0_copy__16->GetXaxis()->SetLabelFont(42);
   frame_31833dd0_copy__16->GetXaxis()->SetTitleOffset(1);
   frame_31833dd0_copy__16->GetXaxis()->SetTitleFont(42);
   frame_31833dd0_copy__16->GetYaxis()->SetTitle("1/Events");
   frame_31833dd0_copy__16->GetYaxis()->SetLabelFont(42);
   frame_31833dd0_copy__16->GetYaxis()->SetTitleFont(42);
   frame_31833dd0_copy__16->GetZaxis()->SetLabelFont(42);
   frame_31833dd0_copy__16->GetZaxis()->SetTitleOffset(1);
   frame_31833dd0_copy__16->GetZaxis()->SetTitleFont(42);
   frame_31833dd0_copy__16->Draw("sameaxis");
   
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
