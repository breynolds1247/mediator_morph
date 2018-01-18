void acc_0.40_10006()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Dec 12 18:15:33 2017) by ROOT version6.10/08
   TCanvas *c1 = new TCanvas("c1", "c1",10,44,700,500);
   gStyle->SetOptFit(1);
   c1->SetHighLightColor(2);
   c1->Range(-0.5,-0.11375,4.5,1.12375);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH2D *frame__11 = new TH2D("frame__11","",10,0,4,10,0.01,1);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.695,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("frame");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 0      ");
   ptstats_LaTex = ptstats->AddText("Mean x =      0");
   ptstats_LaTex = ptstats->AddText("Mean y =      0");
   ptstats_LaTex = ptstats->AddText("Std Dev x =      0");
   ptstats_LaTex = ptstats->AddText("Std Dev y =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(11111);
   ptstats->Draw();
   frame__11->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(frame__11);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame__11->SetLineColor(ci);
   frame__11->GetXaxis()->SetLabelFont(42);
   frame__11->GetXaxis()->SetLabelSize(0.035);
   frame__11->GetXaxis()->SetTitleSize(0.035);
   frame__11->GetXaxis()->SetTitleFont(42);
   frame__11->GetYaxis()->SetLabelFont(42);
   frame__11->GetYaxis()->SetLabelSize(0.035);
   frame__11->GetYaxis()->SetTitleSize(0.035);
   frame__11->GetYaxis()->SetTitleOffset(0);
   frame__11->GetYaxis()->SetTitleFont(42);
   frame__11->GetZaxis()->SetLabelFont(42);
   frame__11->GetZaxis()->SetLabelSize(0.035);
   frame__11->GetZaxis()->SetTitleSize(0.035);
   frame__11->GetZaxis()->SetTitleFont(42);
   frame__11->Draw("");
   
   Double_t _fx21[8] = {
   0.65,
   0.75,
   1.15,
   1.05,
   1.7,
   0.85,
   0.95,
   2};
   Double_t _fy21[8] = {
   0.297,
   0.364,
   0.424,
   0.43,
   0.436,
   0.397,
   0.409,
   0.405};
   TGraph *graph = new TGraph(8,_fx21,_fy21);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(2);
   
   TH1F *Graph_Graph21 = new TH1F("Graph_Graph21","",100,0.515,2.135);
   Graph_Graph21->SetMinimum(0.2831);
   Graph_Graph21->SetMaximum(0.4499);
   Graph_Graph21->SetDirectory(0);
   Graph_Graph21->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph21->SetLineColor(ci);
   Graph_Graph21->GetXaxis()->SetLabelFont(42);
   Graph_Graph21->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph21->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph21->GetXaxis()->SetTitleFont(42);
   Graph_Graph21->GetYaxis()->SetLabelFont(42);
   Graph_Graph21->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph21->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph21->GetYaxis()->SetTitleOffset(0);
   Graph_Graph21->GetYaxis()->SetTitleFont(42);
   Graph_Graph21->GetZaxis()->SetLabelFont(42);
   Graph_Graph21->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph21->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph21->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph21);
   
   
   TF1 *mp22 = new TF1("mp","[0]/(1+exp(-(x-[1])*[2]))*(1+exp(-(x-[3])*[4]))",0.39,2);
   mp22->SetFillColor(19);
   mp22->SetFillStyle(0);
   mp22->SetLineColor(2);
   mp22->SetLineWidth(2);
   mp22->SetChisquare(0.00063302);
   mp22->SetNDF(3);
   mp22->GetXaxis()->SetLabelFont(42);
   mp22->GetXaxis()->SetLabelSize(0.035);
   mp22->GetXaxis()->SetTitleSize(0.035);
   mp22->GetXaxis()->SetTitleFont(42);
   mp22->GetYaxis()->SetLabelFont(42);
   mp22->GetYaxis()->SetLabelSize(0.035);
   mp22->GetYaxis()->SetTitleSize(0.035);
   mp22->GetYaxis()->SetTitleOffset(0);
   mp22->GetYaxis()->SetTitleFont(42);
   mp22->SetParameter(0,0.2119013);
   mp22->SetParError(0,0.00236494);
   mp22->SetParLimits(0,0,0.5);
   mp22->SetParameter(1,0.5615984);
   mp22->SetParError(1,0.01046422);
   mp22->SetParLimits(1,0,2);
   mp22->SetParameter(2,9.56834);
   mp22->SetParError(2,0.1405714);
   mp22->SetParLimits(2,5,20);
   mp22->SetParameter(3,2.14695);
   mp22->SetParError(3,0.1567413);
   mp22->SetParLimits(3,1,20);
   mp22->SetParameter(4,-5.735657e-06);
   mp22->SetParError(4,0.9921673);
   mp22->SetParLimits(4,-100,0);
   graph->GetListOfFunctions()->Add(mp22);
   graph->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
