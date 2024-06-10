void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_5__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 18:22:49 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-34.26123,2.25,394.0042);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_469ac480__65 = new TH1D("frame_469ac480__65","p_T Balance",25,0,2);
   frame_469ac480__65->SetBinContent(1,351.1776);
   frame_469ac480__65->SetMaximum(351.1776);
   frame_469ac480__65->SetEntries(2);
   frame_469ac480__65->SetDirectory(0);
   frame_469ac480__65->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_469ac480__65->SetLineColor(ci);
   frame_469ac480__65->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_469ac480__65->GetXaxis()->SetLabelFont(42);
   frame_469ac480__65->GetXaxis()->SetTitleOffset(1);
   frame_469ac480__65->GetXaxis()->SetTitleFont(42);
   frame_469ac480__65->GetYaxis()->SetTitle("1/Events");
   frame_469ac480__65->GetYaxis()->SetLabelFont(42);
   frame_469ac480__65->GetYaxis()->SetTitleFont(42);
   frame_469ac480__65->GetZaxis()->SetLabelFont(42);
   frame_469ac480__65->GetZaxis()->SetTitleOffset(1);
   frame_469ac480__65->GetZaxis()->SetTitleFont(42);
   frame_469ac480__65->Draw("FUNC");
   
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
   0.1111361,
   36.31347,
   92.5789,
   131.3117,
   200.7101,
   247.8992,
   313.1931,
   298.5284,
   319.9238,
   267.4221,
   232.34,
   199.184,
   130.05,
   87.35635,
   50.50382,
   36.07183,
   17.16792,
   8.526834,
   7.459463,
   3.244991,
   3.240663,
   0.7952709,
   1.044851};
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
   0.08872784,
   4.084692,
   6.63247,
   7.882558,
   10.19977,
   11.30715,
   12.73598,
   12.39722,
   13.0895,
   12.04592,
   11.1368,
   10.18766,
   7.968271,
   6.200004,
   4.532991,
   3.737931,
   2.350647,
   1.646331,
   1.532119,
   0.9016329,
   0.9306837,
   0.326092,
   0.5546194};
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
   0.08872784,
   4.084692,
   6.63247,
   7.882558,
   10.19977,
   11.30715,
   12.73598,
   12.39722,
   13.0895,
   12.04592,
   11.1368,
   10.18766,
   7.968271,
   6.200004,
   4.532991,
   3.737931,
   2.350647,
   1.646331,
   1.532119,
   0.9016329,
   0.9306837,
   0.326092,
   0.5546194};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3017,h_dh_central2_fy3017,h_dh_central2_felx3017,h_dh_central2_fehx3017,h_dh_central2_fely3017,h_dh_central2_fehy3017);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23017 = new TH1F("Graph_h_dh_central23017","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23017->SetMinimum(0);
   Graph_h_dh_central23017->SetMaximum(366.3146);
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
   0.07921775,
   0.1360738,
   0.1645018,
   0.1929298,
   0.2213578,
   0.2497859,
   0.2782139,
   0.3066419,
   0.3350699,
   0.3634979,
   0.391926,
   0.420354,
   0.448782,
   0.47721,
   0.505638,
   0.5340661,
   0.5909221,
   0.6193501,
   0.6477781,
   0.6762062,
   0.6904202,
   0.7046342,
   0.7188482,
   0.7330622,
   0.7472762,
   0.7614902,
   0.7757042,
   0.7899182,
   0.8041323,
   0.8183463,
   0.8325603,
   0.8467743,
   0.8609883,
   0.8752023,
   0.8894163,
   0.9036303,
   0.9178443,
   0.9320583,
   0.9604864,
   0.9889144,
   1.017342,
   1.04577,
   1.102626,
   1.131054,
   1.159483,
   1.173697,
   1.187911,
   1.202125,
   1.216339,
   1.244767,
   1.273195,
   1.301623,
   1.330051,
   1.358479,
   1.386907,
   1.443763,
   1.500619,
   1.500619};
   Double_t Central_fy17[58] = {
   5.267095,
   9.863305,
   13.23984,
   17.54551,
   22.95474,
   29.64844,
   37.80545,
   47.59156,
   59.14644,
   72.56887,
   87.90127,
   105.1146,
   124.0949,
   144.6332,
   166.4198,
   189.045,
   234.7226,
   256.5572,
   276.845,
   294.9254,
   302.9414,
   310.1778,
   316.5693,
   322.0568,
   326.5893,
   330.1241,
   332.6275,
   334.0758,
   334.4549,
   333.7612,
   332.0014,
   329.1924,
   325.361,
   320.5434,
   314.785,
   308.1392,
   300.6669,
   292.4355,
   273.991,
   253.4344,
   231.4291,
   208.638,
   163.16,
   141.5332,
   121.2065,
   111.6281,
   102.7641,
   94.76265,
   87.52505,
   75.00896,
   64.65225,
   56.02291,
   48.78644,
   42.68157,
   37.50243,
   29.30022,
   23.22274,
   23.22274};
   TGraph *graph = new TGraph(58,Central_fx17,Central_fy17);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central17 = new TH1F("Graph_Central17","Projection of centralf DSCB fit",100,0,1.642759);
   Graph_Central17->SetMinimum(4.740386);
   Graph_Central17->SetMaximum(367.3737);
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
   
   TH1D *frame_469ac480__66 = new TH1D("frame_469ac480__66","p_T Balance",25,0,2);
   frame_469ac480__66->SetBinContent(1,351.1776);
   frame_469ac480__66->SetMaximum(351.1776);
   frame_469ac480__66->SetEntries(2);
   frame_469ac480__66->SetDirectory(0);
   frame_469ac480__66->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_469ac480__66->SetLineColor(ci);
   frame_469ac480__66->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_469ac480__66->GetXaxis()->SetLabelFont(42);
   frame_469ac480__66->GetXaxis()->SetTitleOffset(1);
   frame_469ac480__66->GetXaxis()->SetTitleFont(42);
   frame_469ac480__66->GetYaxis()->SetTitle("1/Events");
   frame_469ac480__66->GetYaxis()->SetLabelFont(42);
   frame_469ac480__66->GetYaxis()->SetTitleFont(42);
   frame_469ac480__66->GetZaxis()->SetLabelFont(42);
   frame_469ac480__66->GetZaxis()->SetTitleOffset(1);
   frame_469ac480__66->GetZaxis()->SetTitleFont(42);
   frame_469ac480__66->Draw("AXISSAME");
   
   TH1D *norm_c__67 = new TH1D("norm_c__67","",25,0,2);
   norm_c__67->SetBinContent(3,0.1111361);
   norm_c__67->SetBinContent(4,36.31346);
   norm_c__67->SetBinContent(5,92.5789);
   norm_c__67->SetBinContent(6,131.3117);
   norm_c__67->SetBinContent(7,200.7101);
   norm_c__67->SetBinContent(8,247.8992);
   norm_c__67->SetBinContent(9,313.1931);
   norm_c__67->SetBinContent(10,298.5284);
   norm_c__67->SetBinContent(11,319.9238);
   norm_c__67->SetBinContent(12,267.4221);
   norm_c__67->SetBinContent(13,232.34);
   norm_c__67->SetBinContent(14,199.184);
   norm_c__67->SetBinContent(15,130.05);
   norm_c__67->SetBinContent(16,87.35636);
   norm_c__67->SetBinContent(17,50.50382);
   norm_c__67->SetBinContent(18,36.07183);
   norm_c__67->SetBinContent(19,17.16792);
   norm_c__67->SetBinContent(20,8.526833);
   norm_c__67->SetBinContent(21,7.459463);
   norm_c__67->SetBinContent(22,3.244991);
   norm_c__67->SetBinContent(23,3.240663);
   norm_c__67->SetBinContent(24,0.7952709);
   norm_c__67->SetBinContent(25,1.044851);
   norm_c__67->SetBinContent(26,2.972008);
   norm_c__67->SetBinError(3,0.08872784);
   norm_c__67->SetBinError(4,4.084692);
   norm_c__67->SetBinError(5,6.63247);
   norm_c__67->SetBinError(6,7.882558);
   norm_c__67->SetBinError(7,10.19977);
   norm_c__67->SetBinError(8,11.30715);
   norm_c__67->SetBinError(9,12.73598);
   norm_c__67->SetBinError(10,12.39722);
   norm_c__67->SetBinError(11,13.0895);
   norm_c__67->SetBinError(12,12.04592);
   norm_c__67->SetBinError(13,11.1368);
   norm_c__67->SetBinError(14,10.18766);
   norm_c__67->SetBinError(15,7.968271);
   norm_c__67->SetBinError(16,6.200004);
   norm_c__67->SetBinError(17,4.532991);
   norm_c__67->SetBinError(18,3.737931);
   norm_c__67->SetBinError(19,2.350647);
   norm_c__67->SetBinError(20,1.646331);
   norm_c__67->SetBinError(21,1.532119);
   norm_c__67->SetBinError(22,0.9016329);
   norm_c__67->SetBinError(23,0.9306837);
   norm_c__67->SetBinError(24,0.326092);
   norm_c__67->SetBinError(25,0.5546194);
   norm_c__67->SetBinError(26,0.484552);
   norm_c__67->SetEntries(11950);
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
   entry=leg->AddEntry("frame_x_c2_469ac480","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.802050 #pm 0.005237","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.250869 #pm 0.004302","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.330000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_469ac480_copy__68 = new TH1D("frame_469ac480_copy__68","p_T Balance",25,0,2);
   frame_469ac480_copy__68->SetBinContent(1,351.1776);
   frame_469ac480_copy__68->SetMaximum(351.1776);
   frame_469ac480_copy__68->SetEntries(2);
   frame_469ac480_copy__68->SetDirectory(0);
   frame_469ac480_copy__68->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_469ac480_copy__68->SetLineColor(ci);
   frame_469ac480_copy__68->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_469ac480_copy__68->GetXaxis()->SetLabelFont(42);
   frame_469ac480_copy__68->GetXaxis()->SetTitleOffset(1);
   frame_469ac480_copy__68->GetXaxis()->SetTitleFont(42);
   frame_469ac480_copy__68->GetYaxis()->SetTitle("1/Events");
   frame_469ac480_copy__68->GetYaxis()->SetLabelFont(42);
   frame_469ac480_copy__68->GetYaxis()->SetTitleFont(42);
   frame_469ac480_copy__68->GetZaxis()->SetLabelFont(42);
   frame_469ac480_copy__68->GetZaxis()->SetTitleOffset(1);
   frame_469ac480_copy__68->GetZaxis()->SetTitleFont(42);
   frame_469ac480_copy__68->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-34.99884,2.25,402.4867);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_469d7460__69 = new TH1D("frame_469d7460__69","p_T Balance",25,0,2);
   frame_469d7460__69->SetBinContent(1,358.7382);
   frame_469d7460__69->SetMaximum(358.7382);
   frame_469d7460__69->SetEntries(2);
   frame_469d7460__69->SetDirectory(0);
   frame_469d7460__69->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_469d7460__69->SetLineColor(ci);
   frame_469d7460__69->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_469d7460__69->GetXaxis()->SetLabelFont(42);
   frame_469d7460__69->GetXaxis()->SetTitleOffset(1);
   frame_469d7460__69->GetXaxis()->SetTitleFont(42);
   frame_469d7460__69->GetYaxis()->SetTitle("1/Events");
   frame_469d7460__69->GetYaxis()->SetLabelFont(42);
   frame_469d7460__69->GetYaxis()->SetTitleFont(42);
   frame_469d7460__69->GetZaxis()->SetLabelFont(42);
   frame_469d7460__69->GetZaxis()->SetTitleOffset(1);
   frame_469d7460__69->GetZaxis()->SetTitleFont(42);
   frame_469d7460__69->Draw("FUNC");
   
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
   0.4038081,
   30.64854,
   87.14733,
   128.3288,
   181.623,
   240.9478,
   307.683,
   318.8329,
   317.2936,
   288.8127,
   260.3768,
   213.7268,
   139.0879,
   91.58474,
   54.88668,
   39.74961,
   17.27969,
   11.5455,
   7.949643,
   4.786281,
   2.584637,
   1.003717,
   0.9077934};
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
   0.376363,
   3.855717,
   6.554692,
   8.038762,
   9.641546,
   11.24825,
   12.69987,
   12.91803,
   13.13911,
   12.66798,
   11.95559,
   10.6742,
   8.495289,
   6.375868,
   4.883438,
   3.986935,
   2.53979,
   1.934912,
   1.603403,
   1.218974,
   0.7892996,
   0.3495363,
   0.5246275};
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
   0.376363,
   3.855717,
   6.554692,
   8.038762,
   9.641546,
   11.24825,
   12.69987,
   12.91803,
   13.13911,
   12.66798,
   11.95559,
   10.6742,
   8.495289,
   6.375868,
   4.883438,
   3.986935,
   2.53979,
   1.934912,
   1.603403,
   1.218974,
   0.7892996,
   0.3495363,
   0.5246275};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3018,h_dh_up2_fy3018,h_dh_up2_felx3018,h_dh_up2_fehx3018,h_dh_up2_fely3018,h_dh_up2_fehy3018);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23018 = new TH1F("Graph_h_dh_up23018","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23018->SetMinimum(0);
   Graph_h_dh_up23018->SetMaximum(364.926);
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
   
   Double_t up_fx18[58] = {
   0.1270555,
   0.1545283,
   0.1820011,
   0.2094739,
   0.2369467,
   0.2644195,
   0.2918923,
   0.3193651,
   0.3468379,
   0.3743107,
   0.4017836,
   0.4292564,
   0.4567292,
   0.484202,
   0.5116748,
   0.5666204,
   0.621566,
   0.6490388,
   0.6765116,
   0.690248,
   0.7039844,
   0.7177208,
   0.7314572,
   0.7451936,
   0.75893,
   0.7726664,
   0.7864029,
   0.8001393,
   0.8138757,
   0.8276121,
   0.8413485,
   0.8550849,
   0.8688213,
   0.8825577,
   0.8962941,
   0.9100305,
   0.9237669,
   0.9375033,
   0.9512397,
   0.9787125,
   1.006185,
   1.033658,
   1.061131,
   1.116077,
   1.143549,
   1.171022,
   1.198495,
   1.212231,
   1.225968,
   1.253441,
   1.280913,
   1.308386,
   1.335859,
   1.363332,
   1.390805,
   1.44575,
   1.500696,
   1.500696};
   Double_t up_fy18[58] = {
   8.153103,
   10.92102,
   14.45548,
   18.90736,
   24.43761,
   31.21157,
   39.39143,
   49.12665,
   60.54269,
   73.72852,
   88.72347,
   105.5044,
   123.9744,
   143.9537,
   165.1743,
   209.8311,
   254.1639,
   274.7766,
   293.5451,
   302.0531,
   309.884,
   316.973,
   323.2605,
   328.6929,
   333.2232,
   336.812,
   339.4276,
   341.0469,
   341.6554,
   341.2477,
   339.8275,
   337.4075,
   334.0089,
   329.6619,
   324.4045,
   318.282,
   311.347,
   303.658,
   295.2785,
   276.7249,
   256.2676,
   234.5139,
   212.0667,
   167.3278,
   146.0023,
   125.8869,
   107.3493,
   99.14939,
   91.71771,
   78.83059,
   68.12948,
   59.18411,
   51.65988,
   45.29427,
   39.87962,
   31.27386,
   24.86919,
   24.86919};
   graph = new TGraph(58,up_fx18,up_fy18);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up18 = new TH1F("Graph_up18","Projection of upf DSCB fit",100,0,1.63806);
   Graph_up18->SetMinimum(7.337792);
   Graph_up18->SetMaximum(375.0056);
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
   
   TH1D *frame_469d7460__70 = new TH1D("frame_469d7460__70","p_T Balance",25,0,2);
   frame_469d7460__70->SetBinContent(1,358.7382);
   frame_469d7460__70->SetMaximum(358.7382);
   frame_469d7460__70->SetEntries(2);
   frame_469d7460__70->SetDirectory(0);
   frame_469d7460__70->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_469d7460__70->SetLineColor(ci);
   frame_469d7460__70->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_469d7460__70->GetXaxis()->SetLabelFont(42);
   frame_469d7460__70->GetXaxis()->SetTitleOffset(1);
   frame_469d7460__70->GetXaxis()->SetTitleFont(42);
   frame_469d7460__70->GetYaxis()->SetTitle("1/Events");
   frame_469d7460__70->GetYaxis()->SetLabelFont(42);
   frame_469d7460__70->GetYaxis()->SetTitleFont(42);
   frame_469d7460__70->GetZaxis()->SetLabelFont(42);
   frame_469d7460__70->GetZaxis()->SetTitleOffset(1);
   frame_469d7460__70->GetZaxis()->SetTitleFont(42);
   frame_469d7460__70->Draw("AXISSAME");
   
   TH1D *norm_u__71 = new TH1D("norm_u__71","",25,0,2);
   norm_u__71->SetBinContent(3,0.4038081);
   norm_u__71->SetBinContent(4,30.64854);
   norm_u__71->SetBinContent(5,87.14733);
   norm_u__71->SetBinContent(6,128.3288);
   norm_u__71->SetBinContent(7,181.6231);
   norm_u__71->SetBinContent(8,240.9478);
   norm_u__71->SetBinContent(9,307.683);
   norm_u__71->SetBinContent(10,318.8329);
   norm_u__71->SetBinContent(11,317.2936);
   norm_u__71->SetBinContent(12,288.8127);
   norm_u__71->SetBinContent(13,260.3768);
   norm_u__71->SetBinContent(14,213.7268);
   norm_u__71->SetBinContent(15,139.0879);
   norm_u__71->SetBinContent(16,91.58474);
   norm_u__71->SetBinContent(17,54.88668);
   norm_u__71->SetBinContent(18,39.74961);
   norm_u__71->SetBinContent(19,17.27969);
   norm_u__71->SetBinContent(20,11.5455);
   norm_u__71->SetBinContent(21,7.949643);
   norm_u__71->SetBinContent(22,4.786281);
   norm_u__71->SetBinContent(23,2.584637);
   norm_u__71->SetBinContent(24,1.003717);
   norm_u__71->SetBinContent(25,0.9077934);
   norm_u__71->SetBinContent(26,3.058193);
   norm_u__71->SetBinError(3,0.376363);
   norm_u__71->SetBinError(4,3.855717);
   norm_u__71->SetBinError(5,6.554692);
   norm_u__71->SetBinError(6,8.038762);
   norm_u__71->SetBinError(7,9.641546);
   norm_u__71->SetBinError(8,11.24825);
   norm_u__71->SetBinError(9,12.69987);
   norm_u__71->SetBinError(10,12.91803);
   norm_u__71->SetBinError(11,13.13911);
   norm_u__71->SetBinError(12,12.66798);
   norm_u__71->SetBinError(13,11.95559);
   norm_u__71->SetBinError(14,10.6742);
   norm_u__71->SetBinError(15,8.495289);
   norm_u__71->SetBinError(16,6.375868);
   norm_u__71->SetBinError(17,4.883438);
   norm_u__71->SetBinError(18,3.986935);
   norm_u__71->SetBinError(19,2.53979);
   norm_u__71->SetBinError(20,1.934912);
   norm_u__71->SetBinError(21,1.603403);
   norm_u__71->SetBinError(22,1.218974);
   norm_u__71->SetBinError(23,0.7892996);
   norm_u__71->SetBinError(24,0.3495363);
   norm_u__71->SetBinError(25,0.5246275);
   norm_u__71->SetBinError(26,0.5161819);
   norm_u__71->SetEntries(11804);
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
   entry=leg->AddEntry("frame_x_u2_469d7460","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.819698 #pm 0.005154","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.256195 #pm 0.004146","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.746000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_469d7460_copy__72 = new TH1D("frame_469d7460_copy__72","p_T Balance",25,0,2);
   frame_469d7460_copy__72->SetBinContent(1,358.7382);
   frame_469d7460_copy__72->SetMaximum(358.7382);
   frame_469d7460_copy__72->SetEntries(2);
   frame_469d7460_copy__72->SetDirectory(0);
   frame_469d7460_copy__72->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_469d7460_copy__72->SetLineColor(ci);
   frame_469d7460_copy__72->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_469d7460_copy__72->GetXaxis()->SetLabelFont(42);
   frame_469d7460_copy__72->GetXaxis()->SetTitleOffset(1);
   frame_469d7460_copy__72->GetXaxis()->SetTitleFont(42);
   frame_469d7460_copy__72->GetYaxis()->SetTitle("1/Events");
   frame_469d7460_copy__72->GetYaxis()->SetLabelFont(42);
   frame_469d7460_copy__72->GetYaxis()->SetTitleFont(42);
   frame_469d7460_copy__72->GetZaxis()->SetLabelFont(42);
   frame_469d7460_copy__72->GetZaxis()->SetTitleOffset(1);
   frame_469d7460_copy__72->GetZaxis()->SetTitleFont(42);
   frame_469d7460_copy__72->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-39.83734,2.25,358.536);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_469c3ee0__73 = new TH1D("frame_469c3ee0__73","p_T Balance",25,0,2);
   frame_469c3ee0__73->SetBinContent(1,350.5685);
   frame_469c3ee0__73->SetMaximum(350.5685);
   frame_469c3ee0__73->SetEntries(2);
   frame_469c3ee0__73->SetDirectory(0);
   frame_469c3ee0__73->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_469c3ee0__73->SetLineColor(ci);
   frame_469c3ee0__73->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_469c3ee0__73->GetXaxis()->SetLabelFont(42);
   frame_469c3ee0__73->GetXaxis()->SetTitleOffset(1);
   frame_469c3ee0__73->GetXaxis()->SetTitleFont(42);
   frame_469c3ee0__73->GetYaxis()->SetTitle("1/Events");
   frame_469c3ee0__73->GetYaxis()->SetLabelFont(42);
   frame_469c3ee0__73->GetYaxis()->SetTitleFont(42);
   frame_469c3ee0__73->GetZaxis()->SetLabelFont(42);
   frame_469c3ee0__73->GetZaxis()->SetTitleOffset(1);
   frame_469c3ee0__73->GetZaxis()->SetTitleFont(42);
   frame_469c3ee0__73->Draw("FUNC");
   
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
   0.03592829,
   41.52874,
   96.67118,
   140.1246,
   200.8494,
   264.0009,
   300.5477,
   306.4199,
   298.3418,
   249.4656,
   213.638,
   175.3551,
   108.2046,
   82.20758,
   46.52699,
   30.32911,
   19.13701,
   11.22054,
   5.163098,
   2.15356,
   2.520208,
   0.8909808,
   1.383039};
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
   0.03592829,
   4.267328,
   6.7282,
   8.080081,
   9.986256,
   11.60704,
   12.28185,
   12.50087,
   12.50694,
   11.50214,
   10.54823,
   9.450608,
   7.092666,
   5.92596,
   4.293519,
   3.281675,
   2.49847,
   2.000101,
   1.218187,
   0.5999375,
   0.827769,
   0.3364223,
   0.5750496};
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
   0.03592829,
   4.267328,
   6.7282,
   8.080081,
   9.986256,
   11.60704,
   12.28185,
   12.50087,
   12.50694,
   11.50214,
   10.54823,
   9.450608,
   7.092666,
   5.92596,
   4.293519,
   3.281675,
   2.49847,
   2.000101,
   1.218187,
   0.5999375,
   0.827769,
   0.3364223,
   0.5750496};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3019,h_dh_down2_fy3019,h_dh_down2_felx3019,h_dh_down2_fehx3019,h_dh_down2_fely3019,h_dh_down2_fehy3019);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23019 = new TH1F("Graph_h_dh_down23019","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23019->SetMinimum(0);
   Graph_h_dh_down23019->SetMaximum(350.8128);
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
   
   Double_t down_fx19[64] = {
   -0.004674643,
   -0.0009246429,
   0.0009503571,
   0.002825357,
   0.01032536,
   0.02532536,
   0.05532536,
   0.1153254,
   0.1453254,
   0.1753254,
   0.2053254,
   0.2353254,
   0.2653254,
   0.2953254,
   0.3253254,
   0.3553254,
   0.3853254,
   0.4153254,
   0.4453254,
   0.4753254,
   0.5053254,
   0.5353254,
   0.5653254,
   0.5953254,
   0.6253254,
   0.6403254,
   0.6553254,
   0.6703254,
   0.6853254,
   0.7003254,
   0.7153254,
   0.7303254,
   0.7453254,
   0.7603254,
   0.7753254,
   0.7903254,
   0.8053254,
   0.8203254,
   0.8353254,
   0.8503254,
   0.8653254,
   0.8803254,
   0.8953254,
   0.9103254,
   0.9253254,
   0.9553254,
   1.015325,
   1.045325,
   1.060325,
   1.075325,
   1.090325,
   1.105325,
   1.135325,
   1.165325,
   1.195325,
   1.225325,
   1.255325,
   1.285325,
   1.315325,
   1.345325,
   1.375325,
   1.435325,
   1.495325,
   1.495325};
   Double_t down_fy19[64] = {
   0,
   0,
   1.501558,
   1.541573,
   1.711483,
   2.103064,
   3.13663,
   6.64186,
   9.429859,
   13.17009,
   18.09426,
   24.45462,
   32.51241,
   42.52121,
   54.7054,
   69.23458,
   86.19541,
   105.5634,
   127.1777,
   150.7219,
   175.7156,
   201.5173,
   227.3435,
   252.3022,
   275.4404,
   286.0266,
   295.8029,
   304.66,
   312.4967,
   319.2218,
   324.7556,
   329.0318,
   331.9984,
   333.6194,
   333.8748,
   332.7615,
   330.2931,
   326.4998,
   321.4278,
   315.1382,
   307.7058,
   299.2177,
   289.7717,
   279.4742,
   268.4384,
   244.6253,
   193.3835,
   167.8311,
   156.1196,
   145.4121,
   135.607,
   126.6146,
   110.7588,
   97.30908,
   85.84033,
   76.0125,
   67.55175,
   60.2361,
   53.88451,
   48.34846,
   43.50546,
   35.50933,
   29.26873,
   29.26873};
   graph = new TGraph(64,down_fx19,down_fy19);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down19 = new TH1F("Graph_down19","Projection of downf DSCB fit",100,-0.1546746,1.645325);
   Graph_down19->SetMinimum(0);
   Graph_down19->SetMaximum(367.2623);
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
   
   TH1D *frame_469c3ee0__74 = new TH1D("frame_469c3ee0__74","p_T Balance",25,0,2);
   frame_469c3ee0__74->SetBinContent(1,350.5685);
   frame_469c3ee0__74->SetMaximum(350.5685);
   frame_469c3ee0__74->SetEntries(2);
   frame_469c3ee0__74->SetDirectory(0);
   frame_469c3ee0__74->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_469c3ee0__74->SetLineColor(ci);
   frame_469c3ee0__74->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_469c3ee0__74->GetXaxis()->SetLabelFont(42);
   frame_469c3ee0__74->GetXaxis()->SetTitleOffset(1);
   frame_469c3ee0__74->GetXaxis()->SetTitleFont(42);
   frame_469c3ee0__74->GetYaxis()->SetTitle("1/Events");
   frame_469c3ee0__74->GetYaxis()->SetLabelFont(42);
   frame_469c3ee0__74->GetYaxis()->SetTitleFont(42);
   frame_469c3ee0__74->GetZaxis()->SetLabelFont(42);
   frame_469c3ee0__74->GetZaxis()->SetTitleOffset(1);
   frame_469c3ee0__74->GetZaxis()->SetTitleFont(42);
   frame_469c3ee0__74->Draw("AXISSAME");
   
   TH1D *norm_d__75 = new TH1D("norm_d__75","",25,0,2);
   norm_d__75->SetBinContent(3,0.03592829);
   norm_d__75->SetBinContent(4,41.52874);
   norm_d__75->SetBinContent(5,96.67118);
   norm_d__75->SetBinContent(6,140.1246);
   norm_d__75->SetBinContent(7,200.8494);
   norm_d__75->SetBinContent(8,264.0009);
   norm_d__75->SetBinContent(9,300.5477);
   norm_d__75->SetBinContent(10,306.4199);
   norm_d__75->SetBinContent(11,298.3418);
   norm_d__75->SetBinContent(12,249.4656);
   norm_d__75->SetBinContent(13,213.638);
   norm_d__75->SetBinContent(14,175.3551);
   norm_d__75->SetBinContent(15,108.2046);
   norm_d__75->SetBinContent(16,82.20758);
   norm_d__75->SetBinContent(17,46.52699);
   norm_d__75->SetBinContent(18,30.32911);
   norm_d__75->SetBinContent(19,19.13701);
   norm_d__75->SetBinContent(20,11.22054);
   norm_d__75->SetBinContent(21,5.163098);
   norm_d__75->SetBinContent(22,2.15356);
   norm_d__75->SetBinContent(23,2.520208);
   norm_d__75->SetBinContent(24,0.8909808);
   norm_d__75->SetBinContent(25,1.383039);
   norm_d__75->SetBinContent(26,2.931186);
   norm_d__75->SetBinError(3,0.03592829);
   norm_d__75->SetBinError(4,4.267328);
   norm_d__75->SetBinError(5,6.7282);
   norm_d__75->SetBinError(6,8.080081);
   norm_d__75->SetBinError(7,9.986256);
   norm_d__75->SetBinError(8,11.60704);
   norm_d__75->SetBinError(9,12.28185);
   norm_d__75->SetBinError(10,12.50087);
   norm_d__75->SetBinError(11,12.50694);
   norm_d__75->SetBinError(12,11.50214);
   norm_d__75->SetBinError(13,10.54823);
   norm_d__75->SetBinError(14,9.450608);
   norm_d__75->SetBinError(15,7.092666);
   norm_d__75->SetBinError(16,5.92596);
   norm_d__75->SetBinError(17,4.293519);
   norm_d__75->SetBinError(18,3.281675);
   norm_d__75->SetBinError(19,2.49847);
   norm_d__75->SetBinError(20,2.000101);
   norm_d__75->SetBinError(21,1.218187);
   norm_d__75->SetBinError(22,0.5999375);
   norm_d__75->SetBinError(23,0.827769);
   norm_d__75->SetBinError(24,0.3364223);
   norm_d__75->SetBinError(25,0.5750496);
   norm_d__75->SetBinError(26,0.4776911);
   norm_d__75->SetEntries(12121);
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
   entry=leg->AddEntry("frame_x_d2_469c3ee0","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.779201 #pm 0.005262","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.240857 #pm 0.004151","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.470000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_469c3ee0_copy__76 = new TH1D("frame_469c3ee0_copy__76","p_T Balance",25,0,2);
   frame_469c3ee0_copy__76->SetBinContent(1,350.5685);
   frame_469c3ee0_copy__76->SetMaximum(350.5685);
   frame_469c3ee0_copy__76->SetEntries(2);
   frame_469c3ee0_copy__76->SetDirectory(0);
   frame_469c3ee0_copy__76->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_469c3ee0_copy__76->SetLineColor(ci);
   frame_469c3ee0_copy__76->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_469c3ee0_copy__76->GetXaxis()->SetLabelFont(42);
   frame_469c3ee0_copy__76->GetXaxis()->SetTitleOffset(1);
   frame_469c3ee0_copy__76->GetXaxis()->SetTitleFont(42);
   frame_469c3ee0_copy__76->GetYaxis()->SetTitle("1/Events");
   frame_469c3ee0_copy__76->GetYaxis()->SetLabelFont(42);
   frame_469c3ee0_copy__76->GetYaxis()->SetTitleFont(42);
   frame_469c3ee0_copy__76->GetZaxis()->SetLabelFont(42);
   frame_469c3ee0_copy__76->GetZaxis()->SetTitleOffset(1);
   frame_469c3ee0_copy__76->GetZaxis()->SetTitleFont(42);
   frame_469c3ee0_copy__76->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-43.37212,2.25,390.3491);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_469e89a0__77 = new TH1D("frame_469e89a0__77","p_T Balance",25,0,2);
   frame_469e89a0__77->SetBinContent(1,381.6747);
   frame_469e89a0__77->SetMaximum(381.6747);
   frame_469e89a0__77->SetEntries(2);
   frame_469e89a0__77->SetDirectory(0);
   frame_469e89a0__77->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_469e89a0__77->SetLineColor(ci);
   frame_469e89a0__77->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_469e89a0__77->GetXaxis()->SetLabelFont(42);
   frame_469e89a0__77->GetXaxis()->SetTitleOffset(1);
   frame_469e89a0__77->GetXaxis()->SetTitleFont(42);
   frame_469e89a0__77->GetYaxis()->SetTitle("1/Events");
   frame_469e89a0__77->GetYaxis()->SetLabelFont(42);
   frame_469e89a0__77->GetYaxis()->SetTitleFont(42);
   frame_469e89a0__77->GetZaxis()->SetLabelFont(42);
   frame_469e89a0__77->GetZaxis()->SetTitleOffset(1);
   frame_469e89a0__77->GetZaxis()->SetTitleFont(42);
   frame_469e89a0__77->Draw("FUNC");
   
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
   48,
   110,
   199,
   248,
   304,
   325,
   311,
   289,
   227,
   213,
   149,
   94,
   66,
   45,
   43,
   21,
   15,
   7,
   5,
   1,
   3,
   0};
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
   6.903979,
   10,
   13.61559,
   15.25595,
   16.94276,
   17.53469,
   17.14228,
   16.50735,
   14.57481,
   14.10308,
   11.71679,
   9.678086,
   8.103403,
   6.683179,
   6.531834,
   4.545807,
   3.82938,
   2.58147,
   2.159691,
   0.8272462,
   1.632705,
   0};
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
   7.97633,
   11,
   14.61559,
   16.25595,
   17.94276,
   18.53469,
   18.14228,
   17.50735,
   15.57481,
   15.10308,
   12.71679,
   10.72977,
   9.165094,
   7.757905,
   7.608278,
   5.655182,
   4.958738,
   3.770281,
   3.382473,
   2.299527,
   2.918186,
   1.147874};
   grae = new TGraphAsymmErrors(25,h_dh_data2_fx3020,h_dh_data2_fy3020,h_dh_data2_felx3020,h_dh_data2_fehx3020,h_dh_data2_fely3020,h_dh_data2_fehy3020);
   grae->SetName("h_dh_data2");
   grae->SetTitle("Histogram of dh_data2_plot__x_o2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_data23020 = new TH1F("Graph_h_dh_data23020","Histogram of dh_data2_plot__x_o2",100,0,2.2);
   Graph_h_dh_data23020->SetMinimum(0);
   Graph_h_dh_data23020->SetMaximum(377.8882);
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
   
   Double_t observation_fx20[61] = {
   -0.003144447,
   0.05380524,
   0.1107549,
   0.1392298,
   0.1677046,
   0.1961795,
   0.2246543,
   0.2531292,
   0.281604,
   0.2958414,
   0.3100788,
   0.3243163,
   0.3385537,
   0.3527911,
   0.3670285,
   0.381266,
   0.3955034,
   0.4239782,
   0.4524531,
   0.5094028,
   0.5378776,
   0.5663524,
   0.5805899,
   0.5948273,
   0.6090647,
   0.6233021,
   0.6375396,
   0.651777,
   0.6660144,
   0.6802518,
   0.6944892,
   0.7087267,
   0.7229641,
   0.7372015,
   0.7514389,
   0.7656764,
   0.7799138,
   0.7941512,
   0.8083886,
   0.822626,
   0.8368635,
   0.8511009,
   0.8653383,
   0.8795757,
   0.8938132,
   0.9080506,
   0.9365254,
   0.9650003,
   0.9934751,
   1.02195,
   1.050425,
   1.0789,
   1.107374,
   1.135849,
   1.164324,
   1.192799,
   1.249749,
   1.306698,
   1.363648,
   1.420598,
   1.420598};
   Double_t observation_fy20[61] = {
   0,
   2.256817,
   5.304235,
   7.895594,
   11.52426,
   16.49328,
   23.14552,
   31.84878,
   42.97192,
   49.54849,
   56.85158,
   64.91144,
   73.75074,
   83.38309,
   93.81151,
   105.0269,
   117.007,
   143.098,
   171.6015,
   232.6453,
   263.0146,
   291.5622,
   304.724,
   316.9193,
   327.9874,
   337.7785,
   346.1573,
   353.0054,
   358.2249,
   361.7401,
   363.4997,
   363.4778,
   361.6748,
   358.1171,
   352.8568,
   345.9699,
   337.555,
   327.7309,
   316.6334,
   304.4125,
   291.2291,
   277.2512,
   262.9925,
   249.5689,
   236.991,
   225.1956,
   203.7263,
   184.7556,
   167.9426,
   152.9993,
   139.6817,
   127.7821,
   117.1231,
   107.5527,
   98.94013,
   91.17267,
   77.79558,
   66.78434,
   57.65415,
   50.03224,
   50.03224};
   graph = new TGraph(61,observation_fx20,observation_fy20);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation20 = new TH1F("Graph_observation20","Projection of obsf DSCB fit",100,-0.1455187,1.562972);
   Graph_observation20->SetMinimum(0);
   Graph_observation20->SetMaximum(399.8496);
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
   
   TH1D *frame_469e89a0__78 = new TH1D("frame_469e89a0__78","p_T Balance",25,0,2);
   frame_469e89a0__78->SetBinContent(1,381.6747);
   frame_469e89a0__78->SetMaximum(381.6747);
   frame_469e89a0__78->SetEntries(2);
   frame_469e89a0__78->SetDirectory(0);
   frame_469e89a0__78->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_469e89a0__78->SetLineColor(ci);
   frame_469e89a0__78->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_469e89a0__78->GetXaxis()->SetLabelFont(42);
   frame_469e89a0__78->GetXaxis()->SetTitleOffset(1);
   frame_469e89a0__78->GetXaxis()->SetTitleFont(42);
   frame_469e89a0__78->GetYaxis()->SetTitle("1/Events");
   frame_469e89a0__78->GetYaxis()->SetLabelFont(42);
   frame_469e89a0__78->GetYaxis()->SetTitleFont(42);
   frame_469e89a0__78->GetZaxis()->SetLabelFont(42);
   frame_469e89a0__78->GetZaxis()->SetTitleOffset(1);
   frame_469e89a0__78->GetZaxis()->SetTitleFont(42);
   frame_469e89a0__78->Draw("AXISSAME");
   
   TH1D *norm_o__79 = new TH1D("norm_o__79","",25,0,2);
   norm_o__79->SetBinContent(4,48);
   norm_o__79->SetBinContent(5,110);
   norm_o__79->SetBinContent(6,199);
   norm_o__79->SetBinContent(7,248);
   norm_o__79->SetBinContent(8,304);
   norm_o__79->SetBinContent(9,325);
   norm_o__79->SetBinContent(10,311);
   norm_o__79->SetBinContent(11,289);
   norm_o__79->SetBinContent(12,227);
   norm_o__79->SetBinContent(13,213);
   norm_o__79->SetBinContent(14,149);
   norm_o__79->SetBinContent(15,94);
   norm_o__79->SetBinContent(16,66);
   norm_o__79->SetBinContent(17,45);
   norm_o__79->SetBinContent(18,43);
   norm_o__79->SetBinContent(19,21);
   norm_o__79->SetBinContent(20,15);
   norm_o__79->SetBinContent(21,7);
   norm_o__79->SetBinContent(22,5);
   norm_o__79->SetBinContent(23,1);
   norm_o__79->SetBinContent(24,3);
   norm_o__79->SetBinContent(26,7);
   norm_o__79->SetMinimum(0);
   norm_o__79->SetMaximum(715);
   norm_o__79->SetEntries(2730);
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
   entry=leg->AddEntry("frame_x_o2_469e89a0","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.701428 #pm 0.004983","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.203133 #pm 0.003824","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.663000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_469e89a0_copy__80 = new TH1D("frame_469e89a0_copy__80","p_T Balance",25,0,2);
   frame_469e89a0_copy__80->SetBinContent(1,381.6747);
   frame_469e89a0_copy__80->SetMaximum(381.6747);
   frame_469e89a0_copy__80->SetEntries(2);
   frame_469e89a0_copy__80->SetDirectory(0);
   frame_469e89a0_copy__80->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_469e89a0_copy__80->SetLineColor(ci);
   frame_469e89a0_copy__80->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_469e89a0_copy__80->GetXaxis()->SetLabelFont(42);
   frame_469e89a0_copy__80->GetXaxis()->SetTitleOffset(1);
   frame_469e89a0_copy__80->GetXaxis()->SetTitleFont(42);
   frame_469e89a0_copy__80->GetYaxis()->SetTitle("1/Events");
   frame_469e89a0_copy__80->GetYaxis()->SetLabelFont(42);
   frame_469e89a0_copy__80->GetYaxis()->SetTitleFont(42);
   frame_469e89a0_copy__80->GetZaxis()->SetLabelFont(42);
   frame_469e89a0_copy__80->GetZaxis()->SetTitleOffset(1);
   frame_469e89a0_copy__80->GetZaxis()->SetTitleFont(42);
   frame_469e89a0_copy__80->Draw("sameaxis");
   
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
