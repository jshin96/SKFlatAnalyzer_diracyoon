void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_5__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 19:17:25 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-58.62811,2.25,674.2233);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_45de3a60__65 = new TH1D("frame_45de3a60__65","p_T Balance",25,0,2);
   frame_45de3a60__65->SetBinContent(1,600.9382);
   frame_45de3a60__65->SetMaximum(600.9382);
   frame_45de3a60__65->SetEntries(2);
   frame_45de3a60__65->SetDirectory(0);
   frame_45de3a60__65->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_45de3a60__65->SetLineColor(ci);
   frame_45de3a60__65->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45de3a60__65->GetXaxis()->SetLabelFont(42);
   frame_45de3a60__65->GetXaxis()->SetTitleOffset(1);
   frame_45de3a60__65->GetXaxis()->SetTitleFont(42);
   frame_45de3a60__65->GetYaxis()->SetTitle("1/Events");
   frame_45de3a60__65->GetYaxis()->SetLabelFont(42);
   frame_45de3a60__65->GetYaxis()->SetTitleFont(42);
   frame_45de3a60__65->GetZaxis()->SetLabelFont(42);
   frame_45de3a60__65->GetZaxis()->SetTitleOffset(1);
   frame_45de3a60__65->GetZaxis()->SetTitleFont(42);
   frame_45de3a60__65->Draw("FUNC");
   
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
   0.6459848,
   64.93734,
   151.1755,
   228.3663,
   333.497,
   432.4597,
   549.7297,
   528.5128,
   519.2407,
   462.5057,
   367.1342,
   288.8695,
   202.7065,
   123.2688,
   95.31734,
   52.96742,
   36.5865,
   22.90037,
   13.7291,
   5.646039,
   4.86669,
   2.034657,
   2.233117};
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
   0.5855745,
   5.533605,
   8.627693,
   11.05034,
   13.49042,
   15.54375,
   17.86731,
   17.23259,
   17.32623,
   16.38908,
   14.14607,
   12.72521,
   10.26264,
   7.631331,
   6.495197,
   4.767227,
   3.673576,
   2.914829,
   2.121826,
   1.175777,
   1.082507,
   0.6498178,
   0.5637441};
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
   0.5855745,
   5.533605,
   8.627693,
   11.05034,
   13.49042,
   15.54375,
   17.86731,
   17.23259,
   17.32623,
   16.38908,
   14.14607,
   12.72521,
   10.26264,
   7.631331,
   6.495197,
   4.767227,
   3.673576,
   2.914829,
   2.121826,
   1.175777,
   1.082507,
   0.6498178,
   0.5637441};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3017,h_dh_central2_fy3017,h_dh_central2_felx3017,h_dh_central2_fehx3017,h_dh_central2_fely3017,h_dh_central2_fehy3017);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23017 = new TH1F("Graph_h_dh_central23017","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23017->SetMinimum(0);
   Graph_h_dh_central23017->SetMaximum(624.3568);
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
   
   Double_t Central_fx17[58] = {
   0.1101879,
   0.1369282,
   0.1636685,
   0.1904088,
   0.2171492,
   0.2438895,
   0.2706298,
   0.2973701,
   0.3241104,
   0.3508507,
   0.377591,
   0.4043313,
   0.4310716,
   0.457812,
   0.4845523,
   0.5380329,
   0.5915135,
   0.6182538,
   0.6449941,
   0.6583643,
   0.6717344,
   0.6851046,
   0.6984748,
   0.7118449,
   0.7252151,
   0.7385852,
   0.7519554,
   0.7653255,
   0.7786957,
   0.7920658,
   0.805436,
   0.8188062,
   0.8321763,
   0.8455465,
   0.8589166,
   0.8722868,
   0.8856569,
   0.8990271,
   0.9123972,
   0.9391376,
   0.9658779,
   0.9926182,
   1.019358,
   1.072839,
   1.099579,
   1.11295,
   1.12632,
   1.15306,
   1.1798,
   1.206541,
   1.233281,
   1.260021,
   1.286762,
   1.313502,
   1.340242,
   1.393723,
   1.447203,
   1.447203};
   Double_t Central_fy17[58] = {
   11.21597,
   15.23544,
   20.44,
   27.08413,
   35.44513,
   45.81483,
   58.48755,
   73.74433,
   91.8336,
   112.949,
   137.2054,
   164.6143,
   195.0617,
   228.2885,
   263.8785,
   339.6781,
   416.066,
   451.9823,
   484.9404,
   499.9767,
   513.8816,
   526.5364,
   537.8308,
   547.6649,
   555.9505,
   562.6124,
   567.5896,
   570.8361,
   572.3221,
   572.0335,
   569.9731,
   566.1601,
   560.6297,
   553.4329,
   544.6352,
   534.3163,
   522.5683,
   509.4948,
   495.2088,
   463.4911,
   428.4521,
   391.1749,
   352.7341,
   276.3275,
   240.1915,
   223.8078,
   208.7974,
   182.369,
   159.9928,
   140.9456,
   124.6504,
   110.6435,
   98.5499,
   88.06441,
   78.9371,
   63.96951,
   52.38723,
   52.38723};
   TGraph *graph = new TGraph(58,Central_fx17,Central_fy17);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central17 = new TH1F("Graph_Central17","Projection of centralf DSCB fit",100,0,1.580905);
   Graph_Central17->SetMinimum(10.09437);
   Graph_Central17->SetMaximum(628.4327);
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
   
   TH1D *frame_45de3a60__66 = new TH1D("frame_45de3a60__66","p_T Balance",25,0,2);
   frame_45de3a60__66->SetBinContent(1,600.9382);
   frame_45de3a60__66->SetMaximum(600.9382);
   frame_45de3a60__66->SetEntries(2);
   frame_45de3a60__66->SetDirectory(0);
   frame_45de3a60__66->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45de3a60__66->SetLineColor(ci);
   frame_45de3a60__66->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45de3a60__66->GetXaxis()->SetLabelFont(42);
   frame_45de3a60__66->GetXaxis()->SetTitleOffset(1);
   frame_45de3a60__66->GetXaxis()->SetTitleFont(42);
   frame_45de3a60__66->GetYaxis()->SetTitle("1/Events");
   frame_45de3a60__66->GetYaxis()->SetLabelFont(42);
   frame_45de3a60__66->GetYaxis()->SetTitleFont(42);
   frame_45de3a60__66->GetZaxis()->SetLabelFont(42);
   frame_45de3a60__66->GetZaxis()->SetTitleOffset(1);
   frame_45de3a60__66->GetZaxis()->SetTitleFont(42);
   frame_45de3a60__66->Draw("AXISSAME");
   
   TH1D *norm_c__67 = new TH1D("norm_c__67","",25,0,2);
   norm_c__67->SetBinContent(3,0.6459848);
   norm_c__67->SetBinContent(4,64.93734);
   norm_c__67->SetBinContent(5,151.1755);
   norm_c__67->SetBinContent(6,228.3663);
   norm_c__67->SetBinContent(7,333.497);
   norm_c__67->SetBinContent(8,432.4597);
   norm_c__67->SetBinContent(9,549.7297);
   norm_c__67->SetBinContent(10,528.5127);
   norm_c__67->SetBinContent(11,519.2407);
   norm_c__67->SetBinContent(12,462.5057);
   norm_c__67->SetBinContent(13,367.1342);
   norm_c__67->SetBinContent(14,288.8695);
   norm_c__67->SetBinContent(15,202.7065);
   norm_c__67->SetBinContent(16,123.2688);
   norm_c__67->SetBinContent(17,95.31734);
   norm_c__67->SetBinContent(18,52.96742);
   norm_c__67->SetBinContent(19,36.5865);
   norm_c__67->SetBinContent(20,22.90037);
   norm_c__67->SetBinContent(21,13.7291);
   norm_c__67->SetBinContent(22,5.646039);
   norm_c__67->SetBinContent(23,4.86669);
   norm_c__67->SetBinContent(24,2.034657);
   norm_c__67->SetBinContent(25,2.233117);
   norm_c__67->SetBinContent(26,6.558932);
   norm_c__67->SetBinError(3,0.5855745);
   norm_c__67->SetBinError(4,5.533605);
   norm_c__67->SetBinError(5,8.627693);
   norm_c__67->SetBinError(6,11.05034);
   norm_c__67->SetBinError(7,13.49042);
   norm_c__67->SetBinError(8,15.54375);
   norm_c__67->SetBinError(9,17.86731);
   norm_c__67->SetBinError(10,17.23259);
   norm_c__67->SetBinError(11,17.32623);
   norm_c__67->SetBinError(12,16.38908);
   norm_c__67->SetBinError(13,14.14607);
   norm_c__67->SetBinError(14,12.72521);
   norm_c__67->SetBinError(15,10.26264);
   norm_c__67->SetBinError(16,7.631331);
   norm_c__67->SetBinError(17,6.495197);
   norm_c__67->SetBinError(18,4.767227);
   norm_c__67->SetBinError(19,3.673576);
   norm_c__67->SetBinError(20,2.914829);
   norm_c__67->SetBinError(21,2.121826);
   norm_c__67->SetBinError(22,1.175777);
   norm_c__67->SetBinError(23,1.082507);
   norm_c__67->SetBinError(24,0.6498178);
   norm_c__67->SetBinError(25,0.5637441);
   norm_c__67->SetBinError(26,0.9003758);
   norm_c__67->SetEntries(18861);
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
   entry=leg->AddEntry("frame_x_c2_45de3a60","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.783208 #pm 0.004039","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.239977 #pm 0.003370","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.360000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_45de3a60_copy__68 = new TH1D("frame_45de3a60_copy__68","p_T Balance",25,0,2);
   frame_45de3a60_copy__68->SetBinContent(1,600.9382);
   frame_45de3a60_copy__68->SetMaximum(600.9382);
   frame_45de3a60_copy__68->SetEntries(2);
   frame_45de3a60_copy__68->SetDirectory(0);
   frame_45de3a60_copy__68->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45de3a60_copy__68->SetLineColor(ci);
   frame_45de3a60_copy__68->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45de3a60_copy__68->GetXaxis()->SetLabelFont(42);
   frame_45de3a60_copy__68->GetXaxis()->SetTitleOffset(1);
   frame_45de3a60_copy__68->GetXaxis()->SetTitleFont(42);
   frame_45de3a60_copy__68->GetYaxis()->SetTitle("1/Events");
   frame_45de3a60_copy__68->GetYaxis()->SetLabelFont(42);
   frame_45de3a60_copy__68->GetYaxis()->SetTitleFont(42);
   frame_45de3a60_copy__68->GetZaxis()->SetLabelFont(42);
   frame_45de3a60_copy__68->GetZaxis()->SetTitleOffset(1);
   frame_45de3a60_copy__68->GetZaxis()->SetTitleFont(42);
   frame_45de3a60_copy__68->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-59.0126,2.25,678.6449);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_45e09110__69 = new TH1D("frame_45e09110__69","p_T Balance",25,0,2);
   frame_45e09110__69->SetBinContent(1,604.8791);
   frame_45e09110__69->SetMaximum(604.8791);
   frame_45e09110__69->SetEntries(2);
   frame_45e09110__69->SetDirectory(0);
   frame_45e09110__69->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45e09110__69->SetLineColor(ci);
   frame_45e09110__69->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45e09110__69->GetXaxis()->SetLabelFont(42);
   frame_45e09110__69->GetXaxis()->SetTitleOffset(1);
   frame_45e09110__69->GetXaxis()->SetTitleFont(42);
   frame_45e09110__69->GetYaxis()->SetTitle("1/Events");
   frame_45e09110__69->GetYaxis()->SetLabelFont(42);
   frame_45e09110__69->GetYaxis()->SetTitleFont(42);
   frame_45e09110__69->GetZaxis()->SetLabelFont(42);
   frame_45e09110__69->GetZaxis()->SetTitleOffset(1);
   frame_45e09110__69->GetZaxis()->SetTitleFont(42);
   frame_45e09110__69->Draw("FUNC");
   
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
   0.7052468,
   65.93084,
   139.2801,
   221.9291,
   306.303,
   432.4181,
   532.6623,
   518.0983,
   535.6123,
   487.5804,
   409.8603,
   290.2083,
   236.4464,
   150.1406,
   116.2164,
   58.06769,
   43.55923,
   28.03652,
   15.07765,
   7.39417,
   7.070186,
   2.40554,
   1.421437};
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
   0.6730721,
   5.849666,
   8.559724,
   10.99637,
   13.15214,
   15.89751,
   17.63648,
   17.18386,
   17.58578,
   17.04845,
   15.26521,
   12.70506,
   11.25259,
   8.854758,
   7.558812,
   4.88992,
   4.375099,
   3.350235,
   2.094672,
   1.497862,
   1.447525,
   0.7462471,
   0.3723264};
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
   0.6730721,
   5.849666,
   8.559724,
   10.99637,
   13.15214,
   15.89751,
   17.63648,
   17.18386,
   17.58578,
   17.04845,
   15.26521,
   12.70506,
   11.25259,
   8.854758,
   7.558812,
   4.88992,
   4.375099,
   3.350235,
   2.094672,
   1.497862,
   1.447525,
   0.7462471,
   0.3723264};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3018,h_dh_up2_fy3018,h_dh_up2_felx3018,h_dh_up2_fehx3018,h_dh_up2_fely3018,h_dh_up2_fehy3018);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23018 = new TH1F("Graph_h_dh_up23018","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23018->SetMinimum(0);
   Graph_h_dh_up23018->SetMaximum(608.5179);
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
   0.08374911,
   0.1405076,
   0.1688869,
   0.1972661,
   0.2256454,
   0.2540247,
   0.2824039,
   0.3107832,
   0.3391624,
   0.3675417,
   0.3959209,
   0.4243002,
   0.4526795,
   0.4810587,
   0.509438,
   0.5378172,
   0.5945758,
   0.622955,
   0.6513343,
   0.6655239,
   0.6797135,
   0.6939032,
   0.7080928,
   0.7222824,
   0.736472,
   0.7506617,
   0.7648513,
   0.7790409,
   0.7932306,
   0.8074202,
   0.8216098,
   0.8357994,
   0.8499891,
   0.8641787,
   0.8783683,
   0.892558,
   0.9067476,
   0.9209372,
   0.9351269,
   0.9635061,
   0.9918854,
   1.048644,
   1.077023,
   1.091213,
   1.105402,
   1.119592,
   1.133782,
   1.162161,
   1.19054,
   1.218919,
   1.247299,
   1.275678,
   1.304057,
   1.332436,
   1.360816,
   1.389195,
   1.445953,
   1.502712,
   1.502712};
   Double_t up_fy18[59] = {
   7.630457,
   14.76437,
   20.12101,
   27.04909,
   35.86937,
   46.92056,
   60.54396,
   77.06314,
   96.75888,
   119.8404,
   146.4144,
   176.4545,
   209.7732,
   246.0001,
   284.5699,
   324.7214,
   405.8443,
   444.5147,
   480.2651,
   496.6541,
   511.8517,
   525.7162,
   538.1156,
   548.9299,
   558.0527,
   565.3933,
   570.8778,
   574.4506,
   576.0754,
   575.7354,
   573.4343,
   569.1956,
   563.0622,
   555.0962,
   545.3776,
   534.0025,
   521.0824,
   506.7417,
   491.1157,
   456.5933,
   418.739,
   338.0461,
   297.5738,
   277.7876,
   259.229,
   242.1946,
   226.5367,
   198.8395,
   175.2488,
   155.0551,
   137.6881,
   122.6859,
   109.6724,
   98.33953,
   88.4334,
   79.7438,
   65.34305,
   54.05118,
   54.05118};
   graph = new TGraph(59,up_fx18,up_fy18);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up18 = new TH1F("Graph_up18","Projection of upf DSCB fit",100,0,1.644608);
   Graph_up18->SetMinimum(6.867411);
   Graph_up18->SetMaximum(632.9198);
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
   
   TH1D *frame_45e09110__70 = new TH1D("frame_45e09110__70","p_T Balance",25,0,2);
   frame_45e09110__70->SetBinContent(1,604.8791);
   frame_45e09110__70->SetMaximum(604.8791);
   frame_45e09110__70->SetEntries(2);
   frame_45e09110__70->SetDirectory(0);
   frame_45e09110__70->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45e09110__70->SetLineColor(ci);
   frame_45e09110__70->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45e09110__70->GetXaxis()->SetLabelFont(42);
   frame_45e09110__70->GetXaxis()->SetTitleOffset(1);
   frame_45e09110__70->GetXaxis()->SetTitleFont(42);
   frame_45e09110__70->GetYaxis()->SetTitle("1/Events");
   frame_45e09110__70->GetYaxis()->SetLabelFont(42);
   frame_45e09110__70->GetYaxis()->SetTitleFont(42);
   frame_45e09110__70->GetZaxis()->SetLabelFont(42);
   frame_45e09110__70->GetZaxis()->SetTitleOffset(1);
   frame_45e09110__70->GetZaxis()->SetTitleFont(42);
   frame_45e09110__70->Draw("AXISSAME");
   
   TH1D *norm_u__71 = new TH1D("norm_u__71","",25,0,2);
   norm_u__71->SetBinContent(3,0.7052468);
   norm_u__71->SetBinContent(4,65.93084);
   norm_u__71->SetBinContent(5,139.2801);
   norm_u__71->SetBinContent(6,221.9291);
   norm_u__71->SetBinContent(7,306.303);
   norm_u__71->SetBinContent(8,432.4181);
   norm_u__71->SetBinContent(9,532.6623);
   norm_u__71->SetBinContent(10,518.0983);
   norm_u__71->SetBinContent(11,535.6123);
   norm_u__71->SetBinContent(12,487.5804);
   norm_u__71->SetBinContent(13,409.8603);
   norm_u__71->SetBinContent(14,290.2082);
   norm_u__71->SetBinContent(15,236.4464);
   norm_u__71->SetBinContent(16,150.1406);
   norm_u__71->SetBinContent(17,116.2164);
   norm_u__71->SetBinContent(18,58.06769);
   norm_u__71->SetBinContent(19,43.55923);
   norm_u__71->SetBinContent(20,28.03652);
   norm_u__71->SetBinContent(21,15.07765);
   norm_u__71->SetBinContent(22,7.39417);
   norm_u__71->SetBinContent(23,7.070186);
   norm_u__71->SetBinContent(24,2.40554);
   norm_u__71->SetBinContent(25,1.421437);
   norm_u__71->SetBinContent(26,6.922342);
   norm_u__71->SetBinError(3,0.6730721);
   norm_u__71->SetBinError(4,5.849666);
   norm_u__71->SetBinError(5,8.559724);
   norm_u__71->SetBinError(6,10.99637);
   norm_u__71->SetBinError(7,13.15214);
   norm_u__71->SetBinError(8,15.89751);
   norm_u__71->SetBinError(9,17.63648);
   norm_u__71->SetBinError(10,17.18386);
   norm_u__71->SetBinError(11,17.58578);
   norm_u__71->SetBinError(12,17.04845);
   norm_u__71->SetBinError(13,15.26521);
   norm_u__71->SetBinError(14,12.70506);
   norm_u__71->SetBinError(15,11.25259);
   norm_u__71->SetBinError(16,8.854758);
   norm_u__71->SetBinError(17,7.558812);
   norm_u__71->SetBinError(18,4.88992);
   norm_u__71->SetBinError(19,4.375099);
   norm_u__71->SetBinError(20,3.350235);
   norm_u__71->SetBinError(21,2.094672);
   norm_u__71->SetBinError(22,1.497862);
   norm_u__71->SetBinError(23,1.447525);
   norm_u__71->SetBinError(24,0.7462471);
   norm_u__71->SetBinError(25,0.3723264);
   norm_u__71->SetBinError(26,0.9709027);
   norm_u__71->SetEntries(18375);
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
   entry=leg->AddEntry("frame_x_u2_45e09110","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.820715 #pm 0.004072","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.265829 #pm 0.003217","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.490000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_45e09110_copy__72 = new TH1D("frame_45e09110_copy__72","p_T Balance",25,0,2);
   frame_45e09110_copy__72->SetBinContent(1,604.8791);
   frame_45e09110_copy__72->SetMaximum(604.8791);
   frame_45e09110_copy__72->SetEntries(2);
   frame_45e09110_copy__72->SetDirectory(0);
   frame_45e09110_copy__72->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45e09110_copy__72->SetLineColor(ci);
   frame_45e09110_copy__72->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45e09110_copy__72->GetXaxis()->SetLabelFont(42);
   frame_45e09110_copy__72->GetXaxis()->SetTitleOffset(1);
   frame_45e09110_copy__72->GetXaxis()->SetTitleFont(42);
   frame_45e09110_copy__72->GetYaxis()->SetTitle("1/Events");
   frame_45e09110_copy__72->GetYaxis()->SetLabelFont(42);
   frame_45e09110_copy__72->GetYaxis()->SetTitleFont(42);
   frame_45e09110_copy__72->GetZaxis()->SetLabelFont(42);
   frame_45e09110_copy__72->GetZaxis()->SetTitleOffset(1);
   frame_45e09110_copy__72->GetZaxis()->SetTitleFont(42);
   frame_45e09110_copy__72->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-68.23155,2.25,614.0839);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_45e009d0__73 = new TH1D("frame_45e009d0__73","p_T Balance",25,0,2);
   frame_45e009d0__73->SetBinContent(1,600.4376);
   frame_45e009d0__73->SetMaximum(600.4376);
   frame_45e009d0__73->SetEntries(2);
   frame_45e009d0__73->SetDirectory(0);
   frame_45e009d0__73->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45e009d0__73->SetLineColor(ci);
   frame_45e009d0__73->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45e009d0__73->GetXaxis()->SetLabelFont(42);
   frame_45e009d0__73->GetXaxis()->SetTitleOffset(1);
   frame_45e009d0__73->GetXaxis()->SetTitleFont(42);
   frame_45e009d0__73->GetYaxis()->SetTitle("1/Events");
   frame_45e009d0__73->GetYaxis()->SetLabelFont(42);
   frame_45e009d0__73->GetYaxis()->SetTitleFont(42);
   frame_45e009d0__73->GetZaxis()->SetLabelFont(42);
   frame_45e009d0__73->GetZaxis()->SetTitleOffset(1);
   frame_45e009d0__73->GetZaxis()->SetTitleFont(42);
   frame_45e009d0__73->Draw("FUNC");
   
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
   0.1108509,
   68.08558,
   167.5633,
   243.1896,
   338.8801,
   454.5146,
   545.832,
   521.5342,
   496.2768,
   423.2049,
   331.9411,
   257.1138,
   167.0213,
   112.5354,
   84.16724,
   55.29221,
   30.03952,
   19.00035,
   11.7734,
   6.380215,
   3.655777,
   2.187205,
   2.409925};
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
   0.06403071,
   5.421907,
   8.896216,
   11.24714,
   13.36437,
   15.79924,
   17.49624,
   17.05499,
   16.70137,
   15.32495,
   13.26264,
   11.77937,
   8.982211,
   7.118248,
   5.942199,
   4.828962,
   3.279746,
   2.484697,
   1.871329,
   1.298444,
   0.8220643,
   0.6155206,
   0.6093642};
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
   0.06403071,
   5.421907,
   8.896216,
   11.24714,
   13.36437,
   15.79924,
   17.49624,
   17.05499,
   16.70137,
   15.32495,
   13.26264,
   11.77937,
   8.982211,
   7.118248,
   5.942199,
   4.828962,
   3.279746,
   2.484697,
   1.871329,
   1.298444,
   0.8220643,
   0.6155206,
   0.6093642};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3019,h_dh_down2_fy3019,h_dh_down2_felx3019,h_dh_down2_fehx3019,h_dh_down2_fely3019,h_dh_down2_fehy3019);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23019 = new TH1F("Graph_h_dh_down23019","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23019->SetMinimum(0);
   Graph_h_dh_down23019->SetMaximum(619.661);
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
   
   Double_t down_fx19[60] = {
   0.01466368,
   0.07189238,
   0.1291211,
   0.1577354,
   0.1863498,
   0.2149641,
   0.2435785,
   0.2721928,
   0.3008072,
   0.3294215,
   0.3580358,
   0.3866502,
   0.4152645,
   0.4438789,
   0.4724932,
   0.5011076,
   0.5297219,
   0.5583363,
   0.5869506,
   0.615565,
   0.6298721,
   0.6441793,
   0.6584865,
   0.6727937,
   0.6871008,
   0.701408,
   0.7157152,
   0.7300224,
   0.7443295,
   0.7586367,
   0.7729439,
   0.7872511,
   0.8015582,
   0.8158654,
   0.8301726,
   0.8444797,
   0.8587869,
   0.8730941,
   0.8874013,
   0.9017084,
   0.9303228,
   0.9589371,
   0.9875515,
   1.016166,
   1.030473,
   1.04478,
   1.059087,
   1.073395,
   1.102009,
   1.130623,
   1.159238,
   1.187852,
   1.216466,
   1.245081,
   1.273695,
   1.302309,
   1.330924,
   1.388152,
   1.445381,
   1.445381};
   Double_t down_fy19[60] = {
   2.644795,
   5.871909,
   12.22841,
   17.22825,
   23.88711,
   32.59392,
   43.76838,
   57.84092,
   75.22474,
   96.2802,
   121.273,
   150.3287,
   183.3879,
   220.166,
   260.1241,
   302.4557,
   346.0938,
   389.7414,
   431.9268,
   471.0798,
   489.0247,
   505.6264,
   520.7045,
   534.0916,
   545.6357,
   555.2039,
   562.6846,
   567.9893,
   571.0551,
   571.8454,
   570.3506,
   566.5886,
   560.6044,
   552.469,
   542.278,
   530.15,
   516.2241,
   500.6572,
   483.6212,
   465.2999,
   425.5751,
   383.0631,
   339.3245,
   296.0147,
   276.1902,
   257.9978,
   241.279,
   225.8927,
   198.6298,
   175.3585,
   155.3976,
   138.1977,
   123.313,
   110.3794,
   99.0979,
   89.22156,
   80.5455,
   66.13849,
   54.81339,
   54.81339};
   graph = new TGraph(60,down_fx19,down_fy19);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down19 = new TH1F("Graph_down19","Projection of downf DSCB fit",100,0,1.588453);
   Graph_down19->SetMinimum(2.380316);
   Graph_down19->SetMaximum(628.7654);
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
   
   TH1D *frame_45e009d0__74 = new TH1D("frame_45e009d0__74","p_T Balance",25,0,2);
   frame_45e009d0__74->SetBinContent(1,600.4376);
   frame_45e009d0__74->SetMaximum(600.4376);
   frame_45e009d0__74->SetEntries(2);
   frame_45e009d0__74->SetDirectory(0);
   frame_45e009d0__74->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45e009d0__74->SetLineColor(ci);
   frame_45e009d0__74->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45e009d0__74->GetXaxis()->SetLabelFont(42);
   frame_45e009d0__74->GetXaxis()->SetTitleOffset(1);
   frame_45e009d0__74->GetXaxis()->SetTitleFont(42);
   frame_45e009d0__74->GetYaxis()->SetTitle("1/Events");
   frame_45e009d0__74->GetYaxis()->SetLabelFont(42);
   frame_45e009d0__74->GetYaxis()->SetTitleFont(42);
   frame_45e009d0__74->GetZaxis()->SetLabelFont(42);
   frame_45e009d0__74->GetZaxis()->SetTitleOffset(1);
   frame_45e009d0__74->GetZaxis()->SetTitleFont(42);
   frame_45e009d0__74->Draw("AXISSAME");
   
   TH1D *norm_d__75 = new TH1D("norm_d__75","",25,0,2);
   norm_d__75->SetBinContent(3,0.1108509);
   norm_d__75->SetBinContent(4,68.08558);
   norm_d__75->SetBinContent(5,167.5633);
   norm_d__75->SetBinContent(6,243.1896);
   norm_d__75->SetBinContent(7,338.8801);
   norm_d__75->SetBinContent(8,454.5146);
   norm_d__75->SetBinContent(9,545.832);
   norm_d__75->SetBinContent(10,521.5342);
   norm_d__75->SetBinContent(11,496.2768);
   norm_d__75->SetBinContent(12,423.2049);
   norm_d__75->SetBinContent(13,331.9411);
   norm_d__75->SetBinContent(14,257.1138);
   norm_d__75->SetBinContent(15,167.0213);
   norm_d__75->SetBinContent(16,112.5354);
   norm_d__75->SetBinContent(17,84.16724);
   norm_d__75->SetBinContent(18,55.29221);
   norm_d__75->SetBinContent(19,30.03952);
   norm_d__75->SetBinContent(20,19.00035);
   norm_d__75->SetBinContent(21,11.7734);
   norm_d__75->SetBinContent(22,6.380215);
   norm_d__75->SetBinContent(23,3.655777);
   norm_d__75->SetBinContent(24,2.187205);
   norm_d__75->SetBinContent(25,2.409925);
   norm_d__75->SetBinContent(26,6.319476);
   norm_d__75->SetBinError(3,0.06403071);
   norm_d__75->SetBinError(4,5.421907);
   norm_d__75->SetBinError(5,8.896216);
   norm_d__75->SetBinError(6,11.24714);
   norm_d__75->SetBinError(7,13.36437);
   norm_d__75->SetBinError(8,15.79924);
   norm_d__75->SetBinError(9,17.49624);
   norm_d__75->SetBinError(10,17.05499);
   norm_d__75->SetBinError(11,16.70137);
   norm_d__75->SetBinError(12,15.32495);
   norm_d__75->SetBinError(13,13.26264);
   norm_d__75->SetBinError(14,11.77937);
   norm_d__75->SetBinError(15,8.982211);
   norm_d__75->SetBinError(16,7.118248);
   norm_d__75->SetBinError(17,5.942199);
   norm_d__75->SetBinError(18,4.828962);
   norm_d__75->SetBinError(19,3.279746);
   norm_d__75->SetBinError(20,2.484697);
   norm_d__75->SetBinError(21,1.871329);
   norm_d__75->SetBinError(22,1.298444);
   norm_d__75->SetBinError(23,0.8220643);
   norm_d__75->SetBinError(24,0.6155206);
   norm_d__75->SetBinError(25,0.6093642);
   norm_d__75->SetBinError(26,1.021865);
   norm_d__75->SetEntries(19193);
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
   entry=leg->AddEntry("frame_x_d2_45e009d0","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.756429 #pm 0.003947","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.226211 #pm 0.003278","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.504000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_45e009d0_copy__76 = new TH1D("frame_45e009d0_copy__76","p_T Balance",25,0,2);
   frame_45e009d0_copy__76->SetBinContent(1,600.4376);
   frame_45e009d0_copy__76->SetMaximum(600.4376);
   frame_45e009d0_copy__76->SetEntries(2);
   frame_45e009d0_copy__76->SetDirectory(0);
   frame_45e009d0_copy__76->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45e009d0_copy__76->SetLineColor(ci);
   frame_45e009d0_copy__76->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45e009d0_copy__76->GetXaxis()->SetLabelFont(42);
   frame_45e009d0_copy__76->GetXaxis()->SetTitleOffset(1);
   frame_45e009d0_copy__76->GetXaxis()->SetTitleFont(42);
   frame_45e009d0_copy__76->GetYaxis()->SetTitle("1/Events");
   frame_45e009d0_copy__76->GetYaxis()->SetLabelFont(42);
   frame_45e009d0_copy__76->GetYaxis()->SetTitleFont(42);
   frame_45e009d0_copy__76->GetZaxis()->SetLabelFont(42);
   frame_45e009d0_copy__76->GetZaxis()->SetTitleOffset(1);
   frame_45e009d0_copy__76->GetZaxis()->SetTitleFont(42);
   frame_45e009d0_copy__76->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-73.98243,2.25,665.8418);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_45e05a70__77 = new TH1D("frame_45e05a70__77","p_T Balance",25,0,2);
   frame_45e05a70__77->SetBinContent(1,651.0453);
   frame_45e05a70__77->SetMaximum(651.0453);
   frame_45e05a70__77->SetEntries(2);
   frame_45e05a70__77->SetDirectory(0);
   frame_45e05a70__77->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45e05a70__77->SetLineColor(ci);
   frame_45e05a70__77->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45e05a70__77->GetXaxis()->SetLabelFont(42);
   frame_45e05a70__77->GetXaxis()->SetTitleOffset(1);
   frame_45e05a70__77->GetXaxis()->SetTitleFont(42);
   frame_45e05a70__77->GetYaxis()->SetTitle("1/Events");
   frame_45e05a70__77->GetYaxis()->SetLabelFont(42);
   frame_45e05a70__77->GetYaxis()->SetTitleFont(42);
   frame_45e05a70__77->GetZaxis()->SetLabelFont(42);
   frame_45e05a70__77->GetZaxis()->SetTitleOffset(1);
   frame_45e05a70__77->GetZaxis()->SetTitleFont(42);
   frame_45e05a70__77->Draw("FUNC");
   
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
   1,
   84,
   226,
   289,
   399,
   547,
   573,
   532,
   490,
   378,
   338,
   257,
   193,
   132,
   73,
   72,
   30,
   17,
   16,
   7,
   4,
   3,
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
   0.8272462,
   9.146873,
   14.54161,
   16.50735,
   19.48124,
   22.89338,
   23.44264,
   22.57054,
   21.64159,
   18.94865,
   17.89157,
   15.53901,
   13.40144,
   11,
   8.524388,
   8.465529,
   5.446522,
   4.082184,
   3.957801,
   2.58147,
   1.914339,
   1.632705,
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
   2.299527,
   10.20155,
   15.54161,
   17.50735,
   20.48124,
   23.89338,
   24.44264,
   23.57054,
   22.64159,
   19.94865,
   18.89157,
   16.53901,
   14.40144,
   12,
   9.583044,
   9.524592,
   6.538046,
   5.203719,
   5.083066,
   3.770281,
   3.162753,
   2.918186,
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
   Graph_h_dh_data23020->SetMaximum(657.1869);
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
   
   Double_t observation_fx20[68] = {
   -0.03929357,
   -0.009672336,
   -0.002267028,
   -0.0004157008,
   0.001435626,
   0.00513828,
   0.0199489,
   0.07919136,
   0.1088126,
   0.1384338,
   0.1680551,
   0.1976763,
   0.2272975,
   0.2569188,
   0.28654,
   0.3013506,
   0.3161612,
   0.3309718,
   0.3457825,
   0.3605931,
   0.3754037,
   0.3902143,
   0.4050249,
   0.4346462,
   0.4642674,
   0.4938886,
   0.5235099,
   0.5531311,
   0.5679417,
   0.5827523,
   0.5975629,
   0.6123736,
   0.6271842,
   0.6419948,
   0.6568054,
   0.671616,
   0.6864266,
   0.7012373,
   0.7160479,
   0.7308585,
   0.7456691,
   0.7604797,
   0.7752903,
   0.790101,
   0.8049116,
   0.8197222,
   0.8345328,
   0.8493434,
   0.864154,
   0.8789647,
   0.8937753,
   0.9085859,
   0.9233965,
   0.9382071,
   0.9678284,
   0.9974496,
   1.027071,
   1.056692,
   1.086313,
   1.115935,
   1.145556,
   1.175177,
   1.204798,
   1.264041,
   1.323283,
   1.382526,
   1.441768,
   1.441768};
   Double_t observation_fy20[68] = {
   0,
   0,
   0,
   0,
   1.69383,
   1.802662,
   2.304928,
   5.843649,
   9.014262,
   13.61438,
   20.13203,
   29.14734,
   41.31731,
   57.34386,
   77.92263,
   90.11769,
   103.6721,
   118.6368,
   135.0461,
   152.9151,
   172.2361,
   192.976,
   215.074,
   262.9501,
   314.7607,
   368.9007,
   423.3117,
   475.5901,
   500.1235,
   523.1511,
   544.3553,
   563.4342,
   580.1087,
   594.1293,
   605.2824,
   613.3955,
   618.3417,
   620.0432,
   618.473,
   613.6561,
   605.6682,
   594.6343,
   580.725,
   564.1526,
   545.1651,
   524.0407,
   501.0803,
   476.6012,
   451.2689,
   427.2816,
   404.8671,
   383.9033,
   364.279,
   345.8928,
   312.4722,
   282.9924,
   256.9085,
   233.7618,
   213.1642,
   194.7861,
   178.3466,
   163.6054,
   150.3562,
   127.6478,
   109.0692,
   93.75092,
   81.02992,
   81.02992};
   graph = new TGraph(68,observation_fx20,observation_fy20);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation20 = new TH1F("Graph_observation20","Projection of obsf DSCB fit",100,-0.1873997,1.589874);
   Graph_observation20->SetMinimum(0);
   Graph_observation20->SetMaximum(682.0475);
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
   
   TH1D *frame_45e05a70__78 = new TH1D("frame_45e05a70__78","p_T Balance",25,0,2);
   frame_45e05a70__78->SetBinContent(1,651.0453);
   frame_45e05a70__78->SetMaximum(651.0453);
   frame_45e05a70__78->SetEntries(2);
   frame_45e05a70__78->SetDirectory(0);
   frame_45e05a70__78->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45e05a70__78->SetLineColor(ci);
   frame_45e05a70__78->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45e05a70__78->GetXaxis()->SetLabelFont(42);
   frame_45e05a70__78->GetXaxis()->SetTitleOffset(1);
   frame_45e05a70__78->GetXaxis()->SetTitleFont(42);
   frame_45e05a70__78->GetYaxis()->SetTitle("1/Events");
   frame_45e05a70__78->GetYaxis()->SetLabelFont(42);
   frame_45e05a70__78->GetYaxis()->SetTitleFont(42);
   frame_45e05a70__78->GetZaxis()->SetLabelFont(42);
   frame_45e05a70__78->GetZaxis()->SetTitleOffset(1);
   frame_45e05a70__78->GetZaxis()->SetTitleFont(42);
   frame_45e05a70__78->Draw("AXISSAME");
   
   TH1D *norm_o__79 = new TH1D("norm_o__79","",25,0,2);
   norm_o__79->SetBinContent(3,1);
   norm_o__79->SetBinContent(4,84);
   norm_o__79->SetBinContent(5,226);
   norm_o__79->SetBinContent(6,289);
   norm_o__79->SetBinContent(7,399);
   norm_o__79->SetBinContent(8,547);
   norm_o__79->SetBinContent(9,573);
   norm_o__79->SetBinContent(10,532);
   norm_o__79->SetBinContent(11,490);
   norm_o__79->SetBinContent(12,378);
   norm_o__79->SetBinContent(13,338);
   norm_o__79->SetBinContent(14,257);
   norm_o__79->SetBinContent(15,193);
   norm_o__79->SetBinContent(16,132);
   norm_o__79->SetBinContent(17,73);
   norm_o__79->SetBinContent(18,72);
   norm_o__79->SetBinContent(19,30);
   norm_o__79->SetBinContent(20,17);
   norm_o__79->SetBinContent(21,16);
   norm_o__79->SetBinContent(22,7);
   norm_o__79->SetBinContent(23,4);
   norm_o__79->SetBinContent(24,3);
   norm_o__79->SetBinContent(25,1);
   norm_o__79->SetBinContent(26,6);
   norm_o__79->SetMinimum(0);
   norm_o__79->SetMaximum(1260.6);
   norm_o__79->SetEntries(4668);
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
   entry=leg->AddEntry("frame_x_o2_45e05a70","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.701560 #pm 0.003806","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.203780 #pm 0.002918","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.219000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_45e05a70_copy__80 = new TH1D("frame_45e05a70_copy__80","p_T Balance",25,0,2);
   frame_45e05a70_copy__80->SetBinContent(1,651.0453);
   frame_45e05a70_copy__80->SetMaximum(651.0453);
   frame_45e05a70_copy__80->SetEntries(2);
   frame_45e05a70_copy__80->SetDirectory(0);
   frame_45e05a70_copy__80->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_45e05a70_copy__80->SetLineColor(ci);
   frame_45e05a70_copy__80->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_45e05a70_copy__80->GetXaxis()->SetLabelFont(42);
   frame_45e05a70_copy__80->GetXaxis()->SetTitleOffset(1);
   frame_45e05a70_copy__80->GetXaxis()->SetTitleFont(42);
   frame_45e05a70_copy__80->GetYaxis()->SetTitle("1/Events");
   frame_45e05a70_copy__80->GetYaxis()->SetLabelFont(42);
   frame_45e05a70_copy__80->GetYaxis()->SetTitleFont(42);
   frame_45e05a70_copy__80->GetZaxis()->SetLabelFont(42);
   frame_45e05a70_copy__80->GetZaxis()->SetTitleOffset(1);
   frame_45e05a70_copy__80->GetZaxis()->SetTitleFont(42);
   frame_45e05a70_copy__80->Draw("sameaxis");
   
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
