void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_2__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 18:15:35 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-11.11444,2.25,127.816);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_36206e00__17 = new TH1D("frame_36206e00__17","p_T Balance",25,0,2);
   frame_36206e00__17->SetBinContent(1,113.923);
   frame_36206e00__17->SetMaximum(113.923);
   frame_36206e00__17->SetEntries(1);
   frame_36206e00__17->SetDirectory(0);
   frame_36206e00__17->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_36206e00__17->SetLineColor(ci);
   frame_36206e00__17->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_36206e00__17->GetXaxis()->SetLabelFont(42);
   frame_36206e00__17->GetXaxis()->SetTitleOffset(1);
   frame_36206e00__17->GetXaxis()->SetTitleFont(42);
   frame_36206e00__17->GetYaxis()->SetTitle("1/Events");
   frame_36206e00__17->GetYaxis()->SetLabelFont(42);
   frame_36206e00__17->GetYaxis()->SetTitleFont(42);
   frame_36206e00__17->GetZaxis()->SetLabelFont(42);
   frame_36206e00__17->GetZaxis()->SetTitleOffset(1);
   frame_36206e00__17->GetZaxis()->SetTitleFont(42);
   frame_36206e00__17->Draw("FUNC");
   
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
   1.32178,
   4.019692,
   3.488751,
   8.599605,
   8.228834,
   24.3039,
   30.27038,
   53.88508,
   80.45663,
   103.0898,
   87.368,
   85.5285,
   48.5295,
   28.79324,
   12.32623,
   7.398479,
   1.965136,
   0.6249687,
   0.7747611,
   0.2715213,
   0.3195465,
   0.1141099,
   0.06021643,
   0.03107809};
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
   0.5541634,
   1.036946,
   0.7856802,
   1.581664,
   1.510307,
   2.711869,
   2.906637,
   4.072391,
   4.846554,
   5.408295,
   4.774606,
   4.798297,
   3.348248,
   2.677842,
   1.551281,
   1.263368,
   0.537937,
   0.2613016,
   0.2819998,
   0.1338692,
   0.1829252,
   0.07933843,
   0.04263666,
   0.02574194};
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
   0.5541634,
   1.036946,
   0.7856802,
   1.581664,
   1.510307,
   2.711869,
   2.906637,
   4.072391,
   4.846554,
   5.408295,
   4.774606,
   4.798297,
   3.348248,
   2.677842,
   1.551281,
   1.263368,
   0.537937,
   0.2613016,
   0.2819998,
   0.1338692,
   0.1829252,
   0.07933843,
   0.04263666,
   0.02574194};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3005,h_dh_central2_fy3005,h_dh_central2_felx3005,h_dh_central2_fehx3005,h_dh_central2_fely3005,h_dh_central2_fehy3005);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23005 = new TH1F("Graph_h_dh_central23005","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23005->SetMinimum(0);
   Graph_h_dh_central23005->SetMaximum(119.3479);
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
   
   Double_t Central_fx5[59] = {
   0.4319803,
   0.4680404,
   0.5041005,
   0.5221305,
   0.5401606,
   0.5581906,
   0.5762207,
   0.5942507,
   0.6122808,
   0.6212958,
   0.6303108,
   0.6393258,
   0.6483409,
   0.6663709,
   0.684401,
   0.720461,
   0.7384911,
   0.7565211,
   0.7745512,
   0.7925812,
   0.8015962,
   0.8106113,
   0.8196263,
   0.8286413,
   0.8376563,
   0.8466714,
   0.8556864,
   0.8647014,
   0.8737164,
   0.8827314,
   0.8917465,
   0.9007615,
   0.9097765,
   0.9187915,
   0.9278066,
   0.9368216,
   0.9458366,
   0.9548516,
   0.9728817,
   0.9909117,
   1.008942,
   1.026972,
   1.045002,
   1.081062,
   1.099092,
   1.117122,
   1.135152,
   1.153182,
   1.171212,
   1.189242,
   1.207272,
   1.225302,
   1.243332,
   1.261362,
   1.270377,
   1.279392,
   1.297422,
   1.333483,
   1.333483};
   Double_t Central_fy5[59] = {
   15.8033,
   17.90243,
   20.53484,
   22.11427,
   23.91607,
   25.98755,
   28.38994,
   31.20377,
   34.53696,
   36.44246,
   38.53725,
   40.8492,
   43.4118,
   49.14395,
   55.10674,
   67.20953,
   73.10083,
   78.70447,
   83.88072,
   88.49331,
   90.54807,
   92.41541,
   94.08187,
   95.53531,
   96.765,
   97.76178,
   98.51816,
   99.02842,
   99.28871,
   99.29703,
   99.05332,
   98.55945,
   97.81914,
   96.83801,
   95.62342,
   94.18443,
   92.53165,
   90.67717,
   86.41764,
   81.52531,
   76.13216,
   70.37679,
   64.39859,
   52.30305,
   46.42274,
   40.78685,
   35.47277,
   30.53906,
   26.02567,
   21.95502,
   18.33374,
   15.15494,
   12.40061,
   10.05382,
   9.551992,
   9.318378,
   9.053272,
   8.772654,
   8.772654};
   TGraph *graph = new TGraph(59,Central_fx5,Central_fy5);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central5 = new TH1F("Graph_Central5","Projection of centralf DSCB fit",100,0.3418301,1.423633);
   Graph_Central5->SetMinimum(7.895388);
   Graph_Central5->SetMaximum(108.3495);
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
   
   TH1D *frame_36206e00__18 = new TH1D("frame_36206e00__18","p_T Balance",25,0,2);
   frame_36206e00__18->SetBinContent(1,113.923);
   frame_36206e00__18->SetMaximum(113.923);
   frame_36206e00__18->SetEntries(1);
   frame_36206e00__18->SetDirectory(0);
   frame_36206e00__18->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_36206e00__18->SetLineColor(ci);
   frame_36206e00__18->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_36206e00__18->GetXaxis()->SetLabelFont(42);
   frame_36206e00__18->GetXaxis()->SetTitleOffset(1);
   frame_36206e00__18->GetXaxis()->SetTitleFont(42);
   frame_36206e00__18->GetYaxis()->SetTitle("1/Events");
   frame_36206e00__18->GetYaxis()->SetLabelFont(42);
   frame_36206e00__18->GetYaxis()->SetTitleFont(42);
   frame_36206e00__18->GetZaxis()->SetLabelFont(42);
   frame_36206e00__18->GetZaxis()->SetTitleOffset(1);
   frame_36206e00__18->GetZaxis()->SetTitleFont(42);
   frame_36206e00__18->Draw("AXISSAME");
   
   TH1D *norm_c__19 = new TH1D("norm_c__19","",25,0,2);
   norm_c__19->SetBinContent(2,1.32178);
   norm_c__19->SetBinContent(3,4.019692);
   norm_c__19->SetBinContent(4,3.488751);
   norm_c__19->SetBinContent(5,8.599605);
   norm_c__19->SetBinContent(6,8.228834);
   norm_c__19->SetBinContent(7,24.3039);
   norm_c__19->SetBinContent(8,30.27038);
   norm_c__19->SetBinContent(9,53.88508);
   norm_c__19->SetBinContent(10,80.45664);
   norm_c__19->SetBinContent(11,103.0898);
   norm_c__19->SetBinContent(12,87.368);
   norm_c__19->SetBinContent(13,85.5285);
   norm_c__19->SetBinContent(14,48.5295);
   norm_c__19->SetBinContent(15,28.79324);
   norm_c__19->SetBinContent(16,12.32623);
   norm_c__19->SetBinContent(17,7.398479);
   norm_c__19->SetBinContent(18,1.965136);
   norm_c__19->SetBinContent(19,0.6249687);
   norm_c__19->SetBinContent(20,0.7747611);
   norm_c__19->SetBinContent(21,0.2715213);
   norm_c__19->SetBinContent(22,0.3195465);
   norm_c__19->SetBinContent(23,0.1141099);
   norm_c__19->SetBinContent(24,0.06021644);
   norm_c__19->SetBinContent(25,0.03107809);
   norm_c__19->SetBinContent(26,0.135223);
   norm_c__19->SetBinError(2,0.5541634);
   norm_c__19->SetBinError(3,1.036946);
   norm_c__19->SetBinError(4,0.7856802);
   norm_c__19->SetBinError(5,1.581664);
   norm_c__19->SetBinError(6,1.510307);
   norm_c__19->SetBinError(7,2.711869);
   norm_c__19->SetBinError(8,2.906637);
   norm_c__19->SetBinError(9,4.072391);
   norm_c__19->SetBinError(10,4.846554);
   norm_c__19->SetBinError(11,5.408295);
   norm_c__19->SetBinError(12,4.774606);
   norm_c__19->SetBinError(13,4.798297);
   norm_c__19->SetBinError(14,3.348248);
   norm_c__19->SetBinError(15,2.677842);
   norm_c__19->SetBinError(16,1.551281);
   norm_c__19->SetBinError(17,1.263368);
   norm_c__19->SetBinError(18,0.537937);
   norm_c__19->SetBinError(19,0.2613016);
   norm_c__19->SetBinError(20,0.2819998);
   norm_c__19->SetBinError(21,0.1338692);
   norm_c__19->SetBinError(22,0.1829252);
   norm_c__19->SetBinError(23,0.07933843);
   norm_c__19->SetBinError(24,0.04263666);
   norm_c__19->SetBinError(25,0.02574194);
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
   entry=leg->AddEntry("frame_x_c2_36206e00","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.876561 #pm 0.009499","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.172320 #pm 0.009995","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.851000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_36206e00_copy__20 = new TH1D("frame_36206e00_copy__20","p_T Balance",25,0,2);
   frame_36206e00_copy__20->SetBinContent(1,113.923);
   frame_36206e00_copy__20->SetMaximum(113.923);
   frame_36206e00_copy__20->SetEntries(1);
   frame_36206e00_copy__20->SetDirectory(0);
   frame_36206e00_copy__20->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_36206e00_copy__20->SetLineColor(ci);
   frame_36206e00_copy__20->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_36206e00_copy__20->GetXaxis()->SetLabelFont(42);
   frame_36206e00_copy__20->GetXaxis()->SetTitleOffset(1);
   frame_36206e00_copy__20->GetXaxis()->SetTitleFont(42);
   frame_36206e00_copy__20->GetYaxis()->SetTitle("1/Events");
   frame_36206e00_copy__20->GetYaxis()->SetLabelFont(42);
   frame_36206e00_copy__20->GetYaxis()->SetTitleFont(42);
   frame_36206e00_copy__20->GetZaxis()->SetLabelFont(42);
   frame_36206e00_copy__20->GetZaxis()->SetTitleOffset(1);
   frame_36206e00_copy__20->GetZaxis()->SetTitleFont(42);
   frame_36206e00_copy__20->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-16.88121,2.25,127.0671);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_36202300__21 = new TH1D("frame_36202300__21","p_T Balance",25,0,2);
   frame_36202300__21->SetBinContent(1,112.6722);
   frame_36202300__21->SetMinimum(-5.365344);
   frame_36202300__21->SetMaximum(112.6722);
   frame_36202300__21->SetEntries(1);
   frame_36202300__21->SetDirectory(0);
   frame_36202300__21->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_36202300__21->SetLineColor(ci);
   frame_36202300__21->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_36202300__21->GetXaxis()->SetLabelFont(42);
   frame_36202300__21->GetXaxis()->SetTitleOffset(1);
   frame_36202300__21->GetXaxis()->SetTitleFont(42);
   frame_36202300__21->GetYaxis()->SetTitle("1/Events");
   frame_36202300__21->GetYaxis()->SetLabelFont(42);
   frame_36202300__21->GetYaxis()->SetTitleFont(42);
   frame_36202300__21->GetZaxis()->SetLabelFont(42);
   frame_36202300__21->GetZaxis()->SetTitleOffset(1);
   frame_36202300__21->GetZaxis()->SetTitleFont(42);
   frame_36202300__21->Draw("FUNC");
   
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
   0.7544543,
   3.220064,
   3.390391,
   7.73182,
   8.632007,
   21.7275,
   32.00355,
   49.28091,
   77.84115,
   101.8745,
   94.18811,
   87.62907,
   55.63287,
   33.78218,
   14.2973,
   10.11344,
   1.679255,
   0.9395659,
   0.8885629,
   0.2016053,
   0.3119825,
   0.1726243,
   0.07783403,
   0.006022057};
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
   0.3712715,
   0.9584126,
   0.8846983,
   1.43566,
   1.609129,
   2.589286,
   3.063191,
   3.832773,
   4.806914,
   5.432428,
   4.974688,
   4.935853,
   3.717423,
   2.873208,
   1.797964,
   1.521481,
   0.4903401,
   0.3501738,
   0.2942924,
   0.1185888,
   0.1816837,
   0.09556391,
   0.05702214,
   0.006022057};
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
   0.3712715,
   0.9584126,
   0.8846983,
   1.43566,
   1.609129,
   2.589286,
   3.063191,
   3.832773,
   4.806914,
   5.432428,
   4.974688,
   4.935853,
   3.717423,
   2.873208,
   1.797964,
   1.521481,
   0.4903401,
   0.3501738,
   0.2942924,
   0.1185888,
   0.1816837,
   0.09556391,
   0.05702214,
   0.006022057};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3006,h_dh_up2_fy3006,h_dh_up2_felx3006,h_dh_up2_fehx3006,h_dh_up2_fely3006,h_dh_up2_fehy3006);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23006 = new TH1F("Graph_h_dh_up23006","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23006->SetMinimum(-10.73069);
   Graph_h_dh_up23006->SetMaximum(118.0376);
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
   
   Double_t up_fx6[55] = {
   0.4429026,
   0.4610158,
   0.479129,
   0.4972422,
   0.5153554,
   0.5334686,
   0.5515818,
   0.569695,
   0.5878082,
   0.6059214,
   0.6240346,
   0.6421478,
   0.660261,
   0.6964874,
   0.7327138,
   0.750827,
   0.7689402,
   0.7870534,
   0.8051666,
   0.8232798,
   0.8323364,
   0.841393,
   0.8504496,
   0.8595062,
   0.8685628,
   0.8776194,
   0.886676,
   0.8957326,
   0.9047892,
   0.9138458,
   0.9229024,
   0.931959,
   0.9410156,
   0.9500722,
   0.9681854,
   0.9862986,
   1.004412,
   1.022525,
   1.040638,
   1.058751,
   1.094978,
   1.131204,
   1.149317,
   1.167431,
   1.185544,
   1.203657,
   1.22177,
   1.239883,
   1.257997,
   1.27611,
   1.294223,
   1.312336,
   1.330449,
   1.348563,
   1.348563};
   Double_t up_fy6[55] = {
   6.629711,
   8.226156,
   10.11566,
   12.32781,
   14.88924,
   17.8219,
   21.14123,
   24.85427,
   28.95788,
   33.43699,
   38.2633,
   43.39427,
   48.77273,
   59.97231,
   71.1383,
   76.44023,
   81.40204,
   85.90991,
   89.85579,
   93.14158,
   94.51003,
   95.68325,
   96.6535,
   97.41435,
   97.96073,
   98.28897,
   98.39685,
   98.28367,
   97.95016,
   97.39859,
   96.63265,
   95.65744,
   94.47945,
   93.10642,
   89.81218,
   85.85895,
   81.34497,
   76.37841,
   71.07309,
   65.54425,
   54.25974,
   43.33111,
   38.20349,
   33.38112,
   28.90638,
   24.80739,
   21.09907,
   17.78445,
   14.85635,
   12.29925,
   10.09113,
   8.205326,
   6.61221,
   5.280708,
   5.280708};
   graph = new TGraph(55,up_fx6,up_fy6);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up6 = new TH1F("Graph_up6","Projection of upf DSCB fit",100,0.3523366,1.439129);
   Graph_up6->SetMinimum(4.752637);
   Graph_up6->SetMaximum(107.7085);
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
   
   TH1D *frame_36202300__22 = new TH1D("frame_36202300__22","p_T Balance",25,0,2);
   frame_36202300__22->SetBinContent(1,112.6722);
   frame_36202300__22->SetMinimum(-5.365344);
   frame_36202300__22->SetMaximum(112.6722);
   frame_36202300__22->SetEntries(1);
   frame_36202300__22->SetDirectory(0);
   frame_36202300__22->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_36202300__22->SetLineColor(ci);
   frame_36202300__22->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_36202300__22->GetXaxis()->SetLabelFont(42);
   frame_36202300__22->GetXaxis()->SetTitleOffset(1);
   frame_36202300__22->GetXaxis()->SetTitleFont(42);
   frame_36202300__22->GetYaxis()->SetTitle("1/Events");
   frame_36202300__22->GetYaxis()->SetLabelFont(42);
   frame_36202300__22->GetYaxis()->SetTitleFont(42);
   frame_36202300__22->GetZaxis()->SetLabelFont(42);
   frame_36202300__22->GetZaxis()->SetTitleOffset(1);
   frame_36202300__22->GetZaxis()->SetTitleFont(42);
   frame_36202300__22->Draw("AXISSAME");
   
   TH1D *norm_u__23 = new TH1D("norm_u__23","",25,0,2);
   norm_u__23->SetBinContent(2,0.7544543);
   norm_u__23->SetBinContent(3,3.220064);
   norm_u__23->SetBinContent(4,3.390391);
   norm_u__23->SetBinContent(5,7.73182);
   norm_u__23->SetBinContent(6,8.632007);
   norm_u__23->SetBinContent(7,21.7275);
   norm_u__23->SetBinContent(8,32.00355);
   norm_u__23->SetBinContent(9,49.28092);
   norm_u__23->SetBinContent(10,77.84115);
   norm_u__23->SetBinContent(11,101.8745);
   norm_u__23->SetBinContent(12,94.18811);
   norm_u__23->SetBinContent(13,87.62907);
   norm_u__23->SetBinContent(14,55.63286);
   norm_u__23->SetBinContent(15,33.78218);
   norm_u__23->SetBinContent(16,14.2973);
   norm_u__23->SetBinContent(17,10.11344);
   norm_u__23->SetBinContent(18,1.679255);
   norm_u__23->SetBinContent(19,0.9395659);
   norm_u__23->SetBinContent(20,0.8885629);
   norm_u__23->SetBinContent(21,0.2016053);
   norm_u__23->SetBinContent(22,0.3119825);
   norm_u__23->SetBinContent(23,0.1726243);
   norm_u__23->SetBinContent(24,0.07783404);
   norm_u__23->SetBinContent(25,0.006022057);
   norm_u__23->SetBinContent(26,0.1696389);
   norm_u__23->SetBinError(2,0.3712715);
   norm_u__23->SetBinError(3,0.9584126);
   norm_u__23->SetBinError(4,0.8846983);
   norm_u__23->SetBinError(5,1.43566);
   norm_u__23->SetBinError(6,1.609129);
   norm_u__23->SetBinError(7,2.589286);
   norm_u__23->SetBinError(8,3.063191);
   norm_u__23->SetBinError(9,3.832773);
   norm_u__23->SetBinError(10,4.806914);
   norm_u__23->SetBinError(11,5.432428);
   norm_u__23->SetBinError(12,4.974688);
   norm_u__23->SetBinError(13,4.935853);
   norm_u__23->SetBinError(14,3.717423);
   norm_u__23->SetBinError(15,2.873208);
   norm_u__23->SetBinError(16,1.797964);
   norm_u__23->SetBinError(17,1.521481);
   norm_u__23->SetBinError(18,0.4903401);
   norm_u__23->SetBinError(19,0.3501738);
   norm_u__23->SetBinError(20,0.2942924);
   norm_u__23->SetBinError(21,0.1185888);
   norm_u__23->SetBinError(22,0.1816837);
   norm_u__23->SetBinError(23,0.09556391);
   norm_u__23->SetBinError(24,0.05702214);
   norm_u__23->SetBinError(25,0.006022057);
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
   entry=leg->AddEntry("frame_x_u2_36202300","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.886576 #pm 0.008447","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.190990 #pm 0.007235","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","KS Score: 0.844000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_36202300_copy__24 = new TH1D("frame_36202300_copy__24","p_T Balance",25,0,2);
   frame_36202300_copy__24->SetBinContent(1,112.6722);
   frame_36202300_copy__24->SetMinimum(-5.365344);
   frame_36202300_copy__24->SetMaximum(112.6722);
   frame_36202300_copy__24->SetEntries(1);
   frame_36202300_copy__24->SetDirectory(0);
   frame_36202300_copy__24->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_36202300_copy__24->SetLineColor(ci);
   frame_36202300_copy__24->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_36202300_copy__24->GetXaxis()->SetLabelFont(42);
   frame_36202300_copy__24->GetXaxis()->SetTitleOffset(1);
   frame_36202300_copy__24->GetXaxis()->SetTitleFont(42);
   frame_36202300_copy__24->GetYaxis()->SetTitle("1/Events");
   frame_36202300_copy__24->GetYaxis()->SetLabelFont(42);
   frame_36202300_copy__24->GetYaxis()->SetTitleFont(42);
   frame_36202300_copy__24->GetZaxis()->SetLabelFont(42);
   frame_36202300_copy__24->GetZaxis()->SetTitleOffset(1);
   frame_36202300_copy__24->GetZaxis()->SetTitleFont(42);
   frame_36202300_copy__24->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-18.10341,2.25,111.2067);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_361e7c10__25 = new TH1D("frame_361e7c10__25","p_T Balance",25,0,2);
   frame_361e7c10__25->SetBinContent(1,108.6205);
   frame_361e7c10__25->SetMinimum(-5.172404);
   frame_361e7c10__25->SetMaximum(108.6205);
   frame_361e7c10__25->SetEntries(1);
   frame_361e7c10__25->SetDirectory(0);
   frame_361e7c10__25->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_361e7c10__25->SetLineColor(ci);
   frame_361e7c10__25->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_361e7c10__25->GetXaxis()->SetLabelFont(42);
   frame_361e7c10__25->GetXaxis()->SetTitleOffset(1);
   frame_361e7c10__25->GetXaxis()->SetTitleFont(42);
   frame_361e7c10__25->GetYaxis()->SetTitle("1/Events");
   frame_361e7c10__25->GetYaxis()->SetLabelFont(42);
   frame_361e7c10__25->GetYaxis()->SetTitleFont(42);
   frame_361e7c10__25->GetZaxis()->SetLabelFont(42);
   frame_361e7c10__25->GetZaxis()->SetTitleOffset(1);
   frame_361e7c10__25->GetZaxis()->SetTitleFont(42);
   frame_361e7c10__25->Draw("FUNC");
   
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
   1.440723,
   3.418876,
   3.214236,
   8.940245,
   9.529925,
   23.81333,
   32.56078,
   56.96601,
   79.80495,
   98.3064,
   88.21171,
   78.23141,
   45.53554,
   29.58997,
   14.22302,
   7.104348,
   2.819796,
   0.7553616,
   1.08884,
   0.1786216,
   0.2781101,
   0.1151179,
   0.02875021,
   0.03130544};
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
   0.5378518,
   0.9608282,
   0.7006372,
   1.594611,
   1.646724,
   2.666614,
   3.008112,
   4.192719,
   4.765582,
   5.141676,
   4.845277,
   4.522351,
   3.296999,
   2.664059,
   1.753377,
   1.234265,
   0.7480369,
   0.2977129,
   0.3550374,
   0.1161893,
   0.178242,
   0.0800425,
   0.02875021,
   0.02592665};
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
   0.5378518,
   0.9608282,
   0.7006372,
   1.594611,
   1.646724,
   2.666614,
   3.008112,
   4.192719,
   4.765582,
   5.141676,
   4.845277,
   4.522351,
   3.296999,
   2.664059,
   1.753377,
   1.234265,
   0.7480369,
   0.2977129,
   0.3550374,
   0.1161893,
   0.178242,
   0.0800425,
   0.02875021,
   0.02592665};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3007,h_dh_down2_fy3007,h_dh_down2_felx3007,h_dh_down2_fehx3007,h_dh_down2_fely3007,h_dh_down2_fehy3007);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23007 = new TH1F("Graph_h_dh_down23007","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23007->SetMinimum(-10.34481);
   Graph_h_dh_down23007->SetMaximum(113.7929);
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
   
   Double_t down_fx7[59] = {
   0.3566144,
   0.3968751,
   0.4371359,
   0.4572663,
   0.4773967,
   0.4824293,
   0.4874619,
   0.4975271,
   0.5176575,
   0.5377878,
   0.5579182,
   0.5780486,
   0.598179,
   0.6183094,
   0.6384398,
   0.6787005,
   0.6988309,
   0.7189613,
   0.7390917,
   0.7592221,
   0.7793525,
   0.7894177,
   0.7994828,
   0.809548,
   0.8196132,
   0.8296784,
   0.8397436,
   0.8498088,
   0.859874,
   0.8699392,
   0.8800044,
   0.8900696,
   0.9001348,
   0.9102,
   0.9202652,
   0.9303304,
   0.9403955,
   0.9504607,
   0.9605259,
   0.9806563,
   1.000787,
   1.020917,
   1.041047,
   1.081308,
   1.101439,
   1.121569,
   1.141699,
   1.16183,
   1.18196,
   1.202091,
   1.222221,
   1.242351,
   1.262482,
   1.282612,
   1.302742,
   1.322873,
   1.343003,
   1.363134,
   1.363134};
   Double_t down_fy7[59] = {
   11.84974,
   12.06553,
   12.41454,
   12.7194,
   13.35784,
   13.72168,
   14.37937,
   15.8679,
   19.16939,
   22.91237,
   27.09595,
   31.70382,
   36.70216,
   42.03823,
   47.63981,
   59.25699,
   65.04046,
   70.63181,
   75.89094,
   80.67748,
   84.85696,
   86.68019,
   88.30707,
   89.72516,
   90.92351,
   91.89278,
   92.62533,
   93.11537,
   93.35899,
   93.35425,
   93.1012,
   92.60185,
   91.86017,
   90.88203,
   89.67512,
   88.24887,
   86.61428,
   84.78384,
   82.77131,
   78.26056,
   73.21143,
   67.76222,
   62.05391,
   50.40233,
   44.70442,
   39.23044,
   34.06189,
   29.26085,
   24.87013,
   20.91423,
   17.40118,
   14.32479,
   11.6673,
   9.402113,
   7.49641,
   5.913628,
   4.615592,
   3.564296,
   3.564296};
   graph = new TGraph(59,down_fx7,down_fy7);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down7 = new TH1F("Graph_down7","Projection of downf DSCB fit",100,0.2559625,1.463786);
   Graph_down7->SetMinimum(3.207866);
   Graph_down7->SetMaximum(102.3385);
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
   
   TH1D *frame_361e7c10__26 = new TH1D("frame_361e7c10__26","p_T Balance",25,0,2);
   frame_361e7c10__26->SetBinContent(1,108.6205);
   frame_361e7c10__26->SetMinimum(-5.172404);
   frame_361e7c10__26->SetMaximum(108.6205);
   frame_361e7c10__26->SetEntries(1);
   frame_361e7c10__26->SetDirectory(0);
   frame_361e7c10__26->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_361e7c10__26->SetLineColor(ci);
   frame_361e7c10__26->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_361e7c10__26->GetXaxis()->SetLabelFont(42);
   frame_361e7c10__26->GetXaxis()->SetTitleOffset(1);
   frame_361e7c10__26->GetXaxis()->SetTitleFont(42);
   frame_361e7c10__26->GetYaxis()->SetTitle("1/Events");
   frame_361e7c10__26->GetYaxis()->SetLabelFont(42);
   frame_361e7c10__26->GetYaxis()->SetTitleFont(42);
   frame_361e7c10__26->GetZaxis()->SetLabelFont(42);
   frame_361e7c10__26->GetZaxis()->SetTitleOffset(1);
   frame_361e7c10__26->GetZaxis()->SetTitleFont(42);
   frame_361e7c10__26->Draw("AXISSAME");
   
   TH1D *norm_d__27 = new TH1D("norm_d__27","",25,0,2);
   norm_d__27->SetBinContent(2,1.440723);
   norm_d__27->SetBinContent(3,3.418876);
   norm_d__27->SetBinContent(4,3.214236);
   norm_d__27->SetBinContent(5,8.940244);
   norm_d__27->SetBinContent(6,9.529925);
   norm_d__27->SetBinContent(7,23.81333);
   norm_d__27->SetBinContent(8,32.56078);
   norm_d__27->SetBinContent(9,56.96601);
   norm_d__27->SetBinContent(10,79.80496);
   norm_d__27->SetBinContent(11,98.3064);
   norm_d__27->SetBinContent(12,88.21171);
   norm_d__27->SetBinContent(13,78.23142);
   norm_d__27->SetBinContent(14,45.53554);
   norm_d__27->SetBinContent(15,29.58997);
   norm_d__27->SetBinContent(16,14.22302);
   norm_d__27->SetBinContent(17,7.104348);
   norm_d__27->SetBinContent(18,2.819796);
   norm_d__27->SetBinContent(19,0.7553616);
   norm_d__27->SetBinContent(20,1.08884);
   norm_d__27->SetBinContent(21,0.1786216);
   norm_d__27->SetBinContent(22,0.2781101);
   norm_d__27->SetBinContent(23,0.1151179);
   norm_d__27->SetBinContent(24,0.02875021);
   norm_d__27->SetBinContent(25,0.03130544);
   norm_d__27->SetBinContent(26,0.2312986);
   norm_d__27->SetBinError(2,0.5378518);
   norm_d__27->SetBinError(3,0.9608282);
   norm_d__27->SetBinError(4,0.7006372);
   norm_d__27->SetBinError(5,1.594611);
   norm_d__27->SetBinError(6,1.646724);
   norm_d__27->SetBinError(7,2.666614);
   norm_d__27->SetBinError(8,3.008112);
   norm_d__27->SetBinError(9,4.192719);
   norm_d__27->SetBinError(10,4.765582);
   norm_d__27->SetBinError(11,5.141676);
   norm_d__27->SetBinError(12,4.845277);
   norm_d__27->SetBinError(13,4.522351);
   norm_d__27->SetBinError(14,3.296999);
   norm_d__27->SetBinError(15,2.664059);
   norm_d__27->SetBinError(16,1.753377);
   norm_d__27->SetBinError(17,1.234265);
   norm_d__27->SetBinError(18,0.7480369);
   norm_d__27->SetBinError(19,0.2977129);
   norm_d__27->SetBinError(20,0.3550374);
   norm_d__27->SetBinError(21,0.1161893);
   norm_d__27->SetBinError(22,0.178242);
   norm_d__27->SetBinError(23,0.0800425);
   norm_d__27->SetBinError(24,0.02875021);
   norm_d__27->SetBinError(25,0.02592665);
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
   entry=leg->AddEntry("frame_x_d2_361e7c10","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.864715 #pm 0.008544","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.195023 #pm 0.006844","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#KS Score: 0.957000","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TH1D *frame_361e7c10_copy__28 = new TH1D("frame_361e7c10_copy__28","p_T Balance",25,0,2);
   frame_361e7c10_copy__28->SetBinContent(1,108.6205);
   frame_361e7c10_copy__28->SetMinimum(-5.172404);
   frame_361e7c10_copy__28->SetMaximum(108.6205);
   frame_361e7c10_copy__28->SetEntries(1);
   frame_361e7c10_copy__28->SetDirectory(0);
   frame_361e7c10_copy__28->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_361e7c10_copy__28->SetLineColor(ci);
   frame_361e7c10_copy__28->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_361e7c10_copy__28->GetXaxis()->SetLabelFont(42);
   frame_361e7c10_copy__28->GetXaxis()->SetTitleOffset(1);
   frame_361e7c10_copy__28->GetXaxis()->SetTitleFont(42);
   frame_361e7c10_copy__28->GetYaxis()->SetTitle("1/Events");
   frame_361e7c10_copy__28->GetYaxis()->SetLabelFont(42);
   frame_361e7c10_copy__28->GetYaxis()->SetTitleFont(42);
   frame_361e7c10_copy__28->GetZaxis()->SetLabelFont(42);
   frame_361e7c10_copy__28->GetZaxis()->SetTitleOffset(1);
   frame_361e7c10_copy__28->GetZaxis()->SetTitleFont(42);
   frame_361e7c10_copy__28->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-19.04732,2.25,171.4259);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_362029e0__29 = new TH1D("frame_362029e0__29","p_T Balance",25,0,2);
   frame_362029e0__29->SetBinContent(1,167.6164);
   frame_362029e0__29->SetMaximum(167.6164);
   frame_362029e0__29->SetEntries(1);
   frame_362029e0__29->SetDirectory(0);
   frame_362029e0__29->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_362029e0__29->SetLineColor(ci);
   frame_362029e0__29->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_362029e0__29->GetXaxis()->SetLabelFont(42);
   frame_362029e0__29->GetXaxis()->SetTitleOffset(1);
   frame_362029e0__29->GetXaxis()->SetTitleFont(42);
   frame_362029e0__29->GetYaxis()->SetTitle("1/Events");
   frame_362029e0__29->GetYaxis()->SetLabelFont(42);
   frame_362029e0__29->GetYaxis()->SetTitleFont(42);
   frame_362029e0__29->GetZaxis()->SetLabelFont(42);
   frame_362029e0__29->GetZaxis()->SetTitleOffset(1);
   frame_362029e0__29->GetZaxis()->SetTitleFont(42);
   frame_362029e0__29->Draw("FUNC");
   
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
   5,
   12,
   14,
   15,
   26,
   43,
   80,
   105,
   147,
   130,
   96,
   75,
   28,
   16,
   8,
   4,
   1,
   0,
   0,
   0,
   0,
   0,
   1};
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
   2.159691,
   3.415266,
   3.6965,
   3.82938,
   5.066015,
   6.531834,
   8.925539,
   9.759142,
   11.63466,
   10.91271,
   9.780867,
   8.640903,
   5.259711,
   3.957801,
   2.768386,
   1.914339,
   0.8272462,
   0,
   0,
   0,
   0,
   0,
   0.8272462};
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
   3.382473,
   4.559819,
   4.830381,
   4.958738,
   6.164324,
   7.608278,
   9.981567,
   10.75914,
   12.63466,
   11.91271,
   10.83201,
   9.698771,
   6.354446,
   5.083066,
   3.945142,
   3.162753,
   2.299527,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   2.299527};
   grae = new TGraphAsymmErrors(25,h_dh_data2_fx3008,h_dh_data2_fy3008,h_dh_data2_felx3008,h_dh_data2_fehx3008,h_dh_data2_fely3008,h_dh_data2_fehy3008);
   grae->SetName("h_dh_data2");
   grae->SetTitle("Histogram of dh_data2_plot__x_o2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_data23008 = new TH1F("Graph_h_dh_data23008","Histogram of dh_data2_plot__x_o2",100,0,2.2);
   Graph_h_dh_data23008->SetMinimum(0);
   Graph_h_dh_data23008->SetMaximum(175.5981);
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
   
   Double_t observation_fx8[57] = {
   0.4185309,
   0.4548037,
   0.4910765,
   0.5092129,
   0.5273493,
   0.5454857,
   0.5545539,
   0.5636221,
   0.5817585,
   0.5998949,
   0.6180314,
   0.6361678,
   0.6543042,
   0.6724406,
   0.7087134,
   0.7268498,
   0.7449862,
   0.7631226,
   0.781259,
   0.7993954,
   0.8084636,
   0.8175318,
   0.8266,
   0.8356682,
   0.8447364,
   0.8538046,
   0.8628728,
   0.871941,
   0.8810092,
   0.8900774,
   0.8991457,
   0.9082139,
   0.9172821,
   0.9263503,
   0.9354185,
   0.9444867,
   0.9626231,
   0.9807595,
   0.9988959,
   1.017032,
   1.035169,
   1.071442,
   1.089578,
   1.107714,
   1.125851,
   1.143987,
   1.162124,
   1.18026,
   1.198396,
   1.216533,
   1.234669,
   1.252806,
   1.270942,
   1.289078,
   1.307215,
   1.325351,
   1.325351};
   Double_t observation_fy8[57] = {
   20.90415,
   22.0576,
   23.6716,
   24.78111,
   26.24863,
   28.36114,
   29.86455,
   31.93699,
   37.66789,
   44.01782,
   50.91995,
   58.3109,
   66.10187,
   74.17884,
   90.61904,
   98.64898,
   106.3085,
   113.4085,
   119.7638,
   125.201,
   127.5263,
   129.5664,
   131.3063,
   132.7331,
   133.8361,
   134.6072,
   135.0403,
   135.1324,
   134.8826,
   134.2929,
   133.3677,
   132.114,
   130.5412,
   128.661,
   126.4873,
   124.0359,
   118.3723,
   111.8292,
   104.5833,
   96.82152,
   88.73269,
   72.29597,
   64.27361,
   56.56575,
   49.28068,
   42.5013,
   36.28523,
   30.66619,
   25.65619,
   21.24842,
   17.42061,
   14.13847,
   11.3591,
   9.034155,
   7.112683,
   5.543469,
   5.543469};
   graph = new TGraph(57,observation_fx8,observation_fy8);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation8 = new TH1F("Graph_observation8","Projection of obsf DSCB fit",100,0.3278488,1.416033);
   Graph_observation8->SetMinimum(4.989122);
   Graph_observation8->SetMaximum(148.0913);
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
   
   TH1D *frame_362029e0__30 = new TH1D("frame_362029e0__30","p_T Balance",25,0,2);
   frame_362029e0__30->SetBinContent(1,167.6164);
   frame_362029e0__30->SetMaximum(167.6164);
   frame_362029e0__30->SetEntries(1);
   frame_362029e0__30->SetDirectory(0);
   frame_362029e0__30->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_362029e0__30->SetLineColor(ci);
   frame_362029e0__30->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_362029e0__30->GetXaxis()->SetLabelFont(42);
   frame_362029e0__30->GetXaxis()->SetTitleOffset(1);
   frame_362029e0__30->GetXaxis()->SetTitleFont(42);
   frame_362029e0__30->GetYaxis()->SetTitle("1/Events");
   frame_362029e0__30->GetYaxis()->SetLabelFont(42);
   frame_362029e0__30->GetYaxis()->SetTitleFont(42);
   frame_362029e0__30->GetZaxis()->SetLabelFont(42);
   frame_362029e0__30->GetZaxis()->SetTitleOffset(1);
   frame_362029e0__30->GetZaxis()->SetTitleFont(42);
   frame_362029e0__30->Draw("AXISSAME");
   
   TH1D *norm_o__31 = new TH1D("norm_o__31","",25,0,2);
   norm_o__31->SetBinContent(3,5);
   norm_o__31->SetBinContent(4,12);
   norm_o__31->SetBinContent(5,14);
   norm_o__31->SetBinContent(6,15);
   norm_o__31->SetBinContent(7,26);
   norm_o__31->SetBinContent(8,43);
   norm_o__31->SetBinContent(9,80);
   norm_o__31->SetBinContent(10,105);
   norm_o__31->SetBinContent(11,147);
   norm_o__31->SetBinContent(12,130);
   norm_o__31->SetBinContent(13,96);
   norm_o__31->SetBinContent(14,75);
   norm_o__31->SetBinContent(15,28);
   norm_o__31->SetBinContent(16,16);
   norm_o__31->SetBinContent(17,8);
   norm_o__31->SetBinContent(18,4);
   norm_o__31->SetBinContent(19,1);
   norm_o__31->SetBinContent(25,1);
   norm_o__31->SetMinimum(0);
   norm_o__31->SetMaximum(323.4);
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
   entry=leg->AddEntry("frame_x_o2_362029e0","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.866047 #pm 0.007248","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.168992 #pm 0.006893","");
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
   
   TH1D *frame_362029e0_copy__32 = new TH1D("frame_362029e0_copy__32","p_T Balance",25,0,2);
   frame_362029e0_copy__32->SetBinContent(1,167.6164);
   frame_362029e0_copy__32->SetMaximum(167.6164);
   frame_362029e0_copy__32->SetEntries(1);
   frame_362029e0_copy__32->SetDirectory(0);
   frame_362029e0_copy__32->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_362029e0_copy__32->SetLineColor(ci);
   frame_362029e0_copy__32->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_362029e0_copy__32->GetXaxis()->SetLabelFont(42);
   frame_362029e0_copy__32->GetXaxis()->SetTitleOffset(1);
   frame_362029e0_copy__32->GetXaxis()->SetTitleFont(42);
   frame_362029e0_copy__32->GetYaxis()->SetTitle("1/Events");
   frame_362029e0_copy__32->GetYaxis()->SetLabelFont(42);
   frame_362029e0_copy__32->GetYaxis()->SetTitleFont(42);
   frame_362029e0_copy__32->GetZaxis()->SetLabelFont(42);
   frame_362029e0_copy__32->GetZaxis()->SetTitleOffset(1);
   frame_362029e0_copy__32->GetZaxis()->SetTitleFont(42);
   frame_362029e0_copy__32->Draw("sameaxis");
   
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
