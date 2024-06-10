void DataAndMC_passMVAID_iso_WP80_Central_pTlead_over_rest_alpha_4__Fit()
{
//=========Macro generated from canvas: cvs/
//=========  (Wed Mar 20 16:39:42 2024) by ROOT version 6.24/07
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
   pad_up->Range(-0.25,-10.58851,2.25,121.7679);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_40615e40__49 = new TH1D("frame_40615e40__49","p_T Balance",25,0,2);
   frame_40615e40__49->SetBinContent(1,108.5322);
   frame_40615e40__49->SetMaximum(108.5322);
   frame_40615e40__49->SetEntries(1);
   frame_40615e40__49->SetDirectory(0);
   frame_40615e40__49->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_40615e40__49->SetLineColor(ci);
   frame_40615e40__49->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40615e40__49->GetXaxis()->SetLabelFont(42);
   frame_40615e40__49->GetXaxis()->SetTitleOffset(1);
   frame_40615e40__49->GetXaxis()->SetTitleFont(42);
   frame_40615e40__49->GetYaxis()->SetTitle("1/Events");
   frame_40615e40__49->GetYaxis()->SetLabelFont(42);
   frame_40615e40__49->GetYaxis()->SetTitleFont(42);
   frame_40615e40__49->GetZaxis()->SetLabelFont(42);
   frame_40615e40__49->GetZaxis()->SetTitleOffset(1);
   frame_40615e40__49->GetZaxis()->SetTitleFont(42);
   frame_40615e40__49->Draw("FUNC");
   
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
   2.88653,
   10.22199,
   20.91876,
   31.54222,
   37.78397,
   61.75039,
   82.88341,
   81.29472,
   96.83368,
   82.47614,
   69.27886,
   53.18334,
   34.50411,
   18.12184,
   16.08553,
   5.555349,
   2.781589,
   1.903256,
   0.793009,
   0.1774472,
   0.2598269,
   0.06068435,
   0.728779};
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
   0.848527,
   1.947786,
   3.168368,
   3.58512,
   4.159616,
   5.172261,
   5.986345,
   5.952299,
   6.530343,
   5.964326,
   5.32715,
   4.739133,
   3.717179,
   2.584986,
   2.305127,
   1.41239,
   0.911898,
   0.7052386,
   0.4276578,
   0.1371939,
   0.195403,
   0.06068434,
   0.4380947};
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
   0.848527,
   1.947786,
   3.168368,
   3.58512,
   4.159616,
   5.172261,
   5.986345,
   5.952299,
   6.530343,
   5.964326,
   5.32715,
   4.739133,
   3.717179,
   2.584986,
   2.305127,
   1.41239,
   0.911898,
   0.7052386,
   0.4276578,
   0.1371939,
   0.195403,
   0.06068434,
   0.4380947};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(25,h_dh_central2_fx3013,h_dh_central2_fy3013,h_dh_central2_felx3013,h_dh_central2_fehx3013,h_dh_central2_fely3013,h_dh_central2_fehy3013);
   grae->SetName("h_dh_central2");
   grae->SetTitle("Histogram of dh_central2_plot__x_c2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_central23013 = new TH1F("Graph_h_dh_central23013","Histogram of dh_central2_plot__x_c2",100,0,2.2);
   Graph_h_dh_central23013->SetMinimum(0);
   Graph_h_dh_central23013->SetMaximum(113.7004);
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
   
   Double_t Central_fx13[59] = {
   0.1877443,
   0.2129261,
   0.225517,
   0.2381079,
   0.2632897,
   0.2884716,
   0.3136534,
   0.3388352,
   0.364017,
   0.3891988,
   0.4143807,
   0.4395625,
   0.4647443,
   0.4899261,
   0.5151079,
   0.5402898,
   0.5906534,
   0.6158352,
   0.6410171,
   0.6661989,
   0.6913807,
   0.7165625,
   0.7291534,
   0.7417443,
   0.7543353,
   0.7669262,
   0.7795171,
   0.792108,
   0.8046989,
   0.8172898,
   0.8298807,
   0.8424716,
   0.8550625,
   0.8676535,
   0.8802444,
   0.8928353,
   0.9054262,
   0.9180171,
   0.9431989,
   0.9683807,
   0.9935626,
   1.018744,
   1.043926,
   1.09429,
   1.119472,
   1.144653,
   1.169835,
   1.195017,
   1.220199,
   1.245381,
   1.270563,
   1.295744,
   1.320926,
   1.346108,
   1.37129,
   1.396472,
   1.421654,
   1.446835,
   1.446835};
   Double_t Central_fy13[59] = {
   5.700647,
   5.894486,
   6.088011,
   6.625261,
   8.27778,
   10.24034,
   12.54307,
   15.21189,
   18.26635,
   21.7175,
   25.56568,
   29.79849,
   34.38908,
   39.29491,
   44.45713,
   49.80077,
   60.65876,
   65.95631,
   71.00823,
   75.69207,
   79.888,
   83.48378,
   85.02486,
   86.37978,
   87.53881,
   88.49353,
   89.23696,
   89.76362,
   90.06962,
   90.15268,
   90.01219,
   89.64919,
   89.06637,
   88.26804,
   87.26007,
   86.04983,
   84.64608,
   83.05887,
   79.38006,
   75.11492,
   70.37696,
   65.28662,
   59.9663,
   49.10681,
   43.78175,
   38.64861,
   33.78035,
   29.2337,
   25.04914,
   21.25159,
   17.85169,
   14.84761,
   12.2271,
   9.969645,
   8.048692,
   6.433693,
   5.091958,
   3.990238,
   3.990238};
   TGraph *graph = new TGraph(59,Central_fx13,Central_fy13);
   graph->SetName("Central");
   graph->SetTitle("Projection of centralf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(2);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Central13 = new TH1F("Graph_Central13","Projection of centralf DSCB fit",100,0.06183515,1.572744);
   Graph_Central13->SetMinimum(3.591214);
   Graph_Central13->SetMaximum(98.76893);
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
   
   TH1D *frame_40615e40__50 = new TH1D("frame_40615e40__50","p_T Balance",25,0,2);
   frame_40615e40__50->SetBinContent(1,108.5322);
   frame_40615e40__50->SetMaximum(108.5322);
   frame_40615e40__50->SetEntries(1);
   frame_40615e40__50->SetDirectory(0);
   frame_40615e40__50->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40615e40__50->SetLineColor(ci);
   frame_40615e40__50->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40615e40__50->GetXaxis()->SetLabelFont(42);
   frame_40615e40__50->GetXaxis()->SetTitleOffset(1);
   frame_40615e40__50->GetXaxis()->SetTitleFont(42);
   frame_40615e40__50->GetYaxis()->SetTitle("1/Events");
   frame_40615e40__50->GetYaxis()->SetLabelFont(42);
   frame_40615e40__50->GetYaxis()->SetTitleFont(42);
   frame_40615e40__50->GetZaxis()->SetLabelFont(42);
   frame_40615e40__50->GetZaxis()->SetTitleOffset(1);
   frame_40615e40__50->GetZaxis()->SetTitleFont(42);
   frame_40615e40__50->Draw("AXISSAME");
   
   TH1D *norm_c__51 = new TH1D("norm_c__51","",25,0,2);
   norm_c__51->SetBinContent(3,2.88653);
   norm_c__51->SetBinContent(4,10.22199);
   norm_c__51->SetBinContent(5,20.91876);
   norm_c__51->SetBinContent(6,31.54222);
   norm_c__51->SetBinContent(7,37.78397);
   norm_c__51->SetBinContent(8,61.75039);
   norm_c__51->SetBinContent(9,82.88341);
   norm_c__51->SetBinContent(10,81.29472);
   norm_c__51->SetBinContent(11,96.83368);
   norm_c__51->SetBinContent(12,82.47613);
   norm_c__51->SetBinContent(13,69.27886);
   norm_c__51->SetBinContent(14,53.18334);
   norm_c__51->SetBinContent(15,34.50411);
   norm_c__51->SetBinContent(16,18.12184);
   norm_c__51->SetBinContent(17,16.08553);
   norm_c__51->SetBinContent(18,5.555349);
   norm_c__51->SetBinContent(19,2.781589);
   norm_c__51->SetBinContent(20,1.903256);
   norm_c__51->SetBinContent(21,0.793009);
   norm_c__51->SetBinContent(22,0.1774472);
   norm_c__51->SetBinContent(23,0.2598269);
   norm_c__51->SetBinContent(24,0.06068434);
   norm_c__51->SetBinContent(25,0.7287789);
   norm_c__51->SetBinContent(26,0.5299399);
   norm_c__51->SetBinError(3,0.848527);
   norm_c__51->SetBinError(4,1.947786);
   norm_c__51->SetBinError(5,3.168368);
   norm_c__51->SetBinError(6,3.58512);
   norm_c__51->SetBinError(7,4.159616);
   norm_c__51->SetBinError(8,5.172261);
   norm_c__51->SetBinError(9,5.986345);
   norm_c__51->SetBinError(10,5.952299);
   norm_c__51->SetBinError(11,6.530343);
   norm_c__51->SetBinError(12,5.964326);
   norm_c__51->SetBinError(13,5.32715);
   norm_c__51->SetBinError(14,4.739133);
   norm_c__51->SetBinError(15,3.717179);
   norm_c__51->SetBinError(16,2.584986);
   norm_c__51->SetBinError(17,2.305127);
   norm_c__51->SetBinError(18,1.41239);
   norm_c__51->SetBinError(19,0.911898);
   norm_c__51->SetBinError(20,0.7052386);
   norm_c__51->SetBinError(21,0.4276578);
   norm_c__51->SetBinError(22,0.1371939);
   norm_c__51->SetBinError(23,0.195403);
   norm_c__51->SetBinError(24,0.06068434);
   norm_c__51->SetBinError(25,0.4380947);
   norm_c__51->SetBinError(26,0.2226858);
   norm_c__51->SetEntries(2908);
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
   entry=leg->AddEntry("frame_x_c2_40615e40","Central Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.815673 #pm 0.009834","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.252760 #pm 0.007775","");
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
   
   TH1D *frame_40615e40_copy__52 = new TH1D("frame_40615e40_copy__52","p_T Balance",25,0,2);
   frame_40615e40_copy__52->SetBinContent(1,108.5322);
   frame_40615e40_copy__52->SetMaximum(108.5322);
   frame_40615e40_copy__52->SetEntries(1);
   frame_40615e40_copy__52->SetDirectory(0);
   frame_40615e40_copy__52->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40615e40_copy__52->SetLineColor(ci);
   frame_40615e40_copy__52->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40615e40_copy__52->GetXaxis()->SetLabelFont(42);
   frame_40615e40_copy__52->GetXaxis()->SetTitleOffset(1);
   frame_40615e40_copy__52->GetXaxis()->SetTitleFont(42);
   frame_40615e40_copy__52->GetYaxis()->SetTitle("1/Events");
   frame_40615e40_copy__52->GetYaxis()->SetLabelFont(42);
   frame_40615e40_copy__52->GetYaxis()->SetTitleFont(42);
   frame_40615e40_copy__52->GetZaxis()->SetLabelFont(42);
   frame_40615e40_copy__52->GetZaxis()->SetTitleOffset(1);
   frame_40615e40_copy__52->GetZaxis()->SetTitleFont(42);
   frame_40615e40_copy__52->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-16.34644,2.25,123.0418);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetBottomMargin(0.08);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_4061da20__53 = new TH1D("frame_4061da20__53","p_T Balance",25,0,2);
   frame_4061da20__53->SetBinContent(1,109.103);
   frame_4061da20__53->SetMinimum(-5.195379);
   frame_4061da20__53->SetMaximum(109.103);
   frame_4061da20__53->SetEntries(1);
   frame_4061da20__53->SetDirectory(0);
   frame_4061da20__53->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4061da20__53->SetLineColor(ci);
   frame_4061da20__53->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4061da20__53->GetXaxis()->SetLabelFont(42);
   frame_4061da20__53->GetXaxis()->SetTitleOffset(1);
   frame_4061da20__53->GetXaxis()->SetTitleFont(42);
   frame_4061da20__53->GetYaxis()->SetTitle("1/Events");
   frame_4061da20__53->GetYaxis()->SetLabelFont(42);
   frame_4061da20__53->GetYaxis()->SetTitleFont(42);
   frame_4061da20__53->GetZaxis()->SetLabelFont(42);
   frame_4061da20__53->GetZaxis()->SetTitleOffset(1);
   frame_4061da20__53->GetZaxis()->SetTitleFont(42);
   frame_4061da20__53->Draw("FUNC");
   
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
   3.486598,
   9.552779,
   14.96528,
   32.76069,
   38.3136,
   59.18113,
   85.70733,
   88.32848,
   97.24225,
   86.36143,
   72.00243,
   53.32842,
   37.15163,
   24.20832,
   15.09331,
   7.895865,
   2.581144,
   1.056837,
   1.861485,
   0.280826,
   0.324072,
   0.0603851,
   0.6543078};
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
   0.990027,
   1.873982,
   2.546077,
   3.768301,
   4.177686,
   5.03642,
   6.283075,
   6.33211,
   6.665332,
   6.174295,
   5.408936,
   4.819857,
   3.794395,
   3.083618,
   2.22801,
   1.730201,
   0.9189327,
   0.3735526,
   0.7556671,
   0.1509852,
   0.2051838,
   0.06038511,
   0.4133917};
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
   0.990027,
   1.873982,
   2.546077,
   3.768301,
   4.177686,
   5.03642,
   6.283075,
   6.33211,
   6.665332,
   6.174295,
   5.408936,
   4.819857,
   3.794395,
   3.083618,
   2.22801,
   1.730201,
   0.9189327,
   0.3735526,
   0.7556671,
   0.1509852,
   0.2051838,
   0.06038511,
   0.4133917};
   grae = new TGraphAsymmErrors(25,h_dh_up2_fx3014,h_dh_up2_fy3014,h_dh_up2_felx3014,h_dh_up2_fehx3014,h_dh_up2_fely3014,h_dh_up2_fehy3014);
   grae->SetName("h_dh_up2");
   grae->SetTitle("Histogram of dh_up2_plot__x_u2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_up23014 = new TH1F("Graph_h_dh_up23014","Histogram of dh_up2_plot__x_u2",100,0,2.2);
   Graph_h_dh_up23014->SetMinimum(-10.39076);
   Graph_h_dh_up23014->SetMaximum(114.2983);
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
   0.1673772,
   0.1933291,
   0.219281,
   0.2452329,
   0.2711848,
   0.2971367,
   0.3230886,
   0.3490405,
   0.3749924,
   0.4009443,
   0.4268962,
   0.4528481,
   0.4788,
   0.5047519,
   0.5307038,
   0.5826076,
   0.6345114,
   0.6604633,
   0.6864152,
   0.7123671,
   0.7253431,
   0.738319,
   0.751295,
   0.7642709,
   0.7772469,
   0.7902228,
   0.8031988,
   0.8161747,
   0.8291507,
   0.8421266,
   0.8551026,
   0.8680785,
   0.8810544,
   0.8940304,
   0.9070063,
   0.9199823,
   0.9329582,
   0.9459342,
   0.9718861,
   0.997838,
   1.02379,
   1.049742,
   1.101646,
   1.127597,
   1.153549,
   1.179501,
   1.205453,
   1.231405,
   1.257357,
   1.283309,
   1.309261,
   1.335213,
   1.361165,
   1.387116,
   1.413068,
   1.43902,
   1.464972,
   1.464972};
   Double_t up_fy14[58] = {
   2.928893,
   3.826979,
   4.946982,
   6.326397,
   8.003948,
   10.01807,
   12.40496,
   15.19632,
   18.41677,
   22.08107,
   26.19139,
   30.73469,
   35.6805,
   40.97932,
   46.56187,
   58.20455,
   69.69644,
   75.0473,
   79.945,
   84.25183,
   86.14356,
   87.84139,
   89.3323,
   90.60471,
   91.64863,
   92.4558,
   93.01977,
   93.33602,
   93.40202,
   93.21723,
   92.78314,
   92.10324,
   91.18296,
   90.02961,
   88.65231,
   87.0618,
   85.27038,
   83.29169,
   78.83289,
   73.81507,
   68.37769,
   62.66363,
   50.95809,
   45.21782,
   39.69518,
   34.47449,
   29.62031,
   25.17753,
   21.17232,
   17.61391,
   14.49688,
   11.80389,
   9.508405,
   7.577429,
   5.974037,
   4.659568,
   3.595466,
   3.595466};
   graph = new TGraph(58,up_fx14,up_fy14);
   graph->SetName("up");
   graph->SetTitle("Projection of upf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetLineWidth(2);
   
   TH1F *Graph_up14 = new TH1F("Graph_up14","Projection of upf DSCB fit",100,0.03761773,1.594732);
   Graph_up14->SetMinimum(2.636004);
   Graph_up14->SetMaximum(102.4493);
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
   
   TH1D *frame_4061da20__54 = new TH1D("frame_4061da20__54","p_T Balance",25,0,2);
   frame_4061da20__54->SetBinContent(1,109.103);
   frame_4061da20__54->SetMinimum(-5.195379);
   frame_4061da20__54->SetMaximum(109.103);
   frame_4061da20__54->SetEntries(1);
   frame_4061da20__54->SetDirectory(0);
   frame_4061da20__54->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4061da20__54->SetLineColor(ci);
   frame_4061da20__54->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4061da20__54->GetXaxis()->SetLabelFont(42);
   frame_4061da20__54->GetXaxis()->SetTitleOffset(1);
   frame_4061da20__54->GetXaxis()->SetTitleFont(42);
   frame_4061da20__54->GetYaxis()->SetTitle("1/Events");
   frame_4061da20__54->GetYaxis()->SetLabelFont(42);
   frame_4061da20__54->GetYaxis()->SetTitleFont(42);
   frame_4061da20__54->GetZaxis()->SetLabelFont(42);
   frame_4061da20__54->GetZaxis()->SetTitleOffset(1);
   frame_4061da20__54->GetZaxis()->SetTitleFont(42);
   frame_4061da20__54->Draw("AXISSAME");
   
   TH1D *norm_u__55 = new TH1D("norm_u__55","",25,0,2);
   norm_u__55->SetBinContent(3,3.486598);
   norm_u__55->SetBinContent(4,9.552779);
   norm_u__55->SetBinContent(5,14.96528);
   norm_u__55->SetBinContent(6,32.76069);
   norm_u__55->SetBinContent(7,38.3136);
   norm_u__55->SetBinContent(8,59.18113);
   norm_u__55->SetBinContent(9,85.70733);
   norm_u__55->SetBinContent(10,88.32847);
   norm_u__55->SetBinContent(11,97.24225);
   norm_u__55->SetBinContent(12,86.36143);
   norm_u__55->SetBinContent(13,72.00243);
   norm_u__55->SetBinContent(14,53.32842);
   norm_u__55->SetBinContent(15,37.15164);
   norm_u__55->SetBinContent(16,24.20833);
   norm_u__55->SetBinContent(17,15.09331);
   norm_u__55->SetBinContent(18,7.895865);
   norm_u__55->SetBinContent(19,2.581144);
   norm_u__55->SetBinContent(20,1.056837);
   norm_u__55->SetBinContent(21,1.861485);
   norm_u__55->SetBinContent(22,0.280826);
   norm_u__55->SetBinContent(23,0.324072);
   norm_u__55->SetBinContent(24,0.06038511);
   norm_u__55->SetBinContent(25,0.6543078);
   norm_u__55->SetBinContent(26,0.211128);
   norm_u__55->SetBinError(3,0.990027);
   norm_u__55->SetBinError(4,1.873982);
   norm_u__55->SetBinError(5,2.546077);
   norm_u__55->SetBinError(6,3.768301);
   norm_u__55->SetBinError(7,4.177686);
   norm_u__55->SetBinError(8,5.03642);
   norm_u__55->SetBinError(9,6.283075);
   norm_u__55->SetBinError(10,6.33211);
   norm_u__55->SetBinError(11,6.665332);
   norm_u__55->SetBinError(12,6.174295);
   norm_u__55->SetBinError(13,5.408936);
   norm_u__55->SetBinError(14,4.819857);
   norm_u__55->SetBinError(15,3.794395);
   norm_u__55->SetBinError(16,3.083618);
   norm_u__55->SetBinError(17,2.22801);
   norm_u__55->SetBinError(18,1.730201);
   norm_u__55->SetBinError(19,0.9189327);
   norm_u__55->SetBinError(20,0.3735526);
   norm_u__55->SetBinError(21,0.7556671);
   norm_u__55->SetBinError(22,0.1509852);
   norm_u__55->SetBinError(23,0.2051838);
   norm_u__55->SetBinError(24,0.06038511);
   norm_u__55->SetBinError(25,0.4133917);
   norm_u__55->SetBinError(26,0.1044794);
   norm_u__55->SetEntries(2866);
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
   entry=leg->AddEntry("frame_x_u2_4061da20","JEC up Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.826011 #pm 0.009649","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.250311 #pm 0.007770","");
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
   
   TH1D *frame_4061da20_copy__56 = new TH1D("frame_4061da20_copy__56","p_T Balance",25,0,2);
   frame_4061da20_copy__56->SetBinContent(1,109.103);
   frame_4061da20_copy__56->SetMinimum(-5.195379);
   frame_4061da20_copy__56->SetMaximum(109.103);
   frame_4061da20_copy__56->SetEntries(1);
   frame_4061da20_copy__56->SetDirectory(0);
   frame_4061da20_copy__56->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4061da20_copy__56->SetLineColor(ci);
   frame_4061da20_copy__56->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4061da20_copy__56->GetXaxis()->SetLabelFont(42);
   frame_4061da20_copy__56->GetXaxis()->SetTitleOffset(1);
   frame_4061da20_copy__56->GetXaxis()->SetTitleFont(42);
   frame_4061da20_copy__56->GetYaxis()->SetTitle("1/Events");
   frame_4061da20_copy__56->GetYaxis()->SetLabelFont(42);
   frame_4061da20_copy__56->GetYaxis()->SetTitleFont(42);
   frame_4061da20_copy__56->GetZaxis()->SetLabelFont(42);
   frame_4061da20_copy__56->GetZaxis()->SetTitleOffset(1);
   frame_4061da20_copy__56->GetZaxis()->SetTitleFont(42);
   frame_4061da20_copy__56->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-11.39776,2.25,102.5799);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_40621a20__57 = new TH1D("frame_40621a20__57","p_T Balance",25,0,2);
   frame_40621a20__57->SetBinContent(1,100.3003);
   frame_40621a20__57->SetMaximum(100.3003);
   frame_40621a20__57->SetEntries(1);
   frame_40621a20__57->SetDirectory(0);
   frame_40621a20__57->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40621a20__57->SetLineColor(ci);
   frame_40621a20__57->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40621a20__57->GetXaxis()->SetLabelFont(42);
   frame_40621a20__57->GetXaxis()->SetTitleOffset(1);
   frame_40621a20__57->GetXaxis()->SetTitleFont(42);
   frame_40621a20__57->GetYaxis()->SetTitle("1/Events");
   frame_40621a20__57->GetYaxis()->SetLabelFont(42);
   frame_40621a20__57->GetYaxis()->SetTitleFont(42);
   frame_40621a20__57->GetZaxis()->SetLabelFont(42);
   frame_40621a20__57->GetZaxis()->SetTitleOffset(1);
   frame_40621a20__57->GetZaxis()->SetTitleFont(42);
   frame_40621a20__57->Draw("FUNC");
   
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
   3.710223,
   11.44936,
   19.75731,
   34.09052,
   36.8318,
   68.68055,
   81.74986,
   81.94062,
   89.40575,
   86.02085,
   60.51782,
   47.56944,
   34.70934,
   12.38705,
   14.00783,
   4.406571,
   3.017859,
   2.38591,
   0.2197556,
   0.04989491,
   0.261948,
   0.06117974,
   0.7935008};
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
   1.053249,
   1.999576,
   2.980215,
   3.970183,
   3.975256,
   5.510841,
   5.892776,
   6.033143,
   6.118344,
   6.0796,
   4.949583,
   4.40327,
   3.710474,
   1.979566,
   2.137004,
   1.26629,
   0.9812418,
   0.7795622,
   0.1394927,
   0.04989491,
   0.1969982,
   0.06117974,
   0.4455156};
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
   1.053249,
   1.999576,
   2.980215,
   3.970183,
   3.975256,
   5.510841,
   5.892776,
   6.033143,
   6.118344,
   6.0796,
   4.949583,
   4.40327,
   3.710474,
   1.979566,
   2.137004,
   1.26629,
   0.9812418,
   0.7795622,
   0.1394927,
   0.04989491,
   0.1969982,
   0.06117974,
   0.4455156};
   grae = new TGraphAsymmErrors(25,h_dh_down2_fx3015,h_dh_down2_fy3015,h_dh_down2_felx3015,h_dh_down2_fehx3015,h_dh_down2_fely3015,h_dh_down2_fehy3015);
   grae->SetName("h_dh_down2");
   grae->SetTitle("Histogram of dh_down2_plot__x_d2");
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   grae->SetMarkerStyle(8);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_h_dh_down23015 = new TH1F("Graph_h_dh_down23015","Histogram of dh_down2_plot__x_d2",100,0,2.2);
   Graph_h_dh_down23015->SetMinimum(0);
   Graph_h_dh_down23015->SetMaximum(105.0765);
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
   
   Double_t down_fx15[57] = {
   0.1506778,
   0.1763646,
   0.2020515,
   0.2277384,
   0.2534253,
   0.2791122,
   0.3047991,
   0.3304859,
   0.3561728,
   0.3818597,
   0.4075466,
   0.4332335,
   0.4589204,
   0.4846073,
   0.5102941,
   0.5616679,
   0.6130417,
   0.6387286,
   0.6644154,
   0.6901023,
   0.7029458,
   0.7157892,
   0.7286327,
   0.7414761,
   0.7543195,
   0.767163,
   0.7800064,
   0.7928499,
   0.8056933,
   0.8185368,
   0.8313802,
   0.8442236,
   0.8570671,
   0.8699105,
   0.882754,
   0.8955974,
   0.9084408,
   0.9212843,
   0.9469712,
   0.9726581,
   0.9983449,
   1.024032,
   1.075406,
   1.101092,
   1.126779,
   1.152466,
   1.178153,
   1.20384,
   1.229527,
   1.255214,
   1.280901,
   1.306588,
   1.332274,
   1.357961,
   1.383648,
   1.435022,
   1.435022};
   Double_t down_fy15[57] = {
   2.79077,
   3.652075,
   4.727596,
   6.053773,
   7.668262,
   9.608439,
   11.90951,
   14.60225,
   17.7105,
   21.24844,
   25.21786,
   29.60565,
   34.38159,
   39.49684,
   44.8832,
   56.10247,
   67.14604,
   72.27153,
   76.94831,
   81.0431,
   82.83358,
   84.43414,
   85.83234,
   87.01721,
   87.97932,
   88.71096,
   89.20625,
   89.46116,
   89.47362,
   89.24354,
   88.77278,
   88.06516,
   87.12638,
   85.96398,
   84.5872,
   83.00686,
   81.23527,
   79.28601,
   74.9142,
   70.01915,
   64.7373,
   59.20759,
   47.93781,
   42.43812,
   37.16373,
   32.19344,
   27.58675,
   23.384,
   19.6075,
   16.26888,
   13.52868,
   11.34186,
   9.579579,
   8.14666,
   6.971921,
   5.194193,
   5.194193};
   graph = new TGraph(57,down_fx15,down_fy15);
   graph->SetName("down");
   graph->SetTitle("Projection of downf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineColor(7);
   graph->SetLineWidth(2);
   
   TH1F *Graph_down15 = new TH1F("Graph_down15","Projection of downf DSCB fit",100,0.02224334,1.563456);
   Graph_down15->SetMinimum(2.511693);
   Graph_down15->SetMaximum(98.1419);
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
   
   TH1D *frame_40621a20__58 = new TH1D("frame_40621a20__58","p_T Balance",25,0,2);
   frame_40621a20__58->SetBinContent(1,100.3003);
   frame_40621a20__58->SetMaximum(100.3003);
   frame_40621a20__58->SetEntries(1);
   frame_40621a20__58->SetDirectory(0);
   frame_40621a20__58->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40621a20__58->SetLineColor(ci);
   frame_40621a20__58->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40621a20__58->GetXaxis()->SetLabelFont(42);
   frame_40621a20__58->GetXaxis()->SetTitleOffset(1);
   frame_40621a20__58->GetXaxis()->SetTitleFont(42);
   frame_40621a20__58->GetYaxis()->SetTitle("1/Events");
   frame_40621a20__58->GetYaxis()->SetLabelFont(42);
   frame_40621a20__58->GetYaxis()->SetTitleFont(42);
   frame_40621a20__58->GetZaxis()->SetLabelFont(42);
   frame_40621a20__58->GetZaxis()->SetTitleOffset(1);
   frame_40621a20__58->GetZaxis()->SetTitleFont(42);
   frame_40621a20__58->Draw("AXISSAME");
   
   TH1D *norm_d__59 = new TH1D("norm_d__59","",25,0,2);
   norm_d__59->SetBinContent(3,3.710223);
   norm_d__59->SetBinContent(4,11.44936);
   norm_d__59->SetBinContent(5,19.75731);
   norm_d__59->SetBinContent(6,34.09052);
   norm_d__59->SetBinContent(7,36.8318);
   norm_d__59->SetBinContent(8,68.68055);
   norm_d__59->SetBinContent(9,81.74985);
   norm_d__59->SetBinContent(10,81.94062);
   norm_d__59->SetBinContent(11,89.40575);
   norm_d__59->SetBinContent(12,86.02085);
   norm_d__59->SetBinContent(13,60.51782);
   norm_d__59->SetBinContent(14,47.56944);
   norm_d__59->SetBinContent(15,34.70934);
   norm_d__59->SetBinContent(16,12.38705);
   norm_d__59->SetBinContent(17,14.00783);
   norm_d__59->SetBinContent(18,4.406571);
   norm_d__59->SetBinContent(19,3.017859);
   norm_d__59->SetBinContent(20,2.38591);
   norm_d__59->SetBinContent(21,0.2197556);
   norm_d__59->SetBinContent(22,0.04989491);
   norm_d__59->SetBinContent(23,0.261948);
   norm_d__59->SetBinContent(24,0.06117974);
   norm_d__59->SetBinContent(25,0.7935008);
   norm_d__59->SetBinContent(26,0.1975077);
   norm_d__59->SetBinError(3,1.053249);
   norm_d__59->SetBinError(4,1.999576);
   norm_d__59->SetBinError(5,2.980215);
   norm_d__59->SetBinError(6,3.970183);
   norm_d__59->SetBinError(7,3.975256);
   norm_d__59->SetBinError(8,5.510841);
   norm_d__59->SetBinError(9,5.892776);
   norm_d__59->SetBinError(10,6.033143);
   norm_d__59->SetBinError(11,6.118344);
   norm_d__59->SetBinError(12,6.0796);
   norm_d__59->SetBinError(13,4.949583);
   norm_d__59->SetBinError(14,4.40327);
   norm_d__59->SetBinError(15,3.710474);
   norm_d__59->SetBinError(16,1.979566);
   norm_d__59->SetBinError(17,2.137004);
   norm_d__59->SetBinError(18,1.26629);
   norm_d__59->SetBinError(19,0.9812418);
   norm_d__59->SetBinError(20,0.7795622);
   norm_d__59->SetBinError(21,0.1394927);
   norm_d__59->SetBinError(22,0.04989491);
   norm_d__59->SetBinError(23,0.1969982);
   norm_d__59->SetBinError(24,0.06117974);
   norm_d__59->SetBinError(25,0.4455156);
   norm_d__59->SetBinError(26,0.1051775);
   norm_d__59->SetEntries(2904);
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
   entry=leg->AddEntry("frame_x_d2_40621a20","JEC down Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.801990 #pm 0.009875","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.249018 #pm 0.007979","");
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
   
   TH1D *frame_40621a20_copy__60 = new TH1D("frame_40621a20_copy__60","p_T Balance",25,0,2);
   frame_40621a20_copy__60->SetBinContent(1,100.3003);
   frame_40621a20_copy__60->SetMaximum(100.3003);
   frame_40621a20_copy__60->SetEntries(1);
   frame_40621a20_copy__60->SetDirectory(0);
   frame_40621a20_copy__60->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_40621a20_copy__60->SetLineColor(ci);
   frame_40621a20_copy__60->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_40621a20_copy__60->GetXaxis()->SetLabelFont(42);
   frame_40621a20_copy__60->GetXaxis()->SetTitleOffset(1);
   frame_40621a20_copy__60->GetXaxis()->SetTitleFont(42);
   frame_40621a20_copy__60->GetYaxis()->SetTitle("1/Events");
   frame_40621a20_copy__60->GetYaxis()->SetLabelFont(42);
   frame_40621a20_copy__60->GetYaxis()->SetTitleFont(42);
   frame_40621a20_copy__60->GetZaxis()->SetLabelFont(42);
   frame_40621a20_copy__60->GetZaxis()->SetTitleOffset(1);
   frame_40621a20_copy__60->GetZaxis()->SetTitleFont(42);
   frame_40621a20_copy__60->Draw("sameaxis");
   
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
   pad_up->Range(-0.25,-13.56185,2.25,122.0566);
   pad_up->SetFillColor(0);
   pad_up->SetBorderMode(0);
   pad_up->SetBorderSize(2);
   pad_up->SetTopMargin(0.02);
   pad_up->SetFrameBorderMode(0);
   pad_up->SetFrameBorderMode(0);
   
   TH1D *frame_4062c150__61 = new TH1D("frame_4062c150__61","p_T Balance",25,0,2);
   frame_4062c150__61->SetBinContent(1,119.3443);
   frame_4062c150__61->SetMaximum(119.3443);
   frame_4062c150__61->SetEntries(1);
   frame_4062c150__61->SetDirectory(0);
   frame_4062c150__61->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4062c150__61->SetLineColor(ci);
   frame_4062c150__61->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4062c150__61->GetXaxis()->SetLabelFont(42);
   frame_4062c150__61->GetXaxis()->SetTitleOffset(1);
   frame_4062c150__61->GetXaxis()->SetTitleFont(42);
   frame_4062c150__61->GetYaxis()->SetTitle("1/Events");
   frame_4062c150__61->GetYaxis()->SetLabelFont(42);
   frame_4062c150__61->GetYaxis()->SetTitleFont(42);
   frame_4062c150__61->GetZaxis()->SetLabelFont(42);
   frame_4062c150__61->GetZaxis()->SetTitleOffset(1);
   frame_4062c150__61->GetZaxis()->SetTitleFont(42);
   frame_4062c150__61->Draw("FUNC");
   
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
   12,
   22,
   28,
   56,
   68,
   95,
   103,
   92,
   83,
   57,
   55,
   35,
   19,
   14,
   9,
   2,
   2,
   1,
   0,
   0,
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
   3.415266,
   4.654502,
   5.259711,
   7.4609,
   8.225883,
   9.729612,
   9.661201,
   9.574201,
   9.092044,
   7.527619,
   7.39358,
   5.887675,
   4.320219,
   3.6965,
   2.943461,
   1.291815,
   1.291815,
   0.8272462,
   0,
   0,
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
   4.559819,
   5.761366,
   6.354446,
   8.527879,
   9.28666,
   10.78102,
   10.6612,
   10.62644,
   10.14705,
   8.594007,
   8.461166,
   6.97241,
   5.435196,
   4.830381,
   4.110204,
   2.63786,
   2.63786,
   2.299527,
   1.147874,
   1.147874,
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
   Graph_h_dh_data23016->SetMaximum(125.0273);
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
   
   Double_t observation_fx16[59] = {
   0.1102736,
   0.1371481,
   0.1640225,
   0.190897,
   0.2177715,
   0.244646,
   0.2715205,
   0.2983949,
   0.3252694,
   0.3521439,
   0.3790184,
   0.4058929,
   0.4327673,
   0.4596418,
   0.4865163,
   0.5133908,
   0.5402653,
   0.5940142,
   0.6208887,
   0.6477632,
   0.6746376,
   0.6880749,
   0.7015121,
   0.7149494,
   0.7283866,
   0.7418238,
   0.7552611,
   0.7686983,
   0.7821356,
   0.7955728,
   0.80901,
   0.8224473,
   0.8358845,
   0.8493218,
   0.862759,
   0.8761962,
   0.8896335,
   0.9030707,
   0.916508,
   0.9433824,
   0.9702569,
   0.9971314,
   1.024006,
   1.077755,
   1.104629,
   1.131504,
   1.158378,
   1.185253,
   1.19869,
   1.212127,
   1.239002,
   1.265876,
   1.292751,
   1.319625,
   1.3465,
   1.373374,
   1.400249,
   1.453998,
   1.453998};
   Double_t observation_fy16[59] = {
   1.830205,
   2.486491,
   3.336939,
   4.423683,
   5.792873,
   7.493388,
   9.574954,
   12.08563,
   15.06872,
   18.55913,
   22.57944,
   27.13582,
   32.21418,
   37.77681,
   43.76005,
   50.07312,
   56.5986,
   69.69965,
   75.93717,
   81.72455,
   86.88101,
   89.169,
   91.2371,
   93.06741,
   94.64383,
   95.95234,
   96.98117,
   97.72099,
   98.16503,
   98.30924,
   98.15229,
   97.69562,
   96.94342,
   95.90254,
   94.58243,
   92.99495,
   91.15424,
   89.07645,
   86.77958,
   81.60795,
   75.80915,
   69.56408,
   63.05547,
   49.93682,
   43.62961,
   37.65443,
   32.10148,
   27.07379,
   24.88564,
   22.91416,
   19.52358,
   16.73756,
   14.43124,
   12.50883,
   10.89613,
   9.535148,
   8.380179,
   6.550271,
   6.550271};
   graph = new TGraph(59,observation_fx16,observation_fy16);
   graph->SetName("observation");
   graph->SetTitle("Projection of obsf DSCB fit");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_observation16 = new TH1F("Graph_observation16","Projection of obsf DSCB fit",100,0,1.58837);
   Graph_observation16->SetMinimum(1.647184);
   Graph_observation16->SetMaximum(107.9571);
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
   
   TH1D *frame_4062c150__62 = new TH1D("frame_4062c150__62","p_T Balance",25,0,2);
   frame_4062c150__62->SetBinContent(1,119.3443);
   frame_4062c150__62->SetMaximum(119.3443);
   frame_4062c150__62->SetEntries(1);
   frame_4062c150__62->SetDirectory(0);
   frame_4062c150__62->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4062c150__62->SetLineColor(ci);
   frame_4062c150__62->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4062c150__62->GetXaxis()->SetLabelFont(42);
   frame_4062c150__62->GetXaxis()->SetTitleOffset(1);
   frame_4062c150__62->GetXaxis()->SetTitleFont(42);
   frame_4062c150__62->GetYaxis()->SetTitle("1/Events");
   frame_4062c150__62->GetYaxis()->SetLabelFont(42);
   frame_4062c150__62->GetYaxis()->SetTitleFont(42);
   frame_4062c150__62->GetZaxis()->SetLabelFont(42);
   frame_4062c150__62->GetZaxis()->SetTitleOffset(1);
   frame_4062c150__62->GetZaxis()->SetTitleFont(42);
   frame_4062c150__62->Draw("AXISSAME");
   
   TH1D *norm_o__63 = new TH1D("norm_o__63","",25,0,2);
   norm_o__63->SetBinContent(3,4);
   norm_o__63->SetBinContent(4,12);
   norm_o__63->SetBinContent(5,22);
   norm_o__63->SetBinContent(6,28);
   norm_o__63->SetBinContent(7,56);
   norm_o__63->SetBinContent(8,68);
   norm_o__63->SetBinContent(9,95);
   norm_o__63->SetBinContent(10,103);
   norm_o__63->SetBinContent(11,92);
   norm_o__63->SetBinContent(12,83);
   norm_o__63->SetBinContent(13,57);
   norm_o__63->SetBinContent(14,55);
   norm_o__63->SetBinContent(15,35);
   norm_o__63->SetBinContent(16,19);
   norm_o__63->SetBinContent(17,14);
   norm_o__63->SetBinContent(18,9);
   norm_o__63->SetBinContent(19,2);
   norm_o__63->SetBinContent(20,2);
   norm_o__63->SetBinContent(21,1);
   norm_o__63->SetBinContent(26,1);
   norm_o__63->SetMinimum(0);
   norm_o__63->SetMaximum(226.6);
   norm_o__63->SetEntries(758);
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
   entry=leg->AddEntry("frame_x_o2_4062c150","Data Fit","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#mu: 0.795257 #pm 0.009424","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#sigma: 0.242672 #pm 0.007723","");
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
   
   TH1D *frame_4062c150_copy__64 = new TH1D("frame_4062c150_copy__64","p_T Balance",25,0,2);
   frame_4062c150_copy__64->SetBinContent(1,119.3443);
   frame_4062c150_copy__64->SetMaximum(119.3443);
   frame_4062c150_copy__64->SetEntries(1);
   frame_4062c150_copy__64->SetDirectory(0);
   frame_4062c150_copy__64->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4062c150_copy__64->SetLineColor(ci);
   frame_4062c150_copy__64->GetXaxis()->SetTitle("p_T(j_1)/p_T(Z)");
   frame_4062c150_copy__64->GetXaxis()->SetLabelFont(42);
   frame_4062c150_copy__64->GetXaxis()->SetTitleOffset(1);
   frame_4062c150_copy__64->GetXaxis()->SetTitleFont(42);
   frame_4062c150_copy__64->GetYaxis()->SetTitle("1/Events");
   frame_4062c150_copy__64->GetYaxis()->SetLabelFont(42);
   frame_4062c150_copy__64->GetYaxis()->SetTitleFont(42);
   frame_4062c150_copy__64->GetZaxis()->SetLabelFont(42);
   frame_4062c150_copy__64->GetZaxis()->SetTitleOffset(1);
   frame_4062c150_copy__64->GetZaxis()->SetTitleFont(42);
   frame_4062c150_copy__64->Draw("sameaxis");
   
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
