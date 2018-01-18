void acc_0.20_10006()
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
   
   TH2D *frame__10 = new TH2D("frame__10","",10,0,4,10,0.01,1);
   
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
   frame__10->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(frame__10);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame__10->SetLineColor(ci);
   frame__10->GetXaxis()->SetLabelFont(42);
   frame__10->GetXaxis()->SetLabelSize(0.035);
   frame__10->GetXaxis()->SetTitleSize(0.035);
   frame__10->GetXaxis()->SetTitleFont(42);
   frame__10->GetYaxis()->SetLabelFont(42);
   frame__10->GetYaxis()->SetLabelSize(0.035);
   frame__10->GetYaxis()->SetTitleSize(0.035);
   frame__10->GetYaxis()->SetTitleOffset(0);
   frame__10->GetYaxis()->SetTitleFont(42);
   frame__10->GetZaxis()->SetLabelFont(42);
   frame__10->GetZaxis()->SetLabelSize(0.035);
   frame__10->GetZaxis()->SetTitleSize(0.035);
   frame__10->GetZaxis()->SetTitleFont(42);
   frame__10->Draw("");
   
   Double_t _fx19[10] = {
   0.65,
   0.75,
   0.45,
   0.55,
   1,
   1.5,
   1.7,
   0.85,
   0.95,
   2};
   Double_t _fy19[10] = {
   0.331,
   0.401,
   0.011,
   0.158,
   0.455,
   0.463,
   0.467,
   0.442,
   0.453,
   0.454};
   TGraph *graph = new TGraph(10,_fx19,_fy19);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(2);
   
   TH1F *Graph_Graph19 = new TH1F("Graph_Graph19","",100,0.295,2.155);
   Graph_Graph19->SetMinimum(0.0099);
   Graph_Graph19->SetMaximum(0.5126);
   Graph_Graph19->SetDirectory(0);
   Graph_Graph19->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph19->SetLineColor(ci);
   Graph_Graph19->GetXaxis()->SetLabelFont(42);
   Graph_Graph19->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph19->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph19->GetXaxis()->SetTitleFont(42);
   Graph_Graph19->GetYaxis()->SetLabelFont(42);
   Graph_Graph19->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph19->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph19->GetYaxis()->SetTitleOffset(0);
   Graph_Graph19->GetYaxis()->SetTitleFont(42);
   Graph_Graph19->GetZaxis()->SetLabelFont(42);
   Graph_Graph19->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph19->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph19->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph19);
   
   
   TF1 *mp20 = new TF1("mp","[0]/(1+exp(-(x-[1])*[2]))*(1+exp(-(x-[3])*[4]))",0.39,2);
   mp20->SetFillColor(19);
   mp20->SetFillStyle(0);
   mp20->SetLineColor(2);
   mp20->SetLineWidth(2);
   mp20->SetChisquare(0.001607186);
   mp20->SetNDF(5);
   mp20->GetXaxis()->SetLabelFont(42);
   mp20->GetXaxis()->SetLabelSize(0.035);
   mp20->GetXaxis()->SetTitleSize(0.035);
   mp20->GetXaxis()->SetTitleFont(42);
   mp20->GetYaxis()->SetLabelFont(42);
   mp20->GetYaxis()->SetLabelSize(0.035);
   mp20->GetYaxis()->SetTitleSize(0.035);
   mp20->GetYaxis()->SetTitleOffset(0);
   mp20->GetYaxis()->SetTitleFont(42);
   mp20->SetParameter(0,0.2272527);
   mp20->SetParError(0,0.000137903);
   mp20->SetParLimits(0,0,0.5);
   mp20->SetParameter(1,0.5943664);
   mp20->SetParError(1,0.0003155216);
   mp20->SetParLimits(1,0,2);
   mp20->SetParameter(2,16.66872);
   mp20->SetParError(2,0.07143857);
   mp20->SetParLimits(2,5,20);
   mp20->SetParameter(3,14.87106);
   mp20->SetParError(3,0.2919311);
   mp20->SetParLimits(3,1,20);
   mp20->SetParameter(4,-6.030211e-06);
   mp20->SetParError(4,0.07542366);
   mp20->SetParLimits(4,-100,0);
   graph->GetListOfFunctions()->Add(mp20);
   graph->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
