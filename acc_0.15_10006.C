void acc_0.15_10006()
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
   
   TH2D *frame__7 = new TH2D("frame__7","",10,0,4,10,0.01,1);
   
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
   frame__7->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(frame__7);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame__7->SetLineColor(ci);
   frame__7->GetXaxis()->SetLabelFont(42);
   frame__7->GetXaxis()->SetLabelSize(0.035);
   frame__7->GetXaxis()->SetTitleSize(0.035);
   frame__7->GetXaxis()->SetTitleFont(42);
   frame__7->GetYaxis()->SetLabelFont(42);
   frame__7->GetYaxis()->SetLabelSize(0.035);
   frame__7->GetYaxis()->SetTitleSize(0.035);
   frame__7->GetYaxis()->SetTitleOffset(0);
   frame__7->GetYaxis()->SetTitleFont(42);
   frame__7->GetZaxis()->SetLabelFont(42);
   frame__7->GetZaxis()->SetLabelSize(0.035);
   frame__7->GetZaxis()->SetTitleSize(0.035);
   frame__7->GetZaxis()->SetTitleFont(42);
   frame__7->Draw("");
   
   Double_t _fx13[11] = {
   0.65,
   0.75,
   0.45,
   0.55,
   1,
   0.35,
   1.5,
   1.7,
   0.85,
   0.95,
   2};
   Double_t _fy13[11] = {
   0.335,
   0.405,
   0.01,
   0.16,
   0.459,
   0.006,
   0.467,
   0.469,
   0.437,
   0.448,
   0.464};
   TGraph *graph = new TGraph(11,_fx13,_fy13);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(2);
   
   TH1F *Graph_Graph13 = new TH1F("Graph_Graph13","",100,0.185,2.165);
   Graph_Graph13->SetMinimum(0.0054);
   Graph_Graph13->SetMaximum(0.5153);
   Graph_Graph13->SetDirectory(0);
   Graph_Graph13->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph13->SetLineColor(ci);
   Graph_Graph13->GetXaxis()->SetLabelFont(42);
   Graph_Graph13->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph13->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph13->GetXaxis()->SetTitleFont(42);
   Graph_Graph13->GetYaxis()->SetLabelFont(42);
   Graph_Graph13->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph13->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph13->GetYaxis()->SetTitleOffset(0);
   Graph_Graph13->GetYaxis()->SetTitleFont(42);
   Graph_Graph13->GetZaxis()->SetLabelFont(42);
   Graph_Graph13->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph13->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph13->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph13);
   
   
   TF1 *mp14 = new TF1("mp","[0]/(1+exp(-(x-[1])*[2]))",0.39,2);
   mp14->SetFillColor(19);
   mp14->SetFillStyle(0);
   mp14->SetLineColor(2);
   mp14->SetLineWidth(2);
   mp14->SetChisquare(0.001929396);
   mp14->SetNDF(7);
   mp14->GetXaxis()->SetLabelFont(42);
   mp14->GetXaxis()->SetLabelSize(0.035);
   mp14->GetXaxis()->SetTitleSize(0.035);
   mp14->GetXaxis()->SetTitleFont(42);
   mp14->GetYaxis()->SetLabelFont(42);
   mp14->GetYaxis()->SetLabelSize(0.035);
   mp14->GetYaxis()->SetTitleSize(0.035);
   mp14->GetYaxis()->SetTitleOffset(0);
   mp14->GetYaxis()->SetTitleFont(42);
   mp14->SetParameter(0,0.4562101);
   mp14->SetParError(0,0.007022161);
   mp14->SetParLimits(0,0,0);
   mp14->SetParameter(1,0.5931658);
   mp14->SetParError(1,0.007631367);
   mp14->SetParLimits(1,0,0);
   mp14->SetParameter(2,16.84954);
   mp14->SetParError(2,1.915015);
   mp14->SetParLimits(2,0,0);
   graph->GetListOfFunctions()->Add(mp14);
   graph->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
